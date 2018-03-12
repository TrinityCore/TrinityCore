ALTER TABLE `character_garrison` ADD COLUMN `type` TINYINT(3) UNSIGNED NOT NULL AFTER `guid`, DROP PRIMARY KEY, ADD PRIMARY KEY (`guid`, `type`); 
ALTER TABLE `character_garrison_blueprints` ADD COLUMN `garrison_type` TINYINT(3) UNSIGNED NOT NULL AFTER `guid`, DROP PRIMARY KEY, ADD PRIMARY KEY (`guid`, `garrison_type`, `buildingId`); 
ALTER TABLE `character_garrison_buildings` ADD COLUMN `garrison_type` TINYINT(3) UNSIGNED NOT NULL AFTER `guid`, DROP PRIMARY KEY, ADD PRIMARY KEY (`guid`, `garrison_type`, `plotInstanceId`); 
ALTER TABLE `character_garrison_followers` ADD COLUMN `garrison_type` TINYINT(3) UNSIGNED NOT NULL AFTER `guid`;
