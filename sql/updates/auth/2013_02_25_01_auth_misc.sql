-- Add new permission
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES (13, 'Skip Instance required bosses check');

-- Add new role
INSERT INTO `rbac_roles` (`id`, `name`) VALUES (9, 'Skip Instance required bosses check');

-- Add the permission to the role
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES (9, 13);

-- Add it to all GM+ groups
INSERT INTO `rbac_group_roles` (`groupId`, `roleId`) VALUES
(2, 9),
(3, 9),
(4, 9);
