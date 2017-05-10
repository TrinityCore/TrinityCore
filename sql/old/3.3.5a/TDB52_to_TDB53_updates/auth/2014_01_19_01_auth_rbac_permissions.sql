SET @oldId = 775;
SET @id = 777;

-- Add new permissions
DELETE FROM `rbac_permissions` WHERE `id`=@oldId;
DELETE FROM `rbac_permissions` WHERE `id`=@id;
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(@id, 'Command: mailbox');

DELETE FROM `rbac_linked_permissions` WHERE `linkedId`=@oldId;
DELETE FROM `rbac_linked_permissions` WHERE `linkedId`=@id;
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES
(196, @id);
