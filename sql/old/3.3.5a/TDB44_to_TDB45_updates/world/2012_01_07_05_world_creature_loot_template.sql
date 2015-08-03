-- correct id for firelord
DELETE FROM `creature_loot_template` WHERE `entry` IN (12231,11668) AND `item`=20951;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(11668,20951,-100,1,0,1,1); -- Firelord
