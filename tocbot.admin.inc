<?php
/**
 * @file
 * Admin form to configure module
 *
 */

/**
 * Configuration form to update module settings.
 */
function tocbot_config_form($form, &$form_state) {

  $config = config('tocbot.settings');
  
  $form['moduleSettings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Module Settings'),
    '#description' => t('Module settings to customize tocbot.'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );
  $form['moduleSettings']['tocbot_extrabodyclass'] = array(
    '#type' => 'textfield',
    '#title' => t('Extra Body Class on Activation'),
    '#description' => t('When the tocbot is activated you can add an extra class
     to the body to adjust the theme of your site if desired. Leave blank if you
      dont need this.'),
    '#default_value' => $config->get('tocbot_extrabodyclass'),
  );
  $form['moduleSettings']['tocbot_tocTitle'] = array(
    '#type' => 'textfield',
    '#title' => t('tocTitle'),
    '#description' => t('An optional title for the TOC, leave blank for none.
    Will be an strong tag with class <code>toc-title</code> so you can theme it'),
    '#default_value' => $config->get('tocbot_tocTitle'),
  );
  $form['moduleSettings']['tocbot_minActivate'] = array(
    '#type' => 'textfield',
    '#title' => t('minActivate (number)'),
    '#description' => t('Only activate if greater than or equal to this many
    headings'),
    '#default_value' => $config->get('tocbot_minActivate'),
  );
  $form['moduleSettings']['tocbot_createAutoIds'] = array(
    '#type' => 'checkbox',
    '#title' => t('Create Automatic Ids'),
    '#description' => t('Using Javascript automatic Ids can be created needed
    for Tocbot to work, or disable it if you have another means of creating ids
    such as a text filter module'),
    '#default_value' => $config->get('tocbot_createAutoIds'),
  );
  $form['moduleSettings']['tocbot_use_local'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use local copy of Tocbot'),
    '#description' => t('Enable if you want to host Tocbot locally (pre-installed for you) instead CDN'),
    '#default_value' => $config->get('tocbot_use_local'),
  );

  // Tocbot Settings tab.
  $form['tocbot_jsSettings'] = array(
    '#type' => 'fieldset',
    '#title' => t('TocBot JS Settings'),
    '#description' => t('Tocbot API settings passed to javascript
    <a href="https://tscanlin.github.io/tocbot/#api">See API for details</a>.'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );
  $form['tocbot_jsSettings']['tocbot_tocSelector'] = array(
    '#type' => 'textfield',
    '#title' => t('tocSelector'),
    '#description' => t('Where to render the table of contents. Place an empty
    div with a unique class into your theme template or use this block itself
    by settings it to <code>.js-toc-block</code>.'),
    '#default_value' => $config->get('tocbot_tocSelector'),
  );
  $form['tocbot_jsSettings']['tocbot_contentSelector'] = array(
    '#type' => 'textfield',
    '#title' => t('contentSelector'),
    '#description' => t('Where to grab the headings to build the table of
    contents.'),
    '#default_value' => $config->get('tocbot_contentSelector'),
  );
  $form['tocbot_jsSettings']['tocbot_headingSelector'] = array(
    '#type' => 'textfield',
    '#title' => t('headingSelector'),
    '#description' => t('Comma and space seperated <code>h2, h3, h4, h5, h6</code>'),
    '#default_value' => $config->get('tocbot_headingSelector'),
  );
  $form['tocbot_jsSettings']['tocbot_ignoreSelector'] = array(
    '#type' => 'textfield',
    '#title' => t('ignoreSelector'),
    '#description' => t('Headings that match the ignoreSelector will be skipped.'),
    '#default_value' => $config->get('tocbot_ignoreSelector'),
  );
  $form['tocbot_jsSettings']['tocbot_linkClass'] = array(
    '#type' => 'textfield',
    '#title' => t('linkClass'),
    '#description' => t('Main class to add to links.'),
    '#default_value' => $config->get('tocbot_linkClass'),
  );
  $form['tocbot_jsSettings']['tocbot_extraLinkClasses'] = array(
    '#type' => 'textfield',
    '#title' => t('extraLinkClasses'),
    '#description' => t('Extra classes to add to links.'),
    '#default_value' => $config->get('tocbot_extraLinkClasses'),
  );
  $form['tocbot_jsSettings']['tocbot_activeLinkClass'] = array(
    '#type' => 'textfield',
    '#title' => t('activeLinkClass'),
    '#description' => t('Class to add to active links, the link corresponding
    to the top most heading on the page.'),
    '#default_value' => $config->get('tocbot_activeLinkClass'),
  );
  $form['tocbot_jsSettings']['tocbot_listClass'] = array(
    '#type' => 'textfield',
    '#title' => t('listClass'),
    '#description' => t('Main class to add to lists.'),
    '#default_value' => $config->get('tocbot_listClass'),
  );
  $form['tocbot_jsSettings']['tocbot_extraListClasses'] = array(
    '#type' => 'textfield',
    '#title' => t('extraListClasses'),
    '#description' => t('Extra classes to add to lists.'),
    '#default_value' => $config->get('tocbot_extraListClasses'),
  );
  $form['tocbot_jsSettings']['tocbot_isCollapsedClass'] = array(
    '#type' => 'textfield',
    '#title' => t('isCollapsedClass'),
    '#description' => t('Class that gets added when a list should be collapsed.'),
    '#default_value' => $config->get('tocbot_isCollapsedClass'),
  );
  $form['tocbot_jsSettings']['tocbot_collapsibleClass'] = array(
    '#type' => 'textfield',
    '#title' => t('collapsibleClass'),
    '#description' => t('Class that gets added when a list should be able to be
    collapsed but isn\'t necessarily collapsed.'),
    '#default_value' => $config->get('tocbot_collapsibleClass'),
  );
  $form['tocbot_jsSettings']['tocbot_listItemClass'] = array(
    '#type' => 'textfield',
    '#title' => t('listItemClass'),
    '#description' => t('Class to add to list items.'),
    '#default_value' => $config->get('tocbot_listItemClass'),
  );
  $form['tocbot_jsSettings']['tocbot_collapseDepth'] = array(
    '#type' => 'textfield',
    '#title' => t('collapseDepth (number)'),
    '#description' => t('Class to add to list items.'),
    '#default_value' => $config->get('tocbot_collapseDepth'),
  );
  $form['tocbot_jsSettings']['tocbot_orderedList'] = array(
    '#type' => 'checkbox',
    '#title' => t('orderedList'),
    '#description' => t('OrderedList can be set to false to generate unordered
    lists (ul) instead of ordered lists (ol).'),
    '#default_value' => $config->get('tocbot_orderedList'),
  );
  $form['tocbot_jsSettings']['tocbot_scrollSmooth'] = array(
    '#type' => 'checkbox',
    '#title' => t('scrollSmooth'),
    '#description' => t('Smooth scrolling enabled.'),
    '#default_value' => $config->get('tocbot_scrollSmooth'),
  );
  $form['tocbot_jsSettings']['tocbot_scrollSmoothDuration'] = array(
    '#type' => 'textfield',
    '#title' => t('scrollSmoothDuration (number)'),
    '#description' => t('Smooth scroll duration.'),
    '#default_value' => $config->get('tocbot_scrollSmoothDuration'),
  );
  $form['tocbot_jsSettings']['tocbot_throttleTimeout'] = array(
    '#type' => 'textfield',
    '#title' => t('throttleTimeout (number)'),
    '#description' => t('Timeout between events firing to make sure its not too
    rapid (for performance reasons)'),
    '#default_value' => $config->get('tocbot_throttleTimeout'),
  );
  $form['tocbot_jsSettings']['tocbot_positionFixedSelector'] = array(
    '#type' => 'textfield',
    '#title' => t('positionFixedSelector'),
    '#description' => t('Element to add the positionFixedClass to such as the .js-toc-block class.'),
    '#default_value' => $config->get('tocbot_positionFixedSelector'),
  );
  $form['tocbot_jsSettings']['tocbot_positionFixedClass'] = array(
    '#type' => 'textfield',
    '#title' => t('positionFixedClass'),
    '#description' => t('Fixed position class to add to make sidebar fixed after
    scrolling down past the fixedSidebarOffset.'),
    '#default_value' => $config->get('tocbot_positionFixedClass'),
  );
  $form['tocbot_jsSettings']['tocbot_fixedSidebarOffset'] = array(
    '#type' => 'textfield',
    '#title' => t('fixedSidebarOffset'),
    '#description' => t('fixedSidebarOffset can be any number but by default
    is set to auto which sets the fixedSidebarOffset to the sidebar elements
    offsetTop from the top of the document on init.'),
    '#default_value' => $config->get('tocbot_fixedSidebarOffset'),
  );
  $form['tocbot_jsSettings']['tocbot_includeHtml'] = array(
    '#type' => 'checkbox',
    '#title' => t('includeHtml'),
    '#description' => t('includeHtml can be set to true to include the HTML
    markup from the heading node instead of just including the textContent.'),
    '#default_value' => $config->get('tocbot_includeHtml'),
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save settings'),
  );
  
  return $form;
}

/**
 * Save Configuration form.
 */
function tocbot_config_form_submit($form, &$form_state) {
  $config = config('tocbot.settings');

  $fields_to_save = array(
    'tocbot_extrabodyclass',
    'tocbot_tocTitle',
    'tocbot_minActivate',
    'tocbot_createAutoIds',
    'tocbot_use_local',
    'tocbot_tocSelector',
    'tocbot_contentSelector',
    'tocbot_headingSelector',
    'tocbot_ignoreSelector',
    'tocbot_linkClass',
    'tocbot_extraLinkClasses',
    'tocbot_activeLinkClass',
    'tocbot_listClass',
    'tocbot_extraListClasses',
    'tocbot_isCollapsedClass',
    'tocbot_collapsibleClass',
    'tocbot_listItemClass',
    'tocbot_collapseDepth',
    'tocbot_orderedList',
    'tocbot_scrollSmooth',
    'tocbot_scrollSmoothDuration',
    'tocbot_throttleTimeout',
    'tocbot_positionFixedSelector',
    'tocbot_positionFixedClass',
    'tocbot_fixedSidebarOffset',
    'tocbot_includeHtml',
  );

  foreach ($fields_to_save as $value) {
    $form_value = $form_state['values'][$value];
    $config->set($value, $form_value);
  }

  $config->save();
  
  backdrop_set_message(t('The configuration options have been saved.'));
}
