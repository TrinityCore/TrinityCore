ALTER TABLE `achievement`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `achievement_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `anim_kit`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `animation_data`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `area_group_member`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `area_table`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `area_table_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `area_trigger`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `armor_location`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `artifact`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `artifact_appearance`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `artifact_appearance_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `artifact_appearance_set`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `artifact_appearance_set_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `artifact_category`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `artifact_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `artifact_power`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `artifact_power_link`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `artifact_power_picker`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `artifact_power_rank`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `artifact_quest_xp`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `artifact_tier`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `artifact_unlock`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `auction_house`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `auction_house_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `azerite_empowered_item`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `azerite_essence`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `azerite_essence_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `azerite_essence_power`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `azerite_essence_power_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `azerite_item`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `azerite_item_milestone_power`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `azerite_knowledge_multiplier`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `azerite_level_info`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `azerite_power`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `azerite_power_set_member`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `azerite_tier_unlock`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `azerite_tier_unlock_set`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `azerite_unlock_mapping`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `bank_bag_slot_prices`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `banned_addons`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `barber_shop_style`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `barber_shop_style_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `battle_pet_breed_quality`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `battle_pet_breed_state`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `battle_pet_species`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `battle_pet_species_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `battle_pet_species_state`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `battlemaster_list`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `battlemaster_list_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `broadcast_text`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `broadcast_text_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `cfg_regions`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `char_base_section`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `char_sections`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `char_start_outfit`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `char_titles`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `char_titles_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `character_facial_hair_styles`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `chat_channels`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `chat_channels_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `chr_classes`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `chr_classes_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `chr_classes_x_power_types`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `chr_races`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `chr_races_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `chr_specialization`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `chr_specialization_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `cinematic_camera`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `cinematic_sequences`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `content_tuning`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `content_tuning_x_expected`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `conversation_line`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `creature_display_info`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `creature_display_info_extra`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `creature_family`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `creature_family_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `creature_model_data`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `creature_type`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `creature_type_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `criteria`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `criteria_tree`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `criteria_tree_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `currency_types`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `currency_types_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `curve`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `curve_point`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `destructible_model_data`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `difficulty`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `difficulty_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `dungeon_encounter`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `dungeon_encounter_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `durability_costs`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `durability_quality`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `emotes`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `emotes_text`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `emotes_text_sound`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `expected_stat`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `expected_stat_mod`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `faction`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `faction_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `faction_template`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `gameobject_display_info`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `gameobjects`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `gameobjects_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `garr_ability`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `garr_ability_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `garr_building`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `garr_building_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `garr_building_plot_inst`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `garr_class_spec`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `garr_class_spec_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `garr_follower`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `garr_follower_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `garr_follower_x_ability`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `garr_plot`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `garr_plot_building`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `garr_plot_instance`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `garr_site_level`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `garr_site_level_plot_inst`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `gem_properties`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `glyph_bindable_spell`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `glyph_properties`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `glyph_required_spec`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `guild_color_background`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `guild_color_border`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `guild_color_emblem`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `guild_perk_spells`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `heirloom`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `heirloom_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `holidays`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `import_price_armor`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `import_price_quality`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `import_price_shield`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `import_price_weapon`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `item`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `item_appearance`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `item_armor_quality`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `item_armor_shield`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `item_armor_total`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `item_bag_family`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `item_bag_family_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `item_bonus`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `item_bonus_list_level_delta`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `item_bonus_tree_node`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `item_child_equipment`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `item_class`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `item_class_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `item_currency_cost`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `item_damage_ammo`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `item_damage_one_hand`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `item_damage_one_hand_caster`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `item_damage_two_hand`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `item_damage_two_hand_caster`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `item_disenchant_loot`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `item_effect`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `item_extended_cost`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `item_level_selector`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `item_level_selector_quality`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `item_level_selector_quality_set`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `item_limit_category`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `item_limit_category_condition`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `item_limit_category_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `item_modified_appearance`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `item_name_description`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `item_name_description_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `item_price_base`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `item_search_name`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `item_search_name_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `item_set`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `item_set_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `item_set_spell`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `item_sparse`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `item_sparse_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `item_spec`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `item_spec_override`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `item_x_bonus_tree`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `keychain`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `lfg_dungeons`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `lfg_dungeons_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `light`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `liquid_type`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `lock`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `mail_template`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `mail_template_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `map`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `map_difficulty`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `map_difficulty_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `map_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `modifier_tree`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `mount`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `mount_capability`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `mount_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `mount_type_x_capability`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `mount_x_display`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `movie`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `name_gen`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `names_profanity`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `names_reserved`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `names_reserved_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `num_talents_at_level`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `override_spell_data`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `phase`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `phase_x_phase_group`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `player_condition`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `player_condition_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `power_display`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `power_type`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `prestige_level_info`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `prestige_level_info_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `pvp_difficulty`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `pvp_item`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `pvp_talent`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `pvp_talent_category`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `pvp_talent_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `pvp_talent_slot_unlock`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `quest_faction_reward`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `quest_money_reward`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `quest_package_item`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `quest_sort`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `quest_sort_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `quest_v2`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `quest_xp`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `rand_prop_points`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `reward_pack`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `reward_pack_x_currency_type`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `reward_pack_x_item`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `scaling_stat_distribution`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `scenario`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `scenario_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `scenario_step`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `scenario_step_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `scene_script`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `scene_script_global_text`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `scene_script_package`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `scene_script_text`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `skill_line`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `skill_line_ability`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `skill_line_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `skill_race_class_info`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `sound_kit`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `spec_set_member`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `specialization_spells`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `specialization_spells_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `spell_aura_options`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `spell_aura_restrictions`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `spell_cast_times`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `spell_casting_requirements`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `spell_categories`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `spell_category`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `spell_category_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `spell_class_options`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `spell_cooldowns`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `spell_duration`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `spell_effect`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `spell_equipped_items`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `spell_focus_object`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `spell_focus_object_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `spell_interrupts`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `spell_item_enchantment`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `spell_item_enchantment_condition`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `spell_item_enchantment_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `spell_learn_spell`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `spell_levels`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `spell_misc`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `spell_name`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `spell_name_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `spell_power`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `spell_power_difficulty`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `spell_procs_per_minute`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `spell_procs_per_minute_mod`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `spell_radius`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `spell_range`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `spell_range_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `spell_reagents`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `spell_scaling`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `spell_shapeshift`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `spell_shapeshift_form`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `spell_shapeshift_form_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `spell_target_restrictions`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `spell_totems`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `spell_visual_kit`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `spell_x_spell_visual`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `summon_properties`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `tact_key`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `talent`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `talent_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `taxi_nodes`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `taxi_nodes_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `taxi_path`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `taxi_path_node`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `totem_category`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `totem_category_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `toy`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `toy_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `transmog_holiday`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `transmog_set`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `transmog_set_group`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `transmog_set_group_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `transmog_set_item`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `transmog_set_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `transport_animation`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `transport_rotation`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `ui_map`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `ui_map_assignment`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `ui_map_link`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `ui_map_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `ui_map_x_map_art`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `unit_power_bar`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `unit_power_bar_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `vehicle`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `vehicle_seat`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `wmo_area_table`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `wmo_area_table_locale`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`),
  DROP INDEX `idx_locale`,
  ENGINE=InnoDB
  PARTITION BY LIST COLUMNS(`locale`)
  (PARTITION deDE VALUES IN ('deDE'),
   PARTITION esES VALUES IN ('esES'),
   PARTITION esMX VALUES IN ('esMX'),
   PARTITION frFR VALUES IN ('frFR'),
   PARTITION itIT VALUES IN ('itIT'),
   PARTITION koKR VALUES IN ('koKR'),
   PARTITION ptBR VALUES IN ('ptBR'),
   PARTITION ruRU VALUES IN ('ruRU'),
   PARTITION zhCN VALUES IN ('zhCN'),
   PARTITION zhTW VALUES IN ('zhTW'));

ALTER TABLE `world_effect`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `world_map_overlay`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;

ALTER TABLE `world_state_expression`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`ID`,`VerifiedBuild`),
  ENGINE=InnoDB;
