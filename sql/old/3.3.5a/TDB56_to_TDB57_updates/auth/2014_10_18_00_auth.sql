DELETE FROM `rbac_permissions` WHERE `id` IN (795, 796);
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(795, 'Command: .instance setbossstate'),
(796, 'Command: .instance getbossstate');

DELETE FROM `rbac_linked_permissions` WHERE `linkedId` IN (795, 796);
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES
(192, 795),
(192, 796);
