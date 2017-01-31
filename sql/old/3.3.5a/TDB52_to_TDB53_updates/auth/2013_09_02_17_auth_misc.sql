/* cs_character.cpp */

SET @id = 273;

-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` BETWEEN @id AND @id+17;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(@id+0 , 'character'),
(@id+1 , 'character customize'),
(@id+2 , 'character changefaction'),
(@id+3 , 'character changerace'),
(@id+4 , 'character deleted'),
-- (@id+5 , 'character deleted delete'),
(@id+6 , 'character deleted list'),
(@id+7 , 'character deleted restore'),
-- (@id+8 , 'character deleted old'),
-- (@id+9 , 'character erase'),
(@id+10, 'character level'),
(@id+11, 'character rename'),
(@id+12, 'character reputation'),
(@id+13, 'character titles'),
(@id+14, 'levelup'),
(@id+15, 'pdump'),
(@id+16, 'pdump load'),
(@id+17, 'pdump write');

-- Add permissions to "corresponding Commands Role"
DELETE FROM `rbac_role_permissions` WHERE `permissionId` BETWEEN @id AND @id+17;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(3, @id+0 ),
(3, @id+1 ),
(3, @id+2 ),
(3, @id+3 ),
(3, @id+4 ),
-- (c, @id+5 ),
(4, @id+6 ),
(4, @id+7 ),
-- (c, @id+8 ),
-- (c, @id+9 ),
(4, @id+10),
(3, @id+11),
(3, @id+12),
(3, @id+13),
(4, @id+14),
(4, @id+15),
(4, @id+16),
(4, @id+17);
