DELETE FROM `rbac_permissions` WHERE `id` = 851;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
( 851, 'Command : reload areatrigger templates' );

DELETE FROM `rbac_linked_permissions` WHERE `id` = 192 AND `linkedId` = 851;
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES
( 192, 851 );
