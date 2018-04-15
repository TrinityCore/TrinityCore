/* cs_server.cpp */

SET @id = 718;

-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` BETWEEN @id AND @id+18;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(@id+0, 'server'),
(@id+1, 'server corpses'),
(@id+2, 'server exit'),
(@id+3, 'server idlerestart'),
(@id+4, 'server idlerestart cancel'),
(@id+5, 'server idleshutdown'),
(@id+6, 'server idleshutdown cancel'),
(@id+7, 'server info'),
(@id+8, 'server plimit'),
(@id+9, 'server restart'),
(@id+10, 'server restart cancel'),
(@id+11, 'server set'),
(@id+12, 'server set closed'),
(@id+13, 'server set difftime'),
(@id+14, 'server set loglevel'),
(@id+15, 'server set motd'),
(@id+16, 'server shutdown'),
(@id+17, 'server shutdown cancel'),
(@id+18, 'server motd');

-- Add permissions to "corresponding Commands Role"
DELETE FROM `rbac_role_permissions` WHERE `permissionId` BETWEEN @id AND @id+18;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(4, @id+0),
(4, @id+1),
(4, @id+3),
(4, @id+4),
(4, @id+5),
(4, @id+6),
(4, @id+7),
(4, @id+8),
(4, @id+9),
(4, @id+10),
(4, @id+11),
(4, @id+12),
(4, @id+15),
(4, @id+16),
(4, @id+17),
(4, @id+18);
