DELETE FROM rbac_permissions WHERE id = 214;
INSERT INTO rbac_permissions (`id`, `name`) VALUES
(214, 'Command: pvpstats');

DELETE FROM rbac_linked_permissions WHERE `linkedId` = 214;
INSERT INTO rbac_linked_permissions (`id`, `linkedId`) VALUES
(199, 214);
