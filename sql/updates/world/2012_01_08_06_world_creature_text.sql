-- Remove old script text for boss_balinda.cpp "Not sure if the text actually exist"
DELETE FROM `script_texts` WHERE `entry` IN (-1810023,-1810024);
-- Add new creature_text for Captain Balinda Stonehearth <Stormpike Captain>
DELETE FROM `creature_text` WHERE `entry` IN (11949);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
-- Aggro
(11949,0,0, 'Begone, uncouth scum! The Alliance shall prevail in Alterac Valley!',14,0,100,0,0,0, 'Captain Balinda Stonehearth'),
-- Reset
(11949,1,0, 'Filthy Frostwolf cowards! If you want a fight, you''ll have to come to me!',14,0,100,0,0,0, 'Captain Balinda Stonehearth'),
-- (Alliance players receives Stormpike's Salvation buff (+20% health points for 2 minutes))
(11949,2,0, 'Take heart, Alliance! Throw these villains from Alterac Valley!',14,0,100,0,0,0, 'Captain Balinda Stonehearth');
