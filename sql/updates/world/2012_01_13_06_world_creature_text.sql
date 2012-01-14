-- Remove old script text for npc_torek
DELETE FROM `script_texts` WHERE `entry` IN (-1000106, -1000110);

-- Add creature texts for Torek
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(12858, 0, 0, 'Everyone ready?', 0, 0, 100, 0, 0, 0, 'Torek'),
(12858, 1, 0, 'Ok, Lets move out!', 0, 0, 100, 0, 0, 0, 'Torek'),
(12858, 2, 0, 'Prepare yourselves. Silverwing is just around the bend.', 0, 0, 100, 0, 0, 0, 'Torek'),
(12858, 3, 0, 'Silverwing is ours!', 0, 0, 100, 0, 0, 0, 'Torek'),
(12858, 4, 0, 'Go report that the outpost is taken. We will remain here.', 0, 0, 100, 0, 0, 0, 'Torek');
