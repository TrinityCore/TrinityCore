SET @ATID := 95;
SEt @ATCP := 83;
SET @ATIDSPAWN := 97;
SET @CGUID := 7001525;
SET @SPAWNGROUP := 1258;

-- Instance
DELETE FROM `instance_template` WHERE `map`=1864;
INSERT INTO `instance_template` (`map`, `parent`, `script`) VALUES
(1864, 0, 'instance_shrine_of_the_storm');

-- Creature
DELETE FROM `creature` WHERE `guid`= @CGUID+0;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 134056, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3931.7275390625, -1244.4896240234375, 128.450714111328125, 0.069714099168777465, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55664); -- Aqu'sirr (Area: Tidewater Sanctum - Difficulty: Normal) CreateObject2 (Auras: )

UPDATE `creature_template_difficulty` SET `ContentTuningID`=500, `StaticFlags1`=805306624, `VerifiedBuild`=55664 WHERE (`Entry`=134828 AND `DifficultyID`=1); -- 134828 (Aqualing) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=500, `StaticFlags1`=805306624, `VerifiedBuild`=55664 WHERE (`Entry`=134056 AND `DifficultyID`=1); -- 134056 (Aqu'sirr) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=134056 AND `DifficultyID`=1); -- Aqu'sirr
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=139737 AND `DifficultyID`=1); -- Lord Stormsong
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=134828 AND `DifficultyID`=1); -- Aqualing

UPDATE `creature_template_addon` SET `auras`='274341' WHERE `entry`=139737; -- 139737 (Lord Stormsong) - Water Ritual
UPDATE `creature_template` SET `ScriptName`='npc_aqusirr_intro_lord_stormsong' WHERE `entry`=139737; -- 139737 (Lord Stormsong)
UPDATE `creature_template` SET `ScriptName`='boss_aqusirr' WHERE `entry`=134056; -- 134056 (Aqu'sirr)
UPDATE `creature_template` SET `ScriptName`='boss_aqusirr_aqualing' WHERE `entry`=134828; -- 134828 (Aqualing)
UPDATE `creature_template` SET `faction`=16, `speed_run`=1.285714268684387207, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=524288 WHERE `entry`=134828; -- Aqualing

DELETE FROM `creature_template_addon` WHERE `entry` IN (134828, 134612);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(134828, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '264899'), -- 134828 (Aqualing) - Diminish
(134612, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''); -- 134612 (Grasping Tentacles)

-- Conversations
DELETE FROM `conversation_actors` WHERE (`Idx`=0 AND `ConversationId` IN (8762, 8761));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(8762, 65085, 0, 139971, 60766, 0, 0, 34601),
(8761, 0, 0, 139970, 81302, 0, 0, 27843);

DELETE FROM `conversation_template` WHERE `Id` IN (8762, 8761);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(8762, 19643, 0, 34601),
(8761, 19642, 0, 27843);

DELETE FROM `conversation_line_template` WHERE `Id` IN (19643, 19642);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(19643, 1060, 0, 0, 0, 34601),
(19642, 82, 0, 0, 0, 27843);

-- Spawngroup
DELETE FROM `spawn_group_template` WHERE `groupId`= @SPAWNGROUP+0;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWNGROUP+0, 'Shrine of the Storm - Aqu\'sirr spawn', 4);

DELETE FROM `spawn_group` WHERE `groupId`= @SPAWNGROUP+0;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWNGROUP+0, 0, @CGUID+0);

-- Areatrigger
DELETE FROM `areatrigger_template` WHERE (`Id` = @ATID+0 AND `IsCustom` = 1);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES 
(@ATID+0, 1, 1, 0);

DELETE FROM `areatrigger` WHERE `SpawnId`= @ATIDSPAWN+0;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `ScriptName`, `Comment`, `VerifiedBuild`) VALUES
(@ATIDSPAWN+0, @ATCP+0, 1, 1864, '1,2,23,8', 3925.384, -1245.656, 128.339, 3.31631, 1, 0, 0, 'at_aqusirr_intro', 'Shrine of the Storm - Trigger Aqu\'sirr intro', 0);

DELETE FROM `areatrigger_create_properties` WHERE `Id`= @ATCP+0 AND `IsCustom`=1;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(@ATCP+0, 1, @ATID+0, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 18, 30, 5, 18, 30, 5, 0, 0, '', 0);

DELETE FROM `areatrigger_template` WHERE (`IsCustom`=0 AND `Id` IN (17428, 17427));
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES
(17428, 0, 0, 55664),
(17427, 0, 0, 55664);

DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` IN (12773, 12775));
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(12773, 0, 17427, 0, 4, 0, 0, 0, 0, -1, 0, 0, 0, 6000, 0, 100, 100, 0, 0, 0, 0, 0, 0, 'at_aqusirr_undertow', 55664), -- Spell: 264144 (Undertow)
(12775, 0, 17428, 0, 4, 0, 0, 0, 0, -1, 0, 0, 0, 4000, 0, 6, 6, 0, 0, 0, 0, 0, 0, 'at_aqusirr_surging_rush', 55664); -- Spell: 264101 (Surging Rush)

-- Spells
DELETE FROM `spell_script_names` WHERE `spell_id` IN (274365, 274367, 274364, 264903, 264911, 264912, 264913, 274260, 264102, 264560, 264941, 264477, 264526);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(274365, 'spell_aqusirr_requiem_of_the_abyss'),
(274367, 'spell_aqusirr_requiem_of_the_abyss'),
(274364, 'spell_aqusirr_requiem_of_the_abyss_periodic'),
(264903, 'spell_aqusirr_erupting_waters_aura'),
(264911, 'spell_aqusirr_erupting_waters_split_1'),
(264912, 'spell_aqusirr_erupting_waters_split_2'),
(264913, 'spell_aqusirr_erupting_waters_split_3'),
(264560, 'spell_aqusirr_choking_brine'),
(274260, 'spell_aqusirr_surging_rush'),
(264102, 'spell_aqusirr_surging_rush_selector'),
(264941, 'spell_aqusirr_erupting_waters'),
(264477, 'spell_aqusirr_grasp_from_the_depths_selector'),
(264526, 'spell_aqusirr_grasp_from_the_depths_damage');

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=265030;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 265030, 0, 0, 51, 0, 5, 134056, 0, '', 0, 0, 0, '', 'Spell \'Erupting Waters\' can only hit \'Aqu\'sirr\'');

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` = 139737;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(139737, 0, 0, 'How dare you sully this holy place with your presence!', 14, 0, 100, 25, 0, 108219, 150520, 0, 'Lord Stormsong to Player'),
(139737, 1, 0, 'I call upon the surging waters! Arise, and wipe out these intruders!', 14, 0, 100, 5, 0, 108220, 150521, 0, 'Lord Stormsong to Player');

-- SAI
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=0, `unit_flags2`=32800, `unit_flags3`=524288, `AIName`='SmartAI' WHERE `entry`=134612; -- Grasping Tentacles
DELETE FROM `smart_scripts` WHERE `entryorguid`=134612 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(134612, 0, 0, 0, '', 63, 0, 100, 0, 0, 0, 0, 0, 0, '', 85, 264526, 2, 128, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Grasping Tentacles - On Just Created - Self: Cast Spell 264526');

UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=501, `StaticFlags1`=805306624, `VerifiedBuild`=56647 WHERE (`Entry`=134828 AND `DifficultyID`=2); -- 134828 (Aqualing) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=501, `StaticFlags1`=805306624, `VerifiedBuild`=56647 WHERE (`Entry`=134612 AND `DifficultyID`=2); -- 134612 (Grasping Tentacles) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=502, `StaticFlags1`=805306624, `VerifiedBuild`=56647 WHERE (`Entry`=134828 AND `DifficultyID`=23); -- 134828 (Aqualing) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=502, `StaticFlags1`=805306624, `VerifiedBuild`=56647 WHERE (`Entry`=134612 AND `DifficultyID`=23); -- 134612 (Grasping Tentacles) - Sessile, CanSwim, Floating
