DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000578 AND -1000575;
INSERT INTO `script_texts` (`npc_entry`,`entry`,`content_default`,`sound`,`type`,`language`,`emote`,`comment`) VALUES
(19589,-1000575, 'All systems on-line. Prepare yourself, we leave shortly.',0,0,0,0, 'max_a_million SAY_START'),
(19589,-1000576, 'Be careful in there and come back in one piece!',0,0,0,0, 'bot-specialist_alley SAY_ALLEY_FAREWELL'),
(19589,-1000577, 'Proceed.',0,0,0,0, 'max_a_million SAY_CONTINUE'),
(19589,-1000578, 'You are back! Were you able to get all of the machines?',0,0,0,0, 'bot-specialist_alley SAY_ALLEY_FINISH');
