--
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` IN(18849,19008);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (18849,19008);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(18849, 0, 0, 0, 8,  0, 100, 0, 33067, 0, 0, 0, 33, 18849   , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Invis Alliance Siege Engine - East - On Spellhit - Kill Credit'),
(19008, 0, 0, 0, 8,  0, 100, 0, 33067, 0, 0, 0, 33, 19008   , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Invis Alliance Siege Engine - West - On Spellhit - Kill Credit');

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` IN(15941,15945,28352,28064,28304,28305);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(15941,15945,28352,28064,28304,28305);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15941, 0, 0, 0, 8,  0, 100, 0, 27907, 0, 15000, 15000, 33, 15941   , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Apprentice Ralen - On Spellhit - Kill Credit'),
(15945, 0, 0, 0, 8,  0, 100, 0, 27907, 0, 15000, 15000, 33, 15945   , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Apprentice Meledor - On Spellhit - Kill Credit'),
(28352, 0, 0, 0, 8,  0, 100, 0, 51381, 0, 180000, 180000, 33, 28352   , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Nethurbian Crater KC Bunny - On Spellhit - Kill Credit'),
(28064, 0, 0, 0, 8,  0, 100, 0, 51247, 0, 0, 0, 33, 28064   , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Drakkari Pedestal 01 - On Spellhit - Kill Credit'),
(28304, 0, 0, 0, 8,  0, 100, 0, 51247, 0, 0, 0, 33, 28304   , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Drakkari Pedestal 02 - On Spellhit - Kill Credit'),
(28305, 0, 0, 0, 8,  0, 100, 0, 51247, 0, 0, 0, 33, 28305   , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Drakkari Pedestal 03 - On Spellhit - Kill Credit');
