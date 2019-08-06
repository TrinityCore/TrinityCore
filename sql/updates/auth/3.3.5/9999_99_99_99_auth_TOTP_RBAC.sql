-- 
DELETE FROM `rbac_permissions` WHERE `id` BETWEEN 378 AND 381;
INSERT INTO `rbac_permissions` (`id`,`name`) VALUES
(378, 'Command: account 2fa'),
(379, 'Command: account 2fa setup'),
(380, 'Command: account 2fa remove'),
(381, 'Command: account set 2fa');

DELETE FROM `rbac_linked_permissions` WHERE `linkedId` BETWEEN 378 AND 381;
INSERT INTO `rbac_linked_permissions` (`id`,`linkedId`) VALUES
(199, 378),
(199, 379),
(199, 380);
