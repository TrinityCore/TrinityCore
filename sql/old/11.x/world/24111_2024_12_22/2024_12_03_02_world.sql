SET @CGUID := 10004652;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 224710, 2552, 14717, 14788, '0', 0, 0, 0, 0, 1600.611083984375, -2244.0400390625, 26.4508819580078125, 1.743003726005554199, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689); -- Kix'arak (Area: The Opalcreg - Difficulty: 0) CreateObject2

UPDATE `creature_template_difficulty` SET `GoldMin` = 22000, `GoldMax` = 30000 WHERE `Entry` = 224710;

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` = 224710;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(224710, 0, 0, 'For The Queen!', 12, 0, 100, 0, 0, 0, 0, 0, 'Kix\'arak to Player'),
(224710, 1, 0, 'All... Our... Plans...', 12, 0, 100, 0, 0, 0, 0, 0, 'Kix\'arak to Player');

-- Quest
DELETE FROM `creature_queststarter` WHERE (`id`=224708 AND `quest`=82801);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(224708, 82801, 57689); -- Beetlejeweled offered by Cenderragg

DELETE FROM `creature_questender` WHERE (`id`=218535 AND `quest` = 82801);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(218535, 82801, 57689); -- Beetlejeweled ended by Germira

DELETE FROM `quest_template_addon` WHERE `ID` = 82801;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(82801, 0, 0, 0, 82800, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- Beetlejeweled

-- Kix'arak smart ai
SET @ENTRY := 224710;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On aggro - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On death - Self: Talk 1 to invoker', ''),
(@ENTRY, 0, 2, 0, 0, 0, 100, 0, 4000, 6000, 8000, 12000, 0, 11, 448549, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 8 - 12 seconds (4 - 6s initially) (IC) - Self: Cast spell  448549 on Victim', ''),
(@ENTRY, 0, 3, 0, 0, 0, 100, 0, 14000, 18000, 22000, 26000, 0, 11, 432127, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 22 - 26 seconds (14 - 18s initially) (IC) - Self: Cast spell  432127 on Self', '');

-- Path for Kixarak
SET @MOVERGUID := @CGUID+0;
SET @ENTRY := 224710;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Kix\'arak - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1629.967, -2215.054, 18.494781, NULL, 0),
(@PATH, 1, 1637.566, -2208.9307, 16.840057, NULL, 0),
(@PATH, 2, 1647.2726, -2202.2812, 14.86443, NULL, 0),
(@PATH, 3, 1660.7379, -2202.8508, 13.917351, NULL, 0),
(@PATH, 4, 1673.3073, -2204.2605, 13.463098, NULL, 0),
(@PATH, 5, 1686.2587, -2207.2864, 13.45392, NULL, 0),
(@PATH, 6, 1697.8351, -2207.467, 12.939968, NULL, 0),
(@PATH, 7, 1702.7726, -2209.1545, 12.505653, NULL, 0),
(@PATH, 8, 1697.7396, -2207.236, 12.963745, NULL, 0),
(@PATH, 9, 1686.0885, -2206.7344, 13.45141, NULL, 0),
(@PATH, 10, 1673.6892, -2204.0227, 13.463442, NULL, 0),
(@PATH, 11, 1660.9098, -2202.592, 13.9051, NULL, 0),
(@PATH, 12, 1647.4601, -2202.2744, 14.836533, NULL, 0),
(@PATH, 13, 1638.6423, -2206.6824, 16.531567, NULL, 0),
(@PATH, 14, 1637.4202, -2209.1633, 16.889801, NULL, 0),
(@PATH, 15, 1629.4774, -2214.3994, 18.596039, NULL, 0),
(@PATH, 16, 1615.9688, -2224.375, 22.299618, NULL, 0),
(@PATH, 17, 1604.2048, -2235.2327, 25.067307, NULL, 0),
(@PATH, 18, 1598.5608, -2245.934, 25.06629, NULL, 0),
(@PATH, 19, 1617.6702, -2225.6528, 22.119532, NULL, 0);

UPDATE `creature` SET `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
