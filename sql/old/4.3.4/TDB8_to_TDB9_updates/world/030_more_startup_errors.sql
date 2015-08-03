UPDATE `creature_template` SET `lootid`=0 WHERE `lootid` IN (448,639,39946,33021,39948,39947,32860,32935,33009,33020,33022,33905,48518);

DELETE FROM `creature_loot_template` WHERE `entry`=51726 AND `item` IN (62785,67510,67511);
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(51726,62785,25,1,0,1,1),
(51726,67510,80,1,0,1,1),
(51726,67511,20,1,0,1,1);

DELETE FROM `pet_levelstats` WHERE `creature_entry`=1 AND `level` BETWEEN 81 AND 85;
INSERT INTO `pet_levelstats` (`creature_entry`,`level`,`hp`,`mana`,`armor`,`str`,`agi`,`sta`,`inte`,`spi`) VALUES
(1,81,1,1,1,1,1,1,1,1),
(1,82,1,1,1,1,1,1,1,1),
(1,83,1,1,1,1,1,1,1,1),
(1,84,1,1,1,1,1,1,1,1),
(1,85,1,1,1,1,1,1,1,1);

UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=102760 WHERE `entryorguid`=15664 AND `id`=1;
UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=42404, `action_param2`=0, `action_param3`=0 WHERE `entryorguid`=23777 AND `id`=4;
UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=88818 WHERE `entryorguid`=47707 AND `id`=1;
UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=89165 WHERE `entryorguid`=47930 AND `id`=1;
UPDATE `smart_scripts` SET `id`=0, `action_type`=11, `action_param1`=89193, `comment`= 'Arcane Guest Registry - OOC - Cast Killcredit spell' WHERE `entryorguid`=49528;
UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=39812 WHERE `entryorguid`=2297900 AND `id`=2;
