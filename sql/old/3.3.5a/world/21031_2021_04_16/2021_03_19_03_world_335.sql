-- Remaining with Blue Dragonscale
UPDATE `creature_template` SET `skinloot` = 60028 WHERE `entry` IN (6109);
UPDATE `creature_template` SET `skinloot` = 60029 WHERE `entry` IN (193,6129,6130,6131,7435);
UPDATE `creature_template` SET `skinloot` = 60030 WHERE `entry` IN (7436,7437,10662,10663,10664,10196,10202);
UPDATE `creature_template` SET `skinloot` = 60031 WHERE `entry` IN (10659,10660,10661);

DELETE FROM `skinning_loot_template` WHERE `Entry` BETWEEN 60028 AND 60031;
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (6109,193,6129,6130,6131,7435,7436,7437,10662,10663,10664,10196,10202,10659,10660,10661);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60028,15415,0,100,0,1,1,3,6,"Blue Dragonscale"),
(60029,4304,0,25,0,1,1,1,2,"Thick Leather"),
(60029,8165,0,10,0,1,1,1,1,"Worn Dragonscale"),
(60029,8169,0,3,0,1,1,1,1,"Thick Hide"),
(60029,8170,0,43,0,1,1,1,2,"Rugged Leather"),
(60029,8171,0,4,0,1,1,1,1,"Rugged Hide"),
(60029,15415,0,15,0,1,1,1,1,"Blue Dragonscale"),
(60030,4304,0,5,0,1,1,1,2,"Thick Leather"),
(60030,8165,0,10,0,1,1,1,1,"Worn Dragonscale"),
(60030,8170,0,55,0,1,1,1,2,"Rugged Leather"),
(60030,8171,0,5,0,1,1,1,1,"Rugged Hide"),
(60030,15415,0,25,0,1,1,1,1,"Blue Dragonscale"),
(60031,4304,0,40,0,1,1,1,1,"Thick Leather"),
(60031,8165,0,5,0,1,1,1,1,"Worn Dragonscale"),
(60031,8169,0,3,0,1,1,1,1,"Thick Hide"),
(60031,8170,0,45,0,1,1,1,1,"Rugged Leather"),
(60031,8171,0,4,0,1,1,1,1,"Rugged Hide"),
(60031,15415,0,3,0,1,1,1,1,"Blue Dragonscale");

-- Remaining with Green Dragonscale
UPDATE `creature_template` SET `skinloot` = 60032 WHERE `entry` IN (14887,14888,14889,14890);
UPDATE `creature_template` SET `skinloot` = 60033 WHERE `entry` IN (742,743,744,745,746);
UPDATE `creature_template` SET `skinloot` = 60034 WHERE `entry` IN (5709);
UPDATE `creature_template` SET `skinloot` = 60035 WHERE `entry` IN (5277,5280,5283,8497);
UPDATE `creature_template` SET `skinloot` = 60036 WHERE `entry` IN (5719,5720,5721,5722);
UPDATE `creature_template` SET `skinloot` = 60037 WHERE `entry` IN (1063,14445);
UPDATE `creature_template` SET `skinloot` = 60038 WHERE `entry` IN (8319);
UPDATE `creature_template` SET `skinloot` = 60039 WHERE `entry` IN (5312,5314,5317,5718,5319,5320,12474,12475,12476,12477,12478,12479,12496,12497,12498,12900);

DELETE FROM `skinning_loot_template` WHERE `Entry` BETWEEN 60032 AND 60039;
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (742,743,744,745,746,5709,5277,5280,5283,8497,5719,5720,5721,5722,1063,14445,8319,5319,5320,12474,12475,12476,12477,12479,12498,12900,15412);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60032,20381,0,100,0,1,0,3,5,"Dreamscale"),
(60032,15412,0,100,0,1,0,5,8,"Green Dragonscale"),
(60033,4234,0,25,0,1,1,1,2,"Heavy Leather"),
(60033,4235,0,5,0,1,1,1,1,"Heavy Hide"),
(60033,4304,0,45,0,1,1,1,2,"Thick Leather"),
(60033,8165,0,5,0,1,1,1,2,"Worn Dragonscale"),
(60033,8169,0,5,0,1,1,1,1,"Thick Hide"),
(60033,15412,0,15,0,1,1,1,1,"Green Dragonscale"),
-- May be slightly different
(60034,4304,0,27,0,1,1,1,2,"Thick Leather"),
(60034,8165,0,10,0,1,1,1,1,"Worn Dragonscale"),
(60034,8169,0,3,0,1,1,1,1,"Thick Hide"),
(60034,8170,0,27,0,1,1,1,2,"Rugged Leather"),
(60034,8171,0,3,0,1,1,1,1,"Rugged Hide"),
(60034,15412,0,30,0,1,1,1,1,"Green Dragonscale"),
(60035,4304,0,48,0,1,1,1,2,"Thick Leather"),
(60035,8165,0,7,0,1,1,1,2,"Worn Dragonscale"),
(60035,8169,0,5,0,1,1,1,1,"Thick Hide"),
(60035,8170,0,15,0,1,1,1,2,"Rugged Leather"),
(60035,15412,0,25,0,1,1,1,1,"Green Dragonscale"),
(60036,8165,0,100,0,1,0,1,2,"Worn Dragonscale"),
(60036,8169,0,20,0,1,0,1,1,"Thick Hide"),
(60036,8170,0,100,0,1,0,2,3,"Rugged Leather"),
(60036,15412,0,100,0,1,0,2,3,"Green Dragonscale"),
-- May be slightly different. Completely dead-end case, we'll never know correct chance
(60037,4304,0,68,0,1,1,1,1,"Thick Leather"),
(60037,8165,0,5,0,1,1,1,1,"Worn Dragonscale"),
(60037,8169,0,3,0,1,1,1,1,"Thick Hide"),
(60037,8170,0,20,0,1,1,1,1,"Rugged Leather"),
(60037,15412,0,4,0,1,1,1,1,"Green Dragonscale"),
(60038,4304,0,68,0,1,1,1,2,"Thick Leather"),
(60038,8165,0,5,0,1,1,1,1,"Worn Dragonscale"),
(60038,8169,0,3,0,1,1,1,1,"Thick Hide"),
(60038,8170,0,20,0,1,1,1,2,"Rugged Leather"),
(60038,15412,0,4,0,1,1,1,1,"Green Dragonscale"),
-- Another completely dead-end case, may be different
(60039,4304,0,5,0,1,1,1,2,"Thick Leather"),
(60039,8165,0,10,0,1,1,1,1,"Worn Dragonscale"),
(60039,8170,0,40,0,1,1,1,2,"Rugged Leather"),
(60039,8171,0,5,0,1,1,1,1,"Rugged Hide"),
(60039,15412,0,40,0,1,1,1,1,"Green Dragonscale");

-- Remaining with Red Dragonscale
UPDATE `creature_template` SET `skinloot` = 0 WHERE `entry` IN (15414);
UPDATE `creature_template` SET `skinloot` = 60040 WHERE `entry` IN (1045,1046,1047,1048,1049,1050,12899);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (15414,60040,1045,1046,1047,1048,1049,1050,12899);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60040,4304,0,5,0,1,1,1,2,"Thick Leather"),
(60040,8165,0,10,0,1,1,1,1,"Worn Dragonscale"),
(60040,8170,0,55,0,1,1,1,2,"Rugged Leather"),
(60040,8171,0,5,0,1,1,1,1,"Rugged Hide"),
(60040,15414,0,25,0,1,1,1,2,"Red Dragonscale");

-- Remaining with Worn Dragonscale
UPDATE `creature_template` SET `skinloot` = 60041 WHERE `entry` IN (2725,4323,4324,5278,7997,23687);
UPDATE `creature_template` SET `skinloot` = 60042 WHERE `entry` IN (2447,2726,4328,4329,4331,4334,4339);
UPDATE `creature_template` SET `skinloot` = 60043 WHERE `entry` IN (10678,14398);
UPDATE `creature_template` SET `skinloot` = 60044 WHERE `entry` IN (12129,36572);
UPDATE `creature_template` SET `skinloot` = 60045 WHERE `entry` IN (5276);
UPDATE `creature_template` SET `skinloot` = 60046 WHERE `entry` IN (8196);
UPDATE `creature_template` SET `skinloot` = 60047 WHERE `entry` IN (8197);
UPDATE `creature_template` SET `skinloot` = 60048 WHERE `entry` IN (8198);

DELETE FROM `skinning_loot_template` WHERE `Entry` BETWEEN 60041 AND 60048;
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (2725,4323,4324,5278,2447,2726,4328,4329,4331,4334,4339,10678,14398,12129,5276,8196,8197,8198);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60041,4234,0,40,0,1,1,1,1,"Heavy Leather"),
(60041,4235,0,3,0,1,1,1,1,"Heavy Hide"),
(60041,4304,0,50,0,1,1,1,1,"Thick Leather"),
(60041,8165,0,3,0,1,1,1,1,"Worn Dragonscale"),
(60041,8169,0,4,0,1,1,1,1,"Thick Hide"),
(60042,4234,0,35,0,1,1,1,2,"Heavy Leather"),
(60042,4235,0,5,0,1,1,1,1,"Heavy Hide"),
(60042,4304,0,50,0,1,1,1,2,"Thick Leather"),
(60042,8165,0,5,0,1,1,1,2,"Worn Dragonscale"),
(60042,8169,0,5,0,1,1,1,1,"Thick Hide"),
(60043,4304,0,15,0,1,1,1,1,"Thick Leather"),
(60043,8165,0,5,0,1,1,1,1,"Worn Dragonscale"),
(60043,8170,0,75,0,1,1,1,1,"Rugged Leather"),
(60043,8171,0,5,0,1,1,1,1,"Rugged Hide"),
-- Hm, interesting https://www.wowhead.com/npc=12129/onyxian-warder#comments:id=1061033
(60044,8170,0,80,0,1,1,1,20,"Rugged Leather"),
(60044,8171,0,20,0,1,1,5,10,"Rugged Hide"),
-- Below 100% are not accurate, completely dead-end cases
(60045,4304,0,77,0,1,1,1,1,"Thick Leather"),
(60045,8165,0,3,0,1,1,1,1,"Worn Dragonscale"),
(60045,8169,0,3,0,1,1,1,1,"Thick Hide"),
(60045,8170,0,17,0,1,1,1,1,"Rugged Leather"),
(60046,4304,0,70,0,1,1,1,2,"Thick Leather"),
(60046,8165,0,5,0,1,1,1,2,"Worn Dragonscale"),
(60046,8169,0,5,0,1,1,1,1,"Thick Hide"),
(60046,8170,0,20,0,1,1,1,2,"Rugged Leather"),
(60047,4304,0,5,0,1,1,1,2,"Thick Leather"),
(60047,8165,0,10,0,1,1,1,1,"Worn Dragonscale"),
(60047,8170,0,80,0,1,1,1,2,"Rugged Leather"),
(60047,8171,0,5,0,1,1,1,1,"Rugged Hide"),
(60048,4304,0,40,0,1,1,1,2,"Thick Leather"),
(60048,8165,0,10,0,1,1,1,1,"Worn Dragonscale"),
(60048,8169,0,3,0,1,1,1,1,"Thick Hide"),
(60048,8170,0,44,0,1,1,1,2,"Rugged Leather"),
(60048,8171,0,3,0,1,1,1,1,"Rugged Hide");
