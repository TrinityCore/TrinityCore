-- Fix quest Strength of the Tempest
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=29079;
DELETE FROM `smart_scripts` WHERE `entryorguid`=29079 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(29079,0,0,0,9,0,100,0,0,70,2000,6000,11,53062,0,0,0,0,0,18,70,0,0,0,0,0,0,'Shrine of the Tempest - Range cast Lightning Strike'); -- GUESSING, 10% sure that this is the correct spell. Could 51213 Weather Shrine Active Aura

DELETE FROM `spell_scripts` WHERE `id`=53062;
INSERT INTO `spell_scripts` (`id`, `effIndex`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES
(53062, 0, 0, 15, 53067, 2, 0, 0, 0, 0, 0); -- Cast create item spell
