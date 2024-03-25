SET @CGUID := 6000973;
SET @OGUID := 6000599;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+18;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 101789, 1481, 7705, 7754, '0', 5086, 0, 0, 1, 1260.154541015625, 1641.6875, 100.9092330932617187, 3.049184083938598632, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52129), -- Demon Hunter (Area: Cryptic Hollow - Difficulty: 0) CreateObject1 (Auras: 222589 - Glaive Anim Replacement, 42459 - Dual Wield)
(@CGUID+1, 96503, 1481, 7705, 7754, '0', 5086, 0, 0, 0, 1260.1475830078125, 1622.65283203125, 104.5185623168945312, 2.54924321174621582, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 52129), -- Coilskar Sea-Caller (Area: Cryptic Hollow - Difficulty: 0) CreateObject1
(@CGUID+2, 94655, 1481, 7705, 7754, '0', 5084, 0, 0, 0, 1268.1712646484375, 1633.87890625, 101.96368408203125, 4.924914836883544921, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 52129), -- Soul Leech (Area: Cryptic Hollow - Difficulty: 0) CreateObject1
(@CGUID+3, 96504, 1481, 7705, 7754, '0', 5086, 0, 0, 1, 1270.828125, 1629.8836669921875, 103.63201904296875, 2.806705474853515625, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52129), -- Shivarra Destroyer (Area: Cryptic Hollow - Difficulty: 0) CreateObject1
(@CGUID+4, 101790, 1481, 7705, 7754, '0', 5086, 0, 0, 1, 1256.125, 1623.560791015625, 103.582275390625, 2.434679508209228515, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52129), -- Demon Hunter (Area: Cryptic Hollow - Difficulty: 0) CreateObject1 (Auras: 222589 - Glaive Anim Replacement)
(@CGUID+5, 96500, 1481, 7705, 7754, '0', 5086, 0, 0, 1, 1264.4271240234375, 1643.5625, 100.3602523803710937, 3.099401712417602539, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52129), -- Ashtongue Warrior (Area: Cryptic Hollow - Difficulty: 0) CreateObject1
(@CGUID+6, 96502, 1481, 7705, 7754, '0', 5086, 0, 0, 1, 1262.017333984375, 1653.3472900390625, 99.29711151123046875, 3.591078042984008789, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52129), -- Coilskar Myrmidon (Area: Cryptic Hollow - Difficulty: 0) CreateObject1
(@CGUID+7, 96436, 1481, 7705, 7754, '0', 5086, 0, 0, 1, 1267.638916015625, 1631.3316650390625, 102.8649826049804687, 2.820116043090820312, 120, 0, 0, 34166, 0, 0, NULL, NULL, NULL, NULL, 52129), -- Jace Darkweaver (Area: Cryptic Hollow - Difficulty: 0) CreateObject1
(@CGUID+8, 99218, 1481, 7705, 7754, '0', 5086, 0, 0, 0, 1611.648193359375, 1615.797119140625, 69.82251739501953125, 6.044284820556640625, 120, 0, 0, 5647, 0, 0, NULL, NULL, NULL, NULL, 52129), -- Legion Devastator Missile (Area: Cryptic Hollow - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+9, 96501, 1481, 7705, 7754, '0', 5086, 0, 0, 1, 1265.703125, 1645.295166015625, 99.90142822265625, 3.22532820701599121, 120, 0, 0, 2485, 3801, 0, NULL, NULL, NULL, NULL, 52129), -- Ashtongue Mystic (Area: Cryptic Hollow - Difficulty: 0) CreateObject1
(@CGUID+10, 101787, 1481, 7705, 7754, '0', 5086, 0, 0, 1, 1262.829833984375, 1624.66845703125, 104.2876739501953125, 2.599559545516967773, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52129), -- Demon Hunter (Area: Cryptic Hollow - Difficulty: 0) CreateObject1 (Auras: 222589 - Glaive Anim Replacement, 42459 - Dual Wield)
(@CGUID+11, 96500, 1481, 7705, 7754, '0', 5086, 0, 0, 1, 1262.9305419921875, 1649.1666259765625, 100.1077728271484375, 3.395916461944580078, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52129), -- Ashtongue Warrior (Area: Cryptic Hollow - Difficulty: 0) CreateObject1
(@CGUID+12, 101788, 1481, 7705, 7754, '0', 5086, 0, 0, 1, 1267.470458984375, 1627.0885009765625, 104.1023788452148437, 2.661838054656982421, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52129), -- Demon Hunter (Area: Cryptic Hollow - Difficulty: 0) CreateObject1 (Auras: 222589 - Glaive Anim Replacement, 42459 - Dual Wield)
(@CGUID+13, 96502, 1481, 7705, 7754, '0', 5086, 0, 0, 1, 1266.3941650390625, 1624.6510009765625, 104.7028732299804687, 2.724278450012207031, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52129), -- Coilskar Myrmidon (Area: Cryptic Hollow - Difficulty: 0) CreateObject1
(@CGUID+14, 101787, 1481, 7705, 7754, '0', 5086, 0, 0, 1, 1262.451416015625, 1646.5816650390625, 100.3852386474609375, 3.394980669021606445, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52129), -- Demon Hunter (Area: Cryptic Hollow - Difficulty: 0) CreateObject1 (Auras: 222589 - Glaive Anim Replacement; 42459 - Dual Wield)
(@CGUID+15, 96493, 1481, 7705, 7754, '0', 5084, 0, 0, 1, 1222.2274169921875, 1648.2864990234375, 101.4953689575195312, 5.768243312835693359, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52129), -- Felguard Butcher (Area: Cryptic Hollow - Difficulty: 0) CreateObject1 (Auras: 191175 - Fel Invisibility)
(@CGUID+16, 96493, 1481, 7705, 7754, '0', 5084, 0, 0, 1, 1204.751708984375, 1676.079833984375, 92.766632080078125, 5.433307647705078125, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52129), -- Felguard Butcher (Area: Cryptic Hollow - Difficulty: 0) CreateObject1 (Auras: 191175 - Fel Invisibility)
(@CGUID+17, 96493, 1481, 7705, 7754, '0', 5084, 0, 0, 1, 1225.7447509765625, 1650.1805419921875, 101.721923828125, 5.705277919769287109, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52129), -- Felguard Butcher (Area: Cryptic Hollow - Difficulty: 0) CreateObject1 (Auras: 191175 - Fel Invisibility)
(@CGUID+18, 96493, 1481, 7705, 7754, '0', 5084, 0, 0, 1, 1214.521484375, 1658.967529296875, 97.752655029296875, 5.4336395263671875, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52129); -- Felguard Butcher (Area: Cryptic Hollow - Difficulty: 0) CreateObject1 (Auras: 191175 - Fel Invisibility)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+18;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '222589 42459'), -- Demon Hunter - 222589 - Glaive Anim Replacement, 42459 - Dual Wield
(@CGUID+3, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, ''), -- Shivarra Destroyer
(@CGUID+4, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '222589'), -- Demon Hunter - 222589 - Glaive Anim Replacement
(@CGUID+5, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 0, ''), -- Ashtongue Warrior
(@CGUID+6, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 0, ''), -- Coilskar Myrmidon
(@CGUID+7, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Jace Darkweaver
(@CGUID+9, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Ashtongue Mystic
(@CGUID+10, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '222589 42459'), -- Demon Hunter - 222589 - Glaive Anim Replacement, 42459 - Dual Wield
(@CGUID+11, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 0, ''), -- Ashtongue Warrior
(@CGUID+12, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '222589 42459'), -- Demon Hunter - 222589 - Glaive Anim Replacement, 42459 - Dual Wield
(@CGUID+13, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 0, ''), -- Coilskar Myrmidon
(@CGUID+14, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '222589 42459'); -- Demon Hunter - 222589 - Glaive Anim Replacement; 42459 - Dual Wield

-- GameObject
DELETE FROM `gameobject` WHERE `guid` = @OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 245045, 1481, 7705, 7754, '0', 1, 0, 0, 1237.15283203125, 1642.6180419921875, 103.1518402099609375, 5.805587291717529296, 0, 0, -0.23653602600097656, 0.971622705459594726, 120, 255, 1, 52129); -- Rockslide (Area: Cryptic Hollow - Difficulty: 0) CreateObject1

-- Template Addon
DELETE FROM `gameobject_template_addon` WHERE `entry` = 245045 /*Rockslide*/;
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(245045, 114, 32, 0, 0); -- Rockslide

DELETE FROM `creature_template_addon` WHERE `entry` = 96493;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(96493, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, '191175'); -- 96493 (Felguard Butcher) - Fel Invisibility

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` = 96436;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(96436, 0, 0, '$n, will you use your spectral sight on the cave entrance? Something\'s not right.', 12, 0, 100, 397, 0, 55233, 98201, 5, 'Jace Darkweaver to Player');

-- Phasing
DELETE FROM `phase_area` WHERE `PhaseId` = 5086 AND `AreaId` = 7705 OR `PhaseID` = 5084 AND `AreaId` = 7754;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7705, 5086, 'Kayn Sunfury and Spawns at Cryptic Hollow'),
(7754, 5084, 'Cryptic Hollow uncovered Demons');

DELETE FROM `phase_name` WHERE `ID` = 5084;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(5084, 'Cryptic Hollow uncovered Demons');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 5084 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 5084, 0, 0, 0, 47, 0, 39262, 64, 0, 1, 'Apply Phase 5084 if Quest 38813 is not rewarded');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 5086 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 5086, 0, 0, 0, 47, 0, 38813, 64, 0, 0, 'Apply Phase 5086 if Quest 38813 is rewarded'),
(26, 5086, 0, 0, 0, 47, 0, 39495, 8|2|64, 0, 1, 'Apply Phase 5086 if Quest 38813 is not in progress|complete|rewarded');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=32 AND `SourceGroup` = 8 AND `SourceEntry` = 245045);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(32, 8, 245045, 0, 0, 48, 0, 280354, 0, 1, 1, 0, 0, '', 'Rockslide gets visible if Questobjective: 280354 (Rockslide) is not rewarded'),
(32, 8, 245045, 0, 0, 47, 0, 39495, 64, 0, 1, 0, 0, '', 'Rockslide gets visible if Quest: 39495 is not rewarded');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=15 AND `SourceGroup` = 19175 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 19175, 0, 0, 0, 47, 0, 39262, 8, 0, 0, 0, 0, '', 'Show gossip menu option if quest 39262 is in progress'),
(15, 19175, 0, 0, 0, 48, 0, 279763, 0, 1, 1, 0, 0, '', 'Show gossip menu option if player has not quest objective done: Speak with Jace Darkweaver');

-- Conversation
DELETE FROM `conversation_template` WHERE `Id`=486;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(486, 1298, 0, 52129);

DELETE FROM `conversation_actors` WHERE (`ConversationId`=486 AND `Idx` IN (1,0));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `ConversationActorGuid`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(486, 49160, 1, 6000972, 0, 0, 0, 0, 52129), -- Full: 0x203CC8B9205E290000239B00005383C6 Creature/0 R3890/S9115 Map: 1481 (Mardum) Entry: 96420 (Cyana Nightglaive) Low: 5473222
(486, 47908, 0, 6000971, 0, 0, 0, 0, 52129); -- Full: 0x203CC8B9205AF1C000239B00005383C6 Creature/0 R3890/S9115 Map: 1481 (Mardum) Entry: 93127 (Kayn Sunfury) Low: 5473222

DELETE FROM `conversation_line_template` WHERE `Id` IN (1299, 1298);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(1299, 0, 1, 0, 0, 52129),
(1298, 0, 0, 0, 0, 52129);

-- Serverside Spell
DELETE FROM `serverside_spell` WHERE `Id` IN (191203, 191095, 191097);
INSERT INTO `serverside_spell` (`Id`, `DifficultyID`, `CategoryId`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `AttributesEx11`, `AttributesEx12`, `AttributesEx13`, `AttributesEx14`, `Stances`, `StancesNot`, `Targets`, `TargetCreatureType`, `RequiresSpellFocus`, `FacingCasterFlags`, `CasterAuraState`, `TargetAuraState`, `ExcludeCasterAuraState`, `ExcludeTargetAuraState`, `CasterAuraSpell`, `TargetAuraSpell`, `ExcludeCasterAuraSpell`, `ExcludeTargetAuraSpell`, `CasterAuraType`, `TargetAuraType`, `ExcludeCasterAuraType`, `ExcludeTargetAuraType`, `CastingTimeIndex`, `RecoveryTime`, `CategoryRecoveryTime`, `StartRecoveryCategory`, `StartRecoveryTime`, `InterruptFlags`, `AuraInterruptFlags1`, `AuraInterruptFlags2`, `ChannelInterruptFlags1`, `ChannelInterruptFlags2`, `ProcFlags`, `ProcFlags2`, `ProcChance`, `ProcCharges`, `ProcCooldown`, `ProcBasePPM`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `Speed`, `LaunchDelay`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `ContentTuningId`, `SpellName`, `ConeAngle`, `ConeWidth`, `MaxTargetLevel`, `MaxAffectedTargets`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `SpellFamilyFlags4`, `DmgClass`, `PreventionType`, `AreaGroupId`, `SchoolMask`, `ChargeCategoryId`) VALUES
(191203, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, 0, 'Give Me Sight Beyond Sight: Quest Accept', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(191095, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 21, 1, 0, 0, 0, -1, 0, 0, 0, 'Give Me Sight Beyond Sight: Periodic Trigger Aura', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(191097, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 21, 1, 0, 0, 0, -1, 0, 0, 0, 'Give Me Sight Beyond Sight: Periodic Trigger Dummy', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `serverside_spell_effect` WHERE `SpellID` IN (191203, 191095, 191097) AND `EffectIndex` = 0;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(191203, 0, 0, 290, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 188501, 0, 0, 0, 0, 0, 0, -30000, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(191095, 0, 0, 6, 23, 0, 0, 1000, 0, 0, 0, 0, 0, 0, 0, 0, 191203, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(191097, 0, 0, 6, 226, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);

-- SpllScript names
DELETE FROM `spell_script_names` WHERE `spell_id` = 191097;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(191097, 'spell_give_me_sight_beyond_sight_periodic');

-- Quest stuff
DELETE FROM `quest_details` WHERE `ID`=39495;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(39495, 1, 25, 0, 0, 0, 0, 0, 0, 52129); -- Hidden No More

DELETE FROM `quest_offer_reward` WHERE `ID`=39262;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(39262, 5, 0, 0, 0, 0, 0, 0, 0, 'I KNEW that I\'d sensed something foul!', 52129); -- Give Me Sight Beyond Sight

DELETE FROM `quest_request_items` WHERE `ID`=39262;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(39262, 0, 0, 0, 0, '$n, we need you to scan the cave with your spectral sight.\n\nWe must know if there are Legion forces magically hidden within.', 53877); -- Give Me Sight Beyond Sight

DELETE FROM `creature_queststarter` WHERE (`id`=96436 AND `quest`=39495);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(96436, 39495, 52129); -- Hidden No More offered Jace Darkweaver

DELETE FROM `quest_template_addon` WHERE `ID` = 39495;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(39495, 0, 0, 0, 39262, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

-- Creature 93127 smart ai
SET @ENTRY := 93127;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 60, 0, 100, 0, 1000, 4000, 4000, 7000, 10, 396, 273, 6, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 4 - 7 seconds (1 - 4s initially) - Self: Play random emote: 396, 273, 6,'),
(@ENTRY, 0, 1, 0, '', 19, 0, 100, 0, 38813, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest 38813 - Player who accepted quest: Talk 0 to invoker'),
(@ENTRY, 0, 2, 0, '', 19, 0, 100, 0, 39262, 0, 0, 0, 143, 486, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest 39262 - Start Conversation 143 - to Invoker'),
(@ENTRY, 0, 3, 0, '', 19, 0, 100, 0, 39262, 0, 0, 0, 85, 191203, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest 39262 - Player who accepted Quest: Cast spell 191095 on self');

-- Jace Darkweaver smart ai
SET @ENTRY := 96436;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 62, 0, 100, 0, 19175, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19175 selected - Gossip player: Talk 0 to invoker'),
(@ENTRY, 0, 1, 0, '', 62, 0, 100, 0, 19175, 0, 0, 0, 33, 96436, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19175 selected - Gossip player: Give kill credit Jace Darkweaver (96436)'),
(@ENTRY, 0, 2, 0, '', 62, 0, 100, 0, 19175, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19175 selected - Gossip player: Close gossip'),
(@ENTRY, 0, 3, 0, '', 62, 0, 100, 0, 19175, 0, 0, 0, 85, 191095, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19175 selected - Gossip player: Cast spell 191095 on self'),
(@ENTRY, 0, 4, 0, '', 62, 0, 100, 0, 19175, 0, 0, 0, 85, 191097, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19175 selected - Gossip player: Cast spell 191097 on self'),
(@ENTRY, 0, 5, 0, '', 20, 0, 100, 0, 39495, 0, 0, 0, 85, 82238, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player rewarded quest Hidden No More (39495) - Rewarded player: Cast spell 82238 on self');
