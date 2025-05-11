ALTER TABLE `item_instance`
	ADD COLUMN `randomPropertiesId` INT DEFAULT 0 NOT NULL AFTER `bonusListIDs`;
