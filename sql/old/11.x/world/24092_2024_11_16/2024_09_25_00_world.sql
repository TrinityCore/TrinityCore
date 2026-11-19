SET @CGUID := 10002119;
SET @OGUID := 10000546;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+175;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 210109, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, 8.123264312744140625, 4.045138835906982421, 361.62188720703125, 0.304010480642318725, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Earth Infused Golem (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+1, 212453, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, 30.140625, 11.15277767181396484, 361.82861328125, 2.601182937622070312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Ghastly Voidsoul (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 462597 - [DNT] In RP Combat)
(@CGUID+2, 212764, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -28.3732643127441406, -50.3350715637207031, 363.147613525390625, 4.287942886352539062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Engine Speaker (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 462597 - [DNT] In RP Combat)
(@CGUID+3, 222923, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, 36.86632156372070312, -5.38541603088378906, 361.865325927734375, 4.959231853485107421, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Repurposed Loaderbot (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 462597 - [DNT] In RP Combat, 244972 - Set Health (Random 65%-85%))
(@CGUID+4, 210109, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, 8.118055343627929687, -4.21354150772094726, 361.62188720703125, 5.814573287963867187, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Earth Infused Golem (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+5, 210109, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, 33.54513931274414062, -10.3836803436279296, 361.98876953125, 0.365502864122390747, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Earth Infused Golem (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 462597 - [DNT] In RP Combat, 244972 - Set Health (Random 65%-85%), 18950 - Invisibility and Stealth Detection)
(@CGUID+6, 212389, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, 37.42361068725585937, -12.6423616409301757, 362.0186767578125, 2.601182937622070312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cursedheart Invader (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 462597 - [DNT] In RP Combat, 244972 - Set Health (Random 65%-85%))
(@CGUID+7, 212453, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, 29.94444465637207031, 17.046875, 361.82861328125, 4.030330181121826171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Ghastly Voidsoul (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 462597 - [DNT] In RP Combat)
(@CGUID+8, 210109, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, 26.27604103088378906, 13.68055534362792968, 361.82861328125, 5.771520614624023437, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Earth Infused Golem (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 462597 - [DNT] In RP Combat, 244972 - Set Health (Random 65%-85%), 18950 - Invisibility and Stealth Detection)
(@CGUID+9, 210108, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -36.5104179382324218, -0.0225694440305233, 361.82861328125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- E.D.N.A (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 451704 - Earthen Energy, 447230 - Skarden Spawn RP, 422356 - Bot AI Follow Advert)
(@CGUID+10, 210931, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -25.9895839691162109, -45.1822929382324218, 362.2083740234375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+11, 212453, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, 37.94097137451171875, -8.23958301544189453, 361.865325927734375, 3.603260755538940429, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Ghastly Voidsoul (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 462597 - [DNT] In RP Combat, 244972 - Set Health (Random 65%-85%))
(@CGUID+12, 212765, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -30.5086803436279296, -54.6753463745117187, 363.147613525390625, 1.153206229209899902, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Void Bound Despoiler (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 462597 - [DNT] In RP Combat, 18950 - Invisibility and Stealth Detection)
(@CGUID+13, 212764, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -25.6215286254882812, -51.9982643127441406, 363.147613525390625, 4.197084426879882812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Engine Speaker (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 462597 - [DNT] In RP Combat)
(@CGUID+14, 222923, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, 27.19444465637207031, 17.73611068725585937, 361.82861328125, 5.540773868560791015, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Repurposed Loaderbot (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 462597 - [DNT] In RP Combat, 244972 - Set Health (Random 65%-85%))
(@CGUID+15, 212405, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -22.265625, -88.9479141235351562, 359.583770751953125, 0, 7200, 0, 0, 0, NULL, 832, NULL, 1, 56647), -- Aspiring Forgehand (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 325988 - Cosmetic Feign Death)
(@CGUID+16, 212764, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -31.2534732818603515, -48.8177070617675781, 363.147613525390625, 4.344115734100341796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Engine Speaker (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 462597 - [DNT] In RP Combat)
(@CGUID+17, 212389, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, 74.05034637451171875, 6.159722328186035156, 358.068450927734375, 4.701115131378173828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cursedheart Invader (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 462597 - [DNT] In RP Combat, 244972 - Set Health (Random 65%-85%))
(@CGUID+18, 213338, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -27.0399303436279296, -95.236114501953125, 359.350616455078125, 5.197933197021484375, 7200, 0, 0, 0, NULL, 832, NULL, 1, 56647), -- Forgebound Mender (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 325988 - Cosmetic Feign Death)
(@CGUID+19, 212389, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, 77.61284637451171875, 3.208333253860473632, 358.104034423828125, 3.279689311981201171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cursedheart Invader (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 462597 - [DNT] In RP Combat, 244972 - Set Health (Random 65%-85%))
(@CGUID+20, 212405, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -27.5868053436279296, -103.951393127441406, 359.35125732421875, 1.251128554344177246, 7200, 0, 0, 0, NULL, 832, NULL, 1, 56647), -- Aspiring Forgehand (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 325988 - Cosmetic Feign Death)
(@CGUID+21, 222816, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, 96.470489501953125, -4.15277767181396484, 358.14990234375, 2.127249956130981445, 7200, 0, 0, 0, NULL, NULL, 2049, 2214600704, 56647), -- Volatile Skardyn (Area: The Stonevault - Difficulty: Normal) CreateObject1
(@CGUID+22, 212764, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -31.8559036254882812, -95.5, 359.350830078125, 5.0768585205078125, 7200, 0, 0, 0, NULL, 832, NULL, 1, 56647), -- Engine Speaker (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 325988 - Cosmetic Feign Death)
(@CGUID+23, 222815, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, 78.0381927490234375, -5.15972232818603515, 358.14990234375, 4.850755691528320312, 7200, 0, 0, 0, NULL, NULL, 2049, 2214600704, 56647), -- Cursedheart Invader (Area: The Stonevault - Difficulty: Normal) CreateObject1
(@CGUID+24, 221979, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -44.1927070617675781, -102.111106872558593, 359.151885986328125, 5.844392299652099609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Void Bound Howler (Area: The Stonevault - Difficulty: Normal) CreateObject1
(@CGUID+25, 213343, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -40.1701393127441406, -102.760406494140625, 359.351318359375, 1.074899792671203613, 7200, 0, 0, 0, NULL, 832, NULL, 1, 56647), -- Forge Loader (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 325988 - Cosmetic Feign Death)
(@CGUID+26, 221979, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -37.2152786254882812, -90.8958358764648437, 359.151885986328125, 0.08322165161371231, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Void Bound Howler (Area: The Stonevault - Difficulty: Normal) CreateObject1
(@CGUID+27, 214350, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -30.3940982818603515, -105.998268127441406, 359.151885986328125, 0.640008211135864257, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Turned Speaker (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 427300 - Pillaging)
(@CGUID+28, 212389, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, 75.1961822509765625, -1.75173616409301757, 358.068450927734375, 3.896122455596923828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cursedheart Invader (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 462597 - [DNT] In RP Combat, 244972 - Set Health (Random 65%-85%))
(@CGUID+29, 212405, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -26.0833339691162109, -107.395843505859375, 359.729888916015625, 0, 7200, 0, 0, 0, NULL, 832, NULL, 1, 56647), -- Aspiring Forgehand (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 325988 - Cosmetic Feign Death)
(@CGUID+30, 213338, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -29.2309036254882812, -109.458343505859375, 359.7313232421875, 2.01099562644958496, 7200, 0, 0, 0, NULL, 832, NULL, 1, 56647), -- Forgebound Mender (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 325988 - Cosmetic Feign Death)
(@CGUID+31, 210930, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -21.8420143127441406, 0.164930552244186401, 361.82861328125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 422354 - Bot AI Follow Advert)
(@CGUID+32, 212764, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -27.057291030883789, -99.8697891235351562, 359.3509521484375, 3.937535762786865234, 7200, 0, 0, 0, NULL, 832, NULL, 1, 56647), -- Engine Speaker (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 325988 - Cosmetic Feign Death)
(@CGUID+33, 222815, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, 70.26389312744140625, 1.279513955116271972, 358.14990234375, 3.36962890625, 7200, 0, 0, 0, NULL, NULL, 2049, 2214600704, 56647), -- Cursedheart Invader (Area: The Stonevault - Difficulty: Normal) CreateObject1
(@CGUID+34, 222923, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, 72.90103912353515625, -3.02777791023254394, 358.14990234375, 0.619694173336029052, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Repurposed Loaderbot (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 462597 - [DNT] In RP Combat, 244972 - Set Health (Random 65%-85%))
(@CGUID+35, 222923, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, 74.69965362548828125, 3.28819441795349121, 358.068450927734375, 6.212892532348632812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Repurposed Loaderbot (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 462597 - [DNT] In RP Combat, 244972 - Set Health (Random 65%-85%))
(@CGUID+36, 212403, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -29.4409732818603515, 49.61111068725585937, 362.592559814453125, 2.084402322769165039, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cursedheart Invader (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 462597 - [DNT] In RP Combat)
(@CGUID+37, 222817, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, 97.05034637451171875, 4.892361164093017578, 358.14990234375, 5.31201934814453125, 7200, 0, 0, 0, NULL, NULL, 2049, 2214600704, 56647), -- Earth Infused Golem (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 325988 - Cosmetic Feign Death)
(@CGUID+38, 214264, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -127.694442749023437, 7.029513835906982421, 362.054840087890625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cursedforge Honor Guard (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+39, 224962, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -128.90972900390625, 9.638889312744140625, 362.87469482421875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cursedforge Mender (Area: The Stonevault - Difficulty: Normal) CreateObject1
(@CGUID+40, 212405, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -32.0625, 49.1805572509765625, 362.5927734375, 0.191479146480560302, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Aspiring Forgehand (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 462597 - [DNT] In RP Combat, 423766 - Fracturing Blows)
(@CGUID+41, 210933, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -60.703125, 0.116319447755813598, 362.373870849609375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 423677 - Bot AI Follow Advert)
(@CGUID+42, 212764, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -29.7986106872558593, 52.3368072509765625, 362.5927734375, 5.612159252166748046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Engine Speaker (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 462597 - [DNT] In RP Combat)
(@CGUID+43, 222923, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, 99.13541412353515625, 6.864583492279052734, 358.068450927734375, 5.66515970230102539, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Repurposed Loaderbot (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 462597 - [DNT] In RP Combat, 244972 - Set Health (Random 65%-85%))
(@CGUID+44, 213954, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -131.63385009765625, -0.10494722425937652, 362.062225341796875, 0.000679781893268227, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Rock Smasher (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+45, 210932, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -25.6701393127441406, 44.53125, 362.043212890625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 422360 - Bot AI Follow Advert)
(@CGUID+46, 214264, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -127.482643127441406, -5.97916650772094726, 362.054840087890625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cursedforge Honor Guard (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+47, 224962, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -129.782989501953125, -9.05034732818603515, 362.054840087890625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cursedforge Mender (Area: The Stonevault - Difficulty: Normal) CreateObject1
(@CGUID+48, 212389, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, 99.38889312744140625, 2.911458730697631835, 358.068450927734375, 2.952651023864746093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cursedheart Invader (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 462597 - [DNT] In RP Combat, 244972 - Set Health (Random 65%-85%))
(@CGUID+49, 212405, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -26.0451393127441406, 53.80208206176757812, 362.5927734375, 4.337618350982666015, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Aspiring Forgehand (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 462597 - [DNT] In RP Combat, 423766 - Fracturing Blows)
(@CGUID+50, 212403, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -27.3576393127441406, 51.25694656372070312, 362.592559814453125, 2.487752437591552734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cursedheart Invader (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 462597 - [DNT] In RP Combat)
(@CGUID+51, 222923, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, 95.62326812744140625, 3.552083253860473632, 358.068450927734375, 6.06420755386352539, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Repurposed Loaderbot (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 462597 - [DNT] In RP Combat, 244972 - Set Health (Random 65%-85%))
(@CGUID+52, 222815, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, 103.9739608764648437, -0.984375, 358.14990234375, 1.84397280216217041, 7200, 0, 0, 0, NULL, NULL, 2049, 2214600704, 56647), -- Cursedheart Invader (Area: The Stonevault - Difficulty: Normal) CreateObject1
(@CGUID+53, 214066, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -161.006942749023437, 6.34375, 365.86529541015625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cursedforge Stoneshaper (Area: The Stonevault - Difficulty: Normal) CreateObject1
(@CGUID+54, 224962, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -160.309036254882812, 0.251736104488372802, 365.865478515625, 6.281378746032714843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cursedforge Mender (Area: The Stonevault - Difficulty: Normal) CreateObject1
(@CGUID+55, 214066, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -161.234375, -5.87152767181396484, 365.865325927734375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cursedforge Stoneshaper (Area: The Stonevault - Difficulty: Normal) CreateObject1
(@CGUID+56, 212453, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, 101.5989608764648437, 5.430556297302246093, 358.068450927734375, 3.225002765655517578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Ghastly Voidsoul (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 462597 - [DNT] In RP Combat, 244972 - Set Health (Random 65%-85%))
(@CGUID+57, 222815, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, 114.9947891235351562, 5.244791507720947265, 358.14990234375, 2.00709080696105957, 7200, 0, 0, 0, NULL, NULL, 2049, 2214600704, 56647), -- Cursedheart Invader (Area: The Stonevault - Difficulty: Normal) CreateObject1
(@CGUID+58, 210109, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, 120.083343505859375, -4.64409732818603515, 358.332427978515625, 6.113531112670898437, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Earth Infused Golem (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 462597 - [DNT] In RP Combat, 244972 - Set Health (Random 65%-85%), 18950 - Invisibility and Stealth Detection)
(@CGUID+59, 212389, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, 124.1510391235351562, -5.46180582046508789, 358.2974853515625, 3.315186023712158203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cursedheart Invader (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 462597 - [DNT] In RP Combat, 244972 - Set Health (Random 65%-85%))
(@CGUID+60, 212389, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, 120.626739501953125, -0.5972219705581665, 358.345855712890625, 4.817592144012451171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cursedheart Invader (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 462597 - [DNT] In RP Combat, 244972 - Set Health (Random 65%-85%))
(@CGUID+61, 222817, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, 125.220489501953125, 7.309027671813964843, 358.159637451171875, 0.73095780611038208, 7200, 0, 0, 0, NULL, NULL, 2049, 2214600704, 56647), -- Earth Infused Golem (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 325988 - Cosmetic Feign Death)
(@CGUID+62, 221979, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -47.5885429382324218, -117.234382629394531, 359.768829345703125, 1.699558019638061523, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Void Bound Howler (Area: The Stonevault - Difficulty: Normal) CreateObject1
(@CGUID+63, 214350, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -43.4299507141113281, -118.201370239257812, 359.71368408203125, 1.699558258056640625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Turned Speaker (Area: The Stonevault - Difficulty: Normal) CreateObject1
(@CGUID+64, 212400, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -51.5554275512695312, -117.748008728027343, 359.81695556640625, 1.699558258056640625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Void Touched Elemental (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 426862 - Void earth elemental Cosmetic, 422357 - Bot AI Follow Advert)
(@CGUID+65, 213343, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -33.9444465637207031, -128.182296752929687, 360.231292724609375, 0.833762228488922119, 7200, 0, 0, 0, NULL, 832, NULL, 1, 56647), -- Forge Loader (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 325988 - Cosmetic Feign Death)
(@CGUID+66, 212405, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -31.1597232818603515, -133.161453247070312, 360.231292724609375, 0.867291450500488281, 7200, 0, 0, 0, NULL, 832, NULL, 1, 56647), -- Aspiring Forgehand (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 325988 - Cosmetic Feign Death)
(@CGUID+67, 214066, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -199.998260498046875, 12.25520801544189453, 365.05841064453125, 5.923659801483154296, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cursedforge Stoneshaper (Area: The Stonevault - Difficulty: Normal) CreateObject1
(@CGUID+68, 214066, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -200.552078247070312, -11.8142366409301757, 365.05841064453125, 0.428877592086791992, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cursedforge Stoneshaper (Area: The Stonevault - Difficulty: Normal) CreateObject1
(@CGUID+69, 214066, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -202.048614501953125, -7.57638883590698242, 365.05841064453125, 0.428877592086791992, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cursedforge Stoneshaper (Area: The Stonevault - Difficulty: Normal) CreateObject1
(@CGUID+70, 212389, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -35.5729179382324218, -131.354171752929687, 359.561767578125, 1.311313867568969726, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cursedheart Invader (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 427300 - Pillaging)
(@CGUID+71, 214066, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -201.947921752929687, 8.208333015441894531, 365.05841064453125, 5.923659801483154296, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cursedforge Stoneshaper (Area: The Stonevault - Difficulty: Normal) CreateObject1
(@CGUID+72, 213954, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -207.251739501953125, -12.4513893127441406, 365.05841064453125, 0.428877592086791992, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Rock Smasher (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+73, 213954, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -207.12847900390625, 12.50868034362792968, 365.05841064453125, 5.923659801483154296, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Rock Smasher (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+74, 213338, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -30.2274303436279296, -136.489578247070312, 359.583740234375, 3.84118056297302246, 7200, 0, 0, 0, NULL, 832, NULL, 1, 56647), -- Forgebound Mender (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 325988 - Cosmetic Feign Death)
(@CGUID+75, 212764, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -28.3975696563720703, -139.751739501953125, 359.583740234375, 3.84118056297302246, 7200, 0, 0, 0, NULL, 832, NULL, 1, 56647), -- Engine Speaker (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 325988 - Cosmetic Feign Death)
(@CGUID+76, 212405, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -47.2690963745117187, -138.913192749023437, 360.231292724609375, 3.84118056297302246, 7200, 0, 0, 0, NULL, 832, NULL, 1, 56647), -- Aspiring Forgehand (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 325988 - Cosmetic Feign Death)
(@CGUID+77, 212405, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -45.1145820617675781, -142.328125, 360.231292724609375, 3.323546171188354492, 7200, 0, 0, 0, NULL, 832, NULL, 1, 56647), -- Aspiring Forgehand (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 325988 - Cosmetic Feign Death)
(@CGUID+78, 212389, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -30.671875, -141.251739501953125, 359.764404296875, 0.649735689163208007, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cursedheart Invader (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 427300 - Pillaging)
(@CGUID+79, 212405, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -26.9618053436279296, -143.303817749023437, 360.231292724609375, 5.299609184265136718, 7200, 0, 0, 0, NULL, 832, NULL, 1, 56647), -- Aspiring Forgehand (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 325988 - Cosmetic Feign Death)
(@CGUID+80, 222923, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -52.5104179382324218, 85.6788177490234375, 358.928680419921875, 5.251307487487792968, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Repurposed Loaderbot (Area: The Stonevault - Difficulty: Normal) CreateObject1
(@CGUID+81, 213119, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -248.510421752929687, -0.05034722387790679, 365.05841064453125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Void Speaker Eirich (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 423679 - Bot AI Follow Advert)
(@CGUID+82, 213338, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -52.7638893127441406, 91.6180572509765625, 358.928680419921875, 5.177597999572753906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Forgebound Mender (Area: The Stonevault - Difficulty: Normal) CreateObject1
(@CGUID+83, 212764, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -47.1631965637207031, 88.5086822509765625, 358.928680419921875, 5.24006509780883789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Engine Speaker (Area: The Stonevault - Difficulty: Normal) CreateObject1
(@CGUID+84, 212764, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -72.1371536254882812, 114.8298568725585937, 356.552276611328125, 5.184496402740478515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Engine Speaker (Area: The Stonevault - Difficulty: Normal) CreateObject1
(@CGUID+85, 212764, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -64.0902786254882812, 119.4722213745117187, 356.552215576171875, 5.184496402740478515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Engine Speaker (Area: The Stonevault - Difficulty: Normal) CreateObject1
(@CGUID+86, 213343, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -66.6701431274414062, 115.1423568725585937, 356.552398681640625, 5.184496402740478515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Forge Loader (Area: The Stonevault - Difficulty: Normal) CreateObject1 (Auras: 458490 - Override Mana Bar Color - Red)
(@CGUID+87, 212405, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -102.993057250976562, 121.2986068725585937, 356.55230712890625, 1.783839106559753417, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Aspiring Forgehand (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 423766 - Fracturing Blows)
(@CGUID+88, 222923, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -109.258682250976562, 134.4895782470703125, 356.55230712890625, 0.597899913787841796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Repurposed Loaderbot (Area: The Stonevault - Difficulty: Follower) CreateObject1
(@CGUID+89, 212764, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -107.454856872558593, 135.8819427490234375, 356.55230712890625, 3.99321603775024414, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Engine Speaker (Area: The Stonevault - Difficulty: Follower) CreateObject1
(@CGUID+90, 212405, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -104.178146362304687, 132.527496337890625, 357.50933837890625, 3.610523700714111328, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Aspiring Forgehand (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 423766 - Fracturing Blows) (possible waypoints or random movement)
(@CGUID+91, 212405, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -102.9080810546875, 130.003021240234375, 357.5096435546875, 3.611867666244506835, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Aspiring Forgehand (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 423766 - Fracturing Blows) (possible waypoints or random movement)
(@CGUID+92, 213839, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -41.8242263793945312, 74.21955108642578125, 358.93890380859375, 2.207305669784545898, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 428569 - Passive, 413569 - Bot AI Follow Advert)
(@CGUID+93, 213338, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -104.833343505859375, 123.6076431274414062, 356.55230712890625, 5.305357933044433593, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Forgebound Mender (Area: The Stonevault - Difficulty: Follower) CreateObject1
(@CGUID+94, 213338, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -101.430557250976562, 124.2326431274414062, 356.55224609375, 4.204864025115966796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Forgebound Mender (Area: The Stonevault - Difficulty: Follower) CreateObject1
(@CGUID+95, 212405, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -103.54180908203125, 134.4326934814453125, 357.50909423828125, 3.606025457382202148, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Aspiring Forgehand (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 423766 - Fracturing Blows) (possible waypoints or random movement)
(@CGUID+96, 212405, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -104.468856811523437, 130.798828125, 356.512725830078125, 3.614884376525878906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Aspiring Forgehand (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 423766 - Fracturing Blows) (possible waypoints or random movement)
(@CGUID+97, 212405, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -101.019477844238281, 129.380645751953125, 357.5098876953125, 3.611497402191162109, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Aspiring Forgehand (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 423766 - Fracturing Blows)
(@CGUID+98, 212405, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -110.689239501953125, 132.4027862548828125, 356.552337646484375, 1.103271961212158203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Aspiring Forgehand (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 423766 - Fracturing Blows)
(@CGUID+99, 212405, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -80.7222213745117187, 167.94097900390625, 354.759033203125, 2.181993961334228515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Aspiring Forgehand (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 423766 - Fracturing Blows)
(@CGUID+100, 212405, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -74.6145858764648437, 175.2586822509765625, 354.89166259765625, 0.373065203428268432, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Aspiring Forgehand (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 423766 - Fracturing Blows)
(@CGUID+101, 229507, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -82.5277786254882812, 174.0989532470703125, 355.941070556640625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Imbued Iron Bar (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 462456 - [DNT] Earthen Metal Bar Cosmetic Aura, 462496 - [DNT] Ready to Interact)
(@CGUID+102, 222149, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -118.765632629394531, 148.9965362548828125, 354.89166259765625, 2.046959638595581054, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Injured Earthen (Area: The Stonevault - Difficulty: Follower) CreateObject1
(@CGUID+103, 212405, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -87.4409713745117187, 170.15972900390625, 354.759033203125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Aspiring Forgehand (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 423766 - Fracturing Blows)
(@CGUID+104, 212764, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -83.1753463745117187, 172.576385498046875, 354.759033203125, 1.06533050537109375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Engine Speaker (Area: The Stonevault - Difficulty: Follower) CreateObject1
(@CGUID+105, 213338, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -117.291656494140625, 151.7864532470703125, 354.89166259765625, 5.717685699462890625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Forgebound Mender (Area: The Stonevault - Difficulty: Follower) CreateObject1
(@CGUID+106, 213338, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -111.727432250976562, 153.65625, 354.89166259765625, 3.892225980758666992, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Forgebound Mender (Area: The Stonevault - Difficulty: Follower) CreateObject1
(@CGUID+107, 222149, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -115.821182250976562, 150.829864501953125, 354.89166259765625, 2.046959638595581054, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Injured Earthen (Area: The Stonevault - Difficulty: Follower) CreateObject1
(@CGUID+108, 222149, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -112.949653625488281, 152.3090362548828125, 354.89166259765625, 2.046959638595581054, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Injured Earthen (Area: The Stonevault - Difficulty: Follower) CreateObject1
(@CGUID+109, 213338, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -123.317710876464843, 147.9756927490234375, 354.89166259765625, 6.016321659088134765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Forgebound Mender (Area: The Stonevault - Difficulty: Follower) CreateObject1
(@CGUID+110, 222149, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -121.659721374511718, 147.2604217529296875, 354.89166259765625, 2.046959638595581054, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Injured Earthen (Area: The Stonevault - Difficulty: Follower) CreateObject1
(@CGUID+111, 212405, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -86.8888931274414062, 176.359375, 354.759033203125, 4.080295085906982421, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Aspiring Forgehand (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 423766 - Fracturing Blows)
(@CGUID+112, 213343, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -151.717010498046875, 162.94097900390625, 356.244140625, 5.214436054229736328, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Forge Loader (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 458490 - Override Mana Bar Color - Red, 18950 - Invisibility and Stealth Detection)
(@CGUID+113, 212764, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -188.803817749023437, 122.1388931274414062, 354.89166259765625, 4.934685230255126953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Engine Speaker (Area: The Stonevault - Difficulty: Follower) CreateObject1
(@CGUID+114, 212764, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -124.501358032226562, 161.253082275390625, 354.859100341796875, 2.070465564727783203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Engine Speaker (Area: The Stonevault - Difficulty: Follower) CreateObject1
(@CGUID+115, 213338, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -186.149307250976562, 115.7135391235351562, 354.89166259765625, 1.296942353248596191, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Forgebound Mender (Area: The Stonevault - Difficulty: Follower) CreateObject1
(@CGUID+116, 212405, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -122.5263671875, 157.635040283203125, 354.859100341796875, 2.070466041564941406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Aspiring Forgehand (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 423766 - Fracturing Blows)
(@CGUID+117, 212405, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -126.120315551757812, 156.8398895263671875, 354.859100341796875, 2.070465564727783203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Aspiring Forgehand (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 423766 - Fracturing Blows)
(@CGUID+118, 213839, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -134.169525146484375, 117.3049468994140625, 356.468475341796875, 2.396193981170654296, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 428569 - Passive, 413569 - Bot AI Follow Advert)
(@CGUID+119, 212764, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -128.910751342773437, 158.8953094482421875, 354.859100341796875, 2.070464611053466796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Engine Speaker (Area: The Stonevault - Difficulty: Follower) CreateObject1
(@CGUID+120, 212405, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -179.090286254882812, 116.7118072509765625, 354.99169921875, 3.362549781799316406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Aspiring Forgehand (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 427300 - Pillaging, 423766 - Fracturing Blows)
(@CGUID+121, 213343, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -163.126739501953125, 155.3819427490234375, 356.244140625, 5.063612937927246093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Forge Loader (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 458490 - Override Mana Bar Color - Red, 18950 - Invisibility and Stealth Detection)
(@CGUID+122, 212405, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -119.914108276367187, 160.2285614013671875, 354.859100341796875, 2.070466279983520507, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Aspiring Forgehand (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 423766 - Fracturing Blows)
(@CGUID+123, 212764, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -187.588546752929687, 156.546875, 354.75897216796875, 3.126629829406738281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Engine Speaker (Area: The Stonevault - Difficulty: Follower) CreateObject1
(@CGUID+124, 213338, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -144.177078247070312, 191.9166717529296875, 354.759033203125, 3.068027496337890625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Forgebound Mender (Area: The Stonevault - Difficulty: Follower) CreateObject1
(@CGUID+125, 222149, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -145.256942749023437, 192.03125, 354.89166259765625, 5.825603961944580078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Injured Earthen (Area: The Stonevault - Difficulty: Follower) CreateObject1
(@CGUID+126, 212405, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -138.980911254882812, 197.0746612548828125, 354.759033203125, 1.611867547035217285, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Aspiring Forgehand (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 423766 - Fracturing Blows)
(@CGUID+127, 222149, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -140.001739501953125, 193.6059112548828125, 354.89166259765625, 5.706722736358642578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Injured Earthen (Area: The Stonevault - Difficulty: Follower) CreateObject1
(@CGUID+128, 212764, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -195.970489501953125, 152.7083282470703125, 354.75897216796875, 1.238586187362670898, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Engine Speaker (Area: The Stonevault - Difficulty: Follower) CreateObject1
(@CGUID+129, 212405, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -190.571182250976562, 158.842010498046875, 354.75897216796875, 3.174368619918823242, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Aspiring Forgehand (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 423766 - Fracturing Blows)
(@CGUID+130, 213343, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -188.95404052734375, 128.1555938720703125, 354.8909912109375, 5.950735092163085937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Forge Loader (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 458490 - Override Mana Bar Color - Red, 18950 - Invisibility and Stealth Detection)
(@CGUID+131, 212764, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -191.819442749023437, 155.1510467529296875, 354.75897216796875, 1.88775038719177246, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Engine Speaker (Area: The Stonevault - Difficulty: Follower) CreateObject1
(@CGUID+132, 210933, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -166.623260498046875, 114.2343826293945312, 354.957550048828125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 423677 - Bot AI Follow Advert)
(@CGUID+133, 213338, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -139.890625, 192.095489501953125, 354.759033203125, 1.515998005867004394, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Forgebound Mender (Area: The Stonevault - Difficulty: Follower) CreateObject1
(@CGUID+134, 213338, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -192.111114501953125, 116.552093505859375, 354.89166259765625, 1.158193826675415039, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Forgebound Mender (Area: The Stonevault - Difficulty: Follower) CreateObject1
(@CGUID+135, 212405, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -197.138885498046875, 156.7743072509765625, 354.75897216796875, 0.58676844835281372, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Aspiring Forgehand (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 423766 - Fracturing Blows)
(@CGUID+136, 212405, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -194.765625, 120.0451431274414062, 354.89166259765625, 5.4961700439453125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Aspiring Forgehand (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 423766 - Fracturing Blows)
(@CGUID+137, 212764, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -180.94097900390625, 208.0086822509765625, 354.91558837890625, 5.462304592132568359, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Engine Speaker (Area: The Stonevault - Difficulty: Follower) CreateObject1
(@CGUID+138, 212764, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -186.53125, 208.217010498046875, 354.91558837890625, 5.462297916412353515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Engine Speaker (Area: The Stonevault - Difficulty: Follower) CreateObject1
(@CGUID+139, 212764, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -188.963546752929687, 203.953125, 354.91558837890625, 5.462309837341308593, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Engine Speaker (Area: The Stonevault - Difficulty: Follower) CreateObject1
(@CGUID+140, 213216, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -241.411453247070312, 295.1875, 351.278106689453125, 5.22495889663696289, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Speaker Dorlita (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 422362 - Bot AI Follow Advert)
(@CGUID+141, 213338, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -192.887161254882812, 209.689239501953125, 354.91558837890625, 5.462304592132568359, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Forgebound Mender (Area: The Stonevault - Difficulty: Follower) CreateObject1
(@CGUID+142, 213338, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -184.727432250976562, 214.2447967529296875, 354.91558837890625, 5.462304592132568359, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Forgebound Mender (Area: The Stonevault - Difficulty: Follower) CreateObject1
(@CGUID+143, 213217, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -230.55035400390625, 301.423614501953125, 351.278106689453125, 5.320723533630371093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Speaker Brokk (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 422362 - Bot AI Follow Advert)
(@CGUID+144, 212765, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -7.03472232818603515, -188.324661254882812, 360.2745361328125, 2.082269668579101562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Void Bound Despoiler (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+145, 221979, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -8.9375, -192.776046752929687, 359.9654541015625, 2.082269668579101562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Void Bound Howler (Area: The Stonevault - Difficulty: Follower) CreateObject1
(@CGUID+146, 210158, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -39.1475715637207031, -147.449661254882812, 360.231292724609375, 1.403132796287536621, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Earthen Melee (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 325988 - Cosmetic Feign Death)
(@CGUID+147, 221979, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -2.27083325386047363, -188.61285400390625, 359.965667724609375, 2.082269668579101562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Void Bound Howler (Area: The Stonevault - Difficulty: Follower) CreateObject1
(@CGUID+148, 213839, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -28.8651618957519531, -152.195907592773437, 359.736328125, 5.275461196899414062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 428569 - Passive, 413569 - Bot AI Follow Advert)
(@CGUID+149, 212765, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, 24.10014915466308593, -214.22601318359375, 359.316070556640625, 3.679252386093139648, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Void Bound Despoiler (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+150, 212405, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -16.1788196563720703, -236.029510498046875, 360.59100341796875, 0.742919683456420898, 7200, 0, 0, 0, NULL, 832, NULL, 1, 56647), -- Aspiring Forgehand (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 325988 - Cosmetic Feign Death)
(@CGUID+151, 212453, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -24.5138893127441406, -222.564239501953125, 361.04229736328125, 1.915041446685791015, 7200, 0, 0, 0, NULL, 832, NULL, 1, 56647), -- Ghastly Voidsoul (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 325988 - Cosmetic Feign Death)
(@CGUID+152, 212453, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -26.734375, -222.90625, 361.94561767578125, 0.873152494430541992, 7200, 0, 0, 0, NULL, 832, NULL, 1, 56647), -- Ghastly Voidsoul (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 325988 - Cosmetic Feign Death)
(@CGUID+153, 212389, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, 25.06423568725585937, -203.229171752929687, 359.15185546875, 5.778912544250488281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cursedheart Invader (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 427300 - Pillaging)
(@CGUID+154, 212453, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -23.3194446563720703, -224.506942749023437, 360.45318603515625, 5.543067455291748046, 7200, 0, 0, 0, NULL, 832, NULL, 1, 56647), -- Ghastly Voidsoul (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 325988 - Cosmetic Feign Death)
(@CGUID+155, 212389, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -12.3142366409301757, -229.460067749023437, 359.15185546875, 4.639920711517333984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cursedheart Invader (Area: The Stonevault - Difficulty: Follower) CreateObject1
(@CGUID+156, 212400, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, 32.08333206176757812, -207.732635498046875, 359.15185546875, 3.372585535049438476, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Void Touched Elemental (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 426862 - Void earth elemental Cosmetic, 422357 - Bot AI Follow Advert)
(@CGUID+157, 212400, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -6.74131965637207031, -227.590286254882812, 359.15185546875, 3.779775619506835937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Void Touched Elemental (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 426862 - Void earth elemental Cosmetic, 422357 - Bot AI Follow Advert)
(@CGUID+158, 214350, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -9.57986164093017578, -235.585067749023437, 359.15185546875, 3.779775619506835937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Turned Speaker (Area: The Stonevault - Difficulty: Follower) CreateObject1
(@CGUID+159, 214350, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -16.6996536254882812, -230.72222900390625, 359.15185546875, 5.388166427612304687, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Turned Speaker (Area: The Stonevault - Difficulty: Follower) CreateObject1
(@CGUID+160, 212405, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -12.8454866409301757, -236.078125, 359.852508544921875, 0, 7200, 0, 0, 0, NULL, 832, NULL, 1, 56647), -- Aspiring Forgehand (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 325988 - Cosmetic Feign Death)
(@CGUID+161, 212405, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, 26.41666603088378906, -203.920135498046875, 359.15185546875, 1.706470012664794921, 7200, 0, 0, 0, NULL, 832, NULL, 1, 56647), -- Aspiring Forgehand (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 325988 - Cosmetic Feign Death)
(@CGUID+162, 212453, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -25.6232643127441406, -225.109375, 360.76788330078125, 4.86128091812133789, 7200, 0, 0, 0, NULL, 832, NULL, 1, 56647), -- Ghastly Voidsoul (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 325988 - Cosmetic Feign Death)
(@CGUID+163, 212405, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -14.5173616409301757, -233.557296752929687, 359.452423095703125, 4.672635555267333984, 7200, 0, 0, 0, NULL, 832, NULL, 1, 56647), -- Aspiring Forgehand (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 325988 - Cosmetic Feign Death)
(@CGUID+164, 212764, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, 26.5, -207.291671752929687, 359.151885986328125, 5.177672863006591796, 7200, 0, 0, 0, NULL, 832, NULL, 1, 56647), -- Engine Speaker (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 325988 - Cosmetic Feign Death)
(@CGUID+165, 212389, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, 25.18229103088378906, -208.28472900390625, 359.15185546875, 0.544412970542907714, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cursedheart Invader (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 427300 - Pillaging)
(@CGUID+166, 212400, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, 30.60763931274414062, -203.201385498046875, 359.15185546875, 3.297360420227050781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Void Touched Elemental (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 426862 - Void earth elemental Cosmetic, 422357 - Bot AI Follow Advert)
(@CGUID+167, 212299, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, -25.5763893127441406, -223.092010498046875, 361.18438720703125, 6.14813232421875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Reinforce Stalker (Area: The Stonevault - Difficulty: Follower) CreateObject1
(@CGUID+168, 212453, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, 40.71354293823242187, -216.444442749023437, 362.04644775390625, 3.380663633346557617, 7200, 0, 0, 0, NULL, 832, NULL, 1, 56647), -- Ghastly Voidsoul (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 325988 - Cosmetic Feign Death)
(@CGUID+169, 212299, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, 41.125, -216.453125, 360.681671142578125, 6.238059520721435546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Reinforce Stalker (Area: The Stonevault - Difficulty: Follower) CreateObject1
(@CGUID+170, 212405, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 1, -13.4375, -238.623260498046875, 360.619964599609375, 2.882988929748535156, 7200, 0, 0, 0, NULL, 832, NULL, 1, 56647), -- Aspiring Forgehand (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 325988 - Cosmetic Feign Death)
(@CGUID+171, 212453, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, 40.48784637451171875, -219.420135498046875, 360.95538330078125, 5.033022403717041015, 7200, 0, 0, 0, NULL, 832, NULL, 1, 56647), -- Ghastly Voidsoul (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 325988 - Cosmetic Feign Death)
(@CGUID+172, 210156, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, 27.78298568725585937, -249.493057250976562, 359.15185546875, 1.893433451652526855, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Skarmorak (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 429974 - Energy Bar, 422359 - Bot AI Follow Advert)
(@CGUID+173, 210932, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, 38.85590362548828125, -194.340286254882812, 359.41741943359375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 422360 - Bot AI Follow Advert)
(@CGUID+174, 212453, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, 38.09548568725585937, -214.28472900390625, 361.79644775390625, 3.125622272491455078, 7200, 0, 0, 0, NULL, 832, NULL, 1, 56647), -- Ghastly Voidsoul (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 325988 - Cosmetic Feign Death)
(@CGUID+175, 212453, 2652, 14883, 14883, '1,2,8,23', 0, 0, 0, 0, 38.32986068725585937, -217.230911254882812, 360.86773681640625, 4.029385566711425781, 7200, 0, 0, 0, NULL, 832, NULL, 1, 56647); -- Ghastly Voidsoul (Area: The Stonevault - Difficulty: Follower) CreateObject1 (Auras: 325988 - Cosmetic Feign Death)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+175;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+1, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, '462597'), -- Ghastly Voidsoul - 462597 - [DNT] In RP Combat
(@CGUID+2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '462597'), -- Engine Speaker - 462597 - [DNT] In RP Combat
(@CGUID+5, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '462597 244972 18950'), -- Earth Infused Golem - 462597 - [DNT] In RP Combat, 244972 - Set Health (Random 65%-85%), 18950 - Invisibility and Stealth Detection
(@CGUID+6, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '462597 244972'), -- Cursedheart Invader - 462597 - [DNT] In RP Combat, 244972 - Set Health (Random 65%-85%)
(@CGUID+7, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, '462597'), -- Ghastly Voidsoul - 462597 - [DNT] In RP Combat
(@CGUID+11, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '462597 244972'), -- Ghastly Voidsoul - 462597 - [DNT] In RP Combat, 244972 - Set Health (Random 65%-85%)
(@CGUID+13, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '462597'), -- Engine Speaker - 462597 - [DNT] In RP Combat
(@CGUID+15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '325988'), -- Aspiring Forgehand - 325988 - Cosmetic Feign Death
(@CGUID+16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '462597'), -- Engine Speaker - 462597 - [DNT] In RP Combat
(@CGUID+17, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '462597 244972'), -- Cursedheart Invader - 462597 - [DNT] In RP Combat, 244972 - Set Health (Random 65%-85%)
(@CGUID+18, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '325988'), -- Forgebound Mender - 325988 - Cosmetic Feign Death
(@CGUID+19, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '462597 244972'), -- Cursedheart Invader - 462597 - [DNT] In RP Combat, 244972 - Set Health (Random 65%-85%)
(@CGUID+20, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '325988'), -- Aspiring Forgehand - 325988 - Cosmetic Feign Death
(@CGUID+21, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- Volatile Skardyn
(@CGUID+22, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '325988'), -- Engine Speaker - 325988 - Cosmetic Feign Death
(@CGUID+23, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- Cursedheart Invader
(@CGUID+24, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, ''), -- Void Bound Howler
(@CGUID+25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '325988'), -- Forge Loader - 325988 - Cosmetic Feign Death
(@CGUID+26, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- Void Bound Howler
(@CGUID+27, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '427300'), -- Turned Speaker - 427300 - Pillaging
(@CGUID+28, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '462597 244972'), -- Cursedheart Invader - 462597 - [DNT] In RP Combat, 244972 - Set Health (Random 65%-85%)
(@CGUID+29, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '325988'), -- Aspiring Forgehand - 325988 - Cosmetic Feign Death
(@CGUID+30, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '325988'), -- Forgebound Mender - 325988 - Cosmetic Feign Death
(@CGUID+32, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '325988'), -- Engine Speaker - 325988 - Cosmetic Feign Death
(@CGUID+33, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- Cursedheart Invader
(@CGUID+36, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '462597'), -- Cursedheart Invader - 462597 - [DNT] In RP Combat
(@CGUID+37, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '325988'), -- Earth Infused Golem - 325988 - Cosmetic Feign Death
(@CGUID+38, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 3, '18950'), -- Cursedforge Honor Guard - 18950 - Invisibility and Stealth Detection
(@CGUID+39, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 3, ''), -- Cursedforge Mender
(@CGUID+40, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '462597 423766'), -- Aspiring Forgehand - 462597 - [DNT] In RP Combat, 423766 - Fracturing Blows
(@CGUID+42, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '462597'), -- Engine Speaker - 462597 - [DNT] In RP Combat
(@CGUID+46, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 3, '18950'), -- Cursedforge Honor Guard - 18950 - Invisibility and Stealth Detection
(@CGUID+47, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 3, ''), -- Cursedforge Mender
(@CGUID+48, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '462597 244972'), -- Cursedheart Invader - 462597 - [DNT] In RP Combat, 244972 - Set Health (Random 65%-85%)
(@CGUID+49, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '462597 423766'), -- Aspiring Forgehand - 462597 - [DNT] In RP Combat, 423766 - Fracturing Blows
(@CGUID+50, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '462597'), -- Cursedheart Invader - 462597 - [DNT] In RP Combat
(@CGUID+52, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- Cursedheart Invader
(@CGUID+53, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 3, ''), -- Cursedforge Stoneshaper
(@CGUID+54, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 3, ''), -- Cursedforge Mender
(@CGUID+55, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 3, ''), -- Cursedforge Stoneshaper
(@CGUID+56, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '462597 244972'), -- Ghastly Voidsoul - 462597 - [DNT] In RP Combat, 244972 - Set Health (Random 65%-85%)
(@CGUID+57, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- Cursedheart Invader
(@CGUID+58, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '462597 244972 18950'), -- Earth Infused Golem - 462597 - [DNT] In RP Combat, 244972 - Set Health (Random 65%-85%), 18950 - Invisibility and Stealth Detection
(@CGUID+59, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '462597 244972'), -- Cursedheart Invader - 462597 - [DNT] In RP Combat, 244972 - Set Health (Random 65%-85%)
(@CGUID+60, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '462597 244972'), -- Cursedheart Invader - 462597 - [DNT] In RP Combat, 244972 - Set Health (Random 65%-85%)
(@CGUID+61, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '325988'), -- Earth Infused Golem - 325988 - Cosmetic Feign Death
(@CGUID+64, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '426862 422357'), -- Void Touched Elemental - 426862 - Void earth elemental Cosmetic, 422357 - Bot AI Follow Advert
(@CGUID+65, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '325988'), -- Forge Loader - 325988 - Cosmetic Feign Death
(@CGUID+66, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '325988'), -- Aspiring Forgehand - 325988 - Cosmetic Feign Death
(@CGUID+67, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 3, ''), -- Cursedforge Stoneshaper
(@CGUID+68, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 3, ''), -- Cursedforge Stoneshaper
(@CGUID+69, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 3, ''), -- Cursedforge Stoneshaper
(@CGUID+70, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '427300'), -- Cursedheart Invader - 427300 - Pillaging
(@CGUID+71, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 3, ''), -- Cursedforge Stoneshaper
(@CGUID+72, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 3, '18950'), -- Rock Smasher - 18950 - Invisibility and Stealth Detection
(@CGUID+73, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 3, '18950'), -- Rock Smasher - 18950 - Invisibility and Stealth Detection
(@CGUID+74, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '325988'), -- Forgebound Mender - 325988 - Cosmetic Feign Death
(@CGUID+75, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '325988'), -- Engine Speaker - 325988 - Cosmetic Feign Death
(@CGUID+76, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '325988'), -- Aspiring Forgehand - 325988 - Cosmetic Feign Death
(@CGUID+77, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '325988'), -- Aspiring Forgehand - 325988 - Cosmetic Feign Death
(@CGUID+78, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '427300'), -- Cursedheart Invader - 427300 - Pillaging
(@CGUID+79, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '325988'), -- Aspiring Forgehand - 325988 - Cosmetic Feign Death
(@CGUID+80, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Repurposed Loaderbot
(@CGUID+81, 0, 0, 0, 0, 0, 1, 0, 474, 0, 0, 0, 3, '423679'), -- Void Speaker Eirich - 423679 - Bot AI Follow Advert
(@CGUID+82, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Forgebound Mender
(@CGUID+83, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Engine Speaker
(@CGUID+84, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Engine Speaker
(@CGUID+85, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Engine Speaker
(@CGUID+86, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '458490'), -- Forge Loader - 458490 - Override Mana Bar Color - Red
(@CGUID+87, 0, 0, 0, 0, 0, 1, 0, 605, 0, 0, 0, 0, '423766'), -- Aspiring Forgehand - 423766 - Fracturing Blows
(@CGUID+89, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- Engine Speaker
(@CGUID+100, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, '423766'), -- Aspiring Forgehand - 423766 - Fracturing Blows
(@CGUID+93, 0, 0, 0, 0, 0, 1, 0, 378, 0, 0, 0, 0, ''), -- Forgebound Mender
(@CGUID+94, 0, 0, 0, 0, 0, 1, 0, 378, 0, 0, 0, 0, ''), -- Forgebound Mender
(@CGUID+98, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, '423766'), -- Aspiring Forgehand - 423766 - Fracturing Blows
(@CGUID+104, 0, 0, 0, 0, 0, 1, 0, 601, 0, 0, 0, 0, ''), -- Engine Speaker
(@CGUID+105, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- Forgebound Mender
(@CGUID+106, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- Forgebound Mender
(@CGUID+109, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- Forgebound Mender
(@CGUID+111, 0, 0, 0, 0, 0, 1, 0, 720, 0, 0, 0, 0, '423766'), -- Aspiring Forgehand - 423766 - Fracturing Blows
(@CGUID+112, 0, 0, 0, 0, 0, 1, 0, 617, 0, 0, 0, 0, '458490 18950'), -- Forge Loader - 458490 - Override Mana Bar Color - Red, 18950 - Invisibility and Stealth Detection
(@CGUID+113, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, ''), -- Engine Speaker
(@CGUID+120, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '427300 423766'), -- Aspiring Forgehand - 427300 - Pillaging, 423766 - Fracturing Blows
(@CGUID+121, 0, 0, 0, 0, 0, 1, 0, 617, 0, 0, 0, 0, '458490 18950'), -- Forge Loader - 458490 - Override Mana Bar Color - Red, 18950 - Invisibility and Stealth Detection
(@CGUID+124, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- Forgebound Mender
(@CGUID+125, 0, 0, 0, 0, 0, 1, 0, 426, 0, 0, 0, 0, ''), -- Injured Earthen
(@CGUID+126, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, '423766'), -- Aspiring Forgehand - 423766 - Fracturing Blows
(@CGUID+127, 0, 0, 0, 0, 0, 1, 0, 426, 0, 0, 0, 0, ''), -- Injured Earthen
(@CGUID+133, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- Forgebound Mender
(@CGUID+137, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Engine Speaker
(@CGUID+138, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Engine Speaker
(@CGUID+139, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Engine Speaker
(@CGUID+141, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Forgebound Mender
(@CGUID+142, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Forgebound Mender
(@CGUID+144, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, '18950'), -- Void Bound Despoiler - 18950 - Invisibility and Stealth Detection
(@CGUID+145, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, ''), -- Void Bound Howler
(@CGUID+146, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '325988'), -- Earthen Melee - 325988 - Cosmetic Feign Death
(@CGUID+147, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, ''), -- Void Bound Howler
(@CGUID+150, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '325988'), -- Aspiring Forgehand - 325988 - Cosmetic Feign Death
(@CGUID+151, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '325988'), -- Ghastly Voidsoul - 325988 - Cosmetic Feign Death
(@CGUID+152, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '325988'), -- Ghastly Voidsoul - 325988 - Cosmetic Feign Death
(@CGUID+154, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '325988'), -- Ghastly Voidsoul - 325988 - Cosmetic Feign Death
(@CGUID+157, 0, 0, 0, 0, 0, 1, 0, 474, 0, 0, 0, 0, '426862 422357'), -- Void Touched Elemental - 426862 - Void earth elemental Cosmetic, 422357 - Bot AI Follow Advert
(@CGUID+160, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '325988'), -- Aspiring Forgehand - 325988 - Cosmetic Feign Death
(@CGUID+161, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '325988'), -- Aspiring Forgehand - 325988 - Cosmetic Feign Death
(@CGUID+162, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '325988'), -- Ghastly Voidsoul - 325988 - Cosmetic Feign Death
(@CGUID+163, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '325988'), -- Aspiring Forgehand - 325988 - Cosmetic Feign Death
(@CGUID+164, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '325988'), -- Engine Speaker - 325988 - Cosmetic Feign Death
(@CGUID+168, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '325988'), -- Ghastly Voidsoul - 325988 - Cosmetic Feign Death
(@CGUID+170, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '325988'), -- Aspiring Forgehand - 325988 - Cosmetic Feign Death
(@CGUID+171, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '325988'), -- Ghastly Voidsoul - 325988 - Cosmetic Feign Death
(@CGUID+174, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '325988'), -- Ghastly Voidsoul - 325988 - Cosmetic Feign Death
(@CGUID+175, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '325988'); -- Ghastly Voidsoul - 325988 - Cosmetic Feign Death

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+20;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 440236, 2652, 14883, 14883, '1,2,8,23', 0, 0, 56.4410247802734375, -0.08332844823598861, 361.960235595703125, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 0, 56647), -- 11DU_Foundry_Door02 (Area: The Stonevault - Difficulty: Normal) CreateObject1
(@OGUID+1, 440238, 2652, 14883, 14883, '1,2,8,23', 0, 0, -68.9727020263671875, -0.00000602978525421, 362.243072509765625, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 56647), -- 11DU_Foundry_Door03 (Area: The Stonevault - Difficulty: Normal) CreateObject1
(@OGUID+2, 440227, 2652, 14883, 14883, '1,2,8,23', 0, 0, 31.34294700622558593, -54.3612480163574218, 362.280242919921875, 2.094393253326416015, 0, 0, 0.866024971008300781, 0.50000077486038208, 7200, 255, 1, 56647), -- 11EA_Earthen_Navigation_SmallMinecart03 (Area: The Stonevault - Difficulty: Normal) CreateObject1
(@OGUID+3, 433057, 2652, 14883, 14883, '1,2,8,23', 0, 0, 27.60407638549804687, 47.8278045654296875, 361.680816650390625, 1.047197580337524414, 0, 0, 0.5, 0.866025388240814208, 7200, 255, 1, 56647), -- 11DU_Foundry_Door01 (Area: The Stonevault - Difficulty: Normal) CreateObject1
(@OGUID+4, 440235, 2652, 14883, 14883, '1,2,8,23', 0, 0, -27.3447647094726562, -47.6088066101074218, 362.5902099609375, 4.188792228698730468, 0, 0, -0.86602497100830078, 0.50000077486038208, 7200, 255, 1, 56647), -- 11DU_Foundry_Door02 (Area: The Stonevault - Difficulty: Normal) CreateObject1
(@OGUID+5, 433056, 2652, 14883, 14883, '1,2,8,23', 0, 0, 27.47012138366699218, -47.6778144836425781, 361.680816650390625, 2.094393253326416015, 0, 0, 0.866024971008300781, 0.50000077486038208, 7200, 255, 1, 56647), -- 11DU_Foundry_Door01 (Area: The Stonevault - Difficulty: Normal) CreateObject1
(@OGUID+6, 440239, 2652, 14883, 14883, '1,2,8,23', 0, 0, -27.4123516082763671, 47.6798248291015625, 361.960113525390625, 2.094393253326416015, 0, 0, 0.866024971008300781, 0.50000077486038208, 7200, 255, 1, 56647), -- 11DU_Foundry_Door02 (Area: The Stonevault - Difficulty: Normal) CreateObject1
(@OGUID+7, 441884, 2652, 14883, 14883, '1,2,8,23', 0, 0, -55.6035881042480468, -37.6647872924804687, 371.973175048828125, 3.83858656883239746, 0, 0, -0.93988704681396484, 0.341485440731048583, 7200, 255, 1, 56647), -- 11EA_Earthen_Special_GeothermalMachine02_AssetFix (Area: The Stonevault - Difficulty: Normal) CreateObject1
(@OGUID+8, 440234, 2652, 14883, 14883, '1,2,8,23', 0, 0, -64.444000244140625, -0.26195374131202697, 362.58709716796875, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 56647), -- 11DU_Foundry_DoorChain01 (Area: The Stonevault - Difficulty: Normal) CreateObject1
(@OGUID+9, 440240, 2652, 14883, 14883, '1,2,8,23', 0, 0, -169.734085083007812, -0.00001483862524764, 365.69207763671875, 0, 0, 0, 0, 1, 7200, 255, 0, 56647), -- 11DU_Foundry_Door03 (Area: The Stonevault - Difficulty: Normal) CreateObject1
(@OGUID+10, 433060, 2652, 14883, 14883, '1,2,8,23', 0, 0, -1.26504278182983398, -199.498703002929687, 359.295501708984375, 2.094393253326416015, 0, 0, 0.866024971008300781, 0.50000077486038208, 7200, 255, 0, 56647), -- 11DU_Rookery_Door01 (Area: The Stonevault - Difficulty: Normal) CreateObject1
(@OGUID+11, 440233, 2652, 14883, 14883, '1,2,8,23', 0, 0, -63.7452239990234375, -0.12124178558588027, 369.069793701171875, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 56647), -- 11DU_Foundry_DoorChain02 (Area: The Stonevault - Difficulty: Normal) CreateObject1
(@OGUID+12, 440229, 2652, 14883, 14883, '1,2,8,23', 0, 0, 48.13997650146484375, -188.873764038085937, 359.665069580078125, 0.523597896099090576, 0, 0, 0.258818626403808593, 0.965925931930541992, 7200, 255, 1, 56647), -- Minecart (Area: The Stonevault - Difficulty: Normal) CreateObject1
(@OGUID+13, 440226, 2652, 14883, 14883, '1,2,8,23', 0, 0, 31.22036170959472656, 54.148590087890625, 362.2802734375, 4.188792228698730468, 0, 0, -0.86602497100830078, 0.50000077486038208, 7200, 255, 1, 56647), -- 11EA_Earthen_Navigation_SmallMinecart03 (Area: The Stonevault - Difficulty: Normal) CreateObject1
(@OGUID+14, 433049, 2652, 14883, 14883, '1,2,8,23', 0, 0, 39.9830474853515625, -193.704116821289062, 359.07720947265625, 0.523597896099090576, 0, 0, 0.258818626403808593, 0.965925931930541992, 7200, 255, 1, 56647), -- 11DU_Foundry_Door01 (Area: The Stonevault - Difficulty: Normal) CreateObject1
(@OGUID+15, 252248, 2652, 14883, 14883, '1,2,8,23', 0, 0, 163.3819427490234375, 0.201388895511627197, 360.32244873046875, 0, 0, 0, 0, 1, 7200, 255, 1, 56647), -- Instance Portal (Area: The Stonevault - Difficulty: Normal) CreateObject1
(@OGUID+16, 419988, 2652, 14883, 14883, '1,2,8,23', 0, 0, -165.924819946289062, 112.772308349609375, 354.60552978515625, 5.235990047454833984, 0, 0, -0.49999904632568359, 0.866025924682617187, 7200, 255, 1, 56647), -- 11DU_Foundry_Door01 (Area: The Stonevault - Difficulty: Normal) CreateObject1
(@OGUID+17, 445512, 2652, 14883, 14883, '1,2,8,23', 0, 0, -215.43896484375, 258.21905517578125, 349.776824951171875, 2.094393253326416015, 0, 0, 0.866024971008300781, 0.50000077486038208, 7200, 255, 0, 56647), -- 10FX_Generic_Fire_Barrier (Area: The Stonevault - Difficulty: Normal) CreateObject1
(@OGUID+18, 433052, 2652, 14883, 14883, '1,2,8,23', 0, 0, -139.656890869140625, 127.3994216918945312, 356.760223388671875, 2.094393253326416015, 0, 0, 0.866024971008300781, 0.50000077486038208, 7200, 255, 0, 56647), -- 11DU_Rookery_Door01 (Area: The Stonevault - Difficulty: Normal) CreateObject1
(@OGUID+19, 444374, 2652, 14883, 14883, '1,2,8,23', 0, 0, -161.47442626953125, 105.1706619262695312, 354.98028564453125, 2.094393253326416015, 0, 0, 0.866024971008300781, 0.50000077486038208, 7200, 255, 1, 56647), -- Minecart (Area: The Stonevault - Difficulty: Normal) CreateObject1
(@OGUID+20, 441885, 2652, 14883, 14883, '1,2,8,23', 0, 0, -55.548736572265625, 37.75059890747070312, 371.973175048828125, 2.437207698822021484, 0, 0, 0.938618659973144531, 0.344956547021865844, 7200, 255, 1, 56647); -- 11EA_Earthen_Special_GeothermalMachine02_AssetFix (Area: The Stonevault - Difficulty: Normal) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+20;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 1, -0.00000004371138828, 0, 0), -- 11DU_Foundry_Door02
(@OGUID+1, 0, 0, 1, -0.00000004371138828, 0, 0), -- 11DU_Foundry_Door03
(@OGUID+2, 0, 0, 1, -0.00000004371138828, 0, 0), -- 11EA_Earthen_Navigation_SmallMinecart03
(@OGUID+3, 0, 0, 1, -0.00000004371138828, 0, 0), -- 11DU_Foundry_Door01
(@OGUID+4, 0, 0, 1, -0.00000004371138828, 0, 0), -- 11DU_Foundry_Door02
(@OGUID+5, 0, 0, 1, -0.00000004371138828, 0, 0), -- 11DU_Foundry_Door01
(@OGUID+6, 0, 0, 1, -0.00000004371138828, 0, 0), -- 11DU_Foundry_Door02
(@OGUID+7, 0, 0, 1, -0.00000004371138828, 0, 4543), -- 11EA_Earthen_Special_GeothermalMachine02_AssetFix
(@OGUID+8, 0, 0, 1, -0.00000004371138828, 0, 0), -- 11DU_Foundry_DoorChain01
(@OGUID+9, 0, 0, 1, -0.00000004371138828, 0, 0), -- 11DU_Foundry_Door03
(@OGUID+10, 0, 0, 1, -0.00000004371138828, 0, 0), -- 11DU_Rookery_Door01
(@OGUID+11, 0, 0, 1, -0.00000004371138828, 0, 0), -- 11DU_Foundry_DoorChain02
(@OGUID+12, 0, 0, 1, -0.00000004371138828, 26287, 0), -- Minecart
(@OGUID+13, 0, 0, 1, -0.00000004371138828, 0, 0), -- 11EA_Earthen_Navigation_SmallMinecart03
(@OGUID+14, 0, 0, 1, -0.00000004371138828, 0, 0), -- 11DU_Foundry_Door01
(@OGUID+16, 0, 0, 1, -0.00000004371138828, 0, 0), -- 11DU_Foundry_Door01
(@OGUID+17, 0, 0, 1, -0.00000004371138828, 0, 0), -- 10FX_Generic_Fire_Barrier
(@OGUID+18, 0, 0, 1, -0.00000004371138828, 0, 0), -- 11DU_Rookery_Door01
(@OGUID+19, 0, 0, 1, -0.00000004371138828, 26529, 0), -- Minecart
(@OGUID+20, 0, 0, 1, -0.00000004371138828, 0, 4543); -- 11EA_Earthen_Special_GeothermalMachine02_AssetFix

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (213119 /*213119 (Void Speaker Eirich) - Bot AI Follow Advert*/, 212400 /*212400 (Void Touched Elemental) - Void earth elemental Cosmetic, Bot AI Follow Advert*/, 214066 /*214066 (Cursedforge Stoneshaper)*/, 213954 /*213954 (Rock Smasher) - Invisibility and Stealth Detection*/, 210933 /*210933 (Path Helper) - Bot AI Follow Advert*/, 224962 /*224962 (Cursedforge Mender)*/, 214264 /*214264 (Cursedforge Honor Guard) - Invisibility and Stealth Detection*/, 222817 /*222817 (Earth Infused Golem) - Cosmetic Feign Death*/, 212403 /*212403 (Cursedheart Invader) - [DNT] In RP Combat*/, 221583 /*221583 (Speaker Mechhand) - Ride Vehicle Hardcoded*/, 214350 /*214350 (Turned Speaker) - Pillaging*/, 213343 /*213343 (Forge Loader) - Cosmetic Feign Death*/, 222815 /*222815 (Cursedheart Invader)*/, 222816 /*222816 (Volatile Skardyn)*/, 213338 /*213338 (Forgebound Mender) - Cosmetic Feign Death*/, 224516 /*224516 (Skardyn Invader)*/, 212405 /*212405 (Aspiring Forgehand) - Cosmetic Feign Death*/, 212765 /*212765 (Void Bound Despoiler) - [DNT] In RP Combat, Invisibility and Stealth Detection*/, 210108 /*210108 (E.D.N.A) - Earthen Energy, Skarden Spawn RP, Bot AI Follow Advert*/, 212389 /*212389 (Cursedheart Invader) - [DNT] In RP Combat, Set Health (Random 65%-85%)*/, 222923 /*222923 (Repurposed Loaderbot) - [DNT] In RP Combat, Set Health (Random 65%-85%)*/, 212764 /*212764 (Engine Speaker) - [DNT] In RP Combat*/, 212453 /*212453 (Ghastly Voidsoul) - [DNT] In RP Combat*/, 210109 /*210109 (Earth Infused Golem) - Invisibility and Stealth Detection*/, 222149, 229507, 213217, 221586, 213216, 210156);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(213119, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '423679'), -- 213119 (Void Speaker Eirich) - Bot AI Follow Advert
(212400, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '426862 422357'), -- 212400 (Void Touched Elemental) - Void earth elemental Cosmetic, Bot AI Follow Advert
(214066, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 214066 (Cursedforge Stoneshaper)
(213954, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '18950'), -- 213954 (Rock Smasher) - Invisibility and Stealth Detection
(210933, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '423677'), -- 210933 (Path Helper) - Bot AI Follow Advert
(224962, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 224962 (Cursedforge Mender)
(214264, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '18950'), -- 214264 (Cursedforge Honor Guard) - Invisibility and Stealth Detection
(222817, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- 222817 (Earth Infused Golem)
(212403, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 212403 (Cursedheart Invader)
(221583, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 221583 (Speaker Mechhand)
(214350, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 214350 (Turned Speaker)
(213343, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 213343 (Forge Loader)
(222815, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- 222815 (Cursedheart Invader)
(222816, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- 222816 (Volatile Skardyn)
(213338, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 213338 (Forgebound Mender)
(224516, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 224516 (Skardyn Invader)
(212405, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 212405 (Aspiring Forgehand)
(212765, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '18950'), -- 212765 (Void Bound Despoiler) - Invisibility and Stealth Detection
(210108, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '451704 447230 422356'), -- 210108 (E.D.N.A) - Earthen Energy, Skarden Spawn RP, Bot AI Follow Advert
(212389, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '244972'), -- 212389 (Cursedheart Invader) - Set Health (Random 65%-85%)
(222923, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '462597 244972'), -- 222923 (Repurposed Loaderbot) - Set Health (Random 65%-85%)
(212764, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 212764 (Engine Speaker)
(212453, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 212453 (Ghastly Voidsoul)
(210109, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '18950'), -- 210109 (Earth Infused Golem) - Invisibility and Stealth Detection
(222149, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 222149 (Injured Earthen)
(229507, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '462456 462496'), -- 229507 (Imbued Iron Bar) - [DNT] Earthen Metal Bar Cosmetic Aura, [DNT] Ready to Interact
(213217, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '422362'), -- 213217 (Speaker Brokk) - Bot AI Follow Advert
(221586, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 221586 (Speaker Dorlita)
(213216, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '422362'), -- 213216 (Speaker Dorlita) - Bot AI Follow Advert
(210156, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '429974 422359'); -- 210156 (Skarmorak) - Energy Bar, Bot AI Follow Advert

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (441885 /*11EA_Earthen_Special_GeothermalMachine02_AssetFix*/, 444374 /*Minecart*/, 433052 /*11DU_Rookery_Door01*/, 445512 /*10FX_Generic_Fire_Barrier*/, 419988 /*11DU_Foundry_Door01*/, 433049 /*11DU_Foundry_Door01*/, 440229 /*Minecart*/, 433060 /*11DU_Rookery_Door01*/, 440240 /*11DU_Foundry_Door03*/, 441884 /*11EA_Earthen_Special_GeothermalMachine02_AssetFix*/, 440239 /*11DU_Foundry_Door02*/, 433056 /*11DU_Foundry_Door01*/, 440235 /*11DU_Foundry_Door02*/, 433057 /*11DU_Foundry_Door01*/, 440238 /*11DU_Foundry_Door03*/, 440236 /*11DU_Foundry_Door02*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(441885, 0, 16, 0, 4543), -- 11EA_Earthen_Special_GeothermalMachine02_AssetFix
(444374, 0, 32, 26529, 0), -- Minecart
(433052, 0, 48, 0, 0), -- 11DU_Rookery_Door01
(445512, 0, 48, 0, 0), -- 10FX_Generic_Fire_Barrier
(419988, 0, 48, 0, 0), -- 11DU_Foundry_Door01
(433049, 0, 48, 0, 0), -- 11DU_Foundry_Door01
(440229, 0, 32, 26287, 0), -- Minecart
(433060, 0, 48, 0, 0), -- 11DU_Rookery_Door01
(440240, 0, 48, 0, 0), -- 11DU_Foundry_Door03
(441884, 0, 16, 0, 4543), -- 11EA_Earthen_Special_GeothermalMachine02_AssetFix
(440239, 0, 48, 0, 0), -- 11DU_Foundry_Door02
(433056, 0, 48, 0, 0), -- 11DU_Foundry_Door01
(440235, 0, 48, 0, 0), -- 11DU_Foundry_Door02
(433057, 0, 48, 0, 0), -- 11DU_Foundry_Door01
(440238, 0, 48, 0, 0), -- 11DU_Foundry_Door03
(440236, 0, 48, 0, 0); -- 11DU_Foundry_Door02

-- Template
UPDATE `creature_template` SET `faction`=14, `speed_walk`=1.60000002384185791, `speed_run`=1.714285731315612792, `BaseAttackTime`=1500, `unit_flags`=33555008, `unit_flags2`=2048 WHERE `entry`=213119; -- Void Speaker Eirich
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=212400; -- Void Touched Elemental
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=8388608 WHERE `entry`=214066; -- Cursedforge Stoneshaper
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=213954; -- Rock Smasher
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=67108864, `unit_flags3`=1090551809 WHERE `entry`=210933; -- Path Helper
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=224962; -- Cursedforge Mender
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=214264; -- Cursedforge Honor Guard
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2500, `unit_flags`=832, `unit_flags2`=2048, `unit_flags3`=2147483649 WHERE `entry`=222817; -- Earth Infused Golem
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry` IN (212403, 212389); -- Cursedheart Invader
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=67110912 WHERE `entry`=221583; -- Speaker Mechhand
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=214350; -- Turned Speaker
UPDATE `creature_template` SET `faction`=16, `speed_run`=1.38888859748840332, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=8388608, `VehicleId`=8478 WHERE `entry`=213343; -- Forge Loader
UPDATE `creature_template` SET `faction`=16, `speed_walk`=1.277776002883911132, `speed_run`=0.992062866687774658, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=221979; -- Void Bound Howler
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=832, `unit_flags2`=2048, `unit_flags3`=2147483648 WHERE `entry`=222815; -- Cursedheart Invader
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=832, `unit_flags2`=2048, `unit_flags3`=2147483648 WHERE `entry`=222816; -- Volatile Skardyn
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=213338; -- Forgebound Mender
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=524289 WHERE `entry`=224516; -- Skardyn Invader
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=212405; -- Aspiring Forgehand
UPDATE `creature_template` SET `faction`=16, `speed_walk`=1.60000002384185791, `speed_run`=1.285714268684387207, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=212765; -- Void Bound Despoiler
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=320, `unit_flags3`=8388609 WHERE `entry`=210108; -- E.D.N.A
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=222923; -- Repurposed Loaderbot
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=212764; -- Engine Speaker
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=212453; -- Ghastly Voidsoul
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2500, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=210109; -- Earth Infused Golem
UPDATE `creature_template` SET `faction`=2944, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=222149; -- Injured Earthen
UPDATE `creature_template` SET `faction`=16, `speed_run`=2, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=213217; -- Speaker Brokk
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=67110912 WHERE `entry`=221586; -- Speaker Dorlita
UPDATE `creature_template` SET `faction`=16, `speed_run`=2, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=8388608, `VehicleId`=8479 WHERE `entry`=213216; -- Speaker Dorlita
UPDATE `creature_template` SET `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110944, `unit_flags3`=1094713345 WHERE `entry`=229507; -- Imbued Iron Bar
UPDATE `creature_template` SET `faction`=35, `speed_walk`=1.20000004768371582, `speed_run`=2, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=67110912, `unit_flags3`=16810017, `flags_extra` = 128 WHERE `entry`=213839; -- Path Helper
UPDATE `creature_template` SET `faction`=16, `speed_walk`=1.60000002384185791, `speed_run`=1.714285731315612792, `BaseAttackTime`=2000, `unit_flags`=64 WHERE `entry`=210156; -- Skarmorak
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=832, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=210158; -- Earthen Melee
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=33554944, `unit_flags2`=2048, `unit_flags3`=1090551809, `flags_extra` = 128 WHERE `entry`=212299; -- Reinforce Stalker
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=33554944, `unit_flags2`=2048, `unit_flags3`=1090551809, `flags_extra` = 128 WHERE `entry`=213712; -- Jump Target Stalker
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=33554944, `unit_flags2`=2048, `unit_flags3`=1090551809, `flags_extra` = 128 WHERE `entry`=213660; -- Call Metal Stalker
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=33554944, `unit_flags2`=2048, `unit_flags3`=1090551809, `flags_extra` = 128 WHERE `entry`=213853; -- Refine Metal Stalker
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=33554944, `unit_flags2`=2048, `unit_flags3`=1090551809, `flags_extra` = 128 WHERE `entry`=214049; -- Vent Stalker

DELETE FROM `gameobject_template` WHERE `entry` IN (441885 /*11EA_Earthen_Special_GeothermalMachine02_AssetFix*/, 445512 /*10FX_Generic_Fire_Barrier*/, 444374 /*Minecart*/, 433052 /*11DU_Rookery_Door01*/, 419988 /*11DU_Foundry_Door01*/, 440240 /*11DU_Foundry_Door03*/, 440229 /*Minecart*/, 433060 /*11DU_Rookery_Door01*/, 433049 /*11DU_Foundry_Door01*/, 440226 /*11EA_Earthen_Navigation_SmallMinecart03*/, 440234 /*11DU_Foundry_DoorChain01*/, 440233 /*11DU_Foundry_DoorChain02*/, 441884 /*11EA_Earthen_Special_GeothermalMachine02_AssetFix*/, 440239 /*11DU_Foundry_Door02*/, 440238 /*11DU_Foundry_Door03*/, 433057 /*11DU_Foundry_Door01*/, 440227 /*11EA_Earthen_Navigation_SmallMinecart03*/, 440235 /*11DU_Foundry_Door02*/, 440236 /*11DU_Foundry_Door02*/, 433056 /*11DU_Foundry_Door01*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(441885, 5, 90445, '11EA_Earthen_Special_GeothermalMachine02_AssetFix', '', '', '', 1.999999523162841796, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 11EA_Earthen_Special_GeothermalMachine02_AssetFix
(445512, 0, 75069, '10FX_Generic_Fire_Barrier', '', '', '', 1.229999899864196777, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 10FX_Generic_Fire_Barrier
(444374, 10, 90093, 'Minecart', 'driver', '', '', 0.999999761581420898, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 430744, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 116615, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Minecart
(433052, 0, 89967, '11DU_Rookery_Door01', '', '', '', 0.799999892711639404, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 11DU_Rookery_Door01
(419988, 0, 87027, '11DU_Foundry_Door01', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 11DU_Foundry_Door01
(440240, 0, 89968, '11DU_Foundry_Door03', '', '', '', 0.999999761581420898, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 11DU_Foundry_Door03
(440229, 10, 86834, 'Minecart', 'driver', '', '', 0.999999761581420898, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 430739, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 116613, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Minecart
(433060, 0, 89967, '11DU_Rookery_Door01', '', '', '', 0.799999892711639404, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 11DU_Rookery_Door01
(433049, 0, 87027, '11DU_Foundry_Door01', '', '', '', 0.999999761581420898, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 11DU_Foundry_Door01
(440226, 5, 86834, '11EA_Earthen_Navigation_SmallMinecart03', '', '', '', 0.999999761581420898, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 11EA_Earthen_Navigation_SmallMinecart03
(440234, 5, 90095, '11DU_Foundry_DoorChain01', '', '', '', 0.999999761581420898, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 11DU_Foundry_DoorChain01
(440233, 5, 90094, '11DU_Foundry_DoorChain02', '', '', '', 0.999999761581420898, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 11DU_Foundry_DoorChain02
(441884, 5, 90445, '11EA_Earthen_Special_GeothermalMachine02_AssetFix', '', '', '', 1.999999403953552246, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 11EA_Earthen_Special_GeothermalMachine02_AssetFix
(440239, 0, 89967, '11DU_Foundry_Door02', '', '', '', 0.779999852180480957, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 11DU_Foundry_Door02
(440238, 0, 89968, '11DU_Foundry_Door03', '', '', '', 0.999999761581420898, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 11DU_Foundry_Door03
(433057, 0, 87027, '11DU_Foundry_Door01', '', '', '', 0.999999701976776123, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 11DU_Foundry_Door01
(440227, 5, 86834, '11EA_Earthen_Navigation_SmallMinecart03', '', '', '', 0.999999761581420898, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 11EA_Earthen_Navigation_SmallMinecart03
(440235, 0, 89967, '11DU_Foundry_Door02', '', '', '', 0.759999871253967285, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 11DU_Foundry_Door02
(440236, 0, 89967, '11DU_Foundry_Door02', '', '', '', 0.799999773502349853, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- 11DU_Foundry_Door02
(433056, 0, 87027, '11DU_Foundry_Door01', '', '', '', 0.999999761581420898, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647); -- 11DU_Foundry_Door01

-- Creature Equip
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (214066,214264,212405,212764));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(214066, 1, 189834, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Cursedforge Stoneshaper
(214264, 1, 214469, 0, 0, 225346, 0, 0, 0, 0, 0, 56647), -- Cursedforge Honor Guard
(212405, 1, 58905, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Aspiring Forgehand
(212764, 1, 116646, 0, 0, 0, 0, 0, 0, 0, 0, 56647); -- Engine Speaker

-- Vehicle
DELETE FROM `vehicle_template_accessory` WHERE (`seat_id`=0 AND `entry` IN (213216, 213343));
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(213216, 221586, 0, 0, 'Speaker Dorlita - Speaker Dorlita', 8, 0), -- Speaker Dorlita - Speaker Dorlita
(213343, 221583, 0, 0, 'Forge Loader - Speaker Mechhand', 8, 0); -- Forge Loader - Speaker Mechhand

-- NPC Spellclick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (213343, 213216);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(213343, 46598, 1, 0),
(213216, 46598, 1, 0);

-- ScriptNames
DELETE FROM `spell_script_names` WHERE `spell_id` = 325988;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(325988, 'spell_gen_feign_death_all_flags');

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2975, `StaticFlags1`=805306624, `StaticFlags3`=33554432, `VerifiedBuild`=56647 WHERE (`Entry`=214287 AND `DifficultyID`=0); -- 214287 (Earth Burst Totem) - Sessile, CanSwim, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2975, `VerifiedBuild`=56647 WHERE (`Entry`=214443 AND `DifficultyID`=0); -- 214443 (Crystal Shard) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2975, `StaticFlags1`=536871168, `StaticFlags3`=33554432, `VerifiedBuild`=56647 WHERE (`Entry`=212299 AND `DifficultyID`=0); -- 212299 (Reinforce Stalker) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2975, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=210156 AND `DifficultyID`=1); -- 210156 (Skarmorak) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2975, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=212400 AND `DifficultyID`=0); -- 212400 (Void Touched Elemental) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2145, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=210158 AND `DifficultyID`=0); -- 210158 (Earthen Melee) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2975, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=214350 AND `DifficultyID`=0); -- 214350 (Turned Speaker) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2975, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=221979 AND `DifficultyID`=0); -- 221979 (Void Bound Howler) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=536871168, `StaticFlags3`=33554432, `VerifiedBuild`=56647 WHERE (`Entry`=221403 AND `DifficultyID`=0); -- 221403 (Console Stalker) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=536871168, `StaticFlags3`=33554432, `VerifiedBuild`=56647 WHERE (`Entry`=213712 AND `DifficultyID`=0); -- 213712 (Jump Target Stalker) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=536871168, `StaticFlags3`=33554432, `VerifiedBuild`=56647 WHERE (`Entry`=213660 AND `DifficultyID`=0); -- 213660 (Call Metal Stalker) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=536871168, `StaticFlags3`=33554432, `VerifiedBuild`=56647 WHERE (`Entry`=213853 AND `DifficultyID`=0); -- 213853 (Refine Metal Stalker) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=536871168, `StaticFlags3`=33554432, `VerifiedBuild`=56647 WHERE (`Entry`=214049 AND `DifficultyID`=0); -- 214049 (Vent Stalker) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2975, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=213216 AND `DifficultyID`=0); -- 213216 (Speaker Dorlita) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2975, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=213217 AND `DifficultyID`=0); -- 213217 (Speaker Brokk) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2975, `StaticFlags1`=805306624, `VerifiedBuild`=56647 WHERE (`Entry`=221586 AND `DifficultyID`=0); -- 221586 (Speaker Dorlita) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2975, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=213119 AND `DifficultyID`=0); -- 213119 (Void Speaker Eirich) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=536871168, `StaticFlags3`=33554432, `VerifiedBuild`=56647 WHERE (`Entry`=229507 AND `DifficultyID`=0); -- 229507 (Imbued Iron Bar) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2975, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=222149 AND `DifficultyID`=0); -- 222149 (Injured Earthen) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2975, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=213343 AND `DifficultyID`=0); -- 213343 (Forge Loader) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2975, `StaticFlags1`=805306624, `VerifiedBuild`=56647 WHERE (`Entry`=221583 AND `DifficultyID`=0); -- 221583 (Speaker Mechhand) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2975, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=213338 AND `DifficultyID`=0); -- 213338 (Forgebound Mender) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2975, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=214066 AND `DifficultyID`=0); -- 214066 (Cursedforge Stoneshaper) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2702, `StaticFlags1`=805306624, `VerifiedBuild`=56647 WHERE (`Entry`=210933 AND `DifficultyID`=0); -- 210933 (Path Helper) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=536871168, `VerifiedBuild`=56647 WHERE (`Entry`=223237 AND `DifficultyID`=0); -- 223237 (Volatile Spike Stalker) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2975, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=212765 AND `DifficultyID`=0); -- 212765 (Void Bound Despoiler) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2975, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=212405 AND `DifficultyID`=0); -- 212405 (Aspiring Forgehand) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2975, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=224962 AND `DifficultyID`=0); -- 224962 (Cursedforge Mender) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2975, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=212764 AND `DifficultyID`=0); -- 212764 (Engine Speaker) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2975, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=212403 AND `DifficultyID`=0); -- 212403 (Cursedheart Invader) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2975, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=214264 AND `DifficultyID`=0); -- 214264 (Cursedforge Honor Guard) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2975, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=213954 AND `DifficultyID`=0); -- 213954 (Rock Smasher) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2975, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=210108 AND `DifficultyID`=1); -- 210108 (E.D.N.A) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=224516 AND `DifficultyID`=0); -- 224516 (Skardyn Invader) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2975, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=210109 AND `DifficultyID`=0); -- 210109 (Earth Infused Golem) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2975, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=222817 AND `DifficultyID`=0); -- 222817 (Earth Infused Golem) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2975, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=212389 AND `DifficultyID`=0); -- 212389 (Cursedheart Invader) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2975, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=222816 AND `DifficultyID`=0); -- 222816 (Volatile Skardyn) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2975, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=212453 AND `DifficultyID`=0); -- 212453 (Ghastly Voidsoul) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2975, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=222815 AND `DifficultyID`=0); -- 222815 (Cursedheart Invader) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2975, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=222923 AND `DifficultyID`=0); -- 222923 (Repurposed Loaderbot) - CanSwim

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID` IN (119856, 109870, 115945, 120170, 115944, 118453, 118692, 115974, 120054, 118702, 117641, 118731, 115818, 121954, 121903, 113752, 113753, 118714);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(119856, 0.650004267692565917, 0, 0, 56647),
(109870, 2.119057416915893554, 5, 0, 56647),
(115945, 0.520500004291534423, 2.25, 0, 56647),
(120170, 0.416400015354156494, 1.799999952316284179, 0, 56647),
(115944, 0.520500004291534423, 2.25, 0, 56647),
(118453, 0.347000002861022949, 1.5, 0, 56647),
(118692, 0.347000002861022949, 1.499999880790710449, 0, 56647),
(115974, 0.347000002861022949, 1.5, 0, 56647),
(120054, 1.029999971389770507, 1.5, 0, 56647),
(118702, 0.347000032663345336, 1.5, 0, 56647),
(117641, 0.347000002861022949, 1.5, 0, 56647),
(118731, 0.347000002861022949, 1.499999880790710449, 0, 56647),
(115818, 0.347000002861022949, 2, 0, 56647),
(121954, 0.347000002861022949, 1.499999880790710449, 0, 56647),
(121903, 2.892634868621826171, 3.749999761581420898, 0, 56647),
(113752, 0.236000001430511474, 1.5, 0, 56647),
(113753, 0.208000004291534423, 1.5, 0, 56647),
(118714, 7.877120494842529296, 10, 0, 56647);

UPDATE `creature_model_info` SET `VerifiedBuild`=56647 WHERE `DisplayID` IN (117855, 116911, 118365, 114686, 117973, 23767, 117970, 117402);

-- Path for Aspiring Forgehand
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+96;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+96, @CGUID+96, 0, 0, 515, 14, 44),
(@CGUID+96, @CGUID+91, 2, 300, 515, 14, 44),
(@CGUID+96, @CGUID+97, 4, 310, 515, 14, 44),
(@CGUID+96, @CGUID+90, 2, 60, 515, 14, 44),
(@CGUID+96, @CGUID+95, 4, 50, 515, 14, 44);

SET @MOVERGUID := @CGUID+96;
SET @ENTRY := 212405;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Aspiring Forgehand - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -107.40944, 127.704025, 357.51807, NULL, 0),
(@PATH, 1, -110.29174, 126.22796, 357.52124, NULL, 0),
(@PATH, 2, -113.15044, 124.76399, 357.52438, NULL, 0),
(@PATH, 3, -116.013855, 123.29759, 357.52756, NULL, 0),
(@PATH, 4, -118.856026, 121.84208, 357.5306, NULL, 0),
(@PATH, 5, -121.70289, 120.38416, 357.51657, NULL, 0),
(@PATH, 6, -124.554474, 118.92382, 357.50247, NULL, 0),
(@PATH, 7, -127.42966, 117.45139, 357.48828, NULL, 0),
(@PATH, 8, -130.3072, 115.97776, 357.47406, NULL, 0),
(@PATH, 9, -132.68475, 114.7602, 357.46848, NULL, 0),
(@PATH, 10, -135.2458, 113.44865, 357.47357, NULL, 0),
(@PATH, 11, -138.11365, 111.97998, 357.50998, NULL, 0),
(@PATH, 12, -139.06017, 111.495255, 357.522, NULL, 0),
(@PATH, 13, -137.71385, 112.18472, 357.47305, NULL, 0),
(@PATH, 14, -140.25497, 110.88337, 357.47845, NULL, 0),
(@PATH, 15, -137.71385, 112.18472, 357.47305, NULL, 0),
(@PATH, 16, -135.17273, 113.48608, 357.46765, NULL, 0),
(@PATH, 17, -135.17273, 113.48608, 357.46765, NULL, 0),
(@PATH, 18, -132.31097, 114.9516, 357.47333, NULL, 0),
(@PATH, 19, -129.45616, 116.4136, 357.48175, NULL, 0),
(@PATH, 20, -126.59671, 117.87796, 357.5015, NULL, 0),
(@PATH, 21, -123.74664, 119.337524, 357.5227, NULL, 0),
(@PATH, 22, -120.92466, 120.7827, 357.5399, NULL, 0),
(@PATH, 23, -118.0792, 122.2399, 357.53653, NULL, 0),
(@PATH, 24, -115.233734, 123.697105, 357.53317, NULL, 0),
(@PATH, 25, -112.367195, 125.1651, 357.5298, NULL, 0),
(@PATH, 26, -109.531105, 126.61749, 357.52643, NULL, 0),
(@PATH, 27, -106.662224, 128.08669, 357.52304, NULL, 0),
(@PATH, 28, -104.11842, 129.38943, 357.51297, NULL, 0),
(@PATH, 29, -103.13828, 129.89134, 357.47247, NULL, 0),
(@PATH, 30, -100.304565, 131.34253, 357.48666, NULL, 0),
(@PATH, 31, -97.45681, 132.8009, 357.5056, NULL, 0),
(@PATH, 32, -96.04576, 133.57765, 357.49316, NULL, 0),
(@PATH, 33, -93.26629, 132.35359, 357.5908, NULL, 0),
(@PATH, 34, -90.47265, 131.12334, 357.63107, NULL, 0),
(@PATH, 35, -87.70153, 129.90298, 357.57947, NULL, 0),
(@PATH, 36, -84.90522, 128.67154, 357.5274, NULL, 0),
(@PATH, 37, -82.15012, 127.45824, 357.4829, NULL, 0),
(@PATH, 38, -79.39259, 126.243866, 357.52692, NULL, 0),
(@PATH, 39, -76.600716, 125.01436, 357.57147, NULL, 0),
(@PATH, 40, -73.797386, 123.779816, 357.6162, NULL, 0),
(@PATH, 41, -71.01926, 122.55637, 357.66052, NULL, 0),
(@PATH, 42, -68.21417, 121.32106, 357.61902, NULL, 0),
(@PATH, 43, -65.441376, 120.09997, 357.54254, NULL, 0),
(@PATH, 44, -63.506603, 119.247925, 357.48917, NULL, 0),
(@PATH, 45, -64.69136, 119.76967, 357.5906, NULL, 0),
(@PATH, 46, -66.5437, 120.58541, 357.64038, NULL, 0),
(@PATH, 47, -69.31125, 121.80419, 357.645, NULL, 0),
(@PATH, 48, -72.111115, 123.03721, 357.6056, NULL, 0),
(@PATH, 49, -74.90869, 124.269226, 357.56622, NULL, 0),
(@PATH, 50, -77.681114, 125.49015, 357.52722, NULL, 0),
(@PATH, 51, -80.46721, 126.7171, 357.51004, NULL, 0),
(@PATH, 52, -83.25092, 127.94301, 357.55743, NULL, 0),
(@PATH, 53, -86.03693, 129.16992, 357.6049, NULL, 0),
(@PATH, 54, -88.82053, 130.39577, 357.63168, NULL, 0),
(@PATH, 55, -91.60344, 131.62132, 357.56296, NULL, 0),
(@PATH, 56, -94.3931, 132.84984, 357.5067, NULL, 0),
(@PATH, 57, -96.10782, 133.49176, 357.4977, NULL, 0),
(@PATH, 58, -98.986084, 132.01775, 357.4805, NULL, 0),
(@PATH, 59, -101.403595, 130.7797, 357.47733, NULL, 0),
(@PATH, 60, -102.58371, 130.17535, 357.51276, NULL, 0),
(@PATH, 61, -105.45772, 128.70354, 357.51593, NULL, 0);

UPDATE `creature` SET `position_x`=-107.40944, `position_y`=127.704025, `position_z`=357.51807, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Engine Speaker
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+114;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+114, @CGUID+114, 0, 0, 515, 12, 0),
(@CGUID+114, @CGUID+119, 4, 270, 515, 12, 0),
(@CGUID+114, @CGUID+117, 4, 320, 515, 12, 0),
(@CGUID+114, @CGUID+122, 4, 40, 515, 12, 0),
(@CGUID+114, @CGUID+116, 4, 0, 515, 12, 0);

SET @MOVERGUID := @CGUID+114;
SET @ENTRY := 212764;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Engine Speaker - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -120.669754, 154.23387, 354.8591, NULL, 0),
(@PATH, 1, -122.16282, 156.96906, 354.8591, NULL, 0),
(@PATH, 2, -123.65588, 159.70424, 354.8591, NULL, 0),
(@PATH, 3, -125.15516, 162.4508, 354.8591, NULL, 0),
(@PATH, 4, -126.189, 164.34471, 354.8591, NULL, 0),
(@PATH, 5, -127.53414, 166.8089, 354.8591, NULL, 0),
(@PATH, 6, -128.95135, 169.40512, 355.31207, NULL, 0),
(@PATH, 7, -130.41846, 172.0928, 355.3927, NULL, 0),
(@PATH, 8, -131.92433, 174.85144, 354.93704, NULL, 0),
(@PATH, 9, -133.34375, 177.4517, 354.94366, NULL, 0),
(@PATH, 10, -134.93155, 180.36044, 354.9238, NULL, 0),
(@PATH, 11, -135.92899, 182.18768, 354.91132, NULL, 7779),
(@PATH, 12, -138.67613, 187.22026, 354.87692, NULL, 0),
(@PATH, 13, -137.16467, 184.45135, 354.8958, NULL, 0),
(@PATH, 14, -135.66817, 181.70984, 354.91458, NULL, 0),
(@PATH, 15, -134.16074, 178.94835, 354.93344, NULL, 0),
(@PATH, 16, -132.73332, 176.3335, 354.8591, NULL, 0),
(@PATH, 17, -131.2428, 173.60283, 355.43243, NULL, 0),
(@PATH, 18, -130.35944, 171.98465, 355.39175, NULL, 0),
(@PATH, 19, -128.84795, 169.21571, 355.2617, NULL, 0),
(@PATH, 20, -127.3538, 166.47855, 354.8591, NULL, 0),
(@PATH, 21, -125.8609, 163.74367, 354.8591, NULL, 0),
(@PATH, 22, -124.3618, 160.99742, 354.8591, NULL, 0),
(@PATH, 23, -123.40783, 159.24982, 354.8591, NULL, 5638);

UPDATE `creature` SET `position_x`=-120.669754, `position_y`=154.23387, `position_z`=354.8591, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Forge Loader
SET @MOVERGUID := @CGUID+130;
SET @ENTRY := 213343;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Forge Loader - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -200.63745, 134.40535, 354.66507, NULL, 0),
(@PATH, 1, -200.4555, 134.05833, 355.0634, NULL, 0),
(@PATH, 2, -200.27356, 133.71132, 355.4617, NULL, 0),
(@PATH, 3, -200.07161, 133.32617, 355.46848, NULL, 0),
(@PATH, 4, -199.21875, 131.69966, 355.472, NULL, 0),
(@PATH, 5, -198.99617, 131.62282, 355.48166, NULL, 0),
(@PATH, 6, -196.33612, 130.70438, 355.4549, NULL, 0),
(@PATH, 7, -195.4991, 130.41539, 354.84973, NULL, 0),
(@PATH, 8, -193.33884, 129.66953, 354.95193, NULL, 0),
(@PATH, 9, -192.06075, 129.22824, 355.06223, NULL, 0),
(@PATH, 10, -189.12074, 128.21315, 354.8759, NULL, 0),
(@PATH, 11, -188.26562, 127.91791, 354.95337, NULL, 0),
(@PATH, 12, -185.91795, 127.10733, 354.8557, NULL, 0),
(@PATH, 13, -179.31862, 124.8288, 354.98697, NULL, 0),
(@PATH, 14, -171.96529, 122.28993, 355.0445, NULL, 0),
(@PATH, 15, -199.21875, 131.69966, 355.472, NULL, 0),
(@PATH, 16, -210.23091, 152.70139, 354.94626, NULL, 0),
(@PATH, 17, -232.78299, 143.84549, 354.85913, NULL, 0),
(@PATH, 18, -240.52174, 140.80658, 354.85913, NULL, 0),
(@PATH, 19, -232.78299, 143.84549, 354.85913, NULL, 0),
(@PATH, 20, -225.04424, 146.8844, 354.85913, NULL, 0),
(@PATH, 21, -214.43677, 151.0498, 354.92896, NULL, 0),
(@PATH, 22, -212.35526, 151.86719, 354.8591, NULL, 0),
(@PATH, 23, -210.23091, 152.70139, 354.94626, NULL, 0);

UPDATE `creature` SET `position_x`=-200.63745, `position_y`=134.40535, `position_z`=354.66507, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Void Bound Howler
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+62;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+62, @CGUID+62, 0, 0, 515, 7, 11),
(@CGUID+62, @CGUID+63, 4, 70, 515, 7, 11),
(@CGUID+62, @CGUID+64, 4, 290, 515, 7, 11);

SET @MOVERGUID := @CGUID+62;
SET @ENTRY := 221979;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Void Bound Howler - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -46.9988, -121.789154, 359.7473, NULL, 0),
(@PATH, 1, -46.594017, -124.91541, 359.73254, NULL, 0),
(@PATH, 2, -46.189236, -128.04167, 359.71777, NULL, 0),
(@PATH, 3, -43.93717, -132.24777, 359.6765, NULL, 0),
(@PATH, 4, -43.352448, -133.33984, 359.7933, NULL, 0),
(@PATH, 5, -41.54514, -136.71529, 359.69153, NULL, 0),
(@PATH, 6, -35.01736, -149.7882, 359.7813, NULL, 0),
(@PATH, 7, -28.069445, -161.2552, 359.61334, NULL, 4064),
(@PATH, 8, -35.01736, -149.7882, 359.7813, NULL, 0),
(@PATH, 9, -41.54514, -136.71529, 359.69153, NULL, 0),
(@PATH, 10, -46.189236, -128.04167, 359.71777, NULL, 0),
(@PATH, 11, -47.588543, -117.23438, 359.76883, NULL, 4450);

UPDATE `creature` SET `position_x`=-46.9988, `position_y`=-121.789154, `position_z`=359.7473, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Void Bound Despoiler
SET @MOVERGUID := @CGUID+149;
SET @ENTRY := 212765;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Void Bound Despoiler - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 27.71409, -212.07117, 359.43393, NULL, 0),
(@PATH, 1, 26.887154, -212.56424, 359.38516, NULL, 0),
(@PATH, 2, 26.060217, -213.05731, 359.3364, NULL, 0),
(@PATH, 3, 22.83952, -214.97766, 359.30298, NULL, 0),
(@PATH, 4, 20.189308, -216.55786, 359.16226, NULL, 0),
(@PATH, 5, 16.367886, -218.83641, 359.2751, NULL, 0),
(@PATH, 6, 12.162051, -221.34416, 359.39304, NULL, 0),
(@PATH, 7, 2.9342442, -226.8463, 359.25882, NULL, 0),
(@PATH, 8, -0.0019550323, -228.59703, 359.32574, NULL, 0),
(@PATH, 9, -2.5972977, -230.14452, 359.2473, NULL, 0),
(@PATH, 10, -4.018549, -230.99194, 359.43695, NULL, 0),
(@PATH, 11, -5.1996527, -231.69618, 359.41098, NULL, 0),
(@PATH, 12, 26.887154, -212.56424, 359.38516, NULL, 0);

UPDATE `creature` SET `position_x`=27.71409, `position_y`=-212.07117, `position_z`=359.43393, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '18950');

-- Path for Rock Smasher
SET @MOVERGUID := @CGUID+44;
SET @ENTRY := 213954;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Rock Smasher - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -143.2552, -0.11284722, 362.0622, NULL, 0),
(@PATH, 1, -99.83854, -0.083333336, 362.0622, NULL, 0);

UPDATE `creature` SET `position_x`=-143.2552, `position_y`=-0.11284722, `position_z`=362.0622, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, 3, '18950');
