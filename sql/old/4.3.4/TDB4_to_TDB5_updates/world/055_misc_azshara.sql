SET @OGUID := 164822;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+30;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 148675, 1, 1, 1, 3962.221, -4779.728, 304.9186, 6.239553, 0, 0, 0.91706, 0.3987491, 120, 255, 1), -- Chair (Area: -Unknown-)
(@OGUID+1, 148669, 1, 1, 1, 3962.357, -4777.882, 304.9186, 6.239553, 0, 0, 0.91706, 0.3987491, 120, 255, 1), -- Chair (Area: -Unknown-)
(@OGUID+2, 148686, 1, 1, 1, 3969.099, -4786.542, 296.0426, 0.383971, 0, 0, 0.91706, 0.3987491, 120, 255, 1), -- Chair (Area: -Unknown-)
(@OGUID+3, 148697, 1, 1, 1, 3972.341, -4793.325, 304.8643, 1.52716, 0, 0, 0.91706, 0.3987491, 120, 255, 1), -- Chair (Area: -Unknown-)
(@OGUID+4, 148668, 1, 1, 1, 3978.572, -4795.192, 296.0426, 1.169371, 0, 0, 0.91706, 0.3987491, 120, 255, 1), -- Chair (Area: -Unknown-)
(@OGUID+5, 148680, 1, 1, 1, 3971.073, -4769.237, 296.0426, 5.698502, 0, 0, 0.91706, 0.3987491, 120, 255, 1), -- Chair (Area: -Unknown-)
(@OGUID+6, 148661, 1, 1, 1, 3982.726, -4801.353, 304.9186, 1.52716, 0, 0, 0.91706, 0.3987491, 120, 255, 1), -- Chair (Area: -Unknown-)
(@OGUID+7, 148660, 1, 1, 1, 3984.573, -4801.489, 304.9186, 1.52716, 0, 0, 0.91706, 0.3987491, 120, 255, 1), -- Chair (Area: -Unknown-)
(@OGUID+8, 148696, 1, 1, 1, 3972.867, -4772.461, 270.3713, 5.672322, 0, 0, 0.91706, 0.3987491, 120, 255, 1), -- Chair (Area: -Unknown-)
(@OGUID+9, 148659, 1, 1, 1, 3975.057, -4769.867, 280.7443, 5.558874, 0, 0, 0.91706, 0.3987491, 120, 255, 1), -- Chair (Area: -Unknown-)
(@OGUID+10, 148670, 1, 1, 1, 3986.404, -4795.979, 296.0426, 1.771508, 0, 0, 0.91706, 0.3987491, 120, 255, 1), -- Chair (Area: -Unknown-)
(@OGUID+11, 148693, 1, 1, 1, 3982.214, -4782.915, 270.3713, 1.151916, 0, 0, 0.91706, 0.3987491, 120, 255, 1), -- Chair (Area: -Unknown-)
(@OGUID+12, 196474, 1, 1, 1, 3985.06, -4791.476, 270.3309, 1.553341, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+13, 148683, 1, 1, 1, 3982.079, -4771.274, 304.7975, 0.2705252, 0, 0, 0.91706, 0.3987491, 120, 255, 1), -- Chair (Area: -Unknown-)
(@OGUID+14, 148671, 1, 1, 1, 3991.387, -4794.61, 296.0426, 1.954769, 0, 0, 0.91706, 0.3987491, 120, 255, 1), -- Chair (Area: -Unknown-)
(@OGUID+15, 148695, 1, 1, 1, 3978.354, -4767.4, 270.3713, 5.070184, 0, 0, 0.91706, 0.3987491, 120, 255, 1), -- Chair (Area: -Unknown-)
(@OGUID+16, 148694, 1, 1, 1, 3988.374, -4792.122, 270.3713, 1.893679, 0, 0, 0.91706, 0.3987491, 120, 255, 1), -- Chair (Area: -Unknown-)
(@OGUID+17, 148684, 1, 1, 1, 3987.076, -4772.785, 304.7653, 1.108283, 0, 0, 0.91706, 0.3987491, 120, 255, 1), -- Chair (Area: -Unknown-)
(@OGUID+18, 148665, 1, 1, 1, 3989.485, -4777.605, 304.7522, 0.4799641, 0, 0, 0.91706, 0.3987491, 120, 255, 1), -- Chair (Area: -Unknown-)
(@OGUID+19, 148664, 1, 1, 1, 3992.43, -4783.59, 304.7975, 1.108283, 0, 0, 0.91706, 0.3987491, 120, 255, 1), -- Chair (Area: -Unknown-)
(@OGUID+20, 148663, 1, 1, 1, 3995.687, -4794.115, 304.899, 2.155482, 0, 0, 0.91706, 0.3987491, 120, 255, 1), -- Chair (Area: -Unknown-)
(@OGUID+21, 148692, 1, 1, 1, 3987.099, -4772.271, 270.3713, 4.363324, 0, 0, 0.91706, 0.3987491, 120, 255, 1), -- Chair (Area: -Unknown-)
(@OGUID+22, 148725, 1, 1, 1, 3998.346, -4791.525, 304.899, 2.408549, 0, 0, 0.91706, 0.3987491, 120, 255, 1), -- Chair (Area: -Unknown-)
(@OGUID+23, 148677, 1, 1, 1, 3982.15, -4762.887, 296.0426, 4.913104, 0, 0, 0.91706, 0.3987491, 120, 255, 1), -- Chair (Area: -Unknown-)
(@OGUID+24, 148707, 1, 1, 1, 3998.42, -4767.591, 304.8701, 3.865906, 0, 0, 0.91706, 0.3987491, 120, 255, 1), -- Chair (Area: -Unknown-)
(@OGUID+25, 148714, 1, 1, 1, 3997.235, -4766.168, 304.8701, 3.865906, 0, 0, 0.91706, 0.3987491, 120, 255, 1), -- Chair (Area: -Unknown-)
(@OGUID+26, 148674, 1, 1, 1, 3994.473, -4766.229, 296.0426, 4.127707, 0, 0, 0.91706, 0.3987491, 120, 255, 1), -- Chair (Area: -Unknown-)
(@OGUID+27, 148658, 1, 1, 1, 3983.982, -4757.376, 304.9186, 4.668757, 0, 0, 0.91706, 0.3987491, 120, 255, 1), -- Chair (Area: -Unknown-)
(@OGUID+28, 148662, 1, 1, 1, 3985.828, -4757.513, 304.9186, 4.668757, 0, 0, 0.91706, 0.3987491, 120, 255, 1), -- Chair (Area: -Unknown-)
(@OGUID+29, 148691, 1, 1, 1, 4006.333, -4779.137, 304.9186, 3.097919, 0, 0, 0.91706, 0.3987491, 120, 255, 1), -- Chair (Area: -Unknown-)
(@OGUID+30, 148682, 1, 1, 1, 4006.197, -4780.984, 304.9186, 3.097919, 0, 0, 0.91706, 0.3987491, 120, 255, 1); -- Chair (Area: -Unknown-)


UPDATE `creature_template` SET `unit_flags2`=4196352 WHERE `entry`=43217; -- Bilgewater Rocket-jockey
UPDATE `creature_template` SET `minlevel`=16, `maxlevel`=16, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=8, `unit_flags`=33536 WHERE `entry`=36370; -- Lux
UPDATE `creature_template` SET `minlevel`=16, `maxlevel`=16, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=8, `unit_flags`=33536 WHERE `entry`=36371; -- Morta the Wretch
UPDATE `creature_template` SET `minlevel`=21, `maxlevel`=21, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=8, `unit_flags`=33536 WHERE `entry`=36376; -- Fib Gyrojolt
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=62, `npcflag`=2, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=768 WHERE `entry`=36373; -- Coral Moongale
UPDATE `creature_template` SET `npcflag`=1 WHERE `entry`=50299; -- Sanath Lim-yo
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=36372; -- Joanna
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=36374; -- Nyrill
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=36375; -- Tex Vortacoil
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=37152; -- Image of Archmage Xylem


DELETE FROM `creature_template_addon` WHERE `entry` IN (36373, 50299, 36377, 37152, 36375, 36372, 36376, 36371, 36370, 43217);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(36370, 0, 0x0, 0x1, ''), -- Lux
(36371, 0, 0x0, 0x1, ''), -- Morta the Wretch
(36372, 0, 0x0, 0x1, ''), -- Joanna
(36373, 0, 0x1, 0x1, ''), -- Coral Moongale
(36375, 0, 0x0, 0x1, ''), -- Tex Vortacoil
(36376, 0, 0x0, 0x1, ''), -- Fib Gyrojolt
(36377, 0, 0x0, 0x1, ''), -- Animated Sweeper
(37152, 0, 0x0, 0x1, ''), -- Image of Archmage Xylem
(43217, 0, 0x0, 0x101, ''), -- Bilgewater Rocket-jockey
(50299, 0, 0x1, 0x1, ''); -- Sanath Lim-yo


UPDATE `creature_model_info` SET `bounding_radius`=0.3519, `combat_reach`=1.725, `gender`=0 WHERE `modelid`=30095; -- 30095
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=30094; -- 30094
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=30093; -- 30093


SET @CGUID := 223804;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+24;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 721, 1, 1, 1, 3836.386, -4662.884, 248.6003, 1.754892, 120, 0, 0), -- Rabbit (Area: -Unknown-)
(@CGUID+1, 721, 1, 1, 1, 3914.46, -4649.12, 266.6716, 1.234677, 120, 0, 0), -- Rabbit (Area: -Unknown-)
(@CGUID+2, 36373, 1, 1, 1, 3931.042, -4732.128, 266.6544, 0.5585054, 120, 0, 0), -- Coral Moongale (Area: -Unknown-)
(@CGUID+3, 721, 1, 1, 1, 3919.846, -4735.811, 266.6124, 2.363418, 120, 0, 0), -- Rabbit (Area: -Unknown-)
(@CGUID+4, 721, 1, 1, 1, 3817.163, -4797.229, 168.019, 2.193996, 120, 0, 0), -- Rabbit (Area: -Unknown-)
(@CGUID+5, 61081, 1, 1, 1, 3938.749, -4776.361, 275.409, 5.045737, 120, 0, 0), -- -Unknown- (Area: -Unknown-) (possible waypoints or random movement)
(@CGUID+6, 50299, 1, 1, 1, 3875.382, -4869.753, 150.6926, 4.694936, 120, 0, 0), -- Sanath Lim-yo (Area: -Unknown-)
(@CGUID+7, 721, 1, 1, 1, 3852.709, -4914.217, 147.6372, 4.151686, 120, 0, 0), -- Rabbit (Area: -Unknown-)
(@CGUID+8, 721, 1, 1, 1, 3906.261, -4902.598, 149.3195, 1.526793, 120, 0, 0), -- Rabbit (Area: -Unknown-)
(@CGUID+9, 36377, 1, 1, 1, 3973.862, -4786.825, 304.7328, 2.359688, 120, 0, 0), -- Animated Sweeper (Area: -Unknown-) (possible waypoints or random movement)
(@CGUID+10, 37152, 1, 1, 1, 3964.137, -4777.662, 304.8054, 1.493246, 120, 0, 0), -- Image of Archmage Xylem (Area: -Unknown-) (possible waypoints or random movement)
(@CGUID+11, 37152, 1, 1, 1, 3975.159, -4793.59, 304.806, 2.583061, 120, 0, 0), -- Image of Archmage Xylem (Area: -Unknown-) (possible waypoints or random movement)
(@CGUID+12, 36377, 1, 1, 1, 3971.796, -4780.512, 289.9996, 4.84789, 120, 0, 0), -- Animated Sweeper (Area: -Unknown-) (possible waypoints or random movement)
(@CGUID+13, 37152, 1, 1, 1, 3972.099, -4771.882, 304.7103, 3.9492, 120, 0, 0), -- Image of Archmage Xylem (Area: -Unknown-) (possible waypoints or random movement)
(@CGUID+14, 36377, 1, 1, 1, 3974.479, -4769.88, 296.0075, 1.519067, 120, 0, 0), -- Animated Sweeper (Area: -Unknown-) (possible waypoints or random movement)
(@CGUID+15, 36375, 1, 1, 1, 3982.222, -4782.795, 270.4143, 1.256637, 120, 0, 0), -- Tex Vortacoil (Area: -Unknown-)
(@CGUID+16, 36372, 1, 1, 1, 3985.341, -4784.139, 270.4143, 1.902409, 120, 0, 0), -- Joanna (Area: -Unknown-)
(@CGUID+17, 36376, 1, 1, 1, 3987.026, -4772.874, 304.5494, 1.134464, 120, 0, 0), -- Fib Gyrojolt (Area: -Unknown-)
(@CGUID+18, 36377, 1, 1, 1, 3993.919, -4771.076, 273.8042, 5.177472, 120, 0, 0), -- Animated Sweeper (Area: -Unknown-) (possible waypoints or random movement)
(@CGUID+19, 37152, 1, 1, 1, 3982.589, -4762.01, 304.8876, 0.9250245, 120, 0, 0), -- Image of Archmage Xylem (Area: -Unknown-)
(@CGUID+20, 36371, 1, 1, 1, 3991.356, -4766.285, 296.1026, 1.151917, 120, 0, 0), -- Morta the Wretch (Area: -Unknown-)
(@CGUID+21, 37152, 1, 1, 1, 3984.787, -4758.238, 304.8876, 4.660029, 120, 0, 0), -- Image of Archmage Xylem (Area: -Unknown-)
(@CGUID+22, 36370, 1, 1, 1, 3994.535, -4766.088, 296.1026, 4.08407, 120, 0, 0), -- Lux (Area: -Unknown-)
(@CGUID+23, 37152, 1, 1, 1, 4006.938, -4775.554, 304.8876, 0.7679449, 120, 0, 0), -- Image of Archmage Xylem (Area: -Unknown-)
(@CGUID+24, 43217, 1, 1, 1, 3556, -4802.84, 160.7873, 4.694936, 120, 0, 0); -- Bilgewater Rocket-jockey (Area: -Unknown-)
