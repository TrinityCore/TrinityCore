/* cs_gm.cpp */

SET @id = 371;

-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` BETWEEN @id AND @id+5;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(@id+0, 'gm'),
(@id+1, 'gm chat'),
(@id+2, 'gm fly'),
(@id+3, 'gm ingame'),
(@id+4, 'gm list'),
(@id+5, 'gm visible');

-- Add permissions to "corresponding Commands Role"
DELETE FROM `rbac_role_permissions` WHERE `permissionId` BETWEEN @id AND @id+5;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(2, @id+0),
(2, @id+1),
(4, @id+2),
(2, @id+3),
(4, @id+4),
(2, @id+5);
