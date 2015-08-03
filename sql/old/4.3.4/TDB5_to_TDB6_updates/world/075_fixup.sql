-- Azshara's Veil - Creates the loot
DELETE FROM `gameobject_loot_template` WHERE `entry` = 28523 AND `item` IN (52985, 52329, 63122);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(28523, 52985, 100, 1, 0, 1, 9),
(28523, 52329, 39, 1, 0, 1, 4),
(28523, 63122, 10, 1, 0, 1, 1);

-- Fel Moss (3297) has Guaranteed drop rate
-- Nightsaber Fang (3409) and Strigid Owl Feather (3409) have Very High drop rate
-- http://eu.battle.net/wow/en/item/3297
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=-100 WHERE `entry` IN (1988,1989) and `item`=3297;
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=-90 WHERE `entry`IN (2033,2034,2042,2043,14430) and `item`=3409;
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=-90 WHERE `entry` IN (1995,1996,1997) and `item`=3411;

-- There is no proof that Leper Gnomes have Restabilization Cog (3083) and/or Gyromechanic Gear (3084) in their loot template
-- http://eu.battle.net/wow/en/item/3083 / http://eu.battle.net/wow/en/item/3084 / http://www.wowhead.com/npc=1211
DELETE FROM `creature_loot_template` WHERE `entry`=1211 and`item` IN (3083,3084);
