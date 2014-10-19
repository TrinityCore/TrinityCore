-- Gnoll Paw has High drop rate (exception Sergeant Brashclaw who has Guaranteed)
-- http://eu.battle.net/wow/en/item/725
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=-75 WHERE `entry` IN (98,117,123,124,125,452,453,500,501,1065,1426) and `item`=725;
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=-100 WHERE `entry`=506 and `item`=725;
DELETE FROM `creature_loot_template` WHERE `entry` IN (54371,54372,54373) and `item`=725;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(54371,725,-75,1,0,1,1), -- Riverpaw Bandit (4.2.0 Spawn)
(54372,725,-75,1,0,1,1), -- Riverpaw Brute (4.2.0 Spawn)
(54373,725,-75,1,0,1,1); -- Riverpaw Herbalist (4.2.0 Spawn)
UPDATE `creature_template` SET `lootid`=54371 WHERE `entry`=54371;
UPDATE `creature_template` SET `lootid`=54372 WHERE `entry`=54372;
UPDATE `creature_template` SET `lootid`=54373 WHERE `entry`=54373;
