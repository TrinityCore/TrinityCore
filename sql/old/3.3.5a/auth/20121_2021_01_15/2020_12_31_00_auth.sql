DELETE FROM `rbac_permissions` WHERE `id`=881;
INSERT INTO `rbac_permissions` (`id`,`name`) VALUES
(881, 'Command: reload vehicle_template');

DELETE FROM `rbac_linked_permissions` WHERE `linkedId`=881;
INSERT INTO `rbac_linked_permissions` (`id`,`linkedId`) VALUES
(196,881);
