--
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` =28413;
DELETE FROM `smart_scripts` WHERE `entryorguid` =28413 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` =2841300 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid` =2841301 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid` =2841302 AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(28413, 0, 0, 1, 11, 0, 100, 1, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nerubian Cocoon - On Respawn - Disable Combat Movement (No Repeat)'),
(28413, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 18, 2097152, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nerubian Cocoon - On Respawn - Set Flag Disarmed (No Repeat)'),
(28413, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nerubian Cocoon - On Respawn - Set Invincibility HP'),
(28413, 0, 3, 0, 4, 0, 100, 0, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Nerubian Cocoon - On Death - Store Target List (No Repeat)'),
(28413, 0, 4, 0, 2, 0, 100, 1, 0, 2, 0, 0, 87, 2841300, 2841301, 2841300, 2841302, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nerubian Cocoon - On Death - Run Random Script (No Repeat)'),
(2841300, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 51599, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nerubian Cocoon - Script 1 - Cast Summon Captive Footman'),
(2841300, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 33, 28415, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Nerubian Cocoon - Script 1 - Give Kill Cedit'),
(2841300, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nerubian Cocoon - Script 1 - Despawn'),
(2841301, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 51597, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nerubian Cocoon - Script 2 - Cast Summon Summon Scourged Captive'),
(2841301, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nerubian Cocoon - Script 2 - Despawn'),
(2841302, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nerubian Cocoon - Script 3 - Despawn');
