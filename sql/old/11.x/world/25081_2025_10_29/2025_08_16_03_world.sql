SET @CGUID := 10006617;
SET @NPCTEXTID := 600113;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 233603, 2552, 14771, 15044, '0', 24888, 0, 0, 0, 2923.185791015625, -2418.092041015625, 266.3282470703125, 4.768257617950439453, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Locus-Walker (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@CGUID+1, 227758, 2552, 14771, 15044, '0', 25164, 0, 0, 1, 2923.63720703125, -2423.116455078125, 266.3282470703125, 2.940192699432373046, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62493); -- Alleria Windrunner (Area: Foundation Hall - Difficulty: 0) CreateObject1 (Auras: 463787 - [DNT] RP Chat Bubble)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, '463787'); -- Alleria Windrunner - 463787 - [DNT] RP Chat Bubble

-- Template
UPDATE `creature_template` SET `faction`=35, `npcflag`=281474976710659, `BaseAttackTime`=2000, `unit_flags`=0x140, `unit_flags2`=0x800 WHERE `entry`=227758; -- Alleria Windrunner
UPDATE `creature_template` SET `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=233603; -- Locus-Walker

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=0 AND `Entry` IN (231120,238129,233603));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `TypeFlags3`) VALUES
(231120, 0, 10, 10, 1, 282441, 0x4, 0, 0), -- Alleria Windrunner
(238129, 0, 10, 1, 1, 317096, 0x0, 0, 0), -- Researcher Onermu
(233603, 0, 10, 1, 1, 285245, 0x0, 32768, 0); -- Locus-Walker

UPDATE `creature_template_difficulty` SET `VerifiedBuild`=62493 WHERE (`DifficultyID`=0 AND `Entry` IN (223746,222754,230542,222631,224544,226739,214838,230031,221462,242566,231110,219348,222781,219188,227321,232132,226237,219382,214947,227318,219014,225654,214950,242550,229379,214824,225664,215070,214948,219346,227389));
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2462, `StaticFlags1`=0x10000000, `VerifiedBuild`=62493 WHERE (`Entry`=223728 AND `DifficultyID`=0); -- 223728 (Auditor Balwurz) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2462, `StaticFlags1`=0x10000000, `VerifiedBuild`=62493 WHERE (`Entry`=223726 AND `DifficultyID`=0); -- 223726 (Waxmonger Quiwik) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x30000100, `VerifiedBuild`=62493 WHERE (`Entry`=227437 AND `DifficultyID`=0); -- 227437 (Archmage Khadgar) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=863, `StaticFlags1`=0x10000000, `VerifiedBuild`=62493 WHERE (`Entry`=228046 AND `DifficultyID`=0); -- 228046 (Alta) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `VerifiedBuild`=62493 WHERE (`Entry`=223129 AND `DifficultyID`=0); -- 223129 (Invis bunny for spell targeting) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2829, `StaticFlags1`=0x10000000, `VerifiedBuild`=62493 WHERE (`Entry`=238129 AND `DifficultyID`=0); -- 238129 (Researcher Onermu) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x30000100, `VerifiedBuild`=62493 WHERE (`Entry`=227436 AND `DifficultyID`=0); -- 227436 (Archmage Khadgar) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=62493 WHERE (`Entry`=227758 AND `DifficultyID`=0); -- 227758 (Alleria Windrunner) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3004, `StaticFlags1`=0x10000000, `VerifiedBuild`=62493 WHERE (`Entry`=235214 AND `DifficultyID`=0); -- 235214 (Mole Machine Operator) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2855, `VerifiedBuild`=62493 WHERE (`Entry`=219542 AND `DifficultyID`=0); -- 219542 (Bronze Timekeeper) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3008, `StaticFlags1`=0x10000000, `VerifiedBuild`=62493 WHERE (`Entry`=233603 AND `DifficultyID`=0); -- 233603 (Locus-Walker) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=863, `StaticFlags1`=0x10000000, `VerifiedBuild`=62493 WHERE (`Entry`=228048 AND `DifficultyID`=0); -- 228048 (Flint) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3004, `StaticFlags1`=0x10000000, `VerifiedBuild`=62493 WHERE (`Entry`=233325 AND `DifficultyID`=0); -- 233325 (Stormranger Guide) - CanSwim

-- Conversation
DELETE FROM `conversation_template` WHERE `Id` IN (27165, 27635);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(27165, 77288, 0, 62493),
(27635, 75991, 0, 62493);

DELETE FROM `conversation_actors` WHERE (`ConversationId`=27165 AND `Idx` IN (2,1,0)) OR (`ConversationId`=27635 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(27165, 103262, @CGUID+0, 2, 0, 0, 0, 0, 62493), -- Full: 0x202FD53F00E420C0002E7A00001DBC13 Creature/0 R3061/S11898 Map: 2552 (Khaz Algar (Surface)) Entry: 233603 (Locus-Walker) Low: 1948691
(27165, 100751, @CGUID+1, 1, 0, 0, 0, 0, 62493), -- Full: 0x202FD53F00DE6B80002E7A00001DBC13 Creature/0 R3061/S11898 Map: 2552 (Khaz Algar (Surface)) Entry: 227758 (Alleria Windrunner) Low: 1948691
(27165, 0, 0, 0, 0, 0, 0, 1, 62493), -- Full: 0x0800040000000000FFFFFFFFFFFFFFFF Player/0 R1/S16777215 Map: 0 (Eastern Kingdoms) Low: 1099511627775
(27635, 102508, 0, 0, 231120, 131464, 0, 0, 62493);

DELETE FROM `conversation_line_template` WHERE `Id` IN (74231, 74230, 77288, 75991);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(74231, 0, 2, 0, 0, 62493),
(74230, 0, 1, 0, 0, 62493),
(77288, 0, 0, 0, 0, 62493),
(75991, 1854, 0, 0, 0, 62493);

-- Phase
DELETE FROM `phase_area` WHERE `PhaseId` IN (24888,25164);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(14771, 24888, 'See Locus-Walker in Dornogal'),
(14771, 25164, 'See Alleria in Dornogal');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 24888 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 24888, 0, 0, 0, 47, 0, 84957, 8|64, 0, 1, 'Apply Phase 9191 if Quest 84957 is not in progress | rewarded');

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=233603 AND `MenuID`=39815) OR (`CreatureID`=227758 AND `MenuID`=35701);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(233603, 39815, 62493), -- Locus-Walker
(227758, 35701, 62493); -- Alleria Windrunner

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+1;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 293256, 0, 0, 0, 0, 0, 0, 0, 62493), -- 233603 (Locus-Walker)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 268604, 0, 0, 0, 0, 0, 0, 0, 62493); -- 227758 (Alleria Windrunner)

DELETE FROM `gossip_menu` WHERE (`MenuID`=39815 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=35701 AND `TextID`=@NPCTEXTID+1);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(39815, @NPCTEXTID+0, 62493), -- 233603 (Locus-Walker)
(35701, @NPCTEXTID+1, 62493); -- 227758 (Alleria Windrunner)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=39815 AND `OptionID`=0) OR (`MenuID`=35701 AND `OptionID`=2);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(39815, 134562, 0, 0, '<Show me your vision of the Dark Heart.>', 0, 0, 4, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 62493),
(35701, 131199, 2, 0, 'I have heard this tale before. |cFFFF0000<Skip the \"Lingering Shadows\" campaign.>|r', 0, 0, 1, 0, 0, NULL, 0, 0, 'Are you sure? Certain quests will be abandoned and unearned rewards will be lost. This action cannot be undone.', 0, NULL, NULL, 62493);

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID` IN (126344, 131473);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(126344, 0.305999994277954101, 1.5, 0, 62493),
(131473, 0.756186842918395996, 1.20000004768371582, 0, 62493);

UPDATE `creature_model_info` SET `VerifiedBuild`=62493 WHERE `DisplayID` IN (120753, 117351, 120830, 121734, 119703, 121975, 122461, 118648, 117357, 120676, 121178, 120623, 25947, 120757, 120670, 120637, 118451, 120669, 120802, 117354, 121985, 123939, 121971, 120638, 105161, 116218, 117656, 120610, 27823, 118650, 118452, 42941, 117794, 120626, 117409, 119074, 120627, 121986, 117410, 40657, 125322, 120668, 117649, 118072, 121973, 117359, 117652, 123792, 118887, 121153, 121976, 117338, 117657, 121978, 121972, 120675, 117651, 121982, 117660, 118463, 117352, 104041, 104040, 120540, 121157, 121980, 117650, 124737, 120672, 40658, 114814, 45304, 118447, 103813, 121155, 120541, 23767, 106697, 120750, 123940, 114500, 123789, 120756, 121154);

-- Quest
DELETE FROM `quest_offer_reward` WHERE `ID`=84956;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(84956, 1, 1, 0, 0, 0, 0, 0, 0, 'The Shadowguard will stop at nothing to revive the Void Lord, Dimensius. And we should be concerned--my home was sundered by the monster. It is no mystery on how things will end if it is not stopped.\n\nHowever, I have been working on a plan... a contingency really, and it is now time to put it into motion.', 62493); -- A Shadowy Invitation

DELETE FROM `quest_details` WHERE `ID` IN (84957 /*Return to the Veiled Market*/, 84956 /*A Shadowy Invitation*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(84957, 1, 273, 0, 0, 0, 0, 0, 0, 62493), -- Return to the Veiled Market
(84956, 1, 0, 0, 0, 0, 0, 0, 0, 62493); -- A Shadowy Invitation

DELETE FROM `creature_queststarter` WHERE (`id`=233603 AND `quest`=84957);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(233603, 84957, 62493); -- Return to the Veiled Market offered by Locus-Walker

DELETE FROM `creature_questender` WHERE (`id`=233603 AND `quest`=84956);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(233603, 84956, 62493); -- A Shadowy Invitation ended by Locus-Walker

DELETE FROM `quest_template_addon` WHERE `ID` = 84957;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(84957, 0, 0, 0, 84956, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

-- A Shadowy Invitation
SET @ENTRY := 84956;
INSERT IGNORE INTO `quest_template_addon` (`ID`) VALUES (@ENTRY);
UPDATE `quest_template_addon` SET `ScriptName` = 'SmartQuest' WHERE `ID` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 5 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 5, 0, 0, 47, 0, 100, 0, 0, 0, 0, 0, 0, 143, 27635, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On quest accepted - Player who accepted: Start conversation (27635) Actors<Alleria Windrunner (102508)> (first line 75991)', '');
