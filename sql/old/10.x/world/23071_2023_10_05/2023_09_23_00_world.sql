SET @CGUID := 5000132;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+9;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 78430, 1265, 7025, 7041, '0', 3265, 0, 0, 1, 3837.99560546875, -2776.723876953125, 93.9245758056640625, 5.573551177978515625, 120, 0, 0, 400000, 100, 0, NULL, NULL, NULL, NULL, 51130), -- Cordana Felsong (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+1, 78553, 1265, 7025, 7041, '0', 3265, 0, 0, 1, 3844.734375, -2786.68408203125, 94.16998291015625, 5.674098968505859375, 120, 0, 0, 4800000, 320750, 0, NULL, NULL, NULL, NULL, 51130), -- Thrall (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+2, 78556, 1265, 7025, 7041, '0', 3655, 0, 0, 1, 3842.366455078125, -2787.322998046875, 94.377410888671875, 5.560853958129882812, 120, 0, 0, 20000, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Ariok (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+3, 78568, 1265, 7025, 7041, '0', 3265, 0, 0, 1, 3837.892333984375, -2768.734375, 93.89243316650390625, 0.200779974460601806, 120, 0, 0, 20000, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Thaelin Darkanvil (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+4, 79315, 1265, 7025, 7041, '0', 3265, 0, 0, 1, 3840.3359375, -2767.654541015625, 93.88391876220703125, 3.119690895080566406, 120, 0, 0, 20000, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Olin Umberhide (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+5, 79675, 1265, 7025, 7041, '0', 3265, 0, 0, 1, 3844.427978515625, -2769.032958984375, 93.99267578125, 4.584816455841064453, 120, 0, 0, 400000, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Lady Liadrin (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+6, 78569, 1265, 7025, 7041, '0', 3265, 0, 0, 1, 3838.14501953125, -2767.05908203125, 93.86634063720703125, 5.749032974243164062, 120, 0, 0, 20000, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Hansel Heavyhands (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+7, 79316, 1265, 7025, 7041, '0', 3265, 0, 0, 1, 3832.265625, -2775.342041015625, 94.3538818359375, 6.141648769378662109, 120, 0, 0, 20000, 1283, 0, NULL, NULL, NULL, NULL, 51130), -- Qiana Moonshadow (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+8, 78559, 1265, 7025, 7041, '0', 3265, 0, 0, 1, 3839.858642578125, -2777.1181640625, 93.9246368408203125, 5.596025943756103515, 120, 0, 0, 640000, 9573, 0, NULL, NULL, NULL, NULL, 51130), -- Archmage Khadgar (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+9, 78554, 1265, 7025, 7041, '0', 3265, 0, 0, 1, 3834.88720703125, -2775.640625, 94.0558013916015625, 3.19539046287536621, 120, 0, 0, 4800000, 128300, 0, NULL, NULL, NULL, NULL, 51130); -- Vindicator Maraad (Area: Heartblood - Difficulty: 0) CreateObject1 (Auras: 165746 - Retribution Aura)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+9;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '165746'); -- Vindicator Maraad - 165746 - Retribution Aura

-- Phases
DELETE FROM `phase_name` WHERE `ID` = 3655;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(3655, 'Cosmetic - Ariok at Bleeding Hollow Altar (E)');

DELETE FROM `phase_area` WHERE `AreaId` IN (7025, 7041, 7039, 7129) AND `PhaseId` IN (3265, 3655);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7025, 3265, 'See Questgivers at Bleeding Hollow Altar'),
(7041, 3655, 'See Ariok at Bleeding Hollow Altar'),
(7039, 3655, 'See Ariok at Bleeding Hollow Altar'),
(7129, 3655, 'See Ariok at Bleeding Hollow Altar');

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=3265 AND `ConditionValue1`=35297;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 3265, 0, 0, 0, 47, 0, 35297, 2 | 64, 0, 0, 0, 0, '', 'Apply Phase 3264 if Quest 35297 is complete | rewarded');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=3655 AND `ConditionValue1`=35297;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 3655, 0, 0, 0, 47, 0, 35297, 2 | 64, 0, 0, 0, 0, '', 'Apply Phase 3264 if Quest 35297 is complete | rewarded');

-- Previous conditions already added
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=3264 AND `ConditionValue1`=34422;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 3264, 0, 0, 0, 47, 0, 34422, 2 | 8 | 64, 0, 1, 0, 0, '', 'Apply Phase 3264 if Quest 34422 is not in progress | complete | rewarded');

-- Quest
UPDATE `quest_poi` SET `VerifiedBuild`=51130 WHERE (`QuestID`=34422 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=34422 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=34422 AND `BlobIndex`=0 AND `Idx1`=0);
UPDATE `quest_poi_points` SET `VerifiedBuild`=51130 WHERE (`QuestID`=34422 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=34422 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=34422 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=34422 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=34422 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=34422 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=34422 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=34422 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=34422 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=34422 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=34422 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=34422 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=34422 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=34422 AND `Idx1`=0 AND `Idx2`=0);
UPDATE `creature_queststarter` SET `VerifiedBuild`=51130 WHERE (`id`=78559 AND `quest`=34422);
UPDATE `quest_details` SET `VerifiedBuild`=51130 WHERE `ID` = 34422;

DELETE FROM `quest_template_addon` WHERE `ID`=34422;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(34422, 0, 0, 0, 34420, 34423, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'quest_blaze_of_glory');

-- Scene
UPDATE `scene_template` SET `ScriptName` = 'scene_bleeding_hollow_holdout' WHERE `SceneId`=770;
UPDATE `scene_template` SET `ScriptName` = 'scene_bleeding_hollow_trail_of_flame' WHERE `SceneId`=771;

-- Serverside spell
DELETE FROM `serverside_spell` WHERE `Id`=164613 AND `DifficultyID`=0;
INSERT INTO `serverside_spell` (`Id`, `DifficultyID`, `CategoryId`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `AttributesEx11`, `AttributesEx12`, `AttributesEx13`, `AttributesEx14`, `Stances`, `StancesNot`, `Targets`, `TargetCreatureType`, `RequiresSpellFocus`, `FacingCasterFlags`, `CasterAuraState`, `TargetAuraState`, `ExcludeCasterAuraState`, `ExcludeTargetAuraState`, `CasterAuraSpell`, `TargetAuraSpell`, `ExcludeCasterAuraSpell`, `ExcludeTargetAuraSpell`, `CasterAuraType`, `TargetAuraType`, `ExcludeCasterAuraType`, `ExcludeTargetAuraType`, `CastingTimeIndex`, `RecoveryTime`, `CategoryRecoveryTime`, `StartRecoveryCategory`, `StartRecoveryTime`, `InterruptFlags`, `AuraInterruptFlags1`, `AuraInterruptFlags2`, `ChannelInterruptFlags1`, `ChannelInterruptFlags2`, `ProcFlags`, `ProcFlags2`, `ProcChance`, `ProcCharges`, `ProcCooldown`, `ProcBasePPM`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `Speed`, `LaunchDelay`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `ContentTuningId`, `SpellName`, `ConeAngle`, `ConeWidth`, `MaxTargetLevel`, `MaxAffectedTargets`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `SpellFamilyFlags4`, `DmgClass`, `PreventionType`, `AreaGroupId`, `SchoolMask`, `ChargeCategoryId`) VALUES
(164613, 0, 0, 0, 0, 128, 0, 268435456, 0, 128, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, -1, 0, 0, 0, 'Hut Credit', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);

DELETE FROM `serverside_spell_effect` WHERE `SpellID`=164613 AND `EffectIndex`=0 AND `DifficultyID`=0;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(164613, 0, 0, 90, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 81760, 0, 0, 0, 0, 0, 0, 0, 1, 0);

DELETE FROM `spell_area` WHERE `spell` IN(164609, 164611);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES 
(164609, 7025, 34422, 35297, 0, 0, 2, 3, 10, 1),
(164611, 7025, 34422, 35297, 0, 0, 2, 3, 8, 1);
