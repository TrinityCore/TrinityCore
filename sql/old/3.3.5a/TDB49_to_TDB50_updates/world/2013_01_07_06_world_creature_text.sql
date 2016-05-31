-- Texts for Ayamiss the Hunter
DELETE FROM `creature_text` WHERE `entry`= 15369;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(15369,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'Ayamiss the Hunter Frenzy Emote');
