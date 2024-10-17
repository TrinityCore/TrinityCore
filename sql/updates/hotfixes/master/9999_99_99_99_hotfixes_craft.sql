DROP TABLE IF EXISTS `crafting_data`;
CREATE TABLE `crafting_data` (
	`ID` INT(10) UNSIGNED NOT NULL,
	`Type` INT(10) NOT NULL DEFAULT '0',
	`CraftingDifficultyID` INT(10) NOT NULL DEFAULT '0',
	`CraftedItemID` INT(10) NOT NULL DEFAULT '0',
	`ItemBonusTreeID` INT(10) NOT NULL DEFAULT '0',
	`CraftingDifficulty` INT(10) NOT NULL DEFAULT '0',
	`Field_10_0_0_44649_005` FLOAT(10) NOT NULL DEFAULT '0',
	`CraftSkillBonusPercent` FLOAT(10) NOT NULL DEFAULT '0',
	`ReCraftSkillBonusPercent` FLOAT(10) NOT NULL DEFAULT '0',
	`InspirationSkillBonusPercent` FLOAT(10) NOT NULL DEFAULT '0',
	`Field_10_0_0_44649_009` FLOAT(10) NOT NULL DEFAULT '0',
	`Field_10_0_0_45141_011` FLOAT(10) NOT NULL DEFAULT '0',
	`FirstCraftFlagQuestID` INT(10) NOT NULL DEFAULT '0',
	`FirstCraftTreasureID` INT(10) NOT NULL DEFAULT '0',
	`Field_10_2_5_52432_014` INT(10) NOT NULL DEFAULT '0',
	`CraftedTreasureID` INT(10) NOT NULL DEFAULT '0',
	`VerifiedBuild` INT(10) NOT NULL DEFAULT '0',
    PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;


DROP TABLE IF EXISTS `crafting_data_item_quality`;
CREATE TABLE `crafting_data_item_quality` (
	`ID` INT(10) UNSIGNED NOT NULL,
	`ItemID` INT(10) NOT NULL DEFAULT '0',
	`CraftingDataID` INT(10) NOT NULL DEFAULT '0',
	`VerifiedBuild` INT(10) NOT NULL DEFAULT '0',
    PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;


DROP TABLE IF EXISTS `crafting_difficulty`;
CREATE TABLE `crafting_difficulty` (
	`ID` INT(10) UNSIGNED NOT NULL,
	`MaxRandomSkillBonusPercent` FLOAT(10) NOT NULL DEFAULT '0',
	`CraftSkillBonusPercent` FLOAT(10) NOT NULL DEFAULT '0',
	`ReCraftSkillBonusPercent` FLOAT(10) NOT NULL DEFAULT '0',
	`InspirationSkillBonusPercent` FLOAT(10) NOT NULL DEFAULT '0',
	`Field_10_0_0_44649_004` FLOAT(10) NOT NULL DEFAULT '0',
	`ConcentrationSkillCurveID` INT(10) NOT NULL DEFAULT '0',
	`ConcentrationDifficultyCurveID` INT(10) NOT NULL DEFAULT '0',
	`VerifiedBuild` INT(10) NOT NULL DEFAULT '0',
    PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;


DROP TABLE IF EXISTS `crafting_difficulty_quality`;
CREATE TABLE `crafting_difficulty_quality` (
	`ID` INT(10) UNSIGNED NOT NULL,
	`Order` INT(10) NOT NULL DEFAULT '0',
	`CraftingQualityID` INT(10) NOT NULL DEFAULT '0',
	`QualityPercentage` FLOAT(10) NOT NULL DEFAULT '0',
	`Field_10_0_0_44895_004` FLOAT(10) NOT NULL DEFAULT '0',
	`CraftingDifficultyID` INT(10) NOT NULL DEFAULT '0',
	`VerifiedBuild` INT(10) NOT NULL DEFAULT '0',
    PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;


DROP TABLE IF EXISTS `crafting_reagent_quality`;
CREATE TABLE `crafting_reagent_quality` (
	`ID` INT(10) UNSIGNED NOT NULL,
	`OrderIndex` INT(10) NOT NULL DEFAULT '0',
	`ItemID` INT(10) NOT NULL DEFAULT '0',
	`MaxDifficultyAdjustment` FLOAT(10) NOT NULL DEFAULT '0',
	`ReagentEffectPct` FLOAT(10) NOT NULL DEFAULT '0',
	`ModifiedCraftingCategoryID` INT(10) NOT NULL DEFAULT '0',
	`VerifiedBuild` INT(10) NOT NULL DEFAULT '0',
    PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;


DROP TABLE IF EXISTS `crafting_quality`;
CREATE TABLE `crafting_quality` (
	`ID` INT(10) UNSIGNED NOT NULL,
	`QualityTier` INT(10) NOT NULL DEFAULT '0',
	`VerifiedBuild` INT(10) NOT NULL DEFAULT '0',
    PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;


DROP TABLE IF EXISTS `mcr_slot_x_mcr_category`;
CREATE TABLE `mcr_slot_x_mcr_category` (
	`ID` INT(10) UNSIGNED NOT NULL,
	`ModifiedCraftingCategoryID` INT(10) NOT NULL DEFAULT '0',
	`Order` INT(10) NOT NULL DEFAULT '0',
	`ModifiedCraftingReagentSlotID` INT(10) NOT NULL DEFAULT '0',
	`VerifiedBuild` INT(10) NOT NULL DEFAULT '0',
    PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;


DROP TABLE IF EXISTS `modified_crafting_category`;
CREATE TABLE `modified_crafting_category` (
	`ID` INT(10) UNSIGNED NOT NULL,
	`DisplayName` text,
	`Description` text,
	`Field_9_0_1_33978_001` INT(10) NOT NULL DEFAULT '0',
	`MatQualityWeight` INT(10) NOT NULL DEFAULT '0',
	`Field_10_0_0_44649_004` INT(10) NOT NULL DEFAULT '0',
	`VerifiedBuild` INT(10) NOT NULL DEFAULT '0',
    PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;


DROP TABLE IF EXISTS `modified_crafting_category_locale`;
CREATE TABLE `modified_crafting_category_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `DisplayName_lang` text,
  `Description_lang` text,
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;


DROP TABLE IF EXISTS `modified_crafting_reagent_item`;
CREATE TABLE `modified_crafting_reagent_item` (
	`ID` INT(10) UNSIGNED NOT NULL,
	`Description` text,
	`ModifiedCraftingCategoryID` INT(10) NOT NULL DEFAULT '0',
	`ItemBonusTreeID` INT(10) NOT NULL DEFAULT '0',
	`Flags` INT(10) NOT NULL DEFAULT '0',
	`Field_9_1_0_38511_004` INT(10) NOT NULL DEFAULT '0',
	`ItemContextOffset` INT(10) NOT NULL DEFAULT '0',
	`VerifiedBuild` INT(10) NOT NULL DEFAULT '0',
    PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;


DROP TABLE IF EXISTS `modified_crafting_reagent_item_locale`;
CREATE TABLE `modified_crafting_reagent_item_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Description_lang` text,
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;


DROP TABLE IF EXISTS `modified_crafting_reagent_slot`;
CREATE TABLE `modified_crafting_reagent_slot` (
	`Name` text,
	`ID` INT(10) UNSIGNED NOT NULL,
	`Field_9_0_1_33978_001` INT(10) NOT NULL DEFAULT '0',
	`PlayerConditionID` INT(10) NOT NULL DEFAULT '0',
	`ReagentType` INT(10) NOT NULL DEFAULT '0',
	`Field_10_0_2_46091_005` INT(10) NOT NULL DEFAULT '0',
	`VerifiedBuild` INT(10) NOT NULL DEFAULT '0',
    PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;


DROP TABLE IF EXISTS `modified_crafting_reagent_slot_locale`;
CREATE TABLE `modified_crafting_reagent_slot_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

DROP TABLE IF EXISTS `modified_crafting_spell_slot`;
CREATE TABLE `modified_crafting_spell_slot` (
	`ID` INT(10) UNSIGNED NOT NULL,
	`SpellID` INT(10) NOT NULL DEFAULT '0',
	`Slot` INT(10) NOT NULL DEFAULT '0',
	`ModifiedCraftingReagentSlotID` INT(10) NOT NULL DEFAULT '0',
	`Field_9_0_1_35679_003` INT(10) NOT NULL DEFAULT '0',
	`ReagentCount` INT(10) NOT NULL DEFAULT '0',
	`ReagentReCraftCount` INT(10) NOT NULL DEFAULT '0',
	`VerifiedBuild` INT(10) NOT NULL DEFAULT '0',
    PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
