/* cs_lookup.cpp */

SET @id = 442;

-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` BETWEEN @id AND @id+19;
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
(@id+10, 'lookup player ip'),
(@id+11, 'lookup player account'),
(@id+12, 'lookup player email'),
(@id+13, 'lookup skill'),
(@id+14, 'lookup spell'),
(@id+15, 'lookup spell id'),
(@id+16, 'lookup taxinode'),
(@id+17, 'lookup tele'),
(@id+18, 'lookup title'),
(@id+19, 'lookup map');

-- Add permissions to "corresponding Commands Role"
DELETE FROM `rbac_role_permissions` WHERE `permissionId` BETWEEN @id AND @id+19;
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
(4, @id+15),
(4, @id+16),
(4, @id+17),
(4, @id+19);
