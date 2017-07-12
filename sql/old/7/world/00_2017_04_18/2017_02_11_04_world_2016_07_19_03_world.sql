-- 
DELETE FROM `smart_scripts` WHERE `entryorguid`=11443 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11443, 0, 0, 0, 4, 0, 50, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Gordok Ogre-Mage - On Aggro - Say Line 0"),
(11443, 0, 1, 0, 9, 0, 100, 0, 0, 40, 2400, 3800, 11, 20823, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Gordok Ogre-Mage - Between 0-40 Range - Cast 20823"),
(11443, 0, 2, 0, 0, 0, 100, 0, 5000, 12000, 35000, 45000, 11, 6742, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gordok Ogre-Mage - In Combat - Cast 6742");
