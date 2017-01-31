-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` IN (30, 31, 38);
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(30, 'Save character without delay with .save command'),
(31, 'Use params with .unstuck command'),
(38, 'Resurrect with full Health Points');

-- Add new role
DELETE FROM `rbac_roles` WHERE `id` IN (11, 12, 13);
INSERT INTO `rbac_roles` (`id`, `name`) VALUES
(11, 'Instant .save'),
(12, 'Allow params with .unstuck'),
(13, 'Full HP after resurrect');

-- Add the permission to the role
DELETE FROM `rbac_role_permissions` WHERE `roleId` IN (11, 12, 13);
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(11, 30),
(12, 31),
(13, 38);

-- Add it to all GM+ groups
DELETE FROM `rbac_group_roles` WHERE `roleId` IN (11, 12, 13);
INSERT INTO `rbac_group_roles` (`groupId`, `roleId`) VALUES
(2, 11),
(3, 11),
(4, 11),
(2, 12),
(3, 12),
(4, 12),
(2, 13),
(3, 13),
(4, 13);
