DELETE FROM `rbac_permissions` WHERE `id`=2009;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES 
(2009, 'Command: reload spell_script_names');

DELETE FROM `rbac_linked_permissions` WHERE `id`=192 AND `linkedId`=2009;
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES (192, 2009);
