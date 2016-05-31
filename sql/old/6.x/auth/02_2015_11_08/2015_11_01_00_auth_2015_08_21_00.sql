DELETE FROM `rbac_permissions` WHERE `id` = 835;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES (835, 'Command: debug loadcells');

DELETE FROM `rbac_linked_permissions` WHERE `id` = 192 AND `linkedId` = 835;
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES (192, 835);
