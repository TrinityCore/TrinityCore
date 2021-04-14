-- Chicken Spawns from sniff:
SET @Chicken := 28161;
SET @CGUID := 88570;
DELETE FROM `creature` WHERE `id`=@Chicken;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`MovementType`) VALUES
(@CGUID,@Chicken,571,1,1,5199.809,4704.83,-128.2989,1.70125,120,0,0), -- Chicken Escapee
(@CGUID+1,@Chicken,571,1,1,5201.715,4702.484,-127.8371,1.53589,120,0,0), -- Chicken Escapee
(@CGUID+2,@Chicken,571,1,1,5198.132,4702.78,-127.5534,1.797689,120,0,0), -- Chicken Escapee
(@CGUID+3,@Chicken,571,1,1,5198.32,4704.375,-127.9992,1.064651,120,0,0), -- Chicken Escapee
(@CGUID+4,@Chicken,571,1,1,5201.744,4704.674,-128.4752,4.555309,120,0,0), -- Chicken Escapee
(@CGUID+5,@Chicken,571,1,1,5251.442,4508.976,-85.30431,4.304774,120,0,0), -- Chicken Escapee
(@CGUID+6,@Chicken,571,1,1,5251.708,4511.778,-85.32935,1.64061,120,0,0), -- Chicken Escapee
(@CGUID+7,@Chicken,571,1,1,5251.118,4509.744,-85.32935,4.886922,120,0,0), -- Chicken Escapee
(@CGUID+8,@Chicken,571,1,1,5252.795,4509.772,-85.32524,0.7853982,120,0,0), -- Chicken Escapee
(@CGUID+9,@Chicken,571,1,1,5253.682,4511.424,-85.32755,2.356194,120,0,0), -- Chicken Escapee
(@CGUID+10,@Chicken,571,1,1,5254.174,4514.632,-84.96572,0.4096795,120,0,0), -- Chicken Escapee
(@CGUID+11,@Chicken,571,1,1,5252.096,4514.868,-85.32635,4.363323,120,0,0), -- Chicken Escapee
(@CGUID+12,@Chicken,571,1,1,5251.637,4513.41,-85.32935,3.490659,120,0,0), -- Chicken Escapee
(@CGUID+13,@Chicken,571,1,1,5253.287,4513.109,-85.32935,3.036873,120,0,0), -- Chicken Escapee
(@CGUID+14,@Chicken,571,1,1,5253.494,4514.764,-85.31329,3.717551,120,0,0), -- Chicken Escapee
(@CGUID+15,@Chicken,571,1,1,5251.158,4518.321,-85.3019,1.592369,120,0,0), -- Chicken Escapee
(@CGUID+16,@Chicken,571,1,1,5250.385,4516.643,-85.3257,5.044002,120,0,0), -- Chicken Escapee
(@CGUID+17,@Chicken,571,1,1,5251.159,4515.294,-85.32935,4.694936,120,0,0), -- Chicken Escapee
(@CGUID+18,@Chicken,571,1,1,5252.267,4516.414,-85.30904,0.5235988,120,0,0), -- Chicken Escapee
(@CGUID+19,@Chicken,571,1,1,5251.693,4517.859,-85.3243,4.590216,120,0,0), -- Chicken Escapee
(@CGUID+20,@Chicken,571,1,1,5262.68,4528.738,-84.4747,4.718389,120,0,0), -- Chicken Escapee
(@CGUID+21,@Chicken,571,1,1,5256.907,4480.617,-84.26879,4.927223,120,0,0), -- Chicken Escapee
(@CGUID+22,@Chicken,571,1,1,5298.603,4489.708,-93.65161,6.16371,120,0,0), -- Chicken Escapee
(@CGUID+23,@Chicken,571,1,1,5192.673,4513.661,-89.12463,1.299241,120,0,0), -- Chicken Escapee
(@CGUID+24,@Chicken,571,1,1,5228.781,4579.799,-96.98647,0.05766594,120,0,0), -- Chicken Escapee
(@CGUID+25,@Chicken,571,1,1,5230.247,4433.143,-96.82567,5.135688,120,0,0), -- Chicken Escapee
(@CGUID+26,@Chicken,571,1,1,5180.035,4541.38,-97.84879,0.2208638,120,0,0), -- Chicken Escapee
(@CGUID+27,@Chicken,571,1,1,5178.563,4538.964,-97.54511,0.9771074,120,0,0), -- Chicken Escapee
(@CGUID+28,@Chicken,571,1,1,5272.981,4417.033,-96.50356,0.9044432,120,0,0), -- Chicken Escapee
(@CGUID+29,@Chicken,571,1,1,5214.513,4416.202,-96.53072,2.862281,120,0,0), -- Chicken Escapee
(@CGUID+30,@Chicken,571,1,1,5160.117,4474.996,-96.96887,4.499754,120,0,0), -- Chicken Escapee
(@CGUID+31,@Chicken,571,1,1,5263.541,4409.121,-95.87889,1.570796,120,0,0), -- Chicken Escapee
(@CGUID+32,@Chicken,571,1,1,5234.166,4404.604,-95.12725,1.031549,120,0,0), -- Chicken Escapee
(@CGUID+33,@Chicken,571,1,1,5297.803,4493.681,-93.65161,5.525303,120,0,0), -- Chicken Escapee
(@CGUID+34,@Chicken,571,1,1,5260.112,4340.577,-97.61092,1.942801,120,0,0), -- Chicken Escapee
(@CGUID+35,@Chicken,571,1,1,5208.492,4379.111,-95.49483,0.6675518,120,0,0), -- Chicken Escapee
(@CGUID+36,@Chicken,571,1,1,5172.742,4368.674,-96.27965,0.8766832,120,0,0), -- Chicken Escapee
(@CGUID+37,@Chicken,571,1,1,5223.491,4467.19,-96.75621,4.723376,120,0,0), -- Chicken Escapee
(@CGUID+38,@Chicken,571,1,1,5220.966,4469.76,-96.75582,5.183968,120,0,0), -- Chicken Escapee
(@CGUID+39,@Chicken,571,1,1,5221.419,4473.14,-96.75536,4.98181,120,0,0), -- Chicken Escapee
(@CGUID+40,@Chicken,571,1,1,5221.419,4473.14,-96.75536,5.49084,120,0,0), -- Chicken Escapee
(@CGUID+41,@Chicken,571,1,1,5221.828,4470.711,-96.57594,5.315169,120,0,0), -- Chicken Escapee
(@CGUID+42,@Chicken,571,1,1,5151.083,4416.434,-96.38642,2.066685,120,0,0), -- Chicken Escapee
(@CGUID+43,@Chicken,571,1,1,5281.582,4425.185,-96.79945,4.45059,120,0,0), -- Chicken Escapee
(@CGUID+44,@Chicken,571,1,1,5257.173,4424.231,-95.62836,3.996804,120,0,0); -- Chicken Escapee

-- Aura for Chicken Escapee (thx Discovered)
DELETE FROM `creature_template_addon` WHERE `entry`=28161;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(28161,0,0,0,0,'50734'); -- Chicken Escapee - Frenzyheart Chicken: Invisibility
