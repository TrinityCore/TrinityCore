--
DELETE FROM `conditions` WHERE `SourceEntry`=43189 AND `SourceTypeOrReferenceId`=17;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 43189, 0, 0, 29, 0, 24173, 100, 0, 1, 0, 0, "", "Spell 'Test Horn' cannot be cast if NPC 'Frostgore' is nearby"),
(17, 0, 43189, 0, 0, 36, 0, 0, 0, 0, 0, 0, 0, "", "Spell 'Test Horn' cannot be cast if nearby NPC 'Frostgore' is alive");

UPDATE `event_scripts` SET `x`=2932.631, `y`=-4488.105, `z`=285.6876, `o`=3.298672 WHERE `id`=15726;

DELETE FROM `waypoints` WHERE `entry`=24173;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(24173, 1, 2918.373, -4505.415, 280.0419, ""),
(24173, 2, 2920.935, -4521.924, 276.0025, ""),
(24173, 3, 2923.956, -4535.499, 274.4535, ""),
(24173, 4, 2944.427, -4555.303, 273.6897, "");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=24173;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (24173, 2417300);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24173, 0, 0, 0, 0, 0, 100, 0, 5000, 10000, 10000, 20000, 11, 52058, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Frostgore - In Combat - Cast 'Ground Slam'"),
(24173, 0, 1, 2, 11, 0, 100, 0, 0, 0, 0, 0, 18, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Frostgore - On Spawn - Add UNIT_FLAG_IMMUNE_TO_PC"),
(24173, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 1, 24173, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Frostgore - On Spawn - Start Waypoint"),
(24173, 0, 3, 0, 40, 0, 100, 0, 4, 0, 0, 0, 80, 2417300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Frostgore - On WP 4 Reached - Start Script"),
(2417300, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, "Frostgore - On Script - Set home position to summoner's position"),
(2417300, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, "Frostgore - On Script - Turn to summoner"),
(2417300, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Frostgore - On Script - Say Text 0"),
(2417300, 9, 3, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Frostgore - On Script - Say Text 1"),
(2417300, 9, 4, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 19, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Frostgore - On Script - Remove UNIT_FLAG_IMMUNE_TO_PC"),
(2417300, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, "Frostgore - On Script - Attack summoner");

DELETE FROM `creature_text` WHERE `entry`=24173;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(24173, 0, 0, (SELECT MaleText FROM broadcast_text WHERE ID = 22876), 12, 0, 100, 1, 0, 0, 22876, 0, "Frostgore"),
(24173, 1, 0, (SELECT MaleText FROM broadcast_text WHERE ID = 22877), 12, 0, 100, 25, 0, 0, 22877, 0, "Frostgore");
