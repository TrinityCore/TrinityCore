DELETE FROM `rbac_permissions` WHERE `id`=7;
INSERT INTO `rbac_permissions` (`id`,`name`) VALUES
(7, 'Skip idle connection check');

DELETE FROM `rbac_linked_permissions` WHERE `linkedId`=7;
INSERT INTO `rbac_linked_permissions` (`id`,`linkedId`) VALUES
(196,7);
