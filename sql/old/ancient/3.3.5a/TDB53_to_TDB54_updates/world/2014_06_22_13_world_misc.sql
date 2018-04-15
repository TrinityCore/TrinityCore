--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=23689;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 4, 23689, 0, 0, 29, 1, 24170, 75, 0, 0, 0, 0, '', 'Protodrake Only execute SAI if there is Draconis Gasritus Bunny');

DELETE FROM `smart_scripts` WHERE `entryorguid`=23689 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23689, 0, 1, 2, 65, 0, 100, 0, 0, 0, 0, 0, 11, 36809, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Proto-Drake - On Follow Complete - Cast \'Overpowering Sickness\''),
(23689, 0, 2, 7, 61, 0, 100, 0, 0, 0, 0, 0, 11, 43174, 0, 0, 0, 0, 0, 18, 35, 0, 0, 0, 0, 0, 0, 'Proto-Drake - On Follow Complete - Cast \'Draconis Gastritis: Kill Credit\''),
(23689, 0, 3, 5, 1, 0, 100, 0, 10000, 10000, 10000, 10000, 29, 0, 0, 24170, 1, 1, 0, 19, 24170, 75, 0, 0, 0, 0, 0, 'Proto-Drake - Out of Combat - Start Follow Closest Creature \'Draconis Gastritis Bunny\''),
(23689, 0, 4, 0, 65, 0, 100, 0, 0, 0, 0, 0, 51, 0, 0, 0, 0, 0, 0, 19, 24170, 5, 0, 0, 0, 0, 0, 'Proto-Drake - On Follow Complete - Kill Target'),
(23689, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Proto-Drake - Out of Combat - Set Event Phase 1'),
(23689, 0, 6, 0, 1, 1, 100, 0, 45000, 45000, 45000, 45000, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Proto-Drake - Out of Combat - Despawn Instant'),
(23689, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 33, 24170, 0, 0, 0, 0, 0, 18, 35, 0, 0, 0, 0, 0, 0, 'Proto-Drake - On Death - Quest Reward'),
(23689, 0, 8, 0, 8, 0, 100, 0, 40969, 0, 120000, 120000, 69, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Proto-Drake - On Spellhit - Move to Position'),
(23689, 0, 9, 0, 9, 0, 100, 1, 0, 20, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Proto-Drake - On Range - Set Home Position'),
(23689, 0, 10, 0, 9, 0, 100, 0, 0, 5, 2000, 3500, 11, 51219, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Proto-Drake - On Range - Cast Flame Breath'),
(23689, 0, 11, 0, 0, 0, 100, 0, 3000, 9000, 30000, 45000, 11, 42362, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Proto-Drake - IC - Cast Flames of Birth'),
(23689, 0, 12, 0, 9, 0, 100, 0, 0, 20, 10000, 15000, 11, 41572, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Proto-Drake - On Range - Cast Wing Buffet');
