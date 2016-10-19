DELETE FROM `rbac_permissions` WHERE `id` IN (841,842,843);
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(841, 'Command: reload character_template'),
(842, 'Command: reload quest_greeting'),
(843, 'Command: debug send playscene');

DELETE FROM `rbac_linked_permissions` WHERE `linkedId` IN (841,842,843);
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES
(196, 841),
(196, 842),
(192, 843);
