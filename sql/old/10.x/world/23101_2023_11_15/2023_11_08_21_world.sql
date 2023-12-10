SET @CGUID := 6000784;
SET @ATID := 48;
SET @ATIDSPAWN := 48;
SET @NPCTEXTID := 560008;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 99915, 1481, 7705, 7742, '0', 5462, 0, 0, 1, 1587.9617919921875, 2543.091064453125, 62.10065841674804687, 3.499679088592529296, 120, 0, 0, 27954, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Sevis Brightflame (Area: Seat of Command - Difficulty: 0) CreateObject1 (Auras: 42459 - Dual Wield)
(@CGUID+1, 24021, 1481, 7705, 7742, '0', 0, 0, 0, 0, 1614.876708984375, 2517.765625, 76.457977294921875, 2.601563215255737304, 120, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 51886); -- ELM General Purpose Bunny (scale x0.01) (Area: Seat of Command - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '42459'); -- Sevis Brightflame - 42459 - Dual Wield

-- Serverside AT
DELETE FROM `areatrigger_template` WHERE `Id` = @ATID+0 AND `IsServerSide` = 1;
INSERT INTO `areatrigger_template` (`Id`, `IsServerSide`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `VerifiedBuild`) VALUES
(@ATID+0, 1, 1, 0, 35, 20, 25, 35, 20, 25, 0, 0, 0);

DELETE FROM `areatrigger` WHERE `SpawnId` = @ATIDSPAWN AND `IsServerSide` = 1;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerId`, `IsServerSide`, `MapId`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `Comment`) VALUES
(@ATIDSPAWN, @ATID, 1, 1481, 1167.2064, 2559.8027, -13.9890, 0.026840, 0, 0, 0, 1, 35, 20, 25, 35, 20, 25, 0, 0, 'at_enter_the_illidari_shivarra_conversation', 'Mardum - Trigger Conversation for Quest "Enter the Illidari: Shivarra"');

-- Template
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_sevis_brightflame_shivarra_gateway' WHERE `entry` = 99915;

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` = 99915;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(99915, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '42459'); -- 99915 (Sevis Brightflame) - Dual Wield

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` = 99915;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(99915, 0, 0, '$n, we have a huge problem here.', 12, 0, 100, 0, 0, 55342, 1, 101663, 0, 'Sevis Brightflame to Player'),
(99915, 1, 0, 'Your sacrifice will NOT be in vain!', 12, 0, 100, 0, 0, 55343, 1, 101655, 0, 'Sevis Brightflame to Player'),
(99915, 2, 0, 'It has been... an honor.', 12, 0, 100, 0, 0, 55341, 1, 101653, 0, 'Sevis Brightflame to Player');

-- Phasing
DELETE FROM `phase_area` WHERE `PhaseId` = 5462 AND `AreaId` = 7742;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7742, 5462, 'Sevis Brightflame at Shivarra Gateway');

-- Condition
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 5462 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 5462, 0, 0, 0, 47, 0, 38765, 8, 0, 0, 'Apply Phase 5462 if Quest 40378 is in progress'),
(26, 5462, 0, 0, 0, 48, 0, 280772, 0, 1, 1, 'Apply Phase 5462 if Questobjective 280772 (Sacrifice made) is not rewarded');

-- SendEvent: 47550 & 47549
DELETE FROM `event_script_names` WHERE `Id` IN (47550, 47549);
INSERT INTO `event_script_names` (`Id`, `ScriptName`) VALUES
(47550, 'event_sevis_sacrifice_player'),
(47549, 'event_sevis_sacrifice_self');

-- Scene data
DELETE FROM `scene_template` WHERE `SceneId`=1078;
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`, `Encrypted`) VALUES
(1078, 20, 1469, 0);

-- Serverside Spell
DELETE FROM `serverside_spell` WHERE `Id` IN (203292, 196866, 184563);
INSERT INTO `serverside_spell` (`Id`, `DifficultyID`, `CategoryId`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `AttributesEx11`, `AttributesEx12`, `AttributesEx13`, `AttributesEx14`, `Stances`, `StancesNot`, `Targets`, `TargetCreatureType`, `RequiresSpellFocus`, `FacingCasterFlags`, `CasterAuraState`, `TargetAuraState`, `ExcludeCasterAuraState`, `ExcludeTargetAuraState`, `CasterAuraSpell`, `TargetAuraSpell`, `ExcludeCasterAuraSpell`, `ExcludeTargetAuraSpell`, `CasterAuraType`, `TargetAuraType`, `ExcludeCasterAuraType`, `ExcludeTargetAuraType`, `CastingTimeIndex`, `RecoveryTime`, `CategoryRecoveryTime`, `StartRecoveryCategory`, `StartRecoveryTime`, `InterruptFlags`, `AuraInterruptFlags1`, `AuraInterruptFlags2`, `ChannelInterruptFlags1`, `ChannelInterruptFlags2`, `ProcFlags`, `ProcFlags2`, `ProcChance`, `ProcCharges`, `ProcCooldown`, `ProcBasePPM`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `Speed`, `LaunchDelay`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `ContentTuningId`, `SpellName`, `ConeAngle`, `ConeWidth`, `MaxTargetLevel`, `MaxAffectedTargets`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `SpellFamilyFlags4`, `DmgClass`, `PreventionType`, `AreaGroupId`, `SchoolMask`, `ChargeCategoryId`) VALUES
(203292, 0, 0, 0, 0, 0, 0, 0, 1048576, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 21, 1, 0, 0, 0, -1, 0, 0, 0, 'Enter the Illidari: Shivarra - Sevis Killed Me Aura', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(196866, 0, 0, 0, 0, 8388608, 0, 1, 1048576, 0, 0, 16777216, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, 0, 'Enter the Illidari: Shivarra - TH Conversation Called from Area Trigger When Dead', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(184563, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000080, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, 0, 'Enter the Illidari: Shivarra - Legion Gateway Kill Credit', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `serverside_spell_effect` WHERE `SpellID` IN (203292, 196866, 184563);
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(203292, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(196866, 0, 0, 267, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 736, 0, 0, 0, 0, 0, 0, 0, 18, 0),
(184563, 0, 0, 90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 94407, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(184563, 1, 0, 164, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 203292, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(184563, 2, 0, 140, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 190851, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);

-- Conversation data
DELETE FROM `conversation_template` WHERE `Id`=736;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(736, 1756, 0, 51972);

DELETE FROM `conversation_actors` WHERE (`ConversationId`=736 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(736, 50124, 0, 98075, 21135, 0, 0, 51972);

DELETE FROM `conversation_line_template` WHERE `Id` IN (1759, 1757, 1756);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(1759, 296, 0, 0, 0, 51972),
(1757, 296, 0, 0, 0, 51972),
(1756, 296, 0, 0, 0, 51972);

-- Gossip data
UPDATE `creature_template_gossip` SET `MenuID`=19016 WHERE (`CreatureID`=99915 AND `MenuID` = 19133);
UPDATE `creature_template_gossip` SET `VerifiedBuild`=51886 WHERE (`CreatureID`=99915 AND `MenuID` IN (19016,19133)) OR (`CreatureID`=93759 AND `MenuID`=18438);

DELETE FROM `gossip_menu` WHERE `MenuID` = 19016 AND `TextID` = 27771;

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+0;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 103328, 0, 0, 0, 0, 0, 0, 0, 51886); -- 99915 (Sevis Brightflame)

DELETE FROM `gossip_menu` WHERE (`MenuID`=19132 AND `TextID`=@NPCTEXTID+0);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(19132, @NPCTEXTID+0, 51886); -- 99915 (Sevis Brightflame)

UPDATE `gossip_menu` SET `VerifiedBuild`=51886 WHERE (`MenuID`=19016 AND `TextID` IN (27771,27770)) OR (`MenuID`=19133 AND `TextID`=28000) OR (`MenuID`=18438 AND `TextID`=26813);

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=19132 AND `OptionID` IN (0,1));
INSERT INTO `gossip_menu_option` (`GossipOptionID`, `MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `Flags`, `OverrideIconID`, `GossipNpcOptionID`, `VerifiedBuild`) VALUES
(45099, 19132, 0, 0, 'I\'ve made up my mind. Sacrifice me, Sevis, and power the gateway.', 103332, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 51754),
(45100, 19132, 1, 0, 'Hold a moment, Sevis. I\'m reconsidering.', 103336, 0, 19016, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 51754);

UPDATE `gossip_menu_option` SET `VerifiedBuild`=51886 WHERE (`MenuID`=19132 AND `OptionID` IN (1,0)) OR (`MenuID`=19016 AND `OptionID`=1);
UPDATE `gossip_menu_option` SET `GossipOptionID`=45102, `ActionMenuID`=19016, `VerifiedBuild`=51886 WHERE (`MenuID`=19133 AND `OptionID`=1);
UPDATE `gossip_menu_option` SET `GossipOptionID`=45101, `VerifiedBuild`=51886 WHERE (`MenuID`=19133 AND `OptionID`=0);
UPDATE `gossip_menu_option` SET `ActionMenuID`=19133, `VerifiedBuild`=51886 WHERE (`MenuID`=19016 AND `OptionID`=0);
UPDATE `gossip_menu_option` SET `ActionMenuID`=19132, `VerifiedBuild`=51886 WHERE (`MenuID`=19016 AND `OptionID`=1);

-- Quest stuff
DELETE FROM `quest_details` WHERE `ID`=38765;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(38765, 0, 0, 0, 0, 0, 0, 0, 0, 51754); -- Enter the Illidari: Shivarra

DELETE FROM `creature_queststarter` WHERE (`id`=93759 AND `quest`=38765);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(93759, 38765, 51754); -- Enter the Illidari: Shivarra offered Jace Darkweaver

DELETE FROM `quest_template_addon` WHERE `ID` = 38765;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(38765, 0, 0, 0, 39050, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'quest_enter_the_illidari_shivarra');

DELETE FROM `quest_objectives_completion_effect` WHERE `ObjectiveID` = 280772;
INSERT INTO `quest_objectives_completion_effect` (`ObjectiveID`, `GameEventID`, `SpellID`, `ConversationID`, `UpdatePhaseShift`, `UpdateZoneAuras`) VALUES
(280772, NULL, NULL, NULL, 1, 0);

-- Path for Sevis
SET @ENTRY := 99915;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 0, 1585.986, 2542.674, 62.01733, NULL, 0, 1),
(@PATH, 1, 1562.615, 2510.789, 59.19324, NULL, 0, 1),
(@PATH, 2, 1544.493, 2487.906, 56.45208, NULL, 0, 1),
(@PATH, 3, 1523.809, 2462.708, 55.58163, NULL, 0, 1);
