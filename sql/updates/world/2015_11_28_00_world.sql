--
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (22268, 22460);
UPDATE `gameobject` SET `position_z`=-16.9 WHERE `guid`=99984 AND `id`= 185307;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `Entry` IN (22268, 22460);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (22268, 22460) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2226800, 2246000) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(22460, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, 2246000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spirit  - Just summoned - action list'),
(2246000, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 3672.275635, 5286.437988, 20.585167, 5.40622, 'Spirit  - action list - move to pos'),
(2246000, 9, 1, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 3672.275635, 5286.437988, 20.585167, 5.40622, 'Spirit  - action list - Set Orientation'),
(2246000, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 9, 0, 0, 0, 0, 0, 0, 20, 185296, 20, 0, 0, 0, 0, 0, 'Spirit  - action list - Activate object'),
(2246000, 9, 3, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 45, 0, 1, 0, 0, 0, 0, 19, 22268, 20, 0, 0, 0, 0, 0, 'Spirit  - action list - Set data'),
(2246000, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spirit  - action list - Despawn'),
(22268, 0, 0, 0, 38, 0, 100, 0, 0, 1, 0, 0, 80, 2226800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Leok  - On data set - action list'),
(2226800, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 3638.89575, 5343.02978, 23.28319, 2.086646, 'Leok  - action list - Move to pos'),
(2226800, 9, 1, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Leok  - action list - Despawn');
