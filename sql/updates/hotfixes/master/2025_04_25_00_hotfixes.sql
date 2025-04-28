ALTER TABLE `chr_classes` MODIFY COLUMN `PrimaryStatPriority` tinyint NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `chr_race_x_chr_model` MODIFY COLUMN `ChrRacesID` tinyint unsigned NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `creature_model_data` MODIFY COLUMN `SizeClass` tinyint NOT NULL DEFAULT 0 AFTER `SoundID`;

ALTER TABLE `dungeon_encounter` ADD COLUMN `Unknown1115` int NOT NULL DEFAULT 0 AFTER `Faction`;

ALTER TABLE `heirloom` MODIFY COLUMN `Flags` int NOT NULL DEFAULT 0 AFTER `SourceTypeEnum`;

ALTER TABLE `item_class` MODIFY COLUMN `Flags` int NOT NULL DEFAULT 0 AFTER `PriceModifier`;

ALTER TABLE `item_extended_cost` MODIFY COLUMN `Flags` int NOT NULL DEFAULT 0 AFTER `ArenaBracket`;

ALTER TABLE `num_talents_at_level` ADD COLUMN `Unknown1115` float NOT NULL DEFAULT 0 AFTER `NumTalentsDemonHunter`;

ALTER TABLE `spell_casting_requirements` MODIFY COLUMN `FacingCasterFlags` int NOT NULL DEFAULT 0 AFTER `SpellID`;

ALTER TABLE `talent` ADD COLUMN `TabID` smallint unsigned NOT NULL DEFAULT 0 AFTER `ColumnIndex`;
ALTER TABLE `talent` ADD COLUMN `RequiredSpellID` int unsigned NOT NULL DEFAULT 0 AFTER `OverridesSpellID`;
ALTER TABLE `talent` MODIFY COLUMN `CategoryMask1` int NOT NULL DEFAULT 0 AFTER `RequiredSpellID`;
ALTER TABLE `talent` MODIFY COLUMN `CategoryMask2` int NOT NULL DEFAULT 0 AFTER `CategoryMask1`;
ALTER TABLE `talent` ADD COLUMN `SpellRank1` int unsigned NOT NULL DEFAULT 0 AFTER `CategoryMask2`;
ALTER TABLE `talent` ADD COLUMN `SpellRank2` int unsigned NOT NULL DEFAULT 0 AFTER `SpellRank1`;
ALTER TABLE `talent` ADD COLUMN `SpellRank3` int unsigned NOT NULL DEFAULT 0 AFTER `SpellRank2`;
ALTER TABLE `talent` ADD COLUMN `SpellRank4` int unsigned NOT NULL DEFAULT 0 AFTER `SpellRank3`;
ALTER TABLE `talent` ADD COLUMN `SpellRank5` int unsigned NOT NULL DEFAULT 0 AFTER `SpellRank4`;
ALTER TABLE `talent` ADD COLUMN `SpellRank6` int unsigned NOT NULL DEFAULT 0 AFTER `SpellRank5`;
ALTER TABLE `talent` ADD COLUMN `SpellRank7` int unsigned NOT NULL DEFAULT 0 AFTER `SpellRank6`;
ALTER TABLE `talent` ADD COLUMN `SpellRank8` int unsigned NOT NULL DEFAULT 0 AFTER `SpellRank7`;
ALTER TABLE `talent` ADD COLUMN `SpellRank9` int unsigned NOT NULL DEFAULT 0 AFTER `SpellRank8`;
ALTER TABLE `talent` ADD COLUMN `PrereqTalent1` int unsigned NOT NULL DEFAULT 0 AFTER `SpellRank9`;
ALTER TABLE `talent` ADD COLUMN `PrereqTalent2` int unsigned NOT NULL DEFAULT 0 AFTER `PrereqTalent1`;
ALTER TABLE `talent` ADD COLUMN `PrereqTalent3` int unsigned NOT NULL DEFAULT 0 AFTER `PrereqTalent2`;
ALTER TABLE `talent` ADD COLUMN `PrereqRank1` tinyint unsigned NOT NULL DEFAULT 0 AFTER `PrereqTalent3`;
ALTER TABLE `talent` ADD COLUMN `PrereqRank2` tinyint unsigned NOT NULL DEFAULT 0 AFTER `PrereqRank1`;
ALTER TABLE `talent` ADD COLUMN `PrereqRank3` tinyint unsigned NOT NULL DEFAULT 0 AFTER `PrereqRank2`;

ALTER TABLE `toy` MODIFY COLUMN `Flags` int NOT NULL DEFAULT 0 AFTER `ItemID`;

ALTER TABLE `vehicle_seat` MODIFY COLUMN `EnterAnimKitID` int NOT NULL DEFAULT 0 AFTER `CameraSeatZoomMax`;
ALTER TABLE `vehicle_seat` MODIFY COLUMN `RideAnimKitID` int NOT NULL DEFAULT 0 AFTER `EnterAnimKitID`;
ALTER TABLE `vehicle_seat` MODIFY COLUMN `ExitAnimKitID` int NOT NULL DEFAULT 0 AFTER `RideAnimKitID`;
ALTER TABLE `vehicle_seat` MODIFY COLUMN `VehicleEnterAnimKitID` int NOT NULL DEFAULT 0 AFTER `ExitAnimKitID`;
ALTER TABLE `vehicle_seat` MODIFY COLUMN `VehicleRideAnimKitID` int NOT NULL DEFAULT 0 AFTER `VehicleEnterAnimKitID`;
ALTER TABLE `vehicle_seat` MODIFY COLUMN `VehicleExitAnimKitID` int NOT NULL DEFAULT 0 AFTER `VehicleRideAnimKitID`;
