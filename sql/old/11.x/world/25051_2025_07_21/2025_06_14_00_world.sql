SET @CGUID := 10006613;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 212299, 2652, 14883, 14883, '1,2,8,23,205', 0, 0, 0, 0, -10.4965276718139648, -266.364593505859375, 361.270050048828125, 6.14813232421875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 58238); -- Reinforce Stalker (Area: The Stonevault - Difficulty: Mythic) CreateObject1 (Auras: 206150 - Challenger's Might)

UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x80001, `AIName`='SmartAI' WHERE `entry`=214443; -- Crystal Shard
UPDATE `creature_template` SET `ScriptName`='boss_skarmorak' WHERE `entry`=210156; -- Skarmorak

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=23 AND `Entry` IN (214443,210156));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`) VALUES
(214443, 23, 10, 0.400000005960464477, 1, 279589, 0x0, 128), -- Crystal Shard
(210156, 23, 10, 31.5, 1, 258193, 0x200068, 128); -- Skarmorak

UPDATE `creature_template_difficulty` SET `ContentTuningID`=1279, `VerifiedBuild`=58238 WHERE (`Entry`=214443 AND `DifficultyID`=23); -- 214443 (Crystal Shard) - 
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=1279, `StaticFlags1`=0x10000000, `VerifiedBuild`=58238 WHERE (`Entry`=210156 AND `DifficultyID`=23); -- 210156 (Skarmorak) - CanSwim

-- Areatrigger
DELETE FROM `areatrigger_template` WHERE (`IsCustom`=0 AND `Id` = 35431);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES
(35431, 0, 0, 58238);

DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` = 32832);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(32832, 0, 35431, 0, 0, 0, 0, 0, 0, -1, 0, 1073741824, 443405, 15000, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 'at_skarmorak_unstable_fragments', 58238); -- Spell: 443405 (Unstable Fragments)

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=426181;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 426181, 0, 0, 51, 0, 5, 212299, 0, '', 0, 0, 0, '', 'Spell \'Fortified Shell\' can only hit \'Reinforce Stalker\''),
(13, 2, 426181, 0, 0, 51, 0, 5, 214443, 0, '', 0, 0, 0, '', 'Spell \'Fortified Shell\' can only hit \'Crystal Shard\''),
(13, 2, 426181, 0, 0, 36, 0, 0, 0, 0, '', 0, 0, 0, '', 'Potential target of the spell is alive');

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID`=210156;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(210156, 0, 0, 'Not us. Must kill.', 14, 0, 100, 0, 0, 247920, 261870, 0, 'Skarmorak'),
(210156, 1, 0, 'To dust.', 14, 0, 100, 0, 0, 247921, 252163, 0, 'Skarmorak'),
(210156, 1, 1, 'Shattered.', 14, 0, 100, 0, 0, 247922, 261866, 0, 'Skarmorak'),
(210156, 1, 2, 'Crushed.', 14, 0, 100, 0, 0, 247923, 261867, 0, 'Skarmorak'),
(210156, 2, 0, 'Fortify!', 14, 0, 100, 0, 0, 247924, 252162, 0, 'Skarmorak'),
(210156, 3, 0, 'Lay waste!', 14, 0, 100, 0, 0, 247925, 252161, 0, 'Skarmorak'),
(210156, 4, 0, 'Destroyed. All.', 14, 0, 100, 0, 0, 247926, 261876, 0, 'Skarmorak'),
(210156, 5, 0, 'Return... to nothing...', 14, 0, 100, 0, 0, 247927, 252166, 0, 'Skarmorak');

-- SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`= 214443 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(214443, 0, 0, 0, '', 54, 0, 100, 0, 0, 0, 0, 0, 0, '', 8, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Crystal Shard - On Just Summoned - Set Passive'),
(214443, 0, 1, 0, '', 6, 0, 100, 0, 0, 0, 0, 0, 0, '', 85, 443494, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Crystal Shard - On Just Died - Cast \'Crystalline Eruption\'');

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_skarmorak_crystal_shards', 'spell_skarmorak_crystalline_smash', 'spell_skarmorak_unstable_crash', 'spell_skarmorak_fortified_shell_energize', 'spell_skarmorak_fortified_shell_selector', 'spell_skarmorak_fortified_shell_absorb', 'spell_skarmorak_fortified_shell_periodic_absorb', 'spell_skarmorak_unstable_crash_fragment_selector', 'spell_skarmorak_unstable_energy_area', 'spell_skarmorak_unstable_energy');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(422294, 'spell_skarmorak_crystal_shards'),
(422233, 'spell_skarmorak_crystalline_smash'),
(423538, 'spell_skarmorak_unstable_crash'),
(429976, 'spell_skarmorak_fortified_shell_energize'),
(426181, 'spell_skarmorak_fortified_shell_selector'),
(423228, 'spell_skarmorak_fortified_shell_absorb'),
(439600, 'spell_skarmorak_fortified_shell_periodic_absorb'),
(443838, 'spell_skarmorak_unstable_crash_fragment_selector'),
(423572, 'spell_skarmorak_unstable_energy_area'),
(435813, 'spell_skarmorak_unstable_energy');
