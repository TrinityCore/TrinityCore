-- Conversation
DELETE FROM `conversation_actors` WHERE (`ConversationId`=922 AND `Idx` IN (2,1,0));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(922, 50662, 2, 0, 0, 0, 0, 50622), -- Full: 0x203AE8B9205FFD0000062700004BB5D8 Creature/0 R3770/S1575 Map: 1481 (Mardum) Entry: 98292 (Kor'vas Bloodthorn) Low: 4961752
(922, 48466, 1, 0, 0, 0, 0, 50622), -- Full: 0x203AE8B9205AD4C000062700004BB5D8 Creature/0 R3770/S1575 Map: 1481 (Mardum) Entry: 93011 (Kayn Sunfury) Low: 4961752
(922, 0, 0, 0, 0, 0, 1, 50622); -- Full: 0x0800040000000000FFFFFFFFFFFFFFFF Player/0 R1/S16777215 Map: 0 (Eastern Kingdoms) Low: 1099511627775

DELETE FROM `conversation_line_template` WHERE `Id` IN (2289, 2288, 2287, 2529);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(2289, 0, 2, 0, 1, 50622),
(2288, 0, 1, 0, 0, 50622),
(2287, 0, 1, 0, 0, 50622),
(2529, 0, 0, 0, 0, 50622);

DELETE FROM `conversation_template` WHERE `Id`=922;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(922, 2529, 0, 50622);

-- Quest stuff
DELETE FROM `quest_details` WHERE `ID`=40077;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(40077, 0, 0, 0, 0, 0, 0, 0, 0, 50622); -- The Invasion Begins

DELETE FROM `creature_queststarter` WHERE (`id`=93011 AND `quest`=40077);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(93011, 40077, 50622); -- The Invasion Begins offered Kayn Sunfury

-- Creature Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`Entry`=94580 AND `DifficultyID`=0);
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `VerifiedBuild`) VALUES
(94580, 0, 0, 0, 699, 6, 1, 1, 94555, 0, 0, 50622); -- Wrath Warrior

-- Creature Equip
DELETE FROM `creature_equip_template` WHERE (`CreatureID`=94580 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(94580, 1, 127651, 0, 0, 0, 0, 0, 0, 0, 0, 50622); -- Wrath Warrior

-- Creature Template
UPDATE `creature_template` SET `faction`=954, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480, `unit_flags3`=524288, `flags_extra` = 536870912 WHERE `entry`=94580; -- Wrath Warrior

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (94580);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(94580, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 5, ''); -- 94580 (Wrath Warrior)

-- Update Condition for Phase 4899
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` = 4899 AND `SourceEntry` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4899, 0, 0, 0, 47, 0, 40076, 64, 0, 0, 'Apply Phase 4899 if Quest 40076 is rewarded'),
(26, 4899, 0, 0, 0, 47, 0, 40077, 2 | 8 | 64, 0, 1, 'Apply Phase 4899 if Quest 40076 is not in progress | complete | rewarded');

-- Update Scripts
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_kayn_sunfury_invasion_begins' WHERE `entry` = 93011;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_jayce_darkweaver_invasion_begins' WHERE `entry` = 98228;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_allari_the_souleater_invasion_begins' WHERE `entry` = 98227;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_korvas_bloodthorn_invasion_begins' WHERE `entry` = 98292;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_sevis_brightflame_invasion_begins' WHERE `entry` = 99918;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_cyana_nightglaive_invasion_begins' WHERE `entry` = 98290;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_illidari_fighting_invasion_begins' WHERE `entry` IN (98459, 98458, 98456, 98460, 99919, 98457);
UPDATE `conversation_template` SET `ScriptName` = 'conversation_the_invasion_begins' WHERE `Id` = 922;

-- Serverside Spells
DELETE FROM `serverside_spell` WHERE `Id` = 175799;
INSERT INTO `serverside_spell` (`Id`, `DifficultyID`, `CategoryId`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `AttributesEx11`, `AttributesEx12`, `AttributesEx13`, `AttributesEx14`, `Stances`, `StancesNot`, `Targets`, `TargetCreatureType`, `RequiresSpellFocus`, `FacingCasterFlags`, `CasterAuraState`, `TargetAuraState`, `ExcludeCasterAuraState`, `ExcludeTargetAuraState`, `CasterAuraSpell`, `TargetAuraSpell`, `ExcludeCasterAuraSpell`, `ExcludeTargetAuraSpell`, `CasterAuraType`, `TargetAuraType`, `ExcludeCasterAuraType`, `ExcludeTargetAuraType`, `CastingTimeIndex`, `RecoveryTime`, `CategoryRecoveryTime`, `StartRecoveryCategory`, `StartRecoveryTime`, `InterruptFlags`, `AuraInterruptFlags1`, `AuraInterruptFlags2`, `ChannelInterruptFlags1`, `ChannelInterruptFlags2`, `ProcFlags`, `ProcFlags2`, `ProcChance`, `ProcCharges`, `ProcCooldown`, `ProcBasePPM`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `Speed`, `LaunchDelay`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `ContentTuningId`, `SpellName`, `ConeAngle`, `ConeWidth`, `MaxTargetLevel`, `MaxAffectedTargets`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `SpellFamilyFlags4`, `DmgClass`, `PreventionType`, `AreaGroupId`, `SchoolMask`, `ChargeCategoryId`) VALUES
(175799, 0, 0, 0, 0, 0, (0x00000004 | 0x00004000), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, (0x00000008), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 21, 13, 0, 0, 0, -1, 0, 0, 0, '(Serverside/Non-DB2) Generic - Track Target in Channel (Not Unique)', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `serverside_spell_effect` WHERE `SpellID` = 175799;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(175799, 0, 0, 6, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25, 0);

 -- Wrath Warrior smart ai
SET @ENTRY := 94580;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 53, 1, 9458000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On just created - Self: Start path #9458000, run, do not repeat, Passive');

-- Waypoints for Illidari
SET @ENTRY := 98228; -- Jayce Darkweaver
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 0, 1159.479, 3209.122, 50.16586, NULL, 0, 1),
(@PATH, 1, 1146.019, 3207.825, 46.61276, NULL, 0, 1),
(@PATH, 2, 1137.608, 3206.883, 43.31707, NULL, 324, 1);

SET @ENTRY := 98228;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 0, 1119.24, 3203.42, 38.1061, NULL, 404, 1),
(@PATH, 1, 1106.443, 3197.732, 34.12574, NULL, 0, 1),
(@PATH, 2, 1098.535, 3194.377, 31.75129, NULL, 0, 1),
(@PATH, 3, 1087.286, 3189.897, 27.46083, NULL, 0, 1),
(@PATH, 4, 1081.759, 3187.692, 26.16743, NULL, 0, 1),
(@PATH, 5, 1068.651, 3181.97, 22.13405, NULL, 0, 1),
(@PATH, 6, 1060.307, 3176.874, 19.37006, NULL, 0, 1);

-- Kayn Sunfury
SET @ENTRY := 93011;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 0, 1095.367, 3186.3792, 29.398575, NULL, 0, 1),
(@PATH, 1, 1096.117, 3186.6292, 29.898575, NULL, 0, 1),
(@PATH, 2, 1096.995, 3186.7002, 29.981531, NULL, 0, 1);

SET @ENTRY := 93011;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 0, 1069.715, 3177.44, 21.46352, NULL, 3000, 1),
(@PATH, 1, 1063.477, 3172.725, 18.63585, NULL, 0, 1);

-- Allari the Souleater
SET @ENTRY := 98227;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 0, 1150.981, 3205.185, 47.57572, NULL, 0, 1),
(@PATH, 1, 1142.78, 3203.735, 44.76439, NULL, 366, 1);

SET @ENTRY := 98227;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 0, 1120.08, 3197.2, 36.8502, NULL, 320, 1),
(@PATH, 1, 1098.106, 3190.198, 30.81477, NULL, 0, 1),
(@PATH, 2, 1087.92, 3186.326, 27.1753, NULL, 0, 1),
(@PATH, 3, 1083.852, 3184.756, 26.13717, NULL, 0, 1),
(@PATH, 4, 1076.007, 3181.132, 23.98388, NULL, 0, 1),
(@PATH, 5, 1065.649, 3175.742, 19.78723, NULL, 0, 1),
(@PATH, 6, 1055.398, 3167.896, 17.91369, NULL, 0, 1),
(@PATH, 7, 1054.142, 3166.28, 17.57548, NULL, 0, 1);

-- Kor'vas Bloodthorn
SET @ENTRY := 98292;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 0, 1155.078, 3204.171, 48.49304, NULL, 0, 1),
(@PATH, 1, 1138.806, 3200.725, 42.95776, NULL, 213, 1);

SET @ENTRY := 98292;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 0, 1117.89, 3196.24, 36.2158, NULL, 237, 1),
(@PATH, 1, 1100.179, 3189.184, 31.32025, NULL, 0, 1),
(@PATH, 2, 1092.804, 3186.828, 28.65943, NULL, 0, 1),
(@PATH, 3, 1079.504, 3181.279, 24.81245, NULL, 0, 1),
(@PATH, 4, 1065.17, 3172.552, 18.92646, NULL, 0, 1),
(@PATH, 5, 1058.738, 3166.632, 17.96959, NULL, 0, 1);

-- Sevis Brightflame
SET @ENTRY := 99918;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 0, 1150.524, 3206.556, 47.50604, NULL, 0, 1),
(@PATH, 1, 1140.031, 3203.963, 43.88533, NULL, 93, 1);

SET @ENTRY := 99918;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 0, 1120.74, 3199.47, 37.5157, NULL, 278, 1),
(@PATH, 1, 1101.424, 3194.313, 32.54323, NULL, 0, 1),
(@PATH, 2, 1088.533, 3188.805, 27.74644, NULL, 0, 1),
(@PATH, 3, 1075.568, 3183.056, 24.12158, NULL, 0, 1),
(@PATH, 4, 1065.212, 3177.734, 19.99919, NULL, 0, 1),
(@PATH, 5, 1059.837, 3173.674, 19.00958, NULL, 0, 1);

-- Cyana Nightglaive
SET @ENTRY := 98290;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 0, 1154.392, 3203.176, 48.01282, NULL, 0, 1),
(@PATH, 1, 1144.257, 3200.841, 44.53834, NULL, 159, 1);

SET @ENTRY := 98290;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 0, 1120.34, 3194.28, 36.4321, NULL, 242, 1),
(@PATH, 1, 1104.913, 3188.93, 32.40257, NULL, 0, 1),
(@PATH, 2, 1096.353, 3186.152, 29.55845, NULL, 0, 1),
(@PATH, 3, 1090.165, 3183.755, 27.35834, NULL, 0, 1),
(@PATH, 4, 1081.186, 3180.038, 25.01144, NULL, 0, 1),
(@PATH, 5, 1064.868, 3170.523, 18.56903, NULL, 0, 1),
(@PATH, 6, 1059.193, 3164.68, 17.53739, NULL, 0, 1);

-- Wrath Warrior
SET @ENTRY := 94580;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 1088.1326, 3184.2913, 27.202965, NULL, 0),
(@PATH, 1, 1098.8898, 3187.22, 30.489897, NULL, 0);
