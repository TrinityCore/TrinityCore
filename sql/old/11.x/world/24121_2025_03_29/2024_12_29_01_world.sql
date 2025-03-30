SET @CGUID := 10005011;
SET @NPCTEXTID := 600069;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 223923, 2552, 14717, 14717, '0', 23673, 0, 0, 0, 568.5399169921875, -1205.8992919921875, 2.48101663589477539, 1.82973647117614746, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Natalia Pearce (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+1, 223924, 2552, 14717, 14717, '0', 23674, 0, 0, 0, 606.951416015625, -1231.859375, -2.37935256958007812, 5.465282917022705078, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689); -- Natalia Pearce (Area: Isle of Dorn - Difficulty: 0) CreateObject1

-- Template
UPDATE `creature_template` SET `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=223923; -- Natalia Pearce
UPDATE `creature_template` SET `faction`=35, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=223924; -- Natalia Pearce

-- Conversation
DELETE FROM `conversation_template` WHERE `Id` IN (25586,25590);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(25586, 69573, 0, 57689),
(25590, 69579, 0, 57689);

UPDATE `conversation_template` SET `ScriptName` = 'conversation_natalia_pearces_accept_precious_gems' WHERE `Id` = 25586;
UPDATE `conversation_template` SET `ScriptName` = 'conversation_natalia_pearces_complete_precious_gems' WHERE `Id` = 25590;

DELETE FROM `conversation_actors` WHERE (`ConversationId`=25586 AND `Idx` = 0) OR (`ConversationId`=25590 AND `Idx` IN (0,1));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(25586, 99047, 0, 0, 0, 0, 0, 57689), -- Full: 0x20197D3F00DA6540001389000050CAC8 Creature/0 R1631/S5001 Map: 2552 (Khaz Algar (Surface)) Entry: 223637 (Natalia Pearce) Low: 5294792
(25590, 99215, 0, 0, 0, 0, 0, 57689), -- Full: 0x2042313F00DAAD000064D40000531CDF Creature/0 R4236/S25812 Map: 2552 (Khaz Algar (Surface)) Entry: 223924 (Natalia Pearce) Low: 5446879
(25590, 0, 1, 0, 0, 0, 1, 57689); -- Full: 0x0800040000000000FFFFFFFFFFFFFFFF Player/0 R1/S16777215 Map: 0 (Eastern Kingdoms) Low: 1099511627775

DELETE FROM `conversation_line_template` WHERE `Id` IN (69573, 69584, 69583, 69581, 69580, 69579);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(69573, 0, 0, 0, 0, 57689),
(69584, 0, 0, 0, 0, 57689),
(69583, 0, 1, 0, 0, 57689),
(69581, 0, 0, 0, 0, 57689),
(69580, 0, 1, 0, 0, 57689),
(69579, 0, 0, 0, 0, 57689);

-- Phase
DELETE FROM `phase_name` WHERE `ID` = 23674;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(23674, 'Cosmetic - See Natalia Pearces inside the Basalteous cave');

DELETE FROM `phase_area` WHERE `PhaseId` = 23674;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(14717, 23674, 'See Natalia Pearces inside the Basalteous cave');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (23673,23674) AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 23673, 0, 0, 0, 47, 0, 82465, 8, 0, 0, 'Apply Phase 23673 if Quest 82465 is taken'),
(26, 23674, 0, 0, 0, 47, 0, 82465, 2|64, 0, 0, 'Apply Phase 23674 if Quest 82465 is complete | rewarded');

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=223923 AND `MenuID`=34984);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(223923, 34984, 57689); -- Natalia Pearce

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+0;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 264643, 0, 0, 0, 0, 0, 0, 0, 57689); -- 223923 (Natalia Pearce)

DELETE FROM `gossip_menu` WHERE (`MenuID`=34984 AND `TextID`=@NPCTEXTID+0);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(34984, @NPCTEXTID+0, 57689); -- 223923 (Natalia Pearce)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=34984 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(34984, 122493, 0, 0, 'After you.', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 57689);

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15) AND (`SourceGroup` IN (34984));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(15, 34984, 0, 0, 0, 9, 0, 82465, 0, 0, '', 0, 'Player for which gossip text is shown has quest Precious Gems (82465) active');

-- Quest
DELETE FROM `creature_queststarter` WHERE (`id`=223924 AND `quest`=82466);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(223924, 82466, 57689); -- What We Do For Gems offered by Natalia Pearce

DELETE FROM `creature_questender` WHERE (`id`=223924 AND `quest`=82465);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(223924, 82465, 57689); -- Precious Gems ended by Natalia Pearce

DELETE FROM `quest_objectives_completion_effect` WHERE `ObjectiveID` = 450025;
INSERT INTO `quest_objectives_completion_effect` (`ObjectiveID`, `GameEventID`, `SpellID`, `ConversationID`, `UpdatePhaseShift`, `UpdateZoneAuras`) VALUES
(450025, NULL, NULL, NULL, 1, 0);

DELETE FROM `quest_template_addon` WHERE `ID` = 82466;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(82466, 0, 0, 0, 82465, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- What We Do For Gems

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=223924 AND `DifficultyID`=0); -- 223924 (Natalia Pearce) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=223923 AND `DifficultyID`=0); -- 223923 (Natalia Pearce) - CanSwim

-- Natalia Pearce smart ai
SET @ENTRY := 223637;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 19, 0, 100, 0, 82465, 0, 0, 0, 0, 143, 25586, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest Precious Gems (82465) - Player who accepted quest: Start conversation 25586', ''),
(@ENTRY, 0, 1, 0, 40, 0, 100, 0, 1, 22363700, 0, 0, 0, 41, 2000, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On wapoint 1 of path 22363700 reached - Self: Despawn in 2 s', '');

-- Natalia Pearce smart ai
SET @ENTRY := 223923;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 1, 62, 0, 100, 0, 34984, 0, 0, 0, 0, 33, 223923, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 34984 selected - Gossip player: Give kill credit Natalia Pearce (223923)', ''),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 34984 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 143, 25590, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 34984 selected - Gossip player: Start conversation (25590) Actors<> (first line 69579)', '');

-- Natalia Pearce smart ai
SET @ENTRY := 223924;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 58, 0, 100, 0, 19, 22392400, 0, 0, 0, 53, 0, 22392401, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 19 of path 22392400 ended - Self: Start path #22392401, walk, do not repeat, Passive', ''),
(@ENTRY, 0, 1, 0, 58, 0, 100, 0, 0, 22392401, 0, 0, 0, 41, 2000, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On any waypoint of path 22392401 ended - Self: Despawn in 2 s', '');

-- Path for Natalia Pearce
SET @ENTRY := 223637;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Natalia Pearce - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1161.875, -2005.408, 80.17253, NULL, 0),
(@PATH, 1, 1165.0295, -1991.0452, 80.59499, NULL, 0),
(@PATH, 2, 1165.3923, -1984.4323, 80.73431, NULL, 0),
(@PATH, 3, 1165.191, -1978.092, 80.491325, NULL, 0),
(@PATH, 4, 1165.7305, -1974.1309, 80.28405, NULL, 0),
(@PATH, 5, 1166.1348, -1971.1602, 80.06721, NULL, 0),
(@PATH, 6, 1166.1666, -1970.941, 80.04346, NULL, 0);

-- Path for Natalia Pearce (run)
SET @ENTRY := 223924;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Natalia Pearce - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 573.13086, -1204.5195, 1.5434456, NULL, 0),
(@PATH, 1, 574.1289, -1204.4609, 1.3652716, NULL, 0),
(@PATH, 2, 574.8262, -1204.416, 1.3652716, NULL, 0),
(@PATH, 3, 575.1992, -1204.4395, 1.1621518, NULL, 0),
(@PATH, 4, 576.55914, -1203.9913, 1.2641888, NULL, 0),
(@PATH, 5, 577.2599, -1203.7604, 1.1122702, NULL, 0),
(@PATH, 6, 578.23956, -1203.4375, 1.4185454, NULL, 0),
(@PATH, 7, 578.4873, -1203.7229, 1.6263658, NULL, 0),
(@PATH, 8, 579.9707, -1205.432, 2.4789832, NULL, 0),
(@PATH, 9, 580.4241, -1205.9543, 2.5559785, NULL, 0),
(@PATH, 10, 581.66205, -1207.3807, 3.2729156, NULL, 0),
(@PATH, 11, 581.8108, -1207.5521, 3.2960181, NULL, 0),
(@PATH, 12, 582.42993, -1208.5288, 3.5478327, NULL, 0),
(@PATH, 13, 582.9775, -1209.3926, 3.8676937, NULL, 0),
(@PATH, 14, 583.25854, -1209.8359, 3.8548698, NULL, 0),
(@PATH, 15, 585.0303, -1212.6307, 4.1777277, NULL, 0),
(@PATH, 16, 585.8515, -1213.9263, 3.8800235, NULL, 0),
(@PATH, 17, 586.125, -1214.3577, 3.8656776, NULL, 0),
(@PATH, 18, 589.6389, -1221.2135, 1.5684685, NULL, 0),
(@PATH, 19, 594.40454, -1230.3663, -0.9916396, NULL, 0);

-- Path for Natalia Pearce (walk)
SET @ENTRY := 223924;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Natalia Pearce - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 606.9514, -1231.8594, -2.349821, NULL, 0);
