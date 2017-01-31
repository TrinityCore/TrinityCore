-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` IN (26, 45, 46);
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(26, 'Allow channel chat between factions'),
(45, 'Join channels without announce'),
(46, 'Change channel settings without being channel moderator');

-- Add new role
DELETE FROM `rbac_roles` WHERE `id` IN (30, 31, 32);
INSERT INTO `rbac_roles` (`id`, `name`) VALUES
(30, 'Allow channel chat between factions'),
(31, 'Join channels without announce'),
(32, 'Change channel settings without being channel moderator');

-- Add the permission to the role
DELETE FROM `rbac_role_permissions` WHERE `roleId` IN (30, 31, 32);
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(30, 26),
(31, 45),
(32, 46);

-- Add it to all GM+ groups
DELETE FROM `rbac_group_roles` WHERE `roleId` IN (30, 31, 32);
INSERT INTO `rbac_group_roles` (`groupId`, `roleId`) VALUES
(1, 30),
(2, 30),
(3, 30),
(4, 30),
(2, 31),
(3, 31),
(4, 31),
(2, 32),
(3, 32),
(4, 32);
