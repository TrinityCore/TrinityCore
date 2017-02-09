DELETE FROM `rbac_permissions` WHERE `id` IN (845, 852);
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(852, 'Command: go offset');
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES
(198, 852);
