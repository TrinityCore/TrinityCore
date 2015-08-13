ALTER TABLE `account_access` ADD FOREIGN KEY (`id`) REFERENCES `account`(`id`) ON DELETE CASCADE ON UPDATE CASCADE;
ALTER TABLE `account_banned` ADD FOREIGN KEY (`id`) REFERENCES `account`(`id`) ON DELETE CASCADE ON UPDATE CASCADE;
ALTER TABLE `account_muted` ADD FOREIGN KEY (`guid`) REFERENCES `account`(`id`) ON DELETE CASCADE ON UPDATE CASCADE;
ALTER TABLE `logs` ADD FOREIGN KEY (`realm`) REFERENCES `realmlist`(`id`) ON DELETE CASCADE ON UPDATE CASCADE;
ALTER TABLE `logs_ip_actions` ADD FOREIGN KEY (`account_id`) REFERENCES `account`(`id`) ON DELETE CASCADE ON UPDATE CASCADE;
-- Can't add FK on logs_ip_actions to character_guid as that belongs to another database, and I can't hardcode here
ALTER TABLE `rbac_account_permissions` DROP FOREIGN KEY `fk__rbac_account_permissions__account`;
ALTER TABLE `rbac_account_permissions` DROP FOREIGN KEY `fk__rbac_account_roles__rbac_permissions`;
ALTER TABLE `rbac_account_permissions` ADD FOREIGN KEY (`accountId`) REFERENCES `account`(`id`) ON DELETE CASCADE ON UPDATE CASCADE;
ALTER TABLE `rbac_account_permissions` ADD FOREIGN KEY (`permissionId`) REFERENCES `rbac_permissions`(`id`) ON DELETE CASCADE ON UPDATE CASCADE;
ALTER TABLE `rbac_default_permissions` DROP FOREIGN KEY `fk__rbac_default_permissions__rbac_permissions`;
ALTER TABLE `rbac_default_permissions` ADD FOREIGN KEY (`permissionId`) REFERENCES `rbac_permissions`(`id`) ON DELETE CASCADE ON UPDATE CASCADE;
ALTER TABLE `rbac_linked_permissions` DROP FOREIGN KEY `fk__rbac_linked_permissions__rbac_permissions1`;
ALTER TABLE `rbac_linked_permissions` DROP FOREIGN KEY `fk__rbac_linked_permissions__rbac_permissions2`;
ALTER TABLE `rbac_linked_permissions` ADD FOREIGN KEY (`id`) REFERENCES `rbac_permissions`(`id`) ON DELETE CASCADE ON UPDATE CASCADE;
ALTER TABLE `rbac_linked_permissions` ADD FOREIGN KEY (`linkedId`) REFERENCES `rbac_permissions`(`id`) ON DELETE CASCADE ON UPDATE CASCADE;
ALTER TABLE `realmcharacters` ADD FOREIGN KEY (`realmid`) REFERENCES `realmlist`(`id`) ON DELETE CASCADE ON UPDATE CASCADE;
ALTER TABLE `realmcharacters` ADD FOREIGN KEY (`acctid`) REFERENCES `account`(`id`) ON DELETE CASCADE ON UPDATE CASCADE;
ALTER TABLE `uptime` ADD FOREIGN KEY (`realmid`) REFERENCES `realmlist`(`id`) ON DELETE CASCADE ON UPDATE CASCADE;

-- This trigger is to handle automatic delete of tables where its realmlist can be -1 so they can't be a FKEY
DELIMITER //
CREATE TRIGGER delete_realm_actions AFTER DELETE ON `realmlist`
FOR EACH ROW
BEGIN
	DELETE FROM `account_access` WHERE `RealmID` = OLD.`id`;
	DELETE FROM `autobroadcast` WHERE `realmid` = OLD.`id`;
	DELETE FROM `rbac_account_permissions` WHERE `realmId` = OLD.`id`;
	DELETE FROM `rbac_default_permissions` WHERE `realmId` = OLD.`id`;
END;//
DELIMITER ;
