DELETE FROM `script_texts` WHERE `entry` IN (-1000471,-1000472,-1000473);
INSERT INTO `script_texts` (`npc_entry`,`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`,`sound`,`type`,`language`,`emote`,`comment`) VALUES
   (23861,-1000471,'It was... terrible... the demon...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,''),
   (23864,-1000472,'This land was mine long before your wretched kind set foot here.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,1,0,0,''),
   (23864,-1000473,'All who venture here belong to me, including you!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,1,0,0,'');

