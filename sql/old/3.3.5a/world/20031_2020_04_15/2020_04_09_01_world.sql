-- 
UPDATE `creature` SET `spawntimesecs`=60 WHERE `id`=25724;
UPDATE `gameobject_template_addon` SET `flags` = 48 WHERE `entry` = 187884; 
DELETE FROM `smart_scripts` WHERE `entryorguid`=2535600 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(2535600, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Warmage Anzim - On Script - Say text"),
(2535600, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 83, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Warmage Anzim - On Script - Remove Npc Flag Questgiver"),
(2535600, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 118574, 27888, 0, 0, 0, 0, 0, 0, "Warmage Anzim - On Script - Set Data 1 1"),
(2535600, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 107998, 25732, 0, 0, 0, 0, 0, 0, "Warmage Anzim - On Script - Set Data 1 1"),
(2535600, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 108027, 25733, 0, 0, 0, 0, 0, 0, "Warmage Anzim - On Script - Set Data 1 1"),
(2535600, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 107602, 25727, 0, 0, 0, 0, 0, 0, "Warmage Anzim - On Script - Set Data 1 1"),
(2535600, 9, 6, 0, 0, 0, 100, 0, 180000, 180000, 0, 0, 0, 82, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Warmage Anzim - On Script - Add Npc Flag Questgiver");

DELETE FROM `creature_text` WHERE `CreatureID`=25356;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(25356, 0, 0, 'Mages! Take wing!', 14, 0, 100, 0, 0, 0, 24886, 0, 'Warmage Anzim');
