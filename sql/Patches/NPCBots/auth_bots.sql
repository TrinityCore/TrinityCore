DELETE FROM `rbac_permissions` WHERE `id` IN (1800,1801,1802,1803,1804,1805,1806,1807,1808,1809,1810);
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(1800, 'Command: npcbot'),
(1801, 'Command: npcbot set faction'),
(1802, 'Command: npcbot set owner'),
(1803, 'Command: npcbot set'),
(1804, 'Command: npcbot add'),
(1805, 'Command: npcbot remove'),
(1806, 'Command: npcbot spawn'),
(1807, 'Command: npcbot delete'),
(1808, 'Command: npcbot lookup'),
(1809, 'Command: npcbot revive'),
(1810, 'Command: npcbot cast');

DELETE FROM `rbac_linked_permissions` WHERE `linkedid` IN (1800,1801,1802,1803,1804,1805,1806,1807,1808,1809,1810);
INSERT INTO `rbac_linked_permissions` (`id`,`linkedId`) VALUES
(197, 1800),
(197, 1801),
(197, 1802),
(197, 1803),
(197, 1804),
(197, 1805),
(197, 1806),
(197, 1807),
(197, 1808),
(197, 1809),
(197, 1810);
