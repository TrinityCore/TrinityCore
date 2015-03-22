DELETE FROM rbac_permissions WHERE id = 797;
INSERT INTO rbac_permissions (`id`, `name`) VALUES
(797, 'Command: pvpstats');

DELETE FROM rbac_linked_permissions WHERE `linkedId` = 797;
INSERT INTO rbac_linked_permissions (`id`, `linkedId`) VALUES
(199, 797);
