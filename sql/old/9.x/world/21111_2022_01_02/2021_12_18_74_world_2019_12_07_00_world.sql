-- 
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=18069;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`IN(1806900,1806901);
DELETE FROM `smart_scripts` WHERE `entryorguid`=18471 AND `source_type`=0 AND `id` IN (30,31);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (18400) AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(18471, 0, 30, 20, 52, 0, 100, 0, 13, 18471, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 19, 18069, 0, 0, 0, 0, 0, 0, 0, "Gurgthock - On text over - Say Line 3"),
(18471, 0, 31, 22, 38, 0, 100, 512, 16, 16, 0, 0, 0, 81, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Gurgthock - On Data Set - Set NPC Flag'),
(18069, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 3500, 3500, 0, 11, 16033, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Mogor - In Combat - Cast \'Chain Lightning\' (No Repeat)'),
(18069, 0, 1, 0, 2, 0, 100, 1, 0, 60, 0, 0, 0, 11, 15982, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mogor - Between 0-60% Health - Cast \'Healing Wave\' (No Repeat)'),
(18069, 0, 2, 0, 2, 0, 100, 1, 0, 30, 0, 0, 0, 11, 28747, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mogor - Between 0-30% Health - Cast \'Frenzy\' (No Repeat)'),
(18069, 0, 3, 0, 2, 0, 100, 1, 0, 30, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mogor - Between 0-30% Health - Say Line 0 (No Repeat)'),
(18069, 0, 4, 0, 61, 0, 100, 513, 0, 0, 0, 0, 0, 80, 1806901, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On 1% HP or less (Phase 1) - Run Script '),
(18069, 0, 5, 0, 38, 0, 100, 0, 12, 12, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On Data Set 12 12 - Say Line 1 (No Repeat)'),
(18069, 0, 6, 0, 38, 0, 100, 0, 13, 13, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On Data Set 13 13 - Say Line 2 (No Repeat)'),
(18069, 0, 7, 0, 38, 0, 100, 0, 14, 14, 0, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On Data Set 14 14 - Say Line 6 (No Repeat)'),
(18069, 0, 8, 9, 38, 0, 100, 512, 1, 1, 0, 0, 0, 53, 0, 18069, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On Data Set 1 1 - Start Waypoint'),
(18069, 0, 9, 0, 61, 0, 100, 512, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On Data Set 1 1 - Set event phase 1'),
(18069, 0, 10, 15, 40, 0, 100, 512, 4, 18069, 0, 0, 0, 80, 1806900, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On Waypoint 4 Reached - Run Script'),
(18069, 0, 12, 13, 6, 2, 100, 513, 0, 0, 0, 0, 0, 15, 9977, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On Just Died - Quest Credit \'The Ring of Blood: The Final Challenge\''),
(18069, 0, 13, 0, 61, 0, 100, 512, 0, 0, 0, 0, 0, 45, 15, 15, 0, 0, 0, 0, 19, 18471, 0, 0, 0, 0, 0, 0, 0, 'Mogor - Linked with Previous Event - Say Data'),
(18069, 0, 14, 0, 0, 0, 100, 0, 1000, 3000, 60000, 65000, 0, 11, 18975, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mogor - In Combat - Cast Ice Totem'),
(18069, 0, 15, 0, 61, 0, 100, 512, 0, 0, 0, 0, 0, 42, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On Waypoint 4 Reached - Set Invincibility HP On'),
(18069, 0, 16, 17, 2, 1, 100, 513, 0, 1, 0, 0, 0, 18, 536870912, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On 1% HP or less  - Set Unit Flags'),
(18069, 0, 17, 18, 61, 1, 100, 513, 0, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On 1% HP or less (Phase 1)  - Set Unit Flags'),
(18069, 0, 18, 19, 61, 1, 100, 513, 0, 0, 0, 0, 0, 95, 32, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On 1% HP or less (Phase 1)  - Set Dyamic Flags'),
(18069, 0, 19, 4, 61, 1, 100, 513, 0, 0, 0, 0, 0, 90, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On 1% HP or less  (Phase 1) - Set Bytes 1'),
(18069, 0, 20, 21, 7, 3, 100, 0, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On Evade (Phase 1 & 2)  - Set Faction'),
(18069, 0, 21, 0, 61, 3, 100, 0, 0, 0, 0, 0, 0, 53, 1, 1806900, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On Evade (Phase 1 & 2)  - Start WP (Path 2)'),
(18069, 0, 22, 23, 40, 0, 100, 0, 1, 1806900, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On Reached WP1 (Path 2)  - Set Home Position'),
(18069, 0, 23, 24, 61, 0, 100, 0, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 4.3693, 'Mogor - On Reached WP1 (Path 2)  - Set Orientation'),
(18069, 0, 24, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 45, 16, 16, 0, 0, 0, 0, 19, 18471, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On Reached WP1 (Path 2) - Say Data'),
(18069, 0, 25, 0, 7, 0, 100, 512, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, 12141, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On Evade (All Phases) - Despawn Ice Totem'),
(18069, 0, 26, 0, 40, 0, 100, 512, 3, 18069, 0, 0, 0, 45, 1, 6, 0, 0, 0, 0, 19, 18471, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On Data Set 1 1 - Say Line 3'),
(18069, 0, 27, 0, 0, 0, 100, 0, 4000, 4000, 11000, 13000, 0, 11, 39529, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Mogor - In Combat - Cast Flame Shock'),
(1806900, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On Script - Say Line 4'),
(1806900, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 0, 2, 14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On Script - Set Faction 14'),
(1806900, 9, 2, 0, 0, 0, 100, 0, 9, 9, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On Script - Set Reactstate Aggressive'),
(1806901, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On Script - Set Home Position'),
(1806901, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 22, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On Script - Set Phase 3'),
(1806901, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 0, 11, 32343, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On Script - Cast \'Revive Self\''),
(1806901, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 91, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On Script - Set Bytes 1'),
(1806901, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 96, 32, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On Script - Set Dyanmic Flags'),
(1806901, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 19, 536870912, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On Script - Set Unit Flags'),
(1806901, 9, 6, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On Script - Say Line 5'),
(1806901, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 42, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On Script - Turn Invinvibility HP OFF'),
(1806901, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On Script - Set Phase 2'),
(1806901, 9, 9, 0, 0, 0, 100, 0, 500, 500, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On Script - Set Unit Flags'),
(1806901, 9, 10, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 35, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On Script - Start Attacking');

DELETE FROM `waypoints` WHERE `entry`=1806900 AND `pointid`=1;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(1806900, 1, -714.823, 7931.65, 58.8672, 'Mogor (Path 2)');
