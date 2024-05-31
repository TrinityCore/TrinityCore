-- Creature
UPDATE `creature_template` SET `ScriptName`='boss_adarogg' WHERE `entry`=61408;

UPDATE `creature` SET `StringId`='npc_corrupted_houndmaster_1' WHERE `guid`=4000039;
UPDATE `creature` SET `StringId`='npc_corrupted_houndmaster_2' WHERE `guid`=4000052;

-- Spells
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (120064, 119405, 119298, 120113);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 120064, 0, 0, 51, 0, 5, 61659, 0, '', 0, 0, 0, '', 'Spell \'Eat Trog\' can only hit \'Slain Trogg\''),
(13, 1, 120064, 0, 1, 51, 0, 5, 61669, 0, '', 0, 0, 0, '', 'Spell \'Eat Trog\' can only hit \'Oggleflint\''),
(13, 1, 119405, 0, 0, 51, 0, 5, 61409, 0, '', 0, 0, 0, '', 'Spell \'Inferno Charge\' can only hit \'Demonic Leap\''),
(13, 1, 119298, 0, 0, 51, 0, 5, 61409, 0, '', 0, 0, 0, '', 'Spell \'Inferno Charge\' can only hit \'Demonic Leap\''),
(13, 1, 120113, 0, 0, 51, 0, 5, 61666, 0, '', 0, 0, 0, '', 'Spell \'Adjules Chow Time\' can only hit \'Corrupted Houndmaster\''),
(13, 2, 120113, 0, 0, 51, 0, 5, 61666, 0, '', 0, 0, 0, '', 'Spell \'Adjules Chow Time\' can only hit \'Corrupted Houndmaster\'');

-- Serverside spells
DELETE FROM `serverside_spell` WHERE `Id` IN (119297, 119298) AND `DifficultyID`=0;
INSERT INTO `serverside_spell` (`Id`, `DifficultyID`, `CategoryId`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `AttributesEx11`, `AttributesEx12`, `AttributesEx13`, `AttributesEx14`, `Stances`, `StancesNot`, `Targets`, `TargetCreatureType`, `RequiresSpellFocus`, `FacingCasterFlags`, `CasterAuraState`, `TargetAuraState`, `ExcludeCasterAuraState`, `ExcludeTargetAuraState`, `CasterAuraSpell`, `TargetAuraSpell`, `ExcludeCasterAuraSpell`, `ExcludeTargetAuraSpell`, `CasterAuraType`, `TargetAuraType`, `ExcludeCasterAuraType`, `ExcludeTargetAuraType`, `CastingTimeIndex`, `RecoveryTime`, `CategoryRecoveryTime`, `StartRecoveryCategory`, `StartRecoveryTime`, `InterruptFlags`, `AuraInterruptFlags1`, `AuraInterruptFlags2`, `ChannelInterruptFlags1`, `ChannelInterruptFlags2`, `ProcFlags`, `ProcFlags2`, `ProcChance`, `ProcCharges`, `ProcCooldown`, `ProcBasePPM`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `Speed`, `LaunchDelay`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `ContentTuningId`, `SpellName`, `ConeAngle`, `ConeWidth`, `MaxTargetLevel`, `MaxAffectedTargets`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `SpellFamilyFlags4`, `DmgClass`, `PreventionType`, `AreaGroupId`, `SchoolMask`, `ChargeCategoryId`) VALUES
(119297, 0, 0, 0, 0, 256, 0, 0, 256, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28, 5, 0, 0, 0, -1, 0, 0, 0, 'Inferno Charge', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(119298, 0, 0, 0, 0, 256, 0, 0, 0, 0, 0, 0, 0, 134217728, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 25, 0, 0, -1, 0, 0, 0, 'Inferno Charge', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);

DELETE FROM `serverside_spell_effect` WHERE `SpellID` IN (119297, 119298) AND `EffectIndex`=0 AND `DifficultyID`=0;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(119297, 0, 0, 28, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61409, 491, 0, 0, 0, 0, 0, 0, 53, 0),
(119298, 0, 0, 96, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 119299, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 46, 0);

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID`=61666;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(61666, 0, 0, 'He\'s cornered!', 14, 0, 100, 0, 0, 0, 61203, 0, 'Corrupted Houndmaster to Player'),
(61666, 1, 0, 'We\'ve got him now!', 14, 0, 100, 0, 0, 0, 61204, 0, 'Corrupted Houndmaster to Player');

-- Areatrigger
DELETE FROM `areatrigger_scripts` WHERE `entry`=7904;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(7904, 'at_adarogg_intro');

-- Waypoint
SET @ENTRY := 61408;
SET @PATH := @ENTRY * 100;
DELETE FROM `waypoint_path` WHERE `PathId` BETWEEN @PATH+0 AND @PATH+2;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH+0, 0, 0, 'Adarogg - Intro - Oggleflint from start'),
(@PATH+1, 0, 0, 'Adarogg - Intro - Slain Trogg'),
(@PATH+2, 0, 0, 'Adarogg - Intro - Oggleflint from Slain Trogg');

DELETE FROM `waypoint_path_node` WHERE `PathId` BETWEEN @PATH+0 AND @PATH+2;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH+0, 0, -277.3586, -36.89559, -60.6918, NULL, 0),
(@PATH+1, 0, -278.8507, -54.90896, -60.57021, NULL, 0),
(@PATH+1, 1, -285.0681, -66.49124, -60.46365, NULL, 0),
(@PATH+1, 2, -286.4794, -74.89896, -60.55044, NULL, 0),
(@PATH+2, 0, -278.9581, -43.25373, -60.82312, NULL, 0),
(@PATH+2, 1, -277.3586, -36.89559, -60.6918, NULL, 0);
