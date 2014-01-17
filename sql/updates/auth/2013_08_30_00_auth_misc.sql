-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` BETWEEN 200 AND 216;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(200, 'Command: .rbac'),
(201, 'Command: .rbac account'),
(202, 'Command: .rbac account group'),
(203, 'Command: .rbac account group add'),
(204, 'Command: .rbac account group remove'),
(205, 'Command: .rbac account role'),
(206, 'Command: .rbac account role grant'),
(207, 'Command: .rbac account role deny'),
(208, 'Command: .rbac account role revoke'),
(209, 'Command: .rbac account permission'),
(210, 'Command: .rbac account permission grant'),
(211, 'Command: .rbac account permission deny'),
(212, 'Command: .rbac account permission revoke'),
(213, 'Command: .rbac list'),
(214, 'Command: .rbac list groups'),
(215, 'Command: .rbac list roles'),
(216, 'Command: .rbac list permissions');

-- Add Permissions to "Administrator Commands Role"
DELETE FROM `rbac_role_permissions` WHERE `roleId` = 4 AND `permissionId` BETWEEN 200 AND 216;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(4, 200),
(4, 201),
(4, 202),
(4, 203),
(4, 204),
(4, 205),
(4, 206),
(4, 207),
(4, 208),
(4, 209),
(4, 210),
(4, 211),
(4, 212),
(4, 213),
(4, 214),
(4, 215),
(4, 216);
