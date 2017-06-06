DELETE FROM `rbac_permissions` WHERE `id` = 843; -- this id does not exist in TDB 335.63
INSERT INTO `rbac_permissions` (`id`,`name`) VALUES
(843, 'Command: reload quest_greeting');

DELETE FROM `rbac_linked_permissions` WHERE `id` = 843;
INSERT INTO `rbac_linked_permissions` (`id`,`linkedId`) VALUES
(196, 843);
