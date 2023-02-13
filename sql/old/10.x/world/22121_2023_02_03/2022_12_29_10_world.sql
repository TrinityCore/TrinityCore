SET @CGUID := 1250708;
SET @OGUID := 700034;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+409;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3425.98095703125, 3431.858642578125, 275.362945556640625, 5.681218147277832031, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+1, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3485.435791015625, 3425.747314453125, 273.7197265625, 0.163867503404617309, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+2, 188542, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3479.197998046875, 3419.02685546875, 273.78759765625, 5.361971378326416015, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 47213), -- Brackenhide Deadeye (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+3, 188542, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3431.19091796875, 3415.895751953125, 276.31072998046875, 6.199040889739990234, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 47213), -- Brackenhide Deadeye (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+4, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3445.711181640625, 3467.373046875, 271.23980712890625, 5.619220733642578125, 120, 4, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+5, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3495.95654296875, 3450.115478515625, 273.31781005859375, 1.2460784912109375, 120, 4, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+6, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3452.423583984375, 3454.6953125, 271.1636962890625, 1.378580570220947265, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 369588 - Sparring Aura: Attack1H [DNT])
(@CGUID+7, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3493.553955078125, 3417.424560546875, 274.2164306640625, 1.281504034996032714, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+8, 188542, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3474.876708984375, 3481.0869140625, 272.300811767578125, 4.898689746856689453, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 47213), -- Brackenhide Deadeye (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371465 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+9, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3444.872314453125, 3427.82080078125, 273.423553466796875, 5.807306289672851562, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+10, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3451.907958984375, 3457.3447265625, 271.1636962890625, 4.520173549652099609, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 369588 - Sparring Aura: Attack1H [DNT])
(@CGUID+11, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3523.001708984375, 3466.008056640625, 270.76995849609375, 3.243909358978271484, 120, 4, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+12, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3532.196533203125, 3416.402587890625, 260.481292724609375, 1.436334133148193359, 120, 4, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+13, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3448.9775390625, 3526.32373046875, 271.115264892578125, 0.497889637947082519, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 369588 - Sparring Aura: Attack1H [DNT])
(@CGUID+14, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3508.5087890625, 3495.458251953125, 271.811187744140625, 1.91025543212890625, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+15, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3510.578125, 3518.0478515625, 272.3001708984375, 5.823171138763427734, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+16, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3446.604248046875, 3527.61376953125, 271.115478515625, 3.639482498168945312, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 369588 - Sparring Aura: Attack1H [DNT])
(@CGUID+17, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3530.9150390625, 3446.012939453125, 265.890869140625, 4.991135120391845703, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+18, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3530.670166015625, 3436.69970703125, 264.6474609375, 1.729728460311889648, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+19, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3525.69970703125, 3396.018310546875, 261.46051025390625, 0.492877066135406494, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+20, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3572.00341796875, 3524.459716796875, 274.26947021484375, 2.280708074569702148, 120, 4, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+21, 188542, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3541.392333984375, 3513.772705078125, 274.101104736328125, 2.044067859649658203, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 47213), -- Brackenhide Deadeye (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+22, 186361, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3581.625, 3436.915771484375, 198.1674652099609375, 1.403111934661865234, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Rotting Treant (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: )
(@CGUID+23, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3540.12158203125, 3501.088623046875, 272.260162353515625, 3.703927040100097656, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+24, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3547.5869140625, 3542.4765625, 273.191619873046875, 0.247151464223861694, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 391245 - Supply-Laden)
(@CGUID+25, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3534.161376953125, 3544.87939453125, 274.958709716796875, 3.196723699569702148, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+26, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3559.670166015625, 3434.520751953125, 258.443115234375, 5.371424198150634765, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+27, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3553.7587890625, 3491.030517578125, 270.566070556640625, 3.49192976951599121, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+28, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3529, 3554.302001953125, 275.7120361328125, 2.145115613937377929, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+29, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3553.75, 3528.229248046875, 272.796783447265625, 2.893810033798217773, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+30, 188542, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3548.986083984375, 3481.607666015625, 269.927520751953125, 3.2543487548828125, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 47213), -- Brackenhide Deadeye (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+31, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3530.49951171875, 3523.626708984375, 273.145721435546875, 4.889098167419433593, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+32, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3595.90283203125, 3418.76220703125, 250.045074462890625, 3.618752479553222656, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 369588 - Sparring Aura: Attack1H [DNT])
(@CGUID+33, 186362, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3578.673583984375, 3445.943603515625, 198.1674652099609375, 4.926601409912109375, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 47213), -- Brackenhide Rotflinger (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+34, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3593.551513671875, 3394.951416015625, 254.8060760498046875, 0.815765202045440673, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+35, 186362, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3592.1806640625, 3463.444580078125, 197.40771484375, 3.735027551651000976, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 47213), -- Brackenhide Rotflinger (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371837 - Channel: Decay from Ground [DNT])
(@CGUID+36, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3598.30029296875, 3417.522705078125, 249.899322509765625, 0.477159738540649414, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 369588 - Sparring Aura: Attack1H [DNT])
(@CGUID+37, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3570.90625, 3392.94189453125, 255.8752899169921875, 6.199040889739990234, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+38, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3542.614501953125, 3359.809814453125, 252.30487060546875, 4.508188724517822265, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+39, 188542, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3555.545166015625, 3364.9921875, 252.30926513671875, 6.199040889739990234, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 47213), -- Brackenhide Deadeye (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+40, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3618.87841796875, 3449.5869140625, 200.700592041015625, 3.156441450119018554, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 369588 - Sparring Aura: Attack1H [DNT])
(@CGUID+41, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3540.34716796875, 3362.4228515625, 252.521484375, 4.235173702239990234, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+42, 186361, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3660.470703125, 3470.787109375, 197.3795928955078125, 0.022457163780927658, 120, 4, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Rotting Treant (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+43, 191560, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3692.716796875, 3456.574462890625, 199.2028961181640625, 0.022375822067260742, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+44, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3648.392333984375, 3473.09033203125, 196.7227630615234375, 0, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+45, 186361, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3654.86669921875, 3532.97216796875, 195.6067352294921875, 1.471208572387695312, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Rotting Treant (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+46, 191560, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3690.21142578125, 3456.3701171875, 199.415679931640625, 2.190046310424804687, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+47, 191560, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3689.298828125, 3456.958251953125, 199.495330810546875, 2.897199392318725585, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+48, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3614.329833984375, 3509.43310546875, 218.9483184814453125, 5.371424198150634765, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+49, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3621.57470703125, 3449.546875, 198.07269287109375, 0.014848601073026657, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 369588 - Sparring Aura: Attack1H [DNT])
(@CGUID+50, 191560, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3689.368408203125, 3456.08642578125, 199.4753265380859375, 2.353564977645874023, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+51, 188542, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3609.239501953125, 3525.249267578125, 215.431976318359375, 4.796617507934570312, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 47213), -- Brackenhide Deadeye (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+52, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3637.814208984375, 3490.286376953125, 196.5738983154296875, 1.12324678897857666, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+53, 186362, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3648.786376953125, 3512.843017578125, 196.506561279296875, 3.048963546752929687, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 47213), -- Brackenhide Rotflinger (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371837 - Channel: Decay from Ground [DNT])
(@CGUID+54, 186362, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3665.069580078125, 3514.772705078125, 195.1856231689453125, 1.0569915771484375, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 47213), -- Brackenhide Rotflinger (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+55, 186362, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3627.286376953125, 3559.9765625, 207.085052490234375, 3.048963546752929687, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 47213), -- Brackenhide Rotflinger (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371837 - Channel: Decay from Ground [DNT])
(@CGUID+56, 186362, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3658.7275390625, 3534.561279296875, 195.5680694580078125, 1.473036885261535644, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 47213), -- Brackenhide Rotflinger (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+57, 186361, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3735.8828125, 3482.19921875, 201.603973388671875, 4.641620635986328125, 120, 4, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Rotting Treant (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+58, 186361, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3718.47119140625, 3477.2958984375, 197.183624267578125, 1.142510175704956054, 120, 4, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Rotting Treant (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+59, 186362, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3683.377685546875, 3467.04248046875, 199.3477020263671875, 4.117673873901367187, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 47213), -- Brackenhide Rotflinger (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 376191 - Decay Transformation) (possible waypoints or random movement)
(@CGUID+60, 191560, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3606.552001953125, 3478.654541015625, 232.6794586181640625, 3.66719985008239746, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+61, 191560, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3606.552001953125, 3478.654541015625, 232.6794586181640625, 3.910084247589111328, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+62, 186361, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3596.832763671875, 3620.88134765625, 216.8368682861328125, 1.390069127082824707, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Rotting Treant (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+63, 186362, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3696.454833984375, 3517.47998046875, 194.1636962890625, 4.971343994140625, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 47213), -- Brackenhide Rotflinger (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+64, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3680.342041015625, 3524.268310546875, 197.203125, 1.531298398971557617, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+65, 186361, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3652.9150390625, 3633.716064453125, 205.366058349609375, 0.556649684906005859, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Rotting Treant (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+66, 186361, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3588.717041015625, 3610.092041015625, 217.8084716796875, 2.400597333908081054, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Rotting Treant (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: )
(@CGUID+67, 186362, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3670.507080078125, 3553.41748046875, 196.7357940673828125, 1.727167010307312011, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 47213), -- Brackenhide Rotflinger (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+68, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3638.217041015625, 3585.31591796875, 204.273712158203125, 0.947269439697265625, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371837 - Channel: Decay from Ground [DNT]) (possible waypoints or random movement)
(@CGUID+69, 186361, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3725.444580078125, 3560.349853515625, 187.57464599609375, 0.604140222072601318, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Rotting Treant (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: )
(@CGUID+70, 186361, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3646.954833984375, 3610.72900390625, 203.9289398193359375, 0.329345345497131347, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Rotting Treant (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+71, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3677.194580078125, 3525.0869140625, 196.994781494140625, 3.264481782913208007, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+72, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3672.125, 3560.850830078125, 195.737945556640625, 5.355769157409667968, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+73, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3643.232666015625, 3564.174560546875, 200.1100006103515625, 2.491613626480102539, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+74, 186362, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3717.17529296875, 3535.88720703125, 194.9463653564453125, 1.560080289840698242, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 47213), -- Brackenhide Rotflinger (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371837 - Channel: Decay from Ground [DNT])
(@CGUID+75, 186362, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3600.619873046875, 3622.3916015625, 215.920196533203125, 1.36956644058227539, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 47213), -- Brackenhide Rotflinger (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+76, 186361, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3750.344970703125, 3590.5498046875, 186.806243896484375, 1.143854618072509765, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Rotting Treant (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+77, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3711.85595703125, 3487.506103515625, 196.292022705078125, 3.225178718566894531, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+78, 186362, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3611.515625, 3651.935791015625, 213.2860565185546875, 5.724321842193603515, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 47213), -- Brackenhide Rotflinger (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371837 - Channel: Decay from Ground [DNT])
(@CGUID+79, 186361, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3764.39013671875, 3548.6796875, 180.3086700439453125, 1.315303802490234375, 120, 4, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Rotting Treant (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+80, 186362, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3724.796875, 3605.1953125, 186.68212890625, 2.778933048248291015, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 47213), -- Brackenhide Rotflinger (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+81, 186361, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3773.4248046875, 3605.377197265625, 179.0096435546875, 2.935001850128173828, 120, 4, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Rotting Treant (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+82, 196459, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3697.41845703125, 3643.829345703125, 176.8928985595703125, 4.792530536651611328, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+83, 186361, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3762.21435546875, 3577.333740234375, 181.196624755859375, 1.472974061965942382, 120, 4, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Rotting Treant (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+84, 186359, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3724.350830078125, 3581.6728515625, 186.720489501953125, 4.51296091079711914, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+85, 191560, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3763.493896484375, 3622.65966796875, 181.44366455078125, 6.247068405151367187, 120, 3, 0, 28249, 0, 1, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+86, 196459, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3646.942626953125, 3649.46875, 171.1725921630859375, 0.757606446743011474, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 369588 - Sparring Aura: Attack1H [DNT])
(@CGUID+87, 186361, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3707.3125, 3627.40185546875, 183.791168212890625, 5.798951148986816406, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Rotting Treant (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+88, 186362, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3678.333251953125, 3612.377685546875, 193.9413604736328125, 0.116667762398719787, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 47213), -- Brackenhide Rotflinger (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371837 - Channel: Decay from Ground [DNT])
(@CGUID+89, 186361, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3744.984375, 3610.869873046875, 186.552520751953125, 4.67977762222290039, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Rotting Treant (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+90, 186362, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3594.6962890625, 3617.47216796875, 217.09576416015625, 5.924088478088378906, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 47213), -- Brackenhide Rotflinger (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+91, 196459, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3644.578125, 3650.78125, 171.1725921630859375, 3.648331880569458007, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 369588 - Sparring Aura: Attack1H [DNT])
(@CGUID+92, 191560, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3762.1025390625, 3623.411376953125, 181.9926300048828125, 0.830107629299163818, 120, 3, 0, 28249, 0, 1, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+93, 186362, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3716.9150390625, 3564.5244140625, 187.805328369140625, 3.776276350021362304, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 47213), -- Brackenhide Rotflinger (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+94, 186362, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3705.751708984375, 3516.3212890625, 194.1636962890625, 0, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 47213), -- Brackenhide Rotflinger (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371837 - Channel: Decay from Ground [DNT])
(@CGUID+95, 186362, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3647.708984375, 3614.6982421875, 203.2700042724609375, 0.324222713708877563, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 47213), -- Brackenhide Rotflinger (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+96, 186362, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3587.774169921875, 3632.726806640625, 219.0629730224609375, 4.348931789398193359, 120, 6, 0, 67184, 6882, 1, 0, 0, 0, 47213), -- Brackenhide Rotflinger (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+97, 186361, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3758.29736328125, 3571.060791015625, 181.5922088623046875, 0.021979972720146179, 120, 4, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Rotting Treant (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+98, 188542, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3690.967041015625, 3635.197021484375, 179.16064453125, 3.717143535614013671, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 47213), -- Brackenhide Deadeye (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+99, 186362, 2444, 13646, 13998, '0', '0', 0, 0, 1, -3690.59716796875, 3567.165771484375, 199.53692626953125, 6.108488082885742187, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 47213), -- Brackenhide Rotflinger (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+100, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3674.678955078125, 3670.080810546875, 170.611480712890625, 3.648331880569458007, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 369588 - Sparring Aura: Attack1H [DNT], 391245 - Supply-Laden)
(@CGUID+101, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3681.791748046875, 3667.096435546875, 169.453643798828125, 3.467923641204833984, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+102, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3677.04345703125, 3668.768310546875, 170.078399658203125, 0.506739020347595214, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 369588 - Sparring Aura: Attack1H [DNT])
(@CGUID+103, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3703.454833984375, 3649.963623046875, 175.5972442626953125, 5.6196441650390625, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+104, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3678.70654296875, 3699.79345703125, 166.94854736328125, 0.18974064290523529, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+105, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3670.626708984375, 3704.397705078125, 166.785430908203125, 5.095302104949951171, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+106, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3662.955810546875, 3708.354248046875, 166.796539306640625, 0.449838608503341674, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+107, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3684.49658203125, 3695.38720703125, 166.9122772216796875, 2.261993646621704101, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 369588 - Sparring Aura: Attack1H [DNT])
(@CGUID+108, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3674.755126953125, 3694.4306640625, 167.2472381591796875, 3.69468855857849121, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+109, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3668.829833984375, 3699.056396484375, 166.872344970703125, 1.699853062629699707, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+110, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3717.802001953125, 3692.470458984375, 165.7347259521484375, 5.30624246597290039, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+111, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3698.46533203125, 3682.357666015625, 167.005767822265625, 0.757606446743011474, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 369588 - Sparring Aura: Attack1H [DNT])
(@CGUID+112, 188542, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3695.6162109375, 3691.191650390625, 166.49627685546875, 0.058641102164983749, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 47213), -- Brackenhide Deadeye (Area: Brackenhide Brambles - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+113, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3718.65625, 3679.583251953125, 166.4278411865234375, 4.388073921203613281, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 369588 - Sparring Aura: Attack1H [DNT])
(@CGUID+114, 188542, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3732.3125, 3664.0517578125, 166.8235321044921875, 2.90380263328552246, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 47213), -- Brackenhide Deadeye (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+115, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3704.109375, 3685.5390625, 166.2950286865234375, 2.816216468811035156, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 369588 - Sparring Aura: Attack1H [DNT])
(@CGUID+116, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3685.25341796875, 3700.401123046875, 166.71435546875, 5.499550342559814453, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 369588 - Sparring Aura: Attack1H [DNT])
(@CGUID+117, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3703.53125, 3665.290771484375, 169.6033477783203125, 1.878094077110290527, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 369588 - Sparring Aura: Attack1H [DNT])
(@CGUID+118, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3700.866455078125, 3696.733642578125, 165.7044219970703125, 4.861523151397705078, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+119, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3708.833251953125, 3671.35498046875, 167.9301605224609375, 5.209937572479248046, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+120, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3721.1962890625, 3691.866455078125, 165.8414154052734375, 1.452693700790405273, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 369588 - Sparring Aura: Attack1H [DNT])
(@CGUID+121, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3707.23095703125, 3683.354248046875, 166.3076019287109375, 0.947302877902984619, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 391245 - Supply-Laden)
(@CGUID+122, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3706.671875, 3686.403564453125, 166.0088958740234375, 6.208323955535888671, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 369588 - Sparring Aura: Attack1H [DNT])
(@CGUID+123, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3696.100830078125, 3683.670166015625, 166.973297119140625, 3.648331880569458007, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 369588 - Sparring Aura: Attack1H [DNT])
(@CGUID+124, 188542, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3673.12841796875, 3716.3046875, 166.7557830810546875, 1.657451868057250976, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 47213), -- Brackenhide Deadeye (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+125, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3704.348876953125, 3667.8671875, 168.8462982177734375, 5.019686698913574218, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 369588 - Sparring Aura: Attack1H [DNT], 391245 - Supply-Laden)
(@CGUID+126, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3717.5087890625, 3695.63720703125, 165.2253265380859375, 5.379101753234863281, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+127, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3693.098876953125, 3693.99560546875, 166.405670166015625, 4.856673240661621093, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+128, 186362, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3738.467041015625, 3596.935791015625, 186.7208709716796875, 0.273962318897247314, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 47213), -- Brackenhide Rotflinger (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+129, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3716.123046875, 3701.92578125, 164.1811981201171875, 5.116475105285644531, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+130, 186362, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3754.353759765625, 3625.05908203125, 185.8810577392578125, 1.491102576255798339, 120, 4, 0, 67184, 6882, 1, 0, 0, 0, 47213), -- Brackenhide Rotflinger (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 376191 - Decay Transformation) (possible waypoints or random movement)
(@CGUID+131, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3720.875, 3694.57421875, 165.1727142333984375, 4.84653472900390625, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 369588 - Sparring Aura: Attack1H [DNT])
(@CGUID+132, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3688.09375, 3719.501708984375, 165.277496337890625, 2.023659467697143554, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+133, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3687.35595703125, 3724.533935546875, 165.3153228759765625, 3.455457687377929687, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+134, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3692.53125, 3721.8212890625, 164.5950469970703125, 3.972739458084106445, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+135, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3704.5712890625, 3715.88720703125, 163.06329345703125, 2.24598860740661621, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+136, 191560, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3784.46875, 3575.612060546875, 174.0166015625, 2.858501195907592773, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Brambles - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+137, 191560, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3790.736328125, 3574.484375, 172.101806640625, 4.968967437744140625, 120, 3, 0, 28249, 0, 1, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+138, 191560, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3783.50732421875, 3575.16162109375, 174.3437347412109375, 5.768032550811767578, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Brambles - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+139, 191560, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3811.1669921875, 3612.663330078125, 160.512054443359375, 2.098590373992919921, 120, 3, 0, 28249, 0, 1, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+140, 186361, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3788.440185546875, 3515.932861328125, 173.5159454345703125, 2.29510354995727539, 120, 4, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Rotting Treant (Area: Brackenhide Brambles - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+141, 186362, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3757.14013671875, 3556.743408203125, 180.671234130859375, 0.781942725181579589, 120, 4, 0, 67184, 6882, 1, 0, 0, 0, 47213), -- Brackenhide Rotflinger (Area: Brackenhide Brambles - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+142, 191560, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3810.4736328125, 3610.93310546875, 161.077423095703125, 0.747569978237152099, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+143, 191560, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3807.230712890625, 3612.98974609375, 161.752227783203125, 0.35869598388671875, 120, 3, 0, 28249, 0, 1, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Brambles - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+144, 191560, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3811.353271484375, 3567.16357421875, 166.3756256103515625, 1.943475127220153808, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Brambles - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+145, 186361, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3785.520263671875, 3537.483642578125, 174.002655029296875, 4.242191314697265625, 120, 4, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Rotting Treant (Area: Brackenhide Brambles - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+146, 186362, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3743.882080078125, 3582.744873046875, 186.7534637451171875, 2.338065385818481445, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 47213), -- Brackenhide Rotflinger (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 371837 - Channel: Decay from Ground [DNT])
(@CGUID+147, 191560, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3788.4072265625, 3577.735107421875, 172.305206298828125, 3.794074535369873046, 120, 3, 0, 28249, 0, 1, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+148, 191560, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3811.383544921875, 3567.12158203125, 166.3636627197265625, 1.521071195602416992, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Brambles - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+149, 191560, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3810.841796875, 3611.876953125, 160.762969970703125, 2.256525993347167968, 120, 3, 0, 28249, 0, 1, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Brambles - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+150, 186362, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3796.397705078125, 3501.00341796875, 174.23187255859375, 0.744964420795440673, 120, 4, 0, 67184, 6882, 1, 0, 0, 0, 47213), -- Brackenhide Rotflinger (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+151, 186362, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3791.424072265625, 3486.24267578125, 174.4812469482421875, 4.606694221496582031, 120, 4, 0, 67184, 6882, 1, 0, 0, 0, 47213), -- Brackenhide Rotflinger (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 376191 - Decay Transformation)
(@CGUID+152, 186362, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3790.953125, 3635.966064453125, 174.8819427490234375, 5.055264472961425781, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 47213), -- Brackenhide Rotflinger (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 371837 - Channel: Decay from Ground [DNT])
(@CGUID+153, 191560, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3805.68701171875, 3477.68212890625, 173.6791229248046875, 3.970501899719238281, 120, 3, 0, 28249, 0, 1, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Brambles - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+154, 186362, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3790.44677734375, 3606.708740234375, 169.1403961181640625, 2.318203210830688476, 120, 4, 0, 67184, 6882, 1, 0, 0, 0, 47213), -- Brackenhide Rotflinger (Area: Brackenhide Brambles - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+155, 186362, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3726.97216796875, 3461.552001953125, 194.3738250732421875, 4.817363739013671875, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 47213), -- Brackenhide Rotflinger (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+156, 191560, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3804.463623046875, 3478.504638671875, 173.65618896484375, 5.449568748474121093, 120, 3, 0, 28249, 0, 1, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Brambles - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+157, 191560, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3778.007568359375, 3476.29052734375, 175.0564422607421875, 3.982987642288208007, 120, 3, 0, 28249, 0, 1, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Brambles - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+158, 186362, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3784.522705078125, 3573.010009765625, 174.418701171875, 0.523018300533294677, 120, 4, 0, 67184, 6882, 1, 0, 0, 0, 47213), -- Brackenhide Rotflinger (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 376191 - Decay Transformation) (possible waypoints or random movement)
(@CGUID+159, 191560, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3777.05029296875, 3479.5615234375, 175.669281005859375, 0.881182074546813964, 120, 3, 0, 28249, 0, 1, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Brambles - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+160, 186362, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3762.41845703125, 3482.21533203125, 180.901641845703125, 1.560080289840698242, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 47213), -- Brackenhide Rotflinger (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 371837 - Channel: Decay from Ground [DNT])
(@CGUID+161, 186362, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3808.146484375, 3616.5341796875, 160.627227783203125, 4.663498401641845703, 120, 4, 0, 67184, 6882, 1, 0, 0, 0, 47213), -- Brackenhide Rotflinger (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 376191 - Decay Transformation) (possible waypoints or random movement)
(@CGUID+162, 186362, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3779.059814453125, 3455.1728515625, 178.983917236328125, 2.083125114440917968, 120, 4, 0, 67184, 6882, 1, 0, 0, 0, 47213), -- Brackenhide Rotflinger (Area: Brackenhide Brambles - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+163, 186359, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3705.296875, 3450.729248046875, 196.92108154296875, 3.225178718566894531, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+164, 191560, 2444, 13646, 0, '0', '0', 0, 0, 0, -3777.575927734375, 3477.3544921875, 176.052947998046875, 5.665107250213623046, 120, 3, 0, 28249, 0, 1, 0, 0, 0, 47213), -- Oozing Decay (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+165, 191560, 2444, 13646, 0, '0', '0', 0, 0, 0, -3777.72900390625, 3478.164794921875, 175.257781982421875, 4.561234474182128906, 120, 3, 0, 28249, 0, 1, 0, 0, 0, 47213), -- Oozing Decay (Area: 0 - Difficulty: 0)
(@CGUID+166, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3727.661376953125, 3705.4140625, 163.0156707763671875, 0.602119743824005126, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+167, 191560, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3810.661376953125, 3607.11767578125, 162.4986419677734375, 0.481238543987274169, 120, 3, 0, 28249, 0, 1, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+168, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3728.369873046875, 3702.841064453125, 163.2704315185546875, 1.657290935516357421, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+169, 191560, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3810.661376953125, 3607.11767578125, 162.4986419677734375, 2.2845306396484375, 120, 3, 0, 28249, 0, 1, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Brambles - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+170, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3739.4462890625, 3703.966064453125, 163.30816650390625, 5.553743362426757812, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+171, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3725.435791015625, 3706.943603515625, 162.5889129638671875, 3.992572784423828125, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 369588 - Sparring Aura: Attack1H [DNT])
(@CGUID+172, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3721.04345703125, 3704.440185546875, 162.5530242919921875, 5.002544403076171875, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+173, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3701.8125, 3720.06591796875, 163.357208251953125, 5.28867197036743164, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+174, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3698.640625, 3731.626708984375, 164.1121978759765625, 3.71563124656677246, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+175, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3711.1806640625, 3718.993896484375, 162.700469970703125, 5.804247856140136718, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+176, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3708.0869140625, 3719.7666015625, 162.778839111328125, 4.80193948745727539, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 369588 - Sparring Aura: Attack1H [DNT])
(@CGUID+177, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3708.513916015625, 3717.099853515625, 162.778839111328125, 1.412023186683654785, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 369588 - Sparring Aura: Attack1H [DNT])
(@CGUID+178, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3735.16845703125, 3738.67529296875, 161.4917449951171875, 5.318524360656738281, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+179, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3707.95849609375, 3735.010009765625, 161.130706787109375, 2.682287216186523437, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+180, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3708.710205078125, 3735.4375, 160.827392578125, 0.674289524555206298, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 369588 - Sparring Aura: Attack1H [DNT])
(@CGUID+181, 188542, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3720.3662109375, 3747.99462890625, 156.43017578125, 4.551574230194091796, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 47213), -- Brackenhide Deadeye (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+182, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3650.99658203125, 3776.37060546875, 137.846343994140625, 3.298695325851440429, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+183, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3734.642578125, 3748.8701171875, 161.0077972412109375, 0.273851782083511352, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+184, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3673.3369140625, 3788.9072265625, 137.591461181640625, 0.660052061080932617, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 369588 - Sparring Aura: Attack1H [DNT])
(@CGUID+185, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3693.132080078125, 3778.405517578125, 143.4286651611328125, 2.62938690185546875, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+186, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3735.16845703125, 3738.67529296875, 161.4917449951171875, 5.318524360656738281, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+187, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3657.538330078125, 3774.631103515625, 140.0800323486328125, 1.914641857147216796, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+188, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3723.65380859375, 3745.4765625, 157.38580322265625, 4.56784820556640625, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+189, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3728.412109375, 3752.7646484375, 156.923919677734375, 6.080486774444580078, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 369588 - Sparring Aura: Attack1H [DNT])
(@CGUID+190, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3708.5556640625, 3760.44970703125, 152.486175537109375, 4.218516826629638671, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+191, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3719.43408203125, 3740.983642578125, 158.087738037109375, 2.980849504470825195, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+192, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3727.474609375, 3741.3515625, 158.152923583984375, 0.171190127730369567, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+193, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3710.911376953125, 3763.494873046875, 151.698577880859375, 5.982250690460205078, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+194, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3725.896484375, 3751.609375, 156.772308349609375, 2.711081981658935546, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 369588 - Sparring Aura: Attack1H [DNT])
(@CGUID+195, 188542, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3725.930908203125, 3748.936767578125, 157.2659149169921875, 4.549489021301269531, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 47213), -- Brackenhide Deadeye (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+196, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3714.4931640625, 3769.671875, 151.56488037109375, 1.146691083908081054, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+197, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3710.626708984375, 3738.07373046875, 159.784698486328125, 4.900204658508300781, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+198, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3713.359375, 3748.88623046875, 156.740814208984375, 4.983184337615966796, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+199, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3731.720458984375, 3725.692626953125, 160.229156494140625, 4.979070663452148437, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+200, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3738.47216796875, 3752.282958984375, 162.5069427490234375, 0.487838000059127807, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 369588 - Sparring Aura: Attack1H [DNT])
(@CGUID+201, 188542, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3748.33154296875, 3733.327392578125, 162.3111572265625, 1.70898139476776123, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 47213), -- Brackenhide Deadeye (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 371465 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+202, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3706.28125, 3762.460205078125, 150.921356201171875, 2.686945199966430664, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+203, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3728.697998046875, 3736.521728515625, 158.629241943359375, 0.45046091079711914, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+204, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3670.158203125, 3775.7890625, 142.1439971923828125, 2.067600965499877929, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+205, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3700.94091796875, 3782.770751953125, 145.07525634765625, 5.754151344299316406, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+206, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3703.5244140625, 3762.631103515625, 150.240814208984375, 1.396663427352905273, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+207, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3680.1962890625, 3766.70654296875, 148.227813720703125, 2.321343183517456054, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+208, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3712.967041015625, 3773.61279296875, 151.43463134765625, 4.390759468078613281, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+209, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3655.182373046875, 3780.916748046875, 137.81146240234375, 4.659507274627685546, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+210, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3712.029541015625, 3744.8212890625, 158.154327392578125, 1.698868751525878906, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+211, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3706.598876953125, 3737.125, 160.827392578125, 3.815882205963134765, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 369588 - Sparring Aura: Attack1H [DNT])
(@CGUID+212, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3666.616455078125, 3778.202392578125, 141.536956787109375, 2.384345054626464843, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+213, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3736, 3753.5947265625, 161.5077972412109375, 3.629430770874023437, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 369588 - Sparring Aura: Attack1H [DNT], 391245 - Supply-Laden)
(@CGUID+214, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3717.451171875, 3798.6572265625, 149.80755615234375, 3.563288688659667968, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+215, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3705.678955078125, 3811.4072265625, 143.114990234375, 0.275531709194183349, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+216, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3685.982666015625, 3824.048583984375, 135.326904296875, 0.881894052028656005, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+217, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3691.048828125, 3798.990234375, 141.0189971923828125, 0.632391571998596191, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 369588 - Sparring Aura: Attack1H [DNT], 391245 - Supply-Laden)
(@CGUID+218, 188542, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3794.607666015625, 3719.460205078125, 161.6868896484375, 4.685454845428466796, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 47213), -- Brackenhide Deadeye (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+219, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3671.1181640625, 3790.62939453125, 137.591461181640625, 3.801644802093505859, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 369588 - Sparring Aura: Attack1H [DNT])
(@CGUID+220, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3667.248291015625, 3794.354248046875, 136.1313018798828125, 2.158169269561767578, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+221, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3706.427001953125, 3817.588623046875, 144.5962371826171875, 0.034219488501548767, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+222, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3688.515625, 3800.23095703125, 140.489013671875, 3.473124265670776367, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 369588 - Sparring Aura: Attack1H [DNT])
(@CGUID+223, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3673.32470703125, 3814.7109375, 134.30615234375, 6.220897197723388671, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 391245 - Supply-Laden)
(@CGUID+224, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3681.517333984375, 3820.27001953125, 135.509521484375, 5.498568058013916015, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+225, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3713.53759765625, 3819.6591796875, 147.2481689453125, 0.638385295867919921, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+226, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3644.939208984375, 3794.743896484375, 132.75897216796875, 2.730626344680786132, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+227, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3679.166015625, 3815.625, 135.495361328125, 0.997256875038146972, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+228, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3648.729248046875, 3798.765625, 133.17864990234375, 3.17889404296875, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 369588 - Sparring Aura: Attack1H [DNT])
(@CGUID+229, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3660.92529296875, 3798.34375, 134.68841552734375, 1.455437779426574707, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+230, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3675.585205078125, 3791.13623046875, 137.862945556640625, 0.016880713403224945, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+231, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3652.0869140625, 3801.05126953125, 133.7221221923828125, 5.064707279205322265, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+232, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3783.177001953125, 3704.771728515625, 161.7874908447265625, 3.399634361267089843, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+233, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3688.5078125, 3796.6669921875, 140.6439971923828125, 1.833876013755798339, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+234, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3680.788330078125, 3807.444580078125, 137.19384765625, 2.209135770797729492, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+235, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3684.7744140625, 3810.026123046875, 138.5615234375, 5.483000755310058593, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+236, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3651.537109375, 3798.404296875, 133.55364990234375, 0.338161259889602661, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 369588 - Sparring Aura: Attack1H [DNT])
(@CGUID+237, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3673.75, 3808.9228515625, 134.774658203125, 0.447634756565093994, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+238, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3683.826416015625, 3825.850830078125, 134.751708984375, 3.722627162933349609, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 369588 - Sparring Aura: Attack1H [DNT])
(@CGUID+239, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3693.46875, 3828.803955078125, 132.8226318359375, 0.25390791893005371, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+240, 191560, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3791.083740234375, 3852.709228515625, 151.737579345703125, 4.154025077819824218, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Brambles - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+241, 196459, 2444, 13646, 13923, '0', '0', 0, 0, 1, -3686.935791015625, 3826.0244140625, 134.49951171875, 2.17771458625793457, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 391245 - Supply-Laden)
(@CGUID+242, 191560, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3763.56591796875, 3720.892333984375, 165.4575042724609375, 1.215955018997192382, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+243, 191560, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3763.56591796875, 3720.892333984375, 165.4575042724609375, 1.382486939430236816, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+244, 191560, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3807.80029296875, 3715.296875, 159.810089111328125, 0.030515555292367935, 120, 3, 0, 28249, 0, 1, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+245, 191560, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3807.80029296875, 3715.296875, 159.810089111328125, 5.624155044555664062, 120, 3, 0, 28249, 0, 1, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Brambles - Difficulty: 0) (Auras: )
(@CGUID+246, 191560, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3794.673583984375, 3580.904052734375, 170.764862060546875, 1.418988943099975585, 120, 3, 0, 28249, 0, 1, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Brambles - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+247, 191560, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3794.673583984375, 3580.904052734375, 170.764862060546875, 5.433670520782470703, 120, 3, 0, 28249, 0, 1, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Brambles - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+248, 191560, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3790.638427734375, 3854.341552734375, 151.677032470703125, 5.133546829223632812, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+249, 191560, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3810.3701171875, 3486.021484375, 172.30023193359375, 5.277095794677734375, 120, 3, 0, 28249, 0, 1, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+250, 191560, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3810.313720703125, 3487.012451171875, 172.12872314453125, 1.301724672317504882, 120, 3, 0, 28249, 0, 1, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+251, 191560, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3779.539794921875, 3565.6591796875, 176.557586669921875, 3.739557504653930664, 120, 3, 0, 28249, 0, 1, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+252, 191560, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3779.421630859375, 3565.67529296875, 177.0471954345703125, 4.41751718521118164, 120, 3, 0, 28249, 0, 1, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+253, 191560, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3690.05029296875, 3456.884521484375, 199.5862274169921875, 0, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+254, 191560, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3690.05029296875, 3456.884521484375, 199.5862274169921875, 3.502677440643310546, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+255, 191560, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3535.84375, 3306.392333984375, 245.3413848876953125, 4.626889228820800781, 120, 3, 0, 28249, 0, 1, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+256, 191560, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3535.84375, 3306.392333984375, 245.3413848876953125, 6.102923393249511718, 120, 3, 0, 28249, 0, 1, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+257, 191558, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3422.973876953125, 3473.31689453125, 272.413116455078125, 2.02745223045349121, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brambledoe (Area: The Azure Span - Difficulty: 0) (Auras: 376140 - Decaying)
(@CGUID+258, 193425, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3406.895751953125, 3377.4296875, 283.2723388671875, 0, 120, 0, 0, 8, 0, 0, 0, 0, 0, 47213), -- Cricket (Area: The Azure Span - Difficulty: 0)
(@CGUID+259, 193428, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3383.717041015625, 3348.9775390625, 282.459869384765625, 5.66228342056274414, 120, 10, 0, 25194, 0, 1, 0, 0, 0, 47213), -- Feral Hyena (Area: The Azure Span - Difficulty: 0) (Auras: 383173 - Decaying)
(@CGUID+260, 193509, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3373.694091796875, 3298.801025390625, 279.770904541015625, 0.284584850072860717, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Woodland Filcher (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+261, 193430, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3261.711181640625, 3478.396240234375, 323.574493408203125, 3.890415906906127929, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Prowling Vulture (Area: The Azure Span - Difficulty: 0) (Auras: 383173 - Decaying) (possible waypoints or random movement)
(@CGUID+262, 193428, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3458.522216796875, 3366.725830078125, 281.35601806640625, 0.902466535568237304, 120, 10, 0, 25194, 0, 1, 0, 0, 0, 47213), -- Feral Hyena (Area: The Azure Span - Difficulty: 0) (Auras: 383173 - Decaying) (possible waypoints or random movement)
(@CGUID+263, 193511, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3432.50537109375, 3329.948974609375, 277.159271240234375, 1.610808968544006347, 120, 6, 0, 16796, 0, 1, 0, 0, 0, 47213), -- Woadspine (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+264, 191529, 2444, 13646, 13998, '0', 0, 0, 0, 0, -3493.672119140625, 3309.721435546875, 256.928192138671875, 5.671339035034179687, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Bramblestag (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+267, 193428, 2444, 13646, 13998, '0', 0, 0, 0, 0, -3454.515869140625, 3328.50732421875, 280.427215576171875, 1.139480113983154296, 120, 10, 0, 25194, 0, 1, 0, 0, 0, 47213), -- Feral Hyena (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 383173 - Decaying) (possible waypoints or random movement)
(@CGUID+268, 191529, 2444, 13646, 13998, '0', 0, 0, 0, 0, -3530.479248046875, 3326.354248046875, 247.182830810546875, 0.001507349195890128, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Bramblestag (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 375942 - Decaying)
(@CGUID+269, 191558, 2444, 13646, 13998, '0', 0, 0, 0, 0, -3606.552001953125, 3478.654541015625, 232.59613037109375, 4.891264915466308593, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brambledoe (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+270, 191529, 2444, 13646, 13998, '0', 0, 0, 0, 0, -3570.432861328125, 3317.465087890625, 248.71380615234375, 4.136300086975097656, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Bramblestag (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 376140 - Decaying)
(@CGUID+271, 191544, 2444, 13646, 13998, '0', 0, 0, 0, 0, -3578.767333984375, 3336.93115234375, 252.5155029296875, 2.714641809463500976, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Brambledoe (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 376140 - Decaying)
(@CGUID+272, 3300, 2444, 13646, 13998, '0', 0, 0, 0, 0, -3553.326904296875, 3327.481689453125, 247.897216796875, 1.575920462608337402, 120, 10, 0, 1, 0, 1, 0, 0, 0, 47213), -- Adder (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+273, 191544, 2444, 13646, 13998, '0', 0, 0, 0, 0, -3545.104248046875, 3283.0302734375, 246.9493255615234375, 6.243167877197265625, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Brambledoe (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+274, 190221, 2444, 13646, 13998, '0', 0, 0, 0, 0, -3511.062744140625, 3283.2744140625, 272.94189453125, 5.197723865509033203, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Pine Flicker (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+275, 191544, 2444, 13646, 13998, '0', 0, 0, 0, 0, -3485.55322265625, 3275.5166015625, 256.35504150390625, 0.480928093194961547, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Brambledoe (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+276, 193511, 2444, 13646, 13998, '0', 0, 0, 0, 0, -3527.935791015625, 3257.467529296875, 246.657806396484375, 4.208989620208740234, 120, 6, 0, 16796, 0, 1, 0, 0, 0, 47213), -- Woadspine (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+277, 191544, 2444, 13646, 13998, '0', 0, 0, 0, 0, -3460.415771484375, 3291.4716796875, 265.131866455078125, 2.386850595474243164, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Brambledoe (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+278, 191544, 2444, 13646, 13998, '0', 0, 0, 0, 0, -3466.720458984375, 3281.9501953125, 263.89605712890625, 4.677213191986083984, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Brambledoe (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+279, 191544, 2444, 13646, 13998, '0', 0, 0, 0, 0, -3532.992431640625, 3232.989501953125, 245.8895416259765625, 5.418867111206054687, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Brambledoe (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+280, 193509, 2444, 13646, 13998, '0', 0, 0, 0, 0, -3429.116455078125, 3250.40625, 267.24176025390625, 3.648430824279785156, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Woodland Filcher (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+281, 191544, 2444, 13646, 13998, '0', 0, 0, 0, 0, -3510.018310546875, 3222.012939453125, 248.1096649169921875, 4.330069541931152343, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Brambledoe (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+282, 191544, 2444, 13646, 13998, '0', 0, 0, 0, 0, -3484.011962890625, 3220.97998046875, 254.1435699462890625, 5.683099746704101562, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Brambledoe (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+283, 191544, 2444, 13646, 14487, '0', 0, 0, 0, 0, -3420.653076171875, 3245.5107421875, 266.6728515625, 5.175340652465820312, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Brambledoe (Area: Ancient Outlook - Difficulty: 0)
(@CGUID+284, 191544, 2444, 13646, 14487, '0', 0, 0, 0, 0, -3400.792724609375, 3268.57470703125, 271.6728515625, 4.793095588684082031, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Brambledoe (Area: Ancient Outlook - Difficulty: 0)
(@CGUID+285, 192069, 2444, 13646, 14487, '0', 0, 0, 0, 0, -3414.919189453125, 3204.5966796875, 267.53436279296875, 5.577436447143554687, 120, 4, 0, 5, 0, 1, 0, 0, 0, 47213), -- Vorquin Runt (Area: Ancient Outlook - Difficulty: 0)
(@CGUID+286, 190221, 2444, 13646, 14487, '0', 0, 0, 0, 0, -3397.224609375, 3198.763671875, 294.15863037109375, 4.032835006713867187, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Pine Flicker (Area: Ancient Outlook - Difficulty: 0)
(@CGUID+287, 193502, 2444, 13646, 14487, '0', 0, 0, 0, 0, -3312.291748046875, 3281.31298828125, 291.874847412109375, 6.212859630584716796, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 47213), -- Red Furred Calf (Area: Ancient Outlook - Difficulty: 0)
(@CGUID+288, 193497, 2444, 13646, 14487, '0', 0, 0, 0, 0, -3318.7021484375, 3244.888916015625, 290.592803955078125, 6.237915992736816406, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Shortcoat Bear (Area: Ancient Outlook - Difficulty: 0)
(@CGUID+289, 193503, 2444, 13646, 14487, '0', 0, 0, 0, 0, -3272.19775390625, 3270.167724609375, 298.958221435546875, 0.258715361356735229, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Red Furred Cow (Area: Ancient Outlook - Difficulty: 0)
(@CGUID+290, 190221, 2444, 13646, 14487, '0', 0, 0, 0, 0, -3322.1240234375, 3293.43896484375, 325.12530517578125, 4.6227569580078125, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Pine Flicker (Area: Ancient Outlook - Difficulty: 0)
(@CGUID+291, 193511, 2444, 13646, 14487, '0', 0, 0, 0, 0, -3306.641845703125, 3319.24169921875, 290.08538818359375, 0.320206761360168457, 120, 6, 0, 16796, 0, 1, 0, 0, 0, 47213), -- Woadspine (Area: Ancient Outlook - Difficulty: 0)
(@CGUID+292, 193425, 2444, 13646, 14487, '0', 0, 0, 0, 0, -3295.6181640625, 3336.612060546875, 294.51776123046875, 0, 120, 0, 0, 8, 0, 0, 0, 0, 0, 47213), -- Cricket (Area: Ancient Outlook - Difficulty: 0)
(@CGUID+293, 190221, 2444, 13646, 14487, '0', 0, 0, 0, 0, -3293.52587890625, 3296.72412109375, 340.89141845703125, 2.610142230987548828, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Pine Flicker (Area: Ancient Outlook - Difficulty: 0)
(@CGUID+294, 190221, 2444, 13646, 0, '0', 0, 0, 0, 0, -3328.804443359375, 3191.843505859375, 308.652801513671875, 3.488046169281005859, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Pine Flicker (Area: 0 - Difficulty: 0)
(@CGUID+295, 192069, 2444, 13646, 0, '0', 0, 0, 0, 0, -3264.67431640625, 3244.921630859375, 297.367645263671875, 2.276667594909667968, 120, 4, 0, 5, 0, 1, 0, 0, 0, 47213), -- Vorquin Runt (Area: 0 - Difficulty: 0)
(@CGUID+296, 193425, 2444, 13646, 0, '0', 0, 0, 0, 0, -3245.203125, 3369.564208984375, 310.54058837890625, 0, 120, 0, 0, 8, 0, 0, 0, 0, 0, 47213), -- Cricket (Area: 0 - Difficulty: 0)
(@CGUID+297, 190221, 2444, 13646, 0, '0', 0, 0, 0, 0, -3239.4658203125, 3230.208251953125, 327.824066162109375, 1.738309383392333984, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Pine Flicker (Area: 0 - Difficulty: 0)
(@CGUID+298, 193425, 2444, 13646, 0, '0', 0, 0, 0, 0, -3233.69970703125, 3369.37841796875, 312.8541259765625, 0, 120, 0, 0, 8, 0, 0, 0, 0, 0, 47213), -- Cricket (Area: 0 - Difficulty: 0)
(@CGUID+299, 193425, 2444, 13646, 0, '0', 0, 0, 0, 0, -3173.67529296875, 3286.53564453125, 317.191009521484375, 0.825959682464599609, 120, 0, 0, 8, 0, 0, 0, 0, 0, 47213), -- Cricket (Area: 0 - Difficulty: 0)
(@CGUID+300, 193430, 2444, 13646, 0, '0', 0, 0, 0, 0, -3197.400390625, 3419.575927734375, 345.271270751953125, 3.03557753562927246, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Prowling Vulture (Area: 0 - Difficulty: 0)
(@CGUID+301, 190221, 2444, 13646, 0, '0', 0, 0, 0, 0, -3170.156982421875, 3296.1708984375, 357.97479248046875, 4.032068729400634765, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Pine Flicker (Area: 0 - Difficulty: 0)
(@CGUID+302, 188690, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3478.583251953125, 3416.671875, 273.787841796875, 6.036953449249267578, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+303, 188690, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3492.87841796875, 3442.596435546875, 274.09405517578125, 2.110018253326416015, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+304, 188690, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3484.772705078125, 3414.270751953125, 273.785614013671875, 2.110018253326416015, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+305, 188690, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3498.671875, 3433.97314453125, 273.80889892578125, 1.614605903625488281, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+306, 188690, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3443.486083984375, 3477.62939453125, 271.274322509765625, 2.110018253326416015, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+307, 188690, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3497.494873046875, 3419.8212890625, 273.78558349609375, 6.036953449249267578, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+308, 188690, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3446.71875, 3448.4150390625, 271.67724609375, 2.110018253326416015, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+309, 188690, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3455.59375, 3491.686767578125, 270.445556640625, 2.110018253326416015, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+310, 188690, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3496.375, 3414.462646484375, 273.6878662109375, 3.146697759628295898, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+311, 188690, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3509.232666015625, 3428.16064453125, 273.192413330078125, 2.110018253326416015, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+312, 188690, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3510.411376953125, 3458.710205078125, 270.620697021484375, 2.110018253326416015, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+313, 188690, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3542.364501953125, 3501.544189453125, 272.050384521484375, 4.520258903503417968, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+314, 188690, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3534.666748046875, 3544.392333984375, 274.8114013671875, 5.5301513671875, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+315, 188690, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3560.154541015625, 3500.213623046875, 270.493133544921875, 4.520258903503417968, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+316, 188690, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3547.526123046875, 3544.713623046875, 273.348907470703125, 5.159641265869140625, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+317, 188690, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3546.05908203125, 3540.3916015625, 272.861968994140625, 2.62667250633239746, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+318, 188690, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3625.8125, 3453.35498046875, 197.989959716796875, 1.847855091094970703, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+319, 188690, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3625.423583984375, 3520.2890625, 213.8704833984375, 3.622732162475585937, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+320, 188690, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3665.994873046875, 3520.9541015625, 195.0088348388671875, 5.731909751892089843, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+321, 188690, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3694.8056640625, 3459.384521484375, 198.9598236083984375, 5.731909751892089843, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+322, 188690, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3650.173583984375, 3513.6171875, 196.47283935546875, 2.110018253326416015, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+323, 188690, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3627.97216796875, 3561.3515625, 206.817840576171875, 5.731909751892089843, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+324, 188690, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3710.078125, 3492.1953125, 195.3680877685546875, 6.260955810546875, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+325, 188690, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3697.45654296875, 3637.11376953125, 178.611236572265625, 5.871331691741943359, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+326, 188690, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3717.880126953125, 3603.63720703125, 186.7628631591796875, 1.429499149322509765, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+327, 188690, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3611.10595703125, 3650.673583984375, 213.089691162109375, 4.675782680511474609, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+328, 188690, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3591.100830078125, 3630.115478515625, 218.1443634033203125, 1.429499149322509765, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+329, 188690, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3699.072998046875, 3540.70654296875, 196.23443603515625, 1.429499149322509765, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+330, 188690, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3719.685791015625, 3552.932373046875, 189.196685791015625, 1.429499149322509765, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+331, 188690, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3684.9931640625, 3592.12939453125, 188.3507843017578125, 1.429499149322509765, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+332, 188690, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3624.354248046875, 3619.90966796875, 209.528350830078125, 1.429499149322509765, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+333, 188690, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3712.56591796875, 3574.647705078125, 187.84515380859375, 1.429499149322509765, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+334, 188690, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3676.73779296875, 3610.893310546875, 194.307281494140625, 1.429499149322509765, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+335, 188690, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3690.404541015625, 3668.998291015625, 169.7307586669921875, 5.871331691741943359, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+336, 188690, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3746.842041015625, 3586.075439453125, 186.73089599609375, 1.429499149322509765, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+337, 188690, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3758.48095703125, 3610.23779296875, 185.027862548828125, 1.847855091094970703, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+338, 188690, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3791.432373046875, 3633.0234375, 174.7281036376953125, 1.847855091094970703, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+339, 188690, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3766.59716796875, 3494.572021484375, 180.24395751953125, 1.847855091094970703, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+340, 188690, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3725.05908203125, 3478.708251953125, 198.13238525390625, 1.82788848876953125, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+341, 188690, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3794.708251953125, 3578.703125, 170.527069091796875, 1.847855091094970703, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+342, 188690, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3790.3837890625, 3505.05126953125, 174.452789306640625, 2.110018253326416015, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+343, 188690, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3819.217041015625, 3609.353271484375, 160.4083251953125, 1.847855091094970703, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+344, 188690, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3800.210205078125, 3457.72998046875, 173.816650390625, 1.847855091094970703, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+345, 188690, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3720.8056640625, 3705.561767578125, 162.569793701171875, 1.847855091094970703, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+346, 188690, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3783.9375, 3690.55908203125, 162.0563507080078125, 1.847855091094970703, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+347, 188690, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3710.80908203125, 3727.991455078125, 162.7105255126953125, 5.871331691741943359, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+348, 188690, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3692.48779296875, 3725.69189453125, 164.5901947021484375, 5.871331691741943359, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+349, 188690, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3737.857666015625, 3719.014892578125, 161.5079498291015625, 6.127501964569091796, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+350, 188690, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3740.00341796875, 3716.6650390625, 161.82049560546875, 1.847855091094970703, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+351, 188690, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3815.361083984375, 3701.116455078125, 156.8212890625, 1.847855091094970703, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Decaying Animal (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+352, 188689, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3452.91162109375, 3431.964111328125, 272.85565185546875, 5.585010051727294921, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+353, 188689, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3512.64697265625, 3436.571533203125, 270.70684814453125, 2.49887251853942871, 120, 3, 0, 28249, 0, 1, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+354, 188689, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3433.69677734375, 3500.228271484375, 271.96966552734375, 5.531612396240234375, 120, 3, 0, 28249, 0, 1, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+355, 188689, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3473.546630859375, 3503.352783203125, 274.298492431640625, 1.935584783554077148, 120, 3, 0, 28249, 0, 1, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+356, 188689, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3514.84326171875, 3433.58056640625, 269.43133544921875, 3.327300786972045898, 120, 3, 0, 28249, 0, 1, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+357, 188689, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3464.75341796875, 3418.6142578125, 273.60186767578125, 3.929064273834228515, 120, 3, 0, 28249, 0, 1, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+358, 188689, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3451.1884765625, 3426.575927734375, 273.16571044921875, 5.649312496185302734, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+359, 188689, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3472.603759765625, 3501.951904296875, 274.017120361328125, 3.124909877777099609, 120, 3, 0, 28249, 0, 1, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+360, 188689, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3458.540771484375, 3416.38330078125, 273.26226806640625, 0.223214849829673767, 120, 3, 0, 28249, 0, 1, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+361, 188689, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3456.067138671875, 3417.836181640625, 273.2906494140625, 3.782146692276000976, 120, 3, 0, 28249, 0, 1, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+362, 188689, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3472.420166015625, 3481.585205078125, 271.832427978515625, 4.675063610076904296, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Outskirts - Difficulty: 0)
(@CGUID+363, 188689, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3426.361328125, 3503.444091796875, 271.454620361328125, 3.70826578140258789, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+364, 188689, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3483.530517578125, 3499.734375, 273.893646240234375, 0.5811614990234375, 120, 3, 0, 28249, 0, 1, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+365, 188689, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3511.324951171875, 3433.353271484375, 271.49017333984375, 4.948845386505126953, 120, 3, 0, 28249, 0, 1, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+366, 188689, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3432.763671875, 3499.8720703125, 271.8065185546875, 0.674740970134735107, 120, 3, 0, 28249, 0, 1, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+367, 188689, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3598.078369140625, 3395.938232421875, 254.7205657958984375, 0.870808005332946777, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+368, 188689, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3597.722412109375, 3390.500244140625, 254.6024627685546875, 0.878595530986785888, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+369, 188689, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3700.4609375, 3646.395751953125, 175.9970703125, 4.792530536651611328, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+370, 188689, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3694.83251953125, 3646.939208984375, 176.0204925537109375, 4.792530536651611328, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Outskirts - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+371, 188689, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3704.105712890625, 3689.698486328125, 166.024627685546875, 5.740925788879394531, 120, 3, 0, 28249, 0, 1, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Brambles - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+372, 188689, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3702.453369140625, 3694.755859375, 165.822662353515625, 5.343771934509277343, 120, 3, 0, 28249, 0, 1, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Brambles - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+373, 188689, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3724.661865234375, 3713.9501953125, 162.153961181640625, 4.213323593139648437, 120, 3, 0, 28249, 0, 1, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Brambles - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+374, 188689, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3722.624267578125, 3712.262451171875, 162.39111328125, 0.660700380802154541, 120, 3, 0, 28249, 0, 1, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Brambles - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+375, 188689, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3733.87939453125, 3717.294189453125, 161.441253662109375, 5.688176631927490234, 120, 3, 0, 28249, 0, 1, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Brambles - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+376, 188689, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3740.10693359375, 3740.506103515625, 162.1327972412109375, 3.675737857818603515, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Brambles - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+377, 188689, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3741.70068359375, 3738.871337890625, 161.893890380859375, 2.544089794158935546, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Brambles - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+378, 188689, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3744.69189453125, 3737.953369140625, 161.6327972412109375, 1.833048105239868164, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+379, 188689, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3716.75048828125, 3752.124755859375, 155.470733642578125, 4.463619232177734375, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+380, 188689, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3727.7294921875, 3754.113037109375, 156.7093353271484375, 4.413172721862792968, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Brambles - Difficulty: 0)
(@CGUID+381, 188689, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3658.407470703125, 3785.113037109375, 138.2069854736328125, 1.316106915473937988, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Brambles - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+382, 188689, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3655.0048828125, 3781.593505859375, 137.5207061767578125, 0.14493320882320404, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Brambles - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+383, 188689, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3658.87255859375, 3783.75341796875, 138.45916748046875, 1.508255720138549804, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 47213), -- Oozing Decay (Area: Brackenhide Brambles - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+384, 191558, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3825.552001953125, 3641.954833984375, 155.6292572021484375, 4.30689859390258789, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brambledoe (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 376140 - Decaying)
(@CGUID+385, 191558, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3807.80029296875, 3715.296875, 159.7267608642578125, 5.369885921478271484, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brambledoe (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 376140 - Decaying)
(@CGUID+386, 191544, 2444, 13646, 13646, '0', '0', 0, 0, 0, -3742.910400390625, 3393.580322265625, 186.7986297607421875, 3.395667552947998046, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Brambledoe (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+387, 3300, 2444, 13646, 13646, '0', '0', 0, 0, 0, -3764.68017578125, 3438.157470703125, 183.822052001953125, 1.393422126770019531, 120, 10, 0, 1, 0, 1, 0, 0, 0, 47213), -- Adder (Area: The Azure Span - Difficulty: 0)
(@CGUID+388, 191529, 2444, 13646, 13646, '0', '0', 0, 0, 0, -3753.252685546875, 3411.1826171875, 185.6012115478515625, 4.531783580780029296, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Bramblestag (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+389, 191529, 2444, 13646, 13646, '0', '0', 0, 0, 0, -3712.319580078125, 3432.967041015625, 192.800994873046875, 1.932708144187927246, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Bramblestag (Area: The Azure Span - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+390, 191529, 2444, 13646, 13646, '0', '0', 0, 0, 0, -3745.161376953125, 3435.13720703125, 188.389923095703125, 3.351846218109130859, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Bramblestag (Area: The Azure Span - Difficulty: 0) (Auras: 375942 - Decaying)
(@CGUID+391, 191544, 2444, 13646, 13646, '0', '0', 0, 0, 0, -3761.951171875, 3392.206787109375, 185.61175537109375, 3.378997564315795898, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Brambledoe (Area: The Azure Span - Difficulty: 0)
(@CGUID+392, 191544, 2444, 13646, 13646, '0', '0', 0, 0, 0, -3781.548583984375, 3406.998779296875, 181.2674102783203125, 1.263249039649963378, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Brambledoe (Area: The Azure Span - Difficulty: 0)
(@CGUID+393, 191529, 2444, 13646, 13646, '0', '0', 0, 0, 0, -3730.97119140625, 3376.058349609375, 189.2351531982421875, 5.934247493743896484, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Bramblestag (Area: The Azure Span - Difficulty: 0)
(@CGUID+394, 191544, 2444, 13646, 13646, '0', '0', 0, 0, 0, -3818.75830078125, 3469.46728515625, 170.58856201171875, 4.575189590454101562, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Brambledoe (Area: The Azure Span - Difficulty: 0)
(@CGUID+395, 191544, 2444, 13646, 13646, '0', '0', 0, 0, 0, -3733.686279296875, 3374.776123046875, 189.5716552734375, 5.944871425628662109, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brambledoe (Area: The Azure Span - Difficulty: 0)
(@CGUID+396, 191544, 2444, 13646, 13646, '0', '0', 0, 0, 0, -3732.262451171875, 3378.75830078125, 189.411041259765625, 5.956874370574951171, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Brambledoe (Area: The Azure Span - Difficulty: 0)
(@CGUID+397, 191529, 2444, 13646, 13646, '0', '0', 0, 0, 0, -3857.3798828125, 3353.718505859375, 174.3090362548828125, 4.895037651062011718, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Bramblestag (Area: The Azure Span - Difficulty: 0) (Auras: 391254 - Hearty)
(@CGUID+398, 191529, 2444, 13646, 13646, '0', '0', 0, 0, 0, -3704.404541015625, 3416.54296875, 191.80938720703125, 1.262526750564575195, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Bramblestag (Area: The Azure Span - Difficulty: 0) (Auras: 376140 - Decaying)
(@CGUID+399, 3300, 2444, 13646, 13646, '0', '0', 0, 0, 0, -3717.884765625, 3301.94921875, 190.611358642578125, 5.237160205841064453, 120, 10, 0, 1, 0, 1, 0, 0, 0, 47213), -- Adder (Area: The Azure Span - Difficulty: 0)
(@CGUID+400, 192267, 2444, 13646, 13646, '0', '0', 0, 0, 0, -3651.587158203125, 3329.81787109375, 203.4504241943359375, 3.541973352432250976, 120, 4, 0, 5, 0, 1, 0, 0, 0, 47213), -- Azure Crystalspine (Area: The Azure Span - Difficulty: 0)
(@CGUID+401, 191529, 2444, 13646, 0, '0', '0', 0, 0, 0, -3552.248291015625, 3346.887939453125, 250.6973114013671875, 0, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Bramblestag (Area: 0 - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+402, 192502, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3462.619873046875, 3466.958251953125, 271.163818359375, 3.393913507461547851, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Fallen Iskaara Tuskarr (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+403, 192502, 2444, 13646, 0, '0', '0', 0, 0, 0, -3513.4931640625, 3454.157958984375, 270.67535400390625, 2.496710777282714843, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Fallen Iskaara Tuskarr (Area: 0 - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+404, 192502, 2444, 13646, 0, '0', '0', 0, 0, 0, -3498.8837890625, 3495.111083984375, 271.826416015625, 0, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Fallen Iskaara Tuskarr (Area: 0 - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+405, 192502, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3567.10595703125, 3503.64501953125, 270.394134521484375, 0, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Fallen Iskaara Tuskarr (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 371491 - Permanent Feign Death)
(@CGUID+406, 188853, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3631.4619140625, 3477.94189453125, 199.23150634765625, 2.988582372665405273, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Lutokk (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 130966 - Permanent Feign Death)
(@CGUID+407, 188854, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3618.666748046875, 3592.4306640625, 209.2065887451171875, 5.826032161712646484, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Kaqiata (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 130966 - Permanent Feign Death)
(@CGUID+408, 188856, 2444, 13646, 13998, '0', '0', 0, 0, 0, -3679.70654296875, 3584.135498046875, 189.390625, 2.37267613410949707, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Nomurok (Area: Brackenhide Outskirts - Difficulty: 0) (Auras: 130966 - Permanent Feign Death)
(@CGUID+409, 188855, 2444, 13646, 13923, '0', '0', 0, 0, 0, -3733.0556640625, 3598.45654296875, 186.7208709716796875, 0, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213); -- Tuyuki (Area: Brackenhide Brambles - Difficulty: 0) (Auras: 130966 - Permanent Feign Death)

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+20;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 380948, 2444, 13646, 13998, '0', '0', 0, -3168.583251953125, 4463.4921875, 0.0791034996509552, 2.836153030395507812, 0.019017696380615234, -0.01068496704101562, 0.988101959228515625, 0.152245521545410156, 120, 255, 0, 47213), -- Gnoll Cage 01 (Always Open) (Area: Brackenhide Outskirts - Difficulty: 0)
(@OGUID+1, 380949, 2444, 13646, 13998, '0', '0', 0, -3049.18408203125, 4431.0078125, 0.950052499771118164, 1.483533263206481933, 0, 0, 0.675591468811035156, 0.737276196479797363, 120, 255, 0, 47213), -- Brackenhide Gate (Always Open) (Area: Brackenhide Outskirts - Difficulty: 0)
(@OGUID+2, 380945, 2444, 13646, 13998, '0', '0', 0, -3284.182373046875, 4056.5625, 48.76538467407226562, 4.686212062835693359, 0, 0, -0.71630096435546875, 0.697791457176208496, 120, 255, 0, 47213), -- Brackenhide Gate (Always Open) (Area: Brackenhide Outskirts - Difficulty: 0)
(@OGUID+3, 380946, 2444, 13646, 13998, '0', '0', 0, -3211.77783203125, 4073.666748046875, 32.92833328247070312, 5.681047439575195312, 0, 0, -0.29654121398925781, 0.955020070075988769, 120, 255, 0, 47213), -- Brackenhide Gate (Always Open) (Area: Brackenhide Outskirts - Difficulty: 0)
(@OGUID+4, 380947, 2444, 13646, 13998, '0', '0', 0, -3162.204833984375, 4472.05712890625, 0.409722238779067993, 1.85004889965057373, 0, 0, 0.798635482788085937, 0.60181504487991333, 120, 255, 0, 47213), -- Gnoll Cage 01 (Always Open) (Area: Brackenhide Outskirts - Difficulty: 0)
(@OGUID+5, 381020, 2444, 13646, 13998, '0', '0', 0, -3269.7119140625, 4510.9697265625, 0.345486104488372802, 0.471238404512405395, -0.00268840789794921, -0.02164745330810546, 0.233237266540527343, 0.972175180912017822, 120, 255, 0, 47213), -- Gnoll Cage 01 (Always Open) (Area: Brackenhide Outskirts - Difficulty: 0)
(@OGUID+6, 381019, 2444, 13646, 13998, '0', '0', 0, -3199.6181640625, 4622.62744140625, 4.076388835906982421, 5.061457157135009765, -0.01799440383911132, -0.0123300552368164, -0.57356739044189453, 0.818867862224578857, 120, 255, 0, 47213), -- Gnoll Cage 01 (Always Open) (Area: Brackenhide Outskirts - Difficulty: 0)
(@OGUID+7, 385121, 2444, 13646, 13998, '0', '0', 0, -3462.6181640625, 3463.650146484375, 271.13818359375, 3.403396368026733398, 0, 0, -0.99144458770751953, 0.130528271198272705, 120, 255, 1, 47213), -- Campfire (Area: Brackenhide Outskirts - Difficulty: 0)
(@OGUID+8, 380912, 2444, 13646, 13998, '0', '0', 0, -3277.057373046875, 4254.7333984375, 11.20616531372070312, 6.030115127563476562, 0, 0, -0.12619781494140625, 0.992005109786987304, 120, 255, 0, 47213), -- Brackenhide Gate (Always Open) (Area: Brackenhide Outskirts - Difficulty: 0)
(@OGUID+9, 385110, 2444, 13646, 13998, '0', '0', 0, -3556.522705078125, 3491.028564453125, 270.10418701171875, 4.075345039367675781, 0, 0, -0.89297866821289062, 0.450098991394042968, 120, 255, 1, 47213), -- Campfire (Area: Brackenhide Outskirts - Difficulty: 0)
(@OGUID+10, 385117, 2444, 13646, 13998, '0', '0', 0, -3507.819580078125, 3499.01904296875, 271.85040283203125, 2.827429771423339843, 0, 0, 0.987688064575195312, 0.156436234712600708, 120, 255, 1, 47213), -- Campfire (Area: Brackenhide Outskirts - Difficulty: 0)
(@OGUID+11, 385113, 2444, 13646, 13998, '0', '0', 0, -3671.697998046875, 3501.278564453125, 195.0572052001953125, 2.879789113998413085, 0, 0, 0.991444587707519531, 0.130528271198272705, 120, 255, 1, 47213), -- Campfire (Area: Brackenhide Outskirts - Difficulty: 0)
(@OGUID+12, 385111, 2444, 13646, 13998, '0', '0', 0, -3702.991455078125, 3507.6337890625, 194.1363372802734375, 4.965465068817138671, 0, 0, -0.61221599578857421, 0.790690541267395019, 120, 255, 1, 47213), -- Campfire (Area: Brackenhide Outskirts - Difficulty: 0)
(@OGUID+13, 385114, 2444, 13646, 13998, '0', '0', 0, -3719.598876953125, 3586.138916015625, 186.6935272216796875, 2.076939344406127929, 0, 0, 0.861628532409667968, 0.50753939151763916, 120, 255, 1, 47213), -- Campfire (Area: Brackenhide Outskirts - Difficulty: 0)
(@OGUID+14, 377471, 2444, 13646, 13998, '0', '0', 0, -3666.505126953125, 3711.194580078125, 166.7419281005859375, 3.543023586273193359, 0, 0, -0.97992420196533203, 0.199370384216308593, 120, 255, 1, 47213), -- Bonfire (Area: Brackenhide Outskirts - Difficulty: 0)
(@OGUID+15, 385115, 2444, 13646, 13998, '0', '0', 0, -3733.00341796875, 3680.8984375, 166.0814361572265625, 5.672319889068603515, 0, 0, -0.3007059097290039, 0.953716933727264404, 120, 255, 1, 47213), -- Campfire (Area: Brackenhide Outskirts - Difficulty: 0)
(@OGUID+16, 377921, 2444, 13646, 13923, '0', '0', 0, -3778.147705078125, 3804.076416015625, 125.6231765747070312, 0.547472059726715087, -0.12381410598754882, 0.388026237487792968, 0.253025054931640625, 0.877544343471527099, 120, 255, 1, 47213), -- Ley Crystal (Area: Brackenhide Brambles - Difficulty: 0)
(@OGUID+17, 377921, 2444, 13646, 13923, '0', '0', 0, -3764.56591796875, 3826.529541015625, 125.8907623291015625, 0, 0, 0, 0, 1, 120, 255, 1, 47213), -- Ley Crystal (Area: Brackenhide Brambles - Difficulty: 0)
(@OGUID+18, 377921, 2444, 13646, 13923, '0', '0', 0, -3797.75341796875, 3856.532958984375, 126.6612930297851562, 4.36078643798828125, 0.325540542602539062, 0.244781494140625, -0.74512100219726562, 0.528109908103942871, 120, 255, 1, 47213), -- Ley Crystal (Area: Brackenhide Brambles - Difficulty: 0)
(@OGUID+19, 385189, 2444, 13646, 13923, '0', '0', 0, -3815.15185546875, 3942.555908203125, 147.5651397705078125, 5.454157352447509765, 0, 0, -0.40274524688720703, 0.915312111377716064, 120, 255, 1, 47213), -- Campfire (Area: Brackenhide Brambles - Difficulty: 0)
(@OGUID+20, 385218, 2444, 13646, 13847, '0', '0', 0, -3773.534912109375, 4001.42236328125, 123.9678115844726562, 6.073748111724853515, 0, 0, -0.10452747344970703, 0.994521975517272949, 120, 255, 1, 47213); -- Campfire (Area: Brackenhide Hollow - Difficulty: 0)
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+20;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+19, 0, 0, -0.1478094458580017, 0.989015877246856689, 0, 0), -- Campfire
(@OGUID+20, 0, 0, 0.224950835108757019, 0.974370181560516357, 0, 0); -- Campfire

-- Creature Addon
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+409;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+2, 0, 0, 0, 1, 69, 0, 0, 0, 0, ''), -- Brackenhide Deadeye
(@CGUID+3, 0, 0, 0, 2, 747, 0, 0, 0, 0, ''), -- Brackenhide Deadeye
(@CGUID+6, 0, 0, 0, 1, 333, 0, 0, 0, 0, '369588'), -- Brackenhide Scrapper - 369588 - Sparring Aura: Attack1H [DNT]
(@CGUID+7, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+8, 0, 0, 0, 1, 0, 0, 0, 0, 0, '371465'), -- Brackenhide Deadeye - 371465 - Cosmetic - Sleep Zzz Breakable
(@CGUID+10, 0, 0, 0, 1, 333, 0, 0, 0, 0, '369588'), -- Brackenhide Scrapper - 369588 - Sparring Aura: Attack1H [DNT]
(@CGUID+13, 0, 0, 0, 1, 333, 0, 0, 0, 0, '369588'), -- Brackenhide Scrapper - 369588 - Sparring Aura: Attack1H [DNT]
(@CGUID+14, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+15, 0, 0, 0, 1, 69, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+16, 0, 0, 0, 1, 333, 0, 0, 0, 0, '369588'), -- Brackenhide Scrapper - 369588 - Sparring Aura: Attack1H [DNT]
(@CGUID+19, 0, 0, 0, 1, 173, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+21, 0, 0, 0, 1, 69, 0, 0, 0, 0, ''), -- Brackenhide Deadeye
(@CGUID+23, 0, 0, 0, 1, 93, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+24, 0, 0, 0, 1, 0, 0, 0, 0, 0, '391245'), -- Brackenhide Scrapper - 391245 - Supply-Laden
(@CGUID+26, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+27, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+28, 0, 0, 0, 1, 93, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+29, 0, 0, 0, 1, 69, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+30, 0, 0, 0, 1, 69, 0, 0, 0, 0, ''), -- Brackenhide Deadeye
(@CGUID+32, 0, 0, 0, 1, 333, 0, 0, 0, 0, '369588'), -- Brackenhide Scrapper - 369588 - Sparring Aura: Attack1H [DNT]
(@CGUID+35, 0, 0, 0, 1, 0, 0, 0, 0, 0, '371837'), -- Brackenhide Rotflinger - 371837 - Channel: Decay from Ground [DNT]
(@CGUID+36, 0, 0, 0, 1, 333, 0, 0, 0, 0, '369588'), -- Brackenhide Scrapper - 369588 - Sparring Aura: Attack1H [DNT]
(@CGUID+38, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+39, 0, 0, 0, 2, 747, 0, 0, 0, 0, ''), -- Brackenhide Deadeye
(@CGUID+40, 0, 0, 0, 1, 333, 0, 0, 0, 0, '369588'), -- Brackenhide Scrapper - 369588 - Sparring Aura: Attack1H [DNT]
(@CGUID+41, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+44, 0, 0, 0, 1, 69, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+48, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+49, 0, 0, 0, 1, 333, 0, 0, 0, 0, '369588'), -- Brackenhide Scrapper - 369588 - Sparring Aura: Attack1H [DNT]
(@CGUID+51, 0, 0, 0, 2, 747, 0, 0, 0, 0, ''), -- Brackenhide Deadeye
(@CGUID+52, 0, 0, 0, 1, 69, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+53, 0, 0, 0, 1, 0, 0, 0, 0, 0, '371837'), -- Brackenhide Rotflinger - 371837 - Channel: Decay from Ground [DNT]
(@CGUID+55, 0, 0, 0, 1, 0, 0, 0, 0, 0, '371837'), -- Brackenhide Rotflinger - 371837 - Channel: Decay from Ground [DNT]
(@CGUID+59, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- Brackenhide Rotflinger
(@CGUID+64, 0, 0, 0, 1, 234, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+65, 0, 0, 0, 1, 431, 0, 0, 0, 0, ''), -- Rotting Treant
(@CGUID+68, 0, 0, 0, 1, 0, 0, 0, 0, 0, '371837'), -- Brackenhide Scrapper - 371837 - Channel: Decay from Ground [DNT]
(@CGUID+71, 0, 0, 0, 1, 69, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+73, 0, 0, 0, 1, 234, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+74, 0, 0, 0, 1, 0, 0, 0, 0, 0, '371837'), -- Brackenhide Rotflinger - 371837 - Channel: Decay from Ground [DNT]
(@CGUID+77, 0, 0, 0, 1, 69, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+78, 0, 0, 0, 1, 0, 0, 0, 0, 0, '371837'), -- Brackenhide Rotflinger - 371837 - Channel: Decay from Ground [DNT]
(@CGUID+84, 0, 0, 0, 1, 234, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+86, 0, 0, 0, 1, 333, 0, 0, 0, 0, '369588'), -- Brackenhide Scrapper - 369588 - Sparring Aura: Attack1H [DNT]
(@CGUID+87, 0, 0, 0, 1, 431, 0, 0, 0, 0, ''), -- Rotting Treant
(@CGUID+88, 0, 0, 0, 1, 0, 0, 0, 0, 0, '371837'), -- Brackenhide Rotflinger - 371837 - Channel: Decay from Ground [DNT]
(@CGUID+89, 0, 0, 0, 1, 431, 0, 0, 0, 0, ''), -- Rotting Treant
(@CGUID+91, 0, 0, 0, 1, 333, 0, 0, 0, 0, '369588'), -- Brackenhide Scrapper - 369588 - Sparring Aura: Attack1H [DNT]
(@CGUID+94, 0, 0, 0, 1, 0, 0, 0, 0, 0, '371837'), -- Brackenhide Rotflinger - 371837 - Channel: Decay from Ground [DNT]
(@CGUID+98, 0, 0, 0, 2, 747, 0, 0, 0, 0, ''), -- Brackenhide Deadeye
(@CGUID+100, 0, 0, 0, 1, 333, 0, 0, 0, 0, '369588 391245'), -- Brackenhide Scrapper - 369588 - Sparring Aura: Attack1H [DNT], 391245 - Supply-Laden
(@CGUID+101, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+102, 0, 0, 0, 1, 333, 0, 0, 0, 0, '369588'), -- Brackenhide Scrapper - 369588 - Sparring Aura: Attack1H [DNT]
(@CGUID+103, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+104, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+105, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+107, 0, 0, 0, 1, 333, 0, 0, 0, 0, '369588'), -- Brackenhide Scrapper - 369588 - Sparring Aura: Attack1H [DNT]
(@CGUID+108, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+109, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+110, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+111, 0, 0, 0, 1, 333, 0, 0, 0, 0, '369588'), -- Brackenhide Scrapper - 369588 - Sparring Aura: Attack1H [DNT]
(@CGUID+113, 0, 0, 0, 1, 333, 0, 0, 0, 0, '369588'), -- Brackenhide Scrapper - 369588 - Sparring Aura: Attack1H [DNT]
(@CGUID+115, 0, 0, 0, 1, 333, 0, 0, 0, 0, '369588'), -- Brackenhide Scrapper - 369588 - Sparring Aura: Attack1H [DNT]
(@CGUID+116, 0, 0, 0, 1, 333, 0, 0, 0, 0, '369588'), -- Brackenhide Scrapper - 369588 - Sparring Aura: Attack1H [DNT]
(@CGUID+117, 0, 0, 0, 1, 333, 0, 0, 0, 0, '369588'), -- Brackenhide Scrapper - 369588 - Sparring Aura: Attack1H [DNT]
(@CGUID+118, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+119, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+120, 0, 0, 0, 1, 333, 0, 0, 0, 0, '369588'), -- Brackenhide Scrapper - 369588 - Sparring Aura: Attack1H [DNT]
(@CGUID+121, 0, 0, 0, 1, 333, 0, 0, 0, 0, '391245'), -- Brackenhide Scrapper - 391245 - Supply-Laden
(@CGUID+122, 0, 0, 0, 1, 333, 0, 0, 0, 0, '369588'), -- Brackenhide Scrapper - 369588 - Sparring Aura: Attack1H [DNT]
(@CGUID+123, 0, 0, 0, 1, 333, 0, 0, 0, 0, '369588'), -- Brackenhide Scrapper - 369588 - Sparring Aura: Attack1H [DNT]
(@CGUID+124, 0, 0, 0, 1, 69, 0, 0, 0, 0, ''), -- Brackenhide Deadeye
(@CGUID+125, 0, 0, 0, 1, 333, 0, 0, 0, 0, '369588 391245'), -- Brackenhide Scrapper - 369588 - Sparring Aura: Attack1H [DNT], 391245 - Supply-Laden
(@CGUID+126, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+127, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+129, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+130, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- Brackenhide Rotflinger
(@CGUID+131, 0, 0, 0, 1, 333, 0, 0, 0, 0, '369588'), -- Brackenhide Scrapper - 369588 - Sparring Aura: Attack1H [DNT]
(@CGUID+132, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+133, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+134, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+135, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+146, 0, 0, 0, 1, 0, 0, 0, 0, 0, '371837'), -- Brackenhide Rotflinger - 371837 - Channel: Decay from Ground [DNT]
(@CGUID+151, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- Brackenhide Rotflinger
(@CGUID+152, 0, 0, 0, 1, 0, 0, 0, 0, 0, '371837'), -- Brackenhide Rotflinger - 371837 - Channel: Decay from Ground [DNT]
(@CGUID+155, 0, 0, 0, 1, 27, 0, 0, 0, 0, ''), -- Brackenhide Rotflinger
(@CGUID+158, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- Brackenhide Rotflinger
(@CGUID+160, 0, 0, 0, 1, 0, 0, 0, 0, 0, '371837'), -- Brackenhide Rotflinger - 371837 - Channel: Decay from Ground [DNT]
(@CGUID+161, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- Brackenhide Rotflinger
(@CGUID+163, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+166, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+168, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+170, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+171, 0, 0, 0, 1, 333, 0, 0, 0, 0, '369588'), -- Brackenhide Scrapper - 369588 - Sparring Aura: Attack1H [DNT]
(@CGUID+172, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+173, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+174, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+175, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+176, 0, 0, 0, 1, 333, 0, 0, 0, 0, '369588'), -- Brackenhide Scrapper - 369588 - Sparring Aura: Attack1H [DNT]
(@CGUID+177, 0, 0, 0, 1, 333, 0, 0, 0, 0, '369588'), -- Brackenhide Scrapper - 369588 - Sparring Aura: Attack1H [DNT]
(@CGUID+178, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+180, 0, 0, 0, 1, 333, 0, 0, 0, 0, '369588'), -- Brackenhide Scrapper - 369588 - Sparring Aura: Attack1H [DNT]
(@CGUID+182, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+183, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+184, 0, 0, 0, 1, 333, 0, 0, 0, 0, '369588'), -- Brackenhide Scrapper - 369588 - Sparring Aura: Attack1H [DNT]
(@CGUID+185, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+186, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+187, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+189, 0, 0, 0, 1, 333, 0, 0, 0, 0, '369588'), -- Brackenhide Scrapper - 369588 - Sparring Aura: Attack1H [DNT]
(@CGUID+190, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+191, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+192, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+193, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+194, 0, 0, 0, 1, 333, 0, 0, 0, 0, '369588'), -- Brackenhide Scrapper - 369588 - Sparring Aura: Attack1H [DNT]
(@CGUID+196, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+197, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+198, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+199, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+200, 0, 0, 0, 1, 333, 0, 0, 0, 0, '369588'), -- Brackenhide Scrapper - 369588 - Sparring Aura: Attack1H [DNT]
(@CGUID+201, 0, 0, 0, 1, 0, 0, 0, 0, 0, '371465'), -- Brackenhide Deadeye - 371465 - Cosmetic - Sleep Zzz Breakable
(@CGUID+202, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+203, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+204, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+205, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+206, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+207, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+208, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+209, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+210, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+211, 0, 0, 0, 1, 333, 0, 0, 0, 0, '369588'), -- Brackenhide Scrapper - 369588 - Sparring Aura: Attack1H [DNT]
(@CGUID+212, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+213, 0, 0, 0, 1, 333, 0, 0, 0, 0, '369588 391245'), -- Brackenhide Scrapper - 369588 - Sparring Aura: Attack1H [DNT], 391245 - Supply-Laden
(@CGUID+215, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+216, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+217, 0, 0, 0, 1, 333, 0, 0, 0, 0, '369588 391245'), -- Brackenhide Scrapper - 369588 - Sparring Aura: Attack1H [DNT], 391245 - Supply-Laden
(@CGUID+218, 0, 0, 0, 2, 747, 0, 0, 0, 0, ''), -- Brackenhide Deadeye
(@CGUID+219, 0, 0, 0, 1, 333, 0, 0, 0, 0, '369588'), -- Brackenhide Scrapper - 369588 - Sparring Aura: Attack1H [DNT]
(@CGUID+220, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+221, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+222, 0, 0, 0, 1, 333, 0, 0, 0, 0, '369588'), -- Brackenhide Scrapper - 369588 - Sparring Aura: Attack1H [DNT]
(@CGUID+223, 0, 0, 0, 1, 333, 0, 0, 0, 0, '391245'), -- Brackenhide Scrapper - 391245 - Supply-Laden
(@CGUID+224, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+225, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+226, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+227, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+228, 0, 0, 0, 1, 333, 0, 0, 0, 0, '369588'), -- Brackenhide Scrapper - 369588 - Sparring Aura: Attack1H [DNT]
(@CGUID+229, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+230, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+231, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+232, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+233, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+234, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+235, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+236, 0, 0, 0, 1, 333, 0, 0, 0, 0, '369588'), -- Brackenhide Scrapper - 369588 - Sparring Aura: Attack1H [DNT]
(@CGUID+237, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+238, 0, 0, 0, 1, 333, 0, 0, 0, 0, '369588'), -- Brackenhide Scrapper - 369588 - Sparring Aura: Attack1H [DNT]
(@CGUID+239, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Brackenhide Scrapper
(@CGUID+241, 0, 0, 0, 1, 333, 0, 0, 0, 0, '391245'), -- Brackenhide Scrapper - 391245 - Supply-Laden
(@CGUID+257, 0, 0, 0, 1, 64, 0, 0, 0, 0, '376140'), -- Brambledoe - 376140 - Decaying
(@CGUID+269, 0, 0, 0, 1, 64, 0, 0, 0, 0, '376140'), -- Brambledoe - 376140 - Decaying
(@CGUID+384, 0, 0, 0, 1, 64, 0, 0, 0, 0, '376140'), -- Brambledoe - 376140 - Decaying
(@CGUID+385, 0, 0, 0, 1, 64, 0, 0, 0, 0, '376140'), -- Brambledoe - 376140 - Decaying
(@CGUID+389, 0, 0, 262144, 1, 0, 0, 0, 0, 0, '371491'), -- Bramblestag - 371491 - Permanent Feign Death
(@CGUID+390, 0, 0, 0, 1, 64, 0, 0, 0, 0, '375942'), -- Bramblestag - 375942 - Decaying
(@CGUID+397, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- Bramblestag - 391254
(@CGUID+398, 0, 0, 0, 1, 64, 0, 0, 0, 0, '376140'), -- Bramblestag - 376140 - Decaying
(@CGUID+401, 0, 0, 0, 1, 0, 0, 0, 0, 0, '376140'); -- Bramblestag - 376140 - Decaying

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (188855, 188856, 188854, 188853, 192502, 188690);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(188855, 0, 0, 262144, 1, 0, 0, 0, 0, 0, '130966'), -- 188855 (Tuyuki) - Permanent Feign Death
(188856, 0, 0, 262144, 1, 0, 0, 0, 0, 0, '130966'), -- 188856 (Nomurok) - Permanent Feign Death
(188854, 0, 0, 262144, 1, 0, 0, 0, 0, 0, '130966'), -- 188854 (Kaqiata) - Permanent Feign Death
(188853, 0, 0, 262144, 1, 0, 0, 0, 0, 0, '130966'), -- 188853 (Lutokk) - Permanent Feign Death
(192502, 0, 0, 262144, 1, 0, 0, 0, 0, 0, '371491'), -- 192502 (Fallen Iskaara Tuskarr) - Permanent Feign Death
(188690, 0, 0, 262144, 1, 0, 0, 0, 0, 0, '371491'); -- 188690 (Decaying Animal) - Permanent Feign Death

-- Creature Template
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=191544; -- Brambledoe
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=193507; -- Red Furred Bull
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=537166592, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=188690; -- Decaying Animal
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=191529; -- Bramblestag
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=190, `speed_walk`=0.5, `speed_run`=0.571428596973419189, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=191558; -- Brambledoe
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry` IN (186363, 192057); -- Brackenhide Putrifier
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry` IN (196459, 186359); -- Brackenhide Scrapper
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=67, `faction`=16, `BaseAttackTime`=1500, `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=524288 WHERE `entry`=191560; -- Oozing Decay
UPDATE `creature_template` SET `minlevel`=67, `maxlevel`=67, `faction`=16, `BaseAttackTime`=1500, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=188689; -- Oozing Decay
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=186362; -- Brackenhide Rotflinger
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=186361; -- Rotting Treant
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=188542; -- Brackenhide Deadeye
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=3273, `BaseAttackTime`=2000, `unit_flags`=537165824, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=188855; -- Tuyuki
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=3273, `BaseAttackTime`=2000, `unit_flags`=537165824, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=188856; -- Nomurok
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=3273, `BaseAttackTime`=2000, `unit_flags`=537165824, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=188854; -- Kaqiata
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=3273, `BaseAttackTime`=2000, `unit_flags`=537165824, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=186197; -- Popoak
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=3273, `BaseAttackTime`=2000, `unit_flags`=537165824, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=188853; -- Lutokk
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=3273, `BaseAttackTime`=2000, `unit_flags`=537166592, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=192502; -- Fallen Iskaara Tuskarr

-- Add SpellScript to Feign Death Aura
DELETE FROM `spell_script_names` WHERE `spell_id` IN (371491,130966);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(371491, 'spell_gen_feign_death_all_flags'),
(130966, 'spell_gen_feign_death_all_flags');

-- Creature Equip
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (196459,188542,186359));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(196459, 1, 189549, 0, 0, 0, 0, 0, 0, 0, 0, 47213), -- Brackenhide Scrapper
(188542, 1, 0, 0, 0, 0, 0, 0, 191696, 0, 0, 47213), -- Brackenhide Deadeye
(186359, 1, 189549, 0, 0, 0, 0, 0, 0, 0, 0, 47213); -- Brackenhide Scrapper

-- SAI
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` IN (186362, 186359);
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` IN (-(@CGUID+90), -(@CGUID+93), -(@CGUID+33));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-(@CGUID+90), 0, 0, 0, 1, 0, 100, 1, 1000, 1000, 0, 0, 11, 371632, 3, 0, 0, 0, 0, 10, @CGUID+66, 186361, 0, 0, 0, 0, 0, 'OOC after 1s - cast "Channel: Decay to Target [DNT]" - to Rotting Treant'),
(-(@CGUID+33), 0, 0, 0, 1, 0, 100, 1, 1000, 1000, 0, 0, 11, 371632, 3, 0, 0, 0, 0, 10, @CGUID+22, 186361, 0, 0, 0, 0, 0, 'OOC after 1s - cast "Channel: Decay to Target [DNT]" - to Rotting Treant'),
(-(@CGUID+93), 0, 0, 0, 1, 0, 100, 1, 1000, 1000, 0, 0, 11, 371632, 3, 0, 0, 0, 0, 10, @CGUID+69, 186361, 0, 0, 0, 0, 0, 'OOC after 1s - cast "Channel: Decay to Target [DNT]" - to Rotting Treant');

-- Waypoints for CGUID+289
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+289;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+289, @CGUID+289, 0, 0, 515, 0, 0),
(@CGUID+289, @CGUID+287, 5, 0, 515, 0, 0);

SET @PATH := (@CGUID+289) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3301.153, 3281.348, 293.5553, NULL, 0),
(@PATH, 1, -3281.96, 3267.584, 298.048, NULL, 0),
(@PATH, 2, -3262.705, 3272.689, 300.8335, NULL, 10449),
(@PATH, 3, -3281.96, 3267.584, 298.048, NULL, 0),
(@PATH, 4, -3301.153, 3281.348, 293.5553, NULL, 0),
(@PATH, 5, -3322.984, 3288.247, 288.0433, NULL, 0),
(@PATH, 6, -3334.321, 3274.076, 287.7037, NULL, 0),
(@PATH, 7, -3343.521, 3263.768, 284.7176, NULL, 10871),
(@PATH, 8, -3334.321, 3274.076, 287.7037, NULL, 0),
(@PATH, 9, -3322.984, 3288.247, 288.0433, NULL, 0);

UPDATE `creature` SET `position_x`= -3301.153, `position_y`= 3281.348, `position_z`= 293.5553, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+289;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+289;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+289, @PATH, 1);

-- Waypoints for CGUID+9
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+9;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+9, @CGUID+9, 0, 0, 515, 0, 0),
(@CGUID+9, @CGUID+352, 4, 0, 515, 0, 0),
(@CGUID+9, @CGUID+358, 4, 90, 515, 4, 9);

SET @PATH := (@CGUID+9) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3437.733, 3424.139, 273.6657, NULL, 0),
(@PATH, 1, -3453.009, 3432.015, 272.8378, NULL, 0),
(@PATH, 2, -3465.896, 3442.83, 272.3782, NULL, 0),
(@PATH, 3, -3475.505, 3453.327, 271.8084, NULL, 0),
(@PATH, 4, -3487.068, 3465.604, 272.1452, NULL, 0),
(@PATH, 5, -3493.62, 3470.936, 272.058, NULL, 0),
(@PATH, 6, -3487.068, 3465.604, 272.1452, NULL, 0),
(@PATH, 7, -3475.505, 3453.327, 271.8084, NULL, 0),
(@PATH, 8, -3465.896, 3442.83, 272.3782, NULL, 0),
(@PATH, 9, -3453.009, 3432.015, 272.8378, NULL, 0);

UPDATE `creature` SET `position_x`= -3437.733, `position_y`= 3424.139, `position_z`= 273.6657, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+9;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+9;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+9, @PATH, 1);

-- Waypoints for CGUID+1
SET @PATH := (@CGUID+1) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3485.436, 3425.747, 273.7197, NULL, 8147),
(@PATH, 1, -3488.734, 3430.269, 273.7197, NULL, 0),
(@PATH, 2, -3491.595, 3433.137, 273.7197, NULL, 0),
(@PATH, 3, -3495.719, 3434.07, 273.7702, NULL, 2942),
(@PATH, 4, -3494.853, 3428.885, 273.7197, NULL, 0),
(@PATH, 5, -3494.396, 3425.063, 273.8997, NULL, 0),
(@PATH, 6, -3494.96, 3423.958, 273.8447, NULL, 7911);

UPDATE `creature` SET `position_x`= -3485.436, `position_y`= 3425.747, `position_z`= 273.7197, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+1;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+1;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+1, @PATH, 1);

-- Waypoints for CGUID+31
SET @PATH := (@CGUID+31) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3529.795, 3519.662, 273.1397, NULL, 0),
(@PATH, 1, -3527.99, 3509.519, 272.1725, NULL, 0),
(@PATH, 2, -3522.901, 3504.253, 271.6657, NULL, 0),
(@PATH, 3, -3514.698, 3501.004, 271.6415, NULL, 10393),
(@PATH, 4, -3522.901, 3504.253, 271.6657, NULL, 0),
(@PATH, 5, -3527.99, 3509.519, 272.1725, NULL, 0),
(@PATH, 6, -3529.795, 3519.662, 273.1397, NULL, 0),
(@PATH, 7, -3532.281, 3533.604, 272.7277, NULL, 15405);

UPDATE `creature` SET `position_x`= -3529.795, `position_y`= 3519.662, `position_z`= 273.1397, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+31;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+31;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+31, @PATH, 1);

-- Waypoints for CGUID+34
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+34;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+34, @CGUID+34, 0, 0, 515, 0, 0),
(@CGUID+34, @CGUID+368, 4, 0, 515, 0, 0),
(@CGUID+34, @CGUID+367, 4, 270, 515, 4, 9);

SET @PATH := (@CGUID+34) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3585.017, 3400.721, 253.7196, NULL, 300),
(@PATH, 1, -3593.394, 3395.119, 254.8006, NULL, 0),
(@PATH, 2, -3602.516, 3385.462, 253.1001, NULL, 0),
(@PATH, 3, -3605.134, 3378.008, 253.6034, NULL, 0),
(@PATH, 4, -3606.908, 3372.839, 254.5602, NULL, 0),
(@PATH, 5, -3605.134, 3378.008, 253.6034, NULL, 0),
(@PATH, 6, -3602.516, 3385.462, 253.1001, NULL, 0),
(@PATH, 7, -3593.394, 3395.119, 254.8006, NULL, 0);

UPDATE `creature` SET `position_x`= -3585.017, `position_y`= 3400.721, `position_z`= 253.7196, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+34;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+34;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+34, @PATH, 1);

-- Waypoints for CGUID+75
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+75;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+75, @CGUID+75, 0, 0, 515, 0, 0),
(@CGUID+75, @CGUID+62, 3, 90, 515, 0, 0);

SET @PATH := (@CGUID+75) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3601.314, 3607.458, 214.2122, NULL, 0),
(@PATH, 1, -3600.106, 3599.446, 214.43, NULL, 0),
(@PATH, 2, -3604.538, 3594.458, 212.0033, NULL, 0),
(@PATH, 3, -3609.878, 3589.01, 208.4115, NULL, 10281),
(@PATH, 4, -3604.538, 3594.458, 212.0033, NULL, 0),
(@PATH, 5, -3600.106, 3599.446, 214.43, NULL, 0),
(@PATH, 6, -3601.314, 3607.458, 214.2122, NULL, 0),
(@PATH, 7, -3601.526, 3617.973, 215.1604, NULL, 0),
(@PATH, 8, -3600.62, 3622.392, 215.9202, NULL, 6186),
(@PATH, 9, -3601.526, 3617.973, 215.1604, NULL, 0);

UPDATE `creature` SET `position_x`= -3601.314, `position_y`= 3607.458, `position_z`= 214.2122, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+75;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+75;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+75, @PATH, 1);

-- Waypoints for CGUID+95
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+95;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+95, @CGUID+95, 0, 0, 515, 0, 0),
(@CGUID+95, @CGUID+70, 3, 90, 515, 0, 0);

SET @PATH := (@CGUID+95) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3667.911, 3607.559, 196.1429, NULL, 0),
(@PATH, 1, -3659.363, 3610.09, 198.5289, NULL, 0),
(@PATH, 2, -3653.392, 3612.788, 200.7381, NULL, 0),
(@PATH, 3, -3647.709, 3614.698, 203.27, NULL, 7603),
(@PATH, 4, -3653.392, 3612.788, 200.7381, NULL, 0),
(@PATH, 5, -3659.363, 3610.09, 198.5289, NULL, 0),
(@PATH, 6, -3667.911, 3607.559, 196.1429, NULL, 0),
(@PATH, 7, -3675.165, 3605.073, 191.8009, NULL, 10355);

UPDATE `creature` SET `position_x`= -3667.911, `position_y`= 3607.559, `position_z`= 196.1429, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+95;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+95;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+95, @PATH, 1);

-- Waypoints for CGUID+56
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+56;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+56, @CGUID+56, 0, 0, 515, 0, 0),
(@CGUID+56, @CGUID+45, 3, 90, 515, 0, 0);

SET @PATH := (@CGUID+56) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3665.728, 3579.786, 191.6043, NULL, 0),
(@PATH, 1, -3659.394, 3567.85, 193.1215, NULL, 0),
(@PATH, 2, -3658.432, 3556.034, 194.8838, NULL, 0),
(@PATH, 3, -3657.58, 3546.383, 195.4204, NULL, 0),
(@PATH, 4, -3658.913, 3532.666, 195.5959, NULL, 10389),
(@PATH, 5, -3657.58, 3546.383, 195.4204, NULL, 0),
(@PATH, 6, -3658.432, 3556.034, 194.8838, NULL, 0),
(@PATH, 7, -3659.394, 3567.85, 193.1215, NULL, 0),
(@PATH, 8, -3665.728, 3579.786, 191.6043, NULL, 0),
(@PATH, 9, -3671.835, 3588.481, 190.5246, NULL, 0),
(@PATH, 10, -3690.285, 3596.095, 187.5607, NULL, 6754),
(@PATH, 11, -3671.835, 3588.481, 190.5246, NULL, 0);

UPDATE `creature` SET `position_x`= -3665.728, `position_y`= 3579.786, `position_z`= 191.6043, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+56;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+56;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+56, @PATH, 1);

-- Waypoints for CGUID+80
SET @PATH := (@CGUID+80) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3726.304, 3597.602, 186.7451, NULL, 0),
(@PATH, 1, -3726.618, 3592.274, 186.7451, NULL, 0),
(@PATH, 2, -3725.559, 3590.085, 186.7451, NULL, 0),
(@PATH, 3, -3723.632, 3587.31, 186.7451, NULL, 0),
(@PATH, 4, -3722.603, 3586.843, 186.7451, NULL, 6478),
(@PATH, 5, -3724.797, 3605.195, 186.6821, NULL, 6043);

UPDATE `creature` SET `position_x`= -3726.304, `position_y`= 3597.602, `position_z`= 186.7451, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+80;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+80;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+80, @PATH, 1);

-- Waypoints for CGUID+35
SET @PATH := (@CGUID+35) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3595.651, 3449.667, 197.3913, NULL, 0),
(@PATH, 1, -3597.253, 3445.1, 197.3603, NULL, 0),
(@PATH, 2, -3600.873, 3437.014, 196.8132, NULL, 0),
(@PATH, 3, -3603.663, 3434.269, 197.7825, NULL, 0),
(@PATH, 4, -3592.181, 3463.445, 197.4077, NULL, 12077);

UPDATE `creature` SET `position_x`= -3595.651, `position_y`= 3449.667, `position_z`= 197.3913, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+35;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+35;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+35, @PATH, 1);

-- Waypoints for CGUID+82
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+82;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+82, @CGUID+82, 0, 0, 515, 0, 0),
(@CGUID+82, @CGUID+370, 4, 300, 515, 0, 0),
(@CGUID+82, @CGUID+369, 4, 60, 515, 0, 0);

SET @PATH := (@CGUID+82) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3701.103, 3673.68, 168.2738, NULL, 0),
(@PATH, 1, -3699.536, 3667.16, 169.5757, NULL, 0),
(@PATH, 2, -3698.53, 3657.661, 172.3544, NULL, 0),
(@PATH, 3, -3697.075, 3639.425, 178.0491, NULL, 0),
(@PATH, 4, -3698.53, 3657.661, 172.3544, NULL, 0),
(@PATH, 5, -3699.536, 3667.16, 169.5757, NULL, 0);

UPDATE `creature` SET `position_x`= -3701.103, `position_y`= 3673.68, `position_z`= 168.2738, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+82;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+82;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+82, @PATH, 1);

-- Waypoints for CGUID+188
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+188;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+188, @CGUID+188, 0, 0, 515, 0, 0),
(@CGUID+188, @CGUID+379, 4, 300, 515, 0, 0),
(@CGUID+188, @CGUID+380, 4, 60, 515, 0, 0);

SET @PATH := (@CGUID+188) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3722.543, 3752.512, 156.0006, NULL, 0),
(@PATH, 1, -3723.688, 3745.245, 157.5194, NULL, 0),
(@PATH, 2, -3725.594, 3736.718, 158.452, NULL, 193),
(@PATH, 10, -3723.688, 3745.245, 157.5194, NULL, 0),
(@PATH, 11, -3722.543, 3752.512, 156.0006, NULL, 0),
(@PATH, 12, -3715.858, 3761.587, 153.1709, NULL, 0),
(@PATH, 13, -3707.53, 3770.556, 149.4313, NULL, 0),
(@PATH, 14, -3701.375, 3774.517, 146.7491, NULL, 21215),
(@PATH, 15, -3715.858, 3761.587, 153.1709, NULL, 0);

UPDATE `creature` SET `position_x`= -3722.543, `position_y`= 3752.512, `position_z`= 156.0006, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+188;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+188;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+188, @PATH, 1);

-- Waypoints for CGUID+393
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+393;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+393, @CGUID+393, 0, 0, 515, 0, 0),
(@CGUID+393, @CGUID+396, 4, 300, 515, 0, 0),
(@CGUID+393, @CGUID+395, 4, 60, 515, 0, 0);

SET @PATH := (@CGUID+393) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3736.57, 3331.27, 187.4087, NULL, 0),
(@PATH, 1, -3745.51, 3342.944, 186.3947, NULL, 0),
(@PATH, 2, -3754.615, 3355.125, 185.5948, NULL, 0),
(@PATH, 3, -3750.674, 3369.812, 187.0651, NULL, 0),
(@PATH, 4, -3740.957, 3379.691, 189.3744, NULL, 0),
(@PATH, 5, -3723.365, 3373.287, 189.7154, NULL, 0),
(@PATH, 6, -3704.972, 3353.952, 192.2967, NULL, 0),
(@PATH, 7, -3686.155, 3334.682, 195.2742, NULL, 0),
(@PATH, 8, -3673.519, 3315.968, 199.1388, NULL, 0),
(@PATH, 9, -3671.738, 3304.782, 201.3967, NULL, 0),
(@PATH, 10, -3681.793, 3303.139, 198.0477, NULL, 0),
(@PATH, 11, -3688.002, 3302.358, 197.0277, NULL, 0),
(@PATH, 12, -3702.33, 3308.531, 193.1773, NULL, 0),
(@PATH, 13, -3728.417, 3320.944, 187.6648, NULL, 0);

UPDATE `creature` SET `position_x`= -3736.57, `position_y`= 3331.27, `position_z`= 187.4087, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+393;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+393;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+393, @PATH, 1);
