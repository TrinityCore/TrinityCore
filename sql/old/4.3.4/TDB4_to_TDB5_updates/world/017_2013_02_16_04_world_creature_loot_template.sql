-- Remove Zulian Mudskunk from Zulian Crocolisk's loot template
DELETE FROM `creature_loot_template` WHERE `entry`=15043 and `item`=19975;
-- Add Vicious Oil (Item) into loot template of Vicious Oil (NPC)
DELETE FROM `creature_loot_template` WHERE `entry`=30325 and `item`=42640;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) values
(30325,42640,-100,1,0,1,1);
