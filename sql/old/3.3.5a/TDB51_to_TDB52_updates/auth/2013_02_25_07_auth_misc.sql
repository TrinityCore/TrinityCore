-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` IN (42, 43);
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(42, 'Allows to use CMSG_WORLD_TELEPORT opcode'),
(43, 'Allows to use CMSG_WHOIS opcode');

-- Add new role
DELETE FROM `rbac_roles` WHERE `id` = 18;
INSERT INTO `rbac_roles` (`id`, `name`) VALUES
(18, 'Allows Admin Opcodes');

-- Add the permission to the role
DELETE FROM `rbac_role_permissions` WHERE `roleId` = 18;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(18, 42),
(18, 43);

-- Add it to admins groups
DELETE FROM `rbac_group_roles` WHERE `roleId` = 18;
INSERT INTO `rbac_group_roles` (`groupId`, `roleId`) VALUES
(4, 18);
