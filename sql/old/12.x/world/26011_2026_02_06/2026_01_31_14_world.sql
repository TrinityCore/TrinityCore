SET @ATSPAWN := 276;
SET @ATPROP := 171;
SET @ATID := 180;

-- Creature
DELETE FROM `creature_template_addon` WHERE `entry`=97720;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(97720, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''); -- 97720 (Blightshard Skitter)

UPDATE `creature_template` SET `faction`=16, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags2`=0x820, `unit_flags3`=0x80000 WHERE `entry`=97720; -- Blightshard Skitter
UPDATE `creature_template` SET `unit_flags`=0x8140, `ScriptName` = 'boss_rokmora' WHERE `entry`=91003;
UPDATE `creature_template` SET `ScriptName` = 'npc_rokmora_navarrogg_intro' WHERE `entry` = 100700;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (105300, 97720);

-- Difficulty
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=100700 AND `DifficultyID`=0); -- 100700 (Navarrogg) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=97720 AND `DifficultyID`=23); -- 97720 (Blightshard Skitter) - CanSwim

-- Areatrigger
DELETE FROM `areatrigger` WHERE `SpawnId`=@ATSPAWN;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `ScriptName`, `Comment`, `VerifiedBuild`) VALUES
(@ATSPAWN, @ATPROP, 1, 1458, '23,2,8,1', 2921.3066, 1394.1822, -2.4048, 5.180378, 0, 0, 0, 'at_rokmora_intro', 'Neltharion\'s Lair - Rokmora Intro', 0);

DELETE FROM `areatrigger_create_properties` WHERE `Id`=@ATPROP AND `IsCustom`=1;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(@ATPROP, 1, @ATID, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 0, 20, 20, 0, 0, 0, 0, 0, 0, '', 0);

DELETE FROM `areatrigger_template` WHERE `Id`=@ATID AND `IsCustom`=1;
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `ActionSetId`, `ActionSetFlags`, `VerifiedBuild`) VALUES
(@ATID, 1, 1, 0, 0, 0);

DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` IN (4953,7415));
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(4953, 0, 9669, 0, 0, 0, 0, 0, 0, -1, 0, 426, NULL, 300000, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 'at_rokmora_choking_dust', 61967), -- Spell: 192799 (Choking Dust)
(7415, 0, 11860, 0, 2, 0, 1958, 0, 0, -1, 0, 64, NULL, 10000, 0, 0, 45, 45, 0, 0, 0, 0, 0, 0, 'at_rokmora_crystalline_ground', 61967); -- Spell: 216470 (Crystalline Ground)

-- Instance
DELETE FROM `instance_template` WHERE `map`=1458;
INSERT INTO `instance_template` (`map`, `parent`, `script`) VALUES
(1458, 0, 'instance_neltharions_lair');

-- Conversation
DELETE FROM `conversation_actors` WHERE (`Idx`=0 AND `ConversationId` IN (1885, 822, 823, 824, 825) OR (`Idx`=1 AND `ConversationId` IN (1885)));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(822, 50446, 6004276, 0, 0, 0, 0, 0, 61967), -- Full: 0x20197CB64058DEC0006D9F00000266A8 Creature/0 R1631/S28063 Map: 1458 (Neltharion's Lair) Entry: 91003 (Rokmora) Low: 157352
(823, 50446, 6004276, 0, 0, 0, 0, 0, 61967), -- Full: 0x20197CB64058DEC0006D9F00000266A8 Creature/0 R1631/S28063 Map: 1458 (Neltharion's Lair) Entry: 91003 (Rokmora) Low: 157352
(824, 50446, 6004276, 0, 0, 0, 0, 0, 61967), -- Full: 0x20197CB64058DEC0006D9F00000266A8 Creature/0 R1631/S28063 Map: 1458 (Neltharion's Lair) Entry: 91003 (Rokmora) Low: 157352
(825, 50446, 6004276, 0, 0, 0, 0, 0, 61967), -- Full: 0x20197CB64058DEC0006D9F00000266A8 Creature/0 R1631/S28063 Map: 1458 (Neltharion's Lair) Entry: 91003 (Rokmora) Low: 157352
(1885, 52526, 6004308, 0, 105300, 0, 0, 0, 61967), -- Full: 0x20197CB64066D500006D9F00000266A8 Creature/0 R1631/S28063 Map: 1458 (Neltharion's Lair) Entry: 105300 (Ularogg Cragshaper) Low: 157352
(1885, 52530, 0, 1, 100700, 0, 0, 0, 61967); -- Full: 0x20197CB640625700006D9F00000266FB Creature/0 R1631/S28063 Map: 1458 (Neltharion's Lair) Entry: 100700 (Navarrogg) Low: 157435

DELETE FROM `conversation_template` WHERE `Id` IN (822, 823, 824, 825, 1885);
INSERT INTO `conversation_template` (`Id`, `FirstLineId`, `TextureKitId`, `Flags`, `ScriptName`, `VerifiedBuild`) VALUES
(822, 2010, 0, 0, '', 61967),
(823, 2011, 0, 0, '', 61967),
(824, 2012, 0, 0, '', 61967),
(825, 2013, 0, 0, '', 61967),
(1885, 3990, 0, 0, 'conversation_rokmora_intro', 61967);

DELETE FROM `conversation_line_template` WHERE `Id` IN (3992, 3991, 3990, 2013, 2012, 2011, 2010);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(2010, 0, 0, 0, 1, 61967),
(2011, 0, 0, 0, 1, 61967),
(2012, 0, 0, 0, 1, 61967),
(2013, 0, 0, 0, 1, 61967),
(3992, 0, 0, 0, 1, 61967),
(3991, 0, 1, 0, 1, 61967),
(3990, 0, 0, 0, 1, 61967);

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` = 91003;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(91003, 0, 0, 'Rok SMASH!', 14, 0, 100, 0, 0, 54551, 102714, 0, 'Rokmora'),
(91003, 1, 0, 'Rokmora creates |cFFFF0000|Hspell:215898|h[Crystaline Ground]|h|r! Don\'t move!', 41, 0, 100, 0, 0, 0, 114681, 0, 'Rokmora'),
(91003, 2, 0, 'Rokmora rears back for |cFFFF0000|Hspell:188169|h[Razor Shards]|h|r!', 41, 0, 100, 0, 0, 0, 108748, 0, 'Rokmora'),
(91003, 3, 0, 'Rok... no... break', 14, 0, 100, 0, 0, 54549, 102713, 0, 'Rokmora');

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (209390, 200247);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 209390, 0, 0, 51, 0, 5, 91003, 0, '', 0, 0, 0, '', 'Spell \'Boss 01 Intro Ularogg Cast\' can only hit Rokmora'),
(13, 1, 200247, 0, 0, 51, 0, 5, 97720, 0, '', 0, 0, 0, '', 'Spell \'Shatter\' can only hit \'Blightshard Skitter\'');

-- SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=105300 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(105300, 0, 0, 0, '', 63, 0, 100, 0, 0, 0, 0, 0, 0, '', 85, 209390, 2, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Ularogg - On Just Created - Cast Self: Boss 01 Intro Ularogg Cast'),
(105300, 0, 1, 0, '', 40, 0, 100, 0, 5, 10530000, 0, 0, 0, '', 41, 1, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Ularogg - On waypoint 5 reached - Despawn');

DELETE FROM `smart_scripts` WHERE `entryorguid`=97720 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(97720, 0, 0, 0, '', 6, 0, 100, 0, 0, 0, 0, 0, 0, '', 85, 192799, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Blightshard Skitter - On Just Died - Cast \'Choking Dust\''),
(97720, 0, 1, 0, '2,8,23', 6, 0, 100, 0, 0, 0, 0, 0, 0, '', 85, 215929, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Blightshard Skitter (Difficulties Heroic, Mythic and M+) - On Just Died - Cast \'Rupturing Skitter\'');

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_rokmora_crystalline_ground_periodic', 'spell_rokmora_emerge', 'spell_rokmora_razor_shards', 'spell_rokmora_shatter', 'spell_rokmora_update_interactions');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(215898, 'spell_rokmora_crystalline_ground_periodic'),
(209394, 'spell_rokmora_emerge'),
(188169, 'spell_rokmora_razor_shards'),
(188114, 'spell_rokmora_shatter'),
(134730, 'spell_rokmora_update_interactions');

-- Waypoints
SET @ENTRY := 105300;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Neltharion\'s Lair - Ularogg Rokmora Intro Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2884.442, 1397.453, -2.405085, NULL, 0),
(@PATH, 1, 2871.429, 1382.59, -2.403809, NULL, 0),
(@PATH, 2, 2864.82, 1372.012, -2.044964, NULL, 0),
(@PATH, 3, 2847.353, 1358.851, -0.1555594, NULL, 0),
(@PATH, 4, 2828.669, 1352.583, 0.9565357, NULL, 0),
(@PATH, 5, 2816.361, 1353.323, 4.334983, NULL, 0);

SET @ENTRY := 100700;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Neltharion\'s Lair - Navarrogg Rokmora Intro Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2899.39, 1406.309, -2.405086, NULL, 0),
(@PATH, 1, 2886.757, 1399.142, -2.405085, NULL, 0),
(@PATH, 2, 2876.358, 1391.255, -2.405085, NULL, 0),
(@PATH, 3, 2865.902, 1373.759, -2.163703, NULL, 0),
(@PATH, 4, 2858.577, 1366.91, -1.52154, NULL, 0),
(@PATH, 5, 2840.839, 1355.285, -0.3443635, NULL, 0),
(@PATH, 6, 2830.136, 1352.953, 0.7276564, NULL, 0),
(@PATH, 7, 2822.574, 1353.08, 2.647024, NULL, 0);
