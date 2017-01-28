SET @PERMISSION := 851;

DELETE FROM `rbac_permissions` WHERE `id` = @PERMISSION;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(@PERMISSION, 'Command: reload areatrigger_templates' );

DELETE FROM `rbac_linked_permissions` WHERE `id` = 192 AND `linkedId` = @PERMISSION;
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES
(192, @PERMISSION);
