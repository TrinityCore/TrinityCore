/*
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI', `ScriptName`='' WHERE  `entry`=177673;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` =12369;

DELETE FROM `smart_scripts` WHERE `entryorguid` =177673 AND `source_type`=1 OR `entryorguid`=17767300 AND `source_type`=9 OR `entryorguid`=12369 AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(177673, 1, 0 ,1, 70, 0, 100, 0, 2, 0, 0,0,80,17767300,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Serpent Statue - On State Changed - Run Script'),
(17767300, 9, 0 ,0, 0, 0, 100, 0, 5000, 5000, 0,0,12,12369,1,180000,0,0,0,8,0,0,0,254.166855,2966.883545,1.367331,0.957399, 'Serpent Statue - Script - Spawn Lord Kragaru'),
(17767300, 9, 1 ,0, 0, 0, 100, 0, 185000, 185000, 0,0,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Serpent Statue - Script - Reset Go'),
(12369, 0, 0 ,0, 9, 0, 100, 0, 0, 5, 3000,4000,11,15496,0,0,0,0,0,7,0,0,0,0, 0, 0, 0, 'Lord Kragaru - On Range - Cast Cleave'),
(12369, 0, 1 ,0, 13, 0, 100, 0, 10000, 15000, 0,0,11,12555,0,0,0,0,0,7,0,0,0,0, 0, 0, 0, 'Lord Kragaru - On Target Casting - Cast Pummel');
*/
