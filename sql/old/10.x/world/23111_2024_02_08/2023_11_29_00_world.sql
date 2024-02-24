SET @CGUID := 7000031;
SET @OGUID := 7000142;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+222;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 130680, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -879.08392333984375, 2148.897216796875, 692.653564453125, 4.51165628433227539, 7200, 10, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Goldshell Scuttler (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+1, 127757, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -773.01312255859375, 2146.70166015625, 705.84100341796875, 5.364300251007080078, 7200, 3, 0, 84936, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Reanimated Honor Guard (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255960 - Bad Voodoo, 256956 - Bad Voodoo - Dummy)
(@CGUID+2, 130678, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -818.3526611328125, 2145.214111328125, 692.653564453125, 4.295135498046875, 7200, 10, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Poisonous Gekkota (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+3, 127352, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -833.30035400390625, 2070.31591796875, 725.20745849609375, 0.623969554901123046, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Risen Honor Guard (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 252737 - Honor Guard Sleep)
(@CGUID+4, 127352, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -863.201416015625, 2146.19970703125, 692.71234130859375, 4.301091194152832031, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Risen Honor Guard (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 252737 - Honor Guard Sleep)
(@CGUID+5, 120652, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -848.560791015625, 2072.99658203125, 725.22796630859375, 4.624306678771972656, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Global Affix Stalker (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+6, 127352, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -844.513916015625, 2098.798583984375, 727.70599365234375, 5.627816677093505859, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Risen Honor Guard (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 252737 - Honor Guard Sleep)
(@CGUID+7, 130678, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -859.6409912109375, 2091.584228515625, 725.99139404296875, 3.638842105865478515, 7200, 10, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Poisonous Gekkota (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+8, 130678, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -860.31597900390625, 2145.88671875, 692.77056884765625, 1.374134421348571777, 7200, 10, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Poisonous Gekkota (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+9, 127352, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -864.09722900390625, 2079.578125, 725.2069091796875, 3.948627948760986328, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Risen Honor Guard (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 252737 - Honor Guard Sleep)
(@CGUID+10, 127315, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -770.67535400390625, 2151.14404296875, 705.76153564453125, 3.573521614074707031, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Reanimation Totem (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+11, 130680, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -875.22515869140625, 2057.271728515625, 725.9913330078125, 6.11855316162109375, 7200, 10, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Goldshell Scuttler (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+12, 127352, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -837.40277099609375, 2150.782958984375, 692.7169189453125, 2.783057689666748046, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Risen Honor Guard (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 252737 - Honor Guard Sleep)
(@CGUID+13, 130678, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -823.92645263671875, 2087.77587890625, 725.991455078125, 0.045113202184438705, 7200, 10, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Poisonous Gekkota (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+14, 127352, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -816.953125, 2142.604248046875, 692.7149658203125, 1.535500407218933105, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Risen Honor Guard (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 252737 - Honor Guard Sleep)
(@CGUID+15, 127352, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -856.76739501953125, 2194.8837890625, 678.31854248046875, 2.933136463165283203, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Risen Honor Guard (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 252737 - Honor Guard Sleep)
(@CGUID+16, 128435, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -844.85589599609375, 2242.970458984375, 677.8359375, 1.985951662063598632, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Toxic Saurid (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255894 - Poisoned Claws)
(@CGUID+17, 127799, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -940.3680419921875, 2148.569580078125, 705.76629638671875, 5.780410289764404296, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Dazar'ai Honor Guard (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+18, 122971, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -994.63543701171875, 2174.751708984375, 705.7257080078125, 5.717124462127685546, 7200, 0, 0, 81397, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Dazar'ai Juggernaut (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+19, 127352, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -730.94793701171875, 2141.161376953125, 705.76873779296875, 0.879902005195617675, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Risen Honor Guard (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 252737 - Honor Guard Sleep)
(@CGUID+20, 128434, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -943.39410400390625, 2190.35595703125, 665.1400146484375, 0.33617401123046875, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Feasting Skyscreamer (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 123978 - Mod Scale 95-120%)
(@CGUID+21, 127352, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -703.1632080078125, 2191.185791015625, 705.76214599609375, 3.295352935791015625, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Risen Honor Guard (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 252737 - Honor Guard Sleep)
(@CGUID+22, 122973, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -989.77081298828125, 2185.9150390625, 705.758056640625, 5.44956207275390625, 7200, 0, 0, 70780, 18070, 0, NULL, NULL, NULL, NULL, 52188), -- Dazar'ai Confessor (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+23, 128435, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -784.84893798828125, 2194.786376953125, 665.3043212890625, 3.038234233856201171, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Toxic Saurid (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255894 - Poisoned Claws)
(@CGUID+24, 128434, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -856.326416015625, 2245.1494140625, 680.9688720703125, 5.186097145080566406, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Feasting Skyscreamer (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 123978 - Mod Scale 95-120%)
(@CGUID+25, 128435, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -852.609375, 2190.694580078125, 678.32098388671875, 0.732817232608795166, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Toxic Saurid (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255894 - Poisoned Claws)
(@CGUID+26, 127352, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -786.0538330078125, 2192.90283203125, 662.2403564453125, 1.33616650104522705, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Risen Honor Guard (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 252737 - Honor Guard Sleep)
(@CGUID+27, 122973, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -994.9617919921875, 2170.44091796875, 705.24725341796875, 5.934119224548339843, 7200, 0, 0, 70780, 18070, 0, NULL, NULL, NULL, NULL, 52188), -- Dazar'ai Confessor (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+28, 128435, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -845.984375, 2246.710205078125, 677.8055419921875, 4.725109577178955078, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Toxic Saurid (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255894 - Poisoned Claws)
(@CGUID+29, 122969, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -728.0711669921875, 2143.4150390625, 705.7686767578125, 3.655416488647460937, 7200, 0, 0, 63702, 18070, 0, NULL, NULL, NULL, NULL, 52188), -- Zanchuli Witch-Doctor (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 123978 - Mod Scale 95-120%)
(@CGUID+30, 122972, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -1004.401123046875, 2148.013916015625, 705.7708740234375, 0.567355573177337646, 7200, 0, 0, 70780, 18070, 0, NULL, NULL, NULL, NULL, 52188), -- Dazar'ai Augur (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+31, 122971, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -964.76214599609375, 2158.98779296875, 705.989013671875, 6.048663139343261718, 7200, 0, 0, 81397, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Dazar'ai Juggernaut (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+32, 130678, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -879.26422119140625, 2242.828857421875, 641.9967041015625, 2.593777179718017578, 7200, 8, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Poisonous Gekkota (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+33, 127352, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -833.5694580078125, 2194.270751953125, 678.31207275390625, 1.857377529144287109, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Risen Honor Guard (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 252737 - Honor Guard Sleep)
(@CGUID+34, 127799, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -940.6007080078125, 2142.84375, 705.76776123046875, 1.052170157432556152, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Dazar'ai Honor Guard (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+35, 130680, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -924.435791015625, 2187.390625, 662.24725341796875, 5.335638046264648437, 7200, 6, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Goldshell Scuttler (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+36, 128435, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -787.71527099609375, 2188.96533203125, 662.2403564453125, 3.13679051399230957, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Toxic Saurid (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255894 - Poisoned Claws)
(@CGUID+37, 127757, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -729.81640625, 2150.49609375, 705.24725341796875, 6.108325481414794921, 7200, 3, 0, 84936, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Reanimated Honor Guard (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255967 - Bad Voodoo, 256956 - Bad Voodoo - Dummy)
(@CGUID+38, 128435, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -855.8680419921875, 2193.291748046875, 678.3140869140625, 1.828930616378784179, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Toxic Saurid (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255894 - Poisoned Claws)
(@CGUID+39, 127352, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -791.265625, 2187.151123046875, 662.2403564453125, 5.714879512786865234, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Risen Honor Guard (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 252737 - Honor Guard Sleep)
(@CGUID+40, 127352, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -850.64410400390625, 2191.61279296875, 678.32012939453125, 0.976584374904632568, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Risen Honor Guard (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 252737 - Honor Guard Sleep)
(@CGUID+41, 128435, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -849.13543701171875, 2241.329833984375, 677.77850341796875, 3.595347404479980468, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Toxic Saurid (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255894 - Poisoned Claws)
(@CGUID+42, 135989, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -936.47918701171875, 2146.770751953125, 705.76593017578125, 3.17913365364074707, 7200, 0, 0, 70072, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Shieldbearer of Zul (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%, 257568 - Cosmetic Aura, 141048 - Stealth and Invisibility Detection [DNT])
(@CGUID+43, 122973, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -969.1024169921875, 2154.373291015625, 705.72552490234375, 6.228983402252197265, 7200, 0, 0, 70780, 18070, 0, NULL, NULL, NULL, NULL, 52188), -- Dazar'ai Confessor (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+44, 122972, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -967.21356201171875, 2164.876708984375, 706.0172119140625, 5.814768314361572265, 7200, 0, 0, 70780, 18070, 0, NULL, NULL, NULL, NULL, 52188), -- Dazar'ai Augur (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+45, 128435, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -848.84027099609375, 2193.692626953125, 678.04901123046875, 4.155405998229980468, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Toxic Saurid (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255894 - Poisoned Claws)
(@CGUID+46, 130678, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -700.4266357421875, 2164.72216796875, 705.8409423828125, 3.592861175537109375, 7200, 6, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Poisonous Gekkota (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+47, 127352, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -850.21527099609375, 2240.529541015625, 677.8118896484375, 1.963768720626831054, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Risen Honor Guard (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 252737 - Honor Guard Sleep)
(@CGUID+48, 127879, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -727.56201171875, 2168.410400390625, 705.84100341796875, 0.770574808120727539, 7200, 0, 0, 77858, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Shieldbearer of Zul (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%, 257568 - Cosmetic Aura, 141048 - Stealth and Invisibility Detection [DNT])
(@CGUID+49, 130679, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -799.1944580078125, 2189.329833984375, 662.2471923828125, 6.040395736694335937, 7200, 10, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Temple Snake (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+50, 128435, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -848.74652099609375, 2243.302001953125, 677.76953125, 0.179554581642150878, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Toxic Saurid (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255894 - Poisoned Claws)
(@CGUID+51, 127352, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -845.8992919921875, 2244.060791015625, 677.80828857421875, 0.446586549282073974, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Risen Honor Guard (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 252737 - Honor Guard Sleep)
(@CGUID+52, 127352, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -724.08160400390625, 2151.204833984375, 705.76739501953125, 0.224438428878784179, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Risen Honor Guard (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 252737 - Honor Guard Sleep)
(@CGUID+53, 128434, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -879.44268798828125, 2269.864501953125, 691.0430908203125, 1.246177196502685546, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Feasting Skyscreamer (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 123978 - Mod Scale 95-120%)
(@CGUID+54, 128435, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -788.5850830078125, 2193.710205078125, 662.2403564453125, 6.118176460266113281, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Toxic Saurid (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255894 - Poisoned Claws)
(@CGUID+55, 128435, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -850.90106201171875, 2239.439208984375, 677.8341064453125, 1.46741342544555664, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Toxic Saurid (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255894 - Poisoned Claws)
(@CGUID+56, 122971, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -938.4930419921875, 2157.197998046875, 705.7637939453125, 5.587091445922851562, 7200, 0, 0, 81397, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Dazar'ai Juggernaut (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+57, 128434, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -927.328125, 2207.90283203125, 664.1473388671875, 4.786040306091308593, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Feasting Skyscreamer (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 123978 - Mod Scale 95-120%)
(@CGUID+58, 127879, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -727.71875, 2139.26220703125, 705.7698974609375, 3.34220433235168457, 7200, 0, 0, 77858, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Shieldbearer of Zul (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%, 257568 - Cosmetic Aura, 141048 - Stealth and Invisibility Detection [DNT])
(@CGUID+59, 130679, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -729.208251953125, 2136.181640625, 705.84100341796875, 4.731421470642089843, 7200, 0, 0, 2831, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Temple Snake (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+60, 128435, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -790.0867919921875, 2189.5712890625, 662.2403564453125, 4.47552347183227539, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Toxic Saurid (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255894 - Poisoned Claws)
(@CGUID+61, 135989, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -934.85418701171875, 2153.85595703125, 705.76544189453125, 2.335720539093017578, 7200, 0, 0, 70072, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Shieldbearer of Zul (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%, 257568 - Cosmetic Aura, 141048 - Stealth and Invisibility Detection [DNT])
(@CGUID+62, 128435, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -854.6336669921875, 2197.314208984375, 678.32342529296875, 4.108931541442871093, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Toxic Saurid (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255894 - Poisoned Claws)
(@CGUID+63, 122984, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -997.092041015625, 2182.611083984375, 706.2071533203125, 5.621304988861083984, 7200, 0, 0, 120326, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Dazar'ai Colossus (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 254958 - Soulforged Construct, 141048 - Stealth and Invisibility Detection [DNT])
(@CGUID+64, 127315, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -729.390625, 2145.78125, 705.76885986328125, 4.427501201629638671, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Reanimation Totem (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+65, 122972, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -984.16143798828125, 2187.22216796875, 705.758056640625, 5.362247943878173828, 7200, 0, 0, 70780, 18070, 0, NULL, NULL, NULL, NULL, 52188), -- Dazar'ai Augur (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+66, 122971, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -1000.06951904296875, 2143.70654296875, 705.7734375, 2.031732082366943359, 7200, 0, 0, 81397, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Dazar'ai Juggernaut (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+67, 128435, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -849.4305419921875, 2190.954833984375, 678.04901123046875, 2.234563589096069335, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Toxic Saurid (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255894 - Poisoned Claws)
(@CGUID+68, 127879, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -729.6319580078125, 2170.500732421875, 705.84100341796875, 0.7976875901222229, 7200, 0, 0, 77858, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Shieldbearer of Zul (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%, 257568 - Cosmetic Aura, 141048 - Stealth and Invisibility Detection [DNT])
(@CGUID+69, 128435, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -793.515625, 2186.694580078125, 662.2403564453125, 0.062369633466005325, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Toxic Saurid (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255894 - Poisoned Claws)
(@CGUID+70, 122971, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -991.10089111328125, 2208.607177734375, 705.8409423828125, 1.56832122802734375, 7200, 0, 0, 81397, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Dazar'ai Juggernaut (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+71, 127352, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -956.0382080078125, 2227.873291015625, 662.24853515625, 0.77999192476272583, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Risen Honor Guard (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 252737 - Honor Guard Sleep)
(@CGUID+72, 127352, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -955.02777099609375, 2236.63720703125, 662.2449951171875, 3.963501691818237304, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Risen Honor Guard (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 252737 - Honor Guard Sleep)
(@CGUID+73, 122969, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -701.732666015625, 2194.609375, 705.76214599609375, 4.316590785980224609, 7200, 0, 0, 63702, 18070, 0, NULL, NULL, NULL, NULL, 52188), -- Zanchuli Witch-Doctor (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 123978 - Mod Scale 95-120%)
(@CGUID+74, 127315, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -698.8125, 2190.817626953125, 705.76214599609375, 4.655211925506591796, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Reanimation Totem (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+75, 127757, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -693.6007080078125, 2195.119873046875, 705.841064453125, 3.953847169876098632, 7200, 3, 0, 84936, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Reanimated Honor Guard (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255968 - Bad Voodoo, 256956 - Bad Voodoo - Dummy)
(@CGUID+76, 127879, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -697.09027099609375, 2186.710205078125, 705.76214599609375, 3.926842689514160156, 7200, 0, 0, 77858, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Shieldbearer of Zul (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%, 257568 - Cosmetic Aura, 141048 - Stealth and Invisibility Detection [DNT])
(@CGUID+77, 128435, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -884.467041015625, 2287.23095703125, 677.953857421875, 2.571131706237792968, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Toxic Saurid (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255894 - Poisoned Claws)
(@CGUID+78, 127352, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -885.13543701171875, 2288.335205078125, 677.90618896484375, 3.067486524581909179, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Risen Honor Guard (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 252737 - Honor Guard Sleep)
(@CGUID+79, 130678, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -953.667236328125, 2239.0849609375, 662.247314453125, 4.424492835998535156, 7200, 10, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Poisonous Gekkota (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+80, 130679, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -745.07916259765625, 2234.11083984375, 662.24725341796875, 3.686456680297851562, 7200, 6, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Temple Snake (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+81, 130679, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -843.09356689453125, 2285.428955078125, 678.4814453125, 3.242713212966918945, 7200, 10, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Temple Snake (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+82, 128435, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -885.36285400390625, 2289.661376953125, 677.84619140625, 4.699065685272216796, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Toxic Saurid (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255894 - Poisoned Claws)
(@CGUID+83, 130678, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -861.25970458984375, 2268.21142578125, 644.5755615234375, 2.782968759536743164, 7200, 8, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Poisonous Gekkota (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+84, 130680, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -836.9970703125, 2265.284912109375, 642.6138916015625, 2.007321357727050781, 7200, 0, 0, 2831, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Goldshell Scuttler (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+85, 128434, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -800.63018798828125, 2284.4375, 680.9742431640625, 2.602713823318481445, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Feasting Skyscreamer (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 123978 - Mod Scale 95-120%)
(@CGUID+86, 130680, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -733.685546875, 2224.552734375, 663.0921630859375, 3.376913070678710937, 7200, 6, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Goldshell Scuttler (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+87, 128435, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -807.25177001953125, 2296.4931640625, 677.906005859375, 4.995004653930664062, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Toxic Saurid (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255894 - Poisoned Claws)
(@CGUID+88, 130678, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -797.4454345703125, 2286.23779296875, 678.182861328125, 3.074682235717773437, 7200, 6, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Poisonous Gekkota (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+89, 128435, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -884.904541015625, 2294.21875, 677.8316650390625, 3.089670658111572265, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Toxic Saurid (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255894 - Poisoned Claws)
(@CGUID+90, 127352, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -801.7569580078125, 2290.76220703125, 677.7872314453125, 3.861353635787963867, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Risen Honor Guard (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 252737 - Honor Guard Sleep)
(@CGUID+91, 122963, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -895.67926025390625, 2274.459228515625, 642.32220458984375, 1.516122221946716308, 7200, 0, 0, 495460, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Rezan (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+92, 128435, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -808.90972900390625, 2293.388916015625, 677.7794189453125, 0.387643873691558837, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Toxic Saurid (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255894 - Poisoned Claws)
(@CGUID+93, 128435, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -888.74652099609375, 2294.8994140625, 677.80657958984375, 5.828828811645507812, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Toxic Saurid (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255894 - Poisoned Claws)
(@CGUID+94, 128435, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -848.69854736328125, 2299.43994140625, 678.5118408203125, 1.569059371948242187, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Toxic Saurid (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255894 - Poisoned Claws)
(@CGUID+95, 130680, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -869.44921875, 2285.55078125, 678.244873046875, 1.156540751457214355, 7200, 10, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Goldshell Scuttler (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+96, 127352, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -806.8367919921875, 2294.520751953125, 677.81640625, 3.905434608459472656, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Risen Honor Guard (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 252737 - Honor Guard Sleep)
(@CGUID+97, 128435, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -800.201416015625, 2292.4375, 677.7613525390625, 3.982561349868774414, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Toxic Saurid (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255894 - Poisoned Claws)
(@CGUID+98, 128435, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -804.38018798828125, 2291.029541015625, 677.763916015625, 0.125474840402603149, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Toxic Saurid (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255894 - Poisoned Claws)
(@CGUID+99, 127879, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -696.6805419921875, 2230.880126953125, 705.76336669921875, 4.406280994415283203, 7200, 0, 0, 77858, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Shieldbearer of Zul (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%, 257568 - Cosmetic Aura, 141048 - Stealth and Invisibility Detection [DNT])
(@CGUID+100, 127352, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -886.34375, 2293.77783203125, 677.7864990234375, 1.550305366516113281, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Risen Honor Guard (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 252737 - Honor Guard Sleep)
(@CGUID+101, 128435, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -802.22393798828125, 2288.553955078125, 677.83197021484375, 1.459046363830566406, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Toxic Saurid (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255894 - Poisoned Claws)
(@CGUID+102, 130679, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -679.91217041015625, 2192.26513671875, 705.84100341796875, 1.227792143821716308, 7200, 0, 0, 2831, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Temple Snake (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+103, 128435, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -886.951416015625, 2290.897705078125, 677.79547119140625, 1.28327345848083496, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Toxic Saurid (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255894 - Poisoned Claws)
(@CGUID+104, 127315, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -699.7586669921875, 2243.2431640625, 705.76385498046875, 2.01109933853149414, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Reanimation Totem (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+105, 128435, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -847.68939208984375, 2304.3017578125, 678.361328125, 1.568718552589416503, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Toxic Saurid (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255894 - Poisoned Claws)
(@CGUID+106, 129552, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -844.155029296875, 2303.7373046875, 679.28912353515625, 1.568707942962646484, 7200, 0, 0, 144391, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Monzumi (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+107, 128435, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -920.53643798828125, 2290.28466796875, 677.7542724609375, 1.973983407020568847, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Toxic Saurid (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255894 - Poisoned Claws)
(@CGUID+108, 128435, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -919.64239501953125, 2293.05908203125, 677.761962890625, 3.196370601654052734, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Toxic Saurid (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255894 - Poisoned Claws)
(@CGUID+109, 127879, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -690.2742919921875, 2231.201416015625, 705.7652587890625, 4.894147396087646484, 7200, 0, 0, 77858, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Shieldbearer of Zul (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%, 257568 - Cosmetic Aura, 141048 - Stealth and Invisibility Detection [DNT])
(@CGUID+110, 128455, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -851.22607421875, 2303.752197265625, 679.28912353515625, 1.568707942962646484, 7200, 0, 0, 141560, 0, 0, NULL, NULL, NULL, NULL, 52188), -- T'lonja (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+111, 122969, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -703.25177001953125, 2244.2431640625, 705.76312255859375, 4.115313529968261718, 7200, 0, 0, 63702, 18070, 0, NULL, NULL, NULL, NULL, 52188), -- Zanchuli Witch-Doctor (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 123978 - Mod Scale 95-120%)
(@CGUID+112, 128435, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -764.52777099609375, 2288.703125, 677.9342041015625, 1.399469256401062011, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Toxic Saurid (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255894 - Poisoned Claws)
(@CGUID+113, 130679, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -807.71435546875, 2282.662841796875, 641.79541015625, 6.038660049438476562, 7200, 10, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Temple Snake (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+114, 127352, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -921.076416015625, 2292.62841796875, 677.7528076171875, 4.642620563507080078, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Risen Honor Guard (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 252737 - Honor Guard Sleep)
(@CGUID+115, 128435, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -849.6934814453125, 2301.516357421875, 678.411865234375, 1.569324612617492675, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Toxic Saurid (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255894 - Poisoned Claws)
(@CGUID+116, 128435, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -922.61285400390625, 2292.350830078125, 677.74700927734375, 6.02665567398071289, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Toxic Saurid (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255894 - Poisoned Claws)
(@CGUID+117, 128435, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -845.69683837890625, 2301.51220703125, 678.39080810546875, 1.568113446235656738, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Toxic Saurid (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255894 - Poisoned Claws)
(@CGUID+118, 130678, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -999.58892822265625, 2229.705810546875, 705.84100341796875, 4.170212745666503906, 7200, 10, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Poisonous Gekkota (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+119, 127757, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -695.74468994140625, 2238.114990234375, 705.8409423828125, 2.840140581130981445, 7200, 3, 0, 84936, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Reanimated Honor Guard (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255970 - Bad Voodoo, 256956 - Bad Voodoo - Dummy)
(@CGUID+120, 128435, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -765.65277099609375, 2291.489501953125, 677.79931640625, 5.800620079040527343, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Toxic Saurid (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255894 - Poisoned Claws)
(@CGUID+121, 129553, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -847.68231201171875, 2307.685791015625, 678.279296875, 1.568709731101989746, 7200, 0, 0, 169872, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Dinomancer Kish'o (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+122, 127352, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -770.04168701171875, 2295.873291015625, 677.8209228515625, 5.579017162322998046, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Risen Honor Guard (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 252737 - Honor Guard Sleep)
(@CGUID+123, 128434, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -919.55035400390625, 2300.18408203125, 678.33380126953125, 3.050086498260498046, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Feasting Skyscreamer (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 123978 - Mod Scale 95-120%)
(@CGUID+124, 130679, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -1044.2646484375, 2150.34765625, 717.04412841796875, 5.686460494995117187, 7200, 10, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Temple Snake (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+125, 128434, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -768.24481201171875, 2300.954833984375, 680.76904296875, 5.749906539916992187, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Feasting Skyscreamer (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 123978 - Mod Scale 95-120%)
(@CGUID+126, 128435, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -762.8038330078125, 2291.123291015625, 677.80548095703125, 4.224608421325683593, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Toxic Saurid (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255894 - Poisoned Claws)
(@CGUID+127, 130679, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -888.04791259765625, 2286.264404296875, 643.30487060546875, 2.280898332595825195, 7200, 10, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Temple Snake (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+128, 128435, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -922.58160400390625, 2294.37158203125, 677.798828125, 5.242909908294677734, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Toxic Saurid (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255894 - Poisoned Claws)
(@CGUID+129, 129985, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -974.92706298828125, 2270.03125, 686.934814453125, 1.570796370506286621, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Tiki Mask (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+130, 128435, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -771.55902099609375, 2298.2587890625, 677.9989013671875, 5.253190040588378906, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Toxic Saurid (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255894 - Poisoned Claws)
(@CGUID+131, 127352, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -763.92706298828125, 2290.296875, 677.82464599609375, 2.680580377578735351, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Risen Honor Guard (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 252737 - Honor Guard Sleep)
(@CGUID+132, 128435, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -771, 2294.239501953125, 677.7012939453125, 0.665159642696380615, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Toxic Saurid (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255894 - Poisoned Claws)
(@CGUID+133, 130680, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -700.27734375, 2250.56640625, 705.84100341796875, 0.543601810932159423, 7200, 6, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Goldshell Scuttler (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+134, 130678, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -1058.2874755859375, 2151.1689453125, 717.0491943359375, 4.405092716217041015, 7200, 10, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Poisonous Gekkota (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+135, 130679, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -824.37786865234375, 2303.42919921875, 642.621337890625, 0.876897454261779785, 7200, 10, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Temple Snake (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+136, 122972, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -967.33331298828125, 2290.270751953125, 680.9151611328125, 0.252334505319595336, 7200, 0, 0, 70780, 18070, 0, NULL, NULL, NULL, NULL, 52188), -- Dazar'ai Augur (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+137, 127799, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -962.248291015625, 2287.6875, 680.91741943359375, 0.801671147346496582, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Dazar'ai Honor Guard (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+138, 129985, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -957.68231201171875, 2293.585205078125, 673.275146484375, 0, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Tiki Mask (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 257685 - Tiki Mask)
(@CGUID+139, 127879, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -731.97052001953125, 2285.87841796875, 680.9180908203125, 3.128293752670288085, 7200, 0, 0, 77858, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Shieldbearer of Zul (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%, 257568 - Cosmetic Aura, 141048 - Stealth and Invisibility Detection [DNT])
(@CGUID+140, 130678, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -730.48046875, 2278.12890625, 681.04248046875, 0.348303020000457763, 7200, 0, 0, 2831, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Poisonous Gekkota (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+141, 128434, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -874.09027099609375, 2319.854248046875, 695.2012939453125, 5.724257946014404296, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Feasting Skyscreamer (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 123978 - Mod Scale 95-120%)
(@CGUID+142, 122969, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -731.68402099609375, 2290.963623046875, 680.9197998046875, 2.823445081710815429, 7200, 0, 0, 63702, 18070, 0, NULL, NULL, NULL, NULL, 52188), -- Zanchuli Witch-Doctor (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 123978 - Mod Scale 95-120%)
(@CGUID+143, 122969, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -730.44268798828125, 2294.046875, 681.18878173828125, 3.358532190322875976, 7200, 0, 0, 63702, 18070, 0, NULL, NULL, NULL, NULL, 52188), -- Zanchuli Witch-Doctor (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 123978 - Mod Scale 95-120%, 258727 - Ritual Voodoo)
(@CGUID+144, 129985, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -1000.598876953125, 2270.03125, 699.2056884765625, 1.570796370506286621, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Tiki Mask (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+145, 127879, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -732.513916015625, 2298.85595703125, 680.918212890625, 3.624039173126220703, 7200, 0, 0, 77858, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Shieldbearer of Zul (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%, 257568 - Cosmetic Aura, 141048 - Stealth and Invisibility Detection [DNT])
(@CGUID+146, 129985, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -1015.55548095703125, 2270.03125, 711.22418212890625, 1.570796370506286621, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Tiki Mask (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 257685 - Tiki Mask)
(@CGUID+147, 130679, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -796.05377197265625, 2305.63720703125, 641.27874755859375, 3.955721378326416015, 7200, 10, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Temple Snake (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+148, 122972, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -966.79864501953125, 2296.204833984375, 680.9150390625, 6.207649707794189453, 7200, 0, 0, 70780, 18070, 0, NULL, NULL, NULL, NULL, 52188), -- Dazar'ai Augur (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+149, 130679, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -854.10107421875, 2329.419921875, 678.13433837890625, 5.999964714050292968, 7200, 10, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Temple Snake (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+150, 127799, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -963.310791015625, 2299.37158203125, 680.9168701171875, 6.202130317687988281, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Dazar'ai Honor Guard (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+151, 122971, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -1054.0035400390625, 2224.27783203125, 741.0364990234375, 4.756319522857666015, 7200, 0, 0, 81397, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Dazar'ai Juggernaut (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+152, 130678, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -859.75274658203125, 2316.446533203125, 642.486083984375, 5.758289337158203125, 7200, 10, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Poisonous Gekkota (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+153, 122972, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -1047.3992919921875, 2223.8681640625, 741.0364990234375, 4.590658187866210937, 7200, 0, 0, 70780, 18070, 0, NULL, NULL, NULL, NULL, 52188), -- Dazar'ai Augur (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+154, 130680, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -831.1378173828125, 2321.738525390625, 643.114990234375, 0.43214687705039978, 7200, 6, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Goldshell Scuttler (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+155, 129985, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -974.92706298828125, 2315.208251953125, 687.81982421875, 4.712388992309570312, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Tiki Mask (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+156, 130680, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -893.71014404296875, 2337.8779296875, 642.486083984375, 0.983833849430084228, 7200, 10, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Goldshell Scuttler (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+157, 130680, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -834.10150146484375, 2344.170654296875, 642.91253662109375, 2.686678409576416015, 7200, 10, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Goldshell Scuttler (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+158, 130678, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -726.88165283203125, 2304.991455078125, 680.91375732421875, 1.411447405815124511, 7200, 0, 0, 2831, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Poisonous Gekkota (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+159, 130680, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -882.767822265625, 2341.73046875, 642.54217529296875, 3.078077316284179687, 7200, 0, 0, 2831, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Goldshell Scuttler (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+160, 122969, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -655.515625, 2281.2900390625, 708.0631103515625, 2.295832395553588867, 7200, 0, 0, 63702, 18070, 0, NULL, NULL, NULL, NULL, 52188), -- Zanchuli Witch-Doctor (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 123978 - Mod Scale 95-120%)
(@CGUID+161, 127352, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -699.34552001953125, 2341.6962890625, 705.76397705078125, 4.173900127410888671, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Risen Honor Guard (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 252737 - Honor Guard Sleep)
(@CGUID+162, 129985, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -1000.598876953125, 2315.208251953125, 700.0904541015625, 4.712388992309570312, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Tiki Mask (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+163, 129985, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -1015.55548095703125, 2315.208251953125, 712.1094970703125, 4.712388992309570312, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Tiki Mask (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 257685 - Tiki Mask)
(@CGUID+164, 127352, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -663.5225830078125, 2303.317626953125, 707.51702880859375, 4.47273874282836914, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Risen Honor Guard (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 252737 - Honor Guard Sleep)
(@CGUID+165, 125977, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -636.02777099609375, 2269.217041015625, 709.9739990234375, 3.116801738739013671, 7200, 0, 0, 56624, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Reanimation Totem (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+166, 127352, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -656.359375, 2283.998291015625, 707.642578125, 0.73479008674621582, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Risen Honor Guard (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 252737 - Honor Guard Sleep)
(@CGUID+167, 127315, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -652.90972900390625, 2293.005126953125, 709.36700439453125, 2.069970369338989257, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Reanimation Totem (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+168, 130678, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -1088.27734375, 2227.421875, 740.78399658203125, 3.297425031661987304, 7200, 10, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Poisonous Gekkota (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+169, 127757, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -659.35150146484375, 2288.814208984375, 706.04339599609375, 1.378377914428710937, 7200, 3, 0, 84936, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Reanimated Honor Guard (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255972 - Bad Voodoo, 256956 - Bad Voodoo - Dummy)
(@CGUID+170, 122969, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -655.48614501953125, 2302.067626953125, 708.7017822265625, 4.545207977294921875, 7200, 0, 0, 63702, 18070, 0, NULL, NULL, NULL, NULL, 52188), -- Zanchuli Witch-Doctor (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 123978 - Mod Scale 95-120%)
(@CGUID+171, 130679, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -597.58331298828125, 2266.152587890625, 709.841064453125, 5.260217666625976562, 7200, 10, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Temple Snake (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+172, 127315, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -698.58160400390625, 2357.79345703125, 705.7635498046875, 1.028818011283874511, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Reanimation Totem (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+173, 122965, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -616.35418701171875, 2292.71875, 709.8065185546875, 3.221103906631469726, 7200, 0, 0, 445914, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Vol'kaal (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 250192 - Bad Voodoo)
(@CGUID+174, 127352, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -690.27081298828125, 2350.96875, 705.7657470703125, 5.199552536010742187, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Risen Honor Guard (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 252737 - Honor Guard Sleep)
(@CGUID+175, 132126, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -1090.8992919921875, 2286.338623046875, 740.6871337890625, 5.5116729736328125, 7200, 0, 0, 70780, 100, 0, NULL, NULL, NULL, NULL, 52188), -- Gilded Priestess (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+176, 122971, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -1093.7847900390625, 2294.11279296875, 741.27947998046875, 0.261781275272369384, 7200, 0, 0, 81397, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Dazar'ai Juggernaut (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+177, 127757, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -709.36468505859375, 2358.17333984375, 706.0054931640625, 2.663568735122680664, 7200, 3, 0, 84936, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Reanimated Honor Guard (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255971 - Bad Voodoo, 256956 - Bad Voodoo - Dummy)
(@CGUID+178, 127799, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -1092.236083984375, 2303.116455078125, 740.6871337890625, 0.801671147346496582, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Dazar'ai Honor Guard (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+179, 122972, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -1086.5364990234375, 2289.835205078125, 740.68701171875, 0.349243223667144775, 7200, 0, 0, 70780, 18070, 0, NULL, NULL, NULL, NULL, 52188), -- Dazar'ai Augur (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+180, 127799, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -1087.3004150390625, 2299.23779296875, 740.68707275390625, 0.889429748058319091, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Dazar'ai Honor Guard (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+181, 125977, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -591.23956298828125, 2292.442626953125, 709.9677734375, 3.116801738739013671, 7200, 0, 0, 56624, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Reanimation Totem (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+182, 130678, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -704.8436279296875, 2361.9384765625, 705.9151611328125, 1.241296768188476562, 7200, 10, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Poisonous Gekkota (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+183, 122969, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -701.68231201171875, 2359.80908203125, 705.76287841796875, 1.763882994651794433, 7200, 0, 0, 63702, 18070, 0, NULL, NULL, NULL, NULL, 52188), -- Zanchuli Witch-Doctor (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 123978 - Mod Scale 95-120%)
(@CGUID+184, 127757, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -698.42535400390625, 2352.99609375, 705.9326171875, 1.930976510047912597, 7200, 3, 0, 84936, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Reanimated Honor Guard (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255971 - Bad Voodoo, 256956 - Bad Voodoo - Dummy)
(@CGUID+185, 127799, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -1094.9757080078125, 2281.882080078125, 740.687255859375, 5.449492454528808593, 7200, 0, 0, 70780, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Dazar'ai Honor Guard (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+186, 125977, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -636.18927001953125, 2316.12158203125, 709.962890625, 3.116801738739013671, 7200, 0, 0, 56624, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Reanimation Totem (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+187, 132126, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -1097.1754150390625, 2249.79345703125, 740.6873779296875, 2.515300750732421875, 7200, 0, 0, 70780, 100, 0, NULL, NULL, NULL, NULL, 52188), -- Gilded Priestess (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+188, 131289, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -865.25, 2473.49658203125, 734.50604248046875, 0, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Shadowflame (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+189, 122968, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -847.5694580078125, 2467.100830078125, 734.311767578125, 4.684121608734130859, 7200, 0, 0, 552084, 100, 0, NULL, NULL, NULL, NULL, 52188), -- Yazma (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+190, 122967, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -1119.7066650390625, 2292.36279296875, 745.197509765625, 3.100947380065917968, 7200, 0, 0, 637020, 100, 0, NULL, NULL, NULL, NULL, 52188), -- Priestess Alun'za (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 258386 - Ritual)
(@CGUID+191, 131289, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -830.40802001953125, 2473.380126953125, 734.50604248046875, 0, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Shadowflame (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+192, 128956, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -1110.49658203125, 2259.4306640625, 741.76031494140625, 0.093232475221157073, 7200, 0, 0, 495460, 9035, 0, NULL, NULL, NULL, NULL, 52188), -- Blood-Tainted Cauldron of Gold (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (Auras: 255619 - Blood-Tainted Cauldron of Gold)
(@CGUID+193, 130680, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -1053.545166015625, 2349.40966796875, 740.4503173828125, 0.329934179782867431, 7200, 10, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Goldshell Scuttler (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+194, 131289, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -883.36285400390625, 2523.971435546875, 734.5064697265625, 0, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Shadowflame (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+195, 130680, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -640.04144287109375, 2326.565185546875, 710.13360595703125, 2.856304645538330078, 7200, 10, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Goldshell Scuttler (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+196, 131289, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -812.3125, 2523.663330078125, 734.50604248046875, 0, 7200, 0, 0, 14156, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Shadowflame (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+197, 130681, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -667.87847900390625, 2362.234375, 716.01531982421875, 5.630397319793701171, 7200, 0, 0, 2831, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Glitterlight Flitter (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+198, 130681, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -724.56549072265625, 2417.338623046875, 710.72357177734375, 1.104001045227050781, 7200, 0, 0, 2831, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Glitterlight Flitter (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+199, 130681, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -663.57684326171875, 2382.419189453125, 715.6981201171875, 5.609563350677490234, 7200, 0, 0, 2831, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Glitterlight Flitter (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+200, 130686, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -700.4127197265625, 2421.146240234375, 707.66168212890625, 6.246387958526611328, 7200, 10, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Mountaintop Croaker (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+201, 130686, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -679.9019775390625, 2404.12109375, 708.36651611328125, 6.258326530456542968, 7200, 0, 0, 2831, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Mountaintop Croaker (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+202, 130681, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -648.0745849609375, 2380.338134765625, 721.87054443359375, 5.193470954895019531, 7200, 10, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Glitterlight Flitter (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+203, 130681, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -748.7474365234375, 2437.3056640625, 707.23590087890625, 3.318969964981079101, 7200, 10, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Glitterlight Flitter (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+204, 130686, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -700.66668701171875, 2430.681640625, 707.55645751953125, 1.010955333709716796, 7200, 10, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Mountaintop Croaker (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+205, 130681, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -716.76025390625, 2448.9794921875, 715.53594970703125, 5.222360134124755859, 7200, 10, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Glitterlight Flitter (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+206, 130686, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -697.57403564453125, 2452.199951171875, 707.9005126953125, 2.491846561431884765, 7200, 10, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Mountaintop Croaker (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+207, 132126, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 0, -1096.685791015625, 2334.303955078125, 740.6873779296875, 3.718596935272216796, 7200, 0, 0, 70780, 100, 0, NULL, NULL, NULL, NULL, 52188), -- Gilded Priestess (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@CGUID+208, 130681, 1763, 9028, 9382, '1,2,23,8', 0, 0, 0, 0, -674.9610595703125, 2449.23974609375, 711.18011474609375, 2.120967388153076171, 7200, 10, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Glitterlight Flitter (Area: Sacrificial Pits - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+209, 128956, 1763, 9028, 9382, '1,2,23,8', 0, 0, 0, 0, -1110.545166015625, 2325.282958984375, 741.76031494140625, 0.093232475221157073, 7200, 0, 0, 495460, 9035, 0, NULL, NULL, NULL, NULL, 52188), -- Blood-Tainted Cauldron of Gold (Area: Sacrificial Pits - Difficulty: Mythic) CreateObject1 (Auras: 255619 - Blood-Tainted Cauldron of Gold)
(@CGUID+210, 130678, 1763, 9028, 9382, '1,2,23,8', 0, 0, 0, 0, -1103.5208740234375, 2356.295166015625, 740.78399658203125, 5.132504463195800781, 7200, 10, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Poisonous Gekkota (Area: Sacrificial Pits - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+211, 130681, 1763, 9028, 9382, '1,2,23,8', 0, 0, 0, 0, -620.89068603515625, 2409.718017578125, 710.2015380859375, 6.207088947296142578, 7200, 10, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Glitterlight Flitter (Area: Sacrificial Pits - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+212, 130681, 1763, 9028, 9382, '1,2,23,8', 0, 0, 0, 0, -631.39398193359375, 2441.041748046875, 715.26446533203125, 5.469112396240234375, 7200, 10, 0, 2831, 0, 1, NULL, NULL, NULL, NULL, 52188), -- Glitterlight Flitter (Area: Sacrificial Pits - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+213, 122970, 1763, 9028, 0, '1,2,23,8', 0, 0, 0, 1, -782.85772705078125, 2147.662109375, 705.841064453125, 6.265757083892822265, 7200, 10, 0, 70780, 100, 1, NULL, NULL, NULL, NULL, 52188), -- Shadowblade Stalker (Area: 0 - Difficulty: Mythic) CreateObject1 (Auras: 123167 - Mod Scale 95-100%, 252661 - Venom-Tipped Blade, 252703 - Stealth) (possible waypoints or random movement)
(@CGUID+214, 122970, 1763, 9028, 0, '1,2,23,8', 0, 0, 0, 1, -706.4716796875, 2212.2236328125, 705.84100341796875, 1.579848051071166992, 7200, 10, 0, 70780, 100, 1, NULL, NULL, NULL, NULL, 52188), -- Shadowblade Stalker (Area: 0 - Difficulty: Mythic) CreateObject1 (Auras: 123167 - Mod Scale 95-100%, 252703 - Stealth, 252661 - Venom-Tipped Blade) (possible waypoints or random movement)
(@CGUID+215, 122970, 1763, 9028, 0, '1,2,23,8', 0, 0, 0, 1, -682.81451416015625, 2294.48583984375, 702.273193359375, 3.126766204833984375, 7200, 10, 0, 70780, 100, 1, NULL, NULL, NULL, NULL, 52188), -- Shadowblade Stalker (Area: 0 - Difficulty: Mythic) CreateObject1 (Auras: 123167 - Mod Scale 95-100%, 252703 - Stealth, 252661 - Venom-Tipped Blade) (possible waypoints or random movement)
(@CGUID+216, 122970, 1763, 9028, 0, '1,2,23,8', 0, 0, 0, 1, -682.86968994140625, 2290.486083984375, 702.250732421875, 3.126706361770629882, 7200, 10, 0, 70780, 100, 1, NULL, NULL, NULL, NULL, 52188), -- Shadowblade Stalker (Area: 0 - Difficulty: Mythic) CreateObject1 (Auras: 123167 - Mod Scale 95-100%, 252661 - Venom-Tipped Blade, 252703 - Stealth) (possible waypoints or random movement)
(@CGUID+217, 122971, 1763, 9028, 0, '1,2,23,8', 0, 0, 0, 1, -1051.3199462890625, 2210.679931640625, 734.4210205078125, 0, 7200, 0, 0, 81397, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Dazar'ai Juggernaut (Area: 0 - Difficulty: Mythic) CreateObject2 (Auras: )
(@CGUID+218, 122973, 1763, 9028, 0, '1,2,23,8', 0, 0, 0, 1, -1051.3199462890625, 2210.679931640625, 734.4210205078125, 0, 7200, 0, 0, 70780, 18070, 0, NULL, NULL, NULL, NULL, 52188), -- Dazar'ai Confessor (Area: 0 - Difficulty: Mythic) CreateObject2 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+219, 122972, 1763, 9028, 0, '1,2,23,8', 0, 0, 0, 1, -1051.3199462890625, 2210.679931640625, 734.4210205078125, 0, 7200, 0, 0, 70780, 18070, 0, NULL, NULL, NULL, NULL, 52188), -- Dazar'ai Augur (Area: 0 - Difficulty: Mythic) CreateObject2 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+220, 122984, 1763, 9028, 0, '1,2,23,8', 0, 0, 0, 0, -1051.3199462890625, 2210.679931640625, 734.4210205078125, 6.209408283233642578, 7200, 0, 0, 120326, 0, 0, NULL, NULL, NULL, NULL, 52188), -- Dazar'ai Colossus (Area: 0 - Difficulty: Mythic) CreateObject2 (Auras: 254958 - Soulforged Construct)
(@CGUID+221, 122970, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -739.34722900390625, 2113.154541015625, 715.1943359375, 1.635016798973083496, 7200, 0, 0, 80465, 100, 0, NULL, NULL, NULL, NULL, 52188), -- Shadowblade Stalker (Area: Atal'Dazar - Difficulty: 0) CreateObject1 (Auras: 123167 - Mod Scale 95-100%)
(@CGUID+222, 122970, 1763, 9028, 9028, '1,2,23,8', 0, 0, 0, 1, -744.18231201171875, 2112.92529296875, 715.3468017578125, 1.635016798973083496, 7200, 0, 0, 80465, 100, 0, NULL, NULL, NULL, NULL, 52188); -- Shadowblade Stalker (Area: Atal'Dazar - Difficulty: Normal) CreateObject2 (Auras: 123167 - Mod Scale 95-100%)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+222;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+17, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, '237007'), -- Dazar'ai Honor Guard - 237007 - Mod Scale 90-100%
(@CGUID+18, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Dazar'ai Juggernaut
(@CGUID+22, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Dazar'ai Confessor
(@CGUID+30, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, '237007'), -- Dazar'ai Augur - 237007 - Mod Scale 90-100%
(@CGUID+31, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Dazar'ai Juggernaut
(@CGUID+34, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, '237007'), -- Dazar'ai Honor Guard - 237007 - Mod Scale 90-100%
(@CGUID+43, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, '237007'), -- Dazar'ai Confessor - 237007 - Mod Scale 90-100%
(@CGUID+44, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, '237007'), -- Dazar'ai Augur - 237007 - Mod Scale 90-100%
(@CGUID+56, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 4, ''), -- Dazar'ai Juggernaut
(@CGUID+58, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, '237007 257568 141048'), -- Shieldbearer of Zul - 237007 - Mod Scale 90-100%, 257568 - Cosmetic Aura, 141048 - Stealth and Invisibility Detection [DNT]
(@CGUID+63, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 4, '254958 141048'), -- Dazar'ai Colossus - 254958 - Soulforged Construct, 141048 - Stealth and Invisibility Detection [DNT]
(@CGUID+65, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Dazar'ai Augur
(@CGUID+66, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Dazar'ai Juggernaut
(@CGUID+68, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '237007 257568 141048'), -- Shieldbearer of Zul - 237007 - Mod Scale 90-100%, 257568 - Cosmetic Aura, 141048 - Stealth and Invisibility Detection [DNT]
(@CGUID+76, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, '237007 257568 141048'), -- Shieldbearer of Zul - 237007 - Mod Scale 90-100%, 257568 - Cosmetic Aura, 141048 - Stealth and Invisibility Detection [DNT]
(@CGUID+99, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, '237007 257568 141048'), -- Shieldbearer of Zul - 237007 - Mod Scale 90-100%, 257568 - Cosmetic Aura, 141048 - Stealth and Invisibility Detection [DNT]
(@CGUID+109, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, '237007 257568 141048'), -- Shieldbearer of Zul - 237007 - Mod Scale 90-100%, 257568 - Cosmetic Aura, 141048 - Stealth and Invisibility Detection [DNT]
(@CGUID+136, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 4, '237007'), -- Dazar'ai Augur - 237007 - Mod Scale 90-100%
(@CGUID+137, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, '237007'), -- Dazar'ai Honor Guard - 237007 - Mod Scale 90-100%
(@CGUID+139, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, '237007 257568 141048'), -- Shieldbearer of Zul - 237007 - Mod Scale 90-100%, 257568 - Cosmetic Aura, 141048 - Stealth and Invisibility Detection [DNT]
(@CGUID+145, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, '237007 257568 141048'), -- Shieldbearer of Zul - 237007 - Mod Scale 90-100%, 257568 - Cosmetic Aura, 141048 - Stealth and Invisibility Detection [DNT]
(@CGUID+148, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, '237007'), -- Dazar'ai Augur - 237007 - Mod Scale 90-100%
(@CGUID+150, 0, 0, 0, 0, 0, 1, 0, 733, 0, 0, 0, 4, '237007'), -- Dazar'ai Honor Guard - 237007 - Mod Scale 90-100%
(@CGUID+151, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Dazar'ai Juggernaut
(@CGUID+153, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, '237007'), -- Dazar'ai Augur - 237007 - Mod Scale 90-100%
(@CGUID+175, 0, 0, 0, 0, 0, 1, 0, 733, 0, 0, 0, 0, ''), -- Gilded Priestess
(@CGUID+176, 0, 0, 0, 0, 0, 1, 0, 714, 0, 0, 0, 4, ''), -- Dazar'ai Juggernaut
(@CGUID+178, 0, 0, 0, 0, 0, 1, 0, 734, 0, 0, 0, 4, '237007'), -- Dazar'ai Honor Guard - 237007 - Mod Scale 90-100%
(@CGUID+179, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, '237007'), -- Dazar'ai Augur - 237007 - Mod Scale 90-100%
(@CGUID+180, 0, 0, 0, 0, 0, 1, 0, 433, 0, 0, 0, 4, '237007'), -- Dazar'ai Honor Guard - 237007 - Mod Scale 90-100%
(@CGUID+185, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, '237007'), -- Dazar'ai Honor Guard - 237007 - Mod Scale 90-100%
(@CGUID+215, 0, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 4, '123167 252661 252703'), -- Shadowblade Stalker - 123167 - Mod Scale 95-100%, 252661 - Venom-Tipped Blade, 252703 - Stealth
(@CGUID+217, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 4, ''), -- Dazar'ai Juggernaut
(@CGUID+218, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, '237007'), -- Dazar'ai Confessor - 237007 - Mod Scale 90-100%
(@CGUID+219, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, '237007'), -- Dazar'ai Augur - 237007 - Mod Scale 90-100%
(@CGUID+220, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 4, '254958'), -- Dazar'ai Colossus - 254958 - Soulforged Construct
(@CGUID+221, 0, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 4, '123167 252661 252703'), -- Shadowblade Stalker - 123167 - Mod Scale 95-100%, 252661 - Venom-Tipped Blade, 252703 - Stealth
(@CGUID+222, 0, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 4, '123167 252661 252703'); -- Shadowblade Stalker - 123167 - Mod Scale 95-100%, 252661 - Venom-Tipped Blade, 252703 - Stealth

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+20;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 246779, 1763, 9028, 9028, '23', 0, 0, -848.30206298828125, 2105.291748046875, 727.3809814453125, 0, 0, 0, 0, 1, 7200, 255, 1, 52188), -- Font of Power (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@OGUID+1, 278820, 1763, 9028, 9028, '1,2,23,8', 0, 0, -911.57989501953125, 2147.010498046875, 704.99041748046875, 0, 0, -0.70710659027099609, 0, 0.707106947898864746, 7200, 255, 1, 52188), -- Collision Wall (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@OGUID+2, 276643, 1763, 9028, 9028, '1,2,23,8', 0, 0, -849.076416015625, 2044.1666259765625, 729.69415283203125, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 1, 52188), -- Instance Portal (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@OGUID+3, 249386, 1763, 9028, 9028, '1,2,23,8', 0, 0, -940.97393798828125, 2254.960205078125, 642.75860595703125, 1.550428628921508789, 0, 0, 0.699869155883789062, 0.714271068572998046, 7200, 255, 1, 52188), -- Arcane Barrier (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@OGUID+4, 249386, 1763, 9028, 9028, '1,2,23,8', 0, 0, -940.97393798828125, 2267.723876953125, 642.75860595703125, 1.550428628921508789, 0, 0, 0.699869155883789062, 0.714271068572998046, 7200, 255, 1, 52188), -- Arcane Barrier (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@OGUID+5, 288202, 1763, 9028, 9028, '1,2,23,8', 0, 0, -739.553466796875, 2288.6064453125, 681.2730712890625, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 52188), -- Doodad_8DU_CityofGold_Gate003 (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@OGUID+6, 288204, 1763, 9028, 9028, '1,2,23,8', 0, 0, -955.9854736328125, 2288.6064453125, 681.2730712890625, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 52188), -- Doodad_8DU_CityofGold_Gate001 (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@OGUID+7, 288205, 1763, 9028, 9028, '1,2,23,8', 0, 0, -955.9854736328125, 2296.698486328125, 681.2730712890625, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 52188), -- Doodad_8DU_CityofGold_Gate002 (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@OGUID+8, 288203, 1763, 9028, 9028, '1,2,23,8', 0, 0, -739.553466796875, 2296.698486328125, 681.2730712890625, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 52188), -- Doodad_8DU_CityofGold_Gate004 (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@OGUID+9, 249386, 1763, 9028, 9028, '1,2,23,8', 0, 0, -941.65972900390625, 2318.263916015625, 642.75860595703125, 1.515627145767211914, 0, 0, 0.687335014343261718, 0.726340532302856445, 7200, 255, 1, 52188), -- Arcane Barrier (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@OGUID+10, 288478, 1763, 9028, 9028, '1,2,23,8', 0, 0, -965.96722412109375, 2279.492431640625, 681.54559326171875, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 52188), -- Ancient Switch (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@OGUID+11, 288477, 1763, 9028, 9028, '1,2,23,8', 0, 0, -729.3082275390625, 2279.52001953125, 681.54559326171875, 0, 0, 0, 0, 1, 7200, 255, 1, 52188), -- Ancient Switch (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@OGUID+12, 249386, 1763, 9028, 9028, '1,2,23,8', 0, 0, -941.19097900390625, 2331.30908203125, 642.75860595703125, 1.515627145767211914, 0, 0, 0.687335014343261718, 0.726340532302856445, 7200, 255, 1, 52188), -- Arcane Barrier (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@OGUID+13, 292402, 1763, 9028, 9028, '1,2,23,8', 0, 0, -649.21533203125, 2280.24072265625, 711.623779296875, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 0, 52188), -- Doodad_8DU_CityofGold_Gate005 (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@OGUID+14, 278422, 1763, 9028, 9028, '1,2,23,8', 0, 0, -847.7703857421875, 2415.89013671875, 678.25006103515625, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 7200, 255, 1, 52188), -- Doodad_8DU_CityofGold_WaterfallStairs001 (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@OGUID+15, 292399, 1763, 9028, 9028, '1,2,23,8', 0, 0, -649.21533203125, 2288.388671875, 711.623779296875, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 0, 52188), -- Doodad_8DU_CityofGold_Gate006 (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@OGUID+16, 292401, 1763, 9028, 9028, '1,2,23,8', 0, 0, -649.21533203125, 2304.632568359375, 711.623779296875, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 0, 52188), -- Doodad_8DU_CityofGold_Gate008 (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@OGUID+17, 292400, 1763, 9028, 9028, '1,2,23,8', 0, 0, -649.21533203125, 2296.54638671875, 711.623779296875, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 0, 52188), -- Doodad_8DU_CityofGold_Gate007 (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@OGUID+18, 278820, 1763, 9028, 9028, '1,2,23,8', 0, 0, -847.69964599609375, 2389.782958984375, 678.36370849609375, 4.705675125122070312, 0, 0, -0.70947647094726562, 0.704729139804840087, 7200, 255, 1, 52188), -- Collision Wall (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@OGUID+19, 292398, 1763, 9028, 9028, '1,2,23,8', 0, 0, -880.58062744140625, 2469.369140625, 732.95025634765625, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 7200, 255, 0, 52188), -- Doodad_8DU_CityofGold_Gate010 (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
(@OGUID+20, 292397, 1763, 9028, 9028, '1,2,23,8', 0, 0, -815.11834716796875, 2469.369140625, 732.95025634765625, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 7200, 255, 0, 52188); -- Doodad_8DU_CityofGold_Gate009 (Area: Atal'Dazar - Difficulty: Mythic) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+20;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+5, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_8DU_CityofGold_Gate003
(@OGUID+6, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_8DU_CityofGold_Gate001
(@OGUID+7, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_8DU_CityofGold_Gate002
(@OGUID+8, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_8DU_CityofGold_Gate004
(@OGUID+10, 0, 0, 1, -0.00000004371138828, 0, 0), -- Ancient Switch
(@OGUID+11, 0, 0, 1, -0.00000004371138828, 0, 0), -- Ancient Switch
(@OGUID+13, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_8DU_CityofGold_Gate005
(@OGUID+14, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_8DU_CityofGold_WaterfallStairs001
(@OGUID+15, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_8DU_CityofGold_Gate006
(@OGUID+16, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_8DU_CityofGold_Gate008
(@OGUID+17, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_8DU_CityofGold_Gate007
(@OGUID+19, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_8DU_CityofGold_Gate010
(@OGUID+20, 0, 0, 1, -0.00000004371138828, 0, 0); -- Doodad_8DU_CityofGold_Gate009

-- Templates
UPDATE `creature_template` SET `unit_flags3`=16777217 WHERE `entry`=128956; -- Blood-Tainted Cauldron of Gold
UPDATE `creature_template` SET `unit_flags`=33088, `unit_flags3`=1 WHERE `entry`=122968; -- Yazma
UPDATE `creature_template` SET `unit_flags3`=8388608 WHERE `entry`=122963; -- Rezan
UPDATE `creature_template` SET `unit_flags3`=134217728 WHERE `entry`=128434; -- Feasting Skyscreamer
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags3`=67108864 WHERE `entry`=128435; -- Toxic Saurid
UPDATE `creature_template` SET `unit_flags3`=134217728 WHERE `entry`=122986; -- Wild Skyscreamer
UPDATE `creature_template` SET `unit_flags3`=67108864 WHERE `entry`=130902; -- Creepy Spider
UPDATE `creature_template` SET `flags_extra` = 128 WHERE `entry` = 120652; -- Global Affix Stalker

UPDATE `gameobject_template_addon` SET `flags`=2 WHERE `entry` IN (288477, 288478); -- Ancient Switch

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (130681, 128956, 122967, 122968, 122965, 125977, 129553, 128455, 129552, 122963, 122972, 122969, 122973, 128434, 122971, 127799, 128435, 127315, 127352, 129985, 122986);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(130681, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 130681 (Glitterlight Flitter)
(128956, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '255619'), -- 128956 (Blood-Tainted Cauldron of Gold) - Blood-Tainted Cauldron of Gold
(122967, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '258386'), -- 122967 (Priestess Alun'za) - Ritual
(122968, 0, 0, 0, 0, 0, 1, 0, 0, 1093, 0, 0, 5, ''), -- 122968 (Yazma)
(122965, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 122965 (Vol'kaal)
(125977, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 125977 (Reanimation Totem)
(129553, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 4, ''), -- 129553 (Dinomancer Kish'o)
(128455, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 128455 (T'lonja)
(129552, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 129552 (Monzumi)
(122963, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 122963 (Rezan)
(122972, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '237007'), -- 122972 (Dazar'ai Augur) - Mod Scale 90-100%
(122969, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '123978'), -- 122969 (Zanchuli Witch-Doctor) - Mod Scale 95-120%
(122973, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 122973 (Dazar'ai Confessor)
(128434, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '123978'), -- 128434 (Feasting Skyscreamer) - Mod Scale 95-120%
(122971, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 122971 (Dazar'ai Juggernaut)
(127799, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '237007'), -- 127799 (Dazar'ai Honor Guard) - Mod Scale 90-100%
(128435, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '255894'), -- 128435 (Toxic Saurid) - Poisoned Claws
(127315, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 127315 (Reanimation Totem)
(127352, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '252737'), -- 127352 (Risen Honor Guard) - Honor Guard Sleep
(129985, 0, 0, 0, 3, 0, 1, 0, 0, 10455, 0, 0, 4, '257685'), -- 129985 (Tiki Mask)
(122986, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 5, '123978'); -- 122986 (Wild Skyscreamer) - Mod Scale 95-120%

-- Creature Movement
DELETE FROM `creature_template_movement` WHERE `CreatureId` = 130681;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(130681, 0, 0, 1, 0, 0, 0, NULL);

-- AreaTrigger
DELETE FROM `areatrigger_template` WHERE (`IsServerSide`=0 AND `Id` IN (16503,16589,16644,16643));
INSERT INTO `areatrigger_template` (`Id`, `IsServerSide`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `VerifiedBuild`) VALUES
(16503, 0, 0, 4, 20, 20, 0, 0, 0, 0, 0, 0, 52188),
(16589, 0, 4, 4, 6.800000190734863281, 6.800000190734863281, 10, 10, 3, 3, 0, 0, 52188),
(16644, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 52188),
(16643, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 52188);

DELETE FROM `areatrigger_create_properties` WHERE `Id` IN (11814 /*Spell: 254958 (Soulforged Construct)*/, 11897 /*Spell: 255619 (Blood-Tainted Cauldron of Gold)*/, 11959 /*Spell: 256608 (Pile of Bones)*/, 11958 /*Spell: 256606 (Pile of Bones)*/);
INSERT INTO `areatrigger_create_properties` (`Id`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `VerifiedBuild`) VALUES
(11814, 16503, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 20, 20, 0, 0, 0, 0, 0, 0, 52188), -- Spell: 254958 (Soulforged Construct)
(11897, 16589, 0, 0, 0, 0, -1, 0, 0, 0, 0, 4, 6.800000190734863281, 6.800000190734863281, 10, 10, 3, 3, 0, 0, 52188), -- Spell: 255619 (Blood-Tainted Cauldron of Gold)
(11959, 16644, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 52188), -- Spell: 256608 (Pile of Bones)
(11958, 16643, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 52188); -- Spell: 256606 (Pile of Bones)

-- Path for Rezan
SET @ENTRY := 122963;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -889.3941, 2320.872, 642.4862, NULL, 0),
(@PATH, 1, -881.2743, 2334.361, 642.6951, NULL, 0),
(@PATH, 2, -868.4121, 2342.096, 643.0334, NULL, 0),
(@PATH, 3, -847.9427, 2345.576, 642.5255, NULL, 0),
(@PATH, 4, -832.5677, 2346.835, 642.5773, NULL, 0),
(@PATH, 5, -811.375, 2324.641, 641.4143, NULL, 0),
(@PATH, 6, -800.3993, 2301.29, 641.4551, NULL, 0),
(@PATH, 7, -799.4375, 2291.526, 641.3069, NULL, 0),
(@PATH, 8, -805.6511, 2268.309, 641.6155, NULL, 0),
(@PATH, 9, -815.6215, 2253.351, 642.463, NULL, 0),
(@PATH, 10, -837.1441, 2245.082, 641.5023, NULL, 0),
(@PATH, 11, -845.5313, 2244.21, 641.434, NULL, 0),
(@PATH, 12, -867.6371, 2247.021, 642.2295, NULL, 0),
(@PATH, 13, -885.9583, 2251.991, 642.528, NULL, 0),
(@PATH, 14, -895.757, 2273.04, 642.2986, NULL, 0),
(@PATH, 15, -894.2257, 2300.78, 642.494, NULL, 0);

UPDATE `creature` SET `position_x`= -889.3941, `position_y`= 2320.872, `position_z`= 642.4862, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+91;
UPDATE `creature_template_addon` SET `path_id` = @PATH WHERE `entry` = @ENTRY;

-- Waypoints for CGUID+27
SET @ENTRY := 122973;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -1000.184, 2150.809, 705.8411, NULL, 2788),
(@PATH, 1, -994.9618, 2170.441, 705.2473, NULL, 7670);

UPDATE `creature` SET `position_x`= -1000.184, `position_y`= 2150.809, `position_z`= 705.8411, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+27;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+27;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `visibilityDistanceType`) VALUES
(@CGUID+27, @PATH, 1, 4);

-- Waypoints for CGUID+70
SET @ENTRY := 122971;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -991.0521, 2199.611, 705.841, NULL, 7177),
(@PATH, 1, -991.0469, 2230.415, 705.8411, NULL, 0),
(@PATH, 2, -991.1233, 2199.542, 705.841, NULL, 7118),
(@PATH, 3, -991.0469, 2230.415, 705.8411, NULL, 0);

UPDATE `creature` SET `position_x`= -991.0521, `position_y`= 2199.611, `position_z`= 705.841, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+70;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+70;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `visibilityDistanceType`) VALUES
(@CGUID+70, @PATH, 1, 4);

-- Waypoints for CGUID+121
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+121;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+121, @CGUID+121, 0, 0, 515, 0, 0), -- Dinomancer Kish'o
(@CGUID+121, @CGUID+110, 4, 300, 515, 0, 0), -- T'lonja
(@CGUID+121, @CGUID+106, 4, 60, 515, 0, 0), -- Monzumi
(@CGUID+121, @CGUID+105, 3, 0, 515, 0, 0), -- Toxic Saurid
(@CGUID+121, @CGUID+115, 7, 340, 515, 0, 0), -- Toxic Saurid
(@CGUID+121, @CGUID+117, 7, 20, 515, 0, 0), -- Toxic Saurid
(@CGUID+121, @CGUID+94, 8, 0, 515, 0, 0); -- Toxic Saurid

SET @ENTRY := 129553;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -847.7465, 2276.934, 678.2473, NULL, 7150),
(@PATH, 1, -847.6823, 2307.686, 678.2793, NULL, 8342);

UPDATE `creature` SET `position_x`= -847.7465, `position_y`= 2276.934, `position_z`= 678.2473, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+121;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+121;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `visibilityDistanceType`) VALUES
(@CGUID+121, @PATH, 2, 4);

-- Waypoints for CGUID+213
SET @ENTRY := 122970;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -821.7066, 2147.844, 692.6536, NULL, 9138),
(@PATH, 1, -802.8871, 2147.448, 693.4504, NULL, 0),
(@PATH, 2, -786.7066, 2147.729, 705.7842, NULL, 0),
(@PATH, 3, -782.1285, 2147.649, 705.8411, NULL, 9017),
(@PATH, 4, -786.7066, 2147.729, 705.7842, NULL, 0),
(@PATH, 5, -802.8871, 2147.448, 693.4504, NULL, 0);

UPDATE `creature` SET `position_x`= -821.7066, `position_y`= 2147.844, `position_z`= 692.6536, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+213;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+213;
INSERT INTO `creature_addon` (`guid`, `path_id`, `VisFlags`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+213, @PATH, 2, 1, 4, '123167 252661 252703');

-- Waypoints for CGUID+214
SET @ENTRY := 122970;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -685.3629, 2205.538, 705.841, NULL, 8356),
(@PATH, 1, -706.4358, 2208.262, 705.841, NULL, 0),
(@PATH, 2, -706.743, 2242.207, 705.8409, NULL, 8324),
(@PATH, 3, -706.4358, 2208.262, 705.841, NULL, 0);

UPDATE `creature` SET `position_x`= -685.3629, `position_y`= 2205.538, `position_z`= 705.841, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+214;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+214;
INSERT INTO `creature_addon` (`guid`, `path_id`, `VisFlags`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+214, @PATH, 2, 1, 4, '123167 252661 252703');

-- Waypoints for CGUID+48
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+48;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+48, @CGUID+48, 0, 0, 515, 0, 0),
(@CGUID+48, @CGUID+68, 3, 90, 515, 1, 6);

SET @ENTRY := 127879;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -742.7274, 2164.288, 705.841, NULL, 0),
(@PATH, 1, -750.0729, 2156.314, 705.841, NULL, 4062),
(@PATH, 2, -742.7274, 2164.288, 705.841, NULL, 0),
(@PATH, 3, -733.908, 2166.118, 705.841, NULL, 0),
(@PATH, 4, -718.4827, 2181.927, 705.841, NULL, 0),
(@PATH, 5, -717.2292, 2189.809, 705.8409, NULL, 0),
(@PATH, 6, -710.7239, 2196.74, 705.8409, NULL, 4068),
(@PATH, 7, -717.2292, 2189.809, 705.8409, NULL, 0),
(@PATH, 8, -718.4827, 2181.927, 705.841, NULL, 0),
(@PATH, 9, -733.908, 2166.118, 705.841, NULL, 0);

UPDATE `creature` SET `position_x`= -742.7274, `position_y`= 2164.288, `position_z`= 705.841, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+48;
UPDATE `creature` SET `position_x`= -721.0803, `position_y`= 2179.264, `position_z`= 705.841 WHERE `guid`= @CGUID+68;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+48;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+48, @PATH, 1, 4, '237007 257568 141048');

-- Waypoints for CGUID+216
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+216;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+216, @CGUID+216, 0, 0, 515, 0, 0),
(@CGUID+216, @CGUID+215, 4, 270, 515, 17, 34);

SET @ENTRY := 122970;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -714.2671, 2291.005, 680.8411, NULL, 0),
(@PATH, 1, -711.4585, 2290.939, 681.3384, NULL, 0),
(@PATH, 2, -708.4335, 2290.869, 681.4514, NULL, 0),
(@PATH, 3, -706.2261, 2290.833, 683.0844, NULL, 0),
(@PATH, 4, -703.7859, 2290.797, 684.9706, NULL, 0),
(@PATH, 5, -701.7172, 2290.766, 686.7714, NULL, 0),
(@PATH, 6, -699.3236, 2290.73, 688.7261, NULL, 0),
(@PATH, 7, -696.9215, 2290.695, 690.6823, NULL, 0),
(@PATH, 8, -694.5422, 2290.659, 692.6686, NULL, 0),
(@PATH, 9, -692.2656, 2290.626, 694.7486, NULL, 0),
(@PATH, 10, -689.8727, 2290.59, 696.6343, NULL, 0),
(@PATH, 11, -687.5677, 2290.556, 698.6763, NULL, 0),
(@PATH, 12, -685.0786, 2290.519, 700.4708, NULL, 0),
(@PATH, 13, -682.6797, 2290.483, 702.4172, NULL, 0),
(@PATH, 14, -680.2917, 2290.448, 704.3814, NULL, 0),
(@PATH, 15, -677.9352, 2290.413, 706.3237, NULL, 0),
(@PATH, 16, -675.0176, 2290.365, 706.7679, NULL, 0),
(@PATH, 17, -673.3272, 2290.337, 706.8817, NULL, 5650),
(@PATH, 18, -677.4221, 2290.405, 706.6613, NULL, 0),
(@PATH, 19, -679.8218, 2290.441, 704.7791, NULL, 0),
(@PATH, 20, -682.1733, 2290.476, 702.8464, NULL, 0),
(@PATH, 21, -684.5642, 2290.511, 700.8926, NULL, 0),
(@PATH, 22, -687.0312, 2290.548, 699.0779, NULL, 0),
(@PATH, 23, -689.281, 2290.581, 697.0491, NULL, 0),
(@PATH, 24, -691.7119, 2290.617, 695.2324, NULL, 0),
(@PATH, 25, -693.9542, 2290.651, 693.14, NULL, 0),
(@PATH, 26, -696.326, 2290.686, 691.1857, NULL, 0),
(@PATH, 27, -698.6959, 2290.721, 689.233, NULL, 0),
(@PATH, 28, -701.0988, 2290.757, 687.3516, NULL, 0),
(@PATH, 29, -703.2052, 2290.788, 685.6032, NULL, 0),
(@PATH, 30, -705.5008, 2290.822, 683.6456, NULL, 0),
(@PATH, 31, -707.9166, 2290.86, 681.7797, NULL, 0),
(@PATH, 32, -710.8792, 2290.926, 681.4505, NULL, 0),
(@PATH, 33, -713.6285, 2290.99, 680.841, NULL, 0),
(@PATH, 34, -716.695, 2291.062, 680.8411, NULL, 5327);

UPDATE `creature` SET `position_x`= -714.2671, `position_y`= 2291.005, `position_z`= 680.8411, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+216;
UPDATE `creature` SET `position_x`= -714.2671, `position_y`= 2291.005, `position_z`= 680.8411 WHERE `guid`= @CGUID+215;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+216;
INSERT INTO `creature_addon` (`guid`, `path_id`, `VisFlags`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+216, @PATH, 2, 1, 4, '123167 252661 252703');
