UPDATE `creature_template` SET `flags_extra`=536871681, `InhabitType`=7 WHERE `entry`=17225;
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
(17225, 4, 0, 15920, 0),
(17225, 5, 0, 15920, 0);

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
(17225, 4, 0, 1, -11162.230, -1900.3290, 91.472650),
(17225, 5, 0, 0, -11160.130, -1870.6830, 97.738760),
(17225, 5, 0, 1, -11117.730, -1941.2610, 127.17200),
(17225, 5, 0, 2, -11123.780, -1968.2430, 125.92200),
(17225, 5, 0, 3, -11148.340, -1972.9800, 116.69970),
(17225, 5, 0, 4, -11161.620, -1945.7250, 103.08860),
(17225, 5, 0, 5, -11168.010, -1922.9050, 97.394150),
(17225, 5, 0, 6, -11162.230, -1900.3290, 94.727470);
