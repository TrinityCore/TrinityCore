/* cs_cast.cpp */

SET @id = 263;

-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` BETWEEN @id AND @id+5;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(@id+0, 'cast'),
(@id+1, 'cast back'),
(@id+2, 'cast dist'),
(@id+3, 'cast self'),
(@id+4, 'cast target'),
(@id+5, 'cast dest');

-- Add permissions to "corresponding Commands Role"
DELETE FROM `rbac_role_permissions` WHERE `permissionId` BETWEEN @id AND @id+5;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(4, @id+0),
(4, @id+1),
(4, @id+2),
(4, @id+3),
(4, @id+4),
(4, @id+5);
