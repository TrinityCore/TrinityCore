-- 
DELETE FROM `creature` WHERE `guid` IN(78207,78208,78209,78210,78211,97536,97593,97647,97648,97649);
INSERT INTO creature (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(78207, 30352, 571, 0, 0, 1, 1, 0, 0, 7642.397, 2065.035, 600.3427, 1.117011, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Skybreaker Marine (Area: -Unknown-) (Auras: 59660 - Inside Cloak Dome, Individual)
(78208, 30352, 571, 0, 0, 1, 1, 0, 0, 7640.947, 2066.576, 600.3427, 0.296706, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Skybreaker Marine (Area: -Unknown-) (Auras: 59660 - Inside Cloak Dome, Individual)
(78209, 30352, 571, 0, 0, 1, 1, 0, 0, 7623.698, 2045.048, 600.5334, 4.45059, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Skybreaker Marine (Area: -Unknown-) (Auras: 59660 - Inside Cloak Dome, Individual)
(78210, 31648, 571, 0, 0, 1, 1, 0, 0, 7624.706, 2059.861, 600.3425, 3.368485, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Karen No (Area: -Unknown-) (Auras: 59660 - Inside Cloak Dome, Individual)
(78211, 32274, 571, 0, 0, 1, 1, 0, 0, 7622.745, 2069.923, 600.3428, 3.909538, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Alliance Bomber Pilot (Area: -Unknown-) (Auras: 59660 - Inside Cloak Dome, Individual)
(97536, 32444, 571, 0, 0, 1, 1, 0, 0, 7632.007, 2060.202, 600.3427, 6.161012, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Kibli Killohertz (Area: -Unknown-) (Auras: 59660 - Inside Cloak Dome, Individual)
(97593, 32523, 571, 0, 0, 1, 1, 0, 0, 7634.357, 2045.982, 600.3427, 0.06981317, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Johnny Yes (Area: -Unknown-) (Auras: 59660 - Inside Cloak Dome, Individual)
(97647, 32524, 571, 0, 0, 1, 1, 0, 0, 7635.958, 2048.406, 600.3425, 5.061455, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Willy Maybe (Area: -Unknown-) (Auras: 59660 - Inside Cloak Dome, Individual)
(97648, 32525, 571, 0, 0, 1, 1, 0, 0, 7620.44, 2067.247, 600.3428, 2.216568, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Alliance Infra-green Bomber, Parked (Area: -Unknown-) (Auras: 59660 - Inside Cloak Dome, Individual)
(97649, 32526, 571, 0, 0, 1, 1, 0, 0, 7630.336, 2058.154, 600.3427, 2.426008, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463); -- Alliance Infra-green Engineer (Area: -Unknown-) (Auras: 59660 - Inside Cloak Dome, Individual)

DELETE FROM `creature_addon` WHERE `guid` IN(78207,78208,78209,78210,78211,97536,97593,97647,97648,97649);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(78207, 0, 0, 65536, 257, 0, ""), -- Skybreaker Marine - 59660 - Inside Cloak Dome, Individual
(78208, 0, 0, 65536, 257, 0, ""), -- Skybreaker Marine - 59660 - Inside Cloak Dome, Individual
(78209, 0, 0, 65536, 257, 0, ""), -- Skybreaker Marine - 59660 - Inside Cloak Dome, Individual
(78210, 0, 0, 65536, 1, 0, ""), -- Karen No - 59660 - Inside Cloak Dome, Individual
(78211, 0, 0, 65536, 1, 0, ""), -- Alliance Bomber Pilot - 59660 - Inside Cloak Dome, Individual
(97536, 0, 0, 65536, 1, 0, ""), -- Kibli Killohertz - 59660 - Inside Cloak Dome, Individual
(97593, 0, 0, 65536, 1, 0, ""), -- Johnny Yes - 59660 - Inside Cloak Dome, Individual
(97647, 0, 0, 65536, 1, 0, ""), -- Willy Maybe - 59660 - Inside Cloak Dome, Individual
(97648, 0, 0, 50397184, 1, 0, ""), -- Alliance Infra-green Bomber, Parked - 59660 - Inside Cloak Dome, Individual
(97649, 0, 0, 65536, 1, 0, ""); -- Alliance Infra-green Engineer - 59660 - Inside Cloak Dome, Individual

SET @OGUID := 85147;
DELETE FROM gameobject WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+74;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 193719, 571, 210, 4510, 1, 1, 7642.188, 2066.252, 601.5114, 4.319694, 0.3292384, -0.6257801, -0.5436525, 0.452154, 120, 255, 1, 21463), -- Doodad_gunshopdynamite01 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+1, 193758, 571, 210, 4510, 1, 1, 7628.88, 2060.108, 600.4948, 4.721116, 0, 0, -0.7040148, 0.7101853, 120, 255, 1, 21463), -- Doodad_thronerailing05 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+2, 193705, 571, 210, 4510, 1, 1, 7641.539, 2066.838, 601.4728, 0.4014249, 0, 0, 0.1993675, 0.9799248, 120, 255, 1, 21463), -- Doodad_gunshopmortarshell01 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+3, 193764, 571, 210, 4510, 1, 1, 7625.869, 2060.053, 604.2698, 0.07854, 0, 0, 0.03925991, 0.9992291, 120, 255, 1, 21463), -- Doodad_battlefieldbanneralliance_static_wall02 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+4, 193704, 571, 210, 4510, 1, 1, 7642.364, 2067.464, 601.4591, 3.395874, 0.05676365, 0.01450825, -0.9901714, 0.1269958, 120, 255, 1, 21463), -- Doodad_gunshopbomb03 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+5, 193707, 571, 210, 4510, 1, 1, 7639.48, 2069.832, 600.6568, 2.347469, 0, 0, 0.9222012, 0.3867105, 120, 255, 1, 21463), -- Doodad_thronerailing01 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+6, 193766, 571, 210, 4510, 1, 1, 7637.411, 2072.358, 600.2718, 1.248237, 0.5122056, 0.3577566, 0.4621201, 0.6293653, 120, 255, 1, 21463), -- Doodad_shield_pvpalliance01 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+7, 193720, 571, 210, 4510, 1, 1, 7639.406, 2049.981, 600.6811, 0.7504887, 0, 0, 0.3664999, 0.9304181, 120, 255, 1, 21463), -- Doodad_thronerailing02 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+8, 193706, 571, 210, 4510, 1, 1, 7642.216, 2066.698, 601.4728, 5.715955, 0, 0, -0.2798281, 0.9600501, 120, 255, 1, 21463), -- Doodad_gunshopmortarshell02 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+9, 193761, 571, 210, 4510, 1, 1, 7629.734, 2062.715, 600.2579, 2.95833, 0, 0, 0.9958048, 0.09150324, 120, 255, 1, 21463), -- Doodad_stormwindcrate05 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+10, 193715, 571, 210, 4510, 1, 1, 7642.14, 2051.818, 600.2618, 5.349435, 0, 0, -0.450098, 0.8929791, 120, 255, 1, 21463), -- Doodad_gunshopbomb04 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+11, 193754, 571, 210, 4510, 1, 1, 7630.588, 2060.198, 600.1646, 0.01745246, 0, 0, 0.00872612, 0.9999619, 120, 255, 1, 21463), -- Doodad_g_gnometerminal01 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+12, 193701, 571, 210, 4510, 1, 1, 7642.834, 2067.318, 600.2566, 3.700098, 0, 0, -0.9612617, 0.2756371, 120, 255, 1, 21463), -- Doodad_gnometable01 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+13, 193760, 571, 210, 4510, 1, 1, 7630.542, 2062.55, 600.2484, 4.249877, 0, 0, -0.8503523, 0.5262138, 120, 255, 1, 21463), -- Doodad_stormwindcrate04 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+14, 193757, 571, 210, 4510, 1, 1, 7628.604, 2060.201, 599.632, 4.616396, 0, 0, -0.7402182, 0.6723668, 120, 255, 1, 21463), -- Doodad_battlefieldbanneralliancestatusbar2min01 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+15, 193763, 571, 210, 4510, 1, 1, 7625.772, 2060.065, 600.8868, 0.06389178, 0, 0, 0.03194046, 0.9994898, 120, 255, 1, 21463), -- Doodad_vr_bm_wood_01 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+16, 193711, 571, 210, 4510, 1, 1, 7645.835, 2061.109, 600.2529, 3.848451, 0, 0, -0.9381914, 0.3461168, 120, 255, 1, 21463), -- Doodad_gnomehazardlightred02 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+17, 193756, 571, 210, 4510, 1, 1, 7628.604, 2060.201, 598.5339, 6.143559, 0, 0, -0.06975651, 0.9975641, 120, 255, 1, 21463), -- Doodad_g_hologrambasetanaris01 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+18, 193703, 571, 210, 4510, 1, 1, 7642.847, 2067.183, 601.4788, 2.181656, -0.1823864, 0.0442028, 0.8750734, 0.4461253, 120, 255, 1, 21463), -- Doodad_gunshopbomb02 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+19, 193762, 571, 210, 4510, 1, 1, 7625.664, 2060.036, 604.1954, 3.228859, 0, 0, -0.9990482, 0.04361926, 120, 255, 1, 21463), -- Doodad_battlefieldbanneralliance_static_wall01 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+20, 193759, 571, 210, 4510, 1, 1, 7629.982, 2061.771, 600.2438, 3.351047, 0, 0, -0.9945211, 0.1045355, 120, 255, 1, 21463), -- Doodad_stormwindcrate03 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+21, 193702, 571, 210, 4510, 1, 1, 7643.083, 2067.654, 601.4622, 3.307401, -0.08287525, 0.04249382, -0.9925499, 0.07855374, 120, 255, 1, 21463), -- Doodad_gunshopbomb01 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+22, 193726, 571, 210, 4510, 1, 1, 7644.185, 2052.059, 600.2386, 2.085668, 0, 0, 0.8638353, 0.5037743, 120, 255, 1, 21463), -- Doodad_gunshopbomb12 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+23, 193718, 571, 210, 4510, 1, 1, 7641.954, 2051.513, 600.2402, 2.923416, 0, 0, 0.9940557, 0.1088722, 120, 255, 1, 21463), -- Doodad_gunshopbomb07 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+24, 193697, 571, 210, 4510, 1, 1, 7635.758, 2074.88, 600.2704, 3.33359, 0, 0, -0.9953957, 0.09585124, 120, 255, 1, 21463), -- Doodad_stormwindcrate02 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+25, 193721, 571, 210, 4510, 1, 1, 7636.481, 2046.313, 600.1296, 2.094393, 0, 0, 0.866025, 0.5000008, 120, 255, 1, 21463), -- Doodad_gnometable02 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+26, 193696, 571, 210, 4510, 1, 1, 7637.641, 2074.039, 600.2725, 2.609261, 0, 0, 0.9647865, 0.2630341, 120, 255, 1, 21463), -- Doodad_stormwindcrate01 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+27, 193984, 571, 210, 4510, 1, 1, 7647.473, 2055.554, 599.3989, 6.003934, 0, 0, -0.1391726, 0.9902682, 120, 255, 1, 21463), -- Alliance Banner (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+28, 193713, 571, 210, 4510, 1, 1, 7642.541, 2051.884, 600.25, 1.844759, 0.05028915, 0.2018385, 0.7698412, 0.6033877, 120, 255, 1, 21463), -- Doodad_deadminepowderkeg01 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+29, 193699, 571, 210, 4510, 1, 1, 7637.206, 2073.309, 601.4195, 4.347476, 0.06531382, 0.673378, -0.3379927, 0.6542608, 120, 255, 1, 21463), -- Doodad_humansword01 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+30, 193712, 571, 210, 4510, 1, 1, 7642.718, 2051.59, 600.2614, 1.710422, 0, 0, 0.7547092, 0.6560594, 120, 255, 1, 21463), -- Doodad_gunshopdynamitebundle01 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+31, 193738, 571, 210, 4510, 1, 1, 7621.407, 2072.642, 601.4335, 1.954769, 0, 0, 0.8290377, 0.5591928, 120, 255, 1, 21463), -- Doodad_gunshopmortarshell03 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+32, 193723, 571, 210, 4510, 1, 1, 7636.346, 2046.305, 601.3502, 0.5759577, -0.09489918, 0.1619043, 0.2869635, 0.9393791, 120, 255, 1, 21463), -- Doodad_gunshopbomb09 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+33, 193698, 571, 210, 4510, 1, 1, 7636.033, 2073.45, 600.2334, 4.354225, -0.005270004, -0.02503777, -0.8212976, 0.5699259, 120, 255, 1, 21463), -- Doodad_barrel01 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+34, 193984, 571, 210, 4510, 1, 1, 7647.418, 2065.228, 599.3082, 0.2792516, 0, 0, 0.1391726, 0.9902682, 120, 255, 1, 21463), -- Alliance Banner (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+35, 193709, 571, 210, 4510, 1, 1, 7645.862, 2060.065, 601.1218, 4.642611, 0.6819983, -0.7313414, -0.0006885529, 0.004207443, 120, 255, 1, 21463), -- Doodad_gnomestructuralspotlight01 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+36, 193722, 571, 210, 4510, 1, 1, 7636.708, 2047.292, 601.3093, 3.010666, 0, 0, 0.997858, 0.06541648, 120, 255, 1, 21463), -- Doodad_gunshopbomb08 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+37, 193708, 571, 210, 4510, 1, 1, 7636.178, 2073.495, 601.4435, 3.420848, -0.2174191, -0.08422661, -0.9611683, 0.1476155, 120, 255, 1, 21463), -- Doodad_dalaran_helm_deepdivehelm_space01 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+38, 193714, 571, 210, 4510, 1, 1, 7642.293, 2051.724, 600.264, 4.860743, 0, 0, -0.6527596, 0.7575652, 120, 255, 1, 21463), -- Doodad_crate01 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+39, 193725, 571, 210, 4510, 1, 1, 7644.375, 2052.462, 600.2384, 4.598945, 0, 0, -0.7460566, 0.6658826, 120, 255, 1, 21463), -- Doodad_gunshopbomb11 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+40, 193700, 571, 210, 4510, 1, 1, 7638.745, 2073.49, 600.2512, 1.247908, 0, 0, 0.5842485, 0.8115748, 120, 255, 1, 21463), -- Doodad_gunshoppowderkegopen01 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+41, 193717, 571, 210, 4510, 1, 1, 7642.185, 2051.599, 600.4606, 5.174902, 0, 0, -0.5262136, 0.8503524, 120, 255, 1, 21463), -- Doodad_gunshopbomb06 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+42, 193724, 571, 210, 4510, 1, 1, 7644.042, 2052.387, 600.233, 0.7068561, 0.03858662, -0.1408815, 0.3406696, 0.9287667, 120, 255, 1, 21463), -- Doodad_gunshopbomb10 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+43, 193710, 571, 210, 4510, 1, 1, 7645.787, 2059.069, 600.2527, 5.244716, 0, 0, -0.4962158, 0.8681992, 120, 255, 1, 21463), -- Doodad_gnomehazardlightred01 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+44, 193716, 571, 210, 4510, 1, 1, 7642.394, 2051.588, 600.24, 3.639014, 0, 0, -0.9692307, 0.2461543, 120, 255, 1, 21463), -- Doodad_gunshopbomb05 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+45, 193727, 571, 210, 4510, 1, 1, 7629.876, 2076.93, 600.2466, 0.5846839, 0, 0, 0.2881956, 0.9575716, 120, 255, 1, 21463), -- Doodad_gnomehazardlightred03 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+46, 193765, 571, 210, 4510, 1, 1, 7635.557, 2046.72, 601.6681, 1.26947, -0.03150654, 0.07753849, 0.5895319, 0.8033973, 120, 255, 1, 21463), -- Doodad_bow_crossbow_pvpalliance_a_01 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+47, 193751, 571, 210, 4510, 1, 1, 7614.736, 2052.607, 601.3495, 5.52397, 0.0257082, 0.1858978, -0.356205, 0.9153683, 120, 255, 1, 21463), -- Doodad_gunshopbomb13 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+48, 193737, 571, 210, 4510, 1, 1, 7620.95, 2073.946, 600.2172, 5.253442, 0, 0, -0.4924231, 0.870356, 120, 255, 1, 21463), -- Doodad_gnometable03 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+49, 193750, 571, 210, 4510, 1, 1, 7614.776, 2052.477, 600.1286, 0.7592169, 0, 0, 0.3705568, 0.9288098, 120, 255, 1, 21463), -- Doodad_gnometable04 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+50, 193729, 571, 210, 4510, 1, 1, 7627.838, 2076.871, 600.2466, 5.471607, 0, 0, -0.3947439, 0.9187912, 120, 255, 1, 21463), -- Doodad_gnomehazardlightred04 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+51, 193736, 571, 210, 4510, 1, 1, 7618.226, 2070.371, 600.5572, 3.892087, 0, 0, -0.9304171, 0.3665025, 120, 255, 1, 21463), -- Doodad_thronerailing03 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+52, 193753, 571, 210, 4510, 1, 1, 7615, 2053.275, 601.3189, 4.834563, -0.07124805, -0.1183796, -0.6536837, 0.7440481, 120, 255, 1, 21463), -- Doodad_gunshopbomb15 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+53, 193728, 571, 210, 4510, 1, 1, 7628.878, 2076.953, 601.1158, 6.265767, 0.9999533, -0.008717537, 0.002464294, 0.003374091, 120, 255, 1, 21463), -- Doodad_gnomestructuralspotlight02 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+54, 193739, 571, 210, 4510, 1, 1, 7621.291, 2074.292, 601.4191, 0.1570771, 0, 0, 0.07845783, 0.9969174, 120, 255, 1, 21463), -- Doodad_gunshopmortarshell04 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+55, 193752, 571, 210, 4510, 1, 1, 7614.638, 2053.234, 601.3213, 4.153885, 0, 0, -0.8746195, 0.4848101, 120, 255, 1, 21463), -- Doodad_gunshopbomb14 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+56, 193731, 571, 210, 4510, 1, 1, 7613.702, 2066.874, 600.3386, 5.733425, -0.6246157, 0.3538227, 0.5999422, 0.3531771, 120, 255, 1, 21463), -- Doodad_gunshopdynamitebundle03 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+57, 193744, 571, 210, 4510, 1, 1, 7611.466, 2060.243, 601.0989, 1.474833, 0.7402067, 0.6723661, 0.004041672, 0.00119604, 120, 255, 1, 21463), -- Doodad_gnomestructuralspotlight04 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+58, 193755, 571, 210, 4510, 1, 1, 7617.735, 2050.136, 600.6691, 5.480334, 0, 0, -0.3907309, 0.920505, 120, 255, 1, 21463), -- Doodad_thronerailing04 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+59, 193730, 571, 210, 4510, 1, 1, 7613.633, 2067.524, 600.2297, 2.809975, 0, 0, 0.9862852, 0.1650499, 120, 255, 1, 21463), -- Doodad_gunshopdynamitebundle02 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+60, 193741, 571, 210, 4510, 1, 1, 7628.472, 2043.349, 601.0817, 3.097993, -0.02180719, -0.999753, -0.00331974, 0.002718635, 120, 255, 1, 21463), -- Doodad_gnomestructuralspotlight03 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+61, 193747, 571, 210, 4510, 1, 1, 7619.736, 2046.999, 600.1399, 4.127707, 0, 0, -0.8808899, 0.4733212, 120, 255, 1, 21463), -- Doodad_oildrum01 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+62, 193733, 571, 210, 4510, 1, 1, 7614.119, 2068.628, 600.2443, 2.862335, 0, 0, 0.9902678, 0.1391754, 120, 255, 1, 21463), -- Doodad_crate02 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+63, 193740, 571, 210, 4510, 1, 1, 7620.102, 2074.375, 601.4209, 6.012661, 0, 0, -0.1348505, 0.9908659, 120, 255, 1, 21463), -- Doodad_gunshopmortarshell05 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+64, 193732, 571, 210, 4510, 1, 1, 7613.58, 2067.849, 600.3611, 0.7589362, 0.7104883, 0.04713154, -0.7010336, 0.03920263, 120, 255, 1, 21463), -- Doodad_gunshopdynamitebundle04 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+65, 193743, 571, 210, 4510, 1, 1, 7629.514, 2043.403, 600.2165, 2.303831, 0, 0, 0.9135447, 0.4067384, 120, 255, 1, 21463), -- Doodad_gnomehazardlightred06 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+66, 193749, 571, 210, 4510, 1, 1, 7621.336, 2045.823, 600.0079, 5.864307, 0, 0, -0.2079115, 0.9781476, 120, 255, 1, 21463), -- Doodad_oildrum03 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+67, 193735, 571, 210, 4510, 1, 1, 7613.965, 2068.401, 600.2634, 5.41052, 0.1816483, -0.0515995, -0.4201708, 0.8875798, 120, 255, 1, 21463), -- Doodad_gunshopdynamitebundle06 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+68, 193742, 571, 210, 4510, 1, 1, 7627.475, 2043.398, 600.2156, 3.700098, 0, 0, -0.9612617, 0.2756371, 120, 255, 1, 21463), -- Doodad_gnomehazardlightred05 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+69, 193748, 571, 210, 4510, 1, 1, 7621.169, 2048.11, 600.0346, 3.194002, 0, 0, -0.9996567, 0.02620165, 120, 255, 1, 21463), -- Doodad_oildrum02 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+70, 193734, 571, 210, 4510, 1, 1, 7614.18, 2069.15, 600.2694, 2.277706, 0.4829254, 0.5232553, -0.4815292, 0.5109956, 120, 255, 1, 21463), -- Doodad_gunshopdynamitebundle05 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+71, 193745, 571, 210, 4510, 1, 1, 7611.443, 2061.459, 600.2303, 2.076939, 0, 0, 0.8616285, 0.5075394, 120, 255, 1, 21463), -- Doodad_gnomehazardlightred07 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+72, 193984, 571, 210, 4510, 1, 1, 7609.858, 2055.526, 599.4938, 3.42085, 0, 0, -0.9902678, 0.1391754, 120, 255, 1, 21463), -- Alliance Banner (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+73, 193984, 571, 210, 4510, 1, 1, 7610.175, 2065.307, 599.4262, 2.879789, 0, 0, 0.9914446, 0.1305283, 120, 255, 1, 21463), -- Alliance Banner (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)
(@OGUID+74, 193746, 571, 210, 4510, 1, 1, 7611.341, 2059.421, 600.2303, 0.6806767, 0, 0, 0.333806, 0.9426418, 120, 255, 1, 21463); -- Doodad_gnomehazardlightred08 (Area: Aldur'thar: The Desolation Gate - Difficulty: 0)

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+74;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`) VALUES
(@OGUID+0, 0, 0, 0.9999905, 0.004363511), -- Doodad_gunshopdynamite01
(@OGUID+1, 0, 0, 0.9999905, 0.004363511), -- Doodad_thronerailing05
(@OGUID+2, 0, 0, 0.9999905, 0.004363511), -- Doodad_gunshopmortarshell01
(@OGUID+3, 0, 0, 0.9999905, 0.004363511), -- Doodad_battlefieldbanneralliance_static_wall02
(@OGUID+4, 0, 0, 0.9999905, 0.004363511), -- Doodad_gunshopbomb03
(@OGUID+5, 0, 0, 0.9999905, 0.004363511), -- Doodad_thronerailing01
(@OGUID+6, 0, 0, 0.9999905, 0.004363511), -- Doodad_shield_pvpalliance01
(@OGUID+7, 0, 0, 0.9999905, 0.004363511), -- Doodad_thronerailing02
(@OGUID+8, 0, 0, 0.9999905, 0.004363511), -- Doodad_gunshopmortarshell02
(@OGUID+9, 0, 0, 0.9999905, 0.004363511), -- Doodad_stormwindcrate05
(@OGUID+10, 0, 0, 0.9999905, 0.004363511), -- Doodad_gunshopbomb04
(@OGUID+11, 0, 0, 0.9999905, 0.004363511), -- Doodad_g_gnometerminal01
(@OGUID+12, 0, 0, 0.9999905, 0.004363511), -- Doodad_gnometable01
(@OGUID+13, 0, 0, 0.9999905, 0.004363511), -- Doodad_stormwindcrate04
(@OGUID+14, 0, 0, 0.9999905, 0.004363511), -- Doodad_battlefieldbanneralliancestatusbar2min01
(@OGUID+15, 0, 0, 0.9999905, 0.004363511), -- Doodad_vr_bm_wood_01
(@OGUID+16, 0, 0, 0.9999905, 0.004363511), -- Doodad_gnomehazardlightred02
(@OGUID+17, 0, 0, 0.9999905, 0.004363511), -- Doodad_g_hologrambasetanaris01
(@OGUID+18, 0, 0, 0.9999905, 0.004363511), -- Doodad_gunshopbomb02
(@OGUID+19, 0, 0, 0.9999905, 0.004363511), -- Doodad_battlefieldbanneralliance_static_wall01
(@OGUID+20, 0, 0, 0.9999905, 0.004363511), -- Doodad_stormwindcrate03
(@OGUID+21, 0, 0, 0.9999905, 0.004363511), -- Doodad_gunshopbomb01
(@OGUID+22, 0, 0, 0.9999905, 0.004363511), -- Doodad_gunshopbomb12
(@OGUID+23, 0, 0, 0.9999905, 0.004363511), -- Doodad_gunshopbomb07
(@OGUID+24, 0, 0, 0.9999905, 0.004363511), -- Doodad_stormwindcrate02
(@OGUID+25, 0, 0, 0.9999905, 0.004363511), -- Doodad_gnometable02
(@OGUID+26, 0, 0, 0.9999905, 0.004363511), -- Doodad_stormwindcrate01
(@OGUID+28, 0, 0, 0.9999905, 0.004363511), -- Doodad_deadminepowderkeg01
(@OGUID+29, 0, 0, 0.9999905, 0.004363511), -- Doodad_humansword01
(@OGUID+30, 0, 0, 0.9999905, 0.004363511), -- Doodad_gunshopdynamitebundle01
(@OGUID+31, 0, 0, 0.9999905, 0.004363511), -- Doodad_gunshopmortarshell03
(@OGUID+32, 0, 0, 0.9999905, 0.004363511), -- Doodad_gunshopbomb09
(@OGUID+33, 0, 0, 0.9999905, 0.004363511), -- Doodad_barrel01
(@OGUID+35, 0, 0, 0.9999905, 0.004363511), -- Doodad_gnomestructuralspotlight01
(@OGUID+36, 0, 0, 0.9999905, 0.004363511), -- Doodad_gunshopbomb08
(@OGUID+37, 0, 0, 0.9999905, 0.004363511), -- Doodad_dalaran_helm_deepdivehelm_space01
(@OGUID+38, 0, 0, 0.9999905, 0.004363511), -- Doodad_crate01
(@OGUID+39, 0, 0, 0.9999905, 0.004363511), -- Doodad_gunshopbomb11
(@OGUID+40, 0, 0, 0.9999905, 0.004363511), -- Doodad_gunshoppowderkegopen01
(@OGUID+41, 0, 0, 0.9999905, 0.004363511), -- Doodad_gunshopbomb06
(@OGUID+42, 0, 0, 0.9999905, 0.004363511), -- Doodad_gunshopbomb10
(@OGUID+43, 0, 0, 0.9999905, 0.004363511), -- Doodad_gnomehazardlightred01
(@OGUID+44, 0, 0, 0.9999905, 0.004363511), -- Doodad_gunshopbomb05
(@OGUID+45, 0, 0, 0.9999905, 0.004363511), -- Doodad_gnomehazardlightred03
(@OGUID+46, 0, 0, 0.9999905, 0.004363511), -- Doodad_bow_crossbow_pvpalliance_a_01
(@OGUID+47, 0, 0, 0.9999905, 0.004363511), -- Doodad_gunshopbomb13
(@OGUID+48, 0, 0, 0.9999905, 0.004363511), -- Doodad_gnometable03
(@OGUID+49, 0, 0, 0.9999905, 0.004363511), -- Doodad_gnometable04
(@OGUID+50, 0, 0, 0.9999905, 0.004363511), -- Doodad_gnomehazardlightred04
(@OGUID+51, 0, 0, 0.9999905, 0.004363511), -- Doodad_thronerailing03
(@OGUID+52, 0, 0, 0.9999905, 0.004363511), -- Doodad_gunshopbomb15
(@OGUID+53, 0, 0, 0.9999905, 0.004363511), -- Doodad_gnomestructuralspotlight02
(@OGUID+54, 0, 0, 0.9999905, 0.004363511), -- Doodad_gunshopmortarshell04
(@OGUID+55, 0, 0, 0.9999905, 0.004363511), -- Doodad_gunshopbomb14
(@OGUID+56, 0, 0, 0.9999905, 0.004363511), -- Doodad_gunshopdynamitebundle03
(@OGUID+57, 0, 0, 0.9999905, 0.004363511), -- Doodad_gnomestructuralspotlight04
(@OGUID+58, 0, 0, 0.9999905, 0.004363511), -- Doodad_thronerailing04
(@OGUID+59, 0, 0, 0.9999905, 0.004363511), -- Doodad_gunshopdynamitebundle02
(@OGUID+60, 0, 0, 0.9999905, 0.004363511), -- Doodad_gnomestructuralspotlight03
(@OGUID+61, 0, 0, 0.9999905, 0.004363511), -- Doodad_oildrum01
(@OGUID+62, 0, 0, 0.9999905, 0.004363511), -- Doodad_crate02
(@OGUID+63, 0, 0, 0.9999905, 0.004363511), -- Doodad_gunshopmortarshell05
(@OGUID+64, 0, 0, 0.9999905, 0.004363511), -- Doodad_gunshopdynamitebundle04
(@OGUID+65, 0, 0, 0.9999905, 0.004363511), -- Doodad_gnomehazardlightred06
(@OGUID+66, 0, 0, 0.9999905, 0.004363511), -- Doodad_oildrum03
(@OGUID+67, 0, 0, 0.9999905, 0.004363511), -- Doodad_gunshopdynamitebundle06
(@OGUID+68, 0, 0, 0.9999905, 0.004363511), -- Doodad_gnomehazardlightred05
(@OGUID+69, 0, 0, 0.9999905, 0.004363511), -- Doodad_oildrum02
(@OGUID+70, 0, 0, 0.9999905, 0.004363511), -- Doodad_gunshopdynamitebundle05
(@OGUID+71, 0, 0, 0.9999905, 0.004363511), -- Doodad_gnomehazardlightred07
(@OGUID+74, 0, 0, 0.9999905, 0.004363511); -- Doodad_gnomehazardlightred08
