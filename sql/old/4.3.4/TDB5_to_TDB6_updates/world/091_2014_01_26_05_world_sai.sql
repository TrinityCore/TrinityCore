--
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`= 29978;

DELETE FROM `smart_scripts` WHERE `entryorguid`=29978;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(29978, 0, 0, 0, 6, 0, 100, 0, 0, 0, 0, 0, 33, 30297, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Iron Dwarf Assailant - On Death - Give Kill credit');

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`= 29984;

DELETE FROM `smart_scripts` WHERE `entryorguid`=29984;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(29984, 0, 0, 0, 6, 0, 100, 0, 0, 0, 0, 0, 33, 30296, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Iron Sentinel <Servant of Loken> - On Death - Give Kill credit'),
(29984, 0, 1, 0, 9, 0, 100, 0, 0,10, 12000, 24000, 11, 56490, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Iron Sentinel <Servant of Loken> - On Range - Cast Stomp'),
(29984, 0, 2, 0, 0, 0, 100, 0, 0, 3000, 5000, 8000, 11, 55811, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Iron Sentinel <Servant of Loken> - IC - Cast Throw Bolder'),
(29984, 0, 3, 0, 9, 0, 100, 0, 0, 5, 5000, 7000, 11, 5568, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Iron Sentinel <Servant of Loken> - IC - Cast Trample');
