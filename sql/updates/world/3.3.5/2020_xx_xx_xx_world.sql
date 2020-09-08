-- Vault of Archavon for 10 & 25 people 

-- Archavon Warder
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`="" WHERE `entry` = 32353;

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 32353);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(32353, 0, 0, 0, 0, 0, 100, 2, 20000, 20000, 20000, 20000, 0, 11, 60897, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Archavon Warder - In Combat - Cast \'Shield Crush\' (Normal Dungeon)'),
(32353, 0, 1, 0, 0, 0, 100, 4, 20000, 20000, 20000, 20000, 0, 11, 60899, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Archavon Warder - In Combat - Cast \'Shield Crush\' (Heroic Dungeon)'),
(32353, 0, 2, 0, 0, 0, 100, 2, 7000, 7000, 8000, 8000, 0, 11, 60902, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Archavon Warder - In Combat - Cast \'Whirl\' (Normal Dungeon)'),
(32353, 0, 3, 0, 0, 0, 100, 4, 7000, 7000, 8000, 8000, 0, 11, 60916, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Archavon Warder - In Combat - Cast \'Whirl\' (Heroic Dungeon)'),
(32353, 0, 4, 0, 0, 0, 100, 2, 2000, 2000, 6000, 6000, 0, 11, 60919, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 'Archavon Warder - In Combat - Cast \'Rock Shower\' (Normal Dungeon)'),
(32353, 0, 5, 0, 0, 0, 100, 4, 2000, 2000, 6000, 6000, 0, 11, 60923, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 'Archavon Warder - In Combat - Cast \'Rock Shower\' (Heroic Dungeon)');

-- Flame Warder
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`="" WHERE `entry` = 35143;

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 35143);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(35143, 0, 0, 0, 0, 0, 100, 6, 5000, 5000, 15000, 15000, 0, 11, 66813, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 'Flame Warder - In Combat - Cast \'Lava Burst\' (Dungeon)'),
(35143, 0, 1, 0, 0, 0, 100, 6, 10000, 10000, 20000, 20000, 0, 11, 66808, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Flame Warder - In Combat - Cast \'Meteor Fists\' (Dungeon)');

-- Frost Warder
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`="" WHERE `entry` = 38482;

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 38482);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(38482, 0, 0, 0, 0, 0, 100, 6, 5000, 5000, 20000, 20000, 0, 11, 72123, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 'Frost Warder - In Combat - Cast \'Frost Blast\' (Dungeon)'),
(38482, 0, 1, 0, 4, 0, 100, 7, 0, 0, 0, 0, 0, 11, 72122, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Frost Warder - On Aggro - Cast \'Frozen Mallet\' (No Repeat) (Dungeon)');

-- Tempest Warder
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`="" WHERE `entry` = 34015;

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 34015);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(34015, 0, 0, 0, 0, 0, 100, 6, 5000, 8000, 4000, 7000, 0, 11, 64363, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 'Tempest Warder - In Combat - Cast \'Shock\' (Dungeon)'),
(34015, 0, 1, 0, 0, 0, 100, 6, 10000, 12000, 18000, 22000, 0, 11, 64217, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Tempest Warder - In Combat - Cast \'Overcharged\' (Dungeon)');
