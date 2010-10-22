Drupal.behaviors.zipcart = function() {
    $('a.zipcart').click( function(e) {
      e.preventDefault();
      if ( a = $(e.target).closest('a[href]') ) {
        // add AJAX parameter
        filePath = $(a).attr('href').replace(Drupal.settings.zipcart.path_add, Drupal.settings.zipcart.path_add_ajax) ;
        // add Drupal basePath
        filePath = Drupal.settings.basePath + filePath ;
        // remove multiple slashes at start
        filePath = filePath.replace(/^\/+/, '/');
        $.ajax({
          'url': filePath,
          success: function(data, textStatus, req) {
            // 
            // console.log(data);
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
      }
    } ) ;
} ;