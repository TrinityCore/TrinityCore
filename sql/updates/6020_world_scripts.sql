
-- Quest - Kroshius' Infernal Core (level 50 warlock specific)
UPDATE `creature_template` SET `AIName`='EventAI' WHERE `entry`=14467;
INSERT INTO `creature_ai_scripts`
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES 
   (1446701, 14467, 11, 0, 100, 0, 0, 0, 0, 0, 1, -980, 0, 0, 19, 768, 0, 0, 2, 16, 0, 0, 'Kroshius Spawn Say');
INSERT INTO `creature_ai_texts`
   (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`, `sound`, `type`, `language`, `emote`, `comment`)
VALUES 
   (-980, 'Kroshius live? Kroshius crush!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 1, 0, 0, NULL);
