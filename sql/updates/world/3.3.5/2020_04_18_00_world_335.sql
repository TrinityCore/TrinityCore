-- 
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (14392,14721) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1439200,1472100,1439201,1472101) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14392, 0, 0, 0, 20, 0, 100, 0, 7784, 0, 0, 0, 0, 80, 1439200, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Overlord Runthak - On Quest 'The Lord of Blackrock' Finished - Run Script"),
(14392, 0, 1, 0, 20, 0, 100, 0, 7784, 0, 0, 0, 0, 80, 1439201, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Overlord Runthak - On Quest 'The Lord of Blackrock' Finished - Run Script"),
(1439200, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 83, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Overlord Runthak - On Script - Remove Npc Flag Questgiver"),
(1439200, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Overlord Runthak - On Script - Set Run Off"),
(1439200, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 1544, -4425.87, 10.9056, 3.323, "Overlord Runthak - On Script - Move To Position"),
(1439200, 9, 3, 0, 0, 0, 100, 0, 14000, 14000, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0.6367, "Overlord Runthak - On Script - Set Orientation 0,6367"),
(1439200, 9, 4, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 1, 0, 17000, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Overlord Runthak - On Script - Say Line 0"),
(1439200, 9, 5, 0, 0, 0, 100, 0, 17000, 17000, 0, 0, 0, 1, 1, 10000, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Overlord Runthak - On Script - Say Line 1"),
(1439200, 9, 6, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 70, 7200, 0, 0, 0, 0, 0, 14, 7229, 179881, 0, 0, 0, 0, 0, 0, "Overlord Runthak - On Script - respawn Gameobject"),
(1439200, 9, 7, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 20, 179881, 100, 0, 0, 0, 0, 0, 0, "Overlord Runthak - On Script - Activate Gameobject"),
(1439200, 9, 8, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 50, 179557, 5, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Overlord Runthak - On Script - Summon gob"),
-- (1439200, 9, 9, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 20, 179557, 50, 0, 0, 0, 0, 0, 0, "Overlord Runthak - On Script - Activate gob"),
(1439200, 9, 9, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 1568, -4405.87, 8.13371, 0.3434, "Overlord Runthak - On Script - Move To Position"),
(1439200, 9, 10, 0, 0, 0, 100, 0, 15000, 15000, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 3.31613, "Overlord Runthak - On Script - Set Orientation 3,,31613"),
(1439200, 9, 11, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 82, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Overlord Runthak - On Script - Add Npc Flag Questgiver"),
(1439201, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 83, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Overlord Runthak - On Script - Remove Npc Flag Questgiver"),
(1439201, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 1, 0, 17000, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Overlord Runthak - On Script - Say Line 0"),
(1439201, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 82, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Overlord Runthak - On Script - Add Npc Flag Questgiver"),
(14721, 0, 0, 0, 20, 0, 100, 0, 7782, 0, 0, 0, 0, 80, 1472100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Field Marshal Afrasiabi - On Quest 'The Lord of Blackrock' Finished - Run Script"),
(14721, 0, 1, 0, 20, 0, 100, 0, 7782, 0, 0, 0, 0, 80, 1472101, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Field Marshal Afrasiabi - On Quest 'The Lord of Blackrock' Finished - Run Script"),
(1472100, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 83, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Field Marshal Afrasiabi - On Script - Remove Npc Flag Questgiver"),
(1472100, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 0, 1, 0, 8000, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Field Marshal Afrasiabi - On Script - Say Line 0"),
(1472100, 9, 2, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 0, 1, 1, 10000, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Field Marshal Afrasiabi - On Script - Say Line 1"),
(1472100, 9, 3, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 70, 7200, 0, 0, 0, 0, 0, 14, 9389, 179882, 0, 0, 0, 0, 0, 0, "Field Marshal Afrasiabi - On Script - respawn Gameobject"),
(1472100, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 20, 179882, 100, 0, 0, 0, 0, 0, 0, "Field Marshal Afrasiabi - On Script - Activate Gameobject"),
(1472100, 9, 5, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 50, 179560, 5, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Field Marshal Afrasiabi - On Script - Summon gob"),
-- (1472100, 9, 6, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 20, 179560, 50, 0, 0, 0, 0, 0, 0, "Field Marshal Afrasiabi - On Script - Activate gob"),
(1472100, 9, 6, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 82, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Field Marshal Afrasiabi - On Script - Add Npc Flag Questgiver"),
(1472101, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 83, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Field Marshal Afrasiabi - On Script - Remove Npc Flag Questgiver"),
(1472101, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 0, 1, 0, 8000, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Field Marshal Afrasiabi - On Script - Say Line 0"),
(1472101, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 82, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Field Marshal Afrasiabi - On Script - Add Npc Flag Questgiver");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (14392, 14721);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 14392, 0, 0, 30, 1, 179881, 50, 0, 1, 0, 0, "", "SAI triggers only if the head of Nefarian is Not Spawned'"),
(22, 2, 14392, 0, 0, 30, 1, 179881, 50, 0, 0, 0, 0, "", "SAI triggers only if the head of Nefarian is Spawned'"),
(22, 1, 14721, 0, 0, 30, 1, 179882, 50, 0, 1, 0, 0, "", "SAI triggers only if the head of Nefarian is Not Spawned'"),
(22, 2, 14721, 0, 0, 30, 1, 179882, 50, 0, 0, 0, 0, "", "SAI triggers only if the head of Nefarian is Spawned'");

UPDATE `gameobject_template_addon` SET `faction`=1803 WHERE `entry`=179557;
UPDATE `gameobject_template_addon` SET `faction`=1802 WHERE `entry`=179560;
DELETE FROM `gameobject` WHERE `guid` IN (7229,9389) AND `id` IN (179881,179882);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(7229, 179881, 1, 0, 0, 1, 1, 1540.28, -4422.19, 7.0051, 5.22833, 0, 0, 0.9636297, 0.267241, -1, 255, 1, 0),
(9389, 179882, 0, 0, 0, 1, 1, -8925.57, 496.042, 103.767, 2.42801, 0, 0, 0.9636297, 0.267241, -1, 255, 1, 0);

-- Hacks: traps must cast heir spell once activated with the action 9
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry` IN (179560,179557);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (179560,179557) AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(179557, 1, 0, 0, 60, 0, 100, 1, 3000, 3000, 0, 0, 0, 11, 22888, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rallying Call - On Update - Cast Rallying Cry of the Dragonslayer"),
(179560, 1, 0, 0, 60, 0, 100, 1, 3000, 3000, 0, 0, 0, 11, 22888, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rallying Call - On Update - Cast Rallying Cry of the Dragonslayer");
