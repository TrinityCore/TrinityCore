/* cs_cheat.cpp */

SET @id = 291;

-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` BETWEEN @id AND @id+8;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(@id+0, 'cheat'),
(@id+1, 'cheat casttime'),
(@id+2, 'cheat cooldown'),
(@id+3, 'cheat explore'),
(@id+4, 'cheat god'),
(@id+5, 'cheat power'),
(@id+6, 'cheat status'),
(@id+7, 'cheat taxi'),
(@id+8, 'cheat waterwalk');

-- Add permissions to "corresponding Commands Role"
DELETE FROM `rbac_role_permissions` WHERE `permissionId` BETWEEN @id AND @id+8;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(4, @id+0),
(4, @id+1),
(4, @id+2),
(4, @id+3),
(4, @id+4),
(4, @id+5),
(4, @id+6),
(4, @id+7),
(4, @id+8);
