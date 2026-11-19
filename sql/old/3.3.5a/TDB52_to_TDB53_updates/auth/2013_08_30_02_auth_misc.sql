-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` BETWEEN 230 AND 238;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(230, 'achievement'),
(231, 'achievement add'),
(232, 'arena'),
(233, 'arena captain'),
(234, 'arena create'),
(235, 'arena disband'),
(236, 'arena info'),
(237, 'arena lookup'),
(238, 'arena rename');

-- Add Permissions to "corresponding Commands Role"
DELETE FROM `rbac_role_permissions` WHERE `permissionId` BETWEEN 230 AND 238;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(4, 230),
(4, 231),
(3, 232),
(4, 233),
(4, 234),
(4, 235),
(3, 236),
(3, 237),
(4, 238);
