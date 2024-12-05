-- Ymirheim Updates
UPDATE `creature` SET `position_x`=7178.28, `position_y`=1939.18, `position_z`=558.933, `orientation`=5.497786998748779296 WHERE `guid`=121141;
UPDATE `creature_addon` SET `StandState`=1 WHERE `guid` IN (121141,121164);
UPDATE `waypoint_data` SET `id`=1214230 WHERE `id`=1211710;
UPDATE `creature` SET `position_x`=7151.5, `position_y`=1895.11, `position_z`=540.436, `orientation`=4.6, `MovementType`=2, `wander_distance`=0 WHERE `guid`=121423;
UPDATE `creature_addon` SET `path_id`=1214230 WHERE `guid`=121423;
UPDATE `creature` SET `equipment_id`=0, `position_x`=7211.31201171875, `position_y`=1803.10546875, `position_z`=527.7430419921875, `orientation`=4.660028934478759765, `MovementType`=0 WHERE `guid`=121137;
UPDATE `creature_addon` SET `SheathState`=0 WHERE `guid` IN (121137,121152);
UPDATE `creature` SET `position_x`=7185.58203125, `position_y`=1861.2357177734375, `position_z`=532.28070068359375, `orientation`=3.211405754089355468, `MovementType`=0 WHERE `guid`=121171;
UPDATE `creature` SET `position_x`=7263.79443359375, `position_y`=1664.0059814453125, `position_z`=443.9375, `orientation`=6.126105785369873046 WHERE `guid`=120901;
UPDATE `creature_addon` SET `path_id`=0, `StandState`=1 WHERE `guid`=121171;
UPDATE `creature` SET `equipment_id`=0 WHERE `guid` IN (121143,121152,121154);
UPDATE `creature_addon` SET `emote`=333 WHERE `guid`=121169;
UPDATE `creature_addon` SET `emote`=459 WHERE `guid` IN (121138,121159);
UPDATE `creature` SET `position_x`=6815.93408203125, `position_y`=1826.19189453125, `position_z`=578.795166015625, `orientation`=4.852015495300292968 WHERE `guid`=121159;
UPDATE `waypoint_data` SET `id`=1212370 WHERE `id`=1214690;
UPDATE `creature` SET `position_x`=7235.66, `position_y`=2026.75, `position_z`=574.407, `MovementType`=2, `wander_distance`=0 WHERE `guid`=121237;
UPDATE `creature` SET `position_x`=7178.044921875, `position_y`=1975.9620361328125, `position_z`=574.13299560546875, `orientation`=2.757620096206665039, `MovementType`=0 WHERE `guid`=121469;
UPDATE `creature_addon` SET `path_id`=0, `StandState`=8 WHERE `guid`=121469;
UPDATE `creature` SET `position_x`=7225.90966796875, `position_y`=1592.8804931640625, `position_z`=379.873382568359375, `orientation`=5.235987663269042968 WHERE `guid`=120902;
UPDATE `creature_addon` SET `StandState`=8 WHERE `guid`=120902;

DELETE FROM `creature_template_addon` WHERE `entry`=31262;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(31262, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, '59532');
DELETE FROM `creature_addon` WHERE `guid` IN (121229,121230,121231,121232,121233,121234,121235,121236,121237,121238,121239,121240);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(121229, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '59532'),
(121230, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, '59532'),
(121231, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, '59532'),
(121232, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, '59532'),
(121233, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, '59532'),
(121234, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, '59532'),
(121235, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, '59532'),
(121236, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, '59532'),
(121237, 1212370, 0, 0, 0, 0, 0, 0, 0, 0, 0, '59532'),
(121238, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '59532'),
(121239, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, '59532'),
(121240, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, '59532');

UPDATE `creature_template_addon` SET `AnimTier`=0, `auras`='54775' WHERE `entry`=31263;

-- Ymirheim Defender
SET @GUID=40296; -- 8 free guid needed
DELETE FROM `creature` WHERE `guid`=@GUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `StringId`, `VerifiedBuild`) VALUES
(@GUID, 31746, 571, 0, 0, 1, 1, 0, 1, 7320.869140625, 1710.2799072265625, 465.02459716796875, 0.78539818525314331, 300, 0, 0, 12600, 0, 0, 0, 0, 0, '', NULL, 57292);
DELETE FROM `creature_addon` WHERE `guid`=@GUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(@GUID, 0, 0, 0, 8, 0, 0, 1, 0, 0, 0, NULL);

-- Ymirheim Chosen Warrior
DELETE FROM `creature` WHERE `guid`=@GUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `StringId`, `VerifiedBuild`) VALUES
(@GUID+1, 31258, 571, 0, 0, 1, 1, 0, 1, 7248.92724609375, 1974.7469482421875, 570.17535400390625, 2.844886541366577148, 300, 0, 0, 12600, 0, 0, 0, 0, 0, '', NULL, 56819);
DELETE FROM `creature_addon` WHERE `guid`=@GUID+1;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(@GUID+1, 0, 0, 0, 0, 0, 0, 1, 0, 459, 0, NULL);

-- Ymirheim Chosen Warrior
DELETE FROM `creature` WHERE `guid`=@GUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `StringId`, `VerifiedBuild`) VALUES
(@GUID+2, 31258, 571, 0, 0, 1, 1, 0, 1, 7196.0791015625, 2003.345947265625, 575.2510986328125, 0.122173048555850982, 300, 0, 0, 12600, 0, 0, 0, 0, 0, '', NULL, 56819);
DELETE FROM `creature_addon` WHERE `guid`=@GUID+2;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(@GUID+2, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, NULL);

-- Ymirheim Chosen Warrior
DELETE FROM `creature` WHERE `guid`=@GUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `StringId`, `VerifiedBuild`) VALUES
(@GUID+3, 31258, 571, 0, 0, 1, 1, 0, 1, 7219.29541015625, 1893.203125, 567.2725830078125, 4.921828269958496093, 300, 0, 0, 12600, 0, 0, 0, 0, 0, '', NULL, 56819);
DELETE FROM `creature_addon` WHERE `guid`=@GUID+3;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(@GUID+3, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, NULL);

-- Ymirjar Element Shaper
DELETE FROM `creature` WHERE `guid`=@GUID+4;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `StringId`, `VerifiedBuild`) VALUES
(@GUID+4, 31267, 571, 0, 0, 1, 1, 0, 1, 7220.52978515625, 1889.025146484375, 567.76910400390625, 1.919862151145935058, 300, 0, 0, 10080, 8814, 0, 0, 0, 0, '', NULL, 56819);
DELETE FROM `creature_addon` WHERE `guid`=@GUID+4;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(@GUID+4, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, NULL);

-- Ymirheim Chosen Warrior
DELETE FROM `creature` WHERE `guid`=@GUID+5;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `StringId`, `VerifiedBuild`) VALUES
(@GUID+5, 31258, 571, 0, 0, 1, 1, 0, 1, 7147.21728515625, 1701.251953125, 477.1998291015625, 3.054326057434082031, 300, 0, 0, 12600, 0, 0, 0, 0, 0, '', NULL, 56819);
DELETE FROM `creature_addon` WHERE `guid`=@GUID+5;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(@GUID+5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, NULL);

-- Ymirjar Element Shaper
DELETE FROM `creature` WHERE `guid`=@GUID+6;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `StringId`, `VerifiedBuild`) VALUES
(@GUID+6, 31267, 571, 0, 0, 1, 1, 0, 1, 7141.1181640625, 1700.5926513671875, 477.7032470703125, 0.383972436189651489, 300, 0, 0, 10080, 8814, 0, 0, 0, 0, '', NULL, 56819);
DELETE FROM `creature_addon` WHERE `guid`=@GUID+6;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(@GUID+6, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, NULL);

-- Ymirheim Chosen Warrior
DELETE FROM `creature` WHERE `guid`=@GUID+7;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `StringId`, `VerifiedBuild`) VALUES
(@GUID+7, 31258, 571, 0, 0, 1, 1, 0, 1, 7122.36962890625, 1693.2943115234375, 478.649810791015625, 1.65806281566619873, 300, 0, 0, 12600, 0, 0, 0, 0, 0, '', NULL, 56819);
DELETE FROM `creature_addon` WHERE `guid`=@GUID+7;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(@GUID+7, 0, 0, 0, 0, 0, 0, 1, 0, 426, 0, NULL);

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (31267,31258);
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryorguid` = 3125800;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3125800, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 11, 58952, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ymirjar Chosen Warrior - On Script - Cast 'Drink Alcohol'"),
(3125800, 9, 1, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 0, 11, 58952, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ymirjar Chosen Warrior - On Script - Cast 'Drink Alcohol'");

DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = -121140;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-121140, 0, 0, 0, 1, 0, 100, 0, 5000, 5000, 30000, 30000, 0, 80, 3125800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ymirjar Chosen Warrior - OOC - Call Timed Actionlist");

DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = -121141;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-121141, 0, 0, 0, 1, 0, 100, 0, 5000, 5000, 30000, 30000, 0, 80, 3125800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ymirjar Chosen Warrior - OOC - Call Timed Actionlist");

DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = -(@GUID+1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-(@GUID+1), 0, 0, 0, 1, 0, 100, 0, 5000, 5000, 30000, 30000, 0, 80, 3125800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ymirjar Chosen Warrior - OOC - Call Timed Actionlist");

DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = -(@GUID+2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-(@GUID+2), 0, 0, 0, 1, 0, 100, 0, 5000, 5000, 30000, 30000, 0, 80, 3125800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ymirjar Chosen Warrior - OOC - Call Timed Actionlist");

DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = -121144;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-121144, 0, 0, 0, 1, 0, 100, 0, 5000, 5000, 30000, 30000, 0, 80, 3125800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ymirjar Chosen Warrior - OOC - Call Timed Actionlist");

DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = -121145;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-121145, 0, 0, 0, 1, 0, 100, 0, 5000, 5000, 30000, 30000, 0, 80, 3125800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ymirjar Chosen Warrior - OOC - Call Timed Actionlist");

DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = -121149;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-121149, 0, 0, 0, 1, 0, 100, 0, 5000, 5000, 30000, 30000, 0, 80, 3125800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ymirjar Chosen Warrior - OOC - Call Timed Actionlist");

DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = -(@GUID+7);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-(@GUID+7), 0, 0, 0, 1, 0, 100, 0, 5000, 5000, 30000, 30000, 0, 80, 3125800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ymirjar Chosen Warrior - OOC - Call Timed Actionlist");

DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = -121155;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-121155, 0, 0, 0, 1, 0, 100, 0, 5000, 5000, 30000, 30000, 0, 80, 3125800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ymirjar Chosen Warrior - OOC - Call Timed Actionlist");

DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = -121156;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-121156, 0, 0, 0, 1, 0, 100, 0, 5000, 5000, 30000, 30000, 0, 80, 3125800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ymirjar Chosen Warrior - OOC - Call Timed Actionlist");

DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = -121159;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-121159, 0, 0, 0, 1, 0, 100, 0, 5000, 5000, 30000, 30000, 0, 80, 3125800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ymirjar Chosen Warrior - OOC - Call Timed Actionlist");

DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = -121163;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-121163, 0, 0, 0, 1, 0, 100, 0, 5000, 5000, 30000, 30000, 0, 80, 3125800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ymirjar Chosen Warrior - OOC - Call Timed Actionlist");

DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = -121164;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-121164, 0, 0, 0, 1, 0, 100, 0, 5000, 5000, 30000, 30000, 0, 80, 3125800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ymirjar Chosen Warrior - OOC - Call Timed Actionlist");

DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = -121165;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-121165, 0, 0, 0, 1, 0, 100, 0, 5000, 5000, 30000, 30000, 0, 80, 3125800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ymirjar Chosen Warrior - OOC - Call Timed Actionlist");

DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = -121170;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-121170, 0, 0, 0, 1, 0, 100, 0, 5000, 5000, 30000, 30000, 0, 80, 3125800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ymirjar Chosen Warrior - OOC - Call Timed Actionlist");

DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = -121171;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-121171, 0, 0, 0, 1, 0, 100, 0, 5000, 5000, 30000, 30000, 0, 80, 3125800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ymirjar Chosen Warrior - OOC - Call Timed Actionlist");

-- Emotes
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=-121465;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-121465, 0, 0, 0, 1, 0, 100, 0, 4000, 4000, 17000, 17000, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ymirjar Element Shaper - OOC - Play Emote 1");

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=-121166;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-121166, 0, 0, 0, 1, 0, 100, 0, 5000, 5000, 17000, 17000, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ymirheim Chosen Warrior - OOC - Play Emote 1");

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=-121467;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-121467, 0, 0, 0, 1, 0, 100, 0, 4000, 4000, 17000, 17000, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ymirjar Element Shaper - OOC - Play Emote 1");

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=-121167;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-121167, 0, 0, 0, 1, 0, 100, 0, 5000, 5000, 17000, 17000, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ymirheim Chosen Warrior - OOC - Play Emote 1");

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=-(@GUID+6);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-(@GUID+6), 0, 0, 0, 1, 0, 100, 0, 4000, 4000, 17000, 17000, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ymirjar Element Shaper - OOC - Play Emote 1");

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=-(@GUID+5);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-(@GUID+5), 0, 0, 0, 1, 0, 100, 0, 5000, 5000, 17000, 17000, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ymirheim Chosen Warrior - OOC - Play Emote 1");

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=-(@GUID+4);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-(@GUID+4), 0, 0, 0, 1, 0, 100, 0, 4000, 4000, 17000, 17000, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ymirjar Element Shaper - OOC - Play Emote 1");

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=-(@GUID+3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-(@GUID+3), 0, 0, 0, 1, 0, 100, 0, 5000, 5000, 17000, 17000, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ymirheim Chosen Warrior - OOC - Play Emote 1");

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=-121468;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-121468, 0, 0, 0, 1, 0, 100, 0, 4000, 4000, 17000, 17000, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ymirjar Element Shaper - OOC - Play Emote 1");

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=-121172;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-121172, 0, 0, 0, 1, 0, 100, 0, 5000, 5000, 17000, 17000, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ymirheim Chosen Warrior - OOC - Play Emote 1");

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=-121410;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-121410, 0, 0, 0, 1, 0, 100, 0, 4000, 4000, 17000, 17000, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ymirjar Element Shaper - OOC - Play Emote 1");

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=-121139;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-121139, 0, 0, 0, 1, 0, 100, 0, 5000, 5000, 17000, 17000, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ymirheim Chosen Warrior - OOC - Play Emote 1");

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=-121455;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-121455, 0, 0, 0, 1, 0, 100, 0, 4000, 4000, 17000, 17000, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ymirjar Element Shaper - OOC - Play Emote 1");

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=-121162;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-121162, 0, 0, 0, 1, 0, 100, 0, 5000, 5000, 17000, 17000, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ymirheim Chosen Warrior - OOC - Play Emote 1");

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=-121451;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-121451, 0, 0, 0, 1, 0, 100, 0, 4000, 4000, 17000, 17000, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ymirjar Element Shaper - OOC - Play Emote 1");

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=-121158;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-121158, 0, 0, 0, 1, 0, 100, 0, 5000, 5000, 17000, 17000, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ymirheim Chosen Warrior - OOC - Play Emote 1");

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=-121453;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-121453, 0, 0, 0, 1, 0, 100, 0, 4000, 4000, 17000, 17000, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ymirjar Element Shaper - OOC - Play Emote 1");

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=-121160;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-121160, 0, 0, 0, 1, 0, 100, 0, 5000, 5000, 17000, 17000, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ymirheim Chosen Warrior - OOC - Play Emote 1");
