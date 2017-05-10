ALTER TABLE `rbac_roles` MODIFY COLUMN `name` varchar(100) NOT NULL COMMENT 'Role name';
ALTER TABLE `rbac_groups` MODIFY COLUMN `name` varchar(100) NOT NULL COMMENT 'Group name';

-- Add new permission
DELETE FROM `rbac_permissions` WHERE `id` = 11;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES (11, 'Log GM trades');

-- Add new role
DELETE FROM `rbac_roles` WHERE `id` = 8;
INSERT INTO `rbac_roles` (`id`, `name`) VALUES (8, 'Log GM trades');

-- Add the permission to the role
DELETE FROM `rbac_role_permissions` WHERE `roleId` = 8;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES (8, 11);

-- Add it to all GM+ groups
DELETE FROM `rbac_group_roles` WHERE `roleId` = 8;
INSERT INTO `rbac_group_roles` (`groupId`, `roleId`) VALUES
(2, 8),
(3, 8),
(4, 8);
