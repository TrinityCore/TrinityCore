/* cs_modify.cpp */

SET @id = 542;

-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` BETWEEN @id AND @id+27;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(@id+0, 'morph'),
(@id+1, 'demorph'),
(@id+2, 'modify'),
(@id+3, 'modify arenapoints'),
(@id+4, 'modify bit'),
(@id+5, 'modify drunk'),
(@id+6, 'modify energy'),
(@id+7, 'modify faction'),
(@id+8, 'modify gender'),
(@id+9, 'modify honor'),
(@id+10, 'modify hp'),
(@id+11, 'modify mana'),
(@id+12, 'modify money'),
(@id+13, 'modify mount'),
(@id+14, 'modify phase'),
(@id+15, 'modify rage'),
(@id+16, 'modify reputation'),
(@id+17, 'modify runicpower'),
(@id+18, 'modify scale'),
(@id+19, 'modify speed'),
(@id+20, 'modify speed all'),
(@id+21, 'modify speed backwalk'),
(@id+22, 'modify speed fly'),
(@id+23, 'modify speed walk'),
(@id+24, 'modify speed swim'),
(@id+25, 'modify spell'),
(@id+26, 'modify standstate'),
(@id+27, 'modify talentpoints');


-- Add permissions to "corresponding Commands Role"
DELETE FROM `rbac_role_permissions` WHERE `permissionId` BETWEEN @id AND @id+27;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(3, @id+0),
(3, @id+1),
(2, @id+2),
(2, @id+3),
(2, @id+4),
(2, @id+5),
(2, @id+6),
(2, @id+7),
(3, @id+8),
(2, @id+9),
(2, @id+10),
(2, @id+11),
(2, @id+12),
(2, @id+13),
(4, @id+14),
(2, @id+15),
(3, @id+16),
(2, @id+17),
(2, @id+18),
(2, @id+19),
(2, @id+20),
(2, @id+21),
(2, @id+22),
(2, @id+23),
(2, @id+24),
(2, @id+25),
(3, @id+26),
(2, @id+27);
