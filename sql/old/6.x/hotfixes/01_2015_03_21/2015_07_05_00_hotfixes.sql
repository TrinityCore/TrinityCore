--
-- Table structure for table `auction_house`
--

DROP TABLE IF EXISTS `auction_house`;
CREATE TABLE `auction_house` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `FactionID` int(10) unsigned NOT NULL DEFAULT '0',
  `DepositRate` int(10) unsigned NOT NULL DEFAULT '0',
  `ConsignmentRate` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `auction_house_locale`
--

DROP TABLE IF EXISTS `auction_house_locale`;
CREATE TABLE `auction_house_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `barber_shop_style`
--

DROP TABLE IF EXISTS `barber_shop_style`;
CREATE TABLE `barber_shop_style` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Type` int(10) unsigned NOT NULL DEFAULT '0',
  `DisplayName` text,
  `Description` text,
  `CostModifier` float NOT NULL DEFAULT '0',
  `Race` int(10) unsigned NOT NULL DEFAULT '0',
  `Sex` int(10) unsigned NOT NULL DEFAULT '0',
  `Data` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `barber_shop_style_locale`
--

DROP TABLE IF EXISTS `barber_shop_style_locale`;
CREATE TABLE `barber_shop_style_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `DisplayName_lang` text,
  `Description_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `char_start_outfit`
--

DROP TABLE IF EXISTS `char_start_outfit`;
CREATE TABLE `char_start_outfit` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `RaceID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ClassID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `GenderID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `OutfitID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `ItemID1` int(11) NOT NULL DEFAULT '0',
  `ItemID2` int(11) NOT NULL DEFAULT '0',
  `ItemID3` int(11) NOT NULL DEFAULT '0',
  `ItemID4` int(11) NOT NULL DEFAULT '0',
  `ItemID5` int(11) NOT NULL DEFAULT '0',
  `ItemID6` int(11) NOT NULL DEFAULT '0',
  `ItemID7` int(11) NOT NULL DEFAULT '0',
  `ItemID8` int(11) NOT NULL DEFAULT '0',
  `ItemID9` int(11) NOT NULL DEFAULT '0',
  `ItemID10` int(11) NOT NULL DEFAULT '0',
  `ItemID11` int(11) NOT NULL DEFAULT '0',
  `ItemID12` int(11) NOT NULL DEFAULT '0',
  `ItemID13` int(11) NOT NULL DEFAULT '0',
  `ItemID14` int(11) NOT NULL DEFAULT '0',
  `ItemID15` int(11) NOT NULL DEFAULT '0',
  `ItemID16` int(11) NOT NULL DEFAULT '0',
  `ItemID17` int(11) NOT NULL DEFAULT '0',
  `ItemID18` int(11) NOT NULL DEFAULT '0',
  `ItemID19` int(11) NOT NULL DEFAULT '0',
  `ItemID20` int(11) NOT NULL DEFAULT '0',
  `ItemID21` int(11) NOT NULL DEFAULT '0',
  `ItemID22` int(11) NOT NULL DEFAULT '0',
  `ItemID23` int(11) NOT NULL DEFAULT '0',
  `ItemID24` int(11) NOT NULL DEFAULT '0',
  `PetDisplayID` int(10) unsigned NOT NULL DEFAULT '0',
  `PetFamilyID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `chr_classes_x_power_types`
--

DROP TABLE IF EXISTS `chr_classes_x_power_types`;
CREATE TABLE `chr_classes_x_power_types` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ClassID` int(10) unsigned NOT NULL DEFAULT '0',
  `PowerType` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `cinematic_sequences`
--

DROP TABLE IF EXISTS `cinematic_sequences`;
CREATE TABLE `cinematic_sequences` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SoundID` int(10) unsigned NOT NULL DEFAULT '0',
  `Camera1` int(10) unsigned NOT NULL DEFAULT '0',
  `Camera2` int(10) unsigned NOT NULL DEFAULT '0',
  `Camera3` int(10) unsigned NOT NULL DEFAULT '0',
  `Camera4` int(10) unsigned NOT NULL DEFAULT '0',
  `Camera5` int(10) unsigned NOT NULL DEFAULT '0',
  `Camera6` int(10) unsigned NOT NULL DEFAULT '0',
  `Camera7` int(10) unsigned NOT NULL DEFAULT '0',
  `Camera8` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `creature_display_info`
--

DROP TABLE IF EXISTS `creature_display_info`;
CREATE TABLE `creature_display_info` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ModelID` int(10) unsigned NOT NULL DEFAULT '0',
  `SoundID` int(10) unsigned NOT NULL DEFAULT '0',
  `ExtendedDisplayInfoID` int(10) unsigned NOT NULL DEFAULT '0',
  `CreatureModelScale` float NOT NULL DEFAULT '0',
  `Unknown620` float NOT NULL DEFAULT '0',
  `CreatureModelAlpha` int(10) unsigned NOT NULL DEFAULT '0',
  `TextureVariation1` text,
  `TextureVariation2` text,
  `TextureVariation3` text,
  `PortraitTextureName` text,
  `PortraitCreatureDisplayInfoID` int(10) unsigned NOT NULL DEFAULT '0',
  `SizeClass` int(10) unsigned NOT NULL DEFAULT '0',
  `BloodID` int(10) unsigned NOT NULL DEFAULT '0',
  `NPCSoundID` int(10) unsigned NOT NULL DEFAULT '0',
  `ParticleColorID` int(10) unsigned NOT NULL DEFAULT '0',
  `CreatureGeosetData` int(10) unsigned NOT NULL DEFAULT '0',
  `ObjectEffectPackageID` int(10) unsigned NOT NULL DEFAULT '0',
  `AnimReplacementSetID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `Gender` int(11) NOT NULL DEFAULT '0',
  `StateSpellVisualKitID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `creature_display_info_locale`
--

DROP TABLE IF EXISTS `creature_display_info_locale`;
CREATE TABLE `creature_display_info_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `TextureVariation_lang1` text,
  `TextureVariation_lang2` text,
  `TextureVariation_lang3` text,
  `PortraitTextureName_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `creature_type`
--

DROP TABLE IF EXISTS `creature_type`;
CREATE TABLE `creature_type` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `creature_type_locale`
--

DROP TABLE IF EXISTS `creature_type_locale`;
CREATE TABLE `creature_type_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `destructible_model_data`
--

DROP TABLE IF EXISTS `destructible_model_data`;
CREATE TABLE `destructible_model_data` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `StateDamagedDisplayID` int(10) unsigned NOT NULL DEFAULT '0',
  `StateDamagedImpactEffectDoodadSet` int(10) unsigned NOT NULL DEFAULT '0',
  `StateDamagedAmbientDoodadSet` int(10) unsigned NOT NULL DEFAULT '0',
  `StateDamagedNameSet` int(10) unsigned NOT NULL DEFAULT '0',
  `StateDestroyedDisplayID` int(10) unsigned NOT NULL DEFAULT '0',
  `StateDestroyedDestructionDoodadSet` int(10) unsigned NOT NULL DEFAULT '0',
  `StateDestroyedImpactEffectDoodadSet` int(10) unsigned NOT NULL DEFAULT '0',
  `StateDestroyedAmbientDoodadSet` int(10) unsigned NOT NULL DEFAULT '0',
  `StateDestroyedNameSet` int(10) unsigned NOT NULL DEFAULT '0',
  `StateRebuildingDisplayID` int(10) unsigned NOT NULL DEFAULT '0',
  `StateRebuildingDestructionDoodadSet` int(10) unsigned NOT NULL DEFAULT '0',
  `StateRebuildingImpactEffectDoodadSet` int(10) unsigned NOT NULL DEFAULT '0',
  `StateRebuildingAmbientDoodadSet` int(10) unsigned NOT NULL DEFAULT '0',
  `StateRebuildingNameSet` int(10) unsigned NOT NULL DEFAULT '0',
  `StateSmokeDisplayID` int(10) unsigned NOT NULL DEFAULT '0',
  `StateSmokeInitDoodadSet` int(10) unsigned NOT NULL DEFAULT '0',
  `StateSmokeAmbientDoodadSet` int(10) unsigned NOT NULL DEFAULT '0',
  `StateSmokeNameSet` int(10) unsigned NOT NULL DEFAULT '0',
  `EjectDirection` int(10) unsigned NOT NULL DEFAULT '0',
  `RepairGroundFx` int(10) unsigned NOT NULL DEFAULT '0',
  `DoNotHighlight` int(10) unsigned NOT NULL DEFAULT '0',
  `HealEffect` int(10) unsigned NOT NULL DEFAULT '0',
  `HealEffectSpeed` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `durability_quality`
--

DROP TABLE IF EXISTS `durability_quality`;
CREATE TABLE `durability_quality` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `QualityMod` float NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `glyph_slot`
--

DROP TABLE IF EXISTS `glyph_slot`;
CREATE TABLE `glyph_slot` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Type` int(10) unsigned NOT NULL DEFAULT '0',
  `Tooltip` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `guild_perk_spells`
--

DROP TABLE IF EXISTS `guild_perk_spells`;
CREATE TABLE `guild_perk_spells` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `GuildLevel` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `import_price_armor`
--

DROP TABLE IF EXISTS `import_price_armor`;
CREATE TABLE `import_price_armor` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ClothFactor` float NOT NULL DEFAULT '0',
  `LeatherFactor` float NOT NULL DEFAULT '0',
  `MailFactor` float NOT NULL DEFAULT '0',
  `PlateFactor` float NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `import_price_quality`
--

DROP TABLE IF EXISTS `import_price_quality`;
CREATE TABLE `import_price_quality` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Factor` float NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `import_price_shield`
--

DROP TABLE IF EXISTS `import_price_shield`;
CREATE TABLE `import_price_shield` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Factor` float NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `import_price_weapon`
--

DROP TABLE IF EXISTS `import_price_weapon`;
CREATE TABLE `import_price_weapon` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Factor` float NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `item_class`
--

DROP TABLE IF EXISTS `item_class`;
CREATE TABLE `item_class` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `PriceMod` float NOT NULL DEFAULT '0',
  `Name` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `item_class_locale`
--

DROP TABLE IF EXISTS `item_class_locale`;
CREATE TABLE `item_class_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `item_disenchant_loot`
--

DROP TABLE IF EXISTS `item_disenchant_loot`;
CREATE TABLE `item_disenchant_loot` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemClass` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemSubClass` int(11) NOT NULL DEFAULT '0',
  `ItemQuality` int(10) unsigned NOT NULL DEFAULT '0',
  `MinItemLevel` int(10) unsigned NOT NULL DEFAULT '0',
  `MaxItemLevel` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredDisenchantSkill` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `item_limit_category`
--

DROP TABLE IF EXISTS `item_limit_category`;
CREATE TABLE `item_limit_category` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Quantity` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `item_limit_category_locale`
--

DROP TABLE IF EXISTS `item_limit_category_locale`;
CREATE TABLE `item_limit_category_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `item_price_base`
--

DROP TABLE IF EXISTS `item_price_base`;
CREATE TABLE `item_price_base` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemLevel` int(10) unsigned NOT NULL DEFAULT '0',
  `ArmorFactor` float NOT NULL DEFAULT '0',
  `WeaponFactor` float NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `item_random_properties`
--

DROP TABLE IF EXISTS `item_random_properties`;
CREATE TABLE `item_random_properties` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `InternalName` text,
  `Enchantment1` int(10) unsigned NOT NULL DEFAULT '0',
  `Enchantment2` int(10) unsigned NOT NULL DEFAULT '0',
  `Enchantment3` int(10) unsigned NOT NULL DEFAULT '0',
  `Enchantment4` int(10) unsigned NOT NULL DEFAULT '0',
  `Enchantment5` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `item_random_properties_locale`
--

DROP TABLE IF EXISTS `item_random_properties_locale`;
CREATE TABLE `item_random_properties_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `InternalName_lang` text,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `item_random_suffix`
--

DROP TABLE IF EXISTS `item_random_suffix`;
CREATE TABLE `item_random_suffix` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `InternalName` text,
  `Enchantment1` int(10) unsigned NOT NULL DEFAULT '0',
  `Enchantment2` int(10) unsigned NOT NULL DEFAULT '0',
  `Enchantment3` int(10) unsigned NOT NULL DEFAULT '0',
  `Enchantment4` int(10) unsigned NOT NULL DEFAULT '0',
  `Enchantment5` int(10) unsigned NOT NULL DEFAULT '0',
  `AllocationPct1` int(10) unsigned NOT NULL DEFAULT '0',
  `AllocationPct2` int(10) unsigned NOT NULL DEFAULT '0',
  `AllocationPct3` int(10) unsigned NOT NULL DEFAULT '0',
  `AllocationPct4` int(10) unsigned NOT NULL DEFAULT '0',
  `AllocationPct5` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `item_random_suffix_locale`
--

DROP TABLE IF EXISTS `item_random_suffix_locale`;
CREATE TABLE `item_random_suffix_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `InternalName_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `item_spec`
--

DROP TABLE IF EXISTS `item_spec`;
CREATE TABLE `item_spec` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `MinLevel` int(10) unsigned NOT NULL DEFAULT '0',
  `MaxLevel` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemType` int(10) unsigned NOT NULL DEFAULT '0',
  `PrimaryStat` int(10) unsigned NOT NULL DEFAULT '0',
  `SecondaryStat` int(10) unsigned NOT NULL DEFAULT '0',
  `SpecID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `item_spec_override`
--

DROP TABLE IF EXISTS `item_spec_override`;
CREATE TABLE `item_spec_override` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpecID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `mail_template`
--

DROP TABLE IF EXISTS `mail_template`;
CREATE TABLE `mail_template` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Body` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `mail_template_locale`
--

DROP TABLE IF EXISTS `mail_template_locale`;
CREATE TABLE `mail_template_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Body_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `mount_capability`
--

DROP TABLE IF EXISTS `mount_capability`;
CREATE TABLE `mount_capability` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredRidingSkill` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredArea` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredAura` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredSpell` int(10) unsigned NOT NULL DEFAULT '0',
  `SpeedModSpell` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredMap` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `mount_type`
--

DROP TABLE IF EXISTS `mount_type_x_capability`;
CREATE TABLE `mount_type_x_capability` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `MountTypeID` int(10) unsigned NOT NULL DEFAULT '0',
  `OrderIndex` int(10) unsigned NOT NULL DEFAULT '0',
  `MountCapabilityID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `name_gen`
--

DROP TABLE IF EXISTS `name_gen`;
CREATE TABLE `name_gen` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Race` int(10) unsigned NOT NULL DEFAULT '0',
  `Sex` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `name_gen_locale`
--

DROP TABLE IF EXISTS `name_gen_locale`;
CREATE TABLE `name_gen_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `quest_money_reward`
--

DROP TABLE IF EXISTS `quest_money_reward`;
CREATE TABLE `quest_money_reward` (
  `Level` int(10) unsigned NOT NULL DEFAULT '0',
  `Money1` int(10) unsigned NOT NULL DEFAULT '0',
  `Money2` int(10) unsigned NOT NULL DEFAULT '0',
  `Money3` int(10) unsigned NOT NULL DEFAULT '0',
  `Money4` int(10) unsigned NOT NULL DEFAULT '0',
  `Money5` int(10) unsigned NOT NULL DEFAULT '0',
  `Money6` int(10) unsigned NOT NULL DEFAULT '0',
  `Money7` int(10) unsigned NOT NULL DEFAULT '0',
  `Money8` int(10) unsigned NOT NULL DEFAULT '0',
  `Money9` int(10) unsigned NOT NULL DEFAULT '0',
  `Money10` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`Level`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `quest_sort`
--

DROP TABLE IF EXISTS `quest_sort`;
CREATE TABLE `quest_sort` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SortName` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `quest_sort_locale`
--

DROP TABLE IF EXISTS `quest_sort_locale`;
CREATE TABLE `quest_sort_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `SortName_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `quest_v2`
--

DROP TABLE IF EXISTS `quest_v2`;
CREATE TABLE `quest_v2` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `UniqueBitFlag` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `quest_v2`
--

LOCK TABLES `quest_v2` WRITE;
/*!40000 ALTER TABLE `quest_v2` DISABLE KEYS */;
/*!40000 ALTER TABLE `quest_v2` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `quest_xp`
--

DROP TABLE IF EXISTS `quest_xp`;
CREATE TABLE `quest_xp` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Exp1` int(10) unsigned NOT NULL DEFAULT '0',
  `Exp2` int(10) unsigned NOT NULL DEFAULT '0',
  `Exp3` int(10) unsigned NOT NULL DEFAULT '0',
  `Exp4` int(10) unsigned NOT NULL DEFAULT '0',
  `Exp5` int(10) unsigned NOT NULL DEFAULT '0',
  `Exp6` int(10) unsigned NOT NULL DEFAULT '0',
  `Exp7` int(10) unsigned NOT NULL DEFAULT '0',
  `Exp8` int(10) unsigned NOT NULL DEFAULT '0',
  `Exp9` int(10) unsigned NOT NULL DEFAULT '0',
  `Exp10` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `scaling_stat_distribution`
--

DROP TABLE IF EXISTS `scaling_stat_distribution`;
CREATE TABLE `scaling_stat_distribution` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `MinLevel` int(10) unsigned NOT NULL DEFAULT '0',
  `MaxLevel` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemLevelCurveID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `specialization_spells`
--

DROP TABLE IF EXISTS `specialization_spells`;
CREATE TABLE `specialization_spells` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpecID` int(10) unsigned NOT NULL DEFAULT '0',
  `OrderIndex` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `OverridesSpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `Description` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `specialization_spells_locale`
--

DROP TABLE IF EXISTS `specialization_spells_locale`;
CREATE TABLE `specialization_spells_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Description_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `spell_cast_times`
--

DROP TABLE IF EXISTS `spell_cast_times`;
CREATE TABLE `spell_cast_times` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `CastTime` int(11) NOT NULL DEFAULT '0',
  `CastTimePerLevel` int(11) NOT NULL DEFAULT '0',
  `MinCastTime` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `spell_duration`
--

DROP TABLE IF EXISTS `spell_duration`;
CREATE TABLE `spell_duration` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Duration1` int(11) NOT NULL DEFAULT '0',
  `Duration2` int(11) NOT NULL DEFAULT '0',
  `Duration3` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `spell_item_enchantment_condition`
--

DROP TABLE IF EXISTS `spell_item_enchantment_condition`;
CREATE TABLE `spell_item_enchantment_condition` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `LTOperandType1` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `LTOperandType2` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `LTOperandType3` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `LTOperandType4` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `LTOperandType5` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `LTOperand1` int(10) unsigned NOT NULL DEFAULT '0',
  `LTOperand2` int(10) unsigned NOT NULL DEFAULT '0',
  `LTOperand3` int(10) unsigned NOT NULL DEFAULT '0',
  `LTOperand4` int(10) unsigned NOT NULL DEFAULT '0',
  `LTOperand5` int(10) unsigned NOT NULL DEFAULT '0',
  `Operator1` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Operator2` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Operator3` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Operator4` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Operator5` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RTOperandType1` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RTOperandType2` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RTOperandType3` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RTOperandType4` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RTOperandType5` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `RTOperand1` int(10) unsigned NOT NULL DEFAULT '0',
  `RTOperand2` int(10) unsigned NOT NULL DEFAULT '0',
  `RTOperand3` int(10) unsigned NOT NULL DEFAULT '0',
  `RTOperand4` int(10) unsigned NOT NULL DEFAULT '0',
  `RTOperand5` int(10) unsigned NOT NULL DEFAULT '0',
  `Logic1` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Logic2` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Logic3` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Logic4` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Logic5` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
--
-- Table structure for table `spell_radius`
--

DROP TABLE IF EXISTS `spell_radius`;
CREATE TABLE `spell_radius` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Radius` float NOT NULL DEFAULT '0',
  `RadiusPerLevel` float NOT NULL DEFAULT '0',
  `RadiusMin` float NOT NULL DEFAULT '0',
  `RadiusMax` float NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `spell_range`
--

DROP TABLE IF EXISTS `spell_range`;
CREATE TABLE `spell_range` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `MinRangeHostile` float NOT NULL DEFAULT '0',
  `MinRangeFriend` float NOT NULL DEFAULT '0',
  `MaxRangeHostile` float NOT NULL DEFAULT '0',
  `MaxRangeFriend` float NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `DisplayName` text,
  `DisplayNameShort` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `spell_range_locale`
--

DROP TABLE IF EXISTS `spell_range_locale`;
CREATE TABLE `spell_range_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `DisplayName_lang` text,
  `DisplayNameShort_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `spell_x_spell_visual`
--

DROP TABLE IF EXISTS `spell_x_spell_visual`;
CREATE TABLE `spell_x_spell_visual` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `DifficultyID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellVisualID1` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellVisualID2` int(10) unsigned NOT NULL DEFAULT '0',
  `Unk620` float NOT NULL DEFAULT '0',
  `PlayerConditionID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `totem_category`
--

DROP TABLE IF EXISTS `totem_category`;
CREATE TABLE `totem_category` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `CategoryType` int(10) unsigned NOT NULL DEFAULT '0',
  `CategoryMask` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `totem_category_locale`
--

DROP TABLE IF EXISTS `totem_category_locale`;
CREATE TABLE `totem_category_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `transport_animation`
--

DROP TABLE IF EXISTS `transport_animation`;
CREATE TABLE `transport_animation` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `TransportID` int(10) unsigned NOT NULL DEFAULT '0',
  `TimeIndex` int(10) unsigned NOT NULL DEFAULT '0',
  `PosX` float NOT NULL DEFAULT '0',
  `PosY` float NOT NULL DEFAULT '0',
  `PosZ` float NOT NULL DEFAULT '0',
  `SequenceID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `transport_rotation`
--

DROP TABLE IF EXISTS `transport_rotation`;
CREATE TABLE `transport_rotation` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `TransportID` int(10) unsigned NOT NULL DEFAULT '0',
  `TimeIndex` int(10) unsigned NOT NULL DEFAULT '0',
  `X` float NOT NULL DEFAULT '0',
  `Y` float NOT NULL DEFAULT '0',
  `Z` float NOT NULL DEFAULT '0',
  `W` float NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `unit_power_bar`
--

DROP TABLE IF EXISTS `unit_power_bar`;
CREATE TABLE `unit_power_bar` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `MinPower` int(10) unsigned NOT NULL DEFAULT '0',
  `MaxPower` int(10) unsigned NOT NULL DEFAULT '0',
  `StartPower` int(10) unsigned NOT NULL DEFAULT '0',
  `CenterPower` int(10) unsigned NOT NULL DEFAULT '0',
  `RegenerationPeace` float NOT NULL DEFAULT '0',
  `RegenerationCombat` float NOT NULL DEFAULT '0',
  `BarType` int(10) unsigned NOT NULL DEFAULT '0',
  `FileDataID1` int(10) unsigned NOT NULL DEFAULT '0',
  `FileDataID2` int(10) unsigned NOT NULL DEFAULT '0',
  `FileDataID3` int(10) unsigned NOT NULL DEFAULT '0',
  `FileDataID4` int(10) unsigned NOT NULL DEFAULT '0',
  `FileDataID5` int(10) unsigned NOT NULL DEFAULT '0',
  `FileDataID6` int(10) unsigned NOT NULL DEFAULT '0',
  `Color1` int(10) unsigned NOT NULL DEFAULT '0',
  `Color2` int(10) unsigned NOT NULL DEFAULT '0',
  `Color3` int(10) unsigned NOT NULL DEFAULT '0',
  `Color4` int(10) unsigned NOT NULL DEFAULT '0',
  `Color5` int(10) unsigned NOT NULL DEFAULT '0',
  `Color6` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Cost` text,
  `OutOfError` text,
  `ToolTip` text,
  `StartInset` float NOT NULL DEFAULT '0',
  `EndInset` float NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `unit_power_bar_locale`
--

DROP TABLE IF EXISTS `unit_power_bar_locale`;
CREATE TABLE `unit_power_bar_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `Cost_lang` text,
  `OutOfError_lang` text,
  `ToolTip_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `world_map_overlay`
--

DROP TABLE IF EXISTS `world_map_overlay`;
CREATE TABLE `world_map_overlay` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `MapAreaID` int(10) unsigned NOT NULL DEFAULT '0',
  `AreaID1` int(10) unsigned NOT NULL DEFAULT '0',
  `AreaID2` int(10) unsigned NOT NULL DEFAULT '0',
  `AreaID3` int(10) unsigned NOT NULL DEFAULT '0',
  `AreaID4` int(10) unsigned NOT NULL DEFAULT '0',
  `TextureName` text,
  `TextureWidth` int(10) unsigned NOT NULL DEFAULT '0',
  `TextureHeight` int(10) unsigned NOT NULL DEFAULT '0',
  `OffsetX` int(10) unsigned NOT NULL DEFAULT '0',
  `OffsetY` int(10) unsigned NOT NULL DEFAULT '0',
  `HitRectTop` int(10) unsigned NOT NULL DEFAULT '0',
  `HitRectLeft` int(10) unsigned NOT NULL DEFAULT '0',
  `HitRectBottom` int(10) unsigned NOT NULL DEFAULT '0',
  `HitRectRight` int(10) unsigned NOT NULL DEFAULT '0',
  `PlayerConditionID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `world_map_overlay_locale`
--

DROP TABLE IF EXISTS `world_map_overlay_locale`;
CREATE TABLE `world_map_overlay_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `TextureName_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

ALTER TABLE `garr_ability` ADD `FollowerTypeID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `GarrAbilityCategoryID`;
ALTER TABLE `garr_follower`
  ADD `FollowerTypeID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `ID`,
  ADD `HordeListPortraitTextureKitID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `AlliancePortraitIconID`,
  ADD `AllianceListPortraitTextureKitID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `HordeListPortraitTextureKitID`;
ALTER TABLE `item_effect` ADD `ChrSpecializationID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `CategoryCooldown`;
ALTER TABLE `spell_misc` DROP `SpellVisualID1`, DROP `SpellVisualID2`;
