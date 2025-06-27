DELETE FROM `rbac_permissions` WHERE `id`=872;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(872, 'Command: server debug');
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES
(196, 872);
