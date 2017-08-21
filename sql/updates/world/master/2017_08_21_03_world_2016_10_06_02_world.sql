--
UPDATE `creature_template` SET `AIName`="SmartAI", `flags_extra`=0 WHERE `entry`=4276;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (4276, 427600) AND `source_type` IN (0, 9);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4276, 0, 0, 1, 19, 0, 100, 0, 1090, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Piznik - On Quest 'Gerenzo's Orders' accepted - Store Targetlist"),
(4276, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 427600, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Piznik - On Quest 'Gerenzo's Orders' accepted - Run Actionlist"),
(4276, 0, 2, 0, 6, 0, 100, 0, 0, 0, 0, 0, 6, 1090, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, "Piznik - On Death - Fail quest 'Gerenzo's Orders'"),
(427600, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 19, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Piznik - On Script - Remove UNIT_FLAG_IMMUNE_TO_NPC"),
(427600, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 83, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Piznik - On Script - Remove Questgiver flag"),
(427600, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 2, 42, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Piznik - On Script - Change faction to 42 (guessed)"),
(427600, 9, 3, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 12, 3998, 4, 20000, 0, 0, 0, 8, 0, 0, 0, 938.30, -257.35, -2.22, 0, "Piznik - On Script - Summon Windshear Vermin"),
(427600, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 3998, 4, 20000, 0, 0, 0, 8, 0, 0, 0, 942.28, -254.49, -2.38, 0, "Piznik - On Script - Summon Windshear Vermin"),
(427600, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 4001, 4, 20000, 0, 0, 0, 8, 0, 0, 0, 938.52, -253.20, -2.08, 0, "Piznik - On Script - Summon Windshear Tunnel Rat"),
(427600, 9, 6, 0, 0, 0, 100, 0, 60000, 60000, 0, 0, 12, 4002, 4, 20000, 0, 0, 0, 8, 0, 0, 0, 938.30, -257.35, -2.22, 0, "Piznik - On Script - Summon Windshear Stonecutter"),
(427600, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 4002, 4, 20000, 0, 0, 0, 8, 0, 0, 0, 942.28, -254.49, -2.38, 0, "Piznik - On Script - Summon Windshear Stonecutter"),
(427600, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 4003, 4, 20000, 0, 0, 0, 8, 0, 0, 0, 938.52, -253.20, -2.08, 0, "Piznik - On Script - Summon Windshear Geomancer"),
(427600, 9, 9, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 4003, 4, 20000, 0, 0, 0, 8, 0, 0, 0, 939.51, -253.11, -2.02, 0, "Piznik - On Script - Summon Windshear Geomancer"),
(427600, 9, 10, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 4004, 4, 20000, 0, 0, 0, 8, 0, 0, 0, 938.30, -257.35, -2.22, 0, "Piznik - On Script - Summon Windshear Overlord"),
(427600, 9, 11, 0, 0, 0, 100, 0, 60000, 60000, 0, 0, 12, 4001, 4, 20000, 0, 0, 0, 8, 0, 0, 0, 938.30, -257.35, -2.22, 0, "Piznik - On Script - Summon Windshear Tunnel Rat"),
(427600, 9, 12, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 4001, 4, 20000, 0, 0, 0, 8, 0, 0, 0, 942.28, -254.49, -2.38, 0, "Piznik - On Script - Summon Windshear Tunnel Rat"),
(427600, 9, 13, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 4001, 4, 20000, 0, 0, 0, 8, 0, 0, 0, 938.52, -253.20, -2.08, 0, "Piznik - On Script - Summon Windshear Tunnel Rat"),
(427600, 9, 14, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 4004, 4, 20000, 0, 0, 0, 8, 0, 0, 0, 939.51, -253.11, -2.02, 0, "Piznik - On Script - Summon Windshear Overlord"),
(427600, 9, 15, 0, 0, 0, 100, 0, 30000, 30000, 0, 0, 18, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Piznik - On Script - Set UNIT_FLAG_IMMUNE_TO_NPC"),
(427600, 9, 16, 0, 0, 0, 100, 0, 0, 0, 0, 0, 82, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Piznik - On Script - Add Questgiver flag"),
(427600, 9, 17, 0, 0, 0, 100, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Piznik - On Script - Change faction to 35"),
(427600, 9, 18, 0, 0, 0, 100, 0, 0, 0, 0, 0, 15, 1090, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, "Piznik - On Script - Complete quest 'Gerenzo's Orders'");
