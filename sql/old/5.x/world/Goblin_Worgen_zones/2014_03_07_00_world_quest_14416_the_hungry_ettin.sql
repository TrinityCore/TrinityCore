-- The Hungry Ettin - 14416
delete from smart_scripts where entryorguid = 36540;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES (36540, 0, 0, 1, 8, 0, 100, 1, 68903, 0, 0, 0, 41, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Mountain Horse - On spell hit - Despawn for quest 14416'),
(36540, 0, 1, 0, 8, 0, 100, 1, 68903, 0, 0, 0, 33, 36560, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Mountain Horse - On spell hit - Give kill credit for quest 14416');

delete from npc_spellclick_spells where npc_entry = '36540';
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) 
VALUES (36540, 46598, 1, 0);

UPDATE `creature_template` SET `faction_A` = '35', `faction_H` = '35', `speed_run` = '1.14286', `VehicleId` = '62', `AIName` = 'SmartAI', `movementId` = '0', `WDBVerified` = '12340' WHERE `entry` = '36540';