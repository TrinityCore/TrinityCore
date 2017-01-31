-- Lurgglbr
DELETE FROM `creature_text` WHERE `entry`=25208;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES 
(25208,0,0, 'You can''t hold me against my will! You''ve all been brainwashed!', 12,0,100,0,0,0, 'Lurgglbr'),
(25208,1,0, 'Together we will fight our way out of here. Are you ready?', 12,0,100,0,0,0, 'Lurgglbr'),
(25208,2,0, 'This is far enough. I can make it on my own from here.', 12,0,100,0,0,0, 'Lurgglbr'),
(25208,3,0, 'Thank you for rescuing me, $r. Please tell the king that I am back.', 12,0,100,0,0,0, 'Lurgglbr');
