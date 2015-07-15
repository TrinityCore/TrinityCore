DELETE FROM `creature_text` WHERE `entry`=21411;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(21411, 0, 0, '%s cracks the rotten egg open and - to the horror and dismay of all around him - begins to drink from its putrid core.', 16, 0, 100, 92, 0, 0, 19098, 'Tobias the Filth Gorger to Player'),
(21411, 1, 0, 'That was life-changing... Excuse me for one minute.', 12, 0, 100, 273, 0, 0, 19099, 'Tobias the Filth Gorger to Player'),
(21411, 2, 0, '%s lets loose the most foul belch ever heard or smelled.', 16, 0, 100, 15, 0, 10593, 19100, 'Tobias the Filth Gorger to Player'),
(21411, 3, 0, 'Ok then, back to business.', 12, 0, 100, 1, 0, 0, 19101, 'Tobias the Filth Gorger to Player');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` =21411;

DELETE FROM `smart_scripts` WHERE `entryorguid` =21411 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` =2141100 AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21411, 0, 0, 1, 19, 0, 100, 0, 10550, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Tobias the Filth Gorger - On Quest 10550 taken - Store Targetlist'),
(21411, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 2141100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tobias the Filth Gorger - On Quest 10550 taken - Run script'),
(21411, 0, 2, 0, 34, 0, 100, 0, 0, 1, 0, 0, 54, 10000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tobias the Filth Gorger - On Reached WP1 - Pause WP'),
(21411, 0, 3, 0, 34, 0, 100, 0, 0, 2, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0.3141593, 'Tobias the Filth Gorger - On Reached WP2 - Set Orientation'),
(2141100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tobias the Filth Gorger - Script - Set NPC Flags'),
(2141100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 20468, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tobias the Filth Gorger - Script - Equip Item'),
(2141100, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Tobias the Filth Gorger - Script - Say Line 0'),
(2141100, 9, 3, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 5, 92, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tobias the Filth Gorger - Script - Play Emote OneShotEatNoSheathe'),
(2141100, 9, 4, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Tobias the Filth Gorger - Script - Set Orientation'),
(2141100, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tobias the Filth Gorger - Script - UnEquip Item'),
(2141100, 9, 6, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Tobias the Filth Gorger - Script - Say Line 1'),
(2141100, 9, 7, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 53, 0, 21411, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tobias the Filth Gorger - Script - Start WP'),
(2141100, 9, 8, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tobias the Filth Gorger - Script - Say Line 2'),
(2141100, 9, 9, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 11, 36823, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tobias the Filth Gorger - Script - Cast Overwhelming Odor'),
(2141100, 9, 10, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 5.544791, 'Tobias the Filth Gorger - Script - Set Orientation'),
(2141100, 9, 11, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 36824, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tobias the Filth Gorger - Script - Cast Overwhelming Odor'),
(2141100, 9, 12, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tobias the Filth Gorger - Script - Say Line 2'),
(2141100, 9, 13, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tobias the Filth Gorger - Script - Set NPC Flags');

DELETE FROM `waypoints` WHERE `entry` =21411;

INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(21411, 1,-2080.307, 5296.746, -37.32356, 'Tobias the Filth Gorger'),
(21411, 2,-2083.831, 5299.953, -37.32356, 'Tobias the Filth Gorger');
