-- Add new permission
DELETE FROM `rbac_permissions` WHERE `id` = 13;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES (13, 'Skip Instance required bosses check');

-- Add new role
DELETE FROM `rbac_roles` WHERE `id` = 9;
INSERT INTO `rbac_roles` (`id`, `name`) VALUES (9, 'Skip Instance required bosses check');

-- Add the permission to the role
DELETE FROM `rbac_role_permissions` WHERE `roleId` = 9;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES (9, 13);

-- Add it to all GM+ groups
DELETE FROM `rbac_group_roles` WHERE `roleId` = 9;
INSERT INTO `rbac_group_roles` (`groupId`, `roleId`) VALUES
(2, 9),
(3, 9),
(4, 9);
