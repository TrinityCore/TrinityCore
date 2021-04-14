/* cs_lfg.cpp */

SET @id = 430;

-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` BETWEEN @id AND @id+5;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(@id+0, 'lfg'),
(@id+1, 'lfg player'),
(@id+2, 'lfg group'),
(@id+3, 'lfg queue'),
(@id+4, 'lfg clean'),
(@id+5, 'lfg options');

-- Add permissions to "corresponding Commands Role"
DELETE FROM `rbac_role_permissions` WHERE `permissionId` BETWEEN @id AND @id+5;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(2, @id+0),
(2, @id+1),
(2, @id+2),
(2, @id+3),
(4, @id+4),
(4, @id+5);
