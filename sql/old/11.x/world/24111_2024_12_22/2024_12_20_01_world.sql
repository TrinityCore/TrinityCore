SET @CGUID := 10004976;
SET @OGUID := 10001290;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+34;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 219014, 2552, 14771, 14771, '0', 0, 0, 0, 6, 2175.65283203125, -2316.32470703125, 198.6017913818359375, 3.883375167846679687, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58187), -- Oathsworn Peacekeeper (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+1, 219014, 2552, 14771, 14771, '0', 0, 0, 0, 2, 2181.427001953125, -2321.59375, 198.6017913818359375, 3.803325414657592773, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58187), -- Oathsworn Peacekeeper (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+2, 219014, 2552, 14771, 14771, '0', 0, 0, 0, 4, 2177.62158203125, -2265.632080078125, 198.7687530517578125, 2.342832326889038085, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58187), -- Oathsworn Peacekeeper (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+3, 219014, 2552, 14771, 14771, '0', 0, 0, 0, 3, 2170.54345703125, -2310.826416015625, 198.6017913818359375, 3.927297115325927734, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58187), -- Oathsworn Peacekeeper (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+4, 219014, 2552, 14771, 14771, '0', 0, 0, 0, 1, 2171.229248046875, -2272.005126953125, 198.7687530517578125, 2.22944498062133789, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58187), -- Oathsworn Peacekeeper (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+5, 219014, 2552, 14771, 14771, '0', 0, 0, 0, 7, 2183.854248046875, -2258.786376953125, 198.7687530517578125, 2.533100366592407226, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58187), -- Oathsworn Peacekeeper (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+6, 219169, 2552, 14771, 14771, '0', 0, 0, 0, 1, 2328.395751953125, -2282.420654296875, 181.5892791748046875, 4.72267770767211914, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58187), -- Oathsworn Peacekeeper (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+7, 219014, 2552, 14771, 14771, '0', 0, 0, 0, 1, 2330.208251953125, -2282.322265625, 181.5892791748046875, 4.779384613037109375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58187), -- Oathsworn Peacekeeper (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+8, 219014, 2552, 14771, 14771, '0', 0, 0, 0, 1, 2326.26220703125, -2282.568603515625, 181.5892791748046875, 4.766392230987548828, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58187), -- Oathsworn Peacekeeper (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+9, 214947, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2311.34033203125, -2295.248291015625, 184.8430633544921875, 0, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 58187), -- Eye of Topaz (Area: Dornogal - Difficulty: 0) CreateObject2
(@CGUID+10, 214947, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2283.322998046875, -2281.907958984375, 184.2237701416015625, 0, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 58187), -- Eye of Topaz (Area: Dornogal - Difficulty: 0) CreateObject2
(@CGUID+11, 219181, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2302.03466796875, -2241.1494140625, 181.6734161376953125, 1.47887730598449707, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 58187), -- Coreling (Area: Dornogal - Difficulty: 0) CreateObject2
(@CGUID+12, 214772, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2304.84716796875, -2230.34375, 206.048492431640625, 4.539597034454345703, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58187), -- Limestone Falcon (Area: Dornogal - Difficulty: 0) CreateObject2
(@CGUID+13, 214947, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2260.225830078125, -2264.114501953125, 194.0302581787109375, 0, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 58187), -- Eye of Topaz (Area: Dornogal - Difficulty: 0) CreateObject2
(@CGUID+14, 219181, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2234.61279296875, -2321.8525390625, 190.8435516357421875, 6.033689498901367187, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 58187), -- Coreling (Area: Dornogal - Difficulty: 0) CreateObject2
(@CGUID+15, 219334, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2284.76220703125, -2288.763916015625, 182.5074615478515625, 0.858511507511138916, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58187), -- Freysworn Arborist (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+16, 219191, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2323.767333984375, -2331.194580078125, 182.0562744140625, 3.925093412399291992, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58187), -- Earthen Geomender (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+17, 220674, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2287.21875, -2284.576416015625, 182.7853851318359375, 1.587289810180664062, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58187), -- [DNT] Watering Beam Stalker (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+18, 219193, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2336.625, -2329.57470703125, 181.672607421875, 5.509642601013183593, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58187), -- Wounded Oathsworn (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 369109 - Set Health (Random 40%-60%))
(@CGUID+19, 219193, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2331.335205078125, -2335.038330078125, 181.672607421875, 5.509642601013183593, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58187), -- Wounded Oathsworn (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 369109 - Set Health (Random 40%-60%))
(@CGUID+20, 219176, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2267.361083984375, -2290.142333984375, 181.6734161376953125, 3.265631675720214843, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58187), -- Freysworn Arborist (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+21, 220674, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2294.701416015625, -2299.939208984375, 182.9297943115234375, 1.844522953033447265, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58187), -- [DNT] Watering Beam Stalker (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+22, 219191, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2330.26904296875, -2328.24658203125, 181.672607421875, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58187), -- Earthen Geomender (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+23, 219194, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2332.30029296875, -2327.791748046875, 181.672607421875, 2.421919584274291992, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58187), -- Wounded Unbound (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 369109 - Set Health (Random 40%-60%))
(@CGUID+24, 219382, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2324.588623046875, -2235.69091796875, 181.673370361328125, 2.933559179306030273, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58187), -- Unbound Trader (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+25, 229927, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2322.026123046875, -2280.63720703125, 181.672607421875, 4.688057422637939453, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58187), -- Unbound Crafter (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+26, 219382, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2321.93408203125, -2282.427001953125, 181.672607421875, 0.094851680099964141, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58187), -- Unbound Trader (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+27, 229927, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2322.68408203125, -2235.0869140625, 182.492950439453125, 5.95221710205078125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58187), -- Unbound Crafter (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+28, 219166, 2552, 14771, 14771, '0', 0, 0, 0, 1, 2160.170166015625, -2321.507080078125, 190.450836181640625, 2.639991044998168945, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58187), -- Oathsworn Peacekeeper (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+29, 219166, 2552, 14771, 14771, '0', 0, 0, 0, 1, 2173.24658203125, -2335.03466796875, 190.4508209228515625, 2.940500497817993164, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58187), -- Oathsworn Peacekeeper (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+30, 219166, 2552, 14771, 14771, '0', 0, 0, 0, 1, 2200.345458984375, -2219.47216796875, 190.4507904052734375, 3.636798381805419921, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58187), -- Oathsworn Peacekeeper (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+31, 219166, 2552, 14771, 14771, '0', 0, 0, 0, 1, 2186.7119140625, -2348.329833984375, 190.4507904052734375, 2.674014091491699218, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58187), -- Oathsworn Peacekeeper (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+32, 219166, 2552, 14771, 14771, '0', 0, 0, 0, 1, 2160.060791015625, -2259.848876953125, 190.450836181640625, 3.372433662414550781, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58187), -- Oathsworn Peacekeeper (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+33, 219166, 2552, 14771, 14771, '0', 0, 0, 0, 1, 2173.40966796875, -2246.52783203125, 190.450836181640625, 3.628367424011230468, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58187), -- Oathsworn Peacekeeper (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+34, 219166, 2552, 14771, 14771, '0', 0, 0, 0, 1, 2186.59716796875, -2233.23779296875, 190.4508209228515625, 3.615820884704589843, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58187); -- Oathsworn Peacekeeper (Area: Dornogal - Difficulty: 0) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+34;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 1, 747, 0, 0, 0, 0, '18950'), -- Oathsworn Peacekeeper - 18950 - Invisibility and Stealth Detection
(@CGUID+1, 0, 0, 0, 0, 0, 1, 1, 747, 0, 0, 0, 0, '18950'), -- Oathsworn Peacekeeper - 18950 - Invisibility and Stealth Detection
(@CGUID+2, 0, 0, 0, 0, 0, 1, 1, 747, 0, 0, 0, 0, '18950'), -- Oathsworn Peacekeeper - 18950 - Invisibility and Stealth Detection
(@CGUID+3, 0, 0, 0, 0, 0, 1, 1, 747, 0, 0, 0, 0, '18950'), -- Oathsworn Peacekeeper - 18950 - Invisibility and Stealth Detection
(@CGUID+4, 0, 0, 0, 0, 0, 1, 1, 747, 0, 0, 0, 0, '18950'), -- Oathsworn Peacekeeper - 18950 - Invisibility and Stealth Detection
(@CGUID+5, 0, 0, 0, 0, 0, 1, 1, 747, 0, 0, 0, 0, '18950'), -- Oathsworn Peacekeeper - 18950 - Invisibility and Stealth Detection
(@CGUID+12, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Limestone Falcon
(@CGUID+18, 0, 0, 0, 0, 0, 1, 0, 0, 28519, 0, 0, 0, '369109'), -- Wounded Unbound - 369109 - Set Health (Random 40%-60%)
(@CGUID+19, 0, 0, 0, 0, 0, 1, 0, 0, 28519, 0, 0, 0, '369109'), -- Wounded Unbound - 369109 - Set Health (Random 40%-60%)
(@CGUID+20, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Freysworn Arborist
(@CGUID+22, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Earthen Geomender
(@CGUID+23, 0, 0, 0, 0, 0, 1, 0, 0, 28519, 0, 0, 0, '369109'), -- Wounded Unbound - 369109 - Set Health (Random 40%-60%)
(@CGUID+26, 0, 0, 0, 0, 0, 1, 0, 720, 0, 0, 0, 0, ''), -- Unbound Trader
(@CGUID+27, 0, 0, 0, 0, 0, 1, 0, 461, 0, 0, 0, 0, ''), -- Unbound Crafter
(@CGUID+28, 0, 118324, 0, 0, 0, 1, 1, 0, 0, 0, 0, 3, ''), -- Oathsworn Peacekeeper
(@CGUID+29, 0, 118332, 0, 0, 0, 1, 1, 0, 0, 0, 0, 3, ''), -- Oathsworn Peacekeeper
(@CGUID+30, 0, 118333, 0, 0, 0, 1, 1, 0, 0, 0, 0, 3, ''), -- Oathsworn Peacekeeper
(@CGUID+31, 0, 118333, 0, 0, 0, 1, 1, 0, 0, 0, 0, 3, ''), -- Oathsworn Peacekeeper
(@CGUID+32, 0, 118324, 0, 0, 0, 1, 1, 0, 0, 0, 0, 3, ''), -- Oathsworn Peacekeeper
(@CGUID+33, 0, 118333, 0, 0, 0, 1, 1, 0, 0, 0, 0, 3, ''), -- Oathsworn Peacekeeper
(@CGUID+34, 0, 118333, 0, 0, 0, 1, 1, 0, 0, 0, 0, 3, ''); -- Oathsworn Peacekeeper

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+37;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 420130, 2552, 14771, 14771, '0', 0, 0, 2174.710205078125, -2269.4150390625, 198.6854248046875, 5.422672748565673828, 0, 0, -0.41710376739501953, 0.908858835697174072, 120, 255, 0, 58187), -- Telescope (Area: Dornogal - Difficulty: 0) CreateObject1
(@OGUID+1, 459293, 2552, 14771, 14771, '0', 0, 0, 2227.334228515625, -2341.5869140625, 203.67999267578125, 5.497788906097412109, 0, 0, -0.38268280029296875, 0.923879802227020263, 120, 255, 1, 58187), -- Bench (Area: Dornogal - Difficulty: 0) CreateObject1
(@OGUID+2, 459294, 2552, 14771, 14771, '0', 0, 0, 2226.490478515625, -2340.6796875, 191.673919677734375, 5.497788906097412109, 0, 0, -0.38268280029296875, 0.923879802227020263, 120, 255, 1, 58187), -- Bench (Area: Dornogal - Difficulty: 0) CreateObject1
(@OGUID+3, 429058, 2552, 14771, 14771, '0', 0, 0, 2356.18408203125, -2235.736083984375, 181.88751220703125, 2.364918231964111328, 0, 0, 0.925539970397949218, 0.378649920225143432, 120, 255, 1, 58187), -- Bench (Area: Dornogal - Difficulty: 0) CreateObject1
(@OGUID+4, 429059, 2552, 14771, 14771, '0', 0, 0, 2346.755126953125, -2269.70654296875, 181.843231201171875, 3.141592741012573242, 0, 0, -1, 0, 120, 255, 1, 58187), -- Bench (Area: Dornogal - Difficulty: 0) CreateObject1
(@OGUID+5, 429069, 2552, 14771, 14771, '0', 0, 0, 2295.697998046875, -2243.494873046875, 181.590087890625, 5.497788906097412109, 0, 0, -0.38268280029296875, 0.923879802227020263, 120, 255, 1, 58187), -- Bench (Area: Dornogal - Difficulty: 0) CreateObject1
(@OGUID+6, 429070, 2552, 14771, 14771, '0', 0, 0, 2346.31591796875, -2342.0869140625, 181.685150146484375, 3.141592741012573242, 0, 0, -1, 0, 120, 255, 1, 58187), -- Bench (Area: Dornogal - Difficulty: 0) CreateObject1
(@OGUID+7, 437624, 2552, 14771, 14771, '0', 0, 0, 2389.38232421875, -2119.841796875, 182.6873016357421875, 5.470241069793701171, 0, 0, -0.3953714370727539, 0.918521344661712646, 120, 255, 1, 58187), -- Chair (Area: Dornogal - Difficulty: 0) CreateObject1
(@OGUID+8, 429071, 2552, 14771, 14771, '0', 0, 0, 2346.541748046875, -2322.125, 181.8417510986328125, 3.141592741012573242, 0, 0, -1, 0, 120, 255, 1, 58187), -- Bench (Area: Dornogal - Difficulty: 0) CreateObject1
(@OGUID+9, 437625, 2552, 14771, 14771, '0', 0, 0, 2392.59619140625, -2122.80908203125, 182.68505859375, 2.503940582275390625, 0, 0, 0.949604034423828125, 0.313452035188674926, 120, 255, 1, 58187), -- Chair (Area: Dornogal - Difficulty: 0) CreateObject1
(@OGUID+10, 452654, 2552, 14771, 14771, '0', 0, 0, 2340.294921875, -2182.7353515625, 182.9147491455078125, 3.926990509033203125, 0, 0, -0.92387962341308593, 0.382683247327804565, 120, 255, 1, 58187), -- Chair (Area: Dornogal - Difficulty: 0) CreateObject1
(@OGUID+11, 452655, 2552, 14771, 14771, '0', 0, 0, 2330.39111328125, -2186.34130859375, 182.975311279296875, 5.497788906097412109, 0, 0, -0.38268280029296875, 0.923879802227020263, 120, 255, 1, 58187), -- Chair (Area: Dornogal - Difficulty: 0) CreateObject1
(@OGUID+12, 459292, 2552, 14771, 14771, '0', 0, 0, 2224.80517578125, -2238.673095703125, 198.370147705078125, 3.926990509033203125, 0, 0, -0.92387962341308593, 0.382683247327804565, 120, 255, 1, 58187), -- Bench (Area: Dornogal - Difficulty: 0) CreateObject1
(@OGUID+13, 429078, 2552, 14771, 14771, '0', 0, 0, 2265.630126953125, -2282.600830078125, 181.58990478515625, 0, 0, 0, 0, 1, 120, 255, 1, 58187), -- Bench (Area: Dornogal - Difficulty: 0) CreateObject1
(@OGUID+14, 429079, 2552, 14771, 14771, '0', 0, 0, 2272.42529296875, -2269.9306640625, 181.58990478515625, 5.497788906097412109, 0, 0, -0.38268280029296875, 0.923879802227020263, 120, 255, 1, 58187), -- Bench (Area: Dornogal - Difficulty: 0) CreateObject1
(@OGUID+15, 437607, 2552, 14771, 14771, '0', 0, 0, 2382.95703125, -2109.544921875, 182.7224884033203125, 2.360307216644287109, 0, 0, 0.924664497375488281, 0.380782842636108398, 120, 255, 1, 58187), -- Chair (Area: Dornogal - Difficulty: 0) CreateObject1
(@OGUID+16, 459289, 2552, 14771, 14771, '0', 0, 0, 2240.903564453125, -2223.319091796875, 191.479156494140625, 3.926990509033203125, 0, 0, -0.92387962341308593, 0.382683247327804565, 120, 255, 1, 58187), -- Bench (Area: Dornogal - Difficulty: 0) CreateObject1
(@OGUID+17, 459290, 2552, 14771, 14771, '0', 0, 0, 2240.39404296875, -2223.679443359375, 203.4850616455078125, 3.926990509033203125, 0, 0, -0.92387962341308593, 0.382683247327804565, 120, 255, 1, 58187), -- Bench (Area: Dornogal - Difficulty: 0) CreateObject1
(@OGUID+18, 452656, 2552, 14771, 14771, '0', 0, 0, 2325.26611328125, -2197.21728515625, 182.9959259033203125, 0.776669740676879882, 0, 0, 0.378647804260253906, 0.925540864467620849, 120, 255, 1, 58187), -- Chair (Area: Dornogal - Difficulty: 0) CreateObject1
(@OGUID+19, 459291, 2552, 14771, 14771, '0', 0, 0, 2225.935546875, -2237.897705078125, 218.827850341796875, 3.926990509033203125, 0, 0, -0.92387962341308593, 0.382683247327804565, 120, 255, 1, 58187), -- Bench (Area: Dornogal - Difficulty: 0) CreateObject1
(@OGUID+20, 437612, 2552, 14771, 14771, '0', 0, 0, 2344.692138671875, -2114.8291015625, 183.4424285888671875, 0.194752290844917297, 0, 0, 0.097222328186035156, 0.995262682437896728, 120, 255, 1, 58187), -- Chair (Area: Dornogal - Difficulty: 0) CreateObject1
(@OGUID+21, 437613, 2552, 14771, 14771, '0', 0, 0, 2347.451904296875, -2111.546142578125, 183.44464111328125, 4.606964588165283203, 0, 0, -0.74338054656982421, 0.668868720531463623, 120, 255, 1, 58187), -- Chair (Area: Dornogal - Difficulty: 0) CreateObject1
(@OGUID+22, 437614, 2552, 14771, 14771, '0', 0, 0, 2355.802490234375, -2102.761962890625, 183.427978515625, 0.965783298015594482, 0, 0, 0.464342117309570312, 0.885655939579010009, 120, 255, 1, 58187), -- Chair (Area: Dornogal - Difficulty: 0) CreateObject1
(@OGUID+23, 437615, 2552, 14771, 14771, '0', 0, 0, 2358.701171875, -2100.40234375, 183.4517059326171875, 3.9946746826171875, 0, 0, -0.91040229797363281, 0.413724154233932495, 120, 255, 1, 58187), -- Chair (Area: Dornogal - Difficulty: 0) CreateObject1
(@OGUID+24, 429080, 2552, 14771, 14771, '0', 0, 0, 2265.467041015625, -2298.3525390625, 181.590087890625, 0, 0, 0, 0, 1, 120, 255, 1, 58187), -- Bench (Area: Dornogal - Difficulty: 0) CreateObject1
(@OGUID+25, 437608, 2552, 14771, 14771, '0', 0, 0, 2359.62451171875, -2114.0751953125, 182.707916259765625, 5.509572982788085937, 0, 0, -0.37723255157470703, 0.926118552684783935, 120, 255, 1, 58187), -- Chair (Area: Dornogal - Difficulty: 0) CreateObject1
(@OGUID+26, 429081, 2552, 14771, 14771, '0', 0, 0, 2271.803955078125, -2310.520751953125, 181.590087890625, 0.785396754741668701, 0, 0, 0.38268280029296875, 0.923879802227020263, 120, 255, 1, 58187), -- Bench (Area: Dornogal - Difficulty: 0) CreateObject1
(@OGUID+27, 437609, 2552, 14771, 14771, '0', 0, 0, 2357.760009765625, -2116.080322265625, 182.727630615234375, 5.509572982788085937, 0, 0, -0.37723255157470703, 0.926118552684783935, 120, 255, 1, 58187), -- Chair (Area: Dornogal - Difficulty: 0) CreateObject1
(@OGUID+28, 473902, 2552, 14771, 14771, '0', 0, 0, 3225.015625, -3080.736083984375, 360.747894287109375, 3.124123096466064453, 0, 0, 0.99996185302734375, 0.008734640665352344, 120, 255, 1, 58187), -- Zeppelin to Dornogal (Area: Dornogal - Difficulty: 0) CreateObject1
(@OGUID+29, 437610, 2552, 14771, 14771, '0', 0, 0, 2357.945068359375, -2119.17431640625, 182.7161712646484375, 0.991470277309417724, 0, 0, 0.475678443908691406, 0.879619240760803222, 120, 255, 1, 58187), -- Chair (Area: Dornogal - Difficulty: 0) CreateObject1
(@OGUID+30, 437611, 2552, 14771, 14771, '0', 0, 0, 2362.811767578125, -2114.3076171875, 182.7218017578125, 3.955691337585449218, 0, 0, -0.91829299926757812, 0.395901471376419067, 120, 255, 1, 58187), -- Chair (Area: Dornogal - Difficulty: 0) CreateObject1
(@OGUID+31, 437621, 2552, 14771, 14771, '0', 0, 0, 2379.95458984375, -2109.513916015625, 182.71356201171875, 0.774014115333557128, 0, 0, 0.37741851806640625, 0.926042795181274414, 120, 255, 1, 58187), -- Chair (Area: Dornogal - Difficulty: 0) CreateObject1
(@OGUID+32, 429060, 2552, 14771, 14771, '0', 0, 0, 2346.6806640625, -2256.348876953125, 181.8605499267578125, 3.141592741012573242, 0, 0, -1, 0, 120, 255, 1, 58187), -- Bench (Area: Dornogal - Difficulty: 0) CreateObject1
(@OGUID+33, 437622, 2552, 14771, 14771, '0', 0, 0, 2362.9716796875, -2146.466796875, 182.644317626953125, 5.902507305145263671, 0, 0, -0.18919181823730468, 0.981940150260925292, 120, 255, 1, 58187), -- Chair (Area: Dornogal - Difficulty: 0) CreateObject1
(@OGUID+34, 429061, 2552, 14771, 14771, '0', 0, 0, 2365.494873046875, -2226.154541015625, 181.9048004150390625, 2.364918231964111328, 0, 0, 0.925539970397949218, 0.378649920225143432, 120, 255, 1, 58187), -- Bench (Area: Dornogal - Difficulty: 0) CreateObject1
(@OGUID+35, 437623, 2552, 14771, 14771, '0', 0, 0, 2367.246826171875, -2147.952880859375, 182.6899566650390625, 2.994932174682617187, 0, 0, 0.997312545776367187, 0.073264561593532562, 120, 255, 1, 58187), -- Chair (Area: Dornogal - Difficulty: 0) CreateObject1
(@OGUID+36, 437616, 2552, 14771, 14771, '0', 0, 0, 2331.11767578125, -2114.398193359375, 183.42108154296875, 0.893776178359985351, 0, 0, 0.432161331176757812, 0.901796340942382812, 120, 255, 1, 58187), -- Chair (Area: Dornogal - Difficulty: 0) CreateObject1
(@OGUID+37, 437617, 2552, 14771, 14771, '0', 0, 0, 2334.153564453125, -2111.7294921875, 183.4152984619140625, 4.043092250823974609, 0, 0, -0.90012073516845703, 0.435640543699264526, 120, 255, 1, 58187); -- Chair (Area: Dornogal - Difficulty: 0) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+37;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+1, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0), -- Bench
(@OGUID+2, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0), -- Bench
(@OGUID+7, 0, 0, -0.38268330693244934, 0.923879623413085937, 0, 0), -- Chair
(@OGUID+9, 0, 0, -0.38268330693244934, 0.923879623413085937, 0, 0), -- Chair
(@OGUID+10, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Chair
(@OGUID+11, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Chair
(@OGUID+12, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Bench
(@OGUID+15, 0, 0, -0.38268330693244934, 0.923879623413085937, 0, 0), -- Chair
(@OGUID+16, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Bench
(@OGUID+17, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Bench
(@OGUID+18, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Bench
(@OGUID+19, 0, 0, -0.38268330693244934, 0.923879623413085937, 0, 0), -- Chair
(@OGUID+21, 0, 0, -0.38268330693244934, 0.923879623413085937, 0, 0), -- Chair
(@OGUID+22, 0, 0, -0.38268330693244934, 0.923879623413085937, 0, 0), -- Chair
(@OGUID+23, 0, 0, -0.38268330693244934, 0.923879623413085937, 0, 0), -- Chair
(@OGUID+25, 0, 0, -0.38268330693244934, 0.923879623413085937, 0, 0), -- Chair
(@OGUID+27, 0, 0, -0.38268330693244934, 0.923879623413085937, 0, 0), -- Chair
(@OGUID+29, 0, 0, -0.38268330693244934, 0.923879623413085937, 0, 0), -- Chair
(@OGUID+30, 0, 0, -0.38268330693244934, 0.923879623413085937, 0, 0), -- Chair
(@OGUID+31, 0, 0, -0.38268330693244934, 0.923879623413085937, 0, 0), -- Chair
(@OGUID+33, 0, 0, -0.38268330693244934, 0.923879623413085937, 0, 0), -- Chair
(@OGUID+35, 0, 0, -0.38268330693244934, 0.923879623413085937, 0, 0), -- Chair
(@OGUID+36, 0, 0, -0.38268330693244934, 0.923879623413085937, 0, 0), -- Chair
(@OGUID+37, 0, 0, -0.38268330693244934, 0.923879623413085937, 0, 0); -- Chair

UPDATE `gameobject` SET `PhaseId` = 23962 WHERE `guid` IN (10001239, 10001243, 10001228, 10001235, 10001230, 10001236);

-- Template
UPDATE `creature_template` SET `faction`=3407, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x80200 WHERE `entry`=219194; -- Wounded Unbound
UPDATE `creature_template` SET `faction`=3407, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=219176; -- Freysworn Arborist
UPDATE `creature_template` SET `faction`=3407, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x80200 WHERE `entry`=219193; -- Wounded Oathsworn
UPDATE `creature_template` SET `faction`=3407, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=219191; -- Earthen Geomender
UPDATE `creature_template` SET `faction`=3408, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800, `unit_flags3`=0x800000 WHERE `entry`=219169; -- Oathsworn Peacekeeper

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=58187 WHERE (`Entry`=219194 AND `DifficultyID`=0); -- 219194 (Wounded Unbound) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=58187 WHERE (`Entry`=219176 AND `DifficultyID`=0); -- 219176 (Freysworn Arborist) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=58187 WHERE (`Entry`=219193 AND `DifficultyID`=0); -- 219193 (Wounded Oathsworn) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=58187 WHERE (`Entry`=219191 AND `DifficultyID`=0); -- 219191 (Earthen Geomender) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2803, `StaticFlags1`=0x10000000, `VerifiedBuild`=58187 WHERE (`Entry`=219169 AND `DifficultyID`=0); -- 219169 (Oathsworn Peacekeeper) - CanSwim

-- Phase
DELETE FROM `phase_name` WHERE `ID` IN (22586, 23962);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(22586, 'Cosmetic - See Horde Banner at the Tranquill Strand'),
(23962, 'Cosmetic - See Alliance and Horde Transports at the Tranquill Strand');

-- Path for Oathsworn Peacekeeper
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+6;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+6, @CGUID+6, 0, 0, 515, 0, 0),
(@CGUID+6, @CGUID+7, 2, 70, 515, 8, 29),
(@CGUID+6, @CGUID+8, 2, 290, 515, 8, 29);

SET @MOVERGUID := @CGUID+6;
SET @ENTRY := 219169;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Oathsworn Peacekeeper - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2292.7935, -2324.8906, 181.59009, NULL, 0),
(@PATH, 1, 2272.7673, -2325.283, 190.85316, NULL, 0),
(@PATH, 2, 2267.217, -2325.092, 190.76022, NULL, 0),
(@PATH, 3, 2258.2778, -2322.0833, 190.76022, NULL, 0),
(@PATH, 4, 2241.3923, -2310.9045, 190.76022, NULL, 0),
(@PATH, 5, 2241.6963, -2295.7847, 190.76022, NULL, 0),
(@PATH, 6, 2239.2432, -2292.507, 190.76022, NULL, 0),
(@PATH, 7, 2233.9097, -2290.5852, 190.76022, NULL, 0),
(@PATH, 8, 2229.3699, -2290.3784, 190.76025, 3.1463, 16260),
(@PATH, 9, 2233.9097, -2290.5852, 190.76022, NULL, 0),
(@PATH, 10, 2239.2432, -2292.507, 190.76022, NULL, 0),
(@PATH, 11, 2241.6963, -2295.7847, 190.76022, NULL, 0),
(@PATH, 12, 2241.3923, -2310.9045, 190.76022, NULL, 0),
(@PATH, 13, 2258.2778, -2322.0833, 190.76022, NULL, 0),
(@PATH, 14, 2267.217, -2325.092, 190.76022, NULL, 0),
(@PATH, 15, 2272.7673, -2325.283, 190.85316, NULL, 0),
(@PATH, 16, 2292.7935, -2324.8906, 181.59009, NULL, 0),
(@PATH, 17, 2308.4565, -2319.0278, 181.58936, NULL, 0),
(@PATH, 18, 2320.6528, -2308.7727, 181.58931, NULL, 0),
(@PATH, 19, 2328.5696, -2299.309, 181.58926, NULL, 0),
(@PATH, 20, 2328.3838, -2281.2517, 181.58928, NULL, 0),
(@PATH, 21, 2325.1892, -2275.0227, 181.59003, NULL, 0),
(@PATH, 22, 2308.5364, -2256.7258, 181.59006, NULL, 0),
(@PATH, 23, 2293.0903, -2255.9565, 181.59009, NULL, 0),
(@PATH, 24, 2272.5955, -2256.0227, 190.94844, NULL, 0),
(@PATH, 25, 2258.0017, -2255.9062, 190.76022, NULL, 0),
(@PATH, 26, 2243.1702, -2270.4497, 190.76022, NULL, 0),
(@PATH, 27, 2241.7153, -2288.0034, 190.76022, NULL, 0),
(@PATH, 28, 2239.3298, -2290.9167, 190.76022, NULL, 0),
(@PATH, 29, 2229.323, -2290.337, 190.76025, 3.1463, 15345),
(@PATH, 30, 2239.3298, -2290.9167, 190.76022, NULL, 0),
(@PATH, 31, 2241.7153, -2288.0034, 190.76022, NULL, 0),
(@PATH, 32, 2243.1702, -2270.4497, 190.76022, NULL, 0),
(@PATH, 33, 2258.0017, -2255.9062, 190.76022, NULL, 0),
(@PATH, 34, 2272.5955, -2256.0227, 190.94844, NULL, 0),
(@PATH, 35, 2293.0903, -2255.9565, 181.59009, NULL, 0),
(@PATH, 36, 2308.5364, -2256.7258, 181.59006, NULL, 0),
(@PATH, 37, 2325.1892, -2275.0227, 181.59003, NULL, 0),
(@PATH, 38, 2328.3838, -2281.2517, 181.58928, NULL, 0),
(@PATH, 39, 2328.5696, -2299.309, 181.58926, NULL, 0),
(@PATH, 40, 2320.6528, -2308.7727, 181.58931, NULL, 0),
(@PATH, 41, 2308.4565, -2319.0278, 181.58936, NULL, 0);

UPDATE `creature` SET `position_x`=2292.7935, `position_y`=-2324.8906, `position_z`=181.59009, `orientation`=0 WHERE `guid` IN (@CGUID+8, @CGUID+7); 
UPDATE `creature` SET `position_x`=2292.7935, `position_y`=-2324.8906, `position_z`=181.59009, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 121156, 1, '18950');

-- Path for Earthen Geomender
SET @MOVERGUID := @CGUID+16;
SET @ENTRY := 219191;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Earthen Geomender - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2331.514, -2323.4775, 182.05627, NULL, 8071),
(@PATH, 1, 2323.7673, -2331.1946, 182.05627, NULL, 9830);

UPDATE `creature` SET `position_x`=2331.514, `position_y`=-2323.4775, `position_z`=182.05627, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
