DELETE FROM `rbac_permissions` WHERE id = 1000;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES (1000, 'Command: qc');

DELETE FROM `rbac_linked_permissions` WHERE linkedId = 1000;
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES (195, 1000);

