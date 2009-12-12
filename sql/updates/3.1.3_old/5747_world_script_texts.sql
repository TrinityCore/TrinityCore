DELETE FROM `script_texts` WHERE `entry` BETWEEN -1604017 AND -1604010;
INSERT INTO `script_texts` (`npc_entry`,`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`,`sound`,`type`,`language`,`emote`,`comment`) VALUES
   (29305,-1604010,'We fought back da Scourge. What chance joo be thinkin'' JOO got?',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,1,0,0,'SAY_AGGRO boss_moorabi'),
   (29305,-1604012,'Who gonna stop me; you? ',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,1,0,0,'SAY_SLAY_2 boss_moorabi'),
   (29305,-1604013,'Not so tough now.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,1,0,0,'SAY_SLAY_3 boss_moorabi'),
   (29305,-1604014,'If our gods can die... den so can we... ',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,1,0,0,'SAY_DEATH boss_moorabi'),
   (29305,-1604015,'Get ready for somethin''... much... BIGGAH! ',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,1,0,0,'SAY_TRANSFORM boss_moorabi'),
   (29305,-1604016,'Da ground gonna swallow you up',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,1,0,0,'SAY_QUAKE boss_moorabi'),
   (29305,-1604017,'%s begins to transform!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,3,0,0,'EMOTE_TRANSFORM boss_moorabi');
