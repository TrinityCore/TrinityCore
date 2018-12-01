DELETE FROM `rbac_permissions` WHERE `id` = 698;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(698, 'Command: reload spell_script_names');

DELETE FROM `rbac_linked_permissions` WHERE `linkedId` = 698;
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES
(196, 698);
