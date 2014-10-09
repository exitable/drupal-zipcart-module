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

  $form['zipcart_field_display'] = array(
    '#title' => t('File Display'),
    '#type' => 'select',
    '#default_value' => variable_get('zipcart_field_display', 'link'),
    '#options' => array(
      'link' => t('Filename as link'),
      'checkbox' => t('Checkbox')
    ),
    '#description' => t('How to display the ZipCart related links. Please note that the checkbox method doesn\'t have a fallback for non-javascript visitors.'),
  );

  $form['zipcart_remove_hotlink'] = array(
    '#type' => 'checkbox',
    '#title' => t('Remove direct links to file.'),
    '#default_value' => variable_get('zipcart_remove_hotlink', 0),
    '#description' => t('Whether or not hotlinks to files (for direct download) should stay or be removed.'),
  );
  return system_settings_form($form);
}
