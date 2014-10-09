<?php

/**
 * @file
 * ZipCart admin pages.
 */

/**
 * Settings form
 */
function zipcart_settings_form() {
  $methods = _zipcart_get_available_methods();
  foreach ($methods as $k => $v) {
    $zipcart_zip_method_options[$k] = $v['title'];
  }
  $form['zipcart_zip_method'] = array(
    '#title' => t('Zip Method'),
    '#type' => 'select',
    '#default_value' => variable_get('zipcart_zip_method', ''),
    '#options' => $zipcart_zip_method_options,
    '#description' => t('Method used to generate bundle files.'),
  );

  $form['zipcart_field_formatting'] = array(
    '#type' => 'fieldset',
    '#title' => t('Field formatting settings'),
    '#collapsible' => true,
  );

  $form['zipcart_field_formatting']['zipcart_field_display'] = array(
    '#title' => t('File Display'),
    '#type' => 'select',
    '#default_value' => variable_get('zipcart_field_display', 'link'),
    '#options' => array(
      'link' => t('Filename as link'),
      'checkbox' => t('Checkbox')
    ),
    '#description' => t('How to display the ZipCart related links. Checkbox works with enabled javascript, only.'),
  );

  $form['zipcart_field_formatting']['zipcart_remove_hotlink'] = array(
    '#type' => 'checkbox',
    '#title' => t('Remove direct links to file.'),
    '#default_value' => variable_get('zipcart_remove_hotlink', 0),
    '#description' => t('Whether or not hotlinks to files (for direct download) should stay or be removed.'),
  );

  $form['zipcart_field_formatting']['zipcart_node_types'] = array(
    '#type' => 'fieldset',
    '#title' => t('Node types'),
    '#collapsible' => true,
    '#collapsed' => true,
    '#description' => t('Only selected node types will use the ZipCart field formatters. If none is selected, all node types will be affected.'),
  );
  var_dump(variable_get('zipcart_node_types_active'));
  $node_types = node_type_get_types();
  $zipcart_node_types_options = array();
  foreach ($node_types AS $machine_name => $node_type) {
    $zipcart_node_types_options[$machine_name] = $node_type->name;
  }
  $form['zipcart_field_formatting']['zipcart_node_types']['zipcart_node_types_active'] = array(
    '#type' => 'checkboxes',
    '#options' => $zipcart_node_types_options,
    '#default_value' => variable_get('zipcart_node_types_active'),
  );

  return system_settings_form($form);
}
