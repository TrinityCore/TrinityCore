ALTER TABLE `achievement` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `achievement` MODIFY COLUMN `Description` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL FIRST;
ALTER TABLE `achievement` MODIFY COLUMN `Title` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Description`;
ALTER TABLE `achievement` MODIFY COLUMN `Reward` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Title`;

ALTER TABLE `achievement_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `achievement_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `achievement_locale` MODIFY COLUMN `Description_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `achievement_locale` MODIFY COLUMN `Title_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Description_lang`;
ALTER TABLE `achievement_locale` MODIFY COLUMN `Reward_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Title_lang`;
ALTER TABLE `achievement_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `anim_kit` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `animation_data` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `area_group_member` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `area_table` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `area_table` MODIFY COLUMN `ZoneName` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;
ALTER TABLE `area_table` MODIFY COLUMN `AreaName` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ZoneName`;

ALTER TABLE `area_table_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `area_table_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `area_table_locale` MODIFY COLUMN `AreaName_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `area_table_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `area_trigger` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `armor_location` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `artifact` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `artifact` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL FIRST;

ALTER TABLE `artifact_appearance` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `artifact_appearance` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL FIRST;

ALTER TABLE `artifact_appearance_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `artifact_appearance_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `artifact_appearance_locale` MODIFY COLUMN `Name_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `artifact_appearance_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `artifact_appearance_set` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `artifact_appearance_set` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL FIRST;
ALTER TABLE `artifact_appearance_set` MODIFY COLUMN `Description` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Name`;

ALTER TABLE `artifact_appearance_set_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `artifact_appearance_set_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `artifact_appearance_set_locale` MODIFY COLUMN `Name_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `artifact_appearance_set_locale` MODIFY COLUMN `Description_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Name_lang`;
ALTER TABLE `artifact_appearance_set_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `artifact_category` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `artifact_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `artifact_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `artifact_locale` MODIFY COLUMN `Name_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `artifact_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `artifact_power` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `artifact_power_link` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `artifact_power_picker` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `artifact_power_rank` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `artifact_quest_xp` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `artifact_tier` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `artifact_unlock` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `auction_house` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `auction_house` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;

ALTER TABLE `auction_house_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `auction_house_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `auction_house_locale` MODIFY COLUMN `Name_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `auction_house_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `azerite_empowered_item` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `azerite_essence` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `azerite_essence` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL FIRST;
ALTER TABLE `azerite_essence` MODIFY COLUMN `Description` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Name`;

ALTER TABLE `azerite_essence_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `azerite_essence_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `azerite_essence_locale` MODIFY COLUMN `Name_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `azerite_essence_locale` MODIFY COLUMN `Description_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Name_lang`;
ALTER TABLE `azerite_essence_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `azerite_essence_power` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `azerite_essence_power` MODIFY COLUMN `SourceAlliance` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;
ALTER TABLE `azerite_essence_power` MODIFY COLUMN `SourceHorde` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `SourceAlliance`;

ALTER TABLE `azerite_essence_power_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `azerite_essence_power_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `azerite_essence_power_locale` MODIFY COLUMN `SourceAlliance_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `azerite_essence_power_locale` MODIFY COLUMN `SourceHorde_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `SourceAlliance_lang`;
ALTER TABLE `azerite_essence_power_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `azerite_item` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `azerite_item_milestone_power` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `azerite_knowledge_multiplier` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `azerite_level_info` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `azerite_power` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `azerite_power_set_member` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `azerite_tier_unlock` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `azerite_tier_unlock_set` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `azerite_unlock_mapping` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `bank_bag_slot_prices` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `banned_addons` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `banned_addons` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;
ALTER TABLE `banned_addons` MODIFY COLUMN `Version` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Name`;

ALTER TABLE `barber_shop_style` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `barber_shop_style` MODIFY COLUMN `DisplayName` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL FIRST;
ALTER TABLE `barber_shop_style` MODIFY COLUMN `Description` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `DisplayName`;

ALTER TABLE `barber_shop_style_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `barber_shop_style_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `barber_shop_style_locale` MODIFY COLUMN `DisplayName_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `barber_shop_style_locale` MODIFY COLUMN `Description_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `DisplayName_lang`;
ALTER TABLE `barber_shop_style_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `battle_pet_breed_quality` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `battle_pet_breed_state` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `battle_pet_species` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `battle_pet_species` MODIFY COLUMN `Description` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL FIRST;
ALTER TABLE `battle_pet_species` MODIFY COLUMN `SourceText` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Description`;

ALTER TABLE `battle_pet_species_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `battle_pet_species_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `battle_pet_species_locale` MODIFY COLUMN `Description_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `battle_pet_species_locale` MODIFY COLUMN `SourceText_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Description_lang`;
ALTER TABLE `battle_pet_species_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `battle_pet_species_state` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `battlemaster_list` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `battlemaster_list` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;
ALTER TABLE `battlemaster_list` MODIFY COLUMN `GameType` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Name`;
ALTER TABLE `battlemaster_list` MODIFY COLUMN `ShortDescription` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `GameType`;
ALTER TABLE `battlemaster_list` MODIFY COLUMN `LongDescription` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ShortDescription`;

ALTER TABLE `battlemaster_list_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `battlemaster_list_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `battlemaster_list_locale` MODIFY COLUMN `Name_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `battlemaster_list_locale` MODIFY COLUMN `GameType_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Name_lang`;
ALTER TABLE `battlemaster_list_locale` MODIFY COLUMN `ShortDescription_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `GameType_lang`;
ALTER TABLE `battlemaster_list_locale` MODIFY COLUMN `LongDescription_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ShortDescription_lang`;
ALTER TABLE `battlemaster_list_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `broadcast_text` CHARACTER SET = utf8mb4, COLLATE = utf8mb4_unicode_ci;
ALTER TABLE `broadcast_text` MODIFY COLUMN `Text` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL FIRST;
ALTER TABLE `broadcast_text` MODIFY COLUMN `Text1` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Text`;

ALTER TABLE `broadcast_text_locale` CHARACTER SET = utf8mb4, COLLATE = utf8mb4_unicode_ci;
ALTER TABLE `broadcast_text_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `broadcast_text_locale` MODIFY COLUMN `Text_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `broadcast_text_locale` MODIFY COLUMN `Text1_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Text_lang`;
ALTER TABLE `broadcast_text_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `cfg_regions` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `cfg_regions` MODIFY COLUMN `Tag` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;

ALTER TABLE `char_base_section` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `char_sections` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `char_start_outfit` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `char_titles` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `char_titles` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;
ALTER TABLE `char_titles` MODIFY COLUMN `Name1` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Name`;

ALTER TABLE `char_titles_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `char_titles_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `char_titles_locale` MODIFY COLUMN `Name_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `char_titles_locale` MODIFY COLUMN `Name1_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Name_lang`;
ALTER TABLE `char_titles_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `character_facial_hair_styles` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `chat_channels` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `chat_channels` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;
ALTER TABLE `chat_channels` MODIFY COLUMN `Shortcut` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Name`;

ALTER TABLE `chat_channels_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `chat_channels_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `chat_channels_locale` MODIFY COLUMN `Name_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `chat_channels_locale` MODIFY COLUMN `Shortcut_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Name_lang`;
ALTER TABLE `chat_channels_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `chr_classes` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `chr_classes` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL FIRST;
ALTER TABLE `chr_classes` MODIFY COLUMN `Filename` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Name`;
ALTER TABLE `chr_classes` MODIFY COLUMN `NameMale` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Filename`;
ALTER TABLE `chr_classes` MODIFY COLUMN `NameFemale` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `NameMale`;
ALTER TABLE `chr_classes` MODIFY COLUMN `PetNameToken` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `NameFemale`;

ALTER TABLE `chr_classes_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `chr_classes_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `chr_classes_locale` MODIFY COLUMN `Name_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `chr_classes_locale` MODIFY COLUMN `NameMale_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Name_lang`;
ALTER TABLE `chr_classes_locale` MODIFY COLUMN `NameFemale_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `NameMale_lang`;
ALTER TABLE `chr_classes_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `chr_classes_x_power_types` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `chr_races` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `chr_races` MODIFY COLUMN `ClientPrefix` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL FIRST;
ALTER TABLE `chr_races` MODIFY COLUMN `ClientFileString` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ClientPrefix`;
ALTER TABLE `chr_races` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ClientFileString`;
ALTER TABLE `chr_races` MODIFY COLUMN `NameFemale` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Name`;
ALTER TABLE `chr_races` MODIFY COLUMN `NameLowercase` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `NameFemale`;
ALTER TABLE `chr_races` MODIFY COLUMN `NameFemaleLowercase` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `NameLowercase`;

ALTER TABLE `chr_races_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `chr_races_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `chr_races_locale` MODIFY COLUMN `Name_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `chr_races_locale` MODIFY COLUMN `NameFemale_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Name_lang`;
ALTER TABLE `chr_races_locale` MODIFY COLUMN `NameLowercase_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `NameFemale_lang`;
ALTER TABLE `chr_races_locale` MODIFY COLUMN `NameFemaleLowercase_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `NameLowercase_lang`;
ALTER TABLE `chr_races_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `chr_specialization` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `chr_specialization` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL FIRST;
ALTER TABLE `chr_specialization` MODIFY COLUMN `FemaleName` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Name`;
ALTER TABLE `chr_specialization` MODIFY COLUMN `Description` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `FemaleName`;

ALTER TABLE `chr_specialization_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `chr_specialization_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `chr_specialization_locale` MODIFY COLUMN `Name_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `chr_specialization_locale` MODIFY COLUMN `FemaleName_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Name_lang`;
ALTER TABLE `chr_specialization_locale` MODIFY COLUMN `Description_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `FemaleName_lang`;
ALTER TABLE `chr_specialization_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `cinematic_camera` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `cinematic_sequences` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `content_tuning` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `content_tuning_x_expected` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `conversation_line` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `creature_display_info` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `creature_display_info_extra` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `creature_family` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `creature_family` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;

ALTER TABLE `creature_family_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `creature_family_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `creature_family_locale` MODIFY COLUMN `Name_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `creature_family_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `creature_model_data` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `creature_type` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `creature_type` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;

ALTER TABLE `creature_type_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `creature_type_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `creature_type_locale` MODIFY COLUMN `Name_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `creature_type_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `criteria` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `criteria_tree` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `criteria_tree` MODIFY COLUMN `Description` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;

ALTER TABLE `criteria_tree_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `criteria_tree_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `criteria_tree_locale` MODIFY COLUMN `Description_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `criteria_tree_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `currency_types` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `currency_types` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;
ALTER TABLE `currency_types` MODIFY COLUMN `Description` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Name`;

ALTER TABLE `currency_types_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `currency_types_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `currency_types_locale` MODIFY COLUMN `Name_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `currency_types_locale` MODIFY COLUMN `Description_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Name_lang`;
ALTER TABLE `currency_types_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `curve` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `curve_point` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `destructible_model_data` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `difficulty` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `difficulty` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;

ALTER TABLE `difficulty_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `difficulty_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `difficulty_locale` MODIFY COLUMN `Name_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `difficulty_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `dungeon_encounter` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `dungeon_encounter` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL FIRST;

ALTER TABLE `dungeon_encounter_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `dungeon_encounter_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `dungeon_encounter_locale` MODIFY COLUMN `Name_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `dungeon_encounter_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `durability_costs` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `durability_quality` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `emotes` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `emotes` MODIFY COLUMN `EmoteSlashCommand` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `RaceMask`;

ALTER TABLE `emotes_text` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `emotes_text` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;

ALTER TABLE `emotes_text_sound` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `expected_stat` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `expected_stat_mod` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `faction` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `faction` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ReputationRaceMask4`;
ALTER TABLE `faction` MODIFY COLUMN `Description` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Name`;

ALTER TABLE `faction_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `faction_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `faction_locale` MODIFY COLUMN `Name_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `faction_locale` MODIFY COLUMN `Description_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Name_lang`;
ALTER TABLE `faction_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `faction_template` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `gameobject_display_info` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `gameobjects` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `gameobjects` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL FIRST;

ALTER TABLE `gameobjects_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `gameobjects_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `gameobjects_locale` MODIFY COLUMN `Name_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `gameobjects_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `garr_ability` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `garr_ability` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL FIRST;
ALTER TABLE `garr_ability` MODIFY COLUMN `Description` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Name`;

ALTER TABLE `garr_ability_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `garr_ability_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `garr_ability_locale` MODIFY COLUMN `Name_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `garr_ability_locale` MODIFY COLUMN `Description_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Name_lang`;
ALTER TABLE `garr_ability_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `garr_building` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `garr_building` MODIFY COLUMN `HordeName` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;
ALTER TABLE `garr_building` MODIFY COLUMN `AllianceName` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `HordeName`;
ALTER TABLE `garr_building` MODIFY COLUMN `Description` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `AllianceName`;
ALTER TABLE `garr_building` MODIFY COLUMN `Tooltip` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Description`;

ALTER TABLE `garr_building_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `garr_building_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `garr_building_locale` MODIFY COLUMN `HordeName_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `garr_building_locale` MODIFY COLUMN `AllianceName_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `HordeName_lang`;
ALTER TABLE `garr_building_locale` MODIFY COLUMN `Description_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `AllianceName_lang`;
ALTER TABLE `garr_building_locale` MODIFY COLUMN `Tooltip_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Description_lang`;
ALTER TABLE `garr_building_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `garr_building_plot_inst` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `garr_class_spec` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `garr_class_spec` MODIFY COLUMN `ClassSpec` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL FIRST;
ALTER TABLE `garr_class_spec` MODIFY COLUMN `ClassSpecMale` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ClassSpec`;
ALTER TABLE `garr_class_spec` MODIFY COLUMN `ClassSpecFemale` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ClassSpecMale`;

ALTER TABLE `garr_class_spec_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `garr_class_spec_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `garr_class_spec_locale` MODIFY COLUMN `ClassSpec_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `garr_class_spec_locale` MODIFY COLUMN `ClassSpecMale_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ClassSpec_lang`;
ALTER TABLE `garr_class_spec_locale` MODIFY COLUMN `ClassSpecFemale_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ClassSpecMale_lang`;
ALTER TABLE `garr_class_spec_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `garr_follower` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `garr_follower` MODIFY COLUMN `HordeSourceText` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL FIRST;
ALTER TABLE `garr_follower` MODIFY COLUMN `AllianceSourceText` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `HordeSourceText`;
ALTER TABLE `garr_follower` MODIFY COLUMN `TitleName` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `AllianceSourceText`;

ALTER TABLE `garr_follower_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `garr_follower_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `garr_follower_locale` MODIFY COLUMN `HordeSourceText_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `garr_follower_locale` MODIFY COLUMN `AllianceSourceText_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `HordeSourceText_lang`;
ALTER TABLE `garr_follower_locale` MODIFY COLUMN `TitleName_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `AllianceSourceText_lang`;
ALTER TABLE `garr_follower_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `garr_follower_x_ability` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `garr_plot` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `garr_plot` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;

ALTER TABLE `garr_plot_building` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `garr_plot_instance` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `garr_plot_instance` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;

ALTER TABLE `garr_site_level` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `garr_site_level_plot_inst` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `gem_properties` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `glyph_bindable_spell` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `glyph_properties` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `glyph_required_spec` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `guild_color_background` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `guild_color_border` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `guild_color_emblem` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `guild_perk_spells` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `heirloom` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `heirloom` MODIFY COLUMN `SourceText` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL FIRST;

ALTER TABLE `heirloom_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `heirloom_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `heirloom_locale` MODIFY COLUMN `SourceText_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `heirloom_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `holidays` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `import_price_armor` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `import_price_quality` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `import_price_shield` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `import_price_weapon` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `item` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `item_appearance` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `item_armor_quality` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `item_armor_shield` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `item_armor_total` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `item_bag_family` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `item_bag_family` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;

ALTER TABLE `item_bag_family_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `item_bag_family_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `item_bag_family_locale` MODIFY COLUMN `Name_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `item_bag_family_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `item_bonus` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `item_bonus_list_level_delta` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `item_bonus_tree_node` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `item_child_equipment` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `item_class` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `item_class` MODIFY COLUMN `ClassName` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;

ALTER TABLE `item_class_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `item_class_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `item_class_locale` MODIFY COLUMN `ClassName_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `item_class_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `item_currency_cost` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `item_damage_ammo` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `item_damage_one_hand` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `item_damage_one_hand_caster` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `item_damage_two_hand` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `item_damage_two_hand_caster` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `item_disenchant_loot` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `item_effect` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `item_extended_cost` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `item_level_selector` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `item_level_selector_quality` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `item_level_selector_quality_set` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `item_limit_category` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `item_limit_category` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;

ALTER TABLE `item_limit_category_condition` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `item_limit_category_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `item_limit_category_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;

ALTER TABLE `item_limit_category_locale` MODIFY COLUMN `Name_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;

ALTER TABLE `item_limit_category_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `item_modified_appearance` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `item_name_description` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `item_name_description` MODIFY COLUMN `Description` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;

ALTER TABLE `item_name_description_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `item_name_description_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `item_name_description_locale` MODIFY COLUMN `Description_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `item_name_description_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `item_price_base` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `item_search_name` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `item_search_name` MODIFY COLUMN `Display` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `AllowableRace`;

ALTER TABLE `item_search_name_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `item_search_name_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `item_search_name_locale` MODIFY COLUMN `Display_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `item_search_name_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `item_set` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `item_set` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;

ALTER TABLE `item_set_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `item_set_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `item_set_locale` MODIFY COLUMN `Name_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `item_set_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `item_set_spell` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `item_sparse` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `item_sparse` MODIFY COLUMN `Description` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `AllowableRace`;
ALTER TABLE `item_sparse` MODIFY COLUMN `Display3` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Description`;
ALTER TABLE `item_sparse` MODIFY COLUMN `Display2` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Display3`;
ALTER TABLE `item_sparse` MODIFY COLUMN `Display1` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Display2`;
ALTER TABLE `item_sparse` MODIFY COLUMN `Display` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Display1`;

ALTER TABLE `item_sparse_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `item_sparse_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `item_sparse_locale` MODIFY COLUMN `Description_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `item_sparse_locale` MODIFY COLUMN `Display3_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Description_lang`;
ALTER TABLE `item_sparse_locale` MODIFY COLUMN `Display2_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Display3_lang`;
ALTER TABLE `item_sparse_locale` MODIFY COLUMN `Display1_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Display2_lang`;
ALTER TABLE `item_sparse_locale` MODIFY COLUMN `Display_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Display1_lang`;
ALTER TABLE `item_sparse_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `item_spec` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `item_spec_override` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `item_x_bonus_tree` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `keychain` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `lfg_dungeons` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `lfg_dungeons` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;
ALTER TABLE `lfg_dungeons` MODIFY COLUMN `Description` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Name`;

ALTER TABLE `lfg_dungeons_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `lfg_dungeons_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `lfg_dungeons_locale` MODIFY COLUMN `Name_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `lfg_dungeons_locale` MODIFY COLUMN `Description_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Name_lang`;
ALTER TABLE `lfg_dungeons_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `light` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `liquid_type` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `liquid_type` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;
ALTER TABLE `liquid_type` MODIFY COLUMN `Texture1` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Name`;
ALTER TABLE `liquid_type` MODIFY COLUMN `Texture2` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Texture1`;
ALTER TABLE `liquid_type` MODIFY COLUMN `Texture3` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Texture2`;
ALTER TABLE `liquid_type` MODIFY COLUMN `Texture4` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Texture3`;
ALTER TABLE `liquid_type` MODIFY COLUMN `Texture5` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Texture4`;
ALTER TABLE `liquid_type` MODIFY COLUMN `Texture6` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Texture5`;

ALTER TABLE `lock` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `mail_template` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `mail_template` MODIFY COLUMN `Body` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;

ALTER TABLE `mail_template_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `mail_template_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `mail_template_locale` MODIFY COLUMN `Body_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `mail_template_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `map` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `map` MODIFY COLUMN `Directory` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;
ALTER TABLE `map` MODIFY COLUMN `MapName` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Directory`;
ALTER TABLE `map` MODIFY COLUMN `MapDescription0` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `MapName`;
ALTER TABLE `map` MODIFY COLUMN `MapDescription1` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `MapDescription0`;
ALTER TABLE `map` MODIFY COLUMN `PvpShortDescription` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `MapDescription1`;
ALTER TABLE `map` MODIFY COLUMN `PvpLongDescription` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `PvpShortDescription`;

ALTER TABLE `map_difficulty` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `map_difficulty` MODIFY COLUMN `Message` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;

ALTER TABLE `map_difficulty_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `map_difficulty_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `map_difficulty_locale` MODIFY COLUMN `Message_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `map_difficulty_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `map_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `map_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `map_locale` MODIFY COLUMN `MapName_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `map_locale` MODIFY COLUMN `MapDescription0_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `MapName_lang`;
ALTER TABLE `map_locale` MODIFY COLUMN `MapDescription1_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `MapDescription0_lang`;
ALTER TABLE `map_locale` MODIFY COLUMN `PvpShortDescription_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `MapDescription1_lang`;
ALTER TABLE `map_locale` MODIFY COLUMN `PvpLongDescription_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `PvpShortDescription_lang`;
ALTER TABLE `map_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `modifier_tree` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `mount` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `mount` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL FIRST;
ALTER TABLE `mount` MODIFY COLUMN `SourceText` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Name`;
ALTER TABLE `mount` MODIFY COLUMN `Description` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `SourceText`;

ALTER TABLE `mount_capability` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `mount_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `mount_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `mount_locale` MODIFY COLUMN `Name_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `mount_locale` MODIFY COLUMN `SourceText_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Name_lang`;
ALTER TABLE `mount_locale` MODIFY COLUMN `Description_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `SourceText_lang`;
ALTER TABLE `mount_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `mount_type_x_capability` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `mount_x_display` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `movie` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `name_gen` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `name_gen` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;

ALTER TABLE `names_profanity` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `names_profanity` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;

ALTER TABLE `names_reserved` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `names_reserved` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;

ALTER TABLE `names_reserved_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `names_reserved_locale` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;

ALTER TABLE `num_talents_at_level` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `override_spell_data` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `phase` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `phase_x_phase_group` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `player_condition` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `player_condition` MODIFY COLUMN `FailureDescription` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `RaceMask`;

ALTER TABLE `player_condition_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `player_condition_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `player_condition_locale` MODIFY COLUMN `FailureDescription_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `player_condition_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `power_display` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `power_display` MODIFY COLUMN `GlobalStringBaseTag` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;

ALTER TABLE `power_type` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `power_type` MODIFY COLUMN `NameGlobalStringTag` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL FIRST;
ALTER TABLE `power_type` MODIFY COLUMN `CostGlobalStringTag` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `NameGlobalStringTag`;

ALTER TABLE `prestige_level_info` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `prestige_level_info` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;

ALTER TABLE `prestige_level_info_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `prestige_level_info_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `prestige_level_info_locale` MODIFY COLUMN `Name_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `prestige_level_info_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `pvp_difficulty` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `pvp_item` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `pvp_talent` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `pvp_talent` MODIFY COLUMN `Description` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL FIRST;

ALTER TABLE `pvp_talent_category` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `pvp_talent_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `pvp_talent_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `pvp_talent_locale` MODIFY COLUMN `Description_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `pvp_talent_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `pvp_talent_slot_unlock` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `quest_faction_reward` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `quest_money_reward` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `quest_package_item` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `quest_sort` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `quest_sort` MODIFY COLUMN `SortName` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;

ALTER TABLE `quest_sort_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `quest_sort_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `quest_sort_locale` MODIFY COLUMN `SortName_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `quest_sort_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `quest_v2` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `quest_xp` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `rand_prop_points` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `reward_pack` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `reward_pack_x_currency_type` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `reward_pack_x_item` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `scaling_stat_distribution` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `scenario` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `scenario` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;

ALTER TABLE `scenario_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `scenario_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `scenario_locale` MODIFY COLUMN `Name_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `scenario_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `scenario_step` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `scenario_step` MODIFY COLUMN `Description` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;
ALTER TABLE `scenario_step` MODIFY COLUMN `Title` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Description`;

ALTER TABLE `scenario_step_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `scenario_step_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `scenario_step_locale` MODIFY COLUMN `Description_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `scenario_step_locale` MODIFY COLUMN `Title_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Description_lang`;
ALTER TABLE `scenario_step_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `scene_script` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `scene_script_global_text` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `scene_script_global_text` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;
ALTER TABLE `scene_script_global_text` MODIFY COLUMN `Script` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Name`;

ALTER TABLE `scene_script_package` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `scene_script_package` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;

ALTER TABLE `scene_script_text` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `scene_script_text` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;
ALTER TABLE `scene_script_text` MODIFY COLUMN `Script` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Name`;

ALTER TABLE `skill_line` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `skill_line` MODIFY COLUMN `DisplayName` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL FIRST;
ALTER TABLE `skill_line` MODIFY COLUMN `AlternateVerb` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `DisplayName`;
ALTER TABLE `skill_line` MODIFY COLUMN `Description` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `AlternateVerb`;
ALTER TABLE `skill_line` MODIFY COLUMN `HordeDisplayName` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Description`;
ALTER TABLE `skill_line` MODIFY COLUMN `OverrideSourceInfoDisplayName` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `HordeDisplayName`;

ALTER TABLE `skill_line_ability` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `skill_line_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `skill_line_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `skill_line_locale` MODIFY COLUMN `DisplayName_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `skill_line_locale` MODIFY COLUMN `AlternateVerb_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `DisplayName_lang`;
ALTER TABLE `skill_line_locale` MODIFY COLUMN `Description_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `AlternateVerb_lang`;
ALTER TABLE `skill_line_locale` MODIFY COLUMN `HordeDisplayName_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Description_lang`;
ALTER TABLE `skill_line_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `skill_race_class_info` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `sound_kit` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `spec_set_member` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `specialization_spells` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `specialization_spells` MODIFY COLUMN `Description` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL FIRST;

ALTER TABLE `specialization_spells_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `specialization_spells_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `specialization_spells_locale` MODIFY COLUMN `Description_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `specialization_spells_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `spell_aura_options` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `spell_aura_restrictions` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `spell_cast_times` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `spell_casting_requirements` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `spell_categories` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `spell_category` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `spell_category` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;

ALTER TABLE `spell_category_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `spell_category_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `spell_category_locale` MODIFY COLUMN `Name_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `spell_category_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `spell_class_options` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `spell_cooldowns` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `spell_duration` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `spell_effect` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `spell_equipped_items` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `spell_focus_object` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `spell_focus_object` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;

ALTER TABLE `spell_focus_object_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `spell_focus_object_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `spell_focus_object_locale` MODIFY COLUMN `Name_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `spell_focus_object_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `spell_interrupts` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `spell_item_enchantment` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `spell_item_enchantment` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;
ALTER TABLE `spell_item_enchantment` MODIFY COLUMN `HordeName` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Name`;

ALTER TABLE `spell_item_enchantment_condition` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `spell_item_enchantment_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `spell_item_enchantment_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `spell_item_enchantment_locale` MODIFY COLUMN `Name_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `spell_item_enchantment_locale` MODIFY COLUMN `HordeName_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Name_lang`;

ALTER TABLE `spell_item_enchantment_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `spell_learn_spell` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `spell_levels` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `spell_misc` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `spell_name` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `spell_name` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;

ALTER TABLE `spell_name_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `spell_name_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `spell_name_locale` MODIFY COLUMN `Name_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `spell_name_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `spell_power` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `spell_power_difficulty` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `spell_procs_per_minute` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `spell_procs_per_minute_mod` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `spell_radius` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `spell_range` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `spell_range` MODIFY COLUMN `DisplayName` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;
ALTER TABLE `spell_range` MODIFY COLUMN `DisplayNameShort` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `DisplayName`;

ALTER TABLE `spell_range_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `spell_range_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `spell_range_locale` MODIFY COLUMN `DisplayName_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `spell_range_locale` MODIFY COLUMN `DisplayNameShort_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `DisplayName_lang`;
ALTER TABLE `spell_range_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `spell_reagents` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `spell_scaling` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `spell_shapeshift` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `spell_shapeshift_form` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `spell_shapeshift_form` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;

ALTER TABLE `spell_shapeshift_form_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `spell_shapeshift_form_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `spell_shapeshift_form_locale` MODIFY COLUMN `Name_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `spell_shapeshift_form_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `spell_target_restrictions` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `spell_totems` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `spell_visual_kit` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `spell_x_spell_visual` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `summon_properties` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `tact_key` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `talent` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `talent` MODIFY COLUMN `Description` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;

ALTER TABLE `talent_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `talent_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `talent_locale` MODIFY COLUMN `Description_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `talent_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `taxi_nodes` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `taxi_nodes` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL FIRST;

ALTER TABLE `taxi_nodes_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `taxi_nodes_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `taxi_nodes_locale` MODIFY COLUMN `Name_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `taxi_nodes_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `taxi_path` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `taxi_path_node` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `totem_category` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `totem_category` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;

ALTER TABLE `totem_category_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `totem_category_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `totem_category_locale` MODIFY COLUMN `Name_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `totem_category_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `toy` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `toy` MODIFY COLUMN `SourceText` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL FIRST;

ALTER TABLE `toy_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `toy_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `toy_locale` MODIFY COLUMN `SourceText_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `toy_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `transmog_holiday` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `transmog_set` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `transmog_set` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL FIRST;

ALTER TABLE `transmog_set_group` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `transmog_set_group` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL FIRST;

ALTER TABLE `transmog_set_group_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `transmog_set_group_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `transmog_set_group_locale` MODIFY COLUMN `Name_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `transmog_set_group_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `transmog_set_item` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `transmog_set_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `transmog_set_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `transmog_set_locale` MODIFY COLUMN `Name_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `transmog_set_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `transport_animation` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `transport_rotation` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `ui_map` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `ui_map` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL FIRST;

ALTER TABLE `ui_map_assignment` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `ui_map_link` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `ui_map_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `ui_map_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `ui_map_locale` MODIFY COLUMN `Name_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `ui_map_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `ui_map_x_map_art` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `unit_power_bar` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `unit_power_bar` MODIFY COLUMN `Name` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;
ALTER TABLE `unit_power_bar` MODIFY COLUMN `Cost` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Name`;
ALTER TABLE `unit_power_bar` MODIFY COLUMN `OutOfError` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Cost`;
ALTER TABLE `unit_power_bar` MODIFY COLUMN `ToolTip` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `OutOfError`;

ALTER TABLE `unit_power_bar_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `unit_power_bar_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `unit_power_bar_locale` MODIFY COLUMN `Name_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `unit_power_bar_locale` MODIFY COLUMN `Cost_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Name_lang`;
ALTER TABLE `unit_power_bar_locale` MODIFY COLUMN `OutOfError_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `Cost_lang`;
ALTER TABLE `unit_power_bar_locale` MODIFY COLUMN `ToolTip_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `OutOfError_lang`;
ALTER TABLE `unit_power_bar_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `vehicle` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `vehicle_seat` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `wmo_area_table` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `wmo_area_table` MODIFY COLUMN `AreaName` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL FIRST;

ALTER TABLE `wmo_area_table_locale` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `wmo_area_table_locale` MODIFY COLUMN `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL AFTER `ID`;
ALTER TABLE `wmo_area_table_locale` MODIFY COLUMN `AreaName_lang` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `locale`;
ALTER TABLE `wmo_area_table_locale` ADD INDEX `idx_locale`(`locale`);

ALTER TABLE `world_effect` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `world_map_overlay` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `world_state_expression` CHARACTER SET=utf8mb4, COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `world_state_expression` MODIFY COLUMN `Expression` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`;
