ALTER TABLE `creature_template_addon`   
	ADD COLUMN `StandState` TINYINT UNSIGNED DEFAULT 0 NOT NULL AFTER `MountCreatureID`,
	ADD COLUMN `AnimTier` TINYINT UNSIGNED DEFAULT 0 NOT NULL AFTER `StandState`,
	ADD COLUMN `VisFlags` TINYINT UNSIGNED DEFAULT 0 NOT NULL AFTER `AnimTier`,
	ADD COLUMN `SheathState` TINYINT UNSIGNED DEFAULT 1 NOT NULL AFTER `VisFlags`,
	ADD COLUMN `PvPFlags` TINYINT UNSIGNED DEFAULT 0 NOT NULL AFTER `SheathState`;
	
UPDATE `creature_template_addon` SET `StandState`=`bytes1` & 0xFF;
UPDATE `creature_template_addon` SET `AnimTier`=(`bytes1` >> 24) & 0xFF;
UPDATE `creature_template_addon` SET `VisFlags`=(`bytes1` >> 16) & 0xFF;
UPDATE `creature_template_addon` SET `SheathState`=`bytes2` & 0xFF;
UPDATE `creature_template_addon` SET `PvPFlags`=(`bytes2` >> 8) & 0xFF;

ALTER TABLE `creature_addon`   
	ADD COLUMN `StandState` TINYINT UNSIGNED DEFAULT 0 NOT NULL AFTER `MountCreatureID`,
	ADD COLUMN `AnimTier` TINYINT UNSIGNED DEFAULT 0 NOT NULL AFTER `StandState`,
	ADD COLUMN `VisFlags` TINYINT UNSIGNED DEFAULT 0 NOT NULL AFTER `AnimTier`,
	ADD COLUMN `SheathState` TINYINT UNSIGNED DEFAULT 1 NOT NULL AFTER `VisFlags`,
	ADD COLUMN `PvPFlags` TINYINT UNSIGNED DEFAULT 0 NOT NULL AFTER `SheathState`;
	
UPDATE `creature_addon` SET `StandState`=`bytes1` & 0xFF;
UPDATE `creature_addon` SET `AnimTier`=(`bytes1` >> 24) & 0xFF;
UPDATE `creature_addon` SET `VisFlags`=(`bytes1` >> 16) & 0xFF;
UPDATE `creature_addon` SET `SheathState`=`bytes2` & 0xFF;
UPDATE `creature_addon` SET `PvPFlags`=(`bytes2` >> 8) & 0xFF;

-- Conversion done, drop old columns
ALTER TABLE `creature_template_addon`  
	DROP COLUMN `bytes1`, 
	DROP COLUMN `bytes2`;
	
ALTER TABLE `creature_addon`  
	DROP COLUMN `bytes1`, 
	DROP COLUMN `bytes2`;
