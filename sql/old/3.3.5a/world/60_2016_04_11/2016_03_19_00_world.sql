UPDATE `smart_scripts` SET `target_type`=7 WHERE  `entryorguid`=19227 AND `source_type`=0 AND `id`=1 AND `link`=0;

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` IN(20232);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(20232,20206) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(2020600,2020601,2020602) AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(20232, 0, 0, 0, 20, 0, 100, 0, 10344, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Wing Commander Gryphongar - On quest reward (Wing Commander Gryphongar) - Say'),
(20206, 0, 0, 1, 20, 0, 100, 0, 10919, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fei Fei - On Quest \'Fei Fei\'s Treat\' Finished - Set Active'),
(20206, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fei Fei - On Quest \'Fei Fei\'s Treat\' Finished - Set NPC Flags'),
(20206, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 0, 20206, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fei Fei - On Quest \'Fei Fei\'s Treat\' Finished - Start Waypoints'),
(20206, 0, 3, 4, 40, 0, 100, 0, 1, 20206, 0, 0, 54, 5000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fei Fei - On reached WP1 - Pause WP'),
(20206, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 2020600, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fei Fei - On reached WP1 - Run Script 1'),
(20206, 0, 5, 6, 40, 0, 100, 0, 12, 20206, 0, 0, 54, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fei Fei - On reached WP12 - Pause WP'),
(20206, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fei Fei - On reached WP12 - Say Line 3'),
(20206, 0, 7, 8, 40, 0, 100, 0, 8, 20206, 0, 0, 54, 5000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fei Fei - On reached WP8 - Pause WP'),
(20206, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 2020600, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fei Fei - On reached WP8 - Run Script 2'),
(20206, 0, 9, 10, 40, 0, 100, 0, 14, 20206, 0, 0, 54, 5000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fei Fei - On reached WP14 - Pause WP'),
(20206, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 2020601, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fei Fei - On reached WP14 - Run Script 3'),
(20206, 0, 11, 12, 40, 0, 100, 0, 16, 20206, 0, 0, 81, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fei Fei - On reached WP16 - Set NPC Flags'),
(20206, 0, 12, 13, 61, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 2.22254, 'Fei Fei - On reached WP16 - Set Orientation'),
(20206, 0, 13, 0, 61, 0, 100, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fei Fei - On reached WP16 - Set Active Off'),


(2020600, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fei Fei - Script 1 - Say Line 1'), -- 22:32:01.531
(2020600, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 5, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fei Fei - Script 1 - Play Emote 35'), -- 22:32:02.625
(2020600, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 39216, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fei Fei - Script 1 - Cast  Create Fei Fei Stash'), -- 22:32:03.812
(2020600, 9, 3, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fei Fei - Script 1 - Say Line 2'), -- 22:32:05.156

(2020601, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fei Fei - Script 3 - Say Line 1'), -- 22:32:43.656
(2020601, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 5, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fei Fei - Script 3 - Play Emote 35'), -- 22:32:45.062
(2020601, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fei Fei - Script 3 - Say Line 4'); -- 22:32:46.484

DELETE FROM `creature_text` WHERE `entry` IN(20232,20206);
DELETE FROM `creature_text` WHERE `entry` IN(19308) AND `groupid`=0 AND `id`=3;

INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(20232, 0, 0, 'Welcome to Shatter Point, $n!  I hope you survive the experience!', 12, 0, 100, 1, 0, 0, 18272, 0, 'Wing Commander Gryphongar'),
(19308, 0, 3, 'I regret to inform you all that we sent home another ten soldiers today - in body bags.', 12, 7, 100, 1, 0, 0, 16455, 0, 'Marshal Isildor'),
(20206, 0, 0, '%s digs in the dirt...', 16, 0, 100, 35, 0, 0, 20312, 0, 'Fei Fei to Fei Fei Stash Bunny'),
(20206, 1, 0, '%s sniffs around, unsatisfied with this hiding spot.', 16, 0, 100, 0, 0, 0, 20315, 0,'Fei Fei to Fei Fei Stash Bunny'),
(20206, 2, 0, '%s looks for a hiding spot...', 16, 0, 100, 0, 0, 0, 20316, 0,'Fei Fei to Fei Fei Stash Bunny'),
(20206, 3, 0, '%s buries his treat!', 16, 0, 100, 0, 0, 0, 20313, 0,'Fei Fei to Fei Fei Stash Bunny');

DELETE FROM `waypoints` WHERE `entry`=20206;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(20206, 1, -689.1158, 2630.12, 89.82688, 'Fei Fei'),
(20206, 2,-690.6677 ,2634.433 ,90.20647, 'Fei Fei'),
(20206, 3,-689.6677 ,2656.183 ,92.45647, 'Fei Fei'),
(20206, 4,-686.1677 ,2679.433 ,92.20647, 'Fei Fei'),
(20206, 5,-678.6677 ,2699.683 ,94.95647, 'Fei Fei'),
(20206, 6,-671.6677 ,2710.683 ,94.70647, 'Fei Fei'),
(20206, 7,-667.1677 ,2725.933 ,94.20647, 'Fei Fei'),
(20206, 8,-666.6677 ,2729.433 ,93.95647, 'Fei Fei'),
(20206, 9,-671.9177 ,2732.183 ,93.95647, 'Fei Fei'),
(20206, 10,-680.6677 ,2732.683 ,93.95647, 'Fei Fei'),
(20206, 11,-685.9177 ,2734.933 ,94.20647, 'Fei Fei'),
(20206, 12,-686.4177 ,2742.183 ,93.95647, 'Fei Fei'),
(20206, 13,-690.9177 ,2746.683 ,93.95647, 'Fei Fei'),
(20206, 14,-698.7195, 2743.245, 94.08604, 'Fei Fei'),
(20206, 15,-669.3355, 2727.604, 94.01691, 'Fei Fei'),
(20206, 16,-684.603, 2626.44, 89.1955, 'Fei Fei');

DELETE FROM `gameobject` WHERE `id` =185302;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(28524, 185302, 530, 1, 1, -699.4442, 2742.403, 94.18588, -0.5759573, 0, 0, 0, 1, 120, 255, 1); -- 185302 (Area: 0)
