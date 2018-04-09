DELETE FROM `rbac_permissions` WHERE `id`= 775;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES (775, 'Command: modify currency');
DELETE FROM `rbac_linked_permissions` WHERE `linkedId`= 775;
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES
(196, 775);
