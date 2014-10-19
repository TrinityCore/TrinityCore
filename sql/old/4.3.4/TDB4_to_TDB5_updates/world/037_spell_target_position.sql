DELETE FROM `spell_target_position` WHERE `id` IN (3563, 3567, 89659, 81796, 81798, 81799, 81800, 82329, 82330, 82331, 82332, 95718, 95720, 100268, 100335, 100508, 100509, 100523, 106054, 108202, 109835);
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
(3563, 0, 1773.42, 61.7391, -46.3215, 0), -- Teleport: Undercity
(3567, 1, 1776.5, -4338.8, -7.48, 3.55349), -- Teleport: Orgrimmar
(81796, 671, -1050.05, -602.78, 835.206, 0), -- Teleport (LF)
(81798, 671, -1047.54, -557.208, 835.192, 0), -- Teleport (RF)
(81799, 671, -1059.88, -531.122, 877.69, 0), -- Teleport (RB)
(81800, 671, -1059.99, -633.863, 877.69, 0), -- Teleport (LB)
(82329, 671, -1029.45, -603.773, 831.901, 0), -- Teleport (Earth)
(82330, 671, -987.599, -561.885, 831.901, 0), -- Teleport (Air)
(82331, 671, -1029.41, -561.885, 831.901, 0), -- Teleport (Fire)
(82332, 671, -987.599, -603.773, 831.901, 0), -- Teleport (Water)
(89659, 0, -2738.46, -5003.31, -127.314, 6.17126), -- Iso'rath Awakening Teleport
(95718, 671, -951.908, -582.772, 831.902, 3.13997), -- Teleport
(95720, 671, -1162.09, -754.514, 835.025, 4.69897), -- Teleport
(100268, 0, -5851.85, 5393.11, -1209.77, 0.416258), -- Teleport to Abyssal Breach
(100335, 646, 2355.3, 181.202, 180.891, 6.19286), -- Teleport to Therazane's Throne
(100508, 861, 1447.82, 341.188, 49.9852, 0.715585), -- Teleport to Firelands
(100509, 1, -11664.6, -517.933, 124.216, 2.93215), -- Teleport to Uldum
(100523, 1, 5335.75, -3487.24, 1569.87, 6.28013), -- Teleport to Hyjal
(106054, 967, -13850.6, -13664.14, 296.3515, 1.5708), -- Teleport Single - To Deathwing's Back
(108202, 967, -1797.93, -2394.59, 45.6201, 0.104446), -- Teleport Single - To Wyrmrest Base
(109835, 967, -1804.57, -2395.07, 341.355, 0.0836013); -- Teleport Single - To Wyrmrest Summit
