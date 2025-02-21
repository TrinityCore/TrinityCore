--
-- 
-- Silverpine Forest

SET @CGUID := 999999;
SET @OGUID := 999999;

-- 
-- The Sepulcher

-- Detect: Quest Invis Zone 4
DELETE FROM `spell_area` WHERE `spell` = 84184 AND `area` = 228 AND `quest_start` = 27098 AND `aura_spell`=0 AND `racemask` = 0 AND `gender` = 2;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES 
(84184, 228, 27098, 0, 0, 0, 2, 3, 66, 1);

-- Detect: Quest Invis Zone 8
DELETE FROM `spell_area` WHERE `spell` = 84706 AND `area` = 228 AND `quest_start` = 27098 AND `aura_spell`=0 AND `racemask` = 0 AND `gender` = 2;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES 
(84706, 228, 27098, 27290, 0, 0, 2, 3, 66, 11);

-- Warchief's Command Board
DELETE FROM `gameobject` WHERE `guid`=@OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 278347, 0, 130, 228, '0', 169, 0, 503.220489501953125, 1546.2430419921875, 129.4403839111328125, 3.275460481643676757, 0, 0, -0.99776077270507812, 0.066883839666843414, 120, 255, 0, 45745);

DELETE FROM `gameobject_addon` WHERE `guid`=@OGUID+0;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 0, 1, 8830, 0);

-- Lady Sylvanas Windrunner
DELETE FROM `creature` WHERE `guid`= @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES 
(@CGUID+0, 44365, 0, 130, 228, '0', 0, 169, 0, -1, 0, 0, 500.622, 1564.54, 128.34532, 4.2935099, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'npc_silverpine_sylvanas_windrunner_high_command_sepulcher', 45745);

DELETE FROM `creature_addon` WHERE `guid`= @CGUID+0;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(@CGUID+0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 3, '84183');

-- Arthura
UPDATE `creature_template` SET `unit_flags2` = 2107392, `VehicleId` = 1109  WHERE `entry` = 44610;

DELETE FROM `creature` WHERE `guid`= @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES 
(@CGUID+1, 44610, 0, 130, 228, '0', 0, 169, 0, -1, 0, 0, 499.993011474609375, 1570.6300048828125, 131.7693328857421875, 4.815308570861816406, 120, 0, 0, 0, 0, 0, 0, 2099200, 0, 0, 0, '', 45745);

DELETE FROM `creature_addon` WHERE `guid`= @CGUID+1;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(@CGUID+1, 0, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, '84705');

-- Agatha
DELETE FROM `creature` WHERE `guid`= @CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES 
(@CGUID+2, 44608, 0, 130, 228, '0', 0, 169, 0, -1, 0, 0, 505.1929931640625, 1574.030029296875, 132.09832763671875, 4.26351785659790039, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 45745);

DELETE FROM `creature_addon` WHERE `guid`= @CGUID+2;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(@CGUID+2, 0, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, '84183');

-- Daschla
UPDATE `creature_template` SET `unit_flags2` = 2099200, `HoverHeight` = 2.8 WHERE `entry` = 44609;

DELETE FROM `creature` WHERE `guid`= @CGUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES 
(@CGUID+3, 44609, 0, 130, 228, '0', 0, 169, 0, -1, 0, 0, 505.571014404296875, 1567.6600341796875, 132.6943206787109375, 3.7040863037109375, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 45745);

DELETE FROM `creature_addon` WHERE `guid`= @CGUID+3;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(@CGUID+3, 0, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, '84183');

-- High Warlord Cromush
DELETE FROM `creature_equip_template` WHERE `CreatureID` = 44640;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `ItemID2`, `ItemID3`, `VerifiedBuild`) VALUES
(44640, 1, 47031, 0, 0, 18019);

DELETE FROM `creature` WHERE `guid` = @CGUID+4;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES 
(@CGUID+4, 44640, 0, 130, 228, '0', 0, 169, 0, -1, 0, 1, 549.267, 1572.28, 131.53, 0.161007, 120, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, '', 45745);

SET @PATH := (@CGUID+4) * 10;
DELETE FROM `waypoint_data` WHERE `id` = @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(@PATH, 1, 515.137, 1568.67, 129.55, NULL, 0, 0, 0, 0, 0),
(@PATH, 2, 519.903, 1566.49, 130.313, NULL, 0, 0, 0, 0, 0),
(@PATH, 3, 525.076, 1567.01, 130.858, NULL, 0, 0, 0, 0, 0),
(@PATH, 4, 540.263, 1569.19, 131.486, NULL, 0, 0, 0, 0, 0),
(@PATH, 5, 550.385, 1572.59, 131.555, NULL, 0, 0, 0, 0, 0),
(@PATH, 6, 536.455, 1568.87, 131.395, NULL, 0, 0, 0, 0, 0),
(@PATH, 7, 526.833, 1567.98, 130.94, NULL, 0, 0, 0, 0, 0),
(@PATH, 8, 522.706, 1565.66, 130.711, NULL, 0, 0, 0, 0, 0),
(@PATH, 9, 516.704, 1567.92, 129.798, NULL, 0, 0, 0, 0, 0);

DELETE FROM `creature_addon` WHERE `guid` = @CGUID+4;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(@CGUID+4, @PATH, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 3, '84183');

-- Admiral Hatchet
DELETE FROM `creature` WHERE `guid` = @CGUID+5;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES 
(@CGUID+5, 44916, 0, 130, 228, '0', 0, 169, 0, -1, 0, 0, 492.516, 1527.46, 130.503, 5.52134, 120, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, '', 45745);

DELETE FROM `creature_addon` WHERE `guid` = @CGUID+5;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(@CGUID+5, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 3, '84183 83847');

-- Warlord Torok
DELETE FROM `creature` WHERE `guid` = @CGUID+6;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES 
(@CGUID+6, 44917, 0, 130, 228, '0', 0, 169, 0, -1, 0, 0, 494.368, 1529.64, 130.002, 5.41923, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 45745);

DELETE FROM `creature_addon` WHERE `guid` = @CGUID+6;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(@CGUID+6, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 3, '84183');

-- Karos Razok
UPDATE `creature_template` SET `gossip_menu_id`=4281 WHERE `entry`=2226;

UPDATE `gossip_menu` SET `VerifiedBuild`=45745 WHERE `MenuID`=2226;

-- Thom Denger (Mage Trainer)
UPDATE `creature_template` SET `gossip_menu_id`=14230 WHERE `entry`=49716;

DELETE FROM `gossip_menu` WHERE `MenuID`=14230;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(14230, 564, 45745),
(14230, 563, 45745);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=14230 AND `SourceEntry`=564 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=15 AND `ConditionTarget`=0 AND `ConditionValue1`=128 AND `ConditionValue2`=0 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(14, 14230, 564, 0, 0, 15, 0, 128, 0, 0, 0, 0, 0, '', 'Show npc text 15460 if player is a mage');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=14230 AND `SourceEntry`=563 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=15 AND `ConditionTarget`=0 AND `ConditionValue1`=128 AND `ConditionValue2`=0 AND `ConditionValue3`=0 AND `NegativeCondition`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(14, 14230, 563, 0, 0, 15, 0, 128, 0, 0, 1, 0, 0, '', 'Show npc text 15461 if player is not a mage');

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=14230 AND `OptionID`=8);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(14230, 8, 0, 'Enter the Proving Grounds', 74757, 0, 0, 0, 0, 0, NULL, 0, 45745);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=14230 AND `SourceEntry`=8 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=15 AND `ConditionTarget`=0 AND `ConditionValue1`=128 AND `ConditionValue2`=0 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 14230, 8, 0, 0, 15, 0, 128, 0, 0, 0, 0, 0, '', 'Show gossip option 8 if player is a mage');

SET @ENTRY := 49716;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (4971600, 4971601);
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 40, 0, 100, 0, 2, 3213390, 0, 0, 80, 4971600, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On wapoint 2 of path 3213390 reached - Self: Start timed action list id #4971600 (update out of combat) override existing // -inline'),
(@ENTRY * 100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1.81514, 'After 0 seconds - Self: Set orientation to 1.81514'),
(@ENTRY * 100, 9, 1, 0, 0, 0, 100, 0, 10500, 10500, 0, 0, 5, 397, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 10.5 seconds - Self: Play emote 397'),
(@ENTRY * 100, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 28, 93451, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Remove aura due to spell 93451'),
(@ENTRY, 0, 1, 0, 40, 0, 100, 0, 4, 3213390, 0, 0, 80, 4971601, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On wapoint 4 of path 3213390 reached - Self: Start timed action list id #4971601 (update out of combat) override existing // -inline'),
(@ENTRY * 100 + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1.81514, 'After 0 seconds - Self: Set orientation to 1.81514'),
(@ENTRY * 100 + 1, 9, 1, 0, 0, 0, 100, 0, 10500, 10500, 0, 0, 5, 397, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 10.5 seconds - Self: Play emote 397'),
(@ENTRY * 100 + 1, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 93451, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Cast spell 93451 on Self (limit to 1 target)');

SET @PATH := (321339) * 10;
DELETE FROM `waypoint_data` WHERE `id` = @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(@PATH, 1, 566.5, 1578.81, 132.699, NULL, 0, 0, 0, 0, 0),
(@PATH, 2, 564.833, 1578.28, 132.449, NULL, 21500, 0, 0, 0, 0),
(@PATH, 3, 566.5, 1578.81, 132.699, NULL, 0, 0, 0, 0, 0),
(@PATH, 4, 568.667, 1579.35, 132.449, NULL, 21500, 0, 0, 0, 0);

UPDATE `creature_template_addon` SET `path_id` = @PATH WHERE `entry` = @ENTRY;

-- Matt Bruxworthy (Hunter Trainer)
UPDATE `creature_template` SET `gossip_menu_id`=14189 WHERE `entry`=49958;

DELETE FROM `gossip_menu` WHERE `MenuID`=14189;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(14189, 15460, 45745),
(14189, 15461, 45745);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=14189 AND `SourceEntry`=15460 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=15 AND `ConditionTarget`=0 AND `ConditionValue1`=4 AND `ConditionValue2`=0 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(14, 14189, 15460, 0, 0, 15, 0, 4, 0, 0, 0, 0, 0, '', 'Show npc text 15460 if player is a hunter');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=14189 AND `SourceEntry`=15461 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=15 AND `ConditionTarget`=0 AND `ConditionValue1`=4 AND `ConditionValue2`=0 AND `ConditionValue3`=0 AND `NegativeCondition`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(14, 14189, 15461, 0, 0, 15, 0, 4, 0, 0, 1, 0, 0, '', 'Show npc text 15461 if player is not a hunter');

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=14189 AND `OptionID`=8);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(14189, 8, 0, 'Enter the Proving Grounds', 74757, 0, 0, 0, 0, 0, NULL, 0, 45745);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=14189 AND `SourceEntry`=8 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=15 AND `ConditionTarget`=0 AND `ConditionValue1`=4 AND `ConditionValue2`=0 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 14189, 8, 0, 0, 15, 0, 4, 0, 0, 0, 0, 0, '', 'Show gossip option 8 if player is a hunter');

-- Hobbes (Matt's Pet)
UPDATE `creature_template_addon` SET `StandState`=3, `auras`='34664' WHERE `entry`=49960; -- 49960 (Hobbes) - Sleep Visual - Flavor

UPDATE `creature_model_info` SET `BoundingRadius`=0.697653055191040039, `CombatReach`=1.316326498985290527, `VerifiedBuild`=45745 WHERE `DisplayID`=36686;

-- Angela Hipple (Rogue Trainer)
UPDATE `creature_template` SET `gossip_menu_id`=14232 WHERE `entry`=49870;

DELETE FROM `gossip_menu` WHERE `MenuID`=14232;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(14232, 581, 45745),
(14232, 4796, 45745);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=14232 AND `SourceEntry`=581 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=15 AND `ConditionTarget`=0 AND `ConditionValue1`=8 AND `ConditionValue2`=0 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(14, 14232, 581, 0, 0, 15, 0, 8, 0, 0, 0, 0, 0, '', 'Show npc text 581 if player is a rogue');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=14232 AND `SourceEntry`=4796 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=15 AND `ConditionTarget`=0 AND `ConditionValue1`=8 AND `ConditionValue2`=0 AND `ConditionValue3`=0 AND `NegativeCondition`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(14, 14232, 4796, 0, 0, 15, 0, 8, 0, 0, 1, 0, 0, '', 'Show npc text 4796 if player is not a rogue');

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=14232 AND `OptionID`=8);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(14232, 8, 0, 'Enter the Proving Grounds', 74757, 0, 0, 0, 0, 0, NULL, 0, 45745);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=14232 AND `SourceEntry`=8 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=15 AND `ConditionTarget`=0 AND `ConditionValue1`=8 AND `ConditionValue2`=0 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 14232, 8, 0, 0, 15, 0, 8, 0, 0, 0, 0, 0, '', 'Show gossip option 8 if player is a rogue');

-- Eugene Daller (Warrior Trainer)
UPDATE `creature_template` SET `gossip_menu_id`=14233 WHERE `entry`=49720;

DELETE FROM `gossip_menu` WHERE `MenuID`=14233;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(14233, 1219, 45745),
(14233, 4984, 45745);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=14233 AND `SourceEntry`=1219 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=15 AND `ConditionTarget`=0 AND `ConditionValue1`=1 AND `ConditionValue2`=0 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(14, 14233, 1219, 0, 0, 15, 0, 1, 0, 0, 0, 0, 0, '', 'Show npc text 1219 if player is a warrior');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=14233 AND `SourceEntry`=4984 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=15 AND `ConditionTarget`=0 AND `ConditionValue1`=1 AND `ConditionValue2`=0 AND `ConditionValue3`=0 AND `NegativeCondition`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(14, 14233, 4984, 0, 0, 15, 0, 1, 0, 0, 1, 0, 0, '', 'Show npc text 4984 if player is not a warrior');

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=14233 AND `OptionID`=8);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(14233, 8, 0, 'Enter the Proving Grounds', 74757, 0, 0, 0, 0, 0, NULL, 0, 45745);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=14233 AND `SourceEntry`=8 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=15 AND `ConditionTarget`=0 AND `ConditionValue1`=1 AND `ConditionValue2`=0 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 14233, 8, 0, 0, 15, 0, 1, 0, 0, 0, 0, 0, '', 'Show gossip option 8 if player is a warrior');

-- Bee Bruxworthy (Warlock Trainer)
UPDATE `creature_template` SET `gossip_menu_id`=14229 WHERE `entry`=49718;

DELETE FROM `gossip_menu` WHERE `MenuID`=14229;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(14229, 5719, 45745),
(14229, 5720, 45745);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=14229 AND `SourceEntry`=5719 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=15 AND `ConditionTarget`=0 AND `ConditionValue1`=256 AND `ConditionValue2`=0 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(14, 14229, 5719, 0, 0, 15, 0, 256, 0, 0, 0, 0, 0, '', 'Show npc text 5719 if player is a warlock');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=14229 AND `SourceEntry`=5720 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=15 AND `ConditionTarget`=0 AND `ConditionValue1`=256 AND `ConditionValue2`=0 AND `ConditionValue3`=0 AND `NegativeCondition`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(14, 14229, 5720, 0, 0, 15, 0, 256, 0, 0, 1, 0, 0, '', 'Show npc text 5720 if player is not a warlock');

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=14229 AND `OptionID`=8);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(14229, 8, 0, 'Enter the Proving Grounds', 74757, 0, 0, 0, 0, 0, NULL, 0, 45745);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=14229 AND `SourceEntry`=8 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=15 AND `ConditionTarget`=0 AND `ConditionValue1`=256 AND `ConditionValue2`=0 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 14229, 8, 0, 0, 15, 0, 256, 0, 0, 0, 0, 0, '', 'Show gossip option 8 if player is a warlock');

-- Dark Cleric Pordon (Priest Trainer)
SET @ENTRY := 49715;

UPDATE `creature` SET `MovementType` = 2 WHERE `guid` = 321300;

UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ENTRY;

UPDATE `creature_template_addon` SET `path_id` = 3213000 WHERE `entry` = @ENTRY;

DELETE FROM `gossip_menu` WHERE `MenuID`=14231;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(14231, 4441, 45745),
(14231, 4439, 45745);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=14231 AND `SourceEntry`=4441 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=15 AND `ConditionTarget`=0 AND `ConditionValue1`=16 AND `ConditionValue2`=0 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(14, 14231, 4441, 0, 0, 15, 0, 16, 0, 0, 0, 0, 0, '', 'Show npc text 4441 if player is a priest');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=14231 AND `SourceEntry`=4439 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=15 AND `ConditionTarget`=0 AND `ConditionValue1`=16 AND `ConditionValue2`=0 AND `ConditionValue3`=0 AND `NegativeCondition`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(14, 14231, 4439, 0, 0, 15, 0, 16, 0, 0, 1, 0, 0, '', 'Show npc text 4439 if player is not a priest');

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=14231 AND `OptionID`=8);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(14231, 8, 0, 'Enter the Proving Grounds', 74757, 0, 0, 0, 0, 0, NULL, 0, 45745);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=14231 AND `SourceEntry`=8 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=15 AND `ConditionTarget`=0 AND `ConditionValue1`=16 AND `ConditionValue2`=0 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 14231, 8, 0, 0, 15, 0, 16, 0, 0, 0, 0, 0, '', 'Show gossip option 8 if player is a priest');

DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 40, 0, 100, 0, 1, 3213000, 0, 0, 80, 4971500, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On waypoint 1 of path 3213000 reached - Self: Start timed action list id #4971500 (update out of combat)"),
(@ENTRY, 0, 1, 0, 40, 0, 100, 0, 8, 3213000, 0, 0, 80, 4971500, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On waypoint 8 of path 3213000 reached - Self: Start timed action list id #4971501 (update out of combat)");

SET @ENTRY := 4971500;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 6.23083, 'After 0 seconds - Self: Set orientation to 6.23083'),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 1500, 1500, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1.5 seconds - Self: Set stand state to KNEEL'),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 21500, 21500, 0, 0, 90, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 21.5 seconds - Self: Set stand state to STAND');

SET @PATH := (321300) * 10;
DELETE FROM `waypoint_data` WHERE `id` = @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(@PATH, 1, 513.2222, 1580.6649, 128.26967, NULL, 24000, 0, 0, 0, 0),
(@PATH, 2, 512.96875, 1584.3533, 127.91777, NULL, 0, 0, 0, 0, 0),
(@PATH, 3, 512.46875, 1589.1033, 127.41777, NULL, 0, 0, 0, 0, 0),
(@PATH, 4, 511.96875, 1593.3533, 127.16777, NULL, 0, 0, 0, 0, 0),
(@PATH, 5, 511.71875, 1596.6033, 126.91777, NULL, 0, 0, 0, 0, 0),
(@PATH, 6, 511.96875, 1597.6033, 126.91777, NULL, 0, 0, 0, 0, 0),
(@PATH, 7, 512.96875, 1598.3533, 126.91777, NULL, 0, 0, 0, 0, 0),
(@PATH, 8, 515.2153, 1599.0416, 126.56588, NULL, 24000, 0, 0, 0, 0),
(@PATH, 9, 513.3403, 1598.8047, 126.818375, NULL, 0, 0, 0, 0, 0),
(@PATH, 10, 511.84027, 1598.0547, 126.818375, NULL, 0, 0, 0, 0, 0),
(@PATH, 11, 511.59027, 1596.0547, 127.068375, NULL, 0, 0, 0, 0, 0),
(@PATH, 12, 511.84027, 1594.3047, 127.068375, NULL, 0, 0, 0, 0, 0),
(@PATH, 13, 512.9653, 1581.5677, 128.07088, NULL, 0, 0, 0, 0, 0);

-- Dreadguard
UPDATE `creature` SET `position_x` = 480.299, `position_y` = 1517.3049, `position_z` = 134.8754, `MovementType` = 2 WHERE `guid` = 321240;

SET @PATH := (321240) * 10;
DELETE FROM `waypoint_data` WHERE `id` = @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(@PATH, 1, 480.299, 1517.3049, 134.8754, NULL, 0, 0, 0, 0, 0),
(@PATH, 2, 480.799, 1518.3049, 134.3754, NULL, 0, 0, 0, 0, 0),
(@PATH, 3, 481.299, 1519.0549, 134.1254, NULL, 0, 0, 0, 0, 0),
(@PATH, 4, 482.049, 1520.8049, 133.6254, NULL, 0, 0, 0, 0, 0),
(@PATH, 5, 482.549, 1521.8049, 133.3754, NULL, 0, 0, 0, 0, 0),
(@PATH, 6, 483.549, 1523.5549, 132.8754, NULL, 0, 0, 0, 0, 0),
(@PATH, 7, 484.799, 1525.8049, 132.6254, NULL, 0, 0, 0, 0, 0),
(@PATH, 8, 485.79900, 1527.5549, 132.1254, NULL, 0, 0, 0, 0, 0),
(@PATH, 9, 487.09238, 1529.5917, 131.32819, NULL, 0, 0, 0, 0, 0),
(@PATH, 10, 487.84238, 1531.3417, 131.07819, NULL, 0, 0, 0, 0, 0),
(@PATH, 11, 488.34238, 1532.0917, 130.82819, NULL, 0, 0, 0, 0, 0),
(@PATH, 12, 489.59238, 1533.8417, 130.57819, NULL, 0, 0, 0, 0, 0),
(@PATH, 13, 490.59238, 1535.3417, 130.32819, NULL, 0, 0, 0, 0, 0),
(@PATH, 14, 495.0314, 1540.6221, 129.3741, NULL, 0, 0, 0, 0, 0),
(@PATH, 15, 496.71375, 1544.9521, 129.57129, NULL, 0, 0, 0, 0, 0),
(@PATH, 16, 496.46375, 1548.9521, 129.32129, NULL, 0, 0, 0, 0, 0),
(@PATH, 17, 496.46375, 1552.7021, 129.07129, NULL, 0, 0, 0, 0, 0),
(@PATH, 18, 496.21375, 1555.7021, 128.82129, NULL, 0, 0, 0, 0, 0),
(@PATH, 19, 496.15723, 1557.7905, 128.53928, NULL, 0, 0, 0, 0, 0),
(@PATH, 20, 496.15723, 1559.5405, 128.28928, NULL, 0, 0, 0, 0, 0),
(@PATH, 21, 496.15723, 1561.5405, 128.03928, NULL, 0, 0, 0, 0, 0),
(@PATH, 22, 495.90723, 1562.5405, 127.78928, NULL, 0, 0, 0, 0, 0),
(@PATH, 23, 495.90723, 1565.2905, 127.53928, NULL, 0, 0, 0, 0, 0),
(@PATH, 24, 495.65723, 1568.2905, 127.28928, NULL, 0, 0, 0, 0, 0),
(@PATH, 25, 495.40723, 1570.0405, 127.28928, NULL, 0, 0, 0, 0, 0),
(@PATH, 26, 495.40723, 1574.0405, 127.03928, NULL, 0, 0, 0, 0, 0),
(@PATH, 27, 495.15723, 1577.0405, 126.78928, NULL, 0, 0, 0, 0, 0),
(@PATH, 28, 494.66740, 1582.278, 126.15629, NULL, 0, 0, 0, 0, 0),
(@PATH, 29, 494.66740, 1582.528, 126.15629, NULL, 0, 0, 0, 0, 0),
(@PATH, 30, 495.41740, 1586.528, 125.90629, NULL, 0, 0, 0, 0, 0),
(@PATH, 31, 495.91740, 1592.278, 125.90629, NULL, 0, 0, 0, 0, 0),
(@PATH, 32, 496.36590, 1595.1321, 125.75896, NULL, 0, 0, 0, 0, 0),
(@PATH, 33, 498.11590, 1597.6321, 125.50896, NULL, 0, 0, 0, 0, 0),
(@PATH, 34, 500.11590, 1600.6321, 125.25896, NULL, 0, 0, 0, 0, 0),
(@PATH, 35, 502.96228, 1604.9263, 124.98854, NULL, 0, 0, 0, 0, 0),
(@PATH, 36, 508.26233, 1614.4675, 125.26756, NULL, 0, 0, 0, 0, 0),
(@PATH, 37, 508.26233, 1618.2175, 125.51756, NULL, 0, 0, 0, 0, 0),
(@PATH, 38, 508.23600, 1620.52, 125.551796, NULL, 0, 0, 0, 0, 0),
(@PATH, 39, 508.26144, 1617.5453, 125.3436, NULL, 0, 0, 0, 0, 0),
(@PATH, 40, 508.26144, 1614.2953, 125.0936, NULL, 0, 0, 0, 0, 0),
(@PATH, 41, 502.77737, 1604.5972, 125.28432, NULL, 0, 0, 0, 0, 0),
(@PATH, 42, 499.77737, 1599.8472, 125.28432, NULL, 0, 0, 0, 0, 0),
(@PATH, 43, 497.16608, 1596.2596, 125.68924, NULL, 0, 0, 0, 0, 0),
(@PATH, 44, 496.16608, 1594.7596, 125.68924, NULL, 0, 0, 0, 0, 0),
(@PATH, 45, 495.91608, 1590.7596, 125.93924, NULL, 0, 0, 0, 0, 0),
(@PATH, 46, 495.10205, 1584.9586, 126.34366, NULL, 0, 0, 0, 0, 0),
(@PATH, 47, 494.85205, 1582.2086, 126.59366, NULL, 0, 0, 0, 0, 0),
(@PATH, 48, 495.10205, 1579.2086, 126.84366, NULL, 0, 0, 0, 0, 0),
(@PATH, 49, 495.35205, 1574.4586, 127.09366, NULL, 0, 0, 0, 0, 0),
(@PATH, 50, 495.60205, 1571.7086, 127.09366, NULL, 0, 0, 0, 0, 0),
(@PATH, 51, 495.60205, 1568.7086, 127.34366, NULL, 0, 0, 0, 0, 0),
(@PATH, 52, 495.60205, 1566.7086, 127.59366, NULL, 0, 0, 0, 0, 0),
(@PATH, 53, 495.85205, 1564.7086, 127.84366, NULL, 0, 0, 0, 0, 0),
(@PATH, 54, 496.10205, 1561.7086, 128.09366, NULL, 0, 0, 0, 0, 0),
(@PATH, 55, 496.32523, 1559.1249, 128.62259, NULL, 0, 0, 0, 0, 0),
(@PATH, 56, 496.32523, 1557.1249, 128.62259, NULL, 0, 0, 0, 0, 0),
(@PATH, 57, 496.32523, 1555.1249, 128.87259, NULL, 0, 0, 0, 0, 0),
(@PATH, 58, 496.32523, 1551.3749, 129.12259, NULL, 0, 0, 0, 0, 0),
(@PATH, 59, 496.57523, 1547.3749, 129.37259, NULL, 0, 0, 0, 0, 0),
(@PATH, 60, 496.58823, 1544.7144, 129.73245, NULL, 0, 0, 0, 0, 0),
(@PATH, 61, 492.83823, 1538.9644, 129.98245, NULL, 0, 0, 0, 0, 0),
(@PATH, 62, 491.83823, 1537.4644, 130.23245, NULL, 0, 0, 0, 0, 0),
(@PATH, 63, 490.08823, 1534.9644, 130.48245, NULL, 0, 0, 0, 0, 0),
(@PATH, 64, 489.58823, 1533.9644, 130.73245, NULL, 0, 0, 0, 0, 0),
(@PATH, 65, 488.9079, 1532.977, 130.99368, NULL, 0, 0, 0, 0, 0),
(@PATH, 66, 488.4079, 1532.227, 131.24368, NULL, 0, 0, 0, 0, 0),
(@PATH, 67, 488.1579, 1531.977, 131.24368, NULL, 0, 0, 0, 0, 0),
(@PATH, 68, 487.1579, 1530.227, 131.74368, NULL, 0, 0, 0, 0, 0),
(@PATH, 69, 486.1579, 1528.477, 131.99368, NULL, 0, 0, 0, 0, 0),
(@PATH, 70, 485.1579, 1526.727, 132.49368, NULL, 0, 0, 0, 0, 0),
(@PATH, 71, 484.4079, 1524.977, 132.74368, NULL, 0, 0, 0, 0, 0),
(@PATH, 72, 483.4079, 1523.477, 132.99368, NULL, 0, 0, 0, 0, 0),
(@PATH, 73, 483.1579, 1522.477, 133.24368, NULL, 0, 0, 0, 0, 0),
(@PATH, 74, 482.1579, 1520.727, 133.74368, NULL, 0, 0, 0, 0, 0),
(@PATH, 75, 481.6579, 1519.977, 133.99368, NULL, 0, 0, 0, 0, 0),
(@PATH, 76, 481.1579, 1518.977, 134.49368, NULL, 0, 0, 0, 0, 0);

DELETE FROM `creature_addon` WHERE `guid`= 321240;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(321240, @PATH, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '18950');

-- Andrew Hilbert
UPDATE `npc_vendor` SET `slot`=502, `VerifiedBuild`=45745 WHERE (`entry`=3556 AND `item`=5786 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Murloc Scale Belt
UPDATE `npc_vendor` SET `slot`=501, `VerifiedBuild`=45745 WHERE (`entry`=3556 AND `item`=6272 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Blue Linen Robe
UPDATE `npc_vendor` SET `slot`=500, `VerifiedBuild`=45745 WHERE (`entry`=3556 AND `item`=5771 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Red Linen Bag
UPDATE `npc_vendor` SET `slot`=499, `VerifiedBuild`=45745 WHERE (`entry`=3556 AND `item`=5787 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Murloc Scale Breastplate
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=45745 WHERE (`entry`=3556 AND `item`=6892 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Smoked Bear Meat
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=45745 WHERE (`entry`=3556 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1); -- Light Parchment
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=45745 WHERE (`entry`=3556 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1); -- Bleach
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=45745 WHERE (`entry`=3556 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1); -- Nightcrawlers
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=45745 WHERE (`entry`=3556 AND `item`=6529 AND `ExtendedCost`=0 AND `type`=1); -- Shiny Bauble
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=45745 WHERE (`entry`=3556 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=45745 WHERE (`entry`=3556 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=45745 WHERE (`entry`=3556 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=45745 WHERE (`entry`=3556 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=45745 WHERE (`entry`=3556 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=45745 WHERE (`entry`=3556 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=45745 WHERE (`entry`=3556 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=45745 WHERE (`entry`=3556 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=45745 WHERE (`entry`=3556 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=45745 WHERE (`entry`=3556 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=45745 WHERE (`entry`=3556 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife

-- Lilly
UPDATE `npc_vendor` SET `slot`=1574, `VerifiedBuild`=45745 WHERE (`entry`=5757 AND `item`=6346 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Enchant Chest - Lesser Mana
UPDATE `npc_vendor` SET `slot`=1585, `VerifiedBuild`=45745 WHERE (`entry`=5757 AND `item`=22307 AND `ExtendedCost`=0 AND `type`=1); -- Pattern: Enchanted Mageweave Pouch
UPDATE `npc_vendor` SET `slot`=1584, `VerifiedBuild`=45745 WHERE (`entry`=5757 AND `item`=20753 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Lesser Wizard Oil
UPDATE `npc_vendor` SET `slot`=1583, `VerifiedBuild`=45745 WHERE (`entry`=5757 AND `item`=20752 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Minor Mana Oil
UPDATE `npc_vendor` SET `slot`=1582, `VerifiedBuild`=45745 WHERE (`entry`=5757 AND `item`=20758 AND `ExtendedCost`=0 AND `type`=1); -- Formula: Minor Wizard Oil
UPDATE `npc_vendor` SET `slot`=1581, `VerifiedBuild`=45745 WHERE (`entry`=5757 AND `item`=11291 AND `ExtendedCost`=0 AND `type`=1); -- Star Wood
UPDATE `npc_vendor` SET `slot`=1580, `VerifiedBuild`=45745 WHERE (`entry`=5757 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `slot`=1579, `VerifiedBuild`=45745 WHERE (`entry`=5757 AND `item`=10938 AND `ExtendedCost`=0 AND `type`=1); -- Lesser Magic Essence
UPDATE `npc_vendor` SET `slot`=1578, `maxcount`=3, `VerifiedBuild`=45745 WHERE (`entry`=5757 AND `item`=10940 AND `ExtendedCost`=0 AND `type`=1); -- Strange Dust
UPDATE `npc_vendor` SET `slot`=1577, `VerifiedBuild`=45745 WHERE (`entry`=5757 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod

-- Sarah Goode
UPDATE `creature_template` SET `gossip_menu_id`=9821 WHERE `entry`=9979;

-- Edwin Harly
UPDATE `npc_vendor` SET `slot`=74, `maxcount`=2, `VerifiedBuild`=45745 WHERE (`entry`=2140 AND `item`=858 AND `ExtendedCost`=0 AND `type`=1); -- Lesser Healing Potion
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=45745 WHERE (`entry`=2140 AND `item`=5042 AND `ExtendedCost`=0 AND `type`=1); -- Red Ribboned Wrapping Paper
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=45745 WHERE (`entry`=2140 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=45745 WHERE (`entry`=2140 AND `item`=4498 AND `ExtendedCost`=0 AND `type`=1); -- Brown Leather Satchel
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=45745 WHERE (`entry`=2140 AND `item`=4496 AND `ExtendedCost`=0 AND `type`=1); -- Small Brown Pouch
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=45745 WHERE (`entry`=2140 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=6739 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1); -- Ice Cold Milk
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=45745 WHERE (`entry`=2140 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=6739 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Refreshing Spring Water

-- Inkeeper Bates
UPDATE `creature_template` SET `gossip_menu_id`=348 WHERE `entry`=6739;

UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=45745 WHERE (`entry`=6739 AND `item`=8948 AND `ExtendedCost`=0 AND `type`=1); -- Dried King Bolete
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=45745 WHERE (`entry`=6739 AND `item`=4608 AND `ExtendedCost`=0 AND `type`=1); -- Raw Black Truffle
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=45745 WHERE (`entry`=6739 AND `item`=4607 AND `ExtendedCost`=0 AND `type`=1); -- Delicious Cave Mold
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=45745 WHERE (`entry`=6739 AND `item`=4606 AND `ExtendedCost`=0 AND `type`=1); -- Spongy Morel
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=45745 WHERE (`entry`=6739 AND `item`=4605 AND `ExtendedCost`=0 AND `type`=1); -- Red-Speckled Mushroom
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=45745 WHERE (`entry`=6739 AND `item`=4604 AND `ExtendedCost`=0 AND `type`=1); -- Forest Mushroom Cap
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=45745 WHERE (`entry`=6739 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1); -- Morning Glory Dew
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=45745 WHERE (`entry`=6739 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1); -- Moonberry Juice
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=45745 WHERE (`entry`=6739 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1); -- Sweet Nectar
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=45745 WHERE (`entry`=6739 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1); -- Melon Juice

-- Sebastian Meloche
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=45745 WHERE (`entry`=3553 AND `item`=850 AND `ExtendedCost`=0 AND `type`=1); -- Chainmail Gloves
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=45745 WHERE (`entry`=3553 AND `item`=1846 AND `ExtendedCost`=0 AND `type`=1); -- Chainmail Bracers
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=45745 WHERE (`entry`=3553 AND `item`=849 AND `ExtendedCost`=0 AND `type`=1); -- Chainmail Boots
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=45745 WHERE (`entry`=3553 AND `item`=848 AND `ExtendedCost`=0 AND `type`=1); -- Chainmail Pants
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=45745 WHERE (`entry`=3553 AND `item`=1845 AND `ExtendedCost`=0 AND `type`=1); -- Chainmail Belt
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=45745 WHERE (`entry`=3553 AND `item`=847 AND `ExtendedCost`=0 AND `type`=1); -- Chainmail Armor

-- Andrea Boynton
UPDATE `npc_vendor` SET `slot`=98, `VerifiedBuild`=45745 WHERE (`entry`=3554 AND `item`=4786 AND `ExtendedCost`=0 AND `type`=1); -- Wise Man's Belt
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=45745 WHERE (`entry`=3554 AND `item`=839 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Weave Gloves
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=45745 WHERE (`entry`=3554 AND `item`=3590 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Weave Bracers
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=45745 WHERE (`entry`=3554 AND `item`=840 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Weave Shoes
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=45745 WHERE (`entry`=3554 AND `item`=838 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Weave Pants
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=45745 WHERE (`entry`=3554 AND `item`=3589 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Weave Belt
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=45745 WHERE (`entry`=3554 AND `item`=837 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Weave Armor
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=45745 WHERE (`entry`=3554 AND `item`=16060 AND `ExtendedCost`=0 AND `type`=1); -- Common White Shirt
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=45745 WHERE (`entry`=3554 AND `item`=3428 AND `ExtendedCost`=0 AND `type`=1); -- Common Gray Shirt
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=45745 WHERE (`entry`=3554 AND `item`=16059 AND `ExtendedCost`=0 AND `type`=1); -- Common Brown Shirt

-- Astor Hadren
UPDATE `creature_template` SET `gossip_menu_id`=126 WHERE `entry`=6497;

-- Alexandre Lefevre
UPDATE `npc_vendor` SET `slot`=116, `VerifiedBuild`=45745 WHERE (`entry`=3552 AND `item`=4789 AND `ExtendedCost`=0 AND `type`=1); -- Stable Boots
UPDATE `npc_vendor` SET `slot`=115, `maxcount`=1, `VerifiedBuild`=45745 WHERE (`entry`=3552 AND `item`=4788 AND `ExtendedCost`=0 AND `type`=1); -- Agile Boots
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=45745 WHERE (`entry`=3552 AND `item`=844 AND `ExtendedCost`=0 AND `type`=1); -- Tanned Leather Gloves
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=45745 WHERE (`entry`=3552 AND `item`=1844 AND `ExtendedCost`=0 AND `type`=1); -- Tanned Leather Bracers
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=45745 WHERE (`entry`=3552 AND `item`=843 AND `ExtendedCost`=0 AND `type`=1); -- Tanned Leather Boots
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=45745 WHERE (`entry`=3552 AND `item`=845 AND `ExtendedCost`=0 AND `type`=1); -- Tanned Leather Pants
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=45745 WHERE (`entry`=3552 AND `item`=1843 AND `ExtendedCost`=0 AND `type`=1); -- Tanned Leather Belt
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=45745 WHERE (`entry`=3552 AND `item`=846 AND `ExtendedCost`=0 AND `type`=1); -- Tanned Leather Jerkin

-- Nadia Vernon
UPDATE `npc_vendor` SET `slot`=3, `maxcount`=1, `VerifiedBuild`=45745 WHERE (`entry`=9553 AND `item`=11304 AND `ExtendedCost`=0 AND `type`=1); -- Fine Longbow
UPDATE `npc_vendor` SET `slot`=2, `IgnoreFiltering`=1, `VerifiedBuild`=45745 WHERE (`entry`=9553 AND `item`=3026 AND `ExtendedCost`=0 AND `type`=1); -- Reinforced Bow
UPDATE `npc_vendor` SET `slot`=1, `IgnoreFiltering`=1, `VerifiedBuild`=45745 WHERE (`entry`=9553 AND `item`=2507 AND `ExtendedCost`=0 AND `type`=1); -- Laminated Recurve Bow
DELETE FROM `npc_vendor` WHERE `entry`=9553 AND `item`=5439;
DELETE FROM `npc_vendor` WHERE `entry`=9553 AND `item`=11362;

-- Gwyn Farrow
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=45745 WHERE (`entry`=5886 AND `item`=8948 AND `ExtendedCost`=0 AND `type`=1); -- Dried King Bolete
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=45745 WHERE (`entry`=5886 AND `item`=4608 AND `ExtendedCost`=0 AND `type`=1); -- Raw Black Truffle
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=45745 WHERE (`entry`=5886 AND `item`=4607 AND `ExtendedCost`=0 AND `type`=1); -- Delicious Cave Mold
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=45745 WHERE (`entry`=5886 AND `item`=4606 AND `ExtendedCost`=0 AND `type`=1); -- Spongy Morel
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=45745 WHERE (`entry`=5886 AND `item`=4605 AND `ExtendedCost`=0 AND `type`=1); -- Red-Speckled Mushroom
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=45745 WHERE (`entry`=5886 AND `item`=4604 AND `ExtendedCost`=0 AND `type`=1); -- Forest Mushroom Cap

-- Johan Focht
DELETE FROM `creature_trainer` WHERE `CreatureID`=3555;
INSERT INTO `creature_trainer` (`CreatureID`, `TrainerID`, `MenuID`, `OptionID`) VALUES
(3555, 91, 0, 0);

-- Guillaume Sorouy
UPDATE `creature_template` SET `npcflag`=17 WHERE `entry`=3557;

DELETE FROM `creature_trainer` WHERE `CreatureID`=3557;
INSERT INTO `creature_trainer` (`CreatureID`, `TrainerID`, `MenuID`, `OptionID`) VALUES
(3557, 27, 2749, 0);

-- Corpse-Fed Rat
UPDATE `creature` SET `wander_distance`=5, `MovementType`=1 WHERE `id`=50141;

-- Forest Ettin
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=4, `VerifiedBuild`=45745 WHERE `DisplayID`=30500;

-- Forsaken Catapult
UPDATE `creature_template` SET `unit_flags3`=0 WHERE `entry`=45198;

--
-- Vendors
DELETE FROM `npc_vendor` WHERE (`entry`=3556 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3556 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3556 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=3551 AND `item`=4565 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=5757 AND `item`=183951 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=5757 AND `item`=38682 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=2140 AND `item`=4541 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=2140 AND `item`=4540 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=6739 AND `item`=8952 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=6739 AND `item`=4599 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=6739 AND `item`=3771 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=6739 AND `item`=3770 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=6739 AND `item`=2287 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=6739 AND `item`=117 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(3556, 18, 39505, 0, 0, 1, 0, 0, 45745), -- Virtuoso Inking Set
(3556, 17, 20815, 0, 0, 1, 0, 0, 45745), -- Jeweler's Kit
(3556, 3, 85663, 0, 0, 1, 0, 0, 45745), -- Herbalist's Spade
(3551, 1, 4565, 0, 0, 1, 0, 0, 45745), -- Simple Dagger
(5757, 1576, 183951, 0, 0, 1, 0, 0, 45745), -- Immortal Shard
(5757, 1575, 38682, 0, 0, 1, 0, 0, 45745), -- Enchanting Vellum
(2140, 4, 4541, 0, 0, 1, 0, 0, 45745), -- Freshly Baked Bread
(2140, 3, 4540, 0, 0, 1, 0, 0, 45745), -- Tough Hunk of Bread
(6739, 18, 8952, 0, 0, 1, 0, 0, 45745), -- Roasted Quail
(6739, 17, 4599, 0, 0, 1, 0, 0, 45745), -- Cured Ham Steak
(6739, 16, 3771, 0, 0, 1, 0, 0, 45745), -- Wild Hog Shank
(6739, 15, 3770, 0, 0, 1, 0, 0, 45745), -- Mutton Chop
(6739, 14, 2287, 0, 0, 1, 0, 0, 45745), -- Haunch of Meat
(6739, 13, 117, 0, 0, 1, 0, 0, 45745); -- Tough Jerky

--
-- Olsen's Farthing

-- Detect Sparkle Aura
DELETE FROM `spell_area` WHERE `spell`=84459 AND `area`=229 AND `quest_start`=27180 AND `aura_spell`=0 AND `racemask`=0 AND `gender`=2;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES 
(84459, 229, 27180, 0, 0, 0, 2, 3, 8, 0);

-- Detect Exclamation!
DELETE FROM `spell_area` WHERE `spell`=86560 AND `area`=229 AND `quest_start`=27098 AND `aura_spell`=0 AND `racemask`=0 AND `gender`=2;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES 
(86560, 229, 27098, 27181, 0, 0, 2, 3, 64, 1);

-- Veteran Forsaken Trooper
UPDATE `creature_template` SET `npcflag` = 16777216, `pickpocketloot` = 45197, `ScriptName` = '' WHERE `entry` = 45197;

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 45197 AND `spell_id` = 84379;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
(45197, 84379, 1, 1);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup`=45197 AND `SourceEntry`=84379 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=47 AND `ConditionTarget`=0 AND `ConditionValue1`=27180 AND `ConditionValue2`=8 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(18, 45197, 84379, 0, 0, 47, 0, 27180, 8, 0, 0, 0, 0, '', 'Allow spellclick if quest 27180 is active');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=83756 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2`=45197 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 83756, 0, 0, 31, 0, 3, 45197, 0, 0, 0, 0, '', 'Collect Forsaken Insignia - Target Veteran Forsaken Trooper');

DELETE FROM `pickpocketing_loot_template` WHERE `Entry`=45197 AND `Item`=60862;
INSERT INTO `pickpocketing_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES 
(45197, 60862, 0, 100, 1, 1, 0, 1, 1, 'Forsaken Insignia');

-- Berard the Moon-Crazed
UPDATE `creature_template` SET `dynamicflags`=4, `ScriptName` = 'npc_silverpine_bloodfang_stalker' WHERE `entry` = 46992;

UPDATE `creature` SET `equipment_id`= 1 WHERE `guid` = 321162;

-- Bloodfang Stalker
UPDATE `creature_template` SET `ScriptName` = 'npc_silverpine_bloodfang_stalker' WHERE `entry` = 45195;

UPDATE `creature_template_addon` SET `auras` = '86237 86559' WHERE `entry` = 45195;

UPDATE `creature` SET `MovementType`= 1, `wander_distance`= 5 WHERE `id` = 45195;

UPDATE `creature` SET `MovementType`= 0, `wander_distance`= 0 WHERE `guid` = 321102;

-- Darktusk Boar
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=46575;

DELETE FROM `creature_template_movement` WHERE `CreatureId`=46575;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES 
(46575, 1, 1, 0, 0, 0, 0, NULL);

UPDATE `creature` SET `MovementType`=1, `wander_distance`=5 WHERE `id`=46575;

UPDATE `creature` SET `unit_flags`=262600, `MovementType`=0, `wander_distance`=0, `StringId`='darktusk_boar_dead' WHERE `guid`=321101;

DELETE FROM `creature_addon` WHERE `guid` = 321101;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(321101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '29266');

-- Caretaker Smithers
UPDATE `creature_template` SET `ScriptName`='npc_silverpine_caretaker_smithers' WHERE `entry`=45219;

DELETE FROM `creature_text` WHERE `CreatureID` = 45219;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(45219, 0, 0, 'Come to die, have you?', 12, 0, 100, 0, 0, 0, 0, 45368, 0, ''),
(45219, 1, 0, 'Shovel meet head!', 12, 0, 100, 0, 0, 0, 0, 45369, 0, ''),
(45219, 2, 0, '%s goes into a frenzy!', 16, 0, 100, 0, 0, 0, 0, 2384, 0, '');

-- Forsaken Catapult
-- Note: unit_flag3 = 1 seems related to being a PassiveAI, only the catapults that are using Permanent Feign Death have this flag, but it's not set by the spell or the REACT_STATE on TC, so we set it manually for now.
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry` IN (321185, 321177, 321159, 321154, 321143, 321142, 321119, 321103);

DELETE FROM `creature_addon` WHERE `guid` IN (321185, 321177, 321159, 321154, 321143, 321142, 321119, 321103);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(321185, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '84386'),
(321177, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '84386'),
(321159, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '84386'),
(321154, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '84386'),
(321143, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '84386'),
(321142, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '84386'),
(321119, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '84386'),
(321103, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '84386');

-- Permanent Feign Death
DELETE FROM `spell_script_names` WHERE `spell_id`=84386 AND `ScriptName`='spell_gen_feign_death_all_flags';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(84386, 'spell_gen_feign_death_all_flags');

-- Deathstalker
UPDATE `creature_template` SET `ScriptName`='' WHERE `ScriptName`='npc_silverpine_deathstalker';
