UPDATE `smart_scripts` SET `event_flags`=1 WHERE `entryorguid`=20882 AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid`=20896 AND `source_type`=0 AND `id`=3;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid`=20900 AND `source_type`=0 AND `id`=3;
UPDATE `smart_scripts` SET `link`=0,`event_type`=61 WHERE `entryorguid`=4063 AND `source_type`=0 AND `id`=3;
UPDATE `smart_scripts` SET `event_type`=61 WHERE `entryorguid`=2245 AND `source_type`=0 AND `id`=8;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid`=7038 AND `source_type`=0 AND `id`=17;
UPDATE `smart_scripts` SET `event_type`=61 WHERE `entryorguid`=2345 AND `source_type`=0 AND `id`=11;

DELETE FROM `smart_scripts` WHERE `entryorguid`=314 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(314, 0, 1, 0, 11, 0, 100, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Eliza - Phase 0 - On spawn - Prevent combat movement'),
(314, 0, 2, 3, 4, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Eliza - Phase 0 - On aggro - Say'),
(314, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Eliza - Phase 0 - On aggro - Set phase 1'),
(314, 0, 4, 0, 9, 1, 100, 0, 0, 40, 0, 0, 11, 20819, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Eliza - Phase 1 - In combat - Cast Frostbolt'),
(314, 0, 5, 0, 9, 1, 100, 0, 0, 5, 0, 0, 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Eliza - Phase 1 - 0 to 5 yards - Activate combat movement'),
(314, 0, 6, 0, 9, 1, 100, 0, 5, 35, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Eliza - Phase 1 - 5 to 35 yards - Deactivate combat movement'),
(314, 0, 7, 0, 9, 1, 100, 0, 35, 80, 0, 0, 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Eliza - Phase 1 - 35 to 80 yards - Activate combat movement'),
(314, 0, 8, 0, 0, 1, 100, 0, 4100, 6400, 72300, 72300, 11, 3107, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Eliza - Phase 1 - In combat - Summon Elizas Guard'),
(314, 0, 9, 0, 0, 1, 100, 0, 2100, 2900, 12500, 36300, 11, 11831, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Eliza - Phase 1 - In combat - Cast Frost Nova'),
(314, 0, 10, 12, 3, 1, 100, 0, 0, 7, 0, 0, 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Eliza - Phase 1 - At 7% mana - Start combat movement'),
(314, 0, 11, 0, 61, 1, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Eliza - Phase 1 - At 7% mana - Set phase 2'),
(314, 0, 12, 0, 3, 2, 100, 0, 15, 100, 100, 100, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Eliza - Phase 2 - At 15% mana - Set phase 1');
