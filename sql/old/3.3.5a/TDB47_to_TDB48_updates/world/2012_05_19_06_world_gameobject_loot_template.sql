DELETE FROM `reference_loot_template` WHERE `entry`=34172;
DELETE FROM `creature_loot_template` WHERE `entry`=38013;
DELETE FROM `gameobject_loot_template` WHERE `entry`=28683;
INSERT INTO `gameobject_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(28683,35498,3,1,0,1,1), -- Formula: Enchant Weapon - Deathfrost
(28683,35557,28,1,0,1,2), -- Huge Snowball
(28683,35720,3,1,0,5,6), -- Lord of Frost's Private Label
(28683,35723,12,1,0,1,1), -- Shards of Ahune
(28683,54801,0,1,1,1,1), -- Icebound Cloak
(28683,54802,0,1,1,1,1), -- The Frost Lord's War Cloak
(28683,54803,0,1,1,1,1), -- The Frost Lord's Battle Shroud
(28683,54804,0,1,1,1,1), -- Shroud of Winter's Chill
(28683,54805,0,1,1,1,1); -- Cloak of the Frigid Winds
