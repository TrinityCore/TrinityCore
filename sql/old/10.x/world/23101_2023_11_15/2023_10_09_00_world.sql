SET @CGUID := 6000141;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+16;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 98905, 1481, 7705, 7740, '0', 0, 0, 0, 0, 604.29925537109375, 2449.44970703125, -79.2607879638671875, 1.133339166641235351, 120, 10, 0, 3106, 1534, 1, NULL, NULL, NULL, NULL, 51485), -- Demonic Hallucination (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 194533 - Incite Madness) (possible waypoints or random movement)
(@CGUID+1, 98907, 1481, 7705, 7740, '0', 0, 0, 0, 0, 609.670166015625, 2380.0556640625, -72.2897720336914062, 1.427738189697265625, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 51485), -- Demonic Hallucination (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 194533 - Incite Madness)
(@CGUID+2, 98907, 1481, 7705, 7740, '0', 0, 0, 0, 0, 659.3350830078125, 2380.33154296875, -67.7358551025390625, 1.7917710542678833, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 51485), -- Demonic Hallucination (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 194533 - Incite Madness)
(@CGUID+3, 98905, 1481, 7705, 7740, '0', 0, 0, 0, 0, 606.13311767578125, 2350.93994140625, -87.5009918212890625, 3.073929309844970703, 120, 10, 0, 3106, 1534, 1, NULL, NULL, NULL, NULL, 51485), -- Demonic Hallucination (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 194533 - Incite Madness) (possible waypoints or random movement)
(@CGUID+4, 98905, 1481, 7705, 7740, '0', 0, 0, 0, 0, 610.65435791015625, 2489.897705078125, -74.1997528076171875, 0.080923974514007568, 120, 10, 0, 3106, 1534, 1, NULL, NULL, NULL, NULL, 51485), -- Demonic Hallucination (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 194533 - Incite Madness) (possible waypoints or random movement)
(@CGUID+5, 98905, 1481, 7705, 7740, '0', 0, 0, 0, 0, 623.19720458984375, 2565.274169921875, -74.0265655517578125, 6.013451576232910156, 120, 10, 0, 3106, 1534, 1, NULL, NULL, NULL, NULL, 51485), -- Demonic Hallucination (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 194533 - Incite Madness) (possible waypoints or random movement)
(@CGUID+6, 98907, 1481, 7705, 7740, '0', 0, 0, 0, 0, 656.29864501953125, 2510.217041015625, -77.2955474853515625, 4.467630386352539062, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 51485), -- Demonic Hallucination (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 194533 - Incite Madness)
(@CGUID+7, 98905, 1481, 7705, 7740, '0', 0, 0, 0, 0, 698.900146484375, 2389.650634765625, -78.6407241821289062, 4.383945941925048828, 120, 10, 0, 3106, 1534, 1, NULL, NULL, NULL, NULL, 51485), -- Demonic Hallucination (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 194533 - Incite Madness) (possible waypoints or random movement)
(@CGUID+8, 98905, 1481, 7705, 7740, '0', 0, 0, 0, 0, 484.72607421875, 2492.8876953125, -19.5441608428955078, 4.644806385040283203, 120, 10, 0, 3106, 1534, 1, NULL, NULL, NULL, NULL, 51485), -- Demonic Hallucination (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 194533 - Incite Madness) (possible waypoints or random movement)
(@CGUID+9, 98905, 1481, 7705, 7740, '0', 0, 0, 0, 0, 644.828857421875, 2472.0341796875, -66.2326202392578125, 2.490900754928588867, 120, 10, 0, 3106, 1534, 1, NULL, NULL, NULL, NULL, 51485), -- Demonic Hallucination (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 194533 - Incite Madness) (possible waypoints or random movement)
(@CGUID+10, 98907, 1481, 7705, 7740, '0', 0, 0, 0, 0, 572.47393798828125, 2396.951416015625, -65.2873001098632812, 0.959659993648529052, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 51485), -- Demonic Hallucination (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 194533 - Incite Madness)
(@CGUID+11, 98907, 1481, 7705, 7740, '0', 0, 0, 0, 0, 691.26214599609375, 2426.859375, -68.4354934692382812, 3.220989942550659179, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 51485), -- Demonic Hallucination (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 194533 - Incite Madness)
(@CGUID+12, 98907, 1481, 7705, 7740, '0', 0, 0, 0, 0, 586.17364501953125, 2465.151123046875, -68.3279342651367187, 5.665149688720703125, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 51485), -- Demonic Hallucination (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 194533 - Incite Madness)
(@CGUID+13, 98905, 1481, 7705, 7740, '0', 0, 0, 0, 0, 478.1673583984375, 2438.877685546875, -35.3670387268066406, 1.517186284065246582, 120, 10, 0, 3106, 1534, 1, NULL, NULL, NULL, NULL, 51485), -- Demonic Hallucination (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 194533 - Incite Madness) (possible waypoints or random movement)
(@CGUID+14, 98905, 1481, 7705, 7740, '0', 0, 0, 0, 0, 626.34588623046875, 2454.52685546875, -85.756866455078125, 2.11855316162109375, 120, 10, 0, 3106, 1534, 1, NULL, NULL, NULL, NULL, 51485), -- Demonic Hallucination (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 194533 - Incite Madness) (possible waypoints or random movement)
(@CGUID+15, 98905, 1481, 7705, 7740, '0', 0, 0, 0, 0, 591.45843505859375, 2462.621337890625, -60.8692398071289062, 4.248614788055419921, 120, 10, 0, 3106, 1534, 1, NULL, NULL, NULL, NULL, 51485), -- Demonic Hallucination (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 194533 - Incite Madness) (possible waypoints or random movement)
(@CGUID+16, 98905, 1481, 7705, 7740, '0', 0, 0, 0, 0, 497.449798583984375, 2385.361083984375, -33.8969497680664062, 1.602385282516479492, 120, 10, 0, 3106, 1534, 1, NULL, NULL, NULL, NULL, 51485); -- Demonic Hallucination (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 194533 - Incite Madness) (possible waypoints or random movement)

-- Creature Template
UPDATE `creature_template` SET `faction`=954, `BaseAttackTime`=2000, `unit_flags`=33587712, `unit_flags3`=17301504, `flags_extra` = 128, `ScriptName` = 'npc_baleful_beaming_eye' WHERE `entry`=99160; -- Beaming Eye
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=33556480 WHERE `entry`=96877; -- Ashtongue Stalker
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=1073743872, `unit_flags3`=524288 WHERE `entry`=94990; -- Infernal Ball Bunny

UPDATE `creature_template` SET `ScriptName` = 'npc_inquisitor_baleful_molten_shore' WHERE `entry` = 93105;

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (99160, 96159, 98907, 98905);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(99160, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 99160 (Beaming Eye)
(96159, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 5, ''), -- 96159 (Colossal Infernal)
(98907, 0, 0, 0, 3, 1, 1, 0, 0, 0, 0, 0, 4, '194533'), -- 98907 (Demonic Hallucination) - Incite Madness
(98905, 0, 0, 0, 3, 1, 1, 0, 0, 0, 0, 0, 4, '194533'); -- 98905 (Demonic Hallucination) - Incite Madness

-- Creature Movement
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (93105, 99160, 98907, 98905);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(93105, 0, 0, 1, 0, 0, 0, NULL),
(99160, 0, 0, 1, 1, 0, 0, NULL),
(98907, 0, 0, 1, 0, 0, 0, NULL),
(98905, 0, 0, 1, 0, 0, 0, NULL);

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` = 93105;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(93105, 0, 0, 'I can see your secrets...', 12, 0, 100, 0, 0, 55222, 94930, 0, 'Inquisitor Baleful to Player'),
(93105, 1, 0, 'Enough! My colossal infernal will crush you.', 14, 0, 100, 0, 0, 55224, 99554, 0, 'Inquisitor Baleful'),
(93105, 2, 0, 'My eyes... My eyes!', 14, 0, 100, 0, 0, 55223, 96010, 0, 'Inquisitor Baleful to Ashtongue Stalker');

-- Creature difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=0 AND `Entry` IN (99160,96877,94990));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `VerifiedBuild`) VALUES
(99160, 0, 0, 0, 699, 6, 1, 1, 99666, 0, 0, 51485), -- Beaming Eye
(96877, 0, 0, 0, 699, 6, 1, 1, 97376, 4096, 0, 51485), -- Ashtongue Stalker
(94990, 0, 0, 0, 699, 6, 1, 1, 95229, 1056, 0, 51485); -- Infernal Ball Bunny

-- AreaTrigger
DELETE FROM `areatrigger_create_properties` WHERE `Id` IN (2104, 5151);
INSERT INTO `areatrigger_create_properties` (`Id`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `VerifiedBuild`) VALUES
(2104, 6669, 0, 0, 0, 0, -1, 0, 0, 0, 15000, 0, 5, 5, 0, 0, 0, 0, 0, 0, 51485), -- Spell: 192665 (Legion Aegis)
(5151, 9877, 0, 0, 0, 0, -1, 0, 0, 0, 20000, 1, 6, 1, 0.75, 6, 1, 0.75, 0, 0, 51485); -- Spell: 195051 (Beaming Gaze)

-- AreaTrigger Actions
DELETE FROM `areatrigger_template_actions` WHERE `AreaTriggerId` = 9877 AND `IsServerSide` = 0;
INSERT INTO `areatrigger_template_actions` (`AreaTriggerId`, `IsServerSide`, `ActionType`, `ActionParam`, `TargetType`) VALUES
(9877, 0, 1, 195054, 2);

-- ScriptName
DELETE FROM `spell_script_names` WHERE `spell_id` IN (192665, 192709, 195058);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(192665, 'spell_mardum_baleful_legion_aegis'),
(192709, 'spell_mardum_coloss_infernal_smash_selector'),
(195058, 'spell_mardum_baleful_beaming_gaze_selector');

-- Serverside Spell
DELETE FROM `serverside_spell` WHERE `Id` = 188559;
INSERT INTO `serverside_spell` (`Id`, `DifficultyID`, `CategoryId`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `AttributesEx11`, `AttributesEx12`, `AttributesEx13`, `AttributesEx14`, `Stances`, `StancesNot`, `Targets`, `TargetCreatureType`, `RequiresSpellFocus`, `FacingCasterFlags`, `CasterAuraState`, `TargetAuraState`, `ExcludeCasterAuraState`, `ExcludeTargetAuraState`, `CasterAuraSpell`, `TargetAuraSpell`, `ExcludeCasterAuraSpell`, `ExcludeTargetAuraSpell`, `CasterAuraType`, `TargetAuraType`, `ExcludeCasterAuraType`, `ExcludeTargetAuraType`, `CastingTimeIndex`, `RecoveryTime`, `CategoryRecoveryTime`, `StartRecoveryCategory`, `StartRecoveryTime`, `InterruptFlags`, `AuraInterruptFlags1`, `AuraInterruptFlags2`, `ChannelInterruptFlags1`, `ChannelInterruptFlags2`, `ProcFlags`, `ProcFlags2`, `ProcChance`, `ProcCharges`, `ProcCooldown`, `ProcBasePPM`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `Speed`, `LaunchDelay`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `ContentTuningId`, `SpellName`, `ConeAngle`, `ConeWidth`, `MaxTargetLevel`, `MaxAffectedTargets`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `SpellFamilyFlags4`, `DmgClass`, `PreventionType`, `AreaGroupId`, `SchoolMask`, `ChargeCategoryId`) VALUES
(188559, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000080, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, 0, 'Eye On the Prize: Kill Credit', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `serverside_spell_effect` WHERE `SpellID` = 188559 AND `EffectIndex` = 0;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(188559, 0, 0, 90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 105946, 0, 0, 0, 0, 0, 0, 0, 1, 0);

-- Phasing
DELETE FROM `phase_area` WHERE `PhaseId` = 5056 AND `AreaId` = 7705;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7705, 5056, 'Colossal Infernal from Inquisitor Baleful Molten Shore');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 5056 AND `SourceEntry` = 0); -- Colossal Infernal
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 5056, 0, 0, 0, 47, 0, 39049, 8|2|64, 0, 0, 'Apply Phase 5056 if Quest 39049 is in progress | complete | rewarded');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=13 AND `SourceGroup` = 1 AND `SourceEntry` = 204265);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 204265, 0, 0, 31, 0, 3, 93105, 0, 0, 0, 0, '', 'Spell: Eye on the Prize: Taking Power 02 - can only hit "Inquisitor Baleful"');

-- Quest stuff
DELETE FROM `quest_poi` WHERE (`QuestID`=39049 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=39049 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=39049 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(39049, 0, 2, 32, 0, 0, 1481, 672, 0, 0, 0, 0, 0, 1027851, 0, 51485), -- Eye On the Prize
(39049, 0, 1, 0, 279707, 105946, 1481, 672, 0, 0, 0, 0, 0, 1027197, 0, 51485), -- Eye On the Prize
(39049, 0, 0, -1, 0, 0, 1481, 672, 0, 0, 0, 0, 0, 1027529, 0, 51485); -- Eye On the Prize

UPDATE `quest_poi` SET `VerifiedBuild`=51485 WHERE (`QuestID`=38759 AND `BlobIndex`=0 AND `Idx1`=6) OR (`QuestID`=38759 AND `BlobIndex`=0 AND `Idx1`=5) OR (`QuestID`=38759 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=38759 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=38759 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=38759 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=38759 AND `BlobIndex`=0 AND `Idx1`=0);
DELETE FROM `quest_poi_points` WHERE (`QuestID`=39049 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=39049 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=39049 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(39049, 2, 0, 825, 2758, -30, 51485), -- Eye On the Prize
(39049, 1, 0, 593, 2433, 0, 51485), -- Eye On the Prize
(39049, 0, 0, 1060, 2577, -37, 51485); -- Eye On the Prize

DELETE FROM `quest_details` WHERE `ID`=39049;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(39049, 0, 0, 0, 0, 0, 0, 0, 0, 51485); -- Eye On the Prize

DELETE FROM `creature_queststarter` WHERE (`id`=94410 AND `quest`=39049);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(94410, 39049, 51485); -- Eye On the Prize offered Allari the Souleater

DELETE FROM `quest_template_addon` WHERE `ID` = 39049;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(39049, 0, 0, 0, 40378, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
