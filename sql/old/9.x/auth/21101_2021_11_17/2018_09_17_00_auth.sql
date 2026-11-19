-- 
DELETE FROM `rbac_permissions` WHERE `id`=852;
INSERT INTO `rbac_permissions` (`id`,`name`) VALUES (852, 'Command: debug dummy');

DELETE FROM `rbac_linked_permissions` WHERE `linkedId`=852;
INSERT INTO `rbac_linked_permissions` (`id`,`linkedId`) VALUES (196,852);
