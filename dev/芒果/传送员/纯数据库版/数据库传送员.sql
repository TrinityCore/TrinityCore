/* Stormwind Teleport Quest */
DELETE FROM `quest_template` WHERE `entry` = '800026';
INSERT INTO `quest_template` (`entry`, `ZoneOrSort`, `MinLevel`, `QuestLevel`, `RequiredRaces`, `SpecialFlags`, `Title`, `Details`, `Objectives`, `OfferRewardText`, `RewHonorableKills`, `PointOpt`, `CompleteScript`) VALUES ('800026', '876', '1', '80', '1101', '1', 'Teleport to Stormwind', 'So you want to teleport?', 'Speak with the Teleport Master again.', 'Are you sure, you are ready to teleport?', '0', '0', '800026');
DELETE FROM `quest_end_scripts` WHERE `id` = '800026';
INSERT INTO `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `x`, `y`, `z`, `o`) VALUES ('800026', '0', '6', '0', '-8833.164063', '479.762543', '112.095619', '0.587327');

/* Ironforge Teleport Quest */
DELETE FROM `quest_template` WHERE `entry` = '800027';
INSERT INTO `quest_template` (`entry`, `ZoneOrSort`, `MinLevel`, `QuestLevel`, `RequiredRaces`, `SpecialFlags`, `Title`, `Details`, `Objectives`, `OfferRewardText`, `RewHonorableKills`, `PointOpt`, `CompleteScript`) VALUES ('800027', '876', '1', '80', '1101', '1', 'Teleport to Ironforge', 'So you want to teleport?', 'Speak with the Teleport Master again.', 'Are you sure, you are ready to teleport?', '0', '0', '800027');
DELETE FROM `quest_end_scripts` WHERE `id` = '800027';
INSERT INTO `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `x`, `y`, `z`, `o`) VALUES ('800027', '0', '6', '0', '-4821.613281', '-1155.579468', '502.212250', '3.335226');

/* Darnassus Teleport Quest */
DELETE FROM `quest_template` WHERE `entry` = '800028';
INSERT INTO `quest_template` (`entry`, `ZoneOrSort`, `MinLevel`, `QuestLevel`, `RequiredRaces`, `SpecialFlags`, `Title`, `Details`, `Objectives`, `OfferRewardText`, `RewHonorableKills`, `PointOpt`, `CompleteScript`) VALUES ('800028', '876', '1', '80', '1101', '1', 'Teleport to Darnassus', 'So you want to teleport?', 'Speak with the Teleport Master again.', 'Are you sure, you are ready to teleport?', '0', '0', '800028');
DELETE FROM `quest_end_scripts` WHERE `id` = '800028';
INSERT INTO `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `x`, `y`, `z`, `o`) VALUES ('800028', '0', '6', '1', '9947.525391', '2604.150879', '1316.187988', '4.223004');

/* Exodar Teleport Quest */
DELETE FROM `quest_template` WHERE `entry` = '800029';
INSERT INTO `quest_template` (`entry`, `ZoneOrSort`, `MinLevel`, `QuestLevel`, `RequiredRaces`, `SpecialFlags`, `Title`, `Details`, `Objectives`, `OfferRewardText`, `RewHonorableKills`, `PointOpt`, `CompleteScript`) VALUES ('800029', '876', '1', '80', '1101', '1', 'Teleport to Exodar', 'So you want to teleport?', 'Speak with the Teleport Master again.', 'Are you sure, you are ready to teleport?', '0', '0', '800029');
DELETE FROM `quest_end_scripts` WHERE `id` = '800029';
INSERT INTO `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `x`, `y`, `z`, `o`) VALUES ('800029', '0', '6', '530', '-4054.751709', '-11793.398438', '11.113947', '1.515031');

/* Orgrimmar Teleport Quest */
DELETE FROM `quest_template` WHERE `entry` = '800030';
INSERT INTO `quest_template` (`entry`, `ZoneOrSort`, `MinLevel`, `QuestLevel`, `RequiredRaces`, `SpecialFlags`, `Title`, `Details`, `Objectives`, `OfferRewardText`, `RewHonorableKills`, `PointOpt`, `CompleteScript`) VALUES ('800030', '876', '1', '80', '690', '1', 'Teleport to Orgrimmar', 'So you want to teleport?', 'Speak with the Teleport Master again.', 'Are you sure, you are ready to teleport?', '0', '0', '800030');
DELETE FROM `quest_end_scripts` WHERE `id` = '800030';
INSERT INTO `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `x`, `y`, `z`, `o`) VALUES ('800030', '0', '6', '1', '1677.910400', '-4314.788574', '62.500027', '2.669688');

/* Thunder Bluff Teleport Quest */
DELETE FROM `quest_template` WHERE `entry` = '800031';
INSERT INTO `quest_template` (`entry`, `ZoneOrSort`, `MinLevel`, `QuestLevel`, `RequiredRaces`, `SpecialFlags`, `Title`, `Details`, `Objectives`, `OfferRewardText`, `RewHonorableKills`, `PointOpt`, `CompleteScript`) VALUES ('800031', '876', '1', '80', '690', '1', 'Teleport to Thunder Bluff', 'So you want to teleport?', 'Speak with the Teleport Master again.', 'Are you sure, you are ready to teleport?', '0', '0', '800031');
DELETE FROM `quest_end_scripts` WHERE `id` = '800031';
INSERT INTO `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `x`, `y`, `z`, `o`) VALUES ('800031', '0', '6', '1', '-1197.183716', '29.270617', '179.754837', '2.966604');

/* Undercity Teleport Quest */
DELETE FROM `quest_template` WHERE `entry` = '800032';
INSERT INTO `quest_template` (`entry`, `ZoneOrSort`, `MinLevel`, `QuestLevel`, `RequiredRaces`, `SpecialFlags`, `Title`, `Details`, `Objectives`, `OfferRewardText`, `RewHonorableKills`, `PointOpt`, `CompleteScript`) VALUES ('800032', '876', '1', '80', '690', '1', 'Teleport to Undercity', 'So you want to teleport?', 'Speak with the Teleport Master again.', 'Are you sure, you are ready to teleport?', '0', '0', '800032');
DELETE FROM `quest_end_scripts` WHERE `id` = '800032';
INSERT INTO `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `x`, `y`, `z`, `o`) VALUES ('800032', '0', '6', '0', '1568.478760', '268.519928', '-42.138416', '1.697186');

/* Silvermoon Teleport Quest */
DELETE FROM `quest_template` WHERE `entry` = '800033';
INSERT INTO `quest_template` (`entry`, `ZoneOrSort`, `MinLevel`, `QuestLevel`, `RequiredRaces`, `SpecialFlags`, `Title`, `Details`, `Objectives`, `OfferRewardText`, `RewHonorableKills`, `PointOpt`, `CompleteScript`) VALUES ('800033', '876', '1', '80', '690', '1', 'Teleport to Silvermoon', 'So you want to teleport?', 'Speak with the Teleport Master again.', 'Are you sure, you are ready to teleport?', '0', '0', '800033');
DELETE FROM `quest_end_scripts` WHERE `id` = '800033';
INSERT INTO `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `x`, `y`, `z`, `o`) VALUES ('800033', '0', '6', '530', '9373.077148', '-7166.074219', '11.476312', '5.386526');

/* Dalaran Teleport Quest */
DELETE FROM `quest_template` WHERE `entry` = '800034';
INSERT INTO `quest_template` (`entry`, `ZoneOrSort`, `MinLevel`, `QuestLevel`, `RequiredRaces`, `SpecialFlags`, `Title`, `Details`, `Objectives`, `OfferRewardText`, `RewHonorableKills`, `PointOpt`, `CompleteScript`) VALUES ('800034', '876', '1', '80', '0', '1', 'Teleport to Dalaran', 'So you want to teleport?', 'Speak with the Teleport Master again.', 'Are you sure, you are ready to teleport?', '0', '0', '800034');
DELETE FROM `quest_end_scripts` WHERE `id` = '800034';
INSERT INTO `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `x`, `y`, `z`, `o`) VALUES ('800034', '0', '6', '571', '5819.08', '643.99', '647.80', '3.32');

/* Shattrath Teleport Quest */
DELETE FROM `quest_template` WHERE `entry` = '800035';
INSERT INTO `quest_template` (`entry`, `ZoneOrSort`, `MinLevel`, `QuestLevel`, `RequiredRaces`, `SpecialFlags`, `Title`, `Details`, `Objectives`, `OfferRewardText`, `RewHonorableKills`, `PointOpt`, `CompleteScript`) VALUES ('800035', '876', '1', '80', '0', '1', 'Teleport to Shattrath', 'So you want to teleport?', 'Speak with the Teleport Master again.', 'Are you sure, you are ready to teleport?', '0', '0', '800035');
DELETE FROM `quest_end_scripts` WHERE `id` = '800035';
INSERT INTO `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `x`, `y`, `z`, `o`) VALUES ('800035', '0', '6', '530', '-1879.500977', '5409.461426', '-12.427713', '1.033202');

/* Isle Of Quel'Danas Teleport Quest */
DELETE FROM `quest_template` WHERE `entry` = '800036';
INSERT INTO `quest_template` (`entry`, `ZoneOrSort`, `MinLevel`, `QuestLevel`, `RequiredRaces`, `SpecialFlags`, `Title`, `Details`, `Objectives`, `OfferRewardText`, `RewHonorableKills`, `PointOpt`, `CompleteScript`) VALUES ('800036', '876', '1', '80', '0', '1', 'Teleport to Isle Of Quel\'Danas', 'So you want to teleport?', 'Speak with the Teleport Master again.', 'Are you sure, you are ready to teleport?', '0', '0', '800036');
DELETE FROM `quest_end_scripts` WHERE `id` = '800036';
INSERT INTO `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `x`, `y`, `z`, `o`) VALUES ('800036', '0', '6', '530', '12947.4', '-6893.31', '5.68398', '3.09154');

/* Gurubashi Arena Teleport Quest */
DELETE FROM `quest_template` WHERE `entry` = '800037';
INSERT INTO `quest_template` (`entry`, `ZoneOrSort`, `MinLevel`, `QuestLevel`, `RequiredRaces`, `SpecialFlags`, `Title`, `Details`, `Objectives`,`OfferRewardText`, `RewHonorableKills`, `PointOpt`, `CompleteScript`) VALUES ('800037', '876', '1', '80', '0', '1', 'Teleport to Gurubashi Arena', 'So you want to teleport?', 'Speak with the Teleport Master again.', 'Are you sure, you are ready to teleport?', '0', '0', '800037');
DELETE FROM `quest_end_scripts` WHERE `id` = '800037';
INSERT INTO `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `x`, `y`, `z`, `o`) VALUES ('800037', '0', '6', '0', '-13234.119141', '217.386627', '31.675938', '1.068150');

/* Gadgetan Teleport Quest */
DELETE FROM `quest_template` WHERE `entry` = '800038';
INSERT INTO `quest_template` (`entry`, `ZoneOrSort`, `MinLevel`, `QuestLevel`, `RequiredRaces`, `SpecialFlags`, `Title`, `Details`, `Objectives`, `OfferRewardText`, `RewHonorableKills`, `PointOpt`, `CompleteScript`) VALUES ('800038', '0', '1', '80', '0', '1', 'Teleport to Gadgetzan Arena', 'So you want to teleport?', 'Speak with the Teleport Master again.', 'Are you sure, you are ready to teleport?', '0', '0', '800038');
DELETE FROM `quest_end_scripts` WHERE `id` = '800038';
INSERT INTO `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `x`, `y`, `z`, `o`) VALUES ('800038', '0', '6', '1', '-7155.7', '-3822.1', '8.43', '1.068150');

/* GM Island Teleport Quest */
DELETE FROM `quest_template` WHERE `entry` = '800039';
INSERT INTO `quest_template` (`entry`, `ZoneOrSort`, `MinLevel`, `QuestLevel`, `RequiredRaces`, `SpecialFlags`, `Title`, `Details`, `Objectives`, `OfferRewardText`, `RewHonorableKills`, `PointOpt`, `CompleteScript`) VALUES ('800039', '876', '1', '80', '0', '1', 'Teleport to GM Island', 'So you want to teleport?', 'Speak with the Teleport Master again.', 'Are you sure, you are ready to teleport?', '0', '0', '800039');
DELETE FROM `quest_end_scripts` WHERE `id` = '800039';
INSERT INTO `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `x`, `y`, `z`, `o`) VALUES ('800039', '0', '6', '1', '16225.11', '16251.11', '12.7', '1.684');

/* Teleport to Map29 / high end vendors */
DELETE FROM `quest_template` WHERE `entry` = '800040';
INSERT INTO `quest_template` (`entry`, `ZoneOrSort`, `MinLevel`, `QuestLevel`, `RequiredRaces`, `SpecialFlags`, `Title`, `Details`, `Objectives`, `OfferRewardText`, `RewHonorableKills`, `PointOpt`, `CompleteScript`) VALUES ('800040', '876', '1', '0', '0', '1', 'Teleport to Area52', 'So you want to teleport?', 'Speak with the Teleport Master again.', 'Are you sure, you are ready to teleport?', '0', '0', '800040');
DELETE FROM `quest_end_scripts` WHERE `id` = '800040';
INSERT INTO `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `x`, `y`, `z`, `o`) VALUES ('800040', '0', '6', '29', '3384.189209', '-4949.738770', '161.123047', '1.684');

/* ********************************************************************************************** */
/* Modified Staff of Archmage Vorgath - Used to summon our new portal hoe */
DELETE FROM `item_template` where `entry` = ('50000');
INSERT INTO `item_template` (`entry`, `class`, `subclass`, `unk0`, `name`, `displayid`, `Quality`, `Flags`, `BuyCount`, `BuyPrice`, `SellPrice`, `InventoryType`, `AllowableClass`, `AllowableRace`, `ItemLevel`, `RequiredLevel`, `RequiredSkill`, `RequiredSkillRank`, `requiredspell`, `requiredhonorrank`, `RequiredCityRank`, `RequiredReputationFaction`, `RequiredReputationRank`, `maxcount`, `stackable`, `ContainerSlots`, `StatsCount`, `stat_type1`, `stat_value1`, `stat_type2`, `stat_value2`, `stat_type3`, `stat_value3`, `stat_type4`, `stat_value4`, `stat_type5`, `stat_value5`, `stat_type6`, `stat_value6`, `stat_type7`, `stat_value7`, `stat_type8`, `stat_value8`, `stat_type9`, `stat_value9`, `stat_type10`, `stat_value10`, `ScalingStatDistribution`, `ScalingStatValue`, `dmg_min1`, `dmg_max1`, `dmg_type1`, `dmg_min2`, `dmg_max2`, `dmg_type2`, `armor`, `holy_res`, `fire_res`, `nature_res`, `frost_res`, `shadow_res`, `arcane_res`, `delay`, `ammo_type`, `RangedModRange`, `spellid_1`, `spelltrigger_1`, `spellcharges_1`, `spellppmRate_1`, `spellcooldown_1`, `spellcategory_1`, `spellcategorycooldown_1`, `spellid_2`, `spelltrigger_2`, `spellcharges_2`, `spellppmRate_2`, `spellcooldown_2`, `spellcategory_2`, `spellcategorycooldown_2`, `spellid_3`, `spelltrigger_3`, `spellcharges_3`, `spellppmRate_3`, `spellcooldown_3`, `spellcategory_3`, `spellcategorycooldown_3`, `spellid_4`, `spelltrigger_4`, `spellcharges_4`, `spellppmRate_4`, `spellcooldown_4`, `spellcategory_4`, `spellcategorycooldown_4`, `spellid_5`, `spelltrigger_5`, `spellcharges_5`, `spellppmRate_5`, `spellcooldown_5`, `spellcategory_5`, `spellcategorycooldown_5`, `bonding`, `description`, `PageText`, `LanguageID`, `PageMaterial`, `startquest`, `lockid`, `Material`, `sheath`, `RandomProperty`, `RandomSuffix`, `block`, `itemset`, `MaxDurability`, `area`, `Map`, `BagFamily`, `TotemCategory`, `socketColor_1`, `socketContent_1`, `socketColor_2`, `socketContent_2`, `socketColor_3`, `socketContent_3`, `socketBonus`, `GemProperties`, `RequiredDisenchantSkill`, `ArmorDamageModifier`, `Duration`, `ItemLimitCategory`, `HolidayId`, `ScriptName`, `DisenchantID`, `FoodType`, `minMoneyLoot`, `maxMoneyLoot`) values('50000','12','0','-1','Putzvilles Splendiferous Staff of Wonderlous Teleportation','39227','1','2048','1','0','0','0','-1','-1','1','0','0','0','0','0','0','0','0','1','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','34372','0','0','0','120000','0','-1','0','0','0','0','-1','0','-1','0','0','0','0','-1','0','-1','0','0','0','0','-1','0','-1','0','0','0','0','-1','0','-1','4','Although the staff shows no visible signs of age, you get the impression that it is quite old.','0','0','0','0','0','-1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','-1','0','0','0','0','','0','0','0','0');

/* ********************************************************************************************** */
/* Hijack Image of Archmage Vorgoth with Quests for Teleportation */

/* Clear so not to double-add */
DELETE FROM `creature_questrelation` WHERE `id` = '19644';
DELETE FROM `creature_involvedrelation` WHERE `id` = '19644';

/* Re-add 'standard' quest/involved relations for Archmage Image */
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES ('19644', '10176');
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES ('19644', '10188');
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES ('19644', '10192');
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES ('19644', '10209');
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES ('19644', '10301');

INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES ('19644', '10174');
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES ('19644', '10188');
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES ('19644', '10192');
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES ('19644', '10209');
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES ('19644', '10301');

/* Adding Portal Quests to Archmage Vorgoth */
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES ('19644', '800026');
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES ('19644', '800027');
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES ('19644', '800028');
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES ('19644', '800029');
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES ('19644', '800030');
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES ('19644', '800031');
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES ('19644', '800032');
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES ('19644', '800033');
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES ('19644', '800034');
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES ('19644', '800035');
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES ('19644', '800036');
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES ('19644', '800037');
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES ('19644', '800038');
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES ('19644', '800039');
-- INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES ('19644', '800040');

INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES ('19644', '800026');
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES ('19644', '800027');
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES ('19644', '800028');
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES ('19644', '800029');
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES ('19644', '800030');
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES ('19644', '800031');
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES ('19644', '800032');
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES ('19644', '800033');
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES ('19644', '800034');
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES ('19644', '800035');
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES ('19644', '800036');
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES ('19644', '800037');
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES ('19644', '800038');
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES ('19644', '800039');
-- INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES ('19644', '800040');

/* ********************************************************************************************** */
/*Insert Portal Staff into each players default inventory for new players*/
DELETE FROM playercreateinfo_item WHERE itemid = 50000;
INSERT INTO playercreateinfo_item (`race`,`class`,`itemid`,`amount`)
SELECT DISTINCT race, class, 50000, 1 from playercreateinfo_item;


/*Give the item to each vendor that is an innkeeper*/
DELETE FROM npc_vendor WHERE item = 50000;  
INSERT INTO npc_vendor (`entry`,`item`,`maxcount`,`incrtime`,`ExtendedCost`)  
SELECT DISTINCT entry,50000,0,0,0 from creature_template WHERE subname = 'Innkeeper';