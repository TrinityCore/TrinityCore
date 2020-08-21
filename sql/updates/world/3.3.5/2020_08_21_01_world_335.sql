ALTER TABLE `item_template`
	CHANGE COLUMN `stat_value1` `stat_value1` INT NOT NULL DEFAULT 0 AFTER `stat_type1`,
	CHANGE COLUMN `stat_value2` `stat_value2` INT NOT NULL DEFAULT 0 AFTER `stat_type2`,
	CHANGE COLUMN `stat_value3` `stat_value3` INT NOT NULL DEFAULT 0 AFTER `stat_type3`,
	CHANGE COLUMN `stat_value4` `stat_value4` INT NOT NULL DEFAULT 0 AFTER `stat_type4`,
	CHANGE COLUMN `stat_value5` `stat_value5` INT NOT NULL DEFAULT 0 AFTER `stat_type5`,
	CHANGE COLUMN `stat_value6` `stat_value6` INT NOT NULL DEFAULT 0 AFTER `stat_type6`,
	CHANGE COLUMN `stat_value7` `stat_value7` INT NOT NULL DEFAULT 0 AFTER `stat_type7`,
	CHANGE COLUMN `stat_value8` `stat_value8` INT NOT NULL DEFAULT 0 AFTER `stat_type8`,
	CHANGE COLUMN `stat_value9` `stat_value9` INT NOT NULL DEFAULT 0 AFTER `stat_type9`,
	CHANGE COLUMN `stat_value10` `stat_value10` INT NOT NULL DEFAULT 0 AFTER `stat_type10`;