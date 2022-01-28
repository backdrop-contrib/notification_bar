<div class="clearfix notification-bar-message notification-bar-<?php print $vars['type']; ?> <?php print $vars['container_class']; ?>">
  <?php if (!empty($vars['message']['message_label'])): ?>
    <div class="message-label">
      <?php print $vars['message']['message_label']; ?>
    </div>
  <?php endif; ?>
  <?php if (!empty($vars['message']['message_text'])): ?>
    <div class="content">
      <?php print $vars['message']['message_text']; ?>
    </div>
  <?php endif; ?>
  <?php if (!empty($vars['message']['cta_text'])): ?>
    <div class="message-cta">
      <a class="button" href="<?php print $vars['message']['cta_url']; ?>"><?php print $vars['message']['cta_text']; ?></a>
    </div>
  <?php endif; ?>
</div>
