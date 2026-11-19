SET @CGUID := 9003904;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 199340, 0, 1519, 9171, '0', 20675, 0, 0, 0, -8228.767578125, 777.03472900390625, 77.26209259033203125, 4.643933296203613281, 120, 0, 0, 67751, 0, 0, 0, 0, 0, 49801); -- Agent Render (Area: Stormwind Embassy - Difficulty: 0) CreateObject1

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (199340 /*199340 (Agent Render)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(199340, 0, 0, 0, 0, 0, 1, 0, 0, 16228, 0, 0, 0, ''); -- 199340 (Agent Render)

UPDATE `creature_template` SET `faction`=12, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=34816 WHERE `entry`=199340; -- Agent Render

-- Phasing
DELETE FROM `phase_name` WHERE `ID` = 20675;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(20675, 'Cosmetic - See Agent Render in Stormwind Embassy');

DELETE FROM `phase_area` WHERE (`AreaId` = 1519 AND `PhaseId` = 20675);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(1519, 20675, 'Cosmetic - See Agent Render in Stormwind Embassy');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 20675 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 20675, 0, 0, 0, 16, 0, 0x1, 0, 0, 0, 'Apply Phase 20675 if player is Human'),
(26, 20675, 0, 0, 0, 27, 0, 50, 3, 0, 0, 'Apply Phase 20675 if player is level 50 or higher');

-- Quest data
DELETE FROM `quest_details` WHERE `ID`=75265;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(75265, 0, 0, 0, 0, 0, 0, 0, 0, 49801); -- An Urgent Matter

DELETE FROM `creature_queststarter` WHERE (`id`=199340 AND `quest`=75265);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(199340, 75265, 49801); -- An Urgent Matter offered Agent Render

-- Conversation data
DELETE FROM `conversation_actors` WHERE (`ConversationId`=20338 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(20338, 89175, 0, 198884, 72253, 0, 0, 49801);

DELETE FROM `conversation_line_template` WHERE `Id`=52456;
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(52456, 82, 0, 0, 49801);

DELETE FROM `conversation_template` WHERE `Id`=20338;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(20338, 52456, 0, 49801);

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureId` = 199340;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(199340, 0, 0, 'Hail, $n! I bear a high priority message for you!', 12, 0, 100, 669, 0, 219851, 233050, 5, 'Agent Render to Player');

-- Model data
DELETE FROM `creature_model_info` WHERE `DisplayID`=110648;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(110648, 0.305999994277954101, 1.5, 0, 49801);

 -- Agent Render smart ai
SET @ENTRY := 199340;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 10, 0, 100, 0, 1, 10, 300000, 300000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On only non hostile unit in line of sight (OOC) - Self: Talk (0) to invoker');

 -- An Urgent Matter
DELETE FROM `smart_scripts` WHERE `source_type` = 5 AND `entryOrGuid` IN (75265, 72644);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(75265, 5, 0, 0, 47, 0, 100, 0, 0, 0, 0, 0, 85, 396312, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On quest accepted - Self: Cast spell 396312 on self'),
(72644, 5, 0, 0, 47, 0, 100, 0, 0, 0, 0, 0, 85, 396312, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On quest accepted - Self: Cast spell 396312 on self');

DELETE FROM `quest_template_addon` WHERE `ID` IN (75265, 72644);
INSERT INTO `quest_template_addon` (`ID`, `ScriptName`) VALUES
(75265, 'SmartQuest'),
(72644, 'SmartQuest');
