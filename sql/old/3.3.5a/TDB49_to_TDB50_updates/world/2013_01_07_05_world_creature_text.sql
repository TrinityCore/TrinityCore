-- Texts for Archavon the Stone Watcher
DELETE FROM `creature_text` WHERE `entry`= 31125 AND `groupid`=1;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(31125,1,0, 'Archavon the Stone Watcher lunges for $N!',16,0,100,0,0,0, 'Archavon the Stone Watcher Leap Emote');
