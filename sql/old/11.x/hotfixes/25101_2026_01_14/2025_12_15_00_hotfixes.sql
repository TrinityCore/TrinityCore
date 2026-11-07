ALTER TABLE `conditional_content_tuning` ADD COLUMN `RedirectEnum` int NOT NULL DEFAULT 0 AFTER `RedirectFlag`;

ALTER TABLE `gossip_npc_option` ADD COLUMN `NeighborhoodMapID` int NOT NULL DEFAULT 0 AFTER `Unknown_1002_14`;

ALTER TABLE `item` ADD COLUMN `Unknown1127` int NOT NULL DEFAULT 0 AFTER `CraftingQualityID`;

ALTER TABLE `item_effect` ADD COLUMN `PlayerConditionID` int NOT NULL DEFAULT 0 AFTER `ChrSpecializationID`;

ALTER TABLE `item_scaling_config` ADD COLUMN `Flags` int NOT NULL DEFAULT 0 AFTER `Unknown1125`;

ALTER TABLE `item_sparse` ADD COLUMN `Unknown1127` int NOT NULL DEFAULT 0 AFTER `ItemLevelOffsetItemLevel`;

ALTER TABLE `map_challenge_mode` ADD COLUMN `MaxMedals` int NOT NULL DEFAULT 0 AFTER `Flags`;
ALTER TABLE `map_challenge_mode` ADD COLUMN `CriteriaCount4` smallint NOT NULL DEFAULT 0 AFTER `CriteriaCount3`;
ALTER TABLE `map_challenge_mode` ADD COLUMN `CriteriaCount5` smallint NOT NULL DEFAULT 0 AFTER `CriteriaCount4`;

ALTER TABLE `spell_visual` ADD COLUMN `StateKit` int NOT NULL DEFAULT 0 AFTER `MissileImpactOffset3`;
