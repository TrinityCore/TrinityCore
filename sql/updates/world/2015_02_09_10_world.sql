--
/* SAI for Burning Exile */
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=2760;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2760;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(2760, 0, 0, 0, 8, 0, 100, 0, 4130, 0, 0, 0, 41, 500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Burning Exile - on spellhit - Despawn');

/* SAI for Cresting Exile */
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=2761;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2761;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2761, 0, 0, 0, 1, 0, 100, 1, 1000, 1000, 1800000, 1800000, 11, 12544, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cresting Exile - Out Of Combat - Cast Frost Armor'),
(2761, 0, 1, 0, 0, 0, 100, 0, 1400, 7300, 25600, 32300, 11, 865, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cresting Exile - In Combat - Cast Frost Nova'),
(2761, 0, 2, 0, 8, 0, 100, 0, 4131, 0, 0, 0, 41, 500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cresting Exile - on spellhit - Despawn');

/* SAI for Thundering Exile */
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=2762;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2762;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2762, 0, 0, 0, 1, 0, 100, 1, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thundering Exile - Out Of Combat - Allow Combat Movement'),
(2762, 0, 1, 2, 4, 0, 100, 0, 0, 0, 0, 0, 11, 9532, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Thundering Exile - On Aggro - Cast Lightning Bolt'),
(2762, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thundering Exile - On Aggro - Increment Phase'),
(2762, 0, 3, 0, 9, 0, 100, 0, 0, 40, 3300, 6600, 11, 9532, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Thundering Exile - At 0 - 40 Range - Cast Lightning Bolt'),
(2762, 0, 4, 5, 3, 0, 100, 0, 0, 15, 0, 0, 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thundering Exile - At 15% Mana - Allow Combat Movement'),
(2762, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thundering Exile - At 15% Mana - Increment Phase'),
(2762, 0, 6, 0, 9, 0, 100, 1, 35, 80, 0, 0, 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thundering Exile - At 35 - 80 Range - Allow Combat Movement'),
(2762, 0, 7, 0, 9, 0, 100, 1, 0, 5, 0, 0, 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thundering Exile - At 0 - 5 Range - Allow Combat Movement'),
(2762, 0, 8, 0, 9, 0, 100, 0, 5, 15, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thundering Exile - At 5 - 15 Range - Allow Combat Movement'),
(2762, 0, 9, 10, 3, 0, 100, 0, 30, 100, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thundering Exile - At 100% Mana - Allow Combat Movement'),
(2762, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 23, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thundering Exile - At 100% Mana - Increment Phase'),
(2762, 0, 11, 0, 0, 0, 100, 0, 1600, 15100, 18900, 25400, 11, 11824, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Thundering Exile - In Combat - Cast Shock'),
(2762, 0, 12, 0, 8, 0, 100, 0, 4132, 0, 0, 0, 41, 500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thundering Exile - on spellhit - Despawn');
