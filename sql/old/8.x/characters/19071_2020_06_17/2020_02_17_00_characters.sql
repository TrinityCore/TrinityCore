UPDATE `character_inventory` SET `slot`=`slot`+4 WHERE `slot`>=47 AND `bag`=0;

ALTER TABLE `item_instance_azerite`
  ADD `selectedAzeriteEssences1azeriteEssenceId4` int(10) unsigned NULL DEFAULT '0' AFTER `selectedAzeriteEssences1azeriteEssenceId3`,
  ADD `selectedAzeriteEssences2azeriteEssenceId4` int(10) unsigned NULL DEFAULT '0' AFTER `selectedAzeriteEssences2azeriteEssenceId3`,
  ADD `selectedAzeriteEssences3azeriteEssenceId4` int(10) unsigned NULL DEFAULT '0' AFTER `selectedAzeriteEssences3azeriteEssenceId3`,
  ADD `selectedAzeriteEssences4azeriteEssenceId4` int(10) unsigned NULL DEFAULT '0' AFTER `selectedAzeriteEssences4azeriteEssenceId3`;
