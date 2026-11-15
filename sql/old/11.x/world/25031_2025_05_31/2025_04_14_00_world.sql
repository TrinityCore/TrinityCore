SET @CGUID := 7002008;
SET @OGUID := 7000461;

SET @NPCTEXTID := 570046;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+65;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 130136, 1643, 8721, 0, '0', 0, 0, 0, 0, -140.635421752929687, 1801.1944580078125, 7.182675361633300781, 0, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Wood Moth (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+1, 130160, 1643, 8721, 0, '0', 0, 0, 0, 0, -173.480911254882812, 1733.90283203125, 0.689135730266571044, 5.99333953857421875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Saltrock Terrapin (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+2, 130160, 1643, 8721, 0, '0', 0, 0, 0, 0, -170.677078247070312, 1739.8975830078125, 0.223979681730270385, 5.014759063720703125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Saltrock Terrapin (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+3, 130359, 1643, 8721, 0, '0', 0, 0, 0, 0, -166.234375, 1778.1492919921875, 9.441313743591308593, 0.533290565013885498, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Coastal Osprey (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 105944 - Perch)
(@CGUID+4, 130136, 1643, 8721, 0, '0', 0, 0, 0, 0, -152.963546752929687, 1815.9322509765625, 8.0302886962890625, 0.840344607830047607, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Wood Moth (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+5, 130160, 1643, 8721, 0, '0', 0, 0, 0, 0, -88.6840286254882812, 1818.8125, -0.77139264345169067, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Saltrock Terrapin (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+6, 130160, 1643, 8721, 0, '0', 0, 0, 0, 0, -176.022567749023437, 1727.046875, -1.00037121772766113, 5.222493171691894531, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Saltrock Terrapin (Area: 0 - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+7, 130160, 1643, 8721, 0, '0', 0, 0, 0, 0, -129, 1783.5867919921875, 0.67085433006286621, 0.042543467134237289, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Saltrock Terrapin (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+8, 130136, 1643, 8721, 0, '0', 0, 0, 0, 0, -157.00347900390625, 1770.123291015625, 9.323154449462890625, 5.21376657485961914, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Wood Moth (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+9, 130160, 1643, 8721, 0, '0', 0, 0, 0, 0, -189.791671752929687, 1723.126708984375, 0.613524913787841796, 6.168107032775878906, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Saltrock Terrapin (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+10, 130359, 1643, 8721, 0, '0', 0, 0, 0, 0, -142.631942749023437, 1757.55908203125, 6.938407421112060546, 4.905339717864990234, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Coastal Osprey (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 105944 - Perch)
(@CGUID+11, 130160, 1643, 8721, 0, '0', 0, 0, 0, 0, -126.633682250976562, 1807.1875, -0.86451447010040283, 4.450488090515136718, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Saltrock Terrapin (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+12, 130359, 1643, 8721, 0, '0', 0, 0, 0, 0, -141.109375, 1791.625, 19.19721221923828125, 1.001869916915893554, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Coastal Osprey (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+13, 128386, 1643, 8721, 0, '0', 0, 0, 0, 0, -200.588546752929687, 1756.4791259765625, 10.24659442901611328, 2.849956035614013671, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Lowlands Fawn (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+14, 128384, 1643, 8721, 0, '0', 0, 0, 0, 0, -224.975692749023437, 1796.001708984375, 23.8179473876953125, 1.475475430488586425, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Lowlands Greatstag (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+15, 128386, 1643, 8721, 0, '0', 0, 0, 0, 0, -218.756942749023437, 1791.453125, 22.0041351318359375, 2.355811834335327148, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Lowlands Fawn (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+16, 130136, 1643, 8721, 0, '0', 0, 0, 0, 0, -232.902786254882812, 1816.8680419921875, 42.23596572875976562, 6.02918243408203125, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Wood Moth (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+17, 128385, 1643, 8721, 0, '0', 0, 0, 0, 0, -187.72222900390625, 1798.189208984375, 10.875, 2.951008796691894531, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Lowlands Doe (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+18, 128386, 1643, 8721, 0, '0', 0, 0, 0, 0, -187.442703247070312, 1793.907958984375, 10.77083301544189453, 0.334318429231643676, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Lowlands Fawn (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+19, 128385, 1643, 8721, 0, '0', 0, 0, 0, 0, -222.59375, 1798.923583984375, 23.17378616333007812, 4.874245166778564453, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Lowlands Doe (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+20, 130136, 1643, 8721, 0, '0', 0, 0, 0, 0, -225.807296752929687, 1792.4791259765625, 35.88193893432617187, 2.834929943084716796, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Wood Moth (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+21, 128385, 1643, 8721, 0, '0', 0, 0, 0, 0, -204.932296752929687, 1833.9947509765625, 15.62703800201416015, 1.980223417282104492, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Lowlands Doe (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+22, 128384, 1643, 8721, 0, '0', 0, 0, 0, 0, -213.36285400390625, 1768.314208984375, 15.37818527221679687, 5.426957607269287109, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Lowlands Greatstag (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+23, 128384, 1643, 8721, 0, '0', 0, 0, 0, 0, -203.118057250976562, 1792.09375, 16.67146682739257812, 1.475475430488586425, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Lowlands Greatstag (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+24, 128385, 1643, 8721, 0, '0', 0, 0, 0, 0, -207.614578247070312, 1829.626708984375, 16.40121841430664062, 0.208587303757667541, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Lowlands Doe (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+25, 128386, 1643, 8721, 0, '0', 0, 0, 0, 0, -181.727432250976562, 1803.7586669921875, 9.981843948364257812, 5.163354873657226562, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Lowlands Fawn (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+26, 128384, 1643, 8721, 0, '0', 0, 0, 0, 0, -187.109375, 1777.279541015625, 10.25868034362792968, 4.281260490417480468, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Lowlands Greatstag (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+27, 128385, 1643, 8721, 0, '0', 0, 0, 0, 0, -208.022567749023437, 1755.0885009765625, 10.26650238037109375, 1.980223417282104492, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Lowlands Doe (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+28, 128386, 1643, 8721, 0, '0', 0, 0, 0, 0, -198.123260498046875, 1768.05908203125, 10.79513835906982421, 4.217214584350585937, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Lowlands Fawn (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+29, 128385, 1643, 8721, 0, '0', 0, 0, 0, 0, -191.55035400390625, 1764.94970703125, 10.11412429809570312, 1.168044328689575195, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Lowlands Doe (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+30, 128386, 1643, 8721, 0, '0', 0, 0, 0, 0, -220.685760498046875, 1799.5347900390625, 22.68929672241210937, 1.376326799392700195, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Lowlands Fawn (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+31, 129995, 1643, 8721, 8721, '0', 0, 0, 0, 0, -269.107635498046875, 1666.2535400390625, 57.66659164428710937, 0.064225859940052032, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Emily Mayville (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 258882 - Mourning)
(@CGUID+32, 126695, 1643, 8721, 8721, '0', 0, 0, 0, 0, -261.626739501953125, 1662.829833984375, 64.24524688720703125, 2.635812044143676757, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Baleful Raven (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 105944 - Perch)
(@CGUID+33, 126695, 1643, 8721, 8721, '0', 0, 0, 0, 0, -281.1788330078125, 1679.2691650390625, 67.85861968994140625, 0.491514235734939575, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Baleful Raven (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+34, 126805, 1643, 8721, 8721, '0', 0, 0, 0, 0, -278.53472900390625, 1713.263916015625, 52.42057037353515625, 0, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Skittish Squirrel (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+35, 126805, 1643, 8721, 8721, '0', 0, 0, 0, 0, -293.513885498046875, 1649.579833984375, 62.27732086181640625, 5.0737762451171875, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Skittish Squirrel (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+36, 126805, 1643, 8721, 8721, '0', 0, 0, 0, 0, -260.951385498046875, 1724.2569580078125, 44.29757308959960937, 4.203579902648925781, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Skittish Squirrel (Area: Drustvar - Difficulty: 0) CreateObject2
(@CGUID+37, 130359, 1643, 8721, 8721, '0', 0, 0, 0, 0, -236.298614501953125, 1691.013916015625, 26.27278709411621093, 0.171194389462471008, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Coastal Osprey (Area: Drustvar - Difficulty: 0) CreateObject2 (Auras: 105944 - Perch)
(@CGUID+38, 132146, 1643, 8721, 0, '0', 0, 0, 0, 0, -133.592010498046875, 1764.24658203125, 0.984114229679107666, 3.914975643157958984, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Helen Waterview (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+39, 130136, 1643, 8721, 9131, '0', 0, 0, 0, 0, -423.34027099609375, 1506.7117919921875, 33.0507965087890625, 2.240504026412963867, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Wood Moth (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+40, 125464, 1643, 8721, 9131, '0', 0, 0, 0, 0, -404.211822509765625, 1515.21533203125, 24.0439300537109375, 0.301363319158554077, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Darkmaw Prowler (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+41, 125464, 1643, 8721, 9131, '0', 0, 0, 0, 0, -367.770843505859375, 1433.2847900390625, 23.58945655822753906, 0.475650161504745483, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Darkmaw Prowler (Area: Watcher's Wood - Difficulty: 0) CreateObject2 (Auras: 239490 - Wolf  Eating)
(@CGUID+42, 130136, 1643, 8721, 9131, '0', 0, 0, 0, 0, -379.614593505859375, 1435.52783203125, 30.16878700256347656, 6.179184436798095703, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Wood Moth (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+43, 130136, 1643, 8721, 9131, '0', 0, 0, 0, 0, -434.423614501953125, 1461.357666015625, 35.04608917236328125, 2.368708133697509765, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Wood Moth (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+44, 130136, 1643, 8721, 9131, '0', 0, 0, 0, 0, -411.171875, 1452.6441650390625, 32.83695220947265625, 5.306165218353271484, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Wood Moth (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+45, 125464, 1643, 8721, 9131, '0', 0, 0, 0, 0, -369.1163330078125, 1386.2291259765625, 19.74910545349121093, 0.483990520238876342, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Darkmaw Prowler (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+46, 125411, 1643, 8721, 9131, '0', 0, 0, 0, 0, -381.454864501953125, 1389.3160400390625, 31.18093299865722656, 0.449070185422897338, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Watchful Raven (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+47, 125464, 1643, 8721, 9131, '0', 0, 0, 0, 0, -403.96875, 1512.8350830078125, 23.878753662109375, 6.249038219451904296, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Darkmaw Prowler (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+48, 125411, 1643, 8721, 9131, '0', 0, 0, 0, 0, -404.21875, 1451.1978759765625, 32.13759231567382812, 3.975235462188720703, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Watchful Raven (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+49, 130163, 1643, 8721, 9131, '0', 0, 0, 0, 0, -383.279510498046875, 1414, 23.33592796325683593, 0.919063508510589599, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Estuarine Snail (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+50, 125411, 1643, 8721, 9131, '0', 0, 0, 0, 0, -427.890625, 1494.6319580078125, 34.2999114990234375, 1.939593911170959472, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Watchful Raven (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+51, 125464, 1643, 8721, 9131, '0', 0, 0, 0, 0, -382.017364501953125, 1460.904541015625, 23.15345954895019531, 2.00905776023864746, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Darkmaw Prowler (Area: Watcher's Wood - Difficulty: 0) CreateObject2 (Auras: 145953 - Cosmetic - Sleep Zzz)
(@CGUID+52, 125464, 1643, 8721, 9131, '0', 0, 0, 0, 0, -366.604156494140625, 1431.3316650390625, 23.46059417724609375, 0.792881667613983154, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Darkmaw Prowler (Area: Watcher's Wood - Difficulty: 0) CreateObject2 (Auras: 239490 - Wolf  Eating)
(@CGUID+53, 125464, 1643, 8721, 9131, '0', 0, 0, 0, 0, -378.55035400390625, 1456.404541015625, 23.56597328186035156, 5.64271402359008789, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Darkmaw Prowler (Area: Watcher's Wood - Difficulty: 0) CreateObject2 (Auras: 145953 - Cosmetic - Sleep Zzz)
(@CGUID+54, 125464, 1643, 8721, 9131, '0', 0, 0, 0, 0, -397.01214599609375, 1436.9566650390625, 24.70804595947265625, 3.581285953521728515, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Darkmaw Prowler (Area: Watcher's Wood - Difficulty: 0) CreateObject2 (Auras: 145953 - Cosmetic - Sleep Zzz)
(@CGUID+55, 125464, 1643, 8721, 9131, '0', 0, 0, 0, 0, -378.618072509765625, 1413.6319580078125, 22.9306640625, 0.298382222652435302, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Darkmaw Prowler (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+56, 130136, 1643, 8721, 9131, '0', 0, 0, 0, 0, -383.541656494140625, 1400.90283203125, 30.5965118408203125, 0, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Wood Moth (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+57, 130136, 1643, 8721, 9130, '0', 0, 0, 0, 0, -379.145843505859375, 1264.282958984375, 30.7863006591796875, 0, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Wood Moth (Area: Hangman's Point - Difficulty: 0) CreateObject2
(@CGUID+58, 130136, 1643, 8721, 9130, '0', 0, 0, 0, 0, -366.263885498046875, 1272.361083984375, 40.92888259887695312, 1.249983787536621093, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Wood Moth (Area: Hangman's Point - Difficulty: 0) CreateObject2
(@CGUID+59, 130136, 1643, 8721, 9130, '0', 0, 0, 0, 0, -329.736114501953125, 1257.3021240234375, 20.68123626708984375, 3.074778318405151367, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Wood Moth (Area: Hangman's Point - Difficulty: 0) CreateObject2
(@CGUID+60, 130136, 1643, 8721, 9130, '0', 0, 0, 0, 0, -353.609375, 1278.19970703125, 26.8562164306640625, 3.678243637084960937, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Wood Moth (Area: Hangman's Point - Difficulty: 0) CreateObject2
(@CGUID+61, 130136, 1643, 8721, 9130, '0', 0, 0, 0, 0, -301.86285400390625, 1268.0399169921875, 17.64734077453613281, 1.946955800056457519, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Wood Moth (Area: Hangman's Point - Difficulty: 0) CreateObject2
(@CGUID+62, 130136, 1643, 8721, 9130, '0', 0, 0, 0, 0, -346.904510498046875, 1263.8541259765625, 33.41230010986328125, 1.354365348815917968, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Wood Moth (Area: Hangman's Point - Difficulty: 0) CreateObject2
(@CGUID+63, 125411, 1643, 8721, 9130, '0', 0, 0, 0, 0, -357.3975830078125, 1317.7586669921875, 23.36329269409179687, 1.829953908920288085, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Watchful Raven (Area: Hangman's Point - Difficulty: 0) CreateObject2
(@CGUID+64, 130136, 1643, 8721, 9130, '0', 0, 0, 0, 0, -395.967010498046875, 1253.5052490234375, 25.80410957336425781, 1.322319865226745605, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Wood Moth (Area: Hangman's Point - Difficulty: 0) CreateObject2
(@CGUID+65, 130136, 1643, 8721, 9130, '0', 0, 0, 0, 0, -348.48089599609375, 1332.4305419921875, 25.62765693664550781, 0.954372644424438476, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257); -- Wood Moth (Area: Hangman's Point - Difficulty: 0) CreateObject2
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+65;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+19, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123169'), -- Lowlands Doe - 123169 - Mod Scale 105-110%
(@CGUID+21, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, '123169'), -- Lowlands Doe - 123169 - Mod Scale 105-110%
(@CGUID+22, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, '123169'), -- Lowlands Greatstag - 123169 - Mod Scale 105-110%
(@CGUID+24, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123169'), -- Lowlands Doe - 123169 - Mod Scale 105-110%
(@CGUID+26, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, '123169'), -- Lowlands Greatstag - 123169 - Mod Scale 105-110%
(@CGUID+27, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, '123169'), -- Lowlands Doe - 123169 - Mod Scale 105-110%
(@CGUID+29, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, '123169'), -- Lowlands Doe - 123169 - Mod Scale 105-110%
(@CGUID+32, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '105944'), -- Baleful Raven - 105944 - Perch
(@CGUID+37, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '105944'), -- Coastal Osprey - 105944 - Perch
(@CGUID+38, 0, 0, 0, 0, 0, 1, 1, 720, 0, 0, 0, 0, ''), -- Helen Waterview
(@CGUID+40, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Darkmaw Prowler
(@CGUID+41, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '239490'), -- Darkmaw Prowler - 239490 - Wolf  Eating
(@CGUID+47, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Darkmaw Prowler
(@CGUID+51, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '145953'), -- Darkmaw Prowler - 145953 - Cosmetic - Sleep Zzz
(@CGUID+52, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '239490'), -- Darkmaw Prowler - 239490 - Wolf  Eating
(@CGUID+53, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '145953'), -- Darkmaw Prowler - 145953 - Cosmetic - Sleep Zzz
(@CGUID+54, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '145953'); -- Darkmaw Prowler - 145953 - Cosmetic - Sleep Zzz

-- GameObejct
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+1;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 278482, 1643, 8721, 8721, '0', 0, 0, -267.107635498046875, 1665.75, 57.63779830932617187, 5.860989570617675781, 0, 0, -0.20953369140625, 0.977801442146301269, 120, 255, 1, 60257), -- Dried Flora (Area: Drustvar - Difficulty: 0) CreateObject1
(@OGUID+1, 278507, 1643, 8721, 8721, '0', 0, 0, -264.29339599609375, 1663.0225830078125, 58.80795669555664062, 2.452186107635498046, 0.335145950317382812, -0.11417198181152343, 0.880948066711425781, 0.313962459564208984, 120, 255, 1, 60257); -- Lost Sailors' Memorial (Area: Drustvar - Difficulty: 0) CreateObject1

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (129995);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(129995, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '258882'); -- 129995 (Emily Mayville) - Mourning

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`Entry` IN (130136,126695,130359,129995,132146,125411,125464) AND `DifficultyID`=1);
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000000, `VerifiedBuild`=60257 WHERE (`Entry`=130136 AND `DifficultyID`=0); -- 130136 (Wood Moth) - Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000000, `VerifiedBuild`=60257 WHERE (`Entry`=126695 AND `DifficultyID`=0); -- 126695 (Baleful Raven) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000000, `VerifiedBuild`=60257 WHERE (`Entry`=130359 AND `DifficultyID`=0); -- 130359 (Coastal Osprey) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=129995 AND `DifficultyID`=0); -- 129995 (Emily Mayville) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=132146 AND `DifficultyID`=0); -- 132146 (Helen Waterview) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000000, `VerifiedBuild`=60257 WHERE (`Entry`=125411 AND `DifficultyID`=0); -- 125411 (Watchful Raven) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=125464 AND `DifficultyID`=0); -- 125464 (Darkmaw Prowler) - CanSwim

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=129995 AND `MenuID`=21833);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(129995, 21833, 60257); -- Emily Mayville

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+3;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 141196, 0, 0, 0, 0, 0, 0, 0, 60257), -- 129995 (Emily Mayville)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 141198, 0, 0, 0, 0, 0, 0, 0, 60257), -- 129995 (Emily Mayville)
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 141199, 0, 0, 0, 0, 0, 0, 0, 60257), -- 129995 (Emily Mayville)
(@NPCTEXTID+3, 1, 0, 0, 0, 0, 0, 0, 0, 141201, 0, 0, 0, 0, 0, 0, 0, 60257); -- 129995 (Emily Mayville)

DELETE FROM `gossip_menu` WHERE (`MenuID`=21833 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=21835 AND `TextID`=@NPCTEXTID+1) OR (`MenuID`=21836 AND `TextID`=@NPCTEXTID+2) OR (`MenuID`=21837 AND `TextID`=@NPCTEXTID+3);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(21833, @NPCTEXTID+0, 60257), -- 129995 (Emily Mayville)
(21835, @NPCTEXTID+1, 60257), -- 129995 (Emily Mayville)
(21836, @NPCTEXTID+2, 60257), -- 129995 (Emily Mayville)
(21837, @NPCTEXTID+3, 60257); -- 129995 (Emily Mayville)

DELETE FROM `gossip_menu_option` WHERE (`OptionID`=0 AND `MenuID` IN (21833,21835,21837,21836));
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(21833, 48017, 0, 0, 'Why are you crying?', 141208, 0, 0, 21835, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 60257),
(21835, 48018, 0, 0, 'What happened?', 38334, 0, 0, 21836, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 60257), -- OptionBroadcastTextID: 38334 - 43416 - 78944 - 141209 - 176470 - 197765
(21837, 48020, 0, 0, 'What is it?', 6796, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 60257), -- OptionBroadcastTextID: 6796 - 27143 - 31717 - 72223 - 111502 - 112235 - 112251 - 113420 - 114211 - 120839 - 120886 - 120899 - 120934 - 121188 - 127472 - 127524 - 135536 - 141211 - 143748 - 148959 - 175270 - 211195 - 219810 - 219825 - 263533 - 264022
(21836, 48019, 0, 0, 'Is there anything I can do to help?', 141210, 0, 0, 21837, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 60257);

-- Page Text
DELETE FROM `page_text` WHERE `ID`=7401;
INSERT INTO `page_text` (`ID`, `Text`, `NextPageID`, `PlayerConditionID`, `Flags`, `VerifiedBuild`) VALUES
(7401, 'In search of the next horizon, I follow a constant star, the sea is vast and empty, the journey takes me far.\n\nDarkness falls, the wind now howls, the sky no longer cleared. Straining eyes search the skies but the stars have disappeared.\n\nThrough squall and storm, wind and rain, White Lady guide my path, shine through and bless me with protection from the sea\'s mighty wrath.\n\nThe winds arise, my ship is tossed, our course I fight to keep, struggling against the tides, we are pulled into the deep.\n\nBlue Child comfort the one I love, the one I left alone, the sea is a cruel mistress; I\'ll not be returning home.', 0, 0, 0, 60257); -- 7401

-- Coastal Osprey smart ai
SET @ENTRY := 130359;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 1, 1000, 1000, 0, 0, 0, 85, 105944, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Time = 1 seconds - Self: Cast spell 105944 on self', '');

UPDATE `creature` SET `StringId` = 'ChannelPerched' WHERE `guid` IN (@CGUID+3, @CGUID+10);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 130359 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 130359, 0, 0, 58, 1, 0, 0, 0, 'ChannelPerched', 0, 'Object has StringID ChannelPerched');

-- Path for Coastal Osprey
SET @MOVERGUID := @CGUID+12;
SET @ENTRY := 130359;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 8.5454, 'Coastal Osprey - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -134.80334, 1801.4866, 19.197212, NULL, 0),
(@PATH, 1, -125.20347, 1808.1843, 19.197212, NULL, 0),
(@PATH, 2, -113.77124, 1810.6985, 19.197212, NULL, 0),
(@PATH, 3, -102.24711, 1808.6462, 19.197212, NULL, 0),
(@PATH, 4, -92.38552, 1802.3402, 19.197212, NULL, 0),
(@PATH, 5, -85.68782, 1792.7404, 19.197212, NULL, 0),
(@PATH, 6, -83.17367, 1781.3081, 19.197212, NULL, 0),
(@PATH, 7, -85.225815, 1769.784, 19.197212, NULL, 0),
(@PATH, 8, -91.531845, 1759.9225, 19.197212, NULL, 0),
(@PATH, 9, -101.13173, 1753.2247, 19.197212, NULL, 0),
(@PATH, 10, -112.56396, 1750.7106, 19.197212, NULL, 0),
(@PATH, 11, -124.08809, 1752.7627, 19.197212, NULL, 0),
(@PATH, 12, -133.94966, 1759.0687, 19.197212, NULL, 0),
(@PATH, 13, -140.64737, 1768.6687, 19.197212, NULL, 0),
(@PATH, 14, -143.16151, 1780.1008, 19.197212, NULL, 0),
(@PATH, 15, -141.10938, 1791.625, 19.197212, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Lowlands Greatstag
SET @MOVERGUID := @CGUID+23;
SET @ENTRY := 128384;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Lowlands Greatstag - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -197.5573, 1798.9462, 14.064222, NULL, 0),
(@PATH, 1, -203.35938, 1792.8004, 16.693808, NULL, 6024),
(@PATH, 2, -203.43924, 1813.7656, 15.674254, NULL, 0),
(@PATH, 3, -208.76389, 1824.3577, 16.899656, NULL, 0),
(@PATH, 4, -214.7448, 1830.8298, 19.14035, NULL, 0),
(@PATH, 5, -222.36806, 1837.0278, 23.062231, NULL, 0),
(@PATH, 6, -227.48958, 1841.5938, 27.27963, NULL, 4195),
(@PATH, 7, -220.40625, 1848.2448, 24.573727, NULL, 0),
(@PATH, 8, -215.53645, 1849.7743, 22.77101, NULL, 0),
(@PATH, 9, -206.97049, 1848.6476, 18.579292, NULL, 0),
(@PATH, 10, -198.84201, 1841.0052, 14.100175, NULL, 0),
(@PATH, 11, -196.35243, 1834.5017, 13.890856, NULL, 0),
(@PATH, 12, -195.49826, 1821.2344, 13.812696, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for 
SET @MOVERGUID := @CGUID+33;
SET @ENTRY := 126695;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8687, 'Baleful Raven - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -267.68356, 1686.4937, 67.85862, NULL, 0),
(@PATH, 1, -253.03253, 1682.0594, 67.85862, NULL, 0),
(@PATH, 2, -245.8081, 1668.5642, 67.85862, NULL, 0),
(@PATH, 3, -250.24225, 1653.9131, 67.85862, NULL, 0),
(@PATH, 4, -263.73752, 1646.6887, 67.85862, NULL, 0),
(@PATH, 5, -278.38855, 1651.1228, 67.85862, NULL, 0),
(@PATH, 6, -285.61298, 1664.6182, 67.85862, NULL, 0),
(@PATH, 7, -281.17883, 1679.2692, 67.85862, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Watchful Raven
SET @MOVERGUID := @CGUID+46;
SET @ENTRY := 125411;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8683, 'Watchful Raven - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -371.11264, 1394.3, 31.180933, NULL, 0),
(@PATH, 1, -367.32376, 1405.1373, 31.180933, NULL, 0),
(@PATH, 2, -372.30774, 1415.4795, 31.180933, NULL, 0),
(@PATH, 3, -383.145, 1419.2684, 31.180933, NULL, 0),
(@PATH, 4, -393.48724, 1414.2844, 31.180933, NULL, 0),
(@PATH, 5, -397.27612, 1403.4471, 31.180933, NULL, 0),
(@PATH, 6, -392.29214, 1393.1049, 31.180933, NULL, 0),
(@PATH, 7, -381.45486, 1389.316, 31.180933, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Watchful Raven
SET @MOVERGUID := @CGUID+48;
SET @ENTRY := 125411;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8683, 'Watchful Raven - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -411.93576, 1442.6979, 32.137592, NULL, 0),
(@PATH, 1, -423.4029, 1442.1443, 32.137592, NULL, 0),
(@PATH, 2, -431.9029, 1449.8612, 32.137592, NULL, 0),
(@PATH, 3, -432.45654, 1461.3284, 32.137592, NULL, 0),
(@PATH, 4, -424.73953, 1469.8284, 32.137592, NULL, 0),
(@PATH, 5, -413.2724, 1470.3821, 32.137592, NULL, 0),
(@PATH, 6, -404.7724, 1462.665, 32.137592, NULL, 0),
(@PATH, 7, -404.21875, 1451.1979, 32.137592, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Watchful Raven
SET @MOVERGUID := @CGUID+50;
SET @ENTRY := 125411;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8683, 'Watchful Raven - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -432.0293, 1505.3406, 34.29991, NULL, 0),
(@PATH, 1, -427.3837, 1515.8391, 34.29991, NULL, 0),
(@PATH, 2, -416.67514, 1519.9778, 34.29991, NULL, 0),
(@PATH, 3, -406.17654, 1515.3322, 34.29991, NULL, 0),
(@PATH, 4, -402.03787, 1504.6237, 34.29991, NULL, 0),
(@PATH, 5, -406.68347, 1494.125, 34.29991, NULL, 0),
(@PATH, 6, -417.39206, 1489.9863, 34.29991, NULL, 0),
(@PATH, 7, -427.89062, 1494.632, 34.29991, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Watchful Raven
SET @MOVERGUID := @CGUID+63;
SET @ENTRY := 125411;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8683, 'Watchful Raven - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -360.33966, 1328.8558, 23.363293, NULL, 0),
(@PATH, 1, -354.57318, 1338.783, 23.363293, NULL, 0),
(@PATH, 2, -343.47604, 1341.7251, 23.363293, NULL, 0),
(@PATH, 3, -333.54883, 1335.9586, 23.363293, NULL, 0),
(@PATH, 4, -330.60675, 1324.8615, 23.363293, NULL, 0),
(@PATH, 5, -336.37326, 1314.9342, 23.363293, NULL, 0),
(@PATH, 6, -347.47037, 1311.9922, 23.363293, NULL, 0),
(@PATH, 7, -357.39758, 1317.7587, 23.363293, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
