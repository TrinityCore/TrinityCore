ALTER TABLE `creature_model_data` MODIFY `MountScaleOther1` float NOT NULL DEFAULT 0 AFTER `Unknown1100`;
ALTER TABLE `creature_model_data` MODIFY `MountScaleOther2` float NOT NULL DEFAULT 0 AFTER `MountScaleOther1`;

ALTER TABLE `friendship_rep_reaction` MODIFY `FriendshipRepID` int NOT NULL DEFAULT 0 AFTER `Reaction`;
ALTER TABLE `friendship_rep_reaction` MODIFY `ReactionThreshold` int NOT NULL DEFAULT 0 AFTER `FriendshipRepID`;

ALTER TABLE `garr_mission` MODIFY `GarrFollowerTypeID` tinyint NOT NULL DEFAULT 0 AFTER `GarrMissionTypeID`;

ALTER TABLE `garr_plot` MODIFY `PlotType` tinyint NOT NULL DEFAULT 0 AFTER `Name`;

ALTER TABLE `map_difficulty` ADD `WorldStateExpressionID` int NOT NULL DEFAULT 0 AFTER `ContentTuningID`;

ALTER TABLE `quest_sort` ADD `Flags` int NOT NULL DEFAULT 0 AFTER `UiOrderIndex`;

ALTER TABLE `spell_shapeshift_form` DROP `CreatureDisplayID2`;
ALTER TABLE `spell_shapeshift_form` DROP `CreatureDisplayID3`;
ALTER TABLE `spell_shapeshift_form` DROP `CreatureDisplayID4`;

ALTER TABLE `trait_cond` ADD `TraitNodeEntryID` int NOT NULL DEFAULT 0 AFTER `TraitNodeID`;

ALTER TABLE `ui_map` ADD `MapArtZoneTextPosition` tinyint NOT NULL DEFAULT 0 AFTER `AdventureMapTextureKitID`;
