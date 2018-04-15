DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000488 AND -1000482;
INSERT INTO `script_texts` (`npc_entry`,`entry`,`content_default`,`sound`,`type`,`language`,`emote`,`comment`) VALUES
   (18210,-1000482,'Look out!',0,0,0,0,'maghar captive SAY_MAG_START'),
   (18210,-1000483,'Don''t let them escape! Kill the strong one first!',0,0,0,0,'maghar captive SAY_MAG_NO_ESCAPE'),
   (18210,-1000484,'More of them coming! Watch out!',0,0,0,0,'maghar captive SAY_MAG_MORE'),
   (18210,-1000485,'Where do you think you''re going? Kill them all!',0,0,0,0,'maghar captive SAY_MAG_MORE_REPLY'),
   (18210,-1000486,'Ride the lightning, filth!',0,0,0,0,'maghar captive SAY_MAG_LIGHTNING'),
   (18210,-1000487,'FROST SHOCK!!!',0,0,0,0,'maghar captive SAY_MAG_SHOCK'),
   (18210,-1000488,'It is best that we split up now, in case they send more after us. Hopefully one of us will make it back to Garrosh. Farewell stranger.',0,0,0,0,'maghar captive SAY_MAG_COMPLETE');
