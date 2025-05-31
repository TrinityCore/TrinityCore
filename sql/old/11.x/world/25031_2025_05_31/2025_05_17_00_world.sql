SET @CGUID := 7003102;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+66;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 128852, 1643, 8721, 8721, '0', 0, 0, 0, 0, -1101.279541015625, 1526.560791015625, 36.560394287109375, 5.405164718627929687, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Chillwind Hawk (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+1, 129742, 1643, 8721, 8721, '0', 0, 0, 0, 0, -997.8819580078125, 1461.5711669921875, 23.70985984802246093, 3.050514936447143554, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Tufted Craghopper (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+2, 128942, 1643, 8721, 8721, '0', 0, 0, 0, 0, -1039.9288330078125, 1373.829833984375, -2.7029430866241455, 5.165212631225585937, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Mudfisher Crab (Area: Drustvar - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+3, 128514, 1643, 8721, 8721, '0', 0, 0, 0, 0, -1041.6822509765625, 1381.7847900390625, 0.442927122116088867, 3.460510969161987304, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Harbor Scuttler (Area: Drustvar - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+4, 129137, 1643, 8721, 8721, '0', 0, 0, 0, 0, -1018.58331298828125, 1434.8160400390625, 12.22302436828613281, 2.531750440597534179, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Thicket Hare (Area: Drustvar - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+5, 128514, 1643, 8721, 8721, '0', 0, 0, 0, 0, -1061.173583984375, 1383.1285400390625, -4.71299505233764648, 3.03555917739868164, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Harbor Scuttler (Area: Drustvar - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+6, 128514, 1643, 8721, 8721, '0', 0, 0, 0, 0, -1087.796875, 1421.6492919921875, -2.13665771484375, 2.214028835296630859, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Harbor Scuttler (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+7, 130165, 1643, 8721, 8721, '0', 0, 0, 0, 0, -1047.62158203125, 1422.451416015625, 6.30100870132446289, 5.54833984375, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Highland Shoat (Area: Drustvar - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+8, 128942, 1643, 8721, 8721, '0', 0, 0, 0, 0, -1076.4774169921875, 1413.2916259765625, 0.67728358507156372, 2.150474071502685546, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Mudfisher Crab (Area: Drustvar - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+9, 128942, 1643, 8721, 8721, '0', 0, 0, 0, 0, -1072.4305419921875, 1399.9913330078125, -4.44092416763305664, 0.338947683572769165, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Mudfisher Crab (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+10, 128942, 1643, 8721, 8721, '0', 0, 0, 0, 0, -1059.65625, 1373.0208740234375, -5.96793413162231445, 0.132895052433013916, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Mudfisher Crab (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+11, 128942, 1643, 8721, 8721, '0', 0, 0, 0, 0, -1087.3194580078125, 1431.954833984375, 1.068525314331054687, 0.500985324382781982, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Mudfisher Crab (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+12, 128514, 1643, 8721, 8721, '0', 0, 0, 0, 0, -1058.90283203125, 1406.048583984375, 1.680335640907287597, 6.070624828338623046, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Harbor Scuttler (Area: Drustvar - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+13, 130165, 1643, 8721, 8721, '0', 0, 0, 0, 0, -1033.8367919921875, 1423.092041015625, 8.485143661499023437, 2.447469949722290039, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Highland Shoat (Area: Drustvar - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+14, 128942, 1643, 8721, 8721, '0', 0, 0, 0, 0, -1031.2413330078125, 1383.3802490234375, 0.657243669033050537, 0, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Mudfisher Crab (Area: Drustvar - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+15, 130164, 1643, 8721, 8721, '0', 0, 0, 0, 0, -990.57293701171875, 1435.94970703125, 17.33228302001953125, 4.078789234161376953, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Highland Boar (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+16, 128514, 1643, 8721, 8721, '0', 0, 0, 0, 0, -1020.56951904296875, 1378.52783203125, 0.149613857269287109, 0.942261934280395507, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Harbor Scuttler (Area: Drustvar - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+17, 128852, 1643, 8721, 8721, '0', 0, 0, 0, 0, -1060.751708984375, 1449.6129150390625, 30.56997108459472656, 5.768587112426757812, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Chillwind Hawk (Area: Drustvar - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+18, 128942, 1643, 8721, 8721, '0', 0, 0, 0, 0, -1063.2135009765625, 1396.3385009765625, 0.785998463630676269, 2.988494634628295898, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Mudfisher Crab (Area: Drustvar - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+19, 128514, 1643, 8721, 8721, '0', 0, 0, 0, 0, -1078.75, 1423.625, 1.76069796085357666, 5.395291805267333984, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Harbor Scuttler (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+20, 128514, 1643, 8721, 8721, '0', 0, 0, 0, 0, -1047.68408203125, 1392.640625, 1.01152968406677246, 6.142151355743408203, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Harbor Scuttler (Area: Drustvar - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+21, 129137, 1643, 8721, 8721, '0', 0, 0, 0, 0, -1060.6285400390625, 1470.1822509765625, 23.92616653442382812, 4.541197776794433593, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Thicket Hare (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+22, 129137, 1643, 8721, 8721, '0', 0, 0, 0, 0, -1042.1805419921875, 1425.9375, 7.8901824951171875, 2.716684341430664062, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Thicket Hare (Area: Drustvar - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+23, 128514, 1643, 8721, 8721, '0', 0, 0, 0, 0, -1054.361083984375, 1382.0711669921875, -4.04753589630126953, 0.333368510007858276, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Harbor Scuttler (Area: Drustvar - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+24, 128514, 1643, 8721, 8721, '0', 0, 0, 0, 0, -1093.8541259765625, 1438.717041015625, -0.31897640228271484, 5.383021354675292968, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Harbor Scuttler (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+25, 128942, 1643, 8721, 8721, '0', 0, 0, 0, 0, -1022.75, 1370.142333984375, -3.24950790405273437, 0, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Mudfisher Crab (Area: Drustvar - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+26, 130164, 1643, 8721, 8721, '0', 0, 0, 0, 0, -1045.6614990234375, 1431.76220703125, 7.685554027557373046, 5.729505538940429687, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Highland Boar (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+27, 128514, 1643, 8721, 8721, '0', 0, 0, 0, 0, -1008.8350830078125, 1378.15625, 0.366561830043792724, 0.510446369647979736, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Harbor Scuttler (Area: Drustvar - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+28, 128514, 1643, 8721, 8721, '0', 0, 0, 0, 0, -1080.5260009765625, 1407.329833984375, -3.36807775497436523, 5.471147060394287109, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Harbor Scuttler (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+29, 130165, 1643, 8721, 8721, '0', 0, 0, 0, 0, -988.8836669921875, 1428.907958984375, 15.50868034362792968, 0.592059791088104248, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Highland Shoat (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+30, 128514, 1643, 8721, 8721, '0', 0, 0, 0, 0, -1032.095458984375, 1364.857666015625, -5.64109086990356445, 1.637494325637817382, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Harbor Scuttler (Area: Drustvar - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+31, 128942, 1643, 8721, 8721, '0', 0, 0, 0, 0, -999.140625, 1371.9322509765625, -2.17953872680664062, 2.161304950714111328, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Mudfisher Crab (Area: Drustvar - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+32, 130165, 1643, 8721, 8721, '0', 0, 0, 0, 0, -985.61114501953125, 1438.920166015625, 17.68923759460449218, 0.39018559455871582, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Highland Shoat (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+33, 128942, 1643, 8721, 8721, '0', 0, 0, 0, 0, -972.46875, 1372.7274169921875, 0.394844025373458862, 2.683954238891601562, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Mudfisher Crab (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+34, 128514, 1643, 8721, 8721, '0', 0, 0, 0, 0, -988.2899169921875, 1376.2882080078125, 0.457174271345138549, 0, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Harbor Scuttler (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+35, 128942, 1643, 8721, 8721, '0', 0, 0, 0, 0, -986.04168701171875, 1363.9427490234375, -3.4034433364868164, 2.611755132675170898, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Mudfisher Crab (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+36, 130164, 1643, 8721, 8721, '0', 0, 0, 0, 0, -910.10418701171875, 1456.595458984375, 27.5326690673828125, 0.307439565658569335, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Highland Boar (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+37, 129137, 1643, 8721, 8721, '0', 0, 0, 0, 0, -975.88018798828125, 1405.7864990234375, 10.96509647369384765, 3.12732100486755371, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Thicket Hare (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+38, 129137, 1643, 8721, 8721, '0', 0, 0, 0, 0, -933.623291015625, 1429.953125, 18.17682838439941406, 2.296607494354248046, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Thicket Hare (Area: Drustvar - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+39, 128514, 1643, 8721, 8721, '0', 0, 0, 0, 0, -971.30731201171875, 1365.9288330078125, -2.19083452224731445, 3.480356931686401367, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Harbor Scuttler (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+40, 130165, 1643, 8721, 8721, '0', 0, 0, 0, 0, -895.71527099609375, 1416.6666259765625, 18.69803619384765625, 0.009151108562946319, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Highland Shoat (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+41, 130165, 1643, 8721, 8721, '0', 0, 0, 0, 0, -950.73614501953125, 1435.9375, 19.5636749267578125, 2.589713811874389648, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Highland Shoat (Area: Drustvar - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+42, 130164, 1643, 8721, 8721, '0', 0, 0, 0, 0, -943.66143798828125, 1436.3472900390625, 19.26559638977050781, 4.042464733123779296, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Highland Boar (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+43, 130164, 1643, 8721, 8721, '0', 0, 0, 0, 0, -883.29864501953125, 1412.376708984375, 20.33932685852050781, 3.38025665283203125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Highland Boar (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+44, 130164, 1643, 8721, 8721, '0', 0, 0, 0, 0, -935.8055419921875, 1420.3211669921875, 15.8992156982421875, 2.296503543853759765, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Highland Boar (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+45, 130165, 1643, 8721, 8721, '0', 0, 0, 0, 0, -905.890625, 1449.6944580078125, 26.32946968078613281, 3.434979438781738281, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Highland Shoat (Area: Drustvar - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+46, 130164, 1643, 8721, 8721, '0', 0, 0, 0, 0, -877.75177001953125, 1449.73095703125, 32.3828887939453125, 2.35506749153137207, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Highland Boar (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+47, 130165, 1643, 8721, 8721, '0', 0, 0, 0, 0, -945.078125, 1415.78125, 15.9852752685546875, 0.411179393529891967, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Highland Shoat (Area: Drustvar - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+48, 129137, 1643, 8721, 8721, '0', 0, 0, 0, 0, -906.779541015625, 1406.064208984375, 15.71494483947753906, 3.142325401306152343, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Thicket Hare (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+49, 130165, 1643, 8721, 8721, '0', 0, 0, 0, 0, -895.9757080078125, 1459.46533203125, 29.84681320190429687, 1.416689395904541015, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Highland Shoat (Area: Drustvar - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+50, 130164, 1643, 8721, 8721, '0', 0, 0, 0, 0, -881.34722900390625, 1388.609375, 15.18735408782958984, 2.740431070327758789, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Highland Boar (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+51, 130165, 1643, 8721, 8721, '0', 0, 0, 0, 0, -903.83331298828125, 1381.2066650390625, 9.255526542663574218, 2.545813322067260742, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Highland Shoat (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+52, 129137, 1643, 8721, 8721, '0', 0, 0, 0, 0, -929.904541015625, 1380.8228759765625, 6.918349266052246093, 4.255349159240722656, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Thicket Hare (Area: Drustvar - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+53, 126353, 1643, 8721, 8721, '0', 0, 0, 0, 0, -857.953125, 1434.01220703125, 37.61176300048828125, 1.856121659278869628, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Woodland Bat (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+54, 130165, 1643, 8721, 8721, '0', 0, 0, 0, 0, -890.467041015625, 1416.8021240234375, 19.56219100952148437, 5.336143016815185546, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Highland Shoat (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+55, 129137, 1643, 8721, 8721, '0', 0, 0, 0, 0, -887.4913330078125, 1448.296875, 29.86265182495117187, 0.421812474727630615, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Thicket Hare (Area: Drustvar - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+56, 130164, 1643, 8721, 8721, '0', 0, 0, 0, 0, -898.5850830078125, 1411.795166015625, 17.55295944213867187, 6.213160037994384765, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Highland Boar (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+57, 129137, 1643, 8721, 8721, '0', 0, 0, 0, 0, -914.6649169921875, 1389.8507080078125, 9.997943878173828125, 4.390542030334472656, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Thicket Hare (Area: Drustvar - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+58, 130165, 1643, 8721, 8721, '0', 0, 0, 0, 0, -903.43231201171875, 1390.6180419921875, 12.30180072784423828, 0.525454044342041015, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Highland Shoat (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+59, 130165, 1643, 8721, 8721, '0', 0, 0, 0, 0, -883.328125, 1417.0728759765625, 21.18095588684082031, 5.807631492614746093, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Highland Shoat (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+60, 130164, 1643, 8721, 8721, '0', 0, 0, 0, 0, -895.59893798828125, 1380.013916015625, 9.900560379028320312, 0.733271598815917968, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Highland Boar (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+61, 130164, 1643, 8721, 8721, '0', 0, 0, 0, 0, -905.4617919921875, 1407.1285400390625, 15.99933719635009765, 1.845413804054260253, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Highland Boar (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+62, 130165, 1643, 8721, 8721, '0', 0, 0, 0, 0, -805.6163330078125, 1411.4739990234375, 27.97595977783203125, 2.258482694625854492, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Highland Shoat (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+63, 126353, 1643, 8721, 8721, '0', 0, 0, 0, 0, -803.08160400390625, 1406.829833984375, 33.10757827758789062, 3.6516876220703125, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 60822), -- Woodland Bat (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+64, 130164, 1643, 8721, 8721, '0', 0, 0, 0, 0, -799.8975830078125, 1414.66845703125, 28.92756271362304687, 4.15377044677734375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Highland Boar (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+65, 130164, 1643, 8721, 8721, '0', 0, 0, 0, 0, -851.19097900390625, 1378.185791015625, 16.65465164184570312, 1.28998565673828125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60822), -- Highland Boar (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+66, 129137, 1643, 8721, 8721, '0', 0, 0, 0, 0, -855.48614501953125, 1413.25, 23.42002105712890625, 0.278598368167877197, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60822); -- Thicket Hare (Area: Drustvar - Difficulty: 0) CreateObject2

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+66;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Chillwind Hawk

-- Path for Chillwind Hawk
SET @MOVERGUID := @CGUID+17;
SET @ENTRY := 128852;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 8.5486, 'Chillwind Hawk - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1043.7693, 1440.0109, 30.569971, NULL, 0),
(@PATH, 1, -1031.7542, 1424.6407, 30.569971, NULL, 0),
(@PATH, 2, -1026.5354, 1405.8427, 30.569971, NULL, 0),
(@PATH, 3, -1028.9077, 1386.4784, 30.569971, NULL, 0),
(@PATH, 4, -1038.5098, 1369.496, 30.569971, NULL, 0),
(@PATH, 5, -1053.8798, 1357.4808, 30.569971, NULL, 0),
(@PATH, 6, -1072.6779, 1352.2622, 30.569971, NULL, 0),
(@PATH, 7, -1092.0421, 1354.6345, 30.569971, NULL, 0),
(@PATH, 8, -1109.0245, 1364.2366, 30.569971, NULL, 0),
(@PATH, 9, -1121.0397, 1379.6066, 30.569971, NULL, 0),
(@PATH, 10, -1126.2584, 1398.4047, 30.569971, NULL, 0),
(@PATH, 11, -1123.8861, 1417.7689, 30.569971, NULL, 0),
(@PATH, 12, -1114.284, 1434.7513, 30.569971, NULL, 0),
(@PATH, 13, -1098.9141, 1446.7665, 30.569971, NULL, 0),
(@PATH, 14, -1080.116, 1451.9852, 30.569971, NULL, 0),
(@PATH, 15, -1060.7517, 1449.6129, 30.569971, NULL, 0),
(@PATH, 16, -1043.7693, 1440.0109, 30.569971, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Tufted Craghopper
SET @MOVERGUID := @CGUID+1;
SET @ENTRY := 129742;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x1, NULL, 'Tufted Craghopper - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -986.9514, 1460.5729, 23.65818, NULL, 0),
(@PATH, 1, -997.88196, 1461.5712, 23.70986, NULL, 0),
(@PATH, 2, -1008.8125, 1462.5695, 23.76154, NULL, 0),
(@PATH, 3, -1017.8507, 1463.6754, 24.428148, NULL, 0),
(@PATH, 4, -1022.9063, 1465.7935, 24.762861, NULL, 0),
(@PATH, 5, -1032.3993, 1471.9358, 25.776041, NULL, 0),
(@PATH, 6, -1037.7899, 1476.2031, 29.042372, NULL, 0),
(@PATH, 7, -1042.0817, 1481.0521, 32.48264, NULL, 0),
(@PATH, 8, -1046.1788, 1486.2656, 35.895527, NULL, 0),
(@PATH, 9, -1052.7048, 1497.7726, 40.64757, NULL, 0),
(@PATH, 10, -1055.6077, 1502.3872, 41.949654, NULL, 0),
(@PATH, 11, -1062.8906, 1512.9358, 43.95702, NULL, 0),
(@PATH, 12, -1066.316, 1516.3264, 43.939236, NULL, 0),
(@PATH, 13, -1072.0521, 1520.7692, 43.713543, NULL, 0),
(@PATH, 14, -1076.7552, 1527.3698, 42.62804, NULL, 0),
(@PATH, 15, -1080.5382, 1531.8733, 41.979168, NULL, 0),
(@PATH, 16, -1084.3629, 1533.5435, 40.73977, NULL, 0),
(@PATH, 17, -1096.625, 1538.1423, 40.578846, NULL, 0),
(@PATH, 18, -1103.5729, 1540.217, 44.314236, NULL, 0),
(@PATH, 19, -1112.8767, 1545.0817, 52.48595, NULL, 0),
(@PATH, 20, -1121.0555, 1545.4219, 57.977432, NULL, 0),
(@PATH, 21, -1130.8698, 1544.8091, 64.11979, NULL, 0),
(@PATH, 22, -1137.3438, 1545.217, 68.0816, NULL, 0),
(@PATH, 23, -1142.0156, 1545.5573, 71.03299, NULL, 0),
(@PATH, 24, -1149.1007, 1549.316, 75.578125, NULL, 0),
(@PATH, 25, -1156.2622, 1553.8021, 79.80382, NULL, 0),
(@PATH, 26, -1162.1545, 1550.3438, 81.35261, NULL, 0),
(@PATH, 27, -1166.6841, 1546.8993, 82.77431, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Highland Boar
SET @MOVERGUID := @CGUID+61;
SET @ENTRY := 130164;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Highland Boar - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -905.2344, 1420.776, 20.032576, NULL, 0),
(@PATH, 1, -900.74133, 1424.6423, 21.212202, NULL, 0),
(@PATH, 2, -892.9514, 1427.0435, 22.281239, NULL, 0),
(@PATH, 3, -887.10767, 1426.9185, 23.234447, NULL, 0),
(@PATH, 4, -881.0816, 1422.8663, 23.18728, NULL, 0),
(@PATH, 5, -873.6667, 1417.092, 22.715973, NULL, 0),
(@PATH, 6, -871.9983, 1408.4896, 20.290607, NULL, 0),
(@PATH, 7, -874.2535, 1404.0955, 19.05657, NULL, 15935),
(@PATH, 8, -871.9983, 1408.4896, 20.290607, NULL, 0),
(@PATH, 9, -873.6667, 1417.092, 22.715973, NULL, 0),
(@PATH, 10, -881.0816, 1422.8663, 23.18728, NULL, 0),
(@PATH, 11, -887.10767, 1426.9185, 23.234447, NULL, 0),
(@PATH, 12, -892.9514, 1427.0435, 22.281239, NULL, 0),
(@PATH, 13, -900.74133, 1424.6423, 21.212202, NULL, 0),
(@PATH, 14, -905.2344, 1420.776, 20.032576, NULL, 0),
(@PATH, 15, -906.7344, 1411.6354, 16.79881, NULL, 0),
(@PATH, 16, -905.80035, 1407.3177, 15.851196, NULL, 16044),
(@PATH, 17, -906.7344, 1411.6354, 16.79881, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
