-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` IN (14, 15, 16, 17, 18, 24);
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(14, 'Skips character creation team mask check'),
(15, 'Skips character creation class mask check'),
(16, 'Skips character creation race mask check'),
(17, 'Skips character creation reserved name check'),
(18, 'Skips character creation heroic min level check'),
(24, 'Creation of two side faction characters in same account');

-- Add new role
DELETE FROM `rbac_roles` WHERE `id` IN (33, 34);
INSERT INTO `rbac_roles` (`id`, `name`) VALUES
(33, 'Skips character creation checks'),
(34, 'Creation of two side faction characters in same account');

-- Add the permission to the role
DELETE FROM `rbac_role_permissions` WHERE `roleId` IN (33, 34);
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(33, 14),
(33, 15),
(33, 16),
(33, 17),
(33, 18),
(34, 24);

-- Add it to all groups
DELETE FROM `rbac_role_permissions` WHERE `roleId` IN (33, 34);
INSERT INTO `rbac_group_roles` (`groupId`, `roleId`) VALUES
(2, 33),
(3, 33),
(4, 33),
(2, 34),
(3, 34),
(4, 34);

