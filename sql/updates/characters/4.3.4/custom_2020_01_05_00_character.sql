ALTER TABLE `character_currency`   
	CHANGE `guid` `CharacterGuid` INT(10) UNSIGNED NOT NULL,
	CHANGE `currency` `Currency` SMALLINT(5) UNSIGNED NOT NULL,
	CHANGE `total_count` `Quantity` INT(10) UNSIGNED NOT NULL,
	CHANGE `week_count` `WeeklyQuantity` INT(10) UNSIGNED NOT NULL,
	CHANGE `season_count` `TrackedQuantity` INT(10) UNSIGNED NOT NULL,
	ADD COLUMN `Flags` TINYINT(2) UNSIGNED NOT NULL AFTER `TrackedQuantity`;
