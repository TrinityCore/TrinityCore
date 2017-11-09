DELETE FROM `rbac_permissions` WHERE `id`=1001;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES 
(1001, 'Command: modify fury');

DELETE FROM `rbac_linked_permissions` WHERE `id`=198 AND `linkedId`=1001;
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES (198, 1001);


DELETE FROM `rbac_permissions` WHERE `id`=1002;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES 
(1002, 'Command: modify pain');

DELETE FROM `rbac_linked_permissions` WHERE `id`=198 AND `linkedId`=1002;
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES (198, 1002);

