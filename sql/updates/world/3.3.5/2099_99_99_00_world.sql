ALTER TABLE `creature_template_addon`   
	ADD COLUMN `StandState` TINYINT UNSIGNED DEFAULT 0 NOT NULL AFTER `MountCreatureID`,
	ADD COLUMN `AnimTier` TINYINT UNSIGNED DEFAULT 0 NOT NULL AFTER `StandState`,
	ADD COLUMN `SheathState` TINYINT UNSIGNED DEFAULT 1 NOT NULL AFTER `AnimTier`,
	ADD COLUMN `PvPFlags` TINYINT UNSIGNED DEFAULT 0 NOT NULL AFTER `SheathState`;
	
UPDATE `creature_template_addon` SET `StandState`= 1 WHERE (`bytes1` & 0x1) != 0;
UPDATE `creature_template_addon` SET `StandState`= 2 WHERE (`bytes1` & 0x2) != 0;
UPDATE `creature_template_addon` SET `StandState`= 3 WHERE (`bytes1` & 0x3) != 0;
UPDATE `creature_template_addon` SET `StandState`= 4 WHERE (`bytes1` & 0x4) != 0;
UPDATE `creature_template_addon` SET `StandState`= 5 WHERE (`bytes1` & 0x5) != 0;
UPDATE `creature_template_addon` SET `StandState`= 6 WHERE (`bytes1` & 0x6) != 0;
UPDATE `creature_template_addon` SET `StandState`= 7 WHERE (`bytes1` & 0x7) != 0;
UPDATE `creature_template_addon` SET `StandState`= 8 WHERE (`bytes1` & 0x8) != 0;
UPDATE `creature_template_addon` SET `StandState`= 9 WHERE (`bytes1` & 0x9) != 0;

UPDATE `creature_template_addon` SET `AnimTier`= 1 WHERE (`bytes1` & 0x1000000) != 0;
UPDATE `creature_template_addon` SET `AnimTier`= 2 WHERE (`bytes1` & 0x2000000) != 0;
UPDATE `creature_template_addon` SET `AnimTier`= 3 WHERE (`bytes1` & 0x3000000) != 0;
UPDATE `creature_template_addon` SET `AnimTier`= 4 WHERE (`bytes1` & 0x4000000) != 0;

UPDATE `creature_template_addon` SET `SheathState`= 0 WHERE (`bytes2` & 0x1 | 0x2) = 0;
UPDATE `creature_template_addon` SET `SheathState`= 1 WHERE (`bytes2` & 0x1) != 0;
UPDATE `creature_template_addon` SET `SheathState`= 2 WHERE (`bytes2` & 0x2) != 0;

UPDATE `creature_template_addon` SET `PvPFlags`= `PvPFlags`|0x1 WHERE (`bytes2` & 0x100) != 0;
UPDATE `creature_template_addon` SET `PvPFlags`= `PvPFlags`|0x2 WHERE (`bytes2` & 0x200) != 0;
UPDATE `creature_template_addon` SET `PvPFlags`= `PvPFlags`|0x4 WHERE (`bytes2` & 0x400) != 0;
UPDATE `creature_template_addon` SET `PvPFlags`= `PvPFlags`|0x8 WHERE (`bytes2` & 0x800) != 0;
UPDATE `creature_template_addon` SET `PvPFlags`= `PvPFlags`|0x10 WHERE (`bytes2` & 0x1000) != 0;
UPDATE `creature_template_addon` SET `PvPFlags`= `PvPFlags`|0x20 WHERE (`bytes2` & 0x2000) != 0;
UPDATE `creature_template_addon` SET `PvPFlags`= `PvPFlags`|0x40 WHERE (`bytes2` & 0x4000) != 0;
UPDATE `creature_template_addon` SET `PvPFlags`= `PvPFlags`|0x80 WHERE (`bytes2` & 0x8000) != 0;

ALTER TABLE `creature_addon`   
	ADD COLUMN `StandState` TINYINT UNSIGNED DEFAULT 0 NOT NULL AFTER `MountCreatureID`,
	ADD COLUMN `AnimTier` TINYINT UNSIGNED DEFAULT 0 NOT NULL AFTER `StandState`,
	ADD COLUMN `SheathState` TINYINT UNSIGNED DEFAULT 1 NOT NULL AFTER `AnimTier`,
	ADD COLUMN `PvPFlags` TINYINT UNSIGNED DEFAULT 0 NOT NULL AFTER `SheathState`;
	
UPDATE `creature_addon` SET `StandState`= 1 WHERE (`bytes1` & 0x1) != 0;
UPDATE `creature_addon` SET `StandState`= 2 WHERE (`bytes1` & 0x2) != 0;
UPDATE `creature_addon` SET `StandState`= 3 WHERE (`bytes1` & 0x3) != 0;
UPDATE `creature_addon` SET `StandState`= 4 WHERE (`bytes1` & 0x4) != 0;
UPDATE `creature_addon` SET `StandState`= 5 WHERE (`bytes1` & 0x5) != 0;
UPDATE `creature_addon` SET `StandState`= 6 WHERE (`bytes1` & 0x6) != 0;
UPDATE `creature_addon` SET `StandState`= 7 WHERE (`bytes1` & 0x7) != 0;
UPDATE `creature_addon` SET `StandState`= 8 WHERE (`bytes1` & 0x8) != 0;
UPDATE `creature_addon` SET `StandState`= 9 WHERE (`bytes1` & 0x9) != 0;

UPDATE `creature_addon` SET `AnimTier`= 1 WHERE (`bytes1` & 0x1000000) != 0;
UPDATE `creature_addon` SET `AnimTier`= 2 WHERE (`bytes1` & 0x2000000) != 0;
UPDATE `creature_addon` SET `AnimTier`= 3 WHERE (`bytes1` & 0x3000000) != 0;
UPDATE `creature_addon` SET `AnimTier`= 4 WHERE (`bytes1` & 0x4000000) != 0;

UPDATE `creature_addon` SET `SheathState`= 0 WHERE (`bytes2` & 0x1 | 0x2) = 0;
UPDATE `creature_addon` SET `SheathState`= 1 WHERE (`bytes2` & 0x1) != 0;
UPDATE `creature_addon` SET `SheathState`= 2 WHERE (`bytes2` & 0x2) != 0;

UPDATE `creature_addon` SET `PvPFlags`= `PvPFlags`|0x1 WHERE (`bytes2` & 0x100) != 0;
UPDATE `creature_addon` SET `PvPFlags`= `PvPFlags`|0x2 WHERE (`bytes2` & 0x200) != 0;
UPDATE `creature_addon` SET `PvPFlags`= `PvPFlags`|0x4 WHERE (`bytes2` & 0x400) != 0;
UPDATE `creature_addon` SET `PvPFlags`= `PvPFlags`|0x8 WHERE (`bytes2` & 0x800) != 0;
UPDATE `creature_addon` SET `PvPFlags`= `PvPFlags`|0x10 WHERE (`bytes2` & 0x1000) != 0;
UPDATE `creature_addon` SET `PvPFlags`= `PvPFlags`|0x20 WHERE (`bytes2` & 0x2000) != 0;
UPDATE `creature_addon` SET `PvPFlags`= `PvPFlags`|0x40 WHERE (`bytes2` & 0x4000) != 0;
UPDATE `creature_addon` SET `PvPFlags`= `PvPFlags`|0x80 WHERE (`bytes2` & 0x8000) != 0;

-- Conversion done, drop old columns
ALTER TABLE `creature_template_addon`  
	DROP COLUMN `bytes1`, 
	DROP COLUMN `bytes2`;
	
ALTER TABLE `creature_addon`  
	DROP COLUMN `bytes1`, 
	DROP COLUMN `bytes2`;
