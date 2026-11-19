ALTER TABLE `account_access`
  CHANGE COLUMN `id` `AccountID` INT(10) UNSIGNED NOT NULL,
  CHANGE COLUMN `gmlevel` `SecurityLevel` TINYINT(3) UNSIGNED NOT NULL,
  ADD COLUMN `Comment` VARCHAR(255) DEFAULT NULL AFTER `RealmID`;

UPDATE `rbac_permissions` SET `name` = 'Command: account set seclevel' WHERE `id` = 228;
