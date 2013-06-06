DELETE FROM `creature_text` WHERE `entry` IN (38472,38485);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(38472,0,0, 'Die, intruders! None shall interfere with the Cult''s plans!',1,0,0,0,0,0, 'Darnavan - SAY_DARNAVAN_AGGRO'),
(38472,1,0, 'Wh- where am I...? What a nightmare I have had... But this is no time to reflect, I have much information to report!',0,0,0,0,0,0, 'Darnavan - SAY_DARNAVAN_RESCUED'),
(38485,0,0, 'Die, intruders! None shall interfere with the Cult''s plans!',1,0,0,0,0,0, 'Darnavan - SAY_DARNAVAN_AGGRO'),
(38485,1,0, 'Wh- where am I...? What a nightmare I have had... But this is no time to reflect, I have much information to report!',0,0,0,0,0,0, 'Darnavan - SAY_DARNAVAN_RESCUED');
