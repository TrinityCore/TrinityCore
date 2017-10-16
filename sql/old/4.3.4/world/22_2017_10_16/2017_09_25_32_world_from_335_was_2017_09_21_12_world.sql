-- 
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-127435, -127426, 2663500, 2663501) AND `source_type` IN (0, 9);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-127435, 0, 0, 0, 10, 0, 100, 1, 0, 33, 0, 0, 80, 2663500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Risen Drakkari Warrior - On Data 1 1 Set - Run Script"),
(2663500, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Risen Drakkari Warrior - On Script - Say Line 0"),
(2663500, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 59, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Risen Drakkari Warrior - On Script - Set Run On"),
(2663500, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -333.6878, -568.8351, 11.0343, 0, "Risen Drakkari Warrior - On Script - Move To Pos"),
(2663500, 9, 3, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 45, 2, 2, 0, 0, 0, 0, 11, 26635, 30, 0, 0, 0, 0, 0, "Scourge Reanimator - On Death - Set Data 2 2 to nearby Risen Drakkari Warriors"),
(2663500, 9, 4, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Risen Drakkari Warrior - On Script - Despawn"),
(-127426, 0, 0, 0, 10, 0, 100, 1, 0, 33, 0, 0, 80, 2663501, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Risen Drakkari Warrior - On Data 1 1 Set - Run Script"),
(2663501, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Risen Drakkari Warrior - On Script - Say Line 1"),
(2663501, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 59, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Risen Drakkari Warrior - On Script - Set Run On"),
(2663501, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -329.69747, -640.4216, 11.78151, 0, "Risen Drakkari Warrior - On Script - Move To Pos"),
(2663501, 9, 4, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 45, 2, 2, 0, 0, 0, 0, 10, 127429, 26635, 0, 0, 0, 0, 0, "Scourge Reanimator - On Script - Set Data 2 2 to nearby Risen Drakkari Warriors"),
(2663501, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 10, 127439, 26636, 0, 0, 0, 0, 0, "Scourge Reanimator - On Script - Set Data 2 2 to nearby Risen Drakkari Warriors"),
(2663501, 9, 6, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Risen Drakkari Warrior - On Script - Despawn");

DELETE FROM `smart_scripts` WHERE `entryorguid`=26635 AND `source_type`=0 AND `id`>2;
DELETE FROM `smart_scripts` WHERE `entryorguid`=26636 AND `source_type`=0 AND `id`>6;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(26635, 0, 3, 0, 38, 0, 100, 1, 2, 2, 0, 0, 69, 1, 0, 0, 0, 0, 0, 8, 0, 0, 0, -368.4687, -602.0834, 2.2742, 0, "Risen Drakkari Warrior - On Script - Move To Pos"),
(26635, 0, 4, 0, 34, 0, 100, 0, 0, 1, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 90, 0, 0, 0, 0, 0, 0, "Risen Drakkari Warrior - On movement informer - start attack"),
(26636, 0, 7, 0, 38, 0, 100, 1, 2, 2, 0, 0, 69, 1, 0, 0, 0, 0, 0, 8, 0, 0, 0, -368.4687, -602.0834, 2.2742, 0, "Risen Drakkari Soulmage - On Script - Move To Pos"),
(26636, 0, 8, 0, 34, 0, 100, 0, 0, 1, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 90, 0, 0, 0, 0, 0, 0, "Risen Drakkari Soulmage - On movement informer - start attack");

DELETE FROM `creature_text` WHERE `CreatureID`=26635;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(26635, 0, 0, "Help mon! There's too many of dem!", 14, 0, 100, 0, 0, 0, 26538, 0, "Risen Drakkari Warrior"),
(26635, 1, 0, "Backup! We need backup!", 14, 0, 100, 0, 0, 0, 26537, 0, "Risen Drakkari Warrior");

UPDATE `creature` SET `unit_flags`=768 WHERE `guid` IN (127435, 127426);
UPDATE `creature` SET `MovementType`=0, spawndist=0 WHERE `guid` IN (127439);
