UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI',`ScriptName`='' WHERE `entry`=111148;
DELETE FROM `smart_scripts` WHERE `source_type`=1 AND `entryorguid`=111148;

INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(111148,1,1,0,1,0,100,0,0,0,1000,1000,45,1,1,0,0,0,0,19,2164,5,0,0,0,0,0, 'Night Elven Bear Trap - OOC - Set Data closest Rabid Thistle Bear ');

DELETE FROM `smart_scripts` WHERE `entryorguid`=2164 AND `source_type`=0  AND `id`>0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=216400 AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(2164, 0, 1, 0, 38, 0, 100, 1, 1, 1, 0, 0, 80, 216400, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rabid Thistle Bear - On Data Set - Run Script (No repeat)'),
(2164, 0, 2, 0, 4, 0, 100, 0, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Rabid Thistle Bear - On Agro store targetlist'),
(216400, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rabid Thistle Bear - Script - Evade'),
(216400, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 33, 11836, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Rabid Thistle Bear - Script - Kill Credit'),
(216400, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 29, 0, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Rabid Thistle Bear - Script - Follow Target'),
(216400, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 36, 11836, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rabid Thistle Bear - Script - Change Entry to Captured Rabid Thistle Bear'),
(216400, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 120000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rabid Thistle Bear - Script - Follow Target');
