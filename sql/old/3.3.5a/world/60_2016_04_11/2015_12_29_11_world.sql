-- 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=58563;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,58563,0,0,31,1,3,30951,0,0,0,0,'',"Assassinate Restless Lookout can be used only on Restless lookout");

DELETE FROM `creature_template_addon` WHERE `entry`=31110;
INSERT INTO `creature_template_addon` (`entry`,`auras`) VALUES (31110,'58548');
 
DELETE FROM `smart_scripts` WHERE  `entryorguid`=3095200 AND `id`>3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(3095200, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 45787, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hungering Plaguehound -  Script - Cast Sleeping Sleep'),
(3095200, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hungering Plaguehound -  Script - React passif'),
(3095200, 9, 6, 0, 0, 0, 100, 0, 15000, 15000, 0, 0, 28, 45787, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hungering Plaguehound - Script -  Remove Aura Sleeping Sleep'),
(3095200, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hungering Plaguehound -  Script - Agressif'),
(3095200, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 89, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hungering Plaguehound - Script -  Enable Random Move');

UPDATE `smart_scripts` SET `action_param2`=2 WHERE  `entryorguid`=30952 AND `source_type`=0 AND `id`=0 AND `link`=0;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=30952;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 1, 30952, 0, 0, 1, 1, 45787, 0, 0, 1, 0, 0, '', 'Only run SAI if unit does not have aura sleeping sleep');
