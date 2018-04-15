-- NPC talk text for Apprentice Mirveda
DELETE FROM `creature_text` WHERE `entry`=15402;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(15402,0,0, 'Such... dark... energy!  How can this be possible?',12,0,100,0,0,0, 'Apprentice Mirveda');
