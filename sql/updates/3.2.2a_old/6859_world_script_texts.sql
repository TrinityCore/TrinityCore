DELETE FROM `script_texts` WHERE `npc_entry` IN (25504, 25589);
INSERT INTO `script_texts` (`npc_entry`, `entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`, `sound`, `type`, `language`, `emote`, `comment`) VALUES 
(25504, -1750040, 'My father''s aura is quite strong, he cannot be far. Could you be a doll and fight off the monsters wandering throught the mist?', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, 'npc_mootoo_the_younger'),
(25504, -1750041, 'Watch out for the monsters!Which way should we go first? Let''s try this way...', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, 'npc_mootoo_the_younger'),
(25504, -1750042, 'What could this be?', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, 'npc_mootoo_the_younger'),
(25504, -1750043, 'There''s no sign of it ending! Where could my father be?', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, 'npc_mootoo_the_younger'),
(25504, -1750044, 'Father! You''re safe!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, 'npc_mootoo_the_younger'),
(25589, -1700003, 'I\'ll make you a deal: If you get me out of here alive, you\'ll get a reward larger than you can imagine!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'0','0','0','0','npc_bonker_togglevolt'),
(25589, -1700002, 'I AM NOT AN APPETIZER!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'0','0','0','0','npc_bonker_togglevolt'),
(25589, -1700001, 'Right then, no time to waste. Lets get outa here!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'0','0','0','0','npc_bonker_togglevolt');
