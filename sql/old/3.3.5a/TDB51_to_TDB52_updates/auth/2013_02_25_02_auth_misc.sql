-- Add new permission
DELETE FROM `rbac_permissions` WHERE `id` = 32;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES (32, 'Can be assigned tickets with .assign ticket command');

-- Add new role
DELETE FROM `rbac_roles` WHERE `id` = 10;
INSERT INTO `rbac_roles` (`id`, `name`) VALUES (10, 'Ticket management');

-- Add the permission to the role
DELETE FROM `rbac_role_permissions` WHERE `roleId` = 10;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES (10, 32);

-- Add it to all GM+ groups
DELETE FROM `rbac_group_roles` WHERE `roleId` = 10;
INSERT INTO `rbac_group_roles` (`groupId`, `roleId`) VALUES
(2, 10),
(3, 10),
(4, 10);
