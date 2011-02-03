DELETE FROM `script_texts` WHERE `entry` IN (-1603000,-1603001,-1603002,-1603003,-1603004,-1603005,-1603006);
INSERT INTO `script_texts` (`npc_entry`,`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`,`sound`,`type`,`language`,`emote`,`comment`) VALUES
   (27975,-1603000,'You shouldn''t have come...now you will die!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13487,1,0,0,'maiden of grief SAY_AGGRO'),
   (27975,-1603001,'Why must it be this way?',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13488,1,0,0,'maiden of grief SAY_SLAY_1'),
   (27975,-1603002,'You had it coming!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13489,1,0,0,'maiden of grief SAY_SLAY_2'),
   (27975,-1603003,'My burden grows heavier.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13490,1,0,0,'maiden of grief SAY_SLAY_3'),
   (27975,-1603004,'This is your own fault!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13491,1,0,0,'maiden of grief SAY_SLAY_4'),
   (27975,-1603005,'I hope you all rot! I never...wanted...this.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13493,1,0,0,'maiden of grief SAY_DEATH'),
   (27975,-1603006,'So much lost time... that you''ll never get back!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13492,1,0,0,'maiden of grief SAY_STUN');
