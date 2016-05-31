SET @CGUID := 81;
SET @OGUID := 7;

UPDATE `creature_template` SET `minlevel`=80, `maxlevel`=80, `faction_A`=14, `faction_H`=14, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33554432 WHERE `entry`=53488; -- Summon Enabler Stalker
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87, `faction_A`=14, `faction_H`=14, `speed_walk`=1.428571, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=537133312, `dynamicflags`=32 WHERE `entry`=52427; -- Destroyed Containment Unit
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=32780; -- Invisible Stalker (All Phases)
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87, `faction_A`=14, `faction_H`=14, `speed_walk`=1.428571, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=537133312, `dynamicflags`=32 WHERE `entry`=56369; -- Eye of Occu'thar
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=90, `faction_H`=90, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=56350; -- Disciple of Hate
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87, `faction_A`=14, `faction_H`=14, `speed_walk`=1.428571, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000 WHERE `entry`=56372; -- Eye of Occu'thar
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87, `faction_A`=14, `faction_H`=14, `speed_walk`=0.7142857, `speed_run`=2, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33554432 WHERE `entry`=52368; -- Eyestalk
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87, `faction_A`=14, `faction_H`=14, `speed_walk`=1.428571, `speed_run`=1, `baseattacktime`=1500, `rangeattacktime`=2000, `unit_flags`=64, `VehicleId`=1598 WHERE `entry`=52363; -- Occu'thar
UPDATE `creature_template` SET `minlevel`=88, `maxlevel`=88, `faction_A`=16, `faction_H`=16, `speed_walk`=1.714286, `speed_run`=1.2, `baseattacktime`=1500, `rangeattacktime`=2000 WHERE `entry`=47120; -- Argaloth
UPDATE `creature_template` SET `minlevel`=88, `maxlevel`=88, `faction_A`=16, `faction_H`=16, `speed_walk`=1.714286, `speed_run`=1.6, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32832 WHERE `entry`=55869; -- Alizabal

REPLACE INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(53488, 0, 0x0, 0x1, '99201'), -- Summon Enabler Stalker - Summon Enabler
(52427, 0, 0x0, 0x1, '96733'), -- Destroyed Containment Unit - Permanent Feign Death (Stun)
(32780, 0, 0x0, 0x1, ''), -- Invisible Stalker (All Phases)
(56369, 0, 0x3000000, 0x1, '96733'), -- Eye of Occu'thar - Permanent Feign Death (Stun)
(56350, 0, 0x0, 0x1, ''), -- Disciple of Hate
(56372, 0, 0x3000000, 0x1, '96995 97004'), -- Eye of Occu'thar - Eye of Occu'thar Visual, Eyes of Occu'thar
(52368, 0, 0x0, 0x1, '46598'), -- Eyestalk - Ride Vehicle Hardcoded
(52363, 0, 0x0, 0x1, ''), -- Occu'thar
(47120, 0, 0x0, 0x1, ''), -- Argaloth
(55869, 0, 0x0, 0x1, ''); -- Alizabal

UPDATE `creature_model_info` SET `gender`=1 WHERE `modelid`=21252;
UPDATE `creature_model_info` SET `bounding_radius`=5, `combat_reach`=15, `gender`=0 WHERE `modelid`=35426;
UPDATE `creature_model_info` SET `bounding_radius`=1.5, `combat_reach`=3 WHERE `modelid`=35906;
UPDATE `creature_model_info` SET `bounding_radius`=1.4, `combat_reach`=16 WHERE `modelid`=37876;
UPDATE `creature_model_info` SET `bounding_radius`=0.04, `combat_reach`=0.6 WHERE `modelid`=37887;
UPDATE `creature_model_info` SET `bounding_radius`=0.6, `combat_reach`=2, `gender`=1 WHERE `modelid`=39390;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+31;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 53488, 757, 1, 1, 171.8507, 1337.113, 170.275, 0, 7200, 0, 0), -- Summon Enabler Stalker (Area: 0)
(@CGUID+1, 52427, 757, 1, 1, 219.4167, 1345.793, 170.275, 4.834562, 7200, 0, 0), -- Destroyed Containment Unit (Area: 0)
(@CGUID+2, 32780, 757, 1, 1, 197.6354, 1327.774, 175.5703, 0, 7200, 0, 0), -- Invisible Stalker (All Phases) (Area: 0)
(@CGUID+3, 56369, 757, 1, 1, 234.5365, 1315.615, 170.2803, 0.8028514, 7200, 0, 0), -- Eye of Occu'thar (Area: 0)
(@CGUID+4, 56350, 757, 1, 1, 238.1235, 1329.074, 170.1917, 5.09062, 7200, 0, 0), -- Disciple of Hate (Area: 0) (possible waypoints or random movement)
(@CGUID+5, 56369, 757, 1, 1, 235.0087, 1310.951, 170.2829, 0.8028514, 7200, 0, 0), -- Eye of Occu'thar (Area: 0)
(@CGUID+6, 56369, 757, 1, 1, 237.0469, 1317.146, 170.2807, 0.8028514, 7200, 0, 0), -- Eye of Occu'thar (Area: 0)
(@CGUID+7, 56369, 757, 1, 1, 236.8767, 1313.392, 170.2838, 0.8028514, 7200, 0, 0), -- Eye of Occu'thar (Area: 0)
(@CGUID+8, 56369, 757, 1, 1, 236.533, 1310.998, 170.2854, 0.8028514, 7200, 0, 0), -- Eye of Occu'thar (Area: 0)
(@CGUID+9, 56369, 757, 1, 1, 239.1163, 1315.115, 170.2798, 0.8028514, 7200, 0, 0), -- Eye of Occu'thar (Area: 0)
(@CGUID+10, 56369, 757, 1, 1, 239.2552, 1308.377, 170.2822, 3.822271, 7200, 0, 0), -- Eye of Occu'thar (Area: 0)
(@CGUID+11, 56369, 757, 1, 1, 241.3455, 1311.146, 170.279, 0.8028514, 7200, 0, 0), -- Eye of Occu'thar (Area: 0)
(@CGUID+12, 56372, 757, 1, 1, 280.559, 1352.292, 173.2115, 0.2792527, 7200, 0, 0), -- Eye of Occu'thar (Area: 0)
(@CGUID+13, 52427, 757, 1, 1, 276.7882, 1387.814, 170.275, 3.124139, 7200, 0, 0), -- Destroyed Containment Unit (Area: 0)
(@CGUID+14, 56369, 757, 1, 1, 298.5295, 1363.326, 170.275, 0.8028514, 7200, 0, 0), -- Eye of Occu'thar (Area: 0)
(@CGUID+15, 56369, 757, 1, 1, 300.526, 1358.71, 170.2763, 0.8028514, 7200, 0, 0), -- Eye of Occu'thar (Area: 0)
(@CGUID+16, 56369, 757, 1, 1, 300.8698, 1361.104, 170.275, 0.8028514, 7200, 0, 0), -- Eye of Occu'thar (Area: 0)
(@CGUID+17, 56369, 757, 1, 1, 301.0399, 1364.858, 170.275, 0.8028514, 7200, 0, 0), -- Eye of Occu'thar (Area: 0)
(@CGUID+18, 56369, 757, 1, 1, 302.4115, 1360.665, 170.286, 0.8028514, 7200, 0, 0), -- Eye of Occu'thar (Area: 0)
(@CGUID+19, 56369, 757, 1, 1, 303.1094, 1362.826, 170.275, 0.8028514, 7200, 0, 0), -- Eye of Occu'thar (Area: 0)
(@CGUID+20, 56369, 757, 1, 1, 305.3385, 1358.858, 170.2768, 0.8028514, 7200, 0, 0), -- Eye of Occu'thar (Area: 0)
(@CGUID+21, 52368, 757, 1, 1, 265.6478, 1549.184, 194.0467, 4.694936, 7200, 0, 0), -- Eyestalk (Area: 0)
(@CGUID+22, 52363, 757, 1, 1, 268.4774, 1553.747, 179.9695, 4.694936, 7200, 0, 0), -- Occu'thar (Area: 0)
(@CGUID+23, 52368, 757, 1, 1, 268.0396, 1551.58, 197.6283, 4.694936, 7200, 0, 0), -- Eyestalk (Area: 0)
(@CGUID+24, 52368, 757, 1, 1, 270.902, 1555.131, 198.4283, 4.694936, 7200, 0, 0), -- Eyestalk (Area: 0)
(@CGUID+25, 52368, 757, 1, 1, 272.8563, 1552.496, 197.6283, 4.694936, 7200, 0, 0), -- Eyestalk (Area: 0)
(@CGUID+26, 52368, 757, 1, 1, 266.5027, 1555.208, 198.4283, 4.694936, 7200, 0, 0), -- Eyestalk (Area: 0)
(@CGUID+27, 52368, 757, 1, 1, 265.24, 1551.629, 197.6283, 4.694936, 7200, 0, 0), -- Eyestalk (Area: 0)
(@CGUID+28, 52368, 757, 1, 1, 271.0772, 1548.808, 193.8827, 4.694936, 7200, 0, 0), -- Eyestalk (Area: 0)
(@CGUID+29, 56350, 757, 1, 1, 327.2205, 1337.582, 170.2749, 3.106686, 7200, 0, 0), -- Disciple of Hate (Area: 0) (possible waypoints or random movement)
(@CGUID+30, 47120, 757, 1, 1, 269.707, 1135.49, 160.9933, 1.570796, 7200, 0, 0), -- Argaloth (Area: 0)
(@CGUID+31, 55869, 757, 1, 1, 441.2865, 1336.898, 170.2749, 3.089233, 7200, 0, 0); -- Alizabal (Area: 0) (possible waypoints or random movement)

-- DELETE FROM `creature_equip_template` WHERE `entry` IN (56350, 55869);
-- INSERT INTO `creature_equip_template` (`entry`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES
-- (56350, 76175, 76175, 0), -- Disciple of Hate
-- (55869, 76176, 76176, 0); -- Alizabal

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+5;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 206968, 757, 1, 1, 151.8988, 1337.152, 172.0938, 3.141593, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+1, 207981, 757, 1, 1, 151.8988, 1337.152, 172.0938, 3.141593, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+2, 207980, 757, 1, 1, 151.8988, 1337.152, 172.0938, 3.141593, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+3, 206969, 757, 1, 1, 151.8988, 1337.152, 172.0938, 3.141593, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+4, 207619, 757, 1, 1, 269.7156, 1204.399, 160.7703, 3.141593, 0, 0, 1, -4.371139E-08, 7200, 255, 0), -- -Unknown- (Area: 0)
(@OGUID+5, 208953, 757, 1, 1, 269.7156, 1471.048, 179.9434, 3.141593, 0, 0, 1, -4.371139E-08, 7200, 255, 0); -- -Unknown- (Area: 0)
