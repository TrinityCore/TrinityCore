SET @CGUID := 6001354;
SET @OGUID := 6001356;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+206;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 118719, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -682.8975830078125, 2522.651123046875, 395.345794677734375, 5.438682079315185546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Wyrmtongue Scavenger (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 141502 - Permanent Feign Death)
(@CGUID+1, 118724, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -679.0382080078125, 2443.0087890625, 337.05560302734375, 3.152493476867675781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Helblaze Felbringer (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+2, 118690, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -608.0711669921875, 2497.4150390625, 334.2730712890625, 2.06029057502746582, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Wrathguard Invader (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+3, 120779, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -604.3211669921875, 2566.487060546875, 334.248748779296875, 4.48575592041015625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Helblaze Felbringer (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+4, 118690, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -641.84027099609375, 2457.8681640625, 335.704345703125, 5.387622833251953125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Wrathguard Invader (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+5, 118719, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -673.10418701171875, 2521.99560546875, 395.34576416015625, 3.483119487762451171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Wyrmtongue Scavenger (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 141502 - Permanent Feign Death)
(@CGUID+6, 118717, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -656.98785400390625, 2529.572998046875, 395.2974853515625, 0.864640533924102783, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Helblaze Imp (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 141502 - Permanent Feign Death)
(@CGUID+7, 118719, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -680.75, 2535.6806640625, 395.280548095703125, 2.423405170440673828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Wyrmtongue Scavenger (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 141502 - Permanent Feign Death)
(@CGUID+8, 118717, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -667.95489501953125, 2522.55029296875, 395.280517578125, 3.528850793838500976, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Helblaze Imp (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 141502 - Permanent Feign Death)
(@CGUID+9, 118719, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -652.38018798828125, 2526.61376953125, 395.296630859375, 5.438682079315185546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Wyrmtongue Scavenger (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 141502 - Permanent Feign Death)
(@CGUID+10, 118717, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -646.32989501953125, 2528.603271484375, 395.2957763671875, 2.119910717010498046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Helblaze Imp (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 141502 - Permanent Feign Death)
(@CGUID+11, 118717, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -667.578125, 2534.86279296875, 395.280517578125, 2.238543033599853515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Helblaze Imp (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 141502 - Permanent Feign Death)
(@CGUID+12, 118717, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -640.185791015625, 2522.671875, 394.985595703125, 0.393009066581726074, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Helblaze Imp (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 141502 - Permanent Feign Death)
(@CGUID+13, 118719, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -640.0382080078125, 2526.682373046875, 395.15582275390625, 3.106417179107666015, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Wyrmtongue Scavenger (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 243557 - Agressive)
(@CGUID+14, 120652, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -632.3507080078125, 2527.34814453125, 334.43841552734375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Global Affix Stalker (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+15, 118717, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -643.64190673828125, 2523.143310546875, 395.025970458984375, 1.569980502128601074, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Helblaze Imp (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 243557 - Agressive)
(@CGUID+16, 119923, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -600.05035400390625, 2494.303955078125, 334.235321044921875, 1.826025843620300292, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Helblaze Soulmender (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+17, 120770, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -608.8819580078125, 2568.9375, 334.251739501953125, 4.655721187591552734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Felguard Destroyer (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+18, 119768, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -612.41839599609375, 2506.397705078125, 334.448577880859375, 2.225215435028076171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Legionfall Soldier (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 141502 - Permanent Feign Death)
(@CGUID+19, 118703, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -598.86285400390625, 2566.248291015625, 384.391265869140625, 4.427814006805419921, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Felborne Botanist (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+20, 119768, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -601.76739501953125, 2550.8759765625, 334.523468017578125, 1.897273182868957519, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Legionfall Soldier (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 141502 - Permanent Feign Death)
(@CGUID+21, 121711, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -605.5634765625, 2511.80517578125, 384.817535400390625, 4.947357177734375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Bilespray Lasher (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+22, 120778, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -601.61114501953125, 2570.382080078125, 334.248291015625, 4.580844402313232421, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Wrathguard Invader (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+23, 118700, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -606.34112548828125, 2456.848876953125, 334.43121337890625, 4.904671669006347656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Felblight Stalker (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+24, 118724, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -603.4385986328125, 2457.499755859375, 334.319732666015625, 4.88498687744140625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Helblaze Felbringer (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+25, 118714, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -595.15802001953125, 2526.978271484375, 384.423675537109375, 0.15657895803451538, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Hellblaze Temptress (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 238990 - Barbed Thorns)
(@CGUID+26, 120779, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -596.36285400390625, 2569.2197265625, 334.244537353515625, 4.48575592041015625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Helblaze Felbringer (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+27, 119768, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -607.78472900390625, 2556.533935546875, 334.272613525390625, 0.630885839462280273, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Legionfall Soldier (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 141502 - Permanent Feign Death)
(@CGUID+28, 121569, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -601.59832763671875, 2512.42236328125, 384.400360107421875, 4.947457313537597656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Vilebark Walker (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 242755 - Spawn Cosmetic) (possible waypoints or random movement)
(@CGUID+29, 119768, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -601.29168701171875, 2496.548583984375, 334.4154052734375, 5.869901657104492187, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Legionfall Soldier (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 141502 - Permanent Feign Death)
(@CGUID+30, 118703, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -603.23089599609375, 2565.65283203125, 384.423919677734375, 5.722859382629394531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Felborne Botanist (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+31, 120374, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -595.8507080078125, 2500.963623046875, 334.292236328125, 1.943552613258361816, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Felguard Destroyer (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+32, 118704, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -599.7742919921875, 2584.2431640625, 334.251739501953125, 4.51615762710571289, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Dul'zak (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+33, 118690, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -639.11285400390625, 2441.86279296875, 335.56939697265625, 1.514109373092651367, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Wrathguard Invader (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+34, 119978, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -589.91143798828125, 2523.5166015625, 384.665771484375, 3.877667188644409179, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Fulminating Lasher (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 177645 - Submerged)
(@CGUID+35, 121711, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -605.5531005859375, 2490.60302734375, 384.513092041015625, 1.544494032859802246, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Bilespray Lasher (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+36, 121569, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -601.545166015625, 2490.8525390625, 384.47308349609375, 1.544507741928100585, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Vilebark Walker (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 242755 - Spawn Cosmetic) (possible waypoints or random movement)
(@CGUID+37, 120770, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -591.9288330078125, 2568.040771484375, 334.530670166015625, 4.97383880615234375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Felguard Destroyer (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+38, 119768, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -592.43927001953125, 2507.420166015625, 334.287567138671875, 0.630885839462280273, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Legionfall Soldier (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 141502 - Permanent Feign Death)
(@CGUID+39, 119978, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -589.36456298828125, 2531.326416015625, 384.665771484375, 2.749443292617797851, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Fulminating Lasher (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 177645 - Submerged)
(@CGUID+40, 118703, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -611.40625, 2454.62841796875, 385.825531005859375, 4.070201873779296875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Felborne Botanist (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+41, 118700, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -603.25347900390625, 2442.611083984375, 334.29345703125, 1.437787890434265136, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Felblight Stalker (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+42, 120556, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -547.484375, 2521.833251953125, 344.59051513671875, 4.779669761657714843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Dreadwing (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+43, 118714, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -606.18231201171875, 2433.6962890625, 384.619873046875, 5.82671213150024414, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Hellblaze Temptress (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 238990 - Barbed Thorns)
(@CGUID+44, 118690, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -624.07989501953125, 2386.2900390625, 335.856414794921875, 5.185154914855957031, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Wrathguard Invader (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+45, 118714, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -586.73089599609375, 2438.779541015625, 384.381622314453125, 3.813118219375610351, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Hellblaze Temptress (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 238990 - Barbed Thorns)
(@CGUID+46, 118700, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -600.4918212890625, 2458.094970703125, 334.28466796875, 4.886958122253417968, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Felblight Stalker (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+47, 118703, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -614.576416015625, 2451.56591796875, 385.826568603515625, 0.922481715679168701, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Felborne Botanist (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+48, 119978, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -550.04168701171875, 2496.779541015625, 388.451995849609375, 1.067928075790405273, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Fulminating Lasher (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 177645 - Submerged)
(@CGUID+49, 120556, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -544.4814453125, 2511.658203125, 345.587738037109375, 5.23168182373046875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Dreadwing (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+50, 118716, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -546.40106201171875, 2541.796142578125, 388.451995849609375, 5.321172237396240234, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Bilespray Lasher (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 177645 - Submerged)
(@CGUID+51, 119768, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -603, 2445.81591796875, 334.25177001953125, 0.518372595310211181, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Legionfall Soldier (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 141502 - Permanent Feign Death)
(@CGUID+52, 118703, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -589.5538330078125, 2437.10595703125, 384.4166259765625, 3.59244847297668457, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Felborne Botanist (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+53, 118703, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -602.05206298828125, 2428.192626953125, 384.382659912109375, 1.388131141662597656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Felborne Botanist (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+54, 119978, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -553.63018798828125, 2509.603271484375, 388.586273193359375, 6.167116165161132812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Fulminating Lasher (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 177645 - Submerged)
(@CGUID+55, 118703, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -636.576416015625, 2360.814208984375, 385.907623291015625, 2.250120878219604492, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Felborne Botanist (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+56, 121023, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -547.97918701171875, 2563.576416015625, 251.559967041015625, 5.541373252868652343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Legionfall Soldier (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 35356 - Spawn Feign Death)
(@CGUID+57, 121023, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -529.98785400390625, 2547.5087890625, 251.73699951171875, 0.925089478492736816, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Legionfall Soldier (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 35356 - Spawn Feign Death)
(@CGUID+58, 121023, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -554.795166015625, 2568.221435546875, 251.5557403564453125, 3.659355640411376953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Legionfall Soldier (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 35356 - Spawn Feign Death)
(@CGUID+59, 119768, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -533.359375, 2355.939208984375, 336.595367431640625, 5.053159236907958984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Legionfall Soldier (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 141502 - Permanent Feign Death)
(@CGUID+60, 118714, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -502.0645751953125, 2509.655517578125, 388.540740966796875, 1.228487372398376464, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Hellblaze Temptress (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 238990 - Barbed Thorns)
(@CGUID+61, 118703, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -581.59893798828125, 2408.55908203125, 384.641693115234375, 6.161235809326171875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Felborne Botanist (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 240773 - Plant FeederBotanist RP)
(@CGUID+62, 119768, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -616.6632080078125, 2373.744873046875, 333.91986083984375, 2.476402521133422851, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Legionfall Soldier (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 141502 - Permanent Feign Death)
(@CGUID+63, 118716, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -498.876739501953125, 2535.24560546875, 389.4532470703125, 3.450186967849731445, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Bilespray Lasher (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 177645 - Submerged)
(@CGUID+64, 119923, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -628.8194580078125, 2370.3837890625, 335.856414794921875, 0.661527097225189208, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Helblaze Soulmender (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+65, 119768, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -525.76910400390625, 2349.473876953125, 336.595367431640625, 5.053159236907958984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Legionfall Soldier (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 141502 - Permanent Feign Death)
(@CGUID+66, 121023, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -526.1944580078125, 2533.5712890625, 251.736968994140625, 5.123530387878417968, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Legionfall Soldier (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 35356 - Spawn Feign Death)
(@CGUID+67, 118703, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -541.2569580078125, 2545.815185546875, 388.451995849609375, 2.800644159317016601, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Felborne Botanist (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 240773 - Plant FeederBotanist RP)
(@CGUID+68, 121023, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -539.88543701171875, 2518.286376953125, 251.7369537353515625, 5.374959468841552734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Legionfall Soldier (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 35356 - Spawn Feign Death)
(@CGUID+69, 121023, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -536.5625, 2566.7265625, 251.559967041015625, 5.541373252868652343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Legionfall Soldier (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 35356 - Spawn Feign Death)
(@CGUID+70, 121318, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -574.70831298828125, 2402.166748046875, 384.38818359375, 2.34899759292602539, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Fulminating Lasher (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+71, 119768, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -529.22393798828125, 2383.5869140625, 334.504638671875, 4.754031658172607421, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Legionfall Soldier (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 237597 - Scared Cosmetic)
(@CGUID+72, 118690, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -612.54339599609375, 2374.26220703125, 335.856414794921875, 3.042385578155517578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Wrathguard Invader (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+73, 121023, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -541.34722900390625, 2537.334228515625, 251.73699951171875, 5.374959468841552734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Legionfall Soldier (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 35356 - Spawn Feign Death)
(@CGUID+74, 119768, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -521.57989501953125, 2352.588623046875, 336.595367431640625, 3.654980897903442382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Legionfall Soldier (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 141502 - Permanent Feign Death)
(@CGUID+75, 119768, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -623.060791015625, 2370.94091796875, 333.91986083984375, 1.077267885208129882, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Legionfall Soldier (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 141502 - Permanent Feign Death)
(@CGUID+76, 121023, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -508.883697509765625, 2530.221435546875, 251.7369537353515625, 5.374959468841552734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Legionfall Soldier (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 35356 - Spawn Feign Death)
(@CGUID+77, 118703, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -638.7882080078125, 2364.630126953125, 385.741455078125, 5.39784097671508789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Felborne Botanist (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+78, 119768, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -621.76910400390625, 2383.1494140625, 333.91986083984375, 0.518372595310211181, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Legionfall Soldier (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 141502 - Permanent Feign Death)
(@CGUID+79, 118690, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -573.01739501953125, 2418.935791015625, 334.624481201171875, 1.128249764442443847, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Wrathguard Invader (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+80, 121553, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -555.3009033203125, 2392.68310546875, 339.882080078125, 2.943751811981201171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Dreadhunter (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+81, 117193, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -523.39581298828125, 2468.083251953125, 389.2333984375, 1.523924708366394042, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Agronox (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 218987 - Oakheart Auto Attack Sounds, 244332 - Summon)
(@CGUID+82, 119777, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -509.84027099609375, 2467.710205078125, 251.736328125, 1.256036281585693359, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Durgan Stonestorm (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+83, 121023, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -530.30731201171875, 2511.564208984375, 251.7369537353515625, 0.925089478492736816, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Legionfall Soldier (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 35356 - Spawn Feign Death)
(@CGUID+84, 118716, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -541.5694580078125, 2551.4697265625, 388.451995849609375, 5.936107158660888671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Bilespray Lasher (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 177645 - Submerged)
(@CGUID+85, 118703, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -616.98541259765625, 2363.5751953125, 385.444061279296875, 0.573749780654907226, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Felborne Botanist (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+86, 118703, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -506.4600830078125, 2546.57470703125, 388.63494873046875, 5.824366092681884765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Felborne Botanist (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 240773 - Plant FeederBotanist RP)
(@CGUID+87, 119768, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -626.80731201171875, 2377.98779296875, 333.91986083984375, 6.022923946380615234, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Legionfall Soldier (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 141502 - Permanent Feign Death)
(@CGUID+88, 120556, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -511.629302978515625, 2585.5859375, 348.38580322265625, 5.402177810668945312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Dreadwing (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+89, 121023, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -516.08160400390625, 2540.693603515625, 251.7369537353515625, 0.896879136562347412, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Legionfall Soldier (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 35356 - Spawn Feign Death)
(@CGUID+90, 121711, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -572.25518798828125, 2409.541748046875, 384.3828125, 3.106183290481567382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Bilespray Lasher (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+91, 121023, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -522.54168701171875, 2514.5859375, 251.736968994140625, 5.794710159301757812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Legionfall Soldier (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 35356 - Spawn Feign Death)
(@CGUID+92, 120556, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -495.5125732421875, 2553.296142578125, 340.94354248046875, 2.186269760131835937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Dreadwing (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+93, 120556, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -506.6937255859375, 2564.3515625, 331.962432861328125, 2.514364242553710937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Dreadwing (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+94, 121023, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -505.75347900390625, 2563.598876953125, 251.559967041015625, 0.447120249271392822, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Legionfall Soldier (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 35356 - Spawn Feign Death)
(@CGUID+95, 118716, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -495.52777099609375, 2541.5087890625, 388.577301025390625, 3.717300891876220703, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Bilespray Lasher (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 177645 - Submerged)
(@CGUID+96, 121023, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -502.151031494140625, 2528.9453125, 251.736968994140625, 5.794710159301757812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Legionfall Soldier (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 35356 - Spawn Feign Death)
(@CGUID+97, 121569, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -496.02777099609375, 2502.765625, 388.2705078125, 1.326720833778381347, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Vilebark Walker (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 242755 - Spawn Cosmetic)
(@CGUID+98, 118690, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -472.291656494140625, 2529.546875, 334.6943359375, 2.637405633926391601, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Wrathguard Invader (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+99, 121023, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -498.579864501953125, 2562.435791015625, 251.559967041015625, 1.874434113502502441, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Legionfall Soldier (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 35356 - Spawn Feign Death)
(@CGUID+100, 118690, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -473.2100830078125, 2520.8759765625, 334.7568359375, 3.402789592742919921, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Wrathguard Invader (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+101, 121023, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -494.821197509765625, 2568.208251953125, 251.377685546875, 1.874434113502502441, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Legionfall Soldier (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 35356 - Spawn Feign Death)
(@CGUID+102, 121023, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -499.20660400390625, 2487.99658203125, 251.559967041015625, 5.794710159301757812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Legionfall Soldier (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 35356 - Spawn Feign Death)
(@CGUID+103, 120770, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -461.20660400390625, 2552.68310546875, 334.818359375, 1.603429079055786132, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Felguard Destroyer (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+104, 119978, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -456.930572509765625, 2520.251708984375, 384.662750244140625, 5.924142360687255859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Fulminating Lasher (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 177645 - Submerged)
(@CGUID+105, 120778, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -457.6944580078125, 2578.72216796875, 334.818603515625, 1.582703828811645507, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Wrathguard Invader (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+106, 120770, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -451.963531494140625, 2563.16064453125, 334.5323486328125, 1.238280415534973144, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Felguard Destroyer (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+107, 119978, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -456.642364501953125, 2528.076416015625, 384.66290283203125, 0.769181132316589355, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Fulminating Lasher (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 177645 - Submerged)
(@CGUID+108, 121569, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -445.557037353515625, 2558.85400390625, 384.3680419921875, 4.681491851806640625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Vilebark Walker (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 242755 - Spawn Cosmetic) (possible waypoints or random movement)
(@CGUID+109, 118724, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -448.4375, 2482.93408203125, 334.247802734375, 4.210878372192382812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Helblaze Felbringer (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+110, 119930, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -530.97052001953125, 2363.583251953125, 336.595367431640625, 6.181905269622802734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Dreadwing (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+111, 120779, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -436.421875, 2556.6416015625, 334.91571044921875, 1.671573042869567871, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Helblaze Felbringer (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+112, 120779, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -445.571197509765625, 2552.6572265625, 334.5234375, 1.037526488304138183, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Helblaze Felbringer (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+113, 118690, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -495.388885498046875, 2397.0400390625, 334.235595703125, 3.697377920150756835, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Wrathguard Invader (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+114, 118724, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -490.18402099609375, 2395.647705078125, 334.23565673828125, 3.162828683853149414, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Helblaze Felbringer (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+115, 121695, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -551.50518798828125, 2531.764892578125, 388.635009765625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Budding Flower (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+116, 119923, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -445.02777099609375, 2477.40625, 334.2498779296875, 4.806311607360839843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Helblaze Soulmender (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+117, 121695, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -555.39239501953125, 2499.473876953125, 388.263031005859375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Budding Flower (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+118, 120778, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -456.65277099609375, 2606.999267578125, 334.443939208984375, 2.014739036560058593, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Wrathguard Invader (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+119, 119977, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -555.296875, 2502.642333984375, 388.451995849609375, 0.100460290908813476, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Stranglevine Lasher (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 177645 - Submerged)
(@CGUID+120, 118690, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -493.517364501953125, 2387.444580078125, 334.235595703125, 3.962403297424316406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Wrathguard Invader (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+121, 118714, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -451.289947509765625, 2524.7900390625, 384.671051025390625, 3.331277847290039062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Hellblaze Temptress (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 238990 - Barbed Thorns)
(@CGUID+122, 119923, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -492.802093505859375, 2392.663330078125, 334.235687255859375, 3.280608654022216796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Helblaze Soulmender (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+123, 118700, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -458.737518310546875, 2431.648193359375, 334.229095458984375, 4.30797576904296875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Felblight Stalker (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+124, 120779, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -449.91839599609375, 2593.6572265625, 334.49493408203125, 0.26653715968132019, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Helblaze Felbringer (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+125, 120779, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -452.26214599609375, 2614.4921875, 334.251708984375, 2.035320997238159179, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Helblaze Felbringer (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+126, 119190, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -551.94268798828125, 2500.689208984375, 388.451995849609375, 6.107451915740966796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Choking Vines (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+127, 119169, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -548.40625, 2539.177978515625, 388.451995849609375, 0.769455432891845703, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Fulminating Lasher (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 175057 - Submerged)
(@CGUID+128, 118690, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -439.1007080078125, 2478.21533203125, 334.251495361328125, 5.363992214202880859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Wrathguard Invader (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+129, 120779, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -440.04339599609375, 2587.2119140625, 334.490570068359375, 2.304752826690673828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Helblaze Felbringer (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+130, 119930, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -521.4444580078125, 2360.640625, 336.595367431640625, 2.365532636642456054, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Dreadwing (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+131, 118714, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -463.53472900390625, 2430.717041015625, 384.671051025390625, 0.592320561408996582, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Hellblaze Temptress (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 238990 - Barbed Thorns)
(@CGUID+132, 118700, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -458.13702392578125, 2427.4248046875, 334.23602294921875, 4.073705673217773437, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Felblight Stalker (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+133, 118724, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -473.326080322265625, 2407.16259765625, 334.16070556640625, 3.89364171028137207, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Helblaze Felbringer (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+134, 118700, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -466.442779541015625, 2405.385498046875, 334.6195068359375, 3.893690109252929687, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Felblight Stalker (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+135, 118703, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -474.461822509765625, 2406.0244140625, 384.378570556640625, 0.3450242280960083, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Felborne Botanist (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+136, 118703, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -462.796875, 2426.017333984375, 384.3680419921875, 1.170095801353454589, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Felborne Botanist (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+137, 118700, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -468.552764892578125, 2407.519775390625, 334.456695556640625, 3.893700599670410156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Felblight Stalker (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+138, 118703, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -459.19097900390625, 2432.048583984375, 384.382720947265625, 3.949999332427978515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Felborne Botanist (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+139, 118714, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -458.78472900390625, 2427.588623046875, 384.378936767578125, 1.698308944702148437, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Hellblaze Temptress (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 238990 - Barbed Thorns)
(@CGUID+140, 118714, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -471.427093505859375, 2402.71875, 384.375732421875, 2.350673198699951171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Hellblaze Temptress (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 238990 - Barbed Thorns)
(@CGUID+141, 118714, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -445.53472900390625, 2585.319580078125, 384.65447998046875, 6.197778224945068359, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Hellblaze Temptress (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 238990 - Barbed Thorns)
(@CGUID+142, 119190, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -547.53125, 2544.99560546875, 388.451995849609375, 5.163579940795898437, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Choking Vines (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+143, 118703, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -446.399322509765625, 2425.154541015625, 384.62249755859375, 2.563759565353393554, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Felborne Botanist (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+144, 118703, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -449.541656494140625, 2424.875, 384.382598876953125, 0.601628839969635009, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Felborne Botanist (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+145, 120374, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -571.81597900390625, 2409.182373046875, 334.64947509765625, 1.60875856876373291, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Felguard Destroyer (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+146, 118700, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -429.23687744140625, 2372.823974609375, 333.98211669921875, 3.597977161407470703, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Felblight Stalker (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+147, 118700, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -430.78253173828125, 2380.60400390625, 334.36474609375, 3.127811670303344726, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Felblight Stalker (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+148, 118717, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -397.64410400390625, 2441.19091796875, 335.2568359375, 4.335006237030029296, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Helblaze Imp (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+149, 118717, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -402.138458251953125, 2452.8759765625, 335.376434326171875, 3.721817731857299804, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Helblaze Imp (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+150, 118717, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -399.763885498046875, 2443.6875, 335.2568359375, 2.858816146850585937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Helblaze Imp (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+151, 119923, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -424.2569580078125, 2365.55029296875, 335.8563232421875, 2.176370859146118164, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Helblaze Soulmender (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+152, 118717, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -399.486114501953125, 2439.545166015625, 335.82513427734375, 0.851195812225341796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Helblaze Imp (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+153, 118724, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -420.614593505859375, 2366.979248046875, 335.579742431640625, 2.343935489654541015, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Helblaze Felbringer (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+154, 118690, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -389.666656494140625, 2526.151123046875, 346.909423828125, 3.214821100234985351, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Wrathguard Invader (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+155, 118724, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -390.305572509765625, 2520.291748046875, 346.909393310546875, 3.214821100234985351, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Helblaze Felbringer (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+156, 120374, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -453.338531494140625, 2477, 334.24456787109375, 4.745427608489990234, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Felguard Destroyer (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+157, 121695, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -494.670135498046875, 2479.748291015625, 388.624908447265625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Budding Flower (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+158, 118703, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -440.619781494140625, 2586.193603515625, 384.365631103515625, 4.475276947021484375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Felborne Botanist (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+159, 120770, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -444.96527099609375, 2615.132080078125, 334.251708984375, 1.238280415534973144, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Felguard Destroyer (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+160, 119190, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -495.560760498046875, 2493.161376953125, 388.451995849609375, 3.052753925323486328, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Choking Vines (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+161, 120366, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -385.59375, 2523.447998046875, 346.906036376953125, 3.196902751922607421, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Hellblaze Temptress (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 238990 - Barbed Thorns) (possible waypoints or random movement)
(@CGUID+162, 121695, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -494.7100830078125, 2530.673583984375, 388.21533203125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Budding Flower (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+163, 119190, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -501.961822509765625, 2530.67529296875, 388.451995849609375, 4.158277034759521484, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Choking Vines (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+164, 119169, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -497.039947509765625, 2535.1171875, 388.21533203125, 4.312067985534667968, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Fulminating Lasher (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 175057 - Submerged)
(@CGUID+165, 119169, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -494.37152099609375, 2540.618896484375, 388.21533203125, 6.001201152801513671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Fulminating Lasher (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 175057 - Submerged)
(@CGUID+166, 119169, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -500.4132080078125, 2541.0244140625, 388.21533203125, 2.881120681762695312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Fulminating Lasher (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 175057 - Submerged)
(@CGUID+167, 119169, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -496.510406494140625, 2547.458251953125, 388.21533203125, 1.626000404357910156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Fulminating Lasher (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 175057 - Submerged)
(@CGUID+168, 119977, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -500.329864501953125, 2541.447021484375, 389.4532470703125, 3.450186967849731445, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Stranglevine Lasher (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 177645 - Submerged)
(@CGUID+169, 119169, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -501.170135498046875, 2549.27685546875, 388.21533203125, 5.301447868347167968, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Fulminating Lasher (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 175057 - Submerged)
(@CGUID+170, 121231, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -473.11083984375, 2585.33251953125, 543.951416015625, 5.460243701934814453, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Dreadwing (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+171, 121231, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -466.9388427734375, 2561.0458984375, 553.8272705078125, 6.037804126739501953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Dreadwing (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+172, 121231, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -473.966644287109375, 2563.995849609375, 553.20849609375, 5.726826190948486328, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Dreadwing (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+173, 121231, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -467.4661865234375, 2463.909912109375, 551.95806884765625, 3.529485464096069335, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Dreadwing (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+174, 121231, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -478.422821044921875, 2558.43505859375, 560.631103515625, 2.18570709228515625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Dreadwing (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+175, 121231, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -493.579315185546875, 2477.05859375, 552.50909423828125, 0.942606925964355468, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Dreadwing (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+176, 121231, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -503.93963623046875, 2561.526611328125, 559.3453369140625, 5.343160629272460937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Dreadwing (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+177, 121231, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -501.956695556640625, 2467.674072265625, 552.49920654296875, 0.769461572170257568, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Dreadwing (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+178, 121231, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -503.67132568359375, 2466.013427734375, 552.46917724609375, 0.768681466579437255, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Dreadwing (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+179, 121231, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -461.875732421875, 2433.317138671875, 552.9453125, 0.772316992282867431, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Dreadwing (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+180, 121231, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -509.75579833984375, 2460.2666015625, 552.2930908203125, 0.739412605762481689, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Dreadwing (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+181, 121231, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -522.09527587890625, 2582.224365234375, 552.21649169921875, 5.426323890686035156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Dreadwing (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+182, 121231, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -514.19775390625, 2456.364013671875, 552.1593017578125, 0.699648439884185791, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Dreadwing (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+183, 122237, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -524.5382080078125, 2513.598876953125, 439.772369384765625, 2.5415802001953125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Wondrous Library (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+184, 121231, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -514.21929931640625, 2456.345947265625, 552.15875244140625, 0.699411511421203613, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Dreadwing (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+185, 121231, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -540.22637939453125, 2444.350341796875, 553.02508544921875, 6.2079925537109375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Dreadwing (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+186, 121231, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -557.9100341796875, 2449.81201171875, 556.05859375, 5.847147941589355468, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Dreadwing (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+187, 121231, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -560.27069091796875, 2450.941162109375, 556.514892578125, 5.827642440795898437, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Dreadwing (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+188, 121231, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -554.0234375, 2448.09521484375, 555.31622314453125, 5.889748573303222656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Dreadwing (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+189, 122237, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -530.23956298828125, 2507.52685546875, 439.772369384765625, 2.148921728134155273, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Wondrous Library (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+190, 122236, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -523.8836669921875, 2536.529541015625, 439.772369384765625, 3.685205936431884765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Wondrous Library (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+191, 119169, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -536.107666015625, 2550.907958984375, 388.21533203125, 2.024574518203735351, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Fulminating Lasher (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 175057 - Submerged)
(@CGUID+192, 119169, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -537.72393798828125, 2562.046142578125, 388.451995849609375, 5.144656181335449218, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Fulminating Lasher (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 175057 - Submerged)
(@CGUID+193, 119169, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -536.83331298828125, 2568.31689453125, 388.451995849609375, 4.444902420043945312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Fulminating Lasher (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 175057 - Submerged)
(@CGUID+194, 119169, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -545.3194580078125, 2548.577392578125, 388.451995849609375, 3.455522775650024414, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Fulminating Lasher (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 175057 - Submerged)
(@CGUID+195, 119977, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -548.2725830078125, 2548.7509765625, 388.451995849609375, 5.936107158660888671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Stranglevine Lasher (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (Auras: 177645 - Submerged)
(@CGUID+196, 122236, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -529.97222900390625, 2542.7744140625, 439.772369384765625, 4.103479385375976562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Wondrous Library (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+197, 121231, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -553.436767578125, 2589.8671875, 552.50909423828125, 0.244471952319145202, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Dreadwing (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+198, 121231, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -531.04345703125, 2590.11328125, 552.4578857421875, 5.785979747772216796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Dreadwing (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+199, 119897, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -559.36285400390625, 2537.392333984375, 439.772369384765625, 4.507465839385986328, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Wondrous Library (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+200, 119897, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -553.08856201171875, 2543.6796875, 439.772369384765625, 4.495141029357910156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Wondrous Library (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+201, 122238, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -554.0867919921875, 2508.21435546875, 439.772369384765625, 0.958518564701080322, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Wondrous Library (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+202, 122238, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -559.3680419921875, 2514.47216796875, 439.772369384765625, 0.56430143117904663, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Wondrous Library (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+203, 111221, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -573.1961669921875, 2526.244873046875, 439.772369384765625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Xal'atath (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+204, 120246, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 0, -585.40972900390625, 2526.842041015625, 439.928619384765625, 3.133462429046630859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Thal'kiel (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+205, 119147, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -661.5711669921875, 2525.690185546875, 334.636077880859375, 3.180343866348266601, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Maiev Shadowsong (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@CGUID+206, 120792, 1677, 8527, 8527, '2,8,23', 0, 0, 0, 1, -665.654541015625, 2531.71533203125, 333.953369140625, 2.858439922332763671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60822); -- Illidan Stormrage (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+206;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '141502'), -- Wyrmtongue Scavenger - 141502 - Permanent Feign Death
(@CGUID+2, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 3, ''), -- Wrathguard Invader
(@CGUID+4, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 3, ''), -- Wrathguard Invader
(@CGUID+5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '141502'), -- Wyrmtongue Scavenger - 141502 - Permanent Feign Death
(@CGUID+6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '141502'), -- Helblaze Imp - 141502 - Permanent Feign Death
(@CGUID+7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '141502'), -- Wyrmtongue Scavenger - 141502 - Permanent Feign Death
(@CGUID+8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '141502'), -- Helblaze Imp - 141502 - Permanent Feign Death
(@CGUID+9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '141502'), -- Wyrmtongue Scavenger - 141502 - Permanent Feign Death
(@CGUID+10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '141502'), -- Helblaze Imp - 141502 - Permanent Feign Death
(@CGUID+11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '141502'), -- Helblaze Imp - 141502 - Permanent Feign Death
(@CGUID+12, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '141502'), -- Helblaze Imp - 141502 - Permanent Feign Death
(@CGUID+13, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '243557'), -- Wyrmtongue Scavenger - 243557 - Agressive
(@CGUID+14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 5, ''), -- Global Affix Stalker
(@CGUID+15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '243557'), -- Helblaze Imp - 243557 - Agressive
(@CGUID+16, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 3, ''), -- Helblaze Soulmender
(@CGUID+18, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '141502'), -- Legionfall Soldier - 141502 - Permanent Feign Death
(@CGUID+19, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Felborne Botanist
(@CGUID+20, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '141502'), -- Legionfall Soldier - 141502 - Permanent Feign Death
(@CGUID+21, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Bilespray Lasher
(@CGUID+23, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Felblight Stalker
(@CGUID+24, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Helblaze Felbringer
(@CGUID+25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '238990'), -- Hellblaze Temptress - 238990 - Barbed Thorns
(@CGUID+27, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '141502'), -- Legionfall Soldier - 141502 - Permanent Feign Death
(@CGUID+28, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '242755'), -- Vilebark Walker - 242755 - Spawn Cosmetic
(@CGUID+29, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '141502'), -- Legionfall Soldier - 141502 - Permanent Feign Death
(@CGUID+30, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Felborne Botanist
(@CGUID+31, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Felguard Destroyer
(@CGUID+33, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 3, ''), -- Wrathguard Invader
(@CGUID+34, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '177645'), -- Fulminating Lasher - 177645 - Submerged
(@CGUID+36, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '242755'), -- Vilebark Walker - 242755 - Spawn Cosmetic
(@CGUID+38, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '141502'), -- Legionfall Soldier - 141502 - Permanent Feign Death
(@CGUID+39, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '177645'), -- Fulminating Lasher - 177645 - Submerged
(@CGUID+43, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '238990'), -- Hellblaze Temptress - 238990 - Barbed Thorns
(@CGUID+44, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 3, ''), -- Wrathguard Invader
(@CGUID+45, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '238990'), -- Hellblaze Temptress - 238990 - Barbed Thorns
(@CGUID+46, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Felblight Stalker
(@CGUID+47, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Felborne Botanist
(@CGUID+48, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '177645'), -- Fulminating Lasher - 177645 - Submerged
(@CGUID+50, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '177645'), -- Bilespray Lasher - 177645 - Submerged
(@CGUID+51, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '141502'), -- Legionfall Soldier - 141502 - Permanent Feign Death
(@CGUID+54, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '177645'), -- Fulminating Lasher - 177645 - Submerged
(@CGUID+56, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '35356'), -- Legionfall Soldier - 35356 - Spawn Feign Death
(@CGUID+57, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '35356'), -- Legionfall Soldier - 35356 - Spawn Feign Death
(@CGUID+58, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '35356'), -- Legionfall Soldier - 35356 - Spawn Feign Death
(@CGUID+59, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '141502'), -- Legionfall Soldier - 141502 - Permanent Feign Death
(@CGUID+60, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '238990'), -- Hellblaze Temptress - 238990 - Barbed Thorns
(@CGUID+62, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '141502'), -- Legionfall Soldier - 141502 - Permanent Feign Death
(@CGUID+63, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '177645'), -- Bilespray Lasher - 177645 - Submerged
(@CGUID+64, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 3, ''), -- Helblaze Soulmender
(@CGUID+65, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '141502'), -- Legionfall Soldier - 141502 - Permanent Feign Death
(@CGUID+66, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '35356'), -- Legionfall Soldier - 35356 - Spawn Feign Death
(@CGUID+68, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '35356'), -- Legionfall Soldier - 35356 - Spawn Feign Death
(@CGUID+69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '35356'), -- Legionfall Soldier - 35356 - Spawn Feign Death
(@CGUID+71, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '237597'), -- Legionfall Soldier - 237597 - Scared Cosmetic
(@CGUID+72, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 3, ''), -- Wrathguard Invader
(@CGUID+73, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '35356'), -- Legionfall Soldier - 35356 - Spawn Feign Death
(@CGUID+74, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '141502'), -- Legionfall Soldier - 141502 - Permanent Feign Death
(@CGUID+75, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '141502'), -- Legionfall Soldier - 141502 - Permanent Feign Death
(@CGUID+76, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '35356'), -- Legionfall Soldier - 35356 - Spawn Feign Death
(@CGUID+78, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '141502'), -- Legionfall Soldier - 141502 - Permanent Feign Death
(@CGUID+79, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 3, ''), -- Wrathguard Invader
(@CGUID+80, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Dreadhunter
(@CGUID+82, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- Durgan Stonestorm
(@CGUID+83, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '35356'), -- Legionfall Soldier - 35356 - Spawn Feign Death
(@CGUID+84, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '177645'), -- Bilespray Lasher - 177645 - Submerged
(@CGUID+85, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Felborne Botanist
(@CGUID+87, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '141502'), -- Legionfall Soldier - 141502 - Permanent Feign Death
(@CGUID+89, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '35356'), -- Legionfall Soldier - 35356 - Spawn Feign Death
(@CGUID+91, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '35356'), -- Legionfall Soldier - 35356 - Spawn Feign Death
(@CGUID+94, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '35356'), -- Legionfall Soldier - 35356 - Spawn Feign Death
(@CGUID+95, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '177645'), -- Bilespray Lasher - 177645 - Submerged
(@CGUID+96, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '35356'), -- Legionfall Soldier - 35356 - Spawn Feign Death
(@CGUID+97, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '242755'), -- Vilebark Walker - 242755 - Spawn Cosmetic
(@CGUID+98, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 3, ''), -- Wrathguard Invader
(@CGUID+99, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '35356'), -- Legionfall Soldier - 35356 - Spawn Feign Death
(@CGUID+100, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 3, ''), -- Wrathguard Invader
(@CGUID+101, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '35356'), -- Legionfall Soldier - 35356 - Spawn Feign Death
(@CGUID+102, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '35356'), -- Legionfall Soldier - 35356 - Spawn Feign Death
(@CGUID+104, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '177645'), -- Fulminating Lasher - 177645 - Submerged
(@CGUID+107, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '177645'), -- Fulminating Lasher - 177645 - Submerged
(@CGUID+108, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '242755'), -- Vilebark Walker - 242755 - Spawn Cosmetic
(@CGUID+109, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 3, ''), -- Helblaze Felbringer
(@CGUID+110, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 3, ''), -- Dreadwing
(@CGUID+113, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 3, ''), -- Wrathguard Invader
(@CGUID+114, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 3, ''), -- Helblaze Felbringer
(@CGUID+116, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 3, ''), -- Helblaze Soulmender
(@CGUID+119, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '177645'), -- Stranglevine Lasher - 177645 - Submerged
(@CGUID+120, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 3, ''), -- Wrathguard Invader
(@CGUID+121, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '238990'), -- Hellblaze Temptress - 238990 - Barbed Thorns
(@CGUID+122, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 3, ''), -- Helblaze Soulmender
(@CGUID+123, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Felblight Stalker
(@CGUID+126, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Choking Vines
(@CGUID+127, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '175057'), -- Fulminating Lasher - 175057 - Submerged
(@CGUID+128, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 3, ''), -- Wrathguard Invader
(@CGUID+130, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 3, ''), -- Dreadwing
(@CGUID+131, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '238990'), -- Hellblaze Temptress - 238990 - Barbed Thorns
(@CGUID+139, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '238990'), -- Hellblaze Temptress - 238990 - Barbed Thorns
(@CGUID+140, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '238990'), -- Hellblaze Temptress - 238990 - Barbed Thorns
(@CGUID+141, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '238990'), -- Hellblaze Temptress - 238990 - Barbed Thorns
(@CGUID+142, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Choking Vines
(@CGUID+145, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Felguard Destroyer
(@CGUID+151, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 3, ''), -- Helblaze Soulmender
(@CGUID+153, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 3, ''), -- Helblaze Felbringer
(@CGUID+156, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Felguard Destroyer
(@CGUID+160, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Choking Vines
(@CGUID+161, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '238990'), -- Hellblaze Temptress - 238990 - Barbed Thorns
(@CGUID+163, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Choking Vines
(@CGUID+164, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '175057'), -- Fulminating Lasher - 175057 - Submerged
(@CGUID+165, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '175057'), -- Fulminating Lasher - 175057 - Submerged
(@CGUID+166, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '175057'), -- Fulminating Lasher - 175057 - Submerged
(@CGUID+167, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '175057'), -- Fulminating Lasher - 175057 - Submerged
(@CGUID+168, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '177645'), -- Stranglevine Lasher - 177645 - Submerged
(@CGUID+169, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '175057'), -- Fulminating Lasher - 175057 - Submerged
(@CGUID+191, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '175057'), -- Fulminating Lasher - 175057 - Submerged
(@CGUID+192, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '175057'), -- Fulminating Lasher - 175057 - Submerged
(@CGUID+193, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '175057'), -- Fulminating Lasher - 175057 - Submerged
(@CGUID+194, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '175057'), -- Fulminating Lasher - 175057 - Submerged
(@CGUID+195, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '177645'); -- Stranglevine Lasher - 177645 - Submerged

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+19;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 268714, 1677, 8527, 8527, '2,8,23', 0, 0, -617.83245849609375, 2452.820068359375, 335.13751220703125, 3.298687219619750976, 0, 0, -0.99691677093505859, 0.078466430306434631, 7200, 255, 1, 60822), -- Door (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@OGUID+1, 252245, 1677, 8527, 8527, '2,8,23', 0, 0, -712.5694580078125, 2528.779541015625, 333.792449951171875, 6.268949031829833984, 0, 0, -0.00711822509765625, 0.999974668025970458, 7200, 255, 1, 60822), -- Instance Portal (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@OGUID+2, 268709, 1677, 8527, 8527, '2,8,23', 0, 0, -587.050537109375, 2526.378662109375, 455.61724853515625, 4.694939613342285156, 0, 0, -0.71324920654296875, 0.700910508632659912, 7200, 255, 0, 60822), -- Door (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@OGUID+3, 268374, 1677, 8527, 8527, '2,8,23', 0, 0, -557.2445068359375, 2541.4755859375, 439.4580078125, 2.356194972991943359, 0, 0, 0.923879623413085937, 0.382683247327804565, 7200, 255, 1, 60822), -- Doodad_7DU_TombofSargeras_CircularBookCase003 (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@OGUID+4, 268373, 1677, 8527, 8527, '2,8,23', 0, 0, -557.72894287109375, 2510.28564453125, 439.4580078125, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 7200, 255, 1, 60822), -- Doodad_7DU_TombofSargeras_CircularBookCase002 (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@OGUID+5, 269223, 1677, 8527, 8527, '2,8,23', 0, 0, -553.39385986328125, 2561.95703125, 388.4320068359375, 5.916669845581054687, 0, 0, -0.18223381042480468, 0.983255207538604736, 7200, 255, 1, 60822), -- Doodad_7DU_TombofSargeras_GardenDoor003 (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@OGUID+6, 268713, 1677, 8527, 8527, '2,8,23', 0, 0, -594.11602783203125, 2402.3603515625, 335.32550048828125, 3.874636650085449218, 0, 0, -0.9335794448852539, 0.358370482921600341, 7200, 255, 1, 60822), -- Door (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@OGUID+7, 269221, 1677, 8527, 8527, '2,8,23', 0, 0, -560.1375732421875, 2489.6826171875, 387.9461669921875, 0.122174888849258422, 0, 0, 0.061049461364746093, 0.998134732246398925, 7200, 255, 1, 60822), -- Doodad_7DU_TombofSargeras_GardenDoor001 (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@OGUID+8, 269042, 1677, 8527, 8527, '2,8,23', 0, 0, -594.2745361328125, 2402.23046875, 385.5869140625, 3.857182979583740234, 0, 0, -0.93667125701904296, 0.350209832191467285, 7200, 255, 1, 60822), -- Door (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@OGUID+9, 268711, 1677, 8527, 8527, '2,8,23', 0, 0, -430.9959716796875, 2449.580078125, 335.41693115234375, 6.099930286407470703, 0, 0, -0.09149932861328125, 0.995805144309997558, 7200, 255, 1, 60822), -- Door (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@OGUID+10, 268710, 1677, 8527, 8527, '2,8,23', 0, 0, -496.76458740234375, 2524.7421875, 455.61724853515625, 1.553344011306762695, 0, 0, 0.700909614562988281, 0.71325010061264038, 7200, 255, 1, 60822), -- Door (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@OGUID+11, 268375, 1677, 8527, 8527, '2,8,23', 0, 0, -525.98565673828125, 2540.99169921875, 439.4580078125, 0.785400927066802978, 0, 0, 0.382684707641601562, 0.923878967761993408, 7200, 255, 1, 60822), -- Doodad_7DU_TombofSargeras_CircularBookCase004 (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@OGUID+12, 268680, 1677, 8527, 8527, '2,8,23', 0, 0, -579.3448486328125, 2526.73291015625, 550.9117431640625, 4.694939613342285156, 0, 0, -0.71324920654296875, 0.700910508632659912, 7200, 255, 0, 60822), -- Door (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@OGUID+13, 269122, 1677, 8527, 8527, '2,8,23', 0, 0, -513.52227783203125, 2523.6787109375, 491.570098876953125, 6.265737056732177734, 0, 0, -0.00872421264648437, 0.999961912631988525, 7200, 255, 0, 60822), -- Fel Barrier (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@OGUID+14, 268372, 1677, 8527, 8527, '2,8,23', 0, 0, -526.3812255859375, 2509.5751953125, 439.4580078125, 5.5152435302734375, 0, 0, -0.37460517883300781, 0.927184462547302246, 7200, 255, 1, 60822), -- Doodad_7DU_TombofSargeras_CircularBookCase001 (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@OGUID+15, 269121, 1677, 8527, 8527, '2,8,23', 0, 0, -570.52691650390625, 2524.673583984375, 491.570098876953125, 6.265737056732177734, 0, 0, -0.00872421264648437, 0.999961912631988525, 7200, 255, 1, 60822), -- Fel Barrier (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@OGUID+16, 269222, 1677, 8527, 8527, '2,8,23', 0, 0, -487.594970703125, 2488.37744140625, 388.0341796875, 2.984498262405395507, 0, 0, 0.996916770935058593, 0.078466430306434631, 7200, 255, 1, 60822), -- Doodad_7DU_TombofSargeras_GardenDoor002 (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@OGUID+17, 268712, 1677, 8527, 8527, '2,8,23', 0, 0, -456.3856201171875, 2399.806640625, 335.57843017578125, 5.523970603942871093, 0, 0, -0.37055587768554687, 0.928810179233551025, 7200, 255, 1, 60822), -- Door (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@OGUID+18, 268726, 1677, 8527, 8527, '2,8,23', 0, 0, -1034.904541015625, 1967.607666015625, 48.3911895751953125, 2.007127046585083007, 0.056676387786865234, -0.02165603637695312, 0.842226982116699218, 0.535698175430297851, 7200, 255, 1, 60822), -- Legion Torch (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
(@OGUID+19, 269224, 1677, 8527, 8527, '2,8,23', 0, 0, -492.094024658203125, 2560.69873046875, 388.4320068359375, 3.508116960525512695, 0, 0, -0.98325443267822265, 0.182238012552261352, 7200, 255, 0, 60822); -- Doodad_7DU_TombofSargeras_GardenDoor004 (Area: Cathedral of Eternal Night - Difficulty: Mythic) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+19;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, -0.71324938535690307, 0.700910329818725585, 0, 0), -- Door
(@OGUID+2, 0, 0, -0.71324938535690307, 0.700910329818725585, 0, 0), -- Door
(@OGUID+3, 0, 0, -0.71324938535690307, 0.700910329818725585, 0, 0), -- Doodad_7DU_TombofSargeras_CircularBookCase003
(@OGUID+4, 0, 0, -0.71324938535690307, 0.700910329818725585, 0, 0), -- Doodad_7DU_TombofSargeras_CircularBookCase002
(@OGUID+5, 0, 0, -0.71324938535690307, 0.700910329818725585, 0, 0), -- Doodad_7DU_TombofSargeras_GardenDoor003
(@OGUID+6, 0, 0, -0.71324938535690307, 0.700910329818725585, 0, 0), -- Door
(@OGUID+7, 0, 0, -0.71324938535690307, 0.700910329818725585, 0, 0), -- Doodad_7DU_TombofSargeras_GardenDoor001
(@OGUID+8, 0, 0, -0.71324938535690307, 0.700910329818725585, 0, 0), -- Door
(@OGUID+9, 0, 0, -0.71324938535690307, 0.700910329818725585, 0, 0), -- Door
(@OGUID+10, 0, 0, -0.71324938535690307, 0.700910329818725585, 0, 0), -- Door
(@OGUID+11, 0, 0, -0.71324938535690307, 0.700910329818725585, 0, 0), -- Doodad_7DU_TombofSargeras_CircularBookCase004
(@OGUID+12, 0, 0, -0.71324938535690307, 0.700910329818725585, 0, 0), -- Door
(@OGUID+13, 0, 0, -0.71324938535690307, 0.700910329818725585, 0, 0), -- Fel Barrier
(@OGUID+14, 0, 0, -0.71324938535690307, 0.700910329818725585, 0, 0), -- Doodad_7DU_TombofSargeras_CircularBookCase001
(@OGUID+15, 0, 0, -0.71324938535690307, 0.700910329818725585, 0, 0), -- Fel Barrier
(@OGUID+16, 0, 0, -0.71324938535690307, 0.700910329818725585, 0, 0), -- Doodad_7DU_TombofSargeras_GardenDoor002
(@OGUID+17, 0, 0, -0.71324938535690307, 0.700910329818725585, 0, 0), -- Door
(@OGUID+19, 0, 0, -0.71324938535690307, 0.700910329818725585, 0, 0); -- Doodad_7DU_TombofSargeras_GardenDoor004

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (121231 /*121231 (Dreadwing)*/, 120366 /*120366 (Hellblaze Temptress) - Barbed Thorns*/, 119169 /*119169 (Fulminating Lasher) - Submerged*/, 119190 /*119190 (Choking Vines)*/, 119930 /*119930 (Dreadwing)*/, 119977 /*119977 (Stranglevine Lasher) - Submerged*/, 119777 /*119777 (Durgan Stonestorm)*/, 121318 /*121318 (Fulminating Lasher)*/, 118716 /*118716 (Bilespray Lasher) - Submerged*/, 120550 /*120550 (Wrathguard Invader)*/, 119952 /*119952 (Felguard Destroyer)*/, 120556 /*120556 (Dreadwing)*/, 117193 /*117193 (Agronox) - Oakheart Auto Attack Sounds, Summon*/, 121023 /*121023 (Legionfall Soldier) - Spawn Feign Death*/, 118714 /*118714 (Hellblaze Temptress) - Barbed Thorns*/, 118700 /*118700 (Felblight Stalker)*/, 120778 /*120778 (Wrathguard Invader)*/, 121711 /*121711 (Bilespray Lasher)*/, 119978 /*119978 (Fulminating Lasher) - Submerged*/, 120776 /*120776 (Legionfall Soldier)*/, 118704 /*118704 (Dul'zak)*/, 118703 /*118703 (Felborne Botanist)*/, 120770 /*120770 (Felguard Destroyer)*/, 118724 /*118724 (Helblaze Felbringer)*/, 119768 /*119768 (Legionfall Soldier) - Permanent Feign Death*/, 119923 /*119923 (Helblaze Soulmender)*/, 120779 /*120779 (Helblaze Felbringer)*/, 118717 /*118717 (Helblaze Imp) - Permanent Feign Death*/, 118690 /*118690 (Wrathguard Invader)*/, 118719 /*118719 (Wyrmtongue Scavenger) - Permanent Feign Death*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(121231, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 121231 (Dreadwing)
(120366, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 120366 (Hellblaze Temptress) - Barbed Thorns
(119169, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 119169 (Fulminating Lasher) - Submerged
(119190, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 119190 (Choking Vines)
(119930, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 119930 (Dreadwing)
(119977, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 119977 (Stranglevine Lasher) - Submerged
(119777, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 119777 (Durgan Stonestorm)
(121318, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 121318 (Fulminating Lasher)
(118716, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 118716 (Bilespray Lasher) - Submerged
(120550, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 120550 (Wrathguard Invader)
(119952, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 119952 (Felguard Destroyer)
(120556, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 120556 (Dreadwing)
(117193, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '218987 244332'), -- 117193 (Agronox) - Oakheart Auto Attack Sounds, Summon
(121023, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 121023 (Legionfall Soldier) - Spawn Feign Death
(118714, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 118714 (Hellblaze Temptress) - Barbed Thorns
(118700, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 118700 (Felblight Stalker)
(120778, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 120778 (Wrathguard Invader)
(121711, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 121711 (Bilespray Lasher)
(119978, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 119978 (Fulminating Lasher) - Submerged
(120776, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 120776 (Legionfall Soldier)
(118704, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 118704 (Dul'zak)
(118703, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 118703 (Felborne Botanist)
(120770, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 120770 (Felguard Destroyer)
(118724, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 118724 (Helblaze Felbringer)
(119768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 119768 (Legionfall Soldier) - Permanent Feign Death
(119923, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 119923 (Helblaze Soulmender)
(120779, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 120779 (Helblaze Felbringer)
(118717, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 118717 (Helblaze Imp) - Permanent Feign Death
(118690, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 118690 (Wrathguard Invader)
(118719, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''); -- 118719 (Wyrmtongue Scavenger) - Permanent Feign Death

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (269224 /*Doodad_7DU_TombofSargeras_GardenDoor004*/, 268726 /*Legion Torch*/, 268712 /*Door*/, 269222 /*Doodad_7DU_TombofSargeras_GardenDoor002*/, 269121 /*Fel Barrier*/, 268372 /*Doodad_7DU_TombofSargeras_CircularBookCase001*/, 269122 /*Fel Barrier*/, 268680 /*Door*/, 268375 /*Doodad_7DU_TombofSargeras_CircularBookCase004*/, 268710 /*Door*/, 268711 /*Door*/, 269042 /*Door*/, 269221 /*Doodad_7DU_TombofSargeras_GardenDoor001*/, 268713 /*Door*/, 269223 /*Doodad_7DU_TombofSargeras_GardenDoor003*/, 268373 /*Doodad_7DU_TombofSargeras_CircularBookCase002*/, 268374 /*Doodad_7DU_TombofSargeras_CircularBookCase003*/, 268709 /*Door*/, 268714 /*Door*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(269224, 1375, 0x30, 0, 0), -- Doodad_7DU_TombofSargeras_GardenDoor004
(268726, 0, 0x40020, 0, 0), -- Legion Torch
(268712, 0, 0x20, 0, 0), -- Door
(269222, 1375, 0x30, 0, 0), -- Doodad_7DU_TombofSargeras_GardenDoor002
(269121, 0, 0x30, 0, 0), -- Fel Barrier
(268372, 0, 0x30, 0, 0), -- Doodad_7DU_TombofSargeras_CircularBookCase001
(269122, 0, 0x30, 0, 0), -- Fel Barrier
(268680, 0, 0x30, 0, 0), -- Door
(268375, 0, 0x30, 0, 0), -- Doodad_7DU_TombofSargeras_CircularBookCase004
(268710, 0, 0x30, 0, 0), -- Door
(268711, 0, 0x20, 0, 0), -- Door
(269042, 0, 0x20, 0, 0), -- Door
(269221, 1375, 0x30, 0, 0), -- Doodad_7DU_TombofSargeras_GardenDoor001
(268713, 0, 0x20, 0, 0), -- Door
(269223, 1375, 0x30, 0, 0), -- Doodad_7DU_TombofSargeras_GardenDoor003
(268373, 0, 0x30, 0, 0), -- Doodad_7DU_TombofSargeras_CircularBookCase002
(268374, 0, 0x30, 0, 0), -- Doodad_7DU_TombofSargeras_CircularBookCase003
(268709, 0, 0x30, 0, 0), -- Door
(268714, 0, 0x20, 0, 0); -- Door

-- Template
DELETE FROM `gameobject_template` WHERE `entry`=268726;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(268726, 10, 27615, 'Legion Torch', 'questinteract', 'Lighting', '', 1.549999952316284179, 1690, 0, 0, 0, 0, 0, 0, 0, 0, 0, 233546, 0, 0, 1, 28503, 0, 0, 0, 0, 0, 1, 0, 48249, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 336, 60822); -- Legion Torch

-- Difficulty (Heroic)
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=2 AND `Entry` IN (120246,119777,121023,119768));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`, `VerifiedBuild`) VALUES
(120246, 2, 0, 0, 642, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 60822), -- 120246 (Thal'kiel) - 
(119777, 2, 0, 0, 498, 0x20000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 60822), -- 119777 (Durgan Stonestorm) - Sessile, Floating
(121023, 2, 0, 0, 498, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 60822), -- 121023 (Legionfall Soldier) - 
(119768, 2, 0, 0, 498, 0x100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 60822); -- 119768 (Legionfall Soldier) - Sessile

UPDATE `creature_template_difficulty` SET `VerifiedBuild`=60822 WHERE (`Entry`=111221 AND `DifficultyID`=2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x30000000, `VerifiedBuild`=60822 WHERE (`Entry`=121231 AND `DifficultyID`=2); -- 121231 (Dreadwing) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=120366 AND `DifficultyID`=2); -- 120366 (Hellblaze Temptress) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x30000100, `VerifiedBuild`=60822 WHERE (`Entry`=119169 AND `DifficultyID`=2); -- 119169 (Fulminating Lasher) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=119930 AND `DifficultyID`=2); -- 119930 (Dreadwing) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=119977 AND `DifficultyID`=2); -- 119977 (Stranglevine Lasher) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=120374 AND `DifficultyID`=2); -- 120374 (Felguard Destroyer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=121318 AND `DifficultyID`=2); -- 121318 (Fulminating Lasher) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=118716 AND `DifficultyID`=2); -- 118716 (Bilespray Lasher) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x30000000, `VerifiedBuild`=60822 WHERE (`Entry`=120550 AND `DifficultyID`=2); -- 120550 (Wrathguard Invader) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x30000000, `VerifiedBuild`=60822 WHERE (`Entry`=119952 AND `DifficultyID`=2); -- 119952 (Felguard Destroyer) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x30000000, `VerifiedBuild`=60822 WHERE (`Entry`=120556 AND `DifficultyID`=2); -- 120556 (Dreadwing) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=117193 AND `DifficultyID`=2); -- 117193 (Agronox) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=118714 AND `DifficultyID`=2); -- 118714 (Hellblaze Temptress) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=118700 AND `DifficultyID`=2); -- 118700 (Felblight Stalker) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=120778 AND `DifficultyID`=2); -- 120778 (Wrathguard Invader) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=121711 AND `DifficultyID`=2); -- 121711 (Bilespray Lasher) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=119978 AND `DifficultyID`=2); -- 119978 (Fulminating Lasher) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=118704 AND `DifficultyID`=2); -- 118704 (Dul'zak) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=118703 AND `DifficultyID`=2); -- 118703 (Felborne Botanist) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=120770 AND `DifficultyID`=2); -- 120770 (Felguard Destroyer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=118724 AND `DifficultyID`=2); -- 118724 (Helblaze Felbringer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=119923 AND `DifficultyID`=2); -- 119923 (Helblaze Soulmender) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=120779 AND `DifficultyID`=2); -- 120779 (Helblaze Felbringer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000100, `VerifiedBuild`=60822 WHERE (`Entry`=118717 AND `DifficultyID`=2); -- 118717 (Helblaze Imp) - Sessile, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=118690 AND `DifficultyID`=2); -- 118690 (Wrathguard Invader) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000100, `VerifiedBuild`=60822 WHERE (`Entry`=118719 AND `DifficultyID`=2); -- 118719 (Wyrmtongue Scavenger) - Sessile, CanSwim

-- Difficulty (Mythic)
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=23 AND `Entry` IN (120246,119777,121023,119768));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`, `VerifiedBuild`) VALUES
(120246, 23, 0, 0, 642, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 60822), -- 120246 (Thal'kiel) - 
(119777, 23, 0, 0, 498, 0x20000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 60822), -- 119777 (Durgan Stonestorm) - Sessile, Floating
(121023, 23, 0, 0, 498, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 60822), -- 121023 (Legionfall Soldier) - 
(119768, 23, 0, 0, 498, 0x100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 60822); -- 119768 (Legionfall Soldier) - Sessile

UPDATE `creature_template_difficulty` SET `VerifiedBuild`=60822 WHERE (`Entry`=111221 AND `DifficultyID`=23);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x30000000, `VerifiedBuild`=60822 WHERE (`Entry`=121231 AND `DifficultyID`=23); -- 121231 (Dreadwing) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=120366 AND `DifficultyID`=23); -- 120366 (Hellblaze Temptress) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x30000100, `VerifiedBuild`=60822 WHERE (`Entry`=119169 AND `DifficultyID`=23); -- 119169 (Fulminating Lasher) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=119977 AND `DifficultyID`=23); -- 119977 (Stranglevine Lasher) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=119930 AND `DifficultyID`=23); -- 119930 (Dreadwing) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x30000100, `VerifiedBuild`=60822 WHERE (`Entry`=121554 AND `DifficultyID`=23); -- 121554 (Dreadhunter) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=117193 AND `DifficultyID`=23); -- 117193 (Agronox) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x30000000, `VerifiedBuild`=60822 WHERE (`Entry`=121553 AND `DifficultyID`=23); -- 121553 (Dreadhunter) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=121318 AND `DifficultyID`=23); -- 121318 (Fulminating Lasher) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x30000000, `VerifiedBuild`=60822 WHERE (`Entry`=119952 AND `DifficultyID`=23); -- 119952 (Felguard Destroyer) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=118716 AND `DifficultyID`=23); -- 118716 (Bilespray Lasher) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x30000000, `VerifiedBuild`=60822 WHERE (`Entry`=120550 AND `DifficultyID`=23); -- 120550 (Wrathguard Invader) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x30000000, `VerifiedBuild`=60822 WHERE (`Entry`=120556 AND `DifficultyID`=23); -- 120556 (Dreadwing) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=119978 AND `DifficultyID`=23); -- 119978 (Fulminating Lasher) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=118704 AND `DifficultyID`=23); -- 118704 (Dul'zak) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=120374 AND `DifficultyID`=23); -- 120374 (Felguard Destroyer) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=121569 AND `DifficultyID`=23); -- 121569 (Vilebark Walker) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=118714 AND `DifficultyID`=23); -- 118714 (Hellblaze Temptress) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=118700 AND `DifficultyID`=23); -- 118700 (Felblight Stalker) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=120778 AND `DifficultyID`=23); -- 120778 (Wrathguard Invader) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=121711 AND `DifficultyID`=23); -- 121711 (Bilespray Lasher) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=118703 AND `DifficultyID`=23); -- 118703 (Felborne Botanist) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=120770 AND `DifficultyID`=23); -- 120770 (Felguard Destroyer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=119923 AND `DifficultyID`=23); -- 119923 (Helblaze Soulmender) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000100, `VerifiedBuild`=60822 WHERE (`Entry`=118717 AND `DifficultyID`=23); -- 118717 (Helblaze Imp) - Sessile, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=120779 AND `DifficultyID`=23); -- 120779 (Helblaze Felbringer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=118690 AND `DifficultyID`=23); -- 118690 (Wrathguard Invader) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=118724 AND `DifficultyID`=23); -- 118724 (Helblaze Felbringer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000100, `VerifiedBuild`=60822 WHERE (`Entry`=118719 AND `DifficultyID`=23); -- 118719 (Wyrmtongue Scavenger) - Sessile, CanSwim

-- Scene
DELETE FROM `scene_template` WHERE `SceneId`=1706;
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`, `Encrypted`) VALUES
(1706, 20, 1889, 0);

/* Scene Spell: 243614 (Tomb Scene [DNT]) */

-- Creature Equip
DELETE FROM `creature_equip_template` WHERE (`CreatureID`=120776 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(120776, 1, 109637, 0, 0, 110156, 0, 0, 0, 0, 0, 60822); -- Legionfall Soldier

-- SpellScript
DELETE FROM `spell_script_names` WHERE `spell_id` = 141502;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(141502, 'spell_gen_feign_death_all_flags_uninteractible');

-- SpellClick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 121553;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(121553, 46598, 1, 0);

-- Vehicle
DELETE FROM `vehicle_template_accessory` WHERE (`entry`=121553 AND `seat_id`=0);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(121553, 121554, 0, 0, 'Dreadhunter - Dreadhunter', 8, 0); -- Dreadhunter - Dreadhunter

-- Felborne Botanist smart ai
SET @ENTRY := 118703;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 1, 1000, 1000, 0, 0, 0, 85, 240773, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Time = 1 seconds (OOC) - Self: Cast spell 240773 on self', '');

UPDATE `creature` SET `StringId` = 'FeederBotanist' WHERE `guid` IN (@CGUID+86,@CGUID+67,@CGUID+61);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 118703 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 118703, 0, 0, 58, 1, 0, 0, 0, 'FeederBotanist', 0, 'Object has StringID FeederBotanist');

-- Path for Hellblaze Felbringer
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+24;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+24, @CGUID+24, 0, 0, 515, 0, 0),
(@CGUID+24, @CGUID+46, 3, 290, 515, 0, 4),
(@CGUID+24, @CGUID+23, 3, 90, 515, 0, 4);

SET @MOVERGUID := @CGUID+24;
SET @ENTRY := 118724;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Helblaze Felbringer - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -582.6024, 2410.1199, 334.41986, NULL, 3651),
(@PATH, 1, -593.11633, 2427.1597, 334.21347, NULL, 0),
(@PATH, 2, -602.9601, 2454.7551, 334.36716, NULL, 0),
(@PATH, 3, -605.11456, 2467.1128, 334.24036, NULL, 0),
(@PATH, 4, -601.9375, 2488.198, 334.27, NULL, 4183),
(@PATH, 5, -605.11456, 2467.1128, 334.24036, NULL, 0),
(@PATH, 6, -602.9601, 2454.7551, 334.36716, NULL, 0),
(@PATH, 7, -593.11633, 2427.1597, 334.21347, NULL, 0);

UPDATE `creature` SET `position_x`=-582.6024, `position_y`=2410.1199, `position_z`=334.41986 WHERE `guid` IN (@CGUID+46, @CGUID+23);
UPDATE `creature` SET `position_x`=-582.6024, `position_y`=2410.1199, `position_z`=334.41986, `orientation`=5.3993, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Hellblaze Felbringer
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+133;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+133, @CGUID+133, 0, 0, 515, 0, 0),
(@CGUID+133, @CGUID+137, 3, 290, 515, 4, 8),
(@CGUID+133, @CGUID+134, 6, 290, 515, 4, 8),
(@CGUID+133, @CGUID+132, 3, 70, 515, 4, 8),
(@CGUID+133, @CGUID+123, 6, 70, 515, 4, 8);

SET @MOVERGUID := @CGUID+133;
SET @ENTRY := 118724;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Helblaze Felbringer - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -445.47223, 2451.6042, 334.5645, NULL, 0),
(@PATH, 1, -451.46353, 2431.3801, 334.42648, NULL, 0),
(@PATH, 2, -460.61978, 2419.0486, 334.2188, NULL, 0),
(@PATH, 3, -482.375, 2398.698, 334.16486, NULL, 0),
(@PATH, 4, -485.72916, 2396.5452, 334.16486, NULL, 5156),
(@PATH, 5, -460.61978, 2419.0486, 334.2188, NULL, 0),
(@PATH, 6, -451.46353, 2431.3801, 334.42648, NULL, 0),
(@PATH, 7, -445.47223, 2451.6042, 334.5645, NULL, 0),
(@PATH, 8, -444.6059, 2471.2986, 334.26974, NULL, 3864);

UPDATE `creature` SET `position_x`=-445.47223, `position_y`=2451.6042, `position_z`=334.5645, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Hellblaze Temptress
SET @MOVERGUID := @CGUID+60;
SET @ENTRY := 118714;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Hellblaze Temptress - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -545.26044, 2528.9524, 388.61975, NULL, 0),
(@PATH, 1, -545.71875, 2519.2456, 388.6009, NULL, 0),
(@PATH, 2, -541.98267, 2504.2979, 388.61972, NULL, 0),
(@PATH, 3, -533.1632, 2493.8508, 388.7091, NULL, 0),
(@PATH, 4, -523.8594, 2491.8247, 388.86118, NULL, 0),
(@PATH, 5, -514.46875, 2493.0815, 388.7235, NULL, 0),
(@PATH, 6, -505.98785, 2498.6458, 388.528, NULL, 0),
(@PATH, 7, -501.83508, 2510.2996, 388.5555, NULL, 0),
(@PATH, 8, -500.81946, 2524.341, 388.55548, NULL, 0),
(@PATH, 9, -504.04166, 2534.2258, 388.55548, NULL, 0),
(@PATH, 10, -510.73785, 2542.501, 388.5555, NULL, 0),
(@PATH, 11, -523.19617, 2548.816, 388.63123, NULL, 0),
(@PATH, 12, -537.86115, 2540.8281, 388.61972, NULL, 0);

UPDATE `creature` SET `position_x`=-545.26044, `position_y`=2528.9524, `position_z`=388.61975, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Vilebark Walker
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+28;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+28, @CGUID+28, 0, 0, 515, 0, 0),
(@CGUID+28, @CGUID+21, 4, 90, 515, 2, 0);

SET @MOVERGUID := @CGUID+28;
SET @ENTRY := 121569;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Vilebark Walker - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -601.40106, 2560.8333, 384.41916, NULL, 5797),
(@PATH, 1, -605.691, 2529.5105, 384.68332, NULL, 0),
(@PATH, 2, -601.1858, 2510.6997, 384.41663, NULL, 6158),
(@PATH, 3, -605.691, 2529.5105, 384.68332, NULL, 0);

UPDATE `creature` SET `position_x`=-601.40106, `position_y`=2560.8333, `position_z`=384.41916 WHERE `guid`=@CGUID+21;
UPDATE `creature` SET `position_x`=-601.40106, `position_y`=2560.8333, `position_z`=384.41916, `orientation`=1.54523, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Vilebark Walker
SET @MOVERGUID := @CGUID+108;
SET @ENTRY := 121569;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Vilebark Walker - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -445.73264, 2553.1736, 384.75864, NULL, 0),
(@PATH, 1, -451.3316, 2529.0469, 384.65524, NULL, 3835),
(@PATH, 2, -446.5625, 2553.3254, 384.75864, NULL, 0),
(@PATH, 3, -444.83682, 2582.1536, 384.40054, NULL, 3887);

UPDATE `creature` SET `position_x`=-445.73264, `position_y`=2553.1736, `position_z`=384.75864, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Vilebark Walker
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+36;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+36, @CGUID+36, 0, 0, 515, 0, 0),
(@CGUID+36, @CGUID+35, 4, 90, 515, 1, 0);

SET @MOVERGUID := @CGUID+36;
SET @ENTRY := 121569;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Vilebark Walker - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -602.3455, 2460.4358, 384.50076, NULL, 5981),
(@PATH, 1, -601.54517, 2490.8525, 384.47308, NULL, 5969);

UPDATE `creature` SET `position_x`=-602.3455, `position_y`=2460.4358, `position_z`=384.50076 WHERE `guid`=@CGUID+35;
UPDATE `creature` SET `position_x`=-602.3455, `position_y`=2460.4358, `position_z`=384.50076, `orientation`=4.9113, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Felborne Botanist
SET @MOVERGUID := @CGUID+52;
SET @ENTRY := 118703;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Felborne Botanist - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -600.8143, 2431.6545, 384.43558, NULL, 3448),
(@PATH, 1, -589.55383, 2437.106, 384.41663, NULL, 3467);

UPDATE `creature` SET `position_x`=-600.8143, `position_y`=2431.6545, `position_z`=384.43558, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Felborne Botanist
SET @MOVERGUID := @CGUID+85;
SET @ENTRY := 118703;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Felborne Botanist - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -614.4811, 2388.7864, 385.52924, NULL, 0),
(@PATH, 1, -623.71875, 2391.1997, 385.41663, NULL, 0),
(@PATH, 2, -631.5764, 2387.816, 385.47263, NULL, 0),
(@PATH, 3, -634.9592, 2381.8853, 385.51825, NULL, 0),
(@PATH, 4, -635.6823, 2374.9514, 385.45395, NULL, 0),
(@PATH, 5, -632.61115, 2367.4045, 385.48083, NULL, 0),
(@PATH, 6, -625.53644, 2363.0452, 385.4166, NULL, 0),
(@PATH, 7, -618.28644, 2362.7344, 385.46744, NULL, 0),
(@PATH, 8, -612.61804, 2366.3977, 385.48972, NULL, 0),
(@PATH, 9, -608.17883, 2374.4324, 385.4166, NULL, 0),
(@PATH, 10, -608.52954, 2382.7778, 385.43024, NULL, 0);

UPDATE `creature` SET `position_x`=-614.4811, `position_y`=2388.7864, `position_z`=385.52924, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Felborne Botanist
SET @MOVERGUID := @CGUID+136;
SET @ENTRY := 118703;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Felborne Botanist - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -470.58682, 2407.6284, 384.4912, NULL, 5293),
(@PATH, 1, -462.79688, 2426.0173, 384.36804, NULL, 5302);

UPDATE `creature` SET `position_x`=-470.58682, `position_y`=2407.6284, `position_z`=384.4912, `orientation`=4.1978, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Dreadhunter
SET @MOVERGUID := @CGUID+80;
SET @ENTRY := 121553;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 23.0803, 'Dreadhunter - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -511.23438, 2531.9973, 336.36758, NULL, 0),
(@PATH, 1, -483.37848, 2507.9062, 339.23428, NULL, 0),
(@PATH, 2, -475.10764, 2488.9758, 339.97415, NULL, 0),
(@PATH, 3, -479.78995, 2454.5208, 339.97415, NULL, 0),
(@PATH, 4, -479.56076, 2406.7415, 341.7512, NULL, 0),
(@PATH, 5, -511.20834, 2385.2534, 342.83542, NULL, 0),
(@PATH, 6, -552.9028, 2392.179, 339.97415, NULL, 0),
(@PATH, 7, -574.4358, 2399.1963, 339.97415, NULL, 0),
(@PATH, 8, -587.6268, 2422.4775, 338.70383, NULL, 0),
(@PATH, 9, -580.7656, 2454.9844, 339.97415, NULL, 0),
(@PATH, 10, -542.48956, 2514.1267, 333.9539, NULL, 0);

UPDATE `creature` SET `position_x`=-511.23438, `position_y`=2531.9973, `position_z`=336.36758, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Dreadwing
SET @MOVERGUID := @CGUID+49;
SET @ENTRY := 120556;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 30.2384, 'Dreadwing - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -579.0781, 2450.0557, 339.97415, NULL, 0),
(@PATH, 1, -565.7465, 2428.7031, 339.97415, NULL, 0),
(@PATH, 2, -541.86633, 2412.0208, 339.97415, NULL, 0),
(@PATH, 3, -509.4896, 2411.2188, 339.97415, NULL, 0),
(@PATH, 4, -483.40277, 2425.861, 339.97415, NULL, 0),
(@PATH, 5, -471.66666, 2444, 339.97415, NULL, 0),
(@PATH, 6, -466.7205, 2467.639, 339.97415, NULL, 0),
(@PATH, 7, -472.83682, 2500.5486, 336.2553, NULL, 0),
(@PATH, 8, -484.62674, 2529.9446, 333.28152, NULL, 0),
(@PATH, 9, -492.1736, 2548.2231, 331.94852, NULL, 0),
(@PATH, 10, -506.54166, 2564.2415, 331.94852, NULL, 0),
(@PATH, 11, -539.84375, 2582.7378, 336.2553, NULL, 0),
(@PATH, 12, -558.4531, 2564.764, 336.2553, NULL, 0),
(@PATH, 13, -569.4566, 2501.3438, 338.43192, NULL, 0),
(@PATH, 14, -577.7118, 2472.1597, 339.97415, NULL, 0);

UPDATE `creature` SET `position_x`=-579.0781, `position_y`=2450.0557, `position_z`=339.97415, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Dreadwing
SET @MOVERGUID := @CGUID+42;
SET @ENTRY := 120556;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 30.2988, 'Dreadwing - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -579.0781, 2450.0557, 349.21136, NULL, 0),
(@PATH, 1, -565.7465, 2428.7031, 349.21136, NULL, 0),
(@PATH, 2, -541.86633, 2412.0208, 349.21136, NULL, 0),
(@PATH, 3, -509.4896, 2411.2188, 349.21136, NULL, 0),
(@PATH, 4, -483.40277, 2425.861, 349.21136, NULL, 0),
(@PATH, 5, -471.66666, 2444, 349.21136, NULL, 0),
(@PATH, 6, -466.7205, 2467.639, 349.21136, NULL, 0),
(@PATH, 7, -472.83682, 2500.5486, 345.49252, NULL, 0),
(@PATH, 8, -484.62674, 2529.9446, 342.51877, NULL, 0),
(@PATH, 9, -492.1736, 2548.2231, 341.18576, NULL, 0),
(@PATH, 10, -506.54166, 2564.2415, 341.18576, NULL, 0),
(@PATH, 11, -539.84375, 2582.7378, 345.49252, NULL, 0),
(@PATH, 12, -558.4531, 2564.764, 345.49252, NULL, 0),
(@PATH, 13, -569.4566, 2501.3438, 347.66916, NULL, 0),
(@PATH, 14, -577.7118, 2472.1597, 349.21136, NULL, 0);

UPDATE `creature` SET `position_x`=-579.0781, `position_y`=2450.0557, `position_z`=349.21136, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Dreadwing
SET @MOVERGUID := @CGUID+93;
SET @ENTRY := 120556;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 27.5756, 'Dreadwing - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -506.54166, 2564.2415, 338.10733, NULL, 0),
(@PATH, 1, -528.5799, 2565.1987, 342.41406, NULL, 0),
(@PATH, 2, -541.99133, 2547.0598, 342.41406, NULL, 0),
(@PATH, 3, -547.4844, 2521.8325, 344.59064, NULL, 0),
(@PATH, 4, -539.15106, 2504.9375, 346.13284, NULL, 0),
(@PATH, 5, -518.184, 2492.9062, 346.13284, NULL, 0),
(@PATH, 6, -505.7205, 2500.6597, 342.41406, NULL, 0),
(@PATH, 7, -496.77084, 2515.6355, 339.44034, NULL, 0),
(@PATH, 8, -495.89758, 2544.5938, 338.10733, NULL, 0);

UPDATE `creature` SET `position_x`=-506.54166, `position_y`=2564.2415, `position_z`=338.10733, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Dreadwing
SET @MOVERGUID := @CGUID+92;
SET @ENTRY := 120556;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 24.9921, 'Dreadwing - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -505.7205, 2500.6597, 342.41406, NULL, 0),
(@PATH, 1, -496.77084, 2515.6355, 339.44034, NULL, 0),
(@PATH, 2, -495.89758, 2544.5938, 338.10733, NULL, 0),
(@PATH, 3, -506.54166, 2564.2415, 338.10733, NULL, 0),
(@PATH, 4, -528.5799, 2565.1987, 342.41406, NULL, 0),
(@PATH, 5, -541.99133, 2547.0598, 342.41406, NULL, 0),
(@PATH, 6, -547.4844, 2521.8325, 344.59064, NULL, 0),
(@PATH, 7, -539.15106, 2504.9375, 346.13284, NULL, 0),
(@PATH, 8, -518.184, 2492.9062, 346.13284, NULL, 0);

UPDATE `creature` SET `position_x`=-505.7205, `position_y`=2500.6597, `position_z`=342.41406, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Dreadwing
SET @MOVERGUID := @CGUID+88;
SET @ENTRY := 120556;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 27.8162, 'Dreadwing - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -495.37848, 2486.3872, 348.38577, NULL, 0),
(@PATH, 1, -514.5677, 2474.4844, 348.38577, NULL, 0),
(@PATH, 2, -531.32294, 2475.014, 348.38577, NULL, 0),
(@PATH, 3, -551.3316, 2485.3142, 348.38577, NULL, 0),
(@PATH, 4, -553.35767, 2518.264, 348.38577, NULL, 0),
(@PATH, 5, -549.0643, 2552.5234, 348.38577, NULL, 0),
(@PATH, 6, -543.7205, 2573.2856, 348.38577, NULL, 0),
(@PATH, 7, -523.6198, 2593.882, 348.38577, NULL, 0),
(@PATH, 8, -503.90103, 2573.9644, 348.38577, NULL, 0),
(@PATH, 9, -495.93576, 2542.4229, 348.38577, NULL, 0),
(@PATH, 10, -490.78125, 2497.566, 348.38577, NULL, 0);

UPDATE `creature` SET `position_x`=-495.37848, `position_y`=2486.3872, `position_z`=348.38577, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Dreadwing
SET @MOVERGUID := @CGUID+170;
SET @ENTRY := 121231;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 14.5443, 'Dreadwing - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -540.3802, 2459.019, 552.5091, NULL, 0),
(@PATH, 1, -562.06946, 2473.5815, 552.5091, NULL, 0),
(@PATH, 2, -567.71875, 2477.3074, 556.53613, NULL, 0),
(@PATH, 3, -582.7344, 2487.0852, 560.9378, NULL, 0),
(@PATH, 4, -592.6389, 2495.132, 560.9378, NULL, 0),
(@PATH, 5, -603.4965, 2490.9426, 561.86945, NULL, 0),
(@PATH, 6, -603.5, 2479.1077, 560.9378, NULL, 0),
(@PATH, 7, -594.1719, 2472.4358, 560.0673, NULL, 0),
(@PATH, 8, -574.63196, 2458.3281, 559.0355, NULL, 0),
(@PATH, 9, -535.5903, 2444.4775, 552.5091, NULL, 0),
(@PATH, 10, -500.467, 2469.1128, 552.5091, NULL, 0),
(@PATH, 11, -485.09897, 2492.9878, 552.5091, NULL, 0),
(@PATH, 12, -488.50522, 2503.9253, 552.5091, NULL, 0),
(@PATH, 13, -501.56598, 2497.0642, 552.5091, NULL, 0),
(@PATH, 14, -511.58508, 2477.1963, 552.5091, NULL, 0);

UPDATE `creature` SET `position_x`=-540.3802, `position_y`=2459.019, `position_z`=552.5091, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Dreadwing
SET @MOVERGUID := @CGUID+171;
SET @ENTRY := 121231;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 14.2682, 'Dreadwing - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -582.7344, 2487.0852, 560.9378, NULL, 0),
(@PATH, 1, -592.6389, 2495.132, 560.9378, NULL, 0),
(@PATH, 2, -603.4965, 2490.9426, 561.86945, NULL, 0),
(@PATH, 3, -603.5, 2479.1077, 560.9378, NULL, 0),
(@PATH, 4, -594.1719, 2472.4358, 560.0673, NULL, 0),
(@PATH, 5, -574.63196, 2458.3281, 559.0355, NULL, 0),
(@PATH, 6, -535.5903, 2444.4775, 552.5091, NULL, 0),
(@PATH, 7, -500.467, 2469.1128, 552.5091, NULL, 0),
(@PATH, 8, -485.09897, 2492.9878, 552.5091, NULL, 0),
(@PATH, 9, -488.50522, 2503.9253, 552.5091, NULL, 0),
(@PATH, 10, -501.56598, 2497.0642, 552.5091, NULL, 0),
(@PATH, 11, -511.58508, 2477.1963, 552.5091, NULL, 0),
(@PATH, 12, -540.3802, 2459.019, 552.5091, NULL, 0),
(@PATH, 13, -562.06946, 2473.5815, 552.5091, NULL, 0),
(@PATH, 14, -567.71875, 2477.3074, 556.53613, NULL, 0);

UPDATE `creature` SET `position_x`=-582.7344, `position_y`=2487.0852, `position_z`=560.9378, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Dreadwing
SET @MOVERGUID := @CGUID+172;
SET @ENTRY := 121231;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 14.6108, 'Dreadwing - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -540.3802, 2459.019, 552.5091, NULL, 0),
(@PATH, 1, -562.06946, 2473.5815, 552.5091, NULL, 0),
(@PATH, 2, -567.71875, 2477.3074, 556.53613, NULL, 0),
(@PATH, 3, -582.7344, 2487.0852, 560.9378, NULL, 0),
(@PATH, 4, -592.6389, 2495.132, 560.9378, NULL, 0),
(@PATH, 5, -603.4965, 2490.9426, 561.86945, NULL, 0),
(@PATH, 6, -603.5, 2479.1077, 560.9378, NULL, 0),
(@PATH, 7, -594.1719, 2472.4358, 560.0673, NULL, 0),
(@PATH, 8, -574.63196, 2458.3281, 559.0355, NULL, 0),
(@PATH, 9, -535.5903, 2444.4775, 552.5091, NULL, 0),
(@PATH, 10, -500.467, 2469.1128, 552.5091, NULL, 0),
(@PATH, 11, -485.09897, 2492.9878, 552.5091, NULL, 0),
(@PATH, 12, -488.50522, 2503.9253, 552.5091, NULL, 0),
(@PATH, 13, -501.56598, 2497.0642, 552.5091, NULL, 0),
(@PATH, 14, -511.58508, 2477.1963, 552.5091, NULL, 0);

UPDATE `creature` SET `position_x`=-540.3802, `position_y`=2459.019, `position_z`=552.5091, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Dreadwing
SET @MOVERGUID := @CGUID+173;
SET @ENTRY := 121231;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 14.5385, 'Dreadwing - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -511.58508, 2477.1963, 552.5091, NULL, 0),
(@PATH, 1, -540.3802, 2459.019, 552.5091, NULL, 0),
(@PATH, 2, -562.06946, 2473.5815, 552.5091, NULL, 0),
(@PATH, 3, -567.71875, 2477.3074, 556.53613, NULL, 0),
(@PATH, 4, -582.7344, 2487.0852, 560.9378, NULL, 0),
(@PATH, 5, -592.6389, 2495.132, 560.9378, NULL, 0),
(@PATH, 6, -603.4965, 2490.9426, 561.86945, NULL, 0),
(@PATH, 7, -603.5, 2479.1077, 560.9378, NULL, 0),
(@PATH, 8, -594.1719, 2472.4358, 560.0673, NULL, 0),
(@PATH, 9, -574.63196, 2458.3281, 559.0355, NULL, 0),
(@PATH, 10, -535.5903, 2444.4775, 552.5091, NULL, 0),
(@PATH, 11, -500.467, 2469.1128, 552.5091, NULL, 0),
(@PATH, 12, -485.09897, 2492.9878, 552.5091, NULL, 0),
(@PATH, 13, -488.50522, 2503.9253, 552.5091, NULL, 0),
(@PATH, 14, -501.56598, 2497.0642, 552.5091, NULL, 0);

UPDATE `creature` SET `position_x`=-511.58508, `position_y`=2477.1963, `position_z`=552.5091, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Dreadwing
SET @MOVERGUID := @CGUID+174;
SET @ENTRY := 121231;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 14.0627, 'Dreadwing - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -574.63196, 2458.3281, 559.0355, NULL, 0),
(@PATH, 1, -535.5903, 2444.4775, 552.5091, NULL, 0),
(@PATH, 2, -500.467, 2469.1128, 552.5091, NULL, 0),
(@PATH, 3, -485.09897, 2492.9878, 552.5091, NULL, 0),
(@PATH, 4, -488.50522, 2503.9253, 552.5091, NULL, 0),
(@PATH, 5, -501.56598, 2497.0642, 552.5091, NULL, 0),
(@PATH, 6, -511.58508, 2477.1963, 552.5091, NULL, 0),
(@PATH, 7, -540.3802, 2459.019, 552.5091, NULL, 0),
(@PATH, 8, -562.06946, 2473.5815, 552.5091, NULL, 0),
(@PATH, 9, -567.71875, 2477.3074, 556.53613, NULL, 0),
(@PATH, 10, -582.7344, 2487.0852, 560.9378, NULL, 0),
(@PATH, 11, -592.6389, 2495.132, 560.9378, NULL, 0),
(@PATH, 12, -603.4965, 2490.9426, 561.86945, NULL, 0),
(@PATH, 13, -603.5, 2479.1077, 560.9378, NULL, 0),
(@PATH, 14, -594.1719, 2472.4358, 560.0673, NULL, 0);

UPDATE `creature` SET `position_x`=-574.63196, `position_y`=2458.3281, `position_z`=559.0355, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Dreadwing
SET @MOVERGUID := @CGUID+175;
SET @ENTRY := 121231;
SET @PATHOFFSET := 5;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 14.2732, 'Dreadwing - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -603.4965, 2490.9426, 561.86945, NULL, 0),
(@PATH, 1, -603.5, 2479.1077, 560.9378, NULL, 0),
(@PATH, 2, -594.1719, 2472.4358, 560.0673, NULL, 0),
(@PATH, 3, -574.63196, 2458.3281, 559.0355, NULL, 0),
(@PATH, 4, -535.5903, 2444.4775, 552.5091, NULL, 0),
(@PATH, 5, -500.467, 2469.1128, 552.5091, NULL, 0),
(@PATH, 6, -485.09897, 2492.9878, 552.5091, NULL, 0),
(@PATH, 7, -488.50522, 2503.9253, 552.5091, NULL, 0),
(@PATH, 8, -501.56598, 2497.0642, 552.5091, NULL, 0),
(@PATH, 9, -511.58508, 2477.1963, 552.5091, NULL, 0),
(@PATH, 10, -540.3802, 2459.019, 552.5091, NULL, 0),
(@PATH, 11, -562.06946, 2473.5815, 552.5091, NULL, 0),
(@PATH, 12, -567.71875, 2477.3074, 556.53613, NULL, 0),
(@PATH, 13, -582.7344, 2487.0852, 560.9378, NULL, 0),
(@PATH, 14, -592.6389, 2495.132, 560.9378, NULL, 0);

UPDATE `creature` SET `position_x`=-603.4965, `position_y`=2490.9426, `position_z`=561.86945, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Dreadwing
SET @MOVERGUID := @CGUID+176;
SET @ENTRY := 121231;
SET @PATHOFFSET := 6;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 14.4043, 'Dreadwing - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -592.6389, 2495.132, 560.9378, NULL, 0),
(@PATH, 1, -603.4965, 2490.9426, 561.86945, NULL, 0),
(@PATH, 2, -603.5, 2479.1077, 560.9378, NULL, 0),
(@PATH, 3, -594.1719, 2472.4358, 560.0673, NULL, 0),
(@PATH, 4, -574.63196, 2458.3281, 559.0355, NULL, 0),
(@PATH, 5, -535.5903, 2444.4775, 552.5091, NULL, 0),
(@PATH, 6, -500.467, 2469.1128, 552.5091, NULL, 0),
(@PATH, 7, -485.09897, 2492.9878, 552.5091, NULL, 0),
(@PATH, 8, -488.50522, 2503.9253, 552.5091, NULL, 0),
(@PATH, 9, -501.56598, 2497.0642, 552.5091, NULL, 0),
(@PATH, 10, -511.58508, 2477.1963, 552.5091, NULL, 0),
(@PATH, 11, -540.3802, 2459.019, 552.5091, NULL, 0),
(@PATH, 12, -562.06946, 2473.5815, 552.5091, NULL, 0),
(@PATH, 13, -567.71875, 2477.3074, 556.53613, NULL, 0),
(@PATH, 14, -582.7344, 2487.0852, 560.9378, NULL, 0);

UPDATE `creature` SET `position_x`=-592.6389, `position_y`=2495.132, `position_z`=560.9378, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Dreadwing
SET @MOVERGUID := @CGUID+177;
SET @ENTRY := 121231;
SET @PATHOFFSET := 7;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 15.1461, 'Dreadwing - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -485.09897, 2492.9878, 552.5091, NULL, 0),
(@PATH, 1, -488.50522, 2503.9253, 552.5091, NULL, 0),
(@PATH, 2, -501.56598, 2497.0642, 552.5091, NULL, 0),
(@PATH, 3, -511.58508, 2477.1963, 552.5091, NULL, 0),
(@PATH, 4, -540.3802, 2459.019, 552.5091, NULL, 0),
(@PATH, 5, -562.06946, 2473.5815, 552.5091, NULL, 0),
(@PATH, 6, -567.71875, 2477.3074, 556.53613, NULL, 0),
(@PATH, 7, -582.7344, 2487.0852, 560.9378, NULL, 0),
(@PATH, 8, -592.6389, 2495.132, 560.9378, NULL, 0),
(@PATH, 9, -603.4965, 2490.9426, 561.86945, NULL, 0),
(@PATH, 10, -603.5, 2479.1077, 560.9378, NULL, 0),
(@PATH, 11, -594.1719, 2472.4358, 560.0673, NULL, 0),
(@PATH, 12, -574.63196, 2458.3281, 559.0355, NULL, 0),
(@PATH, 13, -535.5903, 2444.4775, 552.5091, NULL, 0),
(@PATH, 14, -500.467, 2469.1128, 552.5091, NULL, 0);

UPDATE `creature` SET `position_x`=-485.09897, `position_y`=2492.9878, `position_z`=552.5091, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Dreadwing
SET @MOVERGUID := @CGUID+178;
SET @ENTRY := 121231;
SET @PATHOFFSET := 8;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 14.3846, 'Dreadwing - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -592.6389, 2495.132, 560.9378, NULL, 0),
(@PATH, 1, -603.4965, 2490.9426, 561.86945, NULL, 0),
(@PATH, 2, -603.5, 2479.1077, 560.9378, NULL, 0),
(@PATH, 3, -594.1719, 2472.4358, 560.0673, NULL, 0),
(@PATH, 4, -574.63196, 2458.3281, 559.0355, NULL, 0),
(@PATH, 5, -535.5903, 2444.4775, 552.5091, NULL, 0),
(@PATH, 6, -500.467, 2469.1128, 552.5091, NULL, 0),
(@PATH, 7, -485.09897, 2492.9878, 552.5091, NULL, 0),
(@PATH, 8, -488.50522, 2503.9253, 552.5091, NULL, 0),
(@PATH, 9, -501.56598, 2497.0642, 552.5091, NULL, 0),
(@PATH, 10, -511.58508, 2477.1963, 552.5091, NULL, 0),
(@PATH, 11, -540.3802, 2459.019, 552.5091, NULL, 0),
(@PATH, 12, -562.06946, 2473.5815, 552.5091, NULL, 0),
(@PATH, 13, -567.71875, 2477.3074, 556.53613, NULL, 0),
(@PATH, 14, -582.7344, 2487.0852, 560.9378, NULL, 0);

UPDATE `creature` SET `position_x`=-592.6389, `position_y`=2495.132, `position_z`=560.9378, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Dreadwing
SET @MOVERGUID := @CGUID+179;
SET @ENTRY := 121231;
SET @PATHOFFSET := 9;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 15.8513, 'Dreadwing - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -485.09897, 2492.9878, 552.5091, NULL, 0),
(@PATH, 1, -488.50522, 2503.9253, 552.5091, NULL, 0),
(@PATH, 2, -501.56598, 2497.0642, 552.5091, NULL, 0),
(@PATH, 3, -511.58508, 2477.1963, 552.5091, NULL, 0),
(@PATH, 4, -540.3802, 2459.019, 552.5091, NULL, 0),
(@PATH, 5, -562.06946, 2473.5815, 552.5091, NULL, 0),
(@PATH, 6, -567.71875, 2477.3074, 556.53613, NULL, 0),
(@PATH, 7, -582.7344, 2487.0852, 560.9378, NULL, 0),
(@PATH, 8, -592.6389, 2495.132, 560.9378, NULL, 0),
(@PATH, 9, -603.4965, 2490.9426, 561.86945, NULL, 0),
(@PATH, 10, -603.5, 2479.1077, 560.9378, NULL, 0),
(@PATH, 11, -594.1719, 2472.4358, 560.0673, NULL, 0),
(@PATH, 12, -574.63196, 2458.3281, 559.0355, NULL, 0),
(@PATH, 13, -535.5903, 2444.4775, 552.5091, NULL, 0),
(@PATH, 14, -500.467, 2469.1128, 552.5091, NULL, 0);

UPDATE `creature` SET `position_x`=-485.09897, `position_y`=2492.9878, `position_z`=552.5091, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Dreadwing
SET @MOVERGUID := @CGUID+180;
SET @ENTRY := 121231;
SET @PATHOFFSET := 10;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 14.3922, 'Dreadwing - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -450.75, 2566.264, 555.30554, NULL, 0),
(@PATH, 1, -457.27777, 2589.7205, 553.48236, NULL, 0),
(@PATH, 2, -489.19098, 2610.5852, 552.2612, NULL, 0),
(@PATH, 3, -499.80557, 2593.5574, 551.849, NULL, 0),
(@PATH, 4, -475.84027, 2565.29, 553.0702, NULL, 0),
(@PATH, 5, -456.15973, 2560.212, 554.8934, NULL, 0);

UPDATE `creature` SET `position_x`=-450.75, `position_y`=2566.264, `position_z`=555.30554, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Dreadwing
SET @MOVERGUID := @CGUID+181;
SET @ENTRY := 121231;
SET @PATHOFFSET := 11;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 16.3590, 'Dreadwing - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -502.48438, 2427.5852, 554.8934, NULL, 0),
(@PATH, 1, -497.37674, 2421.283, 555.30554, NULL, 0),
(@PATH, 2, -473.18228, 2423.9739, 553.48236, NULL, 0),
(@PATH, 3, -447.48438, 2452.1458, 552.2612, NULL, 0),
(@PATH, 4, -462.5955, 2465.3438, 551.849, NULL, 0),
(@PATH, 5, -494.32812, 2446.2065, 553.0702, NULL, 0);

UPDATE `creature` SET `position_x`=-502.48438, `position_y`=2427.5852, `position_z`=554.8934, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Dreadwing
SET @MOVERGUID := @CGUID+182;
SET @ENTRY := 121231;
SET @PATHOFFSET := 12;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 14.3055, 'Dreadwing - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -499.4514, 2555.1685, 560.9378, NULL, 0),
(@PATH, 1, -492.99307, 2544.1667, 560.9378, NULL, 0),
(@PATH, 2, -481.35764, 2544.2847, 561.86945, NULL, 0),
(@PATH, 3, -477.21527, 2555.3733, 560.9378, NULL, 0),
(@PATH, 4, -483.6111, 2564.8855, 560.0673, NULL, 0),
(@PATH, 5, -496.96875, 2584.9497, 559.0355, NULL, 0),
(@PATH, 6, -534.8125, 2606.9844, 552.5091, NULL, 0),
(@PATH, 7, -576.3333, 2596.2014, 552.5091, NULL, 0),
(@PATH, 8, -599.0903, 2579.2205, 552.5091, NULL, 0),
(@PATH, 9, -599.7292, 2567.7847, 552.5091, NULL, 0),
(@PATH, 10, -585.09375, 2569.632, 552.5091, NULL, 0),
(@PATH, 11, -568.75, 2584.736, 552.5091, NULL, 0),
(@PATH, 12, -535.42017, 2591.6807, 552.5091, NULL, 0),
(@PATH, 13, -516.2535, 2575.6746, 552.5091, NULL, 0),
(@PATH, 14, -510.09027, 2569.5852, 556.53613, NULL, 0);

UPDATE `creature` SET `position_x`=-499.4514, `position_y`=2555.1685, `position_z`=560.9378, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Dreadwing
SET @MOVERGUID := @CGUID+184;
SET @ENTRY := 121231;
SET @PATHOFFSET := 13;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 14.1533, 'Dreadwing - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -499.4514, 2555.1685, 560.9378, NULL, 0),
(@PATH, 1, -492.99307, 2544.1667, 560.9378, NULL, 0),
(@PATH, 2, -481.35764, 2544.2847, 561.86945, NULL, 0),
(@PATH, 3, -477.21527, 2555.3733, 560.9378, NULL, 0),
(@PATH, 4, -483.6111, 2564.8855, 560.0673, NULL, 0),
(@PATH, 5, -496.96875, 2584.9497, 559.0355, NULL, 0),
(@PATH, 6, -534.8125, 2606.9844, 552.5091, NULL, 0),
(@PATH, 7, -576.3333, 2596.2014, 552.5091, NULL, 0),
(@PATH, 8, -599.0903, 2579.2205, 552.5091, NULL, 0),
(@PATH, 9, -599.7292, 2567.7847, 552.5091, NULL, 0),
(@PATH, 10, -585.09375, 2569.632, 552.5091, NULL, 0),
(@PATH, 11, -568.75, 2584.736, 552.5091, NULL, 0),
(@PATH, 12, -535.42017, 2591.6807, 552.5091, NULL, 0),
(@PATH, 13, -516.2535, 2575.6746, 552.5091, NULL, 0),
(@PATH, 14, -510.09027, 2569.5852, 556.53613, NULL, 0);

UPDATE `creature` SET `position_x`=-499.4514, `position_y`=2555.1685, `position_z`=560.9378, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Dreadwing
SET @MOVERGUID := @CGUID+185;
SET @ENTRY := 121231;
SET @PATHOFFSET := 14;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 14.1527, 'Dreadwing - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -496.96875, 2584.9497, 559.0355, NULL, 0),
(@PATH, 1, -534.8125, 2606.9844, 552.5091, NULL, 0),
(@PATH, 2, -576.3333, 2596.2014, 552.5091, NULL, 0),
(@PATH, 3, -599.0903, 2579.2205, 552.5091, NULL, 0),
(@PATH, 4, -599.7292, 2567.7847, 552.5091, NULL, 0),
(@PATH, 5, -585.09375, 2569.632, 552.5091, NULL, 0),
(@PATH, 6, -568.75, 2584.736, 552.5091, NULL, 0),
(@PATH, 7, -535.42017, 2591.6807, 552.5091, NULL, 0),
(@PATH, 8, -516.2535, 2575.6746, 552.5091, NULL, 0),
(@PATH, 9, -510.09027, 2569.5852, 556.53613, NULL, 0),
(@PATH, 10, -499.4514, 2555.1685, 560.9378, NULL, 0),
(@PATH, 11, -492.99307, 2544.1667, 560.9378, NULL, 0),
(@PATH, 12, -481.35764, 2544.2847, 561.86945, NULL, 0),
(@PATH, 13, -477.21527, 2555.3733, 560.9378, NULL, 0),
(@PATH, 14, -483.6111, 2564.8855, 560.0673, NULL, 0);

UPDATE `creature` SET `position_x`=-496.96875, `position_y`=2584.9497, `position_z`=559.0355, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Dreadwing
SET @MOVERGUID := @CGUID+186;
SET @ENTRY := 121231;
SET @PATHOFFSET := 15;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 13.3056, 'Dreadwing - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -450.75, 2566.264, 555.30554, NULL, 0),
(@PATH, 1, -457.27777, 2589.7205, 553.48236, NULL, 0),
(@PATH, 2, -489.19098, 2610.5852, 552.2612, NULL, 0),
(@PATH, 3, -499.80557, 2593.5574, 551.849, NULL, 0),
(@PATH, 4, -475.84027, 2565.29, 553.0702, NULL, 0),
(@PATH, 5, -456.15973, 2560.212, 554.8934, NULL, 0);

UPDATE `creature` SET `position_x`=-450.75, `position_y`=2566.264, `position_z`=555.30554, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Dreadwing
SET @MOVERGUID := @CGUID+187;
SET @ENTRY := 121231;
SET @PATHOFFSET := 16;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 14.6592, 'Dreadwing - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -535.42017, 2591.6807, 552.5091, NULL, 0),
(@PATH, 1, -516.2535, 2575.6746, 552.5091, NULL, 0),
(@PATH, 2, -510.09027, 2569.5852, 556.53613, NULL, 0),
(@PATH, 3, -499.4514, 2555.1685, 560.9378, NULL, 0),
(@PATH, 4, -492.99307, 2544.1667, 560.9378, NULL, 0),
(@PATH, 5, -481.35764, 2544.2847, 561.86945, NULL, 0),
(@PATH, 6, -477.21527, 2555.3733, 560.9378, NULL, 0),
(@PATH, 7, -483.6111, 2564.8855, 560.0673, NULL, 0),
(@PATH, 8, -496.96875, 2584.9497, 559.0355, NULL, 0),
(@PATH, 9, -534.8125, 2606.9844, 552.5091, NULL, 0),
(@PATH, 10, -576.3333, 2596.2014, 552.5091, NULL, 0),
(@PATH, 11, -599.0903, 2579.2205, 552.5091, NULL, 0),
(@PATH, 12, -599.7292, 2567.7847, 552.5091, NULL, 0),
(@PATH, 13, -585.09375, 2569.632, 552.5091, NULL, 0),
(@PATH, 14, -568.75, 2584.736, 552.5091, NULL, 0);

UPDATE `creature` SET `position_x`=-535.42017, `position_y`=2591.6807, `position_z`=552.5091, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Dreadwing
SET @MOVERGUID := @CGUID+188;
SET @ENTRY := 121231;
SET @PATHOFFSET := 17;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 14.1624, 'Dreadwing - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -568.75, 2584.736, 552.5091, NULL, 0),
(@PATH, 1, -535.42017, 2591.6807, 552.5091, NULL, 0),
(@PATH, 2, -516.2535, 2575.6746, 552.5091, NULL, 0),
(@PATH, 3, -510.09027, 2569.5852, 556.53613, NULL, 0),
(@PATH, 4, -499.4514, 2555.1685, 560.9378, NULL, 0),
(@PATH, 5, -492.99307, 2544.1667, 560.9378, NULL, 0),
(@PATH, 6, -481.35764, 2544.2847, 561.86945, NULL, 0),
(@PATH, 7, -477.21527, 2555.3733, 560.9378, NULL, 0),
(@PATH, 8, -483.6111, 2564.8855, 560.0673, NULL, 0),
(@PATH, 9, -496.96875, 2584.9497, 559.0355, NULL, 0),
(@PATH, 10, -534.8125, 2606.9844, 552.5091, NULL, 0),
(@PATH, 11, -576.3333, 2596.2014, 552.5091, NULL, 0),
(@PATH, 12, -599.0903, 2579.2205, 552.5091, NULL, 0),
(@PATH, 13, -599.7292, 2567.7847, 552.5091, NULL, 0),
(@PATH, 14, -585.09375, 2569.632, 552.5091, NULL, 0);

UPDATE `creature` SET `position_x`=-568.75, `position_y`=2584.736, `position_z`=552.5091, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Dreadwing
SET @MOVERGUID := @CGUID+197;
SET @ENTRY := 121231;
SET @PATHOFFSET := 18;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 15.9319, 'Dreadwing - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -447.48438, 2452.1458, 552.2612, NULL, 0),
(@PATH, 1, -462.5955, 2465.3438, 551.849, NULL, 0),
(@PATH, 2, -494.32812, 2446.2065, 553.0702, NULL, 0),
(@PATH, 3, -502.48438, 2427.5852, 554.8934, NULL, 0),
(@PATH, 4, -497.37674, 2421.283, 555.30554, NULL, 0),
(@PATH, 5, -473.18228, 2423.9739, 553.48236, NULL, 0);

UPDATE `creature` SET `position_x`=-447.48438, `position_y`=2452.1458, `position_z`=552.2612, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Dreadwing
SET @MOVERGUID := @CGUID+198;
SET @ENTRY := 121231;
SET @PATHOFFSET := 19;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 13.2232, 'Dreadwing - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -484.7986, 2622.2812, 546.35223, NULL, 0),
(@PATH, 1, -482.9809, 2597.9966, 544.529, NULL, 0),
(@PATH, 2, -455.7604, 2571.304, 543.3079, NULL, 0),
(@PATH, 3, -442.01736, 2585.9253, 542.8958, NULL, 0),
(@PATH, 4, -460.0087, 2618.3315, 544.1169, NULL, 0),
(@PATH, 5, -478.31772, 2627.1511, 545.9401, NULL, 0);

UPDATE `creature` SET `position_x`=-484.7986, `position_y`=2622.2812, `position_z`=546.35223, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);
