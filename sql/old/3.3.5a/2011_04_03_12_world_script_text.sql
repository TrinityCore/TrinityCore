DELETE FROM `script_texts` WHERE `npc_entry` IN (18445,20812,18369);
INSERT INTO `script_texts` (`npc_entry`, `entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`, `sound`, `type`, `language`, `emote`, `comment`) VALUES
(18445,-1800071, 'Thanks, $C! I''m sure my dad will reward you greatly! Bye!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,NULL),
(20812,-1800072, 'This is the last time I get caught!I promise! Bye!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,NULL),
(18369,-1800073, 'Thank you for saving me again!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,NULL);
