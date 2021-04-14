--
DELETE FROM `rbac_permissions` WHERE `id`=836;
INSERT INTO `rbac_permissions` (`id`,`name`) VALUES (836,"Command: .debug boundary");

DELETE FROM `rbac_linked_permissions` WHERE `linkedId`=836;
INSERT INTO `rbac_linked_permissions` (`id`,`linkedId`) VALUES (196, 836);
