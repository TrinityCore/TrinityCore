SET @CGUID := 7001517;
SET @SPAWNGROUPID := 1256;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 135322, 1762, 9526, 9526, '23,8,2', 0, 0, 0, 0, -1065.96875, 2641.5087890625, 796.115234375, 5.113396167755126953, 86400, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261); -- The Golden Serpent (Area: Kings' Rest - Difficulty: Heroic) CreateObject2)

-- Template
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'boss_the_golden_serpent' WHERE `entry` = 135322;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_animated_gold' WHERE `entry`= 135406;

UPDATE `creature` SET `StringId` = 'TempleEvent' WHERE `guid` IN (7001366, 7001357, 7001364, 7001359, 7001360, 7001358, 7001362, 7001353, 7001363, 7001352, 7001350);

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (135322 /*135322 (The Golden Serpent) - Golden Serpent Emerge State*/, 135406 /*135406 (Animated Gold) - Molten Gold*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(135322, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 135322 (The Golden Serpent)
(135406, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '265915'); -- 135406 (Animated Gold) - Molten Gold

DELETE FROM `spell_script_names` WHERE `spell_id` IN (265773, 265915);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(265773, 'spell_kings_rest_spit_gold'),
(265915, 'spell_kings_rest_molten_gold');

-- Spawngroup
DELETE FROM `spawn_group_template` WHERE `groupId` = @SPAWNGROUPID;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWNGROUPID, 'Kings Rest - Boss Golden Serpent', 0x04);

DELETE FROM `spawn_group` WHERE `groupId` = @SPAWNGROUPID AND `spawnType`= 0;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWNGROUPID, 0, @CGUID+0);

-- Areatrigger
DELETE FROM `areatrigger_template` WHERE (`Id`=17570 AND `IsCustom`=0);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES
(17570, 0, 0, 55261);

DELETE FROM `areatrigger_create_properties` WHERE (`Id`=12928 AND `IsCustom`=0);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `VerifiedBuild`) VALUES
(12928, 0, 17570, 0, 4, 0, 0, 0, 0, -1, 0, 336, 0, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 55261); -- Spell: 265915 (Molten Gold)

UPDATE `areatrigger_create_properties` SET `ScriptName` = 'at_kings_rest_molten_gold' WHERE (`Id`=12928 AND `IsCustom`=0);

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` = 135322;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(135322, 0, 0, '|TInterface\\ICONS\\INV_Misc_Gem_Pearl_04.blp:20|t The Golden Serpent absorbs an Animated Gold, gaining |cFFFF0000|Hspell:265991|h[Luster]|h|r!', 16, 0, 100, 0, 0, 0, 156383, 0, 'The Golden Serpent to Animated Gold');

-- Spelltarget condition
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 13) AND (`SourceEntry` IN (265991));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(13, 3, 265991, 0, 0, 51, 0, 5, 135322, 0, '', 0, 'Potential target of the spell is creature, entry is The Golden Serpent (135322)');

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`Entry`=135406 AND `DifficultyID`=23);
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`) VALUES
(135406, 23, 7, 0.200000002980232238, 1, 147450, 2097224, 128); -- Animated Gold

UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=135406 AND `DifficultyID`=23); -- 135406 (Animated Gold) - CanSwim

-- Path for Golden Serpent
SET @ENTRY := 135322;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 2, 0, 'The Golden Serpent - Intro Submerge Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1065.9688, 2641.5088, 776.11523, NULL, 0),
(@PATH, 1, -1065.9688, 2641.5088, 796.11523, NULL, 0),
(@PATH, 2, -1065.9688, 2641.5088, 816.11523, NULL, 0),
(@PATH, 3, -1065.9688, 2641.5088, 816.11523, NULL, 0);

SET @ENTRY := 135322;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 2, 0x02, 'The Golden Serpent - Intro Flying Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1064.7257, 2633.5278, 819.26984, NULL, 0),
(@PATH, 1, -1057.2899, 2629.4766, 820.6274, NULL, 0),
(@PATH, 2, -1052.3473, 2632.2317, 821.54755, NULL, 0),
(@PATH, 3, -1050.8108, 2639.5227, 821.841, NULL, 0),
(@PATH, 4, -1051.2969, 2645.2969, 822.05347, NULL, 0),
(@PATH, 5, -1053.8577, 2657.0027, 821.2045, NULL, 0),
(@PATH, 6, -1072.1163, 2661.9514, 820.30493, NULL, 0),
(@PATH, 7, -1084.0192, 2651.1016, 820.091, NULL, 0),
(@PATH, 8, -1089.3334, 2635.2275, 819.84454, NULL, 0),
(@PATH, 9, -1082.0764, 2621.9514, 819.26984, NULL, 0),
(@PATH, 10, -1058.8403, 2615.1667, 815.8778, NULL, 0);

SET @ENTRY := 135322;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 3, 0x02, 'The Golden Serpent - Intro Landing Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1058.8403, 2615.1667, 810.1519, NULL, 0);
