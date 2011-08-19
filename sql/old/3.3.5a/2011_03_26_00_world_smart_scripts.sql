-- Scripts for Nexus Lord and Scion of Eternity
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (30249,30245);
DELETE FROM `smart_scripts` WHERE (`entryorguid`=30249 AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(30249, 0, 0, 0, 0, 0, 100, 6, 3000, 5000, 4000, 6000, 11, 56397, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Scion of Eternity - Cast Arcane Barrage (Random)'),
(30249, 0, 1, 0, 7, 0, 100, 6, 1, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scion of Eternity - Despawn in EvadeMode');
DELETE FROM `smart_scripts` WHERE (`entryorguid`=30245 AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(30245, 0, 0, 0, 0, 0, 100, 6, 7000, 10000, 10000, 15000, 11, 57060, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nexus Lord - Cast Haste (Self)'),
(30245, 0, 1, 0, 0, 0, 100, 6, 5000, 8000, 9000, 12000, 11, 57058, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Nexus Lord - Cast Arcane Shock (Random)'),
(30245, 0, 2, 0, 7, 0, 100, 6, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nexus Lord - Despawn in EvadeMode');
