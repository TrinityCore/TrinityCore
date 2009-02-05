UPDATE `creature_template` SET `ScriptName`='' WHERE `entry`=22083;
UPDATE `creature_template` SET `ScriptName`='npc_overlord_morghor' WHERE `entry`=23139;
UPDATE `creature_template` SET `ScriptName`='' WHERE `entry`=23141;
DELETE FROM `script_texts` WHERE entry BETWEEN -1000221 and -1000206;
INSERT INTO `script_texts` (entry, content_default, type, emote, comment) VALUES
(-1000206, 'Come, $N. Lord Stormrage awaits.', 0, 1, 'OVERLORD_SAY_1'),
(-1000207, 'Lord Illidan will be here shortly.', 0, 1, 'OVERLORD_SAY_2'),
(-1000208, 'Lord Illidan, this is the Dragonmaw that I, and others, have told you about. He will lead us to victory!', 0, 1, 'OVERLORD_SAY_3'),
(-1000209, 'But... My lord, I do not understand. $N... He is the orc that has...', 0, 1, 'OVERLORD_SAY_4'),
(-1000210, 'It will be done, my lord.', 0, 1, 'OVERLORD_SAY_5'),
(-1000211, 'So you thought to make a fool of Mor\'ghor, eh? Before you are delivered to Lord Illidan, you will feel pain that you could not know to exist. I will take pleasure in exacting my own vengeance.', 0, 25, 'OVERLORD_SAY_6'),
(-1000212, 'Warriors of Dragonmaw, gather \'round! One among you has attained the rank of highlord! Bow your heads in reverence! Show your respect and allegiance to Highlord $N!', 1, 22, 'OVERLORD_YELL_1'),
(-1000213, 'All hail Lord Illidan!', 1, 66, 'OVERLORD_YELL_2'),
(-1000214, 'What is the meaning of this, Mor\'ghor?', 0, 1, 'LORD_ILLIDAN_SAY_1'),
(-1000215, 'SILENCE!', 0, 22, 'LORD_ILLIDAN_SAY_2'),
(-1000216, 'Blathering idiot. You incomprehensibly incompetent buffoon...', 0, 1, 'LORD_ILLIDAN_SAY_3'),
(-1000217, 'THIS is your hero?', 0, 6, 'LORD_ILLIDAN_SAY_4'),
(-1000218, 'You have been deceived, imbecile.', 0, 1, 'LORD_ILLIDAN_SAY_5'),
(-1000219, 'This... whole... operation... HAS BEEN COMPROMISED!', 0, 22, 'LORD_ILLIDAN_SAY_6'),
(-1000220, 'I expect to see this insect\'s carcass in pieces in my lair within the hour. Fail and you will suffer a fate so much worse than death.', 0, 1, 'LORD_ILLIDAN_SAY_7'),
(-1000221, 'You will not harm the boy, Mor\'ghor! Quickly, $N, climb on my back!', 0, 22, 'YARZILL_THE_MERC_SAY');

DELETE FROM `script_texts` WHERE `entry`='-1000222';
INSERT INTO `script_texts` (entry, content_default, type, language, emote, comment) VALUES
(-1000222, 'Thank you, mortal.', 0, 11, 1, 'SAY_JUST_EATEN');

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000234 and -1000223;
INSERT INTO `script_texts` (entry, content_default, emote, comment) VALUES
(-1000223, 'I sense the tortured spirits, $N. They are this way, come quickly!', 1, 'SAY_START'),
(-1000224, 'Watch out!', 0, 'SAY_AGGRO1'),
(-1000225, 'Naga attackers! Defend yourself!', 0, 'SAY_AGGRO2'),
(-1000226, 'Kill them all!', 0, 'ASSASSIN_SAY_AGGRO1'),
(-1000227, 'You will never essscape Coilssskarrr...', 0, 'ASSASSIN_SAY_AGGRO2'),
(-1000228, 'Grant me protection $N, i must break trough their foul magic!', 0, 'SAY_PROGRESS1'),
(-1000229, 'The naga of Coilskar are exceptionally cruel to their prisoners. It is a miracle that I survived inside that watery prison for as long as I did. Earthmother be praised.', 0, 'SAY_PROGRESS2'),
(-1000230, 'Now we must find the exit.', 0, 'SAY_PROGRESS3'),
(-1000231, 'Lady Vashj must answer for these atrocities. She must be brought to justice!', 0, 'SAY_PROGRESS4'),
(-1000232, 'The tumultuous nature of the great waterways of Azeroth and Draenor are a direct result of tormented water spirits.', 0, 'SAY_PROGRESS5'),
(-1000233, 'It shouldn\'t be much further, $N. The exit is just up ahead.', 0, 'SAY_PROGRESS6'),
(-1000234, 'Thank you, $N. Please return to my brethren at the Altar of Damnation, near the Hand of Gul\'dan, and tell them that Wilda is safe. May the Earthmother watch over you...', 0, 'SAY_END');