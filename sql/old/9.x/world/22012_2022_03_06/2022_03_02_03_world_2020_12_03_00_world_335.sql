-- All with Heavy Scorpid Scale
UPDATE `creature_template` SET `skinloot` = 60003 WHERE `entry` IN (8301);
UPDATE `creature_template` SET `skinloot` = 60004 WHERE `entry` IN (9691,9695);
UPDATE `creature_template` SET `skinloot` = 60005 WHERE `entry` IN (14476,9698,9701,11735,11736,11737,15196);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (8301,9691,9695,9698,9701,11735,11736,11737,15196,60003,60004,60005);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60003,4304,0,10,0,1,1,1,1,"Thick Leather"),
(60003,8154,0,20,0,1,1,1,2,"Scorpid Scale"),
(60003,8170,0,37,0,1,1,1,1,"Rugged Leather"),
(60003,8171,0,3,0,1,1,1,1,"Rugged Hide"),
(60003,15408,0,30,0,1,1,1,1,"Heavy Scorpid Scale"),
(60004,4304,0,10,0,1,1,1,1,"Thick Leather"),
(60004,8154,0,20,0,1,1,1,2,"Scorpid Scale"),
(60004,8169,0,2,0,1,1,1,1,"Thick Hide"),
(60004,8170,0,35,0,1,1,1,1,"Rugged Leather"),
(60004,8171,0,3,0,1,1,1,1,"Rugged Hide"),
(60004,15408,0,30,0,1,1,1,1,"Heavy Scorpid Scale"),
(60005,4304,0,10,0,1,1,1,1,"Thick Leather"),
(60005,8169,0,5,0,1,1,1,1,"Thick Hide"),
(60005,8170,0,45,0,1,1,1,1,"Rugged Leather"),
(60005,15408,0,40,0,1,1,1,2,"Heavy Scorpid Scale");

-- All with Devilsaur Leather
UPDATE `creature_template` SET `skinloot` = 60006 WHERE `entry` IN (6498,6499,6500,6584);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (6498,6499,6500,6584,60006);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60006,15417,0,100,0,1,1,1,1,"Devilsaur Leather");

-- All with Black Dragonscale
UPDATE `creature_template` SET `skinloot` = 60007 WHERE `entry` IN (7040,7041,7044,7045,9461);
UPDATE `creature_template` SET `skinloot` = 60008 WHERE `entry` IN (7047,7048,7049);
UPDATE `creature_template` SET `skinloot` = 60009 WHERE `entry` IN (7042,7043,7046);
UPDATE `creature_template` SET `skinloot` = 60010 WHERE `entry` IN (8976,7846,9096,9568,10083,10258,10264,10321,10363,10366,10371,10372,10683,12739);
UPDATE `creature_template` SET `skinloot` = 60011 WHERE `entry` IN (10442);
UPDATE `creature_template` SET `skinloot` = 60012 WHERE `entry` IN (10447,10814);
UPDATE `creature_template` SET `skinloot` = 60013 WHERE `entry` IN (10339);
UPDATE `creature_template` SET `skinloot` = 60014 WHERE `entry` IN (11983,14601,11981);
UPDATE `creature_template` SET `skinloot` = 60015 WHERE `entry` IN (11583);
UPDATE `creature_template` SET `skinloot` = 60016 WHERE `entry` IN (12460,12461,12463,12464,12465,12467,12468);
UPDATE `creature_template` SET `skinloot` = 60017 WHERE `entry` IN (14020);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (
7040,7041,7044,7045,9461,60007,
7047,7048,7049,60008,
7042,7043,7046,60009,
8976,7846,9096,9568,10083,10258,10264,10321,10363,10366,10371,10372,10683,12739,60010,
10442,60011,
10447,10814,60012,
10339,60013,
11983,14601,11981,60014,
11583,60015,
12460,12461,12463,12464,12465,12467,12468,60016,
14020,60017,
15416);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
-- Changed at some point
(60007,4304,0,33,0,1,1,1,2,"Thick Leather"), -- 25 > 32 or 33
(60007,8165,0,8,0,1,1,1,1,"Worn Dragonscale"), -- 10 > 8 or 7
(60007,8169,0,3,0,1,1,1,1,"Thick Hide"), -- 3 - 3
(60007,8170,0,43,0,1,1,1,2,"Rugged Leather"), -- 43 - 43
(60007,8171,0,4,0,1,1,1,1,"Rugged Hide"), -- 4 - 4
(60007,15416,0,9,0,1,1,1,1,"Black Dragonscale"), -- 15 > 9 or 10
(60008,4304,0,40,0,1,1,1,1,"Thick Leather"),
(60008,8165,0,5,0,1,1,1,1,"Worn Dragonscale"),
(60008,8169,0,3,0,1,1,1,1,"Thick Hide"),
(60008,8170,0,45,0,1,1,1,1,"Rugged Leather"),
(60008,8171,0,4,0,1,1,1,1,"Rugged Hide"),
(60008,15416,0,3,0,1,1,1,1,"Black Dragonscale"),
(60009,4304,0,8,0,1,1,1,2,"Thick Leather"), -- 5 > 8
(60009,8165,0,7,0,1,1,1,1,"Worn Dragonscale"), -- 10 > 7
(60009,8170,0,68,0,1,1,1,2,"Rugged Leather"), -- ~55 > 68
(60009,8171,0,5,0,1,1,1,1,"Rugged Hide"), -- 5 - 5
(60009,15416,0,12,0,1,1,1,1,"Black Dragonscale"), -- ~25 > 12
(60010,4304,0,5,0,1,1,1,2,"Thick Leather"),
(60010,8165,0,10,0,1,1,1,1,"Worn Dragonscale"),
(60010,8170,0,55,0,1,1,1,2,"Rugged Leather"),
(60010,8171,0,5,0,1,1,1,1,"Rugged Hide"),
(60010,15416,0,25,0,1,1,1,1,"Black Dragonscale"),
(60011,4304,0,10,0,1,1,1,1,"Thick Leather"),
(60011,8170,0,73,0,1,1,1,2,"Rugged Leather"),
(60011,8171,0,5,0,1,1,1,1,"Rugged Hide"),
(60011,15412,0,3,0,1,1,1,1,"Green Dragonscale"),
(60011,15414,0,3,0,1,1,1,1,"Red Dragonscale"),
(60011,15415,0,3,0,1,1,1,1,"Blue Dragonscale"),
(60011,15416,0,3,0,1,1,1,1,"Black Dragonscale"),
(60012,4304,0,5,0,1,1,1,2,"Thick Leather"),
(60012,8165,0,7,0,1,1,1,1,"Worn Dragonscale"),
(60012,8170,0,55,0,1,1,1,2,"Rugged Leather"),
(60012,8171,0,5,0,1,1,1,1,"Rugged Hide"),
(60012,15412,0,7,0,1,1,1,1,"Green Dragonscale"),
(60012,15414,0,7,0,1,1,1,1,"Red Dragonscale"),
(60012,15415,0,7,0,1,1,1,1,"Blue Dragonscale"),
(60012,15416,0,7,0,1,1,1,1,"Black Dragonscale"),
(60013,8170,0,100,0,1,0,2,3,"Rugged Leather"),
(60013,15412,0,100,0,1,0,1,3,"Green Dragonscale"),
(60013,15414,0,100,0,1,0,1,3,"Red Dragonscale"),
(60013,15415,0,100,0,1,0,1,3,"Blue Dragonscale"),
(60013,15416,0,100,0,1,0,1,3,"Black Dragonscale"),
(60014,15416,0,100,0,1,1,2,4,"Black Dragonscale"),
(60015,15416,0,100,0,1,1,5,8,"Black Dragonscale"),
(60016,8170,0,60,0,1,1,1,2,"Rugged Leather"),
(60016,8171,0,5,0,1,1,1,1,"Rugged Hide"),
(60016,15416,0,35,0,1,1,1,1,"Black Dragonscale"),
(60017,12607,0,100,0,1,0,1,1,"Brilliant Chromatic Scale"),
(60017,15412,0,50,0,1,0,1,3,"Green Dragonscale"),
(60017,15414,0,50,0,1,0,1,3,"Red Dragonscale"),
(60017,15415,0,50,0,1,0,1,3,"Blue Dragonscale"),
(60017,15416,0,50,0,1,0,1,3,"Black Dragonscale");

-- All with Shiny Fish Scales
UPDATE `creature_template` SET `skinloot` = 60018 WHERE `entry` IN (905,1193,2173,2174,6033,8236,14490);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (905,1193,2173,2174,6033,8236,60018);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60018,17057,0,100,0,1,1,1,1,"Shiny Fish Scales");

-- All with Rage Scar Yeti Hide
UPDATE `creature_template` SET `skinloot` = 60019 WHERE `entry` IN (5296,5297,5299,7848);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (5296,5297,5299,7848,60019);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60019,4304,0,77,0,1,1,1,1,"Thick Leather"),
(60019,8169,0,3,0,1,1,1,1,"Thick Hide"),
(60019,8170,0,20,0,1,1,1,1,"Rugged Leather"),
(60019,18947,0,80,1,1,0,1,1,"Rage Scar Yeti Hide");

-- All with Frostsaber Leather
-- Patch 3.1.0 (2009-04-14): This item is now of poor quality and no longer used for anything.
-- And the chance was slightly lowered, this means we can't get close values because WotLK has to
-- last 5 years to align all chances (yes, wowhead didn't wiped old data after WotLK came out)
UPDATE `creature_template` SET `skinloot` = 60020 WHERE `entry` IN (7430);
UPDATE `creature_template` SET `skinloot` = 60021 WHERE `entry` IN (7431,7432,7433,7434);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (7430,7431,7432,7433,7434,60020,60021);
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60020,4304,0,35,0,1,1,1,1,"Thick Leather"),
(60020,8169,0,3,0,1,1,1,1,"Thick Hide"),
(60020,8170,0,43,0,1,1,1,1,"Rugged Leather"),
(60020,8171,0,4,0,1,1,1,1,"Rugged Hide"),
(60020,15422,0,15,0,1,1,1,1,"Frostsaber Leather"),
-- Pretty sure they're not entirely correct
(60021,4304,0,12,0,1,1,1,1,"Thick Leather"), -- 10
(60021,8170,0,57,0,1,1,1,1,"Rugged Leather"), -- 50
(60021,8171,0,6,0,1,1,1,1,"Rugged Hide"), -- 5
(60021,15422,0,25,0,1,1,1,1,"Frostsaber Leather"); -- 35
