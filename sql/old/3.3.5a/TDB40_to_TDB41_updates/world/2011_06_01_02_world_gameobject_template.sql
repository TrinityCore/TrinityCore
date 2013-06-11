-- Set proper flags for Flame of Imbel, Flame of Lahassa, Flame of Samha and Flame of Byltan
UPDATE `gameobject_template` SET `flags`=`flags`&~4 WHERE `entry` IN (142185,142187,142186,142188);
-- Set loot template for the gameobjects above
DELETE FROM `gameobject_loot_template` WHERE `entry` IN (6711,6709,6708,6710);
INSERT INTO `gameobject_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(6711,9258,100,1,0,1,1),
(6709,9256,100,1,0,1,1),
(6708,9255,100,1,0,1,1),
(6710,9257,100,1,0,1,1);
