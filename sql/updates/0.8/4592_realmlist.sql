ALTER TABLE realmd.realmlist
   ADD COLUMN `allowedSecurityLevel` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `timezone`;
