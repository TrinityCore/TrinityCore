-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` IN (28, 29, 35, 40);
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(28, 'See two side who list'),
(29, 'Add friends of other faction'),
(35, 'See all security levels with who command'),
(40, 'Allows to add a gm to friend list');

-- Add new role
DELETE FROM `rbac_roles` WHERE `id` IN (35, 36, 37, 38);
INSERT INTO `rbac_roles` (`id`, `name`) VALUES
(35, 'See two side who list'),
(36, 'Add friends of other faction'),
(37, 'See all security levels with who command'),
(38, 'Allows to add a gm to friend list');

-- Add the permission to the role
DELETE FROM `rbac_role_permissions` WHERE `roleId` IN (35, 36, 37, 38);
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(35, 28),
(36, 29),
(37, 35),
(38, 40);

-- Add it to all groups
DELETE FROM `rbac_group_roles` WHERE `roleId` IN (35, 36, 37, 38);
INSERT INTO `rbac_group_roles` (`groupId`, `roleId`) VALUES
(2, 35),
(3, 35),
(4, 35),
(2, 36),
(3, 36),
(4, 36),
(2, 37),
(3, 37),
(4, 37),
(2, 38),
(3, 38),
(4, 38);
