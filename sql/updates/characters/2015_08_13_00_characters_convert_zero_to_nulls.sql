-- auctionhouse
ALTER TABLE `auctionhouse` MODIFY `itemowner` INTEGER(10) UNSIGNED;
ALTER TABLE `auctionhouse` MODIFY `buyguid` INTEGER(10) UNSIGNED;
UPDATE `auctionhouse` SET `itemowner` = NULL WHERE `itemowner` = 0;
UPDATE `auctionhouse` SET `buyguid` = NULL WHERE `buyguid` = 0;

-- channel
UPDATE `channels` SET `password` = NULL WHERE `password` = '';

-- battleground_data
ALTER TABLE `character_battleground_data` MODIFY `instanceId` INTEGER(10) UNSIGNED DEFAULT NULL COMMENT 'Instance Identifier';
UPDATE `character_battleground_data` SET `instanceId` = NULL WHERE `instanceId` = 0;

-- equipmentsets
ALTER TABLE `character_equipmentsets` MODIFY `item0` INTEGER(10) UNSIGNED;
ALTER TABLE `character_equipmentsets` MODIFY `item1` INTEGER(10) UNSIGNED;
ALTER TABLE `character_equipmentsets` MODIFY `item2` INTEGER(10) UNSIGNED;
ALTER TABLE `character_equipmentsets` MODIFY `item3` INTEGER(10) UNSIGNED;
ALTER TABLE `character_equipmentsets` MODIFY `item4` INTEGER(10) UNSIGNED;
ALTER TABLE `character_equipmentsets` MODIFY `item5` INTEGER(10) UNSIGNED;
ALTER TABLE `character_equipmentsets` MODIFY `item6` INTEGER(10) UNSIGNED;
ALTER TABLE `character_equipmentsets` MODIFY `item7` INTEGER(10) UNSIGNED;
ALTER TABLE `character_equipmentsets` MODIFY `item8` INTEGER(10) UNSIGNED;
ALTER TABLE `character_equipmentsets` MODIFY `item9` INTEGER(10) UNSIGNED;
ALTER TABLE `character_equipmentsets` MODIFY `item10` INTEGER(10) UNSIGNED;
ALTER TABLE `character_equipmentsets` MODIFY `item11` INTEGER(10) UNSIGNED;
ALTER TABLE `character_equipmentsets` MODIFY `item12` INTEGER(10) UNSIGNED;
ALTER TABLE `character_equipmentsets` MODIFY `item13` INTEGER(10) UNSIGNED;
ALTER TABLE `character_equipmentsets` MODIFY `item14` INTEGER(10) UNSIGNED;
ALTER TABLE `character_equipmentsets` MODIFY `item15` INTEGER(10) UNSIGNED;
ALTER TABLE `character_equipmentsets` MODIFY `item16` INTEGER(10) UNSIGNED;
ALTER TABLE `character_equipmentsets` MODIFY `item17` INTEGER(10) UNSIGNED;
ALTER TABLE `character_equipmentsets` MODIFY `item18` INTEGER(10) UNSIGNED;
UPDATE `character_equipmentsets`  SET `item0` = NULL WHERE `item0` = 0;
UPDATE `character_equipmentsets`  SET `item1` = NULL WHERE `item1` = 0;
UPDATE `character_equipmentsets`  SET `item2` = NULL WHERE `item2` = 0;
UPDATE `character_equipmentsets`  SET `item3` = NULL WHERE `item3` = 0;
UPDATE `character_equipmentsets`  SET `item4` = NULL WHERE `item4` = 0;
UPDATE `character_equipmentsets`  SET `item5` = NULL WHERE `item5` = 0;
UPDATE `character_equipmentsets`  SET `item6` = NULL WHERE `item6` = 0;
UPDATE `character_equipmentsets`  SET `item7` = NULL WHERE `item7` = 0;
UPDATE `character_equipmentsets`  SET `item8` = NULL WHERE `item8` = 0;
UPDATE `character_equipmentsets`  SET `item9` = NULL WHERE `item9` = 0;
UPDATE `character_equipmentsets`  SET `item10` = NULL WHERE `item10` = 0;
UPDATE `character_equipmentsets`  SET `item11` = NULL WHERE `item11` = 0;
UPDATE `character_equipmentsets`  SET `item12` = NULL WHERE `item12` = 0;
UPDATE `character_equipmentsets`  SET `item13` = NULL WHERE `item13` = 0;
UPDATE `character_equipmentsets`  SET `item14` = NULL WHERE `item14` = 0;
UPDATE `character_equipmentsets`  SET `item15` = NULL WHERE `item15` = 0;
UPDATE `character_equipmentsets`  SET `item16` = NULL WHERE `item16` = 0;
UPDATE `character_equipmentsets`  SET `item17` = NULL WHERE `item17` = 0;
UPDATE `character_equipmentsets`  SET `item18` = NULL WHERE `item18` = 0;

-- corpse
ALTER TABLE `corpse` MODIFY `instanceId` INTEGER(10) UNSIGNED DEFAULT NULL COMMENT 'Instance Identifier';
UPDATE `corpse` SET `instanceId` = NULL WHERE `instanceId` = 0;

-- gmticket
ALTER TABLE `gm_ticket` MODIFY `closedBy` INTEGER(10) UNSIGNED DEFAULT NULL;
ALTER TABLE `gm_ticket` MODIFY `assignedTo` INTEGER(10) UNSIGNED DEFAULT NULL COMMENT 'GUID of admin to whom ticket is assigned';
ALTER TABLE `gm_ticket` ADD closed BOOL NOT NULL DEFAULT FALSE AFTER `needMoreHelp`;
-- Update closed status via old system's values
UPDATE `gm_ticket` SET `closed` = TRUE WHERE `closedBy` <> 0;
-- Fix non existant closedBy characters (posibly deleted characters and/or closed by console)
UPDATE `gm_ticket` SET `closedBy` = NULL WHERE `closedBy` NOT IN ( SELECT `guid` FROM `characters` );
UPDATE `gm_ticket` SET `assignedTo` = NULL WHERE `assignedTo` = 0;
