DELETE FROM `script_texts` WHERE `entry` IN (-1048003,-1048004);
INSERT INTO `script_texts` (`npc_entry`,`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`,`sound`,`type`,`language`,`emote`,`comment`) VALUES
(6729,-1048003,'Aku''mai is dead! At last, I can leave this wretched place.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,1,0,0,''),
(6729,-1048004,'Speak with me to hear my tale',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'');
