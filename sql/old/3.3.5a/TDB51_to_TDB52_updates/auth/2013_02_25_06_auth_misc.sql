-- Add new permission
DELETE FROM `rbac_permissions` WHERE `id` = 23;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES (23, 'Skip over-speed ping check');

-- Add new role
DELETE FROM `rbac_roles` WHERE `id` = 17;
INSERT INTO `rbac_roles` (`id`, `name`) VALUES (17, 'Skip over-speed ping check');

-- Add the permission to the role
DELETE FROM `rbac_role_permissions` WHERE `roleId` = 17;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES (17, 23);

-- Add it to all GM+ groups
DELETE FROM `rbac_group_roles` WHERE `roleId` = 17;
INSERT INTO `rbac_group_roles` (`groupId`, `roleId`) VALUES
(2, 17),
(3, 17),
(4, 17);
