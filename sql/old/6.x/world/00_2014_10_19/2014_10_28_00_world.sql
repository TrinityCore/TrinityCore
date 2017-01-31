DELETE FROM `waypoints` WHERE `entry`=14508;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(14508,1,-13187.14, 319.7746, 33.2346, 'Short John Mithril'),
(14508,2,-13215.14, 322.7813, 33.24456, 'Short John Mithril'),
(14508,3,-13234.32, 314.1292, 33.20762, 'Short John Mithril'),
(14508,4,-13248.82, 299.0459, 33.22644, 'Short John Mithril'),
(14508,5,-13254.88, 284.0705, 33.24255, 'Short John Mithril'),
(14508,6,-13255.58, 264.5797, 33.24498, 'Short John Mithril'),
(14508,7,-13247.58, 243.589, 33.20824, 'Short John Mithril'),
(14508,8,-13237.57, 231.7462, 33.23737, 'Short John Mithril'),
(14508,9,-13233.31, 231.8894, 33.2352, 'Short John Mithril'),
(14508,10,-13235.35, 231.8208, 33.23225, 'Short John Mithril'),
(14508,11,-13234.51, 239.4648, 33.36068, 'Short John Mithril'),
(14508,12,-13239.65, 247.5611, 29.29738, 'Short John Mithril'),
(14508,13,-13244.49, 256.3933, 22.63047, 'Short John Mithril'),
(14508,14,-13241.24, 261.35, 21.93297, 'Short John Mithril'),
(14508,15,-13204.08, 277.1676, 21.98207, 'Short John Mithril'),
(14508,16,-13219.24, 275.4513, 21.98207, 'Short John Mithril'),
(14508,17,-13240.61, 268.921, 21.93298, 'Short John Mithril'),
(14508,18,-13240.61, 268.921, 21.93298, 'Short John Mithril'),
(14508,19,-13244.04, 261.8775, 21.93297, 'Short John Mithril'),
(14508,20,-13243.42, 254.9109, 23.88685, 'Short John Mithril'),
(14508,21,-13239.03, 245.3709, 29.23729, 'Short John Mithril'),
(14508,22,-13233.62, 238.1597, 33.35011, 'Short John Mithril'),
(14508,23,-13237.55, 232.776, 33.23082, 'Short John Mithril'),
(14508,24,-13250.02, 248.9038, 33.23286, 'Short John Mithril'),
(14508,25,-13255.25, 264.0384, 33.24439, 'Short John Mithril'),
(14508,26,-13255.29, 282.6273, 33.24288, 'Short John Mithril'),
(14508,27,-13248.91, 298.4456, 33.24187, 'Short John Mithril'),
(14508,28,-13233.84, 314.3157, 33.20814, 'Short John Mithril'),
(14508,29,-13215.96, 322.7598, 33.24435, 'Short John Mithril'),
(14508,30,-13199.4, 323.3979, 33.24255, 'Short John Mithril'),
(14508,31,-13188.29, 320.0755, 33.23479, 'Short John Mithril'),
(14508,32,-13184.82, 329.8854, 37.95504, 'Short John Mithril'),
(14508,33,-13184.48, 332.6711, 40.32992, 'Short John Mithril');

DELETE FROM `game_event_gameobject` WHERE  `guid`=12029 AND `eventEntry`=16;
DELETE FROM `gameobject` WHERE  `guid`=12029;

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` =14508;
DELETE FROM `smart_scripts` WHERE `entryorguid` =14508 AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(14508, 0, 0, 0, 68, 0, 100, 0, 16, 0, 0, 0, 53, 0, 14508, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Short John Mithril - On Event Start - Start WP'),
(14508, 0, 1, 0, 40, 0, 100, 0, 1, 14508, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Short John Mithril - On Reached WP1 - Say'),
(14508, 0, 2, 3, 40, 0, 100, 0, 16, 14508, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Short John Mithril - On Reached WP16 - Say'),
(14508, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 50, 179697, 10740, 0, 0, 0, 0, 8, 0, 0, 0, -13202.89, 276.757,21.85707,2.775069, 'Short John Mithril - On Reached WP19 - Spawn Chest'),
(14508, 0, 4, 0, 40, 0, 100, 0, 33, 14508, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 4.415683, 'Short John Mithril - On Reached WP33 - Set orientation');

DELETE FROM `creature_text` WHERE `entry`=14508;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(14508, 0, 0, 'Arrr, Me Hearties!   I be havin'' some extra Treasure that I be givin'' away at the Gurubashi Arena!  All ye need do to collect it is open the chest I leave on the arena floor!', 14, 0, 100, 0, 0, 0, 9730, 2, 'Short John Mithril'),
(14508, 1, 0, 'Let the Bloodletting Begin!', 14, 0, 100, 0, 0, 0, 9731, 0, 'Short John Mithril');
