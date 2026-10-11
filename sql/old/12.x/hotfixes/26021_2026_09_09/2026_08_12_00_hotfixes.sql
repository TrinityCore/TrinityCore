ALTER TABLE `criteria`
  MODIFY COLUMN `ModifierTreeId` int NOT NULL DEFAULT 0 AFTER `Asset`,
  MODIFY COLUMN `StartTimer` int NOT NULL DEFAULT 0 AFTER `StartAsset`,
  MODIFY COLUMN `EligibilityWorldStateID` int NOT NULL DEFAULT 0 AFTER `Flags`,
  MODIFY COLUMN `EligibilityWorldStateValue` int NOT NULL DEFAULT 0 AFTER `EligibilityWorldStateID`;

ALTER TABLE `gameobjects` ADD COLUMN `Flags` int NOT NULL DEFAULT 0 AFTER `DisplayID`;

ALTER TABLE `garr_ability` MODIFY COLUMN `GarrFollowerTypeID` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `GarrAbilityCategoryID`;

ALTER TABLE `garr_follower` MODIFY COLUMN `GarrFollowerTypeID` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `GarrTypeID`;

ALTER TABLE `garr_mission` MODIFY COLUMN `GarrFollowerTypeID` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `GarrMissionTypeID`;

ALTER TABLE `gossip_npc_option` MODIFY COLUMN `GarrFollowerTypeID` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `TrainerID`;

ALTER TABLE `player_condition` 
  CHANGE COLUMN `MovementFlags1` `MovementFlags` int NOT NULL DEFAULT 0 AFTER `PowerTypeValue`,
  DROP COLUMN `MovementFlags2`;

ALTER TABLE `spell_class_options` MODIFY COLUMN `SpellClassSet` int NOT NULL DEFAULT 0 AFTER `ModalNextSpell`;
