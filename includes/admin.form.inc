<?php

/**
 * @file
 * Administration page callbacks for the FLVC IR Custom module.
 */

/**
 * FLVC IR Custom administration and configuration form.
 *
 * @ingroup forms
 *
 * @return array
 *   The Drupal form definition.
 */
function flvc_ir_custom_admin_form() {
  $form = array();

  $form['flvc_ir_custom_root_organization_pid'] = array(
    '#type' => 'textfield',
    '#title' => t('PID of Root Organization'),
    '#description' => t('Enter the PID of the root organization for the institutional repository.'),
    '#default_value' => variable_get('flvc_ir_custom_root_organization_pid', ''),
  );

  $form['save_configuration'] = array(
    '#type' => 'submit',
    '#name' => 'saveConfiguration',
    '#default_value' => t('Save configuration'),
  );

  return $form;
}

/**
 * Submit handler for the admin form for the FLVC IR Custom module.
 *
 * @param array $form
 *   An array representing a form in Drupal.
 * @param array $form_state
 *   An array containing the Drupal form state.
 */
function flvc_ir_custom_admin_form_submit($form, &$form_state) {
    variable_set('flvc_ir_custom_root_organization_pid', $form_state['values']['flvc_ir_custom_root_organization_pid']);

    if ($form_state['values']['flvc_ir_custom_root_organization_pid'] != '') {
      drupal_set_message("{$form_state['values']['flvc_ir_custom_root_organization_pid']} has been set as the root organization.");
    }
    else {
      drupal_set_message("You have chosen not to set a root organization.");
    }
    
}
