SET @CGUID := 7001780;
SET @OGUID := 7000384;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+24;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 130684, 1643, 8721, 9032, '0', 9105, 0, 0, 0, -70.9878463745117187, 2070.6025390625, 46.65625, 4.729244232177734375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037), -- Fallhaven Villager (Area: Fallhaven - Difficulty: 0) CreateObject1 (Auras: 258625 - Cursed)
(@CGUID+1, 124499, 1643, 8721, 9032, '0', 9105, 0, 0, 0, -91.3819427490234375, 2055.21875, 41.99387359619140625, 4.055193424224853515, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037), -- Fallhaven Villager (Area: Fallhaven - Difficulty: 0) CreateObject1 (Auras: 246932 - Cursed)
(@CGUID+2, 124497, 1643, 8721, 9032, '0', 9105, 0, 0, 0, -49.3524322509765625, 2053.84033203125, 47.0108795166015625, 1.362218618392944335, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037), -- Fallhaven Villager (Area: Fallhaven - Difficulty: 0) CreateObject1 (Auras: 246908 - Cursed)
(@CGUID+3, 124420, 1643, 8721, 9032, '0', 9105, 0, 0, 0, -108.262153625488281, 2130.30908203125, 48.94041824340820312, 2.395430326461791992, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037), -- Felix Odell (Area: Fallhaven - Difficulty: 0) CreateObject1 (Auras: 247182 - Cursed, 247185 - Hold Utensils)
(@CGUID+4, 130684, 1643, 8721, 9032, '0', 9105, 0, 0, 1, -94.204864501953125, 2054.225830078125, 41.6838836669921875, 4.344016075134277343, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037), -- Fallhaven Villager (Area: Fallhaven - Difficulty: 0) CreateObject1 (Auras: 258625 - Cursed)
(@CGUID+5, 128467, 1643, 8721, 9032, '0', 9105, 0, 0, 0, -66.21875, 2116.100830078125, 46.27579498291015625, 3.110892772674560546, 120, 0, 0, 0, 0, NULL, NULL, NULL, 60037), -- Elijah Eggleton (Area: Fallhaven - Difficulty: 0) CreateObject1 (Auras: 246908 - Cursed, 254930 - Cursed Sausage Vendor)
(@CGUID+6, 124426, 1643, 8721, 9032, '0', 9105, 0, 0, 1, -58.2864570617675781, 2112.345458984375, 46.4765625, 1.580127477645874023, 120, 0, 0, 0, 0, NULL, NULL, NULL, 60037), -- Marjorie Foster (Area: Fallhaven - Difficulty: 0) CreateObject1 (Auras: 246932 - Cursed)
(@CGUID+7, 130374, 1643, 8721, 9032, '0', 9105, 0, 0, 0, -55.5225715637207031, 2127.15625, 47.61580657958984375, 0.135420143604278564, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037), -- Dinah Wellard (Area: Fallhaven - Difficulty: 0) CreateObject1 (Auras: 246932 - Cursed)
(@CGUID+8, 124499, 1643, 8721, 9032, '0', 9105, 0, 0, 0, -49.3489570617675781, 2055.833251953125, 46.96355056762695312, 4.584517955780029296, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037), -- Fallhaven Villager (Area: Fallhaven - Difficulty: 0) CreateObject1 (Auras: 246932 - Cursed)
(@CGUID+9, 124497, 1643, 8721, 9032, '0', 9105, 0, 0, 2, -96.9878463745117187, 2042.9444580078125, 39.66287612915039062, 4.344016075134277343, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037), -- Fallhaven Villager (Area: Fallhaven - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+10, 124497, 1643, 8721, 9032, '0', 9105, 0, 0, 1, -106.083343505859375, 2035.4947509765625, 37.49729537963867187, 1.095583438873291015, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037), -- Fallhaven Villager (Area: Fallhaven - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+11, 144164, 1643, 8721, 9032, '0', 9105, 0, 0, 0, -92.564239501953125, 2151.451416015625, 46.11172103881835937, 5.020122528076171875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037), -- Fallhaven Villager (Area: Fallhaven - Difficulty: 0) CreateObject1 (Auras: 258625 - Cursed)
(@CGUID+12, 124310, 1643, 8721, 9032, '0', 9105, 0, 0, 0, -111.039993286132812, 2134.2734375, 48.78884506225585937, 5.419242382049560546, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037), -- Ava Odell (Area: Fallhaven - Difficulty: 0) CreateObject1 (Auras: 246932 - Cursed, 247184 - Hold Utensils)
(@CGUID+13, 144166, 1643, 8721, 9032, '0', 9105, 0, 0, 0, -72.0538177490234375, 2142.432373046875, 46.18108749389648437, 2.186774253845214843, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037), -- Fallhaven Villager (Area: Fallhaven - Difficulty: 0) CreateObject1 (Auras: 246908 - Cursed)
(@CGUID+14, 129957, 1643, 8721, 9032, '0', 9105, 0, 0, 0, -63.0416679382324218, 2144.26904296875, 46.29737091064453125, 3.72571110725402832, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037), -- Clarence Page (Area: Fallhaven - Difficulty: 0) CreateObject1 (Auras: 246908 - Cursed)
(@CGUID+15, 144165, 1643, 8721, 9032, '0', 9105, 0, 0, 0, -92.046875, 2149.54345703125, 46.06427001953125, 1.959236502647399902, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037), -- Fallhaven Villager (Area: Fallhaven - Difficulty: 0) CreateObject1 (Auras: 246932 - Cursed)
(@CGUID+16, 124416, 1643, 8721, 9032, '0', 9105, 0, 0, 0, -110.918716430664062, 2130.921630859375, 48.78884506225585937, 0.671958446502685546, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037), -- Tom Odell (Area: Fallhaven - Difficulty: 0) CreateObject1 (Auras: 246908 - Cursed, 247184 - Hold Utensils)
(@CGUID+17, 124306, 1643, 8721, 9032, '0', 9105, 0, 0, 1, -84.8663177490234375, 2251.345458984375, 46.54657745361328125, 2.70876932144165039, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037), -- Lawrence Levy (Area: Fallhaven - Difficulty: 0) CreateObject1 (Auras: 246908 - Cursed)
(@CGUID+18, 124423, 1643, 8721, 9032, '0', 9105, 0, 0, 0, -102.057289123535156, 1976.5416259765625, 33.44873809814453125, 1.647157073020935058, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037), -- Lena Shelvey (Area: Fallhaven - Difficulty: 0) CreateObject1 (Auras: 246932 - Cursed)
(@CGUID+19, 124418, 1643, 8721, 9032, '0', 9105, 0, 0, 0, -101.982643127441406, 1978.4166259765625, 33.495635986328125, 3.467626810073852539, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037), -- Griffith Shelvey (Area: Fallhaven - Difficulty: 0) CreateObject1 (Auras: 246908 - Cursed)
(@CGUID+20, 116633, 1643, 8721, 9032, '0', 0, 0, 0, 0, -74.2135391235351562, 2081.404541015625, 46.87125015258789062, 1.557237625122070312, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037), -- Effect (Area: Fallhaven - Difficulty: 0) CreateObject1
(@CGUID+21, 116633, 1643, 8721, 9032, '0', 0, 0, 0, 0, -76.7083358764648437, 2098.935791015625, 50.05485153198242187, 4.677677154541015625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037), -- Effect (Area: Fallhaven - Difficulty: 0) CreateObject1
(@CGUID+22, 116633, 1643, 8721, 9032, '0', 0, 0, 0, 0, -105.907989501953125, 1996.7396240234375, 34.00082778930664062, 1.557237625122070312, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037), -- Effect (Area: Fallhaven - Difficulty: 0) CreateObject1
(@CGUID+23, 69018, 1643, 8721, 9032, '0', 0, 0, 0, 0, 119.9253463745117187, 2388.35595703125, 51.72170639038085937, 5.307061195373535156, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037), -- Totally Generic Bunny (JSB) (Area: Fallhaven - Difficulty: 0) CreateObject1
(@CGUID+24, 116633, 1643, 8721, 9032, '0', 0, 0, 0, 0, -121.789932250976562, 2220.427001953125, 46.37607955932617187, 1.557237625122070312, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037); -- Effect (Area: Fallhaven - Difficulty: 0) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+24;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 1, 0, 13511, 0, 0, 0, '258625'), -- Fallhaven Villager - 258625 - Cursed
(@CGUID+1, 0, 0, 0, 0, 0, 1, 1, 0, 13514, 0, 0, 0, '246932'), -- Fallhaven Villager - 246932 - Cursed
(@CGUID+2, 0, 0, 0, 0, 0, 1, 1, 0, 13506, 0, 0, 0, '246908'), -- Fallhaven Villager - 246908 - Cursed
(@CGUID+3, 0, 0, 0, 0, 0, 1, 0, 0, 13490, 0, 0, 0, '247182 247185'), -- Felix Odell - 247182 - Cursed, 247185 - Hold Utensils
(@CGUID+4, 0, 0, 0, 0, 0, 1, 1, 0, 3449, 0, 0, 0, '258625'), -- Fallhaven Villager - 258625 - Cursed
(@CGUID+5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '246908 254930'), -- Elijah Eggleton - 246908 - Cursed, 254930 - Cursed Sausage Vendor
(@CGUID+6, 0, 0, 0, 0, 0, 1, 1, 0, 13495, 0, 0, 0, '246932'), -- Marjorie Foster - 246932 - Cursed
(@CGUID+7, 0, 0, 0, 0, 0, 1, 0, 0, 14407, 0, 0, 0, '246932'), -- Dinah Wellard - 246932 - Cursed
(@CGUID+8, 0, 0, 0, 0, 0, 1, 1, 0, 13506, 0, 0, 0, '246932'), -- Fallhaven Villager - 246932 - Cursed
(@CGUID+9, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474'), -- Fallhaven Villager - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune)
(@CGUID+10, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474'), -- Fallhaven Villager - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune)
(@CGUID+11, 0, 0, 0, 0, 0, 1, 1, 0, 13507, 0, 0, 0, '258625'), -- Fallhaven Villager - 258625 - Cursed
(@CGUID+12, 0, 0, 5, 0, 0, 1, 1, 0, 13491, 0, 0, 0, '246932 247184'), -- Ava Odell - 246932 - Cursed, 247184 - Hold Utensils
(@CGUID+13, 0, 0, 0, 0, 0, 1, 1, 0, 13511, 0, 0, 0, '246908'), -- Fallhaven Villager - 246908 - Cursed
(@CGUID+14, 0, 0, 0, 0, 0, 1, 0, 0, 13502, 0, 0, 0, '246908'), -- Clarence Page - 246908 - Cursed
(@CGUID+15, 0, 0, 0, 0, 0, 1, 1, 0, 13506, 0, 0, 0, '246932'), -- Fallhaven Villager - 246932 - Cursed
(@CGUID+16, 0, 0, 5, 0, 0, 1, 1, 0, 13491, 0, 0, 0, '246908 247184'), -- Tom Odell - 246908 - Cursed, 247184 - Hold Utensils
(@CGUID+17, 0, 0, 0, 0, 0, 1, 0, 0, 8181, 0, 0, 0, '246908'), -- Lawrence Levy - 246908 - Cursed
(@CGUID+18, 0, 0, 0, 0, 0, 1, 1, 0, 13494, 0, 0, 0, '246932'), -- Lena Shelvey - 246932 - Cursed
(@CGUID+19, 0, 0, 0, 0, 0, 1, 1, 0, 13515, 0, 0, 0, '246908'), -- Griffith Shelvey - 246908 - Cursed
(@CGUID+23, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 5, ''); -- Totally Generic Bunny (JSB)

UPDATE `creature` SET `StringId` = 'ChannelPerched' WHERE `guid` = 7001566;

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+45;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 278475, 1643, 8721, 9032, '0', 0, 0, -86.0989608764648437, 2083.2587890625, 48.88616561889648437, 6.216625690460205078, 0.251361370086669921, -0.21606922149658203, 0.025593757629394531, 0.94312065839767456, 120, 255, 1, 60037), -- Nail (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+1, 278524, 1643, 8721, 9032, '0', 0, 0, -51.71875, 2104.6337890625, 46.493438720703125, 3.115387916564941406, 0, 0, 0.999914169311523437, 0.013101960532367229, 120, 255, 1, 60037), -- Forge (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+2, 290419, 1643, 8721, 9032, '0', 0, 0, -74.796875, 2105.954833984375, 49.99402999877929687, 6.277255535125732421, 0.009271144866943359, -0.08669853210449218, -0.00212478637695312, 0.9961891770362854, 120, 255, 1, 60037), -- Wanted Poster (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+3, 272198, 1643, 8721, 9032, '0', 0, 0, -64.095489501953125, 2085.201416015625, 51.90529251098632812, 4.2960357666015625, 0, 0, -0.837982177734375, 0.545697629451751708, 120, 255, 1, 60037), -- Cursed Charm (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+4, 272176, 1643, 8721, 9032, '0', 0, 0, -108.90625, 2130.97216796875, 49.72929763793945312, 3.101470708847045898, 0, 0, 0.999798774719238281, 0.020059684291481971, 120, 255, 1, 60037), -- Food (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+5, 278523, 1643, 8721, 9032, '0', 0, 0, -58.4652786254882812, 2113.553955078125, 46.25413894653320312, 4.799654960632324218, 0, 0, -0.67559051513671875, 0.737277030944824218, 120, 255, 1, 60037), -- Anvil (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+6, 294469, 1643, 8721, 9032, '0', 0, 0, -108.102226257324218, 2130.078125, 48.78884506225585937, 2.26891183853149414, 0, 0, 0.906304359436035156, 0.422625601291656494, 120, 255, 1, 60037), -- Chair (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+7, 295087, 1643, 8721, 9032, '0', 0, 0, -45.1764183044433593, 2123.166748046875, 47.40594482421875, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 120, 255, 1, 60037), -- Chair (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+8, 295091, 1643, 8721, 9032, '0', 0, 0, -52.4599571228027343, 2121.99072265625, 47.40594482421875, 5.113832950592041015, 0, 0, -0.55192947387695312, 0.833890795707702636, 120, 255, 1, 60037), -- Chair (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+9, 295086, 1643, 8721, 9032, '0', 0, 0, -52.4860305786132812, 2129.850830078125, 47.47341156005859375, 5.375617504119873046, 0, 0, -0.4383697509765625, 0.898794710636138916, 120, 255, 1, 60037), -- Chair (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+10, 295090, 1643, 8721, 9032, '0', 0, 0, -50.5074653625488281, 2129.90283203125, 47.46191024780273437, 4.12772369384765625, 0, 0, -0.88088607788085937, 0.473328351974487304, 120, 255, 1, 60037), -- Chair (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+11, 295089, 1643, 8721, 9032, '0', 0, 0, -45.3489646911621093, 2126.13818359375, 54.0761566162109375, 2.56564497947692871, 0, 0, 0.958821296691894531, 0.284010052680969238, 120, 255, 1, 60037), -- Chair (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+12, 295088, 1643, 8721, 9032, '0', 0, 0, -45.1787185668945312, 2128.322021484375, 54.0761566162109375, 3.883373737335205078, 0, 0, -0.93200492858886718, 0.362445563077926635, 120, 255, 1, 60037), -- Chair (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+13, 278670, 1643, 8721, 9032, '0', 0, 0, -97.7777786254882812, 2113.9150390625, 51.86236953735351562, 6.195461273193359375, 0, 0, -0.04384803771972656, 0.999038219451904296, 120, 255, 1, 60037), -- Cursed Charm (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+14, 295095, 1643, 8721, 9032, '0', 0, 0, -45.2230720520019531, 2126.088134765625, 47.40594482421875, 4.729860305786132812, 0, 0, -0.70090293884277343, 0.713256657123565673, 120, 255, 1, 60037), -- Chair (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+15, 278848, 1643, 8721, 9032, '0', 0, 0, -60.2013893127441406, 2143.239501953125, 46.242706298828125, 3.727866649627685546, 0, 0, -0.95734214782714843, 0.288956791162490844, 120, 255, 1, 60037), -- Roost (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+16, 295094, 1643, 8721, 9032, '0', 0, 0, -48.3318939208984375, 2122.149658203125, 47.40594482421875, 4.729860305786132812, 0, 0, -0.70090293884277343, 0.713256657123565673, 120, 255, 1, 60037), -- Chair (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+17, 295093, 1643, 8721, 9032, '0', 0, 0, -49.7611923217773437, 2122.16455078125, 47.40594482421875, 4.729860305786132812, 0, 0, -0.70090293884277343, 0.713256657123565673, 120, 255, 1, 60037), -- Chair (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+18, 290453, 1643, 8721, 9032, '0', 0, 0, -110.100692749023437, 2130.447998046875, 48.83678436279296875, 4.759515285491943359, 0, 0, -0.69025039672851562, 0.723570585250854492, 120, 255, 1, 60037), -- Book (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+19, 290901, 1643, 8721, 9032, '0', 0, 0, -85.4010391235351562, 2139.310791015625, 46.09429168701171875, 6.265733242034912109, 0, 0, -0.00872611999511718, 0.999961912631988525, 120, 255, 1, 60037), -- Mailbox (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+20, 290413, 1643, 8721, 9032, '0', 0, 0, -55, 2127.21533203125, 47.66533660888671875, 3.147117137908935546, 0, 0, -0.99999618530273437, 0.002762135816738009, 120, 255, 1, 60037), -- Door (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+21, 295092, 1643, 8721, 9032, '0', 0, 0, -51.1103401184082031, 2122.16357421875, 47.40594482421875, 4.729860305786132812, 0, 0, -0.70090293884277343, 0.713256657123565673, 120, 255, 1, 60037), -- Chair (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+22, 272177, 1643, 8721, 9032, '0', 0, 0, -109.979156494140625, 2132.798583984375, 49.64319992065429687, 3.101470708847045898, 0, 0, 0.999798774719238281, 0.020059684291481971, 120, 255, 1, 60037), -- Food (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+23, 272176, 1643, 8721, 9032, '0', 0, 0, -110.541656494140625, 2132.88720703125, 49.71165084838867187, 5.448168754577636718, 0, 0, -0.40548419952392578, 0.914102077484130859, 120, 255, 1, 60037), -- Food (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+24, 277380, 1643, 8721, 9032, '0', 0, 0, -8.62326431274414062, 1986.7916259765625, 34.36499786376953125, 0, 0, 0, 0, 1, 120, 255, 1, 60037), -- Tainted Pig Feed (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+25, 294470, 1643, 8721, 9032, '0', 0, 0, -110.918716430664062, 2130.921630859375, 48.78884506225585937, 0.671958446502685546, 0, 0, 0.329693794250488281, 0.944087922573089599, 120, 255, 1, 60037), -- Chair (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+26, 325418, 1643, 8721, 9032, '0', 0, 0, -194.401046752929687, 2080.307373046875, 68.76320648193359375, 4.323687553405761718, 0, 0, -0.83035755157470703, 0.557230949401855468, 120, 255, 1, 60037), -- Boiling Cauldron (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+27, 278671, 1643, 8721, 9032, '0', 0, 0, 5.927083492279052734, 1997.8333740234375, 41.00786590576171875, 6.001637935638427734, 0, 0, -0.14030933380126953, 0.990107715129852294, 120, 255, 1, 60037), -- Cursed Charm (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+28, 277380, 1643, 8721, 9032, '0', 0, 0, -74.6527786254882812, 2003.37158203125, 33.501007080078125, 0, 0, 0, 0, 1, 120, 255, 1, 60037), -- Tainted Pig Feed (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+29, 278670, 1643, 8721, 9032, '0', 0, 0, -120.378471374511718, 2045.21875, 44.63655471801757812, 6.015980243682861328, 0, 0, -0.13320541381835937, 0.991088449954986572, 120, 255, 1, 60037), -- Cursed Charm (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+30, 294468, 1643, 8721, 9032, '0', 0, 0, -111.039993286132812, 2134.2734375, 48.78884506225585937, 5.419242382049560546, 0, 0, -0.41866207122802734, 0.90814208984375, 120, 255, 1, 60037), -- Chair (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+31, 278418, 1643, 8721, 9032, '0', 0, 0, -194.657989501953125, 2074.51220703125, 71.6263275146484375, 2.599187850952148437, 0, 0, 0.963449478149414062, 0.267890125513076782, 120, 255, 1, 60037), -- Mayor Striggs (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+32, 276234, 1643, 8721, 9032, '0', 0, 0, -162.340286254882812, 2032.232666015625, 32.91264724731445312, 2.337252140045166015, 0, 0, 0.920213699340820312, 0.391416370868682861, 120, 255, 1, 60037), -- Riverbud (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+33, 277380, 1643, 8721, 9032, '0', 0, 0, -75.5711822509765625, 1976.0555419921875, 33.23336029052734375, 0, 0, 0, 0, 1, 120, 255, 1, 60037), -- Tainted Pig Feed (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+34, 272198, 1643, 8721, 9032, '0', 0, 0, -18.2934036254882812, 2050.1494140625, 50.52170181274414062, 6.195461273193359375, 0, 0, -0.04384803771972656, 0.999038219451904296, 120, 255, 1, 60037), -- Cursed Charm (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+35, 278671, 1643, 8721, 9032, '0', 0, 0, -95.4114608764648437, 2196.470458984375, 50.22972488403320312, 4.150334358215332031, 0, 0, -0.87547874450683593, 0.483256608247756958, 120, 255, 1, 60037), -- Cursed Charm (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+36, 277380, 1643, 8721, 9032, '0', 0, 0, -106.388893127441406, 1981.2447509765625, 33.45779037475585937, 0, 0, 0, 0, 1, 120, 255, 1, 60037), -- Tainted Pig Feed (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+37, 277380, 1643, 8721, 9032, '0', 0, 0, -79.6336822509765625, 2003.80908203125, 33.49611282348632812, 0, 0, 0, 0, 1, 120, 255, 1, 60037), -- Tainted Pig Feed (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+38, 294467, 1643, 8721, 9032, '0', 0, 0, -104.323463439941406, 2138.934326171875, 48.788848876953125, 3.150327444076538085, 0, 0, -0.99999046325683593, 0.004367320332676172, 120, 255, 1, 60037), -- Chair (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+39, 277380, 1643, 8721, 9032, '0', 0, 0, -117.232643127441406, 1986.4617919921875, 33.42810821533203125, 0, 0, 0, 0, 1, 120, 255, 1, 60037), -- Tainted Pig Feed (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+40, 272178, 1643, 8721, 9032, '0', 0, 0, -109.628471374511718, 2131.201416015625, 49.68747711181640625, 3.101470708847045898, 0, 0, 0.999798774719238281, 0.020059684291481971, 120, 255, 1, 60037), -- Food (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+41, 272199, 1643, 8721, 9032, '0', 0, 0, -62.7083320617675781, 2144.401123046875, 46.21513748168945312, 0.450207471847534179, 0, 0, 0.223207473754882812, 0.974770963191986083, 120, 255, 1, 60037), -- Stool (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+42, 295781, 1643, 8721, 9032, '0', 0, 0, -245.761383056640625, 2084.287353515625, 62.45363616943359375, 2.652208328247070312, 0.000457763671875, 0.010522842407226562, 0.970152854919433593, 0.242265388369560241, 120, 255, 1, 60037), -- Stove (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+43, 271125, 1643, 8721, 9032, '0', 0, 0, -205.65625, 2107.182373046875, 62.21701431274414062, 3.626770496368408203, 0, 0, -0.9707193374633789, 0.240216508507728576, 120, 255, 1, 60037), -- Meat Pile (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+44, 277380, 1643, 8721, 9032, '0', 0, 0, -85.4947891235351562, 1947.7916259765625, 32.35203933715820312, 0, 0, 0, 0, 1, 120, 255, 1, 60037), -- Tainted Pig Feed (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+45, 278572, 1643, 8721, 9032, '0', 9105, 0, -69.7482681274414062, 2091.911376953125, 61.45096969604492187, 0, 0, 0, 0, 1, 120, 255, 1, 60037); -- Fog (Area: Fallhaven - Difficulty: 0) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+45;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+6, 0, 0, 0.999990463256835937, -0.00436332821846008, 0, 0), -- Chair
(@OGUID+7, 0, 0, 0.999961912631988525, -0.00872652977705001, 0, 0), -- Chair
(@OGUID+8, 0, 0, 0.999961912631988525, -0.00872652977705001, 0, 0), -- Chair
(@OGUID+9, 0, 0, 0.999961912631988525, -0.00872652977705001, 0, 0), -- Chair
(@OGUID+10, 0, 0, 0.999961912631988525, -0.00872652977705001, 0, 0), -- Chair
(@OGUID+11, 0, 0, 0.999961912631988525, -0.00872652977705001, 0, 0), -- Chair
(@OGUID+12, 0, 0, 0.999961912631988525, -0.00872652977705001, 0, 0), -- Chair
(@OGUID+14, 0, 0, 0.999961912631988525, -0.00872652977705001, 0, 0), -- Chair
(@OGUID+16, 0, 0, 0.999961912631988525, -0.00872652977705001, 0, 0), -- Chair
(@OGUID+17, 0, 0, 0.999961912631988525, -0.00872652977705001, 0, 0), -- Chair
(@OGUID+21, 0, 0, 0.999961912631988525, -0.00872652977705001, 0, 0), -- Chair
(@OGUID+25, 0, 0, 0.999990463256835937, -0.00436332821846008, 0, 0), -- Chair
(@OGUID+26, 0, 0, 0, 1, 11674, 0), -- Boiling Cauldron
(@OGUID+30, 0, 0, 0.999990463256835937, -0.00436332821846008, 0, 0), -- Chair
(@OGUID+38, 0, 0, 0.999990463256835937, -0.00436332821846008, 0, 0), -- Chair
(@OGUID+42, -0.0098505113273859, 0.003730420488864183, 0.073740787804126739, 0.997221827507019042, 0, 0); -- Stove

-- Template Addon
DELETE FROM `gameobject_template_addon` WHERE `entry` IN (278572 /*Fog*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(278572, 0, 0x2000, 0, 0); -- Fog

-- Template
UPDATE `creature_template` SET `flags_extra`=128 WHERE `entry` IN (116633, 69018);
UPDATE `gameobject_template` SET `Data8`=103828, `Data10`=30091, `VerifiedBuild`=60037 WHERE `entry`=278523; -- Anvil

-- Difficulty
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=60037 WHERE (`Entry`=124405 AND `DifficultyID`=0); -- 124405 (Pecking Raven) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000000, `VerifiedBuild`=60037 WHERE (`Entry`=69018 AND `DifficultyID`=0); -- 69018 (Totally Generic Bunny (JSB)) - Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=60037 WHERE (`Entry`=124416 AND `DifficultyID`=0); -- 124416 (Tom Odell) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60037 WHERE (`Entry`=144165 AND `DifficultyID`=0); -- 144165 (Fallhaven Villager) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=60037 WHERE (`Entry`=129957 AND `DifficultyID`=0); -- 129957 (Clarence Page) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60037 WHERE (`Entry`=144166 AND `DifficultyID`=0); -- 144166 (Fallhaven Villager) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=60037 WHERE (`Entry`=124310 AND `DifficultyID`=0); -- 124310 (Ava Odell) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60037 WHERE (`Entry`=130234 AND `DifficultyID`=0); -- 130234 (Falls Eel) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60037 WHERE (`Entry`=144164 AND `DifficultyID`=0); -- 144164 (Fallhaven Villager) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=60037 WHERE (`Entry`=124420 AND `DifficultyID`=0); -- 124420 (Felix Odell) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60037 WHERE (`Entry`=124497 AND `DifficultyID`=0); -- 124497 (Fallhaven Villager) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60037 WHERE (`Entry`=124499 AND `DifficultyID`=0); -- 124499 (Fallhaven Villager) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=60037 WHERE (`Entry`=151527 AND `DifficultyID`=0); -- 151527 (Tortollan Young) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60037 WHERE (`Entry`=130684 AND `DifficultyID`=0); -- 130684 (Fallhaven Villager) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=60037 WHERE (`Entry`=116633 AND `DifficultyID`=0); -- 116633 (Effect) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `StaticFlags3`=0x2000000, `VerifiedBuild`=60037 WHERE (`Entry`=124426 AND `DifficultyID`=0); -- 124426 (Marjorie Foster) - CanSwim - CannotTurn
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `StaticFlags3`=0x2000000, `VerifiedBuild`=60037 WHERE (`Entry`=128467 AND `DifficultyID`=0); -- 128467 (Elijah Eggleton) - CanSwim - CannotTurn
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60037 WHERE (`Entry`=130374 AND `DifficultyID`=0); -- 130374 (Dinah Wellard) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60037 WHERE (`Entry`=124418 AND `DifficultyID`=0); -- 124418 (Griffith Shelvey) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60037 WHERE (`Entry`=124423 AND `DifficultyID`=0); -- 124423 (Lena Shelvey) - CanSwim

-- Phasing
DELETE FROM `phase_name` WHERE `ID` = 9105;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(9105, 'Cosmetic - See cursed Fallhaven Villager');

DELETE FROM `phase_area` WHERE `PhaseId` = 9105;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(8721, 9105, 'See cursed Fallhaven Villager');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 9105 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 9105, 0, 0, 0, 47, 0, 47982, 2|64, 0, 1, 'Apply Phase 9105 if Quest 47982 is not complete | rewarded');

-- SpellClick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 124306;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(124306, 46598, 1, 0);

-- Vehicle
DELETE FROM `vehicle_template_accessory` WHERE (`entry`=124306 AND `seat_id` IN (2,1,0));
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(124306, 124405, 2, 0, 'Lawrence Levy - Pecking Raven', 8, 0), -- Lawrence Levy - Pecking Raven
(124306, 124405, 1, 0, 'Lawrence Levy - Pecking Raven', 8, 0), -- Lawrence Levy - Pecking Raven
(124306, 124405, 0, 0, 'Lawrence Levy - Pecking Raven', 8, 0); -- Lawrence Levy - Pecking Raven
