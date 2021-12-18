-- 
DELETE FROM `rbac_permissions` WHERE `id`=879;
INSERT INTO `rbac_permissions` (`id`,`name`) VALUES (879, 'Command: debug poolstatus');

DELETE FROM `rbac_linked_permissions` WHERE `linkedId`=879;
INSERT INTO `rbac_linked_permissions` (`id`,`linkedId`) VALUES (196,879);
