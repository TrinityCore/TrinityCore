UPDATE `creature_template` SET `InhabitType`=4 WHERE  `entry`=23282;


DELETE FROM `smart_scripts` WHERE `entryorguid`=185932 AND `source_type`=1;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(185932, 1, 0, 1, 62, 0, 100, 0, 8685, 0, 0, 0, 85, 41035, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Obsidia\'s Egg - On Gossip Option 0 Selected - Invoker Cast 41035 Four Dragons: Force Cast - Obsidia'),
(185932, 1, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Obsidia\'s Egg - On Gossip Option 0 Selected - Close Gossip');

DELETE FROM `event_scripts` WHERE `id`=15005;
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
(15005, 1, 10, 23364, 100000, 0, 2426.954, 7001.479, 367.3824, 0),
(15005, 0, 10, 23282, 300000, 0, 2424.975, 6933.425, 409.5501, 1.43117);


UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` =23364;
DELETE FROM `smart_scripts` WHERE `entryorguid` =23364 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` =23282 AND `source_type`=0 AND `id`>4;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(23364, 0, 0, 1, 11, 0, 100, 0, 0, 0, 0, 0, 11, 15750, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Black Dragon Whelpling - On Spawn - Cast Rookery Whelp Spawn-in Spell'),
(23364, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Black Dragon Whelpling - On Spawn - Say'),
(23364, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 18, 33536, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Black Dragon Whelpling - On Spawn - Set Unit Flags'),
(23364, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 70, 300, 0, 0, 0, 0, 0, 14, 27915, 185932, 0, 0, 0, 0, 0, 'Black Dragon Whelpling - On Spawn - Despawn Obsidia\'s Egg'),
(23364, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 0, 23364, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Black Dragon Whelpling - On Spawn - Start WP'),
(23364, 0, 5, 6, 40, 0, 100, 0, 2, 23364, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 23282, 0, 0, 0, 0, 0, 0, 'Black Dragon Whelpling - On Reached WP2 - Set Data on Obsidia'),
(23364, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Black Dragon Whelpling - Reached WP2 - Despawn'),
(23282, 0, 5, 0, 11, 0, 100, 0, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Obsidia - On Spawn - Set Unit Flags'),
(23282, 0, 6, 7, 38, 0, 100, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Obsidia - On Data Set - Say'),
(23282, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 1, 23282, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Obsidia - On Data Set - Start WP'),
(23282, 0, 8, 9, 40, 0, 100, 0, 1, 23282, 0, 0, 94, 280, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Obsidia - On Reached WP1 - Set Dynamic Flags'),
(23282, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Obsidia - On Reached WP1 - Set Unit Flags'),
(23282, 0, 10, 11, 61, 0, 100, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Obsidia - On Reached WP1 - Set Home Position'),
(23282, 0, 11, 0, 61, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Obsidia - On Reached WP1 - Set Aggresive');

DELETE FROM `creature_text` WHERE `entry` IN(23364,23282);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(23364, 0, 0, 'The %s screams out for its mother.', 16, 0, 100, 0, 0, 431, 'Black Dragon Whelpling',21420),
(23282, 0, 0, 'I believe that I shall feast upon both $r and ogre flesh tonight.', 14, 0, 100, 0, 0, 7274, 'Obsidia',21718);


DELETE FROM `waypoints` WHERE `entry` IN(23364,23282);

INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(23364, 1,2425.253, 6994.862, 368.0848, 'Black Dragon Whelpling'),
(23364, 2,2424.881, 6998.754, 367.8495, 'Black Dragon Whelpling'),
(23282, 1,2428.085, 6980.77, 369.7684, 'Obsidia');



