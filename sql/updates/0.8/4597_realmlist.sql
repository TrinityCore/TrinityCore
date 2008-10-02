ALTER TABLE realmd.realmlist
   ADD COLUMN `population` float(0) UNSIGNED NOT NULL DEFAULT 0.0 AFTER `allowedSecurityLevel`;
