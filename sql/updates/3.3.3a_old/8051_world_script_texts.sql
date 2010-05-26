DELETE FROM `script_texts` WHERE `npc_entry`=27463;
INSERT INTO `script_texts` (`npc_entry`, `entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`, `sound`, `type`, `language`, `emote`, `comment`) VALUES
(27463, -1800046, 'Thank you. $Class!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, 'RANDOM_SAY_3'),
(27463, -1800045, 'Whoa.. i nearly died there. Thank you, $Race!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, 'RANDOM_SAY_2'),
(27463, -1800044, 'Ahh..better..', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, 'RANDOM_SAY_1');
