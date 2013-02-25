-- Add new permission
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES (11, 'Log GM trades');

-- Add new role
INSERT INTO `rbac_roles` (`id`, `name`) VALUES (8, 'Log GM trades');

-- Add the permission to the role
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES (8, 11);

-- Add it to all GM+ groups
INSERT INTO `rbac_group_roles` (`groupId`, `roleId`) VALUES
(2, 8),
(3, 8),
(4, 8);
