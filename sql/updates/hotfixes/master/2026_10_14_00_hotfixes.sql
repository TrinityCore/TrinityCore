ALTER TABLE `player_data_element_account` ADD COLUMN `Unknown1215` int NOT NULL DEFAULT 0 AFTER `Unknown1125`;

ALTER TABLE `player_data_element_character` ADD COLUMN `Unknown1215` int NOT NULL DEFAULT 0 AFTER `Unknown1125`;

ALTER TABLE `spell_item_enchantment`
  ADD COLUMN `ItemSquishEraID` int NOT NULL DEFAULT 0 AFTER `TransmogCost`,
  MODIFY COLUMN `Charges` int NOT NULL DEFAULT 0 AFTER `Duration`,
  MODIFY COLUMN `Effect1` int NOT NULL DEFAULT 0 AFTER `Charges`,
  MODIFY COLUMN `Effect2` int NOT NULL DEFAULT 0 AFTER `Effect1`,
  MODIFY COLUMN `Effect3` int NOT NULL DEFAULT 0 AFTER `Effect2`,
  MODIFY COLUMN `EffectPointsMin1` int NOT NULL DEFAULT 0 AFTER `Effect3`,
  MODIFY COLUMN `EffectPointsMin2` int NOT NULL DEFAULT 0 AFTER `EffectPointsMin1`,
  MODIFY COLUMN `EffectPointsMin3` int NOT NULL DEFAULT 0 AFTER `EffectPointsMin2`,
  MODIFY COLUMN `ScalingClass` int NOT NULL DEFAULT 0 AFTER `EffectScalingPoints3`,
  MODIFY COLUMN `ScalingClassRestricted` int NOT NULL DEFAULT 0 AFTER `ScalingClass`,
  MODIFY COLUMN `ConditionID` int NOT NULL DEFAULT 0 AFTER `ScalingClassRestricted`,
  MODIFY COLUMN `RequiredSkillID` int NOT NULL DEFAULT 0 AFTER `ConditionID`,
  MODIFY COLUMN `RequiredSkillRank` int NOT NULL DEFAULT 0 AFTER `RequiredSkillID`,
  MODIFY COLUMN `MinLevel` int NOT NULL DEFAULT 0 AFTER `RequiredSkillRank`,
  MODIFY COLUMN `MaxLevel` int NOT NULL DEFAULT 0 AFTER `MinLevel`,
  MODIFY COLUMN `IconFileDataID` int NOT NULL DEFAULT 0 AFTER `MaxLevel`,
  MODIFY COLUMN `MinItemLevel` int NOT NULL DEFAULT 0 AFTER `IconFileDataID`,
  MODIFY COLUMN `MaxItemLevel` int NOT NULL DEFAULT 0 AFTER `MinItemLevel`,
  MODIFY COLUMN `TransmogUseConditionID` int NOT NULL DEFAULT 0 AFTER `MaxItemLevel`,
  MODIFY COLUMN `TransmogCost` int NOT NULL DEFAULT 0 AFTER `TransmogUseConditionID`;

ALTER TABLE `spell_procs_per_minute_mod` ADD COLUMN `PlayerConditionID` int NOT NULL DEFAULT 0 AFTER `Coeff`;

ALTER TABLE `spell_visual_missile`
  ADD COLUMN `MinimumSpellVisualDensityFilterType` int NOT NULL DEFAULT 0 AFTER `Unused1100`,
  ADD COLUMN `MinimumSpellVisualDensityFilterParam` int NOT NULL DEFAULT 0 AFTER `MinimumSpellVisualDensityFilterType`,
  ADD COLUMN `ReducedSpellVisualDensityFilterType` int NOT NULL DEFAULT 0 AFTER `MinimumSpellVisualDensityFilterParam`,
  ADD COLUMN `ReducedSpellVisualDensityFilterParam` int NOT NULL DEFAULT 0 AFTER `ReducedSpellVisualDensityFilterType`;
