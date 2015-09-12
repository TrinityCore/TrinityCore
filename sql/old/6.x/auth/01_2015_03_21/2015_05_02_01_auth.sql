DELETE FROM `rbac_permissions` WHERE `id`=12;
DELETE FROM `rbac_permissions` WHERE `id`=834;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(834, 'Command: go quest');

DELETE FROM `rbac_linked_permissions` WHERE `linkedId`=12;
DELETE FROM `rbac_linked_permissions` WHERE `linkedId`=834;
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES
(198, 834);
