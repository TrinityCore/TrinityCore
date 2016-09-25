DELETE FROM `rbac_permissions` WHERE `id` IN (845, 846, 847, 848, 849, 850, 851);
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
( 845, 'Command : scene' ),
( 846, 'Command : scene debug' ),
( 847, 'Command : scene play' ),
( 848, 'Command : scene play package' ),
( 849, 'Command : scene cancel' ),
( 850, 'Command : list scenes' ),
( 851, 'Command : reload scenes' );

DELETE FROM `rbac_linked_permissions` WHERE `id` = 192 AND `linkedId` IN (845, 846, 847, 848, 849, 850, 851);
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES
( 192, 845 ),
( 192, 846 ),
( 192, 847 ),
( 192, 848 ),
( 192, 849 ),
( 192, 850 ),
( 192, 851 );
