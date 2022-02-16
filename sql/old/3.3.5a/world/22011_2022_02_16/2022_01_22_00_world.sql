--
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (4484, 3879, 3893, 3898, 3899, 3900) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 448400 AND 448406 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4484, 0, 0, 0, 19, 0, 100, 0, 976, 0, 0, 0, 0, 80, 448400, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Feero Ironhand - On Quest Accept (Supplies to Aubderdine) - Run Script"),
(4484, 0, 1, 0, 40, 0, 100, 0, 19, 4484, 0, 0, 0, 80, 448401, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Feero Ironhand - On Waypoint 19 Reached - Run Script"),
(4484, 0, 2, 0, 77, 0, 100, 0, 1, 4, 0, 0, 0, 80, 448402, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Feero Ironhand - On Counter 1 Set To 4 - Run Script"),
(4484, 0, 3, 0, 40, 0, 100, 0, 27, 4484, 0, 0, 0, 80,448403, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Feero Ironhand - On Waypoint 27 Reached - Run Script"),
(4484, 0, 4, 0, 77, 0, 100, 0, 2, 3, 0, 0, 0, 80, 448404, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Feero Ironhand - On Counter 2 Set To 3 - Run Script"),
(4484, 0, 5, 0, 40, 0, 100, 0, 43, 4484, 0, 0, 0, 80, 448405, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Feero Ironhand - On Waypoint 43 Reached - Run Script"),
(4484, 0, 6, 0, 77, 0, 100, 0, 3, 3, 0, 0, 0, 80, 448406, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Feero Ironhand - On Counter 3 Set To 3 - Run Script"),
(4484, 0, 7, 0, 40, 0, 100, 0, 48, 4484, 0, 0, 0, 41, 2000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Feero Ironhand - On Waypoint 48 Reached - Despawn In 2 Seconds"),
(4484, 0, 8, 0, 6, 0, 100, 0, 0, 0, 0, 0, 0, 6, 976, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 0, "Feero Ironhand - On Death - Fail Quest"),

(448400, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 83, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Feero Ironhand - On Script - Remove Npcflag Questgiver"),
(448400, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 16, 0, 0, 0, 0, 0, 0, 0, 0, "Feero Ironhand - On Script - Store Invoker"),
(448400, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 2, 774, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Feero Ironhand - On Script - Set Faction"),
(448400, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 145, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Feero Ironhand - On Script - Set Immune Off"),
(448400, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Feero Ironhand - On Script - Say Line 0"),
(448400, 9, 5, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 53, 1, 4484, 0, 976, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Feero Ironhand - On Script - Start Waypoint"),

(448401, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Feero Ironhand - On Script - Pause Waypoint"),
(448401, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Feero Ironhand - On Script - Say Line 1"),
(448401, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 107, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Feero Ironhand - On Script - Summon Summon Group 0"),

(448402, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0.049138411879539489, "Feero Ironhand - On Script - Set Orientation"),
(448402, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Feero Ironhand - On Script - Say Line 2"),
(448402, 9, 2, 0, 0, 0, 100, 0, 11000, 11000, 0, 0, 0, 65, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Feero Ironhand - On Script - Resume Waypoint"),

(448403, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Feero Ironhand - On Script - Pause Waypoint"),
(448403, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Feero Ironhand - On Script - Say Line 3"),
(448403, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 107, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Feero Ironhand - On Script - Summon Summon Group 1"),
(448403, 9, 3, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 3893, 50, 0, 0, 0, 0, 0, 0, "Feero Ironhand - On Script - Say Line 0 (Forsaken Scout)"),

(448404, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 5.717207908630371093, "Feero Ironhand - On Script - Set Orientation"),
(448404, 9, 1, 0, 0, 0, 100, 0, 200, 200, 0, 0, 0, 5, 15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Feero Ironhand - On Script - Play Emote 'Roar'"),
(448404, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Feero Ironhand - On Script - Say Line 4"),
(448404, 9, 3, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 0, 65, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Feero Ironhand - On Script - Resume Waypoint"),

(448405, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Feero Ironhand - On Script - Pause Waypoint"),
(448405, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Feero Ironhand - On Script - Say Line 5"),
(448405, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 107, 2, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Feero Ironhand - On Script - Summon Summon Group 2"),
(448405, 9, 3, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 3899, 50, 0, 0, 0, 0, 0, 0, "Feero Ironhand - On Script - Say Line 0 (Balizar the Umbrage)"),
(448405, 9, 4, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Feero Ironhand - Script - Say Line 6"),

(448406, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0.644629597663879394, "Feero Ironhand - On Script - Set Orientation"),
(448406, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 1, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Feero Ironhand - On Script - Say Line 7"),
(448406, 9, 2, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 15, 976, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 0, "Feero Ironhand - On Script - Call AreaExploredOrEventHappens"),
(448406, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 65, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Feero Ironhand - On Script - Resume Waypoint"),

(3879, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 19, 4484, 100, 0, 0, 0, 0, 0, 0, "Dark Strand Assassin - On Spawn - Attack NPC 'Feero Ironhand'"),
(3879, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 0, 63, 1, 1, 0, 0, 0, 0, 19, 4484, 100, 0, 0, 0, 0, 0, 0, "Dark Strand Assassin - On Death - Increase Counter 1 By 1 (Feero Ironhand)"),

(3893, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 19, 4484, 100, 0, 0, 0, 0, 0, 0, "Forsaken Scout - On Spawn - Attack NPC 'Feero Ironhand'"),
(3893, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 0, 63, 2, 1, 0, 0, 0, 0, 19, 4484, 100, 0, 0, 0, 0, 0, 0, "Forsaken Scout - On Death - Increase Counter 2 By 1 (Feero Ironhand)"),

(3898, 0, 0, 0, 0, 0, 100, 0, 3000, 4000, 5000, 6000, 0, 11, 9080, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Aligar the Tormentor - In Combat - Cast 'Hamstring'"),
(3898, 0, 1, 0, 0, 0, 100, 0, 6000, 7000, 6000, 7000, 0, 11, 25712, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Aligar the Tormentor - In Combat - Cast 'Heroic Strike'"),
(3898, 0, 2, 0, 11, 0, 100, 0, 0, 0, 0, 0, 0, 11, 7165, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Aligar the Tormentor - On Spawn - Cast 'Battle Stance'"),
(3898, 0, 3, 0, 11, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 19, 4484, 100, 0, 0, 0, 0, 0, 0, "Aligar the Tormentor - On Spawn - Attack NPC 'Feero Ironhand'"),
(3898, 0, 4, 0, 6, 0, 100, 0, 0, 0, 0, 0, 0, 63, 3, 1, 0, 0, 0, 0, 19, 4484, 100, 0, 0, 0, 0, 0, 0, "Aligar the Tormentor - On Death - Increase Counter 3 By 1 (Feero Ironhand)"),

(3899, 0, 0, 0, 0, 0, 100, 0, 1000, 2000, 10000, 15000, 0, 11, 14868, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Balizar the Umbrage - In Combat - Cast 'Curse of Agony'"),
(3899, 0, 1, 0, 0, 0, 100, 0, 3000, 4000, 11000, 16000, 0, 11, 11980, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Balizar the Umbrage - In Combat - Cast 'Curse of Weakness'"),
(3899, 0, 2, 0, 0, 0, 100, 0, 0, 0, 3400, 4800, 0, 11, 20791, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Balizar the Umbrage - In Combat CMC - Cast 'Shadow Bolt'"),
(3899, 0, 3, 0, 11, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 19, 4484, 100, 0, 0, 0, 0, 0, 0, "Balizar the Umbrage - On Spawn - Attack NPC 'Feero Ironhand'"),
(3899, 0, 4, 0, 6, 0, 100, 0, 0, 0, 0, 0, 0, 63, 3, 1, 0, 0, 0, 0, 19, 4484, 100, 0, 0, 0, 0, 0, 0, "Balizar the Umbrage - On Death - Increase Counter 3 By 1 (Feero Ironhand)"),

(3900, 0, 0, 0, 0, 0, 100, 0, 0, 0, 3400, 4800, 0, 11, 9532, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Caedakar the Vicious - In Combat CMC - Cast 'Lightning Bolt'"),
(3900, 0, 1, 0, 74, 0, 100, 0, 0, 40, 30000, 45000, 40, 11, 913, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Caedakar the Vicious - On Friendly Between 0-40% Health - Cast 'Healing Wave'"),
(3900, 0, 2, 0, 11, 0, 100, 0, 0, 0, 0, 0, 0, 11, 905, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Caedakar the Vicious - On Spawn - Cast 'Lightning Shield' (No Repeat)"),
(3900, 0, 3, 0, 11, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 19, 4484, 100, 0, 0, 0, 0, 0, 0, "Caedakar the Vicious - On Spawn - Attack NPC 'Feero Ironhand'"),
(3900, 0, 4, 0, 6, 0, 100, 0, 0, 0, 0, 0, 0, 63, 3, 1, 0, 0, 0, 0, 19, 4484, 100, 0, 0, 0, 0, 0, 0, "Caedakar the Vicious - On Death - Increase Counter 3 By 1 (Feero Ironhand)");

DELETE FROM `waypoints` WHERE `entry`=4484;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `point_comment`) VALUES
(4484, 1, 3192.3206, 196.83081, 5.1151395, 0, 0, ""),
(4484, 2, 3209.471, 188.59155, 6.17224, 0, 0, ""),
(4484, 3, 3219.4888, 182.67622, 6.67224, 0, 0, ""),
(4484, 4, 3223.8237, 181.38179, 6.92224, 0, 0, ""),
(4484, 5, 3227.8333, 196.18517, 7.5747056, 0, 0, ""),
(4484, 6, 3224.7766, 205.17258, 7.579122, 0, 0, ""),
(4484, 7, 3231.7437, 224.55, 10.110373, 0, 0, ""),
(4484, 8, 3248.459, 227.06427, 10.375177, 0, 0, ""),
(4484, 9, 3267.4878, 225.2635, 10.682874, 0, 0, ""),
(4484, 10, 3284.034, 220.56114, 11.057874, 0, 0, ""),
(4484, 11, 3304.9202, 212.05455, 11.326626, 0, 0, ""),
(4484, 12, 3339.7668, 212.76408, 13.356473, 0, 0, ""),
(4484, 13, 3366.668, 225.39502, 11.9138775, 0, 0, ""),
(4484, 14, 3391.747, 227.7465, 10.154356, 0, 0, ""),
(4484, 15, 3422.5266, 226.6062, 9.236998, 0, 0, ""),
(4484, 16, 3443.424, 222.34065, 11.167828, 0, 0, ""),
(4484, 17, 3467.077, 215.57365, 13.330743, 0, 0, ""),
(4484, 18, 3489.4937, 211.17671, 11.528985, 0, 0, ""),
(4484, 19, 3515.7043, 212.53683, 9.727118, 0, 0, "First Wave"),
(4484, 20, 3540.8628, 215.52072, 7.5050516, 0, 0, ""),
(4484, 21, 3566.1138, 218.73894, 5.3500223, 0, 0, ""),
(4484, 22, 3594.5461, 218.75575, 1.936104, 0, 0, ""),
(4484, 23, 3633.7234, 213.53784, 1.3209283, 0, 0, ""),
(4484, 24, 3667.5088, 207.62492, 2.4558206, 0, 0, ""),
(4484, 25, 3706.655, 189.95294, 4.9154587, 0, 0, ""),
(4484, 26, 3733.316, 177.8601, 6.6654587, 0, 0, ""),
(4484, 27, 3756.438, 163.14868, 7.2082067, 0, 0, "Second Wave"),
(4484, 28, 3780.362, 146.15541, 8.324365, 0, 0, ""),
(4484, 29, 3810.1953, 122.06435, 9.944226, 0, 0, ""),
(4484, 30, 3838.7683, 96.39879, 12.606856, 0, 0, ""),
(4484, 31, 3862.8872, 71.39513, 15.090743, 0, 0, ""),
(4484, 32, 3893.385, 44.809135, 15.422417, 0, 0, ""),
(4484, 33, 3926.866, 23.376682, 15.858666, 0, 0, ""),
(4484, 34, 3959.779, 5.890517, 16.898214, 0, 0, ""),
(4484, 35, 3977.419, -1.842936, 16.995945, 0, 0, ""),
(4484, 36, 4002.6206, -6.988173, 16.58935, 0, 0, ""),
(4484, 37, 4026.2197, -8.33827, 16.71435, 0, 0, ""),
(4484, 38, 4060.1206, 4.132487, 15.382931, 0, 0, ""),
(4484, 39, 4097.3535, 17.44477, 16.938572, 0, 0, ""),
(4484, 40, 4131.008, 37.032173, 21.778334, 0, 0, ""),
(4484, 41, 4154.407, 49.684788, 25.568901, 0, 0, ""),
(4484, 42, 4180.185, 65.8317, 29.010221, 0, 0, ""),
(4484, 43, 4202.4434, 82.73123, 32.210342, 0, 0, "Third Wave"),
(4484, 44, 4227.951, 103.60289, 36.24071, 0, 0, ""),
(4484, 45, 4257.1143, 129.38338, 40.92588, 0, 0, ""),
(4484, 46, 4280.424, 146.154, 44.40884, 0, 0, ""),
(4484, 47, 4305.073, 157.83272, 47.012104, 0, 0, ""),
(4484, 48, 4337.6963, 174.8485, 47.099575, 0, 0, "Despawn");

DELETE FROM `creature_summon_groups` WHERE `summonerId`=4484;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`, `Comment`) VALUES
(4484, 0, 0, 3879, 3506.18, 224.306, 12.4251, 5.2399, 4, 60000, "Feero Ironhand - Group 0 - Dark Strand Assassin"),
(4484, 0, 0, 3879, 3490.6, 233.847, 13.9189, 5.58626, 4, 60000, "Feero Ironhand - Group 0 - Dark Strand Assassin"),
(4484, 0, 0, 3879, 3504.15, 200.189, 10.8121, 0.818882, 4, 60000, "Feero Ironhand - Group 0 - Dark Strand Assassin"),
(4484, 0, 0, 3879, 3490.99, 206.759, 11.4049, 0.304446, 4, 60000, "Feero Ironhand - Group 0 - Dark Strand Assassin"),
(4484, 0, 1, 3893, 3772.65, 164.76, 8.47668, 3.16516, 4, 60000, "Feero Ironhand - Group 1 - Forsaken Scout"),
(4484, 0, 1, 3893, 3761.48, 174.392, 8.10884, 4.28122, 4, 60000, "Feero Ironhand - Group 1 - Forsaken Scout"),
(4484, 0, 1, 3893, 3734.07, 191.087, 8.62857, 5.35877, 4, 60000, "Feero Ironhand - Group 1 - Forsaken Scout"),
(4484, 0, 2, 3898, 4213.847168, 92.228050, 34.014664, 3.713694, 4, 60000, "Feero Ironhand - Group 2 - Aligar the Tormentor"),
(4484, 0, 2, 3899, 4221.485352, 90.423935, 34.625427, 3.772599, 4, 60000, "Feero Ironhand - Group 2 - Balizar the Umbrage"),
(4484, 0, 2, 3900, 4214.558105, 100.005493, 34.775146, 3.798517, 4, 60000, "Feero Ironhand - Group 2 - Caedakar the Vicious");

DELETE FROM `creature_text` WHERE `CreatureID`=4484;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4484, 0, 0, "We must move quickly. Auberdine isn't too far away, but many enemies lurk in the forest.", 12, 7, 100, 0, 0, 0, 1292, 0, "Feero Ironhand"),
(4484, 1, 0, "It looks like we're in trouble. Look lively, here they come!", 12, 7, 100, 1, 0, 0, 1372, 0, "Feero Ironhand"),
(4484, 2, 0, "Assassins from that cult you found... Let's get moving before someone else finds us out here.", 12, 7, 100, 1, 0, 0, 1294, 0, "Feero Ironhand"),
(4484, 3, 0, "Hold! I sense an evil presence... Undead!", 12, 7, 100, 1, 0, 0, 1373, 0, "Feero Ironhand"),
(4484, 4, 0, "They're coming out of the woodwork today. Let's keep moving or we may find more things that want me dead.", 12, 7, 100, 0, 0, 0, 1310, 0, "Feero Ironhand"),
(4484, 5, 0, "These three again?", 12, 7, 100, 0, 0, 0, 1374, 0, "Feero Ironhand"),
(4484, 6, 0, "I'll finish you off for good this time!", 12, 0, 100, 0, 0, 0, 1499, 0, "Feero Ironhand"),
(4484, 7, 0, "Well done! I should be fine on my own from here. Remember to talk to Delgren when you return to Maestra's Post in Ashenvale.", 12, 7, 100, 0, 0, 0, 1315, 0, "Feero Ironhand");
