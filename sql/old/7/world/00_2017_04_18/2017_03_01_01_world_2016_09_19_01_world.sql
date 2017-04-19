UPDATE `smart_scripts` SET `event_flags`=512 WHERE  `entryorguid`=16943 AND `source_type`=0 AND `id` IN(3,4,5);
UPDATE `gameobject` SET `spawntimesecs`=43200 WHERE  `id`=20919;
UPDATE `smart_scripts` SET `target_param2`=0 WHERE  `entryorguid`=478100 AND `source_type`=9 AND `id`=1 AND `link`=0;
UPDATE `smart_scripts` SET `target_param2`=0 WHERE  `entryorguid`=478100 AND `source_type`=9 AND `id`=2 AND `link`=0;
UPDATE `smart_scripts` SET `event_flags`=512 WHERE  `entryorguid` IN(28122,28120,28121,28216,28215,28214) AND `source_type`=0;
UPDATE `smart_scripts` SET `event_param3`=15000, `event_param4`=15000 WHERE  `entryorguid`IN(28120,28121,28122) AND `source_type`=0 AND `id`=0 AND `link`=1;

DELETE FROM `smart_scripts` WHERE `entryorguid`=28362 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(2836203,2836204,2836205,2836206,2836201,2836202,2812000) AND `source_type`=9;
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES

(28362, 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 1000, 1000, 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Glinting Dirt - OOC - Increment Phase By 1'),
(28362, 0, 1, 0, 11, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Glinting Dirt - On Spawn - Set Phase 1'),
(28362, 0, 2, 10, 38, 1, 100, 0, 1, 1, 0, 0, 11, 51397, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Glinting Dirt - On Data Set 1 1 (Phase 1) - Cast Dig Up Shining Crystal'),
(28362, 0, 3, 10, 38, 2, 100, 0, 1, 1, 0, 0, 11, 51441, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Glinting Dirt - On Data Set 1 1 (Phase 2) - Cast Dig Up Sparkling Hare'),
(28362, 0, 4, 10, 38, 4, 100, 0, 1, 1, 0, 0, 11, 51398, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Glinting Dirt - On Data Set 1 1 (Phase 3) - Cast Dig Up Glinting Armor'),
(28362, 0, 5, 10, 38, 8, 100, 0, 1, 1, 0, 0, 11, 51400, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Glinting Dirt - On Data Set 1 1 (Phase 4) - Cast Dig Up Glowing Gem'),
(28362, 0, 6, 10, 38, 16, 100, 0, 1, 1, 0, 0, 11, 51401, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Glinting Dirt - On Data Set 1 1 (Phase 5) - Cast Dig Up Polished Platter'),
(28362, 0, 7, 10, 38, 32, 100, 0, 1, 1, 0, 0, 11, 51402, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Glinting Dirt - On Data Set 1 1 (Phase 6) - Cast Dig Up Sparkling Treasure'),
(28362, 0, 8, 10, 38, 64, 100, 0, 1, 1, 0, 0, 11, 51443, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Glinting Dirt - On Data Set 1 1 (Phase 7) - Cast Dig Up Glinting Bug'),
(28362, 0, 9, 0, 1, 128, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Glinting Dirt - OOC (Phase 8)- Set Phase 1'),
(28362, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Glinting Dirt - Link - Despawn'),
(28362, 0, 11, 0, 11, 0, 100, 0, 0, 0, 0, 0, 11, 52213, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Glinting Dirt - On Respawn - Cast \'Rainspeaker Treasures: Invisibility\''),
(28362, 0, 12, 0, 38, 0, 50, 0, 1, 1, 0, 0, 11, 51443, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Glinting Dirt - On Data Set 1 1 - Cast Dig Up Glinting Bug'),
(2812000, 9, 0, 0, 61, 0, 100, 512, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 11, 28362, 10, 0, 0, 0, 0, 0, 'Lafoo - On Script - Move To Closest Creature \'Glinting Dirt\''),
(2812000, 9, 1, 0, 61, 0, 100, 512, 2500, 2500, 0, 0, 11, 51405, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lafoo - On Script - Cast \'Digging for Treasure\''),
(2812000, 9, 2, 0, 61, 0, 100, 512, 5000, 5000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 9, 28362, 0, 2, 0, 0, 0, 0, 'Lafoo - On Script - Set Data 1 1'),
(2812000, 9, 3, 0, 61, 0, 100, 512, 1000, 5000, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lafoo - On Script - Evade');
