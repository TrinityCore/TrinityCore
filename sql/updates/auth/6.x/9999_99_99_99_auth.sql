DELETE FROM `rbac_permissions` WHERE `id` IN (845);
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
( 845, 'Command : reload areatrigger templates' );

DELETE FROM `rbac_linked_permissions` WHERE `id` = 192 AND `linkedId` IN (845);
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES
( 192, 845 );
