<?php
/**
 * Template to display My Downloads link.
 *
 * $count - number of files in cart currently
 * $files - the files
 */
if ( !$count ) {
  $count = '0' ;
}
 ?>
<div class="zipcart-block-downloads">
  <?php print l(t('My Downloads (<span class="zipcart-download-count">!count</span> files)', array('!count' => $count)), 'zipcart/get', array('html' => TRUE, 'query' => _zipcart_get_destination_alias())) ; ?>
</div>