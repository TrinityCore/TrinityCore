-- 
DELETE FROM `rbac_permissions_into` WHERE `id`=864;
INSERT INTO `rbac_permissions_into` (`id`,`name`) VALUES
(864, 'Command: list spawnpoints null');

DELETE FROM `rbac_linked_permissions_into` WHERE `linkedId`=864;
INSERT INTO `rbac_linked_permissions_into` (`id`,`linkedId`) VALUES
(196,864);
