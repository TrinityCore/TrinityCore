SET @OGUID := 13;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+4;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
-- (@OGUID+0, 190536, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: -Unknown-) - !!! transport !!!
(@OGUID+0, 206110, 0, 1, 1, -8320.21, 289.464, 156.833, 3.804818, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+1, 3800, 0, 1, 1, -8246.914, -229.5731, 268.1983, 1.15676, 0, 0, -0.8325468, 0.5539547, 120, 255, 1), -- Cozy Fire (Area: -Unknown-)
(@OGUID+2, 3799, 0, 1, 1, -8247.325, -230.3678, 268.1983, 6.148404, 0, 0, -0.8325468, 0.5539547, 120, 255, 1), -- Cozy Fire (Area: -Unknown-)
-- (@OGUID+3, 176310, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: -Unknown-) - !!! transport !!!
-- (@OGUID+3, 175080, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: -Unknown-) - !!! transport !!!
-- (@OGUID+3, 181689, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: -Unknown-) - !!! transport !!!
-- (@OGUID+3, 176231, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: -Unknown-) - !!! transport !!!
(@OGUID+3, 206987, 0, 1, 1, -8325.96, -340.503, 145.973, 3.142998, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: -Unknown-)
-- (@OGUID+4, 20808, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: -Unknown-) - !!! transport !!!
-- (@OGUID+4, 164871, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: -Unknown-) - !!! transport !!!
(@OGUID+4, 1940, 0, 1, 1, -8637.573, -547.3613, 145.0414, 1.570794, 0, 0, 0, 1, 120, 255, 1); -- Campfire (Area: -Unknown-)

UPDATE `creature_template` SET `minlevel`=3, `maxlevel`=3, `faction_A`=188, `faction_H`=188, `speed_walk`=0.8571429, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000 WHERE `entry`=48873; -- Tekton
UPDATE `creature_template` SET `minlevel`=80, `maxlevel`=80, `faction_A`=875, `faction_H`=875, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33536 WHERE `entry`=48875; -- Agee Tyler


DELETE FROM `creature_template_addon` WHERE `entry` IN (47194, 38821, 38821, 38821, 47194, 47194, 47194, 47194, 47194, 47194, 47194, 47194, 47194, 47194, 47194, 47194, 47194, 48873, 47194, 47194, 47194, 47194, 47194, 47194, 47194, 47194, 47194, 48875, 38821, 38821, 38821, 38821, 37543, 37543, 37574, 40987, 32520, 32520, 32520, 32520);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(47194, 0, 0x0, 0x1, ''), -- Sheep
(38821, 0, 0x0, 0x1, ''), -- Dave's Industrial Light and Magic Bunny (Medium)(Sessile)
(48873, 0, 0x0, 0x1, ''), -- Tekton
(48875, 0, 0x1, 0x1, ''), -- Agee Tyler
(37543, 0, 0x0, 0x1, ''), -- [DND] Shaker
(37574, 0, 0x0, 0x1, ''), -- [DND] Shaker - Small
(40987, 0, 0x0, 0x1, ''), -- Gnash
(32520, 0, 0x0, 0x1, ''); -- Totally Generic Bunny (All Phase)

SET @CGUID := 229;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+39;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 47194, 0, 1, 1, -8272.852, -193.5677, 269.0773, 2.393159, 120, 0, 0), -- Sheep (Area: -Unknown-)
(@CGUID+1, 38821, 0, 1, 1, -8367.76, 267.592, 176.3863, 4.555309, 120, 0, 0), -- Dave's Industrial Light and Magic Bunny (Medium)(Sessile) (Area: -Unknown-)
(@CGUID+2, 38821, 0, 1, 1, -8388.66, 265.104, 189.8273, 5.218534, 120, 0, 0), -- Dave's Industrial Light and Magic Bunny (Medium)(Sessile) (Area: -Unknown-)
(@CGUID+3, 38821, 0, 1, 1, -8396.49, 249.094, 170.0343, 6.265732, 120, 0, 0), -- Dave's Industrial Light and Magic Bunny (Medium)(Sessile) (Area: -Unknown-)
(@CGUID+4, 47194, 0, 1, 1, -8260.433, -180.521, 268.8595, 3.008616, 120, 0, 0), -- Sheep (Area: -Unknown-)
(@CGUID+5, 47194, 0, 1, 1, -8263.054, -186.7788, 269.3605, 2.291438, 120, 0, 0), -- Sheep (Area: -Unknown-)
(@CGUID+6, 47194, 0, 1, 1, -8263.351, -186.9865, 269.2594, 5.140308, 120, 0, 0), -- Sheep (Area: -Unknown-)
(@CGUID+7, 47194, 0, 1, 1, -8265.515, -188.2371, 269.4335, 4.38839, 120, 0, 0), -- Sheep (Area: -Unknown-)
(@CGUID+8, 47194, 0, 1, 1, -8263.111, -195.1104, 269.2594, 0.5087751, 120, 0, 0), -- Sheep (Area: -Unknown-)
(@CGUID+9, 47194, 0, 1, 1, -8268.96, -196.1101, 269.382, 4.190923, 120, 0, 0), -- Sheep (Area: -Unknown-)
(@CGUID+10, 47194, 0, 1, 1, -8247.235, -193.7972, 267.5094, 4.701077, 120, 0, 0), -- Sheep (Area: -Unknown-)
(@CGUID+11, 47194, 0, 1, 1, -8225.768, -180.0258, 267.813, 6.182284, 120, 0, 0), -- Sheep (Area: -Unknown-)
(@CGUID+12, 47194, 0, 1, 1, -8246.726, -195.336, 267.5094, 1.839653, 120, 0, 0), -- Sheep (Area: -Unknown-)
(@CGUID+13, 47194, 0, 1, 1, -8253.43, -198.9133, 268.1086, 3.156981, 120, 0, 0), -- Sheep (Area: -Unknown-)
(@CGUID+14, 47194, 0, 1, 1, -8236.627, -193.8874, 267.6767, 5.249255, 120, 0, 0), -- Sheep (Area: -Unknown-)
(@CGUID+15, 47194, 0, 1, 1, -8246.334, -199.7149, 267.5094, 4.548618, 120, 0, 0), -- Sheep (Area: -Unknown-)
(@CGUID+16, 47194, 0, 1, 1, -8237.378, -195.561, 267.5866, 0.1502857, 120, 0, 0), -- Sheep (Area: -Unknown-)
(@CGUID+17, 48873, 0, 1, 1, -8260.345, -203.4432, 268.7211, 4.970769, 120, 0, 0), -- Tekton (Area: -Unknown-)
(@CGUID+18, 47194, 0, 1, 1, -8248.339, -203.0113, 267.5177, 2.44207, 120, 0, 0), -- Sheep (Area: -Unknown-)
(@CGUID+19, 47194, 0, 1, 1, -8243.146, -201.8193, 267.5177, 2.138198, 120, 0, 0), -- Sheep (Area: -Unknown-)
(@CGUID+20, 47194, 0, 1, 1, -8252.474, -207.4178, 267.6745, 0.1134855, 120, 0, 0), -- Sheep (Area: -Unknown-)
(@CGUID+21, 47194, 0, 1, 1, -8242.899, -205.5314, 267.5177, 2.513997, 120, 0, 0), -- Sheep (Area: -Unknown-)
(@CGUID+22, 47194, 0, 1, 1, -8262.761, -210.6055, 268.1513, 4.575406, 120, 0, 0), -- Sheep (Area: -Unknown-)
(@CGUID+23, 47194, 0, 1, 1, -8244.922, -207.3637, 267.5177, 3.035794, 120, 0, 0), -- Sheep (Area: -Unknown-)
(@CGUID+24, 47194, 0, 1, 1, -8269.146, -214.6483, 268.1782, 2.282488, 120, 0, 0), -- Sheep (Area: -Unknown-)
(@CGUID+25, 47194, 0, 1, 1, -8241.86, -209.2625, 267.5177, 4.530401, 120, 0, 0), -- Sheep (Area: -Unknown-)
(@CGUID+26, 47194, 0, 1, 1, -8237.065, -206.7825, 268.237, 5.437333, 120, 0, 0), -- Sheep (Area: -Unknown-)
(@CGUID+27, 48875, 0, 1, 1, -8249.989, -228.5938, 268.2653, 5.828786, 120, 0, 0), -- Agee Tyler (Area: -Unknown-) (possible waypoints or random movement)
(@CGUID+28, 38821, 0, 1, 1, -8377.04, 225.998, 166.8893, 1.48353, 120, 0, 0), -- Dave's Industrial Light and Magic Bunny (Medium)(Sessile) (Area: -Unknown-)
(@CGUID+29, 38821, 0, 1, 1, -8390.28, 228.731, 176.4893, 0.8726646, 120, 0, 0), -- Dave's Industrial Light and Magic Bunny (Medium)(Sessile) (Area: -Unknown-)
(@CGUID+30, 38821, 0, 1, 1, -8352.49, 240.137, 176.2833, 3.001966, 120, 0, 0), -- Dave's Industrial Light and Magic Bunny (Medium)(Sessile) (Area: -Unknown-)
(@CGUID+31, 38821, 0, 1, 1, -8355.72, 251.807, 159.7383, 3.054326, 120, 0, 0), -- Dave's Industrial Light and Magic Bunny (Medium)(Sessile) (Area: -Unknown-)
(@CGUID+32, 37543, 0, 1, 1, -8450.22, 313.568, 141.3683, 1.291544, 120, 0, 0), -- [DND] Shaker (Area: -Unknown-)
(@CGUID+33, 37543, 0, 1, 1, -8457.44, 341.106, 141.3683, 5.654867, 120, 0, 0), -- [DND] Shaker (Area: -Unknown-)
(@CGUID+34, 37574, 0, 1, 1, -8416.44, 327.04, 134.8203, 2.6529, 120, 0, 0), -- [DND] Shaker - Small (Area: -Unknown-)
(@CGUID+35, 40987, 0, 1, 1, -4817.827, 3627.653, -120.6529, 3.774536, 120, 0, 0), -- Gnash (Area: -Unknown-) (possible waypoints or random movement)
(@CGUID+36, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: 0)
(@CGUID+37, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: 0)
(@CGUID+38, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: 0)
(@CGUID+39, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0); -- Totally Generic Bunny (All Phase) (Area: 0)
