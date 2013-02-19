DELETE FROM `script_texts` WHERE `npc_entry` IN (25828,25248,25827);
INSERT INTO `script_texts` (`npc_entry`,`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`,`sound`,`type`,`language`,`emote`,`comment`) VALUES
(25248,-1571044,'Well...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'npc_hidden_cultist SAY_HIDDEN_CULTIST_1'),
(25828,-1571045,'Finally! This charade is over... Arthas give me strength!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'npc_hidden_cultist SAY_HIDDEN_CULTIST_2'),
(25827,-1571046,'You don''t know who you''re messing with! Death beckons!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'npc_hidden_cultist SAY_HIDDEN_CULTIST_3'),
(25248,-1571047,'I suppose this is it, then? I won''t go down quietly!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'npc_hidden_cultist SAY_HIDDEN_CULTIST_4');