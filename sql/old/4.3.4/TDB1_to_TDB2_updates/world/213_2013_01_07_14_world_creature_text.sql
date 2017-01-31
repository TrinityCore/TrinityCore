-- Texts for Shirrak the Dead Watcher
DELETE FROM `creature_text` WHERE `entry`= 18371;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(18371,0,0, '%s focuses on $n!',41,0,100,0,0,0, 'Shirrak the Dead Watcher - Emote Focus');
