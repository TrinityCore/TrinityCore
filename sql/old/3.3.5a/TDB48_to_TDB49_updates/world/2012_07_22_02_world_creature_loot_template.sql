-- Item was added to the wrong NPC
-- Source: http://old.wowhead.com/item=19364
DELETE FROM `creature_loot_template` WHERE `entry` IN (1853, 11583) AND `item`=19364;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(11583, 19364, 10, 1, 0, 1, 1);
