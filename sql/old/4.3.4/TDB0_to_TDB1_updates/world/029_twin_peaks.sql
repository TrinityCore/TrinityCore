SET @OGUID :=60;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+15;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 179871, 726, 1, 1, 2175.866, 226.6215, 43.76288, 2.600535, 0, 0, 0, 1, 7200, 255, 1), -- Speed Buff (Area: -Unknown-)
(@OGUID+1, 179830, 726, 1, 1, 2117.637, 191.6823, 44.05199, 6.021387, 0, 0, 0, 1, 7200, 255, 1), -- Silverwing Flag (Area: Wildhammer Stronghold)
(@OGUID+2, 179905, 726, 1, 1, 1932.832, 226.7917, -17.05979, 2.44346, 0, 0, 0, 1, 7200, 255, 1), -- Berserk Buff (Area: 0)
(@OGUID+3, 207075, 726, 1, 1, 1986.051, 420.5457, -20.70723, 5.148723, 0, 0, 0.3907311, 0.9205049, 7200, 255, 1), -- -Unknown- (Area: Wildhammer Stronghold)
(@OGUID+4, 207076, 726, 1, 1, 1953.241, 394.6901, -9.542231, 0.5497769, 0, 0, 0.3907311, 0.9205049, 7200, 255, 1), -- -Unknown- (Area: Wildhammer Stronghold)
(@OGUID+5, 179904, 726, 1, 1, 1951.18, 383.795, -10.5257, 4.06662, 0, 0, 0, 1, 7200, 255, 1), -- Food Buff (Area: Wildhammer Stronghold)
(@OGUID+6, 179904, 726, 1, 1, 1951.18, 383.795, -10.5257, 4.06662, 0, 0, 0, 1, 7200, 255, 1), -- Food Buff (Area: 0)
(@OGUID+7, 179906, 726, 1, 1, 1754.163, 242.125, -14.13157, 1.151916, 0, 0, 0, 1, 7200, 255, 1), -- Food Buff (Area: 0)
(@OGUID+8, 179907, 726, 1, 1, 1737.566, 435.8455, -8.086342, 5.515242, 0, 0, 0, 1, 7200, 255, 1), -- Berserk Buff (Area: 0)
(@OGUID+9, 179906, 726, 1, 1, 1754.163, 242.125, -14.13157, 1.151916, 0, 0, 0, 1, 7200, 255, 1), -- Food Buff (Area: 0)
(@OGUID+10, 179831, 726, 1, 1, 1578.337, 344.0451, 2.418409, 2.792518, 0, 0, 0, 1, 7200, 255, 1), -- Warsong Flag (Area: Dragonmaw Stronghold)
(@OGUID+11, 179904, 726, 1, 1, 1951.18, 383.795, -10.5257, 4.06662, 0, 0, 0, 1, 7200, 255, 1), -- Food Buff (Area: 0)
(@OGUID+12, 179905, 726, 1, 1, 1932.832, 226.7917, -17.05979, 2.44346, 0, 0, 0, 1, 7200, 255, 1), -- Berserk Buff (Area: Wildhammer Stronghold)
(@OGUID+13, 179904, 726, 1, 1, 1951.18, 383.795, -10.5257, 4.06662, 0, 0, 0, 1, 7200, 255, 1), -- Food Buff (Area: 0)
(@OGUID+14, 179904, 726, 1, 1, 1951.18, 383.795, -10.5257, 4.06662, 0, 0, 0, 1, 7200, 255, 1), -- Food Buff (Area: 0)
(@OGUID+15, 179786, 726, 1, 1, 2107.039, 210.6103, 43.66296, 3.968888, 0, 0, 0, 1, 7200, 255, 1); -- Warsong Flag (Area: Wildhammer Flag Room)


UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=2339, `faction_H`=2339, `speed_walk`=2.285714, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33554688, `HoverHeight`=1 WHERE `entry`=51127; -- Wildhammer Gryphon
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=2339, `faction_H`=2339, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33587968, `HoverHeight`=1 WHERE `entry`=51128; -- Wildhammer Guard
UPDATE `creature_template` SET `faction_A`=2362, `faction_H`=2362, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33555200, `HoverHeight`=1 WHERE `entry`=51126; -- Wildhammer Gryphon Hatchling
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33554432, `HoverHeight`=1 WHERE `entry`=52977; -- World Trigger (Friendly + Invis Stalker)
UPDATE `creature_template` SET `minlevel`=82, `maxlevel`=83, `faction_A`=2305, `faction_H`=2305, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33555200, `HoverHeight`=1 WHERE `entry`=51130; -- Dragonmaw Worker
UPDATE `creature_template` SET `minlevel`=12, `maxlevel`=13, `faction_A`=189, `faction_H`=189, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33555200, `HoverHeight`=1 WHERE `entry`=42615; -- Twin Peaks Boar
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=84, `faction_H`=84, `npcflag`=32768, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=832, `HoverHeight`=1 WHERE `entry`=13116; -- Alliance Spirit Guide
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=83, `faction_H`=83, `npcflag`=32768, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=832, `HoverHeight`=1 WHERE `entry`=13117; -- Horde Spirit Guide


DELETE FROM `creature_template_addon` WHERE `entry` IN (51127, 51128, 51126, 51126, 51126, 51126, 51128, 51128, 51126, 51127, 51128, 51128, 51126, 51126, 51126, 51126, 51128, 51127, 51127, 51127, 51128, 51128, 51128, 51127, 51127, 51127, 51127, 51128, 51128, 51128, 51128, 51128, 51128, 51128, 51127, 51127, 51127, 52977, 51127, 51130, 51130, 51130, 51130, 51130, 51130, 51130, 51130, 51130, 51130, 51127, 51130, 51127, 51127, 51130, 42615, 42615, 51130, 51130, 51130, 42615, 42615, 42615, 51130, 51127, 51130, 51130, 42615, 42615, 51130, 51127, 51127, 51127, 51127, 51127, 51127, 51127, 51127, 51127, 13116, 13117, 13116, 51127, 51127, 51127, 51127, 51127, 51127, 51127, 51127, 51127, 51127, 51127, 51127, 51127, 51127, 51127, 51127, 51127);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(51127, 0, 0x0, 0x1, ''), -- Wildhammer Gryphon
-- (51128, 0, 0x0, 0x1, ''), -- Wildhammer Guard
(51126, 0, 0x0, 0x1, ''), -- Wildhammer Gryphon Hatchling
(51128, 0, 0x0, 0x0, ''), -- Wildhammer Guard
(52977, 0, 0x0, 0x1, ''), -- World Trigger (Friendly + Invis Stalker)
(51130, 0, 0x0, 0x1, ''), -- Dragonmaw Worker
-- (51130, 0, 0x8, 0x1, ''), -- Dragonmaw Worker
(42615, 0, 0x0, 0x1, ''), -- Twin Peaks Boar
(13116, 0, 0x10000, 0x1, '22011'), -- Alliance Spirit Guide - Spirit Heal Channel
(13117, 0, 0x10000, 0x1, '22011'); -- Horde Spirit Guide - Spirit Heal Channel


UPDATE `creature_model_info` SET `bounding_radius`=0.882, `combat_reach`=0.75 WHERE `modelid`=389;
UPDATE `creature_model_info` SET `bounding_radius`=1.176, `combat_reach`=1 WHERE `modelid`=744;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=13336;
UPDATE `creature_model_info` SET `bounding_radius`=0.208, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=13337;
UPDATE `creature_model_info` SET `bounding_radius`=0.8725, `combat_reach`=3.75, `gender`=1 WHERE `modelid`=13339;
UPDATE `creature_model_info` SET `bounding_radius`=0.31, `combat_reach`=1 WHERE `modelid`=17759;
UPDATE `creature_model_info` SET `bounding_radius`=0.347, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=18749;
UPDATE `creature_model_info` SET `bounding_radius`=0.347, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=18750;
UPDATE `creature_model_info` SET `bounding_radius`=0.347, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=18751;
UPDATE `creature_model_info` SET `bounding_radius`=0.347, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=18752;
UPDATE `creature_model_info` SET `bounding_radius`=0.045 WHERE `modelid`=30412;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=33346;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=33347;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=33348;
UPDATE `creature_model_info` SET `bounding_radius`=0.31, `combat_reach`=1 WHERE `modelid`=34890;
UPDATE `creature_model_info` SET `bounding_radius`=0.075 WHERE `modelid`=36332;
UPDATE `creature_model_info` SET `bounding_radius`=0.06 WHERE `modelid`=36336;

SET @CGUID :=131;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+97;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 51127, 726, 1, 1, 1878.674, -17.76215, 45.33773, 1.204277, 7200, 0, 0), -- Wildhammer Gryphon (Area: -Unknown-) (possible waypoints or random movement)
(@CGUID+1, 51128, 726, 1, 1, 1973.71, 168.5017, -4.376678, 4.852015, 7200, 0, 0), -- Wildhammer Guard (Area: Wildhammer Stronghold)
(@CGUID+2, 51126, 726, 1, 1, 1975.323, 179.8021, -4.407125, 4.660029, 7200, 0, 0), -- Wildhammer Gryphon Hatchling (Area: Wildhammer Stronghold) (possible waypoints or random movement)
(@CGUID+3, 51126, 726, 1, 1, 1970.083, 172.7257, -4.407125, 4.660029, 7200, 0, 0), -- Wildhammer Gryphon Hatchling (Area: Wildhammer Stronghold) (possible waypoints or random movement)
(@CGUID+4, 51126, 726, 1, 1, 1966.523, 183.7569, -4.407125, 4.660029, 7200, 0, 0), -- Wildhammer Gryphon Hatchling (Area: Wildhammer Stronghold) (possible waypoints or random movement)
(@CGUID+5, 51126, 726, 1, 1, 1985.748, 162.4809, 0.5268366, 4.660029, 7200, 0, 0), -- Wildhammer Gryphon Hatchling (Area: Wildhammer Stronghold) (possible waypoints or random movement)
(@CGUID+6, 51128, 726, 1, 1, 1972.122, 195.9913, -4.079089, 4.39823, 7200, 0, 0), -- Wildhammer Guard (Area: Wildhammer Stronghold)
(@CGUID+7, 51128, 726, 1, 1, 1953.998, 181.7795, -4.440118, 0.03490658, 7200, 0, 0), -- Wildhammer Guard (Area: Wildhammer Stronghold)
(@CGUID+8, 51126, 726, 1, 1, 1956.556, 171.5816, -4.407125, 4.660029, 7200, 0, 0), -- Wildhammer Gryphon Hatchling (Area: Wildhammer Stronghold) (possible waypoints or random movement)
(@CGUID+9, 51127, 726, 1, 1, 1890.335, -17.76215, 45.33773, 1.117011, 7200, 0, 0), -- Wildhammer Gryphon (Area: Wildhammer Stronghold) (possible waypoints or random movement)
(@CGUID+10, 51128, 726, 1, 1, 1936.5, 229.0521, -17.00923, 5.218534, 7200, 0, 0), -- Wildhammer Guard (Area: 0)
(@CGUID+11, 51128, 726, 1, 1, 1933.481, 202.1754, -16.88152, 4.572762, 7200, 0, 0), -- Wildhammer Guard (Area: 0)
(@CGUID+12, 51126, 726, 1, 1, 1932.455, 205.7616, -17.01718, 2.861426, 7200, 0, 0), -- Wildhammer Gryphon Hatchling (Area: 0) (possible waypoints or random movement)
(@CGUID+13, 51126, 726, 1, 1, 1940.066, 236.6979, -14.6197, 4.660029, 7200, 0, 0), -- Wildhammer Gryphon Hatchling (Area: 0) (possible waypoints or random movement)
(@CGUID+14, 51126, 726, 1, 1, 1926.195, 228.125, -17.53668, 3.141593, 7200, 0, 0), -- Wildhammer Gryphon Hatchling (Area: 0) (possible waypoints or random movement)
(@CGUID+15, 51126, 726, 1, 1, 1925.845, 218.7499, -17.02013, 2.81808, 7200, 0, 0), -- Wildhammer Gryphon Hatchling (Area: 0) (possible waypoints or random movement)
(@CGUID+16, 51128, 726, 1, 1, 1935.175, 209.8661, -17.01039, 0.4593565, 7200, 0, 0), -- Wildhammer Guard (Area: 0) (possible waypoints or random movement)
(@CGUID+17, 51127, 726, 1, 1, 1878.674, -17.76215, 45.33773, 1.204277, 7200, 0, 0), -- Wildhammer Gryphon (Area: 0) (possible waypoints or random movement)
(@CGUID+18, 51127, 726, 1, 1, 1878.674, -17.76215, 45.33773, 1.204277, 7200, 0, 0), -- Wildhammer Gryphon (Area: Wildhammer Flag Room) (possible waypoints or random movement)
(@CGUID+19, 51127, 726, 1, 1, 1890.335, -17.76215, 45.33773, 1.117011, 7200, 0, 0), -- Wildhammer Gryphon (Area: Wildhammer Stronghold) (possible waypoints or random movement)
(@CGUID+20, 51128, 726, 1, 1, 1974.141, 375.4219, -9.842425, 1.884956, 7200, 0, 0), -- Wildhammer Guard (Area: Wildhammer Stronghold)
(@CGUID+21, 51128, 726, 1, 1, 1991.036, 391.875, -5.526042, 2.775074, 7200, 0, 0), -- Wildhammer Guard (Area: Wildhammer Stronghold)
(@CGUID+22, 51128, 726, 1, 1, 1978.517, 403.2431, -4.943089, 6.073746, 7200, 0, 0), -- Wildhammer Guard (Area: Wildhammer Stronghold)
(@CGUID+23, 51127, 726, 1, 1, 1932.954, -12.67253, 19.61401, 1.72534, 7200, 0, 0), -- Wildhammer Gryphon (Area: Wildhammer Stronghold)
(@CGUID+24, 51127, 726, 1, 1, 1880.12, 22.55383, 32.50345, 1.335938, 7200, 0, 0), -- Wildhammer Gryphon (Area: Wildhammer Stronghold)
(@CGUID+25, 51127, 726, 1, 1, 1890.335, -17.76215, 45.33773, 1.117011, 7200, 0, 0), -- Wildhammer Gryphon (Area: Wildhammer Flag Room) (possible waypoints or random movement)
(@CGUID+26, 51127, 726, 1, 1, 1878.674, -17.76215, 45.33773, 1.204277, 7200, 0, 0), -- Wildhammer Gryphon (Area: Wildhammer Stronghold) (possible waypoints or random movement)
(@CGUID+27, 51128, 726, 1, 1, 1946.863, 362.0295, -14.45387, 0.418879, 7200, 0, 0), -- Wildhammer Guard (Area: Wildhammer Stronghold)
(@CGUID+28, 51128, 726, 1, 1, 1922.563, 388.8559, -14.39674, 0.2443461, 7200, 0, 0), -- Wildhammer Guard (Area: Wildhammer Stronghold)
(@CGUID+29, 51128, 726, 1, 1, 1914.78, 359.684, -19.51139, 3.281219, 7200, 0, 0), -- Wildhammer Guard (Area: Wildhammer Stronghold)
(@CGUID+30, 51128, 726, 1, 1, 1928.988, 411.8125, -12.1624, 0.1047198, 7200, 0, 0), -- Wildhammer Guard (Area: Wildhammer Stronghold)
(@CGUID+31, 51128, 726, 1, 1, 1956.732, 404.1992, -9.047995, 0.5061455, 7200, 0, 0), -- Wildhammer Guard (Area: Wildhammer Stronghold) (possible waypoints or random movement)
(@CGUID+32, 51128, 726, 1, 1, 1944.977, 416.2066, -10.00108, 6.056293, 7200, 0, 0), -- Wildhammer Guard (Area: Wildhammer Stronghold)
(@CGUID+33, 51128, 726, 1, 1, 1946.829, 407.9122, -9.483633, 4.991826, 7200, 0, 0), -- Wildhammer Guard (Area: Wildhammer Stronghold) (possible waypoints or random movement)
(@CGUID+34, 51127, 726, 1, 1, 1877.621, 5.201612, 38.05733, 1.5474, 7200, 0, 0), -- Wildhammer Gryphon (Area: 0)
(@CGUID+35, 51127, 726, 1, 1, 1890.335, -17.76215, 45.33773, 1.117011, 7200, 0, 0), -- Wildhammer Gryphon (Area: 0) (possible waypoints or random movement)
(@CGUID+36, 51127, 726, 1, 1, 1878.674, -17.76215, 45.33773, 1.204277, 7200, 0, 0), -- Wildhammer Gryphon (Area: 0) (possible waypoints or random movement)
(@CGUID+37, 52977, 726, 1, 1, 1818.918, 156.9167, 1.889777, 1.815142, 7200, 0, 0), -- World Trigger (Friendly + Invis Stalker) (Area: 0)
(@CGUID+38, 51127, 726, 1, 1, 1878.674, -17.76215, 45.33773, 1.204277, 7200, 0, 0), -- Wildhammer Gryphon (Area: 0) (possible waypoints or random movement)
(@CGUID+39, 51130, 726, 1, 1, 1732.887, 200.5521, -9.827867, 5.201081, 7200, 0, 0), -- Dragonmaw Worker (Area: 0)
(@CGUID+40, 51130, 726, 1, 1, 1737.274, 232.3924, -13.90292, 5.969026, 7200, 0, 0), -- Dragonmaw Worker (Area: 0)
(@CGUID+41, 51130, 726, 1, 1, 1769.95, 226.9879, -13.90292, 5.654867, 7200, 0, 0), -- Dragonmaw Worker (Area: 0)
(@CGUID+42, 51130, 726, 1, 1, 1765.217, 213.0816, -13.90292, 0.3141593, 7200, 0, 0), -- Dragonmaw Worker (Area: 0)
(@CGUID+43, 51130, 726, 1, 1, 1777.592, 263.0399, -18.27896, 3.054326, 7200, 0, 0), -- Dragonmaw Worker (Area: 0)
(@CGUID+44, 51130, 726, 1, 1, 1747.33, 258.4913, -13.90227, 4.066617, 7200, 0, 0), -- Dragonmaw Worker (Area: 0)
(@CGUID+45, 51130, 726, 1, 1, 1747.47, 241.1632, -13.90293, 3.839724, 7200, 0, 0), -- Dragonmaw Worker (Area: 0)
(@CGUID+46, 51130, 726, 1, 1, 1759.554, 225.2465, -13.94948, 1.797689, 7200, 0, 0), -- Dragonmaw Worker (Area: 0) (possible waypoints or random movement)
(@CGUID+47, 51130, 726, 1, 1, 1773.512, 218.0191, -14.04847, 2.879793, 7200, 0, 0), -- Dragonmaw Worker (Area: 0)
(@CGUID+48, 51130, 726, 1, 1, 1753.467, 296.0469, -13.16725, 2.460914, 7200, 0, 0), -- Dragonmaw Worker (Area: 0)
(@CGUID+49, 51127, 726, 1, 1, 1890.335, -17.76215, 45.33773, 1.117011, 7200, 0, 0), -- Wildhammer Gryphon (Area: 0) (possible waypoints or random movement)
(@CGUID+50, 51130, 726, 1, 1, 1767.208, 401.441, -15.22443, 2.181662, 7200, 0, 0), -- Dragonmaw Worker (Area: 0)
(@CGUID+51, 51127, 726, 1, 1, 2087.113, 168.289, 104.5053, 3.006558, 7200, 0, 0), -- Wildhammer Gryphon (Area: 0) (possible waypoints or random movement)
(@CGUID+52, 51127, 726, 1, 1, 2096.856, 302.8097, 98.42361, 3.006042, 7200, 0, 0), -- Wildhammer Gryphon (Area: 0) (possible waypoints or random movement)
(@CGUID+53, 51130, 726, 1, 1, 1787.04, 448.4427, -14.09361, 0.9250245, 7200, 0, 0), -- Dragonmaw Worker (Area: 0)
(@CGUID+54, 42615, 726, 1, 1, 1755.885, 441.5816, -7.899209, 3.892084, 7200, 0, 0), -- Twin Peaks Boar (Area: 0)
(@CGUID+55, 42615, 726, 1, 1, 1749.061, 419.1945, -8.031966, 4.08407, 7200, 0, 0), -- Twin Peaks Boar (Area: 0)
(@CGUID+56, 51130, 726, 1, 1, 1759.196, 431.1667, -8.128761, 3.630285, 7200, 0, 0), -- Dragonmaw Worker (Area: 0)
(@CGUID+57, 51130, 726, 1, 1, 1739.951, 412.0972, -7.915442, 2.129302, 7200, 0, 0), -- Dragonmaw Worker (Area: 0)
(@CGUID+58, 51130, 726, 1, 1, 1784.918, 457.6371, -12.08598, 1.53589, 7200, 0, 0), -- Dragonmaw Worker (Area: 0)
(@CGUID+59, 42615, 726, 1, 1, 1738.811, 418.1858, -7.916156, 4.782202, 7200, 0, 0), -- Twin Peaks Boar (Area: 0)
(@CGUID+60, 42615, 726, 1, 1, 1750.323, 433.0492, -7.96629, 2.533708, 7200, 0, 0), -- Twin Peaks Boar (Area: 0) (possible waypoints or random movement)
(@CGUID+61, 42615, 726, 1, 1, 1745.186, 418.5451, -7.840154, 5.51524, 7200, 0, 0), -- Twin Peaks Boar (Area: 0)
(@CGUID+62, 51130, 726, 1, 1, 1768.049, 411.3681, -13.01563, 3.769911, 7200, 0, 0), -- Dragonmaw Worker (Area: 0)
(@CGUID+63, 51127, 726, 1, 1, 2194.064, 350.5839, 66.43506, 4.394663, 7200, 0, 0), -- Wildhammer Gryphon (Area: 0) (possible waypoints or random movement)
(@CGUID+64, 51130, 726, 1, 1, 1713.207, 426.4809, -5.051408, 2.617994, 7200, 0, 0), -- Dragonmaw Worker (Area: 0)
(@CGUID+65, 51130, 726, 1, 1, 1726.76, 425.8802, -7.734254, 2.600541, 7200, 0, 0), -- Dragonmaw Worker (Area: 0)
(@CGUID+66, 42615, 726, 1, 1, 1730.788, 423.4054, -7.867835, 4.653298, 7200, 0, 0), -- Twin Peaks Boar (Area: 0) (possible waypoints or random movement)
(@CGUID+67, 42615, 726, 1, 1, 1742.042, 450.5851, -7.749567, 3.368485, 7200, 0, 0), -- Twin Peaks Boar (Area: 0)
(@CGUID+68, 51130, 726, 1, 1, 1740.724, 453.6866, -7.540817, 6.188134, 7200, 0, 0), -- Dragonmaw Worker (Area: 0) (possible waypoints or random movement)
(@CGUID+69, 51127, 726, 1, 1, 1878.674, -17.76215, 45.33773, 1.204277, 7200, 0, 0), -- Wildhammer Gryphon (Area: Dragonmaw Stronghold) (possible waypoints or random movement)
(@CGUID+70, 51127, 726, 1, 1, 1930.316, 211.658, -16.99481, 1.32645, 7200, 0, 0), -- Wildhammer Gryphon (Area: Dragonmaw Stronghold) (possible waypoints or random movement)
(@CGUID+71, 51127, 726, 1, 1, 2018.228, 140.5488, 26.03765, 4.079322, 7200, 0, 0), -- Wildhammer Gryphon (Area: Dragonmaw Stronghold) (possible waypoints or random movement)
(@CGUID+72, 51127, 726, 1, 1, 1933.433, 42.32083, 14.82479, 1.164314, 7200, 0, 0), -- Wildhammer Gryphon (Area: 0)
(@CGUID+73, 51127, 726, 1, 1, 1892.37, 67.58215, 18.19371, 1.376052, 7200, 0, 0), -- Wildhammer Gryphon (Area: 0)
(@CGUID+74, 51127, 726, 1, 1, 1902.724, 14.45712, 34.94335, 1.408777, 7200, 0, 0), -- Wildhammer Gryphon (Area: 0)
(@CGUID+75, 51127, 726, 1, 1, 1878.674, -17.76215, 45.33773, 1.204277, 7200, 0, 0), -- Wildhammer Gryphon (Area: 0) (possible waypoints or random movement)
(@CGUID+76, 51127, 726, 1, 1, 1878.674, -17.76215, 45.33773, 1.204277, 7200, 0, 0), -- Wildhammer Gryphon (Area: 0) (possible waypoints or random movement)
(@CGUID+77, 51127, 726, 1, 1, 1890.335, -17.76215, 45.33773, 1.117011, 7200, 0, 0), -- Wildhammer Gryphon (Area: 0) (possible waypoints or random movement)
(@CGUID+78, 13116, 726, 1, 1, 1879.16, 441.9132, -3.916838, 4.18879, 7200, 0, 0), -- Alliance Spirit Guide (Area: 0)
(@CGUID+79, 13117, 726, 1, 1, 1550.53, 211.552, 14.17433, 0.05235988, 7200, 0, 0), -- Horde Spirit Guide (Area: Dragonmaw Stronghold)
(@CGUID+80, 13116, 726, 1, 1, 2178.082, 332.7639, 34.06198, 3.263766, 7200, 0, 0), -- Alliance Spirit Guide (Area: Wildhammer Stronghold)
(@CGUID+81, 51127, 726, 1, 1, 1895.859, -5.879869, 41.37141, 1.128741, 7200, 0, 0), -- Wildhammer Gryphon (Area: Wildhammer Stronghold)
(@CGUID+82, 51127, 726, 1, 1, 1881.469, 27.87236, 30.84221, 1.311004, 7200, 0, 0), -- Wildhammer Gryphon (Area: Wildhammer Stronghold)
(@CGUID+83, 51127, 726, 1, 1, 1878.674, -17.76215, 45.33773, 1.204277, 7200, 0, 0), -- Wildhammer Gryphon (Area: Wildhammer Stronghold) (possible waypoints or random movement)
(@CGUID+84, 51127, 726, 1, 1, 1890.335, -17.76215, 45.33773, 1.117011, 7200, 0, 0), -- Wildhammer Gryphon (Area: 0) (possible waypoints or random movement)
(@CGUID+85, 51127, 726, 1, 1, 1878.674, -17.76215, 45.33773, 1.204277, 7200, 0, 0), -- Wildhammer Gryphon (Area: 0) (possible waypoints or random movement)
(@CGUID+86, 51127, 726, 1, 1, 1921.099, 93.61095, 10.87177, 1.836904, 7200, 0, 0), -- Wildhammer Gryphon (Area: 0)
(@CGUID+87, 51127, 726, 1, 1, 1893.343, 73.68, 16.04464, 1.44292, 7200, 0, 0), -- Wildhammer Gryphon (Area: 0)
(@CGUID+88, 51127, 726, 1, 1, 1901.043, 7.26618, 36.89694, 1.280702, 7200, 0, 0), -- Wildhammer Gryphon (Area: 0)
(@CGUID+89, 51127, 726, 1, 1, 1878.674, -17.76215, 45.33773, 1.204277, 7200, 0, 0), -- Wildhammer Gryphon (Area: 0) (possible waypoints or random movement)
(@CGUID+90, 51127, 726, 1, 1, 1878.674, -17.76215, 45.33773, 1.204277, 7200, 0, 0), -- Wildhammer Gryphon (Area: Wildhammer Stronghold) (possible waypoints or random movement)
(@CGUID+91, 51127, 726, 1, 1, 1890.335, -17.76215, 45.33773, 1.117011, 7200, 0, 0), -- Wildhammer Gryphon (Area: Wildhammer Stronghold) (possible waypoints or random movement)
(@CGUID+92, 51127, 726, 1, 1, 1878.674, -17.76215, 45.33773, 1.204277, 7200, 0, 0), -- Wildhammer Gryphon (Area: Wildhammer Flag Room) (possible waypoints or random movement)
(@CGUID+93, 51127, 726, 1, 1, 1890.335, -17.76215, 45.33773, 1.117011, 7200, 0, 0), -- Wildhammer Gryphon (Area: Wildhammer Flag Room) (possible waypoints or random movement)
(@CGUID+94, 51127, 726, 1, 1, 1878.674, -17.76215, 45.33773, 1.204277, 7200, 0, 0), -- Wildhammer Gryphon (Area: Wildhammer Flag Room) (possible waypoints or random movement)
(@CGUID+95, 51127, 726, 1, 1, 1890.335, -17.76215, 45.33773, 1.117011, 7200, 0, 0), -- Wildhammer Gryphon (Area: Wildhammer Flag Room) (possible waypoints or random movement)
(@CGUID+96, 51127, 726, 1, 1, 1878.674, -17.76215, 45.33773, 1.204277, 7200, 0, 0), -- Wildhammer Gryphon (Area: Wildhammer Flag Room) (possible waypoints or random movement)
(@CGUID+97, 51127, 726, 1, 1, 1878.674, -17.76215, 45.33773, 1.204277, 7200, 0, 0); -- Wildhammer Gryphon (Area: Wildhammer Flag Room) (possible waypoints or random movement)
