ALTER TABLE `achievement` ADD `HiddenBeforeDisplaySeason` int NOT NULL DEFAULT 0 AFTER `CovenantID`;
ALTER TABLE `achievement` ADD `LegacyAfterTimeEvent` int NOT NULL DEFAULT 0 AFTER `HiddenBeforeDisplaySeason`;

ALTER TABLE `adventure_journal` DROP `ItemID`;
ALTER TABLE `adventure_journal` DROP `ItemQuantity`;
