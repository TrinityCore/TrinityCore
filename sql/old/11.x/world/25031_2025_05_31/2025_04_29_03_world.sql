-- Template
UPDATE `creature_template` SET `npcflag`=16777216 WHERE `entry`=124844; -- Trevor Hightide
UPDATE `creature_template` SET `npcflag`=16777216 WHERE `entry`=129488; -- Travis Daybreak
UPDATE `creature_template` SET `npcflag`=16777216 WHERE `entry`=129489; -- Kyle Sailford
UPDATE `creature_template` SET `npcflag`=16777216 WHERE `entry`=129490; -- Burke Stevenson

-- Spawntracking
DELETE FROM `spawn_tracking_quest_objective` WHERE `QuestObjectiveId` IN (291211,294652,294651,294650);
INSERT INTO `spawn_tracking_quest_objective` (`SpawnTrackingId`, `QuestObjectiveId`, `VerifiedBuild`) VALUES
(1408802,291211,60257), -- Trevor Hightide
(1408806,294652,60257), -- Burke Stevenson
(1408805,294651,60257), -- Kyle Sailford
(1408804,294650,60257); -- Travis Daybreak

DELETE FROM `spawn_tracking` WHERE (`SpawnType`=0 AND `SpawnId` IN (7002627,7002641,7002609,7002650));
INSERT INTO `spawn_tracking` (`SpawnTrackingId`, `SpawnType`, `SpawnId`, `QuestObjectiveId`) VALUES
(1408802, 0, 7002627, 291211), -- Trevor Hightide
(1408806, 0, 7002641, 294652), -- Burke Stevenson
(1408805, 0, 7002609, 294651), -- Kyle Sailford
(1408804, 0, 7002650, 294650); -- Travis Daybreak

DELETE FROM `spawn_tracking_state` WHERE (`SpawnType`=0 AND `SpawnId` IN (7002627,7002641,7002609,7002650));
INSERT INTO `spawn_tracking_state` (`SpawnType`, `SpawnId`, `State`, `Visible`, `StateSpellVisualId`, `StateAnimId`, `StateAnimKitId`, `StateWorldEffects`) VALUES
(0, 7002627, 0, 1, NULL, NULL, NULL, NULL), -- Trevor Hightide
(0, 7002627, 1, 1, NULL, NULL, NULL, NULL), -- Trevor Hightide
(0, 7002627, 2, 0, NULL, NULL, NULL, NULL), -- Trevor Hightide
(0, 7002641, 0, 1, NULL, NULL, NULL, NULL), -- Burke Stevenson
(0, 7002641, 1, 1, NULL, NULL, NULL, NULL), -- Burke Stevenson
(0, 7002641, 2, 0, NULL, NULL, NULL, NULL), -- Burke Stevenson
(0, 7002609, 0, 1, NULL, NULL, NULL, NULL), -- Kyle Sailford
(0, 7002609, 1, 1, NULL, NULL, NULL, NULL), -- Kyle Sailford
(0, 7002609, 2, 0, NULL, NULL, NULL, NULL), -- Kyle Sailford
(0, 7002650, 0, 1, NULL, NULL, NULL, NULL), -- Travis Daybreak
(0, 7002650, 1, 1, NULL, NULL, NULL, NULL), -- Travis Daybreak
(0, 7002650, 2, 0, NULL, NULL, NULL, NULL); -- Travis Daybreak

-- Spellclick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (124844,129488,129489,129490);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(124844, 254972, 1, 0),
(129488, 254972, 1, 0),
(129489, 254972, 1, 0),
(129490, 254972, 1, 0);

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 18) AND (`SourceGroup` IN (124844,129488,129489,129490));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(18, 124844, 254972, 0, 0, 47, 0, 47946, 8, 0, '', 0, 'Clicker has Save Their Bacon (47946) in state incomplete'),
(18, 129488, 254972, 0, 0, 47, 0, 47946, 8, 0, '', 0, 'Clicker has Save Their Bacon (47946) in state incomplete'),
(18, 129489, 254972, 0, 0, 47, 0, 47946, 8, 0, '', 0, 'Clicker has Save Their Bacon (47946) in state incomplete'),
(18, 129490, 254972, 0, 0, 47, 0, 47946, 8, 0, '', 0, 'Clicker has Save Their Bacon (47946) in state incomplete');

-- Trevor Hightide smart ai
SET @ENTRY := 124844;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 11, 254963, 0, 0, 0, 0, 0, 0, 19, 128475, 5, 0, 0, 0, 0, 0, 'On reset - Self: Cast spell  254963 on Closest alive creature Post Bunny (128475) in 5 yards', ''),
(@ENTRY, 0, 1, 0, 8, 0, 100, 0, 254972, 0, 0, 0, 0, 80, 12484400, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spell  254972 hit - Self: Start timed action list id #Trevor Hightide #0 (12484400) (update out of combat)', ''),
(@ENTRY, 0, 2, 0, 34, 0, 100, 0, 2, 29, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 29 - Self: Despawn in 1 s', '');

-- Burke Stevenson smart ai
SET @ENTRY := 129490;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 11, 254963, 0, 0, 0, 0, 0, 0, 19, 128475, 5, 0, 0, 0, 0, 0, 'On reset - Self: Cast spell  254963 on Closest alive creature Post Bunny (128475) in 5 yards', ''),
(@ENTRY, 0, 1, 0, 8, 0, 100, 0, 254972, 0, 0, 0, 0, 80, 12949000, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spell  254972 hit - Self: Start timed action list id #Burke Stevenson #0 (12949000) (update out of combat)', ''),
(@ENTRY, 0, 2, 0, 34, 0, 100, 0, 2, 6, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 6 - Self: Despawn in 1 s', '');

-- Travis Daybreak smart ai
SET @ENTRY := 129488;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 11, 254963, 0, 0, 0, 0, 0, 0, 19, 128475, 5, 0, 0, 0, 0, 0, 'On reset - Self: Cast spell  254963 on Closest alive creature Post Bunny (128475) in 5 yards', ''),
(@ENTRY, 0, 1, 0, 8, 0, 100, 0, 254972, 0, 0, 0, 0, 80, 12948800, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spell  254972 hit - Self: Start timed action list id #Travis Daybreak #0 (12948800) (update out of combat)', ''),
(@ENTRY, 0, 2, 0, 34, 0, 100, 0, 2, 3, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 3 - Self: Despawn in 1 s', '');

-- Kyle Sailford smart ai
SET @ENTRY := 129489;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 11, 254963, 0, 0, 0, 0, 0, 0, 19, 128475, 5, 0, 0, 0, 0, 0, 'On reset - Self: Cast spell  254963 on Closest alive creature Post Bunny (128475) in 5 yards', ''),
(@ENTRY, 0, 1, 0, 8, 0, 100, 0, 254972, 0, 0, 0, 0, 80, 12948900, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spell  254972 hit - Self: Start timed action list id #Kyle Sailford #0 (12948900) (update out of combat)', ''),
(@ENTRY, 0, 2, 0, 34, 0, 100, 0, 2, 5, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 3 - Self: Despawn in 1 s', '');

-- Timed list 12484400 smart ai
SET @ENTRY := 12484400;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 149, 8, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Become personal clone for Last action invoker for 0 seconds (manual despawn)', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 92, 0, 254963, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Interrupt casted spell  254963', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 33, 124844, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Owner/Summoner: Give kill credit Trevor Hightide (124844)', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 53, 0, 12484400, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Start path #12484400, walk, do not repeat, Passive', '');

-- Timed list 12949000 smart ai
SET @ENTRY := 12949000;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 149, 8, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Become personal clone for Last action invoker for 0 seconds (manual despawn)', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 92, 0, 254963, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Interrupt casted spell  254963', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 33, 129490, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Owner/Summoner: Give kill credit Burke Stevenson (129490)', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 53, 0, 12949000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Start path #12949000, walk, do not repeat, Passive', '');

-- Timed list 12948800 smart ai
SET @ENTRY := 12948800;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 149, 8, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Become personal clone for Last action invoker for 0 seconds (manual despawn)', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 92, 0, 254963, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Interrupt casted spell  254963', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 33, 129488, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Owner/Summoner: Give kill credit Travis Daybreak (129488)', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 53, 0, 12948800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Start path #12949000, walk, do not repeat, Passive', '');

-- Timed list 12948900 smart ai
SET @ENTRY := 12948900;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 149, 8, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Become personal clone for Last action invoker for 0 seconds (manual despawn)', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 92, 0, 254963, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Interrupt casted spell  254963', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 33, 129489, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Owner/Summoner: Give kill credit Kyle Sailford (129489)', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 53, 0, 12948900, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Start path #12948900, walk, do not repeat, Passive', '');

-- Stockyard Pig smart ai
SET @ENTRY := 129501;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 11, 254963, 0, 0, 0, 0, 0, 0, 19, 128475, 5, 0, 0, 0, 0, 0, 'On reset - Self: Cast spell  254963 on Closest alive creature Post Bunny (128475) in 5 yards', '');

UPDATE `creature` SET `StringID` = 'TiedUp' WHERE `guid` IN (7002648, 7002649, 7002654, 7002653, 7002647, 7002652, 7002651, 7002626, 7002620, 7002623, 7002610, 7002612, 7002613, 7002615, 7002616, 7002622, 7002640, 7002639);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 129501 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 129501, 0, 0, 58, 1, 0, 0, 0, 'TiedUp', 0, 'Object has StringID TiedUp');

-- Spelltarget cond.
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 13) AND (`SourceEntry` IN (254963));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(13, 1, 254963, 0, 0, 51, 0, 5, 128475, 0, '', 0, 'Potential target of the spell is TYPEID_UNIT, entry is 128475');

-- Path for Trevor Hightide
SET @ENTRY := 124844;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Trevor Hightide - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 179.51567, 1647.1112, 6.841958, NULL, 0),
(@PATH, 1, 180.33203, 1647.6875, 7.1293483, NULL, 0),
(@PATH, 2, 181.14844, 1648.2637, 7.296534, NULL, 0),
(@PATH, 3, 181.96484, 1648.8398, 7.4833827, NULL, 0),
(@PATH, 4, 182.78125, 1649.416, 7.8168244, NULL, 0),
(@PATH, 5, 183.59766, 1649.9922, 8.059791, NULL, 0),
(@PATH, 6, 184.41406, 1650.5684, 8.238252, NULL, 0),
(@PATH, 7, 186.04688, 1651.7207, 8.500779, NULL, 0),
(@PATH, 8, 186.86328, 1652.2969, 8.767218, NULL, 0),
(@PATH, 9, 188.4961, 1653.4492, 8.993593, NULL, 0),
(@PATH, 10, 190.1289, 1654.6016, 9.50076, NULL, 0),
(@PATH, 11, 191.76172, 1655.7539, 10.104084, NULL, 0),
(@PATH, 12, 192.57812, 1656.3301, 10.329568, NULL, 0),
(@PATH, 13, 193.39453, 1656.9062, 10.63672, NULL, 0),
(@PATH, 14, 194.21094, 1657.4824, 11.111256, NULL, 0),
(@PATH, 15, 195.02734, 1658.0586, 11.389358, NULL, 0),
(@PATH, 16, 195.84375, 1658.6348, 11.835064, NULL, 0),
(@PATH, 17, 197.47656, 1659.7871, 12.251947, NULL, 0),
(@PATH, 18, 198.29297, 1660.3633, 12.47695, NULL, 0),
(@PATH, 19, 199.10938, 1660.9395, 12.965077, NULL, 0),
(@PATH, 20, 200.05675, 1661.602, 13.256961, NULL, 0),
(@PATH, 21, 200.05664, 1661.6016, 13.473705, NULL, 0),
(@PATH, 22, 201.54102, 1662.9395, 13.859058, NULL, 0),
(@PATH, 23, 202.2832, 1663.6084, 14.203736, NULL, 0),
(@PATH, 24, 203.76758, 1664.9463, 14.530555, NULL, 0),
(@PATH, 25, 204.50977, 1665.6152, 14.702534, NULL, 0),
(@PATH, 26, 205.99414, 1666.9531, 14.876009, NULL, 0),
(@PATH, 27, 208.2207, 1668.96, 15.206219, NULL, 0),
(@PATH, 28, 208.94774, 1669.607, 15.339778, NULL, 0),
(@PATH, 29, 209.69966, 1669.7396, 15.456769, NULL, 0),
(@PATH, 30, 214.62372, 1670.6078, 16.671051, NULL, 0);

-- Path for Burke Stevenson
SET @ENTRY := 129490;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Burke Stevenson - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 105.863686, 1647.7869, 0.8748083, NULL, 0),
(@PATH, 1, 132.90143, 1645.1799, 0.9134677, NULL, 0),
(@PATH, 2, 155.01024, 1639.2227, 2.5800915, NULL, 0),
(@PATH, 3, 179.05045, 1648.4126, 6.9647055, NULL, 0),
(@PATH, 4, 199.23608, 1662.6313, 13.2694845, NULL, 0),
(@PATH, 5, 208.06699, 1670.5853, 15.406095, NULL, 0),
(@PATH, 6, 209.69966, 1669.7396, 15.456769, NULL, 0),
(@PATH, 7, 214.1394, 1667.44, 15.70382, NULL, 0);

-- Path for Travis Daybreak
SET @ENTRY := 129488;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Travis Daybreak - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 180.64163, 1645.4121, 6.9091005, NULL, 0),
(@PATH, 1, 201.35342, 1659.9757, 13.277277, NULL, 0),
(@PATH, 2, 210.2832, 1668.0029, 15.265754, NULL, 0),
(@PATH, 3, 209.69966, 1669.7396, 15.456769, NULL, 0),
(@PATH, 4, 208.10712, 1674.4792, 16.2329, NULL, 0);

-- Path for Kyle Sailford
SET @ENTRY := 129489;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Kyle Sailford - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 148.5238, 1617.0015, 2.023156, NULL, 0),
(@PATH, 1, 156.31923, 1636.1978, 2.492858, NULL, 0),
(@PATH, 2, 180.69336, 1645.2871, 6.9135194, NULL, 0),
(@PATH, 3, 201.44218, 1659.8644, 13.278393, NULL, 0),
(@PATH, 4, 210.3711, 1667.8916, 15.265754, NULL, 0),
(@PATH, 5, 209.69966, 1669.7396, 15.456769, NULL, 0),
(@PATH, 6, 207.99023, 1674.4365, 16.199602, NULL, 0);
