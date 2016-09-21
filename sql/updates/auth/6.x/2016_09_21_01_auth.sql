INSERT IGNORE INTO rbac_permissions (id, NAME) VALUES
( 845, 'Command : scene' ),
( 846, 'Command : scene debug' ),
( 847, 'Command : scene play' ),
( 848, 'Command : scene play package' ),
( 849, 'Command : scene cancel' ),
( 850, 'Command : list scenes' ),
( 851, 'Command : reload scenes' );

INSERT IGNORE INTO `rbac_linked_permissions` VALUES
( 192, 845 ),
( 192, 846 ),
( 192, 847 ),
( 192, 848 ),
( 192, 849 ),
( 192, 850 ),
( 192, 851 );
