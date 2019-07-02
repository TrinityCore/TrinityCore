-- 
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=19477;
UPDATE `smart_scripts` SET `link`=4 WHERE `entryorguid`=17058 AND `source_type`=0 AND `id`=2;
DELETE FROM `smart_scripts` WHERE `entryorguid`=17058 AND `source_type`=0 AND `id` IN (4, 5);
DELETE FROM `smart_scripts` WHERE `entryorguid`=16938 AND `source_type`=0 AND `id` BETWEEN 1 AND 14;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1693800, 1693801) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17058, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 16938, 0, 0, 0, 0, 0, 0, "Illidari Taskmaster - On Aggro - Set Data 1 1 (Dreghood Brute)"),
(17058, 0, 5, 0, 6, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 16938, 0, 0, 0, 0, 0, 0, "Illidari Taskmaster - On Death - Set Data 2 2 (Dreghood Brute)"),
(16938, 0, 1, 0, 38, 0, 100, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dreghood Brute - On Data 1 1 Set - Say Line 0"),
(16938, 0, 2, 3, 38, 0, 100, 0, 2, 2, 0, 0, 117, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dreghood Brute - On Data 2 2 Set - Disable Evade"),
(16938, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 36, 19477, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dreghood Brute - On Data 2 2 Set - Update Template To 'Dreghood Fleeing Warrior'"),
(16938, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 8, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dreghood Brute - On Data 2 2 Set - Set ReactState Defensive"),
(16938, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dreghood Brute - On Data 2 2 Set - Stop Combat"),
(16938, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 2, 94, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dreghood Brute - On Data 2 2 Set - Set Faction 94"),
(16938, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 45, 3, 3, 0, 0, 0, 0, 9, 16938, 0, 20, 0, 0, 0, 0, "Draghood Brute - On Data 2 2 Set - Set Data 3 3 (Nearby Dreghood Brutes)"),
(16938, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 1693800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dreghood Brute - On Data 2 2 Set - Run Script"),
(16938, 0, 9, 10, 38, 0, 100, 0, 3, 3, 0, 0, 117, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dreghood Brute - On Data 3 3 Set - Disable Evade"),
(16938, 0, 10, 11, 61, 0, 100, 0, 0, 0, 0, 0, 36, 19477, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dreghood Brute - On Data 3 3 Set - Update Template To 'Dreghood Fleeing Warrior'"),
(16938, 0, 11, 12, 61, 0, 100, 0, 0, 0, 0, 0, 8, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dreghood Brute - On Data 3 3 Set - Set ReactState Defensive"),
(16938, 0, 12, 13, 61, 0, 100, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dreghood Brute - On Data 3 3 Set - Stop Combat"),
(16938, 0, 13, 14, 61, 0, 100, 0, 0, 0, 0, 0, 2, 94, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dreghood Brute - On Data 3 3 Set - Set Faction 94"),
(16938, 0, 14, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 1693801, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dreghood Brute - On Data 3 3 Set - Run Script"),
(1693800, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dreghood Brute - On Script - Say Line 0"),
(1693800, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 89, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dreghood Brute - On Script - Random Movement"),
(1693800, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -613.50, 4800.21, 38.24, 0, "Dreghood Brute - On Script - Move To Pos"),
(1693800, 9, 3, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dreghood Brute - On Script - Despawn"),
(1693801, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 89, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dreghood Brute - On Script - Random Movement"),
(1693801, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -613.50, 4800.21, 38.24, 0, "Dreghood Brute - On Script - Move To Pos"),
(1693801, 9, 2, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dreghood Brute - On Script - Despawn");

DELETE FROM `creature_text` WHERE `CreatureID`=16938 AND `ID`=2;
DELETE FROM `creature_text` WHERE `CreatureID`=19477;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(16938, 0, 2, "I will do as you ask, demon.  At least for now.", 12, 0, 100, 0, 0, 0, 16470, 0, "Dreghood Brute"),
(19477, 0, 0, "The taskmaster's dead!  Quick, Dreghoods!  Run!", 12, 0, 100, 0, 0, 0, 13372, 0, "Dreghood Fleeing Warrior"),
(19477, 0, 1, "Flee!  Flee!", 12, 0, 100, 0, 0, 0, 13373, 0, "Dreghood Fleeing Warrior"),
(19477, 0, 2, "This is our chance!  Run for it!", 12, 0, 100, 0, 0, 0, 13374, 0, "Dreghood Fleeing Warrior");

DELETE FROM `creature_formations` WHERE `leaderGUID` IN (59451, 59453, 59464, 59456, 59452, 59462, 59463, 59454, 59455, 59459, 59458, 59460, 59457);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(59451, 59451, 0, 0, 3, 0, 0),
(59451, 58906, 0, 0, 3, 0, 0),
(59451, 58907, 0, 0, 3, 0, 0),
(59453, 59453, 0, 0, 3, 0, 0),
(59453, 58911, 0, 0, 3, 0, 0),
(59453, 58910, 0, 0, 3, 0, 0),
(59464, 59464, 0, 0, 3, 0, 0),
(59464, 58905, 0, 0, 3, 0, 0),
(59464, 58904, 0, 0, 3, 0, 0),
(59456, 59456, 0, 0, 3, 0, 0),
(59456, 58915, 0, 0, 3, 0, 0),
(59456, 58921, 0, 0, 3, 0, 0),
(59452, 59452, 0, 0, 3, 0, 0),
(59452, 58908, 0, 0, 3, 0, 0),
(59452, 58909, 0, 0, 3, 0, 0),
(59462, 59462, 0, 0, 3, 0, 0),
(59462, 58920, 0, 0, 3, 0, 0),
(59462, 58932, 0, 0, 3, 0, 0),
(59463, 59463, 0, 0, 3, 0, 0),
(59463, 58934, 0, 0, 3, 0, 0),
(59463, 58933, 0, 0, 3, 0, 0),
(59454, 59454, 0, 0, 3, 0, 0),
(59454, 58913, 0, 0, 3, 0, 0),
(59454, 58919, 0, 0, 3, 0, 0),
(59455, 59455, 0, 0, 3, 0, 0),
(59455, 58916, 0, 0, 3, 0, 0),
(59455, 58917, 0, 0, 3, 0, 0),
(59455, 58918, 0, 0, 3, 0, 0),
(59459, 59459, 0, 0, 3, 0, 0),
(59459, 58929, 0, 0, 3, 0, 0),
(59459, 58928, 0, 0, 3, 0, 0),
(59458, 59458, 0, 0, 3, 0, 0),
(59458, 58927, 0, 0, 3, 0, 0),
(59458, 58926, 0, 0, 3, 0, 0),
(59460, 59460, 0, 0, 3, 0, 0),
(59460, 58930, 0, 0, 3, 0, 0),
(59460, 58925, 0, 0, 3, 0, 0),
(59457, 59457, 0, 0, 3, 0, 0),
(59457, 58924, 0, 0, 3, 0, 0),
(59457, 58923, 0, 0, 3, 0, 0);
