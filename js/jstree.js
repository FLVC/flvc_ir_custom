/**
 * @file
 * Create a jsTree for use in rendering a serial object.
 */

Drupal.settings.jsTree_jQuery = jQuery.noConflict(true);
(function ($) {
    Drupal.behaviors.jsTree = {
        attach: function(context, settings) {
            $('#flvc_ir_custom_tree_view').jstree({
                'core': {
                    'themes': { 'icons':false },
                    'data': settings.flvc_ir_custom_tree_settings.data
                },
                'types': settings.flvc_ir_custom_tree_settings.types,
                'plugins' : settings.flvc_ir_custom_tree_settings.plugins
            });
            $('#flvc_ir_custom_tree_view').bind("select_node.jstree", function(node, selected, event) {
                // For some reason jsTree doesn't pass the click through
                // in the event parameter, so grab it from selected instead.
                if (typeof selected.event != 'undefined') {
                    if (selected.event.type == 'click') {
                        window.location = Drupal.settings.basePath + 'islandora/object/' + selected.node.original.pid;
                    }
                }
            });
            $('.flvc_ir_custom_tree_close_all').click(function() {
                $('#flvc_ir_custom_tree_view').jstree("close_all");
            });
            $('.flvc_ir_custom_tree_open_all').click(function() {
                $('#flvc_ir_custom_tree_view').jstree("open_all");
            });
        }
    };
})(Drupal.settings.jsTree_jQuery);
