ALTER TABLE `creature_template` DROP `FadeRegionRadius`;

ALTER TABLE `playerchoice_response`
  ADD `ResponseIdentifier` smallint(5) unsigned NOT NULL AFTER `ResponseId`,
  ADD `UiTextureKitID` int(11) NOT NULL DEFAULT '0' AFTER `GroupID`;

--
-- Table structure for table `playerchoice_response_reward_item_choice`
--
DROP TABLE IF EXISTS `playerchoice_response_reward_item_choice`;
CREATE TABLE `playerchoice_response_reward_item_choice` (
  `ChoiceId` int(11) NOT NULL,
  `ResponseId` int(11) NOT NULL,
  `Index` int(10) unsigned NOT NULL,
  `ItemId` int(10) unsigned NOT NULL DEFAULT '0',
  `BonusListIDs` text,
  `Quantity` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ChoiceId`,`ResponseId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `playerchoice_response_maw_power`
--
DROP TABLE IF EXISTS `playerchoice_response_maw_power`;
CREATE TABLE `playerchoice_response_maw_power` (
  `ChoiceId` int(11) NOT NULL,
  `ResponseId` int(11) NOT NULL,
  `TypeArtFileID` int(11) DEFAULT '0',
  `Rarity` int(11) DEFAULT '0',
  `RarityColor` int(10) unsigned DEFAULT '0',
  `SpellID` int(11) DEFAULT '0',
  `MaxStacks` int(11) DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ChoiceId`,`ResponseId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

ALTER TABLE `quest_poi` ADD `NavigationPlayerConditionID` int(11) NOT NULL DEFAULT '0' AFTER `PlayerConditionID`;

ALTER TABLE `quest_poi_points` ADD `Z` int(11) NOT NULL DEFAULT '0' AFTER `Y`;

--
-- Table structure for table `quest_reward_choice_items`
--
DROP TABLE IF EXISTS `quest_reward_choice_items`;
CREATE TABLE `quest_reward_choice_items` (
  `QuestID` int(10) unsigned NOT NULL,
  `Type1` tinyint(3) unsigned DEFAULT '0',
  `Type2` tinyint(3) unsigned DEFAULT '0',
  `Type3` tinyint(3) unsigned DEFAULT '0',
  `Type4` tinyint(3) unsigned DEFAULT '0',
  `Type5` tinyint(3) unsigned DEFAULT '0',
  `Type6` tinyint(3) unsigned DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`QuestID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `quest_reward_display_spell`
--
DROP TABLE IF EXISTS `quest_reward_display_spell`;
CREATE TABLE `quest_reward_display_spell` (
  `QuestID` int(10) unsigned NOT NULL,
  `Idx` int(10) unsigned NOT NULL,
  `SpellID` int(10) unsigned DEFAULT '0',
  `PlayerConditionID` int(10) unsigned DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`QuestID`,`Idx`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

ALTER TABLE `quest_template`
  ADD `ContentTuningID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `QuestPackageID`,
  DROP `QuestLevel`,
  DROP `ScalingFactionGroup`,
  DROP `MaxScalingLevel`,
  DROP `MinLevel`;

ALTER TABLE `scenario_poi` ADD `NavigationPlayerConditionID` int(11) NOT NULL DEFAULT '0' AFTER `PlayerConditionID`;

ALTER TABLE `scenario_poi_points` ADD `Z` int(11) NOT NULL DEFAULT '0' AFTER `Y`;
