/* cs_ticket.cpp */

SET @id = 742;

-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` BETWEEN @id AND @id+18;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(@id+0, 'ticket'),
(@id+1, 'ticket assign'),
(@id+2, 'ticket close'),
(@id+3, 'ticket closedlist'),
(@id+4, 'ticket comment'),
(@id+5, 'ticket complete'),
(@id+6, 'ticket delete'),
(@id+7, 'ticket escalate'),
(@id+8, 'ticket escalatedlist'),
(@id+9, 'ticket list'),
(@id+10, 'ticket onlinelist'),
(@id+11, 'ticket reset'),
(@id+12, 'ticket response'),
(@id+13, 'ticket response append'),
(@id+14, 'ticket response appendln'),
(@id+15, 'ticket togglesystem'),
(@id+16, 'ticket unassign'),
(@id+17, 'ticket viewid'),
(@id+18, 'ticket viewname');

-- Add permissions to "corresponding Commands Role"
DELETE FROM `rbac_role_permissions` WHERE `permissionId` BETWEEN @id AND @id+18;
INSERT INTO `rbac_role_permissions` (`roleId`, `permissionId`) VALUES
(2, @id+0),
(3, @id+1),
(2, @id+2),
(2, @id+3),
(2, @id+4),
(2, @id+5),
(4, @id+6),
(2, @id+7),
(3, @id+8),
(2, @id+9),
(2, @id+10),
(4, @id+11),
(2, @id+12),
(2, @id+13),
(2, @id+14),
(4, @id+15),
(3, @id+16),
(2, @id+17),
(2, @id+18);
