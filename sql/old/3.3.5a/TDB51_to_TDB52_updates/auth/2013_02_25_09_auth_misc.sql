-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` IN (33, 47);
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(33, 'Notify if a command was not found'),
(47, 'Enables lower security than target check');

-- Add new role
DELETE FROM `rbac_roles` WHERE `id` IN (20, 21);
INSERT INTO `rbac_roles` (`id`, `name`) VALUES
(20, 'Notify if a command was not found'),
(21, 'Enables lower security than target check');

-- Add the permission to the role
DELETE FROM `rbac_role_permissions` WHERE `roleId` IN (20, 21);
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(20, 33),
(21, 47);

-- Add it to all GM+ groups
DELETE FROM `rbac_group_roles` WHERE `roleId` IN (20, 21);
INSERT INTO `rbac_group_roles` (`groupId`, `roleId`) VALUES
(2, 20),
(3, 20),
(4, 20),
(2, 21),
(3, 21),
(4, 21);
