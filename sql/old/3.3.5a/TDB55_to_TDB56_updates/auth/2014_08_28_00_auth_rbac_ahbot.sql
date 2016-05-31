SET @id = 778;

-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id` BETWEEN @id AND @id+15;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(@id,    'Command: ahbot'),
(@id+1,  'Command: ahbot items'),
(@id+2,  'Command: ahbot items gray'),
(@id+3,  'Command: ahbot items white'),
(@id+4,  'Command: ahbot items green'),
(@id+5,  'Command: ahbot items blue'),
(@id+6,  'Command: ahbot items purple'),
(@id+7,  'Command: ahbot items orange'),
(@id+8,  'Command: ahbot items yellow'),
(@id+9,  'Command: ahbot ratio'),
(@id+10, 'Command: ahbot ratio alliance'),
(@id+11, 'Command: ahbot ratio horde'),
(@id+12, 'Command: ahbot ratio neutral'),
(@id+13, 'Command: ahbot rebuild'),
(@id+14, 'Command: ahbot reload'),
(@id+15, 'Command: ahbot status');

DELETE FROM `rbac_linked_permissions` WHERE `linkedId` BETWEEN @id AND @id+15;
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES
(192, @id),
(192, @id+1),
(192, @id+2),
(192, @id+3),
(192, @id+4),
(192, @id+5),
(192, @id+6),
(192, @id+7),
(192, @id+8),
(192, @id+9),
(192, @id+10),
(192, @id+11),
(192, @id+12),
(192, @id+13),
(192, @id+14),
(192, @id+15);
