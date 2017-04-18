-- 
UPDATE `creature_template` SET `InhabitType`=4 WHERE `Entry` IN (21159, 18793, 20654);
DELETE FROM `smart_scripts` WHERE `entryorguid`=18794; 
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(18794, 0, 0, 0, 1, 0, 100, 7, 1000, 1000, 0, 0, 11, 32958, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cabal Ritualist - Out of Combat - Cast \'Crystal Channel\ (Dungeon)'),
(18794, 0, 1, 0, 1, 0, 100, 5, 0, 0, 0, 0, 30, 1, 4, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cabal Ritualist - Out of Combat - Set Random Phase(1, 4) (No Repeat) (Dungeon)'),
(18794, 0, 2, 0, 0, 0, 100, 2, 6000, 10000, 4000, 6000, 11, 20795, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cabal Ritualist - In Combat - Cast \'Fire Blast\' (Normal Dungeon)'),
(18794, 0, 3, 0, 0, 0, 100, 4, 6000, 10000, 4000, 6000, 11, 14145, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cabal Ritualist - In Combat - Cast \'Fire Blast\' (Heroic Dungeon)'),
(18794, 0, 4, 0, 0, 0, 100, 6, 2000, 2000, 10000, 12000, 11, 9574, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cabal Ritualist - In Combat - Cast \'Flame Buffet\' (Dungeon)'),
(18794, 0, 5, 0, 0, 0, 100, 6, 4000, 4000, 6000, 8000, 11, 12540, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 'Cabal Ritualist - In Combat - Cast \'Gouge\' (Dungeon)'),
(18794, 0, 6, 0, 4, 1, 100, 6, 0, 0, 0, 0, 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cabal Ritualist - On Aggro - Increment Phase By 1 (Phase 1) (No Repeat) (Dungeon)'),
(18794, 0, 7, 0, 0, 1, 100, 2, 0, 0, 2400, 3800, 11, 15497, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cabal Ritualist - Combat CMC - Cast \'Frostbolt\' (Phase 1) (Normal Dungeon)'),
(18794, 0, 8, 0, 0, 1, 100, 4, 0, 0, 2400, 3800, 11, 12675, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cabal Ritualist - Combat CMC - Cast \'Frostbolt\' (Phase 1) (Heroic Dungeon)'),
(18794, 0, 9, 0, 0, 1, 100, 2, 7000, 7000, 7000, 12000, 11, 15532, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cabal Ritualist - In Combat - Cast \'Frost Nova\' (Phase 1) (Normal Dungeon)'),
(18794, 0, 10, 0, 0, 1, 100, 4, 7000, 7000, 7000, 12000, 11, 15063, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cabal Ritualist - In Combat - Cast \'Frost Nova\' (Phase 1) (Heroic Dungeon)'),
(18794, 0, 11, 0, 0, 2, 100, 6, 4000, 4000, 6000, 8000, 11, 12540, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 'Cabal Ritualist - In Combat - Cast \'Gouge\' (Phase 2) (Dungeon)'),
(18794, 0, 12, 0, 3, 2, 100, 6, 30, 100, 100, 100, 23, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cabal Ritualist - Between 30-100% Mana - Decrement Phase By 1 (Phase 2) (Dungeon)'),
(18794, 0, 13, 0, 4, 4, 100, 0, 0, 0, 0, 0, 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cabal Ritualist - On Aggro - Increment Phase By 1 (Phase 4) (Dungeon)'),
(18794, 0, 14, 0, 0, 4, 100, 2, 0, 0, 2400, 3800, 11, 33833, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cabal Ritualist - Combat CMC - Cast \'Arcane Missiles\' (Phase 4) (Normal Dungeon)'),
(18794, 0, 15, 0, 0, 4, 100, 4, 0, 0, 2400, 3800, 11, 38264, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cabal Ritualist - Combat CMC - Cast \'Arcane Missiles\' (Phase 4) (Heroic Dungeon)'),
(18794, 0, 16, 0, 3, 4, 100, 0, 0, 0, 0, 0, 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cabal Ritualist - Between 0-15% Mana - Increment Phase By 1 (Phase 4) (No Repeat) (Dungeon)'),
(18794, 0, 17, 0, 0, 4, 100, 6, 9000, 12000, 12000, 16000, 11, 33487, 1, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 'Cabal Ritualist - In Combat - Cast \'Addle Humanoid\' (Phase 4) (Dungeon)'),
(18794, 0, 18, 0, 0, 8, 100, 6, 4000, 4000, 6000, 8000, 11, 12540, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 'Cabal Ritualist - In Combat - Cast \'Gouge\' (Phase 8) (Dungeon)'),
(18794, 0, 19, 0, 3, 8, 100, 6, 30, 100, 100, 100, 23, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cabal Ritualist - Between 30-100% Mana - Decrement Phase By 1 (Phase 8) (Dungeon)');
