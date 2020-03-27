
-- lock dark portal
INSERT INTO `gameobject` VALUES (170001,190784,0,0,0,1,1,-11903.8,-3208.54,-14.8329,3.33511,0,0,-0.995323,0.096606,300,255,1,'',0),
(170002,190397,530,0,0,1,1,-194.587,935.59,79.1522,1.67191,-0,-0,-0.741936,-0.67047,300,255,1,'',0),
(170003,190397,530,0,0,1,1,-215.396,934.476,84.3797,1.82506,-0,-0,-0.791054,-0.611746,300,255,1,'',0),
(170004,190397,530,0,0,1,1,-248.109,934.191,84.3798,1.53446,-0,-0,-0.694143,-0.719837,300,255,1,'',0),
(170005,190397,530,0,0,1,1,-282.082,933.293,84.3783,1.56981,-0,-0,-0.706756,-0.707457,300,255,1,'',0),
(170006,190397,530,0,0,1,1,-301.608,933.736,79.5579,1.64834,-0,-0,-0.733986,-0.679165,300,255,1,'',0);

DELETE FROM `areatrigger_teleport` WHERE  `ID`=4354;
DELETE FROM `areatrigger_scripts` WHERE  `entry`=4354;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(4354, 'SmartTrigger');

DELETE FROM `smart_scripts` WHERE `entryorguid`=4354 AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4354, 2, 0, 0, 46, 0, 100, 0, 4354, 0, 0, 0, 0, 62, 530, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, -248.149, 921.875, 84.3885, 1.58415, 'Areatrigger - On Trigger - Teleport Player');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=4354 AND `SourceId`=2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 4354, 2, 0, 27, 0, 60, 1, 0, 0, 0, 0, '', 'SAI areatrigger 4354 triggers only if player level is higher than 60');
