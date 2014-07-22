CREATE TABLE IF NOT EXISTS `custom_transmogrification` (
	`GUID` INT(10) UNSIGNED NOT NULL DEFAULT '0',
	`FakeOwner` INT(10) UNSIGNED NOT NULL DEFAULT '0',
	`FakeEntry` INT(10) UNSIGNED NOT NULL DEFAULT '0'
)
COLLATE='latin1_swedish_ci'
ENGINE=InnoDB;

REPLACE INTO custom_transmogrification (GUID, FakeOwner, FakeEntry) SELECT guid, FakeOwner, FakeEntry FROM item_instance WHERE FakeOwner != 0 AND FakeEntry != 0;
ALTER TABLE `item_instance`
	DROP COLUMN `FakeEntry`,
	DROP COLUMN `FakeOwner`;
