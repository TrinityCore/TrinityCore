/* cs_disable.cpp */

SET @id = 348;

-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` BETWEEN @id AND @id+18;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(@id+0, 'disable'),
(@id+1, 'disable add'),
(@id+2, 'disable add achievement_criteria'),
(@id+3, 'disable add battleground'),
(@id+4, 'disable add map'),
(@id+5, 'disable add mmap'),
(@id+6, 'disable add outdoorpvp'),
(@id+7, 'disable add quest'),
(@id+8, 'disable add spell'),
(@id+9, 'disable add vmap'),
(@id+10, 'disable remove'),
(@id+11, 'disable remove achievement_criteria'),
(@id+12, 'disable remove battleground'),
(@id+13, 'disable remove map'),
(@id+14, 'disable remove mmap'),
(@id+15, 'disable remove outdoorpvp'),
(@id+16, 'disable remove quest'),
(@id+17, 'disable remove spell'),
(@id+18, 'disable remove vmap');

-- Add permissions to "corresponding Commands Role"
DELETE FROM `rbac_role_permissions` WHERE `permissionId` BETWEEN @id AND @id+18;
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
(4, @id+18);
