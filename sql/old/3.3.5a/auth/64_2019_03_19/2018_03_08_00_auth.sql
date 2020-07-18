DELETE FROM `rbac_permissions` WHERE `id` = 873;
INSERT INTO `rbac_permissions` (`id`,`name`) VALUES
(873, 'Command: reload creature_movement_override');

DELETE FROM `rbac_linked_permissions` WHERE `linkedId` = 873;
INSERT INTO `rbac_linked_permissions` (`id`,`linkedId`) VALUES
(196, 873);
