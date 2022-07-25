--
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=15280;
DELETE FROM `smart_scripts` WHERE `entryorguid`=15280 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1528000 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15280, 0, 0, 0, 1, 0, 100, 0, 5000, 8000, 5000, 8000, 0, 80, 1528000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Jesthenis Sunstrider - OOC - Run Script"),
(1528000, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 10, 1, 6, 273, 274, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Jesthenis Sunstrider - On Script - Play Random Emote"),
(1528000, 9, 1, 0, 0, 0, 100, 0, 0, 2000, 0, 0, 0, 10, 1, 6, 273, 274, 0, 0, 19, 15284, 20, 0, 0, 0, 0, 0, 0, "Jesthenis Sunstrider - On Script - Play Random Emote (Matron Arena)");
