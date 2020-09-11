<?php

/**
 * Settings form.
 */
function imc_config_form() {
  $form = array();

  // API Settings
  $form['imc']['api'] = array(
    '#type' => 'fieldset',
    '#title' => t('API Settings'),
  );
  $form['imc']['api']['imc_username'] = array(
    '#type' => 'textfield',
    '#title' => t('Username'),
    '#description' => t('Username for HTTP BASIC AUTH.'),
    '#default_value' => variable_get('imc_username', ''),
    '#required' => TRUE,
  );
  $form['imc']['api']['imc_password'] = array(
    '#type' => 'textfield',
    '#title' => t('Password'),
    '#description' => t('Password for HTTP BASIC AUTH.'),
    '#default_value' => variable_get('imc_password', ''),
    '#required' => TRUE,
  );
  $form['imc']['api']['imc_tenant'] = array(
    '#type' => 'select',
    '#title' => t('Tenant'),
    '#options' => array('/pages/internal-dashboard.jsf?dashboardId=1&client=Client' => 'Client'),
    '#default_value' => variable_get('imc_tenant', ''),
    '#required' => TRUE,
  );
  $form['imc']['api']['imc_environment'] = array(
    '#type' => 'select',
    '#title' => t('Environment'),
    '#options' => array('DEV' => 'Development', 'STAGE' => 'Staging/Pre-Production', 'PROD' => 'Production'),
    '#default_value' => variable_get('imc_environment', ''),
    '#required' => TRUE,
  );
  return system_settings_form($form);
}

/**
 * Field mapping form.
 */
function imc_field_mapping_form() {
  $form = array();

  $options = array();
  $fields = field_info_instances('user');
  if(array_key_exists('user', $fields) && is_array($fields['user'])) {
    foreach($fields['user'] as $k=>$v) {
      $options[$k] = $v['label'];
    }
    $form['imc']['mappings']['imc_field_mappings'] = array(
      '#type' => 'fieldset',
      '#title' => t('Field Mappings'), 
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#tree' => TRUE,
    );

    $data = _imc_get_fields();
    $selected_options = variable_get('imc_field_mappings', array());
    foreach($data as $row) {
      $form['imc']['mappings']['imc_field_mappings'][check_plain($row->key)] = array(
        '#type' => 'select',
        '#title' => check_plain(t($row->label)),
        '#options' => $options,
        '#default_value' => isset($selected_options[check_plain($row->key)]) ? $selected_options[check_plain($row->key)] : '',
        '#required' => TRUE,
      );
    }
  }
  return system_settings_form($form);
}

/**
 * Get IMC fields
 */
function _imc_get_fields() {
  return db_select('imc_fields', 'f')->fields('f')->execute()->fetchAll();
}
