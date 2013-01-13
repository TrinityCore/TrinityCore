-- AzjolNerub/Ahnkahet/Jedoga Shadowseeker
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1619013 AND -1619000;
DELETE FROM `creature_text` WHERE `entry`=29310;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(29310, 0, 0, 'These are sacred halls! Your intrusion will be met with death!', 14, 0, 100, 0, 0, 14343, 'SAY_AGGRO'),
(29310, 1, 0, 'Who among you is devoted?', 14, 0, 100, 0, 0, 14343, 'SAY_SACRIFICE_1_1'),
(29310, 1, 1, 'You there! Step forward!', 14, 0, 100, 0, 0, 14343, 'SAY_SACRIFICE_1_2'),
(29310, 2, 0, 'Yogg-Saron, grant me your power!', 14, 0, 100, 0, 0, 14343, 'SAY_SACRIFICE_2_1'),
(29310, 2, 1, 'Master, a gift for you!', 14, 0, 100, 0, 0, 14343, 'SAY_SACRIFICE_2_2'),
(29310, 3, 0, 'Glory to Yogg-Saron!', 14, 0, 100, 0, 0, 0, 'SAY_SLAY_1'),
(29310, 3, 1, 'You are unworthy!', 14, 0, 100, 0, 0, 0, 'SAY_SLAY_2'),
(29310, 3, 2, 'Get up! You haven''t suffered enough.', 14, 0, 100, 0, 0, 14350, 'SAY_SLAY_3'),
(29310, 4, 0, 'Do not expect your sacrilege... to go unpunished.', 14, 0, 100, 0, 0, 0, 'SAY_DEATH'),
(29310, 5, 0, 'The elements themselves will rise up against the civilized world! Only the faithful will be spared!', 14, 0, 100, 0, 0, 14352, 'SAY_PREACHING_1'),
(29310, 5, 1, 'Immortality can be yours, but only if you pledge yourself fully to Yogg-Saron!', 14, 0, 100, 0, 0, 14353, 'SAY_PREACHING_2'),
(29310, 5, 2, 'Here, on the very borders of his domain, you will experience power you could have never imagined!', 14, 0, 100, 0, 0, 0, 'SAY_PREACHING_3'),
(29310, 5, 3, 'You have traveled long and risked much to be here! Your devotion shall be rewarded.', 14, 0, 100, 0, 0, 0, 'SAY_PREACHING_4'),
(29310, 5, 4, 'The faithful shall be exalted! But there is more work to be done. We will press on until all of Azeroth lies beneath his shadow!', 14, 0, 100, 0, 0, 0, 'SAY_PREACHING_5');
