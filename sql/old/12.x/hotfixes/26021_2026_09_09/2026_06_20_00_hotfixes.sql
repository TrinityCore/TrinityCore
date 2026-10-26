ALTER TABLE `character_loadout`
  CHANGE `RaceMask_1` `RaceMask1` int NOT NULL DEFAULT 0 AFTER `ItemContext`,
  CHANGE `RaceMask_2` `RaceMask2` int NOT NULL DEFAULT 0 AFTER `RaceMask1`,
  DROP `RaceMask`;

ALTER TABLE `chr_customization_req`
  CHANGE `RaceMask_1` `RaceMask1` int NOT NULL DEFAULT 0 AFTER `ItemModifiedAppearanceID`,
  CHANGE `RaceMask_2` `RaceMask2` int NOT NULL DEFAULT 0 AFTER `RaceMask1`,
  DROP `RaceMask`;

ALTER TABLE `emotes`
  CHANGE `RaceMask_1` `RaceMask1` int NOT NULL DEFAULT 0 AFTER `ClassMask`,
  CHANGE `RaceMask_2` `RaceMask2` int NOT NULL DEFAULT 0 AFTER `RaceMask1`,
  DROP `RaceMask`;

ALTER TABLE `faction`
  CHANGE `ReputationRaceMask1_1` `ReputationRaceMask11` int NOT NULL DEFAULT 0 AFTER `ParentFactionCap2`,
  CHANGE `ReputationRaceMask1_2` `ReputationRaceMask12` int NOT NULL DEFAULT 0 AFTER `ReputationRaceMask11`,
  CHANGE `ReputationRaceMask2_1` `ReputationRaceMask21` int NOT NULL DEFAULT 0 AFTER `ReputationRaceMask12`,
  CHANGE `ReputationRaceMask2_2` `ReputationRaceMask22` int NOT NULL DEFAULT 0 AFTER `ReputationRaceMask21`,
  CHANGE `ReputationRaceMask3_1` `ReputationRaceMask31` int NOT NULL DEFAULT 0 AFTER `ReputationRaceMask22`,
  CHANGE `ReputationRaceMask3_2` `ReputationRaceMask32` int NOT NULL DEFAULT 0 AFTER `ReputationRaceMask31`,
  CHANGE `ReputationRaceMask4_1` `ReputationRaceMask41` int NOT NULL DEFAULT 0 AFTER `ReputationRaceMask32`,
  CHANGE `ReputationRaceMask4_2` `ReputationRaceMask42` int NOT NULL DEFAULT 0 AFTER `ReputationRaceMask41`,
  DROP `ReputationRaceMask1`,
  DROP `ReputationRaceMask2`,
  DROP `ReputationRaceMask3`,
  DROP `ReputationRaceMask4`;

ALTER TABLE `item_search_name`
  CHANGE `AllowableRace_1` `AllowableRace1` int NOT NULL DEFAULT 0 AFTER `Flags5`,
  CHANGE `AllowableRace_2` `AllowableRace2` int NOT NULL DEFAULT 0 AFTER `AllowableRace1`,
  DROP `AllowableRace`;

ALTER TABLE `item_sparse`
  CHANGE `AllowableRace_1` `AllowableRace1` int NOT NULL DEFAULT 0 AFTER `RequiredAbility`,
  CHANGE `AllowableRace_2` `AllowableRace2` int NOT NULL DEFAULT 0 AFTER `AllowableRace1`,
  DROP `AllowableRace`;

ALTER TABLE `player_condition`
  CHANGE `RaceMask_1` `RaceMask1` int NOT NULL DEFAULT 0 AFTER `MovementFlags2`,
  CHANGE `RaceMask_2` `RaceMask2` int NOT NULL DEFAULT 0 AFTER `RaceMask1`,
  DROP `RaceMask`;

ALTER TABLE `skill_line_ability`
  CHANGE `RaceMask_1` `RaceMask1` int NOT NULL DEFAULT 0 AFTER `SkillupSkillLineID`,
  CHANGE `RaceMask_2` `RaceMask2` int NOT NULL DEFAULT 0 AFTER `RaceMask1`,
  DROP `RaceMask`;

ALTER TABLE `skill_race_class_info`
  CHANGE `RaceMask_1` `RaceMask1` int NOT NULL DEFAULT 0 AFTER `SkillTierID`,
  CHANGE `RaceMask_2` `RaceMask2` int NOT NULL DEFAULT 0 AFTER `RaceMask1`,
  DROP `RaceMask`;
