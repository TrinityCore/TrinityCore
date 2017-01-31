--
-- Table structure for table `item_instance_artifact`
--
DROP TABLE IF EXISTS `item_instance_artifact`;
CREATE TABLE `item_instance_artifact` (
  `itemGuid` bigint(20) unsigned NOT NULL,
  `xp` int(10) unsigned NOT NULL DEFAULT '0',
  `artifactAppearanceId` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`itemGuid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Table structure for table `item_instance_artifact_powers`
--
DROP TABLE IF EXISTS `item_instance_artifact_powers`;
CREATE TABLE `item_instance_artifact_powers` (
  `itemGuid` bigint(20) unsigned NOT NULL,
  `artifactPowerId` int(10) unsigned NOT NULL,
  `purchasedRank` tinyint(3) unsigned DEFAULT '0',
  PRIMARY KEY (`itemGuid`,`artifactPowerId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Table structure for table `item_instance_modifiers`
--
DROP TABLE IF EXISTS `item_instance_modifiers`;
CREATE TABLE `item_instance_modifiers` (
  `itemGuid` bigint(20) unsigned NOT NULL,
  `fixedScalingLevel` int(10) unsigned DEFAULT '0',
  `artifactKnowledgeLevel` int(10) unsigned DEFAULT '0',
  PRIMARY KEY (`itemGuid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

ALTER TABLE `character_void_storage`
  ADD `fixedScalingLevel` int(10) unsigned DEFAULT '0' AFTER `upgradeId`,
  ADD `artifactKnowledgeLevel` int(10) unsigned DEFAULT '0' AFTER `fixedScalingLevel`;
