-- Add new permission
DELETE FROM `rbac_permissions` WHERE `id` = 44;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES (44, 'Receive global GM messages/texts');

-- Add new role
DELETE FROM `rbac_roles` WHERE `id` = 16;
INSERT INTO `rbac_roles` (`id`, `name`) VALUES (16, 'Receive global GM messages/texts');

-- Add the permission to the role
DELETE FROM `rbac_role_permissions` WHERE `roleId` = 16;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES (16, 44);

-- Add it to all GM+ groups
DELETE FROM `rbac_group_roles` WHERE `roleId` = 16;
INSERT INTO `rbac_group_roles` (`groupId`, `roleId`) VALUES
(2, 16),
(3, 16),
(4, 16);
