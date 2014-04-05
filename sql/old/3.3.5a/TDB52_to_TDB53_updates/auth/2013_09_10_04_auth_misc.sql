/* cs_mmaps.cpp */

SET @id = 536;

-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` BETWEEN @id AND @id+5;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(@id+0, 'mmap'),
(@id+1, 'mmap loadedtiles'),
(@id+2, 'mmap loc'),
(@id+3, 'mmap path'),
(@id+4, 'mmap stats'),
(@id+5, 'mmap testarea');

-- Add permissions to "corresponding Commands Role"
DELETE FROM `rbac_role_permissions` WHERE `permissionId` BETWEEN @id AND @id+5;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(4, @id+0),
(4, @id+1),
(4, @id+2),
(4, @id+3),
(4, @id+4),
(4, @id+5);
