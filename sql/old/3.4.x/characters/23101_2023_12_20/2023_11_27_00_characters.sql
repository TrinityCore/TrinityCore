ALTER TABLE `item_instance`   
	ADD COLUMN `randomPropertiesId` INT DEFAULT 0 NOT NULL AFTER `battlePetDisplayId`,
	ADD COLUMN `randomPropertiesSeed` INT DEFAULT 0 NOT NULL AFTER `randomPropertiesId`;

ALTER TABLE `item_loot_items`   
	ADD COLUMN `random_properties_id` INT DEFAULT 0 NOT NULL AFTER `needs_quest`,
	ADD COLUMN `random_properties_seed` INT DEFAULT 0 NOT NULL AFTER `random_properties_id`;

ALTER TABLE `character_void_storage`   
	ADD COLUMN `randomPropertiesId` INT DEFAULT 0 NOT NULL AFTER `fixedScalingLevel`,
	ADD COLUMN `randomPropertiesSeed` INT DEFAULT 0 NOT NULL AFTER `randomPropertiesId`;
