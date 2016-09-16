-- Battle for the Undercity - Horde

-- Templates
SET @THRALL := 31650;
SET @SYLVANAS := 31651;
SET @VOJLIN := 31649;

SET @DEMOLISHER := 31652;
SET @DEMOLISHER_DRIVER := 31654;
SET @STALKER_TESLA := 31653;

SET @WARSONG_BATTLEGUARD := 31739;

SET @BLIGHT_TRIGGER := 31576;

SET @VORTEX := 31782;

SET @SLINGER_TRIGGER := 31577;

SET @TIDAL_WAVE := 31765;

SET @VARIMATHRAS := 31565;
SET @VARIMATHRAS_PORTAL := 31811;

SET @GUARDIAN := 31532;
SET @DREADLORD := 31531;
SET @FELBEAST := 31528;
SET @MARAUDER := 31527;
SET @BETRAYER := 31529;
SET @CHEMIST := 31482;
SET @COLLABORATOR := 31524;
SET @DOCTOR := 31516;
SET @BLIGHT_SLINGER := 31526;
SET @BLIGHT_SPREADER := 31831;
SET @BLIGHT_ABERRATION := 31844;

SET @CYCLONE := 31688;

SET @PILLARGER := 32159;
SET @KHANOK := 32160;

SET @CAVE_DUMMY := 32200;

SET @DREADGUARD_CORPSE := 31642;

SET @OVERLORD:= 32271;
SET @INVADER:= 32269;
SET @DEADWHISPER:= 32270;

SET @DISTANT_VOICE := 31814;

SET @VARIAN := 32303;
SET @JAINA := 32402;
SET @STORMWIND_ELITE := 31639;

SET @SAURFANG := 32315;

SET @BARRICADE_1 := 193440;
SET @BARRICADE_2 := 193441;
SET @BARRICADE_3 := 193442;
SET @BARRICADE_4 := 193443;
SET @BARRICADE_5 := 193444;
SET @BARRICADE_6 := 193445;
SET @BARRICADE_7 := 193446;
SET @BARRICADE_8 := 193447;
SET @BANNER_1 := 193448;
SET @BANNER_2 := 193449;
SET @BANNER_3 := 193450;
SET @BANNER_4 := 193451;
SET @SPIKES := 193415;

SET @PORTAL_TO_ORGRIMMAR := 193427;

UPDATE `creature_template` SET `gossip_menu_id`=10195, `npcflag`=1, `minlevel`=83, `maxlevel`=83, `faction`=1801, `unit_flags`=0 WHERE `entry`=@THRALL;
UPDATE `creature_template` SET `minlevel`=83, `maxlevel`=83, `faction`=1801, `unit_flags`=0 WHERE `entry`=@SYLVANAS;
UPDATE `creature_template` SET `minlevel`=80, `maxlevel`=80, `unit_flags`=512 WHERE `entry`=@VOJLIN;

UPDATE `creature_template` SET `minlevel`=74, `maxlevel`=75, `faction`=1801, `unit_flags`=33554432, `VehicleId`=106 WHERE `entry`=@DEMOLISHER;
UPDATE `creature_template` SET `minlevel`=74, `maxlevel`=75, `faction`=1801, `unit_flags`=33554432 WHERE `entry`=@DEMOLISHER_DRIVER;

UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `faction`=7, `unit_flags`=33686272, `flags_extra`=130 WHERE `entry` IN (@BLIGHT_TRIGGER,@SLINGER_TRIGGER,@CAVE_DUMMY);
UPDATE `creature_template` SET `faction`=7, `unit_flags`=33686272, `flags_extra`=130, `InhabitType`=4 WHERE `entry`=@STALKER_TESLA;
UPDATE `creature_template` SET `faction`=7, `unit_flags`=33686272, `flags_extra`=130 WHERE `entry` IN (@VARIMATHRAS_PORTAL);

UPDATE `creature_template` SET `minlevel`=75, `maxlevel`=75, `faction`=1801, `unit_flags`=0 WHERE `entry`=@WARSONG_BATTLEGUARD;

UPDATE `creature_template` SET `minlevel`=75, `maxlevel`=75, `faction`=7, `unit_flags`=33554434, `flags_extra`=2 WHERE `entry` IN (@VORTEX,@TIDAL_WAVE);
UPDATE `creature_template` SET `modelid1`=17345, `minlevel`=75, `maxlevel`=75, `faction`=7, `unit_flags`=33554434, `flags_extra`=2, `InhabitType`=4 WHERE `entry` IN (@CYCLONE);

UPDATE `creature_template` SET `minlevel`=83, `maxlevel`=83, `faction`=16, `unit_flags`=768 WHERE `entry`=@VARIMATHRAS;

UPDATE `creature_template` SET `minlevel`=74, `maxlevel`=75, `faction`=16, `unit_flags`=0 WHERE `entry` IN (@GUARDIAN,@MARAUDER,@BETRAYER,@CHEMIST,@COLLABORATOR,@DOCTOR);
UPDATE `creature_template` SET `minlevel`=75, `maxlevel`=75, `faction`=16, `unit_flags`=0 WHERE `entry`=@DREADLORD;
UPDATE `creature_template` SET `minlevel`=74, `maxlevel`=74, `faction`=16, `unit_flags`=0 WHERE `entry` IN (@FELBEAST,@BLIGHT_SLINGER,@BLIGHT_SPREADER);
UPDATE `creature_template` SET `minlevel`=83, `maxlevel`=83, `faction`=16, `unit_flags`=0 WHERE `entry` IN (@BLIGHT_ABERRATION);

UPDATE `creature_template` SET `minlevel`=77, `maxlevel`=78, `faction`=16, `InhabitType`=4, `unit_flags`=0, `flags_extra`=2 WHERE `entry`=@PILLARGER;

UPDATE `creature_template` SET `minlevel`=83, `maxlevel`=83, `faction`=16, `unit_flags`=768 WHERE `entry`=@KHANOK;

UPDATE `creature_template` SET `minlevel`=80, `maxlevel`=80, `faction`=7, `unit_flags`=33555202, `unit_flags2`=1, `dynamicflags`=32 WHERE `entry`=@DREADGUARD_CORPSE;

UPDATE `creature_template` SET `minlevel`=80, `maxlevel`=80, `faction`=16, `unit_flags`=0 WHERE `entry` IN (@OVERLORD,@INVADER,@DEADWHISPER);

UPDATE `creature_template` SET `minlevel`=83, `maxlevel`=83, `faction`=1802, `unit_flags`=768 WHERE `entry`=@VARIAN;
UPDATE `creature_template` SET `minlevel`=74, `maxlevel`=75, `faction`=1802, `unit_flags`=768 WHERE `entry`=@STORMWIND_ELITE;

UPDATE `creature_template` SET `minlevel`=83, `maxlevel`=83, `faction`=1801, `unit_flags`=0 WHERE `entry`=@SAURFANG;

-- Spawns
SET @CGUID := 302359; -- ToDo: change it
SET @OGUID := 219091; -- ToDo: change it

DELETE FROM `creature` WHERE `id` IN (@THRALL,@SYLVANAS,@VOJLIN,@DEMOLISHER,@STALKER_TESLA,@WARSONG_BATTLEGUARD,@BLIGHT_TRIGGER,@SLINGER_TRIGGER,@GUARDIAN,@DREADLORD,@FELBEAST,@MARAUDER,@BETRAYER,@CHEMIST,@COLLABORATOR,@DOCTOR,@BLIGHT_SLINGER,@BLIGHT_ABERRATION,@DREADGUARD_CORPSE);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID,@CHEMIST,0,85,153,1,64,0,0,1805.93,265.096,65.3997,5.70485,600,0,0,0,0,0,0,256,0,0),
(@CGUID+1,@CHEMIST,0,85,153,1,64,0,0,1804.45,213.158,65.3997,0.779858,600,0,0,0,0,0,0,256,0,0),

(@CGUID+2,@DOCTOR,0,85,153,1,64,0,0,1805.42,261.883,65.8723,5.63911,600,0,0,0,0,0,0,256,0,0),
(@CGUID+3,@DOCTOR,0,85,153,1,64,0,0,1807.98,214.334,65.3996,0.855256,600,0,0,0,0,0,0,256,0,0),

(@CGUID+4,@COLLABORATOR,0,85,153,1,64,0,0,1805.39,210.772,65.3997,0.440324,600,0,0,0,0,0,0,256,0,0),
(@CGUID+5,@COLLABORATOR,0,85,153,1,64,0,0,1802.1,264.15,65.3997,5.65615,600,0,0,0,0,0,0,256,0,0),

(@CGUID+6,@GUARDIAN,0,85,153,1,64,0,0,1804.61,207.413,65.3999,1.44665,600,0,0,0,0,0,0,256,0,0),
(@CGUID+7,@GUARDIAN,0,85,153,1,64,0,0,1759.82,238.433,61.0802,0.0437754,600,0,0,0,0,0,0,256,0,0),
(@CGUID+8,@GUARDIAN,0,85,153,1,64,0,0,1776.38,281.52,70.3997,5.43648,600,0,0,0,0,0,0,256,0,0),
(@CGUID+9,@GUARDIAN,0,85,153,1,64,0,0,1808.79,267.084,65.3997,5.38936,600,0,0,0,0,0,0,256,0,0),
(@CGUID+10,@GUARDIAN,0,85,153,1,64,0,0,1782.05,193.323,70.3998,0.775139,600,0,0,0,0,0,0,256,0,0),

(@CGUID+11,@STALKER_TESLA,0,85,153,1,64,0,0,1863.55,266.534,85.6256,3.00597,600,0,0,0,0,0,0,0,0,0),
(@CGUID+12,@STALKER_TESLA,0,85,153,1,64,0,0,1864.69,252.728,92.9314,3.84242,600,0,0,0,0,0,0,0,0,0),
(@CGUID+13,@STALKER_TESLA,0,85,153,1,64,0,0,1876.36,246.296,96.0736,3.52826,600,0,0,0,0,0,0,0,0,0),
(@CGUID+14,@STALKER_TESLA,0,85,153,1,64,0,0,1874.27,246.315,84.0104,3.18268,600,0,0,0,0,0,0,0,0,0),
(@CGUID+15,@STALKER_TESLA,0,85,153,1,64,0,0,1863.55,213.861,84.7783,3.03346,600,0,0,0,0,0,0,0,0,0),
(@CGUID+16,@STALKER_TESLA,0,85,153,1,64,0,0,1874.12,229.666,85.8148,3.18661,600,0,0,0,0,0,0,0,0,0),
(@CGUID+17,@STALKER_TESLA,0,85,153,1,64,0,0,1876.25,247.638,102.872,1.52863,600,0,0,0,0,0,0,0,0,0),
(@CGUID+18,@STALKER_TESLA,0,85,153,1,64,0,0,1872.05,235.115,103.67,3.97593,600,0,0,0,0,0,0,0,0,0),
(@CGUID+19,@STALKER_TESLA,0,85,153,1,64,0,0,1876.5,224.006,102.665,4.95533,600,0,0,0,0,0,0,0,0,0),

(@CGUID+20,@SLINGER_TRIGGER,0,85,153,1,64,0,0,1782.73,221.142,59.6769,3.18081,600,5,0,0,0,1,0,0,0,0),
(@CGUID+21,@SLINGER_TRIGGER,0,85,153,1,64,0,0,1772.55,239.24,60.7732,6.26192,600,5,0,0,0,1,0,0,0,0),
(@CGUID+22,@SLINGER_TRIGGER,0,85,153,1,64,0,0,1779.6,257.8,59.792,5.48674,600,5,0,0,0,1,0,0,0,0),
(@CGUID+23,@SLINGER_TRIGGER,0,85,153,1,64,0,0,1829.76,251.752,59.7508,5.8441,600,5,0,0,0,1,0,0,0,0),
(@CGUID+24,@SLINGER_TRIGGER,0,85,153,1,64,0,0,1831.5,225.561,60.4831,4.80187,600,5,0,0,0,1,0,0,0,0),
(@CGUID+25,@SLINGER_TRIGGER,0,85,153,1,64,0,0,1805.82,255.228,60.69,6.27999,600,5,0,0,0,1,0,0,0,0),
(@CGUID+26,@SLINGER_TRIGGER,0,85,153,1,64,0,0,1807.2,222.127,60.2919,3.05907,600,5,0,0,0,1,0,0,0,0),

(@CGUID+27,@DREADGUARD_CORPSE,0,85,153,1,64,0,0,1317.99,341.872,-65.0272,4.75816,600,0,0,0,0,0,0,0,0,0),
(@CGUID+28,@DREADGUARD_CORPSE,0,85,153,1,64,0,0,1305.08,329.577,-60.0829,0.57517,600,0,0,0,0,0,0,0,0,0),
(@CGUID+29,@DREADGUARD_CORPSE,0,85,153,1,64,0,0,1271.22,330.57,-61.6462,6.18209,600,0,0,0,0,0,0,0,0,0),
(@CGUID+30,@DREADGUARD_CORPSE,0,85,153,1,64,0,0,1262.36,316.457,-65.0272,1.59536,600,0,0,0,0,0,0,0,0,0),
(@CGUID+31,@DREADGUARD_CORPSE,0,85,153,1,64,0,0,1256.9,301.913,-63.709,2.33285,600,0,0,0,0,0,0,0,0,0),
(@CGUID+32,@DREADGUARD_CORPSE,0,85,153,1,64,0,0,1281.19,303.35,-65.0272,3.36251,600,0,0,0,0,0,0,0,0,0),
(@CGUID+33,@DREADGUARD_CORPSE,0,85,153,1,64,0,0,1301.04,281.33,-63.6709,3.57928,600,0,0,0,0,0,0,0,0,0),
(@CGUID+34,@DREADGUARD_CORPSE,0,85,153,1,64,0,0,1310.73,295.577,-65.0272,4.42515,600,0,0,0,0,0,0,0,0,0),
(@CGUID+35,@DREADGUARD_CORPSE,0,85,153,1,64,0,0,1331.77,316.099,-63.7208,5.08724,600,0,0,0,0,0,0,0,0,0),
(@CGUID+36,@DREADGUARD_CORPSE,0,85,153,1,64,0,0,1300.14,333.397,-60.0831,1.06369,600,0,0,0,0,0,0,0,0,0),
(@CGUID+37,@DREADGUARD_CORPSE,0,85,153,1,64,0,0,1301.19,364.085,-67.2922,4.25943,600,0,0,0,0,0,0,0,0,0),
(@CGUID+38,@DREADGUARD_CORPSE,0,85,153,1,64,0,0,1303.29,361.016,-67.2922,4.50212,600,0,0,0,0,0,0,0,0,0),
(@CGUID+39,@DREADGUARD_CORPSE,0,85,153,1,64,0,0,1300.37,349.531,-65.0272,4.25708,600,0,0,0,0,0,0,0,0,0),
(@CGUID+40,@DREADGUARD_CORPSE,0,85,153,1,64,0,0,1321.67,349.958,-63.7364,0.103893,600,0,0,0,0,0,0,0,0,0),
(@CGUID+41,@DREADGUARD_CORPSE,0,85,153,1,64,0,0,1291.98,339.532,-58.4586,2.74208,600,0,0,0,0,0,0,0,0,0),

(@CGUID+45,@DEMOLISHER,0,85,153,1,64,0,0,1952.17,252.972,43.1442,3.21369,600,0,0,0,0,0,0,0,0,0),
(@CGUID+46,@DEMOLISHER,0,85,153,1,64,0,0,1912.95,255.968,53.2161,3.43752,600,0,0,0,0,0,0,0,0,0),
(@CGUID+47,@DEMOLISHER,0,85,153,1,64,0,0,1920.05,221.239,50.6487,3.15085,600,0,0,0,0,0,0,0,0,0),

(@CGUID+48,@WARSONG_BATTLEGUARD,0,85,153,1,64,0,0,1906.38,231.122,53.1895,2.7291,600,0,0,0,0,0,0,0,0,0),
(@CGUID+49,@WARSONG_BATTLEGUARD,0,85,153,1,64,0,0,1905.18,227.511,53.495,2.86261,600,0,0,0,0,0,0,0,0,0),
(@CGUID+50,@WARSONG_BATTLEGUARD,0,85,153,1,64,0,0,1908.14,240.881,52.7707,3.31422,600,0,0,0,0,0,0,0,0,0),
(@CGUID+51,@WARSONG_BATTLEGUARD,0,85,153,1,64,0,0,1907.14,244.7,53.0312,3.26709,600,0,0,0,0,0,0,0,0,0),

(@CGUID+52,@BLIGHT_SLINGER,0,85,153,1,64,0,0,1764.83,283.666,70.3984,5.34616,600,0,0,0,0,0,0,256,0,0),
(@CGUID+53,@BLIGHT_SLINGER,0,85,153,1,64,0,0,1830.29,195.209,70.3998,2.62475,600,0,0,0,0,0,0,256,0,0),
(@CGUID+54,@BLIGHT_SLINGER,0,85,153,1,64,0,0,1737.19,254.653,62.1389,6.28078,600,0,0,0,0,0,0,256,0,0),
(@CGUID+55,@BLIGHT_SLINGER,0,85,153,1,64,0,0,1736.49,224.55,62.5263,6.23915,600,0,0,0,0,0,0,256,0,0),
(@CGUID+56,@BLIGHT_SLINGER,0,85,153,1,64,0,0,1763.51,196.587,70.3997,0.633769,600,0,0,0,0,0,0,256,0,0),
(@CGUID+57,@BLIGHT_SLINGER,0,85,153,1,64,0,0,1833.01,282.311,70.3984,4.0581,600,0,0,0,0,0,0,256,0,0),

(@CGUID+58,@BLIGHT_TRIGGER,0,85,153,1,64,0,0,1875.75,240.681,61.8036,3.08327,600,0,0,0,0,0,0,0,0,0),
(@CGUID+59,@BLIGHT_TRIGGER,0,85,153,1,64,0,0,1879.18,233.716,59.6686,3.2427,600,0,0,0,0,0,0,0,0,0),
(@CGUID+60,@BLIGHT_TRIGGER,0,85,153,1,64,0,0,1867.27,237.753,62.2752,3.21835,600,0,0,0,0,0,0,0,0,0),
(@CGUID+61,@BLIGHT_TRIGGER,0,85,153,1,64,0,0,1863.3,243.354,62.2752,2.19341,600,0,0,0,0,0,0,0,0,0),
(@CGUID+62,@BLIGHT_TRIGGER,0,85,153,1,64,0,0,1856.74,248.25,62.2752,3.17437,600,0,0,0,0,0,0,0,0,0),
(@CGUID+63,@BLIGHT_TRIGGER,0,85,153,1,64,0,0,1858.63,227.999,62.2753,0.028066,600,0,0,0,0,0,0,0,0,0),
(@CGUID+64,@BLIGHT_TRIGGER,0,85,153,1,64,0,0,1848.86,237.472,62.2753,3.05578,600,0,0,0,0,0,0,0,0,0),
(@CGUID+65,@BLIGHT_TRIGGER,0,85,153,1,64,0,0,1863,231.496,62.2753,2.40704,600,0,0,0,0,0,0,0,0,0),
(@CGUID+66,@BLIGHT_TRIGGER,0,85,153,1,64,0,0,1854.09,233.046,62.2751,4.80329,600,0,0,0,0,0,0,0,0,0),
(@CGUID+67,@BLIGHT_TRIGGER,0,85,153,1,64,0,0,1854.16,239.97,62.2751,4.50876,600,0,0,0,0,0,0,0,0,0);

DELETE FROM `gameobject` WHERE `id` IN (@BARRICADE_1,@BARRICADE_2,@BARRICADE_3,@BARRICADE_4,@BARRICADE_5,@BARRICADE_6,@BARRICADE_7,@BARRICADE_8,@BANNER_1,@BANNER_2,@BANNER_3,@BANNER_4,@SPIKES,@PORTAL_TO_ORGRIMMAR);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID,@SPIKES,0,85,153,1,64,1546.09,236.329,-41.3605,5.07102,0,0,0.569651,-0.821887,300,0,1,0),
(@OGUID+1,@SPIKES,0,85,153,1,64,1546.81,234.426,-41.3605,5.07102,0,0,0.569651,-0.821887,300,0,1,0),
(@OGUID+2,@SPIKES,0,85,153,1,64,1546.34,239.839,-41.3605,5.94674,0,0,0.167431,-0.985884,300,0,1,0),
(@OGUID+3,@SPIKES,0,85,153,1,64,1548.37,239.161,-41.3603,5.87606,0,0,0.202162,-0.979352,300,0,1,0),
(@OGUID+4,@SPIKES,0,85,153,1,64,1543.31,242.984,-41.3605,1.95692,0,0,0.829639,0.5583,300,0,1,0),
(@OGUID+5,@SPIKES,0,85,153,1,64,1542.41,245.123,-41.3605,1.97263,0,0,0.833998,0.551767,300,0,1,0),
(@OGUID+6,@SPIKES,0,85,153,1,64,1541.66,246.887,-41.3605,1.96478,0,0,0.831825,0.555038,300,0,1,0),
(@OGUID+7,@SPIKES,0,85,153,1,64,1545.35,238.302,-41.3605,5.07495,0,0,0.568036,-0.823004,300,0,1,0),
(@OGUID+8,@SPIKES,0,85,153,1,64,1541.7,234.616,-41.3606,4.1567,0,0,0.873937,-0.486039,300,0,1,0),
(@OGUID+9,@SPIKES,0,85,153,1,64,1542.53,236.516,-41.3606,4.29021,0,0,0.839568,-0.543255,300,0,1,0),
(@OGUID+10,@SPIKES,0,85,153,1,64,1543.44,238.642,-41.3605,4.2333,0,0,0.854683,-0.51915,300,0,1,0),
(@OGUID+11,@SPIKES,0,85,153,1,64,1538.5,239.236,-41.3604,3.47523,0,0,0.986118,-0.166048,300,0,1,0),
(@OGUID+12,@SPIKES,0,85,153,1,64,1540.27,239.841,-41.3605,3.42418,0,0,0.990034,-0.140826,300,0,1,0),
(@OGUID+13,@SPIKES,0,85,153,1,64,1542.2,240.257,-41.3605,3.33386,0,0,0.995383,-0.0959867,300,0,1,0),
(@OGUID+14,@SPIKES,0,85,153,1,64,1538.65,242.118,-41.3603,2.67806,0,0,0.973262,0.229699,300,0,1,0),
(@OGUID+15,@SPIKES,0,85,153,1,64,1540.4,241.678,-41.3605,2.87441,0,0,0.99109,0.133197,300,0,1,0),
(@OGUID+16,@SPIKES,0,85,153,1,64,1542.34,241.111,-41.3606,2.86614,0,0,0.99053,0.137293,300,0,1,0),
(@OGUID+17,@SPIKES,0,85,153,1,64,1545.25,243.433,-41.3604,1.19116,0,0,0.560988,0.827824,300,0,1,0),
(@OGUID+18,@SPIKES,0,85,153,1,64,1546.71,247.101,-41.3604,1.16367,0,0,0.549558,0.835456,300,0,1,0),
(@OGUID+19,@SPIKES,0,85,153,1,64,1545.98,245.451,-41.3606,1.15582,0,0,0.546273,0.837607,300,0,1,0),
(@OGUID+20,@SPIKES,0,85,153,1,64,1544.29,240.832,-41.3605,0.515716,0,0,0.25501,0.966938,300,0,1,0),
(@OGUID+21,@SPIKES,0,85,153,1,64,1546.11,241.665,-41.3605,0.327221,0,0,0.162882,0.986646,300,0,1,0),
(@OGUID+22,@SPIKES,0,85,153,1,64,1548.39,242.396,-41.3605,0.39398,0,0,0.195718,0.98066,300,0,1,0),
(@OGUID+23,@SPIKES,0,85,153,1,64,1550.36,243.373,-41.3605,0.287951,0,0,0.143479,0.989653,300,0,1,0),
(@OGUID+24,@SPIKES,0,85,153,1,64,1550.24,238.22,-41.3605,5.82109,0,0,0.228999,-0.973427,300,0,1,0),

(@OGUID+25,@BARRICADE_1,0,85,153,1,64,1883.21,230.041,58.7081,2.73612,0,0,0.979519,0.201351,300,0,1,0),
(@OGUID+26,@BARRICADE_1,0,85,153,1,64,1887.53,251.647,58.9577,4.00453,0,0,0.908352,-0.418207,300,0,1,0),
(@OGUID+27,@BARRICADE_2,0,85,153,1,64,1889.93,228.62,57.1115,2.67721,0,0,0.973165,0.230108,300,0,1,0),
(@OGUID+28,@BARRICADE_3,0,85,153,1,64,1885.47,219.617,58.8221,1.93423,0,0,0.823251,0.567677,300,0,1,0),
(@OGUID+29,@BARRICADE_4,0,85,153,1,64,1897.2,227.114,55.4129,2.84529,0,0,0.989046,0.147609,300,0,1,0),
(@OGUID+30,@BARRICADE_5,0,85,153,1,64,1883.95,243.726,58.5648,3.48225,0,0,0.985529,-0.169505,300,0,1,0),
(@OGUID+31,@BARRICADE_6,0,85,153,1,64,1891.55,242.598,56.7591,3.36836,0,0,0.993579,-0.113143,300,0,1,0),
(@OGUID+32,@BARRICADE_8,0,85,153,1,64,1898.79,242.636,54.998,3.26234,0,0,0.998178,-0.0603348,300,0,1,0),

(@OGUID+33,@BANNER_1,0,85,153,1,64,1891.12,222.221,57.3757,2.81073,0,0,0.986348,0.164677,300,0,1,0),
(@OGUID+34,@BANNER_2,0,85,153,1,64,1894.97,249.377,57.111,0.0838973,0,0,0.0419364,0.99912,300,0,1,0),
(@OGUID+35,@BANNER_3,0,85,153,1,64,1896.17,221.601,56.3374,6.13382,0,0,0.0746118,-0.997213,300,0,1,0),
(@OGUID+36,@BANNER_4,0,85,153,1,64,1889.13,249.062,58.3336,3.06201,0,0,0.999208,0.0397831,300,0,1,0),

(@OGUID+37,@PORTAL_TO_ORGRIMMAR,0,85,153,1,64,1967.96,234.603,38.5981,3.13907,0,0,0.999999,0.00125952,300,0,1,0);

-- Creature addons
DELETE FROM `creature_template_addon` WHERE `entry` IN (@THRALL,@SYLVANAS,@VOJLIN,@WARSONG_BATTLEGUARD,@DREADGUARD_CORPSE,@VARIAN,@STORMWIND_ELITE,@PILLARGER);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(@THRALL,0,14575,0,257,0,''),
(@SYLVANAS,0,0,0,257,0,''),
(@VOJLIN,0,15289,0,0,0,''),
(@WARSONG_BATTLEGUARD,0,0,0,257,375,''),
(@DREADGUARD_CORPSE,0,0,0,257,0,'29266'),
(@VARIAN,0,14337,0,0,0,''),
(@STORMWIND_ELITE,0,14337,0,0,0,''),
(@PILLARGER,0,0,0,0,0,'60095');

-- Waypoints
DELETE FROM `waypoint_data` WHERE `id`=@PILLARGER*10;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PILLARGER*10, 1, 1619.279053, 387.159454, -45.365875, 0, 0, 0, 0, 100, 0),
(@PILLARGER*10, 2, 1626.146118, 407.459320, -45.169441, 0, 0, 0, 0, 100, 0),
(@PILLARGER*10, 3, 1568.765381, 404.975708, -45.850800, 0, 0, 0, 0, 100, 0),
(@PILLARGER*10, 4, 1574.694092, 389.525970, -47.180653, 0, 0, 0, 0, 100, 0);

-- Equipments
DELETE FROM `creature_equip_template` WHERE `CreatureID` IN (@VARIAN,@STORMWIND_ELITE,@KHANOK,@WARSONG_BATTLEGUARD,@THRALL,@SYLVANAS,@DREADGUARD_CORPSE);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `ItemID2`, `ItemID3`, `VerifiedBuild`) VALUES
(@VARIAN,1,44705,44705,0,0),
(@STORMWIND_ELITE,1,2177,1984,0,0),
(@KHANOK,1,13623,0,0,0),
(@WARSONG_BATTLEGUARD,1,34638,0,0,0),
(@THRALL,1,12183,0,0,0),
(@SYLVANAS,1,2179,2179,42775,0),
(@DREADGUARD_CORPSE,1,18167,18166,15460,0);

-- Formations
DELETE FROM `creature_formations` WHERE `leaderGUID` IN (@CGUID+43);
INSERT INTO `creature_formations` VALUES
(@CGUID+43,@CGUID+43,0,0,2,0,0),
(@CGUID+43,@CGUID+44,5,45,2,0,0);

-- Accessory_vehicle
DELETE FROM `vehicle_template_accessory` WHERE `entry`=@DEMOLISHER;
INSERT INTO `vehicle_template_accessory` VALUES
(@DEMOLISHER,@DEMOLISHER_DRIVER,0,0,'Demolisher Driver',6,30000);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=@DEMOLISHER;
INSERT INTO `npc_spellclick_spells` VALUES
(@DEMOLISHER,46598,1,0);

-- Spell script names
DELETE FROM `spell_script_names` WHERE `spell_id` IN (59464,59284,60285);
INSERT INTO `spell_script_names` VALUES
(59464,'spell_hurl_boulder'),
(59284,'spell_blight_barrel'),
(60285,'spell_portal_collapse');

-- Spell script
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (59284);
INSERT INTO `spell_linked_spell` VALUES
(59284,59285,1,'Blight Barrel - Blight');

DELETE FROM `spell_scripts` WHERE `id`=60104;
INSERT INTO `spell_scripts` VALUES
(60104,0,0,15,60105,3,0,0,0,0,0);

-- Spell target position
DELETE FROM `spell_target_position` WHERE `id` IN (56347,60699);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `VerifiedBuild`) VALUES
(56347,0,0,1290.41,316.247,-57.2376,1.309,0),
(60699,0,1,1172.78,-4171.14,52.21,2.18,0);

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (59668,60207,60224,60285,59284,60046,59464,59629,60511,60516,60104);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 59464, 0, 0, 31, 0, 3, @STALKER_TESLA, 0, 0, 0, '', 'Boulder Assault targets Stalker'),
(13, 1, 59668, 0, 0, 31, 0, 3, @BLIGHT_TRIGGER, 0, 0, 0, '', 'Vortex targets Blight Trigger'),
(13, 1, 60207, 0, 0, 31, 0, 3, @CAVE_DUMMY, 0, 0, 0, '', 'Call of Earth targets Cave in Dummy'),
(13, 1, 60224, 0, 0, 31, 0, 3, @VARIMATHRAS, 0, 0, 0, '', 'Opening Legion Portals targets Varimathras Portal'),
(13, 1, 60285, 0, 0, 31, 0, 3, @VARIMATHRAS, 0, 0, 0, '', 'Portal Collapse targets Varimathras'),
(13, 1, 59284, 0, 0, 31, 0, 3, @SLINGER_TRIGGER, 0, 0, 0, '', 'Blight Barrel targets Slinger Trigger'),
(13, 1, 60046, 0, 0, 31, 0, 3, @DREADLORD, 0, 0, 0, '', 'Assasinate targets Dreadlord'),
(13, 1, 60046, 0, 1, 31, 0, 3, @FELBEAST, 0, 0, 0, '', 'Assasinate targets Felbeast'),
(13, 1, 60046, 0, 2, 31, 0, 3, @MARAUDER, 0, 0, 0, '', 'Assasinate targets Marauder'),
(13, 1, 60046, 0, 3, 31, 0, 3, @BETRAYER, 0, 0, 0, '', 'Assasinate targets Betrayer'),
(13, 1, 60046, 0, 4, 31, 0, 3, @PILLARGER, 0, 0, 0, '', 'Assasinate targets Pillarger'),
(13, 3, 59629, 0, 0, 31, 0, 3, @GUARDIAN, 0, 0, 0, '', 'Tiday Fury targets Guardian'),
(13, 3, 59629, 0, 1, 31, 0, 3, @CHEMIST, 0, 0, 0, '', 'Tiday Fury targets Chemist'),
(13, 3, 59629, 0, 2, 31, 0, 3, @COLLABORATOR, 0, 0, 0, '', 'Tiday Fury targets Collaborator'),
(13, 3, 59629, 0, 3, 31, 0, 3, @DOCTOR, 0, 0, 0, '', 'Tiday Fury targets Doctor'),
(13, 3, 59629, 0, 4, 31, 0, 3, @BLIGHT_SLINGER, 0, 0, 0, '', 'Tiday Fury targets Blight Slinger'),
(13, 3, 59629, 0, 5, 31, 0, 3, @SLINGER_TRIGGER, 0, 0, 0, '', 'Tiday Fury targets Slinger trigger'),
(13, 3, 59629, 0, 6, 31, 0, 3, @VARIMATHRAS_PORTAL, 0, 0, 0, '', 'Tiday Fury targets varimatharas portal'),
(13, 1, 60511, 0, 0, 31, 0, 3, @VARIAN, 0, 0, 0, '', 'Deep Freeze targets Varian'),
(13, 1, 60511, 0, 1, 31, 0, 3, @THRALL, 0, 0, 0, '', 'Deep Freeze targets Thrall'),
(13, 1, 60511, 0, 2, 31, 0, 3, @SYLVANAS, 0, 0, 0, '', 'Deep Freeze targets Sylvanas'),
(13, 1, 60511, 0, 3, 31, 0, 3, @STORMWIND_ELITE, 0, 0, 0, '', 'Deep Freeze targets Stormwind Elite'),
(13, 1, 60511, 0, 4, 31, 0, 4, 0, 0, 0, 0, '', 'Deep Freeze targets players'),
(13, 1, 60516, 0, 0, 31, 0, 3, @VARIAN, 0, 0, 0, '', 'Mass Teleport targets Varian'),
(13, 1, 60516, 0, 1, 31, 0, 3, @STORMWIND_ELITE, 0, 0, 0, '', 'Mass Teleport targets Stormwind Elite'),
(13, 1, 60104, 0, 0, 31, 0, 3, @THRALL, 0, 0, 0, '', 'Deep Freeze targets Thrall');

-- Update AI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@SYLVANAS,@DEMOLISHER,@STALKER_TESLA,@WARSONG_BATTLEGUARD,@BLIGHT_TRIGGER,@VORTEX,@VARIMATHRAS_PORTAL,@GUARDIAN,@DREADLORD,@FELBEAST,@MARAUDER,@BETRAYER,@CHEMIST,@COLLABORATOR,@DOCTOR,@BLIGHT_SLINGER,@BLIGHT_SPREADER,@BLIGHT_ABERRATION,@CYCLONE,@PILLARGER,@KHANOK,@OVERLORD,@INVADER,@DEADWHISPER,@VARIAN,@STORMWIND_ELITE);
UPDATE `creature_template` SET `ScriptName`='npc_thrall_battle_undercity' WHERE `entry`=@THRALL;
UPDATE `creature_template` SET `ScriptName`='npc_varimathras_battle_undercity' WHERE `entry`=@VARIMATHRAS;
UPDATE `creature_template` SET `ScriptName`='npc_tidal_wave' WHERE `entry` IN (@TIDAL_WAVE);

-- Gossip
DELETE FROM `gossip_menu` WHERE `entry`=10195;
INSERT INTO `gossip_menu` VALUES
(10195,14050,0);

DELETE FROM `gossip_menu_option` WHERE `menu_id`=10195;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(10195, 0, 0, "I am ready, Warchief!", 0, 0, 1, 0, 0, 0, 0, "", 32359, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=10195;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 10195, 0, 0, 0, 28, 0, 13267, 0, 0, 0, 0, '', 'Show gossip if player has quest The Battle for Undercity not rewarded');

-- Waypoints
DELETE FROM `script_waypoint` WHERE `entry`=@THRALL;
INSERT INTO `script_waypoint` VALUES
(@THRALL,1,1883.359253,236.694565,58.670765,0,'Thrall - Battle for the Undercity'),
(@THRALL,2,1862.840088,237.184250,62.275131,0,'Thrall - Battle for the Undercity'),
(@THRALL,3,1862.757080,247.886551,62.275131,0,'Thrall - Battle for the Undercity'),
(@THRALL,4,1854.340942,248.083038,62.275131,0,'Thrall - Battle for the Undercity'),
(@THRALL,5,1853.831421,238.266739,62.275131,0,'Thrall - Battle for the Undercity'),
(@THRALL,6,1843.671753,238.392578,62.275131,0,'Thrall - Battle for the Undercity'),
(@THRALL,7,1806.265869,256.897552,60.771706,0,'Thrall - Battle for the Undercity'),
(@THRALL,8,1779.120483,239.706589,60.452793,0,'Thrall - Battle for the Undercity'),
(@THRALL,9,1767.264404,238.965805,60.849346,0,'Thrall - Battle for the Undercity'),
(@THRALL,10,1750.521973,240.249283,61.519722,0,'Thrall - Battle for the Undercity'),
(@THRALL,11,1731.075073,257.664886,62.466351,0,'Thrall - Battle for the Undercity'),
(@THRALL,12,1714.276367,257.773285,64.265587,0,'Thrall - Battle for the Undercity'),
(@THRALL,13,1712.896973,240.009598,62.597641,0,'Thrall - Battle for the Undercity'),
(@THRALL,14,1641.053345,240.057770,62.591629,0,'Thrall - Battle for the Undercity'),
(@THRALL,15,1620.434326,260.975922,62.594250,0,'Thrall - Battle for the Undercity'),
(@THRALL,16,1602.705444,242.734940,60.149395,0,'Thrall - Battle for the Undercity'),
(@THRALL,17,1552.571899,240.687378,55.242210,0,'Thrall - Battle for the Undercity'),
(@THRALL,18,1536.563354,240.597824,-41.361366,0,'Thrall - Battle for the Undercity'),
(@THRALL,19,1524.657349,240.754517,-41.389881,0,'Thrall - Battle for the Undercity'),
(@THRALL,20,1529.429077,210.967819,-43.055489,0,'Thrall - Battle for the Undercity'),
(@THRALL,21,1559.285034,224.943359,-43.102520,0,'Thrall - Battle for the Undercity'),
(@THRALL,22,1559.221558,239.578247,-43.102520,0.133856,'Thrall - Battle for the Undercity'),
(@THRALL,23,1583.217529,240.472946,-52.154655,0,'Thrall - Battle for the Undercity'),
(@THRALL,24,1588.093750,248.755051,-52.151398,0,'Thrall - Battle for the Undercity'),
(@THRALL,25,1595.841797,248.879410,-52.152058,0,'Thrall - Battle for the Undercity'),
(@THRALL,26,1595.719360,260.126801,-57.161724,0,'Thrall - Battle for the Undercity'),
(@THRALL,27,1579.743164,257.165863,-61.905796,0,'Thrall - Battle for the Undercity'),
(@THRALL,28,1572.475952,263.930786,-58.851940,0,'Thrall - Battle for the Undercity'),
(@THRALL,29,1556.385010,280.758392,-60.776150,0,'Thrall - Battle for the Undercity'),
(@THRALL,30,1556.187256,295.033142,-62.181240,0,'Thrall - Battle for the Undercity'),
(@THRALL,31,1595.798218,315.432129,-62.179409,0,'Thrall - Battle for the Undercity'),
(@THRALL,32,1593.718872,374.145233,-62.179409,0,'Thrall - Battle for the Undercity'),
(@THRALL,33,1572.672607,374.481354,-62.179409,0,'Thrall - Battle for the Undercity'),
(@THRALL,34,1539.444336,367.727997,-62.180317,0,'Thrall - Battle for the Undercity'),
(@THRALL,35,1527.097290,360.952789,-57.151978,0,'Thrall - Battle for the Undercity'),
(@THRALL,36,1508.790771,393.130249,-57.152580,0,'Thrall - Battle for the Undercity'),
(@THRALL,37,1473.218872,366.665955,-62.184952,0,'Thrall - Battle for the Undercity'),
(@THRALL,38,1468.874023,370.961426,-59.449444,0,'Thrall - Battle for the Undercity'),
(@THRALL,39,1415.932251,425.641998,-55.109211,0,'Thrall - Battle for the Undercity'),
(@THRALL,40,1392.498657,438.549408,-53.665539,0,'Thrall - Battle for the Undercity'),
(@THRALL,41,1359.082642,438.218658,-54.415500,0,'Thrall - Battle for the Undercity'),
(@THRALL,42,1327.128052,419.422699,-59.066284,0,'Thrall - Battle for the Undercity'),
(@THRALL,43,1310.649902,393.170776,-63.583462,0,'Thrall - Battle for the Undercity'),
(@THRALL,44,1301.726440,359.496368,-67.294350,0,'Thrall - Battle for the Undercity'),
(@THRALL,45,1286.469971,318.814789,-57.320953,0,'Thrall - Battle for the Undercity'),
(@THRALL,46,1297.901855,341.402374,-60.082996,0,'Thrall - Battle for the Undercity'),
(@THRALL,47,1310.725830,343.401428,-65.027435,0,'Thrall - Battle for the Undercity'),
(@THRALL,48,1305.933350,350.961792,-65.365578,0,'Thrall - Battle for the Undercity');

-- Texts
DELETE FROM `creature_text` WHERE `entry` IN (@THRALL,@SYLVANAS,@VARIMATHRAS,@DISTANT_VOICE,@VARIAN,@SAURFANG);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(@THRALL,0,0,'HEROES OF THE HORDE, YOUR WARCHIEF CALLS!',14,0,100,0,0,16187,32339,0,'Thrall Yell 1'),
(@THRALL,1,0,'Gather behind me at the gates of the Undercity! Soon we march upon our fallen city and reclaim it - FOR THE HORDE!',14,0,100,0,0,16188,32361,0,'Thrall Yell 2'),
(@THRALL,2,0,'Blood and thunder, champions of the Horde! We fight on this day for our fallen brothers and sisters! Mourn them not for they all died with honor in their hearts!',14,0,100,0,0,16189,32340,0,'Thrall Yell 3'),
(@THRALL,3,0,'Though we face great conflict, our might combined shall obliterate those who would oppose us! The grave injustices committed against the Horde will be met by an unstoppable force of reckoning!',14,0,100,0,0,16190,32341,0,'Thrall Yell 4'),
(@THRALL,4,0,'I call to you great spirits! Grant the Horde your blessing! For on this day our cause is righteous and just!',14,0,100,0,0,16191,32342,0,'Thrall Yell 5'),
(@THRALL,5,0,'Spirits of wind, carry to Saurfang the Younger the song of war! May ALL of our fallen brethren be vindicated by this battle!',14,0,100,0,0,16192,32362,0,'Thrall Yell 6'),
(@THRALL,6,0,'The battle for the Undercity begins now! Sound the horns of war! Champions of the Horde, be empowered by the might of your Warchief!',14,0,100,0,0,16193,32363,0,'Thrall Yell 7'),
(@THRALL,7,0,'ONWARD!',14,0,100,0,0,16195,32366,0,'Thrall Yell 8'),
(@THRALL,8,0,'Great wind brother, clear our path!',12,0,100,0,0,16196,32367,0,'Thrall Say 1'),
(@THRALL,9,0,'A wind clears away the blight from Thrall\'s path',16,0,100,0,0,0,0,0,'Thrall Emote 1'), -- missing broadcast_text
(@THRALL,10,0,'You must answer to the elements, demon!',14,0,100,0,0,16197,32368,0,'Thrall Yell 9'),
(@THRALL,11,0,'Great water spirit, wash away this corruption!',12,0,100,0,0,16194,32369,0,'Thrall Say 2'),
(@THRALL,12,0,'ATTACK!!!!',14,0,100,0,0,16198,32396,0,'Thrall Yell 10'),
(@THRALL,13,0,'The courtyard is ours! Onward to the inner sanctum!',14,0,100,0,0,16199,32460,0,'Thrall Yell 11'),
(@THRALL,14,0,'HOLD! They\'ve destroyed the elevators!',12,0,100,0,0,16200,32461,0,'Thrall Say 3'),
(@THRALL,15,0,'Great air spirit, hear my call once more!',12,0,100,0,0,16201,32490,0,'Thrall Say 4'),
(@THRALL,16,0,'The spirits of air have heard my call. Cyclones will lower us to safety. Now we jump!',12,0,100,0,0,16202,32491,0,'Thrall Say 5'),
(@THRALL,17,0,'We have breached the inner sanctum, heroes! We press on!',14,0,100,0,0,16203,32494,0,'Thrall Yell 12'),
(@THRALL,18,0,'Lead the way, Dark Lady. We will follow.',12,0,100,0,0,16204,32496,0,'Thrall Say 6'),
(@THRALL,19,0,'Is that all, demon? Have you nothing left to throw at us?',14,0,100,0,0,16205,32553,0,'Thrall Yell 13'),
(@THRALL,20,0,'We come for you! Prepare yourself!',14,0,100,0,0,16206,32564,0,'Thrall Yell 14'),
(@THRALL,21,0,'COWARD! You think to stop the Warchief of the Horde with pebbles? I will show you the true power of the elements!',14,0,100,0,0,16207,32565,0,'Thrall Yell 15'),
(@THRALL,22,0,'Great spirit of the earth, help us in our hour of need!',14,0,100,0,0,16208,32575,0,'Thrall Yell 16'),
(@THRALL,23,0,'LET\'S GO! QUICKLY!',14,0,100,0,0,16210,32583,0,'Thrall Yell 17'),
(@THRALL,24,0,'What is this?',14,0,100,0,0,16211,32584,0,'Thrall Yell 18'),
(@THRALL,25,0,'WE ARE VICTORIOUS!',14,0,100,0,0,16212,32643,0,'Thrall Yell 19'),
(@THRALL,26,0,'The Undercity belongs to the Horde once more! LOK\'TAR!',14,0,100,0,0,16214,32644,0,'Thrall Yell 20'),
(@THRALL,27,0,'Dark Lady, join me! You have fought hard and spilled much blood for this right. The Royal Quarter belongs to you!',12,0,100,0,0,16215,32646,0,'Thrall Say 7'),
(@THRALL,28,0,'We shall, Sylvanas...',12,0,100,0,0,16216,32648,0,'Thrall Say 8'),
(@THRALL,29,0,'Alliance horns? Stay on guard!',12,0,100,0,0,16217,32649,0,'Thrall Say 9'),
(@THRALL,30,0,'It ends like it began...',12,0,100,0,0,16218,32728,0,'Thrall Say 10'),
(@THRALL,31,0,'All that we have fought for in this world is lost. The hopes and dreams carried by my father and mother... by Doomhammer... Gone...',12,0,100,0,0,16219,32729,0,'Thrall Say 11'),
(@THRALL,32,0,'If only you were here right now, old friend. You would know what to do.',12,0,100,0,0,16220,32730,0,'Thrall Say 12'),
(@THRALL,33,0,'It\'s good to have you back, Varok, old friend. I\'m sorry about your boy.',12,0,100,0,0,16221,32735,0,'Thrall Say 13'),
(@THRALL,34,0,'Thrall nods',16,0,100,0,0,0,0,0,'Thrall Emote 2'), -- missing broadcast_text

(@SYLVANAS,0,0,'Lady Sylvanas Windrunner begins to sing',41,0,100,0,0,0,0,0,'Sylvanas Emote 1'), -- missing broadcast_text
(@SYLVANAS,1,0,'The shaft is trapped, Warchief. A fall would mean certain death.',12,0,100,0,0,16300,32462,0,'Sylvanas Say 1'),
(@SYLVANAS,2,0,'What have they done to my beautiful city!',12,0,100,0,0,16301,32489,0,'Sylvanas Say 2'),
(@SYLVANAS,3,0,'The only redemption for the traitors responsible for this will be an agonizing death. My vengeance will be swift and without mercy!',12,0,100,0,0,16302,32495,0,'Sylvanas Say 3'),
(@SYLVANAS,4,0,'Very well, Warchief. The Royal Quarter is this way. Stay on guard. There\'s no telling what Varimathras and Putress have in store for us.',12,0,100,0,0,16303,32497,0,'Sylvanas Say 4'),
(@SYLVANAS,5,0,'HOLD! I sense dark magic. Demon magic... Stand ready!',12,0,100,0,0,16304,32520,0,'Sylvanas Say 5'),
(@SYLVANAS,6,0,'The Royal Quarter is just up ahead, Warchief.',12,0,100,0,0,16305,32567,0,'Sylvanas Say 6'),
(@SYLVANAS,7,0,'Such will be the fate of all enemies of the Horde, Warchief. Now we must deal with the wretch, Putress.',12,0,100,0,0,16306,32647,0,'Sylvanas Say 7'),

(@VARIMATHRAS,0,0,'Varimathras makes the halls shake, bringing down stones to block the hall to the Royal Quarter',16,0,100,0,0,0,0,0,'Varimathras Emote 1'), -- missing broadcast_text
(@VARIMATHRAS,1,0,'Varimathras spawns untold numbers of demons',16,0,100,0,0,0,0,0,'Varimathras Emote 2'), -- missing broadcast_text
(@VARIMATHRAS,2,0,'Welcome to my kingdom of darkness!',14,0,100,0,0,16156,32375,0,'Varimathras Yell 1'),
(@VARIMATHRAS,3,0,'Did you enjoy my minion\'s terrible creation? Potent, is it not?',14,0,100,0,0,16157,32376,0,'Varimathras Yell 2'),
(@VARIMATHRAS,4,0,'But enough prattling! You wish to reclaim your city? Come then, heroes! Your souls will fuel the host! You will have this place back in pieces!',14,0,100,0,0,16158,32383,0,'Varimathras Yell 3'),
(@VARIMATHRAS,5,0,'Clever girl...',14,0,100,0,0,16159,32521,0,'Varimathras Yell 4'),
(@VARIMATHRAS,6,0,'My brothers have grown hungry. Your souls will sate their appetites.',14,0,100,0,0,16160,32524,0,'Varimathras Yell 5'),
(@VARIMATHRAS,7,0,'Bring down the halls! NOW!',14,0,100,0,0,16161,32568,0,'Varimathras Yell 6'),
(@VARIMATHRAS,8,0,'Welcome to your future -- what little there is left of it...',14,0,100,0,0,16163,32580,0,'Varimathras Yell 7'),
(@VARIMATHRAS,9,0,'Too long... Tireless, endless planning... It will not end like this...',14,0,100,0,0,16164,32610,0,'Varimathras Yell 8'),
(@VARIMATHRAS,10,0,'Need more time... The Master is near...',14,0,100,0,0,16165,32611,0,'Varimathras Yell 9'),
(@VARIMATHRAS,11,0,'Such power! Can you not feel it, mortals? Cease this foolishness and join me!',14,0,100,0,0,16166,32612,0,'Varimathras Yell 11'),
(@VARIMATHRAS,12,0,'I will not fail! Not again!',14,0,100,0,0,16167,32613,0,'Varimathras Yell 11'),
(@VARIMATHRAS,13,0,'I cannot hold... Destabilizing...',14,0,100,0,0,16168,32614,0,'Varimathras Yell 12'),
(@VARIMATHRAS,14,0,'A thousand-thousand pardons, Master! I will deal with these intruders myself!',14,0,100,0,0,16162,32579,0,'Varimathras Yell 13'),
(@VARIMATHRAS,15,0,'Years... wasted...',14,0,100,0,0,16169,32617,0,'Varimathras Yell 14'),

(@DISTANT_VOICE,6,0,'YOU HAVE FAILED ME, VARIMATHRAS!',14,0,100,0,0,16180,32618,0,'A distant voice Yell 1'), -- sargeras?

(@VARIAN,0,0,'I was away for too long. My absence cost us the lives of some of our greatest heroes. Trash like you and this evil witch were allowed to roam free -- unchecked.',12,0,100,0,0,16073,32691,0,'Varian Say 1'),
(@VARIAN,1,0,'The time has come to make things right. To disband your treacherous kingdom of murderers and thieves. Putress was the first strike. Many more will come.',12,0,100,0,0,16074,32693,0,'Varian Say 2'),
(@VARIAN,2,0,'I\'ve waited a long time for this, Thrall. For every time I was thrown into one of your damned arenas... for every time I killed a green-skinned aberration like you... I could only think of one thing.',12,0,100,0,0,16075,32697,0,'Varian Say 3'),
(@VARIAN,3,0,'What our world could be without you and your twisted Horde... It ends now, Warchief.',12,0,100,0,0,16076,32699,0,'Varian Say 4'),
(@VARIAN,4,0,'ATTACK! FOR STORMWIND! FOR BOLVAR! FOR THE ALLIANCE!',12,0,100,0,0,16077,32700,0,'Varian Say 5'),

(@SAURFANG,0,0,'I know what he would do.',12,0,100,0,0,16286,32731,0,'Saurfang Say 1'),
(@SAURFANG,1,0,'He would say to you what I am about to say to you: Thrall. Lead your people.',12,0,100,0,0,16287,32732,0,'Saurfang Say 1'),
(@SAURFANG,2,0,'Let\'s go home, old friend.',12,0,100,0,0,16288,32733,0,'Saurfang Say 1');

-- SAIs
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@SYLVANAS);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@SYLVANAS, 0, 0, 0, 9, 0, 100, 0, 0, 30, 12500, 15000, 11, 59515, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Sylvanas - on 0-30y - cast Multi-Shot'), 
(@SYLVANAS, 0, 1, 0, 0, 0, 100, 0, 17000, 29000, 25000, 30000, 11, 59514, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Sylvanas - IC - cast Shriek of the Highborne'), 
(@SYLVANAS, 0, 2, 3, 4, 0, 100, 1, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sylvanas - On Aggro - Stop movement'), 
(@SYLVANAS, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 11, 41188, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Sylvanas - On Aggro - Cast Shoot'), 
(@SYLVANAS, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sylvanas - On Aggro - Set Phase to 1'), 
(@SYLVANAS, 0, 6, 0, 0, 1, 100, 0, 2200, 4700, 2200, 4700, 11, 41188, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Sylvanas - Cast Shoot (Phase 1)'), 
(@SYLVANAS, 0, 7, 0, 9, 1, 100, 0, 20, 100, 0, 0, 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sylvanas - In 20-100Y - start movement (Phase 1)'), 
(@SYLVANAS, 0, 8, 0, 9, 1, 100, 0, 6, 10, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sylvanas - In 6-10Y - stop movement (Phase 1)'), 
(@SYLVANAS, 0, 9, 0, 9, 1, 100, 0, 0, 5, 0, 0, 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sylvanas - In 0-5Y - start movement (Phase 1)'),
(@SYLVANAS, 0, 10, 0, 8, 0, 100, 0, 56346, 0, 0, 0, 11, 56347, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sylvanas - on spellhit - cast Leap to Platform'),
(@SYLVANAS, 0, 11, 0, 0, 0, 100, 0, 60000, 70000, 80000, 90000, 11, 60046, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sylvanas - IC - cast Assassinate');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@DEMOLISHER);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@DEMOLISHER, 0, 0, 0, 1, 0, 100, 0, 15000, 20000, 20000, 25000, 11, 59464, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Horde Demolisher - IC - cast Boulder Assault');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@STALKER_TESLA);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@STALKER_TESLA, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 49132, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stalker Tesla - on reset - cast cosmetic fire aura');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@WARSONG_BATTLEGUARD);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@WARSONG_BATTLEGUARD, 0, 0, 0, 9, 0, 100, 0, 8, 25, 12000, 19000, 11, 57793, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Warsong Battleguard - on 5-25y - cast Heroic Leap');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@BLIGHT_TRIGGER);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@BLIGHT_TRIGGER, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 59236, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Blight Trigger - on reset - cast Blight Cloud'),
(@BLIGHT_TRIGGER, 0, 1, 0, 8, 0, 100, 0, 59668, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Blight Trigger - on spellhit - despawn');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@BLIGHT_SLINGER);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@BLIGHT_SLINGER, 0, 0, 0, 1, 0, 100, 0, 10000, 15000, 15000, 20000, 11, 59284, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Blight Splinger - OOC - cast Blight Barrel');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@VORTEX);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@VORTEX, 0, 0, 1, 25, 0, 100, 0, 0, 0, 0, 0, 11, 59666, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Great Vortex - on reset - cast Vortex'),
(@VORTEX, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Great Vortex - on reset - stop run');

DELETE FROM `waypoint_data` WHERE `id` IN (@VORTEX*10,@VORTEX*10+1);
INSERT INTO `waypoint_data` VALUES
(@VORTEX*10,1,1863.22,242.27,62.28,0,0,0,0,100,0),
(@VORTEX*10,2,1862.51,248.22,62.27,0,0,0,0,100,0),
(@VORTEX*10,3,1854.78,247.89,62.27,0,0,0,0,100,0),
(@VORTEX*10,4,1852.96,238.10,62.27,0,0,0,0,100,0),
(@VORTEX*10,5,1836.94,232.62,60.28,0,0,0,0,100,0),

(@VORTEX*10+1,1,1863.33,233.98,62.28,0,0,0,0,100,0),
(@VORTEX*10+1,2,1862.25,228.19,62.27,0,0,0,0,100,0),
(@VORTEX*10+1,3,1853.95,228.51,62.27,0,0,0,0,100,0),
(@VORTEX*10+1,4,1852.19,238.01,62.27,0,0,0,0,100,0),
(@VORTEX*10+1,5,1836.72,244.59,60.12,0,0,0,0,100,0);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@CYCLONE);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@CYCLONE, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 59838, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Air Cyclone - on reset - cast Air Entrance revenant');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@VARIMATHRAS_PORTAL);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@VARIMATHRAS_PORTAL, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 60284, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Varimathras Portal - on reset - cast Legion World Portal');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@GUARDIAN);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@GUARDIAN, 0, 0, 0, 9, 0, 100, 0, 8, 40, 15000, 20000, 11, 59395, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Treacherous Guardian - on 8-40y - cast Abomination Hook');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@DREADLORD);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@DREADLORD, 0, 0, 0, 0, 0, 100, 0, 18000, 23000, 17000, 24000, 11, 22884, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Perfidious Dreadlord - IC - cast Psychic Scream'),
(@DREADLORD, 0, 1, 0, 0, 0, 100, 0, 1000, 3000, 5000, 7000, 11, 15587, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Perfidious Dreadlord - IC - cast Mind Blast'),
(@DREADLORD, 0, 2, 0, 0, 0, 100, 0, 9000, 14000, 12000, 16000, 11, 37624, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Perfidious Dreadlord - IC - cast Carrion Swarm');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@FELBEAST);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@FELBEAST, 0, 0, 0, 0, 0, 100, 0, 9000, 15000, 8000, 14000, 11, 38356, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Plagued Felbeast - IC - cast Psychic Scream'),
(@FELBEAST, 0, 1, 0, 9, 0, 100, 0, 0, 5, 12000, 16000, 11, 16128, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Plagued Felbeast - on 5y - cast Infected Bite');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@MARAUDER);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@MARAUDER, 0, 0, 0, 9, 0, 100, 0, 0, 5, 7000, 12000, 11, 15284, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Felguard Marauder - on 5y - cast Cleave'),
(@MARAUDER, 0, 1, 0, 0, 0, 100, 0, 9000, 15000, 16000, 21000, 11, 18072, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Felguard Marauder - IC - cast Uppercut'),
(@MARAUDER, 0, 2, 0, 0, 0, 100, 0, 12000, 18000, 18000, 24000, 11, 23113, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Felguard Marauder - IC - cast Blast Wave');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@BETRAYER);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@BETRAYER, 0, 0, 0, 9, 0, 100, 0, 0, 5, 6000, 9000, 11, 32202, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Ravishing Betrayer - on 5y - cast Lash of Pain'),
(@BETRAYER, 0, 1, 0, 0, 0, 100, 0, 9000, 14000, 8000, 12000, 11, 24616, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Ravishing Betrayer - IC - cast Shadow Shock');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@CHEMIST);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@CHEMIST, 0, 0, 0, 0, 0, 100, 0, 11000, 16000, 18000, 24000, 11, 59122, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Apothecary Chemist - IC - cast Vial of Blight');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@STORMWIND_ELITE);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@STORMWIND_ELITE, 0, 0, 0, 9, 0, 100, 0, 0, 5, 12000, 15000, 11, 9080, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Stormwind Elite - on 5 y - cast Harmstring'),
(@STORMWIND_ELITE, 0, 1, 0, 13, 0, 100, 0, 8000, 12000, 0, 0, 11, 11972, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Stormwind Elite - on target casting - cast Shield Bash'),
(@STORMWIND_ELITE, 0, 2, 0, 0, 0, 100, 0, 7000, 10000, 7000, 10000, 11, 14516, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Stormwind Elite - IC - cast Strike');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@BLIGHT_SPREADER);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@BLIGHT_SPREADER, 0, 0, 0, 0, 0, 100, 0, 5000, 8000, 8000, 12000, 11, 59460, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Blight Spreader - IC - cast Throw Blight Barrel'),
(@BLIGHT_SPREADER, 0, 1, 0, 0, 0, 100, 0, 10000, 12000, 15000, 20000, 11, 50989, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Blight Spreader - IC - cast Flame Breath'),
(@BLIGHT_SPREADER, 0, 2, 0, 4, 0, 100, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Blight Spreader - on aggro - stop combat movement'),
(@BLIGHT_SPREADER, 0, 3, 0, 25, 0, 100, 0, 0, 0, 0, 0, 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Blight Spreader - on reset - allow combat movement');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@BLIGHT_ABERRATION);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@BLIGHT_ABERRATION, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 11, 7741, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Blight Aberration - on just summoned - cast Summoned Demon');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@KHANOK);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@KHANOK, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 11, 7741, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Khanok - on just summoned - cast Summoned Demon'),
(@KHANOK, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 0, @KHANOK, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 'Khanok - on just summoned - wp start'),
(@KHANOK, 0, 2, 3, 58, 0, 100, 0, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Khanok - on wp ended - remove unit flags'),
(@KHANOK, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 19, @THRALL, 50, 0, 0, 0, 0, 0, 'Khanok - on pos 2 - cast on Thrall'),
(@KHANOK, 0, 4, 0, 0, 0, 100, 0, 12000, 15000, 20000, 22000, 11, 60084, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Khanok - IC - cast The Veil of Shadows'),
(@KHANOK, 0, 5, 0, 0, 0, 100, 0, 30000, 30000, 30000, 30000, 11, 60183, 0, 0, 0, 0, 0, 19, @PILLARGER, 100, 0, 0, 0, 0, 0, 'Khanok - IC - cast Throw Blight Barrel'),
(@KHANOK, 0, 6, 0, 9, 0, 100, 0, 4, 40, 10000, 10000, 11, 61104, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Khanok - on 4-40 y - cast Grip Darkness');

DELETE FROM `waypoints` WHERE `entry`=@KHANOK;
INSERT INTO `waypoints` VALUES
(@KHANOK,1,1589.205811,397.432007,-66.297363,'Khanok WP 1'),
(@KHANOK,2,1592.965210,376.265747,-62.177574,'Khanok WP 2');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@OVERLORD);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@OVERLORD, 0, 0, 0, 0, 0, 100, 0, 10000, 10000, 15000, 20000, 11, 26073, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Overlord - IC - cast Fire Nova');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@INVADER);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@INVADER, 0, 0, 0, 9, 0, 100, 0, 0, 5, 12000, 15000, 11, 38572, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Invader - on 5 y - cast Mortal Cleave');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@VARIAN);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@VARIAN, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 11, 60509, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Varian - on just summoned - cast Strength of Wrynn'),
(@VARIAN, 0, 1, 0, 4, 0, 100, 0, 0, 0, 0, 0, 11, 59688, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Varian - on aggro - cast Heroic Leap'),
(@VARIAN, 0, 2, 0, 0, 0, 100, 0, 5000, 6000, 6000, 8000, 11, 41056, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Varian - IC - cast Whirlwind');