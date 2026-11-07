/*
SET @CGUID := 123456789;

DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 167749, 1, 1519, 10523, '0', 0, 0, 0, 0, -8457.6806640625, -4500.56982421875, 8.886342048645019531, 2.302304744720458984, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689); -- Doomwalker (Area: Wizard's Sanctum - Difficulty: 0) CreateObject1
*/

UPDATE `creature_template_difficulty` SET `ContentTuningID`=328, `StaticFlags1`=0x20000100, `VerifiedBuild`=57689 WHERE (`Entry`=18665 AND `DifficultyID`=0); -- 18665 (Overrun Target) - Sessile, Floating
UPDATE `creature_template` SET `unit_flags`=0x2000300, `unit_flags3`=0x40080000 WHERE `entry`=18665; -- Overrun Target
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=3, `LevelScalingDeltaMax`=3, `ContentTuningID`=888, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=167749 AND `DifficultyID`=0); -- 167749 (Doomwalker) - CanSwim
UPDATE `creature_template` SET `faction`=90, `speed_walk`=2.799999952316284179, `speed_run`=2.857142925262451171, `BaseAttackTime`=3000, `unit_flags`=0x40, `unit_flags2`=0x800, `ScriptName`='boss_doomwalker_anniversary' WHERE `entry`=167749; -- Doomwalker

DELETE FROM `creature_text` WHERE `CreatureID`= 167749;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(167749, 0, 0, 'Do not proceed. You will be eliminated.', 14, 0, 100, 0, 0, 11344, 20941, 0, 'Doomwalker'),
(167749, 1, 0, 'Tectonic disruption commencing.', 14, 0, 100, 0, 0, 11345, 20942, 0, 'Doomwalker'),
(167749, 1, 1, 'Magnitude set. Release.', 14, 0, 100, 0, 0, 11346, 20943, 0, 'Doomwalker'),
(167749, 2, 0, 'Trajectory locked.', 14, 0, 100, 0, 0, 11347, 20944, 0, 'Doomwalker'),
(167749, 2, 1, 'Engage maximum speed.', 14, 0, 100, 0, 0, 11348, 20945, 0, 'Doomwalker'),
(167749, 3, 0, 'Threat level zero.', 14, 0, 100, 0, 0, 11349, 20946, 0, 'Doomwalker'),
(167749, 3, 1, 'Directive accomplished.', 14, 0, 100, 0, 0, 11350, 20947, 0, 'Doomwalker'),
(167749, 3, 2, 'Target exterminated.', 14, 0, 100, 0, 0, 11351, 20948, 0, 'Doomwalker'),
(167749, 4, 0, '%s goes into a frenzy!', 16, 0, 100, 0, 0, 0, 36719, 0, 'Doomwalker'), -- BroadcastTextID: 1191 - 2384 - 10645 - 36719 - 38630
(167749, 5, 0, 'System failure in five, f-o-u-r...', 14, 0, 100, 0, 0, 11352, 20949, 0, 'Doomwalker');

-- Spells
DELETE FROM `serverside_spell_effect` WHERE `SpellID` IN (32632, 32634, 32635) AND `EffectIndex`=0 AND `DifficultyID`=0;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(32632, 0, 0, 28, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18665, 64, 27, 0, 0, 0, 0, 0, 47, 0),
(32634, 0, 0, 77, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(32635, 0, 0, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 25, 0);

DELETE FROM `serverside_spell` WHERE `Id`IN (32632, 32634, 32635) AND `DifficultyID`=0;
INSERT INTO `serverside_spell` (`Id`, `DifficultyID`, `CategoryId`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `AttributesEx11`, `AttributesEx12`, `AttributesEx13`, `AttributesEx14`, `Stances`, `StancesNot`, `Targets`, `TargetCreatureType`, `RequiresSpellFocus`, `FacingCasterFlags`, `CasterAuraState`, `TargetAuraState`, `ExcludeCasterAuraState`, `ExcludeTargetAuraState`, `CasterAuraSpell`, `TargetAuraSpell`, `ExcludeCasterAuraSpell`, `ExcludeTargetAuraSpell`, `CasterAuraType`, `TargetAuraType`, `ExcludeCasterAuraType`, `ExcludeTargetAuraType`, `CastingTimeIndex`, `RecoveryTime`, `CategoryRecoveryTime`, `StartRecoveryCategory`, `StartRecoveryTime`, `InterruptFlags`, `AuraInterruptFlags1`, `AuraInterruptFlags2`, `ChannelInterruptFlags1`, `ChannelInterruptFlags2`, `ProcFlags`, `ProcFlags2`, `ProcChance`, `ProcCharges`, `ProcCooldown`, `ProcBasePPM`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `Speed`, `LaunchDelay`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `ContentTuningId`, `SpellName`, `ConeAngle`, `ConeWidth`, `MaxTargetLevel`, `MaxAffectedTargets`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `SpellFamilyFlags4`, `DmgClass`, `PreventionType`, `AreaGroupId`, `SchoolMask`, `ChargeCategoryId`) VALUES
(32632, 0, 0, 0, 0, 256, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 3, 1, 0, 0, 0, -1, 0, 0, 0, 'Summon Overrun Target', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(32634, 0, 0, 0, 0, 256, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, 0, 'Overrun Target Spawn', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(32635, 0, 0, 0, 0, 256, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, -1, 0, 0, 0, 'Overrun Target Spawn Effect', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_doomwalker_earthquake';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_doomwalker_overrun';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_doomwalker_overrun_damage';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(32686, 'spell_doomwalker_earthquake'),
(326405, 'spell_doomwalker_earthquake'),
(32636, 'spell_doomwalker_overrun'),
(32637, 'spell_doomwalker_overrun_damage');

-- Waypoints
SET @ENTRY := 167749;
SET @PATH := @ENTRY * 100;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Doomwalker - 20 Anniversary path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -8502.323, -4474.172, 11.24166, NULL, 0),
(@PATH, 1, -8544.641, -4488.516, 10.2678, NULL, 0),
(@PATH, 2, -8548.467, -4514.222, 10.46302, NULL, 0),
(@PATH, 3, -8548.484, -4548.071, 10.91817, NULL, 0),
(@PATH, 4, -8539.875, -4579.604, 8.880447, NULL, 0),
(@PATH, 5, -8533.594, -4602.74, 9.229619, NULL, 0),
(@PATH, 6, -8547.535, -4624.764, 10.45888, NULL, 0),
(@PATH, 7, -8571.873, -4624.099, 9.643352, NULL, 0),
(@PATH, 8, -8597.544, -4601.42, 10.03511, NULL, 0),
(@PATH, 9, -8607.272, -4560.495, 9.447116, NULL, 0),
(@PATH, 10, -8615.846, -4519.412, 9.316855, NULL, 0),
(@PATH, 11, -8621.404, -4480.259, 9.652395, NULL, 0),
(@PATH, 12, -8646.438, -4457.231, 9.699112, NULL, 0),
(@PATH, 13, -8660.638, -4471.069, 10.47824, NULL, 0),
(@PATH, 14, -8669.319, -4502.384, 9.324999, NULL, 0),
(@PATH, 15, -8658.005, -4533.122, 9.227811, NULL, 0),
(@PATH, 16, -8648.819, -4562.816, 9.524395, NULL, 0),
(@PATH, 17, -8658.92, -4581.91, 9.347061, NULL, 0),
(@PATH, 18, -8670.028, -4589.139, 10.08665, NULL, 0),
(@PATH, 19, -8710.201, -4590.729, 8.909066, NULL, 0),
(@PATH, 20, -8730.903, -4613.196, 9.109312, NULL, 8413),
(@PATH, 21, -8710.201, -4590.729, 8.909066, NULL, 0),
(@PATH, 22, -8670.028, -4589.139, 10.08665, NULL, 0),
(@PATH, 23, -8658.92, -4581.91, 9.347061, NULL, 0),
(@PATH, 24, -8648.819, -4562.816, 9.524395, NULL, 0),
(@PATH, 25, -8658.005, -4533.122, 9.227811, NULL, 0),
(@PATH, 26, -8669.319, -4502.384, 9.324999, NULL, 0),
(@PATH, 27, -8660.638, -4471.069, 10.47824, NULL, 0),
(@PATH, 28, -8646.438, -4457.231, 9.699112, NULL, 0),
(@PATH, 29, -8621.404, -4480.259, 9.652395, NULL, 0),
(@PATH, 30, -8615.846, -4519.412, 9.316855, NULL, 0),
(@PATH, 31, -8607.272, -4560.495, 9.447116, NULL, 0),
(@PATH, 32, -8597.544, -4601.42, 10.03511, NULL, 0),
(@PATH, 33, -8571.873, -4624.099, 9.643352, NULL, 0),
(@PATH, 34, -8547.535, -4624.764, 10.45888, NULL, 0),
(@PATH, 35, -8533.621, -4602.775, 9.228867, NULL, 0),
(@PATH, 36, -8539.875, -4579.604, 8.880447, NULL, 0),
(@PATH, 37, -8548.484, -4548.071, 10.91817, NULL, 0),
(@PATH, 38, -8548.467, -4514.222, 10.46302, NULL, 0),
(@PATH, 39, -8544.641, -4488.516, 10.2678, NULL, 0),
(@PATH, 40, -8502.323, -4474.172, 11.24166, NULL, 0),
(@PATH, 41, -8475.513, -4480.762, 10.5876, NULL, 0),
(@PATH, 42, -8452.853, -4505.946, 9.04792, NULL, 0),
(@PATH, 43, -8452.156, -4539.851, 10.83564, NULL, 0),
(@PATH, 44, -8451.757, -4569.894, 8.90681, NULL, 0),
(@PATH, 45, -8464.755, -4601.2, 9.51715, NULL, 0),
(@PATH, 46, -8476.272, -4625.877, 10.05686, NULL, 0),
(@PATH, 47, -8492.732, -4648.572, 9.209209, NULL, 0),
(@PATH, 48, -8519.594, -4684.045, 9.613039, NULL, 0),
(@PATH, 49, -8534.372, -4705.611, 10.03719, NULL, 0),
(@PATH, 50, -8553.938, -4725.389, 9.142217, NULL, 0),
(@PATH, 51, -8572.599, -4706.585, 9.505441, NULL, 0),
(@PATH, 52, -8580.103, -4681.196, 8.967605, NULL, 0),
(@PATH, 53, -8594.719, -4661.823, 9.830666, NULL, 0),
(@PATH, 54, -8617.113, -4648.759, 9.968203, NULL, 0),
(@PATH, 55, -8633.576, -4648.844, 10.32875, NULL, 0),
(@PATH, 56, -8663.098, -4636.938, 10.03142, NULL, 0),
(@PATH, 57, -8677.866, -4623.108, 9.009595, NULL, 0),
(@PATH, 58, -8698.363, -4612.444, 9.10241, NULL, 0),
(@PATH, 59, -8716.634, -4607.268, 9.502588, NULL, 10034),
(@PATH, 60, -8698.363, -4612.444, 9.10241, NULL, 0),
(@PATH, 61, -8677.866, -4623.108, 9.009595, NULL, 0),
(@PATH, 62, -8663.098, -4636.938, 10.03142, NULL, 0),
(@PATH, 63, -8633.576, -4648.844, 10.32875, NULL, 0),
(@PATH, 64, -8617.113, -4648.759, 9.968203, NULL, 0),
(@PATH, 65, -8594.719, -4661.823, 9.830666, NULL, 0),
(@PATH, 66, -8580.103, -4681.196, 8.967605, NULL, 0),
(@PATH, 67, -8572.599, -4706.585, 9.505441, NULL, 0),
(@PATH, 68, -8553.938, -4725.389, 9.142217, NULL, 0),
(@PATH, 69, -8534.372, -4705.611, 10.03719, NULL, 0),
(@PATH, 70, -8519.594, -4684.045, 9.613039, NULL, 0),
(@PATH, 71, -8492.743, -4648.597, 9.106194, NULL, 0),
(@PATH, 72, -8476.272, -4625.877, 10.05686, NULL, 0),
(@PATH, 73, -8464.755, -4601.2, 9.51715, NULL, 0),
(@PATH, 74, -8451.757, -4569.894, 8.90681, NULL, 0),
(@PATH, 75, -8452.156, -4539.851, 10.83564, NULL, 0),
(@PATH, 76, -8452.853, -4505.946, 9.04792, NULL, 0),
(@PATH, 77, -8475.513, -4480.762, 10.5876, NULL, 0);

/*
UPDATE `creature` SET `position_x`= -8502.323, `position_y`= -4474.172, `position_z`= 11.24166, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+0;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+0;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 5, ''); -- 167749 (Doomwalker)
*/
