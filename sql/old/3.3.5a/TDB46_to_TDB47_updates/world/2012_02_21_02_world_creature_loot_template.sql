UPDATE `creature_template` SET `lootid`=`entry`  WHERE `entry` IN (38032,37917,38016,38023,37214,38030,38006,37984);
DELETE FROM `creature_loot_template` WHERE `entry`IN (38032,37917,38016,38023,37214,38030,38006,37984);
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(38032,1,100,1,0,-45009,1), -- Crown Sprayer
(37917,1,100,1,0,-45009,1), -- Crown Thug
(38016,1,100,1,0,-45009,1), -- Crown Agent
(38023,1,100,1,0,-45009,1), -- Crown Sprinkler
(37214,1,100,1,0,-45009,1), -- Crown Lackey
(38030,1,100,1,0,-45009,1), -- Crown Underling
(38006,1,100,1,0,-45009,1), -- Crown Hoodlum (level 1??)
(37984,1,100,1,0,-45009,1); -- Crown Duster  (level 1??)
