Drupal.behaviors.zipcart = function() {
    $('a.zipcart').click( function(e) {
      if ( e.target.tagName.toLowerCase() == 'a' ) {
        a = e.target ;
      }
      else {
        if ( a = $(e.target).parents('a[href]') ) {
          // found parent a
        }
        else {
          return ;
        }
      }
      e.preventDefault();
      // add AJAX parameter
      filePath = $(a).attr('href').replace(Drupal.settings.zipcart.path_add, Drupal.settings.zipcart.path_add_ajax) ;
      // add Drupal basePath
      filePath = Drupal.settings.basePath + filePath ;
      // remove multiple slashes at start
      filePath = filePath.replace(/^\/+/, '/');
      $.ajax({
        'url': filePath,
        'dataType': 'json',
        success: function(data, textStatus, req) {
          Drupal.settings.zipcart.cart = data.cart ;
          slide = $(e.target).clone();
          cart = $('.zipcart-block-downloads');
          // generate a slide-able copy of whatever was clicked.
          // it would be really nice if this could be attached to 
          // a related image, eg thumbnail version of the photo
          // instead of the 'download' link text ...
          slide.hide();
          slide.css({ position: 'absolute', top: $(e.target).offset().top, left: $(e.target).offset().left, opacity: 0.75 });
          slide.appendTo($('body'));
          slide.show();
          animProps = {
            position: 'absolute', 
            top:  cart.offset().top  + ( ( $(cart).height() - $(e.target).height()/2 ) / 2 ), 
            left: cart.offset().left + ( ( $(cart).width()  - $(e.target).width()/2  ) / 2 ), 
            width: $(slide).width()/2, 
            height: $(slide).height/2 
          };
          animCallback = function(data) {
            $(slide).hide() ;
            $('.zipcart-download-count').html( Drupal.settings.zipcart.cart.length ) ;
          }
          slide.animate(animProps, 'slow', 'swing', animCallback);
        },
        error: function(req, textStatus, errorThrown) {
          alert('Unable to add the file to your ZipCart.');
          console.log(req);
          console.log(textStatus);
          console.log(errorThrown);
          switch ( textStatus ) {
            case 'timeout' :
            case 'null' :
            case 'error' :
            case 'parsererror' :
            case 'notmodified' :
            default :
              break ;
          }
          // probably not permitted - handle file access restriction here
        },
      });
    }) ;
} ;