DELETE FROM `rbac_permissions` WHERE `id`=1010;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES 
(1010, 'Command: modify power');

DELETE FROM `rbac_linked_permissions` WHERE `id`=198 AND `linkedId`=1010;
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES (198, 1010);
