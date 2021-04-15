DELETE FROM `rbac_permissions` WHERE `id` IN (853, 854);
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(853, 'Command: .reload conversation_template'),
(854, 'Command: .debug conversation');

DELETE FROM `rbac_linked_permissions` WHERE `id` = 192 AND `linkedId` IN (853, 854);
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES
(192, 853),
(192, 854);
