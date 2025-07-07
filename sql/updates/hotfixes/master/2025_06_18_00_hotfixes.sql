ALTER TABLE `battlemaster_list` CHANGE `InstanceType` `PvpType` int NOT NULL DEFAULT 0 AFTER `LongDescription`;

ALTER TABLE `content_tuning` ADD `HealthPrimaryStatCurveID` int NOT NULL DEFAULT 0 AFTER `DamageItemLevelCurveID`;
ALTER TABLE `content_tuning` ADD `DamagePrimaryStatCurveID` int NOT NULL DEFAULT 0 AFTER `HealthPrimaryStatCurveID`;

ALTER TABLE `player_condition` MODIFY `ItemFlags` int NOT NULL DEFAULT 0 AFTER `ItemLogic`;

ALTER TABLE `quest_v2` MODIFY `UniqueBitFlag` int NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `talent` MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `TierID`;

ALTER TABLE `wmo_area_table` MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `AreaTableID`;

UPDATE `battlemaster_list` SET `PvpType`=0 WHERE `PvpType`=3;
UPDATE `battlemaster_list` SET `PvpType`=1 WHERE `PvpType`=4;
