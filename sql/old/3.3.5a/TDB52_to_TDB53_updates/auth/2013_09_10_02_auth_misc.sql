/* cs_send.cpp */

SET @id = 483;

-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` BETWEEN @id AND @id+4;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(@id+0 , 'send'),
(@id+1 , 'send items'),
(@id+2 , 'send mail'),
(@id+3 , 'send message'),
(@id+4 , 'send money');

-- Add permissions to "corresponding Commands Role"
DELETE FROM `rbac_role_permissions` WHERE `permissionId` BETWEEN @id AND @id+4;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(2, @id+0),
(2, @id+1),
(3, @id+2),
(3, @id+3),
(3, @id+4);
