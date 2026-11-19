SET @CGUID := 9002451;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+78;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 193429, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4120.18603515625, 3788.612060546875, 59.41533279418945312, 0, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47631), -- Ravaged Bruffalon (Area: The Azure Span - Difficulty: 0) (Auras: 383173 - Decaying, 391254 - Hearty)
(@CGUID+1, 187757, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4245.58154296875, 3723.513427734375, 57.18330764770507812, 0.392141669988632202, 120, 4, 0, 5, 0, 1, 0, 0, 0, 47631), -- Rustpine Rabbit (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+2, 187757, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4146.02490234375, 3718.842041015625, 67.443572998046875, 1.39806365966796875, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47631), -- Rustpine Rabbit (Area: The Azure Span - Difficulty: 0)
(@CGUID+3, 187727, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4196.763671875, 3679.353759765625, 68.3452301025390625, 2.251028299331665039, 120, 12, 0, 83980, 0, 1, 0, 0, 0, 47631), -- Rustpine Bruffalon (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+4, 193420, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4131.13037109375, 3749.97021484375, 67.22402191162109375, 3.290900230407714843, 120, 8, 0, 83980, 0, 1, 0, 0, 0, 47631), -- Desiccated Deer (Area: The Azure Span - Difficulty: 0) (Auras: 383173 - Decaying)
(@CGUID+5, 187757, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4134.8056640625, 3890.3681640625, 46.8611907958984375, 1.169708847999572753, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47631), -- Rustpine Rabbit (Area: The Azure Span - Difficulty: 0)
(@CGUID+6, 193420, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4102.2509765625, 3843.943359375, 60.44777679443359375, 5.3697509765625, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47631), -- Desiccated Deer (Area: The Azure Span - Difficulty: 0) (Auras: 383173 - Decaying)
(@CGUID+7, 187757, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4218.1630859375, 3707.8154296875, 60.35422134399414062, 0.916220426559448242, 120, 4, 0, 5, 0, 1, 0, 0, 0, 47631), -- Rustpine Rabbit (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+8, 187757, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4124.04150390625, 3857.887451171875, 52.56474685668945312, 0.223649829626083374, 120, 4, 0, 5, 0, 1, 0, 0, 0, 47631), -- Rustpine Rabbit (Area: The Azure Span - Difficulty: 0)
(@CGUID+9, 193420, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4098.02587890625, 3792.022705078125, 65.55092620849609375, 0, 120, 8, 0, 83980, 0, 1, 0, 0, 0, 47631), -- Desiccated Deer (Area: The Azure Span - Difficulty: 0) (Auras: 383173 - Decaying)
(@CGUID+10, 193430, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4128.12060546875, 3865.72607421875, 51.8271484375, 2.328855514526367187, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47631), -- Prowling Vulture (Area: The Azure Span - Difficulty: 0) (Auras: 383173 - Decaying)
(@CGUID+11, 187757, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4162.00537109375, 3818.15185546875, 55.51680755615234375, 4.276471138000488281, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47631), -- Rustpine Rabbit (Area: The Azure Span - Difficulty: 0)
(@CGUID+12, 193425, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4095.28466796875, 3798.499267578125, 71.06073760986328125, 0, 120, 0, 0, 8, 0, 0, 0, 0, 0, 47631), -- Cricket (Area: The Azure Span - Difficulty: 0)
(@CGUID+13, 187727, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4226.384765625, 3756.464111328125, 54.924407958984375, 2.263534069061279296, 120, 12, 0, 83980, 0, 1, 0, 0, 0, 47631), -- Rustpine Bruffalon (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+14, 192267, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4207.595703125, 3856.0048828125, 45.61467361450195312, 1.458279252052307128, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47631), -- Azure Crystalspine (Area: The Azure Span - Difficulty: 0)
(@CGUID+15, 187757, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4160.173828125, 3821.953125, 54.076934814453125, 4.201463222503662109, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47631), -- Rustpine Rabbit (Area: The Azure Span - Difficulty: 0)
(@CGUID+16, 187727, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4119.22900390625, 3749.15283203125, 68.970947265625, 4.247226238250732421, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47631), -- Rustpine Bruffalon (Area: The Azure Span - Difficulty: 0)
(@CGUID+17, 187757, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4180.283203125, 3859.641357421875, 42.72960281372070312, 5.490964889526367187, 120, 4, 0, 5, 0, 1, 0, 0, 0, 47631), -- Rustpine Rabbit (Area: The Azure Span - Difficulty: 0)
(@CGUID+18, 187727, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4171.62158203125, 3853.869873046875, 43.75977706909179687, 1.181233763694763183, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47631), -- Rustpine Bruffalon (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+19, 187757, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4191.10546875, 3704.166748046875, 65.63587188720703125, 5.293886184692382812, 120, 4, 0, 5, 0, 1, 0, 0, 0, 47631), -- Rustpine Rabbit (Area: The Azure Span - Difficulty: 0)
(@CGUID+20, 187727, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4151.17041015625, 3806.982666015625, 56.21583175659179687, 4.247226238250732421, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47631), -- Rustpine Bruffalon (Area: The Azure Span - Difficulty: 0)
(@CGUID+21, 187754, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4188.55712890625, 3898.7314453125, 66.74208831787109375, 0.294310569763183593, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47631), -- Rustpine Talonfox (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+22, 187754, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4244.29052734375, 3657.9521484375, 99.513671875, 1.340859889984130859, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47631), -- Rustpine Talonfox (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+23, 187727, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4296.29638671875, 3669.0849609375, 55.7472076416015625, 2.526225566864013671, 120, 8, 0, 83980, 0, 1, 0, 0, 0, 47631), -- Rustpine Bruffalon (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+24, 187757, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4266.34130859375, 3704.337890625, 54.36409378051757812, 5.628239631652832031, 120, 4, 0, 5, 0, 1, 0, 0, 0, 47631), -- Rustpine Rabbit (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+25, 187757, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4149.8447265625, 3639.139892578125, 88.70113372802734375, 4.618456363677978515, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47631), -- Rustpine Rabbit (Area: The Azure Span - Difficulty: 0)
(@CGUID+26, 187727, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4220.357421875, 3579.50439453125, 78.24442291259765625, 2.093340396881103515, 120, 8, 0, 83980, 0, 1, 0, 0, 0, 47631), -- Rustpine Bruffalon (Area: The Azure Span - Difficulty: 0)
(@CGUID+27, 187727, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4262.07666015625, 3578.402099609375, 71.2153778076171875, 3.189873456954956054, 120, 12, 0, 83980, 0, 1, 0, 0, 0, 47631), -- Rustpine Bruffalon (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+28, 187757, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4186.8466796875, 3613.635009765625, 80.427886962890625, 5.635136604309082031, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47631), -- Rustpine Rabbit (Area: The Azure Span - Difficulty: 0)
(@CGUID+29, 187757, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4231.771484375, 3605.728515625, 73.741973876953125, 0.033131811767816543, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47631), -- Rustpine Rabbit (Area: The Azure Span - Difficulty: 0)
(@CGUID+30, 187757, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4234.80615234375, 3596.1240234375, 77.9600372314453125, 1.61228954792022705, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47631), -- Rustpine Rabbit (Area: The Azure Span - Difficulty: 0)
(@CGUID+31, 187757, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4329.119140625, 3657.771240234375, 54.44942855834960937, 1.7951812744140625, 120, 4, 0, 5, 0, 1, 0, 0, 0, 47631), -- Rustpine Rabbit (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+32, 187727, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4280.38720703125, 3521.354736328125, 74.8172760009765625, 1.851778388023376464, 120, 8, 0, 83980, 0, 1, 0, 0, 0, 47631), -- Rustpine Bruffalon (Area: The Azure Span - Difficulty: 0)
(@CGUID+33, 192265, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4156.2607421875, 3588.263671875, 95.17342376708984375, 5.156388759613037109, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47631), -- Azure Crystalspine (Area: The Azure Span - Difficulty: 0)
(@CGUID+34, 187727, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4302.19775390625, 3500.776611328125, 75.0316314697265625, 3.170881271362304687, 120, 8, 0, 83980, 0, 1, 0, 0, 0, 47631), -- Rustpine Bruffalon (Area: The Azure Span - Difficulty: 0)
(@CGUID+35, 187727, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4383.75341796875, 3571.92138671875, 59.1820220947265625, 1.474918484687805175, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 47631), -- Rustpine Bruffalon (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+36, 187727, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4318.95166015625, 3447.50537109375, 75.6538848876953125, 5.542677879333496093, 120, 8, 0, 83980, 0, 1, 0, 0, 0, 47631), -- Rustpine Bruffalon (Area: The Azure Span - Difficulty: 0)
(@CGUID+37, 3300, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4360.7216796875, 3592.75634765625, 59.21348190307617187, 4.028293132781982421, 120, 10, 0, 1, 0, 1, 0, 0, 0, 47631), -- Adder (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+38, 187727, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4383.58056640625, 3453.2724609375, 74.66635894775390625, 1.537572979927062988, 120, 8, 0, 83980, 0, 1, 0, 0, 0, 47631), -- Rustpine Bruffalon (Area: The Azure Span - Difficulty: 0)
(@CGUID+39, 187757, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4364.982421875, 3485.21142578125, 72.69753265380859375, 2.141280651092529296, 120, 4, 0, 5, 0, 1, 0, 0, 0, 47631), -- Rustpine Rabbit (Area: The Azure Span - Difficulty: 0)
(@CGUID+40, 187757, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4390.24755859375, 3504.221435546875, 71.80779266357421875, 4.5672760009765625, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47631), -- Rustpine Rabbit (Area: The Azure Span - Difficulty: 0)
(@CGUID+41, 192267, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4309.13623046875, 3417.636962890625, 78.67746734619140625, 4.557513236999511718, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47631), -- Azure Crystalspine (Area: The Azure Span - Difficulty: 0)
(@CGUID+42, 187790, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4358.40625, 3409.579833984375, 78.27117919921875, 2.1483001708984375, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47631), -- River Timbertooth (Area: The Azure Span - Difficulty: 0)
(@CGUID+43, 192003, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4509.2587890625, 3430.50439453125, 19.30231666564941406, 4.660608768463134765, 120, 0, 0, 251940, 0, 0, 0, 0, 0, 47631), -- Bloodhorn (Area: The Azure Span - Difficulty: 0)
(@CGUID+44, 192044, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4362.8203125, 3345.48193359375, 67.5835113525390625, 3.931891679763793945, 120, 2, 0, 5, 0, 1, 0, 0, 0, 47631), -- Tiny Timbertooth (Area: The Azure Span - Difficulty: 0)
(@CGUID+45, 187790, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4373.42724609375, 3349.65283203125, 67.90110015869140625, 3.616441965103149414, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47631), -- River Timbertooth (Area: The Azure Span - Difficulty: 0)
(@CGUID+46, 187790, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4374.88720703125, 3343.944580078125, 67.4484100341796875, 3.814326286315917968, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47631), -- River Timbertooth (Area: The Azure Span - Difficulty: 0)
(@CGUID+47, 187790, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4388.60791015625, 3343.786376953125, 68.65384674072265625, 1.055991888046264648, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47631), -- River Timbertooth (Area: The Azure Span - Difficulty: 0)
(@CGUID+48, 187790, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4416.904296875, 3370.470947265625, 68.34241485595703125, 1.541148185729980468, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 47631), -- River Timbertooth (Area: The Azure Span - Difficulty: 0)
(@CGUID+49, 189218, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4013.541748046875, 3412.723876953125, 155.760406494140625, 1.072658419609069824, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47631), -- Highland Mammoth (Area: The Azure Span - Difficulty: 0)
(@CGUID+50, 189218, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3919.132080078125, 3474.341064453125, 166.391998291015625, 0.373136550188064575, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47631), -- Highland Mammoth (Area: The Azure Span - Difficulty: 0)
(@CGUID+51, 189221, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3989.6962890625, 3372.185791015625, 154.888458251953125, 0, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 47631), -- Highland Mammoth Calf (Area: The Azure Span - Difficulty: 0)
(@CGUID+52, 192028, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3996.40283203125, 3366.845947265625, 155.2830810546875, 1.067396879196166992, 120, 2, 0, 5, 0, 1, 0, 0, 0, 47631), -- Trunkalumpf (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+53, 189218, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4042.45703125, 3310.96484375, 152.7896575927734375, 4.688956260681152343, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47631), -- Highland Mammoth (Area: The Azure Span - Difficulty: 0) (Auras: 391254 - Hearty) (possible waypoints or random movement)
(@CGUID+54, 189218, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3984.942626953125, 3371.03564453125, 156.0508880615234375, 4.859528541564941406, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47631), -- Highland Mammoth (Area: The Azure Span - Difficulty: 0)
(@CGUID+55, 191544, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3875.019775390625, 3368.732421875, 172.30072021484375, 5.878037452697753906, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47631), -- Brambledoe (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+56, 189218, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3993.373291015625, 3370.359375, 154.8839263916015625, 5.775967121124267578, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47631), -- Highland Mammoth (Area: The Azure Span - Difficulty: 0)
(@CGUID+57, 189220, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3928.622802734375, 3342.806884765625, 165.9322357177734375, 2.546547889709472656, 120, 12, 0, 167960, 0, 1, 0, 0, 0, 47631), -- Highland Mammoth Bull (Area: The Azure Span - Difficulty: 0)
(@CGUID+58, 189220, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3981.733642578125, 3533.166259765625, 154.433746337890625, 3.037763833999633789, 120, 12, 0, 167960, 0, 1, 0, 0, 0, 47631), -- Highland Mammoth Bull (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+59, 189221, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3948.673828125, 3444.620361328125, 161.886627197265625, 4.465752601623535156, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 47631), -- Highland Mammoth Calf (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+60, 189221, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3916.4130859375, 3460.83642578125, 168.6125030517578125, 2.995864391326904296, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 47631), -- Highland Mammoth Calf (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+61, 189221, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3950.153564453125, 3439.91552734375, 162.0710601806640625, 4.387196063995361328, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 47631), -- Highland Mammoth Calf (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+62, 191529, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3872.35009765625, 3370.022705078125, 172.3065948486328125, 5.746114730834960937, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47631), -- Bramblestag (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+63, 189218, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3951.802001953125, 3435.188232421875, 162.3841705322265625, 4.359447002410888671, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47631), -- Highland Mammoth (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+64, 191544, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3873.559326171875, 3372.466064453125, 171.95281982421875, 5.937666893005371093, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47631), -- Brambledoe (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+65, 189221, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4013.27392578125, 3402.9072265625, 155.2221527099609375, 4.936991691589355468, 120, 4, 0, 41990, 0, 1, 0, 0, 0, 47631), -- Highland Mammoth Calf (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+66, 189221, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4016.585205078125, 3413.717041015625, 155.272064208984375, 0, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 47631), -- Highland Mammoth Calf (Area: The Azure Span - Difficulty: 0)
(@CGUID+67, 3300, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3985.868408203125, 3455.7822265625, 155.0193939208984375, 2.573959827423095703, 120, 0, 0, 1, 0, 0, 0, 0, 0, 47631), -- Adder (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+68, 189221, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4047.532958984375, 3316.828857421875, 151.5925750732421875, 2.291855812072753906, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 47631), -- Highland Mammoth Calf (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+69, 189221, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4054.1435546875, 3317.187255859375, 152.3570556640625, 2.363785743713378906, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 47631), -- Highland Mammoth Calf (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+70, 189220, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4147.4638671875, 3374.601318359375, 146.7886810302734375, 1.024007439613342285, 120, 12, 0, 167960, 0, 1, 0, 0, 0, 47631), -- Highland Mammoth Bull (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+71, 189218, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4087.802001953125, 3297.6025390625, 152.172698974609375, 5.713979721069335937, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47631), -- Highland Mammoth (Area: The Azure Span - Difficulty: 0)
(@CGUID+72, 189221, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4089.571044921875, 3300.142578125, 152.357086181640625, 3.428746461868286132, 120, 4, 0, 41990, 0, 1, 0, 0, 0, 47631), -- Highland Mammoth Calf (Area: The Azure Span - Difficulty: 0)
(@CGUID+73, 192028, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4081.855224609375, 3303.9833984375, 152.992523193359375, 1.123053312301635742, 120, 2, 0, 5, 0, 1, 0, 0, 0, 47631), -- Trunkalumpf (Area: The Azure Span - Difficulty: 0)
(@CGUID+74, 192044, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4050.164794921875, 3274.491943359375, 151.4736328125, 2.639418363571166992, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47631), -- Tiny Timbertooth (Area: The Azure Span - Difficulty: 0)
(@CGUID+75, 3300, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4209.978515625, 3395.279052734375, 151.0926055908203125, 2.670952081680297851, 120, 10, 0, 1, 0, 1, 0, 0, 0, 47631), -- Adder (Area: The Azure Span - Difficulty: 0)
(@CGUID+76, 3300, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4109.955078125, 3447.342041015625, 133.4162445068359375, 2.258036613464355468, 120, 10, 0, 1, 0, 1, 0, 0, 0, 47631), -- Adder (Area: The Azure Span - Difficulty: 0)
(@CGUID+77, 189221, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3916.3955078125, 3473.293701171875, 167.0562896728515625, 6.016419410705566406, 120, 4, 0, 41990, 0, 1, 0, 0, 0, 47631), -- Highland Mammoth Calf (Area: The Azure Span - Difficulty: 0)
(@CGUID+78, 193223, 2444, 13646, 13646, '0', 0, 0, 0, 1, -3962.046142578125, 3602.405517578125, 152.6061248779296875, 5.985897541046142578, 120, 0, 0, 523080, 0, 0, 0, 0, 0, 47631); -- Vakril (Area: The Azure Span - Difficulty: 0)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+78;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+16, 0, 0, 0, 0, 0, 1, 0, 64, 0, 0, 0, 0, ''), -- Rustpine Bruffalon
(@CGUID+20, 0, 0, 0, 0, 0, 1, 0, 64, 0, 0, 0, 0, ''), -- Rustpine Bruffalon
(@CGUID+42, 0, 0, 0, 0, 0, 1, 0, 438, 0, 0, 0, 0, ''), -- River Timbertooth
(@CGUID+45, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- River Timbertooth
(@CGUID+47, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''); -- River Timbertooth

DELETE FROM `creature_template_addon` WHERE `entry` IN (193223 /*193223 (Vakril)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(193223, 0, 110986, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 193223 (Vakril)

-- Creature Template
UPDATE `creature_template` SET `faction`=188, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=192044; -- Tiny Timbertooth
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=192003; -- Bloodhorn
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=187790; -- River Timbertooth
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=187754; -- Rustpine Talonfox
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=187727; -- Rustpine Bruffalon
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=187757; -- Rustpine Rabbit
UPDATE `creature_template` SET `minlevel`=69, `maxlevel`=69, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=193223; -- Vakril
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=189220; -- Highland Mammoth Bull
UPDATE `creature_template` SET `faction`=188, `speed_walk`=0.400000005960464477, `speed_run`=0.285714298486709594, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=192028; -- Trunkalumpf
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=188, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=189221; -- Highland Mammoth Calf
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=2136, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=189218; -- Highland Mammoth

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=193223 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(193223, 1, 192157, 0, 0, 0, 0, 0, 0, 0, 0, 47631); -- Vakril

DELETE FROM `creature_template_movement` WHERE `CreatureID` = 187754;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(187754, 0, 0, 1, 0, 0, 0, NULL);

-- Waypoints for Vakril
SET @PATH := (@CGUID+78) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3915.465, 3647.183, 148.4491, NULL, 0),
(@PATH, 1, -3933.392, 3648.151, 148.1405, NULL, 0),
(@PATH, 2, -3960.405, 3636.407, 150.4934, NULL, 0),
(@PATH, 3, -3968.281, 3619.698, 150.0326, NULL, 0),
(@PATH, 4, -3962.99, 3602.695, 152.7204, NULL, 0),
(@PATH, 5, -3937.083, 3594.763, 153.0828, NULL, 0),
(@PATH, 6, -3919.781, 3597.401, 153.701, NULL, 0),
(@PATH, 7, -3911.361, 3613.518, 154.3172, NULL, 0),
(@PATH, 8, -3910.675, 3630.032, 150.4398, NULL, 0);

UPDATE `creature` SET `position_x`= -3915.465, `position_y`= 3647.183, `position_z`= 148.4491, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+78;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+78;
INSERT INTO `creature_addon` (`guid`, `mount`, `path_id`, `SheathState`) VALUES
(@CGUID+78, 110986, @PATH, 1);

-- Waypoints for CGUID+63
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+63;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+63, @CGUID+63, 0, 0, 515, 0, 0),
(@CGUID+63, @CGUID+61, 4, 0, 515, 0, 0),
(@CGUID+63, @CGUID+59, 8, 0, 515, 0, 0);

SET @PATH := (@CGUID+63) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3971.462, 3437.425, 157.4792, NULL, 5215),
(@PATH, 1, -3965.342, 3454.301, 156.3917, NULL, 0),
(@PATH, 2, -3962.991, 3458.232, 158.0059, NULL, 10087),
(@PATH, 3, -3948.299, 3444.698, 161.8736, NULL, 7491),
(@PATH, 4, -3955.559, 3424.99, 161.1669, NULL, 8827),
(@PATH, 5, -3968.738, 3425.534, 159.1675, NULL, 0),
(@PATH, 6, -3968.517, 3434.425, 157.7997, NULL, 0);

UPDATE `creature` SET `position_x`= -3971.462, `position_y`= 3437.425, `position_z`= 157.4792, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+63;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+63;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+63, @PATH, 1);

-- Waypoints for CGUID+62
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+62;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+62, @CGUID+62, 0, 0, 515, 0, 0),
(@CGUID+62, @CGUID+64, 3, 60, 515, 0, 0),
(@CGUID+62, @CGUID+55, 3, 300, 515, 0, 0);

SET @PATH := (@CGUID+62) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3903.587, 3366.257, 169.078, NULL, 0),
(@PATH, 1, -3912.71, 3365.724, 169.3555, NULL, 0),
(@PATH, 2, -3929.12, 3362.429, 165.6958, NULL, 0),
(@PATH, 3, -3935.443, 3366.945, 165.3403, NULL, 0),
(@PATH, 4, -3943.53, 3373.975, 163.4997, NULL, 0),
(@PATH, 5, -3960.559, 3380.749, 159.4094, NULL, 0),
(@PATH, 6, -3943.53, 3373.975, 163.4997, NULL, 0),
(@PATH, 7, -3935.443, 3366.945, 165.3403, NULL, 0),
(@PATH, 8, -3929.12, 3362.429, 165.6958, NULL, 0),
(@PATH, 9, -3912.71, 3365.724, 169.3555, NULL, 0),
(@PATH, 10, -3903.587, 3366.257, 169.078, NULL, 0),
(@PATH, 11, -3890.644, 3367.269, 170.0567, NULL, 0),
(@PATH, 12, -3874.826, 3371.497, 171.9953, NULL, 0),
(@PATH, 13, -3865.266, 3365.797, 172.7985, NULL, 0),
(@PATH, 14, -3858.467, 3359.603, 174.2962, NULL, 0),
(@PATH, 15, -3855.344, 3342.622, 174.4128, NULL, 0),
(@PATH, 16, -3852.608, 3332.962, 175.7695, NULL, 0),
(@PATH, 17, -3855.342, 3342.581, 174.4648, NULL, 0),
(@PATH, 18, -3858.467, 3359.603, 174.2962, NULL, 0),
(@PATH, 19, -3865.266, 3365.797, 172.7985, NULL, 0),
(@PATH, 20, -3874.719, 3371.426, 171.9464, NULL, 0),
(@PATH, 21, -3890.644, 3367.269, 170.0567, NULL, 0);

UPDATE `creature` SET `position_x`= -3903.587, `position_y`= 3366.257, `position_z`= 169.078, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+62;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+62;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+62, @PATH, 1);

-- Waypoints for CGUID+53
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+53;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+53, @CGUID+53, 0, 0, 515, 0, 0),
(@CGUID+53, @CGUID+68, 4, 0, 515, 0, 0),
(@CGUID+53, @CGUID+69, 4, 90, 515, 0, 0);

SET @PATH := (@CGUID+53) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -4042.519, 3330.958, 153.4669, NULL, 0),
(@PATH, 1, -4042.176, 3322.965, 153.4147, NULL, 0),
(@PATH, 2, -4042.457, 3310.965, 152.7897, NULL, 13358),
(@PATH, 3, -4060.698, 3331.966, 153.0738, NULL, 0),
(@PATH, 4, -4060.142, 3345.81, 151.1599, NULL, 0),
(@PATH, 5, -4051.29, 3353.95, 150.7469, NULL, 17296),
(@PATH, 6, -4042.853, 3348.493, 150.161, NULL, 0),
(@PATH, 7, -4039.715, 3342.156, 150.7405, NULL, 0),
(@PATH, 8, -4038.559, 3334.903, 151.721, NULL, 0),
(@PATH, 9, -4036.47, 3333.661, 151.9563, NULL, 17043);

UPDATE `creature` SET `position_x`= -4042.519, `position_y`= 3330.958, `position_z`= 153.4669, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+53;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+53;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+53, @PATH, 1);

-- Waypoints for CGUID+18
SET @PATH := (@CGUID+18) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -4175.035, 3845.753, 45.48207, NULL, 0),
(@PATH, 1, -4176.34, 3830.463, 49.15138, NULL, 0),
(@PATH, 2, -4179.354, 3800.445, 51.82985, NULL, 0),
(@PATH, 3, -4183.446, 3782.476, 53.5034, NULL, 0),
(@PATH, 4, -4189.929, 3767.972, 54.61033, NULL, 6683),
(@PATH, 5, -4183.446, 3782.476, 53.5034, NULL, 0),
(@PATH, 6, -4179.354, 3800.445, 51.82985, NULL, 0),
(@PATH, 7, -4176.34, 3830.463, 49.15138, NULL, 0),
(@PATH, 8, -4175.035, 3845.753, 45.48207, NULL, 0),
(@PATH, 9, -4171.622, 3853.87, 43.75978, NULL, 7905);

UPDATE `creature` SET `position_x`= -4175.035, `position_y`= 3845.753, `position_z`= 45.48207, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+18;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+18;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+18, @PATH, 1);

-- Waypoints for CGUID+15
SET @PATH := (@CGUID+15) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -4158.486, 3839.693, 49.29362, NULL, 0),
(@PATH, 1, -4158.759, 3835.24, 50.61802, NULL, 0),
(@PATH, 2, -4159.043, 3831.253, 51.62481, NULL, 0),
(@PATH, 3, -4159.552, 3827.565, 52.36161, NULL, 0),
(@PATH, 4, -4160.427, 3825.214, 52.64017, NULL, 0),
(@PATH, 5, -4160.174, 3821.953, 54.07693, NULL, 19749),
(@PATH, 6, -4159.552, 3827.565, 52.36161, NULL, 0),
(@PATH, 7, -4159.043, 3831.253, 51.62481, NULL, 0),
(@PATH, 8, -4158.759, 3835.24, 50.61802, NULL, 0),
(@PATH, 9, -4158.486, 3839.693, 49.29362, NULL, 0),
(@PATH, 10, -4158.827, 3844.283, 47.81969, NULL, 15671);

UPDATE `creature` SET `position_x`= -4158.486, `position_y`= 3839.693, `position_z`= 49.29362, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+15;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+15;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+15, @PATH, 1);

-- Waypoints for CGUID+46
SET @PATH := (@CGUID+46) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -4366.832, 3351.495, 67.86259, NULL, 0),
(@PATH, 1, -4369.549, 3348.204, 67.70964, NULL, 0),
(@PATH, 2, -4374.887, 3343.945, 67.44841, NULL, 12696),
(@PATH, 3, -4369.549, 3348.204, 67.70964, NULL, 0),
(@PATH, 4, -4366.832, 3351.495, 67.86259, NULL, 0),
(@PATH, 5, -4365.943, 3356.132, 67.95851, NULL, 0),
(@PATH, 6, -4364.906, 3363.52, 69.90089, NULL, 0),
(@PATH, 7, -4365.007, 3371.861, 73.89365, NULL, 0),
(@PATH, 8, -4363.33, 3383.603, 74.43137, NULL, 0),
(@PATH, 9, -4360.806, 3395.668, 77.56455, NULL, 0),
(@PATH, 10, -4360.094, 3406.55, 78.42621, NULL, 16118),
(@PATH, 11, -4360.806, 3395.668, 77.56455, NULL, 0),
(@PATH, 12, -4363.33, 3383.603, 74.43137, NULL, 0),
(@PATH, 13, -4365.007, 3371.861, 73.89365, NULL, 0),
(@PATH, 14, -4364.906, 3363.52, 69.90089, NULL, 0),
(@PATH, 15, -4365.943, 3356.132, 67.95851, NULL, 0);

UPDATE `creature` SET `position_x`= -4366.832, `position_y`= 3351.495, `position_z`= 67.86259, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+46;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+46;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+46, @PATH, 1);
