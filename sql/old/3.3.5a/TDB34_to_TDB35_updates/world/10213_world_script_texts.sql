DELETE FROM `script_texts` WHERE `entry` IN (-1000002,-1000003);
INSERT INTO `script_texts` (`npc_entry`,`entry`,`content_default`,`sound`,`type`,`language`,`emote`,`comment`) VALUES
(0,-1000002,'%s goes into a frenzy!',0,2,0,0,'EMOTE_GENERIC_FRENZY'),
(0,-1000003,'%s becomes enraged!',0,2,0,0,'EMOTE_GENERIC_ENRAGED');

DELETE FROM `script_texts` WHERE `entry` IN (-1575023,-1575024,-1575025,-1575026,-1575027);
INSERT INTO `script_texts` (`npc_entry`,`entry`,`content_default`,`sound`,`type`,`language`,`emote`,`comment`) VALUES
(26668,-1575023,'Your death approaches.',13850,1,0,0,'svala SAY_SACRIFICE_1'),
(26668,-1575024,'Go now to my master.',13851,1,0,0,'svala SAY_SACRIFICE_2'),
(26668,-1575025,'Your end is inevitable.',13852,1,0,0,'svala SAY_SACRIFICE_3'),
(26668,-1575026,'Yor-guul mak!',13853,1,0,0,'svala SAY_SACRIFICE_4'),
(26668,-1575027,'Any last words?',13854,1,0,0,'svala SAY_SACRIFICE_5');
