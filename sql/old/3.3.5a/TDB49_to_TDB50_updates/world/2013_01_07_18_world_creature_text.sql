-- Texts for Nightbane
DELETE FROM `creature_text` WHERE `entry`= 17225;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(17225,0,0, 'An ancient being awakens in the distance...',16,0,100,0,0,0, 'Nightbane - EMOTE_SUMMON'),
(17225,1,0, 'What fools! I shall bring a quick end to your suffering!',14,0,100,0,0,0, 'Nightbane - YELL_AGGRO'),
(17225,2,0, 'Miserable vermin. I shall exterminate you from the air!',14,0,100,0,0,0, 'Nightbane - YELL_FLY_PHASE'),
(17225,3,0, 'Enough! I shall land and crush you myself!',14,0,100,0,0,0, 'Nightbane - YELL_LAND_PHASE'),
(17225,3,1, 'Insects! Let me show you my strength up close!',14,0,100,0,0,0, 'Nightbane - YELL_LAND_PHASE'),
(17225,4,0, 'takes a deep breath.',16,0,100,0,0,0, 'Nightbane - EMOTE_BREATH');
