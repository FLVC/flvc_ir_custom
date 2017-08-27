<?php
/**
 * @file
 * Implementation of FLVC IR utility functions.
 */

/**
 * Returns the value of the MODS or MADS identifier[@type=u1] element.
 *
 * @param object $object
 *   An islandora object
 * @param string $dsid
 *   A datastream id either MADS or MODS
 * @return string
 *   The value of the identifier[@type=u1]
 * @throws \Exception
 *   if the datastream does not exist, is empty, can't be loaded as xml or the identifier does not exist.
 */
function flvc_ir_custom_get_u1($object, $dsid){
  if(empty($object[$dsid]->content)) {
    throw new Exception("No content found for datastream $dsid");
  }
  $xml = $object[$dsid]->content;
  $doc = @DOMDocument::loadXML($xml);
  if (empty($doc)) {
    // couldn't parse the mods
    throw new Exception('Could not parse XML');
  }
  $xpath = new DOMXPath($doc);
  $namespace = ($dsid === 'MADS') ? 'http://www.loc.gov/mads/v2' : 'http://www.loc.gov/mods/v3';
  $xpath->registerNamespace('ns', $namespace);
  $results = $xpath->query('//ns:identifier[@type="u1" and normalize-space(text())]');
  if ($results->length > 0) {
    // take the first u1 should really only be one
    $u1 = $results->item(0)->textContent;
  }
  if (empty($u1)) {
    // no issn to use in romeo query
    throw new Exception("U1 identifier not found in $dsid datastream.");
  }
  return $u1;
}

/**
 * Returns the value of the MADS affiliation element.
 *
 * @param object $object
 *   An islandora object
 * @return array
 *   The value of the mads affiliation fields
 * @throws \Exception
 *   if the datastream does not exist, is empty, can't be loaded as xml or the identifier does not exist.
 */
function flvc_ir_custom_get_u2($object){
  if(empty($object['MADS']->content)) {
    throw new Exception("No content found for datastream MADS");
  }
  $xml = $object['MADS']->content;
  $doc = @DOMDocument::loadXML($xml);
  if (empty($doc)) {
    // couldn't parse the mods
    throw new Exception('Could not parse MADS XML');
  }
  $xpath = new DOMXPath($doc);
  $namespace = 'http://www.loc.gov/mads/v2';
  $xpath->registerNamespace('ns', $namespace);
  $results = $xpath->query('//ns:affiliation/ns:organization');
  $u2 = array();
  if ($results->length > 0) {
    // take the first u1 should really only be one
    foreach($results as $result){
       array_push($u2, $result->textContent);
    }
  }
  if (empty($u2)) {
    // no issn to use in romeo query
    throw new Exception("Affiliation not found in MADS datastream.");
  }
  return $u2;
}

/**
 * Returns the value of the MADS affiliation element.
 *
 * @param object $object
 *   An islandora object
 * @return array
 *   The value of the MADS parent institution
 * @throws \Exception
 *   if the datastream does not exist, is empty, can't be loaded as xml or the identifier does not exist.
 */
function flvc_ir_custom_get_parent_organization($object){
  if(empty($object['MADS']->content)) {
    throw new Exception("No content found for datastream MADS");
  }
  $xml = $object['MADS']->content;
  $doc = @DOMDocument::loadXML($xml);
  if (empty($doc)) {
    // couldn't parse the mods
    throw new Exception('Could not parse MADS XML');
  }
  $xpath = new DOMXPath($doc);
  $namespace = 'http://www.loc.gov/mads/v2';
  $xpath->registerNamespace('ns', $namespace);
  $results = $xpath->query('//ns:related[@type="parentOrg"]/ns:name/ns:namePart[normalize-space(text())]');
  $parent = '';
  if ($results->length > 0) {
    // take the first parent should really only be one
    $parent = $results->item(0)->textContent;
  }
  return $parent;
}

function flvc_ir_custom_strip_special_chars($string) {  
    $encoded = preg_replace('/[^A-Za-z0-9]/', ' ', $string);
    return $encoded;
}

function flvc_ir_custom_get_children_for_tree($parentvalue, $searchfield, $displayfield, &$tree_entries) {
  module_load_include('inc', 'islandora_solr', 'includes/utilities');

  // search for children of parentvalue
  $query_processor = new IslandoraSolrQueryProcessor();
  $query_processor->solrQuery = $searchfield . ':' . islandora_solr_lesser_escape($parentvalue);
  $query_processor->solrStart = 0;
  $query_processor->solrLimit = 1000;
  $query_processor->solrParams = array(
    'fl' => 'PID, ' . $displayfield,
    'sort' => 'fgs_label_s asc',
  );
  $query_processor->solrParams = array_merge($query_processor->solrParams, flvc_ir_custom_get_solr_filters());
  $query_processor->executeQuery(FALSE);
  $solr_results = $query_processor->islandoraSolrResult;
  // foreach child, add to tree, then search for children of child value
  if ((isset($solr_results['response']['objects']))&&($solr_results['response']['numFound'] > 0)) {
    foreach ($solr_results['response']['objects'] as $object_response) {
      $pid = $object_response['solr_doc']['PID'];
      $dept = $object_response['solr_doc'][$displayfield][0];
      $tree_entry = array();
      $tree_entry['id'] = flvc_ir_custom_strip_special_chars($dept);
      $tree_entry['pid'] = $pid;
      $tree_entry['type'] = 'org';
      $tree_entry['text'] = $dept;
      $tree_entry['parent'] = flvc_ir_custom_strip_special_chars($parentvalue);
      $tree_entries[] = $tree_entry;
      if (count($tree_entries) < 10000) {
        flvc_ir_custom_get_children_for_tree($dept, $searchfield, $displayfield, $tree_entries);
      }
    }
  }

}

function flvc_ir_custom_get_solr_tree_view(AbstractObject $object, $searchfield, $displayfield) {
  $form = array();
  $tree_entries = array();
  $tree_entry = array();
  $tree_entry['id'] = flvc_ir_custom_strip_special_chars($object->label);
  $tree_entry['pid'] = $object->id;
  $tree_entry['type'] = 'org';
  $tree_entry['text'] = $object->label;
  $tree_entry['parent'] = '#';
  $tree_entries[] = $tree_entry;
  flvc_ir_custom_get_children_for_tree($object->label, $searchfield, $displayfield, $tree_entries);
  // only display tree if more than one entry
  //if (count($tree_entries) > 1) {
    $tree_settings = array(
      'data' => $tree_entries,
      'types' => array(
        'org' => array(),
      ),
      'plugins' => array(
        'types',
        'ui',
        'state',
      ),
      'object' => $object->id,
    );
    $module_path = drupal_get_path('module', 'flvc_ir_custom');
    $library_path = libraries_get_path('jstree');
    $form['flvc_ir_custom_tree'] = array(
      '#markup' => '<div id="flvc_ir_custom_tree_view"></div>',
    );
    $form['#attached']['css'] = array(
      "$library_path/dist/themes/default/style.min.css",
    );
    $form['#attached']['js'] = array(
      "$library_path/dist/libs/jquery.js" => array(
        'group' => JS_LIBRARY,
      ),
      "$library_path/dist/jstree.min.js" => array(
        'group' => JS_LIBRARY,
      ),
      "$module_path/js/jstree.js" => array(
        'group' => JS_LIBRARY,
      ),
    );
    $form['#attached']['js'][] = array(
      'data' => array('flvc_ir_custom_tree_settings' => $tree_settings),
      'type' => 'setting',
    );
    $form['collapse_all'] = array(
      '#type' => 'button',
      '#value' => t('Collapse all'),
      '#attributes' => array(
        'class' => array('flvc_ir_custom_tree_close_all'),
      ),
    );
    $form['open_all'] = array(
      '#type' => 'button',
      '#value' => t('Expand all'),
      '#attributes' => array(
        'class' => array('flvc_ir_custom_tree_open_all'),
      ),
    );
    $form['description'] = array(
      '#type' => 'item',
      '#markup' => t('Left click to navigate to the object.'),
    );
  //}
  return $form;
}

function flvc_ir_custom_get_parent_organizations_for_org($organization, &$orglist) {
  module_load_include('inc', 'islandora_solr', 'includes/utilities');

  // search for PID of organization
  $query_processor = new IslandoraSolrQueryProcessor();
  $query_processor->solrQuery = 'MADS_department_ms:' . islandora_solr_lesser_escape($organization);
  $query_processor->solrStart = 0;
  $query_processor->solrLimit = 1000;
  $query_processor->solrParams = array(
    'fl' => 'PID, MADS_parent_institution_ms',
  );
  $query_processor->solrParams = array_merge($query_processor->solrParams, flvc_ir_custom_get_solr_filters());
  $query_processor->executeQuery(FALSE);
  $solr_results = $query_processor->islandoraSolrResult;
  // foreach organization, add to array, then search for parents of organization
  if ((isset($solr_results['response']['objects']))&&($solr_results['response']['numFound'] > 0)) {
    foreach ($solr_results['response']['objects'] as $object_response) {
      $pid = $object_response['solr_doc']['PID'];
      $parentorg = $object_response['solr_doc']['MADS_parent_institution_ms'][0];
      if (!empty($parentorg)) {
        $orglist[] = $parentorg;
        if (count($orglist) < 100) {
          flvc_ir_custom_get_parent_organizations_for_org($parentorg, $orglist);
        }
      }
    }
  }

}

function flvc_ir_custom_get_organizations_for_person($identifier, &$orglist) {
  // search for organizations of identifier
  $query_processor = new IslandoraSolrQueryProcessor();
  $query_processor->solrQuery = 'MADS_u1_ms:' . islandora_solr_lesser_escape($identifier);
  $query_processor->solrStart = 0;
  $query_processor->solrLimit = 1000;
  $query_processor->solrParams = array(
    'fl' => 'PID, MADS_organization_ms',
  );
  $query_processor->solrParams = array_merge($query_processor->solrParams, flvc_ir_custom_get_solr_filters());
  $query_processor->executeQuery(FALSE);
  $solr_results = $query_processor->islandoraSolrResult;
  // foreach organization, add to array
  if ((isset($solr_results['response']['objects']))&&($solr_results['response']['numFound'] > 0)) {
    foreach ($solr_results['response']['objects'] as $object_response) {
      foreach ($object_response['solr_doc']['MADS_organization_ms'] as $organization) {
        $orglist[] = $organization;
        flvc_ir_custom_get_parent_organizations_for_org($organization, $orglist);
      }
    }
  }
}

/**
 * Return sparql format list of all parent organizations.
 */
function flvc_ir_custom_get_parent_organizations(FedoraObject $object, $datastream = 'MODS') {

  $orglist = array();

  if ($datastream == 'MODS') {
    if ((!isset($object['MODS']))||(empty($object['MODS']->content))) {
      drupal_exit();
    }
    $xml = $object['MODS']->content;
    $doc = @DOMDocument::loadXML($xml);
    if (empty($doc)) {
      // couldn't parse the mods
      drupal_exit();
    }
    $xpath = new DOMXPath($doc);
    $namespace = 'http://www.loc.gov/mods/v3';
    $xpath->registerNamespace('ns', $namespace);
    $results = $xpath->query('//ns:name/ns:nameIdentifier[normalize-space(text())]');
    if ($results->length > 0) {
      foreach($results as $result){
        flvc_ir_custom_get_organizations_for_person($result->textContent, $orglist);
      }
    }
  }
  else if ($datastream == 'MADS') {
    if ((!isset($object['MADS']))||(empty($object['MADS']->content))) {
      drupal_exit();
    }
    $xml = $object['MADS']->content;
    $doc = @DOMDocument::loadXML($xml);
    if (empty($doc)) {
      // couldn't parse the mods
      drupal_exit();
    }
    $xpath = new DOMXPath($doc);
    $namespace = 'http://www.loc.gov/mads/v2';
    $xpath->registerNamespace('ns', $namespace);
    $results = array();
    if (in_array('islandora:personCModel', $object->models)) {
      $results = $xpath->query('//ns:affiliation/ns:organization[normalize-space(text())]');
    }
    else if (in_array('islandora:organizationCModel', $object->models)) {
      $results = $xpath->query('//ns:related[@type="parentOrg"]/ns:name/ns:namePart[normalize-space(text())]');
    }
    if ($results->length > 0) {
      foreach($results as $result){
        $orglist[] = $result->textContent;
        flvc_ir_custom_get_parent_organizations_for_org($result->textContent, $orglist);
      }
    }
  }

  $output = '<sparql xmlns="http://www.w3.org/2001/sw/DataAccess/rf1/result"><results>';
  $orglist_dedup = array_unique($orglist);
  foreach ($orglist_dedup as $org) {
    if (!empty($org)) {
      $output .= '<result><organization>' . htmlspecialchars($org) . '</organization></result>';
    }
  }
  $output .= '</results></sparql>';
  print $output;

  drupal_exit();
}

function flvc_ir_custom_get_parent_organizations_from_scholar($scholar) {
  $orglist = array();
  flvc_ir_custom_get_organizations_for_person(urldecode($scholar), $orglist);
  $output = '<sparql xmlns="http://www.w3.org/2001/sw/DataAccess/rf1/result"><results>';
  $orglist_dedup = array_unique($orglist);
  foreach ($orglist_dedup as $org) {
    if (!empty($org)) {
      $output .= '<result><organization>' . htmlspecialchars($org) . '</organization></result>';
    }
  }
  $output .= '</results></sparql>';
  print $output;

  drupal_exit();
}

function flvc_ir_custom_get_parent_organizations_from_org($organization) {
  $orglist = array();
  $orglist[] = urldecode($organization);
  flvc_ir_custom_get_parent_organizations_for_org(urldecode($organization), $orglist);
  $output = '<sparql xmlns="http://www.w3.org/2001/sw/DataAccess/rf1/result"><results>';
  $orglist_dedup = array_unique($orglist);
  foreach ($orglist_dedup as $org) {
    if (!empty($org)) {
      $output .= '<result><organization>' . htmlspecialchars($org) . '</organization></result>';
    }
  }
  $output .= '</results></sparql>';
  print $output;

  drupal_exit();
}

function flvc_ir_custom_get_solr_filters() {

  $filter_params = array();

  // Restrict results based on specified namespaces.
  $namespace_list = trim(variable_get('islandora_solr_namespace_restriction', ''));
  if ($namespace_list) {
    $namespaces = preg_split('/[,|\s]/', $namespace_list);
    $namespace_array = array();
    foreach (array_filter($namespaces) as $namespace) {
      $namespace_array[] = "PID:$namespace\:*";
    }
    $filter_params['fq'][] = implode(' OR ', $namespace_array);
  }


  // get base filters
  $base_filters = preg_split("/\\r\\n|\\n|\\r/", variable_get('islandora_solr_base_filter', ''), -1, PREG_SPLIT_NO_EMPTY);
  foreach ($base_filters as $base_filter) {
    $filter_params['fq'][] = $base_filter;
  }

  return $filter_params;
}

