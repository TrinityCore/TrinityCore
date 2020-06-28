ALTER TABLE `item_instance_azerite` 
  ADD `selectedAzeriteEssences1specId` int(10) unsigned NULL DEFAULT '0',
  ADD `selectedAzeriteEssences1azeriteEssenceId1` int(10) unsigned NULL DEFAULT '0',
  ADD `selectedAzeriteEssences1azeriteEssenceId2` int(10) unsigned NULL DEFAULT '0',
  ADD `selectedAzeriteEssences1azeriteEssenceId3` int(10) unsigned NULL DEFAULT '0',
  ADD `selectedAzeriteEssences2specId` int(10) unsigned NULL DEFAULT '0',
  ADD `selectedAzeriteEssences2azeriteEssenceId1` int(10) unsigned NULL DEFAULT '0',
  ADD `selectedAzeriteEssences2azeriteEssenceId2` int(10) unsigned NULL DEFAULT '0',
  ADD `selectedAzeriteEssences2azeriteEssenceId3` int(10) unsigned NULL DEFAULT '0',
  ADD `selectedAzeriteEssences3specId` int(10) unsigned NULL DEFAULT '0',
  ADD `selectedAzeriteEssences3azeriteEssenceId1` int(10) unsigned NULL DEFAULT '0',
  ADD `selectedAzeriteEssences3azeriteEssenceId2` int(10) unsigned NULL DEFAULT '0',
  ADD `selectedAzeriteEssences3azeriteEssenceId3` int(10) unsigned NULL DEFAULT '0',
  ADD `selectedAzeriteEssences4specId` int(10) unsigned NULL DEFAULT '0',
  ADD `selectedAzeriteEssences4azeriteEssenceId1` int(10) unsigned NULL DEFAULT '0',
  ADD `selectedAzeriteEssences4azeriteEssenceId2` int(10) unsigned NULL DEFAULT '0',
  ADD `selectedAzeriteEssences4azeriteEssenceId3` int(10) unsigned NULL DEFAULT '0';

--
-- Table structure for table `item_instance_azerite_milestone_power`
--
DROP TABLE IF EXISTS `item_instance_azerite_milestone_power`;
CREATE TABLE `item_instance_azerite_milestone_power` (
  `itemGuid` bigint(20) unsigned NOT NULL,
  `azeriteItemMilestonePowerId` int(10) unsigned NOT NULL,
  PRIMARY KEY (`itemGuid`,`azeriteItemMilestonePowerId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Table structure for table `item_instance_azerite_unlocked_essence`
--
DROP TABLE IF EXISTS `item_instance_azerite_unlocked_essence`;
CREATE TABLE `item_instance_azerite_unlocked_essence` (
  `itemGuid` bigint(20) unsigned NOT NULL,
  `azeriteEssenceId` int(10) unsigned NOT NULL,
  `rank` int(10) unsigned NOT NULL,
  PRIMARY KEY (`itemGuid`,`azeriteEssenceId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
