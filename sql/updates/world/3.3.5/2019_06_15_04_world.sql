DELETE FROM `smart_scripts` WHERE `entryorguid`=23728 AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2372801 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23728,0,1,0,62,0,100,0,8984,0,0,0,0,80,2372801,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guard Captain Zorek - On Quest Accepted - Action list'"),
(2372801,9,0,0,0,0,100,0,0,0,0,0,0,85,49845,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Guard Captain Zorek - Action list - Cast 'Valgarde Gryphon'"),
(2372801,9,1,0,0,0,100,0,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Guard Captain Zorek - Action list - Close gossip");

SET @GRYPHON:= 27886;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN(@GRYPHON);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 1, @GRYPHON, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Valgarde Gryphon - Only run SAI if invoker is player'),
(22, 7, @GRYPHON, 0, 0, 1, 1, 46598, 0, 0, 1, 0, 0, '', 'Valgarde Gryphon - Only run SAI no aura 46598');
