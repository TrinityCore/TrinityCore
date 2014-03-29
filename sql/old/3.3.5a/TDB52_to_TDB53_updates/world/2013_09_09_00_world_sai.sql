UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` IN (30135,30144,29974);
DELETE FROM `smart_scripts` WHERE entryorguid IN (30135,30144,29974);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
-- Niffelem Forefather
(29974, 0, 0, 0, 0, 0, 100, 0, 1000, 5000, 8000, 13000, 11, 57454, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Niffelem Forefather - IC - Cast Ice Spike'),
(29974, 0, 1, 2, 8, 0, 100, 0, 55983, 0, 0, 0, 33, 30138, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Niffelem Forefather - On Spellhit - Give Kill Credit'),
(29974, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Niffelem Forefather - Linked with Previous Event Despawn'),
-- Restless Frostborn Warrior
(30135, 0, 0, 0, 0, 0, 100, 0, 1000, 5000, 8000, 13000, 11, 57456, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Restless Frostborn Warrior - IC - Cast Frostbite'),
(30135, 0, 1, 2, 8, 0, 100, 0, 55983, 0, 0, 0, 33, 30139, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Restless Frostborn Warrior - On Spellhit - Give Kill Credit'),
(30135, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Restless Frostborn Warrior - Linked with Previous Event Despawn'),
-- Restless Frostborn Ghost
(30144, 0, 0, 0, 0, 0, 100, 0, 1000, 5000, 8000, 13000, 11, 57456, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Restless Frostborn Ghost - IC - Cast Frostbite'),
(30144, 0, 1, 2, 8, 0, 100, 0, 55983, 0, 0, 0, 33, 30139, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Restless Frostborn Ghost - On Spellhit - Give Kill Credit'),
(30144, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Restless Frostborn Ghost - Linked with Previous Event Despawn');
