-- 4539 skipped

-- Left behind
-- 5352 may use different or unique
UPDATE `creature_template` SET `skinloot` = 60055 WHERE `entry` IN (7268,8437,5352);
UPDATE `creature_template` SET `skinloot` = 60053 WHERE `entry` IN (4829);
-- 12037,5937 may use different or unique
UPDATE `creature_template` SET `skinloot` = 60052 WHERE `entry` IN (4346,4341,856,534,12676,688,12037,5937);
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (12037,4346);
UPDATE `creature_template` SET `skinloot` = 60054 WHERE `entry` IN (205,206,533,681,683,855,898,920,1019,1023,1150,1353,2248,2385,2408,2559,3789,3791,3815,3818,4017,4041,4107,4109,4110,4118,4119,4124,4142,4147,4248,4249,4688,5827,6071,6167,10882);

-- Cannot be skinned
UPDATE `creature_template` SET `skinloot` = 0 WHERE `entry` IN (2565,2831);
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (2565,2831);

--
UPDATE `creature_template` SET `skinloot` = 60072 WHERE `entry` IN (4422);
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60072,4422);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60072,4234,0,100,0,1,0,3,5,"Heavy Leather"),
(60072,4235,0,100,0,1,0,1,1,"Heavy Hide");

--
UPDATE `creature_template` SET `skinloot` = 60073 WHERE `entry` IN (4830);
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60073,4830);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60073,4234,0,77,0,1,1,2,3,"Heavy Leather"),
(60073,4235,0,23,0,1,1,1,1,"Heavy Hide");

-- 5935 may use different or unique
UPDATE `creature_template` SET `skinloot` = 60074 WHERE `entry` IN (11785,8138,4861,7334,7022,4863,5935);
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60074,8138,4861,7334,7022,4863);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60074,4234,0,70,0,1,1,1,2,"Heavy Leather"),
(60074,4235,0,5,0,1,1,1,1,"Heavy Hide"),
(60074,4304,0,25,0,1,1,1,2,"Thick Leather");

--
UPDATE `creature_template` SET `skinloot` = 60075 WHERE `entry` IN (4425,7333,4304,5934);
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60075,4425,7333,5934);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60075,2319,0,40,0,1,1,1,2,"Medium Leather"),
(60075,4232,0,6,0,1,1,1,1,"Medium Hide"),
(60075,4234,0,50,0,1,1,1,2,"Heavy Leather"),
(60075,4235,0,4,0,1,1,1,1,"Heavy Hide");

-- Completely unique template in a weird way
UPDATE `creature_template` SET `skinloot` = 60076 WHERE `entry` IN (7078);
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60076,7078);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60076,2319,0,43,0,1,1,1,1,"Medium Leather"),
(60076,4232,0,4,0,1,1,1,1,"Medium Hide"),
(60076,4234,0,50,0,1,1,1,2,"Heavy Leather"),
(60076,4235,0,3,0,1,1,1,1,"Heavy Hide");

-- 768,684,1713 - Shadowcat Hide will be removed completely
-- 4342,4355 were removed from the game, the only one souce is classic wowhead
UPDATE `creature_template` SET `skinloot` = 60077 WHERE `entry` IN (2452,4660,23873,4504,854,4388,4727,4343,14232,2635,1114,4729,4702,4678,4344,4347,4352,729,4690,2474,767,687,4681,728,4348,4701,4356,1557,4357,4345,690,772,2561,2729,2732,2728,2731,4662,1082,13602,4699,2347,4685,14227,2473,14233,768,684,1713,4342,4355);
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60077,684,729,768,1713,2347,2452,2474,2635,4504,4660);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60077,4235,0,3,0,1,1,1,1,"Heavy Hide"),
(60077,4304,0,20,0,1,1,1,1,"Thick Leather"),
(60077,4234,0,77,0,1,1,1,1,"Heavy Leather");

--
UPDATE `creature_template` SET `skinloot` = 60078 WHERE `entry` IN (5356,2730,5287,8211,2923,2924,5286);
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60078,5356,2730,5287,8211,2923,2924,5286);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60078,4234,0,40,0,1,1,1,1,"Heavy Leather"),
(60078,4235,0,4,0,1,1,1,1,"Heavy Hide"),
(60078,4304,0,50,0,1,1,1,1,"Thick Leather"),
(60078,8169,0,4,0,1,1,1,1,"Thick Hide"),
(60078,8368,0,2,0,1,1,1,1,"Thick Wolfhide");

-- Bye-bye
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (100011,100012,100014,100013,100010);
UPDATE `creature_template` SET `skinloot` = 0 WHERE `entry` IN (12741,10136);
