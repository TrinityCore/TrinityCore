ALTER TABLE `creature_template` CHANGE COLUMN `family` `family` INT(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `dynamicflags`;

ALTER TABLE `creature_template_scaling` ADD COLUMN `DifficultyID` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `Entry`, ADD COLUMN `ContentTuningID` INT(10) NOT NULL DEFAULT '0' AFTER `LevelScalingDeltaMax`, DROP PRIMARY KEY,	ADD PRIMARY KEY (`Entry`, `DifficultyID`);
