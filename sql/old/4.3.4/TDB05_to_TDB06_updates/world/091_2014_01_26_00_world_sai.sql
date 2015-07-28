--
DELETE FROM `smart_scripts` WHERE `entryorguid`=24601 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24601, 0, 2, 0, 6, 0, 100, 0, 0, 0, 0, 0, 33, 25987, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Steam Rager - On Death - Kill Credit');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` =24601;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,3,24601,0,0,1,1,46374,0,0,0,0,'','Windsoul Totem Credit only if aura present at death');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=46374;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,46374,0,0,31,0,3,24601,0,0,0,0,'','Windsoul Totem Aura targets only Steam Rager'),
(13,1,46374,0,0,36,0,0,0,0,0,0,0,'','Windsoul Totem Aura targets only alive units');
