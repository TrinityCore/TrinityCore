
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=17734;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17734, 0, 0, 0, 9, 0, 100, 6, 0, 10, 10500, 20000, 11, 25778, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Underbog Lord - On Target within 10 yards range - Cast \'Knock Away\' '),
(17734, 0, 1, 0, 0, 0, 100, 6, 7100, 7100, 12000, 16000, 11, 32065, 33, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Underbog Lord - In Combat - Cast \'Fungal Decay\''),
(17734, 0, 2, 0, 2, 0, 100, 6, 10000, 10000, 10000, 12000, 11, 40318, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Underbog Lord - IC - Cast \'Growth\' '),
(17734, 0, 3, 4, 2, 0, 100, 7, 0, 30, 0, 0, 11, 8599, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Underbog Lord - Between 0-30% Health - Cast \'Enrage\' (No Repeat) '),
(17734, 0, 4, 0, 61, 0, 100, 7, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Underbog Lord - Between 0-30% Health - Say Line 0 (No Repeat) (Dungeon)'); 
UPDATE `creature_template` SET `gossip_menu_id`='7520' WHERE `entry`=22938;
