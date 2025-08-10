SET @CGUID := 7000424;
SET @OGUID := 7000026;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 93759, 1481, 7705, 7740, '0', 5095, 0, 0, 1, 1059.6754150390625, 2576.71533203125, -37.1619338989257812, 0.488393902778625488, 120, 0, 0, 34166, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Jace Darkweaver (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 188485 - Fel Channelling)
(@CGUID+1, 95049, 1481, 7705, 7740, '0', 0, 0, 0, 0, 1062.0555419921875, 2572.762939453125, -33.839324951171875, 4.638368129730224609, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Demon Ward (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 195821 - Seat of Command: Jace's Demon Ward Area Trigger)
(@CGUID+2, 95049, 1481, 7705, 7740, '0', 0, 0, 0, 0, 1056.595458984375, 2581.59033203125, -34.9345664978027343, 2.579434394836425781, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Demon Ward (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 195821 - Seat of Command: Jace's Demon Ward Area Trigger)
(@CGUID+3, 95049, 1481, 7705, 7740, '0', 0, 0, 0, 0, 1067.217041015625, 2581.671875, -33.8557815551757812, 0.874998629093170166, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51536); -- Demon Ward (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 195821 - Seat of Command: Jace's Demon Ward Area Trigger)
 
-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+3;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 243059, 1481, 7705, 7740, '0', 0, 0, 1057.0103759765625, 2581.33251953125, -37.8438606262207031, 2.61522531509399414, 0, 0, 0.965566635131835937, 0.260155856609344482, 120, 255, 0, 51536), -- Demon Ward (Area: Molten Shore - Difficulty: 0) CreateObject1
(@OGUID+1, 243335, 1481, 7705, 7740, '0', 0, 0, 1062.3853759765625, 2578.52783203125, -37.0822486877441406, 5.324192047119140625, -0.01086902618408203, -0.06977558135986328, -0.45883846282958984, 0.885709047317504882, 120, 255, 1, 51536), -- Nether Crucible (Area: Molten Shore - Difficulty: 0) CreateObject1
(@OGUID+2, 243059, 1481, 7705, 7740, '0', 0, 0, 1062.078125, 2573.25341796875, -36.7530097961425781, 4.702091217041015625, 0, 0, -0.71073818206787109, 0.703456640243530273, 120, 255, 0, 51536), -- Demon Ward (Area: Molten Shore - Difficulty: 0) CreateObject1
(@OGUID+3, 243059, 1481, 7705, 7740, '0', 0, 0, 1066.875, 2581.322021484375, -36.7869338989257812, 0.751146793365478515, 0, 0, 0.3668060302734375, 0.930297434329986572, 120, 255, 0, 51536); -- Demon Ward (Area: Molten Shore - Difficulty: 0) CreateObject1

-- Update Templates
UPDATE `creature_template` SET `Flags_extra` = 128 WHERE `entry` = 95049; -- Demon Ward

UPDATE `gameobject_template` SET `ContentTuningId`=699, `VerifiedBuild`=51536 WHERE `entry`=243335; -- Nether Crucible
UPDATE `gameobject_template` SET `ContentTuningId`=699, `VerifiedBuild`=51536 WHERE `entry`=243059; -- Demon Ward

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (95049, 93759);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(95049, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '195821'), -- 95049 (Demon Ward) - Seat of Command: Jace's Demon Ward Area Trigger
(93759, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, ''); -- 93759 (Jace Darkweaver) - Fel Channelling

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (243335 /*Nether Crucible*/, 243059 /*Demon Ward*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(243335, 0, 262144, 0, 0), -- Nether Crucible
(243059, 114, 0, 0, 0); -- Demon Ward

-- Creature Movement
DELETE FROM `creature_template_movement` WHERE `CreatureId` = 95049;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(95049, 0, 0, 1, 1, 0, 0, NULL);

-- Creature difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=0 AND `Entry` IN (96884,99003));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `VerifiedBuild`) VALUES
(96884, 0, 0, 0, 699, 6, 1, 1, 97383, 4096, 0, 51536), -- Coilskar Sea-Caller
(99003, 0, 0, 0, 699, 6, 2, 1, 99509, 1024, 16, 51536); -- Fel Cannon

-- Phasing
DELETE FROM `phase_area` WHERE `PhaseId` = 5095 AND `AreaId` = 7705;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7705, 5095, 'Jace Darkweaver at Molten Shore');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 5095 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 5095, 0, 0, 0, 47, 0, 40077, 64, 0, 0, 'Apply Phase 5095 if Quest 40077 is rewarded');

-- Serverside Spell
DELETE FROM `serverside_spell` WHERE `Id` = 198253;
INSERT INTO `serverside_spell` (`Id`, `DifficultyID`, `CategoryId`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `AttributesEx11`, `AttributesEx12`, `AttributesEx13`, `AttributesEx14`, `Stances`, `StancesNot`, `Targets`, `TargetCreatureType`, `RequiresSpellFocus`, `FacingCasterFlags`, `CasterAuraState`, `TargetAuraState`, `ExcludeCasterAuraState`, `ExcludeTargetAuraState`, `CasterAuraSpell`, `TargetAuraSpell`, `ExcludeCasterAuraSpell`, `ExcludeTargetAuraSpell`, `CasterAuraType`, `TargetAuraType`, `ExcludeCasterAuraType`, `ExcludeTargetAuraType`, `CastingTimeIndex`, `RecoveryTime`, `CategoryRecoveryTime`, `StartRecoveryCategory`, `StartRecoveryTime`, `InterruptFlags`, `AuraInterruptFlags1`, `AuraInterruptFlags2`, `ChannelInterruptFlags1`, `ChannelInterruptFlags2`, `ProcFlags`, `ProcFlags2`, `ProcChance`, `ProcCharges`, `ProcCooldown`, `ProcBasePPM`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `Speed`, `LaunchDelay`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `ContentTuningId`, `SpellName`, `ConeAngle`, `ConeWidth`, `MaxTargetLevel`, `MaxAffectedTargets`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `SpellFamilyFlags4`, `DmgClass`, `PreventionType`, `AreaGroupId`, `SchoolMask`, `ChargeCategoryId`) VALUES
(198253, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000080, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, 0, 'Meeting With the Queen: Ritual Completed Kill Credit', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `serverside_spell_effect` WHERE `SpellID` = 198253 AND `EffectIndex` = 0;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(198253, 0, 0, 140, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 188539, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);

-- Scene
DELETE FROM `scene_template` WHERE `SceneId`=1061;
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`, `Encrypted`) VALUES
(1061, 26, 1460, 0);

 -- Scene 1061
SET @ENTRY := 1061;
UPDATE `scene_template` SET `ScriptName` = 'SmartScene' WHERE `SceneId` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 10 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 10, 0, 0, 78, 0, 100, 0, 0, 0, 0, 0, 33, 100722, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On Scene Start - Last Action Invoker: Give kill credit "Meeting With the Queen" Ritual Completed Quest Kill Credit (100722)');

-- Update Gossip
UPDATE `gossip_menu_option` SET `GossipOptionID`=45047, `VerifiedBuild`=51536 WHERE (`MenuID`=19015 AND `OptionID`=0);
UPDATE `gossip_menu_option` SET `GossipOptionID`=44470, `ActionMenuID`=19131, `VerifiedBuild`=51536 WHERE (`MenuID`=18438 AND `OptionID`=1);
UPDATE `gossip_menu_option` SET `GossipOptionID`=44469, `ActionMenuID`=19109, `VerifiedBuild`=51536 WHERE (`MenuID`=18438 AND `OptionID`=0);

-- Quest stuff
DELETE FROM `quest_offer_reward` WHERE `ID` IN (40379 /*Enter the Illidari: Coilskar*/, 39049 /*Eye On the Prize*/, 38759 /*Set Them Free*/, 39050);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(40379, 0, 0, 0, 0, 0, 0, 0, 0, 'Grim business, but we\'ve all sacrificed just about everything to get to where we are.\n\nWe will do ANYTHING it takes to defeat the Burning Legion. Anything.', 51536), -- Enter the Illidari: Coilskar
(39049, 273, 0, 0, 0, 0, 0, 0, 0, 'An inquisitor\'s essence... perfect. Allari was right.\n\nNow to complete my ritual and spy on the Legion\'s leadership.', 51536), -- Eye On the Prize
(38759, 0, 0, 0, 0, 0, 0, 0, 0, 'Their souls were being sucked dry by a jailer demon?\n\nThe Burning Legion in this place is far more powerful and brutal than we have ever seen before.', 51536), -- Set Them Free
(39050, 1, 0, 0, 0, 0, 0, 0, 0, 'That\'s new. She looks like some kind of spider demon. As if the Legion needed spiders...', 51536); -- Meeting With the Queen

DELETE FROM `quest_details` WHERE `ID`=39050;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(39050, 1, 0, 0, 0, 0, 0, 0, 0, 51536); -- Meeting With the Queen

DELETE FROM `quest_request_items` WHERE `ID` IN (39050 /*Meeting With the Queen*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(39050, 0, 6, 0, 0, 'If we don\'t know what they\'re planning, we\'re at a disadvantage fighting them.', 51536); -- Meeting With the Queen

DELETE FROM `creature_queststarter` WHERE (`id`=93759 AND `quest`=39050);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(93759, 39050, 51536); -- Meeting With the Queen offered Jace Darkweaver

UPDATE `quest_template_addon` SET `ExclusiveGroup` = -40379, `NextQuestID` = 39050 WHERE `ID` IN (40379, 39049, 38759);
