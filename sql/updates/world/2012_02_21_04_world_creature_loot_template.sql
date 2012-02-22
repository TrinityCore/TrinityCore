SET @ENTRY := 30409; -- Apprentice Osterkilgr
DELETE FROM `creature_loot_template` WHERE entry=@ENTRY;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- Quest related Items
(@ENTRY,43089,-100,1,0,1,1), -- Vrykul Bones
(@ENTRY,42772,-100,1,0,1,1), -- Dr Terrible's "Building a Better Flesh Giant"
(@ENTRY,42422,-50,1,0,1,1), -- Jotunheim Cage Key
-- Other random stuff
(@ENTRY,33470,20,1,0,1,4), -- Frostweave Cloth
(@ENTRY,43851,20,1,0,1,1), -- Fur Clothing Scraps
(@ENTRY,43852,20,1,0,1,1), -- Thick Fur Clothing Scraps
-- References for world drops
(@ENTRY,1,10,1,0,-35063,1), -- Northrend Grey Items
(@ENTRY,2,5,1,0,-35066,1), -- Northrend Green Items
-- hatebook
(@ENTRY,45912,0.1,1,0,1,1); -- Book Glyph of Mastery (honestly screw that thing)
