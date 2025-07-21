--
-- Search by Light Leather item (2318)
UPDATE `creature_template` SET `skinloot` = 60079 WHERE `entry` IN
(5053,3619,1224,3721,17589,17588,3257,3424,4008,3236,2187,213,4129,2165,3247,2323,5829,3245,17527,17348,547,16349,3475,3466,565,2237,3256,1923,3426,16355,2172,3239,
3463,4011,1189,3416,3816,3240,6788,1192,2071,3823,4009,3722 /* guessed */,17661,3398);
UPDATE `creature_template` SET `skinloot` = 60080 WHERE `entry` IN
(3653,3861,3862,5058,3853,3851,3854,3865,3855,3914,3864,3652 /* guessed */);
UPDATE `creature_template` SET `skinloot` = 60081 WHERE `entry` IN
(4887,4279,4827,1225 /* guessed */,3859,4824,3866,4514,3868,5842 /* guessed */,4511,2529,3857,3886,17592 /* guessed */);
UPDATE `creature_template` SET `skinloot` = 60082 WHERE `entry` IN
(521,4015,3237,5832,3774,4044,1017,2354,3472,4067,3238,4042,3824,12940,4018,4117,2089,3809,3235,345,12678,923,4013,2356,3817,1020,4128,3250,1258,4032,2384,4012,2476,
2351,4019,4126,3473,3252,3474);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (3619,3722,3652,17592,5832,5842);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60079,60080,60081,60082);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60079,783,0,5,0,1,1,1,1,'Light Hide'),
(60079,2318,0,73,0,1,1,1,2,'Light Leather'),
(60079,2319,0,20,0,1,1,1,1,'Medium Leather'),
(60079,4232,0,2,0,1,1,1,1,'Medium Hide'),

(60080,783,0,7,0,1,1,1,1,'Light Hide'),
(60080,2318,0,65,0,1,1,1,2,'Light Leather'),
(60080,2319,0,25,0,1,1,1,2,'Medium Leather'),
(60080,4232,0,3,0,1,1,1,1,'Medium Hide'),

(60081,783,0,4,0,1,1,1,1,'Light Hide'),
(60081,2318,0,35,0,1,1,1,2,'Light Leather'),
(60081,2319,0,55,0,1,1,1,2,'Medium Leather'),
(60081,4232,0,6,0,1,1,1,1,'Medium Hide'),

(60082,783,0,3,0,1,1,1,1,'Light Hide'),
(60082,2318,0,42,0,1,1,1,2,'Light Leather'),
(60082,2319,0,50,0,1,1,1,1,'Medium Leather'),
(60082,4232,0,5,0,1,1,1,1,'Medium Hide');

--
-- Search by Thick Wolfhide item (8368)
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (14282);
-- Different difficulties apparently should have different loot, but we have no data
UPDATE `creature_template` SET `skinloot` = 60083 WHERE `entry` IN (14282,22738,31977);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60083);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
-- Unique. No enough data for better values, guessed
-- I think it's wrong to put here all of that at once. Knothide leather is from different difficulty
(60083,21887,0,48,0,1,1,1,1,'Knothide Leather'),
(60083,25649,0,23,0,1,1,2,3,'Knothide Leather Scraps'),
(60083,8170,0,15,0,1,1,1,1,'Rugged Leather'),
(60083,4304,0,11,0,1,1,1,1,'Thick Leather'),
(60083,8368,0,1,0,1,1,1,1,'Thick Wolfhide'),
(60083,8169,0,1,0,1,1,1,1,'Thick Hide'),
(60083,8171,0,1,0,1,1,1,1,'Rugged Hide');

--
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (12121,12122);
-- Different difficulties apparently should have different loot, but we have no data
UPDATE `creature_template` SET `skinloot` = 60084 WHERE `entry` IN (12121,22540,31964,12122,22546,31970);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60084);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
-- No enough data for better values, guessed
(60084,21887,0,42,0,1,1,1,1,'Knothide Leather'),
(60084,25649,0,30,0,1,1,2,3,'Knothide Leather Scraps'),
(60084,8170,0,22,0,1,1,1,2,'Rugged Leather'),
(60084,4304,0,3,0,1,1,1,2,'Thick Leather'),
(60084,8368,0,2,0,1,1,1,1,'Thick Wolfhide'),
(60084,8171,0,1,0,1,1,1,1,'Rugged Hide');

--
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (2681);

UPDATE `creature_template` SET `skinloot` = 60085 WHERE `entry` IN (2681);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60085);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60085,4304,0,73,0,1,1,1,2,'Thick Leather'),
(60085,8170,0,20,0,1,1,1,2,'Rugged Leather'),
(60085,8169,0,5,0,1,1,1,1,'Thick Hide'),
(60085,8368,0,2,0,1,1,1,1,'Thick Wolfhide');

--
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (10147,8921,10981,2925,2680,5984,2926,5985,5288);

UPDATE `creature_template` SET `skinloot` = 60086 WHERE `entry` IN
(10147 /* copied, is he really skinnable? */,14339,8921,10981,22737,31975,2925,2680,5984,2926,5985,5288);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60086);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60086,4304,0,73,0,1,1,1,1,'Thick Leather'),
(60086,8170,0,20,0,1,1,1,1,'Rugged Leather'),
(60086,8169,0,5,0,1,1,1,1,'Thick Hide'),
(60086,8368,0,2,0,1,1,1,1,'Thick Wolfhide');

--
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (9696,13036,8718);

UPDATE `creature_template` SET `skinloot` = 60087 WHERE `entry` IN
(9696,11885,13036,8718);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60087);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60087,8170,0,83,0,1,1,1,2,'Rugged Leather'),
(60087,4304,0,10,0,1,1,1,2,'Thick Leather'),
(60087,8171,0,5,0,1,1,1,1,'Rugged Hide'),
(60087,8368,0,2,0,1,1,1,1,'Thick Wolfhide');

--
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (9042,9416,10221);

UPDATE `creature_template` SET `skinloot` = 60088 WHERE `entry` IN
(9042,9416,10221);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60088);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60088,8170,0,50,0,1,1,1,2,'Rugged Leather'),
(60088,4304,0,41,0,1,1,1,2,'Thick Leather'),
(60088,8171,0,4,0,1,1,1,1,'Rugged Hide'),
(60088,8169,0,3,0,1,1,1,1,'Thick Hide'),
(60088,8368,0,2,0,1,1,1,1,'Thick Wolfhide');

--
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (7055,9690,9694,12418,8922,10156,1817,9697);

UPDATE `creature_template` SET `skinloot` = 60089 WHERE `entry` IN
(7055,9690,9694,12418,8922,10077,1817,9697);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60089);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60089,8170,0,50,0,1,1,1,1,'Rugged Leather'),
(60089,4304,0,41,0,1,1,1,1,'Thick Leather'),
(60089,8171,0,4,0,1,1,1,1,'Rugged Hide'),
(60089,8169,0,3,0,1,1,1,1,'Thick Hide'),
(60089,8368,0,2,0,1,1,1,1,'Thick Wolfhide');

-- Shouldn't be skinnable
UPDATE `creature_template` SET `skinloot` = 0 WHERE `entry` IN (5438); -- Tamed Cat
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (10150);

--
-- Search by Patch of Tainted Skin (11512)
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (7126,8961,8958,8960,7125,8956,8959);

UPDATE `creature_template` SET `skinloot` = 60090 WHERE `entry` IN
(7126,8961,8958,8960,7125,8956,8959);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60090);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60090,8170,0,50,0,1,1,1,1,'Rugged Leather'),
(60090,4304,0,43,0,1,1,1,1,'Thick Leather'),
(60090,11512,0,35,0,1,0,1,1,'Patch of Tainted Skin'),
(60090,8171,0,4,0,1,1,1,1,'Rugged Hide'),
(60090,8169,0,3,0,1,1,1,1,'Thick Hide');

-- Fix wrong chance
UPDATE `skinning_loot_template` SET `Chance` = 35 WHERE `Entry` = 60059 AND `Item` = 11512;

--
-- Search by Thick Yeti Fur item (12366)
-- Actually skinnable only from Rogue Ice Thistle and Ice Thistle Yeti, NOT from all yetis
-- And the chance is quite low
-- Weirdly enough we have 3 template here for 4 NPC and not 2 because the chance is a bit different for unknown reason
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (7457,7458,7459,7460);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60091,60092,60093);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60091,4304,0,43,0,1,1,1,1,'Thick Leather'),
(60091,8169,0,3,0,1,1,1,1,'Thick Hide'),
(60091,8170,0,50,0,1,1,1,1,'Rugged Leather'),
(60091,8171,0,4,0,1,1,1,1,'Rugged Hide'),
(60091,12366,0,10,1,1,0,1,1,'Thick Yeti Fur'),

(60092,4304,0,43,0,1,1,1,1,'Thick Leather'),
(60092,8169,0,3,0,1,1,1,1,'Thick Hide'),
(60092,8170,0,50,0,1,1,1,1,'Rugged Leather'),
(60092,8171,0,4,0,1,1,1,1,'Rugged Hide'),
(60092,12366,0,4,1,1,0,1,1,'Thick Yeti Fur'),

(60093,4304,0,15,0,1,1,1,1,'Thick Leather'),
(60093,8170,0,80,0,1,1,1,1,'Rugged Leather'),
(60093,8171,0,5,0,1,1,1,1,'Rugged Hide');

UPDATE `creature_template` SET `skinloot` = 60091 WHERE `entry` IN (7457);
UPDATE `creature_template` SET `skinloot` = 60092 WHERE `entry` IN (7458);
UPDATE `creature_template` SET `skinloot` = 60093 WHERE `entry` IN (7459,7460);

--
-- Not skinnable, birds
UPDATE `creature_template` SET `skinloot` = 0 WHERE `entry` IN (5982,5983);
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (5982);


--
-- Search by Thick Leather item, in DB, ordered by chance
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (11368);

UPDATE `creature_template` SET `skinloot` = 60094 WHERE `entry` IN (11368);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60094);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60094,8170,0,70,0,1,1,1,1,'Rugged Leather'),
(60094,4304,0,15,0,1,1,1,1,'Thick Leather'),
(60094,19767,0,10,0,1,1,1,1,'Primal Bat Leather'),
(60094,8171,0,5,0,1,1,1,1,'Rugged Hide');

--
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (11360,11361);

UPDATE `creature_template` SET `skinloot` = 60095 WHERE `entry` IN (11360,11361);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60095);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60095,8170,0,60,0,1,1,1,2,'Rugged Leather'),
(60095,19768,0,20,0,1,1,1,1,'Primal Tiger Leather'),
(60095,4304,0,15,0,1,1,1,2,'Thick Leather'),
(60095,8171,0,5,0,1,1,1,1,'Rugged Hide');

--
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (16117,8598,10200,11373,8602,9684,10741,7462);

UPDATE `creature_template` SET `skinloot` = 60096 WHERE `entry` IN (16117,8598,10200,11373,8602,9684,10741,7462);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60096);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60096,8170,0,80,0,1,1,1,1,'Rugged Leather'),
(60096,4304,0,15,0,1,1,1,1,'Thick Leather'),
(60096,8171,0,5,0,1,1,1,1,'Rugged Hide');

--
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (11372,11357,14821,12800,11371,2759,11365,12801,15043,2757,10737,4374);

UPDATE `creature_template` SET `skinloot` = 60097 WHERE `entry` IN (11372,11357,14821,12800,11371,2759,11365,12801,15043,2757,10737,4374);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60097);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60097,8170,0,80,0,1,1,1,2,'Rugged Leather'),
(60097,4304,0,15,0,1,1,1,2,'Thick Leather'),
(60097,8171,0,5,0,1,1,1,1,'Rugged Hide');

--
DELETE FROM `skinning_loot_template` WHERE `Entry` IN
(6581,5291,5349,6507,9318,8675,731,2659,8760,9683,6506,6508,5274,6505,6375,6378,9166,5990,5992,10990,22726,31921,6377,5306,9162,5421,5427,5262,8660,8759,9165,5346,8280);

UPDATE `creature_template` SET `skinloot` = 60098 WHERE `entry` IN
(6581,5291,5349,6507,9318,8675,731,2659,8760,9683,6506,6508,5274,6505,6375,6378,9166,5990,5992,10990,22726,31921,6377,5306,9162,5421,5427,5262,8660,8759,9165,5346,8280);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60098);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60098,4304,0,77,0,1,1,1,1,'Thick Leather'),
(60098,8170,0,20,0,1,1,1,1,'Rugged Leather'),
(60098,8169,0,3,0,1,1,1,1,'Thick Hide');

--
DELETE FROM `skinning_loot_template` WHERE `Entry` IN
(13596,8438,8927,8928,5225,8336,8095,13323,7273,5226,8120,12207);

UPDATE `creature_template` SET `skinloot` = 60099 WHERE `entry` IN
(13596,8438,8927,8928,5225,8336,8095,13323,7273,5226,8120,12207);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60099);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60099,4304,0,70,0,1,1,1,2,'Thick Leather'),
(60099,8170,0,25,0,1,1,1,2,'Rugged Leather'),
(60099,8169,0,5,0,1,1,1,1,'Thick Hide');

--
DELETE FROM `skinning_loot_template` WHERE `Entry` IN
(6140,9622,6503,10197,6379,6380,6513,8761,6516,8600,9163,9167,14502,5993,6349,5991,6502,8596,8601,6514,6010,9164,8597,6348,6501,6347,6585,6504,8300);

UPDATE `creature_template` SET `skinloot` = 60100 WHERE `entry` IN
(6140,9622,6503,10197,6379,6380,6513,8761,6516,8600,9163,9167,14502,5993,6349,5991,6502,8596,8601,6514,6010,9164,8597,6348,6501,6347,6585,6504,8300);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60100);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60100,8170,0,50,0,1,1,1,1,'Rugged Leather'),
(60100,4304,0,43,0,1,1,1,1,'Thick Leather'),
(60100,8171,0,4,0,1,1,1,1,'Rugged Hide'),
(60100,8169,0,3,0,1,1,1,1,'Thick Hide');

--
DELETE FROM `skinning_loot_template` WHERE `Entry` IN
(5708,9029);

UPDATE `creature_template` SET `skinloot` = 60101 WHERE `entry` IN
(5708,9029);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60101);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60101,8170,0,50,0,1,1,1,2,'Rugged Leather'),
(60101,4304,0,43,0,1,1,1,2,'Thick Leather'),
(60101,8171,0,4,0,1,1,1,1,'Rugged Hide'),
(60101,8169,0,3,0,1,1,1,1,'Thick Hide');

--
DELETE FROM `skinning_loot_template` WHERE `Entry` IN
(2521,2522);

UPDATE `creature_template` SET `skinloot` = 60102 WHERE `entry` IN
(2521,2522);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60102);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60102,4304,0,65,0,1,1,1,1,'Thick Leather'),
(60102,4234,0,20,0,1,1,1,1,'Heavy Leather'),
(60102,8170,0,10,0,1,1,1,1,'Rugged Leather'),
(60102,8169,0,4,0,1,1,1,1,'Thick Hide'),
(60102,4235,0,1,0,1,1,1,1,'Heavy Hide');

--
DELETE FROM `skinning_loot_template` WHERE `Entry` IN
(5833);

UPDATE `creature_template` SET `skinloot` = 60103 WHERE `entry` IN
(5833);
-- Guessed values, from above, the only difference is count
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60103);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60103,4304,0,65,0,1,1,1,2,'Thick Leather'),
(60103,4234,0,20,0,1,1,1,1,'Heavy Leather'),
(60103,8170,0,10,0,1,1,1,2,'Rugged Leather'),
(60103,8169,0,4,0,1,1,1,1,'Thick Hide'),
(60103,4235,0,1,0,1,1,1,1,'Heavy Hide');

--
DELETE FROM `skinning_loot_template` WHERE `Entry` IN
(1559);

UPDATE `creature_template` SET `skinloot` = 60104 WHERE `entry` IN
(1559);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60104);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60104,4304,0,50,0,1,1,1,2,'Thick Leather'),
(60104,4234,0,30,0,1,1,1,1,'Heavy Leather'),
(60104,8170,0,12,0,1,1,1,2,'Rugged Leather'),
(60104,8169,0,4,0,1,1,1,1,'Thick Hide'),
(60104,4235,0,3,0,1,1,1,1,'Heavy Hide'),
(60104,8171,0,1,0,1,1,1,1,'Rugged Hide');

--
-- Fix errors
UPDATE `creature_template` SET `skinloot` = 0 WHERE `entry` IN (11871); -- Is it really skinnable?
-- Comments say it's not required to have Cenarion Beacon in inventory to loot Patch of Tainted Skin
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 11 AND `SourceEntry` = 11512;

--
-- Not skinnable
UPDATE `creature_template` SET `skinloot` = 0 WHERE `entry` IN (14750);
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (14750);

--
DELETE FROM `skinning_loot_template` WHERE `Entry` IN
(11673,11982);

UPDATE `creature_template` SET `skinloot` = 60105 WHERE `entry` IN
(11673,11982);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60105);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60105,17012,0,100,0,1,1,1,1,'Core Leather');

--
DELETE FROM `skinning_loot_template` WHERE `Entry` IN
(10184);

UPDATE `creature_template` SET `skinloot` = 60106 WHERE `entry` IN
(10184,36538);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60106);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60106,15410,0,100,0,1,1,2,4,'Scale of Onyxia');

--
DELETE FROM `skinning_loot_template` WHERE `Entry` IN
(3674);

UPDATE `creature_template` SET `skinloot` = 60107 WHERE `entry` IN
(3674);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60107);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60107,2319,0,100,0,1,0,3,5,'Medium Leather'),
(60107,4232,0,50,0,1,0,1,1,'Medium Hide');

--
DELETE FROM `skinning_loot_template` WHERE `Entry` IN
(4539);

UPDATE `creature_template` SET `skinloot` = 60108 WHERE `entry` IN
(4539);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60108);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60108,2319,0,60,0,1,1,1,2,'Medium Leather'),
(60108,4234,0,30,0,1,1,1,2,'Heavy Leather'),
(60108,4232,0,7,0,1,1,1,1,'Medium Hide'),
(60108,4235,0,3,0,1,1,1,1,'Heavy Hide');

-- Zulian Stalker, Zulian Guardian, Zulian Prowler
-- No info, removing
DELETE FROM `skinning_loot_template` WHERE `Entry` IN
(10257);

UPDATE `creature_template` SET `skinloot` = 0 WHERE `entry` IN
(15067,15068,15101);

-- Swiftmane
UPDATE `creature_template` SET `skinloot` = 60081 WHERE `entry` IN (5831);
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (5831);

-- Azzere the Skyblade
UPDATE `creature_template` SET `skinloot` = 60082 WHERE `entry` IN (5834);
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (5834);

-- Halycon & Gizrul the Slavener
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (10220,10268);

UPDATE `creature_template` SET `skinloot` = 60110 WHERE `entry` IN (10220,10268);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60110);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60110,8170,0,90,0,1,1,3,5,'Rugged Leather'),
(60110,8171,0,10,0,1,1,1,1,'Rugged Hide');

-- The Beast
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (10430);

UPDATE `creature_template` SET `skinloot` = 60111 WHERE `entry` IN (10430);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60111);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60111,8170,0,82,0,1,1,4,6,'Rugged Leather'),
(60111,8171,0,15,0,1,1,1,2,'Rugged Hide'),
(60111,12731,0,3,0,1,1,1,1,'Pristine Hide of the Beast');

-- Soulflayer & Chimaerok Devourer
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (11359,12802);

UPDATE `creature_template` SET `skinloot` = 60112 WHERE `entry` IN (11359,12802);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60112);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60112,8170,0,95,0,1,1,1,3,'Rugged Leather'),
(60112,8171,0,5,0,1,1,1,1,'Rugged Hide');

-- A couple more
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (11496,15554);

UPDATE `creature_template` SET `skinloot` = 60113 WHERE `entry` IN (11496,15554);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60113);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60113,8170,0,97,0,1,1,1,1,'Rugged Leather'),
(60113,8171,0,3,0,1,1,1,1,'Rugged Hide');

-- No data at all \ good data for 1984, 1985, 3098, 3124, 16095 but skinnable

--
--
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (100007,100006,100004,100003,100005);

UPDATE `creature_template` SET `skinloot` = 60098 WHERE `entry` = 5347;
UPDATE `creature_template` SET `skinloot` = 60098 WHERE `entry` = 6648;
UPDATE `creature_template` SET `skinloot` = 60098 WHERE `entry` = 8302;
UPDATE `creature_template` SET `skinloot` = 60098 WHERE `entry` = 8303;
UPDATE `creature_template` SET `skinloot` = 60098 WHERE `entry` = 14344;
UPDATE `creature_template` SET `skinloot` = 60098 WHERE `entry` = 3581;
UPDATE `creature_template` SET `skinloot` = 60081 WHERE `entry` = 14357;
UPDATE `creature_template` SET `skinloot` = 60079 WHERE `entry` = 2188; -- Guessed, from 1224
UPDATE `creature_template` SET `skinloot` = 60112 WHERE `entry` = 12803;
UPDATE `creature_template` SET `skinloot` = 0     WHERE `entry` = 4950; -- Easier to remove it completely, no data at all
UPDATE `creature_template` SET `skinloot` = 0     WHERE `entry` = 14237; -- Easier to remove it completely, no data at all
UPDATE `creature_template` SET `skinloot` = 60082 WHERE `entry` = 10644;
UPDATE `creature_template` SET `skinloot` = 60096 WHERE `entry` = 6583;
UPDATE `creature_template` SET `skinloot` = 60054 WHERE `entry` = 14280;
UPDATE `creature_template` SET `skinloot` = 60081 WHERE `entry` IN (335,5828);
UPDATE `creature_template` SET `skinloot` = 60082 WHERE `entry` IN (628,819,1015,1016,1021,1022,1400,1417,2275,3249,3810,4014,4016,4031,4250);
