-- NPC talk text from sniff
DELETE FROM `creature_text` WHERE `entry`=7604;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(7604,0,0, 'What?  How dare you say that to me?!?',12,0,100,6,0,0, 'Sergeant Bly'),
(7604,1,0, 'After all we''ve been through?  Well, I didn''t like you anyway!!',12,0,100,5,0,0, 'Sergeant Bly');
-- Remove old text
DELETE FROM `script_texts` WHERE `entry` IN (-1209002,-1209003);
