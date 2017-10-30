-- add tables for spline chain DB storage
DROP TABLE IF EXISTS `script_spline_chain_meta`;
CREATE TABLE `script_spline_chain_meta` (
	`entry` INT UNSIGNED NOT NULL,
	`chainId` TINYINT UNSIGNED NOT NULL,
	`splineId` TINYINT UNSIGNED NOT NULL,
	`expectedDuration` INT UNSIGNED NOT NULL,
	`msUntilNext` INT UNSIGNED NOT NULL,
	PRIMARY KEY USING BTREE (`entry`,`chainId`,`splineId`)
);
DROP TABLE IF EXISTS `script_spline_chain_waypoints`;
CREATE TABLE `script_spline_chain_waypoints` (
	`entry` INT UNSIGNED NOT NULL,
	`chainId` TINYINT UNSIGNED NOT NULL,
	`splineId` TINYINT UNSIGNED NOT NULL,
	`wpId` TINYINT UNSIGNED NOT NULL,
	`x` FLOAT NOT NULL,
	`y` FLOAT NOT NULL,
	`z` FLOAT NOT NULL,
	PRIMARY KEY USING BTREE (`entry`,`chainId`,`splineId`,`wpId`)
);
