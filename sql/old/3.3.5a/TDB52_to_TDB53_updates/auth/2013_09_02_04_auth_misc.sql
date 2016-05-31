/* cs_event.cpp */

SET @id = 367;

-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` BETWEEN @id AND @id+3;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(@id+0, 'event'),
(@id+1, 'event activelist'),
(@id+2, 'event start'),
(@id+3, 'event stop');

-- Add permissions to "corresponding Commands Role"
DELETE FROM `rbac_role_permissions` WHERE `permissionId` BETWEEN @id AND @id+3;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(2, @id+0),
(2, @id+1),
(2, @id+2),
(2, @id+3);
