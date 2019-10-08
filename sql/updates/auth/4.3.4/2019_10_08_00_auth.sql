
DELETE FROM `rbac_permissions` WHERE `id` IN (214,215,216);
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(214, 'Command: bnetaccount link'),
(215, 'Command: bnetaccount unlink'),
(216, 'Command: bnetaccount gameaccountcreate');

DELETE FROM `rbac_linked_permissions` WHERE `linkedId` IN (214,215,216);
INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES
(196, 214),
(196, 215),
(196, 216);
