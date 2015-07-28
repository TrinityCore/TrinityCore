-- Quest: Demonic Thieves
DELETE FROM `gameobject_loot_template` WHERE `entry`=27260;
INSERT INTO `gameobject_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(27260,46700,100,1,0,1,1); -- Melithar's Stolen Bags
