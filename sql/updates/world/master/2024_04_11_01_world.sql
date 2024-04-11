DELETE FROM `creature_text` WHERE `CreatureID`=54611 AND `GroupID` IN (0,1);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(54611, 0, 0, 'A challenger approaches.', 12, 0, 100, 113, 0, 0, 59692, 0, 'Jaomin Ro to Player'),
(54611, 1, 0, 'You''ve been trained well.', 12, 0, 100, 2, 0, 0, 55205, 0, 'Jaomin Ro to Player'),
(54611, 1, 1, 'Well fought. Master Shang will be pleased.', 12, 0, 100, 2, 0, 0, 55206, 0, 'Jaomin Ro to Player'),
(54611, 1, 2, 'Amazing! You''re much stronger than you look.', 12, 0, 100, 2, 0, 0, 55207, 0, 'Jaomin Ro to Player'),
(54611, 1, 3, 'It seems I have more training to do. Thank you for the lesson.', 12, 0, 100, 2, 0, 0, 55208, 0, 'Jaomin Ro to Player'),
(54611, 1, 4, 'I bow to your skill. You bested me fairly.', 12, 0, 100, 2, 0, 0, 55209, 0, 'Jaomin Ro to Player'),
(54611, 1, 5, 'It was an honor to be defeated by you.', 12, 0, 100, 2, 0, 0, 55210, 0, 'Jaomin Ro to Player');

UPDATE `creature_template_difficulty` SET `StaticFlags1`=268959758, `StaticFlags3`=8388608, `StaticFlags4`=2147483648, `VerifiedBuild`=53441 WHERE (`Entry`=54611 AND `DifficultyID`=0); -- Jaomin Ro
UPDATE `creature_template_difficulty` SET `StaticFlags1`=524806, `ContentTuningID`=80, `VerifiedBuild`=53441 WHERE (`Entry`=57750 AND `DifficultyID`=0); -- Jaomin Ro

UPDATE `creature_template` SET `faction`=2104, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=67584, `unit_flags3`=524288, `VehicleId`=1953, `ScriptName`='npc_jaomin_ro_hawk' WHERE `entry`=57750; -- Jaomin Ro
UPDATE `creature_template` SET `ScriptName`='npc_jaomin_ro' WHERE `entry`=54611; -- Jaomin Ro

DELETE FROM `creature_template_addon` WHERE `entry` = 57750;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(57750, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, '108971'); -- 57750 (Jaomin Ro) - Hawk Diving to Earth

-- Spell
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_force_summoner_to_ride_vehicle', 'spell_ride_drake');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(108583, 'spell_force_summoner_to_ride_vehicle'),
(108582, 'spell_ride_drake');

-- Areatrigger
DELETE FROM `areatrigger_scripts` WHERE `entry` = 7737;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(7737, 'SmartTrigger');

DELETE FROM `smart_scripts` WHERE `source_type` = 2 AND `entryOrGuid` = 7737;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7737, 2, 0, 0, 46, 0, 100, 0, 7737, 0, 0, 0, 0, 86, 88811, 2, 10, 450184, 54611, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On Trigger - Cast Area Trigger Dummy Timer Aura on Invoker');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` = 7737;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 7737, 2, 0, 9, 0, 29409, 0, 0, 0, 0, 0, '', 'SAI only triggers when quest taken'),
(22, 1, 7737, 2, 0, 1, 0, 88811, 0, 0, 1, 0, 0, '', 'SAI only triggers when player has not aura');

-- Serverside Spell
DELETE FROM `serverside_spell` WHERE `Id`=109837 AND `DifficultyID`=0;
INSERT INTO `serverside_spell` (`Id`, `DifficultyID`, `CategoryId`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `AttributesEx11`, `AttributesEx12`, `AttributesEx13`, `AttributesEx14`, `Stances`, `StancesNot`, `Targets`, `TargetCreatureType`, `RequiresSpellFocus`, `FacingCasterFlags`, `CasterAuraState`, `TargetAuraState`, `ExcludeCasterAuraState`, `ExcludeTargetAuraState`, `CasterAuraSpell`, `TargetAuraSpell`, `ExcludeCasterAuraSpell`, `ExcludeTargetAuraSpell`, `CasterAuraType`, `TargetAuraType`, `ExcludeCasterAuraType`, `ExcludeTargetAuraType`, `CastingTimeIndex`, `RecoveryTime`, `CategoryRecoveryTime`, `StartRecoveryCategory`, `StartRecoveryTime`, `InterruptFlags`, `AuraInterruptFlags1`, `AuraInterruptFlags2`, `ChannelInterruptFlags1`, `ChannelInterruptFlags2`, `ProcFlags`, `ProcFlags2`, `ProcChance`, `ProcCharges`, `ProcCooldown`, `ProcBasePPM`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `Speed`, `LaunchDelay`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `ContentTuningId`, `SpellName`, `ConeAngle`, `ConeWidth`, `MaxTargetLevel`, `MaxAffectedTargets`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `SpellFamilyFlags4`, `DmgClass`, `PreventionType`, `AreaGroupId`, `SchoolMask`, `ChargeCategoryId`) VALUES
(109837, 0, 0, 0, 0, 0x29800180, 0x420, 0x10484005, 0x10130200, 0x800080, 0x60008, 0x1200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, -1, 0, 0, 0, 'Jaomin Ro Credit', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);

DELETE FROM `serverside_spell_effect` WHERE `SpellID`=109837 AND `EffectIndex`=0 AND `DifficultyID`=0;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(109837, 0, 0, 134, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 54611, 0, 0, 0, 0, 0, 0, 0, 123, 0);
