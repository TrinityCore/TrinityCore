UPDATE `creature_template` SET `ScriptName` = 'npc_agnetta_tyrsdottar' WHERE `entry` = 30154;

INSERT INTO `script_texts` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`, `sound`, `type`, `language`, `emote`, `comment`) VALUES
(-1571003, 'I\'m not afraid of anything -- bring it on!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, 'aggro_Agnetta');
