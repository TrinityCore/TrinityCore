SET @CGUID := 10004127;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+93;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 219171, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2190.883056640625, -2944.614501953125, 167.4693603515625, 3.072491168975830078, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Velvetfur Ferret (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+1, 219171, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2217.63525390625, -2982.67578125, 162.2803802490234375, 0.893772423267364501, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Velvetfur Ferret (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+2, 219171, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2245.930419921875, -2944.558837890625, 172.4598388671875, 4.78077554702758789, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Velvetfur Ferret (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+3, 219171, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2240.61328125, -2891.78271484375, 174.199676513671875, 3.445118665695190429, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Velvetfur Ferret (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+4, 219171, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2281.30322265625, -2987.817138671875, 173.9058990478515625, 0.304787486791610717, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Velvetfur Ferret (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+5, 222223, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2213.214111328125, -2928.342529296875, 197.2421417236328125, 4.545993328094482421, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Watchful Falcon (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+6, 219171, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2183.101318359375, -2890.869873046875, 169.5794677734375, 4.685362815856933593, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Velvetfur Ferret (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+7, 222618, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2231.71875, -2948.907958984375, 170.6955413818359375, 2.44838571548461914, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Alert Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+8, 219171, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2222.844482421875, -2911.838134765625, 171.638153076171875, 3.299964666366577148, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Velvetfur Ferret (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+9, 222618, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2125.092041015625, -3041.897705078125, 155.117401123046875, 6.036624431610107421, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Alert Shalehorn (Area: The Proscenium - Difficulty: 0) CreateObject1
(@CGUID+10, 219171, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2146.41064453125, -2982.869384765625, 161.4508819580078125, 1.052696824073791503, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Velvetfur Ferret (Area: The Proscenium - Difficulty: 0) CreateObject1
(@CGUID+11, 219171, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2094.2548828125, -3064.61328125, 151.7372894287109375, 3.15423893928527832, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Velvetfur Ferret (Area: The Proscenium - Difficulty: 0) CreateObject1
(@CGUID+12, 219171, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2086.028076171875, -2985.897216796875, 162.1605682373046875, 5.409609317779541015, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Velvetfur Ferret (Area: The Proscenium - Difficulty: 0) CreateObject1
(@CGUID+13, 223095, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2126.10205078125, -3029.117431640625, 157.08807373046875, 1.920651912689208984, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Bedrock Stonecharger (Area: The Proscenium - Difficulty: 0) CreateObject1
(@CGUID+14, 219171, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2060.693359375, -3021.327392578125, 158.451019287109375, 1.079326033592224121, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Velvetfur Ferret (Area: The Proscenium - Difficulty: 0) CreateObject1
(@CGUID+15, 219171, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2138.023681640625, -3054.547607421875, 151.28302001953125, 5.995909690856933593, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Velvetfur Ferret (Area: The Proscenium - Difficulty: 0) CreateObject1
(@CGUID+16, 219171, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2127.95751953125, -3096.598876953125, 148.0182647705078125, 2.339621543884277343, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Velvetfur Ferret (Area: The Proscenium - Difficulty: 0) CreateObject1
(@CGUID+17, 219171, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2106.53076171875, -3026.34228515625, 158.598358154296875, 5.326332569122314453, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Velvetfur Ferret (Area: The Proscenium - Difficulty: 0) CreateObject1
(@CGUID+18, 219171, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2081.431396484375, -3108.0966796875, 148.5657806396484375, 6.257800102233886718, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Velvetfur Ferret (Area: The Proscenium - Difficulty: 0) CreateObject1
(@CGUID+19, 222223, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2112.121826171875, -3000.095703125, 185.308319091796875, 4.75119781494140625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Watchful Falcon (Area: The Proscenium - Difficulty: 0) CreateObject1
(@CGUID+20, 219171, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2174.807373046875, -3024.003662109375, 145.5567169189453125, 6.258922100067138671, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Velvetfur Ferret (Area: The Proscenium - Difficulty: 0) CreateObject1
(@CGUID+21, 219171, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2020.683349609375, -3052.58203125, 156.7813873291015625, 5.627257347106933593, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Velvetfur Ferret (Area: The Proscenium - Difficulty: 0) CreateObject1
(@CGUID+22, 222223, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2046.8746337890625, -3067.05419921875, 175.601959228515625, 6.11820840835571289, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Watchful Falcon (Area: The Proscenium - Difficulty: 0) CreateObject1
(@CGUID+23, 219171, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2045.659912109375, -3077.627685546875, 153.70098876953125, 2.873694419860839843, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Velvetfur Ferret (Area: The Proscenium - Difficulty: 0) CreateObject1
(@CGUID+24, 219171, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2025.75537109375, -3106.8486328125, 154.4615325927734375, 4.312440872192382812, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Velvetfur Ferret (Area: The Proscenium - Difficulty: 0) CreateObject1
(@CGUID+25, 219171, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2114.9765625, -2951.356201171875, 166.62078857421875, 3.798954725265502929, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Velvetfur Ferret (Area: The Proscenium - Difficulty: 0) CreateObject1
(@CGUID+26, 219171, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2100.783203125, -3141.801025390625, 144.6099853515625, 3.869379520416259765, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Velvetfur Ferret (Area: The Proscenium - Difficulty: 0) CreateObject1
(@CGUID+27, 219171, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2048.937744140625, -3140.00830078125, 147.4906463623046875, 3.02278304100036621, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Velvetfur Ferret (Area: The Proscenium - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+28, 222619, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2029.2181396484375, -3112.45068359375, 153.4382171630859375, 0.224405094981193542, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Meandering Shalehorn (Area: The Proscenium - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+29, 222619, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2128.65283203125, -2969.994873046875, 163.9039154052734375, 1.510484218597412109, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Meandering Shalehorn (Area: The Proscenium - Difficulty: 0) CreateObject1
(@CGUID+30, 222619, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2114.145751953125, -2965.861083984375, 164.1006927490234375, 0, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Meandering Shalehorn (Area: The Proscenium - Difficulty: 0) CreateObject1
(@CGUID+31, 222619, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2052.36181640625, -3045.39794921875, 156.8350372314453125, 0.391732782125473022, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Meandering Shalehorn (Area: The Proscenium - Difficulty: 0) CreateObject1
(@CGUID+32, 222619, 2552, 14717, 14776, '0', 0, 0, 0, 0, 2225.318115234375, -2934.476318359375, 169.8880157470703125, 3.397005558013916015, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Meandering Shalehorn (Area: The Proscenium - Difficulty: 0) CreateObject1
(@CGUID+33, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1990.0052490234375, -2920.314208984375, 156.457672119140625, 2.108306407928466796, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+34, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2044.107666015625, -2852.6025390625, 163.8665008544921875, 4.170077323913574218, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: 106562 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+35, 221645, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2048.345458984375, -2802.388916015625, 156.973846435546875, 5.405470848083496093, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Freefoot Mouse (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+36, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2039.30908203125, -2898.3369140625, 168.1781158447265625, 2.330615997314453125, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+37, 221528, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2002.5382080078125, -2793.100830078125, 152.436767578125, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Soaring Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+38, 221528, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2107.067626953125, -2823.8056640625, 177.26361083984375, 3.182725191116333007, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Soaring Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+39, 221642, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1982.954833984375, -2930.236083984375, 157.57171630859375, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+40, 221642, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1982.954833984375, -2930.236083984375, 157.57171630859375, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+41, 221641, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1982.954833984375, -2930.236083984375, 157.57171630859375, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Ramolith Stonecrusher (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+42, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2132.444580078125, -2782.038330078125, 174.10595703125, 5.485352039337158203, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+43, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2121.208251953125, -2837.7275390625, 174.3382110595703125, 2.596964836120605468, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+44, 221645, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2108.270751953125, -2783.1181640625, 163.686798095703125, 3.03032231330871582, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Freefoot Mouse (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+45, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2086.828125, -2775.4931640625, 163.23834228515625, 0.26731044054031372, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: 106562 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+46, 221645, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1993.3194580078125, -2750.307373046875, 145.193145751953125, 0.051155917346477508, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Freefoot Mouse (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+47, 221519, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2021.032958984375, -2667.451416015625, 146.0946044921875, 5.105098247528076171, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Fluttering Sapphire (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+48, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2094.3837890625, -2735.69091796875, 165.19329833984375, 1.930549025535583496, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+49, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2000.8333740234375, -2684.145751953125, 137.188018798828125, 2.95973062515258789, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+50, 221642, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2076.65625, -2758.482666015625, 161.1803131103515625, 1.896942734718322753, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+51, 221641, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2076.65625, -2758.482666015625, 161.1803131103515625, 1.896831393241882324, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Ramolith Stonecrusher (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+52, 221646, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2017.1910400390625, -2735.15966796875, 163.173065185546875, 3.672112464904785156, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Hungry Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+53, 221645, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2044.7569580078125, -2693.2431640625, 148.5457916259765625, 0.932676136493682861, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Freefoot Mouse (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+54, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2027.642333984375, -2748.241455078125, 150.8108673095703125, 3.237847089767456054, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+55, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2062.223876953125, -2734.005126953125, 158.808746337890625, 3.662876129150390625, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+56, 221642, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2076.65625, -2758.482666015625, 161.1803131103515625, 1.896831393241882324, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Ramolith Stonecrusher (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+57, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2012.8975830078125, -2580.947998046875, 131.669097900390625, 5.71903228759765625, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: 106562 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+58, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2025.99658203125, -2613.28125, 137.8802337646484375, 1.068828582763671875, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+59, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2072.576416015625, -2631.32470703125, 146.8342132568359375, 4.122696876525878906, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: 106562 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+60, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2054.80029296875, -2549.682373046875, 139.660675048828125, 5.571977615356445312, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+61, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2068.897705078125, -2592.201416015625, 143.112823486328125, 0.719358623027801513, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+62, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2035.734375, -2562.12158203125, 136.6454925537109375, 4.574154853820800781, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+63, 221525, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1902.8367919921875, -2714.921875, 136.766387939453125, 2.094764471054077148, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Prairie Dog (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+64, 221525, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1911.28125, -2660.3212890625, 140.8081512451171875, 0.657572269439697265, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Prairie Dog (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+65, 221645, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1913.01220703125, -2662.510498046875, 140.7534637451171875, 5.426654815673828125, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Freefoot Mouse (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+66, 221525, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1916.517333984375, -2693.6494140625, 138.38323974609375, 2.991041898727416992, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Prairie Dog (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+67, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1956, -2663.263916015625, 127.7353134155273437, 4.105051994323730468, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: 106562 - Cosmetic - Sleep Zzz Breakable) (possible waypoints or random movement)
(@CGUID+68, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1943.6961669921875, -2731.369873046875, 134.409576416015625, 2.443819522857666015, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+69, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1905.8177490234375, -2745.994873046875, 132.1458892822265625, 3.395481348037719726, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: 106562 - Cosmetic - Sleep Zzz Breakable) (possible waypoints or random movement)
(@CGUID+70, 221646, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1910.1475830078125, -2762.751708984375, 146.6321258544921875, 4.592832565307617187, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Hungry Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+71, 221642, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1965.907958984375, -2894.036376953125, 152.2807464599609375, 1.57934725284576416, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+72, 221642, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1965.907958984375, -2894.036376953125, 152.2807464599609375, 1.57934725284576416, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+73, 221641, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1965.907958984375, -2894.036376953125, 152.2807464599609375, 1.57934725284576416, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Ramolith Stonecrusher (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+74, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1806.8004150390625, -2886.22216796875, 141.3608245849609375, 0.797879338264465332, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+75, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1855.0555419921875, -2899.350830078125, 154.0193939208984375, 1.563138961791992187, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+76, 221644, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1825.7691650390625, -2923.526123046875, 158.454864501953125, 1.178097367286682128, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Soaring Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+77, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1909.6458740234375, -2902.06591796875, 149.392730712890625, 5.073873043060302734, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+78, 221646, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1898.7379150390625, -2886.010498046875, 157.12701416015625, 3.226455926895141601, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Hungry Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+79, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1927.123291015625, -2960.083251953125, 165.035919189453125, 4.539125442504882812, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+80, 221523, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1939.5382080078125, -2959.314208984375, 156.8670196533203125, 1.068151235580444335, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Dazzling Peafowl (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+81, 221645, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1774.9410400390625, -2759.9931640625, 129.417327880859375, 5.778303146362304687, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Freefoot Mouse (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+82, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1681.623291015625, -2889.975830078125, 143.894378662109375, 0.623718023300170898, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+83, 221523, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1717.923583984375, -2849.904541015625, 145.1402435302734375, 5.924172401428222656, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Dazzling Peafowl (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: 106562 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+84, 221522, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1705.7239990234375, -2847.130126953125, 142.85516357421875, 0, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Plains Peachick (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+85, 221522, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1718.1319580078125, -2824.4619140625, 144.921875, 0, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Plains Peachick (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+86, 221523, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1718.310791015625, -2854.717041015625, 146.12115478515625, 0.412396460771560668, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Dazzling Peafowl (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: 106562 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+87, 221523, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1715.2760009765625, -2844.350830078125, 145.8768463134765625, 3.226471662521362304, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Dazzling Peafowl (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+88, 221522, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1739.9566650390625, -2876.03125, 148.5084991455078125, 0, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Plains Peachick (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+89, 221645, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1698.0416259765625, -2748.890625, 131.5449066162109375, 6.046814918518066406, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Freefoot Mouse (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+90, 221645, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1709.93408203125, -2777.49658203125, 139.254150390625, 4.443140506744384765, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Freefoot Mouse (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+91, 221525, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1714.2552490234375, -2796.05908203125, 142.0340423583984375, 2.676555156707763671, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Prairie Dog (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+92, 221523, 2552, 14717, 0, '0', 0, 0, 0, 0, 1853.3958740234375, -3026.072998046875, 152.004058837890625, 1.29598093032836914, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Dazzling Peafowl (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+93, 221523, 2552, 14717, 0, '0', 0, 0, 0, 0, 1804.2100830078125, -3052.5, 145.8252410888671875, 4.690117835998535156, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388); -- Dazzling Peafowl (Area: 0 - Difficulty: 0) CreateObject2
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+93;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+37, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Soaring Plainshawk
(@CGUID+38, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Soaring Plainshawk

-- Template
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=222223; -- Watchful Falcon
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219171; -- Velvetfur Ferret
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=222618; -- Alert Shalehorn
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=222619; -- Meandering Shalehorn
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x4000000 WHERE `entry`=221523; -- Dazzling Peafowl
UPDATE `creature_template` SET `faction`=188, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=221522; -- Plains Peachick
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x4000000 WHERE `entry`=221523; -- Dazzling Peafowl

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=56819 WHERE (`Entry`=222618 AND `DifficultyID`=0); -- 222618 (Alert Shalehorn) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x30000000, `VerifiedBuild`=56819 WHERE (`Entry`=222223 AND `DifficultyID`=0); -- 222223 (Watchful Falcon) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=56819 WHERE (`Entry`=222619 AND `DifficultyID`=0); -- 222619 (Meandering Shalehorn) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=0x10000000, `VerifiedBuild`=56819 WHERE (`Entry`=219171 AND `DifficultyID`=0); -- 219171 (Velvetfur Ferret) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57388 WHERE (`Entry`=221523 AND `DifficultyID`=0); -- 221523 (Dazzling Peafowl) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=0x10000000, `VerifiedBuild`=57388 WHERE (`Entry`=221522 AND `DifficultyID`=0); -- 221522 (Plains Peachick) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57388 WHERE (`Entry`=221523 AND `DifficultyID`=0); -- 221523 (Dazzling Peafowl) - CanSwim

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID` IN (114943, 114939, 121887, 121886, 118628);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(114943, 1.990490317344665527, 2.40000009536743164, 0, 57388),
(114939, 1.990490317344665527, 2.40000009536743164, 0, 57388),
(121887, 1.990490317344665527, 2.40000009536743164, 0, 57388),
(121886, 1.990490317344665527, 2.40000009536743164, 0, 57388),
(118628, 0.5, 1, 0, 57388);

-- Path for Watchful Falcon
SET @MOVERGUID := @CGUID+5;
SET @ENTRY := 222223;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 8.1677, 'Watchful Falcon - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2196.9946, -2945.0405, 197.24214, NULL, 0),
(@PATH, 1, 2182.064, -2941.665, 197.24214, NULL, 0),
(@PATH, 2, 2173.8933, -2928.721, 197.24214, NULL, 0),
(@PATH, 3, 2177.2686, -2913.7903, 197.24214, NULL, 0),
(@PATH, 4, 2190.213, -2905.6196, 197.24214, NULL, 0),
(@PATH, 5, 2205.1436, -2908.9949, 197.24214, NULL, 0),
(@PATH, 6, 2213.3142, -2921.9392, 197.24214, NULL, 0),
(@PATH, 7, 2209.9387, -2936.8699, 197.24214, NULL, 0);

UPDATE `creature` SET `position_x`=2196.9946, `position_y`=-2945.0405, `position_z`=197.24214, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Watchful Falcon
SET @MOVERGUID := @CGUID+19;
SET @ENTRY := 222223;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 8.1678, 'Watchful Falcon - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2075.2163, -2991.0513, 185.3083, NULL, 0),
(@PATH, 1, 2087.6167, -2982.0764, 185.3083, NULL, 0),
(@PATH, 2, 2102.7312, -2984.4985, 185.3083, NULL, 0),
(@PATH, 3, 2111.706, -2996.8987, 185.3083, NULL, 0),
(@PATH, 4, 2109.2837, -3012.0132, 185.3083, NULL, 0),
(@PATH, 5, 2096.8835, -3020.988, 185.3083, NULL, 0),
(@PATH, 6, 2081.769, -3018.566, 185.3083, NULL, 0),
(@PATH, 7, 2072.7942, -3006.1655, 185.3083, NULL, 0);

UPDATE `creature` SET `position_x`=2075.2163, `position_y`=-2991.0513, `position_z`=185.3083, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Watchful Falcon
SET @MOVERGUID := @CGUID+22;
SET @ENTRY := 222223;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 8.1678, 'Watchful Falcon - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2045.3755, -3066.8794, 175.60196, NULL, 0),
(@PATH, 1, 2059.1184, -3073.6208, 175.60196, NULL, 0),
(@PATH, 2, 2064.069, -3088.1057, 175.60196, NULL, 0),
(@PATH, 3, 2057.3274, -3101.8484, 175.60196, NULL, 0),
(@PATH, 4, 2042.8429, -3106.799, 175.60196, NULL, 0),
(@PATH, 5, 2029.1, -3100.0576, 175.60196, NULL, 0),
(@PATH, 6, 2024.1493, -3085.573, 175.60196, NULL, 0),
(@PATH, 7, 2030.8909, -3071.83, 175.60196, NULL, 0);

UPDATE `creature` SET `position_x`=2045.3755, `position_y`=-3066.8794, `position_z`=175.60196, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Ramolith Stonecrusher
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+41;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+41, @CGUID+41, 0, 0, 515, 0, 0),
(@CGUID+41, @CGUID+40, 4, 0, 515, 0, 0),
(@CGUID+41, @CGUID+39, 3, 290, 515, 0, 0);

SET @MOVERGUID := @CGUID+41;
SET @ENTRY := 221641;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Ramolith Stonecrusher - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2015.665, -2917.795, 159.5261, NULL, 0),
(@PATH, 1, 2031.1267, -2904.6562, 162.81262, NULL, 0),
(@PATH, 2, 2049.1165, -2889.9653, 164.41124, NULL, 0),
(@PATH, 3, 2066.052, -2871.9548, 165.7251, NULL, 0),
(@PATH, 4, 2085.566, -2842.625, 168.23795, NULL, 0),
(@PATH, 5, 2086.8196, -2825.1528, 164.11855, NULL, 0),
(@PATH, 6, 2085.566, -2842.625, 168.23795, NULL, 0),
(@PATH, 7, 2066.052, -2871.9548, 165.7251, NULL, 0),
(@PATH, 8, 2031.1267, -2904.6562, 162.81262, NULL, 0),
(@PATH, 9, 2015.7743, -2917.7656, 159.4567, NULL, 0),
(@PATH, 10, 1988.8976, -2927.4548, 157.17873, NULL, 0);

UPDATE `creature` SET `position_x`=2015.665, `position_y`=-2917.795, `position_z`=159.5261, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid` =@MOVERGUID;
UPDATE `creature` SET `position_x`=2015.665, `position_y`=-2917.795, `position_z`=159.5261, `orientation`=0 WHERE `guid` IN (@CGUID+40, @CGUID+39);
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Ramolith Stonecrusher
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+51;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+51, @CGUID+51, 0, 0, 515, 0, 0),
(@CGUID+51, @CGUID+50, 4, 0, 515, 0, 0),
(@CGUID+51, @CGUID+56, 3, 290, 515, 0, 0);

SET @MOVERGUID := @CGUID+51;
SET @ENTRY := 221641;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Ramolith Stonecrusher - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2062.2275, -2723.1216, 156.19382, NULL, 0),
(@PATH, 1, 2052.9758, -2709.0469, 153.76369, NULL, 0),
(@PATH, 2, 2041.5, -2694.8264, 148.54344, NULL, 0),
(@PATH, 3, 2024.9062, -2653.2483, 139.61098, NULL, 0),
(@PATH, 4, 2003.8264, -2627.875, 130.13744, NULL, 0),
(@PATH, 5, 1975.316, -2619.309, 126.40309, NULL, 0),
(@PATH, 6, 1951.6736, -2636.5312, 124.58308, NULL, 0),
(@PATH, 7, 1957.5486, -2656.5122, 126.57661, NULL, 0),
(@PATH, 8, 1962.118, -2680.8264, 131.92188, NULL, 0),
(@PATH, 9, 1958.2396, -2696.6008, 133.12231, NULL, 0),
(@PATH, 10, 1954.316, -2716.8665, 134.33733, NULL, 0),
(@PATH, 11, 1961.8889, -2738.0713, 134.48709, NULL, 0),
(@PATH, 12, 1965.2871, -2761.838, 138.71294, NULL, 0),
(@PATH, 13, 1968.1445, -2780.6152, 143.60983, NULL, 0),
(@PATH, 14, 1977.2676, -2806.0332, 146.11546, NULL, 0),
(@PATH, 15, 1982.7952, -2819.8472, 150.26672, NULL, 0),
(@PATH, 16, 1985.8195, -2823.0417, 151.23688, NULL, 0),
(@PATH, 17, 2076.0034, -2756.4253, 160.94507, NULL, 0),
(@PATH, 18, 2071.257, -2742.5347, 160.70638, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Ramolith Stonecrusher
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+73;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+73, @CGUID+73, 0, 0, 515, 0, 0),
(@CGUID+73, @CGUID+72, 4, 0, 515, 0, 0),
(@CGUID+73, @CGUID+71, 3, 290, 515, 0, 0);

SET @MOVERGUID := @CGUID+73;
SET @ENTRY := 221641;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Ramolith Stonecrusher - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1965.0955, -2867.462, 151.69421, NULL, 0),
(@PATH, 1, 1968.1719, -2845.2188, 148.04239, NULL, 0),
(@PATH, 2, 1966.749, -2814.2793, 146.30638, NULL, 0),
(@PATH, 3, 1969.7622, -2794.0173, 144.76895, NULL, 0),
(@PATH, 4, 1971.3524, -2776.1338, 143.5238, NULL, 0),
(@PATH, 5, 1936.3854, -2776.3472, 134.90073, NULL, 0),
(@PATH, 6, 1892.125, -2796.019, 125.84455, NULL, 0),
(@PATH, 7, 1864.1389, -2804.1145, 128.11363, NULL, 0),
(@PATH, 8, 1844.8629, -2806.9236, 130.44437, NULL, 0),
(@PATH, 9, 1821.9723, -2810.1926, 131.74252, NULL, 0),
(@PATH, 10, 1799.3872, -2807.0781, 138.07526, NULL, 0),
(@PATH, 11, 1776.3629, -2817.1284, 141.5937, NULL, 0),
(@PATH, 12, 1781.4236, -2838.3281, 146.15869, NULL, 0),
(@PATH, 13, 1789.7743, -2869.3682, 143.74213, NULL, 0),
(@PATH, 14, 1814.1962, -2895.8682, 141.48743, NULL, 0),
(@PATH, 15, 1857.2014, -2902.0764, 146.73743, NULL, 0),
(@PATH, 16, 1872.2882, -2913.0574, 149.06194, NULL, 0),
(@PATH, 17, 1901.9863, -2921.957, 150.12895, NULL, 0),
(@PATH, 18, 1922.7848, -2918.4983, 151.7362, NULL, 0),
(@PATH, 19, 1964.7084, -2890.4878, 151.20941, NULL, 0),
(@PATH, 20, 1965.7552, -2876.6946, 151.09651, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Soaring Plainshawk
SET @MOVERGUID := @CGUID+76;
SET @ENTRY := 221644;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8683, 'Soaring Plainshawk - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1830.1626, -2912.9194, 158.45486, NULL, 0),
(@PATH, 1, 1840.7692, -2908.5261, 158.45486, NULL, 0),
(@PATH, 2, 1851.3757, -2912.9194, 158.45486, NULL, 0),
(@PATH, 3, 1855.7692, -2923.5261, 158.45486, NULL, 0),
(@PATH, 4, 1851.3757, -2934.1328, 158.45486, NULL, 0),
(@PATH, 5, 1840.7692, -2938.5261, 158.45486, NULL, 0),
(@PATH, 6, 1830.1626, -2934.1328, 158.45486, NULL, 0),
(@PATH, 7, 1825.7692, -2923.5261, 158.45486, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Soaring Plainshawk
SET @MOVERGUID := 10000809;
SET @ENTRY := 221644;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8683, 'Soaring Plainshawk - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1722.0966, -2766.7786, 163.56966, NULL, 0),
(@PATH, 1, 1732.7031, -2771.1719, 163.56966, NULL, 0),
(@PATH, 2, 1743.3097, -2766.7786, 163.56966, NULL, 0),
(@PATH, 3, 1747.7031, -2756.1719, 163.56966, NULL, 0),
(@PATH, 4, 1743.3097, -2745.5652, 163.56966, NULL, 0),
(@PATH, 5, 1732.7031, -2741.1719, 163.56966, NULL, 0),
(@PATH, 6, 1722.0966, -2745.5652, 163.56966, NULL, 0),
(@PATH, 7, 1717.7031, -2756.1719, 163.56966, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
