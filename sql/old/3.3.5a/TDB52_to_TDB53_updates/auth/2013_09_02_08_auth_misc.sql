/* cs_guild.cpp */

SET @id = 401;

-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` BETWEEN @id AND @id+6;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(@id+0, 'guild'),
(@id+1, 'guild create'),
(@id+2, 'guild delete'),
(@id+3, 'guild invite'),
(@id+4, 'guild uninvite'),
(@id+5, 'guild rank'),
(@id+6, 'guild rename');

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
