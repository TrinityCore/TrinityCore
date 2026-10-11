 -- Dori'thur smart ai
SET @ENTRY := 152000;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 19, 0, 100, 0, 53847, 0, 0, 0, 0, 80, 15200000, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest On Whispered Winds (53847) - Self: Start timed action list id #Dori\'thur #0 (15200000) (update out of combat)', '');

-- Timed list 15200000 smart ai
SET @ENTRY := 15200000;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 149, 8, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Become personal clone for Last action invoker for 0 seconds (manual despawn)', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 53, 0, 15200000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Start path #15200000, walk, do not repeat, Passive', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 20000, 20000, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 20 seconds - Self: Despawn instantly', '');

-- Path for Dorithur
SET @ENTRY := 152000;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Dori''thur - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1011.7518, -532.82117, 17.748726, NULL, 0),
(@PATH, 1, 1001.0643, -528.4427, 20.407505, NULL, 0),
(@PATH, 2, 988.2969, -523.7031, 27.573282, NULL, 0),
(@PATH, 3, 943.97186, -507.2486, 64.51297, NULL, 0);
