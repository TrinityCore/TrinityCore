SET @GAME_TELE_ID_START := 1524;

DELETE FROM `game_tele` WHERE `id` BETWEEN @GAME_TELE_ID_START AND @GAME_TELE_ID_START + 30;
INSERT INTO `game_tele` (`id`, `position_x`, `position_y`, `position_z`, `orientation`, `map`, `name`) VALUES
(@GAME_TELE_ID_START + 00, -62.9117, -884.924, 20.2665, 0.790889, 1116, 'Draenor'),
-- shadowmoon valley
(@GAME_TELE_ID_START + 01, -10.7263, -11.6916, 132.447, 4.99356, 1116, 'DraenorShadowmoonValley'),
(@GAME_TELE_ID_START + 02, 1868.25, 543.887, 36.8879, 0.822293, 1116, 'DraenorTheCursedWoods'),
(@GAME_TELE_ID_START + 03, 792.977, -661.44, -34.4487, 5.79858, 1116, 'DraenorEmbaariVillage'),
-- frostfire ridge
(@GAME_TELE_ID_START + 04, 6277.09, 4661.2, 164.159, 5.27711, 1116, 'DraenorFrostfireRidge'),
(@GAME_TELE_ID_START + 05, 6035.97, 2747.9, 204.467, 4.29143, 1116, 'DraenorThunderPass'),
(@GAME_TELE_ID_START + 06, 7201.84, 6143.85, 118.187, 5.21116, 1116, 'DraenorCircleOfBlood'),
-- talrador
(@GAME_TELE_ID_START + 07, 2434.15, 2375.28, 126.584, 5.44828, 1116, 'DraenorTalrador'),
(@GAME_TELE_ID_START + 08, 2892.45, 3496.2, 60.264, 4.00866, 1116, 'DraenorShattrath'),
(@GAME_TELE_ID_START + 09, 1904.64, 2748.87, 133.659, 2.65699, 1116, 'DraenorAuchindoun'),
(@GAME_TELE_ID_START + 10, 3046.93, 2259.74, 119.867, 3.41882, 1116, 'DraenorTuurem'),
(@GAME_TELE_ID_START + 11, 3250.92, 1007.09, 39.5669, 5.54724, 1116, 'DraenorTangarra'),
(@GAME_TELE_ID_START + 12, 3205.78, 832.338, 81.9089, 4.51366, 1116, 'DraenorKhadagarsTower'),
(@GAME_TELE_ID_START + 13, 3444.42, 3122.29, 20.4026, 0.00939501, 1116, 'DraenorShatariAnchorage'),
-- spires of arak
(@GAME_TELE_ID_START + 14, -587.879, 1080.18, 32.3069, 1.02256, 1116, 'DraenorSpiresOfArak'),
(@GAME_TELE_ID_START + 15, 261.102, 1306.36, 0.370201, 2.31847, 1116, 'DraenorHarvestingPits'),
(@GAME_TELE_ID_START + 16, -2117.71, 1255.85, 14.1154, 3.08267, 1116, 'DraenorPinchwhistlePoint'),
(@GAME_TELE_ID_START + 17, -1243.2, 1948.67, 22.5656, 3.22797, 1116, 'DraenorBloodmanePridelands'),
(@GAME_TELE_ID_START + 18, -166.49, 1862.79, 34.1361, 3.52249, 1116, 'DraenorShadowGlade'),
(@GAME_TELE_ID_START + 19, 596.594, 2410.67, 196.983, 3.76597, 1116, 'DraenorTerrokarPass'),
-- nagrand
(@GAME_TELE_ID_START + 20, 3324.23, 4759.55, 124.411, 1.3061, 1116, 'DraenorNagrand'),
(@GAME_TELE_ID_START + 21, 2000.47, 5057.39, 193.49, 3.05203, 1116, 'DraenorGatesOfGrommash'),
(@GAME_TELE_ID_START + 22, 2693.53, 6341.21, 48.8304, 3.60574, 1116, 'DraenorSpiritWoods'),
(@GAME_TELE_ID_START + 23, 3659.56, 7226.28, 10.4416, 2.00588, 1116, 'DraenorHighmaul'),
-- gorgrond
(@GAME_TELE_ID_START + 24, 6803.53, 1219.95, 69.6852, 5.61794, 1116, 'DraenorGorgrond'),
(@GAME_TELE_ID_START + 25, 7242.45, 902.165, 76.8599, 1.38465, 1116, 'DraenorSteamburstCauldron'),
(@GAME_TELE_ID_START + 26, 6847.86, 418.138, 79.4367, 3.69765, 1116, 'DraenorEverbloomWilds'),
(@GAME_TELE_ID_START + 27, 6126.31, 528.017, 16.2278, 5.23311, 1116, 'DraenorCrimsonFen'),
(@GAME_TELE_ID_START + 28, 5536.02, 1189.81, 93.15, 5.79781, 1116, 'DraenorRazorbloom'),
(@GAME_TELE_ID_START + 29, 5406.03, 1922.05, 171.85, 5.24411, 1116, 'DraenorGorgrondPass'),
-- tanaan junngle
(@GAME_TELE_ID_START + 30, 3549, -2126.4, 17.7437, 0.287412, 1116, 'DraenorBarrierSea');
