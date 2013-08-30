-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` BETWEEN 200 AND 216;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(217, 'Command: .account'),
(218, 'Command: .account addon'),
(219, 'Command: .account create'),
(220, 'Command: .account delete'),
(221, 'Command: .account lock'),
(222, 'Command: .account lock country'),
(223, 'Command: .account lock ip'),
(224, 'Command: .account onlinelist'),
(225, 'Command: .account password'),
(226, 'Command: .account set'),
(227, 'Command: .account set addon'),
(228, 'Command: .account set gmlevel'),
(229, 'Command: .account set password');

-- Add Permissions to "corresponding Commands Role"
DELETE FROM `rbac_role_permissions` WHERE `permissionId` BETWEEN 217 AND 229;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(1, 217),
(2, 218),
(1, 221),
(1, 222),
(1, 223),
(1, 225),
(4, 226),
(4, 227);
