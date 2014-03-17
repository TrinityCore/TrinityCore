/* cs_tele.cpp */

SET @id = 737;

-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` BETWEEN @id AND @id+4;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(@id+0, 'tele'),
(@id+1, 'tele add'),
(@id+2, 'tele del'),
(@id+3, 'tele name'),
(@id+4, 'tele group');

-- Add permissions to "corresponding Commands Role"
DELETE FROM `rbac_role_permissions` WHERE `permissionId` BETWEEN @id AND @id+4;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(2, @id+0),
(4, @id+1),
(4, @id+2),
(2, @id+3),
(2, @id+4);
