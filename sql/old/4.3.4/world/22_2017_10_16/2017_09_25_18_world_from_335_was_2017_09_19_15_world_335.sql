/*
DELETE FROM `smart_scripts` WHERE `entryorguid` =3144 and `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3144, 0, 2, 0,64,  0, 100, 0, 0, 0, 0, 0, 98, 21319, 3580, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Eitrigg - On Gossip Hello - Send Gossip');



DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=3144;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,3,3144,0,0,9,0,4941,0,0,0,0,'','Gossip only if player is on and has not completed Eitrigg''s Wisdom');
*/
