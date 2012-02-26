UPDATE `quest_template` SET `SpecialFlags`=9 WHERE `Id`=25485;

DELETE FROM `item_template` WHERE `entry`=54537;
INSERT INTO `item_template` (`entry`, `class`, `subclass`, `unk0`, `name`, `displayid`, `Quality`, `Flags`, `FlagsExtra`, `BuyCount`, `BuyPrice`, `SellPrice`, `InventoryType`, `AllowableClass`, `AllowableRace`, `ItemLevel`, `RequiredLevel`, `RequiredSkill`, `RequiredSkillRank`, `requiredspell`, `requiredhonorrank`, `RequiredCityRank`, `RequiredReputationFaction`, `RequiredReputationRank`, `maxcount`, `stackable`, `ContainerSlots`, `StatsCount`, `stat_type1`, `stat_value1`, `stat_type2`, `stat_value2`, `stat_type3`, `stat_value3`, `stat_type4`, `stat_value4`, `stat_type5`, `stat_value5`, `stat_type6`, `stat_value6`, `stat_type7`, `stat_value7`, `stat_type8`, `stat_value8`, `stat_type9`, `stat_value9`, `stat_type10`, `stat_value10`, `ScalingStatDistribution`, `ScalingStatValue`, `dmg_min1`, `dmg_max1`, `dmg_type1`, `dmg_min2`, `dmg_max2`, `dmg_type2`, `armor`, `holy_res`, `fire_res`, `nature_res`, `frost_res`, `shadow_res`, `arcane_res`, `delay`, `ammo_type`, `RangedModRange`, `spellid_1`, `spelltrigger_1`, `spellcharges_1`, `spellppmRate_1`, `spellcooldown_1`, `spellcategory_1`, `spellcategorycooldown_1`, `spellid_2`, `spelltrigger_2`, `spellcharges_2`, `spellppmRate_2`, `spellcooldown_2`, `spellcategory_2`, `spellcategorycooldown_2`, `spellid_3`, `spelltrigger_3`, `spellcharges_3`, `spellppmRate_3`, `spellcooldown_3`, `spellcategory_3`, `spellcategorycooldown_3`, `spellid_4`, `spelltrigger_4`, `spellcharges_4`, `spellppmRate_4`, `spellcooldown_4`, `spellcategory_4`, `spellcategorycooldown_4`, `spellid_5`, `spelltrigger_5`, `spellcharges_5`, `spellppmRate_5`, `spellcooldown_5`, `spellcategory_5`, `spellcategorycooldown_5`, `bonding`, `description`, `PageText`, `LanguageID`, `PageMaterial`, `startquest`, `lockid`, `Material`, `sheath`, `RandomProperty`, `RandomSuffix`, `block`, `itemset`, `MaxDurability`, `area`, `Map`, `BagFamily`, `TotemCategory`, `socketColor_1`, `socketContent_1`, `socketColor_2`, `socketContent_2`, `socketColor_3`, `socketContent_3`, `socketBonus`, `GemProperties`, `RequiredDisenchantSkill`, `ArmorDamageModifier`, `Duration`, `ItemLimitCategory`, `HolidayId`, `ScriptName`, `DisenchantID`, `FoodType`, `minMoneyLoot`, `maxMoneyLoot`, `WDBVerified`) VALUES
(54537,15,0,-1,'Heart-Shaped Box',40293,3,4,0,1,0,0,0,-1,-1,80,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,1,'',0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,'',0,0,0,0,12340);

DELETE FROM `item_loot_template` WHERE `entry`=54537;
INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(54537,49715,0,1,1,1,1),
(54537,50446,0,1,1,1,1),
(54537,50741,0,1,1,1,1),
(54537,50471,6,1,0,1,1),
(54537,40753,100,1,0,2,2),
(54537,50250,1,1,0,1,1);

UPDATE `creature_template` SET `faction_A` = 16, `faction_H` = 16, `Health_mod` = 86.189, `lootid` = 36296, `mechanic_immune_mask` = 650854235, `ScriptName` = 'npc_apothecary_hummel' WHERE `entry` = 36296;
UPDATE `creature_template` SET `faction_A` = 16, `faction_H` = 16, `Health_mod` = 86.189, `lootid` = 36296, `mechanic_immune_mask` = 650854235, `ScriptName` = 'npc_apothecary_baxter' WHERE `entry` = 36565;
UPDATE `creature_template` SET `faction_A` = 16, `faction_H` = 16, `Health_mod` = 86.189, `lootid` = 36296, `equipment_id` = 128, `mechanic_immune_mask` = 536870917, `flags_extra` = 256, `ScriptName` = 'npc_apothecary_frye' WHERE `entry` = 36272;
UPDATE `creature_template` SET `faction_A` = 16, `faction_H` = 16, `Health_mod` = 86.189, `mechanic_immune_mask` = 536870917,`ScriptName`='npc_crazed_apothecary' WHERE `entry`=36568;

UPDATE `game_event` SET `holiday`=423 WHERE `eventEntry`=8;
UPDATE `item_template` SET `HolidayId`=423 WHERE `entry`=21815;
