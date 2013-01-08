-- Texts for Zul'jin
DELETE FROM `creature_text` WHERE `entry`= 23863;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(23863,0,0, 'Everybody always wanna take from us. Now we gonna start takin'' back. Anybody who get in our way...gonna drown in their own blood! De Amani empire be back now...seekin'' vengeance. And we gonna start...with you!',14,0,100,0,0,12090, 'Zul''jin YELL_INTRO'),
(23863,1,0, 'Nobody badduh dan me!',14,0,100,0,0,12091, 'Zul''jin YELL_AGGRO'),
(23863,2,0, 'Got me some new tricks...like me bruddah bear!',14,0,100,0,0,12092, 'Zul''jin YELL_TRANSFORM_TO_BEAR'),
(23863,3,0, 'Dere be no hidin'' from da eagle!',14,0,100,0,0,12093, 'Zul''jin YELL_TRANSFORM_TO_EAGLE'),
(23863,4,0, 'Let me introduce to you my new bruddahs: fang and claw!',14,0,100,0,0,12094, 'Zul''jin YELL_TRANSFORM_TO_LYNX'),
(23863,5,0, 'Ya don'' have to look to da sky to see da dragonhawk!',14,0,100,0,0,12095, 'Zul''jin YELL_TRANSFORM_TO_DRAGONHAWK'),
(23863,6,0, 'Fire kill you just as quick!',14,0,100,0,0,12096, 'Zul''jin YELL_FIRE_BREATH'),
(23863,7,0, 'You too slow! Me too strong!',14,0,100,0,0,12097, 'Zul''jin YELL_BERSERK'),
(23863,8,0, 'Da Amani de chuka!',14,0,100,0,0,12098, 'Zul''jin YELL_KILL'),
(23863,8,1, 'Lot more gonna fall like you!',14,0,100,0,0,12099, 'Zul''jin YELL_KILL'),
(23863,9,0, 'Mebbe me fall...but da Amani empire...never gonna die...',14,0,100,0,0,12100, 'Zul''jin YELL_DEATH');
