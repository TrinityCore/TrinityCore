SET @ATSPAWNID := 6666666;
SET @ATPROP := 66666;
SET @ATID := 666666;

-- Creature
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x80000, `AIName`='SmartAI' WHERE `entry`=236190; -- Frenzied Mite
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=33555264, `unit_flags3`=1073741824, `ScriptName`='boss_azhiccar' WHERE `entry`=234893;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=237454;
UPDATE `creature_template` SET `ScriptName`='npc_azhiccar_intro_creature' WHERE `entry` IN (245411, 245412);

DELETE FROM `creature_template_addon` WHERE `entry`=234893;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(234893, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '422356');

DELETE FROM `creature_addon` WHERE `guid`=10006776;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(10006776, 0, 0, 0, 0, 0, 0, 1, 0, 0, 19254, 0, 0, 0, '');

DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=23 AND `Entry` =236190);
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `TypeFlags3`) VALUES
(236190, 23, 10, 0.5, 1, 315019, 0x200048, 128, 0); -- Frenzied Mite

UPDATE `creature_template_difficulty` SET `ContentTuningID`=1279, `StaticFlags1`=0x10000000 WHERE (`Entry`=236190 AND `DifficultyID`=23); -- 236190 (Frenzied Mite) - CanSwim

-- SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=237454 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(237454, 0, 0, 0, '', 63, 0, 100, 0, 0, 0, 0, 0, 0, '', 85, 1217720, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, '[DNT] Stalker - On Just Summoned - Cast self [DNT] Spawn');

DELETE FROM `smart_scripts` WHERE `entryorguid`=236190 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(236190, 0, 0, 0, '', 63, 0, 100, 0, 0, 0, 0, 0, 0, '', 85, 1231811, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Frenzied Mite - On Just Summoned - Cast self Uncontrolled');

-- Instance
DELETE FROM `instance_template` WHERE `map`=2830;
INSERT INTO `instance_template` (`map`, `parent`, `script`) VALUES
(2830, 0, 'instance_ecodome_aldani');

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (1217255, 1233147, 1233116);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 1217255, 0, 0, 51, 0, 5, 236190, 0, '', 0, 0, 0, '', 'Spell \'Devour\' can only hit \'Frenzied Mite\''),
(13, 2, 1217255, 0, 0, 51, 0, 5, 236190, 0, '', 0, 0, 0, '', 'Spell \'Devour\' can only hit \'Frenzied Mite\''),
(13, 2, 1233147, 0, 0, 51, 0, 5, 234893, 0, '', 0, 0, 0, '', 'Spell \'Devour\' can only hit \'Azhiccar\''),
(13, 4, 1233147, 0, 0, 51, 0, 5, 234893, 0, '', 0, 0, 0, '', 'Spell \'Devour\' can only hit \'Azhiccar\''),
(13, 1, 1233116, 0, 1, 51, 0, 5, 245411, 0, '', 0, 0, 0, '', 'Spell \'Devour\' can only hit \'Ravaging Scavenger\''),
(13, 1, 1233116, 0, 0, 51, 0, 5, 245412, 0, '', 0, 0, 0, '', 'Spell \'Devour\' can only hit \'Voracious Gorger\'');

-- Areatrigger
DELETE FROM `areatrigger` WHERE `SpawnId`=@ATSPAWNID;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `ScriptName`, `Comment`, `VerifiedBuild`) VALUES
(@ATSPAWNID, @ATPROP, 1, 2830, '1,2,23,8,205', 526.473, -747.901, 999.682, 6.1991, 0, 0, 0, 'at_azhiccar_intro', 'Eco-Dome Aldani - Azhiccar intro', 0);

DELETE FROM `areatrigger_create_properties` WHERE `Id`=@ATPROP AND `IsCustom`=1;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `SpeedIsTime`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(@ATPROP, 1, @ATID, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 0, 1, 20, 10, 5, 20, 10, 5, 0, 0, '', 0);

DELETE FROM `areatrigger_template` WHERE `Id`=@ATID AND `IsCustom`=1;
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `ActionSetId`, `ActionSetFlags`, `VerifiedBuild`) VALUES
(@ATID, 1, 1, 0, 0, 0);

DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` IN (36165, 36166, 38667, 36181, 38379));
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(36165, 0, 38189, 0, 0, 0, 0, 0, 0, -1, 0, 0, 1217240, 18000, 0, 0, 12, 12, 0, 0, 0, 0, 0, 0, 'at_azhiccar_devour', 63305), -- SpellForVisuals: 1217240 (Devour)
(36166, 0, 38188, 0, 0, 0, 0, 0, 0, -1, 0, 0, 1217240, 18000, 0, 0, 108, 108, 0, 0, 0, 0, 0, 0, 'at_azhiccar_devour_force', 63305), -- SpellForVisuals: 1217240 (Devour)
(38667, 0, 34184, 0, 0, 0, 0, 0, 0, -1, 0, 0, 1217240, 18000, 0, 0, 20, 20, 0, 0, 0, 0, 0, 0, '', 63305), -- SpellForVisuals: 1217240 (Devour)
(36181, 0, 38204, 0, 4, 0, 81441, 0, 0, -1, 0, 690, NULL, 180000, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0, 'at_azhiccar_digestive_spittle', 63305), -- Spell: 1217441 (Digestive Spittle)
(38379, 0, 6197, 0, 2, 0, 0, 0, 0, -1, 0, 0, NULL, 6000, 0, 0, 108, 108, 0, 0, 0, 0, 0, 0, '', 63305);

DELETE FROM `areatrigger_template` WHERE (`IsCustom`=0 AND `Id` IN (38189, 38188, 34184, 38204));
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `VerifiedBuild`) VALUES
(38189, 0, 63305),
(38188, 0, 63305),
(34184, 0, 63305),
(38204, 0, 63305);

UPDATE `areatrigger_template` SET `VerifiedBuild`=63305 WHERE (`Id`=6197 AND `IsCustom`=0);

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` = 234893;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(234893, 0, 0, '|TInterface\\ICONS\\Spell_Shadow_DevouringPlague..blp:20|t %s prepares to |cFFFF0000|Hspell:1217232|h[Devour]|h|r!', 41, 0, 100, 0, 0, 283865, 285972, 0, 'Azhiccar');

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_azhiccar_energy_controller', 'spell_azhiccar_feast', 'spell_azhiccar_devour_selector', 'spell_azhiccar_devour', 'spell_azhiccar_player_detection', 'spell_azhiccar_invading_shriek_dummy', 'spell_azhiccar_toxic_regurgitation_cast', 'spell_azhiccar_toxic_regurgitation_selector', 'spell_azhiccar_devour_intro_selector', 'spell_azhiccar_invading_shriek');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(1217202, 'spell_azhiccar_energy_controller'),
(1217436, 'spell_azhiccar_toxic_regurgitation_selector'),
(1227745, 'spell_azhiccar_toxic_regurgitation_cast'),
(1233116, 'spell_azhiccar_devour_intro_selector'),
(1217330, 'spell_azhiccar_invading_shriek_dummy'),
(1217758, 'spell_azhiccar_player_detection'),
(1217232, 'spell_azhiccar_devour'),
(1217255, 'spell_azhiccar_devour_selector'),
(1217241, 'spell_azhiccar_feast'),
(1217252, 'spell_azhiccar_feast'),
(1217327, 'spell_azhiccar_invading_shriek');

DELETE FROM `serverside_spell` WHERE `Id`=1217758 AND `DifficultyID`=0;
INSERT INTO `serverside_spell` (`Id`, `DifficultyID`, `CategoryId`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `AttributesEx11`, `AttributesEx12`, `AttributesEx13`, `AttributesEx14`, `AttributesEx15`, `Stances`, `StancesNot`, `Targets`, `TargetCreatureType`, `RequiresSpellFocus`, `FacingCasterFlags`, `CasterAuraState`, `TargetAuraState`, `ExcludeCasterAuraState`, `ExcludeTargetAuraState`, `CasterAuraSpell`, `TargetAuraSpell`, `ExcludeCasterAuraSpell`, `ExcludeTargetAuraSpell`, `CasterAuraType`, `TargetAuraType`, `ExcludeCasterAuraType`, `ExcludeTargetAuraType`, `CastingTimeIndex`, `RecoveryTime`, `CategoryRecoveryTime`, `StartRecoveryCategory`, `StartRecoveryTime`, `InterruptFlags`, `AuraInterruptFlags1`, `AuraInterruptFlags2`, `ChannelInterruptFlags1`, `ChannelInterruptFlags2`, `ProcFlags`, `ProcFlags2`, `ProcChance`, `ProcCharges`, `ProcCooldown`, `ProcBasePPM`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `Speed`, `LaunchDelay`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `ContentTuningId`, `SpellName`, `ConeAngle`, `ConeWidth`, `MaxTargetLevel`, `MaxAffectedTargets`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `SpellFamilyFlags4`, `DmgClass`, `PreventionType`, `AreaGroupId`, `SchoolMask`, `ChargeCategoryId`) VALUES
(1217758, 0, 0, 0, 0, 0x20000180, 0x00000400, 0x10400004, 0x00070300, 0x00800000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, 0, 'Player Detection', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);

DELETE FROM `serverside_spell_effect` WHERE `SpellID`=1217758 AND `EffectIndex`=0 AND `DifficultyID`=0;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(1217758, 0, 0, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61, 0, 0, 0, 0, 0, 22, 15);
