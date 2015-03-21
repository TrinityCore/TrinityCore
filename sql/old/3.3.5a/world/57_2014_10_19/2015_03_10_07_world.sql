--
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (4331, 4329);
DELETE FROM `smart_scripts` WHERE `entryorguid`= 4328 AND `source_type`=0 AND `id` IN (3);
DELETE FROM `smart_scripts` WHERE `entryorguid`= 4331 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`= 4329 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4328, 0, 3, 0, 8, 0, 100, 0, 42411, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Firemane Scalebane - On spell hit  - Despawn'),
(4331, 0, 0, 0, 8, 0, 100, 0, 42411, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Firemane Ash Tail - On spell hit  - Despawn'),
(4331, 0, 1, 0, 0, 0, 100, 0, 4000, 6000, 6000, 8000, 11, 11969, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Firemane Ash Tail - Icc  - Cast Fire Nova'),
(4331, 0, 2, 0, 4, 0, 100, 0, 0, 0, 0, 0, 11, 18968, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Firemane Ash Tail - On aggr  - cast Fire Shield'),
(4329, 0, 0, 0, 8, 0, 100, 0, 42411, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Firemane Scout - On spell hit  - Despawn'),
(4329, 0, 1, 0, 4, 0, 100, 0, 0, 0, 0, 0, 11, 18968, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Firemane Scout - On aggr  - cast Fire Shield');
