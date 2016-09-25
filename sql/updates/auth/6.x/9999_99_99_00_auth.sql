DELETE FROM `rbac_permissions` WHERE `id` IN (845, 846);
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(845, 'Command: .reload conversation_template'),
(846, 'Command: .debug conversation');

DELETE FROM `rbac_linked_permissions` WHERE `id` = 192 AND `linkedId` IN (845, 846);
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES (192, 845), (192, 846);
