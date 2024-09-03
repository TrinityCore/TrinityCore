SET @CGUID := 7001518;
SET @SPAWNGROUP := 1257;

-- Creatures
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+6;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `StringId`,`VerifiedBuild`) VALUES
(@CGUID+0, 136161, 1862, 9424, 9424, '1,23,2,8', 0, 0, 0, 0, -524.88714599609375, -260.567718505859375, 182.55462646484375, 3.140421867370605468, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', 55664), -- Gorak Tul (Area: Waycrest Manor - Difficulty: Normal) CreateObject1 (Auras: 263332 - Death Realm Phase In)
(@CGUID+1, 138762, 1862, 9424, 9424, '1,23,2,8', 0, 0, 0, 0, -551.3211669921875, -226.387161254882812, 207.106109619140625, 3.295702457427978515, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', 55664), -- Lucille Waycrest (Area: Waycrest Manor - Difficulty: Normal) CreateObject2
(@CGUID+2, 136087, 1862, 9424, 9424, '1,23,2,8', 0, 0, 0, 0, -547.15277099609375, -227.881942749023437, 208.6376953125, 2.996758222579956054, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', 55664), -- Inquisitor Sterntide (Area: Waycrest Manor - Difficulty: Normal) CreateObject2
(@CGUID+3, 136086, 1862, 9424, 9424, '1,23,2,8', 0, 0, 0, 0, -548.65277099609375, -230.451385498046875, 208.2640838623046875, 3.138803482055664062, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', 55664), -- Inquisitor Mace (Area: Waycrest Manor - Difficulty: Normal) CreateObject2
(@CGUID+4, 136085, 1862, 9424, 9424, '1,23,2,8', 0, 0, 0, 0, -551.54339599609375, -230.234375, 207.130218505859375, 3.157088756561279296, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', 55664), -- Inquisitor Yorrick (Area: Waycrest Manor - Difficulty: Normal) CreateObject2
(@CGUID+5, 136094, 1862, 9424, 9424, '1,23,2,8', 0, 0, 0, 1, -549.638916015625, -228.805557250976562, 207.7095794677734375, 3.153450250625610351, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', 55664), -- Inquisitor Notley (Area: Waycrest Manor - Difficulty: Normal) CreateObject2
(@CGUID+6, 131864, 1862, 9424, 9424, '1,23,2,8', 0, 0, 0, 0, -448.16494750976562, -344.020843505859375, 152.5852508544921875, 3.358537197113037109, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, '', 55664); -- Gorak Tul (Area: Waycrest Manor - Difficulty: Normal) CreateObject2 (Auras: 272830 - Override Energy Bar Color)

DELETE FROM `creature_template_addon` WHERE `entry` IN (136161, 131864);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(136161, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '263332'), -- 136161 (Gorak Tul) - Death Realm Phase In
(131864, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '272830'); -- 131864 (Gorak Tul) - Override Energy Bar Color

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (138762, 136087, 136086, 136085, 136094, 136161);

-- Spawn groups
DELETE FROM `spawn_group_template` WHERE `groupId` = @SPAWNGROUP+0;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWNGROUP+0, 'Waycrest Manor - Group Spawns after kill Lord and Lady Waycrest', 4);

DELETE FROM `spawn_group` WHERE `groupId` = @SPAWNGROUP+0 AND `spawnType`=0;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWNGROUP+0, 0, @CGUID+0),
(@SPAWNGROUP+0, 0, @CGUID+1),
(@SPAWNGROUP+0, 0, @CGUID+2),
(@SPAWNGROUP+0, 0, @CGUID+3),
(@SPAWNGROUP+0, 0, @CGUID+4),
(@SPAWNGROUP+0, 0, @CGUID+5),
(@SPAWNGROUP+0, 0, @CGUID+6);

DELETE FROM `instance_spawn_groups` WHERE `instanceMapId`=1862 AND `bossStateId`=3;
INSERT INTO `instance_spawn_groups` (`instanceMapId`, `bossStateId`, `bossStates`, `spawnGroupId`, `flags`) VALUES
(1862, 3, 0x08, @SPAWNGROUP+0, 0x01);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=33 AND `SourceGroup`=0 AND `SourceEntry` = @SPAWNGROUP+0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(33, 0, @SPAWNGROUP+0, 0, 0, 11, 0, 14560, 1, 0, '', 0, 0, 0, '', 'Waycrest Manor - Spawn group after kill Lord and Lady Waycrest');

-- Sai
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=138762;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
-- Lucille Waycrest
(22, 2, 138762, 0, 0, 11, 0, 4485, 1, 0, '', 0, 0, 0, '', 'Scripted creature does Smart Script if you are Alliance Player'),
(22, 4, 138762, 0, 0, 11, 0, 4486, 1, 0, '', 0, 0, 0, '', 'Scripted creature does Smart Script if you are Horde Player');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=136161;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
-- Gorak Tul
(22, 2, 136161, 0, 0, 11, 0, 4486, 1, 0, '', 0, 0, 0, '', 'Scripted creature does Smart Script if you are Horde Player');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (138762, 136087, 136086, 136085, 136094, 136161) AND `source_type`= 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN  (13876200, 13876201, 13616100) AND `source_type`= 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(138762, 0, 0, 0, '', 63, 0, 100, 0, 0, 0, 0, 0, 0, '', 53, 0, 13876200, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Lucille Waycrest - On Just Created - Self: Start waypoint 13876200'),
(138762, 0, 1, 2, '', 40, 0, 100, 0, 6, 13876200, 0, 0, 0, '', 80, 13876200, 2, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Lucille Waycrest - On Waypoint Reached - Run Script (Alliance)'),
(138762, 0, 2, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 45, 0, 1, 0, 0, 0, 0, 0, NULL, 19, 136161, 0, 0, 0, NULL, 0, 0, 0, 0, 'Lucille Waycrest - Linked - Set Data 0 1 to Gorak Tul'),
(138762, 0, 3, 0, '', 40, 0, 100, 0, 6, 13876200, 0, 0, 0, '', 80, 13876201, 2, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Lucille Waycrest - On Waypoint Reached - Run Script (Horde)'),
(13876200, 9, 0, 0, '',  0, 0, 100, 0, 2500, 2500, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Lucille Waycrest - Talk'),
(13876201, 9, 0, 0, '',  0, 0, 100, 0, 17000, 17000, 0, 0, 0, '', 85, 267609, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Lucille Waycrest - Cast Self spell 267609'),

(136161, 0, 0, 0, '', 38, 0, 100, 0, 0, 1, 0, 0, 0, '', 80, 13616100, 2, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Gorak Tul - On Data Set - Action List'),
(136161, 0, 1, 0, '', 63, 0, 100, 0, 0, 1, 0, 0, 0, '', 85, 267643, 2, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Gorak Tul - Just Created - Cast Self spell 267643'),
(136161, 0, 2, 0, '', 40, 0, 100, 0, 8, 13616100, 0, 0, 0, '', 41, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Gorak Tul - On Waypoint Reached - Despawn'),
(13616100, 9, 0, 0, '', 0, 0, 100, 0, 5000, 5000, 0, 0, 0, '', 85, 267643, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Gorak Tul - Action list - Cast Self spell 267643'),

(136087, 0, 0, 0, '', 63, 0, 100, 0, 0, 0, 0, 0, 0, '', 53, 0, 13608700, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Inquisitor Sterntide - On Just Created - Self: Start waypoint 13608700'),
(136086, 0, 0, 0, '', 63, 0, 100, 0, 0, 0, 0, 0, 0, '', 53, 0, 13608600, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Inquisitor Mace - On Just Created - Self: Start waypoint 13608600'),
(136085, 0, 0, 0, '', 63, 0, 100, 0, 0, 0, 0, 0, 0, '', 53, 0, 13608500, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Inquisitor Yorrick - On Just Created - Self: Start waypoint 13608500'),
(136094, 0, 0, 0, '', 63, 0, 100, 0, 0, 0, 0, 0, 0, '', 53, 0, 13609400, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Inquisitor Notley - On Just Created - Self: Start waypoint 13609400');

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` = 138762;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(138762, 0, 0, 'At long last, the nightmare is over.', 12, 0, 100, 0, 0, 103813, 150450, 0, 'Lucille Waycrest to Lord Waycrest');

-- Conversation
DELETE FROM `conversation_template` WHERE `Id` IN (7353, 7352, 7351);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `ScriptName`, `VerifiedBuild`) VALUES
(7353, 16831, 0, '', 55664),
(7352, 16828, 0, 'conversation_waycrest_manor_waycrests_defeated', 55664),
(7351, 16825, 0, 'conversation_waycrest_manor_waycrests_defeated', 55664);

-- Alliance
DELETE FROM `conversation_actors` WHERE (`ConversationId`=7352 AND `Idx` IN (2,1,0));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(7352, 63754, @CGUID+3, 2, 0, 0, 0, 0, 55664), -- Full: 0x204128E8C084E580001FF700001A1299 Creature/0 R4170/S8183 Map: 1862 (Waycrest Manor) Entry: 136086 (Inquisitor Mace) Low: 1708697
(7352, 63753, @CGUID+1, 1, 0, 0, 0, 0, 55664), -- Full: 0x204128E8C0878280001FF700001A1299 Creature/0 R4170/S8183 Map: 1862 (Waycrest Manor) Entry: 138762 (Lucille Waycrest) Low: 1708697
(7352, 63794, @CGUID+0, 0, 0, 0, 0, 0, 55664); -- Full: 0x204128E8C084F840001FF700001A1123 Creature/0 R4170/S8183 Map: 1862 (Waycrest Manor) Entry: 136161 (Gorak Tul) Low: 1708323

DELETE FROM `conversation_line_template` WHERE `Id` IN (16959, 16958, 16957, 16956, 16955, 16954, 16830, 16829, 16828, 16838);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(16959, 0, 2, 0, 0, 55664),
(16958, 0, 2, 0, 0, 55664),
(16957, 0, 1, 0, 0, 55664),
(16956, 0, 0, 0, 1, 55664),
(16955, 0, 0, 0, 1, 55664),
(16954, 0, 0, 0, 1, 55664),
(16830, 0, 0, 0, 1, 55664),
(16829, 0, 1, 0, 0, 55664),
(16828, 0, 0, 0, 1, 55664);

-- Horde
DELETE FROM `conversation_actors` WHERE (`ConversationId`=7353 AND `Idx` IN (1,0)) OR (`ConversationId`=7351 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(7353, 63753, @CGUID+1, 1, 0, 0, 0, 0, 55664), -- Full: 0x204128E8C087828000212200001AD253 Creature/0 R4170/S8482 Map: 1862 (Waycrest Manor) Entry: 138762 (Lucille Waycrest) Low: 1757779
(7353, 63755, @CGUID+4, 0, 0, 0, 0, 0, 55664), -- Full: 0x204128E8C084E54000212200001AD253 Creature/0 R4170/S8482 Map: 1862 (Waycrest Manor) Entry: 136085 (Inquisitor Yorrick) Low: 1757779
(7351, 63794, @CGUID+0, 0, 0, 0, 0, 0, 55664); -- Full: 0x204128E8C084F84000212200001AD110 Creature/0 R4170/S8482 Map: 1862 (Waycrest Manor) Entry: 136161 (Gorak Tul) Low: 1757456

DELETE FROM `conversation_line_template` WHERE `Id` IN (16833, 16832, 16831, 16850, 16826, 16825);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(16833, 0, 1, 0, 0, 55664),
(16832, 0, 1, 0, 0, 55664),
(16831, 0, 0, 0, 0, 55664),
(16850, 0, 0, 0, 1, 55664),
(16826, 0, 0, 0, 1, 55664),
(16825, 0, 0, 0, 1, 55664);

-- Areatrigger
DELETE FROM `areatrigger_template` WHERE (`IsCustom`=0 AND `Id` = 17740);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES
(17740, 0, 0, 55664);

DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` = 13118);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(13118, 0, 17740, 0, 6, 0, 6328, 0, 0, -1, 0, 0, 0, 4000, 0, 3, 3, 0, 0, 0, 0, 0, 0, 'at_waycrest_manor_organ_missiles', 55664); -- Spell: 267643 (Organ Missiles)

DELETE FROM `spell_script_names` WHERE `spell_id`=267646;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(267646, 'spell_waycrest_manor_organ_missiles');

-- Waypoints
-- This waypoint is temporary/hacky
SET @ENTRY := 136161;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 2, 'Gorak Tul - Path after conversation');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -525.816, -261.41666, 188.96046, NULL, 0),
(@PATH, 1, -532.49304, -279.55383, 186.57698, NULL, 0),
(@PATH, 2, -526.13367, -292.1389, 185.22873, NULL, 0),
(@PATH, 3, -501.00696, -316.64932, 171.55269, NULL, 0),
(@PATH, 4, -488.12326, -329.7795, 161.65425, NULL, 0),
(@PATH, 5, -470.80383, -326.80557, 159.51692, NULL, 0),
(@PATH, 6, -460.06772, -335.67188, 158.33897, NULL, 0),
(@PATH, 7, -446.75, -343.94272, 155.77182, NULL, 0),
(@PATH, 8, -441.15625, -344.0955, 157.48708, NULL, 0);

SET @ENTRY := 138762;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Lucille Waycrest - Waypoint after kill Lord and Lady Waycrest');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -576.658, -233.9219, 197.6254, NULL, 0),
(@PATH, 1, -582.6268, -237.7361, 195.3508, NULL, 0),
(@PATH, 2, -587.4827, -243.8976, 192.537, NULL, 0),
(@PATH, 3, -590.5, -253.8906, 191.5288, NULL, 0),
(@PATH, 4, -583.9792, -260.2344, 190.5964, NULL, 0),
(@PATH, 5, -565.0886, -264.9757, 185.4709, NULL, 0),
(@PATH, 6, -558.1476, -267.7882, 185.3392, NULL, 0);

SET @ENTRY := 136087;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Inquisitor Sterntide - Waypoint after kill Lord and Lady Waycrest');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -577.0208, -235.2465, 197.0377, NULL, 0),
(@PATH, 1, -585.6526, -245.0657, 192.5897, NULL, 0),
(@PATH, 2, -590.1649, -261, 191.5423, NULL, 0),
(@PATH, 3, -580.2448, -264.4219, 189.3687, NULL, 0),
(@PATH, 4, -568.3368, -260.9826, 185.4756, NULL, 0),
(@PATH, 5, -554.7239, -271.4254, 185.3499, NULL, 0);

SET @ENTRY := 136086;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Inquisitor Mace - Waypoint after kill Lord and Lady Waycrest');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -570.8941, -231.8837, 199.6943, NULL, 0),
(@PATH, 1, -581.4688, -241.2448, 194.4376, NULL, 0),
(@PATH, 2, -585.0426, -246.8089, 191.8952, NULL, 0),
(@PATH, 3, -587.3195, -253.3472, 191.5772, NULL, 0),
(@PATH, 4, -564.6823, -257.8715, 185.4444, NULL, 0),
(@PATH, 5, -560.1285, -251.9306, 185.3985, NULL, 0);

SET @ENTRY := 136085;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Inquisitor Yorrick - Waypoint after kill Lord and Lady Waycrest');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -575.4132, -236.0208, 197.4444, NULL, 0),
(@PATH, 1, -581.4688, -241.2448, 194.4376, NULL, 0),
(@PATH, 2, -585.0426, -246.8089, 191.8952, NULL, 0),
(@PATH, 3, -582.809, -257.0538, 190.2229, NULL, 0),
(@PATH, 4, -564.6823, -257.8715, 185.4444, NULL, 0),
(@PATH, 5, -557.691, -255.8872, 185.3982, NULL, 0);

SET @ENTRY := 136094;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Inquisitor Notley - Waypoint after kill Lord and Lady Waycrest');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -577.0208, -235.2465, 197.0377, NULL, 0),
(@PATH, 1, -581.7917, -239.3819, 194.8577, NULL, 0),
(@PATH, 2, -585.6526, -245.0657, 192.5897, NULL, 0),
(@PATH, 3, -590.1649, -261, 191.5423, NULL, 0),
(@PATH, 4, -580.2448, -264.4219, 189.3687, NULL, 0),
(@PATH, 5, -564.283, -262.1788, 185.4568, NULL, 0),
(@PATH, 6, -554.6007, -262.5573, 185.4035, NULL, 0);
