-- Quest Smoke Em Out
DELETE FROM `script_texts` WHERE `entry` BETWEEN (-1603539) AND (-1603535);
INSERT INTO `script_texts` (`npc_entry`,`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`,`sound`,`type`,`language`,`emote`,`comment`) VALUES
   (27570,-1603535,'We\'re all gonna die!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'Smoke \'Em Out - Say1'),
   (27570,-1603536,'Gotta get out of here!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'Smoke \'Em Out - Say2'),
   (27570,-1603537,'No way I\'m stickin\' around!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'Smoke \'Em Out - Say3'),
   (27570,-1603538,'Forget this! I\'m going home!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'Smoke \'Em Out - Say4'),
   (27570,-1603539,'I didn\'t sign up for this!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'Smoke \'Em Out - Say5');

