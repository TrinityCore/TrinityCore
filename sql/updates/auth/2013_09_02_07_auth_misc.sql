/* cs_gobject.cpp */

SET @id = 387;

-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` BETWEEN @id AND @id+12;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(@id+0, 'gobject'),
(@id+1, 'gobject activate'),
(@id+2, 'gobject add'),
(@id+3, 'gobject add temp'),
(@id+4, 'gobject delete'),
(@id+5, 'gobject info'),
(@id+6, 'gobject move'),
(@id+7, 'gobject near'),
(@id+8, 'gobject set'),
(@id+9, 'gobject set phase'),
(@id+10, 'gobject set state'),
(@id+11, 'gobject target'),
(@id+12, 'gobject turn');

-- Add permissions to "corresponding Commands Role"
DELETE FROM `rbac_role_permissions` WHERE `permissionId` BETWEEN @id AND @id+12;
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
(3, @id+12);
