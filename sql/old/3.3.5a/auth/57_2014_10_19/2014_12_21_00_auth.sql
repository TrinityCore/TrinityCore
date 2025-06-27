-- Add rbac_permissions
DELETE FROM `rbac_permissions` WHERE `id` = 51;
INSERT INTO `rbac_permissions` (`id`,`name`) VALUES
(51, 'Allow trading between factions');

-- Add rbac_linked_permissions
DELETE FROM `rbac_linked_permissions` WHERE `linkedId` = 51;
INSERT INTO `rbac_linked_permissions` (`id`,`linkedId`) VALUES
(194, 51);
