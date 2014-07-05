DELETE FROM `rbac_permissions` WHERE `id` IN (207,208,209,210,211,212,213);
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(207, 'Command: battlenetaccount'),
(208, 'Command: battlenetaccount create'),
(209, 'Command: battlenetaccount lock country'),
(210, 'Command: battlenetaccount lock ip'),
(211, 'Command: battlenetaccount password'),
(212, 'Command: battlenetaccount set'),
(213, 'Command: battlenetaccount set password');

DELETE FROM `rbac_linked_permissions` WHERE `linkedId` IN (207,208,209,210,211,212,213);
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES
(199, 207),
(196, 208),
(199, 209),
(199, 210),
(199, 211),
(196, 212),
(196, 213);
