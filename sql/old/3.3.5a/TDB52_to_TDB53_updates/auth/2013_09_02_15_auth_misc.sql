/* cs_message.cpp */

SET @id = 462;

-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` BETWEEN @id AND @id+9;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(@id+0, 'announce'),
(@id+1, 'channel'),
(@id+2, 'channel set'),
(@id+3, 'channel set ownership'),
(@id+4, 'gmannounce'),
(@id+5, 'gmnameannounce'),
(@id+6, 'gmnotify'),
(@id+7, 'nameannounce'),
(@id+8, 'notify'),
(@id+9, 'whispers');

-- Add permissions to "corresponding Commands Role"
DELETE FROM `rbac_role_permissions` WHERE `permissionId` BETWEEN @id AND @id+9;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(2, @id+0),
(4, @id+1),
(4, @id+2),
(4, @id+3),
(2, @id+4),
(2, @id+5),
(2, @id+6),
(2, @id+7),
(2, @id+8),
(2, @id+9);
