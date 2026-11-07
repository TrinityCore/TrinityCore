ALTER TABLE `achievement` MODIFY `UiOrder` smallint UNSIGNED NOT NULL DEFAULT 0 AFTER `Flags`;

ALTER TABLE `achievement_category` MODIFY `UiOrder` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `Parent`;

ALTER TABLE `area_trigger` MODIFY `ContinentID` smallint UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `artifact_power` MODIFY `Tier` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `Flags`;

ALTER TABLE `azerite_power_set_member` MODIFY `AzeritePowerSetID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;
ALTER TABLE `azerite_power_set_member` MODIFY `Tier` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `Class`;

ALTER TABLE `battle_pet_breed_quality` MODIFY `QualityEnum` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `StateMultiplier`;

ALTER TABLE `broadcast_text_duration` MODIFY `BroadcastTextID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `character_loadout` MODIFY `ItemContext` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `Purpose`;

ALTER TABLE `chr_customization_choice` MODIFY `ChrCustomizationOptionID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `chr_customization_option` MODIFY `ChrModelID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `Sex`;

ALTER TABLE `chr_model` MODIFY `DisplayID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `Sex`;

ALTER TABLE `chr_race_x_chr_model` MODIFY `ChrRacesID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `chr_specialization` MODIFY `ClassID` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `conditional_chr_model` MODIFY `ChrModelID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `difficulty` MODIFY `ItemContext` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `Flags`;

ALTER TABLE `dungeon_encounter` MODIFY `MapID` smallint UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `friendship_rep_reaction` MODIFY `FriendshipRepID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `Reaction`;

ALTER TABLE `gameobjects` MODIFY `OwnerID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `garr_building` MODIFY `BuildingType` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `GarrTypeID`;

ALTER TABLE `garr_mission` MODIFY `GarrMissionSetID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `PlayerConditionID`;

ALTER TABLE `garr_plot` MODIFY `PlotType` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `Name`;

ALTER TABLE `garr_talent_tree` MODIFY `FeatureSubtypeIndex` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `FeatureTypeIndex`;

ALTER TABLE `glyph_properties` MODIFY `GlyphType` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `SpellID`;

ALTER TABLE `item_bonus_list_group_entry` MODIFY `ItemBonusListGroupID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `item_bonus_tree_node` MODIFY `ItemContext` int NOT NULL DEFAULT 0 AFTER `ID`;
UPDATE `item_bonus_tree_node` SET `ItemContext` = `ItemContext` + 256 WHERE `ItemContext` < 0;
ALTER TABLE `item_bonus_tree_node` MODIFY `ItemContext` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `item_child_equipment` MODIFY `ParentItemID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `item_context_picker_entry` MODIFY `ItemCreationContext` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `item_currency_cost` MODIFY `ItemID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `item_modified_appearance` MODIFY `ItemID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `lfg_dungeons` MODIFY `Subtype` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `TypeID`;

ALTER TABLE `map_difficulty` MODIFY `ResetInterval` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `LockID`;

ALTER TABLE `maw_power` MODIFY `SpellID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `player_condition` MODIFY `PowerTypeComp` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `PowerType`;

ALTER TABLE `pvp_stat` MODIFY `MapID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `pvp_talent` MODIFY `SpecID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `pvp_tier` MODIFY `BracketID` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `NextTier`;

ALTER TABLE `skill_line_ability` MODIFY `SkillLine` smallint UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `skill_line_x_trait_tree` MODIFY `SkillLineID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `skill_race_class_info` MODIFY `SkillID` smallint UNSIGNED NOT NULL DEFAULT 0 AFTER `RaceMask`;

ALTER TABLE `spell_learn_spell` MODIFY `SpellID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `spell_reagents_currency` MODIFY `SpellID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `trait_cond` MODIFY `TraitTreeID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `CondType`;

ALTER TABLE `trait_currency_source` MODIFY `TraitCurrencyID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `trait_definition_effect_points` MODIFY `TraitDefinitionID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `trait_edge` MODIFY `LeftTraitNodeID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `VisualStyle`;

ALTER TABLE `trait_node` MODIFY `TraitTreeID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `trait_node_entry_x_trait_cond` MODIFY `TraitNodeEntryID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `TraitCondID`;

ALTER TABLE `trait_node_entry_x_trait_cost` MODIFY `TraitNodeEntryID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `trait_node_group` MODIFY `TraitTreeID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `trait_node_group_x_trait_cond` MODIFY `TraitNodeGroupID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `TraitCondID`;

ALTER TABLE `trait_node_group_x_trait_cost` MODIFY `TraitNodeGroupID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `trait_node_group_x_trait_node` MODIFY `TraitNodeGroupID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `trait_node_x_trait_cond` MODIFY `TraitNodeID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `TraitCondID`;

ALTER TABLE `trait_node_x_trait_cost` MODIFY `TraitNodeID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `trait_node_x_trait_node_entry` MODIFY `TraitNodeID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `trait_sub_tree` MODIFY `TraitTreeID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `UiTextureAtlasElementID`;

ALTER TABLE `trait_tree` MODIFY `TraitSystemID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `trait_tree_loadout` MODIFY `TraitTreeID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `trait_tree_loadout_entry` MODIFY `TraitTreeLoadoutID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `trait_tree_x_trait_currency` MODIFY `TraitTreeID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `Index`;

ALTER TABLE `transmog_set` MODIFY `ParentTransmogSetID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `ItemNameDescriptionID`;

ALTER TABLE `ui_map` MODIFY `ParentUiMapID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;
ALTER TABLE `ui_map` MODIFY `System` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `Flags`;

ALTER TABLE `ui_map_assignment` MODIFY `UiMapID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `ui_map_link` MODIFY `ParentUiMapID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `ui_splash_screen` MODIFY `ScreenType` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `HordeQuestID`;
