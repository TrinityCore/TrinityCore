SET @PATH := 13547500; -- If changing this value becomes needed, remember to change PATH_PHASE_TWO in boss_nightbane.cpp as well

UPDATE `creature_template` SET `flags_extra`= `flags_extra` | 536870912, `InhabitType`=7 WHERE `entry`=17225;
UPDATE `creature_text` SET `TextRange`=3 WHERE `entry`=17225;
UPDATE `creature_model_info` SET `BoundingRadius`=0.45, `CombatReach`=10.5 WHERE `DisplayID`=18062;
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17225;
UPDATE `gameobject_template` SET `ScriptName`= 'go_blackened_urn' WHERE `entry`=194092;

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_rain_of_bones';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`)VALUES
(37098,'spell_rain_of_bones');

DELETE FROM `script_spline_chain_meta` WHERE `entry`=17225;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(17225, 1, 0, 3689, 0),
(17225, 2, 0, 26021, 0),
(17225, 3, 0, 2697, 0),
(17225, 4, 0, 15920, 0);

DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=17225;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(17225, 1, 0, 0, -11003.710, -1760.1940, 140.25340),
(17225, 1, 0, 1, -11018.860, -1797.2690, 172.85250),
(17225, 2, 0, 0, -11018.860, -1797.2690, 172.85250),
(17225, 2, 0, 1, -11105.760, -1875.9000, 158.97800),
(17225, 2, 0, 2, -11175.100, -1857.2240, 101.00590),
(17225, 2, 0, 3, -11296.930, -1764.5310, 101.00590),
(17225, 2, 0, 4, -11258.900, -1722.3720, 101.00590),
(17225, 2, 0, 5, -11176.760, -1809.5990, 101.00590),
(17225, 2, 0, 6, -11191.110, -1889.3960, 107.89480),
(17225, 2, 0, 7, -11152.180, -1863.3180, 101.00590),
(17225, 2, 0, 8, -11130.680, -1891.4230, 107.89630),
(17225, 2, 0, 9, -11110.670, -1878.7710, 107.89690),
(17225, 3, 0, 0, -11110.670, -1878.7710, 107.89690),
(17225, 3, 0, 1, -11142.710, -1891.1930, 92.250380),
(17225, 4, 0, 0, -11162.230, -1900.3290, 94.727470),
(17225, 4, 0, 1, -11162.230, -1900.3290, 91.472650);

DELETE FROM `waypoint_data` WHERE `id` IN(@PATH);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH,0,-11117.73,-1941.261,127.172,0,0,1,0,100,0),
(@PATH,1,-11123.78,-1968.243,125.922,0,0,1,0,100,0),
(@PATH,2,-11148.34,-1972.98,116.6997,0,0,1,0,100,0),
(@PATH,3,-11161.62,-1945.725,103.0886,0,0,1,0,100,0),
(@PATH,4,-11168.01,-1922.905,97.39415,0,0,1,0,100,0),
(@PATH,5,-11162.23,-1900.329,94.72747,0,0,1,0,100,0),
(@PATH,6,-11162.23,-1900.329,91.47265,0,0,1,0,100,0);
