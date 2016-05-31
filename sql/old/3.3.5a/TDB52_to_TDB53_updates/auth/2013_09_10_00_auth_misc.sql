/* cs_group.cpp */

SET @id = 472;

-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` BETWEEN @id AND @id+6;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(@id+0 , 'group'),
(@id+1 , 'group leader'),
(@id+2 , 'group disband'),
(@id+3 , 'group remove'),
(@id+4 , 'group join'),
(@id+5 , 'group list'),
(@id+6 , 'group summon');

-- Add permissions to "corresponding Commands Role"
DELETE FROM `rbac_role_permissions` WHERE `permissionId` BETWEEN @id AND @id+6;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(4, @id+0),
(4, @id+1),
(4, @id+2),
(4, @id+3),
(4, @id+4),
(4, @id+5),
(4, @id+6);
