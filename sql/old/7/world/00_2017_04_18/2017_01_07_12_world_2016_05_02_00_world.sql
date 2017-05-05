UPDATE `smart_scripts` SET `link`=5 WHERE  `entryorguid`=28082 AND `source_type`=0 AND `id` IN(0,1) AND `link`=0;
UPDATE `smart_scripts` SET `link`=6 WHERE  `entryorguid`=28082 AND `source_type`=0 AND `id` IN(2,3) AND `link`=0;
UPDATE `smart_scripts` SET `link`=7 WHERE  `entryorguid`=28082 AND `source_type`=0 AND `id` IN(4) AND `link`=0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=28082 AND `source_type`=0 AND `id` IN(5,6,7);
DELETE FROM `smart_scripts` WHERE `entryorguid`=28027 AND `source_type`=0 AND `id` IN(9,10,11);

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(28082, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 85, 51186, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'High-Shaman Rakjak - Link - Cast Summon Goregek the Bristlepine Hunter'),
(28082, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 85, 51188, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'High-Shaman Rakjak - Link - Cast Summon Dajik the Wasp Hunter'),
(28082, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 85, 51189, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'High-Shaman Rakjak - Link - Cast Summon Zepik the Gorloc Hunter'),
(28027, 0, 9, 0, 19, 0, 100, 0, 12571, 0, 0, 0, 85, 51190, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'High-Oracle Soo-say - On Quest Accept - Cast Summon Lafoo'),
(28027, 0, 10, 0, 19, 0, 100, 0, 12574, 0, 0, 0, 85, 51191, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'High-Oracle Soo-say - On Quest Accept - Cast Summon Jaloot'),
(28027, 0, 11, 0, 19, 0, 100, 0, 12578, 0, 0, 0, 85, 51192, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'High-Oracle Soo-say - On Quest Accept - Cast Summon Moodle');
