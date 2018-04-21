-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` BETWEEN 239 AND 256;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(239, 'ban'),
(240, 'ban account'),
(241, 'ban character'),
(242, 'ban ip'),
(243, 'ban playeraccount'),
(244, 'baninfo'),
(245, 'baninfo account'),
(246, 'baninfo character'),
(247, 'baninfo ip'),
(248, 'banlist'),
(249, 'banlist account'),
(250, 'banlist character'),
(251, 'banlist ip'),
(252, 'unban'),
(253, 'unban account'),
(254, 'unban character'),
(255, 'unban ip'),
(256, 'unban playeraccount');

-- Add Permissions to "corresponding Commands Role"
DELETE FROM `rbac_role_permissions` WHERE `permissionId` BETWEEN 239 AND 256;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(4, 239),
(4, 240),
(4, 241),
(4, 242),
(4, 243),
(4, 244),
(4, 245),
(4, 246),
(4, 247),
(4, 248),
(4, 249),
(4, 250),
(4, 251),
(4, 252),
(4, 253),
(4, 254),
(4, 255),
(4, 256);
