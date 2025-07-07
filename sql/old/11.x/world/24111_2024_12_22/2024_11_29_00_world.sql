SET @CGUID := 10004584;

SET @NPCTEXTID := 600049;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 224708, 2552, 14717, 14788, '0', 23936, 0, 0, 0, 1680.701416015625, -2489.767333984375, -58.984619140625, 3.507415056228637695, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689); -- Cenderragg (Area: The Opalcreg - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid` = @CGUID+0;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Cenderragg

-- Template
UPDATE `creature_template` SET `faction`=3407, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=224708; -- Cenderragg

-- Phase
DELETE FROM `phase_name` WHERE `ID` = 23936;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(23936, 'Cosmetic - See Cenderragg in the cave of The Opalcreg');

DELETE FROM `phase_area` WHERE `PhaseId` = 23936;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(14788, 23936, 'See Cenderragg in the cave of The Opalcreg');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 23936 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 23936, 0, 0, 0, 47, 0, 82797, 2|8|64, 0, 0, 'Apply Phase 23936 if Quest 82797 is taken | complete | rewarded'),
(26, 23936, 0, 0, 0, 47, 0, 82799, 2|8|64, 0, 1, 'Apply Phase 23936 if Quest 82799 is not taken | complete | rewarded'),
(26, 23936, 0, 0, 0, 47, 0, 82798, 2|8|64, 0, 1, 'Apply Phase 23936 if Quest 82798 is not taken | complete | rewarded'),
--
(26, 23936, 0, 0, 1, 47, 0, 82797, 2|8|64, 0, 0, 'Apply Phase 23936 if Quest 82797 is taken | complete | rewarded'),
(26, 23936, 0, 0, 1, 47, 0, 82799, 2|8|64, 0, 0, 'Apply Phase 23936 if Quest 82799 is taken | complete | rewarded'),
(26, 23936, 0, 0, 1, 47, 0, 82798, 2|8|64, 0, 1, 'Apply Phase 23936 if Quest 82798 is not taken | complete | rewarded'),
--
(26, 23936, 0, 0, 2, 47, 0, 82797, 2|8|64, 0, 0, 'Apply Phase 23936 if Quest 82797 is taken | complete | rewarded'),
(26, 23936, 0, 0, 2, 47, 0, 82799, 2|8|64, 0, 1, 'Apply Phase 23936 if Quest 82799 is not taken | complete | rewarded'),
(26, 23936, 0, 0, 2, 47, 0, 82798, 2|8|64, 0, 0, 'Apply Phase 23936 if Quest 82798 is taken | complete | rewarded');

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` = 224708;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(224708, 0, 0, 'Clear the path for me! I\'ll see you closer to the entrance to discuss how to shut this operation down.', 12, 0, 100, 0, 0, 0, 0, 0, 'Cenderragg to Player');

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=224708 AND `MenuID`=35425);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(224708, 35425, 57689); -- Cenderragg

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+0;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 268155, 0, 0, 0, 0, 0, 0, 0, 57689); -- 224708 (Cenderragg)

DELETE FROM `gossip_menu` WHERE (`MenuID`=35425 AND `TextID`=@NPCTEXTID+0);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(35425, @NPCTEXTID+0, 57689); -- 224708 (Cenderragg)

-- Quest
DELETE FROM `ui_map_quest` WHERE (`UIMapId`=2248 AND `QuestId`=84429);
INSERT INTO `ui_map_quest` (`UIMapId`, `QuestId`, `VerifiedBuild`) VALUES
(2248, 84429, 57689); -- Construct Containment

DELETE FROM `creature_queststarter` WHERE (`id`=224708 AND `quest` IN (82799,82798));
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(224708, 82799, 57689), -- Web Beats Rock offered by Cenderragg
(224708, 82798, 57689); -- An Opal of Mine offered by Cenderragg

DELETE FROM `creature_questender` WHERE (`id`=224708 AND `quest`=82797);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(224708, 82797, 57689); -- Hit Rock Bottom ended by Cenderragg

DELETE FROM `quest_template_addon` WHERE `ID` IN (82799, 82798);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(82799, 0, 0, 0, 82797, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Web Beats Rock 
(82798, 0, 0, 0, 82797, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- An Opal of Mine

-- Cenderragg smart ai
SET @ENTRY := 224708;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 19, 0, 100, 0, 82799, 0, 0, 0, 0, 80, 22470800, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest Web Beats Rock (82799) - Self: Start timed action list id #Cenderragg #0 (22470800) (update out of combat)', ''),
(@ENTRY, 0, 1, 0, 19, 0, 100, 0, 82798, 0, 0, 0, 0, 80, 22470800, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest An Opal of Mine (82798) - Self: Start timed action list id #Cenderragg #0 (22470800) (update out of combat)', '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 224708 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 224708, 0, 0, 9, 0, 82798, 0, 0, '', 0, 'Action invoker has quest An Opal of Mine (82798) active'),
(22, 2, 224708, 0, 0, 9, 0, 82799, 0, 0, '', 0, 'Action invoker has quest Web Beats Rock (82799) active');

-- Timed list 22470800 smart ai
SET @ENTRY := 22470800;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 149, 8, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Become personal clone for Last action invoker for 0 seconds (manual despawn)', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set npc flags NONE', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Talk 0 to invoker', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 53, 0, 22470800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Start path #22470800, walk, do not repeat, Passive', ''),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 9 seconds - Self: Despawn instantly', '');

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=224708 AND `DifficultyID`=0); -- 224708 (Cenderragg) - CanSwim

-- Path for Cenderragg
SET @ENTRY := 224708;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Cenderragg - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1679.7717, -2489.8135, -58.794106, NULL, 0),
(@PATH, 1, 1674.5217, -2490.0635, -58.794106, NULL, 0),
(@PATH, 2, 1674.0217, -2490.3135, -58.794106, NULL, 0),
(@PATH, 3, 1668.2717, -2490.3135, -58.044106, NULL, 0),
(@PATH, 4, 1667.7717, -2490.3135, -58.294106, NULL, 0),
(@PATH, 5, 1667.0217, -2490.3135, -58.294106, NULL, 0),
(@PATH, 6, 1663.342, -2490.8594, -58.686928, NULL, 0),
(@PATH, 7, 1662.8455, -2490.6362, -58.544083, NULL, 0),
(@PATH, 8, 1659.507, -2490.6233, -58.644463, NULL, 0);
