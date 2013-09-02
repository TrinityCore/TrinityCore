/* cs_lookup.cpp */

SET @id = 442;

-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` BETWEEN @id AND @id+15;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(@id+0, 'lookup'),
(@id+1, 'lookup area'),
(@id+2, 'lookup creature'),
(@id+3, 'lookup event'),
(@id+4, 'lookup faction'),
(@id+5, 'lookup item'),
(@id+6, 'lookup itemset'),
(@id+7, 'lookup object'),
(@id+8, 'lookup quest'),
(@id+9, 'lookup player'),
(@id+10, 'lookup skill'),
(@id+11, 'lookup spell'),
(@id+12, 'lookup taxinode'),
(@id+13, 'lookup tele'),
(@id+14, 'lookup title'),
(@id+15, 'lookup map');

-- Add permissions to "corresponding Commands Role"
DELETE FROM `rbac_role_permissions` WHERE `permissionId` BETWEEN @id AND @id+15;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(4, @id+0),
(4, @id+1),
(4, @id+2),
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
(4, @id+13),
(4, @id+14),
(4, @id+15);
