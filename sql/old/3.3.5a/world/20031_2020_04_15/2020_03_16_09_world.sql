-- 
-- SAI correction for Scarlet Conjuror 4297
-- Fire Elemental will now be correctly summoned instead of prespawned
DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 4297);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4297, 0, 0, 0, 25, 0, 100, 2, 0, 0, 0, 0, 0, 11, 8985, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Scarlet Conjuror - On Reset - Cast \'Summon Fire Elemental\' (Normal Dungeon)'),
(4297, 0, 1, 0, 0, 0, 100, 2, 0, 0, 2400, 3800, 0, 11, 9053, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Scarlet Conjuror - In Combat - Cast \'Fireball\' (Normal Dungeon)'),
(4297, 0, 2, 0, 2, 0, 100, 3, 0, 15, 0, 0, 0, 25, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Scarlet Conjuror - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)');

-- deleting his prespawned Fire Elemental in Scarlet Monastery Armory
DELETE FROM `creature` WHERE `guid` = 40134;
