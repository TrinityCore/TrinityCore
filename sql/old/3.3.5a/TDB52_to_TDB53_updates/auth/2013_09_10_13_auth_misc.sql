/* cs_titles.cpp & cs_wp.cpp */

SET @id = 761;

-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` BETWEEN @id AND @id+13;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(@id+0, 'titles'),
(@id+1, 'titles add'),
(@id+2, 'titles current'),
(@id+3, 'titles remove'),
(@id+4, 'titles set'),
(@id+5, 'titles set mask'),
(@id+6, 'wp'),
(@id+7, 'wp add'),
(@id+8, 'wp event'),
(@id+9, 'wp load'),
(@id+10, 'wp modify'),
(@id+11, 'wp unload'),
(@id+12, 'wp reload'),
(@id+13, 'wp show');

-- Add permissions to "corresponding Commands Role"
DELETE FROM `rbac_role_permissions` WHERE `permissionId` BETWEEN @id AND @id+13;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(3, @id+0),
(3, @id+1),
(3, @id+2),
(3, @id+3),
(3, @id+4),
(3, @id+5),
(3, @id+6),
(3, @id+7),
(3, @id+8),
(3, @id+9),
(3, @id+10),
(3, @id+11),
(4, @id+12),
(3, @id+13);
