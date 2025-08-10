SET @CGUID := 7000565;
SET @OGUID := 7000210;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+397;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4165.8369140625, -1303.779541015625, 180.8975830078125, 4.896152496337890625, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+1, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4155.939453125, -1279.15625, 179.861083984375, 1.97762298583984375, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+2, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4167.314453125, -1300.90625, 180.3885650634765625, 4.704022884368896484, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+3, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4091.751953125, -1276.39404296875, 177.2539825439453125, 5.600994586944580078, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display)) (possible waypoints or random movement)
(@CGUID+4, 134139, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 4164.4794921875, -1288.9990234375, 179.81610107421875, 4.997716903686523437, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Shrine Templar (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+5, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4172.12353515625, -1303.9566650390625, 181.0751953125, 4.619808197021484375, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+6, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4146.408203125, -1277.873291015625, 179.9102935791015625, 1.525839447975158691, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+7, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4096.09326171875, -1284.3302001953125, 177.312744140625, 2.453619956970214843, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+8, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4174.54345703125, -1303.6597900390625, 181.0751953125, 4.740228176116943359, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+9, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4173.6416015625, -1301.84375, 180.568756103515625, 4.537932395935058593, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+10, 141587, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4173.8271484375, -1292.0518798828125, 180.1780548095703125, 4.056932449340820312, 7200, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Rat (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+11, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4164.1640625, -1301.467041015625, 180.4043731689453125, 4.619880199432373046, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+12, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4152.337890625, -1280.092041015625, 179.893798828125, 1.902879714965820312, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+13, 139970, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4171.81689453125, -1259.2083740234375, 181.574981689453125, 2.248472213745117187, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Brother Pike (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+14, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4170.6494140625, -1302.0242919921875, 180.55450439453125, 4.741146087646484375, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+15, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4149.3447265625, -1280.107666015625, 179.9102935791015625, 1.761011004447937011, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+16, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4161.38916015625, -1273.970458984375, 179.8397674560546875, 2.466917991638183593, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+17, 134137, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 4097.67724609375, -1285.5572509765625, 177.4269256591796875, 2.439705848693847656, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Temple Attendant (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+18, 120652, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4173.462890625, -1249.4254150390625, 183.974822998046875, 3.138837814331054687, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Global Affix Stalker (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+19, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4169.0849609375, -1303.701416015625, 180.9181671142578125, 4.758759021759033203, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+20, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4159.875, -1277.1441650390625, 179.8580474853515625, 2.264536380767822265, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+21, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4096.3955078125, -1285.3643798828125, 177.3384552001953125, 5.163544654846191406, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display))
(@CGUID+22, 141587, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4156.220703125, -1280.346435546875, 179.78857421875, 1.06819009780883789, 7200, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Rat (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+23, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4095.68701171875, -1297.240966796875, 177.3146209716796875, 3.88091897964477539, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+24, 134144, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4069.736083984375, -1291.609375, 148.5996246337890625, 3.220905780792236328, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Living Current (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+25, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4095.297607421875, -1284.2685546875, 177.3083038330078125, 0.388292610645294189, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+26, 141585, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4098.62451171875, -1266.673828125, 177.1884002685546875, 0.16165173053741455, 7200, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Sea Louse (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+27, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4092.935791015625, -1301.859375, 177.2600250244140625, 5.274521350860595703, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+28, 141585, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4109.80029296875, -1291.2935791015625, 177.295379638671875, 2.630531072616577148, 7200, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Sea Louse (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+29, 140967, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4181.16748046875, -1309.423583984375, 181.428131103515625, 1.357714653015136718, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Shrine's Breath (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+30, 136186, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 4065.481689453125, -1257.4930419921875, 163.752410888671875, 1.968111276626586914, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Spiritualist (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+31, 136188, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4050.624267578125, -1215.09375, 172.6193084716796875, 2.370021581649780273, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Bound Soul (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+32, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4092.715576171875, -1297.813720703125, 177.3319854736328125, 0.757850706577301025, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+33, 134137, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 4056.3681640625, -1206.8489990234375, 168.345611572265625, 4.024727821350097656, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Temple Attendant (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+34, 140999, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4091.14404296875, -1308.720458984375, 179.7542724609375, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Shrine's Breath (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+35, 136186, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 4053.009521484375, -1222.8385009765625, 168.7990264892578125, 2.979154825210571289, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Spiritualist (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 170134 - Enforce LOD 2)
(@CGUID+36, 134137, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 4058.0234375, -1218.4271240234375, 168.366607666015625, 2.559349536895751953, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Temple Attendant (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+37, 136505, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4047.84375, -1214.7552490234375, 185.1219635009765625, 6.157097339630126953, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Rune (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+38, 141585, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4101.44091796875, -1314.1793212890625, 177.1780548095703125, 0.828377127647399902, 7200, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Sea Louse (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+39, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4095.661376953125, -1287.7484130859375, 177.4789581298828125, 1.224059581756591796, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+40, 141585, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4104.03857421875, -1297.650390625, 177.23089599609375, 2.160120010375976562, 7200, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Sea Louse (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+41, 134137, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 4098.53662109375, -1295.154541015625, 177.4269256591796875, 3.977274894714355468, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Temple Attendant (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+42, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4089.1015625, -1294.9075927734375, 177.395904541015625, 0.364063650369644165, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+43, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4092.86328125, -1294.0169677734375, 177.396270751953125, 1.592236638069152832, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+44, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4088.900634765625, -1280.69873046875, 177.1996002197265625, 5.919715404510498046, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+45, 140999, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4091.171875, -1271.390625, 179.868682861328125, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Shrine's Breath (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 275640 - Shrine's Breath)
(@CGUID+46, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4093.29541015625, -1300.1016845703125, 177.287109375, 5.116585731506347656, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+47, 134137, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 4058.450439453125, -1211.8072509765625, 168.29595947265625, 3.412688016891479492, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Temple Attendant (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+48, 134139, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 4050.87451171875, -1298.572265625, 149.4367523193359375, 5.206009864807128906, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Shrine Templar (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+49, 134137, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 4085.6884765625, -1151.267333984375, 109.4740371704101562, 3.013073921203613281, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Temple Attendant (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+50, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4037.5, -1285.416015625, 149.110626220703125, 5.442338943481445312, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+51, 136505, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4086.093017578125, -1145.279541015625, 112.4451828002929687, 3.726858377456665039, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Rune (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+52, 136188, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4043.294189453125, -1224.91845703125, 172.24151611328125, 5.944369792938232421, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Bound Soul (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+53, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4041.340576171875, -1283.4324951171875, 149.186248779296875, 0.462575286626815795, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+54, 136186, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 4069.911376953125, -1324.3853759765625, 166.5314483642578125, 4.220910549163818359, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Spiritualist (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+55, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4041.299560546875, -1278.680419921875, 149.178192138671875, 1.5866471529006958, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display)) (possible waypoints or random movement)
(@CGUID+56, 136186, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 4029.045166015625, -1207.5260009765625, 168.799102783203125, 5.734608650207519531, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Spiritualist (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+57, 134137, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 4051.225830078125, -1291.65625, 149.271026611328125, 0.1912250816822052, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Temple Attendant (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+58, 140999, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4040.25341796875, -1274.18408203125, 150.490997314453125, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Shrine's Breath (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+59, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4034.783447265625, -1280.1358642578125, 149.0554962158203125, 3.599227190017700195, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+60, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4037.282958984375, -1278.9342041015625, 149.096710205078125, 3.229505062103271484, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display)) (possible waypoints or random movement)
(@CGUID+61, 140999, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4053.6484375, -1295.93408203125, 150.477142333984375, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Shrine's Breath (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 275640 - Shrine's Breath)
(@CGUID+62, 136188, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4042.147705078125, -1205.8194580078125, 174.3257598876953125, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Bound Soul (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+63, 141585, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4046.2021484375, -1297.2935791015625, 149.172210693359375, 2.830228328704833984, 7200, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Sea Louse (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+64, 140999, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4053.817626953125, -1283.59375, 150.5587158203125, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Shrine's Breath (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 275640 - Shrine's Breath)
(@CGUID+65, 139799, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 4080.442626953125, -1149.9427490234375, 108.99371337890625, 5.958197593688964843, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Ironhull Apprentice (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+66, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4045.3955078125, -1276.177978515625, 149.187713623046875, 3.199205875396728515, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display)) (possible waypoints or random movement)
(@CGUID+67, 136188, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4069.400146484375, -1339.16845703125, 170.994171142578125, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Bound Soul (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+68, 136186, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 4033.771728515625, -1227.435791015625, 168.7989959716796875, 0.158345699310302734, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Spiritualist (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 170134 - Enforce LOD 2)
(@CGUID+69, 134137, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 4051.17529296875, -1287.2066650390625, 149.271026611328125, 6.171190738677978515, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Temple Attendant (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+70, 139800, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 4084.1728515625, -1153.373291015625, 109.53082275390625, 1.824002265930175781, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Galecaller Apprentice (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+71, 139799, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 4084.467041015625, -1149.345458984375, 109.13055419921875, 4.207228660583496093, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Ironhull Apprentice (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+72, 136186, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 4048.6494140625, -1203.49658203125, 168.799102783203125, 4.129322528839111328, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Spiritualist (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 170134 - Enforce LOD 2)
(@CGUID+73, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4060.268310546875, -1146.984375, 108.93377685546875, 1.538826704025268554, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+74, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4013.623291015625, -1209.8021240234375, 152.616363525390625, 5.837337970733642578, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+75, 141585, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4030.638427734375, -1269.68701171875, 148.3435821533203125, 3.819953680038452148, 7200, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Sea Louse (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+76, 141587, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4075.50830078125, -1139.8662109375, 109.0478286743164062, 3.370248794555664062, 7200, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Rat (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+77, 136186, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 4039.134521484375, -1317.736083984375, 148.973388671875, 4.90801858901977539, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Spiritualist (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+78, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4066.619873046875, -1140.0208740234375, 108.9016189575195312, 3.295199394226074218, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+79, 134137, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 4022.385498046875, -1281.611083984375, 149.1231536865234375, 2.223783731460571289, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Temple Attendant (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+80, 136186, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 4057.083251953125, -1359.1910400390625, 184.6429443359375, 4.209801197052001953, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Spiritualist (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 170134 - Enforce LOD 2)
(@CGUID+81, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4019.4453125, -1234.3160400390625, 152.616363525390625, 0.937498211860656738, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+82, 139799, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 4054.395751953125, -1180.19970703125, 109.9806594848632812, 2.47371077537536621, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Ironhull Apprentice (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+83, 141587, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4071.223876953125, -1158.879150390625, 108.974945068359375, 5.943602561950683593, 7200, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Rat (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+84, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4015.282958984375, -1217.84033203125, 152.616363525390625, 0.937498211860656738, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+85, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4016.94189453125, -1230.2899169921875, 152.616363525390625, 0.204675644636154174, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+86, 139800, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 4046.369873046875, -1182.157958984375, 110.3197021484375, 1.361045718193054199, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Galecaller Apprentice (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+87, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4012.779541015625, -1213.814208984375, 152.616363525390625, 0.204675644636154174, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+88, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4017.78564453125, -1226.27783203125, 152.616363525390625, 5.837337970733642578, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+89, 134137, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 4050.6953125, -1182.4427490234375, 109.9806594848632812, 1.820573091506958007, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Temple Attendant (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+90, 136505, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4054.10498046875, -1153.126708984375, 112.13720703125, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Rune (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+91, 136186, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 4030.85498046875, -1313.8350830078125, 149.15777587890625, 4.46948099136352539, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Spiritualist (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 267636 - Storm Ritual)
(@CGUID+92, 134137, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 4020.049560546875, -1283.2135009765625, 148.854766845703125, 2.103035688400268554, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Temple Attendant (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+93, 140999, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4040.826416015625, -1304.9010009765625, 150.62469482421875, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Shrine's Breath (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 275640 - Shrine's Breath)
(@CGUID+94, 141585, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4029.4130859375, -1297.087890625, 149.03985595703125, 5.632772445678710937, 7200, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Sea Louse (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+95, 136188, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4041.830810546875, -1335.611083984375, 153.284698486328125, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Bound Soul (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+96, 136505, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4070.150146484375, -1130.3125, 112.203399658203125, 5.066953182220458984, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Rune (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+97, 141585, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4036.806640625, -1313.2811279296875, 148.895599365234375, 3.819658994674682617, 7200, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Sea Louse (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+98, 136188, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3989.5166015625, -1225.90625, 134.2234649658203125, 6.002254962921142578, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Bound Soul (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+99, 136186, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 4030.5009765625, -1363.329833984375, 184.6462860107421875, 4.766553401947021484, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Spiritualist (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 170134 - Enforce LOD 2, 276266 - Spirit's Swiftness, 267636 - Storm Ritual)
(@CGUID+100, 134137, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 3997.03466796875, -1282.05908203125, 140.449249267578125, 1.906982421875, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Temple Attendant (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+101, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4005.50732421875, -1170.84814453125, 122.4341278076171875, 3.221518993377685546, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+102, 140999, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3993.6025390625, -1265.029541015625, 143.7639923095703125, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Shrine's Breath (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+103, 141585, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3998.670654296875, -1289.375244140625, 140.3607025146484375, 3.157950639724731445, 7200, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Sea Louse (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+104, 134144, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3993.68310546875, -1275.1754150390625, 140.483062744140625, 4.959386348724365234, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Living Current (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+105, 136188, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4051.96533203125, -1366.9149169921875, 195.0895843505859375, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Bound Soul (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+106, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4009.18994140625, -1170.6171875, 120.8819732666015625, 3.215612649917602539, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display))
(@CGUID+107, 134150, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 4060.474853515625, -1141.1146240234375, 108.9337081909179687, 0.928723096847534179, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Runecarver Sorn (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 268205 - Read Scrolls)
(@CGUID+108, 136188, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3997.717041015625, -1232.220458984375, 137.309722900390625, 4.885123729705810546, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Bound Soul (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+109, 136186, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 4046.86279296875, -1364.703125, 184.6429443359375, 5.368290424346923828, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Spiritualist (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 170134 - Enforce LOD 2, 276266 - Spirit's Swiftness, 267636 - Storm Ritual)
(@CGUID+110, 136188, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4034.48095703125, -1370.657958984375, 189.450714111328125, 4.231082439422607421, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Bound Soul (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+111, 134139, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 3989.440185546875, -1280.48779296875, 140.3595733642578125, 0.350144803524017333, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Shrine Templar (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+112, 134137, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 3993.119873046875, -1282.2847900390625, 140.442901611328125, 1.569858908653259277, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Temple Attendant (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+113, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4053.52685546875, -1142.0850830078125, 109.5238876342773437, 0.135325327515602111, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display))
(@CGUID+114, 136186, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 3997.614501953125, -1311.1180419921875, 140.442901611328125, 5.419918537139892578, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Spiritualist (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+115, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4012.87451171875, -1170.3880615234375, 119.2265396118164062, 3.208786964416503906, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display))
(@CGUID+116, 136188, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3995.268310546875, -1242.1180419921875, 134.0543975830078125, 4.39266824722290039, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Bound Soul (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+117, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4060.08154296875, -1133.717041015625, 109.6220550537109375, 4.783997058868408203, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display))
(@CGUID+118, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4016.208984375, -1170.1717529296875, 117.7280197143554687, 3.207265138626098632, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display))
(@CGUID+119, 136188, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4025.7119140625, -1331.267333984375, 152.099884033203125, 1.74659895896911621, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Bound Soul (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+120, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3975.5126953125, -1220.8946533203125, 132.7411651611328125, 3.955449819564819335, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+121, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3980.658447265625, -1283.2489013671875, 140.3595428466796875, 1.869682908058166503, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+122, 136186, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 3978.91748046875, -1230.3021240234375, 132.9293670654296875, 6.068381309509277343, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Spiritualist (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+123, 136186, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 3982.325439453125, -1242.9757080078125, 132.830078125, 0.984195649623870849, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Spiritualist (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+124, 134137, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 3979.97314453125, -1236.5728759765625, 132.9041900634765625, 0.483899027109146118, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Temple Attendant (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+125, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3980.00732421875, -1284.2501220703125, 140.3595428466796875, 3.289147138595581054, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+126, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3983.225830078125, -1250.218505859375, 132.742095947265625, 5.848505973815917968, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+127, 136188, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4016.32470703125, -1362.907958984375, 186.1794281005859375, 1.516922712326049804, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Bound Soul (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+128, 139799, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 3993.60498046875, -1169.8819580078125, 124.2475051879882812, 3.428464174270629882, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Ironhull Apprentice (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+129, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3976.670654296875, -1240.9444580078125, 133.0780181884765625, 1.669401764869689941, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+130, 136188, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3997.725830078125, -1324.77783203125, 143.7567901611328125, 4.885123729705810546, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Bound Soul (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+131, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3976.0419921875, -1221.353515625, 132.741058349609375, 3.966077089309692382, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+132, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3976.51806640625, -1277.7420654296875, 140.359344482421875, 2.076418876647949218, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+133, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3984.19482421875, -1249.24951171875, 132.758697509765625, 3.343274116516113281, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+134, 139799, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 3995.38623046875, -1179.013916015625, 124.3687667846679687, 3.323111534118652343, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Ironhull Apprentice (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+135, 136186, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 4013.123291015625, -1355.30908203125, 184.2409515380859375, 4.529748439788818359, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Spiritualist (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 170134 - Enforce LOD 2)
(@CGUID+136, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3984.410400390625, -1247.88232421875, 132.75714111328125, 5.567447185516357421, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+137, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3977.585693359375, -1286.177734375, 140.3595733642578125, 5.057743549346923828, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+138, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3981.5068359375, -1240.9844970703125, 132.7469635009765625, 1.936105728149414062, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+139, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3975.471435546875, -1225.0511474609375, 132.9753875732421875, 1.763827681541442871, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+140, 136186, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 3991.798583984375, -1312.092041015625, 140.442901611328125, 4.535259246826171875, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Spiritualist (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+141, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3981.60009765625, -1279.2879638671875, 140.359527587890625, 0.159124135971069335, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+142, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3973.8642578125, -1246.774658203125, 132.716156005859375, 2.362820386886596679, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+143, 134137, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 3967.90625, -1295.263916015625, 141.0859832763671875, 1.086429119110107421, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Temple Attendant (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+144, 140999, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3960.71533203125, -1264.49658203125, 160.0149993896484375, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Shrine's Breath (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+145, 141585, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 4011.705322265625, -1117.29150390625, 105.7718276977539062, 2.668456077575683593, 7200, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Sea Louse (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+146, 140999, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3960.45654296875, -1258.892333984375, 152.1474609375, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Shrine's Breath (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+147, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3970.534912109375, -1221.604248046875, 132.7446746826171875, 5.205150604248046875, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+148, 134137, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 3984.392333984375, -1353.49658203125, 143.367889404296875, 3.102281093597412109, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Temple Attendant (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+149, 139799, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 4010.859375, -1112.43408203125, 105.714996337890625, 5.849208831787109375, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Ironhull Apprentice (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+150, 140999, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3962.908935546875, -1254.4132080078125, 140.587554931640625, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Shrine's Breath (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+151, 139800, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 4010.7041015625, -1109.5, 105.714996337890625, 5.74587249755859375, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Galecaller Apprentice (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+152, 141585, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3979.661376953125, -1299.525390625, 140.35791015625, 4.913225650787353515, 7200, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Sea Louse (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+153, 134137, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 3971.247314453125, -1303.5, 140.438690185546875, 4.012172222137451171, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Temple Attendant (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+154, 139799, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 4015.80126953125, -1106.092041015625, 105.714996337890625, 5.504992485046386718, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Ironhull Apprentice (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+155, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3970.8330078125, -1218.75, 132.74560546875, 3.651011466979980468, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+156, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3975, -1281.771484375, 140.359466552734375, 5.953692913055419921, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+157, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3968.577880859375, -1218.732666015625, 132.724639892578125, 2.265676021575927734, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+158, 134139, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 3982.1455078125, -1311.2025146484375, 140.3595733642578125, 5.011882781982421875, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Shrine Templar (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+159, 136186, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 3970.482666015625, -1295.2396240234375, 141.085968017578125, 1.272714018821716308, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Spiritualist (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+160, 139800, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 4013.085205078125, -1107.0728759765625, 105.714996337890625, 5.611127376556396484, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Galecaller Apprentice (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+161, 134137, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 3974.2666015625, -1306.3038330078125, 140.452056884765625, 3.958969593048095703, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Temple Attendant (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+162, 140999, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3973.9609375, -1270.126708984375, 143.74188232421875, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Shrine's Breath (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+163, 136249, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3995.302978515625, -1095.8941650390625, 107.6388092041015625, 5.603456974029541015, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Guardian Elemental (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+164, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3953.103759765625, -1245.3638916015625, 127.8736343383789062, 0.678323984146118164, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+165, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3941.920654296875, -1235.295166015625, 128.29498291015625, 2.714607000350952148, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display))
(@CGUID+166, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3950.53759765625, -1240.979736328125, 128.127166748046875, 4.337306499481201171, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display))
(@CGUID+167, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3945.236572265625, -1239.9053955078125, 128.2762298583984375, 4.538245201110839843, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display))
(@CGUID+168, 140999, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3950.38623046875, -1212.8507080078125, 160.608917236328125, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Shrine's Breath (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 275640 - Shrine's Breath)
(@CGUID+169, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3952.2177734375, -1237.51708984375, 127.9056243896484375, 6.118239879608154296, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+170, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3947.3603515625, -1180.6910400390625, 120.4462661743164062, 1.840839743614196777, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display), 271037 - Storm Ritual)
(@CGUID+171, 139986, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3938.001708984375, -1242.673583984375, 153.079803466796875, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Shrine of the Storm (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+172, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3948.60791015625, -1228.8316650390625, 128.305084228515625, 1.598112702369689941, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display))
(@CGUID+173, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3951.03466796875, -1251.2862548828125, 128.031341552734375, 1.152483224868774414, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display))
(@CGUID+174, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3947.061767578125, -1196.8228759765625, 120.4462661743164062, 1.4987412691116333, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display), 271037 - Storm Ritual)
(@CGUID+175, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3950.709716796875, -1235.42041015625, 128.0408172607421875, 5.788081645965576171, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display))
(@CGUID+176, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3948.279052734375, -1254.5057373046875, 128.0748291015625, 0.32232832908630371, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display))
(@CGUID+177, 140999, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3955.4375, -1221.4583740234375, 140.6335906982421875, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Shrine's Breath (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 275640 - Shrine's Breath)
(@CGUID+178, 136214, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 3948.75, -1191.0208740234375, 120.446258544921875, 1.979272007942199707, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Windspeaker Heldis (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 268195 - Wind Ritual)
(@CGUID+179, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3945.412841796875, -1244.8616943359375, 128.178070068359375, 1.834274053573608398, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display))
(@CGUID+180, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3951.861328125, -1237.6656494140625, 127.8838577270507812, 5.718733787536621093, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display))
(@CGUID+181, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3953.5, -1184.5399169921875, 120.4462661743164062, 1.928763031959533691, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display), 271037 - Storm Ritual)
(@CGUID+182, 134137, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 3975.5947265625, -1353.248291015625, 143.367889404296875, 6.201973915100097656, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Temple Attendant (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+183, 140999, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3951.530517578125, -1218.3992919921875, 152.2670745849609375, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Shrine's Breath (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 275640 - Shrine's Breath)
(@CGUID+184, 134173, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3945.689208984375, -1229.4990234375, 127.974945068359375, 5.037024497985839843, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Animated Droplet (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display))
(@CGUID+185, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3953.182373046875, -1059.704833984375, 101.1352996826171875, 1.714236259460449218, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+186, 139800, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 3980.651123046875, -1059.5347900390625, 100.4354095458984375, 2.845263481140136718, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Galecaller Apprentice (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+187, 139800, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 3937.68310546875, -1091.328125, 99.810302734375, 0.555799603462219238, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Galecaller Apprentice (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 274649 - Cosmetic Wind State)
(@CGUID+188, 139799, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 3939.84814453125, -1092.0504150390625, 99.90003204345703125, 1.749951958656311035, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Ironhull Apprentice (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+189, 134137, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 3978.788330078125, -1055.951416015625, 100.2795486450195312, 4.615206718444824218, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Temple Attendant (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+190, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3963.069580078125, -1045.451416015625, 104.7921829223632812, 2.754341363906860351, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+191, 139800, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 3937.5234375, -1088.736083984375, 99.50278472900390625, 5.649913311004638671, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Galecaller Apprentice (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 274649 - Cosmetic Wind State)
(@CGUID+192, 141585, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3945.979736328125, -1101.1702880859375, 100.64532470703125, 3.909065485000610351, 7200, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Sea Louse (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+193, 140999, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3918.482666015625, -1179.9635009765625, 124.4574127197265625, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Shrine's Breath (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+194, 139800, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 3927.765625, -1195.611083984375, 119.9900741577148437, 1.790092706680297851, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Galecaller Apprentice (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+195, 139737, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3912.140625, -1247.8802490234375, 130.68328857421875, 3.335572481155395507, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Lord Stormsong (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+196, 139800, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 3951.873291015625, -1084.2222900390625, 99.65808868408203125, 3.494037389755249023, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Galecaller Apprentice (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+197, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3941.559814453125, -1192.87158203125, 120.4462661743164062, 1.337752699851989746, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+198, 141585, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3972.6025390625, -1066.33837890625, 99.8805389404296875, 5.16701507568359375, 7200, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Sea Louse (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+199, 134137, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 3980.838623046875, -1056.954833984375, 100.6019287109375, 3.830660104751586914, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Temple Attendant (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+200, 139799, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 3957.48583984375, -1056.9583740234375, 102.38177490234375, 2.703427314758300781, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Ironhull Apprentice (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+201, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3965.361083984375, -1043.2603759765625, 104.6702651977539062, 2.886230707168579101, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+202, 139800, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 3923.98779296875, -1196.5833740234375, 119.977325439453125, 1.790092706680297851, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Galecaller Apprentice (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+203, 139800, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 3958.585205078125, -1054.8524169921875, 102.8983917236328125, 2.609553098678588867, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Galecaller Apprentice (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 274649 - Cosmetic Wind State) (possible waypoints or random movement)
(@CGUID+204, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3959.388916015625, -1050.5885009765625, 104.1115493774414062, 2.442286491394042968, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+205, 139799, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 3952.556884765625, -1085.9962158203125, 99.67359161376953125, 3.52524733543395996, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Ironhull Apprentice (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+206, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3960.65966796875, -1047.5972900390625, 104.9827728271484375, 2.603823184967041015, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+207, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3927.494873046875, -1041.798583984375, 105.2430496215820312, 3.268650531768798828, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+208, 141585, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3936.710693359375, -1083.386962890625, 99.0567626953125, 6.193370819091796875, 7200, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Sea Louse (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+209, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3965.765625, -1024.748291015625, 109.5659866333007812, 3.551182031631469726, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display))
(@CGUID+210, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3947.397705078125, -1023.048583984375, 109.25689697265625, 2.288646697998046875, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display))
(@CGUID+211, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3928.487060546875, -1038.3680419921875, 105.5059432983398437, 3.419735670089721679, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+212, 134058, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 3945.271728515625, -1001.4617919921875, 109.4021377563476562, 4.444855213165283203, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Galecaller Faye (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+213, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3949.85595703125, -1020.33160400390625, 109.0369186401367187, 2.288646697998046875, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display))
(@CGUID+214, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3970.703125, -1034.2222900390625, 107.61419677734375, 3.551182031631469726, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+215, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3944.7978515625, -1057.0989990234375, 101.4730148315429687, 1.15289306640625, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+216, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3929.0791015625, -1049.0347900390625, 104.80450439453125, 2.927174091339111328, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display), 271037 - Storm Ritual)
(@CGUID+217, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3968.859375, -1031.0538330078125, 107.9261322021484375, 3.551182031631469726, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+218, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3948.184814453125, -1059.1788330078125, 101.037628173828125, 1.40310823917388916, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+219, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3927.72216796875, -1045.4375, 105.1473770141601562, 3.087558269500732421, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+220, 141585, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3917.403076171875, -1108.8533935546875, 110.771820068359375, 5.562244415283203125, 7200, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Sea Louse (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+221, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3967.484375, -1028.095458984375, 108.2100830078125, 3.551182031631469726, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+222, 134417, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 3900.036376953125, -1106.71875, 110.8449630737304687, 4.734900951385498046, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Deepsea Ritualist (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 268305 - Void Form, 274285 - Void Channel)
(@CGUID+223, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3952.2587890625, -1018.11981201171875, 109.3056488037109375, 2.288646697998046875, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display))
(@CGUID+224, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3930.0400390625, -1021.1475830078125, 109.1142425537109375, 0.767486274242401123, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+225, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3942.20751953125, -1054.732666015625, 102.27105712890625, 0.915905296802520751, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display), 271037 - Storm Ritual)
(@CGUID+226, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3954.928955078125, -1015.473876953125, 109.3056488037109375, 2.288646697998046875, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display))
(@CGUID+227, 139572, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3895.123291015625, -1122.7222900390625, 114.0807037353515625, 4.656858444213867187, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Murky Water (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 274152 - Murky Water)
(@CGUID+228, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3932.81689453125, -1023.68402099609375, 109.3056488037109375, 0.767486274242401123, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+229, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3924.876708984375, -1016.5382080078125, 109.03692626953125, 0.767486274242401123, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display))
(@CGUID+230, 121028, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3621.981689453125, -1392.4600830078125, 323.645843505859375, 0.471368849277496337, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Cove Seagull (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+231, 136347, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3927.71533203125, -1018.859375, 109.03692626953125, 0.767486274242401123, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Initiate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+232, 134063, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 3930.0234375, -1002.765625, 109.3061676025390625, 4.975560188293457031, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Brother Ironhull (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+233, 134417, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 3851.893310546875, -1077.6978759765625, 109.9453887939453125, 0.053565755486488342, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Deepsea Ritualist (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+234, 139986, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3939.920166015625, -1007.33331298828125, 124.6382293701171875, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Shrine of the Storm (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+235, 134417, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 1, 3838.5400390625, -1126.1007080078125, 106.3933792114257812, 5.221284866333007812, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Deepsea Ritualist (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+236, 140999, 1864, 9525, 9525, '1,2,23,8', 0, 0, 0, 0, 3895.1171875, -1122.5382080078125, 114.5282135009765625, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Shrine's Breath (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@CGUID+237, 134418, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 1, 3781.033935546875, -1106.017333984375, 109.1317138671875, 2.257657527923583984, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Drowned Depthbringer (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1
(@CGUID+238, 139626, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3903.29248046875, -1100.3975830078125, 110.8449630737304687, 4.158064842224121093, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Dredged Sailor (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1
(@CGUID+239, 139626, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3891.5546875, -1101.279541015625, 110.852752685546875, 5.647693157196044921, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Dredged Sailor (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1
(@CGUID+240, 134418, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 1, 3771.84716796875, -1102.513916015625, 109.1235122680664062, 1.671818494796752929, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Drowned Depthbringer (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1
(@CGUID+241, 139626, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3897.779541015625, -1099, 110.8517227172851562, 5.078906059265136718, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Dredged Sailor (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1
(@CGUID+242, 139626, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3884.90185546875, -1102.045166015625, 110.2088470458984375, 5.904230117797851562, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Dredged Sailor (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1
(@CGUID+243, 141585, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3874.283935546875, -1091.564208984375, 109.9068450927734375, 2.693005084991455078, 7200, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Sea Louse (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1
(@CGUID+244, 134514, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 1, 3690.4384765625, -1255.357666015625, 155.388031005859375, 1.109372735023498535, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyssal Cultist (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1 (Auras: 123169 - Mod Scale 105-110%, 268312 - Shifting Guise, 274285 - Void Channel)
(@CGUID+245, 139626, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3845.552001953125, -1118.3489990234375, 106.3389358520507812, 3.966567516326904296, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Dredged Sailor (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display), 274210 - Reanimated Bones)
(@CGUID+246, 134514, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 1, 3682.262939453125, -1250.9271240234375, 155.3861541748046875, 1.109372735023498535, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyssal Cultist (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1 (Auras: 123169 - Mod Scale 105-110%, 268312 - Shifting Guise, 274285 - Void Channel)
(@CGUID+247, 139626, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3846.91748046875, -1121.91845703125, 106.3933792114257812, 3.564596891403198242, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Dredged Sailor (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1
(@CGUID+248, 141585, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3841.999267578125, -1125.5615234375, 106.2819366455078125, 3.044297695159912109, 7200, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Sea Louse (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1
(@CGUID+249, 134338, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 1, 3849.9267578125, -1107.7745361328125, 106.4809341430664062, 0.166612669825553894, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Enforcer (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1 (Auras: 139880 - Mod Scale -10% [DNT]; 18950 - Invisibility and Stealth Detection) (possible waypoints or random movement)
(@CGUID+250, 134514, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 1, 3678.2021484375, -1276.4647216796875, 156.482391357421875, 1.076502203941345214, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyssal Cultist (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1 (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+251, 134418, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 1, 3677.522705078125, -1281.45654296875, 156.537353515625, 1.034649491310119628, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Drowned Depthbringer (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%) (possible waypoints or random movement)
(@CGUID+252, 139626, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3837.81591796875, -1120.1041259765625, 106.3933792114257812, 4.772692680358886718, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Dredged Sailor (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1
(@CGUID+253, 141585, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3873.643310546875, -1074.00927734375, 109.771820068359375, 0.607115507125854492, 7200, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Sea Louse (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1
(@CGUID+254, 139626, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3840.47998046875, -1116.5347900390625, 106.3933792114257812, 4.741472721099853515, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Dredged Sailor (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1
(@CGUID+255, 139626, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3861.536376953125, -1079.16845703125, 109.7572479248046875, 2.987401008605957031, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Dredged Sailor (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1
(@CGUID+256, 134338, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 1, 3853.36279296875, -1080.7864990234375, 109.8876953125, 0.292337864637374877, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Enforcer (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1
(@CGUID+257, 139626, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3832.479248046875, -1121.5572509765625, 106.3933792114257812, 5.674550533294677734, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Dredged Sailor (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1
(@CGUID+258, 139626, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3858.865478515625, -1071.4600830078125, 109.7009429931640625, 3.813285112380981445, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Dredged Sailor (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1
(@CGUID+259, 139626, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3858.817626953125, -1082.35595703125, 109.7102127075195312, 2.493849515914916992, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Dredged Sailor (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1
(@CGUID+260, 139626, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3857.65283203125, -1079.62158203125, 109.8260879516601562, 2.832808732986450195, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Dredged Sailor (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1
(@CGUID+261, 139626, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3860.734375, -1075.796875, 109.75042724609375, 3.324360132217407226, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Dredged Sailor (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1
(@CGUID+262, 139626, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3857.0166015625, -1076.904541015625, 109.8426589965820312, 3.253761529922485351, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Dredged Sailor (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1
(@CGUID+263, 139626, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3857.265625, -1073.6146240234375, 109.7684326171875, 3.717751026153564453, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Dredged Sailor (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1
(@CGUID+264, 139626, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3832.678955078125, -1126.0816650390625, 106.3933792114257812, 6.24051523208618164, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Dredged Sailor (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1
(@CGUID+265, 134338, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 1, 3851.564208984375, -1073.998291015625, 109.8697357177734375, 6.107105731964111328, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Enforcer (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1
(@CGUID+266, 139626, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3854.663330078125, -1070, 109.6712722778320312, 4.401516914367675781, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Dredged Sailor (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1
(@CGUID+267, 134514, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 1, 3663.37060546875, -1284.1968994140625, 156.5323944091796875, 1.108304500579833984, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyssal Cultist (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1 (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+268, 134338, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 1, 3819.44091796875, -1111.390625, 110.0628128051757812, 5.794187545776367187, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Enforcer (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+269, 134338, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 1, 3816.2890625, -1116.6302490234375, 110.0628128051757812, 5.867093563079833984, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Tidesage Enforcer (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+270, 134418, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 1, 3659.478271484375, -1287.0277099609375, 156.4750518798828125, 1.088109970092773437, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Drowned Depthbringer (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%) (possible waypoints or random movement)
(@CGUID+271, 134514, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 1, 3656.96435546875, -1325.15234375, 156.7298126220703125, 4.344125747680664062, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyssal Cultist (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1 (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+272, 134514, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 1, 3654.875732421875, -1320.775634765625, 156.4170684814453125, 4.459706306457519531, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyssal Cultist (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1 (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+273, 134418, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 1, 3661.560791015625, -1291.2481689453125, 156.3990936279296875, 1.119274258613586425, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Drowned Depthbringer (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%) (possible waypoints or random movement)
(@CGUID+274, 134418, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 1, 3657.686279296875, -1292.2078857421875, 156.3765411376953125, 1.081828594207763671, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Drowned Depthbringer (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%) (possible waypoints or random movement)
(@CGUID+275, 134069, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3655.05029296875, -1749.060791015625, 85.58869171142578125, 5.550147056579589843, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Vol'zith the Whisperer (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1 (Auras: 267255 - Void Energy)
(@CGUID+276, 134423, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3616.567626953125, -1415.7725830078125, 159.2978363037109375, 3.904282093048095703, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display), 274305 - Shifting Guise)
(@CGUID+277, 141585, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3736.4599609375, -1157.7269287109375, 126.7871246337890625, 3.205129146575927734, 7200, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Sea Louse (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+278, 141585, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3720.671142578125, -1195.317626953125, 142.0350799560546875, 5.302701950073242187, 7200, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Sea Louse (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+279, 141585, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3746.724365234375, -1138.6922607421875, 118.6909027099609375, 4.108569145202636718, 7200, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Sea Louse (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+280, 134423, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3618.029541015625, -1418.63720703125, 159.3959197998046875, 3.904282093048095703, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display), 274305 - Shifting Guise)
(@CGUID+281, 134423, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3613.14501953125, -1420.8055419921875, 159.2978363037109375, 3.904282093048095703, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display), 274305 - Shifting Guise)
(@CGUID+282, 134423, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3616.927001953125, -1426.12158203125, 159.28125, 3.904282093048095703, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display), 274305 - Shifting Guise)
(@CGUID+283, 134423, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3611.6103515625, -1418.0416259765625, 159.3446044921875, 3.904282093048095703, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display), 274305 - Shifting Guise)
(@CGUID+284, 134423, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3613.7421875, -1414.107666015625, 159.2978363037109375, 3.904282093048095703, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display), 274305 - Shifting Guise)
(@CGUID+285, 134423, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3613.012939453125, -1411.5069580078125, 159.2978363037109375, 3.904282093048095703, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display), 274305 - Shifting Guise)
(@CGUID+286, 134423, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3615.6650390625, -1422.5069580078125, 159.2978363037109375, 3.904282093048095703, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display), 274305 - Shifting Guise)
(@CGUID+287, 134423, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3605.125, -1430.5521240234375, 159.5108489990234375, 3.904282093048095703, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display), 274305 - Shifting Guise)
(@CGUID+288, 134423, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3609.134521484375, -1427.59375, 159.392547607421875, 3.904282093048095703, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display), 274305 - Shifting Guise)
(@CGUID+289, 134423, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3603.244873046875, -1427.638916015625, 159.5439605712890625, 3.904282093048095703, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display), 274305 - Shifting Guise)
(@CGUID+290, 134423, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3606.4921875, -1425.74658203125, 159.4306488037109375, 3.904282093048095703, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display), 274305 - Shifting Guise)
(@CGUID+291, 134423, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3608.837646484375, -1435.7569580078125, 159.5054931640625, 3.904282093048095703, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display), 274305 - Shifting Guise)
(@CGUID+292, 134423, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3607.506103515625, -1432.0103759765625, 159.482818603515625, 3.904282093048095703, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display), 274305 - Shifting Guise)
(@CGUID+293, 134423, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3610.666748046875, -1430.6129150390625, 159.3794403076171875, 3.904282093048095703, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display), 274305 - Shifting Guise)
(@CGUID+294, 134423, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3605.318603515625, -1422.6319580078125, 159.369232177734375, 3.904282093048095703, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display), 274305 - Shifting Guise)
(@CGUID+295, 134423, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3593.02783203125, -1402.16845703125, 159.2978363037109375, 4.772433757781982421, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display), 274305 - Shifting Guise)
(@CGUID+296, 134423, 1864, 9525, 9964, '1,2,23,8', 0, 0, 0, 0, 3589.6025390625, -1400.8125, 159.3114471435546875, 4.772433757781982421, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display), 274305 - Shifting Guise)
(@CGUID+297, 140038, 1864, 9525, 10003, '1,2,23,8', 0, 0, 0, 0, 3665.68896484375, -1644.2724609375, 64.75372314453125, 4.977624893188476562, 7200, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Abyssal Eel (Area: Shrine of Shadows - Difficulty: Heroic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+298, 134423, 1864, 9525, 9963, '1,2,23,8', 0, 0, 0, 0, 3583.829833984375, -1401.2603759765625, 159.438507080078125, 4.772433757781982421, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: Fonts of Cleansing - Difficulty: Mythic) CreateObject1
(@CGUID+299, 134423, 1864, 9525, 9963, '1,2,23,8', 0, 0, 0, 0, 3588.458251953125, -1407.4600830078125, 159.2978363037109375, 4.772433757781982421, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: Fonts of Cleansing - Difficulty: Mythic) CreateObject1
(@CGUID+300, 134423, 1864, 9525, 9963, '1,2,23,8', 0, 0, 0, 0, 3586.54248046875, -1401.5989990234375, 159.3737335205078125, 4.772433757781982421, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: Fonts of Cleansing - Difficulty: Mythic) CreateObject1
(@CGUID+301, 134423, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3584.65625, -1407.13720703125, 159.36627197265625, 4.772433757781982421, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+302, 134423, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3581.036376953125, -1413.3785400390625, 159.3903045654296875, 4.772433757781982421, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+303, 134423, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3578.62158203125, -1413.9097900390625, 159.5181427001953125, 4.772433757781982421, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+304, 134423, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3584.70654296875, -1418.8541259765625, 159.2978515625, 4.772433757781982421, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+305, 134423, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3587.614501953125, -1414.26220703125, 159.2978515625, 4.772433757781982421, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+306, 134423, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3581.837646484375, -1406.0677490234375, 159.470001220703125, 4.772433757781982421, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+307, 134423, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3584.052978515625, -1413.970458984375, 159.2978363037109375, 4.772433757781982421, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+308, 134423, 1864, 9525, 9963, '1,2,23,8', 0, 0, 0, 0, 3579.173583984375, -1406.9114990234375, 159.6786651611328125, 4.772433757781982421, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: Fonts of Cleansing - Difficulty: Mythic) CreateObject1
(@CGUID+309, 134423, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3579.123291015625, -1417.7603759765625, 159.3697662353515625, 4.772433757781982421, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+310, 134423, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3581.731689453125, -1418.923583984375, 159.3123779296875, 4.772433757781982421, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+311, 134423, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3576.291748046875, -1417.826416015625, 159.455841064453125, 4.772433757781982421, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+312, 141585, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3652.382568359375, -1354.5264892578125, 156.650543212890625, 5.383687496185302734, 7200, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Sea Louse (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+313, 141585, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3613.981201171875, -1340.1529541015625, 156.6162261962890625, 1.797223329544067382, 7200, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Sea Louse (Area: 0 - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+314, 134423, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3515.712646484375, -1389.111083984375, 77.59033203125, 2.778744459152221679, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: 0 - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display), 274305 - Shifting Guise)
(@CGUID+315, 134423, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3511.3203125, -1396.375, 77.59033203125, 2.778744459152221679, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+316, 134423, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3512.4921875, -1393.6180419921875, 77.59033203125, 2.778744459152221679, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+317, 134423, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3514.6171875, -1391.7257080078125, 77.59033203125, 2.778744459152221679, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+318, 134423, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3507.70654296875, -1403.0867919921875, 77.59033203125, 2.778744459152221679, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: 0 - Difficulty: Mythic) CreateObject1 (Auras: 281206 - Force Low LOD (Do Not Translate, No Display), 274305 - Shifting Guise)
(@CGUID+319, 134423, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3506.611083984375, -1405.701416015625, 77.59033203125, 2.778744459152221679, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+320, 134423, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3503.314208984375, -1410.3507080078125, 77.59033203125, 2.778744459152221679, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+321, 134423, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3504.486083984375, -1407.59375, 77.59033203125, 2.778744459152221679, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+322, 134423, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3499.530517578125, -1418.0677490234375, 77.59033203125, 2.778744459152221679, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+323, 134423, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3496.309814453125, -1422.57470703125, 77.59033203125, 2.778744459152221679, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+324, 134423, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3498.434814453125, -1420.6822509765625, 77.59033203125, 2.778744459152221679, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+325, 134423, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3495.137939453125, -1425.3316650390625, 77.59033203125, 2.778744459152221679, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Abyss Dweller (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+326, 141587, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3612.9169921875, -1401.010498046875, 160.08612060546875, 1.016396403312683105, 7200, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Rat (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+327, 141587, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3598.32373046875, -1386.7760009765625, 159.2978515625, 0, 7200, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Rat (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+328, 134060, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 1, 3545.822021484375, -1511.342041015625, 154.316314697265625, 4.212737560272216796, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Lord Stormsong (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+329, 141587, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3588.12646484375, -1445.6563720703125, 158.9885101318359375, 4.745127677917480468, 7200, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Rat (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+330, 136363, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3517.14404296875, -1519.3468017578125, 82.19756317138671875, 5.251199722290039062, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Jellyfish (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+331, 139963, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 1, 3534.107666015625, -1533.904541015625, 154.3650665283203125, 1.068818092346191406, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Queen Azshara (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+332, 136961, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3560.611083984375, -1444.517333984375, 145.8678436279296875, 1.410063385963439941, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Waken the Void (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+333, 136363, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3514.760498046875, -1531.244384765625, 90.58629608154296875, 5.421474456787109375, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Jellyfish (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+334, 136961, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3596.470458984375, -1467.1771240234375, 144.3021087646484375, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Waken the Void (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+335, 136961, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3609.30029296875, -1464.76220703125, 143.643829345703125, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Waken the Void (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+336, 136961, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3603.3984375, -1474.34375, 143.6918182373046875, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Waken the Void (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+337, 136961, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3543.25439453125, -1439.3333740234375, 145.8678436279296875, 1.410063385963439941, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Waken the Void (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+338, 136961, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3531.869873046875, -1440.951416015625, 145.8678436279296875, 1.410063385963439941, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Waken the Void (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+339, 136961, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3548.267333984375, -1445.87158203125, 145.8678436279296875, 1.410063385963439941, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Waken the Void (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+340, 136961, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3607.07373046875, -1481.736083984375, 144.1658782958984375, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Waken the Void (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+341, 136363, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3496.004638671875, -1532.0655517578125, 78.302703857421875, 2.760146141052246093, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Jellyfish (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+342, 136961, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3612.720458984375, -1475.7413330078125, 143.691558837890625, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Waken the Void (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+343, 136363, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3506.979248046875, -1532.5538330078125, 76.4490966796875, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Jellyfish (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+344, 136363, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3489.973388671875, -1528.2149658203125, 69.0149688720703125, 0.549302220344543457, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Jellyfish (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+345, 136961, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3540.3837890625, -1448.3125, 145.8678436279296875, 1.410063385963439941, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Waken the Void (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+346, 136961, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3532.19873046875, -1454.0035400390625, 145.8678436279296875, 1.410063385963439941, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Waken the Void (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+347, 136363, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3480.660888671875, -1541.0457763671875, 88.75455474853515625, 4.116929531097412109, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Jellyfish (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+348, 136363, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3444.71435546875, -1543.515625, 70.23378753662109375, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Jellyfish (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+349, 141016, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3528.682373046875, -1507.4791259765625, 154.275665283203125, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Shrine's Breath (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+350, 141016, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3559.6181640625, -1523.15283203125, 154.275665283203125, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Shrine's Breath (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+351, 136961, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3539.572998046875, -1532.4132080078125, 148.5007171630859375, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Waken the Void (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+352, 82347, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3536.721435546875, -1528.46875, 153.527740478515625, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Stalker (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+353, 136363, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3486.9248046875, -1610.7833251953125, 88.001800537109375, 5.351438522338867187, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Jellyfish (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+354, 136961, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3528.564208984375, -1528.3055419921875, 148.8274993896484375, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Waken the Void (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+355, 136961, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3536.380126953125, -1527.3367919921875, 148.5007171630859375, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Waken the Void (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+356, 136363, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3450.279541015625, -1577.6019287109375, 68.71671295166015625, 1.474952220916748046, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Jellyfish (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+357, 136961, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3533.427978515625, -1532.763916015625, 148.6944427490234375, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Waken the Void (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+358, 136961, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3536.088623046875, -1523.1319580078125, 148.5007171630859375, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Waken the Void (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+359, 136961, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3542.986083984375, -1525.888916015625, 148.5007171630859375, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Waken the Void (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+360, 136363, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3441.3134765625, -1597.9583740234375, 78.962615966796875, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Jellyfish (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+361, 136363, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3481.92578125, -1634.6893310546875, 62.34993362426757812, 5.565263271331787109, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Jellyfish (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+362, 136363, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3443.393310546875, -1620.0850830078125, 68.20328521728515625, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Jellyfish (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+363, 136295, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3619.739501953125, -1709.1788330078125, 86.14837646484375, 2.774871110916137695, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Sunken Denizen (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+364, 136297, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3617.2509765625, -1718.0833740234375, 85.7364501953125, 2.196255683898925781, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Forgotten Denizen (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+365, 136297, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3627.893310546875, -1711.6302490234375, 85.73644256591796875, 2.196255683898925781, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Forgotten Denizen (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+366, 139986, 1864, 9525, 0, '1,2,23,8', 0, 0, 0, 0, 3631.747314453125, -1728.814208984375, 104.554168701171875, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54630), -- Shrine of the Storm (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+367, 140038, 1864, 9525, 10003, '1,2,23,8', 0, 0, 0, 0, 3580.83154296875, -1651.1273193359375, 70.77420806884765625, 1.883231878280639648, 7200, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Abyssal Eel (Area: Shrine of Shadows - Difficulty: Heroic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+368, 140038, 1864, 9525, 10003, '1,2,23,8', 0, 0, 0, 0, 3547.19921875, -1733.708740234375, 75.39160919189453125, 0.52678614854812622, 7200, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Abyssal Eel (Area: Shrine of Shadows - Difficulty: Heroic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+369, 140038, 1864, 9525, 10003, '1,2,23,8', 0, 0, 0, 0, 3535.18994140625, -1689.5709228515625, 76.215362548828125, 3.949308156967163085, 7200, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Abyssal Eel (Area: Shrine of Shadows - Difficulty: Heroic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+370, 140038, 1864, 9525, 10003, '1,2,23,8', 0, 0, 0, 0, 3555.123046875, -1675.6553955078125, 76.44791412353515625, 4.941031455993652343, 7200, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Abyssal Eel (Area: Shrine of Shadows - Difficulty: Heroic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+371, 140038, 1864, 9525, 10003, '1,2,23,8', 0, 0, 0, 0, 3548.63134765625, -1747.7950439453125, 76.86957550048828125, 1.338196516036987304, 7200, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Abyssal Eel (Area: Shrine of Shadows - Difficulty: Heroic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+372, 140038, 1864, 9525, 10003, '1,2,23,8', 0, 0, 0, 0, 3555.24951171875, -1682.5208740234375, 73.95786285400390625, 1.773516774177551269, 7200, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Abyssal Eel (Area: Shrine of Shadows - Difficulty: Heroic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+373, 140038, 1864, 9525, 10003, '1,2,23,8', 0, 0, 0, 0, 3610.54248046875, -1654.1724853515625, 70.29721832275390625, 2.066353797912597656, 7200, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Abyssal Eel (Area: Shrine of Shadows - Difficulty: Heroic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+374, 140038, 1864, 9525, 10003, '1,2,23,8', 0, 0, 0, 0, 3535.016845703125, -1737.9007568359375, 77.21622467041015625, 0.23104637861251831, 7200, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Abyssal Eel (Area: Shrine of Shadows - Difficulty: Heroic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+375, 140038, 1864, 9525, 10003, '1,2,23,8', 0, 0, 0, 0, 3563.06103515625, -1678.58447265625, 72.963287353515625, 4.582669258117675781, 7200, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Abyssal Eel (Area: Shrine of Shadows - Difficulty: Heroic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+376, 140038, 1864, 9525, 10003, '1,2,23,8', 0, 0, 0, 0, 3596.193359375, -1648.5389404296875, 72.7309112548828125, 2.971310615539550781, 7200, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Abyssal Eel (Area: Shrine of Shadows - Difficulty: Heroic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+377, 140038, 1864, 9525, 10003, '1,2,23,8', 0, 0, 0, 0, 3607.229248046875, -1645.6170654296875, 70.71533966064453125, 4.063070297241210937, 7200, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Abyssal Eel (Area: Shrine of Shadows - Difficulty: Heroic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+378, 140038, 1864, 9525, 10003, '1,2,23,8', 0, 0, 0, 0, 3585.33740234375, -1656.7940673828125, 61.41035842895507812, 5.906122207641601562, 7200, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Abyssal Eel (Area: Shrine of Shadows - Difficulty: Heroic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+379, 140038, 1864, 9525, 10003, '1,2,23,8', 0, 0, 0, 0, 3547.6630859375, -1687.481201171875, 75.95259857177734375, 1.925763130187988281, 7200, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Abyssal Eel (Area: Shrine of Shadows - Difficulty: Heroic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+380, 140038, 1864, 9525, 10003, '1,2,23,8', 0, 0, 0, 0, 3565.22998046875, -1684.53076171875, 69.89453887939453125, 3.416249752044677734, 7200, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Abyssal Eel (Area: Shrine of Shadows - Difficulty: Heroic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+381, 140038, 1864, 9525, 10003, '1,2,23,8', 0, 0, 0, 0, 3601.935302734375, -1646.5238037109375, 73.95009613037109375, 4.299059867858886718, 7200, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Abyssal Eel (Area: Shrine of Shadows - Difficulty: Heroic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+382, 140038, 1864, 9525, 10003, '1,2,23,8', 0, 0, 0, 0, 3540.67333984375, -1681.9378662109375, 76.470489501953125, 3.755388736724853515, 7200, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Abyssal Eel (Area: Shrine of Shadows - Difficulty: Heroic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+383, 140038, 1864, 9525, 10003, '1,2,23,8', 0, 0, 0, 0, 3594.856689453125, -1658.3472900390625, 70.68587493896484375, 3.819964885711669921, 7200, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Abyssal Eel (Area: Shrine of Shadows - Difficulty: Heroic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+384, 140038, 1864, 9525, 10003, '1,2,23,8', 0, 0, 0, 0, 3539.39404296875, -1744.4256591796875, 78.24533843994140625, 2.173897266387939453, 7200, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Abyssal Eel (Area: Shrine of Shadows - Difficulty: Heroic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+385, 140038, 1864, 9525, 10003, '1,2,23,8', 0, 0, 0, 0, 3566.20458984375, -1668.09423828125, 66.11704254150390625, 2.055775165557861328, 7200, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Abyssal Eel (Area: Shrine of Shadows - Difficulty: Heroic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+386, 140038, 1864, 9525, 10003, '1,2,23,8', 0, 0, 0, 0, 3552.502685546875, -1761.4383544921875, 79.69622039794921875, 4.864660263061523437, 7200, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Abyssal Eel (Area: Shrine of Shadows - Difficulty: Heroic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+387, 140038, 1864, 9525, 10003, '1,2,23,8', 0, 0, 0, 0, 3655.371826171875, -1643.4346923828125, 64.566680908203125, 4.936341285705566406, 7200, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Abyssal Eel (Area: Shrine of Shadows - Difficulty: Heroic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+388, 140038, 1864, 9525, 10003, '1,2,23,8', 0, 0, 0, 0, 3611.93212890625, -1638.4779052734375, 72.0477447509765625, 4.933104515075683593, 7200, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Abyssal Eel (Area: Shrine of Shadows - Difficulty: Heroic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+389, 140038, 1864, 9525, 10003, '1,2,23,8', 0, 0, 0, 0, 3540.795654296875, -1753.9468994140625, 80.52072906494140625, 4.403945446014404296, 7200, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Abyssal Eel (Area: Shrine of Shadows - Difficulty: Heroic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+390, 140038, 1864, 9525, 10003, '1,2,23,8', 0, 0, 0, 0, 3652.558837890625, -1656.752685546875, 64.74826812744140625, 4.744365215301513671, 7200, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Abyssal Eel (Area: Shrine of Shadows - Difficulty: Heroic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+391, 140038, 1864, 9525, 10003, '1,2,23,8', 0, 0, 0, 0, 3672.50146484375, -1661.3104248046875, 72.9636993408203125, 2.522705554962158203, 7200, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Abyssal Eel (Area: Shrine of Shadows - Difficulty: Heroic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+392, 140038, 1864, 9525, 10003, '1,2,23,8', 0, 0, 0, 0, 3653.53173828125, -1653.9163818359375, 69.21640777587890625, 0.792882800102233886, 7200, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Abyssal Eel (Area: Shrine of Shadows - Difficulty: Heroic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+393, 140038, 1864, 9525, 10003, '1,2,23,8', 0, 0, 0, 0, 3668.2958984375, -1652.43603515625, 68.321136474609375, 4.71620941162109375, 7200, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Abyssal Eel (Area: Shrine of Shadows - Difficulty: Heroic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+394, 140038, 1864, 9525, 10003, '1,2,23,8', 0, 0, 0, 0, 3549.37451171875, -1755.2340087890625, 78.861968994140625, 0.246978715062141418, 7200, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Abyssal Eel (Area: Shrine of Shadows - Difficulty: Heroic) CreateObject1
(@CGUID+395, 140038, 1864, 9525, 10003, '1,2,23,8', 0, 0, 0, 0, 3663.635986328125, -1649.587646484375, 65.5961456298828125, 2.753129243850708007, 7200, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Abyssal Eel (Area: Shrine of Shadows - Difficulty: Heroic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+396, 140038, 1864, 9525, 10003, '1,2,23,8', 0, 0, 0, 0, 3545.78515625, -1754.989990234375, 81.84532928466796875, 1.660209536552429199, 7200, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54630), -- Abyssal Eel (Area: Shrine of Shadows - Difficulty: Heroic) CreateObject1
(@CGUID+397, 140038, 1864, 9525, 10003, '1,2,23,8', 0, 0, 0, 0, 3644.5078125, -1656.222412109375, 65.430572509765625, 2.974705457687377929, 7200, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 54630); -- Abyssal Eel (Area: Shrine of Shadows - Difficulty: Heroic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+397;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Tidesage Initiate
(@CGUID+2, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Tidesage Initiate
(@CGUID+3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '281206'), -- Animated Droplet - 281206 - Force Low LOD (Do Not Translate, No Display)
(@CGUID+5, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Tidesage Initiate
(@CGUID+8, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Tidesage Initiate
(@CGUID+9, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Tidesage Initiate
(@CGUID+11, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Tidesage Initiate
(@CGUID+14, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Tidesage Initiate
(@CGUID+19, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Tidesage Initiate
(@CGUID+21, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '281206'), -- Animated Droplet - 281206 - Force Low LOD (Do Not Translate, No Display)
(@CGUID+55, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '281206'), -- Animated Droplet - 281206 - Force Low LOD (Do Not Translate, No Display)
(@CGUID+60, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '281206'), -- Animated Droplet - 281206 - Force Low LOD (Do Not Translate, No Display)
(@CGUID+66, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '281206'), -- Animated Droplet - 281206 - Force Low LOD (Do Not Translate, No Display)
(@CGUID+73, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Tidesage Initiate
(@CGUID+74, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Tidesage Initiate
(@CGUID+78, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Tidesage Initiate
(@CGUID+79, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 3, ''), -- Temple Attendant
(@CGUID+81, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Tidesage Initiate
(@CGUID+82, 0, 0, 0, 0, 0, 1, 0, 715, 0, 0, 0, 0, ''), -- Ironhull Apprentice
(@CGUID+84, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Tidesage Initiate
(@CGUID+85, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Tidesage Initiate
(@CGUID+86, 0, 0, 0, 0, 0, 1, 0, 715, 0, 0, 0, 0, ''), -- Galecaller Apprentice
(@CGUID+87, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Tidesage Initiate
(@CGUID+88, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Tidesage Initiate
(@CGUID+89, 0, 0, 0, 0, 0, 1, 0, 715, 0, 0, 0, 3, ''), -- Temple Attendant
(@CGUID+92, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 3, ''), -- Temple Attendant
(@CGUID+100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '123169'), -- Temple Attendant - 123169 - Mod Scale 105-110%
(@CGUID+113, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '281206'), -- Tidesage Initiate - 281206 - Force Low LOD (Do Not Translate, No Display)
(@CGUID+115, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '281206'), -- Tidesage Initiate - 281206 - Force Low LOD (Do Not Translate, No Display)
(@CGUID+117, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '281206'), -- Tidesage Initiate - 281206 - Force Low LOD (Do Not Translate, No Display)
(@CGUID+118, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '281206'), -- Tidesage Initiate - 281206 - Force Low LOD (Do Not Translate, No Display)
(@CGUID+128, 0, 0, 0, 0, 0, 1, 0, 716, 0, 0, 0, 0, ''), -- Ironhull Apprentice
(@CGUID+134, 0, 0, 0, 0, 0, 1, 0, 716, 0, 0, 0, 0, ''), -- Ironhull Apprentice
(@CGUID+143, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Temple Attendant
(@CGUID+148, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Temple Attendant
(@CGUID+149, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 0, ''), -- Ironhull Apprentice
(@CGUID+151, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 0, ''), -- Galecaller Apprentice
(@CGUID+154, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 0, ''), -- Ironhull Apprentice
(@CGUID+159, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Tidesage Spiritualist
(@CGUID+160, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 0, ''), -- Galecaller Apprentice
(@CGUID+165, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '281206'), -- Animated Droplet - 281206 - Force Low LOD (Do Not Translate, No Display)
(@CGUID+166, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '281206'), -- Animated Droplet - 281206 - Force Low LOD (Do Not Translate, No Display)
(@CGUID+167, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '281206'), -- Animated Droplet - 281206 - Force Low LOD (Do Not Translate, No Display)
(@CGUID+172, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '281206'), -- Animated Droplet - 281206 - Force Low LOD (Do Not Translate, No Display)
(@CGUID+173, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '281206'), -- Animated Droplet - 281206 - Force Low LOD (Do Not Translate, No Display)
(@CGUID+175, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '281206'), -- Animated Droplet - 281206 - Force Low LOD (Do Not Translate, No Display)
(@CGUID+176, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '281206'), -- Animated Droplet - 281206 - Force Low LOD (Do Not Translate, No Display)
(@CGUID+179, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '281206'), -- Animated Droplet - 281206 - Force Low LOD (Do Not Translate, No Display)
(@CGUID+180, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '281206'), -- Animated Droplet - 281206 - Force Low LOD (Do Not Translate, No Display)
(@CGUID+182, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '123169'), -- Temple Attendant - 123169 - Mod Scale 105-110%
(@CGUID+184, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '281206'), -- Animated Droplet - 281206 - Force Low LOD (Do Not Translate, No Display)
(@CGUID+188, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123169'), -- Ironhull Apprentice - 123169 - Mod Scale 105-110%
(@CGUID+200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123169'), -- Ironhull Apprentice - 123169 - Mod Scale 105-110%
(@CGUID+209, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '281206'), -- Tidesage Initiate - 281206 - Force Low LOD (Do Not Translate, No Display)
(@CGUID+210, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '281206'), -- Tidesage Initiate - 281206 - Force Low LOD (Do Not Translate, No Display)
(@CGUID+213, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '281206'), -- Tidesage Initiate - 281206 - Force Low LOD (Do Not Translate, No Display)
(@CGUID+214, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Tidesage Initiate
(@CGUID+217, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Tidesage Initiate
(@CGUID+221, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Tidesage Initiate
(@CGUID+223, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '281206'), -- Tidesage Initiate - 281206 - Force Low LOD (Do Not Translate, No Display)
(@CGUID+224, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Tidesage Initiate
(@CGUID+226, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '281206'), -- Tidesage Initiate - 281206 - Force Low LOD (Do Not Translate, No Display)
(@CGUID+228, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Tidesage Initiate
(@CGUID+229, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '281206'), -- Tidesage Initiate - 281206 - Force Low LOD (Do Not Translate, No Display)
(@CGUID+230, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- Cove Seagull
(@CGUID+231, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Tidesage Initiate
(@CGUID+237, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '268312'), -- Drowned Depthbringer
(@CGUID+240, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '268312'), -- Drowned Depthbringer
(@CGUID+249, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '139880 18950'), -- Tidesage Enforcer - 139880 - Mod Scale -10% [DNT], 18950 - Invisibility and Stealth Detection
(@CGUID+250, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '123169'), -- Abyssal Cultist - 123169 - Mod Scale 105-110%
(@CGUID+251, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '237007'), -- Drowned Depthbringer - 237007 - Mod Scale 90-100%
(@CGUID+256, 0, 0, 0, 0, 0, 1, 0, 878, 0, 0, 0, 0, ''), -- Tidesage Enforcer
(@CGUID+265, 0, 0, 0, 0, 0, 1, 0, 878, 0, 0, 0, 0, ''), -- Tidesage Enforcer
(@CGUID+267, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '123169'), -- Abyssal Cultist - 123169 - Mod Scale 105-110%
(@CGUID+268, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '18950'), -- Tidesage Enforcer - 18950 - Invisibility and Stealth Detection
(@CGUID+269, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '18950'), -- Tidesage Enforcer - 18950 - Invisibility and Stealth Detection
(@CGUID+270, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '237007'), -- Drowned Depthbringer - 237007 - Mod Scale 90-100%
(@CGUID+271, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '123169'), -- Abyssal Cultist - 123169 - Mod Scale 105-110%
(@CGUID+272, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '123169'), -- Abyssal Cultist - 123169 - Mod Scale 105-110%
(@CGUID+273, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '237007'), -- Drowned Depthbringer - 237007 - Mod Scale 90-100%
(@CGUID+274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '237007'), -- Drowned Depthbringer - 237007 - Mod Scale 90-100%
(@CGUID+343, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, '243685 267955'), -- Jellyfish
(@CGUID+348, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, '243685 267955'), -- Jellyfish
(@CGUID+360, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, '243685 267955'), -- Jellyfish
(@CGUID+362, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, '243685 267955'), -- Jellyfish
(@CGUID+363, 0, 0, 0, 0, 0, 1, 0, 386, 0, 0, 0, 3, ''); -- Sunken Denizen

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+38;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 252248, 1864, 9525, 9525, '1,2,23,8', 0, 0, 4167.8271484375, -1222.1875, 187.685577392578125, 4.739847660064697265, 0, 0, -0.69733238220214843, 0.716747879981994628, 7200, 255, 1, 54630), -- Instance Portal (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@OGUID+1, 277358, 1864, 9525, 9525, '1,2,23,8', 0, 0, 3987.501708984375, -1362.65625, 157.932159423828125, 4.680798053741455078, 0, 0, -0.71818733215332031, 0.695849835872650146, 7200, 255, 1, 54630), -- Collision Wall (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@OGUID+2, 249386, 1864, 9525, 9525, '1,2,23,8', 0, 0, 3972.826416015625, -1134.970458984375, 141.9206085205078125, 4.489966869354248046, 0, 0, -0.78121471405029296, 0.624262392520904541, 7200, 255, 1, 54630), -- Arcane Barrier (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@OGUID+3, 249386, 1864, 9525, 9525, '1,2,23,8', 0, 0, 3971.479248046875, -1132.1180419921875, 141.9206085205078125, 5.647112369537353515, 0, 0, -0.31270217895507812, 0.949851214885711669, 7200, 255, 1, 54630), -- Arcane Barrier (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@OGUID+4, 249386, 1864, 9525, 9525, '1,2,23,8', 0, 0, 3971.479248046875, -1132.1180419921875, 117.6471633911132812, 5.647112369537353515, 0, 0, -0.31270217895507812, 0.949851214885711669, 7200, 255, 1, 54630), -- Arcane Barrier (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@OGUID+5, 249386, 1864, 9525, 9525, '1,2,23,8', 0, 0, 3972.826416015625, -1134.970458984375, 117.6471633911132812, 4.489966869354248046, 0, 0, -0.78121471405029296, 0.624262392520904541, 7200, 255, 1, 54630), -- Arcane Barrier (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@OGUID+6, 230537, 1864, 9525, 9525, '1,2,23,8', 0, 0, 4003.587646484375, -1109.8802490234375, 106.3221588134765625, 0, 0, 0, 0, 1, 7200, 255, 1, 54630), -- Invisible Door (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@OGUID+7, 230537, 1864, 9525, 9525, '1,2,23,8', 0, 0, 4010.759521484375, -1100.935791015625, 106.67034912109375, 0, 0, 0, 0, 1, 7200, 255, 1, 54630), -- Invisible Door (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@OGUID+8, 249386, 1864, 9525, 9525, '1,2,23,8', 0, 0, 3945.212646484375, -1145.29345703125, 141.9206085205078125, 4.9036865234375, 0, 0, -0.63634395599365234, 0.771405458450317382, 7200, 255, 1, 54630), -- Arcane Barrier (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@OGUID+9, 249386, 1864, 9525, 9525, '1,2,23,8', 0, 0, 3945.212646484375, -1145.29345703125, 117.6471633911132812, 4.9036865234375, 0, 0, -0.63634395599365234, 0.771405458450317382, 7200, 255, 1, 54630), -- Arcane Barrier (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@OGUID+10, 266885, 1864, 9525, 9525, '1,2,23,8', 0, 0, 3965.4306640625, -1358.0728759765625, 157.932159423828125, 1.578292369842529296, 0, 0, 0.709752082824707031, 0.704451560974121093, 7200, 255, 1, 54630), -- Ghost Gate (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@OGUID+11, 249386, 1864, 9525, 9525, '1,2,23,8', 0, 0, 3917.10595703125, -1149.2569580078125, 141.9206085205078125, 4.9036865234375, 0, 0, -0.63634395599365234, 0.771405458450317382, 7200, 255, 1, 54630), -- Arcane Barrier (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@OGUID+12, 216056, 1864, 9525, 9525, '1,2,23,8', 0, 0, 3965.354248046875, -1355.3836669921875, 154.4677581787109375, 0, 0, 0, 0, 1, 7200, 255, 1, 54630), -- Collision PC Size (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@OGUID+13, 249386, 1864, 9525, 9525, '1,2,23,8', 0, 0, 3917.10595703125, -1149.2569580078125, 117.6471633911132812, 4.9036865234375, 0, 0, -0.63634395599365234, 0.771405458450317382, 7200, 255, 1, 54630), -- Arcane Barrier (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@OGUID+14, 230537, 1864, 9525, 9525, '1,2,23,8', 0, 0, 3976.62841796875, -1088.9271240234375, 106.3221588134765625, 0, 0, 0, 0, 1, 7200, 255, 1, 54630), -- Invisible Door (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@OGUID+15, 249386, 1864, 9525, 9525, '1,2,23,8', 0, 0, 3876.359375, -1158.98095703125, 117.6471633911132812, 4.9036865234375, 0, 0, -0.63634395599365234, 0.771405458450317382, 7200, 255, 1, 54630), -- Arcane Barrier (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@OGUID+16, 249386, 1864, 9525, 9525, '1,2,23,8', 0, 0, 3876.359375, -1158.98095703125, 141.9206085205078125, 4.9036865234375, 0, 0, -0.63634395599365234, 0.771405458450317382, 7200, 255, 1, 54630), -- Arcane Barrier (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@OGUID+17, 230537, 1864, 9525, 9525, '1,2,23,8', 0, 0, 3983.80029296875, -1079.982666015625, 106.67034912109375, 0, 0, 0, 0, 1, 7200, 255, 1, 54630), -- Invisible Door (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@OGUID+18, 249386, 1864, 9525, 9525, '1,2,23,8', 0, 0, 3838.002685546875, -1167.282958984375, 141.9206085205078125, 4.9036865234375, 0, 0, -0.63634395599365234, 0.771405458450317382, 7200, 255, 1, 54630), -- Arcane Barrier (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@OGUID+19, 249386, 1864, 9525, 9525, '1,2,23,8', 0, 0, 3838.002685546875, -1167.282958984375, 117.6471633911132812, 4.9036865234375, 0, 0, -0.63634395599365234, 0.771405458450317382, 7200, 255, 1, 54630), -- Arcane Barrier (Area: Shrine of the Storm - Difficulty: Mythic) CreateObject1
(@OGUID+20, 292654, 1864, 9525, 9964, '1,2,23,8', 0, 0, 3847.95654296875, -1819.3680419921875, 98.25485992431640625, 3.289336919784545898, -0.46942424774169921, -0.45528411865234375, -0.6686105728149414, 0.354001551866531372, 7200, 255, 1, 54630), -- Void (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1
(@OGUID+21, 292654, 1864, 9525, 9964, '1,2,23,8', 0, 0, 3839.275146484375, -1820.5347900390625, 85.37005615234375, 3.289336919784545898, -0.46942424774169921, -0.45528411865234375, -0.6686105728149414, 0.354001551866531372, 7200, 255, 1, 54630), -- Void (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1
(@OGUID+22, 292654, 1864, 9525, 9964, '1,2,23,8', 0, 0, 3833.564208984375, -1825.4913330078125, 104.834136962890625, 0.379335016012191772, -0.06698465347290039, -0.3479318618774414, 0.130626678466796875, 0.925955235958099365, 7200, 255, 1, 54630), -- Void (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1
(@OGUID+23, 292653, 1864, 9525, 9964, '1,2,23,8', 0, 0, 3829.493896484375, -1823.2864990234375, 71.47470855712890625, 4.840839862823486328, 0, 0, -0.66026592254638671, 0.751031875610351562, 7200, 255, 1, 54630), -- Barrier (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1
(@OGUID+24, 292653, 1864, 9525, 9964, '1,2,23,8', 0, 0, 3811.345458984375, -1830.7083740234375, 72.18155670166015625, 5.190341949462890625, 0, 0, -0.51963329315185546, 0.854389369487762451, 7200, 255, 1, 54630), -- Barrier (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1
(@OGUID+25, 292654, 1864, 9525, 9964, '1,2,23,8', 0, 0, 3813.205810546875, -1835.0242919921875, 95.52660369873046875, 5.779778480529785156, -0.20919513702392578, -0.28597354888916015, -0.27744102478027343, 0.893019020557403564, 7200, 255, 1, 54630), -- Void (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1
(@OGUID+26, 292653, 1864, 9525, 9964, '1,2,23,8', 0, 0, 3794.48779296875, -1840.435791015625, 72.47440338134765625, 5.190341949462890625, 0, 0, -0.51963329315185546, 0.854389369487762451, 7200, 255, 1, 54630), -- Barrier (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1
(@OGUID+27, 293699, 1864, 9525, 9964, '1,2,23,8', 0, 0, 3784.748291015625, -1071.545166015625, 112.2140274047851562, 4.273712158203125, 0, 0, -0.84402084350585937, 0.536310374736785888, 7200, 255, 1, 54630), -- Scroll of Safe Passage (Area: Tidewater Sanctum - Difficulty: Mythic) CreateObject1
(@OGUID+28, 292653, 1864, 9525, 0, '1,2,23,8', 0, 0, 3778.197021484375, -1851.796875, 72.32448577880859375, 5.449372291564941406, 0, 0, -0.40493392944335937, 0.914345979690551757, 7200, 255, 1, 54630), -- Barrier (Area: 0 - Difficulty: Mythic) CreateObject1
(@OGUID+29, 292653, 1864, 9525, 0, '1,2,23,8', 0, 0, 3764.599853515625, -1863.904541015625, 73.16689300537109375, 5.449372291564941406, 0, 0, -0.40493392944335937, 0.914345979690551757, 7200, 255, 1, 54630), -- Barrier (Area: 0 - Difficulty: Mythic) CreateObject1
(@OGUID+30, 292654, 1864, 9525, 0, '1,2,23,8', 0, 0, 3793.177978515625, -1872.9757080078125, 107.1095428466796875, 0.379335016012191772, -0.06698465347290039, -0.3479318618774414, 0.130626678466796875, 0.925955235958099365, 7200, 255, 1, 54630), -- Void (Area: 0 - Difficulty: Mythic) CreateObject1
(@OGUID+31, 292653, 1864, 9525, 0, '1,2,23,8', 0, 0, 3752.632080078125, -1879.6302490234375, 72.23635101318359375, 5.844522953033447265, 0, 0, -0.21757698059082031, 0.976043164730072021, 7200, 255, 1, 54630), -- Barrier (Area: 0 - Difficulty: Mythic) CreateObject1
(@OGUID+32, 292654, 1864, 9525, 0, '1,2,23,8', 0, 0, 3776.975830078125, -1876.5382080078125, 89.06439971923828125, 0.379335016012191772, -0.06698465347290039, -0.3479318618774414, 0.130626678466796875, 0.925955235958099365, 7200, 255, 1, 54630), -- Void (Area: 0 - Difficulty: Mythic) CreateObject1
(@OGUID+33, 292654, 1864, 9525, 0, '1,2,23,8', 0, 0, 3794.197998046875, -1872.984375, 95.29228973388671875, 5.06549692153930664, -0.29597043991088867, -0.1947946548461914, -0.57213115692138671, 0.739677250385284423, 7200, 255, 1, 54630), -- Void (Area: 0 - Difficulty: Mythic) CreateObject1
(@OGUID+34, 292653, 1864, 9525, 0, '1,2,23,8', 0, 0, 3741.943603515625, -1895.9617919921875, 71.92375946044921875, 5.844522953033447265, 0, 0, -0.21757698059082031, 0.976043164730072021, 7200, 255, 1, 54630), -- Barrier (Area: 0 - Difficulty: Mythic) CreateObject1
(@OGUID+35, 292654, 1864, 9525, 0, '1,2,23,8', 0, 0, 3748.60595703125, -1895.7847900390625, 93.1498260498046875, 0.379335016012191772, -0.06698465347290039, -0.3479318618774414, 0.130626678466796875, 0.925955235958099365, 7200, 255, 1, 54630), -- Void (Area: 0 - Difficulty: Mythic) CreateObject1
(@OGUID+36, 292654, 1864, 9525, 0, '1,2,23,8', 0, 0, 3742.04345703125, -1909.876708984375, 96.99422454833984375, 0.379335016012191772, -0.06698465347290039, -0.3479318618774414, 0.130626678466796875, 0.925955235958099365, 7200, 255, 1, 54630), -- Void (Area: 0 - Difficulty: Mythic) CreateObject1
(@OGUID+37, 292654, 1864, 9525, 0, '1,2,23,8', 0, 0, 3745.10595703125, -1907.3819580078125, 87.67386627197265625, 5.001288414001464843, 0.036137580871582031, -0.65294456481933593, -0.17091655731201171, 0.736983656883239746, 7200, 255, 1, 54630), -- Void (Area: 0 - Difficulty: Mythic) CreateObject1
(@OGUID+38, 292654, 1864, 9525, 0, '1,2,23,8', 0, 0, 3744.186767578125, -1915.203125, 85.0748291015625, 5.30351114273071289, 0.134018421173095703, -0.64006423950195312, -0.05802440643310546, 0.754314243793487548, 7200, 255, 1, 54630); -- Void (Area: 0 - Difficulty: Mythic) CreateObject1

-- Template
UPDATE `creature_template` SET `unit_flags3`=16777217 WHERE `entry`=141028; -- Void Orb
UPDATE `creature_template` SET `unit_flags3`=67108864 WHERE `entry`=140038; -- Abyssal Eel
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=136297; -- Forgotten Denizen
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=136295; -- Sunken Denizen
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=137143; -- Sunken Tentacle
UPDATE `creature_template` SET `unit_flags3`=16777217, `flags_extra` = 128 WHERE `entry`=82347; -- Stalker
UPDATE `creature_template` SET `unit_flags3`=16777217, `flags_extra` = 128 WHERE `entry` IN (141016, 140999, 140967); -- Shrine's Breath
UPDATE `creature_template` SET `unit_flags3`=16777217 WHERE `entry`=136961; -- Waken the Void
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=139963; -- Queen Azshara
UPDATE `creature_template` SET `unit_flags2`=67110912, `unit_flags3`=16777217 WHERE `entry`=136363; -- Jellyfish
UPDATE `creature_template` SET `unit_flags`=320, `unit_flags2`=0 WHERE `entry`=134060; -- Lord Stormsong
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=134056; -- Aqu'sirr
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=134423; -- Abyss Dweller
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=134069; -- Vol'zith the Whisperer
UPDATE `creature_template` SET `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=134514; -- Abyssal Cultist
UPDATE `creature_template` SET `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=134418; -- Drowned Depthbringer
UPDATE `creature_template` SET `unit_flags2`=0 WHERE `entry`=134063; -- Brother Ironhull
UPDATE `creature_template` SET `unit_flags2`=67110912, `unit_flags3`=16777217 WHERE `entry`=139572; -- Murky Water
UPDATE `creature_template` SET `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=134417; -- Deepsea Ritualist
UPDATE `creature_template` SET `unit_flags2`=0 WHERE `entry`=134058; -- Galecaller Faye
UPDATE `creature_template` SET `unit_flags2`=0 WHERE `entry`=139737; -- Lord Stormsong
UPDATE `creature_template` SET `unit_flags2`=2048, `unit_flags3`=16777217, `flags_extra` = 128 WHERE `entry`=139986; -- Shrine of the Storm
UPDATE `creature_template` SET `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=136249; -- Guardian Elemental
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=134150; -- Runecarver Sorn
UPDATE `creature_template` SET `unit_flags2`=67110912, `unit_flags3`=16777217, `flags_extra` = 128 WHERE `entry`=136505; -- Rune
UPDATE `creature_template` SET `unit_flags2`=67110912, `unit_flags3`=16777217 WHERE `entry`=136188; -- Bound Soul
UPDATE `creature_template` SET `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=136186; -- Tidesage Spiritualist
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=134144; -- Living Current
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=120652; -- Global Affix Stalker
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=134137; -- Temple Attendant
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=134139; -- Shrine Templar
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=134173; -- Animated Droplet
UPDATE `creature_template` SET `unit_flags`=0, `unit_flags2`=2048 WHERE `entry`=136347; -- Tidesage Initiate

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (141028 /*141028 (Void Orb)*/, 140038 /*140038 (Abyssal Eel)*/, 136297 /*136297 (Forgotten Denizen)*/, 136295 /*136295 (Sunken Denizen)*/, 137143 /*137143 (Sunken Tentacle)*/, 82347 /*82347 (Stalker)*/, 141016 /*141016 (Shrine's Breath)*/, 136961 /*136961 (Waken the Void)*/, 139963 /*139963 (Queen Azshara)*/, 136363 /*136363 (Jellyfish)*/, 134060 /*134060 (Lord Stormsong)*/, 134056 /*134056 (Aqu'sirr)*/, 134423 /*134423 (Abyss Dweller) - Force Low LOD (Do Not Translate, No Display), Shifting Guise*/, 134069 /*134069 (Vol'zith the Whisperer) - Void Energy*/, 134338 /*134338 (Tidesage Enforcer) - Mod Scale -10% [DNT], Invisibility and Stealth Detection*/, 134514 /*134514 (Abyssal Cultist) - Mod Scale 105-110%, Shifting Guise, Void Channel*/, 139626 /*139626 (Dredged Sailor)*/, 134418 /*134418 (Drowned Depthbringer)*/, 134063 /*134063 (Brother Ironhull)*/, 139572 /*139572 (Murky Water) - Murky Water*/, 134417 /*134417 (Deepsea Ritualist) - Void Form, Void Channel*/, 134058 /*134058 (Galecaller Faye)*/, 139737 /*139737 (Lord Stormsong)*/, 139799 /*139799 (Ironhull Apprentice) - Mod Scale 105-110%*/, 139800 /*139800 (Galecaller Apprentice) - Cosmetic Wind State*/, 136214 /*136214 (Windspeaker Heldis) - Wind Ritual*/, 139986 /*139986 (Shrine of the Storm)*/, 136249 /*136249 (Guardian Elemental)*/, 134150 /*134150 (Runecarver Sorn) - Read Scrolls*/, 136505 /*136505 (Rune)*/, 140999 /*140999 (Shrine's Breath)*/, 136188 /*136188 (Bound Soul)*/, 136186 /*136186 (Tidesage Spiritualist)*/, 134144 /*134144 (Living Current)*/, 134137 /*134137 (Temple Attendant)*/, 134139 /*134139 (Shrine Templar)*/, 134173 /*134173 (Animated Droplet) - Force Low LOD (Do Not Translate, No Display)*/, 136347 /*136347 (Tidesage Initiate)*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(141028, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 141028 (Void Orb)
(140038, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '237007'), -- 140038 (Abyssal Eel)
(136297, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 136297 (Forgotten Denizen)
(136295, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 136295 (Sunken Denizen)
(137143, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 137143 (Sunken Tentacle)
(82347, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '274712'), -- 82347 (Stalker)
(141016, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 141016 (Shrine's Breath)
(136961, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 136961 (Waken the Void)
(139963, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, '274634'), -- 139963 (Queen Azshara)
(136363, 0, 0, 0, 3, 0, 1, 0, 0, 16005, 0, 0, 3, '243685 267955'), -- 136363 (Jellyfish)
(134060, 0, 0, 0, 0, 0, 1, 0, 468, 0, 0, 0, 3, ''), -- 134060 (Lord Stormsong)
(134056, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 134056 (Aqu'sirr)
(134423, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '281206 274305'), -- 134423 (Abyss Dweller) - Force Low LOD (Do Not Translate, No Display), Shifting Guise
(134069, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '267255'), -- 134069 (Vol'zith the Whisperer) - Void Energy
(134338, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '139880 18950'), -- 134338 (Tidesage Enforcer) - Mod Scale -10% [DNT], Invisibility and Stealth Detection
(134514, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '123169 268312'), -- 134514 (Abyssal Cultist) - Mod Scale 105-110%, Shifting Guise, Void Channel
(139626, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, '281206 274210'), -- 139626 (Dredged Sailor)
(134418, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 134418 (Drowned Depthbringer)
(134063, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 134063 (Brother Ironhull)
(139572, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, '274152'), -- 139572 (Murky Water) - Murky Water
(134417, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '268305'), -- 134417 (Deepsea Ritualist) - Void Form, Void Channel
(134058, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 134058 (Galecaller Faye)
(139737, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 139737 (Lord Stormsong)
(139799, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123169'), -- 139799 (Ironhull Apprentice) - Mod Scale 105-110%
(139800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 139800 (Galecaller Apprentice)
(136214, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 136214 (Windspeaker Heldis)
(139986, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 139986 (Shrine of the Storm)
(136249, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '18950'), -- 136249 (Guardian Elemental)
(134150, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 134150 (Runecarver Sorn)
(136505, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 136505 (Rune)
(140999, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 140999 (Shrine's Breath)
(136188, 0, 0, 0, 3, 0, 1, 0, 0, 5138, 0, 0, 3, ''), -- 136188 (Bound Soul)
(136186, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 136186 (Tidesage Spiritualist)
(134144, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '18950'), -- 134144 (Living Current)
(134137, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 134137 (Temple Attendant)
(134139, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 134139 (Shrine Templar)
(134173, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 134173 (Animated Droplet) - Force Low LOD (Do Not Translate, No Display)
(136347, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''); -- 136347 (Tidesage Initiate)

-- Difficulty (fallback, Normal)
UPDATE `creature_template_difficulty` SET `ContentTuningID`=500, `StaticFlags1`=805306368, `VerifiedBuild`=54847 WHERE (`Entry`=140038 AND `DifficultyID`=0); -- 140038 (Abyssal Eel) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=500, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=136297 AND `DifficultyID`=0); -- 136297 (Forgotten Denizen) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=500, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=136295 AND `DifficultyID`=0); -- 136295 (Sunken Denizen) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=500, `StaticFlags1`=805306368, `VerifiedBuild`=54847 WHERE (`Entry`=137143 AND `DifficultyID`=0); -- 137143 (Sunken Tentacle) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536870912, `VerifiedBuild`=54847 WHERE (`Entry`=82347 AND `DifficultyID`=0); -- 82347 (Stalker) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=500, `StaticFlags1`=536870912, `VerifiedBuild`=54847 WHERE (`Entry`=141016 AND `DifficultyID`=0); -- 141016 (Shrine's Breath) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=500, `StaticFlags1`=536870912, `VerifiedBuild`=54847 WHERE (`Entry`=136363 AND `DifficultyID`=0); -- 136363 (Jellyfish) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=500, `StaticFlags1`=536871168, `VerifiedBuild`=54847 WHERE (`Entry`=136961 AND `DifficultyID`=0); -- 136961 (Waken the Void) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=500, `StaticFlags1`=805306368, `VerifiedBuild`=54847 WHERE (`Entry`=139963 AND `DifficultyID`=0); -- 139963 (Queen Azshara) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=500, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134060 AND `DifficultyID`=0); -- 134060 (Lord Stormsong) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=500, `StaticFlags1`=805306624, `VerifiedBuild`=54847 WHERE (`Entry`=134056 AND `DifficultyID`=0); -- 134056 (Aqu'sirr) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=500, `StaticFlags1`=805306624, `VerifiedBuild`=54847 WHERE (`Entry`=134423 AND `DifficultyID`=0); -- 134423 (Abyss Dweller) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=500, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134069 AND `DifficultyID`=0); -- 134069 (Vol'zith the Whisperer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=500, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134514 AND `DifficultyID`=0); -- 134514 (Abyssal Cultist) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=500, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134338 AND `DifficultyID`=0); -- 134338 (Tidesage Enforcer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=500, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=139626 AND `DifficultyID`=0); -- 139626 (Dredged Sailor) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=500, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134418 AND `DifficultyID`=0); -- 134418 (Drowned Depthbringer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=500, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134063 AND `DifficultyID`=0); -- 134063 (Brother Ironhull) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=500, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134058 AND `DifficultyID`=0); -- 134058 (Galecaller Faye) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=121028 AND `DifficultyID`=0); -- 121028 (Cove Seagull) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=500, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134417 AND `DifficultyID`=0); -- 134417 (Deepsea Ritualist) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=500, `StaticFlags1`=536870912, `VerifiedBuild`=54847 WHERE (`Entry`=139572 AND `DifficultyID`=0); -- 139572 (Murky Water) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=500, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=139737 AND `DifficultyID`=0); -- 139737 (Lord Stormsong) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=500, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=136249 AND `DifficultyID`=0); -- 136249 (Guardian Elemental) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=500, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=136214 AND `DifficultyID`=0); -- 136214 (Windspeaker Heldis) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=500, `StaticFlags1`=536871168, `VerifiedBuild`=54847 WHERE (`Entry`=139986 AND `DifficultyID`=0); -- 139986 (Shrine of the Storm) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=500, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134150 AND `DifficultyID`=0); -- 134150 (Runecarver Sorn) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=500, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=139800 AND `DifficultyID`=0); -- 139800 (Galecaller Apprentice) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=500, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=139799 AND `DifficultyID`=0); -- 139799 (Ironhull Apprentice) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=500, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134144 AND `DifficultyID`=0); -- 134144 (Living Current) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=500, `StaticFlags1`=536870912, `VerifiedBuild`=54847 WHERE (`Entry`=136188 AND `DifficultyID`=0); -- 136188 (Bound Soul) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=500, `StaticFlags1`=536870912, `VerifiedBuild`=54847 WHERE (`Entry`=136505 AND `DifficultyID`=0); -- 136505 (Rune) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=500, `StaticFlags1`=536870912, `VerifiedBuild`=54847 WHERE (`Entry`=140999 AND `DifficultyID`=0); -- 140999 (Shrine's Breath) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=500, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=136186 AND `DifficultyID`=0); -- 136186 (Tidesage Spiritualist) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=500, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=139970 AND `DifficultyID`=0); -- 139970 (Brother Pike) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=500, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=136347 AND `DifficultyID`=0); -- 136347 (Tidesage Initiate) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=500, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134137 AND `DifficultyID`=0); -- 134137 (Temple Attendant) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=500, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134139 AND `DifficultyID`=0); -- 134139 (Shrine Templar) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=500, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134173 AND `DifficultyID`=0); -- 134173 (Animated Droplet) - CanSwim

-- Difficulty (Heroic)
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=2 AND `Entry` IN (140038,136297,136295,137143,136353,82347,141016,139963,136961,136363,134060,134056,134423,134069,134338,134514,139626,134418,134063,121028,134058,139572,134417,139737,139986,136249,136214,134150,139799,139800,136505,136188,134144,136186,140999,218977,218647,218646,134137,134173,134139,139970,136347));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`) VALUES
(140038, 2, 7, 2, 1, 147005, 2097225, 0), -- Abyssal Eel
(136297, 2, 7, 5, 1, 142592, 2097224, 0), -- Forgotten Denizen
(136295, 2, 7, 8, 1, 144304, 2097224, 0), -- Sunken Denizen
(137143, 2, 7, 0.699999988079071044, 1, 143605, 2097224, 0), -- Sunken Tentacle
(136353, 2, 7, 5.5, 1, 144302, 2097224, 0), -- Colossal Tentacle
(82347, 2, 9, 0.009999999776482582, 1, 80443, 0, 0), -- Stalker
(141016, 2, 7, 1, 1, 148017, 1610612752, 6), -- Shrine's Breath
(139963, 2, 7, 750, 55.340301513671875, 146834, 2097228, 0), -- Queen Azshara
(136961, 2, 7, 1, 1, 143400, 1610612752, 6), -- Waken the Void
(136363, 2, 7, 1, 1, 142662, 1610612752, 6), -- Jellyfish
(134060, 2, 7, 35, 55.340301513671875, 144314, 2097224, 129), -- Lord Stormsong
(134056, 2, 7, 40, 1, 143572, 2097224, 128), -- Aqu'sirr
(134423, 2, 7, 0.699999988079071044, 1, 144300, 2097224, 0), -- Abyss Dweller
(134069, 2, 7, 32, 1, 143581, 2097224, 128), -- Vol'zith the Whisperer
(134338, 2, 7, 5, 1, 144296, 2097224, 0), -- Tidesage Enforcer
(134514, 2, 7, 5, 1, 144292, 2097224, 0), -- Abyssal Cultist
(139626, 2, 7, 0.25, 1, 146460, 2097224, 0), -- Dredged Sailor
(134418, 2, 7, 5, 1, 144298, 2097224, 0), -- Drowned Depthbringer
(134063, 2, 7, 26.25, 0.338862001895904541, 144308, 2097224, 129), -- Brother Ironhull
(121028, 2, 6, 50, 1, 125478, 2097224, 0), -- Cove Seagull
(134058, 2, 7, 26.25, 0.338862001895904541, 144306, 2097224, 129), -- Galecaller Faye
(139572, 2, 7, 1, 1, 146402, 1610612752, 6), -- Murky Water
(134417, 2, 7, 11, 1, 144294, 2097224, 0), -- Deepsea Ritualist
(139737, 2, 7, 35, 55.340301513671875, 146573, 2097224, 1), -- Lord Stormsong
(139986, 2, 7, 1, 1, 146862, 1610612752, 6), -- Shrine of the Storm
(136249, 2, 7, 15, 1, 144288, 2097224, 0), -- Guardian Elemental
(136214, 2, 7, 18, 1, 144290, 2097224, 0), -- Windspeaker Heldis
(134150, 2, 7, 16, 1, 144284, 2097224, 0), -- Runecarver Sorn
(139799, 2, 7, 5, 1, 146647, 2097224, 0), -- Ironhull Apprentice
(139800, 2, 7, 5, 1, 146650, 2097224, 0), -- Galecaller Apprentice
(136505, 2, 7, 1, 1, 142819, 1610612752, 6), -- Rune
(136188, 2, 7, 1, 1, 142452, 1610612752, 6), -- Bound Soul
(134144, 2, 7, 8, 1, 144276, 2097224, 0), -- Living Current
(136186, 2, 7, 6, 1, 144282, 2097224, 0), -- Tidesage Spiritualist
(140999, 2, 7, 1, 1, 148000, 1610612752, 6), -- Shrine's Breath
(218977, 2, 9, 1, 1, 268541, 0, 0), -- Happy
(218647, 2, 9, 1, 1, 268162, 0, 0), -- Glamrok
(218646, 2, 9, 1, 1, 268161, 0, 0), -- Bubbles
(134137, 2, 7, 5, 1, 144274, 2097224, 0), -- Temple Attendant
(134173, 2, 7, 0.699999988079071044, 1, 144280, 2097224, 0), -- Animated Droplet
(134139, 2, 7, 6, 1, 144278, 2097224, 0), -- Shrine Templar
(139970, 2, 7, 25, 55.340301513671875, 146843, 2097224, 1), -- Brother Pike
(136347, 2, 7, 1, 1, 144286, 2097224, 0); -- Tidesage Initiate

UPDATE `creature_template_difficulty` SET `ContentTuningID`=501, `StaticFlags1`=805306368, `VerifiedBuild`=54847 WHERE (`Entry`=140038 AND `DifficultyID`=2); -- 140038 (Abyssal Eel) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=136297 AND `DifficultyID`=2); -- 136297 (Forgotten Denizen) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=136295 AND `DifficultyID`=2); -- 136295 (Sunken Denizen) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=501, `StaticFlags1`=805306624, `VerifiedBuild`=54847 WHERE (`Entry`=136353 AND `DifficultyID`=2); -- 136353 (Colossal Tentacle) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=501, `StaticFlags1`=805306368, `VerifiedBuild`=54847 WHERE (`Entry`=137143 AND `DifficultyID`=2); -- 137143 (Sunken Tentacle) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=501, `StaticFlags1`=536870912, `VerifiedBuild`=54847 WHERE (`Entry`=141016 AND `DifficultyID`=2); -- 141016 (Shrine's Breath) - Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=501, `StaticFlags1`=805306368, `VerifiedBuild`=54847 WHERE (`Entry`=139963 AND `DifficultyID`=2); -- 139963 (Queen Azshara) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=501, `StaticFlags1`=536871168, `VerifiedBuild`=54847 WHERE (`Entry`=136961 AND `DifficultyID`=2); -- 136961 (Waken the Void) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=501, `StaticFlags1`=536870912, `VerifiedBuild`=54847 WHERE (`Entry`=136363 AND `DifficultyID`=2); -- 136363 (Jellyfish) - Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134060 AND `DifficultyID`=2); -- 134060 (Lord Stormsong) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=501, `StaticFlags1`=805306624, `VerifiedBuild`=54847 WHERE (`Entry`=134056 AND `DifficultyID`=2); -- 134056 (Aqu'sirr) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=501, `StaticFlags1`=805306624, `VerifiedBuild`=54847 WHERE (`Entry`=134423 AND `DifficultyID`=2); -- 134423 (Abyss Dweller) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134069 AND `DifficultyID`=2); -- 134069 (Vol'zith the Whisperer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134338 AND `DifficultyID`=2); -- 134338 (Tidesage Enforcer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134514 AND `DifficultyID`=2); -- 134514 (Abyssal Cultist) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=139626 AND `DifficultyID`=2); -- 139626 (Dredged Sailor) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134418 AND `DifficultyID`=2); -- 134418 (Drowned Depthbringer) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134063 AND `DifficultyID`=2); -- 134063 (Brother Ironhull) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134058 AND `DifficultyID`=2); -- 134058 (Galecaller Faye) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134417 AND `DifficultyID`=2); -- 134417 (Deepsea Ritualist) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=501, `StaticFlags1`=536870912, `VerifiedBuild`=54847 WHERE (`Entry`=139572 AND `DifficultyID`=2); -- 139572 (Murky Water) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=501, `StaticFlags1`=536871168, `VerifiedBuild`=54847 WHERE (`Entry`=139986 AND `DifficultyID`=2); -- 139986 (Shrine of the Storm) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=136214 AND `DifficultyID`=2); -- 136214 (Windspeaker Heldis) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=136249 AND `DifficultyID`=2); -- 136249 (Guardian Elemental) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=139737 AND `DifficultyID`=2); -- 139737 (Lord Stormsong) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134150 AND `DifficultyID`=2); -- 134150 (Runecarver Sorn) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=139799 AND `DifficultyID`=2); -- 139799 (Ironhull Apprentice) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=139800 AND `DifficultyID`=2); -- 139800 (Galecaller Apprentice) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134144 AND `DifficultyID`=2); -- 134144 (Living Current) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=501, `StaticFlags1`=536870912, `VerifiedBuild`=54847 WHERE (`Entry`=140999 AND `DifficultyID`=2); -- 140999 (Shrine's Breath) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=501, `StaticFlags1`=536870912, `VerifiedBuild`=54847 WHERE (`Entry`=136188 AND `DifficultyID`=2); -- 136188 (Bound Soul) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=136186 AND `DifficultyID`=2); -- 136186 (Tidesage Spiritualist) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=501, `StaticFlags1`=536870912, `VerifiedBuild`=54847 WHERE (`Entry`=136505 AND `DifficultyID`=2); -- 136505 (Rune) - Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=139970 AND `DifficultyID`=2); -- 139970 (Brother Pike) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134137 AND `DifficultyID`=2); -- 134137 (Temple Attendant) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134139 AND `DifficultyID`=2); -- 134139 (Shrine Templar) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=136347 AND `DifficultyID`=2); -- 136347 (Tidesage Initiate) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=501, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134173 AND `DifficultyID`=2); -- 134173 (Animated Droplet) - CanSwim

-- Difficulty (Mythic)
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=23 AND `Entry` IN (140038,136297,136295,139963,134060,134056,134423,134069,134514,134338,139626,134418,134063,134058,134417,139737,136249,136214,134150,139799,139800,134144,136186,134137,134173,134139,139970,136347));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`) VALUES
(140038, 23, 7, 2, 1, 147006, 2097225, 0), -- Abyssal Eel
(136297, 23, 7, 5, 1, 142593, 2097224, 0), -- Forgotten Denizen
(136295, 23, 7, 8, 1, 144305, 2097224, 0), -- Sunken Denizen
(139963, 23, 7, 750, 55.340301513671875, 146835, 2097228, 0), -- Queen Azshara
(134060, 23, 7, 35, 55.340301513671875, 144315, 2097224, 129), -- Lord Stormsong
(134056, 23, 7, 40, 1, 143573, 2097224, 128), -- Aqu'sirr
(134423, 23, 7, 0.699999988079071044, 1, 144301, 2097224, 0), -- Abyss Dweller
(134069, 23, 7, 32, 1, 143582, 2097224, 128), -- Vol'zith the Whisperer
(134514, 23, 7, 5, 1, 144293, 2097224, 0), -- Abyssal Cultist
(134338, 23, 7, 5, 1, 144297, 2097224, 0), -- Tidesage Enforcer
(139626, 23, 7, 0.25, 1, 146461, 2097224, 0), -- Dredged Sailor
(134418, 23, 7, 5, 1, 144299, 2097224, 0), -- Drowned Depthbringer
(134063, 23, 7, 26.25, 0.338862001895904541, 144309, 2097224, 129), -- Brother Ironhull
(134058, 23, 7, 26.25, 0.338862001895904541, 144307, 2097224, 129), -- Galecaller Faye
(134417, 23, 7, 11, 1, 144295, 2097224, 0), -- Deepsea Ritualist
(139737, 23, 7, 35, 55.340301513671875, 146574, 2097224, 1), -- Lord Stormsong
(136249, 23, 7, 15, 1, 144289, 2097224, 0), -- Guardian Elemental
(136214, 23, 7, 18, 1, 144291, 2097224, 0), -- Windspeaker Heldis
(134150, 23, 7, 16, 1, 144285, 2097224, 0), -- Runecarver Sorn
(139799, 23, 7, 5, 1, 146648, 2097224, 0), -- Ironhull Apprentice
(139800, 23, 7, 5, 1, 146651, 2097224, 0), -- Galecaller Apprentice
(134144, 23, 7, 8, 1, 144277, 2097224, 0), -- Living Current
(136186, 23, 7, 6, 1, 144283, 2097224, 0), -- Tidesage Spiritualist
(134137, 23, 7, 5, 1, 144275, 2097224, 0), -- Temple Attendant
(134173, 23, 7, 0.699999988079071044, 1, 144281, 2097224, 0), -- Animated Droplet
(134139, 23, 7, 6, 1, 144279, 2097224, 0), -- Shrine Templar
(139970, 23, 7, 25, 55.340301513671875, 146844, 2097224, 1), -- Brother Pike
(136347, 23, 7, 1, 1, 144287, 2097224, 0); -- Tidesage Initiate

DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=23 AND `Entry` IN (141041,141028,137143,82347,141016,136961,136363,121028,139572,139986,136188,140999,136505,140967));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`, `VerifiedBuild`) VALUES
(141041, 23, 0, 0, 502, 536870912, 0, 0, 0, 0, 0, 0, 0, 54847), -- 141041 (Void Orb) - Floating
(141028, 23, 0, 0, 502, 536870912, 0, 0, 0, 0, 0, 0, 0, 54847), -- 141028 (Void Orb) - Floating
(137143, 23, 1, 1, 502, 805306368, 0, 0, 0, 0, 0, 0, 0, 54847), -- 137143 (Sunken Tentacle) - CanSwim, Floating
(82347, 23, 0, 0, 181, 536870912, 0, 0, 0, 0, 0, 0, 0, 54847), -- 82347 (Stalker) - Floating
(141016, 23, 0, 0, 502, 536870912, 0, 0, 0, 0, 0, 0, 0, 54847), -- 141016 (Shrine's Breath) - Floating
(136961, 23, 0, 0, 502, 536871168, 0, 0, 0, 0, 0, 0, 0, 54847), -- 136961 (Waken the Void) - Sessile, Floating
(136363, 23, 0, 0, 502, 536870912, 0, 0, 0, 0, 0, 0, 0, 54847), -- 136363 (Jellyfish) - Floating
(121028, 23, 1, 1, 498, 268435456, 0, 0, 0, 0, 0, 0, 0, 54847), -- 121028 (Cove Seagull) - CanSwim
(139572, 23, 0, 0, 502, 536870912, 0, 0, 0, 0, 0, 0, 0, 54847), -- 139572 (Murky Water) - Floating
(139986, 23, 0, 0, 502, 536871168, 0, 0, 0, 0, 0, 0, 0, 54847), -- 139986 (Shrine of the Storm) - Sessile, Floating
(136188, 23, 0, 0, 502, 536870912, 0, 0, 0, 0, 0, 0, 0, 54847), -- 136188 (Bound Soul) - Floating
(140999, 23, 0, 0, 502, 536870912, 0, 0, 0, 0, 0, 0, 0, 54847), -- 140999 (Shrine's Breath) - Floating
(136505, 23, 0, 0, 502, 536870912, 0, 0, 0, 0, 0, 0, 0, 54847), -- 136505 (Rune) - Floating
(140967, 23, 0, 0, 502, 0, 0, 0, 0, 0, 0, 0, 0, 54847); -- 140967 (Shrine's Breath)

UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=148044, `TypeFlags`=1610612752, `TypeFlags2`=6 WHERE (`Entry`=141041 AND `DifficultyID`=23); -- Void Orb
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=148029, `TypeFlags`=1610612752, `TypeFlags2`=6 WHERE (`Entry`=141028 AND `DifficultyID`=23); -- Void Orb
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `HealthModifier`=0.699999988079071044, `CreatureDifficultyID`=143605, `TypeFlags`=2097224 WHERE (`Entry`=137143 AND `DifficultyID`=23); -- Sunken Tentacle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=0.009999999776482582, `CreatureDifficultyID`=80443 WHERE (`Entry`=82347 AND `DifficultyID`=23); -- Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=148017, `TypeFlags`=1610612752, `TypeFlags2`=6 WHERE (`Entry`=141016 AND `DifficultyID`=23); -- Shrine's Breath
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=143400, `TypeFlags`=1610612752, `TypeFlags2`=6 WHERE (`Entry`=136961 AND `DifficultyID`=23); -- Waken the Void
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=142662, `TypeFlags`=1610612752, `TypeFlags2`=6 WHERE (`Entry`=136363 AND `DifficultyID`=23); -- Jellyfish
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=50, `CreatureDifficultyID`=125478, `TypeFlags`=2097224 WHERE (`Entry`=121028 AND `DifficultyID`=23); -- Cove Seagull
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=146402, `TypeFlags`=1610612752, `TypeFlags2`=6 WHERE (`Entry`=139572 AND `DifficultyID`=23); -- Murky Water
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=146862, `TypeFlags`=1610612752, `TypeFlags2`=6 WHERE (`Entry`=139986 AND `DifficultyID`=23); -- Shrine of the Storm
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=142819, `TypeFlags`=1610612752, `TypeFlags2`=6 WHERE (`Entry`=136505 AND `DifficultyID`=23); -- Rune
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=142452, `TypeFlags`=1610612752, `TypeFlags2`=6 WHERE (`Entry`=136188 AND `DifficultyID`=23); -- Bound Soul
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=148000, `TypeFlags`=1610612752, `TypeFlags2`=6 WHERE (`Entry`=140999 AND `DifficultyID`=23); -- Shrine's Breath
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=147968, `TypeFlags`=1610612752, `TypeFlags2`=6 WHERE (`Entry`=140967 AND `DifficultyID`=23); -- Shrine's Breath
UPDATE `creature_template_difficulty` SET `ContentTuningID`=502, `StaticFlags1`=805306368, `VerifiedBuild`=54847 WHERE (`Entry`=140038 AND `DifficultyID`=23); -- 140038 (Abyssal Eel) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=136297 AND `DifficultyID`=23); -- 136297 (Forgotten Denizen) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=136295 AND `DifficultyID`=23); -- 136295 (Sunken Denizen) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=502, `StaticFlags1`=805306368, `VerifiedBuild`=54847 WHERE (`Entry`=139963 AND `DifficultyID`=23); -- 139963 (Queen Azshara) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134060 AND `DifficultyID`=23); -- 134060 (Lord Stormsong) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=502, `StaticFlags1`=805306624, `VerifiedBuild`=54847 WHERE (`Entry`=134056 AND `DifficultyID`=23); -- 134056 (Aqu'sirr) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=502, `StaticFlags1`=805306624, `VerifiedBuild`=54847 WHERE (`Entry`=134423 AND `DifficultyID`=23); -- 134423 (Abyss Dweller) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134069 AND `DifficultyID`=23); -- 134069 (Vol'zith the Whisperer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134514 AND `DifficultyID`=23); -- 134514 (Abyssal Cultist) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134338 AND `DifficultyID`=23); -- 134338 (Tidesage Enforcer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=139626 AND `DifficultyID`=23); -- 139626 (Dredged Sailor) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134418 AND `DifficultyID`=23); -- 134418 (Drowned Depthbringer) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134063 AND `DifficultyID`=23); -- 134063 (Brother Ironhull) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134058 AND `DifficultyID`=23); -- 134058 (Galecaller Faye) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134417 AND `DifficultyID`=23); -- 134417 (Deepsea Ritualist) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=136249 AND `DifficultyID`=23); -- 136249 (Guardian Elemental) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=139737 AND `DifficultyID`=23); -- 139737 (Lord Stormsong) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=136214 AND `DifficultyID`=23); -- 136214 (Windspeaker Heldis) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134150 AND `DifficultyID`=23); -- 134150 (Runecarver Sorn) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134144 AND `DifficultyID`=23); -- 134144 (Living Current) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=139800 AND `DifficultyID`=23); -- 139800 (Galecaller Apprentice) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=136186 AND `DifficultyID`=23); -- 136186 (Tidesage Spiritualist) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=139799 AND `DifficultyID`=23); -- 139799 (Ironhull Apprentice) - CanSwim
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=54847 WHERE (`Entry`=120652 AND `DifficultyID`=23);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=139970 AND `DifficultyID`=23); -- 139970 (Brother Pike) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134173 AND `DifficultyID`=23); -- 134173 (Animated Droplet) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134137 AND `DifficultyID`=23); -- 134137 (Temple Attendant) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=134139 AND `DifficultyID`=23); -- 134139 (Shrine Templar) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=502, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=136347 AND `DifficultyID`=23); -- 136347 (Tidesage Initiate) - CanSwim

-- Model
UPDATE `creature_model_info` SET `BoundingRadius`=6.01174020767211914, `CombatReach`=1.60000002384185791, `VerifiedBuild`=54630 WHERE `DisplayID` IN (74313, 74319);
UPDATE `creature_model_info` SET `BoundingRadius`=1.049999952316284179, `CombatReach`=3, `VerifiedBuild`=54630 WHERE `DisplayID`=68244;
UPDATE `creature_model_info` SET `BoundingRadius`=0.375, `CombatReach`=0.75, `VerifiedBuild`=54630 WHERE `DisplayID`=68714;
UPDATE `creature_model_info` SET `VerifiedBuild`=54630 WHERE `DisplayID` IN (88149, 21342, 84502, 84023, 86549, 79406, 79043, 51409, 79040, 84789, 65631, 84796, 84416, 84714, 84715, 84716, 84337, 11686, 84638, 84713, 74072, 12191, 88525, 16925, 84637, 81302, 74845, 83302, 84418, 88636, 83301, 83304, 83303);
UPDATE `creature_model_info` SET `BoundingRadius`=4.152166366577148437, `CombatReach`=4, `VerifiedBuild`=54630 WHERE `DisplayID`=86567;
UPDATE `creature_model_info` SET `BoundingRadius`=0.300000011920928955, `VerifiedBuild`=54630 WHERE `DisplayID`=32777;
UPDATE `creature_model_info` SET `BoundingRadius`=0.534377336502075195, `CombatReach`=1.5, `VerifiedBuild`=54630 WHERE `DisplayID`=85180;
UPDATE `creature_model_info` SET `BoundingRadius`=1.92183542251586914, `CombatReach`=3.75, `VerifiedBuild`=54630 WHERE `DisplayID`=85628;
UPDATE `creature_model_info` SET `BoundingRadius`=0.546643853187561035, `CombatReach`=1.499999880790710449, `VerifiedBuild`=54630 WHERE `DisplayID`=86550;
UPDATE `creature_model_info` SET `BoundingRadius`=0.546643853187561035, `CombatReach`=1.5, `VerifiedBuild`=54630 WHERE `DisplayID` IN (87366, 87365);
UPDATE `creature_model_info` SET `BoundingRadius`=0.306000024080276489, `CombatReach`=1.5, `VerifiedBuild`=54630 WHERE `DisplayID` IN (84818, 84817);
UPDATE `creature_model_info` SET `BoundingRadius`=0.546643853187561035, `CombatReach`=1.50000011920928955, `VerifiedBuild`=54630 WHERE `DisplayID`=87367;
UPDATE `creature_model_info` SET `BoundingRadius`=0.264983922243118286, `CombatReach`=1.499999880790710449, `VerifiedBuild`=54630 WHERE `DisplayID`=79405;
UPDATE `creature_model_info` SET `BoundingRadius`=0.264983922243118286, `CombatReach`=1.5, `VerifiedBuild`=54630 WHERE `DisplayID`=79404;
UPDATE `creature_model_info` SET `BoundingRadius`=0.264983922243118286, `CombatReach`=1.50000011920928955, `VerifiedBuild`=54630 WHERE `DisplayID`=79403;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6987152099609375, `CombatReach`=1.5, `VerifiedBuild`=54630 WHERE `DisplayID`=84679;
UPDATE `creature_model_info` SET `BoundingRadius`=0.207999989390373229, `CombatReach`=1.5, `VerifiedBuild`=54630 WHERE `DisplayID` IN (83273, 81779);
UPDATE `creature_model_info` SET `BoundingRadius`=0.367199987173080444, `CombatReach`=1.80000007152557373, `VerifiedBuild`=54630 WHERE `DisplayID`=80996;

-- Tidesage Initiate smart ai
SET @ENTRY := 136347;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 25, 0, 100, 0, 0, 0, 0, 0, 85, 271037, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Cast spell 271037 on self');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceGroup` = 1 AND `SourceEntry` = @ENTRY;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, @ENTRY, 0, 0, 58, 1, 0, 0, 0, 'StormRitual', 0, 'Scripted creature has StringId ''StormRitual''');

UPDATE `creature` SET `StringId`='StormRitual' WHERE `guid` IN (@CGUID+16, @CGUID+20, @CGUID+1, @CGUID+12, @CGUID+15, @CGUID+6, @CGUID+197, @CGUID+170, @CGUID+181, @CGUID+174, @CGUID+201, @CGUID+190, @CGUID+206, @CGUID+204, @CGUID+185, @CGUID+218, @CGUID+215, @CGUID+225, @CGUID+216, @CGUID+219, @CGUID+207, @CGUID+211);

-- Temple Attendant smart ai
SET @ENTRY := 134137;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 25, 0, 100, 0, 0, 0, 0, 0, 85, 279908, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Cast spell 279908 on self');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceGroup` = 1 AND `SourceEntry` = @ENTRY;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, @ENTRY, 0, 0, 58, 1, 0, 0, 0, 'WaterChannel', 0, 'Scripted creature has StringId ''WaterChannel''');

UPDATE `creature` SET `StringId`='WaterChannel' WHERE `guid` IN (@CGUID+41, @CGUID+17, @CGUID+161, @CGUID+153);

-- Galecaller Apprentice smart ai
SET @ENTRY := 139800;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` IN (-(@CGUID+202), -(@CGUID+194));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-(@CGUID+202), 0, 0, 0, '', 25, 0, 100, 0, 0, 0, 0, 0, 85, 274649, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Cast spell 274649 on self'),
(-(@CGUID+194), 0, 0, 0, '', 25, 0, 100, 0, 0, 0, 0, 0, 85, 274649, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Cast spell 274649 on self');

-- Abyssal Cultist smart ai
SET @ENTRY := 134514;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` IN (-(@CGUID+244), -(@CGUID+246));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-(@CGUID+244), 0, 0, 0, '', 25, 0, 100, 0, 0, 0, 0, 0, 85, 274285, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Cast spell 274285 on self'),
(-(@CGUID+246), 0, 0, 0, '', 25, 0, 100, 0, 0, 0, 0, 0, 85, 274285, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Cast spell 274285 on self');

-- Windspeaker Heldis smart ai
SET @ENTRY := 136214;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 25, 0, 100, 0, 0, 0, 0, 0, 85, 268195, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Cast spell 268195 on self');

-- Deepsea Ritualist smart ai
SET @ENTRY := 134417;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 25, 0, 100, 0, 0, 0, 0, 0, 85, 274285, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Cast spell 274285 on self');

-- Waypoints for CGUID+158
SET @ENTRY := 134139;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Shrine Templar - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3982.228, -1326.411, 140.5065, NULL, 0),
(@PATH, 1, 3981.4, -1333.346, 140.5431, NULL, 5464),
(@PATH, 2, 3982.228, -1326.411, 140.5065, NULL, 0),
(@PATH, 3, 3982.2, -1319.748, 140.4179, NULL, 0),
(@PATH, 4, 3982.813, -1313.021, 140.3596, NULL, 0),
(@PATH, 5, 3980.753, -1306.694, 140.3596, NULL, 0),
(@PATH, 6, 3975.312, -1301.715, 140.3568, NULL, 5624),
(@PATH, 7, 3980.753, -1306.694, 140.3596, NULL, 0),
(@PATH, 8, 3982.692, -1312.972, 140.3596, NULL, 0),
(@PATH, 9, 3982.2, -1319.748, 140.4179, NULL, 0);

UPDATE `creature` SET `position_x`= 3982.228, `position_y`= -1326.411, `position_z`= 140.5065, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+158;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+158;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@CGUID+158, @PATH, 1, '18950');

-- Waypoints for CGUID+48
SET @ENTRY := 134139;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Shrine Templar - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 4061.463, -1317.661, 160.7747, NULL, 0),
(@PATH, 1, 4070.668, -1320.314, 166.2474, NULL, 0),
(@PATH, 2, 4083.208, -1321.976, 173.6817, NULL, 0),
(@PATH, 3, 4091.705, -1319.849, 177.0662, NULL, 5391),
(@PATH, 4, 4083.208, -1321.976, 173.6817, NULL, 0),
(@PATH, 5, 4070.668, -1320.314, 166.2474, NULL, 0),
(@PATH, 6, 4061.463, -1317.661, 160.7747, NULL, 0),
(@PATH, 7, 4051.2, -1308.214, 152.993, NULL, 0),
(@PATH, 8, 4046.208, -1290.96, 149.3656, NULL, 0),
(@PATH, 9, 4048.438, -1279.166, 149.1877, NULL, 0),
(@PATH, 10, 4057.644, -1262.524, 158.6288, NULL, 0),
(@PATH, 11, 4069.796, -1257.578, 165.9326, NULL, 0),
(@PATH, 12, 4082.718, -1255.377, 173.206, NULL, 0),
(@PATH, 13, 4095.484, -1262.316, 177.093, NULL, 4221),
(@PATH, 14, 4082.718, -1255.377, 173.206, NULL, 0),
(@PATH, 15, 4069.796, -1257.578, 165.9326, NULL, 0),
(@PATH, 16, 4057.644, -1262.524, 158.6288, NULL, 0),
(@PATH, 17, 4048.313, -1279.123, 149.1877, NULL, 0),
(@PATH, 18, 4046.208, -1290.96, 149.3656, NULL, 0),
(@PATH, 19, 4051.2, -1308.214, 152.993, NULL, 0);

UPDATE `creature` SET `position_x`= 4061.463, `position_y`= -1317.661, `position_z`= 160.7747, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+48;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+48;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@CGUID+48, @PATH, 1, '18950');

-- Waypoints for CGUID+4
SET @ENTRY := 134139;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Shrine Templar - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 4164.463, -1288.944, 179.8154, NULL, 0),
(@PATH, 1, 4157.717, -1278.881, 179.8428, NULL, 7123),
(@PATH, 2, 4164.463, -1288.944, 179.8154, NULL, 0),
(@PATH, 3, 4167.143, -1298.083, 179.8814, NULL, 8392);

UPDATE `creature` SET `position_x`= 4164.463, `position_y`= -1288.944, `position_z`= 179.8154, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+4;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+4;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@CGUID+4, @PATH, 1, '18950');

-- Waypoints for CGUID+111
SET @ENTRY := 134139;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Shrine Templar - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3984.913, -1278.408, 140.3596, NULL, 0),
(@PATH, 1, 3982.726, -1271.863, 140.3596, NULL, 0),
(@PATH, 2, 3979.552, -1264.431, 138.7367, NULL, 0),
(@PATH, 3, 3980.4, -1259.571, 134.8521, NULL, 0),
(@PATH, 4, 3981.25, -1256.25, 132.7417, NULL, 0),
(@PATH, 5, 3979.849, -1249.861, 132.7417, NULL, 0),
(@PATH, 6, 3976.994, -1237.813, 133.024, NULL, 0),
(@PATH, 7, 3980.955, -1236.087, 132.7547, NULL, 10619),
(@PATH, 8, 3979.849, -1249.861, 132.7417, NULL, 0),
(@PATH, 9, 3981.311, -1256.201, 132.7417, NULL, 0),
(@PATH, 10, 3980.4, -1259.571, 134.8521, NULL, 0),
(@PATH, 11, 3979.552, -1264.431, 138.7367, NULL, 0),
(@PATH, 12, 3982.726, -1271.863, 140.3596, NULL, 0),
(@PATH, 13, 3984.913, -1278.408, 140.3596, NULL, 0),
(@PATH, 14, 3987.077, -1281.351, 140.3596, NULL, 0),
(@PATH, 15, 3990.329, -1280.163, 140.3596, NULL, 11180);

UPDATE `creature` SET `position_x`= 3984.913, `position_y`= -1278.408, `position_z`= 140.3596, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+111;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+111;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@CGUID+111, @PATH, 1, '18950');

-- Waypoints for CGUID+101
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+101;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+101, @CGUID+101, 0, 0, 515, 0, 0),
(@CGUID+101, @CGUID+106, 3, 0, 515, 0, 0),
(@CGUID+101, @CGUID+115, 6, 0, 515, 0, 0),
(@CGUID+101, @CGUID+118, 9, 0, 515, 0, 0);

SET @ENTRY := 136347;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Tidesage Initiate - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3998.692, -1172.774, 124.1192, NULL, 0),
(@PATH, 1, 3992.261, -1174.417, 124.3381, NULL, 5739),
(@PATH, 2, 3998.692, -1172.774, 124.1192, NULL, 0),
(@PATH, 3, 4009.569, -1170.617, 120.692, NULL, 0),
(@PATH, 4, 4023.702, -1169.679, 114.2523, NULL, 0),
(@PATH, 5, 4038.068, -1173.856, 110.88, NULL, 0),
(@PATH, 6, 4042.945, -1177.129, 110.5562, NULL, 5801),
(@PATH, 7, 4038.173, -1173.927, 110.8573, NULL, 0),
(@PATH, 8, 4023.702, -1169.679, 114.2523, NULL, 0),
(@PATH, 9, 4009.635, -1170.604, 120.6607, NULL, 0);

UPDATE `creature` SET `position_x`= 3998.692, `position_y`= -1172.774, `position_z`= 124.1192, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+101;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+101;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+101, @PATH, 1);

-- Waypoints for CGUID+196
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+196;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+196, @CGUID+196, 0, 0, 515, 0, 0),
(@CGUID+196, @CGUID+205, 3, 270, 515, 7, 0);

SET @ENTRY := 139800;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Galecaller Apprentice - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3941.139, -1088.661, 99.57634, NULL, 4671),
(@PATH, 1, 3946.374, -1086.922, 99.64238, NULL, 0),
(@PATH, 2, 3952.406, -1084.347, 99.66905, NULL, 0),
(@PATH, 3, 3958.18, -1079.066, 99.67625, NULL, 0),
(@PATH, 4, 3962.763, -1073.795, 99.67633, NULL, 0),
(@PATH, 5, 3967.448, -1069.668, 99.77852, NULL, 0),
(@PATH, 6, 3974.032, -1064.266, 99.93215, NULL, 0),
(@PATH, 7, 3978.503, -1058.879, 99.88483, NULL, 4803),
(@PATH, 8, 3971.877, -1067.703, 99.84988, NULL, 0),
(@PATH, 9, 3960.504, -1077.033, 99.67633, NULL, 0),
(@PATH, 10, 3955.291, -1082.965, 99.67493, NULL, 0),
(@PATH, 11, 3946.181, -1086.316, 99.63004, NULL, 0);

UPDATE `creature` SET `position_x`= 3941.139, `position_y`= -1088.661, `position_z`= 99.57634, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+196;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+196;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+196, @PATH, 1);

-- Waypoints for CGUID+203
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+203;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+203, @CGUID+203, 0, 0, 515, 0, 0),
(@CGUID+203, @CGUID+200, 3, 90, 515, 4, 10);

SET @ENTRY := 139800;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Galecaller Apprentice - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3957.858, -1061.75, 100.8703, NULL, 0),
(@PATH, 1, 3951.181, -1063.92, 100.5172, NULL, 0),
(@PATH, 2, 3943.872, -1063.418, 101.248, NULL, 0),
(@PATH, 3, 3934.577, -1056.063, 103.9987, NULL, 7327),
(@PATH, 4, 3932.128, -1046.22, 104.7616, NULL, 0),
(@PATH, 5, 3934.577, -1056.063, 103.9987, NULL, 0),
(@PATH, 6, 3943.872, -1063.418, 101.248, NULL, 0),
(@PATH, 7, 3951.181, -1063.92, 100.5172, NULL, 0),
(@PATH, 8, 3957.858, -1061.75, 100.8703, NULL, 0),
(@PATH, 9, 3960.201, -1055.804, 102.5946, NULL, 0),
(@PATH, 10, 3958.585, -1054.852, 102.8984, NULL, 6901);

UPDATE `creature` SET `position_x`= 3957.858, `position_y`= -1061.75, `position_z`= 100.8703, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+203;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+203;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+203, @PATH, 1);

-- Waypoints for CGUID+249
SET @ENTRY := 134338;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Tidesage Enforcer - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3828.744, -1115.352, 106.2134, NULL, 0),
(@PATH, 1, 3825.7, -1116.116, 107.4653, NULL, 0),
(@PATH, 2, 3817.626, -1113.913, 110.1781, 5.76130, 8460),
(@PATH, 3, 3827.152, -1117.83, 106.038, NULL, 0),
(@PATH, 4, 3831.603, -1114.642, 106.2453, NULL, 0),
(@PATH, 5, 3834.891, -1111.307, 106.3613, NULL, 0),
(@PATH, 6, 3838.988, -1110.004, 106.1781, NULL, 0),
(@PATH, 7, 3844.061, -1109.299, 106.1781, NULL, 0),
(@PATH, 8, 3851.042, -1105.429, 105.7305, NULL, 0),
(@PATH, 9, 3854.884, -1103.054, 105.7305, NULL, 0),
(@PATH, 10, 3863.055, -1097.754, 109.6243, NULL, 0),
(@PATH, 11, 3875.383, -1094.405, 109.8915, NULL, 0),
(@PATH, 12, 3882.674, -1096.039, 109.7732, NULL, 0),
(@PATH, 13, 3887.353, -1095.342, 109.8411, NULL, 0),
(@PATH, 14, 3891.954, -1093.882, 109.9749, NULL, 8297),
(@PATH, 15, 3867.347, -1093.95, 109.7718, NULL, 0),
(@PATH, 16, 3852.694, -1101.188, 105.7305, NULL, 0),
(@PATH, 17, 3841.05, -1109.042, 106.1781, NULL, 0);

UPDATE `creature` SET `position_x`= 3828.744, `position_y`= -1115.352, `position_z`= 106.2134, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+249;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+249;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@CGUID+249, @PATH, 1, '139880 18950');

-- Waypoints for CGUID+267
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+267;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+267, @CGUID+267, 0, 0, 515, 0, 0),
(@CGUID+267, @CGUID+274, 8, 0, 515, 0, 0),
(@CGUID+267, @CGUID+270, 5, 340, 515, 3, 8),
(@CGUID+267, @CGUID+273, 5, 20, 515, 3, 8);

SET @ENTRY := 134514;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Abyssal Cultist - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3654.714, -1301.559, 156.3765, NULL, 0),
(@PATH, 1, 3644.589, -1319.181, 156.6775, NULL, 0),
(@PATH, 2, 3634.121, -1333.335, 156.5206, NULL, 0),
(@PATH, 3, 3621.955, -1339.104, 156.6145, NULL, 0),
(@PATH, 4, 3634.098, -1333.346, 156.564, NULL, 0),
(@PATH, 5, 3644.505, -1319.293, 156.6862, NULL, 0),
(@PATH, 6, 3654.714, -1301.559, 156.3765, NULL, 0),
(@PATH, 7, 3664.103, -1282.727, 156.564, NULL, 0),
(@PATH, 8, 3670.989, -1268.781, 156.5199, NULL, 0),
(@PATH, 9, 3664.103, -1282.727, 156.564, NULL, 0);

UPDATE `creature` SET `position_x`= 3654.714, `position_y`= -1301.559, `position_z`= 156.3765, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+267;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+267;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@CGUID+267, @PATH, 1, '123169');

-- Waypoints for CGUID+250
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+250;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+250, @CGUID+250, 0, 0, 515, 0, 0),
(@CGUID+250, @CGUID+251, 8, 0, 515, 0, 0),
(@CGUID+250, @CGUID+272, 5, 340, 515, 6, 2),
(@CGUID+250, @CGUID+271, 5, 20, 515, 6, 2);

SET @ENTRY := 134514;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Abyssal Cultist - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3663.311, -1310.304, 156.4136, NULL, 0),
(@PATH, 1, 3669.035, -1293.476, 156.5219, NULL, 0),
(@PATH, 2, 3681.753, -1269.875, 156.493, NULL, 5959),
(@PATH, 3, 3669.035, -1293.476, 156.5219, NULL, 0),
(@PATH, 4, 3663.311, -1310.304, 156.4136, NULL, 0),
(@PATH, 5, 3652.892, -1329.51, 156.7121, NULL, 0),
(@PATH, 6, 3647.227, -1350.401, 156.564, NULL, 5980),
(@PATH, 7, 3652.892, -1329.51, 156.7121, NULL, 0);

UPDATE `creature` SET `position_x`= 3663.311, `position_y`= -1310.304, `position_z`= 156.4136, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+250;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+250;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@CGUID+250, @PATH, 1, '123169');
