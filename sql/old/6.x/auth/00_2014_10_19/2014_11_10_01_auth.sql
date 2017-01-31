/* add rbac permissions to new commands */
DELETE FROM `rbac_permissions` WHERE `id`=798;
INSERT INTO `rbac_permissions` (`id`,`name`) VALUES
(798, 'Command: .mod xp');

DELETE FROM `rbac_linked_permissions` WHERE `id`=798;
INSERT INTO `rbac_linked_permissions` (`id`,`linkedId`) VALUES
/* add mod xp to gms */
(194, 798);
