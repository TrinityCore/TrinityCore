UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry` IN(12858,12859);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(12858,12859) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(1285800) AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES

(12858, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 2, 113, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Torek - On Spawn - Set Faction'),
(12858, 0, 1, 2, 19, 0, 100, 0, 6544, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Torek - On Quest Accept - Store Targetlist'),
(12858, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 1285800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Torek - On Quest Accept - Run Script'),
(12858, 0, 3, 0, 40, 0, 100, 1, 1, 12858, 0, 0, 1, 1, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Torek - On Reached WP1 - Say Line 1'),
(12858, 0, 4, 0, 40, 0, 100, 1, 8, 12858, 0, 0, 1, 2, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Torek - On Reached WP8 - Say Line 2'),
(12858, 0, 5, 0, 40, 0, 100, 1, 19, 12858, 0, 0, 107, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Torek - On Reached WP19 - Summon Group'),
(12858, 0, 6, 7, 40, 0, 100, 1, 20, 12858, 0, 0, 1, 3, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Torek - On Reached WP20 - Say Line 3'),
(12858, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 15, 6544, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Torek - On Reached WP20 - Complete Quest'),
(12858, 0, 8, 9, 40, 0, 100, 1, 21, 12858, 0, 0, 1, 4, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Torek - On Reached WP21 - Say Line 4'),
(12858, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 54, 60000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Torek - On Reached WP21 - Pause WP'),
(12858, 0, 10, 11, 40, 0, 100, 0, 22, 12858, 0, 0, 45, 2, 2, 0, 0, 0, 0, 9, 12859, 0, 100, 0, 0, 0, 0, 'Torek - On Reached WP22 - Set Data on Splintertree Raider'),
(12858, 0, 11, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Torek - On Reached WP22 - Despawn'),
(12858, 0, 12, 13, 6, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 9, 12859, 0, 200, 0, 0, 0, 0, 'Torek - On Death - Set Data on Splintertree Raider'),
(12858, 0, 13, 0, 61, 0, 100, 0, 0, 0, 0, 0, 6, 6544, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Torek - On Death - Fail Quest'),
(12858, 0, 14, 0, 9, 0, 100, 0, 0, 5, 15000, 20000, 11, 11977, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Torek - IC - Cast Rend'),
(12858, 0, 15, 0, 0, 0, 100, 0, 0, 5000, 20000, 30000, 11, 8078, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Torek - IC - Cast Thunderclap'),
(12858, 0, 16, 0, 40, 0, 100, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reached WP - Set Home Position'),

(12859, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 2, 113, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Splintertree Raider - On Spawn - Set Faction'),
(12859, 0, 1, 2, 38, 0, 100, 0, 1, 1, 0, 0, 2, 83, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Splintertree Raider - On Data Set 1 1 - Set Faction'),
(12859, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Splintertree Raider - On Data Set 1 1 - Set Bytes 1'),
(12859, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Splintertree Raider - On Data Set 1 1 - Set Aggresive'),

(12859, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 29, 0, 0, 0, 0, 0, 0, 19, 12858, 0, 0, 0, 0, 0, 0, 'Splintertree Raider - On Data Set 1 1 - Follow Torek'),
(12859, 0, 5, 0, 7, 0, 100, 0, 0, 0, 0, 0, 29, 0, 0, 0, 0, 0, 0, 19, 12858, 0, 0, 0, 0, 0, 0, 'Splintertree Raider - On Evade - Follow Torek'),
(12859, 0, 6, 0, 38, 0, 100, 0, 2, 2, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Splintertree Raider - On Data Set 2 2 - Despawn'),
(12859, 0, 7, 0, 1, 0, 100, 0, 1000, 1000, 1000, 1000, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Splintertree Raider - OOC - Set Home Position'),

(1285800, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Torek - Script - Set NPC Flags'),
(1285800, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 2, 83, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Torek - Script - Set Faction'),
(1285800, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Torek - Script - Say Line 0'),
(1285800, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 9, 12859, 0, 200, 0, 0, 0, 0, 'Torek - Script - Set Data on Splintertree Raider'),
(1285800, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, 12858, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 'Torek - Script - Start WP');

DELETE FROM `creature_summon_groups` WHERE `summonerId`=12858;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES 
(12858, 0, 0, 12860, 1776.73, -2049.06, 109.83, 1.54, 4, 25000),
(12858, 0, 0, 12896, 1774.64, -2049.41, 109.83, 1.40, 4, 25000),
(12858, 0, 0, 12897, 1778.73, -2049.50, 109.83, 1.67, 4, 25000);

DELETE FROM `script_waypoint` WHERE `entry`=12858;
DELETE FROM `waypoints` WHERE `entry`=12858;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
 (12858, 1, 1788.88, -2240.17, 111.71, ''),
 (12858, 2, 1797.49, -2238.11, 112.31, ''),
 (12858, 3, 1803.83, -2232.77, 111.22, ''),
 (12858, 4, 1806.65, -2217.83, 107.36, ''),
 (12858, 5, 1811.81, -2208.01, 107.45, ''),
 (12858, 6, 1820.85, -2190.82, 100.49, ''),
 (12858, 7, 1829.6, -2177.49, 96.44, ''),
 (12858, 8, 1837.98, -2164.19, 96.71, 'prepare'),
 (12858, 9, 1839.99, -2149.29, 96.78, ''),
 (12858, 10, 1835.14, -2134.98, 96.8, ''),
 (12858, 11, 1823.57, -2118.27, 97.43, ''),
 (12858, 12, 1814.99, -2110.35, 98.38, ''),
 (12858, 13, 1806.6, -2103.09, 99.19, ''),
 (12858, 14, 1798.27, -2095.77, 100.04, ''),
 (12858, 15, 1783.59, -2079.92, 100.81, ''),
 (12858, 16, 1776.79, -2069.48, 101.77, ''),
 (12858, 17, 1776.82, -2054.59, 109.82, ''),
 (12858, 18, 1776.88, -2047.56, 109.83, ''),
 (12858, 19, 1776.86, -2036.55, 109.83, ''),
 (12858, 20, 1776.9, -2024.56, 109.83,  'win'),
 (12858, 21, 1776.87, -2028.31, 109.83, 'stay'),
 (12858, 22, 1776.9, -2028.3, 109.83, '');
