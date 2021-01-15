DELETE FROM `rbac_permissions` WHERE `id` IN (842,843,844);
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(842, 'Command: reload character_template'),
(843, 'Command: reload quest_greeting'),
(844, 'Command: debug send playscene');

DELETE FROM `rbac_linked_permissions` WHERE `linkedId` IN (841,842,843);
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES
(196, 842),
(196, 843),
(192, 844);
