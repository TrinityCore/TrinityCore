SET @PATH:= 137969 * 10;

DELETE FROM `waypoint_data` WHERE `id` = @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1 , 117.894, -560.9407, 107.8397, 0, 0, 1, 0, 100, 0),
(@PATH, 2 , 104.644, -557.4407, 108.0897, 0, 0, 1, 0, 100, 0),
(@PATH, 3 , 99.9641, -555.8882, 109.5087, 0, 0, 1, 0, 100, 0),
(@PATH, 4 , 96.7141, -554.3882, 110.7587, 0, 0, 1, 0, 100, 0),
(@PATH, 5 , 95.2141, -553.8882, 110.7587, 0, 0, 1, 0, 100, 0),
(@PATH, 6 , 91.2141, -552.1382, 110.7587, 0, 0, 1, 0, 100, 0),
(@PATH, 7 , 89.7141, -551.3882, 111.0087, 0, 0, 1, 0, 100, 0),
(@PATH, 8 , 87.9641, -550.6382, 111.0087, 0, 0, 1, 0, 100, 0),
(@PATH, 9 , 89.5555, -551.2523, 111.0189, 0, 0, 1, 0, 100, 0),
(@PATH, 10, 87.8055, -550.5023, 111.0189, 0, 0, 1, 0, 100, 0),
(@PATH, 11, 82.5555, -548.2523, 111.0189, 0, 0, 1, 0, 100, 0),
(@PATH, 12, 55.5090, -534.9372, 110.9415, 0, 0, 1, 0, 100, 0),
(@PATH, 13, 27.8879, -513.8772, 110.9468, 0, 0, 1, 0, 100, 0),
(@PATH, 14, 17.0559, -545.8477, 110.9305, 0, 0, 1, 0, 100, 0),
(@PATH, 15, 74.8466, -549.6145, 110.9279, 0, 0, 1, 0, 100, 0),
(@PATH, 16, 70.5093, -524.7200, 110.9333, 0, 0, 1, 0, 100, 0),
(@PATH, 17, 78.7893, -549.1487, 110.9274, 0, 0, 1, 0, 100, 0);

DELETE FROM `areatrigger_scripts` WHERE `entry` IN (2066, 2067);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(2066, 'at_trigger_the_beast_movement'),
(2067, 'at_the_beast_room');

DELETE FROM `creature_text` WHERE `CreatureID` IN (10317, 10776);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(10317, 0, 0, "We're doomed!", 14, 0, 100, 0, 0, 0, 5622, 0, 'Blackhand elite'),
(10776, 0, 0, "Leaping leper gnomes! I've been stuck in there for months. Thanks, gang.", 12, 0, 100, 0, 0, 0, 6066, 0, 'Finkle Einhorn');

-- Its not perm spawn, its dynamic depending if the beast has been skinned or not
DELETE FROM `creature` WHERE `guid` = 42637;
