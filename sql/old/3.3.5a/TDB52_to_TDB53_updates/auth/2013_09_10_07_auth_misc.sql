/* cs_quest.cpp */

SET @id = 602;

-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` BETWEEN @id AND @id+4;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(@id+0, 'quest'),
(@id+1, 'quest add'),
(@id+2, 'quest complete'),
(@id+3, 'quest remove'),
(@id+4, 'quest reward');

-- Add permissions to "corresponding Commands Role"
DELETE FROM `rbac_role_permissions` WHERE `permissionId` BETWEEN @id AND @id+4;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(4, @id+0),
(4, @id+1),
(4, @id+2),
(4, @id+3),
(4, @id+4);
