ALTER TABLE `area_group_member` MODIFY COLUMN `AreaGroupID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `AreaID`;

ALTER TABLE `artifact_appearance_set` MODIFY COLUMN `ArtifactID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Flags`;

ALTER TABLE `artifact_power_rank` MODIFY COLUMN `ArtifactPowerID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `AuraPointsOverride`;

ALTER TABLE `artifact_unlock` MODIFY COLUMN `ArtifactID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `PlayerConditionID`;

ALTER TABLE `battle_pet_breed_state` MODIFY COLUMN `BattlePetBreedID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Value`;

ALTER TABLE `battle_pet_species_state` MODIFY COLUMN `BattlePetSpeciesID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Value`;

ALTER TABLE `char_start_outfit` MODIFY COLUMN `RaceID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `ItemID24`;

ALTER TABLE `chr_classes_x_power_types` MODIFY COLUMN `ClassID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `PowerType`;

ALTER TABLE `content_tuning_x_expected` MODIFY COLUMN `ContentTuningID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `ExpectedStatModID`;

ALTER TABLE `emotes_text_sound` MODIFY COLUMN `EmotesTextID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `SoundID`;

ALTER TABLE `expected_stat` MODIFY COLUMN `Lvl` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `CreatureSpellDamage`;

ALTER TABLE `garr_follower_x_ability` MODIFY COLUMN `GarrFollowerID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `GarrAbilityID`;

ALTER TABLE `glyph_bindable_spell` MODIFY COLUMN `GlyphPropertiesID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `SpellID`;

ALTER TABLE `glyph_required_spec` MODIFY COLUMN `GlyphPropertiesID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `ChrSpecializationID`;

ALTER TABLE `item_bonus_tree_node` MODIFY COLUMN `ParentItemBonusTreeID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `ChildItemLevelSelectorID`;

ALTER TABLE `item_disenchant_loot` MODIFY COLUMN `Class` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `ExpansionID`;

ALTER TABLE `item_effect` MODIFY COLUMN `ParentItemID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `ChrSpecializationID`;

ALTER TABLE `item_level_selector_quality` MODIFY COLUMN `ParentILSQualitySetID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Quality`;

ALTER TABLE `item_limit_category_condition` MODIFY COLUMN `ParentItemLimitCategoryID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `PlayerConditionID`;

ALTER TABLE `item_set_spell` MODIFY COLUMN `ItemSetID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Threshold`;

ALTER TABLE `item_spec_override` MODIFY COLUMN `ItemID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `SpecID`;

ALTER TABLE `item_x_bonus_tree` MODIFY COLUMN `ItemID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `ItemBonusTreeID`;

ALTER TABLE `map_difficulty` MODIFY COLUMN `MapID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `ContentTuningID`;

ALTER TABLE `mount_x_display` MODIFY COLUMN `MountID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `PlayerConditionID`;

ALTER TABLE `phase_x_phase_group` MODIFY COLUMN `PhaseGroupID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `PhaseID`;

ALTER TABLE `pvp_difficulty` MODIFY COLUMN `MapID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `MaxLevel`;

ALTER TABLE `reward_pack_x_item` MODIFY COLUMN `RewardPackID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `ItemQuantity`;

ALTER TABLE `spec_set_member` MODIFY COLUMN `SpecSetID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `ChrSpecializationID`;

ALTER TABLE `spell_aura_options` MODIFY COLUMN `SpellID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `ProcTypeMask2`;

ALTER TABLE `spell_aura_restrictions` MODIFY COLUMN `SpellID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `ExcludeTargetAuraSpell`;

ALTER TABLE `spell_categories` MODIFY COLUMN `SpellID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `ChargeCategory`;

ALTER TABLE `spell_cooldowns` MODIFY COLUMN `SpellID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `StartRecoveryTime`;

ALTER TABLE `spell_effect` MODIFY COLUMN `SpellID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `ImplicitTarget2`;

ALTER TABLE `spell_interrupts` MODIFY COLUMN `SpellID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `ChannelInterruptFlags2`;

ALTER TABLE `spell_levels` MODIFY COLUMN `SpellID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `MaxPassiveAuraLevel`;

ALTER TABLE `spell_misc` MODIFY COLUMN `SpellID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `ContentTuningID`;

ALTER TABLE `spell_power` MODIFY COLUMN `SpellID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `OptionalCost`;

ALTER TABLE `spell_procs_per_minute_mod` MODIFY COLUMN `SpellProcsPerMinuteID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Coeff`;

ALTER TABLE `spell_target_restrictions` MODIFY COLUMN `SpellID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Width`;

ALTER TABLE `spell_x_spell_visual` MODIFY COLUMN `SpellID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `CasterPlayerConditionID`;

ALTER TABLE `transport_animation` MODIFY COLUMN `TransportID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `TimeIndex`;

ALTER TABLE `transport_rotation` MODIFY COLUMN `GameObjectsID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `TimeIndex`;

ALTER TABLE `ui_map_x_map_art` MODIFY COLUMN `UiMapID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `UiMapArtID`;
