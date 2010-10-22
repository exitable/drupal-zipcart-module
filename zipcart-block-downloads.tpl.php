<?php
/**
 * Template to display My Downloads link.
 */
 ?>
<div class="zipcart-block-downloads">
  <?php print l('My Downloads', 'zipcart/get', array('query' => _zipcart_get_destination_alias())) ; ?>
</div>