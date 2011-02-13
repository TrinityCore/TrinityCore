DELETE FROM `script_texts` WHERE `entry` IN (-1603289,-1603297,-1603298,-1603299);
INSERT INTO `script_texts` (`npc_entry`,`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`,`sound`,`type`,`language`,`emote`,`comment`)
VALUES
(33271,-1603289,'A cloud of saronite vapors coalesces nearby!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,3,0,0,'General Vezax - Emote1'),
(33271,-1603297,'The saronite vapors mass and swirl violently, merging into a monstrous form!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,3,0,0,'General Vezax - Emote2'),
(33271,-1603298,'A saronite barrier appears around General Vezax!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,3,0,0,'General Vezax - Emote3'),
(33271,-1603299,'General Vezax roars and surges with dark might!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,3,0,0,'General Vezax - Emote4');
