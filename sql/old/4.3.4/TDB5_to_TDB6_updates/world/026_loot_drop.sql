-- Gyromechanic Gear has High/Guaranteed drop rate
-- http://eu.battle.net/wow/en/item/3084
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=-75 WHERE `entry`=8503 and `item`=3084; -- Gibblewilt
DELETE FROM `creature_loot_template` WHERE `entry`=41146 and `item`=3084;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(41146,3084,-100,1,0,1,1); -- Frostmane Scavenger
UPDATE `creature_template` SET `lootid`=41146 WHERE `entry`=41146;
