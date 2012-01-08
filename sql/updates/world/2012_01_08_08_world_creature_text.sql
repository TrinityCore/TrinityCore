-- Remove old script text for boss_drekthar.cpp "Not sure if the text actually exist"
DELETE FROM `script_texts` WHERE `entry` IN (-1810000,-1810001,-1810002,-1810003,-1810004,-1810005,-1810006,-1810007);
-- Add new creature_text for Drek'Thar
DELETE FROM `creature_text` WHERE `entry` IN (11946);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
-- Aggro
(11946,0,0, 'Stormpike filth! In my keep?! Slay them all!',14,0,100,0,0,0, 'Drek''Thar'),
-- Reset
(11946,1,0, 'You seek to draw the General of the Frostwolf legion out from his fortress? PREPOSTEROUS!',14,0,100,0,0,0, 'Drek''Thar'),
-- Raid wipe
(11946,2,0, 'Stormpike weaklings, face me in my fortress - if you dare!',14,0,100,0,0,0, 'Drek''Thar'),
-- Combat
(11946,3,0, 'Your attacks are slowed by the cold, I think!',14,0,100,0,0,0, 'Drek''Thar'),
(11946,3,1, 'Today, you will meet your ancestors!',14,0,100,0,0,0, 'Drek''Thar'),
(11946,3,2, 'If you will not leave Alterac Valley on your own, then the Frostwolves will force you out!',14,0,100,0,0,0, 'Drek''Thar'),
(11946,3,3, 'You cannot defeat the Frostwolf clan!',14,0,100,0,0,0, 'Drek''Thar'),
(11946,3,4, 'You are no match for the strength of the Horde!',14,0,100,0,0,0, 'Drek''Thar');
