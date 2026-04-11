SET @ATSPAWN := 274;
SET @ATPROP := 169;
SET @ATID := 176;

-- Template
UPDATE `creature_template` SET `ScriptName` = 'npc_fel_lord_caza_cryptic_hollow' WHERE `entry` = 96441;
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags2`=0x4000800, `unit_flags3`=0x41080001, `AIName`='SmartAI' WHERE `entry`=100062; -- Fel Axe

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (100062, 96441);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(100062, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 100062 (Fel Axe)
(96441, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '196769'); -- 96441 (Fel Lord Caza) - Armed

-- AreaTrigger
DELETE FROM `areatrigger_template` WHERE (`Id`=10037 AND `IsCustom`=0);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES
(10037, 0, 0, 57212);

DELETE FROM `areatrigger_template` WHERE `Id` BETWEEN @ATID+0 AND @ATID+2 AND `IsCustom`=1;
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES
(@ATID+0, 1, 1, 0),
(@ATID+1, 1, 1, 0),
(@ATID+2, 1, 1, 0);

DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` IN (5315, 5298, 5295));
DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=1 AND `Id`=@ATPROP);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES 
(5315, 0, 10037, 0, 4, 0, 0, 0, 0, -1, 0, 0, 197180, 6000, 1, 0, 15, 15, 0, 0, 0, 0, 0, 0, 'at_fel_lord_caza_fel_infusion', 57212), -- Spell: 197180 (Fel Infusion)
(5298, 0, @ATID+0, 1, 4, 0, 0, 0, 0, -1, 0, 0, 197180, 10000, 1, 0, 5, 5, 0, 0, 0, 0, 0, 0, 'at_fel_lord_caza_fel_infusion', 57212), -- Spell: 196988 (Violent Fel Energy)
(5295, 0, @ATID+1, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 40, 0, 5, 5, 0, 0, 0, 0, 0, 0, 'at_fel_lord_caza_throw_axe_knockback', 57212),
(@ATPROP, 1, @ATID+2, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 8, 20, 1, 8, 20, 1, 0, 0, 'at_fel_lord_caza_intro', 0);

-- Serverside Areatrigger
DELETE FROM `areatrigger` WHERE `SpawnId`=@ATSPAWN;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `ScriptName`, `Comment`, `VerifiedBuild`) VALUES
(@ATSPAWN, @ATPROP, 1, 1481, 0, 1091.278809, 1637.828247, 115.609467, 5.082482, 0, 5077, 0, '', 'Cryptic Hollow - Fel Lord Caza', 0);

-- ScriptName
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_fel_lord_caza_throwing_axe_selector', 'spell_fel_lord_caza_dies_02', 'spell_fel_lord_caza_disarmed');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(196889, 'spell_fel_lord_caza_throwing_axe_selector'),
(210103, 'spell_fel_lord_caza_dies_02'),
(196892, 'spell_fel_lord_caza_disarmed');

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` = 96441;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(96441, 0, 0, 'Damn your spectral sight!', 14, 0, 100, 0, 0, 55172, 98023, 0, 'Fel Lord Caza to Player'),
(96441, 1, 0, 'My axe never misses its mark.', 14, 0, 100, 0, 0, 55174, 103483, 0, 'Fel Lord Caza to Axe Throw Stalker'),
(96441, 2, 0, 'I would have sundered your forces...', 12, 0, 100, 0, 0, 55173, 98274, 0, 'Fel Lord Caza to Player');

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=773, `StaticFlags1`=0x20000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=57212 WHERE (`Entry`=100062 AND `DifficultyID`=0); -- 100062 (Fel Axe) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=57212 WHERE (`DifficultyID`=0 AND `Entry` IN (97597,94655,101790,97601,96441,100061,97598));

-- SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`= 100062 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(100062, 0, 0, 1, '', 63, 0, 100, 0, 0, 0, 0, 0, 0, '', 8, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Fel Axe - On Just Summoned - Set Passive'),
(100062, 0, 1, 2, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 85, 196988, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Fel Axe - On Just Summoned - Cast \'Violent Fel Energy\''),
(100062, 0, 2, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 85, 196984, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Fel Axe - On Just Summoned - Cast \'Fel Axe\'');

-- Spells
DELETE FROM `spell_target_position` WHERE `ID` = 196875;
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `OrderIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(196875, 0, 0, 1481, 1087.2742919921875, 1626.1614990234375, 116.7649612426757812, 60822), -- Spell: 196875 (Throw Axe) Effect 0: 42 (SPELL_EFFECT_JUMP_DEST)
(196875, 0, 1, 1481, 1119.779541015625, 1612.4444580078125, 116.5227890014648437, 60822), -- Spell: 196875 (Throw Axe) Effect 0: 42 (SPELL_EFFECT_JUMP_DEST)
(196875, 0, 2, 1481, 1097.99658203125, 1598.2569580078125, 116.8708877563476562, 60822), -- Spell: 196875 (Throw Axe) Effect 0: 42 (SPELL_EFFECT_JUMP_DEST)
(196875, 0, 3, 1481, 1089.2239990234375, 1609.329833984375, 116.8122177124023437, 60822); -- Spell: 196875 (Throw Axe) Effect 0: 42 (SPELL_EFFECT_JUMP_DEST)

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (196889, 210107);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 196889, 0, 0, 51, 0, 5, 100061, 0, '', 0, 0, 0, '', 'Spell \'Throw Axe\' can only hit \'Axe Throw Stalker\''),
(13, 1, 210107, 0, 0, 51, 0, 5, 96441, 0, '', 0, 0, 0, '', 'Spell \'Hidden No More: Taking Power 02\' can only hit \'Fel Lord Caza\'');

-- Serverside spells
DELETE FROM `serverside_spell` WHERE `Id` IN (197471, 210103, 210104, 210109) AND `DifficultyID`=0;
INSERT INTO `serverside_spell` (`Id`, `DifficultyID`, `CategoryId`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `AttributesEx11`, `AttributesEx12`, `AttributesEx13`, `AttributesEx14`, `AttributesEx15`, `Stances`, `StancesNot`, `Targets`, `TargetCreatureType`, `RequiresSpellFocus`, `FacingCasterFlags`, `CasterAuraState`, `TargetAuraState`, `ExcludeCasterAuraState`, `ExcludeTargetAuraState`, `CasterAuraSpell`, `TargetAuraSpell`, `ExcludeCasterAuraSpell`, `ExcludeTargetAuraSpell`, `CasterAuraType`, `TargetAuraType`, `ExcludeCasterAuraType`, `ExcludeTargetAuraType`, `CastingTimeIndex`, `RecoveryTime`, `CategoryRecoveryTime`, `StartRecoveryCategory`, `StartRecoveryTime`, `InterruptFlags`, `AuraInterruptFlags1`, `AuraInterruptFlags2`, `ChannelInterruptFlags1`, `ChannelInterruptFlags2`, `ProcFlags`, `ProcFlags2`, `ProcChance`, `ProcCharges`, `ProcCooldown`, `ProcBasePPM`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `Speed`, `LaunchDelay`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `ContentTuningId`, `SpellName`, `ConeAngle`, `ConeWidth`, `MaxTargetLevel`, `MaxAffectedTargets`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `SpellFamilyFlags4`, `DmgClass`, `PreventionType`, `AreaGroupId`, `SchoolMask`, `ChargeCategoryId`) VALUES
(197471, 0, 0, 0, 0, 0x29800180, 0x00000420, 0x10484005, 0x10130200, 0x00800080, 0x000E0008, 0x00001200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, -1, 0, 0, 0, 'Hidden No More: Area Trigger Dummy to Fel Lord Caza', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(210103, 0, 0, 0, 0, 0x29800180, 0x00000420, 0x10484005, 0x10130200, 0x00800080, 0x00060008, 0x00001200, 0, 0, 0x00100000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, 0, 'Hidden No More: Fel Lord Caza Dies 02', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(210104, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000080, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, 0, 'Hidden No More: Kill Credit', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(210109, 0, 0, 0, 0, 0x29800180, 0x00000420, 0x10484005, 0x10130200, 0x00800080, 0x00060008, 0x00001200, 0, 0, 0x00100000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, 0, 'Hidden No More: Taking Power 03', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `serverside_spell_effect` WHERE `SpellID` IN (197471, 210103, 210104, 210109) AND `EffectIndex`=0 AND `DifficultyID`=0;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(197471, 0, 0, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25, 0),
(210103, 0, 0, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(210104, 0, 0, 90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 106014, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(210109, 0, 0, 6, 23, 0, 0, 3000, 0, 1, 0, 0, 0, 0, 0, 0, 210104, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);
