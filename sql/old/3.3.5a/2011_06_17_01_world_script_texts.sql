DELETE FROM `script_texts` WHERE `entry` IN (-1603055,-1603056);
INSERT INTO `script_texts` (`npc_entry`,`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`,`sound`,`type`,`language`,`emote`,`comment`)
VALUES
(33515,-1603055,'Auriaya begins to cast Terrifying Screech.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,3,0,0,'Auriaya - EMOTE_FEAR'),
(33515,-1603056,'Auriaya begins to activate the Feral Defender!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,3,0,0,'Auriaya - EMOTE_DEFENDER');
