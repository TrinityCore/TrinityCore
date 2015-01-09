-- Insert quest item "Twilight Snare" into the loot template of Twilight Dragonstalker and Scalesworn Cultist
-- Quest Chance: High - http://eu.battle.net/wow/en/item/60383
DELETE FROM `creature_loot_template` WHERE `entry` IN (43992, 44221) AND `item`=60383;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(43992,60383,-75,1,0,1,1), -- Twilight Dragonstalker
(44221,60383,-75,1,0,1,1); -- Scalesworn Cultist
