DELETE FROM `script_texts` WHERE `entry` IN (-1048000,-1048001,-1048002);
INSERT INTO `script_texts` (`npc_entry`,`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`,`sound`,`type`,`language`,`emote`,`comment`) VALUES
   (4832,-1048000,'Just...Dust...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,5803,1,0,0,''),
   (4832,-1048001,'Sleep...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,5804,1,0,0,''),
   (4832,-1048002,'Who dares disturb my meditation!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,5805,1,0,0,'');
