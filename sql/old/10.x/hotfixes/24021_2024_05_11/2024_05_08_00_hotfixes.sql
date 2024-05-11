ALTER TABLE `achievement` MODIFY COLUMN `Supercedes` int NOT NULL DEFAULT 0 AFTER `Faction`;

ALTER TABLE `content_tuning` ADD COLUMN `HealthItemLevelCurveID` int NOT NULL DEFAULT 0 AFTER `ExpansionID`;
ALTER TABLE `content_tuning` ADD COLUMN `DamageItemLevelCurveID` int NOT NULL DEFAULT 0 AFTER `HealthItemLevelCurveID`;

ALTER TABLE `item_modified_appearance` ADD COLUMN `Flags` int NOT NULL DEFAULT 0 AFTER `TransmogSourceTypeEnum`;
