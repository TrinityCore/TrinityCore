DELETE FROM `rbac_permissions` WHERE `id` IN (662,664,692);
DELETE FROM `rbac_linked_permissions` WHERE `linkedId` IN (662,664,692);

DELETE FROM `rbac_permissions` WHERE `id` IN (837,838,839);
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(837, 'Command: reload character_template'),
(838, 'Command: reload quest_greeting'),
(839, 'Command: debug send playscene');

DELETE FROM `rbac_linked_permissions` WHERE `linkedId` IN (837,838,839);
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES
(196, 837),
(196, 838),
(192, 839);
