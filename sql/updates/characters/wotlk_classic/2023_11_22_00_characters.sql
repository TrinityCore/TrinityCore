ALTER TABLE `item_instance`   
	DROP COLUMN `bonusListIDs`,
	DROP COLUMN `randomBonusListId`;

DROP TABLE IF EXISTS `item_instance_artifact`;
DROP TABLE IF EXISTS `item_instance_artifact_powers`;
DROP TABLE IF EXISTS `item_instance_azerite`;
DROP TABLE IF EXISTS `item_instance_azerite_empowered`;
DROP TABLE IF EXISTS `item_instance_azerite_milestone_power`;
DROP TABLE IF EXISTS `item_instance_azerite_unlocked_essence`;

ALTER TABLE `character_void_storage`   
	DROP COLUMN `randomBonusListId`, 
	DROP COLUMN `artifactKnowledgeLevel`, 
	DROP COLUMN `bonusListIDs`;

ALTER TABLE `item_loot_items`   
	DROP COLUMN `rnd_bonus`, 
	DROP COLUMN `bonus_list_ids`;
