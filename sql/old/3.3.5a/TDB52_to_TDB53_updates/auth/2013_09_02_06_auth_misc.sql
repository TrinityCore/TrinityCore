/* cs_go.cpp */

SET @id = 377;

-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` BETWEEN @id AND @id+9;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(@id+0, 'go'),
(@id+1, 'go creature'),
(@id+2, 'go graveyard'),
(@id+3, 'go grid'),
(@id+4, 'go object'),
(@id+5, 'go taxinode'),
(@id+6, 'go ticket'),
(@id+7, 'go trigger'),
(@id+8, 'go xyz'),
(@id+9, 'go zonexy');

-- Add permissions to "corresponding Commands Role"
DELETE FROM `rbac_role_permissions` WHERE `permissionId` BETWEEN @id AND @id+9;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(2, @id+0),
(2, @id+1),
(2, @id+2),
(2, @id+3),
(2, @id+4),
(2, @id+5),
(2, @id+6),
(2, @id+7),
(2, @id+8),
(2, @id+9);
