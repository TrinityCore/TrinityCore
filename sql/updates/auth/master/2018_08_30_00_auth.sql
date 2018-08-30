-- 
DELETE FROM `rbac_permissions` WHERE `id`=874;
INSERT INTO `rbac_permissions` (`id`,`name`) VALUES
(874, "Command: go instance");

SET @parent := (SELECT `id` FROM `rbac_linked_permissions` WHERE `linkedId`=852);
DELETE FROM `rbac_linked_permissions` WHERE `linkedId`=874;
INSERT INTO `rbac_linked_permissions` (`id`,`linkedId`) VALUES
(@parent, 874);
