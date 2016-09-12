--
UPDATE `spell_dbc` SET `Effect1`=28, `EffectMiscValueB1`=64 WHERE `Id`=30445;

UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=0.8571 WHERE `entry`=17393;

UPDATE `quest_template_addon` SET `SourceSpellID`=30445 WHERE `ID`=9542;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (17393, 1739300, 1739301, 1739302);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17393, 0, 0, 0, 54, 0, 100, 0, 0, 1, 0, 0, 80, 1739300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Stillpine Ancestor Yor - On Just Summoned - Run Script"),
(17393, 0, 1, 2, 40, 0, 100, 0, 1, 0, 0, 0, 11, 30446, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Stillpine Ancestor Yor - On WP 1 Reached - Cast 'Yor Transform Furbolg DND'"),
(17393, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 54, 500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Stillpine Ancestor Yor - On WP 1 Reached - Pause Waypoint for 500 milliseconds"),
(17393, 0, 3, 0, 40, 0, 100, 0, 2, 0, 0, 0, 80, 1739301, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Stillpine Ancestor Yor - On WP 2 Reached - Run Script"),
(17393, 0, 4, 0, 40, 0, 100, 0, 53, 0, 0, 0, 80, 1739302, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Stillpine Ancestor Yor - On WP 53 Reached - Run Script"),

(1739300, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 17002, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Stillpine Ancestor Yor - On Script - Morph To Model 16999"),
(1739300, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 25035, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Stillpine Ancestor Yor - On Script - Cast 'Elemental Spawn-in'"),
(1739300, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -4639.022, -13066.73, -13.7768, 0, "Stillpine Ancestor Yor - On Script - Move To Position"),
(1739300, 9, 3, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Stillpine Ancestor Yor - On Script - Set Orientation to face Invoker"),
(1739300, 9, 4, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Stillpine Ancestor Yor - On Script - Say Line 0"),
(1739300, 9, 5, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 53, 0, 17393, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Stillpine Ancestor Yor - On Script - Start Waypoint"),

(1739301, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 54, 10000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Stillpine Ancestor Yor - On Script - Pause Waypoint for 10 seconds"),
(1739301, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Stillpine Ancestor Yor - On Script - Set Orientation to face Invoker"),
(1739301, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Stillpine Ancestor Yor - On Script - Say Line 1"),
(1739301, 9, 3, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 11, 32213, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Stillpine Ancestor Yor - On Script - Cast 'Shadow of the Forest SI DND' on Self"),
(1739301, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 32213, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Stillpine Ancestor Yor - On Script - Cast 'Shadow of the Forest SI DND' on Invoker"),
(1739301, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 30447, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Stillpine Ancestor Yor - On Script - Cast 'Shadow of the Forest' on Self"),
(1739301, 9, 6, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Stillpine Ancestor Yor - On Script - Say Line 2"),
(1739301, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 30448, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Stillpine Ancestor Yor - On Script - Cast 'Shadow of the Forest' on Invoker"),
(1739301, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 59, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Stillpine Ancestor Yor - On Script - Set Run On"),

(1739302, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Stillpine Ancestor Yor - On Script - Set Orientation to face Invoker"),
(1739302, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Stillpine Ancestor Yor - On Script - Say Line 3"),
(1739302, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Stillpine Ancestor Yor - On Script - Despawn");

DELETE FROM `creature_text` WHERE `entry`=17393;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(17393, 0, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=13901), 12, 0, 100, 0, 0, 0, 13901, 0, "Stillpine Ancestor Yor"),
(17393, 1, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=13903), 12, 0, 100, 0, 0, 0, 13903, 0, "Stillpine Ancestor Yor"),
(17393, 2, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=13907), 12, 0, 100, 0, 0, 0, 13907, 0, "Stillpine Ancestor Yor"),
(17393, 3, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=13927), 12, 0, 100, 0, 0, 0, 13927, 0, "Stillpine Ancestor Yor");

DELETE FROM `waypoints` WHERE `entry`=17393;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(17393, 1, -4646.627, -13015.36, -1.386728, "Stillpine Ancestor Yor"),
(17393, 2, -4679.141, -12984.98, 0.5803, "Stillpine Ancestor Yor"),
(17393, 3, -4687.865, -12949.55, 3.031635, "Stillpine Ancestor Yor"),
(17393, 4, -4683.147, -12930.07, 3.481483, "Stillpine Ancestor Yor"),
(17393, 5, -4669.631, -12912.28, 1.981483, "Stillpine Ancestor Yor"),
(17393, 6, -4642.212, -12881.51, 4.350018, "Stillpine Ancestor Yor"),
(17393, 7, -4623.764, -12837.02, 5.488779, "Stillpine Ancestor Yor"),
(17393, 8, -4611.349, -12813.14, 7.07358, "Stillpine Ancestor Yor"),
(17393, 9, -4598.923, -12789.41, 4.254271, "Stillpine Ancestor Yor"),
(17393, 10, -4589.229, -12774.91, 7.504271, "Stillpine Ancestor Yor"),
(17393, 11, -4571.645, -12755.01, 7.19785, "Stillpine Ancestor Yor"),
(17393, 12, -4557.206, -12734.06, 11.71249, "Stillpine Ancestor Yor"),
(17393, 13, -4546.748, -12710.12, 9.857432, "Stillpine Ancestor Yor"),
(17393, 14, -4535.69, -12682.16, 13.84785, "Stillpine Ancestor Yor"),
(17393, 15, -4532.907, -12665.75, 16.86223, "Stillpine Ancestor Yor"),
(17393, 16, -4533.329, -12618.87, 12.07004, "Stillpine Ancestor Yor"),
(17393, 17, -4530.376, -12605.46, 12.94504, "Stillpine Ancestor Yor"),
(17393, 18, -4535.566, -12573.9, 12.02134, "Stillpine Ancestor Yor"),
(17393, 19, -4519.527, -12543.23, 7.386412, "Stillpine Ancestor Yor"),
(17393, 20, -4510.07, -12525.35, 4.510124, "Stillpine Ancestor Yor"),
(17393, 21, -4498.348, -12505.46, 4.692971, "Stillpine Ancestor Yor"),
(17393, 22, -4478.837, -12472.25, 2.646569, "Stillpine Ancestor Yor"),
(17393, 23, -4462.558, -12438.15, 2.728706, "Stillpine Ancestor Yor"),
(17393, 24, -4427.293, -12442, 2.653673, "Stillpine Ancestor Yor"),
(17393, 25, -4413.809, -12416.67, 3.903673, "Stillpine Ancestor Yor"),
(17393, 26, -4408.878, -12400.64, 5.028673, "Stillpine Ancestor Yor"),
(17393, 27, -4414.526, -12370.95, 5.982985, "Stillpine Ancestor Yor"),
(17393, 28, -4423.452, -12345.4, 8.322853, "Stillpine Ancestor Yor"),
(17393, 29, -4432.48, -12325.47, 9.82402, "Stillpine Ancestor Yor"),
(17393, 30, -4437.556, -12313.21, 10.5507, "Stillpine Ancestor Yor"),
(17393, 31, -4470.025, -12298.24, 13.49712, "Stillpine Ancestor Yor"),
(17393, 32, -4490.178, -12280.99, 15.24712, "Stillpine Ancestor Yor"),
(17393, 33, -4506.427, -12242.67, 16.71747, "Stillpine Ancestor Yor"),
(17393, 34, -4510.89, -12225.3, 17.34562, "Stillpine Ancestor Yor"),
(17393, 35, -4514.449, -12197.06, 17.095, "Stillpine Ancestor Yor"),
(17393, 36, -4503.036, -12159.08, 16.11765, "Stillpine Ancestor Yor"),
(17393, 37, -4509.509, -12123.57, 16.97741, "Stillpine Ancestor Yor"),
(17393, 38, -4505.789, -12092.21, 19.24188, "Stillpine Ancestor Yor"),
(17393, 39, -4501.154, -12069.86, 21.49188, "Stillpine Ancestor Yor"),
(17393, 40, -4528.139, -12038.62, 25.94593, "Stillpine Ancestor Yor"),
(17393, 41, -4531.142, -12014.65, 27.76284, "Stillpine Ancestor Yor"),
(17393, 42, -4543.319, -11968.29, 29.59258, "Stillpine Ancestor Yor"),
(17393, 43, -4537.629, -11935.67, 27.2518, "Stillpine Ancestor Yor"),
(17393, 44, -4533.029, -11906.79, 22.80003, "Stillpine Ancestor Yor"),
(17393, 45, -4505.259, -11880.3, 17.74497, "Stillpine Ancestor Yor"),
(17393, 46, -4500.286, -11846.75, 15.10397, "Stillpine Ancestor Yor"),
(17393, 47, -4510.456, -11817.56, 13.85152, "Stillpine Ancestor Yor"),
(17393, 48, -4531.697, -11787.08, 15.55769, "Stillpine Ancestor Yor"),
(17393, 49, -4556.125, -11757.58, 17.68301, "Stillpine Ancestor Yor"),
(17393, 50, -4537.018, -11712.65, 18.47407, "Stillpine Ancestor Yor"),
(17393, 51, -4510.735, -11697.22, 14.64272, "Stillpine Ancestor Yor"),
(17393, 52, -4490.109, -11672.72, 10.85828, "Stillpine Ancestor Yor"),
(17393, 53, -4486.507, -11657.93, 10.86087, "Stillpine Ancestor Yor");
