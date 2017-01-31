--
DELETE FROM `creature_text` WHERE `entry` = 10262 AND id IN (6,7);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextID`) VALUES
(10262,0,6, 'Bijou lost! SQUAWK! *cough',12,0,100,0,0,0, 'Opus - Random Say',5541),
(10262,0,7, 'Dragons controlling orcs!? SQUAWK!',12,0,100,0,0,0, 'Opus - Random Say',5546);
