SET @CGUID := 7001719;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+59;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 124885, 1643, 8721, 9033, '0', 0, 0, 0, 0, 261.939239501953125, 1948.357666015625, 102.1084136962890625, 5.392231941223144531, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Bewitched Darkmaw (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248058 - Possessed)
(@CGUID+1, 124890, 1643, 8721, 9033, '0', 0, 0, 0, 0, 251.0902862548828125, 1973.203125, 113.3246231079101562, 3.45985269546508789, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Ensorcelled Bonepicker (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248069 - Possessed) (possible waypoints or random movement)
(@CGUID+2, 124890, 1643, 8721, 9033, '0', 0, 0, 0, 0, 218.40625, 1904.423583984375, 98.44066619873046875, 3.988931894302368164, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Ensorcelled Bonepicker (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248069 - Possessed) (possible waypoints or random movement)
(@CGUID+3, 124885, 1643, 8721, 9033, '0', 0, 0, 0, 0, 203.3506927490234375, 1919.8125, 91.26232147216796875, 4.95542144775390625, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Bewitched Darkmaw (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248058 - Possessed)
(@CGUID+4, 124890, 1643, 8721, 9033, '0', 0, 0, 0, 0, 257.170135498046875, 1897.013916015625, 88.98834228515625, 3.485385894775390625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Ensorcelled Bonepicker (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248069 - Possessed)
(@CGUID+5, 124885, 1643, 8721, 9033, '0', 0, 0, 0, 0, 238.47222900390625, 1888.078125, 82.9836883544921875, 4.529477596282958984, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Bewitched Darkmaw (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248058 - Possessed)
(@CGUID+6, 124885, 1643, 8721, 9033, '0', 0, 0, 0, 0, 220.092010498046875, 1882.8802490234375, 80.878936767578125, 4.958867073059082031, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Bewitched Darkmaw (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248058 - Possessed)
(@CGUID+7, 124890, 1643, 8721, 9033, '0', 0, 0, 0, 0, 225.00347900390625, 1954.8646240234375, 112.8834686279296875, 1.092469096183776855, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Ensorcelled Bonepicker (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248069 - Possessed)
(@CGUID+8, 124890, 1643, 8721, 9033, '0', 0, 0, 0, 0, 253.9600677490234375, 1895.88720703125, 88.47774505615234375, 0.546809792518615722, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Ensorcelled Bonepicker (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248069 - Possessed)
(@CGUID+9, 124885, 1643, 8721, 9033, '0', 0, 0, 0, 0, 261.211822509765625, 1946.138916015625, 101.9185791015625, 5.966767787933349609, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Bewitched Darkmaw (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248058 - Possessed)
(@CGUID+10, 124885, 1643, 8721, 9033, '0', 0, 0, 0, 0, 233.2708282470703125, 1920.326416015625, 94.00223541259765625, 3.806104660034179687, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Bewitched Darkmaw (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248058 - Possessed) (possible waypoints or random movement)
(@CGUID+11, 124890, 1643, 8721, 9033, '0', 0, 0, 0, 0, 179.1944427490234375, 1881.02783203125, 107.9352493286132812, 0.274773567914962768, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Ensorcelled Bonepicker (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248069 - Possessed)
(@CGUID+12, 124890, 1643, 8721, 9033, '0', 0, 0, 0, 0, 183.9375, 1890.2899169921875, 106.9541854858398437, 5.166778564453125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Ensorcelled Bonepicker (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248069 - Possessed)
(@CGUID+13, 128347, 1643, 8721, 9033, '0', 0, 0, 0, 0, 169.3055572509765625, 1971.717041015625, 100.1885833740234375, 4.405030250549316406, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Hexbound Snarler (Area: Shrouded Foothills - Difficulty: 0) CreateObject2
(@CGUID+14, 124885, 1643, 8721, 9033, '0', 0, 0, 0, 0, 137.4305572509765625, 1917.3228759765625, 93.23709869384765625, 1.372560024261474609, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Bewitched Darkmaw (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248058 - Possessed)
(@CGUID+15, 124890, 1643, 8721, 9033, '0', 0, 0, 0, 0, 182.873260498046875, 1880.9444580078125, 96.4317474365234375, 0.787853419780731201, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Ensorcelled Bonepicker (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248069 - Possessed)
(@CGUID+16, 124890, 1643, 8721, 9033, '0', 0, 0, 0, 0, 184.4739532470703125, 1890.984375, 94.34381866455078125, 5.286646842956542968, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Ensorcelled Bonepicker (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248069 - Possessed)
(@CGUID+17, 124890, 1643, 8721, 9033, '0', 0, 0, 0, 0, 155.2604217529296875, 1933.5504150390625, 97.85089874267578125, 4.439385414123535156, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Ensorcelled Bonepicker (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248069 - Possessed)
(@CGUID+18, 124885, 1643, 8721, 9033, '0', 0, 0, 0, 0, 111.6753463745117187, 1922.592041015625, 91.8998260498046875, 3.487060308456420898, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Bewitched Darkmaw (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248058 - Possessed)
(@CGUID+19, 124890, 1643, 8721, 9033, '0', 0, 0, 0, 0, 177.1770782470703125, 1890.685791015625, 110.2867889404296875, 4.230266571044921875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Ensorcelled Bonepicker (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248069 - Possessed)
(@CGUID+20, 124885, 1643, 8721, 9033, '0', 0, 0, 0, 0, 111.9774322509765625, 1913.6475830078125, 91.4948272705078125, 2.172601938247680664, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Bewitched Darkmaw (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248058 - Possessed)
(@CGUID+21, 124885, 1643, 8721, 9033, '0', 0, 0, 0, 0, 129.6666717529296875, 1941.9757080078125, 95.420654296875, 5.139123916625976562, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Bewitched Darkmaw (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248058 - Possessed)
(@CGUID+22, 124890, 1643, 8721, 9033, '0', 0, 0, 0, 0, 135.342010498046875, 1971.423583984375, 103.6694793701171875, 6.076633930206298828, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Ensorcelled Bonepicker (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248069 - Possessed) (possible waypoints or random movement)
(@CGUID+23, 124885, 1643, 8721, 9033, '0', 0, 0, 0, 0, 109.0694427490234375, 1925.2083740234375, 91.85198974609375, 4.146454811096191406, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Bewitched Darkmaw (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248058 - Possessed)
(@CGUID+24, 124885, 1643, 8721, 9033, '0', 0, 0, 0, 0, 158.4635467529296875, 1889.935791015625, 75.9859771728515625, 3.96520853042602539, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Bewitched Darkmaw (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248058 - Possessed)
(@CGUID+25, 124885, 1643, 8721, 9033, '0', 0, 0, 0, 0, 112.7309036254882812, 1915.9444580078125, 91.72686767578125, 2.989071369171142578, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Bewitched Darkmaw (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248058 - Possessed)
(@CGUID+26, 124885, 1643, 8721, 9033, '0', 0, 0, 0, 0, 103.6545181274414062, 1920.701416015625, 93.40085601806640625, 0.503731071949005126, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Bewitched Darkmaw (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248058 - Possessed)
(@CGUID+27, 124885, 1643, 8721, 9033, '0', 0, 0, 0, 0, 149.064239501953125, 1894.63720703125, 75.03401947021484375, 4.151685714721679687, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Bewitched Darkmaw (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248058 - Possessed)
(@CGUID+28, 124885, 1643, 8721, 9033, '0', 0, 0, 0, 0, 137.0260467529296875, 2016.4739990234375, 98.1378326416015625, 6.197886943817138671, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Bewitched Darkmaw (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248058 - Possessed)
(@CGUID+29, 124890, 1643, 8721, 9033, '0', 0, 0, 0, 0, 115.0434036254882812, 2000.2742919921875, 102.7581863403320312, 1.333238959312438964, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Ensorcelled Bonepicker (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248069 - Possessed)
(@CGUID+30, 128347, 1643, 8721, 9033, '0', 0, 0, 0, 0, 171.37847900390625, 2008.48095703125, 103.44366455078125, 2.344791889190673828, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Hexbound Snarler (Area: Shrouded Foothills - Difficulty: 0) CreateObject2
(@CGUID+31, 124890, 1643, 8721, 9033, '0', 0, 0, 0, 0, 111.6909713745117187, 2006.6353759765625, 121.6668624877929687, 0.015758534893393516, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Ensorcelled Bonepicker (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248069 - Possessed)
(@CGUID+32, 124890, 1643, 8721, 9033, '0', 0, 0, 0, 0, 106.052093505859375, 2002.21533203125, 104.3556976318359375, 5.112147331237792968, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Ensorcelled Bonepicker (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248069 - Possessed)
(@CGUID+33, 124890, 1643, 8721, 9033, '0', 0, 0, 0, 0, 147.1822967529296875, 2080.859375, 101.25274658203125, 1.464179039001464843, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Ensorcelled Bonepicker (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248069 - Possessed)
(@CGUID+34, 124890, 1643, 8721, 9033, '0', 0, 0, 0, 0, 170.5868072509765625, 2040.5538330078125, 106.090728759765625, 1.3526536226272583, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Ensorcelled Bonepicker (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248069 - Possessed)
(@CGUID+35, 124890, 1643, 8721, 9033, '0', 0, 0, 0, 0, 107.4375, 2001.3489990234375, 119.6738739013671875, 5.488794803619384765, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Ensorcelled Bonepicker (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248069 - Possessed)
(@CGUID+36, 124890, 1643, 8721, 9033, '0', 0, 0, 0, 0, 171.6614532470703125, 2042.467041015625, 106.5915985107421875, 4.548344135284423828, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Ensorcelled Bonepicker (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248069 - Possessed)
(@CGUID+37, 124890, 1643, 8721, 9033, '0', 0, 0, 0, 0, 115.5659713745117187, 2005.3958740234375, 117.7591476440429687, 4.829337120056152343, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Ensorcelled Bonepicker (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248069 - Possessed)
(@CGUID+38, 124890, 1643, 8721, 9033, '0', 0, 0, 0, 0, 156.829864501953125, 2081.67529296875, 117.4949569702148437, 1.605044960975646972, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Ensorcelled Bonepicker (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248069 - Possessed)
(@CGUID+39, 124890, 1643, 8721, 9033, '0', 0, 0, 0, 0, 114.7361068725585937, 2000.3228759765625, 116.0746231079101562, 1.58880019187927246, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Ensorcelled Bonepicker (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248069 - Possessed)
(@CGUID+40, 124885, 1643, 8721, 9033, '0', 0, 0, 0, 0, 153.548614501953125, 2107.48779296875, 101.8636093139648437, 0, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Bewitched Darkmaw (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248058 - Possessed)
(@CGUID+41, 128385, 1643, 8721, 9033, '0', 0, 0, 0, 0, 150.26910400390625, 2096.710205078125, 101.7009048461914062, 0.01369237620383501, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Lowlands Doe (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+42, 124890, 1643, 8721, 9033, '0', 0, 0, 0, 0, 157.517364501953125, 2080.76904296875, 103.8870773315429687, 4.029100894927978515, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Ensorcelled Bonepicker (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248069 - Possessed)
(@CGUID+43, 124890, 1643, 8721, 9033, '0', 0, 0, 0, 0, 154.454864501953125, 2087.576416015625, 113.5991134643554687, 3.054975509643554687, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Ensorcelled Bonepicker (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248069 - Possessed)
(@CGUID+44, 124890, 1643, 8721, 9033, '0', 0, 0, 0, 0, 147.4114532470703125, 2080.869873046875, 119.2395095825195312, 5.450314521789550781, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Ensorcelled Bonepicker (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248069 - Possessed)
(@CGUID+45, 128385, 1643, 8721, 9033, '0', 0, 0, 0, 0, 153.361114501953125, 2107.585205078125, 101.8360366821289062, 1.019498348236083984, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Lowlands Doe (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+46, 124890, 1643, 8721, 9033, '0', 0, 0, 0, 0, 191.701385498046875, 2031.9410400390625, 114.1305084228515625, 3.255910873413085937, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Ensorcelled Bonepicker (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248069 - Possessed)
(@CGUID+47, 124890, 1643, 8721, 9033, '0', 0, 0, 0, 0, 147.8715362548828125, 2081.420166015625, 115.5402069091796875, 5.450314521789550781, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Ensorcelled Bonepicker (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248069 - Possessed)
(@CGUID+48, 124885, 1643, 8721, 9033, '0', 0, 0, 0, 0, 193.1927032470703125, 2060.6650390625, 116.25567626953125, 1.833861231803894042, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Bewitched Darkmaw (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248058 - Possessed)
(@CGUID+49, 124890, 1643, 8721, 9033, '0', 0, 0, 0, 0, 114.8420181274414062, 2000.3350830078125, 106.4580078125, 3.68942880630493164, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Ensorcelled Bonepicker (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248069 - Possessed)
(@CGUID+50, 124885, 1643, 8721, 9033, '0', 0, 0, 0, 0, 266.423614501953125, 2047.53125, 133.5007171630859375, 5.295577049255371093, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Bewitched Darkmaw (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248058 - Possessed)
(@CGUID+51, 124885, 1643, 8721, 9033, '0', 0, 0, 0, 0, 187.1024322509765625, 2111.614501953125, 118.8160324096679687, 2.158333778381347656, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Bewitched Darkmaw (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248058 - Possessed)
(@CGUID+52, 124890, 1643, 8721, 9033, '0', 0, 0, 0, 0, 171.8194427490234375, 2040.3228759765625, 106.6538543701171875, 1.3526536226272583, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Ensorcelled Bonepicker (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248069 - Possessed)
(@CGUID+53, 124885, 1643, 8721, 9033, '0', 0, 0, 0, 0, 219.420135498046875, 2120.94970703125, 135.638763427734375, 3.468417167663574218, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Bewitched Darkmaw (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248058 - Possessed)
(@CGUID+54, 124890, 1643, 8721, 9033, '0', 0, 0, 0, 0, 158.3177032470703125, 2077.901123046875, 119.6484146118164062, 3.294076204299926757, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Ensorcelled Bonepicker (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248069 - Possessed)
(@CGUID+55, 124890, 1643, 8721, 9033, '0', 0, 0, 0, 0, 221.4166717529296875, 2048.888916015625, 132.440093994140625, 4.498950004577636718, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Ensorcelled Bonepicker (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248069 - Possessed)
(@CGUID+56, 124885, 1643, 8721, 9033, '0', 0, 0, 0, 0, 222.796875, 2034.3316650390625, 118.1668624877929687, 4.059211254119873046, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 59888), -- Bewitched Darkmaw (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248058 - Possessed)
(@CGUID+57, 130143, 1643, 8721, 9033, '0', 0, 0, 0, 0, 149.626739501953125, 2112.010498046875, 100.3157730102539062, 4.235719680786132812, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Balethorn (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+58, 124890, 1643, 8721, 9033, '0', 0, 0, 0, 0, 209.2100677490234375, 2141.529541015625, 134.9510498046875, 4.779919147491455078, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888), -- Ensorcelled Bonepicker (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248069 - Possessed)
(@CGUID+59, 124885, 1643, 8721, 9033, '0', 0, 0, 0, 0, 220.8871612548828125, 2125, 136.595611572265625, 2.566528797149658203, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888); -- Bewitched Darkmaw (Area: Shrouded Foothills - Difficulty: 0) CreateObject2 (Auras: 248058 - Possessed)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+59;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+4, 0, 0, 0, 0, 0, 1, 0, 428, 0, 0, 0, 0, '248069'), -- Ensorcelled Bonepicker - 248069 - Possessed
(@CGUID+5, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '248058'), -- Bewitched Darkmaw - 248058 - Possessed
(@CGUID+6, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '248058'), -- Bewitched Darkmaw - 248058 - Possessed
(@CGUID+8, 0, 0, 0, 0, 0, 1, 0, 428, 0, 0, 0, 0, '248069'), -- Ensorcelled Bonepicker - 248069 - Possessed
(@CGUID+24, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '248058'), -- Bewitched Darkmaw - 248058 - Possessed
(@CGUID+26, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '248058'), -- Bewitched Darkmaw - 248058 - Possessed
(@CGUID+27, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '248058'), -- Bewitched Darkmaw - 248058 - Possessed
(@CGUID+34, 0, 0, 0, 0, 0, 1, 0, 428, 0, 0, 0, 0, '248069'), -- Ensorcelled Bonepicker - 248069 - Possessed
(@CGUID+36, 0, 0, 0, 0, 0, 1, 0, 428, 0, 0, 0, 0, '248069'), -- Ensorcelled Bonepicker - 248069 - Possessed
(@CGUID+52, 0, 0, 0, 0, 0, 1, 0, 428, 0, 0, 0, 0, '248069'), -- Ensorcelled Bonepicker - 248069 - Possessed
(@CGUID+53, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '248058'), -- Bewitched Darkmaw - 248058 - Possessed
(@CGUID+59, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '248058'); -- Bewitched Darkmaw - 248058 - Possessed

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (124890 /*124890 (Ensorcelled Bonepicker) - Possessed*/, 124885 /*124885 (Bewitched Darkmaw) - Possessed*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(124890, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '248069'), -- 124890 (Ensorcelled Bonepicker) - Possessed
(124885, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '248058'); -- 124885 (Bewitched Darkmaw) - Possessed

-- Difficulty
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000000, `VerifiedBuild`=59888 WHERE (`Entry`=124890 AND `DifficultyID`=0); -- 124890 (Ensorcelled Bonepicker) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=59888 WHERE (`Entry`=124885 AND `DifficultyID`=0); -- 124885 (Bewitched Darkmaw) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=59888 WHERE (`Entry`=130143 AND `DifficultyID`=0); -- 130143 (Balethorn) - CanSwim

-- SAI for Ensorcelled Bonepicker
SET @ENTRY := 124890;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 1, 1000, 1000, 0, 0, 0, 85, 258247, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Time = 1 seconds (OOC) - Self: Cast spell 258247 on self', '');

UPDATE `creature` SET `StringId` = 'ChannelPerched' WHERE `guid` IN (@CGUID+17, @CGUID+7);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 124890 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 124890, 0, 0, 58, 1, 0, 0, 0, 'ChannelPerched', 0, 'Object has StringID ChannelPerched');

-- Path for Balethorn
SET @MOVERGUID := @CGUID+57;
SET @ENTRY := 130143;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Balethorn - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 149.15105, 2049.0208, 98.76726, NULL, 0),
(@PATH, 1, 148.07986, 2028.4254, 99.050354, NULL, 0),
(@PATH, 2, 135.3316, 2002.7709, 100.42984, NULL, 0),
(@PATH, 3, 130.20139, 1979.5, 99.85414, NULL, 0),
(@PATH, 4, 124.51041, 1943.0817, 94.958725, NULL, 0),
(@PATH, 5, 135.48785, 1931.481, 95.35072, NULL, 0),
(@PATH, 6, 163.63716, 1921.5695, 89.5449, NULL, 0),
(@PATH, 7, 175.94618, 1917.2379, 91.541565, NULL, 0),
(@PATH, 8, 197.72743, 1905.3906, 91.018456, NULL, 0),
(@PATH, 9, 223.40105, 1899.8785, 84.525665, NULL, 0),
(@PATH, 10, 241.28473, 1907.1163, 90.113655, NULL, 0),
(@PATH, 11, 250.50694, 1911.6649, 93.15857, NULL, 0),
(@PATH, 12, 253.78299, 1925.5817, 96.24595, NULL, 0),
(@PATH, 13, 251.9323, 1932.2118, 97.55184, NULL, 0),
(@PATH, 14, 254.36806, 1943.3923, 100.20311, NULL, 0),
(@PATH, 15, 257.4922, 1950.7598, 101.8999, NULL, 0),
(@PATH, 16, 249.6632, 1973.2048, 102.46658, NULL, 0),
(@PATH, 17, 244.13368, 1992.3802, 102.190575, NULL, 0),
(@PATH, 18, 243.57422, 2003.3691, 105.23662, NULL, 0),
(@PATH, 19, 240.08203, 2014.8535, 108.590454, NULL, 0),
(@PATH, 20, 234.40105, 2025.382, 115.443436, NULL, 0),
(@PATH, 21, 231.27605, 2035.2882, 119.96604, NULL, 0),
(@PATH, 22, 223.57292, 2051.382, 124.17312, NULL, 0),
(@PATH, 23, 208.66145, 2067.7605, 123.881516, NULL, 0),
(@PATH, 24, 206.51367, 2087.6436, 127.4758, NULL, 0),
(@PATH, 25, 191.37326, 2103.5017, 122.71511, NULL, 0),
(@PATH, 26, 175.81944, 2115.6685, 111.08606, NULL, 0),
(@PATH, 27, 160.85156, 2121.3398, 103.04717, NULL, 0),
(@PATH, 28, 149.04341, 2110.8801, 100.399185, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Ensorcelled Bonepicker
SET @MOVERGUID := @CGUID+1;
SET @ENTRY := 124890;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8682, 'Ensorcelled Bonepicker - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 240.18634, 1969.6107, 113.32462, NULL, 0),
(@PATH, 1, 229.93582, 1974.7806, 113.32462, NULL, 0),
(@PATH, 2, 226.34337, 1985.6847, 113.32462, NULL, 0),
(@PATH, 3, 231.51338, 1995.9352, 113.32462, NULL, 0),
(@PATH, 4, 242.41733, 1999.5276, 113.32462, NULL, 0),
(@PATH, 5, 252.66785, 1994.3575, 113.32462, NULL, 0),
(@PATH, 6, 256.26028, 1983.4536, 113.32462, NULL, 0),
(@PATH, 7, 251.09029, 1973.2031, 113.32462, NULL, 0),
(@PATH, 8, 240.18634, 1969.6107, 113.32462, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '248069');

-- Path for Ensorcelled Bonepicker
SET @MOVERGUID := @CGUID+2;
SET @ENTRY := 124890;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8683, 'Ensorcelled Bonepicker - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 210.80641, 1895.8187, 98.44067, NULL, 0),
(@PATH, 1, 211.5171, 1884.3602, 98.44067, NULL, 0),
(@PATH, 2, 220.12201, 1876.7604, 98.44067, NULL, 0),
(@PATH, 3, 231.58049, 1877.4711, 98.44067, NULL, 0),
(@PATH, 4, 239.18033, 1886.0759, 98.44067, NULL, 0),
(@PATH, 5, 238.46965, 1897.5344, 98.44067, NULL, 0),
(@PATH, 6, 229.86475, 1905.1343, 98.44067, NULL, 0),
(@PATH, 7, 218.40625, 1904.4236, 98.44067, NULL, 0),
(@PATH, 8, 210.80641, 1895.8187, 98.44067, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '248069');

-- Path for Ensorcelled Bonepicker
SET @MOVERGUID := @CGUID+11;
SET @ENTRY := 124890;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 9.1692, 'Ensorcelled Bonepicker - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 182.87772, 1882.0662, 107.93525, NULL, 0),
(@PATH, 1, 184.74794, 1885.4049, 107.93525, NULL, 0),
(@PATH, 2, 183.70958, 1889.0881, 107.93525, NULL, 0),
(@PATH, 3, 180.37088, 1890.9584, 107.93525, NULL, 0),
(@PATH, 4, 176.6876, 1889.92, 107.93525, NULL, 0),
(@PATH, 5, 174.81738, 1886.5813, 107.93525, NULL, 0),
(@PATH, 6, 175.85574, 1882.8981, 107.93525, NULL, 0),
(@PATH, 7, 179.19444, 1881.0278, 107.93525, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '248069');

-- Path for Ensorcelled Bonepicker
SET @MOVERGUID := @CGUID+12;
SET @ENTRY := 124890;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 9.1692, 'Ensorcelled Bonepicker - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 185.61713, 1886.8514, 106.954185, NULL, 0),
(@PATH, 1, 184.3734, 1883.2323, 106.954185, NULL, 0),
(@PATH, 2, 180.93488, 1881.5526, 106.954185, NULL, 0),
(@PATH, 3, 177.31578, 1882.7964, 106.954185, NULL, 0),
(@PATH, 4, 175.63615, 1886.235, 106.954185, NULL, 0),
(@PATH, 5, 176.87988, 1889.854, 106.954185, NULL, 0),
(@PATH, 6, 180.3184, 1891.5337, 106.954185, NULL, 0),
(@PATH, 7, 183.9375, 1890.2899, 106.954185, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '248069');

-- Path for Ensorcelled Bonepicker
SET @MOVERGUID := @CGUID+15;
SET @ENTRY := 124890;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 9.1655, 'Ensorcelled Bonepicker - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 186.11244, 1884.1996, 96.43175, NULL, 0),
(@PATH, 1, 186.10115, 1888.7917, 96.43175, NULL, 0),
(@PATH, 2, 182.846, 1892.031, 96.43175, NULL, 0),
(@PATH, 3, 178.2538, 1892.0197, 96.43175, NULL, 0),
(@PATH, 4, 175.01462, 1888.7645, 96.43175, NULL, 0),
(@PATH, 5, 175.02592, 1884.1724, 96.43175, NULL, 0),
(@PATH, 6, 178.28107, 1880.9331, 96.43175, NULL, 0),
(@PATH, 7, 182.87326, 1880.9445, 96.43175, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '248069');

-- Path for Ensorcelled Bonepicker
SET @MOVERGUID := @CGUID+16;
SET @ENTRY := 124890;
SET @PATHOFFSET := 5;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 9.1655, 'Ensorcelled Bonepicker - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 186.96849, 1887.1288, 94.34382, NULL, 0),
(@PATH, 1, 186.00609, 1882.6385, 94.34382, NULL, 0),
(@PATH, 2, 182.1505, 1880.144, 94.34382, NULL, 0),
(@PATH, 3, 177.66028, 1881.1064, 94.34382, NULL, 0),
(@PATH, 4, 175.16574, 1884.962, 94.34382, NULL, 0),
(@PATH, 5, 176.12814, 1889.4523, 94.34382, NULL, 0),
(@PATH, 6, 179.98373, 1891.9468, 94.34382, NULL, 0),
(@PATH, 7, 184.47395, 1890.9844, 94.34382, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '248069');

-- Path for Ensorcelled Bonepicker
SET @MOVERGUID := @CGUID+19;
SET @ENTRY := 124890;
SET @PATHOFFSET := 6;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 9.1691, 'Ensorcelled Bonepicker - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 175.40273, 1887.2952, 110.28679, NULL, 0),
(@PATH, 1, 176.54561, 1883.643, 110.28679, NULL, 0),
(@PATH, 2, 179.93623, 1881.8687, 110.28679, NULL, 0),
(@PATH, 3, 183.58842, 1883.0115, 110.28679, NULL, 0),
(@PATH, 4, 185.36278, 1886.4021, 110.28679, NULL, 0),
(@PATH, 5, 184.2199, 1890.0543, 110.28679, NULL, 0),
(@PATH, 6, 180.82927, 1891.8286, 110.28679, NULL, 0),
(@PATH, 7, 177.17708, 1890.6858, 110.28679, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '248069');

-- Path for Ensorcelled Bonepicker
SET @MOVERGUID := @CGUID+22;
SET @ENTRY := 124890;
SET @PATHOFFSET := 7;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8683, 'Ensorcelled Bonepicker - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 146.57849, 1969.0691, 103.66948, NULL, 0),
(@PATH, 1, 152.85901, 1959.4589, 103.66948, NULL, 0),
(@PATH, 2, 150.50452, 1948.2224, 103.66948, NULL, 0),
(@PATH, 3, 140.89426, 1941.9419, 103.66948, NULL, 0),
(@PATH, 4, 129.65779, 1944.2964, 103.66948, NULL, 0),
(@PATH, 5, 123.377266, 1953.9066, 103.66948, NULL, 0),
(@PATH, 6, 125.73175, 1965.1431, 103.66948, NULL, 0),
(@PATH, 7, 135.34201, 1971.4236, 103.66948, NULL, 0),
(@PATH, 8, 146.57849, 1969.0691, 103.66948, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '248069');

-- Path for Ensorcelled Bonepicker
SET @MOVERGUID := @CGUID+29;
SET @ENTRY := 124890;
SET @PATHOFFSET := 8;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 9.1692, 'Ensorcelled Bonepicker - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 115.94397, 2003.9937, 102.75819, NULL, 0),
(@PATH, 1, 113.95079, 2007.2604, 102.75819, NULL, 0),
(@PATH, 2, 110.23143, 2008.161, 102.75819, NULL, 0),
(@PATH, 3, 106.964645, 2006.1678, 102.75819, NULL, 0),
(@PATH, 4, 106.06407, 2002.4485, 102.75819, NULL, 0),
(@PATH, 5, 108.05726, 1999.1816, 102.75819, NULL, 0),
(@PATH, 6, 111.77662, 1998.2811, 102.75819, NULL, 0),
(@PATH, 7, 115.0434, 2000.2743, 102.75819, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '248069');

-- Path for Ensorcelled Bonepicker
SET @MOVERGUID := @CGUID+31;
SET @ENTRY := 124890;
SET @PATHOFFSET := 9;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 9.1693, 'Ensorcelled Bonepicker - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 115.51733, 2006.6957, 121.66686, NULL, 0),
(@PATH, 1, 118.26562, 2004.0327, 121.66686, NULL, 0),
(@PATH, 2, 118.325935, 2000.2063, 121.66686, NULL, 0),
(@PATH, 3, 115.66293, 1997.458, 121.66686, NULL, 0),
(@PATH, 4, 111.83658, 1997.3977, 121.66686, NULL, 0),
(@PATH, 5, 109.08829, 2000.0607, 121.66686, NULL, 0),
(@PATH, 6, 109.02797, 2003.8871, 121.66686, NULL, 0),
(@PATH, 7, 111.69097, 2006.6354, 121.66686, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '248069');

-- Path for Ensorcelled Bonepicker
SET @MOVERGUID := @CGUID+33;
SET @ENTRY := 124890;
SET @PATHOFFSET := 10;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 9.1697, 'Ensorcelled Bonepicker - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 147.58954, 2084.6646, 101.25275, NULL, 0),
(@PATH, 1, 150.56812, 2087.0671, 101.25275, NULL, 0),
(@PATH, 2, 154.37321, 2086.66, 101.25275, NULL, 0),
(@PATH, 3, 156.77586, 2083.6814, 101.25275, NULL, 0),
(@PATH, 4, 156.36864, 2079.8762, 101.25275, NULL, 0),
(@PATH, 5, 153.39006, 2077.4736, 101.25275, NULL, 0),
(@PATH, 6, 149.58495, 2077.8809, 101.25275, NULL, 0),
(@PATH, 7, 147.1823, 2080.8594, 101.25275, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '248069');

-- Path for Ensorcelled Bonepicker
SET @MOVERGUID := @CGUID+32;
SET @ENTRY := 124890;
SET @PATHOFFSET := 11;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 9.1693, 'Ensorcelled Bonepicker - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 107.5415, 1998.6902, 104.3557, NULL, 0),
(@PATH, 1, 111.08728, 1997.2507, 104.3557, NULL, 0),
(@PATH, 2, 114.61238, 1998.7401, 104.3557, NULL, 0),
(@PATH, 3, 116.05184, 2002.286, 104.3557, NULL, 0),
(@PATH, 4, 114.56245, 2005.811, 104.3557, NULL, 0),
(@PATH, 5, 111.016655, 2007.2505, 104.3557, NULL, 0),
(@PATH, 6, 107.491554, 2005.7611, 104.3557, NULL, 0),
(@PATH, 7, 106.05209, 2002.2153, 104.3557, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '248069');

-- Path for Ensorcelled Bonepicker
SET @MOVERGUID := @CGUID+35;
SET @ENTRY := 124890;
SET @PATHOFFSET := 12;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 9.1692, 'Ensorcelled Bonepicker - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 110.11906, 1998.6188, 119.673874, NULL, 0),
(@PATH, 1, 113.94573, 1998.5845, 119.673874, NULL, 0),
(@PATH, 2, 116.67592, 2001.266, 119.673874, NULL, 0),
(@PATH, 3, 116.71031, 2005.0927, 119.673874, NULL, 0),
(@PATH, 4, 114.02876, 2007.8229, 119.673874, NULL, 0),
(@PATH, 5, 110.20208, 2007.8572, 119.673874, NULL, 0),
(@PATH, 6, 107.47189, 2005.1757, 119.673874, NULL, 0),
(@PATH, 7, 107.4375, 2001.349, 119.673874, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '248069');

-- Path for Ensorcelled Bonepicker
SET @MOVERGUID := @CGUID+37;
SET @ENTRY := 124890;
SET @PATHOFFSET := 13;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 9.1693, 'Ensorcelled Bonepicker - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 116.01249, 2001.5952, 117.75915, NULL, 0),
(@PATH, 1, 113.640724, 1998.5919, 117.75915, NULL, 0),
(@PATH, 2, 109.84003, 1998.1454, 117.75915, NULL, 0),
(@PATH, 3, 106.83679, 2000.5172, 117.75915, NULL, 0),
(@PATH, 4, 106.39028, 2004.3179, 117.75915, NULL, 0),
(@PATH, 5, 108.76205, 2007.3212, 117.75915, NULL, 0),
(@PATH, 6, 112.562744, 2007.7676, 117.75915, NULL, 0),
(@PATH, 7, 115.56597, 2005.3959, 117.75915, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '248069');

-- Path for Ensorcelled Bonepicker
SET @MOVERGUID := @CGUID+38;
SET @ENTRY := 124890;
SET @PATHOFFSET := 14;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 9.1690, 'Ensorcelled Bonepicker - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 156.69882, 2085.5, 117.49496, NULL, 0),
(@PATH, 1, 153.90176, 2088.1116, 117.49496, NULL, 0),
(@PATH, 2, 150.07716, 2087.9805, 117.49496, NULL, 0),
(@PATH, 3, 147.46544, 2085.1836, 117.49496, NULL, 0),
(@PATH, 4, 147.59648, 2081.359, 117.49496, NULL, 0),
(@PATH, 5, 150.39355, 2078.747, 117.49496, NULL, 0),
(@PATH, 6, 154.21814, 2078.8782, 117.49496, NULL, 0),
(@PATH, 7, 156.82986, 2081.6753, 117.49496, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '248069');

-- Path for Ensorcelled Bonepicker
SET @MOVERGUID := @CGUID+39;
SET @ENTRY := 124890;
SET @PATHOFFSET := 15;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 9.1693, 'Ensorcelled Bonepicker - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 114.66721, 2004.149, 116.07462, NULL, 0),
(@PATH, 1, 111.912964, 2006.8059, 116.07462, NULL, 0),
(@PATH, 2, 108.08675, 2006.737, 116.07462, NULL, 0),
(@PATH, 3, 105.42992, 2003.9828, 116.07462, NULL, 0),
(@PATH, 4, 105.49881, 2000.1566, 116.07462, NULL, 0),
(@PATH, 5, 108.25307, 1997.4998, 116.07462, NULL, 0),
(@PATH, 6, 112.07928, 1997.5686, 116.07462, NULL, 0),
(@PATH, 7, 114.73611, 2000.3229, 116.07462, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '248069');

-- Path for Ensorcelled Bonepicker
SET @MOVERGUID := @CGUID+42;
SET @ENTRY := 124890;
SET @PATHOFFSET := 16;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 9.1695, 'Ensorcelled Bonepicker - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 155.10126, 2077.8013, 103.88708, NULL, 0),
(@PATH, 1, 151.29434, 2077.4114, 103.88708, NULL, 0),
(@PATH, 2, 148.32668, 2079.8274, 103.88708, NULL, 0),
(@PATH, 3, 147.93666, 2083.6343, 103.88708, NULL, 0),
(@PATH, 4, 150.35278, 2086.602, 103.88708, NULL, 0),
(@PATH, 5, 154.1597, 2086.9922, 103.88708, NULL, 0),
(@PATH, 6, 157.12737, 2084.576, 103.88708, NULL, 0),
(@PATH, 7, 157.51736, 2080.769, 103.88708, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '248069');

-- Path for Ensorcelled Bonepicker
SET @MOVERGUID := @CGUID+43;
SET @ENTRY := 124890;
SET @PATHOFFSET := 17;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 9.1692, 'Ensorcelled Bonepicker - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 150.64238, 2087.9075, 113.59911, NULL, 0),
(@PATH, 1, 147.71243, 2085.4458, 113.59911, NULL, 0),
(@PATH, 2, 147.38135, 2081.6333, 113.59911, NULL, 0),
(@PATH, 3, 149.84308, 2078.7034, 113.59911, NULL, 0),
(@PATH, 4, 153.65556, 2078.3723, 113.59911, NULL, 0),
(@PATH, 5, 156.58551, 2080.834, 113.59911, NULL, 0),
(@PATH, 6, 156.9166, 2084.6465, 113.59911, NULL, 0),
(@PATH, 7, 154.45486, 2087.5764, 113.59911, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '248069');

-- Path for Ensorcelled Bonepicker
SET @MOVERGUID := @CGUID+44;
SET @ENTRY := 124890;
SET @PATHOFFSET := 18;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 9.1392, 'Ensorcelled Bonepicker - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 149.98593, 2078.0386, 119.23951, NULL, 0),
(@PATH, 1, 153.80844, 2077.857, 119.23951, NULL, 0),
(@PATH, 2, 157.26146, 2080.1206, 121.003975, NULL, 0),
(@PATH, 3, 156.8215, 2084.254, 119.23951, NULL, 0),
(@PATH, 4, 154.24702, 2087.0852, 119.23951, NULL, 0),
(@PATH, 5, 150.4245, 2087.2668, 119.23951, NULL, 0),
(@PATH, 6, 147.59312, 2084.6924, 119.23951, NULL, 0),
(@PATH, 7, 147.41145, 2080.8699, 119.23951, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '248069');

-- Path for Ensorcelled Bonepicker
SET @MOVERGUID := @CGUID+46;
SET @ENTRY := 124890;
SET @PATHOFFSET := 19;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8683, 'Ensorcelled Bonepicker - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 180.29582, 2030.6315, 114.13051, NULL, 0),
(@PATH, 1, 173.15689, 2021.6405, 114.13051, NULL, 0),
(@PATH, 2, 174.46648, 2010.2349, 114.13051, NULL, 0),
(@PATH, 3, 183.45744, 2003.096, 114.13051, NULL, 0),
(@PATH, 4, 194.863, 2004.4055, 114.13051, NULL, 0),
(@PATH, 5, 202.00194, 2013.3965, 114.13051, NULL, 0),
(@PATH, 6, 200.69235, 2024.8021, 114.13051, NULL, 0),
(@PATH, 7, 191.70139, 2031.941, 114.13051, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '248069');

-- Path for Ensorcelled Bonepicker
SET @MOVERGUID := @CGUID+47;
SET @ENTRY := 124890;
SET @PATHOFFSET := 20;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 9.1690, 'Ensorcelled Bonepicker - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 150.44601, 2078.5889, 115.54021, NULL, 0),
(@PATH, 1, 154.26852, 2078.4072, 115.54021, NULL, 0),
(@PATH, 2, 157.09991, 2080.9817, 115.54021, NULL, 0),
(@PATH, 3, 157.28159, 2084.8042, 115.54021, NULL, 0),
(@PATH, 4, 154.7071, 2087.6355, 115.54021, NULL, 0),
(@PATH, 5, 150.88458, 2087.8171, 115.54021, NULL, 0),
(@PATH, 6, 148.0532, 2085.2427, 115.54021, NULL, 0),
(@PATH, 7, 147.87154, 2081.4202, 115.54021, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '248069');

-- Path for Ensorcelled Bonepicker
SET @MOVERGUID := @CGUID+49;
SET @ENTRY := 124890;
SET @PATHOFFSET := 21;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 9.1693, 'Ensorcelled Bonepicker - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 111.57524, 1998.3419, 106.45801, NULL, 0),
(@PATH, 1, 107.85588, 1999.2424, 106.45801, NULL, 0),
(@PATH, 2, 105.862686, 2002.5093, 106.45801, NULL, 0),
(@PATH, 3, 106.76326, 2006.2286, 106.45801, NULL, 0),
(@PATH, 4, 110.03004, 2008.2218, 106.45801, NULL, 0),
(@PATH, 5, 113.7494, 2007.3212, 106.45801, NULL, 0),
(@PATH, 6, 115.742584, 2004.0544, 106.45801, NULL, 0),
(@PATH, 7, 114.84202, 2000.3351, 106.45801, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '248069');

-- Path for Ensorcelled Bonepicker
SET @MOVERGUID := @CGUID+55;
SET @ENTRY := 124890;
SET @PATHOFFSET := 22;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8683, 'Ensorcelled Bonepicker - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 218.98485, 2037.669, 132.4401, NULL, 0),
(@PATH, 1, 225.19902, 2028.0156, 132.4401, NULL, 0),
(@PATH, 2, 236.419, 2025.5839, 132.4401, NULL, 0),
(@PATH, 3, 246.0723, 2031.798, 132.4401, NULL, 0),
(@PATH, 4, 248.50412, 2043.018, 132.4401, NULL, 0),
(@PATH, 5, 242.28995, 2052.6711, 132.4401, NULL, 0),
(@PATH, 6, 231.06996, 2055.103, 132.4401, NULL, 0),
(@PATH, 7, 221.41667, 2048.889, 132.4401, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '248069');

-- Path for Ensorcelled Bonepicker
SET @MOVERGUID := @CGUID+58;
SET @ENTRY := 124890;
SET @PATHOFFSET := 23;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8683, 'Ensorcelled Bonepicker - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 209.98476, 2130.0752, 134.95105, NULL, 0),
(@PATH, 1, 202.4331, 2121.428, 134.95105, NULL, 0),
(@PATH, 2, 190.97878, 2120.6533, 134.95105, NULL, 0),
(@PATH, 3, 182.33154, 2128.2048, 134.95105, NULL, 0),
(@PATH, 4, 181.55685, 2139.6592, 134.95105, NULL, 0),
(@PATH, 5, 189.1085, 2148.3064, 134.95105, NULL, 0),
(@PATH, 6, 200.56284, 2149.0813, 134.95105, NULL, 0),
(@PATH, 7, 209.21007, 2141.5295, 134.95105, NULL, 0),
(@PATH, 8, 209.98476, 2130.0752, 134.95105, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '248069');
