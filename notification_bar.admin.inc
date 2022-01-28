<?php

/**
 * @file
 * Notification Bar module admin functions.
 */

/**
 * Implements hook_admin_settings().
 */
function notification_bar_admin_settings_form($form, $form_state) {
  $config = config('notification_bar.settings');
  $form = array();
  $form['#config'] = 'notification_bar.settings';

  $form['message'] = array(
    '#type' => 'fieldset',
    '#title' => t('Message'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['message']['message_label'] = array(
    '#type' => 'textfield',
    '#title' => t('Label'),
    '#default_value' => $config->get('message_label'),
    '#weight' => -2,
  );
  $notification_bar_message_array = $config->get('message');
  $form['message']['message'] = array(
    '#type' => 'text_format',
    '#title' => t('Message'),
    '#default_value' => isset($notification_bar_message_array['value']) ? $notification_bar_message_array['value'] : '',
    '#format' => isset($notification_bar_message_array['format']) ? $notification_bar_message_array['format'] : 'filtered_html',
    '#weight' => -1,
  );
  $form['message']['cta'] = array(
    '#type' => 'link_field',
    '#title' => t('Call to Action'),
    '#default_value' => array(
      'url' => $config->get('cta.url'),
      'title' => $config->get('cta.title'),
    ),
  );

  $form['settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $options = array(
    0 => t('All pages except those listed'),
    1 => t('Only the listed pages'),
  );
  $description = t("Specify pages by using their paths. Enter one path per line. The '*' character is a wildcard. Example paths are %blog for the blog page and %blog-wildcard for every personal blog. %front is the front page.", array('%blog' => 'blog', '%blog-wildcard' => 'blog/*', '%front' => '<front>'));
  $form['settings']['page_visibility'] = array(
    '#type' => 'radios',
    '#title' => t('Show notification on specific pages'),
    '#options' => $options,
    '#default_value' => $config->get('page_visibility'),
  );
  $form['settings']['page_custom'] = array(
    '#type' => 'textarea',
    '#title' => '<span class="element-invisible">' . t('Pages') . '</span>',
    '#default_value' => $config->get('page_custom'),
    '#description' => $description,
  );
  $form['settings']['settings_css'] = array(
    '#type' => 'checkbox',
    '#title' => t('Load default CSS'),
    '#default_value' => $config->get('settings_css'),
    '#description' => t("Uncheck if you don't want to use the module's default CSS."),
  );
  $form['settings']['settings_container'] = array(
    '#type' => 'checkbox',
    '#title' => t('Add a container class to the notification bar'),
    '#default_value' => $config->get('settings_container'),
  );

  // Add a submit button
  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );

  return $form;
}

/**
 * Submit handler for notification_bar_admin_settings_form().
 */
function notification_bar_admin_settings_form_submit($form, &$form_state) {
  $config = config('notification_bar.settings');
  $config->set('message_label', $form_state['values']['message_label']);
  $config->set('message', $form_state['values']['message']);
  $config->set('cta.url', $form_state['values']['url']);
  $config->set('cta.title', $form_state['values']['title']);
  $config->set('page_visibility', $form_state['values']['page_visibility']);
  $config->set('page_custom', $form_state['values']['page_custom']);
  $config->set('settings_css', $form_state['values']['settings_css']);
  $config->set('settings_container', $form_state['values']['settings_container']);
  $config->save();

  backdrop_set_message(t('The configuration options have been saved.'));
}
