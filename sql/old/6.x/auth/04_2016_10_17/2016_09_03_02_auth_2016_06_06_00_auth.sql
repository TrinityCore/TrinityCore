DELETE FROM `rbac_permissions` WHERE `id` = 841;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES (841, 'Command: .debug neargraveyard');

DELETE FROM `rbac_linked_permissions` WHERE `id` = 196 AND `linkedId` = 841;
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES (196, 841);
