SET @CGUID := 8000869;
SET @OGUID := 8000133;
SET @WORLD_SAFE_LOC_ID := 100105;
SET @SPAWN_GROUP := 1275;

SET @AT_WIDTH := 25;
SET @AT_LENGTH := 30;
SET @AT_HEIGHT := 15;
SET @AT_ID := 175;
SET @AT_PROP_ID := 168;
SET @AT_SPAWN_ID = 272;

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
(@AT_SPAWN_ID+0, @AT_PROP_ID, 1, 2547, 367, 265.875, 97.10447, 3.1415927, 'Enigma Crucible - Entrance Purple'), -- 370 265 95
(@AT_SPAWN_ID+1, @AT_PROP_ID, 1, 2547, 160, 268.20486, 100.78489, 0, 'Enigma Crucible - Entrance Gold'); -- 155 268 97  +1

DELETE FROM `world_safe_locs` WHERE `ID` BETWEEN @WORLD_SAFE_LOC_ID + 0 AND @WORLD_SAFE_LOC_ID + 1;
INSERT INTO `world_safe_locs` (`ID`, `MapID`, `LocX`, `LocY`, `LocZ`, `Facing`, `Comment`) VALUES
(@WORLD_SAFE_LOC_ID+0, 2547, 358.15277, 265.875, 95.10447, DEGREES(3.1415927), 'Enigma Crucible - Purple Team'),
(@WORLD_SAFE_LOC_ID+1, 2547, 167.88716, 268.20486, 97.78489, DEGREES(0), 'Enigma Crucible - Gold Team');

DELETE FROM `battleground_scripts` WHERE `MapId` = 2547 AND `BattlemasterListId` = 0;
INSERT INTO `battleground_scripts` (`MapId`, `BattlemasterListId`, `ScriptName`) VALUES
(2547, 0, 'arena_enigma_crucible');

DELETE FROM `battleground_template` WHERE `ID` = 1076;
INSERT INTO `battleground_template` (`ID`, `AllianceStartLoc`, `HordeStartLoc`, `StartMaxDist`, `Weight`, `Comment`) VALUES
(1076, @WORLD_SAFE_LOC_ID+0, @WORLD_SAFE_LOC_ID+1, 0, 1, 'Enigma Crucible');

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (376125 /*Enigma Arena - Door*/, 376877 /*ProgenitorArena_Button01*/, 376876 /*Enigma Arena Door 01*/, 376866 /*ProgenitorArena_Button_Trim*/, 376861 /*Enigma Arena Door 02*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(376125, 114, 0x0, 0, 0), -- Enigma Arena - Door
(376877, 0, 0x10000000, 0, 0), -- ProgenitorArena_Button01
(376876, 0, 0x20, 0, 0), -- Enigma Arena Door 01
(376866, 0, 0x10000000, 0, 0), -- ProgenitorArena_Button_Trim
(376861, 0, 0x20, 0, 0); -- Enigma Arena Door 02

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 188479, 2547, 14083, 14083, '0', '0', 0, 0, 0, 218.295135498046875, 373.328125, 115.2203521728515625, 5.345910549163818359, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305); -- Zo'sorg (Area: Enigma Crucible - Difficulty: 0) CreateObject1 (Auras: )

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+0;

DELETE FROM `creature_template_addon` WHERE `entry` IN (188479 /*188479 (Zo'sorg)*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(188479, 0, 0, 0, 3, 0, 1, 0, 0, 12224, 0, 0, 0, ''); -- 188479 (Zo'sorg)

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+7;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 376861, 2547, 14083, 14083, '0', '0', 0, 336.84027099609375, 266.173614501953125, 90.4921875, 0, 0, 0, 0, 1, 7200, 255, 1, 63305), -- Enigma Arena Door 02 (Area: Enigma Crucible - Difficulty: 0) CreateObject1
(@OGUID+1, 376866, 2547, 14083, 14083, '0', '0', 0, 266.302093505859375, 266.734375, 89.8592529296875, 0, 0, 0, 0, 1, 7200, 255, 1, 63305), -- ProgenitorArena_Button_Trim (Area: Enigma Crucible - Difficulty: 0) CreateObject1
(@OGUID+2, 376876, 2547, 14083, 14083, '0', '0', 0, 188.095489501953125, 266.3663330078125, 92.7468109130859375, 0, 0, 0, 0, 1, 7200, 255, 1, 63305), -- Enigma Arena Door 01 (Area: Enigma Crucible - Difficulty: 0) CreateObject1
(@OGUID+3, 376877, 2547, 14083, 14083, '0', '0', 0, 266.302093505859375, 266.734375, 89.80551910400390625, 0, 0, 0, 0, 1, 7200, 255, 0, 63305), -- ProgenitorArena_Button01 (Area: Enigma Crucible - Difficulty: 0) CreateObject1
(@OGUID+4, 376125, 2547, 14083, 14083, '0', '0', 0, 336.744781494140625, 265.102447509765625, 90.0426025390625, 0, 0, 0, 0, 1, 7200, 255, 1, 63305), -- Enigma Arena - Door (Area: Enigma Crucible - Difficulty: 0) CreateObject2
(@OGUID+5, 376125, 2547, 14083, 14083, '0', '0', 0, 185.748260498046875, 268.041656494140625, 93.93752288818359375, 0, 0, 0, 0, 1, 7200, 255, 1, 63305), -- Enigma Arena - Door (Area: Enigma Crucible - Difficulty: 0) CreateObject1
(@OGUID+6, 184663, 2547, 14083, 14083, '0', '0', 0, 265.744781494140625, 199.90625, 89.2678985595703125, 0, 0, 0, 0, 1, 360, 255, 1, 63305), -- Shadow Sight (Area: Enigma Crucible - Difficulty: 0) CreateObject2
(@OGUID+7, 184663, 2547, 14083, 14083, '0', '0', 0, 265.467010498046875, 334.057281494140625, 89.2678985595703125, 0, 0, 0, 0, 1, 360, 255, 1, 63305); -- Shadow Sight (Area: Enigma Crucible - Difficulty: 0) CreateObject2

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+7;

DELETE FROM `creature_template_addon` WHERE `entry` IN (185800 /*185800 (Past Self)*/, 188479 /*188479 (Zo'sorg)*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(185800, 0, 0, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, ''), -- 185800 (Past Self)
(188479, 0, 0, 0, 3, 0, 1, 0, 0, 12224, 0, 0, 0, ''); -- 188479 (Zo'sorg)

UPDATE `creature_template_difficulty` SET `ContentTuningID`=807, `StaticFlags1`=0x20000000, `VerifiedBuild`=63305 WHERE (`Entry`=188479 AND `DifficultyID`=0); -- 188479 (Zo'sorg) - Floating
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags2`=0x800 WHERE `entry`=188479; -- Zo'sorg

DELETE FROM `creature_text` WHERE `CreatureID` IN (188479);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(188479, 0, 0, 'Mortals, I present a lucrative opportunity for those who prove themselves worthy of the task.', 12, 0, 100, 1, 0, 188957, 214980, 3, 'Zo\'sorg'),
(188479, 1, 0, 'Many in the cartel are wagering on who are the greater combatants. Care to influence the outcome?', 12, 0, 100, 0, 0, 188958, 214991, 3, 'Zo\'sorg'),
(188479, 2, 0, 'Do not let the cartel down, we expect a return on our investment.', 12, 0, 100, 0, 0, 188954, 214995, 3, 'Zo\'sorg'),
(188479, 3, 0, 'Victory is clear, our bargain is upheld.', 12, 0, 100, 0, 0, 188955, 214998, 3, 'Zo\'sorg to Player'),
(188479, 3, 1, 'No matter who wins, we profit.', 12, 0, 100, 0, 0, 188956, 215067, 3, 'Zo\'sorg to Player');

DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN @SPAWN_GROUP+0 AND @SPAWN_GROUP+1;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWN_GROUP+0, 'Enigma Crucible - Shadow sight', 0x20),
(@SPAWN_GROUP+1, 'Enigma Crucible - Collision Walls', 0x20);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN @SPAWN_GROUP+0 AND @SPAWN_GROUP+1;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWN_GROUP, 1, @OGUID+6),
(@SPAWN_GROUP, 1, @OGUID+7),
(@SPAWN_GROUP+1, 1, @OGUID+4),
(@SPAWN_GROUP+1, 1, @OGUID+5);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 33 AND `SourceEntry` BETWEEN @SPAWN_GROUP+0 AND @SPAWN_GROUP+1;;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `SourceGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ScriptName`) VALUES
(33, @SPAWN_GROUP, 0, 0, 0, 'condition_is_shadow_sight_enabled'),
(33, @SPAWN_GROUP+1, 0, 0, 0, 'condition_enigma_arena_collision_doors');

DELETE FROM `spell_proc` WHERE `SpellId` IN (371601);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(371601,0x00,0,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0,0,0,0); -- Enigma Arena Reaction Trigger

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_enigma_arena_reaction_trigger', 'spell_enigma_arena_reaction_trigger_low_health', 'spell_enigma_arena_warning_countdown', 'spell_enigma_arena_warning_teleport');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(371602, 'spell_enigma_arena_reaction_trigger_low_health'),
(371601, 'spell_enigma_arena_reaction_trigger'),
(370437, 'spell_enigma_arena_warning_countdown'),
(371319, 'spell_enigma_arena_warning_teleport');
