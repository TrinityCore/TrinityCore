SET @CGUID := 6000970;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 96655, 1481, 7705, 7712, '0', 5160, 0, 0, 1, 1458.1649169921875, 1763.0728759765625, 54.5214080810546875, 3.169785976409912109, 120, 0, 0, 31060, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Allari the Souleater (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+1, 93127, 1481, 7705, 7712, '0', 5160, 0, 0, 1, 1456.0225830078125, 1763.717041015625, 54.52132797241210937, 4.90136575698852539, 120, 0, 0, 37272, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Kayn Sunfury (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+2, 96420, 1481, 7705, 7712, '0', 5160, 0, 0, 1, 1453.27783203125, 1762.342041015625, 54.52119827270507812, 0.269516706466674804, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106); -- Cyana Nightglaive (Area: Illidari Foothold - Difficulty: 0) CreateObject1

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (93127, 96420, 96655);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(93127, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 93127 (Kayn Sunfury)
(96420, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 96420 (Cyana Nightglaive)
(96655, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- 96655 (Allari the Souleater)

-- Scene
DELETE FROM `scene_template` WHERE `SceneId` IN (1079, 1095, 1094);
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`, `Encrypted`) VALUES
(1079, 20, 1470, 0),
(1095, 20, 1480, 0),
(1094, 20, 1479, 0);

-- Phasing
DELETE FROM `phase_area` WHERE `PhaseId` = 5160 AND `AreaId` = 7705;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7705, 5160, 'Cyana Nightglaive, Kayn Sunfury and Allari the Souleater at Illidari Foothold');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 4881 AND `SourceEntry` = 0); -- Ashtongue
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4881, 0, 0, 0, 47, 0, 40378, 2|64, 0, 0, 'Apply Phase 4881 if Quest 40378 is completed | rewarded'),
(26, 4881, 0, 0, 0, 47, 0, 38813, 64, 0, 1, 'Apply Phase 4881 if Quest 38813 is not rewarded'),
(26, 4881, 0, 0, 0, 48, 0, 278472, 0, 1, 1, 'Apply Phase 4881 if Questobjective 278472 (Battlelord Gaardoun briefed) is not rewarded');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 4883 AND `SourceEntry` = 0); -- Coilskar
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4883, 0, 0, 0, 47, 0, 40379, 2|64, 0, 0, 'Apply Phase 4883 if Quest 40379 is completed | rewarded'),
(26, 4883, 0, 0, 0, 47, 0, 38813, 64, 0, 1, 'Apply Phase 4883 if Quest 38813 is not rewarded'),
(26, 4883, 0, 0, 0, 48, 0, 278473, 0, 1, 1, 'Apply Phase 4883 if Questobjective 278473 (Lady Stheno briefed) is not rewarded');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 4884 AND `SourceEntry` = 0); -- Shivarra
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4884, 0, 0, 0, 47, 0, 38765, 2|64, 0, 0, 'Apply Phase 4884 if Quest 38765 is completed | rewarded'),
(26, 4884, 0, 0, 0, 47, 0, 38813, 64, 0, 1, 'Apply Phase 4884 if Quest 38813 is not rewarded'),
(26, 4884, 0, 0, 0, 48, 0, 278955, 0, 1, 1, 'Apply Phase 4884 if Questobjective 278955 (Matron Mother Malevolence briefed) is not rewarded');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (17260, 18447, 18434) AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 17260, 0, 0, 0, 47, 0, 38813, 8, 0, 0, 0, 0, '', 'Show gossip menu option if quest 38813 is in progress'),
(15, 17260, 0, 0, 0, 48, 0, 278472, 0, 1, 1, 0, 0, '', 'Show gossip menu option if player has not quest objective done: Battlelord Gaardoun briefed'),
(15, 18447, 0, 0, 0, 47, 0, 38813, 8, 0, 0, 0, 0, '', 'Show gossip menu option if quest 38813 is in progress'),
(15, 18447, 0, 0, 0, 48, 0, 278473, 0, 1, 1, 0, 0, '', 'Show gossip menu option if player has not quest objective done: Lady Stheno briefed'),
(15, 18434, 0, 0, 0, 47, 0, 38813, 8, 0, 0, 0, 0, '', 'Show gossip menu option if quest 38813 is in progress'),
(15, 18434, 0, 0, 0, 48, 0, 278955, 0, 1, 1, 0, 0, '', 'Show gossip menu option if player has not quest objective done: Matron Mother Malevolence briefed');

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` IN (90247, 93127, 93693, 94435);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(90247, 0, 0, 'It will be as you say.', 12, 0, 100, 1, 0, 55044, 98400, 0, 'Battlelord Gaardoun to Player'),
(90247, 1, 0, 'Ashtongue with me!', 14, 0, 100, 15, 0, 55045, 98402, 0, 'Battlelord Gaardoun to Player'),
(93127, 0, 0, 'The spider fortress, the soul engine, and the forge are their primary targets. The Servants of Illidan must succeed.', 12, 0, 100, 6, 0, 55263, 98617, 5, 'Kayn Sunfury to Player'),
(93693, 0, 0, 'A fine task for the Coilskar. I am in agreement.', 12, 0, 100, 396, 0, 55295, 98553, 0, 'Lady S\'theno to Player'),
(93693, 1, 0, 'Let us be done with this business. A volcano is no place for naga.', 12, 0, 100, 396, 0, 55294, 98554, 0, 'Lady S\'theno to Player'),
(94435, 0, 0, 'We will see it done. I urge you to remember that the Black Temple is under attack.', 12, 0, 100, 1, 0, 55314, 98560, 0, 'Matron Mother Malevolence to Player'),
(94435, 1, 0, 'Time is of the essence. Come, sisters, our former brethren await our tender mercies.', 12, 0, 100, 1, 0, 55315, 98561, 0, 'Matron Mother Malevolence to Player');

-- Serverside Spell
DELETE FROM `serverside_spell` WHERE `Id` IN (184644, 184645, 187014);
INSERT INTO `serverside_spell` (`Id`, `DifficultyID`, `CategoryId`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `AttributesEx11`, `AttributesEx12`, `AttributesEx13`, `AttributesEx14`, `Stances`, `StancesNot`, `Targets`, `TargetCreatureType`, `RequiresSpellFocus`, `FacingCasterFlags`, `CasterAuraState`, `TargetAuraState`, `ExcludeCasterAuraState`, `ExcludeTargetAuraState`, `CasterAuraSpell`, `TargetAuraSpell`, `ExcludeCasterAuraSpell`, `ExcludeTargetAuraSpell`, `CasterAuraType`, `TargetAuraType`, `ExcludeCasterAuraType`, `ExcludeTargetAuraType`, `CastingTimeIndex`, `RecoveryTime`, `CategoryRecoveryTime`, `StartRecoveryCategory`, `StartRecoveryTime`, `InterruptFlags`, `AuraInterruptFlags1`, `AuraInterruptFlags2`, `ChannelInterruptFlags1`, `ChannelInterruptFlags2`, `ProcFlags`, `ProcFlags2`, `ProcChance`, `ProcCharges`, `ProcCooldown`, `ProcBasePPM`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `Speed`, `LaunchDelay`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `ContentTuningId`, `SpellName`, `ConeAngle`, `ConeWidth`, `MaxTargetLevel`, `MaxAffectedTargets`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `SpellFamilyFlags4`, `DmgClass`, `PreventionType`, `AreaGroupId`, `SchoolMask`, `ChargeCategoryId`) VALUES
(184644, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000080, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, 0, 'Orders for Your Captains: Battlelord Gaardoun Briefed', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(184645, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000080, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, 0, 'Orders for Your Captains: Lady Stheno Briefed', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(187014, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000080, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, 0, 'Orders for Your Captains: Matron Mother Malevolence Briefed', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `serverside_spell_effect` WHERE `SpellID` IN (184644, 184645, 187014) AND `EffectIndex` IN (0, 1);
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(184644, 0, 0, 90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 90247, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(184644, 1, 0, 140, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 191315, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(184645, 0, 0, 90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 93693, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(184645, 1, 0, 140, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 191400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(187014, 0, 0, 90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 94435, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(187014, 1, 0, 140, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 191402, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);

-- Creature 90247 smart ai
SET @ENTRY := 90247;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 62, 0, 100, 0, 17260, 0, 0, 0, 85, 184644, 3, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 17260 selected - Gossip player: Cast spell  184644 with flags interrupt previous, triggered on self'),
(@ENTRY, 0, 1, 0, '', 62, 0, 100, 0, 17260, 0, 0, 0, 80, 9024700, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 17260 selected - Self: Start timed action list id #9024700 (update out of combat)'),
(@ENTRY, 0, 2, 0, '', 62, 0, 100, 0, 17260, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 17260 selected - Gossip player: Close gossip');

-- Timed list 9024700 smart ai
SET @ENTRY := 9024700;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 149, 8, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - become Personal Clone - Invoker'),
(@ENTRY, 9, 1, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Owner/Summoner: Talk 0 to invoker'),
(@ENTRY, 9, 2, 0, '', 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 7 seconds - Owner/Summoner: Talk 1 to invoker'),
(@ENTRY, 9, 3, 0, '', 0, 0, 100, 0, 3000, 3000, 0, 0, 53, 1, 9024700, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3 seconds - Self: Start path #9024700, run, do not repeat, Passive'),
(@ENTRY, 9, 4, 0, '', 0, 0, 100, 0, 10000, 10000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 10 seconds - Self: Despawn instantly');

-- Creature 93693 smart ai
SET @ENTRY := 93693;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 62, 0, 100, 0, 18447, 0, 0, 0, 85, 184645, 3, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 18447 selected - Gossip player: Cast spell  184645 with flags interrupt previous, triggered on self'),
(@ENTRY, 0, 1, 0, '', 62, 0, 100, 0, 18447, 0, 0, 0, 80, 9369300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 18447 selected - Self: Start timed action list id #9369300 (update out of combat)'),
(@ENTRY, 0, 2, 0, '', 62, 0, 100, 0, 18447, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 18447 selected - Gossip player: Close gossip');

-- Timed list 9369300 smart ai
SET @ENTRY := 9369300;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 149, 8, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - become Personal Clone - Invoker'),
(@ENTRY, 9, 1, 0, '', 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Owner/Summoner: Talk 0 to invoker'),
(@ENTRY, 9, 2, 0, '', 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 7 seconds - Owner/Summoner: Talk 1 to invoker'),
(@ENTRY, 9, 3, 0, '', 0, 0, 100, 0, 4000, 4000, 0, 0, 53, 1, 9369300, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 4 seconds - Self: Start path #9369300, run, do not repeat, Passive'),
(@ENTRY, 9, 4, 0, '', 0, 0, 100, 0, 11000, 11000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 11 seconds - Self: Despawn instantly');

-- Creature 94435 smart ai
SET @ENTRY := 94435;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 62, 0, 100, 0, 18434, 0, 0, 0, 85, 187014, 3, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 18434 selected - Gossip player: Cast spell  187014 with flags interrupt previous, triggered on self'),
(@ENTRY, 0, 1, 0, '', 62, 0, 100, 0, 18434, 0, 0, 0, 80, 9443500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 18434 selected - Self: Start timed action list id #9443500 (update out of combat)'),
(@ENTRY, 0, 2, 0, '', 62, 0, 100, 0, 18434, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 18434 selected - Gossip player: Close gossip');

-- Timed list 9443500 smart ai
SET @ENTRY := 9443500;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 149, 8, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - become Personal Clone - Invoker'),
(@ENTRY, 9, 1, 0, '', 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Owner/Summoner: Talk 0 to invoker'),
(@ENTRY, 9, 2, 0, '', 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 7 seconds - Owner/Summoner: Talk 1 to invoker'),
(@ENTRY, 9, 3, 0, '', 0, 0, 100, 0, 2000, 2000, 0, 0, 137, 43182, 4, 2000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Plays SpellVisual with SpellVisualKitId: 43182, KitType: 4 for 2000 ms'),
(@ENTRY, 9, 4, 0, '', 0, 0, 100, 0, 2000, 2000, 0, 0, 5, 463, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Play emote 463'),
(@ENTRY, 9, 5, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 137, 43576, 4, 1000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Plays SpellVisual with SpellVisualKitId: 43576, KitType: 4 for 1000 ms'),
(@ENTRY, 9, 6, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 137, 64094, 4, 2000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Plays SpellVisual with SpellVisualKitId: 64094, KitType: 4 for 2000 ms'),
(@ENTRY, 9, 7, 0, '', 0, 0, 100, 0, 2000, 2000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Despawn instantly');

-- Creature 93127 smart ai
SET @ENTRY := 93127;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 60, 0, 100, 0, 1000, 4000, 4000, 7000, 10, 396, 273, 6, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 4 - 7 seconds (1 - 4s initially) - Self: Play random emote: 396, 273, 6,'),
(@ENTRY, 0, 1, 0, '', 19, 0, 100, 0, 38813, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest 38813 - Player who accepted quest: Talk 0 to invoker');

-- Creature 96655 smart ai
SET @ENTRY := 96655;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 60, 0, 100, 0, 1000, 6000, 5000, 7000, 10, 6, 274, 273, 396, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 7 seconds (1 - 6s initially) - Self: Play random emote: 6, 274, 273, 396,');

-- Creature 96420 smart ai
SET @ENTRY := 96420;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 60, 0, 100, 0, 1000, 5000, 5000, 8000, 10, 5, 25, 273, 1, 274, 15, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 8 seconds (1 - 5s initially) - Self: Play random emote: 5, 25, 273, 1, 274, 15');

-- Gossip
UPDATE `gossip_menu_option` SET `GossipOptionID`=44410, `VerifiedBuild`=52106 WHERE (`MenuID`=18447 AND `OptionID`=0);
UPDATE `gossip_menu_option` SET `GossipOptionID`=44407, `VerifiedBuild`=52106 WHERE (`MenuID`=18435 AND `OptionID`=0);
UPDATE `gossip_menu_option` SET `GossipOptionID`=42930, `VerifiedBuild`=52106 WHERE (`MenuID`=17260 AND `OptionID`=0);
UPDATE `gossip_menu_option` SET `GossipOptionID`=44865, `VerifiedBuild`=52106 WHERE (`MenuID`=18434 AND `OptionID`=0);

-- Quest stuff
DELETE FROM `quest_offer_reward` WHERE `ID` IN (38813 /*Orders for Your Captains*/, 38766 /*Before We're Overrun*/, 38765 /*Enter the Illidari: Shivarra*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(38813, 273, 0, 0, 0, 0, 0, 0, 0, 'Our forces have engaged the Legion.\n\nSoon we will stand together victorious with Lord Illidan at the Black Temple.', 52106), -- Orders for Your Captains
(38766, 273, 0, 0, 0, 0, 0, 0, 0, 'Already, the flow of demons from below has slowed to a trickle.\n\nI can sense the doom guard\'s energy. You have become more powerful.', 52106), -- Before We're Overrun
(38765, 274, 1, 0, 0, 0, 0, 0, 0, 'Grim. But demon hunters are no strangers to sacrifice. We have given everything to become what we are.\n\nThe Legion will fall. We await your orders, $n.', 52106); -- Enter the Illidari: Shivarra

DELETE FROM `quest_details` WHERE `ID` IN (39262 /*Give Me Sight Beyond Sight*/, 38813 /*Orders for Your Captains*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(39262, 6, 0, 0, 0, 0, 0, 0, 0, 52106), -- Give Me Sight Beyond Sight
(38813, 1, 0, 0, 0, 0, 0, 0, 0, 52106); -- Orders for Your Captains

DELETE FROM `quest_request_items` WHERE `ID`=38813;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(38813, 0, 6, 0, 0, 'Are we ready to commence the assault?', 52106); -- Orders for Your Captains

DELETE FROM `quest_objectives_completion_effect` WHERE `ObjectiveID` IN (278472, 278473, 278955);
INSERT INTO `quest_objectives_completion_effect` (`ObjectiveID`, `GameEventID`, `SpellID`, `ConversationID`, `UpdatePhaseShift`, `UpdateZoneAuras`) VALUES
(278472, NULL, NULL, NULL, 1, 0),
(278473, NULL, NULL, NULL, 1, 0),
(278955, NULL, NULL, NULL, 1, 0);

DELETE FROM `creature_queststarter` WHERE (`id`=93127 AND `quest` IN (39262,38813));
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(93127, 39262, 52106), -- Give Me Sight Beyond Sight offered Kayn Sunfury
(93127, 38813, 52106); -- Orders for Your Captains offered Kayn Sunfury

UPDATE `quest_template_addon` SET `NextQuestID` = 38813, `ExclusiveGroup` = -38765 WHERE `ID` = 38765;

DELETE FROM `quest_template_addon` WHERE `ID` IN (38766, 39262);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(38766, 0, 0, 0, 39050, 38813, -38765, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''),
(39262, 0, 0, 0, 38813, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

-- Path for Battlelord Gardoun
SET @ENTRY := 90247;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 0, 1395.531, 1696.851, 54.48559, NULL, 0, 1),
(@PATH, 1, 1389.953, 1693.366, 56.7639, NULL, 0, 1),
(@PATH, 2, 1377.99, 1685.118, 58.96307, NULL, 0, 1),
(@PATH, 3, 1367.92, 1676.408, 60.96972, NULL, 0, 1),
(@PATH, 4, 1358.097, 1662.188, 61.42056, NULL, 0, 1),
(@PATH, 5, 1354.125, 1649.109, 61.47375, NULL, 0, 1),
(@PATH, 6, 1341.635, 1631.356, 60.7751, NULL, 0, 1),
(@PATH, 7, 1331.135, 1615.684, 57.69614, NULL, 0, 1);

-- Path for Lady Stheno
SET @ENTRY := 93693;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 0, 1440.04, 1798.306, 57.0761, NULL, 0, 1),
(@PATH, 1, 1454.142, 1794.625, 54.07853, NULL, 0, 1),
(@PATH, 2, 1476.059, 1800.788, 51.81568, NULL, 0, 1),
(@PATH, 3, 1501.885, 1800.394, 47.61089, NULL, 0, 1),
(@PATH, 4, 1530.016, 1801.104, 45.29791, NULL, 0, 1),
(@PATH, 5, 1534.41, 1801.161, 45.05981, NULL, 0, 1);
