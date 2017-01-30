DELETE FROM `rbac_permissions` WHERE `id` IN (852, 853);
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(852, 'Command: .reload conversation_template'),
(853, 'Command: .debug conversation');

DELETE FROM `rbac_linked_permissions` WHERE `id` = 192 AND `linkedId` IN (852, 853);
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES (192, 852), (192, 853);
