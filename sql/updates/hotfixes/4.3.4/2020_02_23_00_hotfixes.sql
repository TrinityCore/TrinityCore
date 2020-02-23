ALTER TABLE `item_sparse`
    CHANGE `Unk1` `PriceRandomValue` FLOAT DEFAULT 0 NOT NULL,
    CHANGE `Unk2` `PriceVariance` FLOAT DEFAULT 0 NOT NULL,
    CHANGE `Name` `Display` TEXT CHARSET utf8 COLLATE utf8_general_ci NULL,
    CHANGE `Name2` `Display1` TEXT CHARSET utf8 COLLATE utf8_general_ci NULL,
    CHANGE `Name3` `Display2` TEXT CHARSET utf8 COLLATE utf8_general_ci NULL,
    CHANGE `Name4` `Display3` TEXT CHARSET utf8 COLLATE utf8_general_ci NULL,
    CHANGE `Sheath` `SheatheType` INT(10) UNSIGNED DEFAULT 0 NOT NULL,
    CHANGE `Area` `AreaID` INT(10) UNSIGNED DEFAULT 0 NOT NULL,
    CHANGE `Map` `MapID` INT(10) UNSIGNED DEFAULT 0 NOT NULL;

ALTER TABLE `item`
    CHANGE `Class` `ClassID` INT(10) UNSIGNED DEFAULT 0 NOT NULL,
    CHANGE `SubClass` `SubclassID` INT(10) UNSIGNED DEFAULT 0 NOT NULL,
    CHANGE `SoundOverrideSubclass` `SoundOverrideSubclassID` INT(11) DEFAULT 0 NOT NULL,
    CHANGE `Sheath` `SheatheType` INT(10) UNSIGNED DEFAULT 0 NOT NULL;

ALTER TABLE `item_sparse_locale`   
    CHANGE `Name_lang` `Display_lang` TEXT CHARSET utf8 COLLATE utf8_general_ci NULL,
    CHANGE `Name2_lang` `Display1_lang` TEXT CHARSET utf8 COLLATE utf8_general_ci NULL,
    CHANGE `Name3_lang` `Display2_lang` TEXT CHARSET utf8 COLLATE utf8_general_ci NULL,
    CHANGE `Name4_lang` `Display3_lang` TEXT CHARSET utf8 COLLATE utf8_general_ci NULL;

ALTER TABLE `item_currency_cost`
    CHANGE `ItemId` `ItemID` INT(10) UNSIGNED DEFAULT 0 NOT NULL;

ALTER TABLE `item_sparse`
    CHANGE `RequiredSpell` `RequiredSpell` INT(11) DEFAULT 0 NOT NULL,
    CHANGE `MaxCount` `MaxCount` INT(11) DEFAULT 0 NOT NULL,
    CHANGE `Stackable` `Stackable` INT(11) DEFAULT 0 NOT NULL,
    CHANGE `ItemStatSocketCostMultiplier1` `ItemStatSocketCostMultiplier1` INT(11) DEFAULT 0 NOT NULL,
    CHANGE `ItemStatSocketCostMultiplier2` `ItemStatSocketCostMultiplier2` INT(11) DEFAULT 0 NOT NULL,
    CHANGE `ItemStatSocketCostMultiplier3` `ItemStatSocketCostMultiplier3` INT(11) DEFAULT 0 NOT NULL,
    CHANGE `ItemStatSocketCostMultiplier4` `ItemStatSocketCostMultiplier4` INT(11) DEFAULT 0 NOT NULL,
    CHANGE `ItemStatSocketCostMultiplier5` `ItemStatSocketCostMultiplier5` INT(11) DEFAULT 0 NOT NULL,
    CHANGE `ItemStatSocketCostMultiplier6` `ItemStatSocketCostMultiplier6` INT(11) DEFAULT 0 NOT NULL,
    CHANGE `ItemStatSocketCostMultiplier7` `ItemStatSocketCostMultiplier7` INT(11) DEFAULT 0 NOT NULL,
    CHANGE `ItemStatSocketCostMultiplier8` `ItemStatSocketCostMultiplier8` INT(11) DEFAULT 0 NOT NULL,
    CHANGE `ItemStatSocketCostMultiplier9` `ItemStatSocketCostMultiplier9` INT(11) DEFAULT 0 NOT NULL,
    CHANGE `ItemStatSocketCostMultiplier10` `ItemStatSocketCostMultiplier10` INT(11) DEFAULT 0 NOT NULL,
    CHANGE `ScalingStatDistribution` `ScalingStatDistribution` INT(11) DEFAULT 0 NOT NULL,
    CHANGE `DamageType` `DamageType` INT(11) DEFAULT 0 NOT NULL,
    CHANGE `Bonding` `Bonding` INT(11) DEFAULT 0 NOT NULL,
    CHANGE `LanguageID` `LanguageID` INT(11) DEFAULT 0 NOT NULL,
    CHANGE `PageMaterial` `PageMaterial` INT(11) DEFAULT 0 NOT NULL,
    CHANGE `StartQuest` `StartQuest` INT(11) DEFAULT 0 NOT NULL,
    CHANGE `SheatheType` `SheatheType` INT(11) DEFAULT 0 NOT NULL,
    CHANGE `RandomProperty` `RandomProperty` INT(11) DEFAULT 0 NOT NULL,
    CHANGE `MapID` `MapID` INT(11) DEFAULT 0 NOT NULL,
    CHANGE `BagFamily` `BagFamily` INT(11) DEFAULT 0 NOT NULL,
    CHANGE `TotemCategory` `TotemCategory` INT(11) DEFAULT 0 NOT NULL,
    CHANGE `SocketColor1` `SocketColor1` INT(11) DEFAULT 0 NOT NULL,
    CHANGE `SocketColor2` `SocketColor2` INT(11) DEFAULT 0 NOT NULL,
    CHANGE `SocketColor3` `SocketColor3` INT(11) DEFAULT 0 NOT NULL,
    CHANGE `GemProperties` `GemProperties` INT(11) DEFAULT 0 NOT NULL,
    CHANGE `Duration` `Duration` INT(11) DEFAULT 0 NOT NULL,
    CHANGE `ItemLimitCategory` `ItemLimitCategory` INT(11) DEFAULT 0 NOT NULL,
    CHANGE `HolidayID` `HolidayID` INT(11) DEFAULT 0 NOT NULL;
