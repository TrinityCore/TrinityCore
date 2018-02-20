-- Mists of Pandaria spawns
SET @CGUID:=452711;				-- Set by TC
SET @OGUID:=301158;				-- Set by TC

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+34;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0,  65061, 0, 0, 0, 1, 0, 0, 0, 0, -8230.699, 492.3081, 114.4241, 5.05368,  120,10, 0, 0, 0, 1, 0, 0, 0, 23420), -- Brown Dragon Turtle (Area: Stormwind City) (possible waypoints or random movement)
(@CGUID+1,  65072, 0, 0, 0, 1, 0, 0, 0, 0, -8207.058, 543.5035, 117.7647, 2.447613, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Great Black Dragon Turtle (Area: Stormwind City)
(@CGUID+2,  62106, 0, 0, 0, 1, 0, 0, 0, 0, -8219.729, 561.1302, 116.0979, 3.653169, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Great Red Dragon Turtle (Area: Stormwind City)
(@CGUID+3,  69822, 0, 0, 0, 1, 0, 0, 0, 0, -8316.291, 486.9793, 124.3853, 0.9919749,120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Kelly Aguilar (Area: Stormwind City)
(@CGUID+4,  69334, 0, 0, 0, 1, 0, 0, 0, 0, -8193.158, 544.4063, 117.7312, 4.525026, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Adherent Hanjun (Area: Stormwind City)
(@CGUID+5,  65069, 0, 0, 0, 1, 0, 0, 0, 0, -8171.686, 528.4028,  116.987, 3.008305, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Training Target (Area: Stormwind City)
(@CGUID+6,  70296, 0, 0, 0, 1, 0, 0, 0, 0,  -8210.13, 549.2552, 117.8188, 5.426604, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Mei Lin (Area: Stormwind City)
(@CGUID+7,  65074, 0, 0, 0, 1, 0, 0, 0, 0, -8206.723, 552.0851, 117.9804, 3.028155, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Great Blue Dragon Turtle (Area: Stormwind City)
(@CGUID+8,  65068, 0, 0, 0, 1, 0, 0, 0, 0, -8209.379, 546.0261, 117.8515, 1.611364, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Old Whitenose (Area: Stormwind City)
(@CGUID+9,  65066, 0, 0, 0, 1, 0, 0, 0, 0, -8173.206, 525.3851, 116.8512, 3.550534, 120,10, 0, 0, 0, 1, 0, 0, 0, 23420), -- Jojo Ironbrow (Area: Stormwind City) (Auras: 115672 - Animal Pillar Weapon) (possible waypoints or random movement)
(@CGUID+10, 65063, 0, 0, 0, 1, 0, 0, 0, 0, -8258.997,  549.184, 117.7639, 6.21257,  120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Purple Dragon Turtle (Area: Stormwind City)
(@CGUID+11, 65078, 0, 0, 0, 1, 0, 0, 0, 0, -8213.181, 545.4563, 116.9866, 5.010402, 120,10, 0, 0, 0, 1, 0, 0, 0, 23420), -- Great Purple Dragon Turtle (Area: Stormwind City) (possible waypoints or random movement)
(@CGUID+12, 69823, 0, 0, 0, 1, 0, 0, 0, 0, -8320.514, 485.0347, 124.4639, 5.970798, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Waffle Joe (Area: Stormwind City)
(@CGUID+13, 65065, 0, 0, 0, 1, 0, 0, 0, 0, -8245.194,  519.342, 115.9055, 0.3727989,120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Red Dragon Turtle (Area: Stormwind City)
(@CGUID+14, 63596, 0, 0, 0, 1, 0, 0, 0, 0, -8287.216, 515.4913, 120.5628, 1.472758, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Audrey Burnhep (Area: Stormwind City)
(@CGUID+15, 65058, 0, 0, 0, 1, 0, 0, 0, 0, -8218.748, 535.8333, 114.5575, 0.4572131,120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Black Dragon Turtle (Area: Stormwind City)
(@CGUID+16, 61809, 0, 0, 0, 1, 0, 0, 0, 0, -8269.261, 540.1045,  119.284, 6.135595, 120,10, 0, 0, 0, 1, 0, 0, 0, 23420), -- Green Dragon Turtle (Area: Stormwind City) (possible waypoints or random movement)
(@CGUID+17, 65060, 0, 0, 0, 1, 0, 0, 0, 0, -8215.028, 532.7587, 114.7506, 0.8372275,120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Blue Dragon Turtle (Area: Stormwind City)
(@CGUID+18, 68868, 0, 0, 0, 1, 0, 0, 0, 0, -8195.336, 536.043,   117.715, 2.856428, 120,10, 0, 0, 0, 1, 0, 0, 0, 23420), -- Meng Meng (Area: Stormwind City) (Auras: 19231 - Panda) (possible waypoints or random movement)
(@CGUID+19, 65076, 0, 0, 0, 1, 0, 0, 0, 0, -8210.611, 555.1354, 117.8941, 3.333841, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Great Brown Dragon Turtle (Area: Stormwind City)
(@CGUID+20, 65048, 0, 0, 0, 1, 0, 0, 0, 0, -8194.863,  553.941, 117.7364, 3.160197, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Tushui Trainee (Area: Stormwind City)
(@CGUID+21, 62419, 0, 0, 0, 1, 0, 0, 0, 0, -8180.068,  536.783, 117.7806, 3.475532, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Aysa Cloudsinger (Area: Stormwind City) (Auras: 121801 - Meditate)
(@CGUID+22, 65051, 0, 0, 0, 1, 0, 0, 0, 0, -8177.063, 552.6077, 118.1873, 0.6058627,120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Tushui Monk (Area: Stormwind City)
(@CGUID+23, 65051, 0, 0, 0, 1, 0, 0, 0, 0, -8176.658, 548.5573, 118.1762, 5.998106, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Tushui Monk (Area: Stormwind City)
(@CGUID+24, 65048, 0, 0, 0, 1, 0, 0, 0, 0, -8183.563, 518.2118, 116.0673, 4.893826, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Tushui Trainee (Area: Stormwind City)
(@CGUID+25, 65071, 0, 0, 0, 1, 0, 0, 0, 0, -8210.129, 560.1823, 117.9276, 2.427126, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Great Green Dragon Turtle (Area: Stormwind City)
(@CGUID+26, 60931, 0, 0, 0, 1, 0, 0, 0, 0, -8175.077, 554.1163, 117.5669, 3.952876, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Training Target (Area: Stormwind City)
(@CGUID+27, 65051, 0, 0, 0, 1, 0, 0, 0, 0,     -8175, 527.3802, 117.4257, 0.2804516,120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Tushui Monk (Area: Stormwind City)
(@CGUID+28,   721, 0, 0, 0, 1, 0, 0, 0, 0, -8288.962, 514.8698, 121.1682, 1.322721, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Rabbit (Area: Stormwind City)
(@CGUID+29, 63607, 0, 0, 0, 1, 0, 0, 0, 0,  -8286.06, 515.4132,  121.955, 1.636948, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Squirrel (Area: Stormwind City)
(@CGUID+30,   721, 0, 0, 0, 1, 0, 0, 0, 0, -8285.967, 515.2083, 121.2849, 1.322721, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Rabbit (Area: Stormwind City)
(@CGUID+31,  2620, 0, 0, 0, 1, 0, 0, 0, 0, -8285.226, 516.2621, 120.6083, 1.798302, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Prairie Dog (Area: Stormwind City)
(@CGUID+32, 63607, 0, 0, 0, 1, 0, 0, 0, 0, -8289.283,  516.125, 120.5177, 1.207059, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Squirrel (Area: Stormwind City)
(@CGUID+33,  1412, 0, 0, 0, 1, 0, 0, 0, 0, -8180.209, 557.8125,   117.59, 5.951096, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Squirrel (Area: Stormwind City)
(@CGUID+34,101759, 0, 0, 0, 1, 0, 0, 0, 0, -8196.545, 399.1927, 117.2882, 2.445552, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420); -- Kiatke (Area: The Eastern Earthshrine) (Auras: 182641 - Game Object Despawn Periodic)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+33;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+0,  0, 0, 50331648,  1, 0, 0, 0, 0, ''), -- Brown Dragon Turtle
(@CGUID+1, 0, 0,        0,  1, 0, 0, 0, 0, ''), -- Great Black Dragon Turtle
(@CGUID+2,  0, 0,        0,  1, 0, 0, 0, 0, ''), -- Great Red Dragon Turtle
(@CGUID+3,  0, 0,        0,  1, 0, 0, 0, 0, ''), -- Kelly Aguilar
(@CGUID+4, 0, 0,        0,257, 0, 0, 0, 0, ''), -- Adherent Hanjun
(@CGUID+5, 0, 0,        0,  1, 0, 0, 0, 0, ''), -- Training Target
(@CGUID+6,  0, 0,        0,257, 0, 0, 0, 0, ''), -- Mei Lin
(@CGUID+7, 0, 0,        0,  1, 0, 0, 0, 0, ''), -- Great Blue Dragon Turtle
(@CGUID+8,  0, 0,        0,  1, 0, 0, 0, 0, ''), -- Old Whitenose
(@CGUID+9, 0, 0,        0,  1, 0, 0, 0, 0, '115672'), -- Jojo Ironbrow - 115672 - Animal Pillar Weapon
(@CGUID+10, 0, 0,        0,  1, 0, 0, 0, 0, ''), -- Purple Dragon Turtle
(@CGUID+11, 0, 0,        0,  1, 0, 0, 0, 0, ''), -- Great Purple Dragon Turtle
(@CGUID+12, 0, 0,        0,  1, 0, 0, 0, 0, ''), -- Waffle Joe
(@CGUID+13, 0, 0,        0,  1, 0, 0, 0, 0, ''), -- Red Dragon Turtle
(@CGUID+14, 0, 0,        0,  1, 0, 0, 0, 0, ''), -- Audrey Burnhep
(@CGUID+15, 0, 0, 50331648,  1, 0, 0, 0, 0, ''), -- Black Dragon Turtle
(@CGUID+16, 0, 0,        0,  1, 0, 0, 0, 0, ''), -- Green Dragon Turtle
(@CGUID+17, 0, 0, 50331648,  1, 0, 0, 0, 0, ''), -- Blue Dragon Turtle
(@CGUID+18, 0, 0,        0,  1, 0, 0, 0, 0, '19231'), -- Meng Meng - 19231 - Panda
(@CGUID+19, 0, 0,        0,  1, 0, 0, 0, 0, ''), -- Great Brown Dragon Turtle
(@CGUID+20, 0, 0,        1,  1, 0, 0, 0, 0, ''), -- Tushui Trainee
(@CGUID+21, 0, 0,        0,  1, 0, 0, 0, 0, '121801'), -- Aysa Cloudsinger - 121801 - Meditate
(@CGUID+22, 0, 0,        0,  1, 0, 0, 0, 0, ''), -- Tushui Monk
(@CGUID+23, 0, 0,        0,  1, 0, 0, 0, 0, ''), -- Tushui Monk
(@CGUID+24, 0, 0,        8,  1, 0, 0, 0, 0, ''), -- Tushui Trainee
(@CGUID+25, 0, 0,        0,  1, 0, 0, 0, 0, ''), -- Great Green Dragon Turtle
(@CGUID+26, 0, 0,        0,  1, 0, 0, 0, 0, ''), -- Training Target
(@CGUID+27, 0, 0,        0,  1, 0, 0, 0, 0, ''), -- Tushui Monk
(@CGUID+28, 0, 0,        0,  1, 0, 0, 0, 0, ''), -- Rabbit
(@CGUID+29, 0, 0,        0,  1, 0, 0, 0, 0, ''), -- Squirrel
(@CGUID+30, 0, 0,        0,  1, 0, 0, 0, 0, ''), -- Rabbit
(@CGUID+31, 0, 0,        0,  1, 0, 0, 0, 0, ''), -- Prairie Dog
(@CGUID+32, 0, 0,        0,  1, 0, 0, 0, 0, ''), -- Squirrel
(@CGUID+33, 0, 0,        0,  1, 0, 0, 0, 0, ''); -- Squirrel

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+3;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 214404, 0, 0, 0, 1, 0, 0, -8172.147, 529.6597, 117.1095, 4.910376,          0, 0,         -0.6337605, 0.7735294, 120, 255, 1, 23420), -- Training Target Post (Area: Stormwind City)
(@OGUID+1, 214404, 0, 0, 0, 1, 0, 0, -8172.147, 529.6597, 117.1095, 4.910376,          0, 0,         -0.6337605, 0.7735294, 120, 255, 1, 23420), -- Training Target Post (Area: Stormwind City)
(@OGUID+2, 214405, 0, 0, 0, 1, 0, 0, -8192.064, 559.342,  117.5954, 4.643345,          0, 0,         -0.7310915, 0.6822795, 120, 255, 1, 23420), -- Tushui Banner (Area: Stormwind City)
(@OGUID+3, 214405, 0, 0, 0, 1, 0, 0, -8192.064, 559.342,  117.5954, 4.643345,          0, 0,         -0.7310915, 0.6822795, 120, 255, 1, 23420); -- Tushui Banner (Area: Stormwind City)

DELETE FROM `creature_addon` WHERE `guid`=@CGUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID, 0, 0,        0,  1, 0, 0, 0, 0, ''); -- Kiatke

-- 
DELETE FROM `creature_template_addon` WHERE `entry` IN (65066,65074,65069,69334,65072,65071,60931,65051,62419,65048,65076,68868,65060,61809,65058,63596,65065,69823,65078,65063,65068,70296,63607,69822,62106,65061);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(65066, 0, 0,       0,  1, 0, 0, 0, 0, '115672'), -- 65066 (Jojo Ironbrow) - Animal Pillar Weapon
(65074, 0, 0,       0,  1, 0, 0, 0, 0, ''), -- 65074 (Great Blue Dragon Turtle)
(65069, 0, 0,       0,  1, 0, 0, 0, 0, ''), -- 65069 (Training Target)
(69334, 0, 0,       0,257, 0, 0, 0, 0, ''), -- 69334 (Adherent Hanjun)
(65072, 0, 0,       0,  1, 0, 0, 0, 0, ''), -- 65072 (Great Black Dragon Turtle)
(65071, 0, 0,       0,  1, 0, 0, 0, 0, ''), -- 65071 (Great Green Dragon Turtle)
(60931, 0, 0,       0,  1, 0, 0, 0, 0, ''), -- 60931 (Training Target)
(65051, 0, 0,       0,  1, 0, 0, 0, 0, ''), -- 65051 (Tushui Monk)
(62419, 0, 0,       0,  1, 0, 0, 0, 0, '121801'), -- 62419 (Aysa Cloudsinger) - Meditate
(65048, 0, 0,       1,  1, 0, 0, 0, 0, ''), -- 65048 (Tushui Trainee)
(65076, 0, 0,       0,  1, 0, 0, 0, 0, ''), -- 65076 (Great Brown Dragon Turtle)
(68868, 0, 0,       0,  1, 0, 0, 0, 0, '19231'), -- 68868 (Meng Meng) - Panda
(65060, 0, 0,50331648,  1, 0, 0, 0, 0, ''), -- 65060 (Blue Dragon Turtle)
(61809, 0, 0,       0,  1, 0, 0, 0, 0, ''), -- 61809 (Green Dragon Turtle)
(65058, 0, 0,50331648,  1, 0, 0, 0, 0, ''), -- 65058 (Black Dragon Turtle)
(63596, 0, 0,       0,  1, 0, 0, 0, 0, ''), -- 63596 (Audrey Burnhep)
(65065, 0, 0,       0,  1, 0, 0, 0, 0, ''), -- 65065 (Red Dragon Turtle)
(69823, 0, 0,       0,  1, 0, 0, 0, 0, ''), -- 69823 (Waffle Joe)
(65078, 0, 0,       0,  1, 0, 0, 0, 0, ''), -- 65078 (Great Purple Dragon Turtle)
(65063, 0, 0,       0,  1, 0, 0, 0, 0, ''), -- 65063 (Purple Dragon Turtle)
(65068, 0, 0,       0,  1, 0, 0, 0, 0, ''), -- 65068 (Old Whitenose)
(70296, 0, 0,       0,257, 0, 0, 0, 0, ''), -- 70296 (Mei Lin)
(63607, 0, 0,       0,  1, 0, 0, 0, 0, ''), -- 63607 (Squirrel)
(69822, 0, 0,       0,  1, 0, 0, 0, 0, ''), -- 69822 (Kelly Aguilar)
(62106, 0, 0,       0,  1, 0, 0, 0, 0, ''), -- 62106 (Great Red Dragon Turtle)
(65061, 0, 0,50331648,  1, 0, 0, 0, 0, ''); -- 65061 (Brown Dragon Turtle)

DELETE FROM `npc_vendor` WHERE (`entry`=69334 AND `item`=92071 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=69334 AND `item`=83079 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=101759 AND `item`=133160 AND `ExtendedCost`=5941 AND `type`=1) OR (`entry`=101759 AND `item`=133159 AND `ExtendedCost`=5941 AND `type`=1) OR (`entry`=101759 AND `item`=133154 AND `ExtendedCost`=5941 AND `type`=1) OR (`entry`=101759 AND `item`=133152 AND `ExtendedCost`=5941 AND `type`=1) OR (`entry`=101759 AND `item`=133151 AND `ExtendedCost`=5941 AND `type`=1) OR (`entry`=101759 AND `item`=67414 AND `ExtendedCost`=5940 AND `type`=1) OR (`entry`=101759 AND `item`=122341 AND `ExtendedCost`=5938 AND `type`=1) OR (`entry`=101759 AND `item`=122340 AND `ExtendedCost`=5936 AND `type`=1) OR (`entry`=101759 AND `item`=122339 AND `ExtendedCost`=5937 AND `type`=1) OR (`entry`=101759 AND `item`=122338 AND `ExtendedCost`=5935 AND `type`=1) OR (`entry`=101759 AND `item`=133541 AND `ExtendedCost`=5932 AND `type`=1) OR (`entry`=101759 AND `item`=133540 AND `ExtendedCost`=5932 AND `type`=1) OR (`entry`=101759 AND `item`=133524 AND `ExtendedCost`=5931 AND `type`=1) OR (`entry`=101759 AND `item`=133522 AND `ExtendedCost`=5931 AND `type`=1) OR (`entry`=101759 AND `item`=133525 AND `ExtendedCost`=5931 AND `type`=1) OR (`entry`=101759 AND `item`=133531 AND `ExtendedCost`=5931 AND `type`=1) OR (`entry`=101759 AND `item`=133533 AND `ExtendedCost`=5931 AND `type`=1) OR (`entry`=101759 AND `item`=133527 AND `ExtendedCost`=5931 AND `type`=1) OR (`entry`=101759 AND `item`=133534 AND `ExtendedCost`=5931 AND `type`=1) OR (`entry`=101759 AND `item`=133530 AND `ExtendedCost`=5931 AND `type`=1) OR (`entry`=101759 AND `item`=133528 AND `ExtendedCost`=5931 AND `type`=1) OR (`entry`=101759 AND `item`=133529 AND `ExtendedCost`=5931 AND `type`=1) OR (`entry`=101759 AND `item`=133535 AND `ExtendedCost`=5931 AND `type`=1) OR (`entry`=101759 AND `item`=133521 AND `ExtendedCost`=5931 AND `type`=1) OR (`entry`=101759 AND `item`=133520 AND `ExtendedCost`=5931 AND `type`=1) OR (`entry`=101759 AND `item`=133539 AND `ExtendedCost`=5932 AND `type`=1) OR (`entry`=101759 AND `item`=133536 AND `ExtendedCost`=5931 AND `type`=1) OR (`entry`=101759 AND `item`=133532 AND `ExtendedCost`=5931 AND `type`=1) OR (`entry`=101759 AND `item`=133526 AND `ExtendedCost`=5931 AND `type`=1) OR (`entry`=101759 AND `item`=133538 AND `ExtendedCost`=5932 AND `type`=1) OR (`entry`=101759 AND `item`=133537 AND `ExtendedCost`=5932 AND `type`=1) OR (`entry`=101759 AND `item`=133523 AND `ExtendedCost`=5931 AND `type`=1) OR (`entry`=101759 AND `item`=133542 AND `ExtendedCost`=5948 AND `type`=1) OR (`entry`=101759 AND `item`=133511 AND `ExtendedCost`=5945 AND `type`=1) OR (`entry`=101759 AND `item`=49602 AND `ExtendedCost`=5949 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
( 69334,  2,  92071, 0,    0, 1,19985, 0, 23420), -- Tushui Satchel
( 69334,  1,  83079, 0,    0, 1,    0, 0, 23420), -- Tushui Tabard
(101759, 37, 133160, 0, 5941, 1,    0, 0, 23420), -- Commendation of Therazane
(101759, 36, 133159, 0, 5941, 1,    0, 0, 23420), -- Commendation of The Earthen Ring
(101759, 35, 133154, 0, 5941, 1,    0, 0, 23420), -- Commendation of the Ramkahen
(101759, 34, 133152, 0, 5941, 1,    0, 0, 23420), -- Commendation of the Guardians of Hyjal
(101759, 33, 133151, 0, 5941, 1,    0, 0, 23420), -- Commendation of the Wildhammer Clan
(101759, 31,  67414, 0, 5940, 1,    0, 0, 23420), -- Bag of Shiny Things
(101759, 30, 122341, 0, 5938, 1,    0, 0, 23420), -- Timeworn Heirloom Scabbard
(101759, 29, 122340, 0, 5936, 1,    0, 0, 23420), -- Timeworn Heirloom Armor Casing
(101759, 28, 122339, 0, 5937, 1,    0, 0, 23420), -- Ancient Heirloom Scabbard
(101759, 27, 122338, 0, 5935, 1,    0, 0, 23420), -- Ancient Heirloom Armor Casing
(101759, 26, 133541, 0, 5932, 1,    0, 0, 23420), -- Fire of the Deep
(101759, 25, 133540, 0, 5932, 1,    0, 0, 23420), -- Rotting Skull
(101759, 24, 133524, 0, 5931, 1,    0, 0, 23420), -- Signet of the Resolute
(101759, 23, 133522, 0, 5931, 1,    0, 0, 23420), -- Ring of Torn Flesh
(101759, 22, 133525, 0, 5931, 1,    0, 0, 23420), -- Bones of the Damned
(101759, 21, 133531, 0, 5931, 1,    0, 0, 23420), -- Blinding Girdle of Truth
(101759, 20, 133533, 0, 5931, 1,    0, 0, 23420), -- Flashing Bracers of Warmth
(101759, 19, 133527, 0, 5931, 1,    0, 0, 23420), -- Ghostworld Chestguard
(101759, 18, 133534, 0, 5931, 1,    0, 0, 23420), -- Dragonbelly Bracers
(101759, 17, 133530, 0, 5931, 1,    0, 0, 23420), -- Cord of Dragon Sinew
(101759, 16, 133528, 0, 5931, 1,    0, 0, 23420), -- Decaying Herbalist's Robes
(101759, 15, 133529, 0, 5931, 1,    0, 0, 23420), -- Belt of Hidden Keys
(101759, 14, 133535, 0, 5931, 1,    0, 0, 23420), -- Bracers of Manifold Pockets
(101759, 13, 133521, 0, 5931, 1,    0, 0, 23420), -- Band of Reconstruction
(101759, 12, 133520, 0, 5931, 1,    0, 0, 23420), -- Seal of the Grand Architect
(101759, 11, 133539, 0, 5932, 1,    0, 0, 23420), -- Reflection of the Light
(101759, 10, 133536, 0, 5931, 1,    0, 0, 23420), -- Bracers of the Black Dream
(101759,  9, 133532, 0, 5931, 1,    0, 0, 23420), -- Vestal's Irrepressible Girdle
(101759,  8, 133526, 0, 5931, 1,    0, 0, 23420), -- Lightwarper Vestments
(101759,  7, 133538, 0, 5932, 1,    0, 0, 23420), -- Bottled Wishes
(101759,  6, 133537, 0, 5932, 1,    0, 0, 23420), -- Kiroptyric Sigil
(101759,  5, 133523, 0, 5931, 1,    0, 0, 23420), -- Emergency Descent Loop
(101759,  4, 133542, 0, 5948, 1,    0, 0, 23420), -- Tosselwrench's Mega-Accurate Simulation Viewfinder
(101759,  3, 133511, 0, 5945, 1,    0, 0, 23420), -- Gurboggle's Gleaming Bauble
(101759,  2,  49602, 0, 5949, 1,    0, 0, 23420); -- Earl Black Tea

DELETE FROM `gossip_menu` WHERE (`MenuID`=14249 AND `TextID`=20026) OR (`MenuID`=19197 AND `TextID`=28133);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`) VALUES
(14249, 20026), -- 62419 (Aysa Cloudsinger)
(19197, 28133); -- 101759 (Kiatke)

UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `faction`=35, `npcflag`=131, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=101759; -- Kiatke
UPDATE `creature_template` SET `flags_extra`=0 WHERE `entry`=65069; -- Training Target

DELETE FROM `npc_text` WHERE `ID` IN (20026,28133);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(20026, 1, 0, 0, 0, 0, 0, 0, 0,  61809, 0, 0, 0, 0, 0, 0, 0, 23420), -- 20026
(28133, 1, 0, 0, 0, 0, 0, 0, 0, 100487, 0, 0, 0, 0, 0, 0, 0, 23420); -- 28133

UPDATE `creature_equip_template` SET `ItemID2`=0 WHERE (`CreatureID`=47320 AND `ID`=1); -- Kaellin Tarvane

UPDATE `creature_model_info` SET `BoundingRadius`= 0.4596, `CombatReach`= 1.8, `VerifiedBuild`= 23420 WHERE `DisplayID`= 67320;
UPDATE `creature_model_info` SET `VerifiedBuild`= 23420 WHERE `DisplayID` IN (
134,257,328,1072,3167, 4558, 4626, 10008, 11686, 18055, 19283, 21072, 21342,
26748, 26749, 31174, 33494, 33495, 33496, 33521, 33522, 33523, 33527, 33838,
34336, 35537, 35539, 35540, 36620, 37310, 37311, 38459, 39641, 41281, 41667,
42250, 42352, 43717, 43718, 43719, 43720, 43721, 43722, 43723, 43724, 43725,
43726, 45871, 45873, 45874, 45875, 45876, 46986, 47467, 47710, 47711, 47980);
