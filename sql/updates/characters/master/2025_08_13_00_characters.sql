ALTER TABLE `characters`
  ADD `bankTabs` tinyint unsigned NOT NULL DEFAULT 0 AFTER `bankSlots`,
  DROP `bankBagSlotFlags1`,
  DROP `bankBagSlotFlags2`,
  DROP `bankBagSlotFlags3`,
  DROP `bankBagSlotFlags4`,
  DROP `bankBagSlotFlags5`,
  DROP `bankBagSlotFlags6`,
  DROP `bankBagSlotFlags7`;

UPDATE `characters` SET `bankTabs`=LEAST(6,GREATEST(
  `bankSlots`,
  IF((`playerFlags` & 0x20000000)<>0,6,0), -- unlocked void storage
  IF((`playerFlagsEx` & 0x1)<>0,4,0), -- unlocked reagent bank
  IF(`level`>=80,6,0)
));

--
-- Table structure for table `character_bank_tab_settings`
--
DROP TABLE IF EXISTS `character_bank_tab_settings`;
CREATE TABLE `character_bank_tab_settings` (
  `characterGuid` bigint unsigned NOT NULL,
  `tabId` tinyint unsigned NOT NULL,
  `name` varchar(16) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `icon` varchar(64) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `description` varchar(2048) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `depositFlags` int DEFAULT '0',
  PRIMARY KEY (`characterGuid`,`tabId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

INSERT INTO `character_bank_tab_settings` SELECT `guid`,0,'Tab 1',NULL,NULL,0 FROM `characters` WHERE `bankTabs` >= 1;
INSERT INTO `character_bank_tab_settings` SELECT `guid`,1,'Tab 2',NULL,NULL,0 FROM `characters` WHERE `bankTabs` >= 2;
INSERT INTO `character_bank_tab_settings` SELECT `guid`,2,'Tab 3',NULL,NULL,0 FROM `characters` WHERE `bankTabs` >= 3;
INSERT INTO `character_bank_tab_settings` SELECT `guid`,3,'Reagents',NULL,NULL,0x80 FROM `characters` WHERE `bankTabs` >= 4;
INSERT INTO `character_bank_tab_settings` SELECT `guid`,4,'Void Storage 1',NULL,NULL,0 FROM `characters` WHERE `bankTabs` >= 5;
INSERT INTO `character_bank_tab_settings` SELECT `guid`,5,'Void Storage 2',NULL,NULL,0 FROM `characters` WHERE `bankTabs` >= 6;

-- helper columns
-- character_inventory.bag_slot (inventory slot where the bag is stored)
-- character_inventory.new_slot
-- character_inventory.slot temporarily changed type to SMALLINT
ALTER TABLE `character_inventory`
  ADD `bag_slot` INT,
  ADD `new_slot` INT,
  MODIFY `slot` SMALLINT UNSIGNED NOT NULL;

UPDATE `character_inventory` ci1
LEFT JOIN `character_inventory` ci2 ON ci1.bag = ci2.item
SET ci1.bag_slot = COALESCE(ci2.slot, 0);

-- move items that need moving out of the way
UPDATE `character_inventory` SET `slot`=`slot`+1000 WHERE `bag`=0 AND `slot` BETWEEN 63 AND 97; -- BankItemSlots/BankBagSlots
UPDATE `character_inventory` SET `slot`=`slot`+1000 WHERE `bag`=0 AND `slot` BETWEEN 110 AND 207; -- ReagentSlots

-- adjust BuyBackSlots/ChildEquipmentSlots/EquipableSpellSlots/AccountBankBagSlots
UPDATE `character_inventory` SET `slot`=`slot`-29 WHERE `bag`=0 AND `slot` BETWEEN 98 AND 109; -- BuyBackSlots
UPDATE `character_inventory` SET `slot`=`slot`-127 WHERE `bag`=0 AND `slot` BETWEEN 208 AND 231; -- ChildEquipmentSlots/EquipableSpellSlots/AccountBankBagSlots

SET @item_guid := 0;
SELECT MAX(guid) INTO @item_guid FROM item_instance;

-- create new bags
INSERT INTO `character_inventory` (`guid`,`bag`,`slot`,`item`)
SELECT cbts.characterGuid, 0, 63 + cbts.`tabId`, (@item_guid := @item_guid + 1) FROM `character_bank_tab_settings` cbts;

INSERT INTO `item_instance` (`guid`,`itemEntry`,`owner_guid`,`charges`,`flags`,`enchantments`,`playedTime`,`createTime`,`text`,`bonusListIDs`)
SELECT ci.`item`, 242709, ci.`guid`, '', 0x1, '0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ', c.totaltime, UNIX_TIMESTAMP(),'',''
FROM `character_inventory` ci
LEFT JOIN `characters` c ON c.`guid` = ci.`guid`
WHERE ci.`bag` = 0 AND ci.`slot` BETWEEN 63 AND 68;

-- calculate new slots for old banked items
UPDATE `character_inventory` ci
LEFT JOIN (
  SELECT item, new_slot
  FROM (
    SELECT guid, bag, slot, item, IF(@prev <> guid, @row_num:=0,@row_num:=@row_num+1) AS new_slot, @prev:=guid
    FROM character_inventory,
    (SELECT @row_num:=0) rn,
    (SELECT @prev:='') prev
    WHERE (bag_slot = 0 AND slot BETWEEN 1063 AND 1097) OR bag_slot BETWEEN 91 AND 97
    ORDER BY guid, bag_slot, slot
  ) `window`
) new_slots ON new_slots.item = ci.item
SET ci.new_slot = new_slots.new_slot;

-- assign new bags and slots
UPDATE `character_inventory` ci
LEFT JOIN `character_inventory` ci2 ON ci2.guid = ci.guid AND ci2.bag = 0 AND ci2.slot = (ci.new_slot DIV 98) + 63
SET ci.bag = ci2.item, ci.slot = ci.new_slot MOD 98
WHERE (ci.bag_slot = 0 AND ci.slot BETWEEN 1063 AND 1097) OR ci.bag_slot BETWEEN 91 AND 97;

-- move reagents as-is (bag is the same size)
UPDATE `character_inventory` ci
LEFT JOIN `character_inventory` ci2 ON ci2.guid = ci.guid AND ci2.bag = 0 AND ci2.slot = 66
SET ci.bag = ci2.item, ci.slot = ci.slot - 1110
WHERE (ci.bag_slot = 0 AND ci.slot BETWEEN 1110 AND 1207);

-- void storage
ALTER TABLE `character_void_storage`
  ADD `itemGuid` BIGINT UNSIGNED,
  ADD `bagGuid` BIGINT UNSIGNED;

-- generate guids for void storage
UPDATE `character_void_storage` cvs
SET
cvs.`itemGuid` = (@item_guid := @item_guid + 1),
cvs.`bagGuid` = (SELECT ci.`item` FROM `character_inventory` ci WHERE ci.`guid` = cvs.`playerGuid` AND ci.`bag` = 0 AND ci.`slot` = 67 + (cvs.`slot` DIV 80));

-- create items from void storage
INSERT INTO `item_instance` (`guid`, `itemEntry`, `owner_guid`, `creatorGuid`, `charges`, `flags`, `enchantments`, `randomBonusListId`, `durability`, `playedTime`, `createTime`, `text`, `context`, `bonusListIDs`)
SELECT cvs.`itemGuid`, cvs.`itemEntry`, cvs.`playerGuid`, cvs.`creatorGuid`, '', 0x1, '0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ', cvs.`randomBonusListId`, 999, c.`totaltime`, UNIX_TIMESTAMP(), '', cvs.context, cvs.bonusListIDs FROM `character_void_storage` cvs
LEFT JOIN `characters` c ON c.`guid` = cvs.`playerGuid`;

INSERT INTO `item_instance_modifiers` (`itemGuid`, `fixedScalingLevel`, `artifactKnowledgeLevel`)
SELECT cvs.`itemGuid`, COALESCE(cvs.`fixedScalingLevel`, 0), COALESCE(cvs.`artifactKnowledgeLevel`, 0) FROM `character_void_storage` cvs
WHERE cvs.`fixedScalingLevel` > 0 OR cvs.`artifactKnowledgeLevel` > 0;

INSERT INTO `character_inventory` (`guid`, `bag`, `slot`, `item`)
SELECT cvs.`playerGuid`, cvs.`bagGuid`, cvs.`slot` MOD 80, cvs.`itemGuid` FROM `character_void_storage` cvs;

ALTER TABLE `character_inventory`
  DROP `bag_slot`,
  DROP `new_slot`,
  MODIFY `slot` TINYINT UNSIGNED NOT NULL DEFAULT 0;

DROP TABLE IF EXISTS `character_void_storage`;
