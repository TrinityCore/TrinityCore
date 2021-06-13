-- All with Warbear Leather
UPDATE `creature_template` SET `skinloot` = 60058 WHERE `entry` IN (1815,7443,7444);
UPDATE `creature_template` SET `skinloot` = 60059 WHERE `entry` IN (8957);
UPDATE `creature_template` SET `skinloot` = 60060 WHERE `entry` IN (1816,7445,7446,10806,14308);

DELETE FROM `skinning_loot_template` WHERE `Entry` BETWEEN 60058 AND 60060;
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (1815,7443,7444,8957,1816,7445,7446,10806,14308);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60058,4304,0,38,0,1,1,1,1,"Thick Leather"),
(60058,8169,0,3,0,1,1,1,1,"Thick Hide"),
(60058,8170,0,45,0,1,1,1,1,"Rugged Leather"),
(60058,8171,0,4,0,1,1,1,1,"Rugged Hide"),
(60058,15419,0,10,0,1,1,1,1,"Warbear Leather"),
-- Same as above but we need to make it unique because of quest item
(60059,4304,0,38,0,1,1,1,1,"Thick Leather"),
(60059,8169,0,3,0,1,1,1,1,"Thick Hide"),
(60059,8170,0,45,0,1,1,1,1,"Rugged Leather"),
(60059,8171,0,4,0,1,1,1,1,"Rugged Hide"),
(60059,15419,0,10,0,1,1,1,1,"Warbear Leather"),
(60059,11512,0,50,0,1,0,1,1,"Patch of Tainted Skin"),
(60060,4304,0,10,0,1,1,1,1,"Thick Leather"),
(60060,8170,0,65,0,1,1,1,1,"Rugged Leather"),
(60060,8171,0,5,0,1,1,1,1,"Rugged Hide"),
(60060,15419,0,20,0,1,1,1,1,"Warbear Leather");

-- All with Black Whelp Scale
UPDATE `creature_template` SET `skinloot` = 60061 WHERE `entry` IN (441,14272);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60061,441,14272);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60061,783,0,5,0,1,1,1,1,"Light Hide"),
(60061,2318,0,63,0,1,1,1,2,"Light Leather"),
(60061,4232,0,2,0,1,1,1,1,"Medium Hide"),
(60061,7286,0,30,0,1,1,1,2,"Black Whelp Scale");

-- All with Red Whelp Scale
UPDATE `creature_template` SET `skinloot` = 60062 WHERE `entry` IN (1044);
UPDATE `creature_template` SET `skinloot` = 60063 WHERE `entry` IN (1069,1042,1043);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60062,1044);
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60063,1069,1042,1043,100008);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60062,2319,0,58,0,1,1,1,1,"Medium Leather"),
(60062,4232,0,5,0,1,1,1,1,"Medium Hide"),
(60062,4234,0,15,0,1,1,1,1,"Heavy Leather"),
(60062,4235,0,2,0,1,1,1,1,"Heavy Hide"),
(60062,7287,0,20,0,1,1,1,1,"Red Whelp Scale"),
-- Actually only moved to verified-only range
(60063,7287,0,10,0,1,1,1,1,"Red Whelp Scale"),
(60063,4232,0,5,0,1,1,1,1,"Medium Hide"),
(60063,783,0,3,0,1,1,1,1,"Light Hide"),
(60063,2319,0,45,0,1,1,1,1,"Medium Leather"),
(60063,2318,0,37,0,1,1,1,2,"Light Leather");

-- All with Green Whelp Scale
UPDATE `creature_template` SET `skinloot` = 60064 WHERE `entry` IN (740,741);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60064,740,741);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60064,2319,0,33,0,1,1,1,1,"Medium Leather"),
(60064,4232,0,4,0,1,1,1,1,"Medium Hide"),
(60064,4234,0,40,0,1,1,1,1,"Heavy Leather"),
(60064,4235,0,3,0,1,1,1,1,"Heavy Hide"),
(60064,7392,0,20,0,1,1,1,1,"Green Whelp Scale");

-- Remaining with Scorpid Scale
UPDATE `creature_template` SET `skinloot` = 60065 WHERE `entry` IN (5422,5423,7405);
UPDATE `creature_template` SET `skinloot` = 60066 WHERE `entry` IN (5424,5988,7803,8926);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60065,5422,5423,7405);
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60066,5424,5988,7803,8926);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60065,4234,0,20,0,1,1,1,1,"Heavy Leather"),
(60065,4235,0,3,0,1,1,1,1,"Heavy Hide"),
(60065,4304,0,33,0,1,1,1,1,"Thick Leather"),
(60065,8154,0,40,0,1,1,1,1,"Scorpid Scale"),
(60065,8169,0,4,0,1,1,1,1,"Thick Hide"),

(60066,4304,0,47,0,1,1,1,1,"Thick Leather"),
(60066,8154,0,40,0,1,1,1,2,"Scorpid Scale"),
(60066,8169,0,3,0,1,1,1,1,"Thick Hide"),
(60066,8170,0,10,0,1,1,1,1,"Rugged Leather");

-- All with Ruined Leather Scraps
UPDATE `creature_template` SET `skinloot` = 60067 WHERE `entry` IN (14430,1133,1132,17345,1549,1765,1137,1138,5807,390,2973,2956,1922,2957,2070,17373,17203,3110,17372,3566,113,3126,2033,3225,6789,1554,2972,17202,1548,15650,1547,15651,3130,3099,16347,3122,1134,2034,3131,3035,3100,1196,3123,118,2042,17199,524,3227,1190,1125,1135,3121,834,3127,1201,525,2958,16353,2959,1131,1126,2960,3125,119,15649,1199,822,3226,1127,17200,17374,15652,1553,2043,1128,1689,330,33710,10356,3068);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60067,17374);

INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60067,2318,0,40,0,1,1,1,1,"Light Leather"),
(60067,2934,0,60,0,1,1,1,1,"Ruined Leather Scraps");

UPDATE `creature_template` SET `skinloot` = 60068 WHERE `entry` IN (17201);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60068,17201);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60068,2318,0,40,0,1,1,1,1,"Light Leather"),
(60068,2934,0,60,0,1,1,1,1,"Ruined Leather Scraps"),
(60068,23677,0,80,1,1,0,1,1,"Moongraze Buck Hide");

UPDATE `creature_template` SET `skinloot` = 60069 WHERE `entry` IN (3533,3529,3531,1893,1892,1769,1782,1896,1924,1779,1770,1972);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60069,3529,3533);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
-- For some reason for 1924 max count is 2 in WotLK, 1 in classic, 1 in cata. We'll ignore that fact completely since all worgens
-- except that one drop only 1. Too suspicious
(60069,2318,0,60,0,1,1,1,1,"Light Leather"),
(60069,2934,0,35,0,1,1,1,1,"Ruined Leather Scraps"),
(60069,783,0,5,0,1,1,1,1,"Light Hide");

UPDATE `creature_template` SET `skinloot` = 60070 WHERE `entry` IN (1130,10357,12432,5865,3056,2175,2974,2322,3415,2163,3461,1186,2164,3242,3244,3254,2069,454,16348,1778,17347,3255,3243,4316,2321,16354,1188,3248,3234,833,1191,17525,3425,3246,1797,4127,2185,1766,157,3241,3058,1693,12431,3231,1388,33711,17556);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60070);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60070,783,0,5,0,1,1,1,1,"Light Hide"),
(60070,2318,0,60,0,1,1,1,2,"Light Leather"),
(60070,2934,0,35,0,1,1,1,1,"Ruined Leather Scraps");

UPDATE `creature_template` SET `skinloot` = 60071 WHERE `entry` IN (1961,1271);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60071);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60071,783,0,10,0,1,1,1,1,"Light Hide"),
(60071,2318,0,70,0,1,1,1,2,"Light Leather"),
(60071,2934,0,20,0,1,1,1,1,"Ruined Leather Scraps");

-- Cleaning
UPDATE `conditions` SET `SourceGroup` = 60059 WHERE `SourceTypeOrReferenceId` = 11 AND `SourceGroup` = 8957;

-- Not skinnable
UPDATE `creature_template` SET `skinloot` = 0 WHERE `entry` IN (3939);
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (100002);

-- Well, he probably was never skinned by a single person
UPDATE `creature_template` SET `skinloot` = 60067 WHERE `entry` IN (1129);
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (100001);
