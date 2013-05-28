-- AzjolNerub/Ahnkahet/Herald Volazj
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1619036 AND -1619030;
DELETE FROM `creature_text` WHERE `entry`=29311;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(29311,0,0, 'Shgla''yos plahf mh''naus.', 14,0,100,0,0,14043, 'SAY_AGGRO_1'),
(29311,0,1, 'They who dine on lost souls know only hunger.', 15, 0, 100, 0, 0, 14043, 'SAY_AGGRO_2'),
(29311,1,0, 'Ywaq puul skshgn: on''ma yeh''glu zuq.', 14,0,100,0,0,14045, 'SAY_SLAY_1'),
(29311,1,1, 'Ywaq ma phgwa''cul hnakf.',14,0,100,0,0,14046, 'SAY_SLAY_2'),
(29311,1,2, 'Ywaq maq oou; ywaq maq ssaggh. Ywaq ma shg''fhn.',14,0,100,0,0,14047, 'SAY_SLAY_3'),
(29311,2,0, 'Iilth vwah, uhn''agth fhssh za.', 14, 0, 100, 0, 0, 14048, 'SAY_DEATH_1'),
(29311,2,1, 'Where one falls, many shall take its place.', 15, 0, 100, 0, 0, 14048, 'SAY_DEATH_2'),
(29311,3,0, 'Gul''kafh an''shel. Yoq''al shn ky ywaq nuul.', 14, 0, 100, 0, 0, 14044, 'SAY_PHASE');