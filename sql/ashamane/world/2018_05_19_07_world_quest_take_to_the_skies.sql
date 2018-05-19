DELETE FROM `smart_scripts` WHERE `entryorguid` IN (37915,3791500);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(37915, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Timothy Cunningham - On Aggro - Say Line 0'),
(37915, 0, 1, 0, 4, 0, 100, 0, 0, 0, 0, 0, '', 11, 14252, 4, 30000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Timothy Cunningham - On Aggro - Summon Enraged Felbat'),
(37915, 0, 2, 0, 62, 0, 100, 0, 11152, 0, 0, 0, '', 80, 3791500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Timothy Cunningham - On Gossip Select - Actionlist'),
(3791500, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, '', 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Timothy Cunningham - Close Gossip'),
(3791500, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, '', 11, 73442, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Timothy Cunningham - Cast Bulwark to Brill');

DELETE FROM `conditions` WHERE `SourceGroup`=11152;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 11152, 1, 0, 0, 9, 0, 25012, 0, 0, 0, 0, 0, '', 'Show Gossip when quest 25012 is taken');

