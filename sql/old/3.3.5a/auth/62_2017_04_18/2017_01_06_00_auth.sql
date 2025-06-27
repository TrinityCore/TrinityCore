DELETE FROM `rbac_permissions` WHERE `id`=698;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(698, 'Command: character changeaccount');
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES
(196, 698);
