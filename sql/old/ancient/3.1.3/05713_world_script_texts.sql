DELETE FROM `script_texts` WHERE `entry` BETWEEN -1619028 AND -1619021;
INSERT INTO `script_texts` (`npc_entry`,`entry`,`content_default`,`sound`,`type`,`language`,`emote`,`comment`) VALUES
   (29308,-1619021,'I will feast on your remains.',0,0,0,0,'prince taldaram SAY_AGGRO'),
   (29308,-1619022,'I will drink no blood before it''s time.',0,0,0,0,'prince taldaram SAY_SLAY_1'),
   (29308,-1619023,'One final embrace.',0,0,0,0,'prince taldaram SAY_SLAY_2'),
   (29308,-1619024,'Still I hunger, still I thirst.',0,0,0,0,'prince taldaram SAY_DEATH'),
   (29308,-1619025,'So appetizing.',0,0,0,0,'prince taldaram SAY_FEED1'),
   (29308,-1619026,'Fresh, warm blood. It has been too long.',0,0,0,0,'prince taldaram SAY_FEED2'),
   (29308,-1619027,'Your heartbeat is music to my ears.',0,0,0,0,'prince taldaram SAY_VANISH1'),
   (29308,-1619028,'I am nowhere. I am everywhere. I am the watcher, unseen.',0,0,0,0,'prince taldaram SAY_VANISH2');
