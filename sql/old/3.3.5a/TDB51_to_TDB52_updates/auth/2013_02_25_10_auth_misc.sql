-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` IN (20, 21, 22, 39, 41);
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(20, 'Skip disable map check'),
(21, 'Skip reset talents when used more than allowed check'),
(22, 'Skip spam chat check'),
(39, 'Restore saved gm setting states'),
(41, 'Use Config option START_GM_LEVEL to assign new character level');

-- Add new role
DELETE FROM `rbac_roles` WHERE `id` IN (22, 23, 24, 25, 26);
INSERT INTO `rbac_roles` (`id`, `name`) VALUES
(22, 'Skip disable map check'),
(23, 'Skip reset talents when used more than allowed check'),
(24, 'Skip spam chat check'),
(25, 'Restore saved gm setting states'),
(26, 'Use Config option START_GM_LEVEL to assign new character level');

-- Add the permission to the role
DELETE FROM `rbac_role_permissions` WHERE `roleId` IN (22, 23, 24, 25, 26);
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(22, 20),
(23, 21),
(24, 22),
(25, 39),
(26, 41);

-- Add it to all GM+ groups
DELETE FROM `rbac_group_roles` WHERE `roleId` IN (22, 23, 24, 25, 26);
INSERT INTO `rbac_group_roles` (`groupId`, `roleId`) VALUES
(2, 22),
(3, 22),
(4, 22),
(4, 23),
(2, 24),
(3, 24),
(4, 24),
(2, 25),
(3, 25),
(4, 25),
(2, 26),
(3, 26),
(4, 26);
