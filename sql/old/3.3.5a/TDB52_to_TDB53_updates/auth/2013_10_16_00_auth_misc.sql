SET @id = 400;

-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id`=@id;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(@id, 'debug transport');

DELETE FROM `rbac_linked_permissions` WHERE `linkedId`=@id;
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES
(196, @id);
