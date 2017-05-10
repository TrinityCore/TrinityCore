-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` IN (34, 37);
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(34, 'Check if should appear in list using .gm ingame command'),
(37, 'Use staff badge in chat');

-- Add new role
DELETE FROM `rbac_roles` WHERE `id` IN (14, 15);
INSERT INTO `rbac_roles` (`id`, `name`) VALUES
(14, 'Appear in GM ingame list'),
(15, 'Use staff badge in chat');

-- Add the permission to the role
DELETE FROM `rbac_role_permissions` WHERE `roleId` IN (14, 15);
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(14, 34),
(15, 37);

-- Add it to all GM+ groups
DELETE FROM `rbac_group_roles` WHERE `roleId` IN (14, 15);
INSERT INTO `rbac_group_roles` (`groupId`, `roleId`) VALUES
(2, 14),
(3, 14),
(4, 14),
(2, 15),
(3, 15),
(4, 15);
