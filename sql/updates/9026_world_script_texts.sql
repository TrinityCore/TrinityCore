-- script texts
delete from script_texts where npc_entry in (7607,7604);
insert into `script_texts` (`npc_entry`, `entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`, `sound`, `type`, `language`, `emote`, `comment`) values
('7607','-1209000','Oh no! Here they come!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'0','0','1','0','Weegli Blastfuse SAY_WEEGLI_OHNO'),
('7607','-1209001','OK. Here I go.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'0','0','1','0','Weegli Blastfuse SAY_WEEGLI_OK_I_GO'),
('7604','-1209002','Placeholder 1',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'0','0','1','0','Sergeant Bly SAY_1'),
('7604','-1209003','Placeholder 2',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'0','0','1','0','Sergeant Bly SAY_2');
