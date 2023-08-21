SET @CGUID := 6000054;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+5;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `VerifiedBuild`) VALUES
(@CGUID+0, 98227, 1481, 7705, 7705, '0', 4899, 0, 0, 1, 1177, 3203.068603515625, 51.36370086669921875, 4.887462139129638671, 120, 0, 0, 31060, 0, 0, 0, 0, 50622), -- Allari the Souleater (Area: Mardum, the Shattered Abyss - Difficulty: 0) CreateObject1
(@CGUID+1, 98228, 1481, 7705, 7705, '0', 4899, 0, 0, 1, 1182.35595703125, 3202.912353515625, 51.5215301513671875, 4.885663032531738281, 120, 0, 0, 34166, 0, 0, 0, 0, 50622), -- Jace Darkweaver (Area: Mardum, the Shattered Abyss - Difficulty: 0) CreateObject1
(@CGUID+2, 98290, 1481, 7705, 7705, '0', 4899, 0, 0, 1, 1171.4896240234375, 3203.684814453125, 51.31452178955078125, 3.456398963928222656, 120, 0, 0, 31060, 0, 0, 0, 0, 50622), -- Cyana Nightglaive (Area: Mardum, the Shattered Abyss - Difficulty: 0) CreateObject1
(@CGUID+3, 93011, 1481, 7705, 7705, '0', 4899, 0, 0, 1, 1179.5660400390625, 3202.606689453125, 51.34317398071289062, 4.873765945434570312, 120, 0, 0, 31060, 0, 0, 0, 0, 50622), -- Kayn Sunfury (Area: Mardum, the Shattered Abyss - Difficulty: 0) CreateObject1
(@CGUID+4, 99918, 1481, 7705, 7705, '0', 4899, 0, 0, 1, 1172.9149169921875, 3207.81689453125, 52.39348983764648437, 3.731853008270263671, 120, 0, 0, 27954, 0, 0, 0, 0, 50622), -- Sevis Brightflame (Area: Mardum, the Shattered Abyss - Difficulty: 0) CreateObject1
(@CGUID+5, 98292, 1481, 7705, 7705, '0', 4899, 0, 0, 1, 1170.7430419921875, 3204.713623046875, 51.5426483154296875, 3.367438316345214843, 120, 0, 0, 29507, 0, 0, 0, 0, 50622); -- Kor'vas Bloodthorn (Area: Mardum, the Shattered Abyss - Difficulty: 0) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+5;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Allari the Souleater
(@CGUID+1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Jace Darkweaver
(@CGUID+3, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Kayn Sunfury
(@CGUID+4, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Sevis Brightflame
(@CGUID+5, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''); -- Kor'vas Bloodthorn

-- SpellScript names
DELETE FROM `spell_script_names` WHERE `spell_id` = 196030;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES 
(196030,'spell_demon_hunter_intro_aura');

-- Playercreateinfo
DELETE FROM `playercreateinfo_cast_spell` WHERE `raceMask` = (0x8 | 0x200) AND `classMask` = 0x800;
INSERT INTO `playercreateinfo_cast_spell` (`raceMask`, `classMask`, `createMode`, `spell`, `note`) VALUES
((0x8 | 0x200), 0x800, 0, 196030, 'Demonhunter - Start Quest Invis');

-- Scene
DELETE FROM `scene_template` WHERE `SceneId`=1106;
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`, `Encrypted`) VALUES
(1106, 20, 1487, 0);

UPDATE `scene_template` SET `ScriptName` = 'scene_demonhunter_intro' WHERE `SceneId` = 1106;

-- Conversations
DELETE FROM `conversation_actors` WHERE (`ConversationId`=705 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(705, 50124, 0, 98075, 21135, 0, 0, 50622);

DELETE FROM `conversation_line_template` WHERE `Id` IN (1684, 1683);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(1684, 296, 0, 0, 0, 50622),
(1683, 296, 0, 0, 0, 50622);

DELETE FROM `conversation_template` WHERE `Id`=705;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(705, 1683, 0, 50622);

-- Phasing
DELETE FROM `phase_name` WHERE `ID` = 4899;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(4899, 'Cosmetic - See Illidari after intro scene');

DELETE FROM `phase_area` WHERE `AreaId` = 7705 AND `PhaseId` = 4899;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7705, 4899, 'Cosmetic - See Illidari after intro scene');

-- conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` = 4899 AND `SourceEntry` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4899, 0, 0, 0, 47, 0, 40076, 64, 0, 0, 'Apply Phase 4899 if Quest 40076 is rewarded');

-- Hidden Tracker Quest
DELETE FROM `quest_template` WHERE `ID` = 40076;
INSERT INTO `quest_template` (`ID`, `QuestType`, `QuestPackageID`, `ContentTuningID`, `QuestSortID`, `QuestInfoID`, `SuggestedGroupNum`, `RewardNextQuest`, `RewardXPDifficulty`, `RewardXPMultiplier`, `RewardMoneyDifficulty`, `RewardMoneyMultiplier`, `RewardBonusMoney`, `RewardDisplaySpell1`, `RewardDisplaySpell2`, `RewardDisplaySpell3`, `RewardSpell`, `RewardHonor`, `RewardKillHonor`, `StartItem`, `RewardArtifactXPDifficulty`, `RewardArtifactXPMultiplier`, `RewardArtifactCategoryID`, `Flags`, `FlagsEx`, `FlagsEx2`, `RewardItem1`, `RewardAmount1`, `RewardItem2`, `RewardAmount2`, `RewardItem3`, `RewardAmount3`, `RewardItem4`, `RewardAmount4`, `ItemDrop1`, `ItemDropQuantity1`, `ItemDrop2`, `ItemDropQuantity2`, `ItemDrop3`, `ItemDropQuantity3`, `ItemDrop4`, `ItemDropQuantity4`, `RewardChoiceItemID1`, `RewardChoiceItemQuantity1`, `RewardChoiceItemDisplayID1`, `RewardChoiceItemID2`, `RewardChoiceItemQuantity2`, `RewardChoiceItemDisplayID2`, `RewardChoiceItemID3`, `RewardChoiceItemQuantity3`, `RewardChoiceItemDisplayID3`, `RewardChoiceItemID4`, `RewardChoiceItemQuantity4`, `RewardChoiceItemDisplayID4`, `RewardChoiceItemID5`, `RewardChoiceItemQuantity5`, `RewardChoiceItemDisplayID5`, `RewardChoiceItemID6`, `RewardChoiceItemQuantity6`, `RewardChoiceItemDisplayID6`, `POIContinent`, `POIx`, `POIy`, `POIPriority`, `RewardTitle`, `RewardArenaPoints`, `RewardSkillLineID`, `RewardNumSkillUps`, `PortraitGiver`, `PortraitGiverMount`, `PortraitGiverModelSceneID`, `PortraitTurnIn`, `RewardFactionID1`, `RewardFactionValue1`, `RewardFactionOverride1`, `RewardFactionCapIn1`, `RewardFactionID2`, `RewardFactionValue2`, `RewardFactionOverride2`, `RewardFactionCapIn2`, `RewardFactionID3`, `RewardFactionValue3`, `RewardFactionOverride3`, `RewardFactionCapIn3`, `RewardFactionID4`, `RewardFactionValue4`, `RewardFactionOverride4`, `RewardFactionCapIn4`, `RewardFactionID5`, `RewardFactionValue5`, `RewardFactionOverride5`, `RewardFactionCapIn5`, `RewardFactionFlags`, `RewardCurrencyID1`, `RewardCurrencyQty1`, `RewardCurrencyID2`, `RewardCurrencyQty2`, `RewardCurrencyID3`, `RewardCurrencyQty3`, `RewardCurrencyID4`, `RewardCurrencyQty4`, `AcceptedSoundKitID`, `CompleteSoundKitID`, `AreaGroupID`, `TimeAllowed`, `AllowableRaces`, `TreasurePickerID`, `Expansion`, `ManagedWorldStateID`, `QuestSessionBonus`, `LogTitle`, `LogDescription`, `QuestDescription`, `AreaDescription`, `PortraitGiverText`, `PortraitGiverName`, `PortraitTurnInText`, `PortraitTurnInName`, `QuestCompletionLog`, `VerifiedBuild`) VALUES
(40076, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, (0x00000400), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '[Hidden Tracker] Start Demon Hunter Tracking Event', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0);

-- Serverside Spell
DELETE FROM `serverside_spell` WHERE `ID` IN (196030, 228766);
INSERT INTO `serverside_spell` (`Id`, `DifficultyID`, `CategoryId`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `AttributesEx11`, `AttributesEx12`, `AttributesEx13`, `AttributesEx14`, `Stances`, `StancesNot`, `Targets`, `TargetCreatureType`, `RequiresSpellFocus`, `FacingCasterFlags`, `CasterAuraState`, `TargetAuraState`, `ExcludeCasterAuraState`, `ExcludeTargetAuraState`, `CasterAuraSpell`, `TargetAuraSpell`, `ExcludeCasterAuraSpell`, `ExcludeTargetAuraSpell`, `CasterAuraType`, `TargetAuraType`, `ExcludeCasterAuraType`, `ExcludeTargetAuraType`, `CastingTimeIndex`, `RecoveryTime`, `CategoryRecoveryTime`, `StartRecoveryCategory`, `StartRecoveryTime`, `InterruptFlags`, `AuraInterruptFlags1`, `AuraInterruptFlags2`, `ChannelInterruptFlags1`, `ChannelInterruptFlags2`, `ProcFlags`, `ProcFlags2`, `ProcChance`, `ProcCharges`, `ProcCooldown`, `ProcBasePPM`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `Speed`, `LaunchDelay`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `ContentTuningId`, `SpellName`, `ConeAngle`, `ConeWidth`, `MaxTargetLevel`, `MaxAffectedTargets`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `SpellFamilyFlags4`, `DmgClass`, `PreventionType`, `AreaGroupId`, `SchoolMask`, `ChargeCategoryId`) VALUES
(196030, 0, 0, 0, 0, 134217856, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 23, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 21, 1, 0, 0, 0, -1, 0, 0, 0, 'Start: Quest Invis', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(228766, 0, 0, 0, 0, 384, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, 0, 'Start: Demon Hunters - Flag Quest', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);

DELETE FROM `serverside_spell_effect` WHERE `SpellID` IN (196030, 228766);
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(196030, 0, 0, 6, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(228766, 0, 0, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40076, 0, 0, 0, 0, 0, 0, 0, 1, 0);
