/* cs_learn.cpp */

SET @id = 417;

-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` BETWEEN @id AND @id+12;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(@id+0, 'learn'),
(@id+1, 'learn all'),
(@id+2, 'learn all my'),
(@id+3, 'learn all my class'),
(@id+4, 'learn all my pettalents'),
(@id+5, 'learn all my spells'),
(@id+6, 'learn all my talents'),
(@id+7, 'learn all gm'),
(@id+8, 'learn all crafts'),
(@id+9, 'learn all default'),
(@id+10, 'learn all lang'),
(@id+11, 'learn all recipes'),
(@id+12, 'unlearn');

-- Add permissions to "corresponding Commands Role"
DELETE FROM `rbac_role_permissions` WHERE `permissionId` BETWEEN @id AND @id+12;
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
(4, @id+12);
