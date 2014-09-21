-- Permissions for .guild info command
DELETE FROM `rbac_permissions` WHERE `id`=794;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(794, 'Command: .guild info');

DELETE FROM `rbac_linked_permissions` WHERE `linkedId`=794;
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES
(192, 794);
