-- Sets rbac permission for .reset arenapoints command
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES ('1001', 'Command: reset arenapoints');
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES ('196', '1001');

