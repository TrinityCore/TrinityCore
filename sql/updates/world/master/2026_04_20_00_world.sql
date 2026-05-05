SET @CGUID := 11000790;

SET @NPCTEXTID := 610017;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 236704, 0, 15968, 15995, '0', 26248, 0, 0, 1, 7307.37060546875, -4130.1474609375, 89.17822265625, 6.151532649993896484, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Orweyna (Area: Fairbreeze Village - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+1, 240715, 0, 15968, 15995, '0', 26248, 0, 0, 1, 7308.93994140625, -4128.76416015625, 89.17822265625, 4.997533798217773437, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838); -- Halduron Brightwing (Area: Fairbreeze Village - Difficulty: 0) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- Orweyna

-- Template
UPDATE `creature_template` SET `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=240715; -- Halduron Brightwing
UPDATE `creature_template` SET `faction`=35, `npcflag`=281474976710659, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=236704; -- Orweyna

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3321, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=236704 AND `DifficultyID`=0); -- 236704 (Orweyna) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=3313, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=240715 AND `DifficultyID`=0); -- 240715 (Halduron Brightwing) - CanSwim

-- Phase
DELETE FROM `phase_name` WHERE `ID` = 26248;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(26248, 'Cosmetic - See Orweyna and Halduron at Fairbreeze Village');

DELETE FROM `phase_area` WHERE `PhaseId` = 26248;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(15995, 26248, 'See Orweyna and Halduron at Fairbreeze Village');

-- Conversation
DELETE FROM `conversation_template` WHERE `Id`=31006;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(31006, 85399, 0, 66838);

DELETE FROM `conversation_actors` WHERE (`ConversationId`=31006 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(31006, 105463, 11000754, 0, 0, 0, 0, 0, 66838); -- Full: 0x203CC40000E642C0043900000065B6B7 Creature/0 R3889/S276736 Map: 0 (Eastern Kingdoms) Entry: 235787 (Lor'themar Theron) Low: 6665911

DELETE FROM `conversation_line_template` WHERE `Id` IN (85400, 85399);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(85400, 0, 0, 0, 0, 66838),
(85399, 0, 0, 0, 0, 66838);

-- Quest
DELETE FROM `quest_details` WHERE `ID`=86899;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(86899, 1, 0, 0, 0, 0, 0, 0, 0, 66838); -- The Root Cause

UPDATE `quest_description_conditional` SET `VerifiedBuild`=66838 WHERE (`QuestId`=93057 AND `PlayerConditionId`=923 AND `QuestgiverCreatureId`=0 AND `locale`='enUS');

DELETE FROM `creature_queststarter` WHERE (`id`=236704 AND `quest`=86899);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(236704, 86899, 66838); -- The Root Cause offered by Orweyna

DELETE FROM `quest_template_addon` WHERE `ID` = 86899;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(86899, 0, 0, 0, 89402, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=240715 AND `MenuID`=39207);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(240715, 39207, 66838); -- Halduron Brightwing

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+2;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 289841, 0, 0, 0, 0, 0, 0, 0, 66838), -- 240715 (Halduron Brightwing)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 289840, 0, 0, 0, 0, 0, 0, 0, 66838), -- 240715 (Halduron Brightwing)
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 289843, 0, 0, 0, 0, 0, 0, 0, 66838); -- 240715 (Halduron Brightwing)

DELETE FROM `gossip_menu` WHERE (`MenuID`=39206 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=39207 AND `TextID`=@NPCTEXTID+1) OR (`MenuID`=39208 AND `TextID`=@NPCTEXTID+2);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(39206, @NPCTEXTID+0, 66838), -- 240715 (Halduron Brightwing)
(39207, @NPCTEXTID+1, 66838), -- 240715 (Halduron Brightwing)
(39208, @NPCTEXTID+2, 66838); -- 240715 (Halduron Brightwing)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=39206 AND `OptionID`=0) OR (`MenuID`=39207 AND `OptionID` IN (0,1));
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(39206, 133756, 0, 0, 'I\'d like to ask something else.', 0, 0, 0, 39207, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66838),
(39207, 133754, 0, 0, 'Who are you?', 25092, 0, 0, 39206, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66838), -- OptionBroadcastTextID: 25092 - 38470 - 47091 - 47632 - 62792 - 65124 - 79414 - 97339 - 153888 - 161428 - 166571 - 176081 - 185133 - 224837 - 263541 - 298152
(39207, 133755, 1, 0, 'Why are you coming along?', 0, 0, 0, 39208, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66838);

-- Harandar
SET @ENTRY := 89402;
INSERT IGNORE INTO `quest_template_addon` (`ID`) VALUES (@ENTRY);
UPDATE `quest_template_addon` SET `ScriptName` = 'SmartQuest' WHERE `ID` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 5 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 5, 0, 0, 47, 0, 100, 0, 0, 0, 0, 0, 0, 143, 31006, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On quest accepted - Player who accepted: Start conversation 31006', '');
