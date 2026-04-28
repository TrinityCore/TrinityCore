DROP FUNCTION IF EXISTS `get_nth_token`;
CREATE FUNCTION `get_nth_token`(x TEXT, delim VARCHAR(16), pos INT) RETURNS TEXT NO SQL
RETURN REPLACE(SUBSTRING(SUBSTRING_INDEX(x, delim, pos), LENGTH(SUBSTRING_INDEX(x, delim, pos -1)) + 1), delim, '');

DELIMITER ;;
CREATE PROCEDURE apply_if_not_exists_2026_04_22_00() BEGIN

  -- Fill new situations
  DELETE FROM `character_transmog_outfit_situation` WHERE `situationID` BETWEEN 32 AND 41;

  -- All Weather
  INSERT INTO `character_transmog_outfit_situation`
  SELECT `guid`, `transmogOutfitId`, 32, 0, 0, 0 FROM	`character_transmog_outfit_situation` GROUP BY guid, transmogOutfitId;

  -- All Times
  INSERT INTO `character_transmog_outfit_situation`
  SELECT `guid`, `transmogOutfitId`, 37, 0, 0, 0 FROM	`character_transmog_outfit_situation` GROUP BY guid, transmogOutfitId;

  IF NOT EXISTS (SELECT * FROM `information_schema`.`columns` WHERE `table_schema`=SCHEMA() AND `table_name`='character_transmog_outfit_slot' AND `column_name`='sheatheCategory') THEN
    ALTER TABLE `character_transmog_outfit_slot` ADD `sheatheCategory` tinyint UNSIGNED AFTER `slotOption`;
    UPDATE `character_transmog_outfit_slot` SET `sheatheCategory` = 0;
    ALTER TABLE `character_transmog_outfit_slot` MODIFY `sheatheCategory` tinyint UNSIGNED NOT NULL AFTER `slotOption`;
  END IF;

  IF EXISTS (SELECT * FROM `information_schema`.`columns` WHERE `table_schema`=SCHEMA() AND `table_name`='characters' AND `column_name`='equipmentCache') THEN
    --
    -- Table structure for table `character_select_screen_equipment_cache`
    --
    DROP TABLE IF EXISTS `character_select_screen_equipment_cache`;
    CREATE TABLE `character_select_screen_equipment_cache` (
      `guid` bigint unsigned NOT NULL,
      `headEquippedItemID` int unsigned NOT NULL DEFAULT '0',
      `headVisibleItemID` int unsigned NOT NULL DEFAULT '0',
      `headSubclass` tinyint unsigned NOT NULL DEFAULT '0',
      `headInvType` tinyint unsigned NOT NULL DEFAULT '0',
      `headDisplayID` int unsigned NOT NULL DEFAULT '0',
      `headDisplayEnchantID` int unsigned NOT NULL DEFAULT '0',
      `headSecondaryItemModifiedAppearanceID` int NOT NULL DEFAULT '0',
      `headSheatheCategory` tinyint unsigned NOT NULL DEFAULT '0',
      `neckEquippedItemID` int unsigned NOT NULL DEFAULT '0',
      `neckVisibleItemID` int unsigned NOT NULL DEFAULT '0',
      `neckSubclass` tinyint unsigned NOT NULL DEFAULT '0',
      `neckInvType` tinyint unsigned NOT NULL DEFAULT '0',
      `neckDisplayID` int unsigned NOT NULL DEFAULT '0',
      `neckDisplayEnchantID` int unsigned NOT NULL DEFAULT '0',
      `neckSecondaryItemModifiedAppearanceID` int NOT NULL DEFAULT '0',
      `neckSheatheCategory` tinyint unsigned NOT NULL DEFAULT '0',
      `shoulderEquippedItemID` int unsigned NOT NULL DEFAULT '0',
      `shoulderVisibleItemID` int unsigned NOT NULL DEFAULT '0',
      `shoulderSubclass` tinyint unsigned NOT NULL DEFAULT '0',
      `shoulderInvType` tinyint unsigned NOT NULL DEFAULT '0',
      `shoulderDisplayID` int unsigned NOT NULL DEFAULT '0',
      `shoulderDisplayEnchantID` int unsigned NOT NULL DEFAULT '0',
      `shoulderSecondaryItemModifiedAppearanceID` int NOT NULL DEFAULT '0',
      `shoulderSheatheCategory` tinyint unsigned NOT NULL DEFAULT '0',
      `bodyEquippedItemID` int unsigned NOT NULL DEFAULT '0',
      `bodyVisibleItemID` int unsigned NOT NULL DEFAULT '0',
      `bodySubclass` tinyint unsigned NOT NULL DEFAULT '0',
      `bodyInvType` tinyint unsigned NOT NULL DEFAULT '0',
      `bodyDisplayID` int unsigned NOT NULL DEFAULT '0',
      `bodyDisplayEnchantID` int unsigned NOT NULL DEFAULT '0',
      `bodySecondaryItemModifiedAppearanceID` int NOT NULL DEFAULT '0',
      `bodySheatheCategory` tinyint unsigned NOT NULL DEFAULT '0',
      `chestEquippedItemID` int unsigned NOT NULL DEFAULT '0',
      `chestVisibleItemID` int unsigned NOT NULL DEFAULT '0',
      `chestSubclass` tinyint unsigned NOT NULL DEFAULT '0',
      `chestInvType` tinyint unsigned NOT NULL DEFAULT '0',
      `chestDisplayID` int unsigned NOT NULL DEFAULT '0',
      `chestDisplayEnchantID` int unsigned NOT NULL DEFAULT '0',
      `chestSecondaryItemModifiedAppearanceID` int NOT NULL DEFAULT '0',
      `chestSheatheCategory` tinyint unsigned NOT NULL DEFAULT '0',
      `waistEquippedItemID` int unsigned NOT NULL DEFAULT '0',
      `waistVisibleItemID` int unsigned NOT NULL DEFAULT '0',
      `waistSubclass` tinyint unsigned NOT NULL DEFAULT '0',
      `waistInvType` tinyint unsigned NOT NULL DEFAULT '0',
      `waistDisplayID` int unsigned NOT NULL DEFAULT '0',
      `waistDisplayEnchantID` int unsigned NOT NULL DEFAULT '0',
      `waistSecondaryItemModifiedAppearanceID` int NOT NULL DEFAULT '0',
      `waistSheatheCategory` tinyint unsigned NOT NULL DEFAULT '0',
      `legsEquippedItemID` int unsigned NOT NULL DEFAULT '0',
      `legsVisibleItemID` int unsigned NOT NULL DEFAULT '0',
      `legsSubclass` tinyint unsigned NOT NULL DEFAULT '0',
      `legsInvType` tinyint unsigned NOT NULL DEFAULT '0',
      `legsDisplayID` int unsigned NOT NULL DEFAULT '0',
      `legsDisplayEnchantID` int unsigned NOT NULL DEFAULT '0',
      `legsSecondaryItemModifiedAppearanceID` int NOT NULL DEFAULT '0',
      `legsSheatheCategory` tinyint unsigned NOT NULL DEFAULT '0',
      `feetEquippedItemID` int unsigned NOT NULL DEFAULT '0',
      `feetVisibleItemID` int unsigned NOT NULL DEFAULT '0',
      `feetSubclass` tinyint unsigned NOT NULL DEFAULT '0',
      `feetInvType` tinyint unsigned NOT NULL DEFAULT '0',
      `feetDisplayID` int unsigned NOT NULL DEFAULT '0',
      `feetDisplayEnchantID` int unsigned NOT NULL DEFAULT '0',
      `feetSecondaryItemModifiedAppearanceID` int NOT NULL DEFAULT '0',
      `feetSheatheCategory` tinyint unsigned NOT NULL DEFAULT '0',
      `wristsEquippedItemID` int unsigned NOT NULL DEFAULT '0',
      `wristsVisibleItemID` int unsigned NOT NULL DEFAULT '0',
      `wristsSubclass` tinyint unsigned NOT NULL DEFAULT '0',
      `wristsInvType` tinyint unsigned NOT NULL DEFAULT '0',
      `wristsDisplayID` int unsigned NOT NULL DEFAULT '0',
      `wristsDisplayEnchantID` int unsigned NOT NULL DEFAULT '0',
      `wristsSecondaryItemModifiedAppearanceID` int NOT NULL DEFAULT '0',
      `wristsSheatheCategory` tinyint unsigned NOT NULL DEFAULT '0',
      `handsEquippedItemID` int unsigned NOT NULL DEFAULT '0',
      `handsVisibleItemID` int unsigned NOT NULL DEFAULT '0',
      `handsSubclass` tinyint unsigned NOT NULL DEFAULT '0',
      `handsInvType` tinyint unsigned NOT NULL DEFAULT '0',
      `handsDisplayID` int unsigned NOT NULL DEFAULT '0',
      `handsDisplayEnchantID` int unsigned NOT NULL DEFAULT '0',
      `handsSecondaryItemModifiedAppearanceID` int NOT NULL DEFAULT '0',
      `handsSheatheCategory` tinyint unsigned NOT NULL DEFAULT '0',
      `finger1EquippedItemID` int unsigned NOT NULL DEFAULT '0',
      `finger1VisibleItemID` int unsigned NOT NULL DEFAULT '0',
      `finger1Subclass` tinyint unsigned NOT NULL DEFAULT '0',
      `finger1InvType` tinyint unsigned NOT NULL DEFAULT '0',
      `finger1DisplayID` int unsigned NOT NULL DEFAULT '0',
      `finger1DisplayEnchantID` int unsigned NOT NULL DEFAULT '0',
      `finger1SecondaryItemModifiedAppearanceID` int NOT NULL DEFAULT '0',
      `finger1SheatheCategory` tinyint unsigned NOT NULL DEFAULT '0',
      `finger2EquippedItemID` int unsigned NOT NULL DEFAULT '0',
      `finger2VisibleItemID` int unsigned NOT NULL DEFAULT '0',
      `finger2Subclass` tinyint unsigned NOT NULL DEFAULT '0',
      `finger2InvType` tinyint unsigned NOT NULL DEFAULT '0',
      `finger2DisplayID` int unsigned NOT NULL DEFAULT '0',
      `finger2DisplayEnchantID` int unsigned NOT NULL DEFAULT '0',
      `finger2SecondaryItemModifiedAppearanceID` int NOT NULL DEFAULT '0',
      `finger2SheatheCategory` tinyint unsigned NOT NULL DEFAULT '0',
      `trinket1EquippedItemID` int unsigned NOT NULL DEFAULT '0',
      `trinket1VisibleItemID` int unsigned NOT NULL DEFAULT '0',
      `trinket1Subclass` tinyint unsigned NOT NULL DEFAULT '0',
      `trinket1InvType` tinyint unsigned NOT NULL DEFAULT '0',
      `trinket1DisplayID` int unsigned NOT NULL DEFAULT '0',
      `trinket1DisplayEnchantID` int unsigned NOT NULL DEFAULT '0',
      `trinket1SecondaryItemModifiedAppearanceID` int NOT NULL DEFAULT '0',
      `trinket1SheatheCategory` tinyint unsigned NOT NULL DEFAULT '0',
      `trinket2EquippedItemID` int unsigned NOT NULL DEFAULT '0',
      `trinket2VisibleItemID` int unsigned NOT NULL DEFAULT '0',
      `trinket2Subclass` tinyint unsigned NOT NULL DEFAULT '0',
      `trinket2InvType` tinyint unsigned NOT NULL DEFAULT '0',
      `trinket2DisplayID` int unsigned NOT NULL DEFAULT '0',
      `trinket2DisplayEnchantID` int unsigned NOT NULL DEFAULT '0',
      `trinket2SecondaryItemModifiedAppearanceID` int NOT NULL DEFAULT '0',
      `trinket2SheatheCategory` tinyint unsigned NOT NULL DEFAULT '0',
      `backEquippedItemID` int unsigned NOT NULL DEFAULT '0',
      `backVisibleItemID` int unsigned NOT NULL DEFAULT '0',
      `backSubclass` tinyint unsigned NOT NULL DEFAULT '0',
      `backInvType` tinyint unsigned NOT NULL DEFAULT '0',
      `backDisplayID` int unsigned NOT NULL DEFAULT '0',
      `backDisplayEnchantID` int unsigned NOT NULL DEFAULT '0',
      `backSecondaryItemModifiedAppearanceID` int NOT NULL DEFAULT '0',
      `backSheatheCategory` tinyint unsigned NOT NULL DEFAULT '0',
      `mainHandEquippedItemID` int unsigned NOT NULL DEFAULT '0',
      `mainHandVisibleItemID` int unsigned NOT NULL DEFAULT '0',
      `mainHandSubclass` tinyint unsigned NOT NULL DEFAULT '0',
      `mainHandInvType` tinyint unsigned NOT NULL DEFAULT '0',
      `mainHandDisplayID` int unsigned NOT NULL DEFAULT '0',
      `mainHandDisplayEnchantID` int unsigned NOT NULL DEFAULT '0',
      `mainHandSecondaryItemModifiedAppearanceID` int NOT NULL DEFAULT '0',
      `mainHandSheatheCategory` tinyint unsigned NOT NULL DEFAULT '0',
      `offHandEquippedItemID` int unsigned NOT NULL DEFAULT '0',
      `offHandVisibleItemID` int unsigned NOT NULL DEFAULT '0',
      `offHandSubclass` tinyint unsigned NOT NULL DEFAULT '0',
      `offHandInvType` tinyint unsigned NOT NULL DEFAULT '0',
      `offHandDisplayID` int unsigned NOT NULL DEFAULT '0',
      `offHandDisplayEnchantID` int unsigned NOT NULL DEFAULT '0',
      `offHandSecondaryItemModifiedAppearanceID` int NOT NULL DEFAULT '0',
      `offHandSheatheCategory` tinyint unsigned NOT NULL DEFAULT '0',
      `rangedEquippedItemID` int unsigned NOT NULL DEFAULT '0',
      `rangedVisibleItemID` int unsigned NOT NULL DEFAULT '0',
      `rangedSubclass` tinyint unsigned NOT NULL DEFAULT '0',
      `rangedInvType` tinyint unsigned NOT NULL DEFAULT '0',
      `rangedDisplayID` int unsigned NOT NULL DEFAULT '0',
      `rangedDisplayEnchantID` int unsigned NOT NULL DEFAULT '0',
      `rangedSecondaryItemModifiedAppearanceID` int NOT NULL DEFAULT '0',
      `rangedSheatheCategory` tinyint unsigned NOT NULL DEFAULT '0',
      `tabardEquippedItemID` int unsigned NOT NULL DEFAULT '0',
      `tabardVisibleItemID` int unsigned NOT NULL DEFAULT '0',
      `tabardSubclass` tinyint unsigned NOT NULL DEFAULT '0',
      `tabardInvType` tinyint unsigned NOT NULL DEFAULT '0',
      `tabardDisplayID` int unsigned NOT NULL DEFAULT '0',
      `tabardDisplayEnchantID` int unsigned NOT NULL DEFAULT '0',
      `tabardSecondaryItemModifiedAppearanceID` int NOT NULL DEFAULT '0',
      `tabardSheatheCategory` tinyint unsigned NOT NULL DEFAULT '0',
      PRIMARY KEY (`guid`)
    ) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

    INSERT INTO `character_select_screen_equipment_cache` SELECT guid,
      -- equipped item id | visible item id |                subclass                |             inventory type             |               display id               |                 enchant                |          secondary appearance          | sheathe category
      /* head */        0 ,               0 , get_nth_token(`equipmentCache`,' ', 4) , get_nth_token(`equipmentCache`,' ', 1) , get_nth_token(`equipmentCache`,' ', 2) , get_nth_token(`equipmentCache`,' ', 3) , get_nth_token(`equipmentCache`,' ', 5) , 0,
      /* neck */        0 ,               0 , get_nth_token(`equipmentCache`,' ', 9) , get_nth_token(`equipmentCache`,' ', 6) , get_nth_token(`equipmentCache`,' ', 7) , get_nth_token(`equipmentCache`,' ', 8) , get_nth_token(`equipmentCache`,' ',10) , 0,
      /* shoulders */   0 ,               0 , get_nth_token(`equipmentCache`,' ',14) , get_nth_token(`equipmentCache`,' ',11) , get_nth_token(`equipmentCache`,' ',12) , get_nth_token(`equipmentCache`,' ',13) , get_nth_token(`equipmentCache`,' ',15) , 0,
      /* body */        0 ,               0 , get_nth_token(`equipmentCache`,' ',19) , get_nth_token(`equipmentCache`,' ',16) , get_nth_token(`equipmentCache`,' ',17) , get_nth_token(`equipmentCache`,' ',18) , get_nth_token(`equipmentCache`,' ',20) , 0,
      /* chest */       0 ,               0 , get_nth_token(`equipmentCache`,' ',24) , get_nth_token(`equipmentCache`,' ',21) , get_nth_token(`equipmentCache`,' ',22) , get_nth_token(`equipmentCache`,' ',23) , get_nth_token(`equipmentCache`,' ',25) , 0,
      /* waist */       0 ,               0 , get_nth_token(`equipmentCache`,' ',29) , get_nth_token(`equipmentCache`,' ',26) , get_nth_token(`equipmentCache`,' ',27) , get_nth_token(`equipmentCache`,' ',28) , get_nth_token(`equipmentCache`,' ',30) , 0,
      /* legs */        0 ,               0 , get_nth_token(`equipmentCache`,' ',34) , get_nth_token(`equipmentCache`,' ',31) , get_nth_token(`equipmentCache`,' ',32) , get_nth_token(`equipmentCache`,' ',33) , get_nth_token(`equipmentCache`,' ',35) , 0,
      /* feet */        0 ,               0 , get_nth_token(`equipmentCache`,' ',39) , get_nth_token(`equipmentCache`,' ',36) , get_nth_token(`equipmentCache`,' ',37) , get_nth_token(`equipmentCache`,' ',38) , get_nth_token(`equipmentCache`,' ',40) , 0,
      /* wrists */      0 ,               0 , get_nth_token(`equipmentCache`,' ',44) , get_nth_token(`equipmentCache`,' ',41) , get_nth_token(`equipmentCache`,' ',42) , get_nth_token(`equipmentCache`,' ',43) , get_nth_token(`equipmentCache`,' ',45) , 0,
      /* hands */       0 ,               0 , get_nth_token(`equipmentCache`,' ',49) , get_nth_token(`equipmentCache`,' ',46) , get_nth_token(`equipmentCache`,' ',47) , get_nth_token(`equipmentCache`,' ',48) , get_nth_token(`equipmentCache`,' ',50) , 0,
      /* finger */      0 ,               0 , get_nth_token(`equipmentCache`,' ',54) , get_nth_token(`equipmentCache`,' ',51) , get_nth_token(`equipmentCache`,' ',52) , get_nth_token(`equipmentCache`,' ',53) , get_nth_token(`equipmentCache`,' ',55) , 0,
      /* finger */      0 ,               0 , get_nth_token(`equipmentCache`,' ',59) , get_nth_token(`equipmentCache`,' ',56) , get_nth_token(`equipmentCache`,' ',57) , get_nth_token(`equipmentCache`,' ',58) , get_nth_token(`equipmentCache`,' ',60) , 0,
      /* trinket */     0 ,               0 , get_nth_token(`equipmentCache`,' ',64) , get_nth_token(`equipmentCache`,' ',61) , get_nth_token(`equipmentCache`,' ',62) , get_nth_token(`equipmentCache`,' ',63) , get_nth_token(`equipmentCache`,' ',65) , 0,
      /* trinket */     0 ,               0 , get_nth_token(`equipmentCache`,' ',69) , get_nth_token(`equipmentCache`,' ',66) , get_nth_token(`equipmentCache`,' ',67) , get_nth_token(`equipmentCache`,' ',68) , get_nth_token(`equipmentCache`,' ',70) , 0,
      /* back */        0 ,               0 , get_nth_token(`equipmentCache`,' ',74) , get_nth_token(`equipmentCache`,' ',71) , get_nth_token(`equipmentCache`,' ',72) , get_nth_token(`equipmentCache`,' ',73) , get_nth_token(`equipmentCache`,' ',75) , 0,
      /* main hand */   0 ,               0 , get_nth_token(`equipmentCache`,' ',79) , get_nth_token(`equipmentCache`,' ',76) , get_nth_token(`equipmentCache`,' ',77) , get_nth_token(`equipmentCache`,' ',78) , get_nth_token(`equipmentCache`,' ',80) , 0,
      /* off hand */    0 ,               0 , get_nth_token(`equipmentCache`,' ',84) , get_nth_token(`equipmentCache`,' ',81) , get_nth_token(`equipmentCache`,' ',82) , get_nth_token(`equipmentCache`,' ',83) , get_nth_token(`equipmentCache`,' ',85) , 0,
      /* ranged */      0 ,               0 , get_nth_token(`equipmentCache`,' ',89) , get_nth_token(`equipmentCache`,' ',86) , get_nth_token(`equipmentCache`,' ',87) , get_nth_token(`equipmentCache`,' ',88) , get_nth_token(`equipmentCache`,' ',90) , 0,
      /* tabard */      0 ,               0 , get_nth_token(`equipmentCache`,' ',94) , get_nth_token(`equipmentCache`,' ',91) , get_nth_token(`equipmentCache`,' ',92) , get_nth_token(`equipmentCache`,' ',93) , get_nth_token(`equipmentCache`,' ',95) , 0
    FROM `characters`;

    ALTER TABLE `characters` DROP `equipmentCache`;
  END IF;
END;;

DELIMITER ;

CALL apply_if_not_exists_2026_04_22_00();

DROP PROCEDURE apply_if_not_exists_2026_04_22_00;

DROP FUNCTION `get_nth_token`;
