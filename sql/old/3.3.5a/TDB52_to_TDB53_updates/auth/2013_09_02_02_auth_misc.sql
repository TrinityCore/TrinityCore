/* cs_deserter.cpp */

SET @id = 341;

-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` BETWEEN @id AND @id+6;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(@id+0, 'deserter'),
(@id+1, 'deserter bg'),
(@id+2, 'deserter bg add'),
(@id+3, 'deserter bg remove'),
(@id+4, 'deserter instance'),
(@id+5, 'deserter instance add'),
(@id+6, 'deserter instance remove');

-- Add permissions to "corresponding Commands Role"
DELETE FROM `rbac_role_permissions` WHERE `permissionId` BETWEEN @id AND @id+6;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(4, @id+0),
(4, @id+1),
(4, @id+2),
(4, @id+3),
(4, @id+4),
(4, @id+5),
(4, @id+6);
