DELETE FROM `rbac_permissions` WHERE `id`=866;
INSERT INTO `rbac_permissions` (`id`,`name`) VALUES
(866, 'Command: list spawnpoints');

DELETE FROM `rbac_linked_permissions` WHERE `linkedId`=866;
INSERT INTO `rbac_linked_permissions` (`id`,`linkedId`) VALUES
(196,866);
