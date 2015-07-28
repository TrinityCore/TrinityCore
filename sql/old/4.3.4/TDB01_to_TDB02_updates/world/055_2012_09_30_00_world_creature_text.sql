-- AzjolNerub/Ahnkahet/Elder Nadox
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1619020 AND -1619014;
DELETE FROM `creature_text` WHERE `entry`=29309;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(29309,0,0, 'The secrets of the deep shall remain hidden.',14,0,100,0,0,14033, 'SAY_AGGRO'),
(29309,1,0, 'Sleep now, in the cold dark.',14,0,100,0,0,14036, 'SAY_SLAY_1'),
(29309,1,1, 'For the Lich King!',14,0,100,0,0,14037, 'SAY_SLAY_2'),
(29309,1,2, 'Perhaps we will be allies soon.',14,0,100,0,0,14038, 'SAY_SLAY_3'),
(29309,2,0, 'Master, is my service complete?',14,0,100,0,0,14039, 'SAY_DEATH'),
(29309,3,0, 'The young must not grow hungry...',14,0,100,0,0,14034, 'SAY_EGG_SAC_1'),
(29309,3,1, 'Shhhad ak kereeesshh chak-k-k!',14,0,100,0,0,14035, 'SAY_EGG_SAC_2'),
(29309,4,0, 'An Ahn''kahar Guardian hatches!',16,0,100,0,0,14035, 'EMOTE_HATCHES');
