<?php

/**
 * @file
 * Absolute Messages module admin functions.
 */

/**
 * Implements hook_admin_settings().
 */
function notification_bar_admin_settings_form() {
  $config = config('notification_bar.settings');
  $form = array();
  $form['#config'] = 'notification_bar.settings';

  $form['message'] = array(
    '#type' => 'fieldset',
    '#title' => t('Message'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['message']['notification_bar_message_text_left'] = array(
    '#type' => 'textarea',
    '#title' => t('Left Section'),
    '#default_value' => $config->get('notification_bar_message_text_left'),
    '#weight' => -2,
  );
  $notification_bar_message_array = $config->get('notification_bar_message');
  $form['message']['notification_bar_message'] = array(
    '#type' => 'text_format',
    '#title' => t('Message'),
    '#default_value' => isset($notification_bar_message_array['value']) ? $notification_bar_message_array['value'] : '',
    '#format' => isset($notification_bar_message_array['format']) ? $notification_bar_message_array['format'] : '',
    '#weight' => -1,
  );
  $form['message']['cta'] = array(
    '#type' => 'fieldset',
    '#title' => t('CTA'),
    '#description' => 'Call to Action',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['message']['cta']['notification_bar_message_cta_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Label'),
    '#default_value' => $config->get('notification_bar_message_cta_text'),
  );
  $form['message']['cta']['notification_bar_message_cta_url'] = array(
    '#type' => 'textfield',
    '#title' => t('URL'),
    '#default_value' => $config->get('notification_bar_message_cta_url'),
  );

  $form['visibility'] = array(
    '#type' => 'fieldset',
    '#title' => t('Notification Visibility'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $options = array(
    BLOCK_VISIBILITY_NOTLISTED => t('All pages except those listed'),
    BLOCK_VISIBILITY_LISTED => t('Only the listed pages'),
  );
  $description = t("Specify pages by using their paths. Enter one path per line. The '*' character is a wildcard. Example paths are %blog for the blog page and %blog-wildcard for every personal blog. %front is the front page.", array('%blog' => 'blog', '%blog-wildcard' => 'blog/*', '%front' => '<front>'));
  $form['visibility']['notification_bar_page_visibility'] = array(
    '#type' => 'radios',
    '#title' => t('Show notification on specific pages'),
    '#options' => $options,
    '#default_value' => $config->get('notification_bar_page_visibility'),
  );
  $form['visibility']['notification_bar_page_custom'] = array(
    '#type' => 'textarea',
    '#title' => '<span class="element-invisible">' . t('Pages') . '</span>',
    '#default_value' => $config->get('notification_bar_page_custom'),
    '#description' => $description,
  );

  $form['settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['settings']['notification_bar_settings_css'] = array(
    '#type' => 'checkbox',
    '#title' => t('Load default CSS'),
    '#default_value' => $config->get('notification_bar_settings_css'),
    '#description' => t("Uncheck the box, If you don't want to use module's default CSS."),
  );
  $form['settings']['notification_bar_settings_js'] = array(
    '#type' => 'checkbox',
    '#title' => t('Load default JS'),
    '#default_value' => $config->get('notification_bar_settings_js'),
    '#description' => t("Uncheck the box, If you don't want to use Javascript way to align the notification at the top of the page."),
  );

  return system_settings_form($form);
}
