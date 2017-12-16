UPDATE `rbac_permissions` SET `name`='Command: event info' WHERE  `id`=367;
DELETE FROM `rbac_permissions` WHERE `id` = 845;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES (845, 'Command: go offset');
DELETE FROM `rbac_linked_permissions` WHERE `id` = 198 AND `linkedId` = 845;
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES (198, 845);
