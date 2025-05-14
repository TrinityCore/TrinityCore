SET @CGUID := 7003100;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 140048, 1643, 8721, 9134, '0', 11260, 0, 0, 0, -1152.1649169921875, 1951.0711669921875, 138.3331756591796875, 3.129776716232299804, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Arthur Tradewind (Area: Gol Koval - Difficulty: 0) CreateObject1 (Auras: 132653 - Stealth)
(@CGUID+1, 140048, 1643, 8721, 9134, '0', 11261, 0, 0, 0, -1006.25518798828125, 1755.6336669921875, 124.049224853515625, 4.17934274673461914, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568); -- Arthur Tradewind (Area: Gol Koval - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '132653'); -- Arthur Tradewind - 132653 - Stealth

-- Conversation
DELETE FROM `conversation_template` WHERE `Id` IN (8790,8792);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(8790, 19740, 0, 60568),
(8792, 19750, 0, 60568);

UPDATE `conversation_template` SET `ScriptName` = 'conversation_drustvar_really_big_problem_complete' WHERE `Id` = 8790;

DELETE FROM `conversation_actors` WHERE (`ConversationId`=8790 AND `Idx`=0) OR (`ConversationId`=8792 AND `Idx` IN (0,1));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(8790, 65120, 0, 0, 0, 0, 0, 0, 60568), -- Full: 0x203AF8CD6088C4400002CE000021DA1D Creature/0 R3774/S718 Map: 1643 (Kul Tiras) Entry: 140049 (Thornguard Ironclaw) Low: 2218525
(8792, 65141, 7002987, 0, 0, 0, 0, 0, 60568), -- Full: 0x203AF8CD6088A5800002CE00002195CD Creature/0 R3774/S718 Map: 1643 (Kul Tiras) Entry: 139926 (Thornspeaker Birchgrove) Low: 2201037
(8792, 65118, @CGUID+1, 1, 0, 0, 0, 0, 60568); -- Full: 0x203AF8CD6088C4000002CE00002195CC Creature/0 R3774/S718 Map: 1643 (Kul Tiras) Entry: 140048 (Arthur Tradewind) Low: 2201036

DELETE FROM `conversation_line_template` WHERE `Id` IN (19741, 19740, 19754, 19753, 19752, 19751, 19750);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(19741, 0, 0, 0, 0, 60568),
(19740, 0, 0, 0, 0, 60568),
(19754, 0, 0, 0, 0, 60568),
(19753, 0, 1, 0, 0, 60568),
(19752, 0, 0, 0, 0, 60568),
(19751, 0, 1, 0, 0, 60568),
(19750, 0, 0, 0, 0, 60568);

-- Spellscript
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_drustvar_dismiss_tradewind';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(274789, 'spell_drustvar_dismiss_tradewind');

-- Phase
DELETE FROM `phase_name` WHERE `ID` IN (11260,11261);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(11260, 'Cosmetic - See Arthur Tradewind stealthed'),
(11261, 'Cosmetic - See Arthur Tradewind back in camp');

DELETE FROM `phase_area` WHERE `PhaseId` IN (11260,11261);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(9134, 11260, 'See Arthur Tradewind stealthed'),
(9134, 11261, 'See Arthur Tradewind back in camp');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (11260,11261) AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 11260, 0, 0, 0, 47, 0, 48180, 2|8|64, 0, 1, 'Apply Phase 11260 if Quest 48180 is not in progress | complete | rewarded'),
(26, 11261, 0, 0, 0, 47, 0, 48180, 2|64, 0, 0, 'Apply Phase 11261 if Quest 48180 is complete | rewarded');

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` = 140049;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(140049, 0, 0, 'Come on! Let\'s turn that monster into rubble!', 12, 0, 100, 15, 0, 0, 157373, 5, 'Arthur Tradewind to Player'),
(140049, 1, 0, 'I\'m gonna rip you apart!', 12, 0, 100, 0, 0, 0, 157376, 5, 'Arthur Tradewind to Player');

-- Creature summon data
DELETE FROM `creature_summoned_data` WHERE `CreatureID` = 140049; 
INSERT INTO `creature_summoned_data` (`CreatureID`, `CreatureIDVisibleToSummoner`, `GroundMountDisplayID`, `FlyingMountDisplayID`, `DespawnOnQuestsRemoved`) VALUES
(140049, 140048, NULL, NULL, NULL);

-- SpellArea
DELETE FROM `spell_area` WHERE `area` = 9134 AND `spell` = 274729;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES
(274729, 9134, 48180, 0, 0, 0, 2, 0x01, 8, 11);

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=140048 AND `MenuID`=22755);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(140048, 22755, 60568); -- Arthur Tradewind

-- Quest
DELETE FROM `quest_details` WHERE `ID`=48180;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(48180, 1, 0, 0, 0, 0, 0, 0, 0, 60568); -- Really Big Problem

DELETE FROM `creature_queststarter` WHERE (`id`=140048 AND `quest`=48180);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(140048, 48180, 60568); -- Really Big Problem offered by Arthur Tradewind

DELETE FROM `creature_questender` WHERE (`id`=139926 AND `quest`=48180);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(139926, 48180, 60568); -- Really Big Problem ended by Thornspeaker Birchgrove

DELETE FROM `quest_objectives_completion_effect` WHERE `ObjectiveID` = 291646;
INSERT INTO `quest_objectives_completion_effect` (`ObjectiveID`, `GameEventID`, `SpellID`, `ConversationID`, `UpdatePhaseShift`, `UpdateZoneAuras`) VALUES
(291646, NULL, NULL, 8790, 1, 0);

-- Thornguard Ironclaw smart ai
SET @ENTRY := 140049;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On just summoned - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 1, 0, 4, 0, 100, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'On aggro - Self: Talk 1 to invoker', ''),
(@ENTRY, 0, 2, 0, 0, 0, 100, 0, 1000, 4000, 3000, 7000, 0, 11, 273892, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 3 - 7 seconds (1 - 4s initially) (IC) - Self: Cast spell  273892 on Victim', '');

-- Thornspeaker Birchgrove smart ai
SET @ENTRY := 139926;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 20, 0, 100, 0, 48180, 0, 0, 0, 0, 143, 8792, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player rewarded quest Really Big Problem (48180) - Rewarded player: Start conversation (8792) Actors<> (first line 19750)', '');
