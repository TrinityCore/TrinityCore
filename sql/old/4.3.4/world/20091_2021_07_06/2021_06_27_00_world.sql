ALTER TABLE `conditions` CHANGE COLUMN `ScriptName` `ScriptName` CHAR(64) NOT NULL DEFAULT '' COLLATE 'utf8mb4_unicode_ci' AFTER `ErrorTextId`;
