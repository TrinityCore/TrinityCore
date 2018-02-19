DELETE FROM `rbac_permissions` WHERE `id` = 843; -- this id does not exist in TDB 335.63
INSERT INTO `rbac_permissions` (`id`,`name`) VALUES
(843, 'Command: reload quest_greeting');

DELETE FROM `rbac_linked_permissions` WHERE `linkedId` = 843;
INSERT INTO `rbac_linked_permissions` (`id`,`linkedId`) VALUES
(196, 843);

DELETE FROM `rbac_permissions` WHERE `id` = 867;
INSERT INTO `rbac_permissions` (`id`,`name`) VALUES
(867, 'Command: reload quest_greeting_locale');

DELETE FROM `rbac_linked_permissions` WHERE `id` = 867;
INSERT INTO `rbac_linked_permissions` (`id`,`linkedId`) VALUES
(196, 867);
