DELETE FROM `rbac_permissions` WHERE `id`=776;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES (776, 'Command: debug phase');

DELETE FROM `rbac_linked_permissions` WHERE `id`=192 AND linkedId=776;
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES (192, 776);

