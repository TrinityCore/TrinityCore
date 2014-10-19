SET @OGUID := 306;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+7;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 194497, 530, 1, 1, -3864.427, -11652.23, -137.6314, 2.268925, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Ammen Vale)
(@OGUID+1, 194497, 530, 1, 1, -3855.075, -11644.35, -137.5878, 2.286379, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Ammen Vale)
(@OGUID+2, 202585, 530, 1, 1, -4048.451, -13777.89, 74.94419, 4.34587, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: Ammen Vale)
(@OGUID+3, 207322, 530, 1, 1, -3942.478, -11651.42, -138.8192, 2.478367, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+4, 204879, 530, 1, 1, -3860.474, -11642.74, -137.6218, 2.565632, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+5, 204879, 530, 1, 1, -3865.031, -11646.55, -137.6409, 2.059488, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+6, 209124, 530, 1, 1, -3902.32, -11608.98, -135.3673, 3.455756, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+7, 209114, 530, 1, 1, -3905.078, -11606.61, -135.3963, 4.485497, 0, 0, 0, 1, 120, 255, 1); -- -Unknown- (Area: 0)


SET @CGUID := 519;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+16;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 37543, 530, 1, 1, -3920.7, -11597.19, -121.3342, 4.13643, 120, 0, 0), -- [DND] Shaker (Area: 0)
(@CGUID+1, 37543, 530, 1, 1, -3979.332, -11710.33, -121.2485, 4.13643, 120, 0, 0), -- [DND] Shaker (Area: Ammen Vale)
(@CGUID+2, 37543, 530, 1, 1, -3990.776, -11852.97, 20.50383, 4.13643, 120, 0, 0), -- [DND] Shaker (Area: Ammen Vale)
(@CGUID+3, 37574, 530, 1, 1, -3784.118, -11696.58, -93.25943, 0, 120, 0, 0), -- [DND] Shaker - Small (Area: Ammen Vale)
(@CGUID+4, 37574, 530, 1, 1, -3919.821, -11548.49, -137.8076, 4.764749, 120, 0, 0), -- [DND] Shaker - Small (Area: 0)
(@CGUID+5, 37574, 530, 1, 1, -4019.266, -11729.28, -143.7658, 4.764749, 120, 0, 0), -- [DND] Shaker - Small (Area: Ammen Vale)
(@CGUID+6, 37574, 530, 1, 1, -4023.071, -11734.74, -141.3466, 0.7679449, 120, 0, 0), -- [DND] Shaker - Small (Area: Ammen Vale)
(@CGUID+7, 43991, 530, 1, 1, -4126.64, -12523.8, 44.22773, 2.268928, 120, 0, 0), -- Zaldaan (Area: Ammen Vale)
(@CGUID+8, 44703, 530, 1, 1, -4038.92, -13762.1, 75.98483, 0.7853982, 120, 0, 0), -- Training Dummy (Area: Ammen Vale)
(@CGUID+9, 44703, 530, 1, 1, -4044.67, -13756.8, 76.21204, 0.8901179, 120, 0, 0), -- Training Dummy (Area: Ammen Vale)
(@CGUID+10, 44703, 530, 1, 1, -4051.55, -13755.2, 76.09234, 0.7504916, 120, 0, 0), -- Training Dummy (Area: Ammen Vale)
(@CGUID+11, 44703, 530, 1, 1, -4054.03, -13742.9, 77.65353, 6.091199, 120, 0, 0), -- Training Dummy (Area: Ammen Vale)
(@CGUID+12, 44703, 530, 1, 1, -4054.62, -13749.8, 76.99693, 0.3490658, 120, 0, 0), -- Training Dummy (Area: Ammen Vale)
(@CGUID+13, 47431, 530, 1, 1, -4216.73, -12481.6, 45.32543, 6.056293, 120, 0, 0), -- Valn (Area: Ammen Vale)
(@CGUID+14, 49748, 530, 1, 1, -3942.293, -11648.16, -138.4517, 2.513274, 120, 0, 0), -- Hero's Herald (Area: 0)
(@CGUID+15, 50306, 530, 1, 1, -3869.003, -11645.96, -137.5808, 1.762783, 120, 0, 0), -- Kadu (Area: 0)
(@CGUID+16, 54334, 530, 1, 1, -3905.795, -11608.79, -137.9796, 4.328416, 120, 0, 0); -- Darkmoon Faire Mystic Mage (Area: 0)

UPDATE `creature_template` SET `minlevel`=3, `maxlevel`=3, `faction_A`=7, `faction_H`=7, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=131072, `unit_flags2`=32 WHERE `entry`=44703; -- Training Dummy
