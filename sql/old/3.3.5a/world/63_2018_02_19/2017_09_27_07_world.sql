-- 
DELETE FROM `smart_scripts` WHERE `entryorguid`=16318 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16318, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 1700, 2000, 11, 9613, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Deatholme Darkmage - IC - Cast 'Shadow Bolt'"),
(16318, 0, 1, 0, 0, 0, 100, 0, 7000, 11000, 32000, 36000, 11, 18267, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Deatholme Darkmage - IC - Cast 'Curse of Weakness'"),
(16318, 0, 2, 0, 2, 0, 100, 1, 0, 15, 0, 0, 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Deatholme Darkmage - Between 0-15% Health - Flee For Assist (No Repeat)");

UPDATE `smart_scripts` SET `comment`="Felboar - On Reset - Cast 'Burning Spikes'" WHERE `entryorguid`=21878 AND `id`=0 AND `source_type`=0;
UPDATE `smart_scripts` SET `event_type`=25, `comment`="Deranged Helboar - On Reset - Cast 'Burning Spikes'" WHERE `entryorguid`=16863 AND `id`=0 AND `source_type`=0;
