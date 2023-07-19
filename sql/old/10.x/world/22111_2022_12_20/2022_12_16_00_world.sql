--
-- Table structure for table `creature_template`
--
ALTER TABLE `creature_template` MODIFY `mechanic_immune_mask` bigint unsigned NOT NULL DEFAULT 0;

--
-- Table structure for table `gossip_menu_option`
--
ALTER TABLE `gossip_menu_option` 
  ADD `GossipOptionID` int NOT NULL DEFAULT 0 AFTER `MenuID`,
  ADD `Flags` int NOT NULL DEFAULT 0 AFTER `Language`,
  ADD `GossipNpcOptionID` int NULL DEFAULT NULL AFTER `ActionPoiID`,
  ADD `SpellID` int NULL DEFAULT NULL AFTER `BoxBroadcastTextID`,
  ADD `OverrideIconID` int NULL DEFAULT NULL AFTER `SpellID`;

-- give it a temporary dummy unique value
UPDATE `gossip_menu_option` SET `GossipOptionID`=-((`MenuID`<<8) | `OptionID`);

DROP TABLE IF EXISTS `gossip_menu_option_addon`;

--
-- Table structure for table `quest_completion_log_conditional`
--
DROP TABLE IF EXISTS `quest_completion_log_conditional`;
CREATE TABLE `quest_completion_log_conditional` (
  `QuestId` int NOT NULL,
  `PlayerConditionId` int NOT NULL,
  `QuestgiverCreatureId` int NOT NULL,
  `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  `Text` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci,
  `OrderIndex` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`QuestId`,`PlayerConditionId`,`QuestgiverCreatureId`,`locale`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `quest_description_conditional`
--
DROP TABLE IF EXISTS `quest_description_conditional`;
CREATE TABLE `quest_description_conditional` (
  `QuestId` int NOT NULL,
  `PlayerConditionId` int NOT NULL,
  `QuestgiverCreatureId` int NOT NULL,
  `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  `Text` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci,
  `OrderIndex` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`QuestId`,`PlayerConditionId`,`QuestgiverCreatureId`,`locale`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
ALTER TABLE `creature_template` MODIFY `mechanic_immune_mask` bigint unsigned NOT NULL DEFAULT 0;

--
-- Table structure for table `quest_offer_reward_conditional`
--
DROP TABLE IF EXISTS `quest_offer_reward_conditional`;
CREATE TABLE `quest_offer_reward_conditional` (
  `QuestId` int NOT NULL,
  `PlayerConditionId` int NOT NULL,
  `QuestgiverCreatureId` int NOT NULL,
  `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  `Text` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci,
  `OrderIndex` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`QuestId`,`PlayerConditionId`,`QuestgiverCreatureId`,`locale`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `quest_request_items_conditional`
--
DROP TABLE IF EXISTS `quest_request_items_conditional`;
CREATE TABLE `quest_request_items_conditional` (
  `QuestId` int NOT NULL,
  `PlayerConditionId` int NOT NULL,
  `QuestgiverCreatureId` int NOT NULL,
  `locale` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  `Text` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci,
  `OrderIndex` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`QuestId`,`PlayerConditionId`,`QuestgiverCreatureId`,`locale`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `serverside_spell`
--
ALTER TABLE `serverside_spell`
  ADD `CasterAuraType` int NOT NULL DEFAULT 0 AFTER `ExcludeTargetAuraSpell`,
  ADD `TargetAuraType` int NOT NULL DEFAULT 0 AFTER `CasterAuraType`,
  ADD `ExcludeCasterAuraType` int NOT NULL DEFAULT 0 AFTER `TargetAuraType`,
  ADD `ExcludeTargetAuraType` int NOT NULL DEFAULT 0 AFTER `ExcludeCasterAuraType`;
