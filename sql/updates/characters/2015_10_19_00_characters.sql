DROP TABLE IF EXISTS `battleground_deserters`;
CREATE TABLE `battleground_deserters` (
	`guid` INT(10) UNSIGNED NOT NULL COMMENT 'characters.guid',
	`type` TINYINT(3) UNSIGNED NOT NULL COMMENT 'type of the desertion',
	`datetime` DATETIME NOT NULL COMMENT 'datetime of the desertion'
);
