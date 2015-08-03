-- Add loot table for Ahune <The Frost Lord>.
CALL `sp_get_go_lootid`(187892,@ENTRY);
-- Add loot table for Ahune <The Frost Lord>.
DELETE FROM `gameobject_loot_template` WHERE `entry`= @ENTRY;
INSERT INTO `gameobject_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(@ENTRY,35557,28,1,0,1,2), -- Huge Snowball
(@ENTRY,35723,12,1,0,1,1), -- Shards of Ahune
(@ENTRY,35498,3 ,1,0,1,1), -- Formula: Enchant Weapon - Deathfrost
(@ENTRY,35720,3 ,1,0,5,6), -- Lord of Frost's Private Label
-- CLOAKS
(@ENTRY,54805,0,1,1,1,1), -- Cloak of the Frigid Winds
(@ENTRY,54804,0,1,1,1,1), -- Shroud of Winter's Chill
(@ENTRY,54803,0,1,1,1,1), -- The Frost Lord's Battle Shroud
(@ENTRY,54802,0,1,1,1,1), -- The Frost Lord's War Cloak
(@ENTRY,54801,0,1,1,1,1); -- Icebound Cloak
