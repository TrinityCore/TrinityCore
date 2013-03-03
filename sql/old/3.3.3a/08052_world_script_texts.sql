DELETE FROM `script_texts` WHERE `npc_entry`= 29434;
INSERT INTO `script_texts` (`npc_entry`, `entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`, `sound`, `type`, `language`, `emote`, `comment`) VALUES
('29434', '-1800042', 'Let me know when you''re ready. I''d prefer sooner than later... what with the slowly dying from poison and all. ', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, '0', '0', '0', '0', 'injured goblin SAY_QUEST_START'),
('29434', '-1800043', 'I''m going to bring the venom sack to Ricket... and then... you know... collapse. Thank you for helping me! ', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, '0', '0', '0', '0', 'injured goblin SAY_END_WP_REACHED');
