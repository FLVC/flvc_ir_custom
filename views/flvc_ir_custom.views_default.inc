<?php
/**
 * @file
 * Holds a default views for FLVC IR Custom module
 */

/**
 * Implements hook_views_default_views().
 */
function flvc_ir_custom_views_default_views() {
  $export = array();

  $view1 = flvc_ir_custom_get_view_browse_child_depts_by_dept();
  $export[$view1->name] = $view1;
  $view2 = flvc_ir_custom_get_view_browse_dept();
  $export[$view2->name] = $view2;
  $view3 = flvc_ir_custom_get_view_browse_scholars();
  $export[$view3->name] = $view3;
  $view4 = flvc_ir_custom_get_view_browse_scholars_by_dept();
  $export[$view4->name] = $view4;
  $view5 = flvc_ir_custom_get_view_child_departments();
  $export[$view5->name] = $view5;
  $view6 = flvc_ir_custom_get_view_other_scholars_in_dept();
  $export[$view6->name] = $view6;
  $view7 = flvc_ir_custom_get_view_parent_department();
  $export[$view7->name] = $view7;
  $view8 = flvc_ir_custom_get_view_recent_publications_by_dept();
  $export[$view8->name] = $view8;
  $view9 = flvc_ir_custom_get_view_recent_publications_by_scholar();
  $export[$view9->name] = $view9;

  return $export;
}

function flvc_ir_custom_get_view_browse_child_depts_by_dept() {

$view = new view();
$view->name = 'browse_child_depts_by_dept';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'islandora_solr';
$view->human_name = 'browse_child_depts_by_dept';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Child Departments';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'datatables';
$handler->display->display_options['style_options']['columns'] = array(
  'MADS_department_ms' => 'MADS_department_ms',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'MADS_department_ms' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['style_options']['elements'] = array(
  'search_box' => 0,
  'table_info' => 1,
  'save_state' => 0,
);
$handler->display->display_options['style_options']['layout'] = array(
  'autowidth' => 0,
  'themeroller' => 0,
  'sdom' => '',
);
$handler->display->display_options['style_options']['pages'] = array(
  'pagination_style' => '0',
  'length_change' => 0,
  'display_length' => '10',
);
/* Field: Islandora Solr: MADS_department_ms */
$handler->display->display_options['fields']['MADS_department_ms']['id'] = 'MADS_department_ms';
$handler->display->display_options['fields']['MADS_department_ms']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['MADS_department_ms']['field'] = 'MADS_department_ms';
$handler->display->display_options['fields']['MADS_department_ms']['label'] = 'Child Departments';
$handler->display->display_options['fields']['MADS_department_ms']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['MADS_department_ms']['link_to_object'] = 1;
/* Contextual filter: Islandora Solr: MADS_parent_department_ms */
$handler->display->display_options['arguments']['MADS_parent_department_ms']['id'] = 'MADS_parent_department_ms';
$handler->display->display_options['arguments']['MADS_parent_department_ms']['table'] = 'islandora_solr';
$handler->display->display_options['arguments']['MADS_parent_department_ms']['field'] = 'MADS_parent_department_ms';
$handler->display->display_options['arguments']['MADS_parent_department_ms']['default_action'] = 'not found';
$handler->display->display_options['arguments']['MADS_parent_department_ms']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['MADS_parent_department_ms']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['MADS_parent_department_ms']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['MADS_parent_department_ms']['summary_options']['items_per_page'] = '25';

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'child_depts_by_dept');
$handler->display->display_options['block_description'] = 'child_depts_by_dept';

return $view;
}

function flvc_ir_custom_get_view_browse_dept() {

$view = new view();
$view->name = 'browse_dept';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'islandora_solr';
$view->human_name = 'browse_dept';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Scholar Departments';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'datatables';
$handler->display->display_options['style_options']['columns'] = array(
  'MADS_department_ms' => 'MADS_department_ms',
  'MADS_parent_institution_ms' => 'MADS_parent_institution_ms',
  'MADS_url_ms' => 'MADS_url_ms',
  'MADS_department_mls' => 'MADS_department_mls',
  'fgs_label_s' => 'fgs_label_s',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'MADS_department_ms' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'MADS_parent_institution_ms' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'MADS_url_ms' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'MADS_department_mls' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'fgs_label_s' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['style_options']['elements'] = array(
  'search_box' => 1,
  'table_info' => 1,
  'save_state' => 0,
);
$handler->display->display_options['style_options']['layout'] = array(
  'autowidth' => 0,
  'themeroller' => 0,
  'sdom' => '',
);
$handler->display->display_options['style_options']['pages'] = array(
  'pagination_style' => '0',
  'length_change' => 0,
  'display_length' => '50',
);
/* Field: Islandora Solr: MADS_department_ms */
$handler->display->display_options['fields']['MADS_department_ms']['id'] = 'MADS_department_ms';
$handler->display->display_options['fields']['MADS_department_ms']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['MADS_department_ms']['field'] = 'MADS_department_ms';
$handler->display->display_options['fields']['MADS_department_ms']['label'] = 'Department';
$handler->display->display_options['fields']['MADS_department_ms']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['MADS_department_ms']['link_to_object'] = 1;
/* Field: Islandora Solr: MADS_parent_institution_ms */
$handler->display->display_options['fields']['MADS_parent_institution_ms']['id'] = 'MADS_parent_institution_ms';
$handler->display->display_options['fields']['MADS_parent_institution_ms']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['MADS_parent_institution_ms']['field'] = 'MADS_parent_institution_ms';
$handler->display->display_options['fields']['MADS_parent_institution_ms']['label'] = 'Parent Institution';
$handler->display->display_options['fields']['MADS_parent_institution_ms']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['MADS_parent_institution_ms']['link_to_object'] = 0;
/* Field: Islandora Solr: MADS_url_ms */
$handler->display->display_options['fields']['MADS_url_ms']['id'] = 'MADS_url_ms';
$handler->display->display_options['fields']['MADS_url_ms']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['MADS_url_ms']['field'] = 'MADS_url_ms';
$handler->display->display_options['fields']['MADS_url_ms']['label'] = 'URL';
$handler->display->display_options['fields']['MADS_url_ms']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['MADS_url_ms']['alter']['path'] = '[MADS_url_ms]';
$handler->display->display_options['fields']['MADS_url_ms']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['MADS_url_ms']['link_to_object'] = 0;
/* Field: Islandora Solr: MADS_department_mls */
$handler->display->display_options['fields']['MADS_department_mls']['id'] = 'MADS_department_mls';
$handler->display->display_options['fields']['MADS_department_mls']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['MADS_department_mls']['field'] = 'MADS_department_mls';
$handler->display->display_options['fields']['MADS_department_mls']['label'] = 'Scholars';
$handler->display->display_options['fields']['MADS_department_mls']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['MADS_department_mls']['alter']['text'] = '<a href=\'/islandora/search/MADS_parent_organization_ms%3A("[MADS_department_mls]")\'>View Scholars</a>';
$handler->display->display_options['fields']['MADS_department_mls']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['MADS_department_mls']['link_to_object'] = 0;
/* Field: Islandora Solr: fgs_label_s */
$handler->display->display_options['fields']['fgs_label_s']['id'] = 'fgs_label_s';
$handler->display->display_options['fields']['fgs_label_s']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['fgs_label_s']['field'] = 'fgs_label_s';
$handler->display->display_options['fields']['fgs_label_s']['label'] = 'Publications';
$handler->display->display_options['fields']['fgs_label_s']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['fgs_label_s']['alter']['text'] = '<a href=\'/islandora/search/mods_parent_organization_ms%3A("[fgs_label_s]")\'>View Publications</a>';
$handler->display->display_options['fields']['fgs_label_s']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['fgs_label_s']['link_to_object'] = 0;
/* Filter criterion: Islandora Solr: MADS_department_mt */
$handler->display->display_options['filters']['MADS_department_mt']['id'] = 'MADS_department_mt';
$handler->display->display_options['filters']['MADS_department_mt']['table'] = 'islandora_solr';
$handler->display->display_options['filters']['MADS_department_mt']['field'] = 'MADS_department_mt';
$handler->display->display_options['filters']['MADS_department_mt']['value'] = '*';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'browse_dept';

return $view;
}

function flvc_ir_custom_get_view_browse_scholars() {

$view = new view();
$view->name = 'browse_scholars';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'islandora_solr';
$view->human_name = 'browse_scholars';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'All Scholars';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'datatables';
$handler->display->display_options['style_options']['columns'] = array(
  'MADS_family_mls' => 'MADS_family_mls',
  'MADS_fullname_ms' => 'MADS_fullname_ms',
  'MADS_organization_ms' => 'MADS_organization_ms',
  'MADS_email_ms' => 'MADS_email_ms',
  'MADS_status_ms' => 'MADS_status_ms',
  'MADS_u1_ms' => 'MADS_u1_ms',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'MADS_family_mls' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'MADS_fullname_ms' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'MADS_organization_ms' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'MADS_email_ms' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'MADS_status_ms' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'MADS_u1_ms' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['style_options']['elements'] = array(
  'search_box' => 1,
  'table_info' => 1,
  'save_state' => 0,
);
$handler->display->display_options['style_options']['layout'] = array(
  'autowidth' => 0,
  'themeroller' => 0,
  'sdom' => '',
);
$handler->display->display_options['style_options']['pages'] = array(
  'pagination_style' => '0',
  'length_change' => 0,
  'display_length' => '50',
);
/* Field: Islandora Solr: MADS_family_mls */
$handler->display->display_options['fields']['MADS_family_mls']['id'] = 'MADS_family_mls';
$handler->display->display_options['fields']['MADS_family_mls']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['MADS_family_mls']['field'] = 'MADS_family_mls';
$handler->display->display_options['fields']['MADS_family_mls']['label'] = '';
$handler->display->display_options['fields']['MADS_family_mls']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['MADS_family_mls']['link_to_object'] = 0;
/* Field: Islandora Solr: MADS_fullname_ms */
$handler->display->display_options['fields']['MADS_fullname_ms']['id'] = 'MADS_fullname_ms';
$handler->display->display_options['fields']['MADS_fullname_ms']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['MADS_fullname_ms']['field'] = 'MADS_fullname_ms';
$handler->display->display_options['fields']['MADS_fullname_ms']['label'] = 'Fullname';
$handler->display->display_options['fields']['MADS_fullname_ms']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['MADS_fullname_ms']['link_to_object'] = 1;
/* Field: Islandora Solr: MADS_organization_ms */
$handler->display->display_options['fields']['MADS_organization_ms']['id'] = 'MADS_organization_ms';
$handler->display->display_options['fields']['MADS_organization_ms']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['MADS_organization_ms']['field'] = 'MADS_organization_ms';
$handler->display->display_options['fields']['MADS_organization_ms']['label'] = 'Department(s)';
$handler->display->display_options['fields']['MADS_organization_ms']['alter']['path'] = '/islandora/search/MADS_organization_ms%3A("[MADS_organization_ms]")?sort=MADS_family_s asc';
$handler->display->display_options['fields']['MADS_organization_ms']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['MADS_organization_ms']['link_to_object'] = 0;
/* Field: Islandora Solr: MADS_email_ms */
$handler->display->display_options['fields']['MADS_email_ms']['id'] = 'MADS_email_ms';
$handler->display->display_options['fields']['MADS_email_ms']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['MADS_email_ms']['field'] = 'MADS_email_ms';
$handler->display->display_options['fields']['MADS_email_ms']['label'] = 'Email';
$handler->display->display_options['fields']['MADS_email_ms']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['MADS_email_ms']['alter']['text'] = '<a href="mailto:[MADS_email_ms]">[MADS_email_ms]</a>';
$handler->display->display_options['fields']['MADS_email_ms']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['MADS_email_ms']['link_to_object'] = 0;
/* Field: Islandora Solr: MADS_status_ms */
$handler->display->display_options['fields']['MADS_status_ms']['id'] = 'MADS_status_ms';
$handler->display->display_options['fields']['MADS_status_ms']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['MADS_status_ms']['field'] = 'MADS_status_ms';
$handler->display->display_options['fields']['MADS_status_ms']['label'] = 'Status';
$handler->display->display_options['fields']['MADS_status_ms']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['MADS_status_ms']['link_to_object'] = 0;
/* Field: Islandora Solr: MADS_u1_ms */
$handler->display->display_options['fields']['MADS_u1_ms']['id'] = 'MADS_u1_ms';
$handler->display->display_options['fields']['MADS_u1_ms']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['MADS_u1_ms']['field'] = 'MADS_u1_ms';
$handler->display->display_options['fields']['MADS_u1_ms']['label'] = 'Publications';
$handler->display->display_options['fields']['MADS_u1_ms']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['MADS_u1_ms']['alter']['text'] = '<a href=\'/islandora/search?type=edismax&f[0]=mods_name_nameIdentifier_ms:("[MADS_u1_ms]")&sort=date_sort_dt desc\'>Publications</a>';
$handler->display->display_options['fields']['MADS_u1_ms']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['MADS_u1_ms']['link_to_object'] = 0;
/* Contextual filter: Islandora Solr: MADS_organization_ms */
$handler->display->display_options['arguments']['MADS_organization_ms']['id'] = 'MADS_organization_ms';
$handler->display->display_options['arguments']['MADS_organization_ms']['table'] = 'islandora_solr';
$handler->display->display_options['arguments']['MADS_organization_ms']['field'] = 'MADS_organization_ms';
$handler->display->display_options['arguments']['MADS_organization_ms']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['MADS_organization_ms']['default_argument_skip_url'] = TRUE;
$handler->display->display_options['arguments']['MADS_organization_ms']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['MADS_organization_ms']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['MADS_organization_ms']['summary_options']['items_per_page'] = '25';
/* Filter criterion: Islandora Solr: MADS_u1_mt */
$handler->display->display_options['filters']['MADS_u1_mt']['id'] = 'MADS_u1_mt';
$handler->display->display_options['filters']['MADS_u1_mt']['table'] = 'islandora_solr';
$handler->display->display_options['filters']['MADS_u1_mt']['field'] = 'MADS_u1_mt';
$handler->display->display_options['filters']['MADS_u1_mt']['value'] = '*';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'browse_scholars';

return $view;
}

function flvc_ir_custom_get_view_browse_scholars_by_dept() {

$view = new view();
$view->name = 'browse_scholars_by_dept';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'islandora_solr';
$view->human_name = 'browse_scholars_by_dept';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Department Scholars';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'datatables';
$handler->display->display_options['style_options']['columns'] = array(
  'MADS_family_mls' => 'MADS_family_mls',
  'PID' => 'PID',
  'MADS_fullname_ms' => 'MADS_fullname_ms',
  'MADS_organization_ms' => 'MADS_organization_ms',
  'MADS_email_ms' => 'MADS_email_ms',
  'MADS_status_ms' => 'MADS_status_ms',
  'MADS_u1_ms' => 'MADS_u1_ms',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'MADS_family_mls' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'PID' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'MADS_fullname_ms' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'MADS_organization_ms' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'MADS_email_ms' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'MADS_status_ms' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'MADS_u1_ms' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['style_options']['elements'] = array(
  'search_box' => 0,
  'table_info' => 1,
  'save_state' => 0,
);
$handler->display->display_options['style_options']['layout'] = array(
  'autowidth' => 0,
  'themeroller' => 0,
  'sdom' => '',
);
$handler->display->display_options['style_options']['pages'] = array(
  'pagination_style' => '0',
  'length_change' => 0,
  'display_length' => '10',
);
/* Field: Islandora Solr: MADS_family_mls */
$handler->display->display_options['fields']['MADS_family_mls']['id'] = 'MADS_family_mls';
$handler->display->display_options['fields']['MADS_family_mls']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['MADS_family_mls']['field'] = 'MADS_family_mls';
$handler->display->display_options['fields']['MADS_family_mls']['label'] = '';
$handler->display->display_options['fields']['MADS_family_mls']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['MADS_family_mls']['link_to_object'] = 0;
/* Field: Islandora Solr: PID */
$handler->display->display_options['fields']['PID']['id'] = 'PID';
$handler->display->display_options['fields']['PID']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['PID']['field'] = 'PID';
$handler->display->display_options['fields']['PID']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['PID']['alter']['text'] = '<a href="/islandora/object/[PID]"><img src="/islandora/object/[PID]/datastream/TN/view" height="50" width="50"></a>';
$handler->display->display_options['fields']['PID']['link_to_object'] = 0;
/* Field: Islandora Solr: MADS_fullname_ms */
$handler->display->display_options['fields']['MADS_fullname_ms']['id'] = 'MADS_fullname_ms';
$handler->display->display_options['fields']['MADS_fullname_ms']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['MADS_fullname_ms']['field'] = 'MADS_fullname_ms';
$handler->display->display_options['fields']['MADS_fullname_ms']['label'] = 'Fullname';
$handler->display->display_options['fields']['MADS_fullname_ms']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['MADS_fullname_ms']['link_to_object'] = 1;
/* Field: Islandora Solr: MADS_fieldOfActivity_ms */
$handler->display->display_options['fields']['MADS_fieldOfActivity_ms']['id'] = 'MADS_fieldOfActivity_ms';
$handler->display->display_options['fields']['MADS_fieldOfActivity_ms']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['MADS_fieldOfActivity_ms']['field'] = 'MADS_fieldOfActivity_ms';
$handler->display->display_options['fields']['MADS_fieldOfActivity_ms']['label'] = 'Research Interests';
$handler->display->display_options['fields']['MADS_fieldOfActivity_ms']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['MADS_fieldOfActivity_ms']['link_to_object'] = 0;
/* Field: Islandora Solr: MADS_email_ms */
$handler->display->display_options['fields']['MADS_email_ms']['id'] = 'MADS_email_ms';
$handler->display->display_options['fields']['MADS_email_ms']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['MADS_email_ms']['field'] = 'MADS_email_ms';
$handler->display->display_options['fields']['MADS_email_ms']['label'] = 'Email';
$handler->display->display_options['fields']['MADS_email_ms']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['MADS_email_ms']['alter']['text'] = '<a href="mailto:[MADS_email_ms]">[MADS_email_ms]</a>';
$handler->display->display_options['fields']['MADS_email_ms']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['MADS_email_ms']['link_to_object'] = 0;
/* Field: Islandora Solr: MADS_status_ms */
$handler->display->display_options['fields']['MADS_status_ms']['id'] = 'MADS_status_ms';
$handler->display->display_options['fields']['MADS_status_ms']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['MADS_status_ms']['field'] = 'MADS_status_ms';
$handler->display->display_options['fields']['MADS_status_ms']['label'] = 'Status';
$handler->display->display_options['fields']['MADS_status_ms']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['MADS_status_ms']['link_to_object'] = 0;
/* Field: Islandora Solr: MADS_u1_ms */
$handler->display->display_options['fields']['MADS_u1_ms']['id'] = 'MADS_u1_ms';
$handler->display->display_options['fields']['MADS_u1_ms']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['MADS_u1_ms']['field'] = 'MADS_u1_ms';
$handler->display->display_options['fields']['MADS_u1_ms']['label'] = 'Publications';
$handler->display->display_options['fields']['MADS_u1_ms']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['MADS_u1_ms']['alter']['text'] = '<a href=\'/islandora/search?type=edismax&f[0]=mods_name_nameIdentifier_mt:("[MADS_u1_ms]")&sort=date_sort_dt desc\'>Publications</a>';
$handler->display->display_options['fields']['MADS_u1_ms']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['MADS_u1_ms']['link_to_object'] = 0;
/* Contextual filter: Islandora Solr: MADS_parent_organization_ms */
$handler->display->display_options['arguments']['MADS_parent_organization_ms']['id'] = 'MADS_parent_organization_ms';
$handler->display->display_options['arguments']['MADS_parent_organization_ms']['table'] = 'islandora_solr';
$handler->display->display_options['arguments']['MADS_parent_organization_ms']['field'] = 'MADS_parent_organization_ms';
$handler->display->display_options['arguments']['MADS_parent_organization_ms']['default_action'] = 'not found';
$handler->display->display_options['arguments']['MADS_parent_organization_ms']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['MADS_parent_organization_ms']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['MADS_parent_organization_ms']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['MADS_parent_organization_ms']['summary_options']['items_per_page'] = '25';
/* Filter criterion: Islandora Solr: MADS_u1_mt */
$handler->display->display_options['filters']['MADS_u1_mt']['id'] = 'MADS_u1_mt';
$handler->display->display_options['filters']['MADS_u1_mt']['table'] = 'islandora_solr';
$handler->display->display_options['filters']['MADS_u1_mt']['field'] = 'MADS_u1_mt';
$handler->display->display_options['filters']['MADS_u1_mt']['value'] = '*';

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block');

return $view;
}

function flvc_ir_custom_get_view_child_departments() {

$view = new view();
$view->name = 'child_departments';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'islandora_solr';
$view->human_name = 'child_departments';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Child Departments';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'datatables';
$handler->display->display_options['style_options']['columns'] = array(
  'MADS_department_ms' => 'MADS_department_ms',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'MADS_department_ms' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['style_options']['elements'] = array(
  'search_box' => 0,
  'table_info' => 1,
  'save_state' => 0,
);
$handler->display->display_options['style_options']['layout'] = array(
  'autowidth' => 0,
  'themeroller' => 0,
  'sdom' => '',
);
$handler->display->display_options['style_options']['pages'] = array(
  'pagination_style' => 'no_pagination',
  'length_change' => 0,
  'display_length' => '10',
);
/* Field: Islandora Solr: MADS_department_ms */
$handler->display->display_options['fields']['MADS_department_ms']['id'] = 'MADS_department_ms';
$handler->display->display_options['fields']['MADS_department_ms']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['MADS_department_ms']['field'] = 'MADS_department_ms';
$handler->display->display_options['fields']['MADS_department_ms']['label'] = 'Child Departments';
$handler->display->display_options['fields']['MADS_department_ms']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['MADS_department_ms']['link_to_object'] = 1;
/* Contextual filter: Islandora Solr: MADS_parent_institution_ms */
$handler->display->display_options['arguments']['MADS_parent_institution_ms']['id'] = 'MADS_parent_institution_ms';
$handler->display->display_options['arguments']['MADS_parent_institution_ms']['table'] = 'islandora_solr';
$handler->display->display_options['arguments']['MADS_parent_institution_ms']['field'] = 'MADS_parent_institution_ms';
$handler->display->display_options['arguments']['MADS_parent_institution_ms']['default_action'] = 'not found';
$handler->display->display_options['arguments']['MADS_parent_institution_ms']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['MADS_parent_institution_ms']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['MADS_parent_institution_ms']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['MADS_parent_institution_ms']['summary_options']['items_per_page'] = '25';

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'child_organizations');
$handler->display->display_options['block_description'] = 'child_organizations';

return $view;
}

function flvc_ir_custom_get_view_other_scholars_in_dept() {

$view = new view();
$view->name = 'other_scholars_in_dept';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'islandora_solr';
$view->human_name = 'other_scholars_in_dept';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'other_scholars_in_dept';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '5';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
/* Field: Islandora Solr: MADS_title_ms */
$handler->display->display_options['fields']['MADS_title_ms']['id'] = 'MADS_title_ms';
$handler->display->display_options['fields']['MADS_title_ms']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['MADS_title_ms']['field'] = 'MADS_title_ms';
$handler->display->display_options['fields']['MADS_title_ms']['label'] = '';
$handler->display->display_options['fields']['MADS_title_ms']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['MADS_title_ms']['link_to_object'] = 1;
/* Contextual filter: Islandora Solr: MADS_organization_ms */
$handler->display->display_options['arguments']['MADS_organization_ms']['id'] = 'MADS_organization_ms';
$handler->display->display_options['arguments']['MADS_organization_ms']['table'] = 'islandora_solr';
$handler->display->display_options['arguments']['MADS_organization_ms']['field'] = 'MADS_organization_ms';
$handler->display->display_options['arguments']['MADS_organization_ms']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['MADS_organization_ms']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['MADS_organization_ms']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['MADS_organization_ms']['summary_options']['items_per_page'] = '25';

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'dept_scholars');

return $view;
}

function flvc_ir_custom_get_view_parent_department() {

$view = new view();
$view->name = 'parent_department';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'islandora_solr';
$view->human_name = 'parent_department';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Parent Department';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'datatables';
$handler->display->display_options['style_options']['columns'] = array(
  'MADS_department_ms' => 'MADS_department_ms',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'MADS_department_ms' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['style_options']['elements'] = array(
  'search_box' => 0,
  'table_info' => 1,
  'save_state' => 0,
);
$handler->display->display_options['style_options']['layout'] = array(
  'autowidth' => 0,
  'themeroller' => 0,
  'sdom' => '',
);
$handler->display->display_options['style_options']['pages'] = array(
  'pagination_style' => 'no_pagination',
  'length_change' => 0,
  'display_length' => '10',
);
/* Field: Islandora Solr: MADS_department_ms */
$handler->display->display_options['fields']['MADS_department_ms']['id'] = 'MADS_department_ms';
$handler->display->display_options['fields']['MADS_department_ms']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['MADS_department_ms']['field'] = 'MADS_department_ms';
$handler->display->display_options['fields']['MADS_department_ms']['label'] = 'Parent Department';
$handler->display->display_options['fields']['MADS_department_ms']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['MADS_department_ms']['link_to_object'] = 1;
/* Contextual filter: Islandora Solr: MADS_department_ms */
$handler->display->display_options['arguments']['MADS_department_ms']['id'] = 'MADS_department_ms';
$handler->display->display_options['arguments']['MADS_department_ms']['table'] = 'islandora_solr';
$handler->display->display_options['arguments']['MADS_department_ms']['field'] = 'MADS_department_ms';
$handler->display->display_options['arguments']['MADS_department_ms']['default_action'] = 'not found';
$handler->display->display_options['arguments']['MADS_department_ms']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['MADS_department_ms']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['MADS_department_ms']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['MADS_department_ms']['summary_options']['items_per_page'] = '25';

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'parent_organization');
$handler->display->display_options['block_description'] = 'parent_organization';

return $view;
}

function flvc_ir_custom_get_view_recent_publications_by_dept() {

$view = new view();
$view->name = 'recent_publications_by_dept';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'islandora_solr';
$view->human_name = 'recent_publications_by_dept';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Recent Publications';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '5';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
/* Field: Islandora Solr: title_display_ms */
$handler->display->display_options['fields']['title_display_ms']['id'] = 'title_display_ms';
$handler->display->display_options['fields']['title_display_ms']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['title_display_ms']['field'] = 'title_display_ms';
$handler->display->display_options['fields']['title_display_ms']['label'] = '';
$handler->display->display_options['fields']['title_display_ms']['element_class'] = 'block--recent-citations--title';
$handler->display->display_options['fields']['title_display_ms']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title_display_ms']['link_to_object'] = 1;
/* Field: Islandora Solr: mods_name_namePart_display_ms */
$handler->display->display_options['fields']['mods_name_namePart_display_ms']['id'] = 'mods_name_namePart_display_ms';
$handler->display->display_options['fields']['mods_name_namePart_display_ms']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['mods_name_namePart_display_ms']['field'] = 'mods_name_namePart_display_ms';
$handler->display->display_options['fields']['mods_name_namePart_display_ms']['label'] = '';
$handler->display->display_options['fields']['mods_name_namePart_display_ms']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['mods_name_namePart_display_ms']['link_to_object'] = 0;
/* Field: Islandora Solr: mods_originInfo_dateIssued_ms */
$handler->display->display_options['fields']['mods_originInfo_dateIssued_ms']['id'] = 'mods_originInfo_dateIssued_ms';
$handler->display->display_options['fields']['mods_originInfo_dateIssued_ms']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['mods_originInfo_dateIssued_ms']['field'] = 'mods_originInfo_dateIssued_ms';
$handler->display->display_options['fields']['mods_originInfo_dateIssued_ms']['label'] = '';
$handler->display->display_options['fields']['mods_originInfo_dateIssued_ms']['element_class'] = 'block--recent-citations--date';
$handler->display->display_options['fields']['mods_originInfo_dateIssued_ms']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['mods_originInfo_dateIssued_ms']['link_to_object'] = 0;
/* Sort criterion: Islandora Solr: date_sort_dt */
$handler->display->display_options['sorts']['date_sort_dt']['id'] = 'date_sort_dt';
$handler->display->display_options['sorts']['date_sort_dt']['table'] = 'islandora_solr';
$handler->display->display_options['sorts']['date_sort_dt']['field'] = 'date_sort_dt';
$handler->display->display_options['sorts']['date_sort_dt']['order'] = 'DESC';
/* Contextual filter: Islandora Solr: mods_parent_organization_ms */
$handler->display->display_options['arguments']['mods_parent_organization_ms']['id'] = 'mods_parent_organization_ms';
$handler->display->display_options['arguments']['mods_parent_organization_ms']['table'] = 'islandora_solr';
$handler->display->display_options['arguments']['mods_parent_organization_ms']['field'] = 'mods_parent_organization_ms';
$handler->display->display_options['arguments']['mods_parent_organization_ms']['default_action'] = 'not found';
$handler->display->display_options['arguments']['mods_parent_organization_ms']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['mods_parent_organization_ms']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['mods_parent_organization_ms']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['mods_parent_organization_ms']['summary_options']['items_per_page'] = '25';

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'publications_by_dept');
$handler->display->display_options['block_description'] = 'publications_by_dept';

return $view;
}

function flvc_ir_custom_get_view_recent_publications_by_scholar() {

$view = new view();
$view->name = 'recent_publications_by_scholar';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'islandora_solr';
$view->human_name = 'recent_publications_by_scholar';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Recent Publications';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '5';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
/* Field: Islandora Solr: title_display_ms */
$handler->display->display_options['fields']['title_display_ms']['id'] = 'title_display_ms';
$handler->display->display_options['fields']['title_display_ms']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['title_display_ms']['field'] = 'title_display_ms';
$handler->display->display_options['fields']['title_display_ms']['label'] = '';
$handler->display->display_options['fields']['title_display_ms']['element_class'] = 'block--recent-citations--title';
$handler->display->display_options['fields']['title_display_ms']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title_display_ms']['link_to_object'] = 1;
/* Field: Islandora Solr: mods_originInfo_dateIssued_ms */
$handler->display->display_options['fields']['mods_originInfo_dateIssued_ms']['id'] = 'mods_originInfo_dateIssued_ms';
$handler->display->display_options['fields']['mods_originInfo_dateIssued_ms']['table'] = 'islandora_solr';
$handler->display->display_options['fields']['mods_originInfo_dateIssued_ms']['field'] = 'mods_originInfo_dateIssued_ms';
$handler->display->display_options['fields']['mods_originInfo_dateIssued_ms']['label'] = '';
$handler->display->display_options['fields']['mods_originInfo_dateIssued_ms']['element_class'] = 'block--recent-citations--date';
$handler->display->display_options['fields']['mods_originInfo_dateIssued_ms']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['mods_originInfo_dateIssued_ms']['link_to_object'] = 0;
/* Sort criterion: Islandora Solr: date_sort_dt */
$handler->display->display_options['sorts']['date_sort_dt']['id'] = 'date_sort_dt';
$handler->display->display_options['sorts']['date_sort_dt']['table'] = 'islandora_solr';
$handler->display->display_options['sorts']['date_sort_dt']['field'] = 'date_sort_dt';
$handler->display->display_options['sorts']['date_sort_dt']['order'] = 'DESC';
/* Contextual filter: Islandora Solr: mods_name_nameIdentifier_mt */
$handler->display->display_options['arguments']['mods_name_nameIdentifier_mt']['id'] = 'mods_name_nameIdentifier_mt';
$handler->display->display_options['arguments']['mods_name_nameIdentifier_mt']['table'] = 'islandora_solr';
$handler->display->display_options['arguments']['mods_name_nameIdentifier_mt']['field'] = 'mods_name_nameIdentifier_mt';
$handler->display->display_options['arguments']['mods_name_nameIdentifier_mt']['default_action'] = 'empty';
$handler->display->display_options['arguments']['mods_name_nameIdentifier_mt']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['mods_name_nameIdentifier_mt']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['mods_name_nameIdentifier_mt']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['mods_name_nameIdentifier_mt']['summary_options']['items_per_page'] = '25';

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'publications_by_scholar');
$handler->display->display_options['block_description'] = 'publications_by_scholar';

return $view;
}
