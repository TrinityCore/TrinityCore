-- Texts for Valkyr Battle Maiden
DELETE FROM `creature_text` WHERE `entry`= 28534;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(28534,0,0, 'It is not yet your time, champion. Rise! Rise and fight once more!',15,0,100,0,0,0, 'Valkyr Battle Maiden');

-- Texts for Dark Rider of Acherus
DELETE FROM `creature_text` WHERE `entry`= 28654;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(28654,0,0, 'The realm of shadows awaits...',12,0,100,0,0,0, 'Dark Rider of Acherus');

-- Texts for Scarlet Miner
DELETE FROM `creature_text` WHERE `entry`= 28841;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(28841,0,0, 'Where''d this come from? I better get this down to the ships before the foreman sees it!',12,0,100,0,0,0, 'Scarlet Miner'),
(28841,1,0, "Now I can have a rest!",12,0,100,0,0,0, 'Scarlet Miner');
