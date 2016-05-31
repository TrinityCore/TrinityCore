DELETE FROM `rbac_permissions` WHERE `id` IN (10, 662);
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(10, 'Use character templates'),
(662, 'Command: reload character_template');

DELETE FROM `rbac_linked_permissions` WHERE `linkedId` IN (10, 662);
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES
(196, 10),
(196, 662);
