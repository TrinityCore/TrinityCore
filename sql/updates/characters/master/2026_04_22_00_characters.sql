DELIMITER ;;
CREATE PROCEDURE apply_if_not_exists_2026_04_22_00() BEGIN

  -- Fill new situations
  IF NOT EXISTS (SELECT 1 FROM `character_transmog_outfit_situation` WHERE `situationID` BETWEEN 32 AND 41) THEN
    -- All Weather
    INSERT INTO `character_transmog_outfit_situation`
    SELECT `guid`, `transmogOutfitId`, 32, 0, 0, 0 FROM	`character_transmog_outfit_situation` GROUP BY guid, transmogOutfitId;

    -- All Times
    INSERT INTO `character_transmog_outfit_situation`
    SELECT `guid`, `transmogOutfitId`, 37, 0, 0, 0 FROM	`character_transmog_outfit_situation` GROUP BY guid, transmogOutfitId;
  END IF;

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
      /* head */        0 ,               0 , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ', 4),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ', 4 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ', 1),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ', 1 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ', 2),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ', 2 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ', 3),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ', 3 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ', 5),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ', 5 -1))+1),' ','') , 0,
      /* neck */        0 ,               0 , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ', 9),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ', 9 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ', 6),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ', 6 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ', 7),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ', 7 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ', 8),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ', 8 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',10),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',10 -1))+1),' ','') , 0,
      /* shoulders */   0 ,               0 , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',14),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',14 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',11),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',11 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',12),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',12 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',13),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',13 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',15),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',15 -1))+1),' ','') , 0,
      /* body */        0 ,               0 , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',19),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',19 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',16),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',16 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',17),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',17 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',18),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',18 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',20),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',20 -1))+1),' ','') , 0,
      /* chest */       0 ,               0 , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',24),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',24 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',21),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',21 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',22),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',22 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',23),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',23 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',25),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',25 -1))+1),' ','') , 0,
      /* waist */       0 ,               0 , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',29),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',29 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',26),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',26 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',27),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',27 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',28),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',28 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',30),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',30 -1))+1),' ','') , 0,
      /* legs */        0 ,               0 , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',34),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',34 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',31),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',31 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',32),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',32 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',33),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',33 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',35),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',35 -1))+1),' ','') , 0,
      /* feet */        0 ,               0 , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',39),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',39 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',36),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',36 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',37),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',37 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',38),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',38 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',40),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',40 -1))+1),' ','') , 0,
      /* wrists */      0 ,               0 , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',44),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',44 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',41),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',41 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',42),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',42 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',43),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',43 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',45),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',45 -1))+1),' ','') , 0,
      /* hands */       0 ,               0 , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',49),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',49 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',46),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',46 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',47),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',47 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',48),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',48 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',50),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',50 -1))+1),' ','') , 0,
      /* finger */      0 ,               0 , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',54),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',54 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',51),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',51 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',52),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',52 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',53),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',53 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',55),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',55 -1))+1),' ','') , 0,
      /* finger */      0 ,               0 , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',59),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',59 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',56),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',56 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',57),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',57 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',58),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',58 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',60),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',60 -1))+1),' ','') , 0,
      /* trinket */     0 ,               0 , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',64),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',64 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',61),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',61 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',62),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',62 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',63),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',63 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',65),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',65 -1))+1),' ','') , 0,
      /* trinket */     0 ,               0 , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',69),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',69 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',66),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',66 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',67),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',67 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',68),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',68 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',70),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',70 -1))+1),' ','') , 0,
      /* back */        0 ,               0 , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',74),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',74 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',71),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',71 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',72),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',72 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',73),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',73 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',75),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',75 -1))+1),' ','') , 0,
      /* main hand */   0 ,               0 , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',79),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',79 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',76),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',76 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',77),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',77 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',78),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',78 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',80),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',80 -1))+1),' ','') , 0,
      /* off hand */    0 ,               0 , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',84),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',84 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',81),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',81 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',82),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',82 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',83),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',83 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',85),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',85 -1))+1),' ','') , 0,
      /* ranged */      0 ,               0 , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',89),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',89 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',86),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',86 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',87),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',87 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',88),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',88 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',90),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',90 -1))+1),' ','') , 0,
      /* tabard */      0 ,               0 , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',94),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',94 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',91),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',91 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',92),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',92 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',93),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',93 -1))+1),' ','') , REPLACE(SUBSTRING(SUBSTRING_INDEX(`equipmentCache`,' ',95),LENGTH(SUBSTRING_INDEX(`equipmentCache`,' ',95 -1))+1),' ','') , 0
    FROM `characters`;

    ALTER TABLE `characters` DROP `equipmentCache`;
  END IF;
END;;

DELIMITER ;

CALL apply_if_not_exists_2026_04_22_00();

DROP PROCEDURE apply_if_not_exists_2026_04_22_00;
