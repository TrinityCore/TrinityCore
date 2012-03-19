-- Remove old script text for npc_torek
DELETE FROM `script_texts` WHERE `entry` IN (-1000106, -1000110);

-- Add creature texts for Torek
DELETE FROM `creature_text` WHERE `entry`=12858;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(12858, 0, 0, 'Everyone ready?', 12, 0, 100, 0, 0, 0, 'Torek'),
(12858, 1, 0, 'Ok, Lets move out!', 12, 0, 100, 0, 0, 0, 'Torek'),
(12858, 2, 0, 'Prepare yourselves. Silverwing is just around the bend.', 12, 0, 100, 0, 0, 0, 'Torek'),
(12858, 3, 0, 'Silverwing is ours!', 12, 0, 100, 0, 0, 0, 'Torek'),
(12858, 4, 0, 'Go report that the outpost is taken. We will remain here.', 12, 0, 100, 0, 0, 0, 'Torek');
