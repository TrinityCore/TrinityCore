-- Add loot table for Ahune <The Frost Lord>.
SET @REFERENCE := 34349;
CALL`sp_get_ref_id` ('RAID_CRE',@REFERENCE);
CALL `sp_get_go_lootid`(187892,@ENTRY);

DELETE FROM `reference_loot_template` WHERE `entry` = @ENTRY;
INSERT INTO `reference_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- Cloaks.
(@REFERENCE,54805,0,0,1,1,1), -- Cloak of the Frigid Winds
(@REFERENCE,54804,0,0,1,1,1), -- Shroud of Winter's Chill
(@REFERENCE,54803,0,0,1,1,1), -- The Frost Lord's Battle Shroud
(@REFERENCE,54802,0,0,1,1,1), -- The Frost Lord's War Cloak
(@REFERENCE,54801,0,0,1,1,1); -- Icebound Cloak

-- Add loot table for Ahune <The Frost Lord>.
DELETE FROM `gameobject_loot_template` WHERE `entry`= @ENTRY;
INSERT INTO `gameobject_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(@ENTRY,1,100,0,1,-@REFERENCE,1), -- Reference
(@ENTRY,35557,28,0,2,1,2), -- Huge Snowball
(@ENTRY,35723,12,0,3,1,1), -- Shards of Ahune
(@ENTRY,35498,3,0,4,1,1), -- Formula: Enchant Weapon - Deathfrost
(@ENTRY,35720,3,0,5,5,6); -- Lord of Frost's Private Label
