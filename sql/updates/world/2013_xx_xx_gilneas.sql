/* All data of gilneas */
-- First of all gilneas have 4 maps:
-- 638 [gilneas] -> starting zone with worgen attack
-- 654 [gilneas2] ->outside city forsaken invasion 
-- 655 - 656 -> after cataclism

-- worgen should start at map 638
UPDATE `playercreateinfo` SET  `map` = 638 WHERE `race` = 22;

-- move current creature spawns to correct place
UPDATE `creature` SET `map` = 638 WHERE `id` = 34850;
UPDATE `creature` SET `map` = 638 WHERE `id` = 34851;
UPDATE `creature` SET `map` = 638 WHERE `id` = 34864;
UPDATE `creature` SET `map` = 638 WHERE `id` = 34863;
UPDATE `creature` SET `map` = 638 WHERE `id` = 39095;
UPDATE `creature` SET `map` = 638 WHERE `id` = 44086;
UPDATE `creature` SET `map` = 638 WHERE `id` = 50260;

-- move current object spawns to correct place
UPDATE `gameobject` SET `map` = 638 WHERE `id` = 195581;
UPDATE `gameobject` SET `map` = 638 WHERE `id` = 195327;

-- scipts
UPDATE `creature_template` SET `ScriptName` = 'npc_prince_liam_greymane_1' WHERE `entry` = 34850;

DELETE FROM `creature_text` WHERE `entry` = 34850;
INSERT INTO `creature_text`(`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES 
(34850, 0, 0, 'Stand ready, guards! We don''t know how many intruders we''re dealing with, but the Headlands are overrun and we''re cut off from the harbor towns. Expect to be outnumbered.', 14, 0, 100, 0, 0, 19614, 'PRINCE_LIAM_GREYMANE_1_TALK_1'),
(34850, 1, 0, 'I want the perimeter secured and the gates manned by two guards at all times. No one gets in, no one gets out.', 14, 0, 100, 0, 0, 19615, 'PRINCE_LIAM_GREYMANE_1_TALK_2'),
(34850, 2, 0, 'We protected Gilneas from the Scourge. We protected Gilneas during the Northgate rebellion. We will protect Gilneas from whatever this new threat may be.', 14, 0, 100, 0, 0, 19616, 'PRINCE_LIAM_GREYMANE_1_TALK_3');

UPDATE `creature` SET `phaseMask` = `phaseMask` | 2 WHERE `id` = 34863;
UPDATE `gameobject` SET `phaseMask` = `phaseMask` | 2 | 4 WHERE `id` = 195581;
UPDATE `gameobject` SET `phaseMask` = `phaseMask` | 2 | 4 WHERE `id` = 195327;

-- From https://github.com/ProjectSkyfire/SkyFireEMU
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 34863;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 34863;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(34863, 0, 0, 1, 20, 0, 100, 0, 14078, 0, 0, 0, 75, 59073, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On Quest Reward (Lockdown), cast 59073 on player (to change to phase 2)'),
(34863, 0, 1, 0, 61, 0, 100, 0, 14078, 0, 0, 0, 103, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On Quest Reward (Lockdown), Force Character Save to DB');

-- creature spawns
SET @creatureguid   := ; -- trinity selection
DELETE FROM `creature` WHERE `guid` BETWEEN @creatureguid AND @creatureguid + 1;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(@creatureguid, 34936, 638, 1, 2, 0, 34936, -1465.22, 1403.52, 35.6392, 4.59022, 300, 0, 0, 42, 0, 0, 0, 0, 0),
(@creatureguid + 1, 34913, 638, 1, 2, 0, 663, -1447.71, 1409.8, 35.5561, 0.113226, 300, 0, 0, 42, 0, 0, 0, 134217728, 0);

-- creature addons 
INSERT INTO `CTworld`.`creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
('34913', '0', '2410', '1', '0', '0', NULL);

-- game objects spawns
SET @objectguid     := ; -- trinity selection
DELETE FROM `gameobject` WHERE `guid` BETWEEN @objectguid AND @objectguid + 22;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@objectguid + 0, 195306, 638, 1, 2, -1461.21, 1412.6, 35.556, 4.774, 0, 0, 0, 0, 60, 0, 1),
(@objectguid + 1, 195306, 638, 1, 2, -1485.84, 1442.07, 35.996, 1.55, 0, 0, 0, 0, 60, 0, 1),
(@objectguid + 2, 195306, 638, 1, 2, -1520.73, 1413.4, 35.556, 4.766, 0, 0, 0, 0, 60, 0, 1),
(@objectguid + 3, 195306, 638, 1, 2, -1452.65, 1441.38, 35.988, 1.558, 0, 0, 0, 0, 60, 0, 1),
(@objectguid + 4, 195306, 638, 1, 2, -1541.71, 1443.01, 36.013, 1.66, 0, 0, 0, 0, 60, 0, 1),
(@objectguid + 5, 195306, 638, 1, 2, -1560.58, 1418.01, 35.819, 3.164, 0, 0, 0, 0, 60, 0, 1),
(@objectguid + 6, 195306, 638, 1, 2, -1575.28, 1391.69, 36.644, 3.168, 0, 0, 0, 0, 60, 0, 1),
(@objectguid + 7, 195306, 638, 1, 2, -1545.43, 1374.22, 36.004, 0.0463, 0, 0, 0, 0, 60, 0, 1),
(@objectguid + 8, 195306, 638, 1, 2, -1585.61, 1355.98, 35.712, 3.171, 0, 0, 0, 0, 60, 0, 1),
(@objectguid + 9, 195306, 638, 1, 2, -1512.01, 1367.51, 35.999, 3.164, 0, 0, 0, 0, 60, 0, 1),
(@objectguid + 10, 195306, 638, 1, 2, -1523.08, 1407.03, 35.556, 1.86, 0, 0, 0, 0, 60, 0, 1),
(@objectguid + 11, 195306, 638, 1, 2, -1527.41, 1380.07, 36.003, 4.715, 0, 0, 0, 0, 60, 0, 1),
(@objectguid + 12, 195306, 638, 1, 2, -1477.97, 1380.21, 36.004, 4.664, 0, 0, 0, 0, 60, 0, 1),
(@objectguid + 13, 195306, 638, 1, 2, -1476.91, 1406.65, 35.556, 1.655, 0, 0, 0, 0, 60, 0, 1),
(@objectguid + 14, 195306, 638, 1, 2, -1479.27, 1362.66, 36.047, 1.566, 0, 0, 0, 0, 60, 0, 1),
(@objectguid + 15, 195306, 638, 1, 2, -1429.77, 1442.78, 36.002, 1.558, 0, 0, 0, 0, 60, 0, 1),
(@objectguid + 16, 195306, 638, 1, 2, -1462.17, 1375.44, 36.004, 3.191, 0, 0, 0, 0, 60, 0, 1),
(@objectguid + 17, 195306, 638, 1, 2, -1429.44, 1396.74, 36.003, 6.172, 0, 0, 0, 0, 60, 0, 1),
(@objectguid + 18, 195306, 638, 1, 2, -1394.03, 1438.88, 35.96, 3.136, 0, 0, 0, 0, 60, 0, 1),
(@objectguid + 19, 195306, 638, 1, 2, -1412.7, 1404.44, 36.004, 3.168, 0, 0, 0, 0, 60, 0, 1),
(@objectguid + 20, 195306, 638, 1, 2, -1383.02, 1379.27, 35.961, 6.27, 0, 0, 0, 0, 60, 0, 1),
(@objectguid + 21, 195306, 638, 1, 2, -1423.77, 1381.2, 35.998, 4.71, 0, 0, 0, 0, 60, 0, 1),
(@objectguid + 22, 195306, 638, 1, 2, -1455.53, 1344.04, 35.879, 3.352, 0, 0, 0, 0, 60, 0, 1);
