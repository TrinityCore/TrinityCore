SET @CGUID := 210119019;

UPDATE creature_template SET `ScriptName` = 'boss_king_ranulf' WHERE `entry` = 97083;
UPDATE creature_template SET `ScriptName` = 'boss_king_haldor' WHERE `entry` = 95843;
UPDATE creature_template SET `ScriptName` = 'boss_king_bjorn' WHERE `entry` = 97081;
UPDATE creature_template SET `ScriptName` = 'boss_king_tor' WHERE `entry` = 97084;
UPDATE creature_template SET `ScriptName` = 'boss_god_king_kovald' WHERE `entry` = 95675;
UPDATE creature_template SET `ScriptName` = 'npc_aegis_of_aggramar' WHERE `entry` = 98364;
UPDATE creature_template SET `ScriptName` = 'npc_flame_of_woe' WHERE `entry` = 104822;
UPDATE creature_template SET npcflag = npcflag | 1, `ScriptName` = 'npc_halls_of_valor' WHERE `entry` = 101712;
UPDATE creature_template SET npcflag = npcflag | 1, `ScriptName` = 'npc_field_of_eternal_hunt' WHERE `entry` = 101697;
UPDATE creature_template SET `ScriptName` = 'boss_fenryr' WHERE `entry` IN (99868, 95674);
UPDATE creature_template SET `ScriptName` = 'boss_hymdall' WHERE `entry` = 94960;
UPDATE creature_template SET `ScriptName` = 'boss_hyrja' WHERE `entry` = 95833;
UPDATE creature_template SET `ScriptName` = 'npc_olmyr_the_enlightened' WHERE `entry` = 97202;
UPDATE creature_template SET `ScriptName` = 'npc_olmyr_ghost' WHERE `entry` = 102557;
UPDATE creature_template SET `ScriptName` = 'npc_solsten' WHERE `entry` = 97219;
UPDATE creature_template SET `ScriptName` = 'npc_solsten_ghost' WHERE `entry` = 102558;
UPDATE creature_template SET `ScriptName` = 'boss_odyn_hov' WHERE `entry` = 95676;
UPDATE creature_template SET `ScriptName` = 'npc_spear_of_light' WHERE `entry` = 100575;

UPDATE creature_template SET unit_flags = 0 WHERE entry IN (95675, 95833);
UPDATE creature_template SET flags_extra = 128 WHERE entry = 97795;
UPDATE creature_template SET inhabitType = 4 WHERE entry IN (97068, 96648, 97788);

UPDATE creature_template SET modelid1 = 47641 WHERE entry IN (101712, 101697);

UPDATE areatrigger_template SET `ScriptName` = 'at_center_eye_of_the_storm' WHERE `ID` = 10675;
UPDATE areatrigger_template SET `ScriptName` = 'at_eye_of_the_storm' WHERE `ID` = 10374;
UPDATE areatrigger_template SET `ScriptName` = 'at_sanctify' WHERE `ID` = 9601;
UPDATE areatrigger_template SET `ScriptName` = 'areatrigger_aegis_of_aggramar' WHERE `ID` = 9758;
UPDATE areatrigger_template SET `ScriptName` = 'areatrigger_infernal_flames' WHERE `ID` = 9758;
-- UPDATE areatrigger_template SET `ScriptName` = 'areatrigger_flame_of_woe' WHERE `ID` = ;
UPDATE areatrigger_template SET `ScriptName` = 'areatrigger_dancing_blade' WHERE `ID` = 9700;

UPDATE areatrigger_template SET `ScriptName` = 'areatrigger_runic_mark_1' WHERE `ID` = 10111;
UPDATE areatrigger_template SET `ScriptName` = 'areatrigger_runic_mark_2' WHERE `ID` = 10112;
UPDATE areatrigger_template SET `ScriptName` = 'areatrigger_runic_mark_3' WHERE `ID` = 10113;
UPDATE areatrigger_template SET `ScriptName` = 'areatrigger_runic_mark_4' WHERE `ID` = 10116;
UPDATE areatrigger_template SET `ScriptName` = 'areatrigger_runic_mark_5' WHERE `ID` = 10117;
UPDATE areatrigger_template SET `ScriptName` = 'areatrigger_spear_of_light' WHERE `ID` = 10398;
UPDATE areatrigger_template SET `ScriptName` = 'areatrigger_glowing_fragment' WHERE `ID` = 10126;

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_kovald_ragnarok';
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_kovald_infernal_flames';
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_ravenous_leap_jump';
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_ravenous_leap';
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_expel_light';
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_sanctify';
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_odyn_spear_of_light';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(193828, 'spell_kovald_ragnarok'),
(193828, 'spell_kovald_infernal_flames'),
(196495, 'spell_ravenous_leap_jump'),
(197560, 'spell_ravenous_leap'),
(192048, 'spell_expel_light'),
(192307, 'spell_sanctify'),
(198072, 'spell_odyn_spear_of_light');

UPDATE `instance_template` SET `script` = 'instance_halls_of_valor' WHERE `map` = 1477;

DELETE FROM creature_template_addon WHERE entry IN (97960, 101712);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(97960, 0, 0, 0, 1, 0, 0, 0, 0, 193214),
(101712, 0, 0, 50331648, 1, 0, 0, 0, 0, 200611);

UPDATE `creature_template_addon` SET `auras` = '' WHERE (entry = 95676);

UPDATE creature_template set minlevel = 98, maxlevel = 110 where entry = 97960;
DELETE FROM `creature_template_scaling` WHERE Entry = 97960;
INSERT INTO `creature_template_scaling` (Entry, LevelScalingMin, LevelScalingMax, LevelScalingDeltaMin, LevelScalingDeltaMax, VerifiedBuild) VALUES
(97960, 98, 110, 0, 0, 26822);

DELETE FROM creature WHERE guid BETWEEN @CGUID+0 AND @CGUID+87;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0,  95833,  1477, 7672, 8374, 8388870, 0, 0, 0, 0, 3125.458, 301.2292, 662.8806, 0.7597455,     86400, 0, 0, 0, 0, 1, 0, 0, 0, 26822),
(@CGUID+1,  97202,  1477, 7672, 8374, 8388870, 0, 0, 0, 0, 3141.802, 362.5226, 655.2749, 4.665727,      86400, 0, 0, 0, 0, 1, 0, 0, 0, 26822),
(@CGUID+2,  97219,  1477, 7672, 8374, 8388870, 0, 0, 0, 0, 3191.19,  313.781,  655.185,  3.29767,       86400, 0, 0, 0, 1, 1, 0, 0, 0, 26822),
(@CGUID+4,  93628,  1477, 7672, 8374, 8388870, 0, 0, 0, 0, 3099.326, 294.2066, 662.8859, 0.6025264,     86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+5,  96648,  1477, 7672, 8374, 8388870, 0, 0, 0, 0, 3202.243, 262.4618, 679.0376, 2.189788,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+6,  96648,  1477, 7672, 8374, 8388870, 0, 0, 0, 0, 3109.546, 404.2726, 696.7025, 5.40562,       86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+7,  96648,  1477, 7672, 8374, 8388870, 0, 0, 0, 0, 3090.183, 390.5573, 683.3047, 5.999225,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+8,  96648,  1477, 7672, 8374, 8388870, 0, 0, 0, 0, 3121.077, 261.0451, 685.3596, 1.337977,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+9,  96648,  1477, 7672, 8374, 8388870, 0, 0, 0, 0, 3085.065, 305.2431, 680.6742, 0.3445246,     86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+10, 96648,  1477, 7672, 8374, 8388870, 0, 0, 0, 0, 3105.278, 257.2205, 676.7184, 1.319493,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+11, 96648,  1477, 7672, 8374, 8388870, 0, 0, 0, 0, 3071.859, 251.4965, 682.5523, 0.7387865,     86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+12, 95675,  1477, 7672, 0,    8388870, 0, 0, 0, 0, 2570.286, 529.0504, 748.7409, 3.12402,       86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+13, 101697, 1477, 7672, 8374, 8388870, 0, 0, 0, 0, 3226.241, 658.3748, 632.4739, 0,             86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),

(@CGUID+14, 99891,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3108.364, 3130.456, 645.662,  2.007022,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+15, 96640,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3152.325, 3158.274, 593.7058, 3.342544,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+16, 96677,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 2988.009, 3080.242, 605.7253, 4.821292,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+17, 96608,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3006.592, 3240.283, 583.4375, 1.167524,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+18, 96609,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3175.729, 3185.754, 593.6846, 5.82612,       86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+19, 96934,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3102.402, 3216.353, 593.9286, 2.665279,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+20, 96677,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 2990.385, 2996.81,  617.3197, 1.970357,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+21, 96608,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 2965.924, 3208.717, 585.6805, 3.638524,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+22, 96609,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3176.23,  2897.951, 642.3908, 6.004198,      86400, 10, 0, 0, 0, 1, 0, 0, 0, 26822),
(@CGUID+23, 96934,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3114.452, 3106.07,  597.3161, 0.8715216,     86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+24, 99891,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3070.403, 2919.993, 669.8699, 0.2005882,     86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+25, 96677,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3026.855, 3004.342, 610.5338, 2.967852,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+26, 96611,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3118.75,  3056.25,  606.4654, 5.204703,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+27, 96609,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3187.792, 2970.549, 630.9304, 0.5003395,     86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+28, 96611,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3114.619, 3031.219, 608.9849, 2.746219,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+29, 96608,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3012.537, 3198.001, 585.7324, 3.871046,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+30, 96609,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3156.301, 2972.819, 627.2949, 5.071684,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+31, 96609,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3168.899, 2954.561, 629.3716, 0.2048282,     86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+32, 99891,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3192.832, 2997.357, 646.3761, 4.369969,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+33, 96609,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3074.499, 3080.609, 600.7344, 3.07119,       86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+34, 96677,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3061.458, 3036.524, 609.004,  0.6470689,     86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+35, 96609,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3210.244, 2923.48,  642.4477, 2.138139,      86400, 10, 0, 0, 0, 1, 0, 0, 0, 26822),
(@CGUID+36, 96934,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3132.918, 3158.304, 594.0121, 5.518348,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+37, 96640,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3153.531, 3190.245, 596.5271, 2.67206,       86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+38, 99891,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3253.694, 3027.755, 719.0425, 3.925655,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+39, 99891,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 2968.141, 3180.446, 665.7894, 5.404263,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+40, 96609,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3055.991, 3208.112, 589.9724, 1.431607,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+41, 99804,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3119.981, 3108.459, 595.8796, 1.187427,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+42, 96608,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3004.933, 3194.095, 586.7813, 2.250853,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+43, 96609,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3137.069, 2981.776, 619.3815, 3.451296,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+44, 96611,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3078.754, 3063.355, 605.0632, 4.629012,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+45, 96608,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 2964.135, 3159.084, 594.6597, 2.42724,       86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+46, 96609,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 2929.016, 3176.897, 588.9922, 6.135307,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+47, 103801, 1477, 7672, 7983, 8388870, 0, 0, 0, 0, 2983.055, 2930.014, 623.9768, 0.3097917,     86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+48, 96611,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3046.574, 3071.953, 600.1761, 4.399072,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+49, 96608,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 2959.018, 3161.385, 593.8246, 5.745583,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+50, 96609,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3161.299, 2970.537, 627.3659, 2.564135,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+51, 96609,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3001.462, 3195.836, 586.4297, 0.2021952,     86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+52, 96934,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3116.21,  3199.719, 583.9505, 0.06312224,    86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+53, 96640,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3147.306, 3093.153, 600.7457, 1.874357,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+54, 101712, 1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3210.003, 2902.552, 641.6155, 0,             86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+55, 96677,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 2970.64,  3046.648, 609.4592, 6.187953,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+56, 96609,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3142.653, 3025.447, 615.4653, 0.7153816,     86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+57, 96934,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3170.637, 3171.837, 593.6865, 4.688684,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+58, 96608,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3008.288, 3247.439, 582.7926, 5.112173,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+59, 96609,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3079.189, 3237.634, 594.8312, 4.34477,       86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+60, 96608,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 2976.465, 3159.218, 593.6032, 2.690756,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+61, 96609,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3157.151, 2952.56,  626.1254, 5.622349,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+62, 99891,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 2911.087, 3263.498, 657.7855, 5.102743,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+63, 96611,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3145.285, 3164.481, 593.6871, 2.246225,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+64, 96608,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 2962.681, 3164.671, 593.3438, 4.53425,       86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+65, 96609,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 2962.385, 3161.536, 594.1614, 0.6099821,     86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+66, 95674,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3151.491, 3169.033, 593.6873, 3.649285,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+67, 96677,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3006.624, 2975.124, 619.3312, 1.319187,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+68, 96609,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3165.8,   2995.833, 625.5742, 0.07101943,    86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+69, 96640,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3162.625, 3177.84,  593.6879, 6.281768,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+70, 99891,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 2842.228, 3368.796, 544.73,   2.67967,       86400, 10, 0, 0, 0, 1, 0, 0, 0, 26822),
(@CGUID+71, 96640,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3136.608, 3179.172, 596.1287, 3.873443,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+72, 96677,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3021.997, 3088.107, 602.0958, 6.138111,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+73, 96934,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3151.308, 3088.412, 600.9352, 1.403002,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+74, 96640,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3142.265, 3088.888, 601.3049, 1.678789,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+75, 96611,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3098.232, 2980.897, 615.0662, 4.19891,       86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+76, 99804,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3112.595, 3109.339, 598.0712, 0.5585618,     86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+77, 96608,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 2999.883, 3197.819, 586.1385, 5.453282,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+78, 96609,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3128.556, 3001.693, 616.4182, 5.590447,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+79, 96611,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3167.089, 3147.725, 593.6871, 0.2719503,     86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+80, 96609,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3008.615, 3244.856, 583.092,  4.411496,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+81, 96609,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3052.924, 3260.185, 588.5292, 4.911764,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+82, 99891,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 3266.592, 3496.332, 595.6996, 5.203261,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+83, 96608,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 2964.142, 3258.143, 583.7546, 1.348737,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+84, 96608,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 2963.389, 3254.947, 583.5328, 3.227567,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+85, 96608,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 2975.866, 3258.893, 583.9348, 4.068028,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822),
(@CGUID+86, 99891,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 2975.452, 3641.51,  615.8069, 5.96041,       86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822);
-- (@CGUID+87, 99868,  1477, 7672, 7983, 8388870, 0, 0, 0, 0, 2922.05,  3235.689, 581.7946, 6.057084,      86400, 0, 0, 0, 0, 0, 0, 0, 0, 26822);

UPDATE creature SET spawnmask = 8388870 WHERE map = 1477;
UPDATE gameobject SET spawnmask = 8388870 WHERE map = 1477;

UPDATE `areatrigger_template` SET `VerifiedBuild`=26822 WHERE `Id`=10126;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26822 WHERE `Id`=10398;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26822 WHERE `Id`=9758;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26822 WHERE `Id`=3319;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26822 WHERE `Id`=10295;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26822 WHERE `Id`=9397;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26822 WHERE `Id`=12740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26822 WHERE `Id`=9583;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26822 WHERE `Id`=9582;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26822 WHERE `Id`=7020;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26822 WHERE `Id`=10357;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26822 WHERE `Id`=10235;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26822 WHERE `Id`=9601;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26822 WHERE `Id`=10374;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26822 WHERE `Id`=10675;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26822 WHERE `Id`=10196;
UPDATE `areatrigger_template` SET `Data0`=16, `Data1`=6, `Data3`=16, `Data4`=6, `VerifiedBuild`=26822 WHERE `Id`=9705;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26822 WHERE `Id`=9232;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26822 WHERE `Id`=9705;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26822 WHERE `Id`=9677;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26822 WHERE `Id`=9700;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26822 WHERE `Id`=10192;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26822 WHERE `Id`=12515;

UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=12500, `TimeToTargetScale`=12500, `VerifiedBuild`=26822 WHERE (`SpellMiscId`=5413 AND `AreaTriggerId`=10126); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=26822 WHERE (`SpellMiscId`=5691 AND `AreaTriggerId`=10398); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000, `VerifiedBuild`=26822 WHERE (`SpellMiscId`=5040 AND `AreaTriggerId`=9758); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=26822 WHERE (`SpellMiscId`=383 AND `AreaTriggerId`=3319); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=10000, `VerifiedBuild`=26822 WHERE (`SpellMiscId`=5578 AND `AreaTriggerId`=10295); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=6000, `VerifiedBuild`=26822 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=68828, `TimeToTargetScale`=0, `VerifiedBuild`=26822 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=120000, `VerifiedBuild`=26822 WHERE (`SpellMiscId`=2442 AND `AreaTriggerId`=7020); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=26822 WHERE (`SpellMiscId`=5649 AND `AreaTriggerId`=10357); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2806, `TimeToTargetScale`=0, `VerifiedBuild`=26822 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=25000, `VerifiedBuild`=26822 WHERE (`SpellMiscId`=5523 AND `AreaTriggerId`=10235); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=12000, `TimeToTargetScale`=12000, `VerifiedBuild`=26822 WHERE (`SpellMiscId`=4885 AND `AreaTriggerId`=9601); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=6680, `VerifiedBuild`=26822 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2800, `TimeToTargetScale`=0, `VerifiedBuild`=26822 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=26822 WHERE (`SpellMiscId`=4866 AND `AreaTriggerId`=9583); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=26822 WHERE (`SpellMiscId`=4865 AND `AreaTriggerId`=9582); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=9000, `VerifiedBuild`=26822 WHERE (`SpellMiscId`=5667 AND `AreaTriggerId`=10374); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=14000, `VerifiedBuild`=26822 WHERE (`SpellMiscId`=5987 AND `AreaTriggerId`=10675); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=6801, `VerifiedBuild`=26822 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=56000, `TimeToTargetScale`=0, `VerifiedBuild`=26822 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=10000, `VerifiedBuild`=26822 WHERE (`SpellMiscId`=5488 AND `AreaTriggerId`=10196); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2804, `TimeToTargetScale`=0, `VerifiedBuild`=26822 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=1500, `VerifiedBuild`=26822 WHERE (`SpellMiscId`=4960 AND `AreaTriggerId`=9705); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=12462, `TimeToTargetScale`=12000, `VerifiedBuild`=26822 WHERE (`SpellMiscId`=4987 AND `AreaTriggerId`=9232); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=10415, `TimeToTargetScale`=12000, `VerifiedBuild`=26822 WHERE (`SpellMiscId`=4492 AND `AreaTriggerId`=9232); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=6231, `TimeToTargetScale`=12000, `VerifiedBuild`=26822 WHERE (`SpellMiscId`=4987 AND `AreaTriggerId`=9232); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=10385, `TimeToTargetScale`=12000, `VerifiedBuild`=26822 WHERE (`SpellMiscId`=4987 AND `AreaTriggerId`=9232); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=7811, `TimeToTargetScale`=12000, `VerifiedBuild`=26822 WHERE (`SpellMiscId`=4492 AND `AreaTriggerId`=9232); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=3000, `VerifiedBuild`=26822 WHERE (`SpellMiscId`=4960 AND `AreaTriggerId`=9705); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=3000, `VerifiedBuild`=26822 WHERE (`SpellMiscId`=4964 AND `AreaTriggerId`=9705); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=6923, `TimeToTargetScale`=12000, `VerifiedBuild`=26822 WHERE (`SpellMiscId`=4987 AND `AreaTriggerId`=9232); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=8927, `TimeToTargetScale`=12000, `VerifiedBuild`=26822 WHERE (`SpellMiscId`=4492 AND `AreaTriggerId`=9232); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=26822 WHERE (`SpellMiscId`=4961 AND `AreaTriggerId`=9677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=15643, `TimeToTargetScale`=12000, `VerifiedBuild`=26822 WHERE (`SpellMiscId`=4987 AND `AreaTriggerId`=9232); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=3868, `TimeToTargetScale`=12000, `VerifiedBuild`=26822 WHERE (`SpellMiscId`=4492 AND `AreaTriggerId`=9232); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=3438, `TimeToTargetScale`=12000, `VerifiedBuild`=26822 WHERE (`SpellMiscId`=4492 AND `AreaTriggerId`=9232); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=13408, `TimeToTargetScale`=12000, `VerifiedBuild`=26822 WHERE (`SpellMiscId`=4987 AND `AreaTriggerId`=9232); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=10428, `TimeToTargetScale`=12000, `VerifiedBuild`=26822 WHERE (`SpellMiscId`=4987 AND `AreaTriggerId`=9232); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=9386, `TimeToTargetScale`=12000, `VerifiedBuild`=26822 WHERE (`SpellMiscId`=4987 AND `AreaTriggerId`=9232); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=26822 WHERE (`SpellMiscId`=4985 AND `AreaTriggerId`=9700); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=20000, `VerifiedBuild`=26822 WHERE (`SpellMiscId`=5485 AND `AreaTriggerId`=10192); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=43, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=26822 WHERE (`SpellMiscId`=7363 AND `AreaTriggerId`=12515); -- SpellId : 0

UPDATE `conversation_actors` SET `VerifiedBuild`=26822 WHERE (`ConversationId`=1179 AND `ConversationActorId`=48842 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=26822 WHERE (`ConversationId`=1179 AND `ConversationActorId`=48842 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=26822 WHERE (`ConversationId`=1185 AND `ConversationActorId`=48842 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=26822 WHERE (`ConversationId`=1186 AND `ConversationActorId`=48842 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=26822 WHERE (`ConversationId`=1187 AND `ConversationActorId`=48842 AND `Idx`=0);

UPDATE `conversation_actor_template` SET `VerifiedBuild`=26822 WHERE `Id`=48842;
UPDATE `conversation_actor_template` SET `VerifiedBuild`=26822 WHERE `Id`=48842;
UPDATE `conversation_actor_template` SET `VerifiedBuild`=26822 WHERE `Id`=48842;
UPDATE `conversation_actor_template` SET `VerifiedBuild`=26822 WHERE `Id`=48842;

UPDATE `conversation_line_template` SET `Unk`=8240, `VerifiedBuild`=26822 WHERE `Id`=2798;
UPDATE `conversation_line_template` SET `VerifiedBuild`=26822 WHERE `Id`=2797;
UPDATE `conversation_line_template` SET `VerifiedBuild`=26822 WHERE `Id`=2808;
UPDATE `conversation_line_template` SET `VerifiedBuild`=26822 WHERE `Id`=2809;
UPDATE `conversation_line_template` SET `VerifiedBuild`=26822 WHERE `Id`=2019;
UPDATE `conversation_line_template` SET `VerifiedBuild`=26822 WHERE `Id`=1429;
UPDATE `conversation_line_template` SET `VerifiedBuild`=26822 WHERE `Id`=1428;
UPDATE `conversation_line_template` SET `UiCameraID`=3814728592, `VerifiedBuild`=26822 WHERE `Id`=2027;
UPDATE `conversation_line_template` SET `UiCameraID`=3814728592, `VerifiedBuild`=26822 WHERE `Id`=2026;
UPDATE `conversation_line_template` SET `UiCameraID`=3814728592, `VerifiedBuild`=26822 WHERE `Id`=2025;
UPDATE `conversation_line_template` SET `UiCameraID`=3814728592, `VerifiedBuild`=26822 WHERE `Id`=8548;
UPDATE `conversation_line_template` SET `UiCameraID`=3814728592, `VerifiedBuild`=26822 WHERE `Id`=2024;
UPDATE `conversation_line_template` SET `UiCameraID`=3814728592, `VerifiedBuild`=26822 WHERE `Id`=2023;
UPDATE `conversation_line_template` SET `UiCameraID`=3814728592, `VerifiedBuild`=26822 WHERE `Id`=2022;
UPDATE `conversation_line_template` SET `UiCameraID`=3814728592, `VerifiedBuild`=26822 WHERE `Id`=2021;
UPDATE `conversation_line_template` SET `VerifiedBuild`=26822 WHERE `Id`=2811;

UPDATE `conversation_template` SET `VerifiedBuild`=26822 WHERE `Id`=550;
UPDATE `conversation_template` SET `VerifiedBuild`=26822 WHERE `Id`=1187;
UPDATE `conversation_template` SET `VerifiedBuild`=26822 WHERE `Id`=1186;
UPDATE `conversation_template` SET `VerifiedBuild`=26822 WHERE `Id`=827;
UPDATE `conversation_template` SET `VerifiedBuild`=26822 WHERE `Id`=1185;
UPDATE `conversation_template` SET `VerifiedBuild`=26822 WHERE `Id`=1179;

DELETE FROM `gameobject_template_addon` WHERE `entry`=246272;
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`) VALUES
(246272, 0, 48); -- Fenryr's Tracks

SET @OGUID := 51013700;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+41;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0,  245699, 1477, 7672, 0, 8388870, 0, 0, 2461.409, 528.7147, 747.9489, 3.141593, 0, 0, -1, 0, 86400, 255, 1, 26822),
(@OGUID+1,  245695, 1477, 7672, 0, 8388870, 0, 0, 2403.396, 548.1352, 747.9489, 3.141593, 0, 0, -1, 0, 86400, 255, 1, 26822),
(@OGUID+2,  245698, 1477, 7672, 0, 8388870, 0, 0, 2437.718, 497.5176, 747.9489, 3.141593, 0, 0, -1, 0, 86400, 255, 1, 26822),
(@OGUID+3,  245696, 1477, 7672, 0, 8388870, 0, 0, 2437.728, 559.9277, 747.9489, 3.141593, 0, 0, -1, 0, 86400, 255, 1, 26822),
(@OGUID+4,  245697, 1477, 7672, 0, 8388870, 0, 0, 2403.383, 509.3201, 747.9489, 3.141593, 0, 0, -1, 0, 86400, 255, 1, 26822),

(@OGUID+14, 246272, 1477, 7672, 7983, 8388870, 0, 0, 3113.62, 2978.662, 616.3439, 5.966287, -0.1735573, -0.07434559, -0.1711121, 0.9669908, 86400, 255, 1, 26822),
(@OGUID+15, 246272, 1477, 7672, 7983, 8388870, 0, 0, 3139.613, 3117.921, 597.754, 4.457054, 0.01673985, -0.07458878, -0.7876902, 0.6113105, 86400, 255, 1, 26822),
(@OGUID+16, 246272, 1477, 7672, 7983, 8388870, 0, 0, 3078.61, 2991.225, 612.2484, 5.277221, 0.001732349, -0.1331253, -0.4710102, 0.8720229, 86400, 255, 1, 26822),
(@OGUID+17, 246272, 1477, 7672, 7983, 8388870, 0, 0, 3147.374, 2959.318, 625.047, 5.700463, 0.1623893, -0.1690779, -0.2559681, 0.9378287, 86400, 255, 1, 26822),
(@OGUID+18, 246272, 1477, 7672, 7983, 8388870, 0, 0, 3086.53, 3035.801, 606.0881, 4.101526, 0.02446413, -0.1757803, -0.8682175, 0.4633586, 86400, 255, 1, 26822),
(@OGUID+19, 246272, 1477, 7672, 7983, 8388870, 0, 0, 3094.993, 2982.325, 614.5093, 5.891466, 0.02219582, -0.05920982, -0.192461, 0.9792652, 86400, 255, 1, 26822),
(@OGUID+20, 246272, 1477, 7672, 7983, 8388870, 0, 0, 3113.334, 3074.955, 602.3693, 4.073318, 0.01616764, -0.1420012, -0.8812389, 0.4505466, 86400, 255, 1, 26822),
(@OGUID+21, 246272, 1477, 7672, 7983, 8388870, 0, 0, 3139.8, 2962.493, 622.3377, 5.570619, -0.007715225, -0.1115417, -0.343401, 0.9325099, 86400, 255, 1, 26822),
(@OGUID+22, 246272, 1477, 7672, 7983, 8388870, 0, 0, 3144.834, 3142.852, 596.3694, 4.360972, -0.01859522, -0.03147221, -0.8189888, 0.5726439, 86400, 255, 1, 26822),
(@OGUID+23, 246272, 1477, 7672, 7983, 8388870, 0, 0, 3104.556, 3065.664, 602.712, 4.202754, 0.06674623, -0.1897287, -0.8409414, 0.5023599, 86400, 255, 1, 26822),
(@OGUID+24, 246272, 1477, 7672, 7983, 8388870, 0, 0, 3135.625, 2969.65, 620.8087, 5.682999, 0.06464863, -0.2182198, -0.2642956, 0.9372025, 86400, 255, 1, 26822),
(@OGUID+25, 246272, 1477, 7672, 7983, 8388870, 0, 0, 3102.706, 3055.21, 604.0793, 4.301234, 0.09823799, -0.159584, -0.8211918, 0.5390049, 86400, 255, 1, 26822),
(@OGUID+26, 246272, 1477, 7672, 7983, 8388870, 0, 0, 3161.505, 2948.392, 627.1578, 5.539371, -0.04713011, -0.07626915, -0.363265, 0.927362, 86400, 255, 1, 26822),
(@OGUID+27, 246272, 1477, 7672, 7983, 8388870, 0, 0, 3134.368, 3106.514, 597.9468, 4.10519, 0.03000498, -0.08205032, -0.8823137, 0.4624824, 86400, 255, 1, 26822),
(@OGUID+28, 246272, 1477, 7672, 7983, 8388870, 0, 0, 3127.992, 2972.668, 618.5409, 5.850871, -0.1022706, -0.07546806, -0.2206154, 0.9670441, 86400, 255, 1, 26822),
(@OGUID+29, 246272, 1477, 7672, 7983, 8388870, 0, 0, 3076.766, 3019.679, 608.7006, 4.456823, 0.08274555, -0.1792355, -0.7705593, 0.6060249, 86400, 255, 1, 26822),
(@OGUID+30, 246272, 1477, 7672, 7983, 8388870, 0, 0, 3072.005, 3010.446, 609.3474, 4.689775, -0.0648694, -0.02985764, -0.7143612, 0.696124, 86400, 255, 1, 26822),
(@OGUID+31, 246272, 1477, 7672, 7983, 8388870, 0, 0, 3131.188, 3096.785, 599.2354, 3.855085, 0.01034498, -0.1170826, -0.9292936, 0.35014, 86400, 255, 1, 26822),
(@OGUID+32, 246272, 1477, 7672, 7983, 8388870, 0, 0, 3122.79, 2978.407, 616.9933, 5.84965, -0.03928661, -0.1246119, -0.2147131, 0.9678981, 86400, 255, 1, 26822),
(@OGUID+33, 246272, 1477, 7672, 7983, 8388870, 0, 0, 3119.188, 3089.657, 599.7862, 3.765035, 0.02173185, -0.1540098, -0.9389524, 0.3068827, 86400, 255, 1, 26822),
(@OGUID+34, 246272, 1477, 7672, 7983, 8388870, 0, 0, 3167.137, 2941.12, 630.6885, 5.601831, -0.1094418, -0.08811188, -0.3391914, 0.9301656, 86400, 255, 1, 26822),
(@OGUID+35, 246272, 1477, 7672, 7983, 8388870, 0, 0, 3138.851, 3131.394, 596.7775, 4.453186, 0.002834797, -0.04674435, -0.7910709, 0.6099293, 86400, 255, 1, 26822),
(@OGUID+36, 246272, 1477, 7672, 7983, 8388870, 0, 0, 3152.472, 2952.234, 625.6198, 5.718339, -0.01586962, -0.08093548, -0.2771549, 0.9572788, 86400, 255, 1, 26822),
(@OGUID+37, 246272, 1477, 7672, 7983, 8388870, 0, 0, 3077.111, 3001.494, 610.9059, 4.709196, 0.07709503, -0.1631126, -0.689187, 0.7017633, 86400, 255, 1, 26822),
(@OGUID+38, 246272, 1477, 7672, 7983, 8388870, 0, 0, 3077.727, 3029.672, 606.6914, 4.253955, -0.074821, -0.03433704, -0.8468418, 0.5254348, 86400, 255, 1, 26822),
(@OGUID+39, 246272, 1477, 7672, 7983, 8388870, 0, 0, 3105.486, 2983.061, 615.2264, 5.894977, 0.0443306, -0.0202055, -0.1921339, 0.9801587, 86400, 255, 1, 26822),
(@OGUID+40, 246272, 1477, 7672, 7983, 8388870, 0, 0, 3088.858, 2987.193, 614.6078, 5.382504, 0.05186939, -0.08921814, -0.4284725, 0.8976419, 86400, 255, 1, 26822),
(@OGUID+41, 246272, 1477, 7672, 7983, 8388870, 0, 0, 3091.868, 3046.687, 605.0187, 3.874464, -0.1737485, 0.1534576, -0.9160519, 0.3272785, 86400, 255, 1, 26822);


DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+4;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`) VALUES
(@OGUID+0, 0, 0, 1, -0.00000004371139),
(@OGUID+1, 0, 0, 1, -0.00000004371139),
(@OGUID+2, 0, 0, 1, -0.00000004371139),
(@OGUID+3, 0, 0, 1, -0.00000004371139),
(@OGUID+4, 0, 0, 1, -0.00000004371139);

UPDATE `spell_target_position` SET `VerifiedBuild`=26822 WHERE (`ID`=197577 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=26822 WHERE (`ID`=197575 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=26822 WHERE (`ID`=215792 AND `EffectIndex`=0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (99868 /*99868 (Fenryr) - Licking Wounds*/, 95674 /*95674 (Fenryr)*/, 101712 /*101712 (Halls of Valor) - Portal Cosmetics*/, 103801 /*103801 (Arthfael) - Permanent Feign Death*/, 99804 /*99804 (Valarjar Falconer) - Abandon Passengers on Poly*/, 99828 /*99828 (Trained Hawk) - Ride Vehicle Hardcoded*/, 96611 /*96611 (Angerhoof Bull) - Mod Scale 95-120%*/, 96934 /*96934 (Valarjar Trapper) - Mod Scale 95-120%, Permanent Feign Death*/, 96609 /*96609 (Gildedfur Stag) - Mod Scale 95-120%, Permanent Feign Death*/, 96608 /*96608 (Ebonclaw Worg) - Strength of the Pack, Strength of the Pack*/, 96677 /*96677 (Steeljaw Grizzly)*/, 99891 /*99891 (Storm Drake)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(99868, 0, 0, 0, 1, 0, 9627, 0, 0, '200561'), -- 99868 (Fenryr) - Licking Wounds
(95674, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 95674 (Fenryr)
(101712, 0, 0, 50331648, 1, 0, 0, 0, 0, '200611'), -- 101712 (Halls of Valor) - Portal Cosmetics
(103801, 0, 0, 0, 1, 0, 0, 0, 0, '70628'), -- 103801 (Arthfael) - Permanent Feign Death
(99804, 0, 0, 0, 1, 0, 0, 0, 0, '59532'), -- 99804 (Valarjar Falconer) - Abandon Passengers on Poly
(99828, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- 99828 (Trained Hawk) - Ride Vehicle Hardcoded
(96611, 0, 0, 0, 1, 0, 0, 0, 0, '123978'), -- 96611 (Angerhoof Bull) - Mod Scale 95-120%
(96934, 0, 0, 0, 1, 0, 0, 0, 0, '123978 70628'), -- 96934 (Valarjar Trapper) - Mod Scale 95-120%, Permanent Feign Death
(96609, 0, 0, 0, 1, 0, 0, 0, 0, '123978 70628'), -- 96609 (Gildedfur Stag) - Mod Scale 95-120%, Permanent Feign Death
(96608, 0, 0, 0, 1, 0, 0, 0, 0, '199186 199184'), -- 96608 (Ebonclaw Worg) - Strength of the Pack, Strength of the Pack
(96677, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 96677 (Steeljaw Grizzly)
(99891, 0, 0, 50331648, 1, 0, 0, 0, 0, ''); -- 99891 (Storm Drake)

UPDATE `creature_template_addon` SET `auras`='46598' WHERE `entry`=101637; -- 101637 (Valarjar Aspirant)
UPDATE `creature_template_addon` SET `auras`='46598' WHERE `entry`=101639; -- 101639 (Valarjar Shieldmaiden)
UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=95834; -- 95834 (Valarjar Mystic)
UPDATE `creature_template_addon` SET `auras`='152731' WHERE `entry`=94968; -- 94968 (Valarjar Stormrider)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=97795; -- 97795 (Static Field)
UPDATE `creature_template_addon` SET `bytes1`=3 WHERE `entry`=34330; -- 34330 (Jones)
UPDATE `creature_template_addon` SET `auras`='60913 61354' WHERE `entry`=96778; -- 96778 (Aemara)
UPDATE `creature_template_addon` SET `auras`='183111' WHERE `entry`=104091; -- Kirin Tor Guardian


UPDATE `creature_template_scaling` SET `VerifiedBuild`=26822 WHERE `Entry`=97795;
UPDATE `creature_template_scaling` SET `VerifiedBuild`=26822 WHERE `Entry`=122130;
UPDATE `creature_template_scaling` SET `VerifiedBuild`=26822 WHERE `Entry`=108628;


UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=65873;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=64466;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=67282;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=24490;
UPDATE `creature_model_info` SET `BoundingRadius`=0.9848007, `VerifiedBuild`=26822 WHERE `DisplayID`=42414;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=65853;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=67283;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=67281;
UPDATE `creature_model_info` SET `BoundingRadius`=1.156228, `VerifiedBuild`=26822 WHERE `DisplayID`=45090;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=70154;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=41014;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=70645;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=64464;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=47641;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=64575;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=74478;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=72718;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=28088;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=28085;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=28087;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=67230;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=28086;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=67277;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=25801;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=24991;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=67429;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=25811;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=64200;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=67274;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=64208;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=67773;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=67275;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=67203;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=62350;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=67278;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=67279;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=67276;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=65424;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=70927;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=45437;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=60156;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=27720;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=6295;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=27881;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=64331;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=70638;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=69155;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=40674;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=65252;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=48000;

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=99804 AND `ID`=1) OR (`CreatureID`=96934 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(99804, 1, 34058, 0, 0, 0, 0, 0, 0, 0, 0), -- Valarjar Falconer
(96934, 1, 34816, 0, 0, 34816, 0, 0, 0, 0, 0); -- Valarjar Trapper


DELETE FROM `gossip_menu` WHERE (`MenuId`=20166 AND `TextId`=29996);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`) VALUES
(20166, 29996); -- 95676 (Odyn)

DELETE FROM `gossip_menu_option` WHERE (`MenuId`=20166 AND `OptionIndex`=1);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`) VALUES
(20166, 1, 0, 'I am ready to leave now.', 0);

UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=0 WHERE (`MenuId`=19198 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=0 WHERE (`MenuId`=18850 AND `OptionIndex`=0);





UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_walk`=4, `speed_run`=1.714286, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=4196352 WHERE `entry`=99868; -- Fenryr
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_walk`=4, `speed_run`=1.714286, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=4196352 WHERE `entry`=95674; -- Fenryr
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=101712; -- Halls of Valor
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_walk`=2.8, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=570720512, `unit_flags2`=2049, `unit_flags3`=8193 WHERE `entry`=103801; -- Arthfael
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=1885, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32832, `unit_flags2`=2099200, `VehicleId`=4472 WHERE `entry`=99804; -- Valarjar Falconer
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=1885, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587200, `unit_flags2`=2048 WHERE `entry`=99828; -- Trained Hawk
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=2.8, `speed_run`=2, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=96611; -- Angerhoof Bull
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=3000, `RangeAttackTime`=2000, `unit_flags`=570720576, `unit_flags2`=35653633, `unit_flags3`=8193 WHERE `entry`=96934; -- Valarjar Trapper
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2575, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=570720256, `unit_flags2`=2099201, `unit_flags3`=8192 WHERE `entry`=96609; -- Gildedfur Stag
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=96608; -- Ebonclaw Worg
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=96677; -- Steeljaw Grizzly
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_walk`=4, `speed_run`=1.428571, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=37750784, `HoverHeight`=6.5 WHERE `entry`=99891; -- Storm Drake
UPDATE `creature_template` SET `npcflag`=16777216 WHERE `entry`=102423; -- Mug of Mead
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=97081; -- King Bjorn
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=97083; -- King Ranulf
UPDATE `creature_template` SET `gossip_menu_id`=20166 WHERE `entry`=95676; -- Odyn
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `unit_flags`=32832, `unit_flags3`=0 WHERE `entry`=96574; -- Stormforged Sentinel
UPDATE `creature_template` SET `minlevel`=110, `unit_flags`=32832, `unit_flags3`=0 WHERE `entry`=95834; -- Valarjar Mystic
UPDATE `creature_template` SET `unit_flags`=32832, `unit_flags3`=0 WHERE `entry`=95842; -- Valarjar Thundercaller
UPDATE `creature_template` SET `minlevel`=110, `unit_flags`=32832, `unit_flags3`=0 WHERE `entry`=97087; -- Valarjar Champion
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111 WHERE `entry`=101846; -- Nomi
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=96813; -- Aludane Whitecloud
UPDATE `creature_template` SET `minlevel`=108, `maxlevel`=108 WHERE `entry`=96641; -- Stabled Hunter Pet
UPDATE `creature_template` SET `minlevel`=101, `maxlevel`=101 WHERE `entry`=96636; -- Stabled Hunter Pet
UPDATE `creature_template` SET `minlevel`=104, `maxlevel`=104 WHERE `entry`=96635; -- Stabled Hunter Pet
UPDATE `creature_template` SET `minlevel`=108, `maxlevel`=108 WHERE `entry`=96592; -- Stabled Hunter Pet
UPDATE `creature_template` SET `minlevel`=107, `maxlevel`=107 WHERE `entry`=96643; -- Stabled Hunter Pet

DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (97068, 99804, 101640, 101638, 97788);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(97068, 94968, 0, 0, 'Storm Drake - Valarjar Stormrider', 0, 0), -- Storm Drake - Valarjar Stormrider
(99804, 99828, 0, 0, 'Valarjar Falconer - Trained Hawk', 0, 0), -- Valarjar Falconer - Trained Hawk
(101640, 101639, 0, 0, 'Chosen of Eyir - Valarjar Shieldmaiden', 0, 0), -- Chosen of Eyir - Valarjar Shieldmaiden
(101638, 101637, 0, 0, 'Chosen of Eyir - Valarjar Aspirant', 0, 0), -- Chosen of Eyir - Valarjar Aspirant
(97788, 94968, 0, 0, 'Storm Drake - Valarjar Stormrider', 0, 0); -- Storm Drake - Valarjar Stormrider

-- INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
-- (102423, 202284, 0, 0);


UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=101459; -- Spoils
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=102019; -- Stormforged Obliterator
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=100575; -- Spear of Light
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=111374; -- Xal'atath
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=95675; -- God-King Skovald
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=98364; -- Aegis of Aggramar
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=111936; -- Thal'kiel
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=76168; -- Ravager
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=99922; -- Ebonclaw Packmate
UPDATE `creature_template` SET `family`=1, `VerifiedBuild`=26822 WHERE `entry`=99868; -- Fenryr
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=101085; -- Bear Trap
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=99891; -- Storm Drake
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=95674; -- Fenryr
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=99804; -- Valarjar Falconer
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=99828; -- Trained Hawk
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96934; -- Valarjar Trapper
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96677; -- Steeljaw Grizzly
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96611; -- Angerhoof Bull
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96608; -- Ebonclaw Worg
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96609; -- Gildedfur Stag
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=101712; -- Halls of Valor
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=111421; -- Lurking Owl Kitten
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=103801; -- Arthfael
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=102557; -- Olmyr the Enlightened
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=102558; -- Solsten
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=26668; -- Svala Sorrowgrave
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=101639; -- Valarjar Shieldmaiden
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=101637; -- Valarjar Aspirant
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=101638; -- Chosen of Eyir
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=101640; -- Chosen of Eyir
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=47649; -- Efflorescence
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=101758; -- Eye of the Storm
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=97202; -- Olmyr the Enlightened
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=101697; -- Field of the Eternal Hunt
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=97219; -- Solsten
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=97788; -- Storm Drake
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=97960; -- Dancing Blade
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=97197; -- Valarjar Purifier
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=78217; -- Infernal
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=62982; -- Mindbender
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=100956; -- Crackling Storm
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=98167; -- Void Tendril
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=98680; -- Sphere of Insanity
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=102423; -- Mug of Mead
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=93628; -- Eyir
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=95833; -- Hyrja
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=99625; -- Wind Spirit
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=69791; -- Fire Spirit
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=69792; -- Earth Spirit
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=97084; -- King Tor
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=95676; -- Odyn
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=95843; -- King Haldor
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=97081; -- King Bjorn
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=97083; -- King Ranulf
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=95832; -- Valarjar Shieldmaiden
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96640; -- Valarjar Marksman
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=95834; -- Valarjar Mystic
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96664; -- Valarjar Runecarver
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96574; -- Stormforged Sentinel
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96648; -- Chosen of Eyir
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=94960; -- Hymdall
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=97795; -- Static Field
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=97068; -- Storm Drake
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=94968; -- Valarjar Stormrider
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=95842; -- Valarjar Thundercaller
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=97087; -- Valarjar Champion
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=111833; -- Thal'kiel
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=59394; -- General Purpose Bunny JMF (Ground)
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=59773; -- Terracotta Guardian
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=124265; -- Chitinous Cragscaler
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=122130; -- High Vindicator
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=111816; -- Calydus
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=109751; -- Lightsworn Anchorite
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=78158; -- Doomguard
UPDATE `creature_template` SET `type_flags`=66049, `VerifiedBuild`=26822 WHERE `entry`=65450; -- Ancient Guardian
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=17252; -- Felguard
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=58965; -- Wrathguard
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=108628; -- Armond Thaco
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=65065; -- Red Dragon Turtle
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=40054; -- Abyssal Seahorse
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=97520; -- Drog Skullbreaker
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=112798; -- Nightmare Lasher
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=112132; -- Firebat Pup
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=98463; -- Broot
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=99403; -- Risen Saber Kitten
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=99394; -- Fetid Waveling
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=98077; -- Crispin
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=93143; -- Cinder Pup
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=49588; -- Guild Page
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=94867; -- Left Shark
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=68657; -- Fungal Abomination
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=83594; -- Nightshade Sproutling
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=88225; -- Sentinel's Companion
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=37865; -- Perky Pug
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=84915; -- Molten Corgi
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=85387; -- Fruit Hunter
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=84330; -- Meadowstomper Calf
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=85231; -- Stonegrinder
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=88103; -- Doom Bloom
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=86716; -- Crimson Spore
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=88222; -- Everbloom Peachick
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=36871; -- Core Hound Pup
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=77137; -- Dread Hatchling
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=77221; -- Iron Starlette
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=10598; -- Smolderweb Hatchling
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=7565; -- Black Kingsnake
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=14421; -- Brown Prairie Dog
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=29726; -- Mr. Chilly


UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=95675 AND `Idx`=0); -- God-King Skovald
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=99922 AND `Idx`=0); -- Ebonclaw Packmate
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=99868 AND `Idx`=5); -- Fenryr
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=99868 AND `Idx`=4); -- Fenryr
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=99868 AND `Idx`=3); -- Fenryr
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=99868 AND `Idx`=2); -- Fenryr
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=99868 AND `Idx`=1); -- Fenryr
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=99868 AND `Idx`=0); -- Fenryr
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=99891 AND `Idx`=2); -- Storm Drake
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=99891 AND `Idx`=1); -- Storm Drake
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=99891 AND `Idx`=0); -- Storm Drake
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=95674 AND `Idx`=3); -- Fenryr
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=95674 AND `Idx`=2); -- Fenryr
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=95674 AND `Idx`=1); -- Fenryr
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=95674 AND `Idx`=0); -- Fenryr
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=99828 AND `Idx`=0); -- Trained Hawk
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=96677 AND `Idx`=5); -- Steeljaw Grizzly
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=96677 AND `Idx`=4); -- Steeljaw Grizzly
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=96677 AND `Idx`=3); -- Steeljaw Grizzly
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=96677 AND `Idx`=2); -- Steeljaw Grizzly
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=96677 AND `Idx`=1); -- Steeljaw Grizzly
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=96677 AND `Idx`=0); -- Steeljaw Grizzly
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=96611 AND `Idx`=2); -- Angerhoof Bull
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=96611 AND `Idx`=1); -- Angerhoof Bull
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=96611 AND `Idx`=0); -- Angerhoof Bull
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=96608 AND `Idx`=3); -- Ebonclaw Worg
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=96608 AND `Idx`=2); -- Ebonclaw Worg
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=96608 AND `Idx`=1); -- Ebonclaw Worg
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=96608 AND `Idx`=0); -- Ebonclaw Worg
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=96609 AND `Idx`=2); -- Gildedfur Stag
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=96609 AND `Idx`=1); -- Gildedfur Stag
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=96609 AND `Idx`=0); -- Gildedfur Stag
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=103801 AND `Idx`=5); -- Arthfael
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=103801 AND `Idx`=4); -- Arthfael
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=103801 AND `Idx`=3); -- Arthfael
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=103801 AND `Idx`=2); -- Arthfael
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=103801 AND `Idx`=1); -- Arthfael
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=103801 AND `Idx`=0); -- Arthfael
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=101639 AND `Idx`=0); -- Valarjar Shieldmaiden
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=101637 AND `Idx`=0); -- Valarjar Aspirant
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=97197 AND `Idx`=0); -- Valarjar Purifier
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=95833 AND `Idx`=1); -- Hyrja
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=95833 AND `Idx`=0); -- Hyrja
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=97084 AND `Idx`=0); -- King Tor
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=95843 AND `Idx`=0); -- King Haldor
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=97081 AND `Idx`=0); -- King Bjorn
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=97083 AND `Idx`=0); -- King Ranulf
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=95832 AND `Idx`=0); -- Valarjar Shieldmaiden
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=96640 AND `Idx`=0); -- Valarjar Marksman
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=95834 AND `Idx`=0); -- Valarjar Mystic
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=96664 AND `Idx`=0); -- Valarjar Runecarver
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=96574 AND `Idx`=0); -- Stormforged Sentinel
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=97068 AND `Idx`=2); -- Storm Drake
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=97068 AND `Idx`=1); -- Storm Drake
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=97068 AND `Idx`=0); -- Storm Drake
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=95842 AND `Idx`=0); -- Valarjar Thundercaller
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=97087 AND `Idx`=0); -- Valarjar Champion
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=59773 AND `Idx`=0); -- Terracotta Guardian

DELETE FROM `gameobject_template` WHERE `entry`=246272;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `VerifiedBuild`) VALUES
(246272, 5, 8298, 'Fenryr''s Tracks', '', '', '', 0.75, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26822); -- Fenryr's Tracks

UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=251991; -- The Aegis of Aggramar
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=245847; -- Spoils of the Worthy
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=245696; -- Doodad_7du_valhalla_rune002
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=245695; -- Doodad_7du_valhalla_rune001
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=245698; -- Doodad_7du_valhalla_rune004
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=245697; -- Doodad_7du_valhalla_rune003
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=245699; -- Doodad_7du_valhalla_rune005
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=258968; -- Hymdall's Cache
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=245884; -- Doodad_7du_valhalla_gate004
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=246145; -- Doodad_7du_valhalla_gate006
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=246144; -- Doodad_7du_valhalla_bridge001
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=245702; -- Doodad_7du_valhalla_gate003
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=244664; -- The Gateway of Splendor
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=245701; -- Doodad_7du_valhalla_gate002
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=245700; -- Doodad_7du_valhalla_gate001
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=252145; -- Instance Portal
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=259268; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=252331; -- Traveller Pepe

DELETE FROM `gameobject_questitem` WHERE (`GameObjectEntry`=245847 AND `Idx`=10) OR (`GameObjectEntry`=258968 AND `Idx`=2);
INSERT INTO `gameobject_questitem` (`GameObjectEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(245847, 10, 131928, 26822), -- Spoils of the Worthy
(258968, 2, 138482, 26822); -- Hymdall's Cache

UPDATE `gameobject_questitem` SET `VerifiedBuild`=26822 WHERE (`GameObjectEntry`=245847 AND `Idx`=9); -- Spoils of the Worthy
UPDATE `gameobject_questitem` SET `VerifiedBuild`=26822 WHERE (`GameObjectEntry`=245847 AND `Idx`=8); -- Spoils of the Worthy
UPDATE `gameobject_questitem` SET `VerifiedBuild`=26822 WHERE (`GameObjectEntry`=245847 AND `Idx`=7); -- Spoils of the Worthy
UPDATE `gameobject_questitem` SET `VerifiedBuild`=26822 WHERE (`GameObjectEntry`=245847 AND `Idx`=6); -- Spoils of the Worthy
UPDATE `gameobject_questitem` SET `VerifiedBuild`=26822 WHERE (`GameObjectEntry`=245847 AND `Idx`=5); -- Spoils of the Worthy
UPDATE `gameobject_questitem` SET `VerifiedBuild`=26822 WHERE (`GameObjectEntry`=245847 AND `Idx`=4); -- Spoils of the Worthy
UPDATE `gameobject_questitem` SET `VerifiedBuild`=26822 WHERE (`GameObjectEntry`=245847 AND `Idx`=3); -- Spoils of the Worthy
UPDATE `gameobject_questitem` SET `VerifiedBuild`=26822 WHERE (`GameObjectEntry`=245847 AND `Idx`=2); -- Spoils of the Worthy
UPDATE `gameobject_questitem` SET `VerifiedBuild`=26822 WHERE (`GameObjectEntry`=245847 AND `Idx`=1); -- Spoils of the Worthy
UPDATE `gameobject_questitem` SET `VerifiedBuild`=26822 WHERE (`GameObjectEntry`=245847 AND `Idx`=0); -- Spoils of the Worthy
UPDATE `gameobject_questitem` SET `ItemId`=131928, `VerifiedBuild`=26822 WHERE (`GameObjectEntry`=258968 AND `Idx`=1); -- Hymdall's Cache
UPDATE `gameobject_questitem` SET `VerifiedBuild`=26822 WHERE (`GameObjectEntry`=258968 AND `Idx`=0); -- Hymdall's Cache


UPDATE `npc_text` SET `VerifiedBuild`=26822 WHERE `ID`=29996; -- 29996
UPDATE `npc_text` SET `VerifiedBuild`=26822 WHERE `ID`=28134; -- 28134
UPDATE `npc_text` SET `VerifiedBuild`=26822 WHERE `ID`=27457; -- 27457
