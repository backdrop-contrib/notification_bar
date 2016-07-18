<div class="clearfix notification-bar-message notification-bar-<?php print $vars['type']; ?>">
  <?php if (!empty($vars['message']['message_text_left'])): ?>
    <div class="content-left"><?php print $vars['message']['message_text_left']; ?></div>
  <?php endif; ?>
  <?php if (!empty($vars['message']['message_text'])): ?>
    <div class="content"><?php print $vars['message']['message_text']; ?></div>
  <?php endif; ?>
  <div class="content-right">
    <?php if ($vars['message']['cta_text']): ?>
      <a class="btn" href="<?php print $vars['message']['cta_url']; ?>"><?php print $vars['message']['cta_text']; ?></a>
    <?php endif; ?>
  </div>
</div>
