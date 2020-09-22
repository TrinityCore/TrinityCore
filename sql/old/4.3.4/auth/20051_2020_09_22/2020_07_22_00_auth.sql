-- 
DELETE FROM `rbac_permissions` WHERE `id`=870;
INSERT INTO `rbac_permissions` (`id`,`name`) VALUES
(870, 'Command: debug threatinfo');

DELETE FROM `rbac_linked_permissions` WHERE `linkedId`=870;
INSERT INTO `rbac_linked_permissions` (`id`,`linkedId`) VALUES
(196,870);
