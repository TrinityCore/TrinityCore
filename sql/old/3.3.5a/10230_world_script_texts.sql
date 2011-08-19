DELETE FROM `script_texts` WHERE `entry` BETWEEN -1631114 AND -1631104;
INSERT INTO `script_texts` (`npc_entry`,`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`,`sound`,`type`,`language`,`emote`,`comment`) VALUES
(36678,-1631104,'Good news, everyone! I think I perfected a plague that will destroy all life on Azeroth!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,17114,1,0,0,'SAY_AGGRO'),
(36678,-1631105,'%s begins to cast Unstable Experiment!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,3,0,0,'EMOTE_UNSTABLE_EXPERIMENT'),
(36678,-1631106,'Two oozes, one room! So many delightful possibilities...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,17122,1,0,0,'SAY_PHASE_TRANSITION_HEROIC'),
(36678,-1631107,'Hmm. I don''t feel a thing. Whaa...? Where''d those come from?',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,17120,1,0,15,'SAY_TRANSFORM_1'),
(36678,-1631108,'Tastes like... Cherry! Oh! Excuse me!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,17121,1,0,15,'SAY_TRANSFORM_2'),
(36678,-1631109,'|TInterface\Icons\inv_misc_herb_evergreenmoss.blp:16|t%s cast |cFF00FF00Malleable Goo!|r',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,3,0,0,'EMOTE_MALLEABLE_GOO'),
(36678,-1631110,'%s cast |cFFFF7F00Choking Gas Bomb!|r',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,3,0,0,'EMOTE_CHOKING_GAS_BOMB'),
(36678,-1631111,'Hmm... Interesting...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,17115,1,0,0,'SAY_KILL_1'),
(36678,-1631112,'That was unexpected!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,17116,1,0,0,'SAY_KILL_2'),
(36678,-1631113,'Great news, everyone!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,17118,1,0,0,'SAY_BERSERK'),
(36678,-1631114,'Bad news, everyone! I don''t think I''m going to make it.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,17117,1,0,0,'SAY_DEATH');
