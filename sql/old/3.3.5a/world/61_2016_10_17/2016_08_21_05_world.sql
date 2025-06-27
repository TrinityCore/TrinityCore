-- 
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (25686,25684,25699,25701);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25686,25701,25684,25699) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
-- DB/Creature: Add missing SAI Gorloc Gibberer and Gorloc Dredger
(25686, 0, 0, 0, 0, 0, 100, 0, 0, 4000, 4000, 6000, 11, 50520, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gorloc Gibberer - In Combat - Cast \'Deep Dredge\''),
(25701, 0, 0, 0, 0, 0, 100, 0, 0, 4000, 4000, 6000, 11, 50520, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gorloc Dredger - In Combat - Cast \'Deep Dredge\''),
-- DB/Creature: Add missing SAI Talramas Abomination
(25684, 0, 0, 0, 0, 0, 100, 0, 0, 2000, 20000, 20000, 11, 50366, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Talramas Abomination - In Combat - Cast \'Plague Cloud\''),
-- DB/Creature: Add missing SAI Gorloc Mud Splasher
(25699, 0, 0, 0, 0, 0, 100, 0, 0, 2000, 12000, 20000, 11, 50522, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Gorloc Mud Splasher - In Combat - Cast \'Gorloc Stomp\'');
