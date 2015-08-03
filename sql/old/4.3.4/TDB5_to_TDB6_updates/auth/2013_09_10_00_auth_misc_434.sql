/* cs_modify.cpp & cs_debug.cpp only 4.3.4 */

SET @id = 775;

-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` BETWEEN @id AND @id+13;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(@id+0, 'modify currency'),
(@id+1, 'debug phase');

-- Add permissions to "corresponding Commands Role"
DELETE FROM `rbac_role_permissions` WHERE `permissionId` BETWEEN @id AND @id+13;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(3, @id+0),
(4, @id+1);
