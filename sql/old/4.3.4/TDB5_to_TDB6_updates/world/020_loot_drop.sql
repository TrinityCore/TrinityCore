-- Thick Hydra Scale has Guaranteed drop chance from Fenclaw Thrasher (18214) and Mragesh (18286), High from Parched Hydra (20324)
-- http://eu.battle.net/wow/en/item/24375
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=-100 WHERE `entry`=18214 and `item`=24375;
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=-75 WHERE `entry`=20324 and `item`=24375;
DELETE FROM `creature_loot_template` WHERE `entry`=18286 and `item`=24375;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(18286,24375,-100,1,0,1,1);
