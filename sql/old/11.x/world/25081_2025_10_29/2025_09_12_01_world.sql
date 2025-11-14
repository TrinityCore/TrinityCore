SET @CGUID := 7003479;
SET @ATID := 164;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+109;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 126151, 1643, 8721, 9170, '0', 0, 0, 0, 0, -1020.3870849609375, 1221.982666015625, 7.634742259979248046, 0.703608155250549316, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Curseformed Familiar (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+1, 126151, 1643, 8721, 9170, '0', 0, 0, 0, 0, -983.44097900390625, 1178.095458984375, 7.858855724334716796, 4.287909984588623046, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Curseformed Familiar (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+2, 126151, 1643, 8721, 9170, '0', 0, 0, 0, 0, -1040.21875, 1198.546875, 5.367901802062988281, 0.095402948558330535, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Curseformed Familiar (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+3, 126151, 1643, 8721, 9170, '0', 0, 0, 0, 0, -955.47052001953125, 1212.6492919921875, 6.110913276672363281, 1.060926198959350585, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Curseformed Familiar (Area: Timbered Strand - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+4, 128937, 1643, 8721, 9170, '0', 0, 0, 0, 0, -1012.373291015625, 1236.857666015625, 6.793526649475097656, 3.041042327880859375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Scavenging Raven (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+5, 128937, 1643, 8721, 9170, '0', 0, 0, 0, 0, -1011.02081298828125, 1232.49658203125, 10.24453163146972656, 1.600046396255493164, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Scavenging Raven (Area: Timbered Strand - Difficulty: 0) CreateObject2 (Auras: 258247 - Perched)
(@CGUID+6, 130127, 1643, 8721, 9170, '0', 0, 0, 0, 0, -949.748291015625, 1187.0521240234375, 9.037817955017089843, 5.145512580871582031, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Forest Viper (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+7, 128937, 1643, 8721, 9170, '0', 0, 0, 0, 0, -1015.5521240234375, 1238.2291259765625, 6.187700748443603515, 4.95774698257446289, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Scavenging Raven (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+8, 130127, 1643, 8721, 9170, '0', 0, 0, 0, 0, -953.37152099609375, 1217.4913330078125, 6.377184867858886718, 2.182572841644287109, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Forest Viper (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+9, 130127, 1643, 8721, 9170, '0', 0, 0, 0, 0, -982.72052001953125, 1165.54345703125, 8.447155952453613281, 2.139708518981933593, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Forest Viper (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+10, 130127, 1643, 8721, 9170, '0', 0, 0, 0, 0, -959.6024169921875, 1147.1024169921875, 7.485082149505615234, 0.712646305561065673, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Forest Viper (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+11, 128937, 1643, 8721, 9170, '0', 0, 0, 0, 0, -1055.2117919921875, 1204.24658203125, 7.066392421722412109, 0.561177015304565429, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Scavenging Raven (Area: Timbered Strand - Difficulty: 0) CreateObject2 (Auras: 258247 - Perched)
(@CGUID+12, 128937, 1643, 8721, 9170, '0', 0, 0, 0, 0, -992.76739501953125, 1191.767333984375, 6.896556854248046875, 5.020402908325195312, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Scavenging Raven (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+13, 128937, 1643, 8721, 9170, '0', 0, 0, 0, 0, -996.513916015625, 1160.2135009765625, 17.259246826171875, 0.812970399856567382, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Scavenging Raven (Area: Timbered Strand - Difficulty: 0) CreateObject2 (Auras: 258247 - Perched)
(@CGUID+14, 130127, 1643, 8721, 9170, '0', 0, 0, 0, 0, -997.52777099609375, 1175.2100830078125, 8.040829658508300781, 1.032315015792846679, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Forest Viper (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+15, 126151, 1643, 8721, 9170, '0', 0, 0, 0, 0, -949.1788330078125, 1180.4461669921875, 10.10540962219238281, 0.236816823482513427, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Curseformed Familiar (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+16, 128942, 1643, 8721, 9170, '0', 0, 0, 0, 0, -907.2725830078125, 1233.5728759765625, 1.16168975830078125, 1.737533211708068847, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Mudfisher Crab (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+17, 130127, 1643, 8721, 9170, '0', 0, 0, 0, 0, -1007.43231201171875, 1236.3941650390625, 7.094191551208496093, 3.209064722061157226, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Forest Viper (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+18, 130127, 1643, 8721, 9170, '0', 0, 0, 0, 0, -1028.7586669921875, 1205.4757080078125, 5.778281211853027343, 5.591036796569824218, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Forest Viper (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+19, 128942, 1643, 8721, 9170, '0', 0, 0, 0, 0, -934.015625, 1262.4427490234375, 0.187540203332901, 2.489169120788574218, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Mudfisher Crab (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+20, 128937, 1643, 8721, 9170, '0', 0, 0, 0, 0, -1051.6961669921875, 1206.90625, 5.47492074966430664, 2.058684110641479492, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Scavenging Raven (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+21, 126151, 1643, 8721, 9170, '0', 0, 0, 0, 0, -972.39239501953125, 1255.732666015625, 2.491249561309814453, 5.46521759033203125, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Curseformed Familiar (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+22, 130127, 1643, 8721, 9170, '0', 0, 0, 0, 0, -946.734375, 1232.3697509765625, 6.040618419647216796, 5.433637142181396484, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Forest Viper (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+23, 128937, 1643, 8721, 9170, '0', 0, 0, 0, 0, -919.47222900390625, 1218.8367919921875, 12.30871391296386718, 2.044929027557373046, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Scavenging Raven (Area: Timbered Strand - Difficulty: 0) CreateObject2 (Auras: 258247 - Perched)
(@CGUID+24, 126151, 1643, 8721, 9170, '0', 0, 0, 0, 0, -969.359375, 1281.890625, 1.410550713539123535, 6.108299732208251953, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Curseformed Familiar (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+25, 128937, 1643, 8721, 9170, '0', 0, 0, 0, 0, -967.16839599609375, 1238.5867919921875, 4.381191730499267578, 5.025489330291748046, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Scavenging Raven (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+26, 130127, 1643, 8721, 9170, '0', 0, 0, 0, 0, -1060.4947509765625, 1199.3958740234375, 6.4756011962890625, 5.58775186538696289, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Forest Viper (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+27, 128937, 1643, 8721, 9170, '0', 0, 0, 0, 0, -945.6875, 1282.8524169921875, 13.23130035400390625, 3.158654689788818359, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Scavenging Raven (Area: Timbered Strand - Difficulty: 0) CreateObject2 (Auras: 258247 - Perched)
(@CGUID+28, 128937, 1643, 8721, 9170, '0', 0, 0, 0, 0, -1014.8125, 1235.23095703125, 6.90690469741821289, 0.743078947067260742, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Scavenging Raven (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+29, 126151, 1643, 8721, 9170, '0', 0, 0, 0, 0, -945.9757080078125, 1251.5816650390625, 2.724215030670166015, 1.090157508850097656, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Curseformed Familiar (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+30, 126151, 1643, 8721, 9170, '0', 0, 0, 0, 0, -1039.4478759765625, 1196.28125, 5.287876129150390625, 0.631844580173492431, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Curseformed Familiar (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+31, 126151, 1643, 8721, 9170, '0', 0, 0, 0, 0, -947.0850830078125, 1184.5086669921875, 9.756134033203125, 5.233860015869140625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Curseformed Familiar (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+32, 128937, 1643, 8721, 9170, '0', 0, 0, 0, 0, -933.404541015625, 1204.12158203125, 16.24331092834472656, 3.734553813934326171, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Scavenging Raven (Area: Timbered Strand - Difficulty: 0) CreateObject2 (Auras: 258247 - Perched)
(@CGUID+33, 130127, 1643, 8721, 9170, '0', 0, 0, 0, 0, -1020.671875, 1226.15283203125, 7.493700981140136718, 0.59848487377166748, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Forest Viper (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+34, 126151, 1643, 8721, 9170, '0', 0, 0, 0, 0, -998.59027099609375, 1252.5191650390625, 3.9862060546875, 4.298240184783935546, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Curseformed Familiar (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+35, 128942, 1643, 8721, 9170, '0', 0, 0, 0, 0, -942.1475830078125, 1268.9947509765625, 1.787056922912597656, 4.822662830352783203, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Mudfisher Crab (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+36, 126151, 1643, 8721, 9170, '0', 0, 0, 0, 0, -986.045166015625, 1178.3367919921875, 7.9342803955078125, 4.800882816314697265, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Curseformed Familiar (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+37, 130127, 1643, 8721, 9170, '0', 0, 0, 0, 0, -1011.56427001953125, 1179.796875, 6.629643917083740234, 4.309372901916503906, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Forest Viper (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+38, 128937, 1643, 8721, 9170, '0', 0, 0, 0, 0, -1046.9254150390625, 1152.439208984375, 21.166961669921875, 5.981400966644287109, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Scavenging Raven (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+39, 130127, 1643, 8721, 9170, '0', 0, 0, 0, 0, -962.67535400390625, 1272.939208984375, 1.421199798583984375, 0, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Forest Viper (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+40, 126151, 1643, 8721, 9170, '0', 0, 0, 0, 0, -924.37847900390625, 1234.2430419921875, 3.521344184875488281, 2.767101049423217773, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Curseformed Familiar (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+41, 126151, 1643, 8721, 9170, '0', 0, 0, 0, 0, -966.96527099609375, 1278.2083740234375, 1.41277313232421875, 0.906354665756225585, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Curseformed Familiar (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+42, 128942, 1643, 8721, 9170, '0', 0, 0, 0, 0, -917.08331298828125, 1253.2100830078125, -1.01029980182647705, 0, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Mudfisher Crab (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+43, 130127, 1643, 8721, 9170, '0', 0, 0, 0, 0, -938.685791015625, 1194.7447509765625, 9.508968353271484375, 4.033689498901367187, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Forest Viper (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+44, 128937, 1643, 8721, 9170, '0', 0, 0, 0, 0, -933.55206298828125, 1207.7117919921875, 15.36217021942138671, 2.447749614715576171, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Scavenging Raven (Area: Timbered Strand - Difficulty: 0) CreateObject2 (Auras: 258247 - Perched)
(@CGUID+45, 126151, 1643, 8721, 9170, '0', 0, 0, 0, 0, -917.97222900390625, 1195.71533203125, 7.988570690155029296, 2.598923444747924804, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Curseformed Familiar (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+46, 130127, 1643, 8721, 9170, '0', 0, 0, 0, 0, -991.953125, 1257.7413330078125, 3.272788524627685546, 5.545058727264404296, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Forest Viper (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+47, 126151, 1643, 8721, 9170, '0', 0, 0, 0, 0, -942.56597900390625, 1179.842041015625, 10.59627532958984375, 2.633798122406005859, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Curseformed Familiar (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+48, 128937, 1643, 8721, 9170, '0', 0, 0, 0, 0, -1002.73272705078125, 1223.1771240234375, 17.85565757751464843, 2.600236892700195312, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Scavenging Raven (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+49, 128937, 1643, 8721, 9170, '0', 0, 0, 0, 0, -1063.49658203125, 1240.6961669921875, 18.78057670593261718, 2.53448486328125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Scavenging Raven (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+50, 128937, 1643, 8721, 9170, '0', 0, 0, 0, 0, -948.74652099609375, 1275.6805419921875, 9.349577903747558593, 4.170930862426757812, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Scavenging Raven (Area: Timbered Strand - Difficulty: 0) CreateObject2 (Auras: 258247 - Perched)
(@CGUID+51, 128937, 1643, 8721, 9170, '0', 0, 0, 0, 0, -968.2742919921875, 1236.5660400390625, 4.46142578125, 0.673260450363159179, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Scavenging Raven (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+52, 126151, 1643, 8721, 9170, '0', 0, 0, 0, 0, -1002.7603759765625, 1251.189208984375, 4.187633991241455078, 5.616820812225341796, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Curseformed Familiar (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+53, 130127, 1643, 8721, 9170, '0', 0, 0, 0, 0, -1058.8072509765625, 1269.7552490234375, 8.393434524536132812, 3.680401086807250976, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Forest Viper (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+54, 128937, 1643, 8721, 9170, '0', 0, 0, 0, 0, -1007.32989501953125, 1247.6666259765625, 24.4610137939453125, 0.207660511136054992, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Scavenging Raven (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+55, 128937, 1643, 8721, 9170, '0', 0, 0, 0, 0, -979.48956298828125, 1234.37158203125, 7.409296989440917968, 5.952071666717529296, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Scavenging Raven (Area: Timbered Strand - Difficulty: 0) CreateObject2 (Auras: 258247 - Perched)
(@CGUID+56, 130127, 1643, 8721, 9170, '0', 0, 0, 0, 0, -991.09893798828125, 1233.77783203125, 5.629299163818359375, 0.636477291584014892, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Forest Viper (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+57, 130083, 1643, 8721, 9170, '0', 0, 0, 0, 0, -1025.1910400390625, 1193.8802490234375, 4.874268531799316406, 0.15675412118434906, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Curseformed Ravager (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+58, 126151, 1643, 8721, 9170, '0', 0, 0, 0, 0, -1051.7535400390625, 1246.532958984375, 3.902777671813964843, 2.38696455955505371, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Curseformed Familiar (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+59, 128937, 1643, 8721, 9170, '0', 0, 0, 0, 0, -995.3211669921875, 1248.501708984375, 20.18337059020996093, 3.032025575637817382, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Scavenging Raven (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+60, 126151, 1643, 8721, 9170, '0', 0, 0, 0, 0, -965.6319580078125, 1157.7274169921875, 7.31865549087524414, 5.720538616180419921, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Curseformed Familiar (Area: Timbered Strand - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+61, 126782, 1643, 8721, 9170, '0', 0, 0, 0, 0, -1033.7257080078125, 1335.532958984375, 0.731765329837799072, 3.66341567039489746, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Boat (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+62, 128942, 1643, 8721, 9170, '0', 0, 0, 0, 0, -877.545166015625, 1229.701416015625, -5.09544563293457031, 3.233819246292114257, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Mudfisher Crab (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+63, 126151, 1643, 8721, 9170, '0', 0, 0, 0, 0, -987.75347900390625, 1216.8228759765625, 4.522313117980957031, 2.598923444747924804, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Curseformed Familiar (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+64, 128942, 1643, 8721, 9170, '0', 0, 0, 0, 0, -885.9757080078125, 1175.982666015625, -1.73611104488372802, 2.941543102264404296, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Mudfisher Crab (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+65, 128942, 1643, 8721, 9170, '0', 0, 0, 0, 0, -893.109375, 1192.532958984375, 0.58400118350982666, 0.531914770603179931, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Mudfisher Crab (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+66, 128942, 1643, 8721, 9170, '0', 0, 0, 0, 0, -903.78302001953125, 1170.295166015625, 0.581597208976745605, 6.061593055725097656, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Mudfisher Crab (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+67, 128942, 1643, 8721, 9170, '0', 0, 0, 0, 0, -869.89581298828125, 1222.515625, -6.28936529159545898, 2.411651849746704101, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Mudfisher Crab (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+68, 128942, 1643, 8721, 9170, '0', 0, 0, 0, 0, -941.15277099609375, 1151.5103759765625, 1.64479684829711914, 4.997906684875488281, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Mudfisher Crab (Area: Timbered Strand - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+69, 126434, 1643, 8721, 9170, '0', 0, 0, 0, 0, -957.62677001953125, 1114.1944580078125, -7.33427095413208007, 0.7345428466796875, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Coldscale Puffer (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+70, 130127, 1643, 8721, 0, '0', 0, 0, 0, 0, -1022.6007080078125, 1135.4617919921875, 2.557283878326416015, 4.434712886810302734, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Forest Viper (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+71, 136986, 1643, 8721, 0, '0', 0, 0, 0, 0, -1107.6353759765625, 1046.0364990234375, 0.161623358726501464, 0.993938148021697998, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Sandshell Turtle (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+72, 136986, 1643, 8721, 0, '0', 0, 0, 0, 0, -1089.7552490234375, 1039.3038330078125, 0.831078112125396728, 5.401402473449707031, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Sandshell Turtle (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+73, 126151, 1643, 8721, 0, '0', 0, 0, 0, 0, -1054.1978759765625, 1165.763916015625, 4.60037994384765625, 2.205790281295776367, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Curseformed Familiar (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+74, 130127, 1643, 8721, 0, '0', 0, 0, 0, 0, -1065.7257080078125, 1175.595458984375, 6.240631580352783203, 5.115195274353027343, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Forest Viper (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+75, 128942, 1643, 8721, 0, '0', 0, 0, 0, 0, -1045.9322509765625, 1081.2916259765625, 1.949510574340820312, 3.404632329940795898, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mudfisher Crab (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+76, 128942, 1643, 8721, 0, '0', 0, 0, 0, 0, -1055.857666015625, 1114.2239990234375, 1.191258430480957031, 6.237021923065185546, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mudfisher Crab (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+77, 128942, 1643, 8721, 0, '0', 0, 0, 0, 0, -1041.8646240234375, 1076.6632080078125, 1.865728616714477539, 4.866837501525878906, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Mudfisher Crab (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+78, 128942, 1643, 8721, 0, '0', 0, 0, 0, 0, -1045.84375, 1127.3055419921875, 0.22712564468383789, 0, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Mudfisher Crab (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+79, 130127, 1643, 8721, 0, '0', 0, 0, 0, 0, -1045.376708984375, 1151.328125, 3.023640394210815429, 0.195682957768440246, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Forest Viper (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+80, 126151, 1643, 8721, 0, '0', 0, 0, 0, 0, -1068.2708740234375, 1154.1754150390625, 3.667763471603393554, 2.812817573547363281, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Curseformed Familiar (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+81, 130194, 1643, 8721, 0, '0', 0, 0, 0, 0, -1070.6285400390625, 1105.05908203125, 1.296374320983886718, 1.526719450950622558, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Foulwater Rat (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+82, 136986, 1643, 8721, 0, '0', 0, 0, 0, 0, -1087.12158203125, 1063.720458984375, 0.865402817726135253, 5.382982730865478515, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Sandshell Turtle (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+83, 130127, 1643, 8721, 0, '0', 0, 0, 0, 0, -1059.4166259765625, 1139.9097900390625, 2.856094837188720703, 3.72945261001586914, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Forest Viper (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+84, 136986, 1643, 8721, 0, '0', 0, 0, 0, 0, -1087.0399169921875, 1039.375, 0.739237487316131591, 2.05644083023071289, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Sandshell Turtle (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+85, 130127, 1643, 8721, 0, '0', 0, 0, 0, 0, -1069.43408203125, 1124.736083984375, 2.668241500854492187, 5.7016448974609375, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Forest Viper (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+86, 128942, 1643, 8721, 0, '0', 0, 0, 0, 0, -1061.2882080078125, 1118.6302490234375, 0.360938340425491333, 0.494472831487655639, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Mudfisher Crab (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+87, 127822, 1643, 8721, 0, '0', 0, 0, 0, 0, -1057.109375, 1107.703125, 2.372127056121826171, 5.613190174102783203, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Alpine Goat (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+88, 126695, 1643, 8721, 0, '0', 0, 0, 0, 0, -1104.1510009765625, 1106.63720703125, 35.39870071411132812, 0.739183008670806884, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Baleful Raven (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+89, 126151, 1643, 8721, 9170, '0', 0, 0, 0, 0, -1093.046875, 1248.7117919921875, 11.78514957427978515, 3.743628740310668945, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Curseformed Familiar (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+90, 130127, 1643, 8721, 9170, '0', 0, 0, 0, 0, -1011.576416015625, 1284.90283203125, 3.402704238891601562, 1.145603895187377929, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Forest Viper (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+91, 128942, 1643, 8721, 9170, '0', 0, 0, 0, 0, -983.015625, 1302.4132080078125, -0.30267390608787536, 4.380178451538085937, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Mudfisher Crab (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+92, 130132, 1643, 8721, 9170, '0', 0, 0, 0, 0, -1054.8021240234375, 1290.49658203125, 6.577565670013427734, 0, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Strand Rat (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+93, 130132, 1643, 8721, 9170, '0', 0, 0, 0, 0, -1096.1285400390625, 1236.576416015625, 12.3316650390625, 2.889202117919921875, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Strand Rat (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+94, 130127, 1643, 8721, 9170, '0', 0, 0, 0, 0, -1046.78125, 1268.798583984375, 6.2086639404296875, 3.163860559463500976, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Forest Viper (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+95, 130083, 1643, 8721, 9170, '0', 0, 0, 0, 0, -1081.49658203125, 1286.140625, 3.320164680480957031, 5.094935417175292968, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Curseformed Ravager (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+96, 130127, 1643, 8721, 9170, '0', 0, 0, 0, 0, -1098.984375, 1274.1197509765625, 10.45144176483154296, 5.187495231628417968, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Forest Viper (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+97, 130132, 1643, 8721, 9170, '0', 0, 0, 0, 0, -1032.515625, 1291.9254150390625, 6.185097694396972656, 5.513689517974853515, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Strand Rat (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+98, 130132, 1643, 8721, 9170, '0', 0, 0, 0, 0, -1064.251708984375, 1281.6163330078125, 6.325452804565429687, 0, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 61967), -- Strand Rat (Area: Timbered Strand - Difficulty: 0) CreateObject2
(@CGUID+99, 126478, 1643, 8721, 9170, '0', 0, 0, 0, 1, -1042.75, 1274.7916259765625, 6.67877054214477539, 5.499874114990234375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Fletcher's Hollow Conscript (Area: Timbered Strand - Difficulty: 0) CreateObject1 (Auras: 255426 - Shoot Wickerman Trigger)
(@CGUID+100, 126478, 1643, 8721, 9170, '0', 0, 0, 0, 1, -1052.083984375, 1292.8055419921875, 6.580196380615234375, 2.82173776626586914, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Fletcher's Hollow Conscript (Area: Timbered Strand - Difficulty: 0) CreateObject1 (Auras: 255426 - Shoot Wickerman Trigger)
(@CGUID+101, 126478, 1643, 8721, 9170, '0', 0, 0, 0, 1, -1057.0208740234375, 1286.9461669921875, 6.748768329620361328, 2.385930061340332031, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Fletcher's Hollow Conscript (Area: Timbered Strand - Difficulty: 0) CreateObject1 (Auras: 255426 - Shoot Wickerman Trigger)
(@CGUID+102, 126724, 1643, 8721, 9170, '0', 0, 0, 0, 1, -1047.55908203125, 1275.638916015625, 7.378104686737060546, 1.084452509880065917, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Bridget Bran (Area: Timbered Strand - Difficulty: 0) CreateObject1
(@CGUID+103, 126478, 1643, 8721, 9170, '0', 0, 0, 0, 1, -1059.907958984375, 1275.3802490234375, 7.359099388122558593, 4.328393936157226562, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Fletcher's Hollow Conscript (Area: Timbered Strand - Difficulty: 0) CreateObject1 (Auras: 255426 - Shoot Wickerman Trigger)
(@CGUID+104, 126717, 1643, 8721, 9170, '0', 0, 0, 0, 1, -1055.15283203125, 1280.3785400390625, 7.385304927825927734, 0.242355644702911376, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Provisioner Stapleton (Area: Timbered Strand - Difficulty: 0) CreateObject1 (Auras: 219748 - Backpack Visual)
(@CGUID+105, 126310, 1643, 8721, 9170, '0', 0, 0, 0, 1, -1040.8680419921875, 1283.74658203125, 6.949351787567138671, 1.218581557273864746, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Evelyn Pare (Area: Timbered Strand - Difficulty: 0) CreateObject1
(@CGUID+106, 126478, 1643, 8721, 9170, '0', 0, 0, 0, 1, -1092.125, 1304.2083740234375, 2.496259927749633789, 5.263822555541992187, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Fletcher's Hollow Conscript (Area: Timbered Strand - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+107, 126478, 1643, 8721, 9170, '0', 0, 0, 0, 1, -1078.953125, 1305.1285400390625, 2.228810548782348632, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Fletcher's Hollow Conscript (Area: Timbered Strand - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+108, 126478, 1643, 8721, 9170, '0', 0, 0, 0, 1, -1080.173583984375, 1296.41845703125, 2.689307689666748046, 2.693448781967163085, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Fletcher's Hollow Conscript (Area: Timbered Strand - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+109, 126478, 1643, 8721, 9170, '0', 0, 0, 0, 1, -1105.4947509765625, 1302.44970703125, 4.289308547973632812, 2.380300760269165039, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967); -- Fletcher's Hollow Conscript (Area: Timbered Strand - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+109;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+4, 0, 0, 0, 0, 0, 1, 0, 428, 0, 0, 0, 0, ''), -- Scavenging Raven
(@CGUID+7, 0, 0, 0, 0, 0, 1, 0, 428, 0, 0, 0, 0, ''), -- Scavenging Raven
(@CGUID+12, 0, 0, 0, 0, 0, 1, 0, 428, 0, 0, 0, 0, ''), -- Scavenging Raven
(@CGUID+20, 0, 0, 0, 0, 0, 1, 0, 428, 0, 0, 0, 0, ''), -- Scavenging Raven
(@CGUID+25, 0, 0, 0, 0, 0, 1, 0, 428, 0, 0, 0, 0, ''), -- Scavenging Raven
(@CGUID+28, 0, 0, 0, 0, 0, 1, 0, 428, 0, 0, 0, 0, ''), -- Scavenging Raven
(@CGUID+51, 0, 0, 0, 0, 0, 1, 0, 428, 0, 0, 0, 0, ''), -- Scavenging Raven
(@CGUID+99, 0, 0, 0, 0, 0, 2, 0, 0, 13249, 0, 0, 0, '255426'), -- Fletcher's Hollow Conscript - 255426 - Shoot Wickerman Trigger
(@CGUID+100, 0, 0, 0, 0, 0, 2, 0, 0, 573, 0, 0, 0, '255426'), -- Fletcher's Hollow Conscript - 255426 - Shoot Wickerman Trigger
(@CGUID+101, 0, 0, 0, 0, 0, 2, 0, 0, 13248, 0, 0, 0, '255426'), -- Fletcher's Hollow Conscript - 255426 - Shoot Wickerman Trigger
(@CGUID+102, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Bridget Bran
(@CGUID+103, 0, 0, 0, 0, 0, 2, 0, 0, 13248, 0, 0, 0, '255426'), -- Fletcher's Hollow Conscript - 255426 - Shoot Wickerman Trigger
(@CGUID+104, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '219748'), -- Provisioner Stapleton - 219748 - Backpack Visual
(@CGUID+105, 0, 0, 0, 0, 0, 2, 0, 0, 13249, 0, 0, 0, ''), -- Evelyn Pare
(@CGUID+106, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474'), -- Fletcher's Hollow Conscript - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune)
(@CGUID+107, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474'), -- Fletcher's Hollow Conscript - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune)
(@CGUID+108, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474'), -- Fletcher's Hollow Conscript - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune)
(@CGUID+109, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474'); -- Fletcher's Hollow Conscript - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune)

-- Areatrigger
DELETE FROM `areatrigger_template` WHERE (`Id` = @ATID+0 AND `IsCustom` = 1);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES 
(@ATID+0, 1, 1, 0);

DELETE FROM `areatrigger_create_properties` WHERE (`Id`= 11845 AND `IsCustom`=0);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES 
(11845, 0, @ATID+0, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 15, 15, 0, 0, 0, 0, 0, 0, 'at_drustvar_timbered_strand_shoot_wickerman', 0);

-- Template
UPDATE `creature` SET `ScriptName` = 'npc_drustvar_shoot_wickerman_controller', `StringId` = 'ShootWickermanController' WHERE `guid` = @CGUID+101;
UPDATE `creature_template` SET `ScriptName` = 'npc_drustvar_charging_familiar' WHERE `entry` = 137841;

UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=61967 WHERE `entry`=273814; -- Bladed Charm
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=61967 WHERE `entry`=296627; -- Bonfire
UPDATE `gameobject_template` SET `ContentTuningId`=705, `VerifiedBuild`=61967 WHERE `entry`=291223; -- Small Treasure Chest
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=61967 WHERE `entry`=276513; -- Intact Mudfish
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=61967 WHERE `entry`=276515; -- Fishing Rod
UPDATE `gameobject_template` SET `ContentTuningId`=464, `VerifiedBuild`=61967 WHERE `entry`=290754; -- Egg Sac
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=61967 WHERE `entry`=272792; -- Egg Sac

-- Difficulty
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=126522 AND `DifficultyID`=0); -- 126522 (Sister Early) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000000, `VerifiedBuild`=61967 WHERE (`Entry`=137873 AND `DifficultyID`=0); -- 137873 (Slaughtered Pig) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=137748 AND `DifficultyID`=0); -- 137748 (Grotesque Thrall) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=126629 AND `DifficultyID`=0); -- 126629 (Captured Villager) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=61967 WHERE (`Entry`=126506 AND `DifficultyID`=0); -- 126506 (Ensorcelled Pig Heart) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=126523 AND `DifficultyID`=0); -- 126523 (Sister Mooring) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=61967 WHERE (`Entry`=127652 AND `DifficultyID`=0); -- 127652 (Untended Fishing Rod) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=125395 AND `DifficultyID`=0); -- 125395 (Fletcher's Hollow Villager) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=137842 AND `DifficultyID`=0); -- 137842 (Grotesque Thrall) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=61967 WHERE (`Entry`=115634 AND `DifficultyID`=0); -- 115634 (Controller) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000000, `VerifiedBuild`=61967 WHERE (`Entry`=126782 AND `DifficultyID`=0); -- 126782 (Boat) - Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=126724 AND `DifficultyID`=0); -- 126724 (Bridget Bran) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=61967 WHERE (`Entry`=128964 AND `DifficultyID`=0); -- 128964 (Player Clone) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=126717 AND `DifficultyID`=0); -- 126717 (Provisioner Stapleton) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=130606 AND `DifficultyID`=0); -- 130606 (Dormant Ravager) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=126310 AND `DifficultyID`=0); -- 126310 (Evelyn Pare) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=126478 AND `DifficultyID`=0); -- 126478 (Fletcher's Hollow Conscript) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=137841 AND `DifficultyID`=0); -- 137841 (Charging Familiar) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=130083 AND `DifficultyID`=0); -- 130083 (Curseformed Ravager) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=132166 AND `DifficultyID`=0); -- 132166 (Ian Glassel) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=126730 AND `DifficultyID`=0); -- 126730 (Fletcher's Hollow Woodsman) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=126159 AND `DifficultyID`=0); -- 126159 (Frightened Woodsman) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000000, `VerifiedBuild`=61967 WHERE (`Entry`=128937 AND `DifficultyID`=0); -- 128937 (Scavenging Raven) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=128942 AND `DifficultyID`=0); -- 128942 (Mudfisher Crab) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=61967 WHERE (`Entry`=115913 AND `DifficultyID`=0); -- 115913 (Target) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=61967 WHERE (`Entry`=127548 AND `DifficultyID`=0); -- 127548 (Fishing Rod) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=127553 AND `DifficultyID`=0); -- 127553 (Brinebeak) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=127526 AND `DifficultyID`=0); -- 127526 (Scavenging Snapclaw) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=127530 AND `DifficultyID`=0); -- 127530 (Ravenous Gull) - CanSwim

-- Model
UPDATE `creature_model_info` SET `VerifiedBuild`=61967 WHERE `DisplayID` IN (16356, 79038, 16357, 16358, 85446, 78050, 78947, 32790, 32546, 79039, 85562, 40020, 78048, 85561, 78046, 85560, 78949, 81079, 77955, 78950, 79076, 39810, 79074, 85568, 78861, 85518, 4959, 78948, 85584, 1987, 85517, 82261, 85522, 79871, 85521, 1986, 80962, 75365, 72014, 32646, 21072, 79505, 78152, 60055, 4626, 21342, 52835, 81145, 45598, 78834, 81154, 64978, 75374, 33719, 26774, 6302, 79477);
UPDATE `creature_model_info` SET `BoundingRadius`=0.306255877017974853, `CombatReach`=0.800000011920928955, `VerifiedBuild`=61967 WHERE `DisplayID`=36357;
UPDATE `creature_model_info` SET `BoundingRadius`=0.859295487403869628, `CombatReach`=0.400000005960464477, `VerifiedBuild`=61967 WHERE `DisplayID`=45906;
UPDATE `creature_model_info` SET `BoundingRadius`=1.990509390830993652, `CombatReach`=1.60000002384185791, `VerifiedBuild`=61967 WHERE `DisplayID`=77901;

-- Quest
DELETE FROM `creature_questender` WHERE (`id`=126310 AND `quest`=48171);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(126310, 48171, 61967); -- The Curse of Fletcher's Hollow ended by Evelyn Pare

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=126310 AND `MenuID`=21484);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(126310, 21484, 61967); -- Evelyn Pare

-- Spelltarget
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 13) AND (`SourceEntry` IN (255416));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(13, 1, 255416, 0, 0, 51, 0, 5, 137841, 0, '', 0, 'Potential target of the spell is TYPEID_UNIT, entry is 137841');

-- Vendor
DELETE FROM `npc_vendor` WHERE (`entry`=126717 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=126717 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=126717 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=126717 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=126717 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=126717 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=126717 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=126717 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=126717 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=126717 AND `item`=138293 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=126717 AND `item`=90146 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=126717 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=126717 AND `item`=38682 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=126717 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=126717 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(126717, 15, 64670, 0, 0, 1, 0, 0, 61967), -- Vanishing Powder
(126717, 14, 39505, 0, 0, 1, 0, 0, 61967), -- Virtuoso Inking Set
(126717, 13, 20815, 0, 0, 1, 0, 0, 61967), -- Jeweler's Toolset
(126717, 12, 5956, 0, 0, 1, 0, 0, 61967), -- Blacksmith Hammer
(126717, 11, 6217, 0, 0, 1, 0, 0, 61967), -- Copper Rod
(126717, 10, 6256, 0, 0, 1, 0, 0, 61967), -- Fishing Pole
(126717, 9, 85663, 0, 0, 1, 0, 0, 61967), -- Herbalist's Spade
(126717, 8, 7005, 0, 0, 1, 0, 0, 61967), -- Skinning Knife
(126717, 7, 2901, 0, 0, 1, 0, 0, 61967), -- Mining Pick
(126717, 6, 138293, 0, 0, 1, 0, 0, 61967), -- Explorer's Pack
(126717, 5, 90146, 0, 0, 1, 0, 0, 61967), -- Tinker's Kit
(126717, 4, 4470, 0, 0, 1, 0, 0, 61967), -- Simple Wood
(126717, 3, 38682, 0, 0, 1, 0, 0, 61967), -- Enchanting Vellum
(126717, 2, 3371, 0, 0, 1, 0, 0, 61967), -- Crystal Vial
(126717, 1, 39354, 0, 0, 1, 0, 0, 61967); -- Light Parchment

 -- Scavenging Raven smart ai
SET @ENTRY := 128937;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 1, 1000, 1000, 0, 0, 0, 85, 258247, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Time = 1 seconds (OOC) - Self: Cast spell 258247 on self', '');

UPDATE `creature` SET `StringId` = 'ChannelPerched' WHERE `guid` IN (@CGUID+5, @CGUID+11, @CGUID+13, @CGUID+23, @CGUID+27, @CGUID+32, @CGUID+44, @CGUID+50, @CGUID+55);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 128937 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 128937, 0, 0, 58, 1, 0, 0, 0, 'ChannelPerched', 0, 'Object has StringID ChannelPerched');

-- Path for Scavenging Raven
SET @MOVERGUID := @CGUID+38;
SET @ENTRY := 128937;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.6714, 'Scavenging Raven - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1035.749, 1148.9601, 21.166962, NULL, 0),
(@PATH, 1, -1024.0919, 1150.0227, 21.166962, NULL, 0),
(@PATH, 2, -1013.7289, 1155.4656, 21.166962, NULL, 0),
(@PATH, 3, -1006.2375, 1164.4598, 21.166962, NULL, 0),
(@PATH, 4, -1002.75836, 1175.6362, 21.166962, NULL, 0),
(@PATH, 5, -1003.82104, 1187.2933, 21.166962, NULL, 0),
(@PATH, 6, -1009.26385, 1197.6564, 21.166962, NULL, 0),
(@PATH, 7, -1018.25806, 1205.1477, 21.166962, NULL, 0),
(@PATH, 8, -1029.4344, 1208.6268, 21.166962, NULL, 0),
(@PATH, 9, -1041.0916, 1207.5641, 21.166962, NULL, 0),
(@PATH, 10, -1051.4546, 1202.1213, 21.166962, NULL, 0),
(@PATH, 11, -1058.946, 1193.1271, 21.166962, NULL, 0),
(@PATH, 12, -1062.4252, 1181.9507, 21.166962, NULL, 0),
(@PATH, 13, -1061.3624, 1170.2936, 21.166962, NULL, 0),
(@PATH, 14, -1055.9197, 1159.9305, 21.166962, NULL, 0),
(@PATH, 15, -1046.9254, 1152.4392, 21.166962, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Scavenging Raven
SET @MOVERGUID := @CGUID+48;
SET @ENTRY := 128937;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 9.1744, 'Scavenging Raven - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1012.57166, 1229.093, 17.855658, NULL, 0),
(@PATH, 1, -1015.34564, 1240.2334, 17.855658, NULL, 0),
(@PATH, 2, -1009.4297, 1250.0723, 17.855658, NULL, 0),
(@PATH, 3, -998.28937, 1252.8462, 17.855658, NULL, 0),
(@PATH, 4, -988.4505, 1246.9303, 17.855658, NULL, 0),
(@PATH, 5, -985.6765, 1235.79, 17.855658, NULL, 0),
(@PATH, 6, -991.5924, 1225.951, 17.855658, NULL, 0),
(@PATH, 7, -1002.7327, 1223.1771, 17.855658, NULL, 0);

UPDATE `creature` SET `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Scavenging Raven
SET @MOVERGUID := @CGUID+49;
SET @ENTRY := 128937;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.6714, 'Scavenging Raven - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1073.1102, 1247.374, 18.780577, NULL, 0),
(@PATH, 1, -1079.4366, 1257.2225, 18.780577, NULL, 0),
(@PATH, 2, -1081.5126, 1268.7424, 18.780577, NULL, 0),
(@PATH, 3, -1079.0221, 1280.1798, 18.780577, NULL, 0),
(@PATH, 4, -1072.3442, 1289.7935, 18.780577, NULL, 0),
(@PATH, 5, -1062.4957, 1296.1199, 18.780577, NULL, 0),
(@PATH, 6, -1050.9758, 1298.1958, 18.780577, NULL, 0),
(@PATH, 7, -1039.5385, 1295.7053, 18.780577, NULL, 0),
(@PATH, 8, -1029.9248, 1289.0275, 18.780577, NULL, 0),
(@PATH, 9, -1023.5984, 1279.179, 18.780577, NULL, 0),
(@PATH, 10, -1021.5224, 1267.659, 18.780577, NULL, 0),
(@PATH, 11, -1024.013, 1256.2217, 18.780577, NULL, 0),
(@PATH, 12, -1030.6908, 1246.608, 18.780577, NULL, 0),
(@PATH, 13, -1040.5393, 1240.2816, 18.780577, NULL, 0),
(@PATH, 14, -1052.0592, 1238.2057, 18.780577, NULL, 0),
(@PATH, 15, -1063.4966, 1240.6962, 18.780577, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Scavenging Raven
SET @MOVERGUID := @CGUID+54;
SET @ENTRY := 128937;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 9.1744, 'Scavenging Raven - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -996.09607, 1250.0336, 24.461014, NULL, 0),
(@PATH, 1, -986.4788, 1243.7638, 24.461014, NULL, 0),
(@PATH, 2, -984.1118, 1232.53, 24.461014, NULL, 0),
(@PATH, 3, -990.3816, 1222.9127, 24.461014, NULL, 0),
(@PATH, 4, -1001.6155, 1220.5458, 24.461014, NULL, 0),
(@PATH, 5, -1011.2327, 1226.8156, 24.461014, NULL, 0),
(@PATH, 6, -1013.59973, 1238.0493, 24.461014, NULL, 0),
(@PATH, 7, -1007.3299, 1247.6666, 24.461014, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Scavenging Raven
SET @MOVERGUID := @CGUID+59;
SET @ENTRY := 128937;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 9.1745, 'Scavenging Raven - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1006.73285, 1249.7571, 20.18337, NULL, 0),
(@PATH, 1, -1015.6898, 1242.5756, 20.18337, NULL, 0),
(@PATH, 2, -1016.9452, 1231.164, 20.18337, NULL, 0),
(@PATH, 3, -1009.7637, 1222.2069, 20.18337, NULL, 0),
(@PATH, 4, -998.352, 1220.9515, 20.18337, NULL, 0),
(@PATH, 5, -989.395, 1228.133, 20.18337, NULL, 0),
(@PATH, 6, -988.13965, 1239.5447, 20.18337, NULL, 0),
(@PATH, 7, -995.32117, 1248.5017, 20.18337, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Curseformed Ravager
SET @MOVERGUID := @CGUID+57;
SET @ENTRY := 130083;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Curseformed Ravager - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1008.1285, 1196.5834, 5.3902035, NULL, 0),
(@PATH, 1, -989.3941, 1205.3716, 5.199435, NULL, 0),
(@PATH, 2, -970.17706, 1219.1302, 4.607386, NULL, 0),
(@PATH, 3, -962.36115, 1234.9966, 4.6308064, NULL, 0),
(@PATH, 4, -963.76044, 1251.4705, 2.9167786, NULL, 8660),
(@PATH, 5, -962.36115, 1234.9966, 4.6308064, NULL, 0),
(@PATH, 6, -970.17706, 1219.1302, 4.607386, NULL, 0),
(@PATH, 7, -989.3941, 1205.3716, 5.199435, NULL, 0),
(@PATH, 8, -1008.1285, 1196.5834, 5.3902035, NULL, 0),
(@PATH, 9, -1025.8298, 1194.441, 4.7945294, NULL, 8558);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Curseformed Ravager
SET @MOVERGUID := @CGUID+95;
SET @ENTRY := 130083;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Curseformed Ravager - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1073.4896, 1264.026, 4.5967755, NULL, 0),
(@PATH, 1, -1063.8785, 1248.6129, 4.5985093, NULL, 0),
(@PATH, 2, -1055.6024, 1233.3281, 4.9807796, NULL, 0),
(@PATH, 3, -1050.9913, 1220.4202, 5.1733847, NULL, 0),
(@PATH, 4, -1049.401, 1199.9531, 5.468367, NULL, 0),
(@PATH, 5, -1049.2223, 1181.5868, 5.36551, NULL, 0),
(@PATH, 6, -1052.2969, 1170.5955, 4.940354, NULL, 6388),
(@PATH, 7, -1049.2223, 1181.5868, 5.36551, NULL, 0),
(@PATH, 8, -1049.401, 1199.9531, 5.468367, NULL, 0),
(@PATH, 9, -1050.9913, 1220.4202, 5.1733847, NULL, 0),
(@PATH, 10, -1055.6024, 1233.3281, 4.9807796, NULL, 0),
(@PATH, 11, -1063.8785, 1248.6129, 4.5985093, NULL, 0),
(@PATH, 12, -1073.4896, 1264.026, 4.5967755, NULL, 0),
(@PATH, 13, -1078.7639, 1279.3541, 3.9363153, NULL, 0),
(@PATH, 14, -1081.3004, 1285.7153, 3.2711282, NULL, 7784),
(@PATH, 15, -1078.7639, 1279.3541, 3.9363153, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Baleful Raven
SET @MOVERGUID := @CGUID+88;
SET @ENTRY := 126695;
SET @PATHOFFSET := 8;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 3.3396, 'Baleful Raven - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1095.5005, 1114.523, 35.3987, NULL, 0),
(@PATH, 1, -1084.4907, 1118.498, 35.3987, NULL, 0),
(@PATH, 2, -1072.7977, 1117.9574, 35.3987, NULL, 0),
(@PATH, 3, -1062.2019, 1112.983, 35.3987, NULL, 0),
(@PATH, 4, -1054.316, 1104.3325, 35.3987, NULL, 0),
(@PATH, 5, -1050.341, 1093.3228, 35.3987, NULL, 0),
(@PATH, 6, -1050.8817, 1081.6299, 35.3987, NULL, 0),
(@PATH, 7, -1055.856, 1071.0339, 35.3987, NULL, 0),
(@PATH, 8, -1064.5065, 1063.1482, 35.3987, NULL, 0),
(@PATH, 9, -1075.5162, 1059.1731, 35.3987, NULL, 0),
(@PATH, 10, -1087.2092, 1059.7139, 35.3987, NULL, 0),
(@PATH, 11, -1097.8052, 1064.6881, 35.3987, NULL, 0),
(@PATH, 12, -1105.6909, 1073.3386, 35.3987, NULL, 0),
(@PATH, 13, -1109.666, 1084.3484, 35.3987, NULL, 0),
(@PATH, 14, -1109.1252, 1096.0413, 35.3987, NULL, 0),
(@PATH, 15, -1104.151, 1106.6372, 35.3987, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Charging Familiar
SET @ENTRY := 137841;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Charging Familiar - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1107.752, 1306.2344, 4.2342663, NULL, 0),
(@PATH, 1, -1105.9551, 1305.3555, 3.9109073, NULL, 0),
(@PATH, 2, -1104.1582, 1304.4766, 3.6759202, NULL, 0),
(@PATH, 3, -1101.4629, 1303.1582, 3.4102116, NULL, 0),
(@PATH, 4, -1099.666, 1302.2793, 3.1402373, NULL, 0),
(@PATH, 5, -1097.8691, 1301.4004, 2.952486, NULL, 0),
(@PATH, 6, -1093.377, 1299.2031, 2.7331445, NULL, 0),
(@PATH, 7, -1078.1035, 1291.7324, 2.9034564, NULL, 0),
(@PATH, 8, -1075.4082, 1290.4141, 3.1712468, NULL, 0),
(@PATH, 9, -1073.6113, 1289.5352, 3.6470535, NULL, 0),
(@PATH, 10, -1071.8145, 1288.6562, 4.117653, NULL, 0),
(@PATH, 11, -1070.0176, 1287.7773, 4.58556, NULL, 0),
(@PATH, 12, -1069.1191, 1287.3379, 4.953725, NULL, 0),
(@PATH, 13, -1067.3223, 1286.459, 5.411983, NULL, 0),
(@PATH, 14, -1066.4238, 1286.0195, 5.6251326, NULL, 0),
(@PATH, 15, -1065.5254, 1285.5801, 5.807416, NULL, 0),
(@PATH, 16, -1063.7285, 1284.7012, 6.06653, NULL, 0);

-- Path for Charging Familiar
SET @ENTRY := 137841;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Charging Familiar - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1110.0703, 1309.2725, 4.331596, NULL, 0),
(@PATH, 1, -1108.25, 1308.4443, 4.034461, NULL, 0),
(@PATH, 2, -1105.5195, 1307.2021, 3.8375747, NULL, 0),
(@PATH, 3, -1103.6992, 1306.374, 3.529255, NULL, 0),
(@PATH, 4, -1101.8789, 1305.5459, 3.2772467, NULL, 0),
(@PATH, 5, -1099.1484, 1304.3037, 3.0439014, NULL, 0),
(@PATH, 6, -1097.3281, 1303.4756, 2.8659687, NULL, 0),
(@PATH, 7, -1094.5977, 1302.2334, 2.6397455, NULL, 0),
(@PATH, 8, -1075.4844, 1293.5381, 2.8261364, NULL, 0),
(@PATH, 9, -1072.7539, 1292.2959, 3.2904348, NULL, 0),
(@PATH, 10, -1070.9336, 1291.4678, 3.6528673, NULL, 0),
(@PATH, 11, -1069.1133, 1290.6396, 4.130217, NULL, 0),
(@PATH, 12, -1068.2031, 1290.2256, 4.619435, NULL, 0),
(@PATH, 13, -1067.293, 1289.8115, 4.8335752, NULL, 0),
(@PATH, 14, -1066.3828, 1289.3975, 5.246695, NULL, 0),
(@PATH, 15, -1065.4727, 1288.9834, 5.4194226, NULL, 0),
(@PATH, 16, -1064.5625, 1288.5693, 5.5867577, NULL, 0),
(@PATH, 17, -1063.6523, 1288.1553, 5.801051, NULL, 0),
(@PATH, 18, -1062.7422, 1287.7412, 5.9683857, NULL, 0),
(@PATH, 19, -1061.832, 1287.3271, 6.3225136, NULL, 0),
(@PATH, 20, -1061.459, 1287.14, 6.357631, NULL, 0);

-- Path for Charging Familiar
SET @ENTRY := 137841;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Charging Familiar - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1115.6285, 1270.4618, 11.991214, NULL, 0),
(@PATH, 1, -1114.584, 1266.667, 12.251726, NULL, 0),
(@PATH, 2, -1112.7051, 1265.9873, 11.97921, NULL, 0),
(@PATH, 3, -1111.7656, 1265.6475, 11.789886, NULL, 0),
(@PATH, 4, -1109.8867, 1264.9678, 11.534676, NULL, 0),
(@PATH, 5, -1108.9473, 1264.6279, 11.32185, NULL, 0),
(@PATH, 6, -1106.1289, 1263.6084, 11.092177, NULL, 0),
(@PATH, 7, -1105.1895, 1263.2686, 10.878208, NULL, 0),
(@PATH, 8, -1103.3105, 1262.5889, 10.696095, NULL, 0),
(@PATH, 9, -1102.3711, 1262.249, 10.528121, NULL, 0),
(@PATH, 10, -1100.4922, 1261.5693, 10.238401, NULL, 0),
(@PATH, 11, -1098.6133, 1260.8896, 9.957523, NULL, 0),
(@PATH, 12, -1091.0977, 1258.1709, 9.374429, NULL, 0),
(@PATH, 13, -1089.2188, 1257.4912, 9.168623, NULL, 0),
(@PATH, 14, -1088.2793, 1257.1514, 8.836369, NULL, 0),
(@PATH, 15, -1087.3398, 1256.8115, 8.641872, NULL, 0),
(@PATH, 16, -1086.4004, 1256.4717, 8.230158, NULL, 0),
(@PATH, 17, -1085.4609, 1256.1318, 8.000807, NULL, 0),
(@PATH, 18, -1084.4948, 1255.7795, 7.683979, NULL, 0),
(@PATH, 19, -1073.316, 1258.3837, 4.7902775, NULL, 0),
(@PATH, 20, -1065.2048, 1270.8004, 7.9386816, NULL, 0);

-- Path for Charging Familiar
SET @ENTRY := 137841;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Charging Familiar - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1021.0486, 1227.4896, 7.2532063, NULL, 0),
(@PATH, 1, -1020.834, 1229.167, 7.124133, NULL, 0),
(@PATH, 2, -1020.834, 1231.167, 6.8541365, NULL, 0),
(@PATH, 3, -1020.834, 1233.167, 6.5634046, NULL, 0),
(@PATH, 4, -1021.28125, 1234.2275, 6.391777, NULL, 0),
(@PATH, 5, -1021.7285, 1235.1221, 6.1842365, NULL, 0),
(@PATH, 6, -1021.875, 1235.417, 6.079133, NULL, 0),
(@PATH, 7, -1021.875, 1236.417, 5.8715935, NULL, 0),
(@PATH, 8, -1021.875, 1237.417, 5.652939, NULL, 0),
(@PATH, 9, -1022.60156, 1240.4092, 4.9601984, NULL, 0),
(@PATH, 10, -1022.84375, 1241.3789, 4.694684, NULL, 0),
(@PATH, 11, -1022.916, 1241.667, 4.5824804, NULL, 0),
(@PATH, 12, -1022.916, 1243.667, 4.0396624, NULL, 0),
(@PATH, 13, -1022.916, 1245.667, 3.5740478, NULL, 0),
(@PATH, 14, -1023.3633, 1246.7275, 3.3458872, NULL, 0),
(@PATH, 15, -1023.81055, 1247.6221, 3.1229463, NULL, 0),
(@PATH, 16, -1024.2578, 1248.5166, 2.9246235, NULL, 0),
(@PATH, 17, -1024.7051, 1249.4111, 2.7489502, NULL, 0),
(@PATH, 18, -1025, 1250, 2.723629, NULL, 0),
(@PATH, 19, -1026.4141, 1251.4141, 2.521698, NULL, 0),
(@PATH, 20, -1029.2422, 1254.2422, 2.322771, NULL, 0),
(@PATH, 21, -1032.7773, 1257.7773, 2.0842323, NULL, 0),
(@PATH, 22, -1033.334, 1258.333, 2.0960023, NULL, 0),
(@PATH, 23, -1034.3926, 1260.0283, 2.284857, NULL, 0),
(@PATH, 24, -1035.4512, 1261.7236, 2.6848698, NULL, 0),
(@PATH, 25, -1036.5098, 1263.419, 3.047623, NULL, 0),
(@PATH, 26, -1037.0391, 1264.2666, 3.2892356, NULL, 0),
(@PATH, 27, -1037.5684, 1265.1143, 3.7774231, NULL, 0),
(@PATH, 28, -1038.0977, 1265.9619, 4.0190353, NULL, 0),
(@PATH, 29, -1038.541, 1266.667, 4.272814, NULL, 0);

-- Path for Charging Familiar
SET @ENTRY := 137841;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Charging Familiar - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1107.543, 1310.6992, 4.011923, NULL, 0),
(@PATH, 1, -1106.627, 1310.2979, 3.8319511, NULL, 0),
(@PATH, 2, -1104.7949, 1309.4951, 3.511178, NULL, 0),
(@PATH, 3, -1102.9629, 1308.6924, 3.2554235, NULL, 0),
(@PATH, 4, -1100.2148, 1307.4883, 3.0294623, NULL, 0),
(@PATH, 5, -1098.3828, 1306.6855, 2.833761, NULL, 0),
(@PATH, 6, -1096.5508, 1305.8828, 2.6638746, NULL, 0),
(@PATH, 7, -1092.8867, 1304.2773, 2.4649985, NULL, 0),
(@PATH, 8, -1072.7344, 1295.4473, 2.6612177, NULL, 0),
(@PATH, 9, -1070.9023, 1294.6445, 2.9333994, NULL, 0),
(@PATH, 10, -1069.0703, 1293.8418, 3.2695231, NULL, 0),
(@PATH, 11, -1068.1543, 1293.4404, 3.7718396, NULL, 0),
(@PATH, 12, -1067.2383, 1293.0391, 3.9670625, NULL, 0),
(@PATH, 13, -1066.3223, 1292.6377, 4.521852, NULL, 0),
(@PATH, 14, -1064.4902, 1291.835, 4.839486, NULL, 0),
(@PATH, 15, -1063.5742, 1291.4336, 5.1249566, NULL, 0),
(@PATH, 16, -1061.7422, 1290.6309, 5.4238153, NULL, 0),
(@PATH, 17, -1060.8262, 1290.2295, 5.7786813, NULL, 0),
(@PATH, 18, -1059.9102, 1289.8281, 5.987424, NULL, 0),
(@PATH, 19, -1059.375, 1289.583, 6.1688924, NULL, 0);

-- Path for Charging Familiar
SET @ENTRY := 137841;
SET @PATHOFFSET := 5;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Charging Familiar - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1116.6598, 1267.3698, 12.426893, NULL, 0),
(@PATH, 1, -1113.8711, 1266.2686, 12.115467, NULL, 0),
(@PATH, 2, -1112.0117, 1265.5342, 11.858885, NULL, 0),
(@PATH, 3, -1110.1523, 1264.7998, 11.534676, NULL, 0),
(@PATH, 4, -1109.2227, 1264.4326, 11.3354025, NULL, 0),
(@PATH, 5, -1106.4336, 1263.331, 11.117255, NULL, 0),
(@PATH, 6, -1104.5742, 1262.5967, 10.878208, NULL, 0),
(@PATH, 7, -1103.6445, 1262.2295, 10.67298, NULL, 0),
(@PATH, 8, -1101.7852, 1261.4951, 10.383262, NULL, 0),
(@PATH, 9, -1099.9258, 1260.7607, 10.115615, NULL, 0),
(@PATH, 10, -1097.1367, 1259.6592, 9.837471, NULL, 0),
(@PATH, 11, -1093.418, 1258.1904, 9.636194, NULL, 0),
(@PATH, 12, -1091.5586, 1257.456, 9.374429, NULL, 0),
(@PATH, 13, -1089.6992, 1256.7217, 8.91655, NULL, 0),
(@PATH, 14, -1087.8398, 1255.9873, 8.6070175, NULL, 0),
(@PATH, 15, -1086.9102, 1255.6201, 8.412519, NULL, 0),
(@PATH, 16, -1086.1146, 1255.3195, 8.018966, NULL, 0),
(@PATH, 17, -1073.1354, 1256.7969, 4.883214, NULL, 0),
(@PATH, 18, -1062.6337, 1267.8594, 7.822101, NULL, 0);

-- Path for Charging Familiar
SET @ENTRY := 137841;
SET @PATHOFFSET := 6;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Charging Familiar - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1107.9297, 1318.3926, 3.9033213, NULL, 0),
(@PATH, 1, -1107.0137, 1317.9922, 3.528987, NULL, 0),
(@PATH, 2, -1106.0977, 1317.5918, 3.2859883, NULL, 0),
(@PATH, 3, -1105.1816, 1317.1914, 2.9346614, NULL, 0),
(@PATH, 4, -1102.4336, 1315.9902, 2.661201, NULL, 0),
(@PATH, 5, -1099.6855, 1314.7891, 2.4246476, NULL, 0),
(@PATH, 6, -1094.1895, 1312.3867, 2.2517042, NULL, 0),
(@PATH, 7, -1091.4414, 1311.1855, 2.0544846, NULL, 0),
(@PATH, 8, -1065.793, 1299.9746, 2.2424545, NULL, 0),
(@PATH, 9, -1063.0449, 1298.7734, 2.7613983, NULL, 0),
(@PATH, 10, -1062.1289, 1298.373, 3.250316, NULL, 0),
(@PATH, 11, -1061.2129, 1297.9727, 4.0925035, NULL, 0),
(@PATH, 12, -1060.2969, 1297.5723, 5.021382, NULL, 0),
(@PATH, 13, -1060.27, 1297.55, 4.842248, NULL, 0);

-- Path for Charging Familiar
SET @ENTRY := 137841;
SET @PATHOFFSET := 7;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Charging Familiar - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1004.6632, 1240.9635, 5.9242477, NULL, 0),
(@PATH, 1, -1006.46094, 1241.8408, 5.6676493, NULL, 0),
(@PATH, 2, -1010.4551, 1243.7881, 5.295284, NULL, 0),
(@PATH, 3, -1011.86914, 1245.2021, 4.9393044, NULL, 0),
(@PATH, 4, -1012.5762, 1245.9092, 4.552652, NULL, 0),
(@PATH, 5, -1013.99023, 1247.3232, 4.1353264, NULL, 0),
(@PATH, 6, -1014.69727, 1248.0303, 3.74057, NULL, 0),
(@PATH, 7, -1016.1113, 1249.4443, 3.3683822, NULL, 0),
(@PATH, 8, -1016.666, 1250, 3.234027, NULL, 0),
(@PATH, 9, -1017.37305, 1250.707, 3.0460024, NULL, 0),
(@PATH, 10, -1017.709, 1251.042, 2.9503796, NULL, 0),
(@PATH, 11, -1018.75, 1252.083, 2.6778083, NULL, 0),
(@PATH, 12, -1020.834, 1254.167, 2.3282757, NULL, 0),
(@PATH, 13, -1022.24805, 1255.581, 2.1299415, NULL, 0),
(@PATH, 14, -1024.3691, 1257.7021, 1.9223499, NULL, 0),
(@PATH, 15, -1025, 1258.333, 1.9351819, NULL, 0),
(@PATH, 16, -1026.4141, 1259.7471, 1.7315451, NULL, 0),
(@PATH, 17, -1028.5352, 1261.8682, 1.5549204, NULL, 0),
(@PATH, 18, -1029.166, 1262.5, 1.5743334, NULL, 0),
(@PATH, 19, -1031.2871, 1264.6211, 1.8101692, NULL, 0),
(@PATH, 20, -1032.7012, 1266.0352, 2.4896262, NULL, 0),
(@PATH, 21, -1033.334, 1266.667, 2.8795176, NULL, 0),
(@PATH, 22, -1033.4258, 1267.6631, 3.1313276, NULL, 0),
(@PATH, 23, -1033.61, 1269.63, 3.8520648, NULL, 0);

-- Path for Charging Familiar
SET @ENTRY := 137841;
SET @PATHOFFSET := 8;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Charging Familiar - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1109.6465, 1314.9258, 4.4187794, NULL, 0),
(@PATH, 1, -1108.7363, 1314.5107, 4.2213244, NULL, 0),
(@PATH, 2, -1107.8262, 1314.0957, 4.012377, NULL, 0),
(@PATH, 3, -1106.916, 1313.6807, 3.7599778, NULL, 0),
(@PATH, 4, -1105.0957, 1312.8506, 3.4001656, NULL, 0),
(@PATH, 5, -1102.3652, 1311.6055, 3.125982, NULL, 0),
(@PATH, 6, -1100.5449, 1310.7754, 2.8937895, NULL, 0),
(@PATH, 7, -1098.7246, 1309.9453, 2.6935196, NULL, 0),
(@PATH, 8, -1095.9941, 1308.7002, 2.522256, NULL, 0),
(@PATH, 9, -1093.2637, 1307.4551, 2.2916136, NULL, 0),
(@PATH, 10, -1069.5996, 1296.6641, 2.6910062, NULL, 0),
(@PATH, 11, -1066.8691, 1295.419, 3.2384732, NULL, 0),
(@PATH, 12, -1065.959, 1295.0039, 3.4289682, NULL, 0),
(@PATH, 13, -1065.0488, 1294.5889, 3.9790304, NULL, 0),
(@PATH, 14, -1064.1387, 1294.1738, 4.1890955, NULL, 0),
(@PATH, 15, -1063.2285, 1293.7588, 4.3722105, NULL, 0),
(@PATH, 16, -1062.3184, 1293.3438, 4.943635, NULL, 0),
(@PATH, 17, -1061.4082, 1292.9287, 5.2772765, NULL, 0),
(@PATH, 18, -1060.498, 1292.5137, 5.465423, NULL, 0),
(@PATH, 19, -1059.5879, 1292.0986, 5.674166, NULL, 0),
(@PATH, 20, -1058.6777, 1291.6836, 5.882909, NULL, 0),
(@PATH, 21, -1058.51, 1291.6, 6.0553017, NULL, 0);

-- Path for Charging Familiar
SET @ENTRY := 137841;
SET @PATHOFFSET := 9;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Charging Familiar - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1014.44727, 1231.6094, 7.4682183, NULL, 0),
(@PATH, 1, -1014.9453, 1232.4766, 7.2187667, NULL, 0),
(@PATH, 2, -1015.44336, 1233.3438, 7.0425935, NULL, 0),
(@PATH, 3, -1016.43945, 1235.0781, 6.7597647, NULL, 0),
(@PATH, 4, -1016.9375, 1235.9453, 6.4555254, NULL, 0),
(@PATH, 5, -1017.43555, 1236.8125, 6.2515497, NULL, 0),
(@PATH, 6, -1017.9336, 1237.6797, 5.9023657, NULL, 0),
(@PATH, 7, -1018.43164, 1238.5469, 5.6695337, NULL, 0),
(@PATH, 8, -1019.42773, 1240.2812, 5.30227, NULL, 0),
(@PATH, 9, -1019.9258, 1241.1484, 4.9209113, NULL, 0),
(@PATH, 10, -1020.4238, 1242.0156, 4.6548495, NULL, 0),
(@PATH, 11, -1020.9219, 1242.8828, 4.2629232, NULL, 0),
(@PATH, 12, -1021.91797, 1244.6172, 3.877346, NULL, 0),
(@PATH, 13, -1022.91406, 1246.3516, 3.4158041, NULL, 0),
(@PATH, 14, -1023.4121, 1247.2188, 3.1229463, NULL, 0),
(@PATH, 15, -1023.91016, 1248.0859, 2.9472733, NULL, 0),
(@PATH, 16, -1024.9062, 1249.8203, 2.7489502, NULL, 0),
(@PATH, 17, -1025.9023, 1251.5547, 2.511332, NULL, 0),
(@PATH, 18, -1026.8984, 1253.2891, 2.3421674, NULL, 0),
(@PATH, 19, -1028.8906, 1256.7578, 2.1073968, NULL, 0),
(@PATH, 20, -1029.8867, 1258.4922, 1.9199958, NULL, 0),
(@PATH, 21, -1032.875, 1263.6953, 2.207642, NULL, 0),
(@PATH, 22, -1033.373, 1264.5625, 2.5975335, NULL, 0),
(@PATH, 23, -1034.3691, 1266.2969, 2.8795176, NULL, 0),
(@PATH, 24, -1034.8672, 1267.1641, 3.4289753, NULL, 0),
(@PATH, 25, -1035.3652, 1268.0312, 3.7352736, NULL, 0),
(@PATH, 26, -1035.8633, 1268.8984, 4.334964, NULL, 0),
(@PATH, 27, -1036.32, 1269.62, 4.543865, NULL, 0);

-- Path for Charging Familiar
SET @ENTRY := 137841;
SET @PATHOFFSET := 10;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Charging Familiar - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1104.8105, 1313.9932, 3.2742138, NULL, 0),
(@PATH, 1, -1103.8945, 1313.5938, 3.0508022, NULL, 0),
(@PATH, 2, -1100.2305, 1311.9961, 2.8551257, NULL, 0),
(@PATH, 3, -1098.3984, 1311.1973, 2.6548557, NULL, 0),
(@PATH, 4, -1095.6504, 1309.999, 2.3937478, NULL, 0),
(@PATH, 5, -1091.9863, 1308.4014, 2.152523, NULL, 0),
(@PATH, 6, -1070.002, 1298.8154, 2.3202586, NULL, 0),
(@PATH, 7, -1067.2539, 1297.6172, 2.6934736, NULL, 0),
(@PATH, 8, -1065.4219, 1296.8184, 3.2732494, NULL, 0),
(@PATH, 9, -1064.5059, 1296.419, 3.483315, NULL, 0),
(@PATH, 10, -1062.6738, 1295.6201, 4.059165, NULL, 0),
(@PATH, 11, -1061.7578, 1295.2207, 4.317543, NULL, 0),
(@PATH, 12, -1060.8418, 1294.8213, 4.780431, NULL, 0),
(@PATH, 13, -1060.57, 1294.72, 5.0478086, NULL, 0);

-- Path for Charging Familiar
SET @ENTRY := 137841;
SET @PATHOFFSET := 11;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Charging Familiar - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1116.7291, 1263.5348, 12.732288, NULL, 0),
(@PATH, 1, -1114.8379, 1262.8848, 12.491028, NULL, 0),
(@PATH, 2, -1112.002, 1261.9092, 12.060682, NULL, 0),
(@PATH, 3, -1111.0566, 1261.584, 11.844707, NULL, 0),
(@PATH, 4, -1109.166, 1260.9336, 11.508425, NULL, 0),
(@PATH, 5, -1108.2207, 1260.6084, 11.319796, NULL, 0),
(@PATH, 6, -1105.3848, 1259.6328, 11.082425, NULL, 0),
(@PATH, 7, -1103.4941, 1258.9824, 10.7575655, NULL, 0),
(@PATH, 8, -1102.5488, 1258.6572, 10.586429, NULL, 0),
(@PATH, 9, -1100.6582, 1258.0068, 10.322176, NULL, 0),
(@PATH, 10, -1098.7676, 1257.3564, 10.105137, NULL, 0),
(@PATH, 11, -1095.9316, 1256.3809, 9.923801, NULL, 0),
(@PATH, 12, -1094.041, 1255.7305, 9.710344, NULL, 0),
(@PATH, 13, -1092.1504, 1255.0801, 9.393428, NULL, 0),
(@PATH, 14, -1090.2598, 1254.4297, 8.898365, NULL, 0),
(@PATH, 15, -1088.3691, 1253.7793, 8.715607, NULL, 0),
(@PATH, 16, -1087.4238, 1253.4541, 8.423813, NULL, 0),
(@PATH, 17, -1085.5332, 1252.8037, 8.722738, NULL, 0),
(@PATH, 18, -1084.9098, 1252.5764, 8.501776, NULL, 0),
(@PATH, 19, -1071.7726, 1255.0695, 4.7779503, NULL, 0),
(@PATH, 20, -1062.7014, 1261.2969, 6.453865, NULL, 0);

-- Path for Charging Familiar
SET @ENTRY := 137841;
SET @PATHOFFSET := 12;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Charging Familiar - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1099.6191, 1317.0605, 2.221225, NULL, 0),
(@PATH, 1, -1091.375, 1313.4307, 2.0378296, NULL, 0),
(@PATH, 2, -1069.3906, 1303.751, 1.8448014, NULL, 0),
(@PATH, 3, -1062.0625, 1300.5244, 2.4219987, NULL, 0),
(@PATH, 4, -1061.1465, 1300.1211, 3.2195883, NULL, 0),
(@PATH, 5, -1060.69, 1299.92, 3.556062, NULL, 0);
