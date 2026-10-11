SET @OGUID := 2000000;
SET @CGUID := 2000000;
SET @SPAWN_GROUP := 1270;

SET @AT_WIDTH := 10;
SET @AT_LENGTH := 35;
SET @AT_HEIGHT := 15;
SET @AT_ID := 167;
SET @AT_PROP_ID := 161;
SET @AT_SPAWN_ID = 263;

DELETE FROM `spawn_group_template` WHERE `groupId` = @SPAWN_GROUP;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWN_GROUP, 'Dalaran Arena - Shadow Sight', 0x20);

DELETE FROM `spawn_group` WHERE `groupId` = @SPAWN_GROUP;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWN_GROUP, 1, @OGUID+4),
(@SPAWN_GROUP, 1, @OGUID+5);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 33 AND `SourceEntry` = @SPAWN_GROUP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `SourceGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ScriptName`) VALUES
(33, @SPAWN_GROUP, 0, 22, 617, 'condition_is_shadow_sight_enabled');

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+5;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 192643, 617, 4378, 4378, 0, 0, 0, 1232.58544921875, 764.8028564453125, 21.58008766174316406, 0, 0, 0, 0, 1, 7200, 255, 1, 61967), -- Doodad_Dalaran_SewerDoor_02 (Area: Dalaran Arena - Difficulty: 0) CreateObject1
(@OGUID+1, 192642, 617, 4378, 4378, 0, 0, 0, 1350.7603759765625, 817.2127685546875, 21.58003997802734375, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 61967), -- Doodad_Dalaran_SewerDoor_01 (Area: Dalaran Arena - Difficulty: 0) CreateObject1
(@OGUID+2, 194395, 617, 4378, 4378, 0, 0, 0, 1291.6668701171875, 791.046875, 7.114629268646240234, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 0, 61967), -- Doodad_DalaranSewer_ArenaWaterFall_Collision01 (Area: Dalaran Arena - Difficulty: 0) CreateObject1
(@OGUID+3, 191877, 617, 4378, 4378, 0, 0, 0, 1291.6728515625, 791.00775146484375, 6.824081897735595703, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 0, 61967), -- Doodad_DalaranSewer01 (Area: Dalaran Arena - Difficulty: 0) CreateObject1
(@OGUID+4, 184663, 617, 4378, 4378, 0, 0, 0, 1292.517333984375, 746.78302001953125, 3.159699678421020507, 1.466075778007507324, 0, 0, 0.669130325317382812, 0.74314504861831665, 360, 255, 1, 61967),
(@OGUID+5, 184664, 617, 4378, 4378, 0, 0, 0, 1290.4132080078125, 835.8367919921875, 3.159699440002441406, 5.270895957946777343, 0, 0, -0.48480892181396484, 0.87462007999420166, 360, 255, 1, 61967);

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+3;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_Dalaran_SewerDoor_02
(@OGUID+1, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_Dalaran_SewerDoor_01
(@OGUID+2, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_DalaranSewer_ArenaWaterFall_Collision01
(@OGUID+3, 0, 0, 1, -0.00000004371138828, 0, 0); -- Doodad_DalaranSewer01

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+5;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 23472, 617, 4378, 4378, 0, 0, 0, 0, 0, 1270.6146240234375, 763.39410400390625, 22.04797744750976562, 0.942477762699127197, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- World Trigger (Large AOI, Not Immune PC/NPC) (Area: Dalaran Arena - Difficulty: 0) CreateObject1
(@CGUID+1, 15214, 617, 4378, 4378, 0, 0, 0, 0, 0, 1275.892333984375, 777.625, 7.197959423065185546, 0.523598790168762207, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Invisible Stalker (Area: Dalaran Arena - Difficulty: 0) CreateObject1
(@CGUID+2, 28567, 617, 4378, 4378, 0, 0, 0, 0, 0, 1369.9774169921875, 817.2882080078125, 16.08717727661132812, 3.106686115264892578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Water Spout (Area: Dalaran Arena - Difficulty: 0) CreateObject1 (Auras: 96539 - Pipe Flush Knockback Search Trigger)
(@CGUID+3, 23472, 617, 4378, 4378, 0, 0, 0, 0, 0, 1322.05908203125, 817.20831298828125, 19.52143287658691406, 3.455751895904541015, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- World Trigger (Large AOI, Not Immune PC/NPC) (Area: Dalaran Arena - Difficulty: 0) CreateObject1
(@CGUID+4, 28567, 617, 4378, 4378, 0, 0, 0, 0, 0, 1292.5867919921875, 790.22052001953125, 7.197960376739501953, 3.054326057434082031, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Water Spout (Area: Dalaran Arena - Difficulty: 0) CreateObject1
(@CGUID+5, 28567, 617, 4378, 4378, 0, 0, 0, 0, 0, 1212.8333740234375, 765.38714599609375, 16.09483909606933593, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61967); -- Water Spout (Area: Dalaran Arena - Difficulty: 0) CreateObject1 (Auras: 96539 - Pipe Flush Knockback Search Trigger)

UPDATE `creature` SET `StringId` = 'arena_dalaran_sewers_water_spout_pipe' WHERE `guid` IN (@CGUID+2, @CGUID+5);
UPDATE `creature` SET `StringId` = 'arena_dalaran_sewers_water_spout_center' WHERE `guid` = @CGUID+4;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_arena_dalaran_sewers_pipe_flush_knockback_search', 'spell_arena_dalaran_sewers_flush_knock_back_effect');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(96538, 'spell_arena_dalaran_sewers_pipe_flush_knockback_search'),
(61698, 'spell_arena_dalaran_sewers_flush_knock_back_effect');

UPDATE `serverside_spell` SET `RangeIndex` = 5 WHERE `Id` = 61698;

DELETE FROM `areatrigger_template` WHERE `Id` = @AT_ID AND `IsCustom` = 1;
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`) VALUES
(@AT_ID, 1);

DELETE FROM `areatrigger_create_properties` WHERE `Id` = @AT_PROP_ID AND `IsCustom` = 1;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`) VALUES
(@AT_PROP_ID, 1, @AT_ID, 1, 1, @AT_LENGTH, @AT_WIDTH, @AT_HEIGHT, @AT_LENGTH, @AT_WIDTH, @AT_HEIGHT, 0, 0);

DELETE FROM `areatrigger_template_actions` WHERE `AreaTriggerId` = @AT_ID AND `IsCustom` = 1;
INSERT INTO `areatrigger_template_actions` (`AreaTriggerId`, `IsCustom`, `ActionType`, `ActionParam`, `TargetType`) VALUES
(@AT_ID, 1, 0, 228212, 0); -- Arena Starting Area Marker

DELETE FROM `areatrigger` WHERE `SpawnId` BETWEEN @AT_SPAWN_ID+0 AND @AT_SPAWN_ID+1;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `PosX`, `PosY`, `PosZ`, `Orientation`, `Comment`) VALUES
(@AT_SPAWN_ID+0, @AT_PROP_ID, 1, 617, 1218.01, 764.795, 19.5, 0, 'Dalaran Sewers Entrance A'),
(@AT_SPAWN_ID+1, @AT_PROP_ID, 1, 617, 1361.76, 817.337, 19.5, 0, 'Dalaran Sewers Entrance B');
