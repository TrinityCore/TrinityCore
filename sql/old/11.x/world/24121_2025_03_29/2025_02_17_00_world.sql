SET @CGUID := 10005952;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+122;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 218401, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2879.288330078125, -3369.052001953125, 211.8834228515625, 5.901498794555664062, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Scavenging Stormfang (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+1, 220297, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2873.420166015625, -3428.407958984375, 208.015625, 3.503129243850708007, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Tiny Marmot (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+2, 220297, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2908.882080078125, -3407.189208984375, 208.335662841796875, 0.988451063632965087, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Tiny Marmot (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+3, 220295, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2860.21875, -3423.270751953125, 239.3150787353515625, 2.861058235168457031, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Fallside Falcon (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+4, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2935.362060546875, -3373.6806640625, 207.64678955078125, 4.70092630386352539, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+5, 220297, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2847.859375, -3405.392333984375, 232.218536376953125, 3.338391542434692382, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Tiny Marmot (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+6, 220297, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2914.471435546875, -3429.088623046875, 205.180755615234375, 0, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Tiny Marmot (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+7, 220297, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2864.569580078125, -3376.078125, 215.4494171142578125, 2.392375946044921875, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Tiny Marmot (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+8, 220297, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2856.115478515625, -3393.607666015625, 227.8949127197265625, 1.978889822959899902, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Tiny Marmot (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+9, 220297, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2901.326416015625, -3383.52783203125, 210.96697998046875, 5.264388084411621093, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Tiny Marmot (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+10, 220297, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2782.728271484375, -3524.32470703125, 195.067535400390625, 1.734946608543395996, 120, 5, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Tiny Marmot (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+11, 218401, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2796.952392578125, -3531.960205078125, 197.055206298828125, 5.8144073486328125, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Scavenging Stormfang (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+12, 218401, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2889.7734375, -3444.140625, 202.063873291015625, 4.013400077819824218, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Scavenging Stormfang (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+13, 216017, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2846.767333984375, -3498.270751953125, 195.437408447265625, 5.748039722442626953, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Great Stormfang (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+14, 220297, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2793.225830078125, -3439.65625, 201.230926513671875, 0.468191683292388916, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Tiny Marmot (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+15, 218401, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2779.74658203125, -3506.729248046875, 193.6425018310546875, 6.155102252960205078, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Scavenging Stormfang (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+16, 216017, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2795.60595703125, -3459.73095703125, 194.2233734130859375, 3.461181879043579101, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Great Stormfang (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+17, 218401, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2795.60595703125, -3459.73095703125, 194.2233734130859375, 4.236378192901611328, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Scavenging Stormfang (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+18, 218401, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2854.791748046875, -3424.12841796875, 207.0225677490234375, 0.694332063198089599, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Scavenging Stormfang (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+19, 216017, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2779.333251953125, -3426.873291015625, 192.584136962890625, 1.84086310863494873, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Great Stormfang (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: 78677 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+20, 220297, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2792.366455078125, -3424.192626953125, 198.564605712890625, 6.003740787506103515, 120, 5, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Tiny Marmot (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+21, 226299, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2981.330810546875, -3564.34033203125, 195.3568572998046875, 1.261316776275634765, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Anub'esska (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: 258096 - Submerged)
(@CGUID+22, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2971.990478515625, -3436.892333984375, 197.94677734375, 0.844823062419891357, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+23, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2978.583251953125, -3445.913330078125, 195.980224609375, 3.82739114761352539, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+24, 221519, 2552, 14717, 14717, '0', 0, 0, 0, 0, 3122.90966796875, -3605.59375, 173.52569580078125, 1.178087353706359863, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Fluttering Sapphire (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+25, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 3127.98779296875, -3700.125, 181.608428955078125, 1.529012441635131835, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+26, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 3102.5087890625, -3558.2275390625, 172.9474334716796875, 1.504163980484008789, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+27, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 3133.45751953125, -3635.94970703125, 167.273406982421875, 4.194242000579833984, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+28, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 3191.95654296875, -3567.91845703125, 164.4259033203125, 3.821049213409423828, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+29, 219263, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2985.100341796875, -3280.651611328125, 216.423858642578125, 2.110545635223388671, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Warphorn (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+30, 214772, 2552, 14717, 14717, '0', 0, 0, 0, 0, 3039.4609375, -3219.484375, 264.294281005859375, 3.221493244171142578, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Limestone Falcon (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+31, 214772, 2552, 14717, 14717, '0', 0, 0, 0, 0, 3038.978271484375, -3209.958251953125, 253.7310638427734375, 1.81726694107055664, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Limestone Falcon (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+32, 214772, 2552, 14717, 14717, '0', 0, 0, 0, 0, 3019.365478515625, -3245.670166015625, 233.6047821044921875, 2.897212505340576171, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Limestone Falcon (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+33, 214764, 2552, 14717, 14717, '0', 0, 0, 0, 0, 3002.075439453125, -3219.647705078125, 228.689361572265625, 3.678160429000854492, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Rustmane Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+34, 214772, 2552, 14717, 14717, '0', 0, 0, 0, 0, 3055.34716796875, -3226.25, 264.936187744140625, 0.380276501178741455, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Limestone Falcon (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+35, 214764, 2552, 14717, 14717, '0', 0, 0, 0, 0, 3007.968017578125, -3201.921875, 226.2640533447265625, 2.136946439743041992, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Rustmane Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+36, 214772, 2552, 14717, 14717, '0', 0, 0, 0, 0, 3013.40185546875, -3223.717041015625, 253.538238525390625, 5.063347339630126953, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Limestone Falcon (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+37, 214772, 2552, 14717, 14717, '0', 0, 0, 0, 0, 3048.724853515625, -3201.84033203125, 249.37347412109375, 0.798186659812927246, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Limestone Falcon (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+38, 214772, 2552, 14717, 14717, '0', 0, 0, 0, 0, 3040.368896484375, -3234.552001953125, 272.649383544921875, 1.522764801979064941, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Limestone Falcon (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+39, 214764, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2990.1171875, -3228.632080078125, 223.9555511474609375, 1.835830926895141601, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Rustmane Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+40, 214764, 2552, 14717, 14717, '0', 0, 0, 0, 0, 3104.0478515625, -3226.548583984375, 207.0823211669921875, 3.138810157775878906, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Rustmane Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+41, 214764, 2552, 14717, 14717, '0', 0, 0, 0, 0, 3023.90185546875, -3311.517333984375, 212.44268798828125, 2.4339752197265625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Rustmane Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+42, 214764, 2552, 14717, 14717, '0', 0, 0, 0, 0, 3014.720458984375, -3310.71875, 211.498504638671875, 5.415879249572753906, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Rustmane Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+43, 214764, 2552, 14717, 14717, '0', 0, 0, 0, 0, 3097.353271484375, -3240.454833984375, 211.3101348876953125, 0.197769001126289367, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Rustmane Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+44, 214764, 2552, 14717, 14717, '0', 0, 0, 0, 0, 3103.684814453125, -3217.760498046875, 205.9244384765625, 5.235593795776367187, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Rustmane Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+45, 214764, 2552, 14717, 14717, '0', 0, 0, 0, 0, 3022.125, -3292.548583984375, 217.60833740234375, 3.678160429000854492, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Rustmane Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+46, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 3079.40625, -3342.4619140625, 198.9085845947265625, 2.800868034362792968, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+47, 226296, 2552, 14717, 14717, '0', 0, 0, 0, 0, 3167.68408203125, -3434.288330078125, 173.232940673828125, 6.163871288299560546, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Adolescent Darkwolf (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+48, 226295, 2552, 14717, 14717, '0', 0, 0, 0, 0, 3170.48779296875, -3443.385498046875, 171.0607452392578125, 0.096670612692832946, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Stormscar (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+49, 226296, 2552, 14717, 14717, '0', 0, 0, 0, 0, 3159.615478515625, -3443.640625, 173.9820098876953125, 0.001128647709265351, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Adolescent Darkwolf (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+50, 226296, 2552, 14717, 14717, '0', 0, 0, 0, 0, 3169.3056640625, -3451.736083984375, 170.7452239990234375, 0.301144927740097045, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Adolescent Darkwolf (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+51, 212368, 2552, 14717, 14717, '0', 0, 0, 0, 0, 3262.967041015625, -3261.897705078125, 178.1123809814453125, 4.893528938293457031, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Stormtop Shalemaw Young (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+52, 212368, 2552, 14717, 14717, '0', 0, 0, 0, 0, 3256.8369140625, -3260.157958984375, 179.2256927490234375, 1.033146977424621582, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Stormtop Shalemaw Young (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+53, 212368, 2552, 14717, 14717, '0', 0, 0, 0, 0, 3257.885498046875, -3267.748291015625, 177.541656494140625, 1.953863263130187988, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Stormtop Shalemaw Young (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+54, 212364, 2552, 14717, 14717, '0', 0, 0, 0, 0, 3305.491455078125, -3242.02783203125, 170.3910369873046875, 0.779683947563171386, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Stormtop Shalemaw (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+55, 212364, 2552, 14717, 14717, '0', 0, 0, 0, 0, 3210.337646484375, -3227.322998046875, 194.7045745849609375, 0.73504871129989624, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Stormtop Shalemaw (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+56, 212368, 2552, 14717, 14717, '0', 0, 0, 0, 0, 3245.8447265625, -3199.73095703125, 184.1614532470703125, 0.665777206420898437, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Stormtop Shalemaw Young (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+57, 212368, 2552, 14717, 14717, '0', 0, 0, 0, 0, 3246.893310546875, -3207.3212890625, 185.4722137451171875, 3.910019874572753906, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Stormtop Shalemaw Young (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+58, 212368, 2552, 14717, 14717, '0', 0, 0, 0, 0, 3251.974853515625, -3201.470458984375, 183.001739501953125, 2.38348555564880371, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Stormtop Shalemaw Young (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+59, 212364, 2552, 14717, 14717, '0', 0, 0, 0, 0, 3245.3056640625, -3288.18408203125, 180.41973876953125, 0.14131021499633789, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Stormtop Shalemaw (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+60, 226297, 2552, 14717, 14717, '0', 0, 0, 0, 0, 3303.186767578125, -3077.98779296875, 255.00384521484375, 0.422500491142272949, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Fallen Mage Essence (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+61, 226298, 2552, 14717, 14717, '0', 0, 0, 0, 0, 3308.186767578125, -3076.57470703125, 254.7518157958984375, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Mage Slayer Phytethil (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+62, 226297, 2552, 14717, 14717, '0', 0, 0, 0, 0, 3311.970458984375, -3074.194580078125, 254.8523712158203125, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Fallen Mage Essence (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+63, 222738, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1956.2222900390625, -3390.75341796875, 113.04150390625, 2.22328352928161621, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Troglofrog (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+64, 222199, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2028.513916015625, -3469.927001953125, 113.7823257446289062, 4.103372097015380859, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Spring Waddler (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+65, 221520, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2075.3525390625, -3468.06591796875, 110.0474929809570312, 5.072587966918945312, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Puddle Skipper (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+66, 222199, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2006.9600830078125, -3457.46875, 114.9628372192382812, 5.834802627563476562, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Spring Waddler (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+67, 225311, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1991.6180419921875, -3574.802001953125, 122.83160400390625, 1.142637252807617187, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Plainswalker Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+68, 221519, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1952.7274169921875, -3567.470458984375, 139.0711822509765625, 1.178087353706359863, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Fluttering Sapphire (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+69, 225311, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1994.28125, -3569.208251953125, 123.265625, 4.236411094665527343, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Plainswalker Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+70, 225268, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2007.3228759765625, -3471.18408203125, 118.2533950805664062, 0.472649037837982177, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Plainswalker Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+71, 221520, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2002.3367919921875, -3428.890625, 112.944488525390625, 0.58742755651473999, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Puddle Skipper (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+72, 225268, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1977.7708740234375, -3464.635498046875, 118.1291122436523437, 2.633289337158203125, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Plainswalker Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+73, 221644, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1999.8021240234375, -3457.354248046875, 131.301788330078125, 5.105088233947753906, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Soaring Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+74, 222199, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1945.2603759765625, -3593.34033203125, 119.393585205078125, 5.109650611877441406, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Spring Waddler (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+75, 225268, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1957.8125, -3532.045166015625, 121.3981552124023437, 6.042764186859130859, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Plainswalker Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+76, 225268, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2013.484375, -3614.416748046875, 120.908477783203125, 2.086555004119873046, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Plainswalker Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+77, 225268, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1926.74658203125, -3736.39404296875, 105.4124832153320312, 4.073150634765625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Plainswalker Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+78, 222199, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1972.392333984375, -3683.4375, 110.7212371826171875, 3.26992654800415039, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Spring Waddler (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+79, 221644, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1941.19970703125, -3684.635498046875, 128.2798614501953125, 4.908735275268554687, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Soaring Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+80, 222199, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1986.8211669921875, -3696.501708984375, 106.875885009765625, 1.571250081062316894, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Spring Waddler (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+81, 225268, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1917.326416015625, -3671.708251953125, 112.8922195434570312, 3.938209056854248046, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Plainswalker Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+82, 221519, 2552, 14717, 14782, '0', 0, 0, 0, 0, 2953.786376953125, -3878.317626953125, 139.985076904296875, 5.105098247528076171, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Fluttering Sapphire (Area: Ironwold - Difficulty: 0) CreateObject2
(@CGUID+83, 221524, 2552, 14717, 14782, '0', 0, 0, 0, 0, 2948.478271484375, -3900.02783203125, 117.7931594848632812, 5.155231475830078125, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Gemwing (Area: Ironwold - Difficulty: 0) CreateObject2
(@CGUID+84, 221524, 2552, 14717, 14782, '0', 0, 0, 0, 0, 3002.798583984375, -3935.333251953125, 117.6810760498046875, 2.778733253479003906, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Gemwing (Area: Ironwold - Difficulty: 0) CreateObject2
(@CGUID+85, 227122, 2552, 14717, 14782, '0', 0, 0, 0, 0, 2898.5791015625, -3904.10595703125, 117.0978469848632812, 6.246301174163818359, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Forest Ferret (Area: Ironwold - Difficulty: 0) CreateObject2
(@CGUID+86, 221524, 2552, 14717, 14782, '0', 0, 0, 0, 0, 2900.635498046875, -4008.013916015625, 101.5556640625, 5.107189655303955078, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Gemwing (Area: Ironwold - Difficulty: 0) CreateObject2
(@CGUID+87, 221524, 2552, 14717, 14782, '0', 0, 0, 0, 0, 2863.2431640625, -3979.317626953125, 102.83001708984375, 3.022929668426513671, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Gemwing (Area: Ironwold - Difficulty: 0) CreateObject2
(@CGUID+88, 227122, 2552, 14717, 14782, '0', 0, 0, 0, 0, 2937.014892578125, -3969.6875, 106.286834716796875, 4.092607498168945312, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Forest Ferret (Area: Ironwold - Difficulty: 0) CreateObject2
(@CGUID+89, 227122, 2552, 14717, 14782, '0', 0, 0, 0, 0, 2798.256103515625, -4006.923583984375, 99.079986572265625, 2.040009737014770507, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Forest Ferret (Area: Ironwold - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+90, 221524, 2552, 14717, 14837, '0', 0, 0, 0, 0, 2635.243896484375, -3996.991455078125, 102.6920928955078125, 6.239459514617919921, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Gemwing (Area: Durgaz Cabin - Difficulty: 0) CreateObject2
(@CGUID+91, 221524, 2552, 14717, 14837, '0', 0, 0, 0, 0, 2695.8525390625, -4022.944580078125, 99.867095947265625, 3.892253637313842773, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Gemwing (Area: Durgaz Cabin - Difficulty: 0) CreateObject2
(@CGUID+92, 223098, 2552, 14717, 14782, '0', 0, 0, 0, 0, 2753.52783203125, -4116.8994140625, 81.66271209716796875, 3.001559019088745117, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Cobalt Ramolith (Area: Ironwold - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+93, 227122, 2552, 14717, 14782, '0', 0, 0, 0, 0, 2776.85498046875, -4124.828125, 72.83927154541015625, 5.750719070434570312, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Forest Ferret (Area: Ironwold - Difficulty: 0) CreateObject2
(@CGUID+94, 213698, 2552, 14717, 14782, '0', 0, 0, 0, 0, 2491.022705078125, -3934.520751953125, 69.31890869140625, 3.864860773086547851, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Living Waterfall (Area: Ironwold - Difficulty: 0) CreateObject2 (Auras: 397541 - Aegis of the Elements)
(@CGUID+95, 213698, 2552, 14717, 14782, '0', 0, 0, 0, 0, 2487.366455078125, -3999.626708984375, 46.08876800537109375, 3.608813762664794921, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Living Waterfall (Area: Ironwold - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+96, 213698, 2552, 14717, 14782, '0', 0, 0, 0, 0, 2403.048583984375, -4013.163330078125, 42.59783554077148437, 2.871225357055664062, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Living Waterfall (Area: Ironwold - Difficulty: 0) CreateObject2 (Auras: 397541 - Aegis of the Elements)
(@CGUID+97, 213698, 2552, 14717, 14782, '0', 0, 0, 0, 0, 2458.953125, -3947.0244140625, 69.15081787109375, 3.947260618209838867, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Living Waterfall (Area: Ironwold - Difficulty: 0) CreateObject2 (Auras: 305033 - Water Channel (Cosmetic))
(@CGUID+98, 213698, 2552, 14717, 14782, '0', 0, 0, 0, 0, 2451.20654296875, -3981.98779296875, 47.30548858642578125, 5.152485847473144531, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Living Waterfall (Area: Ironwold - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+99, 213698, 2552, 14717, 14782, '0', 0, 0, 0, 0, 2501.272705078125, -3982.515625, 70.77938079833984375, 2.887258529663085937, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Living Waterfall (Area: Ironwold - Difficulty: 0) CreateObject2
(@CGUID+100, 213698, 2552, 14717, 14782, '0', 0, 0, 0, 0, 2473.829833984375, -3914.44970703125, 106.89996337890625, 5.855045795440673828, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Living Waterfall (Area: Ironwold - Difficulty: 0) CreateObject2
(@CGUID+101, 213698, 2552, 14717, 14782, '0', 0, 0, 0, 0, 2512.757080078125, -3916.09375, 139.85107421875, 3.681929588317871093, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Living Waterfall (Area: Ironwold - Difficulty: 0) CreateObject2 (Auras: 397541 - Aegis of the Elements) (possible waypoints or random movement)
(@CGUID+102, 213698, 2552, 14717, 14782, '0', 0, 0, 0, 0, 2468.963623046875, -3824.125, 138.898651123046875, 1.373927593231201171, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Living Waterfall (Area: Ironwold - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+103, 223098, 2552, 14717, 14782, '0', 0, 0, 0, 0, 2543.85498046875, -3911.178955078125, 144.79962158203125, 5.678271293640136718, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Cobalt Ramolith (Area: Ironwold - Difficulty: 0) CreateObject2
(@CGUID+104, 221524, 2552, 14717, 14782, '0', 0, 0, 0, 0, 2572.421875, -3949.517333984375, 140.8484954833984375, 0.990755140781402587, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Gemwing (Area: Ironwold - Difficulty: 0) CreateObject2
(@CGUID+105, 213698, 2552, 14717, 14782, '0', 0, 0, 0, 0, 2461.9375, -3871.204833984375, 148.6381072998046875, 3.429847240447998046, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Living Waterfall (Area: Ironwold - Difficulty: 0) CreateObject2 (Auras: 305033 - Water Channel (Cosmetic))
(@CGUID+106, 213698, 2552, 14717, 14782, '0', 0, 0, 0, 0, 2516.552001953125, -3946.6962890625, 124.44012451171875, 2.113484859466552734, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Living Waterfall (Area: Ironwold - Difficulty: 0) CreateObject2
(@CGUID+107, 213698, 2552, 14717, 0, '0', 0, 0, 0, 0, 2448.770751953125, -3750.232666015625, 138.4995880126953125, 3.587178230285644531, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Living Waterfall (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+108, 213698, 2552, 14717, 14782, '0', 0, 0, 0, 0, 2383.505126953125, -3819.607666015625, 64.482086181640625, 0.634012818336486816, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Living Waterfall (Area: Ironwold - Difficulty: 0) CreateObject2
(@CGUID+109, 213698, 2552, 14717, 14782, '0', 0, 0, 0, 0, 2404.63720703125, -3777.279541015625, 101.8090591430664062, 0.636292636394500732, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Living Waterfall (Area: Ironwold - Difficulty: 0) CreateObject2
(@CGUID+110, 213698, 2552, 14717, 14782, '0', 0, 0, 0, 0, 2418.979248046875, -3785.192626953125, 101.6826171875, 1.614042162895202636, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Living Waterfall (Area: Ironwold - Difficulty: 0) CreateObject2
(@CGUID+111, 222878, 2552, 14717, 14782, '0', 0, 0, 0, 0, 2302.782958984375, -4057.23779296875, 46.5792694091796875, 6.088024139404296875, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 58911), -- Ghostcap Menace (Area: Ironwold - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+112, 213698, 2552, 14717, 14782, '0', 0, 0, 0, 0, 2261.053955078125, -4046.973876953125, 37.87824630737304687, 1.294681906700134277, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Living Waterfall (Area: Ironwold - Difficulty: 0) CreateObject2
(@CGUID+113, 213698, 2552, 14717, 14782, '0', 0, 0, 0, 0, 2291.078125, -3962.911376953125, 45.91539382934570312, 4.482398033142089843, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Living Waterfall (Area: Ironwold - Difficulty: 0) CreateObject2 (Auras: 305033 - Water Channel (Cosmetic))
(@CGUID+114, 213698, 2552, 14717, 14782, '0', 0, 0, 0, 0, 2313.536376953125, -3908.236083984375, 47.28753280639648437, 3.972168445587158203, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Living Waterfall (Area: Ironwold - Difficulty: 0) CreateObject2 (Auras: 397541 - Aegis of the Elements)
(@CGUID+115, 217509, 2552, 14717, 14782, '0', 0, 0, 0, 0, 2459.74658203125, -4016.22216796875, 26.58762359619140625, 1.151836395263671875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- Slumbering Mountain Giant (Area: Ironwold - Difficulty: 0) CreateObject1
(@CGUID+116, 217938, 2552, 14717, 14782, '0', 0, 0, 0, 0, 2464.859375, -4010.98095703125, 42.1827239990234375, 1.185146093368530273, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- [DNT] Water Elemental Beam Stalker (Area: Ironwold - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+117, 217938, 2552, 14717, 14782, '0', 0, 0, 0, 0, 2497.20654296875, -3925.1181640625, 112.0915145874023437, 2.759046554565429687, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- [DNT] Water Elemental Beam Stalker (Area: Ironwold - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+118, 217938, 2552, 14717, 14782, '0', 0, 0, 0, 0, 2503.877685546875, -3925.6806640625, 129.75311279296875, 2.759046554565429687, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- [DNT] Water Elemental Beam Stalker (Area: Ironwold - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+119, 217938, 2552, 14717, 14782, '0', 0, 0, 0, 0, 2433.104248046875, -3757.71533203125, 140.267364501953125, 2.759046554565429687, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- [DNT] Water Elemental Beam Stalker (Area: Ironwold - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+120, 217938, 2552, 14717, 14782, '0', 0, 0, 0, 0, 2418.203125, -3767.257080078125, 133.1108856201171875, 2.759046554565429687, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- [DNT] Water Elemental Beam Stalker (Area: Ironwold - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+121, 217938, 2552, 14717, 0, '0', 0, 0, 0, 0, 2397.19970703125, -3809.538330078125, 84.7118682861328125, 2.759046554565429687, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911), -- [DNT] Water Elemental Beam Stalker (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+122, 213698, 2552, 14717, 14782, '0', 0, 0, 0, 0, 2343.520751953125, -3920.045166015625, 64.4566650390625, 1.80639350414276123, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58911); -- Living Waterfall (Area: Ironwold - Difficulty: 0) CreateObject2
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+122;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+30, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Limestone Falcon
(@CGUID+31, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Limestone Falcon
(@CGUID+32, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Limestone Falcon
(@CGUID+33, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Rustmane Shalehorn
(@CGUID+34, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Limestone Falcon
(@CGUID+35, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Rustmane Shalehorn
(@CGUID+37, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Limestone Falcon
(@CGUID+39, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Rustmane Shalehorn
(@CGUID+40, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Rustmane Shalehorn
(@CGUID+43, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Rustmane Shalehorn
(@CGUID+44, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Rustmane Shalehorn
(@CGUID+45, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Rustmane Shalehorn
(@CGUID+47, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Adolescent Darkwolf
(@CGUID+48, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Stormscar
(@CGUID+49, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Adolescent Darkwolf
(@CGUID+50, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Adolescent Darkwolf
(@CGUID+67, 0, 0, 0, 0, 0, 1, 0, 567, 0, 0, 0, 0, ''), -- Plainswalker Shalehorn
(@CGUID+69, 0, 0, 0, 0, 0, 1, 0, 567, 0, 0, 0, 0, ''), -- Plainswalker Shalehorn
(@CGUID+77, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Plainswalker Shalehorn
(@CGUID+99, 0, 0, 0, 2, 0, 1, 0, 438, 0, 0, 0, 0, ''); -- Living Waterfall

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (214764, 212368, 212364, 217938, 217509);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(214764, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 214764 (Rustmane Shalehorn)
(212368, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 212368 (Stormtop Shalemaw Young)
(212364, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 212364 (Stormtop Shalemaw)
(217938, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 217938 ([DNT] Water Elemental Beam Stalker)
(217509, 0, 0, 0, 0, 0, 1, 0, 0, 28797, 0, 0, 3, ''); -- 217509 (Slumbering Mountain Giant)

-- Template
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=226299; -- Anub'esska
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800, `unit_flags3`=0x14000000 WHERE `entry`=219263; -- Warphorn
UPDATE `creature_template` SET `faction`=2106, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x4000000 WHERE `entry`=212364; -- Stormtop Shalemaw
UPDATE `creature_template` SET `faction`=2106, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x4000000 WHERE `entry`=226296; -- Adolescent Darkwolf
UPDATE `creature_template` SET `faction`=1711, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=226295; -- Stormscar
UPDATE `creature_template` SET `faction`=2106, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x4000000 WHERE `entry`=212368; -- Stormtop Shalemaw Young
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=226297; -- Fallen Mage Essence
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=226298; -- Mage Slayer Phytethil
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x4000000 WHERE `entry`=225311; -- Plainswalker Shalehorn
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=227122; -- Forest Ferret
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x2000100, `unit_flags2`=0x800, `unit_flags3`=0x1000000, `flags_extra` = 128 WHERE `entry`=217938; -- [DNT] Water Elemental Beam Stalker
UPDATE `creature_template` SET `faction`=35, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800, `unit_flags3`=0x40000000 WHERE `entry`=217509; -- Slumbering Mountain Giant
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=213698; -- Living Waterfall
UPDATE `creature_template` SET `faction`=188, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800 WHERE `entry`=222878; -- Ghostcap Menace

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000100, `VerifiedBuild`=58911 WHERE (`Entry`=226299 AND `DifficultyID`=0); -- 226299 (Anub'esska) - Sessile, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2804, `StaticFlags1`=0x10000000, `VerifiedBuild`=58911 WHERE (`Entry`=219263 AND `DifficultyID`=0); -- 219263 (Warphorn) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=58911 WHERE (`Entry`=226295 AND `DifficultyID`=0); -- 226295 (Stormscar) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x20000000, `VerifiedBuild`=58911 WHERE (`Entry`=212368 AND `DifficultyID`=0); -- 212368 (Stormtop Shalemaw Young) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=58911 WHERE (`Entry`=212371 AND `DifficultyID`=0); -- 212371 (Lethargic Mosswool) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=58911 WHERE (`Entry`=224504 AND `DifficultyID`=0); -- 224504 (Awakened Mountain Giant) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x20000000, `VerifiedBuild`=58911 WHERE (`Entry`=212364 AND `DifficultyID`=0); -- 212364 (Stormtop Shalemaw) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=58911 WHERE (`Entry`=226296 AND `DifficultyID`=0); -- 226296 (Adolescent Darkwolf) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=58911 WHERE (`Entry`=226298 AND `DifficultyID`=0); -- 226298 (Mage Slayer Phytethil) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=58911 WHERE (`Entry`=226297 AND `DifficultyID`=0); -- 226297 (Fallen Mage Essence) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=0x10000000, `VerifiedBuild`=58911 WHERE (`Entry`=227122 AND `DifficultyID`=0); -- 227122 (Forest Ferret) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x20000000, `VerifiedBuild`=58911 WHERE (`Entry`=217938 AND `DifficultyID`=0); -- 217938 ([DNT] Water Elemental Beam Stalker) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x30000100, `VerifiedBuild`=58911 WHERE (`Entry`=217509 AND `DifficultyID`=0); -- 217509 (Slumbering Mountain Giant) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x00080000, `VerifiedBuild`=58911 WHERE (`Entry`=213698 AND `DifficultyID`=0); -- 213698 (Living Waterfall) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=371, `StaticFlags1`=0x10000000, `VerifiedBuild`=58911 WHERE (`Entry`=222878 AND `DifficultyID`=0); -- 222878 (Ghostcap Menace) - CanSwim

DELETE FROM `creature_static_flags_override` WHERE `SpawnId` IN (@CGUID+30, @CGUID+31, @CGUID+32, @CGUID+34, @CGUID+37);
INSERT INTO `creature_static_flags_override` (`SpawnId`, `DifficultyId`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`) VALUES
(@CGUID+30, 0, 0x10000000, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(@CGUID+31, 0, 0x10000000, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(@CGUID+32, 0, 0x10000000, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(@CGUID+34, 0, 0x10000000, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(@CGUID+37, 0, 0x10000000, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

-- Creature template movement
DELETE FROM `creature_template_movement` WHERE `CreatureId` = 213698;
INSERT INTO `creature_template_movement` (`CreatureId`, `HoverInitiallyEnabled`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(213698, 1, 0, 0, NULL);

-- Anub'esska smart ai
SET @ENTRY := 226299;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 85, 258096, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Cast spell 258096 on self', '');

-- Path for Limestone Falcon
SET @MOVERGUID := @CGUID+3;
SET @ENTRY := 220295;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 8.5997, 'Fallside Falcon - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2849.3315, -3420.1338, 238.87349, NULL, 0),
(@PATH, 1, 2836.98, -3396.559, 238.87349, NULL, 0),
(@PATH, 2, 2850.4175, -3369.9915, 238.87349, NULL, 0),
(@PATH, 3, 2884.8655, -3364.1355, 238.87349, NULL, 0),
(@PATH, 4, 2916.0461, -3376.1406, 238.87349, NULL, 0),
(@PATH, 5, 2935.3213, -3415.8645, 238.87349, NULL, 0),
(@PATH, 6, 2930.4758, -3462.665, 238.87349, NULL, 0),
(@PATH, 7, 2883.7917, -3465.6025, 238.87349, NULL, 0),
(@PATH, 8, 2856.9626, -3434.6685, 238.87349, NULL, 0),
(@PATH, 9, 2849.3315, -3420.1338, 238.87349, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Limestone Falcon
SET @MOVERGUID := @CGUID+36;
SET @ENTRY := 214772;
SET @PATHOFFSET := 5;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 8.6720, 'Limestone Falcon - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3016.015, -3230.8542, 255.09587, NULL, 0),
(@PATH, 1, 3029.125, -3253.0625, 255.09587, NULL, 0),
(@PATH, 2, 3058.5903, -3259.9983, 255.09587, NULL, 0),
(@PATH, 3, 3083.1267, -3235.1719, 255.09587, NULL, 0),
(@PATH, 4, 3078.9966, -3200.7258, 255.09587, NULL, 0),
(@PATH, 5, 3045.9072, -3180.8176, 255.09587, NULL, 0),
(@PATH, 6, 3014.7336, -3200.4531, 255.09587, NULL, 0),
(@PATH, 7, 3011.757, -3218.3733, 255.09587, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `AnimTier`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 3, 1);

-- Path for Limestone Falcon
SET @MOVERGUID := @CGUID+38;
SET @ENTRY := 214772;
SET @PATHOFFSET := 6;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 8.5455, 'Limestone Falcon - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3040.931, -3222.86, 275.64938, NULL, 0),
(@PATH, 1, 3036.9758, -3211.843, 275.64938, NULL, 0),
(@PATH, 2, 3029.1057, -3203.1782, 275.64938, NULL, 0),
(@PATH, 3, 3018.5188, -3198.1848, 275.64938, NULL, 0),
(@PATH, 4, 3006.827, -3197.6228, 275.64938, NULL, 0),
(@PATH, 5, 2995.81, -3201.578, 275.64938, NULL, 0),
(@PATH, 6, 2987.1453, -3209.4478, 275.64938, NULL, 0),
(@PATH, 7, 2982.1516, -3220.0347, 275.64938, NULL, 0),
(@PATH, 8, 2981.5896, -3231.7266, 275.64938, NULL, 0),
(@PATH, 9, 2985.5447, -3242.7437, 275.64938, NULL, 0),
(@PATH, 10, 2993.4148, -3251.4084, 275.64938, NULL, 0),
(@PATH, 11, 3004.0017, -3256.402, 275.64938, NULL, 0),
(@PATH, 12, 3015.6936, -3256.9639, 275.64938, NULL, 0),
(@PATH, 13, 3026.7104, -3253.0088, 275.64938, NULL, 0),
(@PATH, 14, 3035.3755, -3245.139, 275.64938, NULL, 0),
(@PATH, 15, 3040.369, -3234.552, 275.64938, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `AnimTier`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 3, 1);

-- Path for Soaring Plainshawk
SET @MOVERGUID := @CGUID+73;
SET @ENTRY := 221644;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8683, 'Soaring Plainshawk - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2004.1956, -3467.961, 131.30179, NULL, 0),
(@PATH, 1, 2014.8021, -3472.3542, 131.30179, NULL, 0),
(@PATH, 2, 2025.4087, -3467.961, 131.30179, NULL, 0),
(@PATH, 3, 2029.8021, -3457.3542, 131.30179, NULL, 0),
(@PATH, 4, 2025.4087, -3446.7476, 131.30179, NULL, 0),
(@PATH, 5, 2014.8021, -3442.3542, 131.30179, NULL, 0),
(@PATH, 6, 2004.1956, -3446.7476, 131.30179, NULL, 0),
(@PATH, 7, 1999.8021, -3457.3542, 131.30179, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Soaring Plainshawk
SET @MOVERGUID := @CGUID+79;
SET @ENTRY := 221644;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.6715, 'Soaring Plainshawk - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1943.4833, -3696.116, 128.27986, NULL, 0),
(@PATH, 1, 1949.9865, -3705.8486, 128.27986, NULL, 0),
(@PATH, 2, 1959.7192, -3712.3518, 128.27986, NULL, 0),
(@PATH, 3, 1971.1997, -3714.6355, 128.27986, NULL, 0),
(@PATH, 4, 1982.6802, -3712.3518, 128.27986, NULL, 0),
(@PATH, 5, 1992.413, -3705.8486, 128.27986, NULL, 0),
(@PATH, 6, 1998.9161, -3696.116, 128.27986, NULL, 0),
(@PATH, 7, 2001.1997, -3684.6355, 128.27986, NULL, 0),
(@PATH, 8, 1998.9161, -3673.155, 128.27986, NULL, 0),
(@PATH, 9, 1992.4128, -3663.4224, 128.27986, NULL, 0),
(@PATH, 10, 1982.6802, -3656.9192, 128.27986, NULL, 0),
(@PATH, 11, 1971.1997, -3654.6355, 128.27986, NULL, 0),
(@PATH, 12, 1959.7192, -3656.9192, 128.27986, NULL, 0),
(@PATH, 13, 1949.9865, -3663.4224, 128.27986, NULL, 0),
(@PATH, 14, 1943.4833, -3673.155, 128.27986, NULL, 0),
(@PATH, 15, 1941.1997, -3684.6355, 128.27986, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Great Stormfang
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+16;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+16, @CGUID+16, 3, 270, 515, 0, 0),
(@CGUID+16, @CGUID+17, 3, 270, 515, 0, 0);

SET @MOVERGUID := @CGUID+16;
SET @ENTRY := 216017;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Great Stormfang - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2815.8325, -3465.5642, 194.60544, NULL, 0),
(@PATH, 1, 2843.4062, -3465.5156, 194.72346, NULL, 0),
(@PATH, 2, 2874.6711, -3476.092, 193.47809, NULL, 5529),
(@PATH, 3, 2843.4062, -3465.5156, 194.72346, NULL, 0),
(@PATH, 4, 2815.8325, -3465.5642, 194.60544, NULL, 0),
(@PATH, 5, 2790.369, -3461.4636, 193.52034, NULL, 0),
(@PATH, 6, 2770.6511, -3447.2656, 191.34985, NULL, 5148),
(@PATH, 7, 2790.369, -3461.4636, 193.52034, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Warphorn
SET @MOVERGUID := @CGUID+29;
SET @ENTRY := 219263;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Warphorn - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2963.6243, -3234.2222, 221.7423, NULL, 0),
(@PATH, 1, 2959.4368, -3210.2778, 220.4834, NULL, 0),
(@PATH, 2, 2964.4583, -3170.0608, 222.89064, NULL, 0),
(@PATH, 3, 2982.6511, -3158.0972, 223.9963, NULL, 0),
(@PATH, 4, 3000.1094, -3144.2188, 224.03351, NULL, 0),
(@PATH, 5, 3032.0122, -3155.29, 221.16641, NULL, 0),
(@PATH, 6, 3070.889, -3174.941, 212.93893, NULL, 0),
(@PATH, 7, 3101.3994, -3184.0955, 206.65929, NULL, 0),
(@PATH, 8, 3118.986, -3184.1284, 202.98459, NULL, 0),
(@PATH, 9, 3153.3472, -3174.0972, 193.03171, NULL, 0),
(@PATH, 10, 3162.4097, -3198.5122, 193.53732, NULL, 0),
(@PATH, 11, 3172.2847, -3205.4722, 193.2679, NULL, 0),
(@PATH, 12, 3180.0034, -3213.9583, 192.79803, NULL, 0),
(@PATH, 13, 3181.0251, -3234.3333, 192.20203, NULL, 0),
(@PATH, 14, 3179.3848, -3244.1973, 191.82578, NULL, 0),
(@PATH, 15, 3175.9229, -3258.611, 191.38074, NULL, 0),
(@PATH, 16, 3170.2031, -3281.7205, 190.38528, NULL, 0),
(@PATH, 17, 3150.7769, -3302.8074, 190.0178, NULL, 0),
(@PATH, 18, 3126.4446, -3309.0989, 192.65877, NULL, 0),
(@PATH, 19, 3095.515, -3317.8542, 198.45786, NULL, 0),
(@PATH, 20, 3053.869, -3320.4219, 207.90216, NULL, 0),
(@PATH, 21, 3016.8777, -3307.4114, 211.89308, NULL, 0),
(@PATH, 22, 2987.0479, -3283.9028, 216.60045, NULL, 0),
(@PATH, 23, 2974.5461, -3263.0105, 218.78426, NULL, 0);

UPDATE `creature` SET `position_x`=2963.6243, `position_y`=-3234.2222, `position_z`=221.7423, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Mage Slayer Phytethil
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+61;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+61, @CGUID+61, 0, 0, 515, 0, 0),
(@CGUID+61, @CGUID+60, 3, 180, 515, 0, 0),
(@CGUID+61, @CGUID+62, 6, 180, 515, 0, 0);

SET @MOVERGUID := @CGUID+61;
SET @ENTRY := 226298;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Mage Slayer Phytethil - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3319.3608, -3069.0112, 253.9162, NULL, 7597),
(@PATH, 1, 3316.8425, -3071.106, 254.68124, NULL, 0),
(@PATH, 2, 3314.5361, -3073.0032, 254.71231, NULL, 0),
(@PATH, 3, 3312.488, -3075.0532, 254.75981, NULL, 0),
(@PATH, 4, 3310.3228, -3077.1714, 254.42789, NULL, 0),
(@PATH, 5, 3308.1426, -3079.3, 254.47441, NULL, 0),
(@PATH, 6, 3305.959, -3081.433, 254.76378, NULL, 0),
(@PATH, 7, 3303.7717, -3083.5696, 255.19043, NULL, 0),
(@PATH, 8, 3303.6501, -3083.6885, 255.18434, NULL, 7445),
(@PATH, 9, 3306.5845, -3080.8203, 254.65997, NULL, 0),
(@PATH, 10, 3308.6934, -3078.7559, 254.44835, NULL, 0),
(@PATH, 11, 3310.9246, -3076.574, 254.50876, NULL, 0),
(@PATH, 12, 3312.9, -3074.354, 254.76468, NULL, 0),
(@PATH, 13, 3315.2654, -3072.4023, 254.72037, NULL, 0),
(@PATH, 14, 3317.4326, -3070.6172, 254.47157, NULL, 0);

UPDATE `creature` SET `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Living Waterfall
SET @MOVERGUID := @CGUID+112;
SET @ENTRY := 213698;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Living Waterfall - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2264.4167, -4028.6511, 39.402737, NULL, 0),
(@PATH, 1, 2265.1807, -4021.552, 38.735638, NULL, 0),
(@PATH, 2, 2265.0608, -4010.9844, 38.735527, NULL, 0),
(@PATH, 3, 2268.3125, -4002.7935, 38.62278, NULL, 0),
(@PATH, 4, 2274.0886, -3994.0886, 38.676, NULL, 0),
(@PATH, 5, 2284.6545, -3991.5383, 38.465374, NULL, 0),
(@PATH, 6, 2295.8801, -3990.6633, 40.120636, NULL, 0),
(@PATH, 7, 2301.1355, -3990.9758, 40.155014, NULL, 0),
(@PATH, 8, 2307.1338, -3992.7673, 40.125572, NULL, 0),
(@PATH, 9, 2312.9739, -3996.4739, 40.087254, NULL, 0),
(@PATH, 10, 2318.0208, -3999.6145, 40.16174, NULL, 0),
(@PATH, 11, 2323.434, -4004.2466, 39.98229, NULL, 0),
(@PATH, 12, 2332.6597, -4008.2727, 39.036205, NULL, 0),
(@PATH, 13, 2343.1077, -4009.7102, 38.813026, NULL, 0),
(@PATH, 14, 2355.3386, -4009.7883, 39.11877, NULL, 0),
(@PATH, 15, 2366.7847, -4009.2136, 39.2516, NULL, 0),
(@PATH, 16, 2375.7258, -4008.837, 37.5562, NULL, 0),
(@PATH, 17, 2366.7847, -4009.2136, 39.2516, NULL, 0),
(@PATH, 18, 2355.3386, -4009.7883, 39.11877, NULL, 0),
(@PATH, 19, 2343.1077, -4009.7102, 38.813026, NULL, 0),
(@PATH, 20, 2332.6597, -4008.2727, 39.036205, NULL, 0),
(@PATH, 21, 2323.5, -4004.2695, 40.056896, NULL, 0),
(@PATH, 22, 2318.0208, -3999.6145, 40.16174, NULL, 0),
(@PATH, 23, 2312.9739, -3996.4739, 40.087254, NULL, 0),
(@PATH, 24, 2307.1338, -3992.7673, 40.125572, NULL, 0),
(@PATH, 25, 2301.1355, -3990.9758, 40.155014, NULL, 0),
(@PATH, 26, 2295.8801, -3990.6633, 40.120636, NULL, 0),
(@PATH, 27, 2284.6545, -3991.5383, 38.465374, NULL, 0),
(@PATH, 28, 2274.0886, -3994.0886, 38.676, NULL, 0),
(@PATH, 29, 2268.3125, -4002.7935, 38.62278, NULL, 0),
(@PATH, 30, 2265.0608, -4010.9844, 38.735527, NULL, 0),
(@PATH, 31, 2265.1807, -4021.552, 38.735638, NULL, 0),
(@PATH, 32, 2264.4167, -4028.6511, 39.402737, NULL, 0),
(@PATH, 33, 2264.5833, -4036.6562, 39.099686, NULL, 0),
(@PATH, 34, 2264.0105, -4044.791, 39.01683, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Living Waterfall
SET @MOVERGUID := @CGUID+122;
SET @ENTRY := 213698;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Living Waterfall - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2339.1997, -3905.2083, 65.87905, NULL, 0),
(@PATH, 1, 2337.3008, -3899.5137, 64.1136, NULL, 0),
(@PATH, 2, 2337.121, -3895.5215, 62.288055, NULL, 0),
(@PATH, 3, 2335.9827, -3891.3125, 61.09894, NULL, 0),
(@PATH, 4, 2334.5676, -3887.4463, 59.96984, NULL, 0),
(@PATH, 5, 2330.8508, -3884.5227, 60.649357, NULL, 0),
(@PATH, 6, 2327.0928, -3883.1562, 62.38676, NULL, 0),
(@PATH, 7, 2322.6338, -3879.1484, 64.14123, NULL, 0),
(@PATH, 8, 2320.054, -3874.2673, 65.38645, NULL, 0),
(@PATH, 9, 2323.5051, -3868.5608, 66.33443, NULL, 0),
(@PATH, 10, 2328.1458, -3863.606, 66.01193, NULL, 0),
(@PATH, 11, 2332.644, -3859.0903, 65.15029, NULL, 0),
(@PATH, 12, 2338.0557, -3857.8577, 63.863556, NULL, 0),
(@PATH, 13, 2346.7395, -3856.2935, 61.453606, NULL, 0),
(@PATH, 14, 2352.6924, -3855.5664, 59.83329, NULL, 0),
(@PATH, 15, 2355.1807, -3857.291, 59.603443, NULL, 0),
(@PATH, 16, 2358.8699, -3861.2205, 62.189686, NULL, 0),
(@PATH, 17, 2363.2778, -3863.5642, 63.97799, NULL, 0),
(@PATH, 18, 2368.2065, -3862.802, 64.870895, NULL, 0),
(@PATH, 19, 2373.5364, -3857.4775, 65.46923, NULL, 0),
(@PATH, 20, 2377.2864, -3850.4045, 65.96965, NULL, 0),
(@PATH, 21, 2376.5017, -3847.1736, 64.846054, NULL, 0),
(@PATH, 22, 2373.9426, -3842.861, 64.3771, NULL, 0),
(@PATH, 23, 2370.087, -3837.639, 65.35174, NULL, 0),
(@PATH, 24, 2373.9426, -3842.861, 64.3771, NULL, 0),
(@PATH, 25, 2376.5017, -3847.1736, 64.846054, NULL, 0),
(@PATH, 26, 2377.2864, -3850.4045, 65.96965, NULL, 0),
(@PATH, 27, 2373.5361, -3857.4668, 65.45962, NULL, 0),
(@PATH, 28, 2368.2065, -3862.802, 64.870895, NULL, 0),
(@PATH, 29, 2363.2778, -3863.5642, 63.97799, NULL, 0),
(@PATH, 30, 2358.8699, -3861.2205, 62.189686, NULL, 0),
(@PATH, 31, 2355.1807, -3857.291, 59.603443, NULL, 0),
(@PATH, 32, 2352.8213, -3855.5503, 59.888428, NULL, 0),
(@PATH, 33, 2346.7395, -3856.2935, 61.453606, NULL, 0),
(@PATH, 34, 2338.0557, -3857.8577, 63.863556, NULL, 0),
(@PATH, 35, 2332.644, -3859.0903, 65.15029, NULL, 0),
(@PATH, 36, 2328.1458, -3863.606, 66.01193, NULL, 0),
(@PATH, 37, 2323.5051, -3868.5608, 66.33443, NULL, 0),
(@PATH, 38, 2320.054, -3874.2673, 65.38645, NULL, 0),
(@PATH, 39, 2322.5886, -3879.106, 64.04605, NULL, 0),
(@PATH, 40, 2327.033, -3883.1338, 62.47376, NULL, 0),
(@PATH, 41, 2330.791, -3884.502, 60.625114, NULL, 0),
(@PATH, 42, 2334.5676, -3887.4463, 59.96984, NULL, 0),
(@PATH, 43, 2335.9424, -3891.205, 61.03023, NULL, 0),
(@PATH, 44, 2337.1199, -3895.5051, 62.393986, NULL, 0),
(@PATH, 45, 2337.2778, -3899.4497, 64.26169, NULL, 0),
(@PATH, 46, 2339.1997, -3905.2083, 65.87905, NULL, 0),
(@PATH, 47, 2341.9775, -3910.481, 66.69433, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
