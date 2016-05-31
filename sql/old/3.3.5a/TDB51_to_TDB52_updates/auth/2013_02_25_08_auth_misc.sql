-- Add new permission
DELETE FROM `rbac_permissions` WHERE `id` = 27;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES (27, 'Two side mail interaction');

-- Add new role
DELETE FROM `rbac_roles` WHERE `id` = 19;
INSERT INTO `rbac_roles` (`id`, `name`) VALUES (19, 'Two side mail interaction');

-- Add the permission to the role
DELETE FROM `rbac_role_permissions` WHERE `roleId` = 19;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES (19, 27);

-- Add it to all GM+ groups
DELETE FROM `rbac_group_roles` WHERE `roleId` = 19;
INSERT INTO `rbac_group_roles` (`groupId`, `roleId`) VALUES
(1, 19),
(2, 19),
(3, 19),
(4, 19);
