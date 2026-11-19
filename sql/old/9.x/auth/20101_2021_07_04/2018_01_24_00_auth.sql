-- 
DELETE FROM `rbac_permissions` WHERE `id`=871;
INSERT INTO `rbac_permissions` (`id`,`name`) VALUES
(871, 'Command: debug instancespawn');

DELETE FROM `rbac_linked_permissions` WHERE `linkedId`=871;
INSERT INTO `rbac_linked_permissions` (`id`,`linkedId`) VALUES
(196,871);
