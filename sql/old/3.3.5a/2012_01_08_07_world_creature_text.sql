-- Remove old script text for boss_galvangar.cpp "Not sure if the text actually exist"
DELETE FROM `script_texts` WHERE `entry` IN (-1810021,-1810022);
-- Add new creature_text for Captain Galvangar
DELETE FROM `creature_text` WHERE `entry`=11947;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(11947,0,0, 'Die! Your kind has no place in Alterac Valley!',14,0,100,0,0,0, 'Captain Galvangar'), -- Aggro
(11947,1,0, 'I''ll never fall for that, fool! If you want a battle it will be on my terms and in my lair!',14,0,100,0,0,0, 'Captain Galvangar'), -- Reset
(11947,2,0, 'Now is the time to attack! For the Horde!',14,0,100,0,0,0, 'Captain Galvangar'); -- Casting Fury of the Frostwolf
