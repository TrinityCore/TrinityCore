DELETE FROM `rbac_permissions` WHERE `id`=692;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES (692, 'Command: debug send playscene');

DELETE FROM `rbac_linked_permissions` WHERE `id`=192 AND linkedId=692;
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES (192, 692);
