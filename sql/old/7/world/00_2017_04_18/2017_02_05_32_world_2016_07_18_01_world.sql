DELETE FROM `waypoints` WHERE `entry`=17893;

INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(17893, 1, -190.9255, -796.3895, 43.79932, 'Naturalist Bite');

DELETE FROM `smart_scripts` WHERE `entryorguid`=17893 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1789300 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=17957 AND `source_type`=0 AND `id`=3;
DELETE FROM `smart_scripts` WHERE `entryorguid`=17960 AND `source_type`=0 AND `id`=12;
DELETE FROM `smart_scripts` WHERE `entryorguid`=17961 AND `source_type`=0 AND `id`=16;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17957, 0, 3, 0, 54, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 19, 17893, 0, 0, 0, 0, 0, 0, 'Coilfang Champion - On Just Summoned - Start Attack'),
(17960, 0, 12, 0, 54, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 100, 0, 0, 0, 0, 0, 0, 'Coilfang Soothsayer - On Just Summoned - Start Attack'),
(17961, 0, 16, 0, 54, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 100, 0, 0, 0, 0, 0, 0, 'Coilfang Enchantress - On Just Summoned - Start Attack'),
(17893, 0, 0, 1, 62, 0, 100, 0, 7520, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Naturalist Bite - On Gossip Select - Close Gossip'),
(17893, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 33, 17893, 0, 0, 0, 0, 0, 16, 0, 0, 0, 0, 0, 0, 0, 'Naturalist Bite - Linked with Previous Event - Give Kill Credit'),
(17893, 0, 2, 0, 10, 1, 100, 0, 1, 15, 15000, 90000, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Naturalist Bite - On Los OOC - Say Line 0 (Phase 1)'),
(17893, 0, 3, 0, 62, 0, 100, 1, 7520, 0, 0, 0, 80, 1789300, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Naturalist Bite - On Gossip Select - Run Script'),
(17893, 0, 4, 5, 40, 0, 100, 1, 1, 17893, 0, 0, 66, 0, 0, 0, 0, 0, 0, 21, 100, 0, 0, 0, 0, 0, 0, 'Naturalist Bite - On Reached WP1 - Set Orientation'),
(17893, 0, 5, 6, 61, 0, 100, 1, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Naturalist Bite - On Reached WP1 - Set Home Position'),
(17893, 0, 6, 7, 61, 0, 100, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Naturalist Bite - On Reached WP1 - Say Line 1'),
(17893, 0, 7, 8, 61, 0, 100, 1, 0, 0, 0, 0, 12, 17957, 8, 0, 0, 0, 0, 8, 0, 0, 0, -117.1674, -750.9227, 37.04787, 3.476038, 'Naturalist Bite - On Reached WP1 - Summon Coilfang Champion'),
(17893, 0, 8, 9, 61, 0, 100, 1, 0, 0, 0, 0, 12, 17961, 8, 0, 0, 0, 0, 8, 0, 0, 0, -117.0361, -754.6592, 37.45506, 0.3444065, 'Naturalist Bite - On Reached WP1 - Summon Coilfang Enchantress'),
(17893, 0, 9, 10, 61, 0, 100, 1, 0, 0, 0, 0, 12, 17960, 8, 0, 0, 0, 0, 8, 0, 0, 0, -119.7346, -750.3145, 37.0497, 0.611494, 'Naturalist Bite - On Reached WP1 - Summon Coilfang Soothsayer'),
(17893, 0, 10, 11, 61, 0, 100, 1, 0, 0, 0, 0, 11, 34906, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Naturalist Bite - On Reached WP1 - Cast Mark of Bite'),
(17893, 0, 11, 0, 61, 0, 100, 1, 0, 0, 0, 0, 11, 34906, 2, 0, 0, 0, 0, 21, 100, 0, 0, 0, 0, 0, 0, 'Naturalist Bite - On Reached WP1 - Cast Mark of Bite'),
(17893, 0, 12, 0, 11, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Naturalist Bite - On Spawn - Set Phase 1'),
(1789300, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Naturalist Bite - Script - Set Phase 0'),
(1789300, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 9, 0, 0, 0, 0, 0, 0, 20, 182094, 0, 0, 0, 0, 0, 0, 'Naturalist Bite - Script - Activate GO'),
(1789300, 9, 2, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 2, 113, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Naturalist Bite - Script - Start WP'),
(1789300, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Naturalist Bite - Script - Set NPC Flags'),
(1789300, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Naturalist Bite - Script - Set Unit Flags'),
(1789300, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, 17893, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Naturalist Bite - Script - Start WP');

DELETE FROM `creature_text` WHERE `entry`=17893;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(17893, 0, 0, 'Hey!  Over here!  Yeah, over here... I\'m in this cage!!!', 14, 0, 100, 0, 0, 0, 14668, 0, 'Naturalist Bite'),
(17893, 1, 0, 'Uh oh!  It would appear that all of the noise you\'ve been making has attracted some unwanted attention!', 12, 0, 100, 0, 0, 0, 14575, 0, 'Naturalist Bite');

