/* cs_reset.cpp */

SET @id = 710;

-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` BETWEEN @id AND @id+7;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(@id+0, 'reset'),
(@id+1, 'reset achievements'),
(@id+2, 'reset honor'),
(@id+3, 'reset level'),
(@id+4, 'reset spells'),
(@id+5, 'reset stats'),
(@id+6, 'reset talents'),
(@id+7, 'reset all');

-- Add permissions to "corresponding Commands Role"
DELETE FROM `rbac_role_permissions` WHERE `permissionId` BETWEEN @id AND @id+7;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(4, @id+0),
(4, @id+1),
(4, @id+2),
(4, @id+3),
(4, @id+4),
(4, @id+5),
(4, @id+6),
(4, @id+7);
