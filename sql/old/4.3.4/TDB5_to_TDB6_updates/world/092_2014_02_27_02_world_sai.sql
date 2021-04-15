--
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(2711300,2711400, 2711500) and`source_type`=9 and`id`=4 and`action_type`=32;
UPDATE `smart_scripts` SET `id`=4, `event_param1`=3000, `event_param2`=3000, `event_param3`=3000, `event_param4`=3000 WHERE `entryorguid` IN(2711300,2711400, 2711500) and`source_type`=9 and`id`=5;

UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI', `ScriptName`='' WHERE  `entry`=188554;
DELETE FROM `smart_scripts` WHERE `source_type`=1 AND `entryorguid`=188554;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=18855400;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(188554, 1, 0 ,0, 70, 0, 100, 0, 2, 0, 0,0,80,18855400,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Dun Argol Cage - On State Changed  - Run Script'),
(18855400, 9, 0 ,0, 0, 0, 100, 0, 15000, 15000, 0,0,32,0,0,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Dun Argol Cage - Script - Reset GO');
