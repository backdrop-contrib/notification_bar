Backdrop.notification_bar = Backdrop.notification_bar || {};

(function ($) {

  Backdrop.notification_bar.initialize = function(){
      // Move messages from closure to right after opening of body tag.
      $("body").prepend($("#notification-bar-messages"));
  };

  $(document).ready(function(){
    Backdrop.notification_bar.initialize();
  });

})(jQuery);
