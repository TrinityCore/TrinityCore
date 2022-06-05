CREATE TABLE `json_data` (
	`entity_type` TINYINT UNSIGNED NOT NULL,
	`table_type` TINYINT UNSIGNED NOT NULL,
	`guid` MEDIUMINT(10) UNSIGNED NOT NULL,
	`json` TEXT,
	PRIMARY KEY(`entity_type`,`table_type`,`guid`)
);