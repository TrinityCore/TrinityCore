-- 
DELETE FROM `rbac_permissions` WHERE `id`=878;
INSERT INTO `rbac_permissions` (`id`,`name`) VALUES (878, 'Command: debug questreset');

DELETE FROM `rbac_linked_permissions` WHERE `linkedId`=878;
INSERT INTO `rbac_linked_permissions` (`id`,`linkedId`) VALUES (196,878);
