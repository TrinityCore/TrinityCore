DELETE FROM `rbac_permissions` WHERE `id`=12;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(12, 'Command: go quest');

DELETE FROM `rbac_linked_permissions` WHERE `linkedId`=12;
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES
(198, 12);
