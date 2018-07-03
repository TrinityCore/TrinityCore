--
DELETE FROM `rbac_linked_permissions` WHERE `id`=198 AND `linkedId`=867;
DELETE FROM `rbac_permissions` WHERE `id`=867;
--
DELETE FROM `rbac_linked_permissions` WHERE `id`=198 AND `linkedId`=868;
DELETE FROM `rbac_permissions` WHERE `id`=868;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(868, 'Command: modify power');

INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES
(198, 868);
