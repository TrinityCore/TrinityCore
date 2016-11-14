DELETE FROM `rbac_permissions` WHERE `id` IN (851, 852);
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(851, 'Command: .reload conversation_template'),
(852, 'Command: .debug conversation');

DELETE FROM `rbac_linked_permissions` WHERE `id` = 192 AND `linkedId` IN (851, 852);
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES (192, 851), (192, 852);
