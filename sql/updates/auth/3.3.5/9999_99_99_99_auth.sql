DELETE FROM `rbac_permissions` WHERE `id` BETWEEN 842 AND 847;
INSERT INTO `rbac_permissions` (`id`,`name`) VALUES
(845, 'Command: anticheat'),
(846, 'Command: anticheat global'),
(847, 'Command: anticheat player'),
(848, 'Command: anticheat handle'),
(849, 'Command: anticheat jail'),
(850, 'Command: anticheat warn');
-- On delete cascade, no delete needed for this table
INSERT INTO `rbac_linked_permissions` (`id`,`linkedId`) VALUES
(197,845),
(196,846),
(197,847),
(196,848),
(197,849),
(197,850);
