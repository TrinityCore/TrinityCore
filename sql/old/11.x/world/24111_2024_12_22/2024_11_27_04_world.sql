SET @CGUID := 10004582;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 224707, 2552, 14717, 14788, '0', 23935, 0, 0, 0, 1561.5242919921875, -2257.34033203125, 25.00594329833984375, 2.806776762008666992, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Alvegar (Area: The Opalcreg - Difficulty: 0) CreateObject1
(@CGUID+1, 224707, 2552, 14717, 14788, '0', 23929, 0, 0, 0, 1630.859375, -2381.404541015625, 80.43780517578125, 4.474325180053710937, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689); -- Alvegar (Area: The Opalcreg - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid` = @CGUID+0;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Alvegar

-- Template
UPDATE `creature_template` SET `faction`=3407, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=224707; -- Alvegar

-- Phase
DELETE FROM `phase_name` WHERE `ID` IN (23935, 23929);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(23935, 'Cosmetic - See Alvegar hiding near The Opalcreg'),
(23929, 'Cosmetic - See Alvegar at the top of The Opalcreg');

DELETE FROM `phase_area` WHERE `PhaseId` IN (23935, 23929); 
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(14788, 23935, 'See Alvegar hiding near The Opalcreg'),
(14788, 23929, 'See Alvegar at the top of The Opalcreg');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 23935 AND `SourceEntry` = 0) OR (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 23929 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 23935, 0, 0, 0, 47, 0, 82792, 2|8|64, 0, 0, 'Apply Phase 23935 if Quest 82792 is taken | complete | rewarded'),
(26, 23935, 0, 0, 0, 47, 0, 82796, 2|8|64, 0, 1, 'Apply Phase 23935 if Quest 82796 is not taken | complete | rewarded'),
(26, 23929, 0, 0, 0, 47, 0, 82796, 2|8|64, 0, 0, 'Apply Phase 23929 if Quest 82796 is taken | complete | rewarded'),
(26, 23929, 0, 0, 0, 47, 0, 82797, 2|8|64, 0, 1, 'Apply Phase 23929 if Quest 82797 is not taken | complete | rewarded');

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` = 224707;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(224707, 0, 0, 'Over here!', 12, 0, 100, 0, 0, 0, 0, 0, 'Alvegar to Player'),
(224707, 1, 0, 'See you up top.', 12, 0, 100, 0, 0, 0, 0, 0, 'Alvegar to Player'),
(224707, 2, 0, 'Cogs bless you. I must inform the Foreman on what\'s happening.', 12, 0, 100, 0, 0, 0, 0, 0, 'Alvegar to Player');

-- Quest
DELETE FROM `creature_queststarter` WHERE (`id`=224707 AND `quest`=82796) OR (`id`=224707 AND `quest`=82797);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(224707, 82796, 57689), -- Third Mine Blind offered by Alvegar
(224707, 82797, 57689); -- Hit Rock Bottom offered by Alvegar

DELETE FROM `creature_questender` WHERE (`id`=224707 AND `quest`=82792) OR (`id`=224707 AND `quest`=82796);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(224707, 82792, 57689), -- All Ore Nothing ended by Alvegar
(224707, 82796, 57689); -- Third Mine Blind ended by Alvegar

DELETE FROM `quest_template_addon` WHERE `ID` IN (82796, 82797);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(82796, 0, 0, 0, 82792, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Third Mine Blind
(82797, 0, 0, 0, 82796, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- Hit Rock Bottom

-- Alvegar smart ai
SET @ENTRY := 224707;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 19, 0, 100, 0, 82796, 0, 0, 0, 0, 80, 22470700, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest Third Mine Blind (82796) - Self: Start timed action list id #Alvegar #0 (22470700) (update out of combat)', ''),
(@ENTRY, 0, 1, 0, 19, 0, 100, 0, 82797, 0, 0, 0, 0, 80, 22470701, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest Hit Rock Bottom (82797) - Self: Start timed action list id #Alvegar #1 (22470701) (update out of combat)', '');

-- Timed list 22470700 smart ai
SET @ENTRY := 22470700;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 149, 8, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Become personal clone for Last action invoker for 0 seconds (manual despawn)', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set npc flags NONE', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Talk 1 to invoker', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 53, 0, 22470700, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Start path #22470700, walk, do not repeat, Passive', ''),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3 seconds - Self: Despawn instantly', '');

-- Timed list 22470701 smart ai
SET @ENTRY := 22470701;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 149, 8, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Become personal clone for Last action invoker for 0 seconds (manual despawn)', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set npc flags NONE', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Talk 2 to invoker', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 53, 0, 22470701, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Start path #22470701, walk, do not repeat, Passive', ''),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 8 seconds - Self: Despawn instantly', '');

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=224707 AND `DifficultyID`=0); -- 224707 (Alvegar) - CanSwim

-- Path for Alvegar
SET @ENTRY := 224707;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Alvegar - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1561.4739, -2257.916, 25.369654, NULL, 0),
(@PATH, 1, 1558.4739, -2258.416, 25.119654, NULL, 0),
(@PATH, 2, 1558.2239, -2258.416, 24.869654, NULL, 0),
(@PATH, 3, 1556.7239, -2259.916, 25.369654, NULL, 0),
(@PATH, 4, 1554.9739, -2260.666, 25.119654, NULL, 0),
(@PATH, 5, 1552.9739, -2261.416, 25.369654, NULL, 0),
(@PATH, 6, 1551.2239, -2262.166, 25.369654, NULL, 0),
(@PATH, 7, 1550.2239, -2262.666, 25.619654, NULL, 0),
(@PATH, 8, 1548.4236, -2263.4915, 25.65003, NULL, 0),
(@PATH, 9, 1547.05, -2262.6719, 25.785364, NULL, 0),
(@PATH, 10, 1546.05, -2262.6719, 25.785364, NULL, 0),
(@PATH, 11, 1545.05, -2262.6719, 25.785364, NULL, 0),
(@PATH, 12, 1544.05, -2262.1719, 25.785364, NULL, 0),
(@PATH, 13, 1541.9236, -2261.698, 25.338785, NULL, 0);

-- Path for Alvegar
SET @ENTRY := 224707;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Alvegar - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1633.5148, -2382.2048, 81.480225, NULL, 0),
(@PATH, 1, 1635.0148, -2382.7048, 81.730225, NULL, 0),
(@PATH, 2, 1636.7648, -2383.2048, 81.980225, NULL, 0),
(@PATH, 3, 1638.7648, -2383.9548, 81.730225, NULL, 0),
(@PATH, 4, 1641.1702, -2385.0051, 80.939316, NULL, 0),
(@PATH, 5, 1643.1719, -2384.9482, 80.91426, NULL, 0),
(@PATH, 6, 1644.1719, -2385.1982, 80.16426, NULL, 0),
(@PATH, 7, 1645.1719, -2385.1982, 79.91426, NULL, 0),
(@PATH, 8, 1647.9219, -2385.4482, 80.91426, NULL, 0),
(@PATH, 9, 1648.5295, -2385.889, 80.748, NULL, 0);
