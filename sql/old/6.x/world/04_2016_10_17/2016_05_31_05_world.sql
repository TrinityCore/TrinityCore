-- Scorpion SmartScript
DELETE FROM smart_scripts WHERE entryorguid = 3125 AND source_type = 0;
INSERT INTO smart_scripts (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) 
VALUES
(3125,0,0,0,0,0,100,0,4000,4500,32000,38000,11,79687,0,0,0,0,0,2,0,0,0,0,0,0,0,'Clattering Scorpid - In Combat - Cast \Poison\ (No Repeat)'),
(3125,0,1,0,0,0,100,0,2000,9000,15000,24000,11,73672,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Envenom'),
(3125,0,2,0,31,0,100,0,73672,0,0,0,33,39236,0,0,0,0,0,2,0,0,0,0,0,0,0,'Give Credit on Totem Aura');

-- Condition to give credit
DELETE FROM conditions WHERE Sourceentry = 3125 AND SourceTypeOrReferenceId = 22;
INSERT INTO conditions (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) 
VALUES
(22,3,3125,0,0,1,0,73673,1,0,0,0,0,'','SAI - Give kill credit when Aura');
