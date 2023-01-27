UPDATE character_battle_pet_journal SET breedID = 0 WHERE breedID < 0;
ALTER TABLE `item_instance` CHANGE `transmogrifyId` `transmogrifyId` INT(10) NULL;