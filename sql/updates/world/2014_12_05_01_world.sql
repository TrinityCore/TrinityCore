UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` =23720;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI', `ScriptName`='' WHERE  `entry`=186287;

DELETE FROM `smart_scripts` WHERE `entryorguid`=186287  AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23720  AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=18628700  AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(186287, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Blackhoof Cage - On State Changed - Store Targetlist'),
(186287, 1, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 18628700, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Blackhoof Cage - On State Changed - Run Script'),
(23720, 0, 0, 1, 38, 0, 100, 0, 1, 1, 0, 0, 1, 0, 2000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Theramore Prisoner - On Data Set - Say'),
(23720, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 33, 23720, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Theramore Prisoner - Linked with Previous Event - Give Kill Credit'),
(23720, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 5000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Theramore Prisoner - Linked with Previous Event - Despawn after 5 seconds'),
(23720, 0, 3, 0, 52, 0, 100, 0, 0, 23720, 0, 0, 46, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Theramore Prisoner - Linked with Previous Event - Move Foward'),
(18628700, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 9, 23720, 0, 5, 0, 0, 0, 0, 'Blackhoof Cage - Script - Send Targetlist to Theramore Prisoner'),
(18628700, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 9, 23720, 0, 5, 0, 0, 0, 0, 'Blackhoof Cage - Script - Set Data'),
(18628700, 9, 2, 0, 0, 0, 100, 0, 430000, 430000, 0, 0, 32, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Blackhoof Cage - Script - Reset Go');
