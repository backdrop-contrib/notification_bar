Backdrop.notification_bar = Backdrop.notification_bar || {};

(function ($) {

  Backdrop.notification_bar.initialize = function () {
    // Move messages from closure to right after opening of body tag.
    $("body > div.layout").prepend($("#notification-bar-messages"));
  };

  $(document).ready(function () {
    Backdrop.notification_bar.initialize();

    var wasScrolled = false;
    var scrollThreshold = 1;

    $(window).on('scroll', function () {
      if ($(this).scrollTop() > scrollThreshold && !wasScrolled) {
        $('#notification-bar-messages').slideUp();
        wasScrolled = true;
      }
    });

  });

})(jQuery);
