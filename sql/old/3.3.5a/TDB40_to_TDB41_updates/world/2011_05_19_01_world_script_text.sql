DELETE FROM `script_texts` WHERE `entry` IN (-1603209,-1603219);
INSERT INTO `script_texts` (`npc_entry`,`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`,`sound`,`type`,`language`,`emote`,`comment`)
VALUES
(32845,-1603209,'Hodir begins to cast Flash Freeze!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,3,0,0,'Hodir - EMOTE_FREEZE'),
(32845,-1603219,'Hodir gains Frozen Blows!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,3,0,0,'Hodir - EMOTE_BLOW');
