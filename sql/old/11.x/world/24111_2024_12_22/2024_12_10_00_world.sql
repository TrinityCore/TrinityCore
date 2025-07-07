SET @CGUID := 10004738;

SET @NPCTEXTID := 600056;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 222224, 2552, 14771, 15184, '0', 23641, 0, 0, 1, 3030.19970703125, -2674.56591796875, 262.306304931640625, 0.045685995370149612, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Peacekeeper Leif (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject1
(@CGUID+1, 222218, 2552, 14771, 15184, '0', 0, 0, 0, 0, 3034.755126953125, -2674.489501953125, 262.945220947265625, 3.204979419708251953, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Peacekeeper Lieutenant (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject1
(@CGUID+2, 226761, 2552, 14771, 15184, '0', 0, 0, 0, 0, 3022.407958984375, -2667.435791015625, 261.653717041015625, 3.212312221527099609, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689); -- Peacekeeper Alef (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject1

UPDATE `creature` SET `PhaseId` = 23640 WHERE `guid` IN (10004224, 10004234);

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (222224, 222218, 226761);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(222224, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 222224 (Peacekeeper Leif)
(222218, 0, 0, 0, 0, 0, 0, 0, 718, 0, 0, 0, 0, ''), -- 222218 (Peacekeeper Lieutenant)
(226761, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- 226761 (Peacekeeper Alef)

-- Template
UPDATE `creature_template` SET `faction`=3407, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=222218; -- Peacekeeper Lieutenant
UPDATE `creature_template` SET `faction`=3407, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=222224; -- Peacekeeper Leif
UPDATE `creature_template` SET `faction`=3407, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=226761; -- Peacekeeper Alef

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2838, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=226761 AND `DifficultyID`=0); -- 226761 (Peacekeeper Alef) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2838, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=222224 AND `DifficultyID`=0); -- 222224 (Peacekeeper Leif) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2838, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=222218 AND `DifficultyID`=0); -- 222218 (Peacekeeper Lieutenant) - CanSwim

-- Conversation
DELETE FROM `conversation_template` WHERE `Id` = 26218;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(26218, 71473, 0, 57689);

DELETE FROM `conversation_actors` WHERE (`ConversationId`=26218 AND `Idx` IN (2,1,0));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(26218, 100284, 2, 0, 0, 0, 0, 57689), -- Full: 0x2042313F00D64B400064D40000D1C06C Creature/0 R4236/S25812 Map: 2552 (Khaz Algar (Surface)) Entry: 219437 (Dornogal Citizen) Low: 13746284
(26218, 100285, 1, 0, 0, 0, 0, 57689), -- Full: 0x2042313F00D64B400064D4000051C06C Creature/0 R4236/S25812 Map: 2552 (Khaz Algar (Surface)) Entry: 219437 (Dornogal Citizen) Low: 5357676
(26218, 0, 0, 0, 0, 0, 1, 57689); -- Full: 0x0800040000000000FFFFFFFFFFFFFFFF Player/0 R1/S16777215 Map: 0 (Eastern Kingdoms) Low: 1099511627775

UPDATE `conversation_actors` SET `ConversationActorGuid` = 10004234 WHERE `ConversationId` = 26218 AND `ConversationActorId` = 100285 AND `Idx` = 1;
UPDATE `conversation_actors` SET `ConversationActorGuid` = 10004224 WHERE `ConversationId` = 26218 AND `ConversationActorId` = 100284 AND `Idx` = 2;

DELETE FROM `conversation_line_template` WHERE `Id` IN (71475, 71474, 71473);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(71475, 0, 2, 0, 0, 57689),
(71474, 0, 1, 0, 0, 57689),
(71473, 0, 0, 0, 0, 57689);

-- Phase
DELETE FROM `phase_name` WHERE `ID` IN (23640, 23641);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(23640, 'Cosmetic - See Dornogal Citizen at Crossroad Plaza'),
(23641, 'Cosmetic - See Peacekeeper Leif in Dornogal');

DELETE FROM `phase_area` WHERE `PhaseId` IN (23640, 23641);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(14717, 23640, 'See Dornogal Citizen at Crossroad Plaza'),
(14717, 23641, 'See Peacekeeper Leif in Dornogal');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 23640 AND `SourceEntry` = 0) OR (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 23641 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 23640, 0, 0, 0, 47, 0, 80456, 64, 0, 1, 'Apply Phase 23640 if Quest 80456 is not rewarded'),
(26, 23640, 0, 0, 0, 47, 0, 80209, 2|8|64, 0, 1, 'Apply Phase 23640 if Quest 80209 is not taken | complete | rewarded'),
(26, 23641, 0, 0, 0, 47, 0, 80209, 2|8|64, 0, 1, 'Apply Phase 23641 if Quest 80209 is not taken | complete | rewarded');

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=222218 AND `MenuID`=35576);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(222218, 35576, 57689); -- Peacekeeper Lieutenant

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+0;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 268204, 0, 0, 0, 0, 0, 0, 0, 57689); -- 222218 (Peacekeeper Lieutenant)

DELETE FROM `gossip_menu` WHERE (`MenuID`=35576 AND `TextID`=@NPCTEXTID+0);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(35576, @NPCTEXTID+0, 57689); -- 222218 (Peacekeeper Lieutenant)

-- Quest
DELETE FROM `creature_queststarter` WHERE (`id`=222224 AND `quest`=80209);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(222224, 80209, 57689); -- An Oddball in Dornogal offered by Peacekeeper Leif

UPDATE `creature_queststarter` SET `VerifiedBuild`=57689 WHERE (`id`=219437 AND `quest`=80456);

DELETE FROM `creature_questender` WHERE (`id`=222224 AND `quest`=80456);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(222224, 80456, 57689); -- A Sassy Arathi ended by Peacekeeper Leif

-- Dornogal Citizen smart ai
SET @ENTRY := 219437;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 19, 0, 100, 0, 80456, 0, 0, 0, 0, 143, 26218, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest A Sassy Arathi (80456) - Player who accepted quest: Start conversation 26218', '');
