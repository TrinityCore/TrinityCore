SET @CGUID := 83858583;
SET @OGUID := 83858583;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 196717, 2527, 14082, 14082, '2,8,23,1,205,24', '0', 0, 0, 0, 64.2413177490234375, -208.335067749023437, -17.1869373321533203, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 70961), -- 196717 (Area: Halls of Infusion - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+1, 189719, 2527, 14082, 14082, '2,8,23,1,205,24', '0', 0, 0, 0, 0.732638895511627197, -206.944442749023437, -35.7815895080566406, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 70961); -- Watcher Irideus (Area: Halls of Infusion - Difficulty: Mythic) CreateObject1 (Auras: 389103 - Power Override, 422356 - Bot AI Follow Advert)

DELETE FROM `creature_template_addon` WHERE `entry` IN (196717, 196712);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(196717, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 196717
(196712, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, '389219'); -- 196712 (Nullification Device) - Containment Apparatus

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+1, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, '389103 422356'); -- Watcher Irideus - 389103 - Power Override, 422356 - Bot AI Follow Advert

UPDATE `creature_template` SET `faction`=35, `unit_class`=1, `type`=10, `speed_walk`=1, `speed_run`=1.14286, `BaseAttackTime`=2000, `unit_flags`=0x2000300, `unit_flags2`=0x800, `unit_flags3`=0x40000001, `AIName`='SmartAI', `VerifiedBuild`=70961 WHERE `entry`=196717; -- Power Device
UPDATE `creature_template` SET `faction`=16, `speed_walk`=5.599999904632568359, `speed_run`=2, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags3`=0x10000000, `RegenHealth`=0, `ScriptName`='boss_watcher_irideus', `VerifiedBuild`=70961 WHERE `entry`=189719; -- Watcher Irideus
UPDATE `creature_template` SET `faction`=16, `speed_walk`=1.60000002384185791, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags2`=0x800, `AIName`='SmartAI', `VerifiedBuild`=70961 WHERE `entry`=196712; -- Nullification Device

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+1;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 379303, 2527, 14082, 14082, '2,8,23,1,205,24', '0', 0, -107.575958251953125, -139.409759521484375, -39.8650970458984375, 0, 0, 0, 0, 1, 86400, 255, 1, 70961), -- 10DU_Uldaman_Door06 (Area: Halls of Infusion - Difficulty: Heroic) CreateObject1
(@OGUID+1, 379304, 2527, 14082, 14082, '2,8,23,1,205,24', '0', 0, -86.3078994750976562, -285.97503662109375, -18.1059722900390625, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 86400, 255, 1, 70961); -- Door (Area: Halls of Infusion - Difficulty: Heroic) CreateObject1

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+1;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 1, -0.00000004371138828, 0, 0), -- 10DU_Uldaman_Door06
(@OGUID+1, 0, 0, 1, -0.00000004371138828, 0, 0); -- Door

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (379303, 379304);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(379303, 0, 0x30, 0, 0), -- 10DU_Uldaman_Door06
(379304, 0, 0x30, 0, 0); -- Door

-- Areatrigger
DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` IN (26680));
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `PositionalSoundKitId`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `Roll`, `Pitch`, `Yaw`, `TargetRoll`, `TargetPitch`, `TargetYaw`, `ScriptName`, `VerifiedBuild`) VALUES
(26680, 0, 30826, 0, 0, 0, 0, 0, 0, -1, 0, 502, NULL, 0, 15000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL, 'at_watcher_irideus_power_field', 70961); -- Spell: 389180 (Power Field)

DELETE FROM `areatrigger_template` WHERE (`IsCustom`=0 AND `Id` IN (30826));
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `VerifiedBuild`) VALUES
(30826, 0, 70961);

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (389056, 389446);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 389056, 0, 0, 51, 0, 5, 196717, 0, 0, 0, 0, '', 'Spell \'Siphon Power\' can only hit Power Device'),
(13, 4, 389446, 0, 0, 51, 0, 5, 189719, 0, 0, 0, 0, '', 'Spell \'Nullifying Pulse\' can only hit Watcher Irideus');

DELETE FROM `creature_summon_groups` WHERE `summonerId`=189719;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`, `Comment`) VALUES
(189719, 0, 0, 196712, 43.220486, -247.2882, -35.319683, 2.134168, 8, 0, 'Watcher Irideus - Nullification Devices'),
(189719, 0, 0, 196712, 42.875, -164.60243, -35.68759, 3.8404324, 8, 0, 'Watcher Irideus - Nullification Devices'),
(189719, 0, 0, 196712, -26.08333, -234.36806, -35.57353, 0.866684, 8, 0, 'Watcher Irideus - Nullification Devices'),
(189719, 0, 0, 196712, -40.89583, -146.08855, -35.68759, 5.527534, 8, 0, 'Watcher Irideus - Nullification Devices');

-- Instance
DELETE FROM `instance_template` WHERE `map`=2527;
INSERT INTO `instance_template` (`map`, `parent`, `script`) VALUES
(2527, 0, 'instance_halls_of_infusion');

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=23 AND `Entry` IN (189719, 196717, 196712)) OR (`DifficultyID`=2 AND `Entry`= 196717);
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `TypeFlags3`) VALUES
(196712, 23, 9, 2, 1, 276959, 0x200048, 128, 0), -- Nullification Device
(189719, 23, 9, 130, 1, 276962, 0x200068, 128, 0), -- Watcher Irideus
(196717, 23, 9, 1, 1, 225000, 0x0, 0, 0), -- Power Device
(196717, 2, 9, 1, 1, 225000, 0x0, 0, 0); -- Power Device

UPDATE `creature_template_difficulty` SET `ContentTuningID`=2156, `StaticFlags1`=0x100, `VerifiedBuild`=70961 WHERE (`Entry`=196717 AND `DifficultyID`=2); -- 196717 (Power Device) - Sessile
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2157, `StaticFlags1`=0x100, `VerifiedBuild`=70961 WHERE (`Entry`=196717 AND `DifficultyID`=23); -- 196717 (Power Device) - Sessile
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2554, `StaticFlags1`=0x100, `VerifiedBuild`=70961 WHERE (`Entry`=196717 AND `DifficultyID`=1); -- 196717 (Power Device) - Sessile

UPDATE `creature_template_difficulty` SET `ContentTuningID`=2554, `StaticFlags1`=0x10000000, `VerifiedBuild`=70961 WHERE (`Entry`=189719 AND `DifficultyID`=1); -- 189719 (Watcher Irideus) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2156, `StaticFlags1`=0x10000000, `VerifiedBuild`=70961 WHERE (`Entry`=189719 AND `DifficultyID`=2); -- 189719 (Watcher Irideus) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2157, `StaticFlags1`=0x10000000, `VerifiedBuild`=70961 WHERE (`Entry`=189719 AND `DifficultyID`=23); -- 189719 (Watcher Irideus) - CanSwim

UPDATE `creature_template_difficulty` SET `ContentTuningID`=2156, `StaticFlags1`=0x10000000, `VerifiedBuild`=70961 WHERE (`Entry`=196712 AND `DifficultyID`=2); -- 196712 (Nullification Device) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2157, `StaticFlags1`=0x10000000, `VerifiedBuild`=70961 WHERE (`Entry`=196712 AND `DifficultyID`=23); -- 196712 (Nullification Device) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2554, `StaticFlags1`=0x10000000, `VerifiedBuild`=70961 WHERE (`Entry`=196712 AND `DifficultyID`=1); -- 196712 (Nullification Device) - CanSwim

DELETE FROM `creature_template_movement` WHERE `CreatureId`=196712;
INSERT INTO `creature_template_movement` (`CreatureId`, `HoverInitiallyEnabled`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(196712, 1, NULL, NULL, NULL);

-- Models
DELETE FROM `creature_template_model` WHERE `CreatureID` IN (189719, 196717);
INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`, `VerifiedBuild`) VALUES
(196717, 1, 27823, 1, 1, 70961), -- Power Device
(196717, 0, 4626, 1, 0, 70961), -- Power Device
(189719, 0, 106801, 2, 1, 70961); -- Watcher Irideus

DELETE FROM `creature_model_info` WHERE `DisplayID` IN (106801, 27823);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(106801, 1.453646183013916015, 3, 0, 70961),
(27823, 0.25, 0.5, 0, 70961);

-- Sai
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (196717, 196712) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(196712, 0, 0, 1, '', 63, 0, 100, 0, 0, 0, 0, 0, 0, '', 85, 389219, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Nullification Device - On Just Created - Cast Self \'Containment Apparatus\''),
(196712, 0, 1, 2, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 69, 1, 0, 0, 0, 0, 0, 0, NULL, 5, 100, 0, 0, 0, NULL, 0, 0, 0, 0, 'Nullification Device - On Linked Event - Move To Hostile Random'),
(196712, 0, 2, 3, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 42, 1, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Nullification Device - On Just Created - Set Invincibility HP 1'),
(196712, 0, 3, 0, '', 0, 0, 100, 0, 6000, 6000, 6000, 8000, 0, '', 11, 389443, 0, 0, 0, 0, 0, 0, NULL, 5, 100, 0, 0, 0, NULL, 0, 0, 0, 0, 'Nullification Device - In Combat - Cast \'Purifying Blast\' to Hostile Random'),
(196712, 0, 4, 5, '', 2, 0, 100, 1, 0, 1, 0, 0, 0, '', 85, 389446, 1, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Nullification Device - At 1% HP - Cast \'Nullifying Pulse\''),
(196712, 0, 5, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 41, 3500, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Nullification Device - On Linked Event - Despawn'),
(196717, 0, 0, 0, '', 8, 0, 100, 1, 389056, 0, 0, 0, 0, '', 85, 389092, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Power Device - On Spell hit - Cast Self Siphon Power');

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_watcher_irideus_spark_volley', 'spell_watcher_irideus_nullifying_pulse', 'spell_watcher_irideus_siphon_power', 'spell_watcher_irideus_reactive_spark_random', 'spell_watcher_irideus_power_overload', 'spell_watcher_irideus_reactive_spark_players');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(389179, 'spell_watcher_irideus_power_overload'),
(383955, 'spell_watcher_irideus_reactive_spark_players'),
(383952, 'spell_watcher_irideus_reactive_spark_random'),
(389056, 'spell_watcher_irideus_siphon_power'),
(389446, 'spell_watcher_irideus_nullifying_pulse'),
(384351, 'spell_watcher_irideus_spark_volley');

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID`=189719;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(189719, 0, 0, 'More trespassers? I will not allow you through!', 14, 0, 100, 0, 0, 203558, 226793, 0, 'Watcher Irideus'),
(189719, 1, 0, 'Order will overwhelm you.', 14, 0, 100, 0, 0, 203566, 226801, 0, 'Watcher Irideus'),
(189719, 2, 0, '|TInterface\\ICONS\\Ability_ThunderKing_LightningWhip.blp:20|t Watcher Irideus begins casting |cFFFF0000|Hspell:389179|h[Power Overload]|h|r!', 41, 0, 100, 0, 0, 0, 0, 0, 'Watcher Irideus'),
(189719, 3, 0, 'I will not let you through!', 14, 0, 100, 0, 0, 203565, 226800, 0, 'Watcher Irideus'),
(189719, 4, 0, '|TInterface\\ICONS\\Spell_Nature_LightningShield.blp:20|t Watcher Irideus erects an |cFFFF0000|Hspell:383840|h[Ablative Barrier]|h|r!', 41, 0, 100, 0, 0, 0, 0, 0, 'Watcher Irideus'),
(189719, 5, 0, 'My sacrifice will keep these halls safe!', 14, 0, 100, 0, 0, 203568, 226803, 0, 'Watcher Irideus'),
(189719, 6, 0, 'A small victory, I will eliminate you!', 14, 0, 100, 0, 0, 203567, 226802, 0, 'Watcher Irideus to Watcher Irideus'),
(189719, 7, 0, 'I will scour these halls of all intruders.', 14, 0, 50, 0, 0, 203561, 226796, 0, 'Watcher Irideus'),
(189719, 7, 1, 'These halls must be kept safe.', 14, 0, 50, 0, 0, 203562, 226797, 0, 'Watcher Irideus'),
(189719, 8, 0, 'Your end was necessary.', 14, 0, 50, 0, 0, 203559, 226794, 0, 'Watcher Irideus'),
(189719, 8, 1, 'I could not allow you to pass.', 14, 0, 50, 0, 0, 203560, 226795, 0, 'Watcher Irideus'),
(189719, 9, 0, 'Tyr... Forgive me... I could not... stop... them...', 14, 0, 100, 0, 0, 203563, 226798, 0, 'Watcher Irideus');
