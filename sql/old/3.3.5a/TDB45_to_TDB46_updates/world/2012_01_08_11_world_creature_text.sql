-- Remove old script text for eversong_woods.cpp
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000640 AND -1000637;
-- Master Kelerun Bloodmourn <Blood Knight> say text
DELETE FROM `creature_text` WHERE `entry`=17807;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(17807,0,0, 'Let the trial begin, Bloodwrath, attack!',14,0,100,0,0,0, 'Master Kelerun Bloodmourn'),
(17807,1,0, 'Champion Lightrend, make me proud!',14,0,100,0,0,0, 'Master Kelerun Bloodmourn'),
(17807,2,0, 'Show this upstart how a real Blood Knight fights, Swiftblade!',14,0,100,0,0,0, 'Master Kelerun Bloodmourn'),
(17807,3,0, 'Show $N the meaning of pain, Sunstriker!',14,0,100,0,0,0, 'Master Kelerun Bloodmourn');
