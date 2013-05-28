-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` IN (19, 25, 36);
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(19, 'Skip needed requirements to use channel check'),
(25, 'Allow say chat between factions'),
(36, 'Filter whispers');

-- Add new role
DELETE FROM `rbac_roles` WHERE `id` IN (27, 28, 29);
INSERT INTO `rbac_roles` (`id`, `name`) VALUES
(27, 'Skip needed requirements to use channel check'),
(28, 'Allow say chat between factions'),
(29, 'Filter whispers');

-- Add the permission to the role
DELETE FROM `rbac_role_permissions` WHERE `roleId` IN (27, 28, 29);
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(27, 19),
(28, 25),
(29, 36);

-- Add it to all GM+ groups
DELETE FROM `rbac_group_roles` WHERE `roleId` IN (27, 28, 29);
INSERT INTO `rbac_group_roles` (`groupId`, `roleId`) VALUES
(2, 27),
(3, 27),
(4, 27),
(1, 28),
(2, 28),
(3, 28),
(4, 28),
(2, 29),
(3, 29),
(4, 29);
