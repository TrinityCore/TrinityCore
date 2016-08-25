DELETE FROM `rbac_permissions` WHERE `id` BETWEEN 842 AND 847;
INSERT INTO `rbac_permissions` (`id`,`name`) VALUES
(842, 'Command: anticheat'),
(843, 'Command: anticheat global'),
(844, 'Command: anticheat player'),
(845, 'Command: anticheat handle'),
(846, 'Command: anticheat jail'),
(847, 'Command: anticheat warn');
-- On delete cascade, no delete needed for this table
INSERT INTO `rbac_linked_permissions` (`id`,`linkedId`) VALUES
(197,842),
(196,843),
(197,844),
(196,845),
(197,846),
(197,847);
