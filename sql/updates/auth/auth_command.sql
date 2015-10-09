DELETE FROM `rbac_permissions` WHERE id IN (900, 901);
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(900, 'Command: .reset honorworld'),
(901, 'Command: .reset arenaseason');

DELETE FROM `rbac_linked_permissions` WHERE linkedId IN (900, 901);
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES
(196, 900),
(196, 901);
