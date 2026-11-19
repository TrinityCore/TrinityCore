--
DELETE FROM `rbac_permissions` WHERE `id`=867;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(867, 'Command: modify power');

DELETE FROM `rbac_linked_permissions` WHERE `id`=198 AND `linkedId`=867;
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES (198, 867);
