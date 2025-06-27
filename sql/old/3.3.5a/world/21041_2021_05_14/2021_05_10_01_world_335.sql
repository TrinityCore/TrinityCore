-- All with Deviate Scale
UPDATE `creature_template` SET `skinloot` = 0 WHERE `entry` = 10581; -- No skinning loot
DELETE FROM `skinning_loot_template` WHERE `Entry` = 12715;

UPDATE `creature_template` SET `skinloot` = 60049 WHERE `entry` IN (5755,5048,3636,5756,5056,3637,8886,5762,3631,3632,20797,3641,3630,3633,3634,5912);
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60049,5912,100009);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60049,2318,0,50,0,1,1,1,2,"Light Leather"),
(60049,2319,0,25,0,1,1,1,2,"Medium Leather"),
(60049,6470,0,10,0,1,1,1,1,"Deviate Scale"),
(60049,783,0,7,0,1,1,1,1,"Light Hide"),
(60049,6471,0,5,0,1,1,1,1,"Perfect Deviate Scale"),
(60049,4232,0,3,0,1,1,1,1,"Medium Hide");

-- All with Chimera Leather
UPDATE `creature_template` SET `skinloot` = 60050 WHERE `entry` IN (10807,11497,7449,7448);
UPDATE `creature_template` SET `skinloot` = 60051 WHERE `entry` IN (7447,8763,8764);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60050,60051,10807,11497,7449,7448,7447,8763,8764);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
-- Hard to be sure since Chimera Leather was made useless and the chance was lowered but wowhead didn't wiped data in WotLK
-- That means to show correct chance creatures should be killed thousands of times only in WotLK, that didn't happened
(60050,4304,0,6,0,1,1,1,1,"Thick Leather"),
(60050,8170,0,63,0,1,1,1,1,"Rugged Leather"),
(60050,8171,0,6,0,1,1,1,1,"Rugged Hide"),
(60050,15423,0,25,0,1,1,1,1,"Chimera Leather"),
(60051,4304,0,30,0,1,1,1,1,"Thick Leather"),
(60051,8169,0,3,0,1,1,1,1,"Thick Hide"),
(60051,8170,0,43,0,1,1,1,1,"Rugged Leather"),
(60051,8171,0,4,0,1,1,1,1,"Rugged Hide"),
(60051,15423,0,20,0,1,1,1,1,"Chimera Leather");

-- Random, not yet assigned to all creatures which uses these references
UPDATE `creature_template` SET `skinloot` = 60052 WHERE `entry` IN (1084,2251,976,6170,2727,4140,1152,4150,4696,686,736,685,2407,1085,4700,4151,689,1151,4697,1108,682,2250,4144,2249,4351,4143,977,4139,2560,2406,4728,4726,10992,4689,14228,14222,1140,3792,507);
UPDATE `creature_template` SET `skinloot` = 60053 WHERE `entry` IN (4512,4825,3927,4538,4274,6215,5928,4066);
UPDATE `creature_template` SET `skinloot` = 60054 WHERE `entry` IN (12677,1018,4548,3476,3811,3825);
UPDATE `creature_template` SET `skinloot` = 60055 WHERE `entry` IN (4841,1516,2753,5307,8208,1511,5305,4390,5300,5308,5426,1550,5304,1514,2657,1551,1087,5420,1558,5425,2734,2658,5272,4389,5419,5260,5268,730,14234,1552,2850,14491);
UPDATE `creature_template` SET `skinloot` = 60056 WHERE `entry` IN (5292,5295,5293);
UPDATE `creature_template` SET `skinloot` = 60057 WHERE `entry` IN (11786,5224);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60052,976,977,3792,6170,14228);
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60053,4066,4512,6215);
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60054);
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60055,1552,2753,2850,4390,14234);
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60056,5292,5295,5293);
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60057);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60052,2319,0,43,0,1,1,1,1,"Medium Leather"),
(60052,4232,0,4,0,1,1,1,1,"Medium Hide"),
(60052,4234,0,50,0,1,1,1,1,"Heavy Leather"),
(60052,4235,0,3,0,1,1,1,1,"Heavy Hide"),

(60053,2319,0,65,0,1,1,1,2,"Medium Leather"),
(60053,4232,0,7,0,1,1,1,1,"Medium Hide"),
(60053,4234,0,25,0,1,1,1,2,"Heavy Leather"),
(60053,4235,0,3,0,1,1,1,1,"Heavy Hide"),

(60054,2319,0,73,0,1,1,1,1,"Medium Leather"),
(60054,4232,0,5,0,1,1,1,1,"Medium Hide"),
(60054,4234,0,20,0,1,1,1,1,"Heavy Leather"),
(60054,4235,0,2,0,1,1,1,1,"Heavy Hide"),

(60055,4234,0,43,0,1,1,1,1,"Heavy Leather"),
(60055,4235,0,3,0,1,1,1,1,"Heavy Hide"),
(60055,4304,0,50,0,1,1,1,1,"Thick Leather"),
(60055,8169,0,4,0,1,1,1,1,"Thick Hide"),

(60056,4234,0,43,0,1,1,1,1,"Heavy Leather"),
(60056,4235,0,3,0,1,1,1,1,"Heavy Hide"),
(60056,4304,0,50,0,1,1,1,1,"Thick Leather"),
(60056,8169,0,4,0,1,1,1,1,"Thick Hide"),
(60056,8973,0,80,1,1,0,1,1,"Thick Yeti Hide"),

(60057,4234,0,40,0,1,1,1,2,"Heavy Leather"),
(60057,4235,0,5,0,1,1,1,1,"Heavy Hide"),
(60057,4304,0,50,0,1,1,1,2,"Thick Leather"),
(60057,8169,0,5,0,1,1,1,1,"Thick Hide");
