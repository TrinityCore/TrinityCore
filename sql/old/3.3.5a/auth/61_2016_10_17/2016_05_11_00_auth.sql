--
DELETE FROM `rbac_permissions` WHERE `id` IN (837,838,839,840);
INSERT INTO `rbac_permissions` (`id`,`name`) VALUES (837,"Command: .npc evade"), (838,"Command: .pet level"), (839,"Command: .server shutdown force"), (840,"Command: .server restart force");

DELETE FROM `rbac_linked_permissions` WHERE `linkedId` IN (837,838,839,840);
INSERT INTO `rbac_linked_permissions` (`id`,`linkedId`) VALUES (196,837),(196,838),(196,839),(196,840);
