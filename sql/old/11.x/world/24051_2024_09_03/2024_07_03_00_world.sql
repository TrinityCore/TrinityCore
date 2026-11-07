SET @CGUID := 9004181;
SET @OGUID := 9003904;

SET @NPCTEXTID := 590117;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+64;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 216753, 2444, 15105, 15121, '0', '0', 0, 0, 0, -266.900146484375, 7135.68896484375, 0.200000002980232238, 3.579563617706298828, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 55261), -- Grimclaw (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+1, 216432, 2444, 15105, 15121, '0', '0', 0, 0, 1, -297.164947509765625, 7086.11474609375, 7.150786399841308593, 4.880284309387207031, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Kaldorei Angler (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 433075 - -Unknown-)
(@CGUID+2, 216432, 2444, 15105, 15121, '0', '0', 0, 0, 1, -269.164947509765625, 7109.57275390625, 6.850209712982177734, 1.881934404373168945, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Kaldorei Angler (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 433075 - -Unknown-)
(@CGUID+3, 216763, 2444, 15105, 15121, '0', '0', 0, 0, 1, -253.08160400390625, 7115.45751953125, 6.850206851959228515, 1.917820692062377929, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Cerellean Whiteclaw (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+4, 216803, 2444, 15105, 15121, '0', '0', 0, 0, 0, -223.630203247070312, 7108.71337890625, 6.447843074798583984, 0.735533118247985839, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Sentinel Eriadnar (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+5, 223484, 2444, 15105, 15121, '0', '0', 0, 0, 0, -348.291656494140625, 7079.12255859375, 11.12598705291748046, 6.185538768768310546, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Captain Idrilae (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+6, 216432, 2444, 15105, 15121, '0', '0', 0, 0, 1, -350.661468505859375, 7130.546875, 7.436840534210205078, 0.203238606452941894, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Kaldorei Angler (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 433073 - -Unknown-)
(@CGUID+7, 216415, 2444, 15105, 15121, '0', '0', 0, 0, 0, -346.807281494140625, 7078.705078125, 11.12423515319824218, 2.960374116897583007, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Taldar Windsinger (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+8, 216432, 2444, 15105, 15121, '0', '0', 0, 0, 1, -354.10589599609375, 7144.36962890625, 6.850209712982177734, 0.234330475330352783, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Kaldorei Angler (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 433075 - -Unknown-)
(@CGUID+9, 216432, 2444, 15105, 15121, '0', '0', 0, 0, 1, -363.454864501953125, 7103.3056640625, 9.853794097900390625, 3.213033199310302734, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Kaldorei Angler (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 433075 - -Unknown-)
(@CGUID+10, 216432, 2444, 15105, 15121, '0', '0', 0, 0, 1, -344.3663330078125, 7034.7646484375, 7.354232311248779296, 3.265764951705932617, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Kaldorei Angler (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 433075 - -Unknown-)
(@CGUID+11, 216432, 2444, 15105, 15121, '0', '0', 0, 0, 1, -371.916656494140625, 7088.94091796875, 9.856652259826660156, 2.546609401702880859, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Kaldorei Angler (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 433073 - -Unknown-)
(@CGUID+12, 216718, 2444, 15105, 15121, '0', '0', 0, 0, 1, -419.639312744140625, 7064.31884765625, 6.385642528533935546, 0.237088143825531005, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Mariner Swiftstar (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+13, 216432, 2444, 15105, 15121, '0', '0', 0, 0, 1, -428.03472900390625, 7071.6025390625, 6.850209712982177734, 1.711673855781555175, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Kaldorei Angler (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 433075 - -Unknown-)
(@CGUID+14, 216432, 2444, 15105, 15121, '0', '0', 0, 0, 1, -442.876739501953125, 7051.0478515625, 7.141425132751464843, 4.964255809783935546, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Kaldorei Angler (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 433073 - -Unknown-)
(@CGUID+15, 216719, 2444, 15105, 15121, '0', '0', 0, 0, 1, -450.8497314453125, 7056.1572265625, 7.589092731475830078, 0.238633275032043457, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Mariner Farsight (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+16, 216432, 2444, 15105, 15121, '0', '0', 0, 0, 1, -500.392364501953125, 7054.8818359375, 7.086116790771484375, 1.935032606124877929, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Kaldorei Angler (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 433070 - -Unknown-)
(@CGUID+17, 216432, 2444, 15105, 15121, '0', '0', 0, 0, 1, -544.76739501953125, 7027.01123046875, 7.113870143890380859, 4.58954620361328125, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Kaldorei Angler (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 433070 - -Unknown-)
(@CGUID+18, 216432, 2444, 15105, 15121, '0', '0', 0, 0, 1, -548.81768798828125, 7043.650390625, 7.129825592041015625, 1.658250808715820312, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Kaldorei Angler (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 433073 - -Unknown-)
(@CGUID+19, 216721, 2444, 15105, 15121, '0', '0', 0, 0, 1, -587.109375, 7017.1318359375, 11.81060981750488281, 3.38821578025817871, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Belanaar Sentinel (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+20, 216721, 2444, 15105, 15121, '0', '0', 0, 0, 1, -589.373291015625, 7033.2734375, 11.41394233703613281, 3.38821578025817871, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Belanaar Sentinel (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+21, 216721, 2444, 15105, 15121, '0', '0', 0, 0, 1, -655.0867919921875, 7029.19091796875, 13.24126625061035156, 1.656360507011413574, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Belanaar Sentinel (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+22, 216721, 2444, 15105, 15121, '0', '0', 0, 0, 1, -665.1163330078125, 7028.32373046875, 13.22318077087402343, 1.82561659812927246, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Belanaar Sentinel (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+23, 216716, 2444, 15105, 15121, '0', '0', 0, 0, 1, -645.37701416015625, 7009.88330078125, 15.16833305358886718, 0.276973307132720947, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Mariner Bladewhisper (Area: -Unknown- - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+24, 210761, 2444, 15105, 15121, '0', '0', 0, 0, 0, -695.9500732421875, 7006.59423828125, 18.88764381408691406, 5.683033943176269531, 120, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 55261), -- Fount Flutterer (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+25, 210761, 2444, 15105, 15121, '0', '0', 0, 0, 0, -707.50091552734375, 7041.5126953125, 26.15556907653808593, 0.960539042949676513, 120, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 55261), -- Fount Flutterer (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+26, 216715, 2444, 15105, 15121, '0', '0', 0, 0, 1, -649.09552001953125, 7013.830078125, 15.04267692565917968, 4.356632709503173828, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Merchant Fallel Stargazer (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+27, 216720, 2444, 15105, 15121, '0', '0', 0, 0, 1, -671.42535400390625, 7011.43310546875, 15.04267692565917968, 6.056697368621826171, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Galley Chief Mariss (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+28, 223452, 2444, 15105, 15121, '0', '0', 0, 0, 0, -696.69268798828125, 7004.31005859375, 15.04267692565917968, 5.158831596374511718, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Ishala (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+29, 215488, 2444, 15105, 15121, '0', '0', 0, 0, 0, -697.170166015625, 7003.30126953125, 15.04267692565917968, 0.339478462934494018, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Belysra Starbreeze (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+30, 216797, 2444, 15105, 15121, '0', '0', 0, 0, 0, -673.36419677734375, 7007.40576171875, 19.10426521301269531, 3.419671058654785156, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Dendrythis (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+31, 210958, 2444, 15105, 15121, '0', '0', 0, 0, 0, -663.42706298828125, 7049.970703125, 16.63963699340820312, 3.323985099792480468, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Vassandra Stormclaw (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+32, 223451, 2444, 15105, 15121, '0', '0', 0, 0, 1, -665.328125, 7050.0087890625, 16.51070022583007812, 6.163814067840576171, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Celestine of the Harvest (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+33, 216646, 2444, 15105, 15121, '0', '0', 0, 0, 0, -671.61285400390625, 7021.10791015625, 14.5685272216796875, 1.979763627052307128, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Shen'dralar Sorcerer (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+34, 210761, 2444, 15105, 15121, '0', '0', 0, 0, 0, -591.45489501953125, 7022.3486328125, 19.62247085571289062, 4.928734779357910156, 120, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 55261), -- Fount Flutterer (Area: -Unknown- - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+35, 210761, 2444, 15105, 15121, '0', '0', 0, 0, 0, -708.74908447265625, 6924.23388671875, 4.966912269592285156, 4.443448066711425781, 120, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 55261), -- Fount Flutterer (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+36, 210761, 2444, 15105, 15121, '0', '0', 0, 0, 0, -734.91497802734375, 6949.80908203125, 5.613886833190917968, 1.550159573554992675, 120, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 55261), -- Fount Flutterer (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+37, 214214, 2444, 15105, 15121, '0', '0', 0, 0, 0, -684.7899169921875, 7016.51904296875, 14.3928384780883789, 4.948853015899658203, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Vigilant Turtle (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 382619 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath (Scale 2, Up 1))
(@CGUID+38, 215480, 2444, 15105, 15121, '0', '0', 0, 0, 0, -631.43231201171875, 6949.93994140625, 0.240694344043731689, 4.160667896270751953, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Tobias Mistmantle (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 433073 - -Unknown-)
(@CGUID+39, 216432, 2444, 15105, 15121, '0', '0', 0, 0, 1, -662.51214599609375, 6960.95849609375, 9.387533187866210937, 4.432619571685791015, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Kaldorei Angler (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 433073 - -Unknown-)
(@CGUID+40, 216432, 2444, 15105, 15121, '0', '0', 0, 0, 1, -678.33160400390625, 6958.6171875, 10.43561458587646484, 4.963687896728515625, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Kaldorei Angler (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 433070 - -Unknown-)
(@CGUID+41, 216432, 2444, 15105, 15121, '0', '0', 0, 0, 1, -763.326416015625, 6925.12060546875, 2.462358951568603515, 6.108506202697753906, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Kaldorei Angler (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 433075 - -Unknown-)
(@CGUID+42, 216432, 2444, 15105, 15121, '0', '0', 0, 0, 1, -802.13543701171875, 7006.99853515625, 2.403669118881225585, 2.924001693725585937, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Kaldorei Angler (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 433075 - -Unknown-)
(@CGUID+43, 216721, 2444, 15105, 15121, '0', '0', 0, 0, 1, -758.72222900390625, 7012.83349609375, 4.313039302825927734, 4.828908443450927734, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Belanaar Sentinel (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+44, 216721, 2444, 15105, 15121, '0', '0', 0, 0, 1, -827.93402099609375, 6936.91650390625, 2.480532407760620117, 3.192994356155395507, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Belanaar Sentinel (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+45, 223440, 2444, 15105, 15121, '0', '0', 0, 0, 0, -841.732666015625, 6946.9833984375, 1.720060229301452636, 5.63374948501586914, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Silvia (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+46, 214214, 2444, 15105, 15131, '0', '0', 0, 0, 0, -657.70660400390625, 6797.533203125, 1.782032370567321777, 1.515710949897766113, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Vigilant Turtle (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 382619 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath (Scale 2, Up 1))
(@CGUID+47, 214214, 2444, 15105, 15131, '0', '0', 0, 0, 0, -610.09722900390625, 6782.8662109375, -1.513932466506958, 0.757005155086517333, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Vigilant Turtle (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 382619 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath (Scale 2, Up 1))
(@CGUID+48, 216432, 2444, 15105, 15121, '0', '0', 0, 0, 1, -851.4305419921875, 6963.587890625, 1.638122797012329101, 1.62959146499633789, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Kaldorei Angler (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 433075 - -Unknown-)
(@CGUID+49, 212502, 2444, 15105, 15121, '0', '0', 0, 0, 0, -551.7430419921875, 7092.81689453125, 0.701282799243927001, 3.469984292984008789, 120, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 55261), -- Petaldancer Salamanther (Area: -Unknown- - Difficulty: 0) CreateObject2
(@CGUID+50, 214214, 2444, 15105, 15121, '0', '0', 0, 0, 0, -580.9461669921875, 7064.59033203125, 2.162050724029541015, 5.706527233123779296, 120, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 55261), -- Vigilant Turtle (Area: -Unknown- - Difficulty: 0) CreateObject2
(@CGUID+51, 214197, 2444, 15105, 15121, '0', '0', 0, 0, 0, -519.078125, 7171.19189453125, 2.06640625, 1.006168961524963378, 120, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 55261), -- Petalgum Biter (Area: -Unknown- - Difficulty: 0) CreateObject2
(@CGUID+52, 214197, 2444, 15105, 15121, '0', '0', 0, 0, 0, -513.84375, 7121.4384765625, 1.22928619384765625, 4.425022602081298828, 120, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 55261), -- Petalgum Biter (Area: -Unknown- - Difficulty: 0) CreateObject2
(@CGUID+53, 212502, 2444, 15105, 15121, '0', '0', 0, 0, 0, -509.489593505859375, 7162.61279296875, 1.148871541023254394, 0.980930626392364501, 120, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 55261), -- Petaldancer Salamanther (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+54, 223448, 2444, 15105, 15131, '0', '0', 0, 0, 1, -714.30902099609375, 6790.65966796875, 6.457492828369140625, 2.142138481140136718, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Tambre (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+55, 216756, 2444, 15105, 15131, '0', '0', 0, 0, 1, -659.685791015625, 6849.98974609375, 36.106475830078125, 0.52385866641998291, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Drelanim Whisperwind (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+56, 223598, 2444, 15105, 15131, '0', '0', 0, 0, 1, -658.85589599609375, 6848.859375, 36.106475830078125, 0.462048858404159545, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Admiral Nightwind (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+57, 216721, 2444, 15105, 15131, '0', '0', 0, 0, 1, -701.076416015625, 6842.9443359375, 5.821938514709472656, 4.808942794799804687, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Belanaar Sentinel (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+58, 216721, 2444, 15105, 15131, '0', '0', 0, 0, 1, -650.92706298828125, 6844.38525390625, 17.34432220458984375, 0.6321183443069458, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Belanaar Sentinel (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+59, 216721, 2444, 15105, 15131, '0', '0', 0, 0, 1, -656.01910400390625, 6851.9130859375, 17.37213706970214843, 0.452021509408950805, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Belanaar Sentinel (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+60, 216721, 2444, 15105, 15131, '0', '0', 0, 0, 1, -678.39581298828125, 6806.9130859375, 5.061420440673828125, 2.664102792739868164, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Belanaar Sentinel (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+61, 223437, 2444, 15105, 15131, '0', '0', 0, 0, 0, -782.09893798828125, 6833.751953125, 2.673566818237304687, 3.082252979278564453, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Adella (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+62, 216432, 2444, 15105, 15131, '0', '0', 0, 0, 1, -777.451416015625, 6859.158203125, 0.66485762596130371, 0.584368884563446044, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Kaldorei Angler (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 433070 - -Unknown-)
(@CGUID+63, 216432, 2444, 15105, 15131, '0', '0', 0, 0, 1, -779.32464599609375, 6862.29150390625, 0.476192235946655273, 0.678981423377990722, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Kaldorei Angler (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 433073 - -Unknown-)
(@CGUID+64, 216710, 2444, 15105, 15131, '0', '0', 0, 0, 0, -670.10418701171875, 6851.36376953125, 37.82958984375, 1.951726317405700683, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261); -- Bel'ameth Watcher (Area: -Unknown- - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+64;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+37, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, '382619'), -- Vigilant Turtle - 382619 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath (Scale 2, Up 1)
(@CGUID+46, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, '382619'), -- Vigilant Turtle - 382619 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath (Scale 2, Up 1)
(@CGUID+47, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, '382619'), -- Vigilant Turtle - 382619 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath (Scale 2, Up 1)
(@CGUID+64, 0, 0, 1, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Bel'ameth Watcher

-- GameObjects
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+9;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 420982, 2444, 15105, 15121, '0', '0', 0, -676.29864501953125, 7022.548828125, 14.54606342315673828, 0, 0, 0, 0, 1, 120, 255, 1, 55261), -- Portal to Feathermoon Stronghold (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+1, 421186, 2444, 15105, 15121, '0', '0', 0, -330.380218505859375, 7000.59716796875, 7.33856964111328125, 1.933421611785888671, 0, 0, 0.823021888732910156, 0.568009674549102783, 120, 255, 1, 55261), -- Kaldorei Spyglass (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+2, 421750, 2444, 15105, 15121, '0', '0', 0, -649.217041015625, 6999.111328125, 14.96323013305664062, 3.447027206420898437, 0, 0, -0.98836135864257812, 0.152124300599098205, 120, 255, 1, 55261), -- Bench (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+3, 421751, 2444, 15105, 15121, '0', '0', 0, -653.1319580078125, 6998.38037109375, 14.97868824005126953, 0.061086613684892654, 0, 0, 0.030538558959960937, 0.999533593654632568, 120, 255, 1, 55261), -- Bench (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+4, 421180, 2444, 15105, 15121, '0', '0', 0, -658.3992919921875, 6974.34375, 21.22912406921386718, 5.441168785095214843, 0, 0, -0.40868091583251953, 0.912677347660064697, 120, 255, 1, 55261), -- Kaldorei Backpack (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+5, 421773, 2444, 15105, 15121, '0', '0', 0, -677.982666015625, 7050.2041015625, 14.57712173461914062, 3.691374778747558593, 0, 0, -0.96245479583740234, 0.271441996097564697, 120, 255, 1, 55261), -- Bench (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+6, 421753, 2444, 15105, 15121, '0', '0', 0, -688.18402099609375, 7049.8115234375, 14.33808708190917968, 5.70722818374633789, 0, 0, -0.28401470184326171, 0.958819925785064697, 120, 255, 1, 55261), -- Bench (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+7, 421781, 2444, 15105, 15121, '0', '0', 0, -685.45489501953125, 6987.1865234375, 14.95934391021728515, 1.797688722610473632, 0, 0, 0.7826080322265625, 0.622514784336090087, 120, 255, 1, 55261), -- Bench (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+8, 421774, 2444, 15105, 15121, '0', '0', 0, -647.935791015625, 6839.791015625, 17.29960441589355468, 0.253072351217269897, 0, 0, 0.126198768615722656, 0.992004990577697753, 120, 255, 1, 55261), -- Bench (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+9, 421775, 2444, 15105, 15121, '0', '0', 0, -659.1632080078125, 6856.60400390625, 17.29593276977539062, 0.820303261280059814, 0, 0, 0.398748397827148437, 0.917060375213623046, 120, 255, 1, 55261); -- Bench (Area: -Unknown- - Difficulty: 0) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+9;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 0, 1, 0, 3503); -- Portal to Feathermoon Stronghold

-- Template
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=212496; -- Shadelapper Duckling
UPDATE `creature_template` SET `faction`=188, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=212498; -- Mistfoot Hopper
UPDATE `creature_template` SET `faction`=1971, `BaseAttackTime`=1500, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=216646; -- Shen'dralar Sorcerer
UPDATE `creature_template` SET `faction`=2237, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=215480; -- Tobias Mistmantle
UPDATE `creature_template` SET `faction`=2237, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=215488; -- Belysra Starbreeze
UPDATE `creature_template` SET `faction`=1971, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=216720; -- Galley Chief Mariss
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=216797; -- Dendrythis
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=214231; -- Rockhorn Argali
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=223451; -- Celestine of the Harvest
UPDATE `creature_template` SET `faction`=2136, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=212495; -- Shadelapper Duck
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=223452; -- Ishala
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=210958; -- Vassandra Stormclaw
UPDATE `creature_template` SET `faction`=1971, `npcflag`=6272, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=216715; -- Merchant Fallel Stargazer
UPDATE `creature_template` SET `faction`=1971, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=216716; -- Mariner Bladewhisper
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=216707; -- Watchful Somnowl
UPDATE `creature_template` SET `faction`=1971, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=216721; -- Belanaar Sentinel
UPDATE `creature_template` SET `faction`=190, `speed_run`=0.992062866687774658, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=214214; -- Vigilant Turtle
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=212504; -- Keen-Eye Ohuna
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=214197; -- Petalgum Biter
UPDATE `creature_template` SET `faction`=188, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=210761; -- Fount Flutterer
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=212502; -- Petaldancer Salamanther
UPDATE `creature_template` SET `faction`=1971, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=216717; -- Mariner Evenmist
UPDATE `creature_template` SET `faction`=1971, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=216415; -- Taldar Windsinger
UPDATE `creature_template` SET `faction`=1971, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=223484; -- Captain Idrilae
UPDATE `creature_template` SET `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=768 WHERE `entry`=223440; -- Silvia
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=768 WHERE `entry`=223448; -- Tambre
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=768 WHERE `entry`=223437; -- Adella
UPDATE `creature_template` SET `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=223598; -- Admiral Nightwind
UPDATE `creature_template` SET `faction`=2854, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=216756; -- Drelanim Whisperwind

DELETE FROM `gameobject_template` WHERE `entry` IN (421775 /*Bench*/, 421774 /*Bench*/, 421751 /*Bench*/, 421753 /*Bench*/, 421180 /*Kaldorei Backpack*/, 421750 /*Bench*/, 421781 /*Bench*/, 421773 /*Bench*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(421775, 7, 85900, 'Bench', '', '', '', 1.029999971389770507, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 55261), -- Bench
(421774, 7, 85900, 'Bench', '', '', '', 1.029999971389770507, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 55261), -- Bench
(421751, 7, 85900, 'Bench', '', '', '', 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 55261), -- Bench
(421753, 7, 85900, 'Bench', '', '', '', 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 55261), -- Bench
(421180, 3, 87315, 'Kaldorei Backpack', 'questinteract', '', '', 1.20000004768371582, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6015, 121578, 0, 0, 0, 0, 2484, 55261), -- Kaldorei Backpack
(421750, 7, 85900, 'Bench', '', '', '', 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 55261), -- Bench
(421781, 7, 85900, 'Bench', '', '', '', 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 55261), -- Bench
(421773, 7, 85900, 'Bench', '', '', '', 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 55261); -- Bench

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (216721 /*216721 (Belanaar Sentinel) - Invisibility and Stealth Detection*/, 216803 /*216803 (Sentinel Eriadnar)*/, 216763 /*216763 (Cerellean Whiteclaw)*/, 216797 /*216797 (Dendrythis)*/, 223451 /*223451 (Celestine of the Harvest)*/, 223440 /*223440 (Silvia)*/, 223448 /*223448 (Tambre)*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(216721, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '18950'), -- 216721 (Belanaar Sentinel) - Invisibility and Stealth Detection
(216803, 0, 89248, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 216803 (Sentinel Eriadnar)
(216763, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 216763 (Cerellean Whiteclaw)
(216797, 0, 0, 0, 3, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 216797 (Dendrythis)
(223451, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 223451 (Celestine of the Harvest)
(223440, 0, 0, 0, 0, 0, 1, 0, 0, 27495, 0, 0, 0, ''), -- 223440 (Silvia)
(223448, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 223448 (Tambre)

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (421186 /*Kaldorei Spyglass*/, 268883 /*Fishing Bobber*/, 421180 /*Kaldorei Backpack*/, 420982 /*Portal to Feathermoon Stronghold*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(421186, 35, 2113536, 0, 0), -- Kaldorei Spyglass
(268883, 1971, 0, 2773, 0), -- Fishing Bobber
(421180, 35, 2113536, 0, 0), -- Kaldorei Backpack
(420982, 1732, 32, 0, 3503); -- Portal to Feathermoon Stronghold

-- Creature Equip
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (216721,216715,216720,223451,216716,223598,216756,223448));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(216721, 1, 213018, 0, 0, 0, 0, 0, 0, 0, 0, 55261), -- Belanaar Sentinel
(216715, 1, 1902, 0, 0, 0, 0, 0, 0, 0, 0, 55261), -- Merchant Fallel Stargazer
(216720, 1, 0, 0, 0, 3757, 0, 0, 0, 0, 0, 55261), -- Galley Chief Mariss
(223451, 1, 50695, 0, 0, 0, 0, 0, 0, 0, 0, 55261), -- Celestine of the Harvest
(216716, 1, 213012, 0, 0, 0, 0, 0, 5258, 0, 0, 55261), -- Mariner Bladewhisper
(223598, 1, 0, 0, 0, 0, 0, 0, 2552, 0, 0, 55261), -- Admiral Nightwind
(216756, 1, 97129, 0, 0, 0, 0, 0, 0, 0, 0, 55261), -- Drelanim Whisperwind
(223448, 1, 31802, 0, 0, 31803, 0, 0, 0, 0, 0, 55261); -- Tambre

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=0 AND `Entry` IN (223437,223448,223484,223598,223440,223452,223451));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`) VALUES
(223437, 0, 9, 1, 1, 274262, 4096, 0), -- Adella
(223448, 0, 9, 1, 1, 274273, 4096, 0), -- Tambre
(223484, 0, 9, 1.10000002384185791, 1, 274311, 0, 0), -- Captain Idrilae
(223598, 0, 9, 10, 1, 274457, 0, 0), -- Admiral Nightwind
(223440, 0, 9, 1, 1, 274265, 4096, 0), -- Silvia
(223452, 0, 9, 1, 1, 274279, 0, 0), -- Ishala
(223451, 0, 9, 15, 1, 274278, 0, 0); -- Celestine of the Harvest

UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=216716 AND `DifficultyID`=0); -- 216716 (Mariner Bladewhisper) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2152, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=212481 AND `DifficultyID`=0); -- 212481 (Murkfur Alpha) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=212497 AND `DifficultyID`=0); -- 212497 (Bloompaw Rabbit) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=223437 AND `DifficultyID`=0); -- 223437 (Adella) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=805306368, `VerifiedBuild`=55261 WHERE (`Entry`=214216 AND `DifficultyID`=0); -- 214216 (Gladeskipper Butterfly) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2152, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=214681 AND `DifficultyID`=0); -- 214681 (Emerald Dragon) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=223448 AND `DifficultyID`=0); -- 223448 (Tambre) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=805306368, `VerifiedBuild`=55261 WHERE (`Entry`=214196 AND `DifficultyID`=0); -- 214196 (Dappleflier) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2152, `StaticFlags1`=805306368, `VerifiedBuild`=55261 WHERE (`Entry`=212490 AND `DifficultyID`=0); -- 212490 (Coastwinged Slyvern) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=216717 AND `DifficultyID`=0); -- 216717 (Mariner Evenmist) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=216415 AND `DifficultyID`=0); -- 216415 (Taldar Windsinger) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=223484 AND `DifficultyID`=0); -- 223484 (Captain Idrilae) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2736, `StaticFlags1`=268435456, `StaticFlags3`=262144, `VerifiedBuild`=55261 WHERE (`Entry`=223598 AND `DifficultyID`=0); -- 223598 (Admiral Nightwind) - CanSwim - AllowInteractionWhileInCombat
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=216756 AND `DifficultyID`=0); -- 216756 (Drelanim Whisperwind) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2152, `StaticFlags1`=805306368, `VerifiedBuild`=55261 WHERE (`Entry`=212504 AND `DifficultyID`=0); -- 212504 (Keen-Eye Ohuna) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `StaticFlags3`=33554432, `VerifiedBuild`=55261 WHERE (`Entry`=223440 AND `DifficultyID`=0); -- 223440 (Silvia) - CanSwim - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=212496 AND `DifficultyID`=0); -- 212496 (Shadelapper Duckling) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2152, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=212495 AND `DifficultyID`=0); -- 212495 (Shadelapper Duck) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2736, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=215488 AND `DifficultyID`=0); -- 215488 (Belysra Starbreeze) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=223452 AND `DifficultyID`=0); -- 223452 (Ishala) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=876, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=216646 AND `DifficultyID`=0); -- 216646 (Shen'dralar Sorcerer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2736, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=215480 AND `DifficultyID`=0); -- 215480 (Tobias Mistmantle) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2736, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=210958 AND `DifficultyID`=0); -- 210958 (Vassandra Stormclaw) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `VerifiedBuild`=55261 WHERE (`Entry`=216720 AND `DifficultyID`=0); -- 216720 (Galley Chief Mariss) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=536870912, `VerifiedBuild`=55261 WHERE (`Entry`=216797 AND `DifficultyID`=0); -- 216797 (Dendrythis) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2254, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=214231 AND `DifficultyID`=0); -- 214231 (Rockhorn Argali) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=223451 AND `DifficultyID`=0); -- 223451 (Celestine of the Harvest) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=212498 AND `DifficultyID`=0); -- 212498 (Mistfoot Hopper) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=216715 AND `DifficultyID`=0); -- 216715 (Merchant Fallel Stargazer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2699, `StaticFlags1`=805306368, `VerifiedBuild`=55261 WHERE (`Entry`=216707 AND `DifficultyID`=0); -- 216707 (Watchful Somnowl) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=883, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=216721 AND `DifficultyID`=0); -- 216721 (Belanaar Sentinel) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=371, `StaticFlags1`=805306368, `VerifiedBuild`=55261 WHERE (`Entry`=210761 AND `DifficultyID`=0); -- 210761 (Fount Flutterer) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2469, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=214214 AND `DifficultyID`=0); -- 214214 (Vigilant Turtle) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=214197 AND `DifficultyID`=0); -- 214197 (Petalgum Biter) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2152, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=212502 AND `DifficultyID`=0); -- 212502 (Petaldancer Salamanther) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2152, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=212482 AND `DifficultyID`=0); -- 212482 (Murkfur Pup) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=216808 AND `DifficultyID`=0); -- 216808 (Huntress Iczelia) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=216465 AND `DifficultyID`=0); -- 216465 (Ancient Protector) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2152, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=212480 AND `DifficultyID`=0); -- 212480 (Murkfur Bakar) - CanSwim

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=216803 AND `MenuID`=34915) OR (`CreatureID`=223484 AND `MenuID`=34914) OR (`CreatureID`=223440 AND `MenuID`=23778) OR (`CreatureID`=223598 AND `MenuID`=12609);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(216803, 34915, 55261), -- Sentinel Eriadnar
(223484, 34914, 55261), -- Captain Idrilae
(223440, 23778, 55261), -- Silvia
(223598, 12609, 55261); -- Admiral Nightwind

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+1;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 263780, 0, 0, 0, 0, 0, 0, 0, 55261), -- 223484 (Captain Idrilae)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 263781, 0, 0, 0, 0, 0, 0, 0, 55261); -- 216803 (Sentinel Eriadnar)

DELETE FROM `gossip_menu` WHERE (`MenuID`=34914 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=34915 AND `TextID`=@NPCTEXTID+1);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(34914, @NPCTEXTID+0, 55261), -- 223484 (Captain Idrilae)
(34915, @NPCTEXTID+1, 55261); -- 216803 (Sentinel Eriadnar)

DELETE FROM `gossip_menu` WHERE (`MenuID`=23778 AND `TextID`=37177);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(23778, 37177, 55261); -- 223440 (Silvia)

UPDATE `gossip_menu` SET `VerifiedBuild`=55261 WHERE (`MenuID`=12609 AND `TextID`=17749);

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID` IN (116850, 119581, 119577, 116851, 116974, 117018, 116849, 116975, 117020, 117019, 116848, 116971, 116970, 117012, 117035, 113045, 116985, 117034, 117024, 119578, 116944, 119583, 116931, 116924, 117022, 110876, 110878, 116998, 110079, 101619, 116984);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(116850, 0.305999994277954101, 1.5, 0, 55261),
(119581, 0.388999998569488525, 1.5, 0, 55261),
(119577, 0.388999998569488525, 1.5, 0, 55261),
(116851, 0.305999994277954101, 1.5, 0, 55261),
(116974, 0.388999998569488525, 1.5, 0, 55261),
(117018, 0.388999998569488525, 1.5, 0, 55261),
(116849, 0.305999994277954101, 1.5, 0, 55261),
(116975, 0.388999998569488525, 1.5, 0, 55261),
(117020, 0.388999998569488525, 1.5, 0, 55261),
(117019, 0.388999998569488525, 1.5, 0, 55261),
(116848, 0.305999994277954101, 1.5, 0, 55261),
(116971, 0.305999994277954101, 1.5, 0, 55261),
(116970, 0.305999994277954101, 1.5, 0, 55261),
(117012, 0.447349995374679565, 1.724999904632568359, 0, 55261),
(117035, 0.388999998569488525, 1.5, 0, 55261),
(113045, 0.305999994277954101, 1.5, 0, 55261),
(116985, 1.07983410358428955, 0, 0, 55261),
(117034, 0.305999994277954101, 1.5, 0, 55261),
(117024, 0.305999994277954101, 1.5, 0, 55261),
(119578, 0.305999994277954101, 1.5, 0, 55261),
(116944, 0.388999998569488525, 1.5, 0, 55261),
(119583, 0.388999998569488525, 1.5, 0, 55261),
(116931, 0.305999994277954101, 1.5, 0, 55261),
(116924, 0.305999994277954101, 1.5, 0, 55261),
(117022, 0.305999994277954101, 1.5, 0, 55261),
(110876, 0.73621445894241333, 0, 0, 55261),
(110878, 0.73621445894241333, 0, 0, 55261),
(116998, 0.305999994277954101, 1.5, 0, 55261),
(110079, 0.567548632621765136, 1.5, 0, 55261),
(101619, 0.851322948932647705, 2.25, 0, 55261),
(116984, 1.07983410358428955, 0, 0, 55261);

UPDATE `creature_model_info` SET `VerifiedBuild`=55261 WHERE `DisplayID` IN (78834, 104675, 101135, 100702, 22468, 28501, 33508, 30813, 106535, 104135, 65532, 100704, 104045, 103367);
UPDATE `creature_model_info` SET `CombatReach`=1.399999976158142089, `VerifiedBuild`=55261 WHERE `DisplayID` IN (105961, 105962);

-- Vendor
DELETE FROM `npc_vendor` WHERE (`entry`=216720 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216720 AND `item`=30817 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216720 AND `item`=8950 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216720 AND `item`=4601 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216720 AND `item`=4544 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216720 AND `item`=4542 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216720 AND `item`=4541 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216720 AND `item`=4540 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216720 AND `item`=8957 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216720 AND `item`=21552 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216720 AND `item`=4594 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216720 AND `item`=4593 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216720 AND `item`=4592 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216720 AND `item`=787 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216720 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216720 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216720 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216720 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216720 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216720 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216720 AND `item`=4600 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216715 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216715 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216715 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216715 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216715 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216715 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216715 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216715 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216715 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216715 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216715 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216715 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216715 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216715 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216715 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216715 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216715 AND `item`=160298 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216715 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216715 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216715 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216715 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216715 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216715 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216715 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216715 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216715 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216715 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216715 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216715 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216715 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=216715 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(216720, 21, 2678, 0, 0, 1, 0, 0, 55261), -- Mild Spices
(216720, 20, 30817, 0, 0, 1, 0, 0, 55261), -- Simple Flour
(216720, 19, 8950, 0, 0, 1, 0, 0, 55261), -- Homemade Cherry Pie
(216720, 18, 4601, 0, 0, 1, 0, 0, 55261), -- Soft Banana Bread
(216720, 17, 4544, 0, 0, 1, 0, 0, 55261), -- Mulgore Spice Bread
(216720, 16, 4542, 0, 0, 1, 0, 0, 55261), -- Moist Cornbread
(216720, 15, 4541, 0, 0, 1, 0, 0, 55261), -- Freshly Baked Bread
(216720, 14, 4540, 0, 0, 1, 0, 0, 55261), -- Tough Hunk of Bread
(216720, 13, 8957, 0, 0, 1, 0, 0, 55261), -- Spinefin Halibut
(216720, 12, 21552, 0, 0, 1, 0, 0, 55261), -- Striped Yellowtail
(216720, 11, 4594, 0, 0, 1, 0, 0, 55261), -- Rockscale Cod
(216720, 10, 4593, 0, 0, 1, 0, 0, 55261), -- Bristle Whisker Catfish
(216720, 9, 4592, 0, 0, 1, 0, 0, 55261), -- Longjaw Mud Snapper
(216720, 8, 787, 0, 0, 1, 0, 0, 55261), -- Slitherskin Mackerel
(216720, 7, 8766, 0, 0, 1, 0, 0, 55261), -- Morning Glory Dew
(216720, 6, 1645, 0, 0, 1, 0, 0, 55261), -- Moonberry Juice
(216720, 5, 1708, 0, 0, 1, 0, 0, 55261), -- Sweet Nectar
(216720, 4, 1205, 0, 0, 1, 0, 0, 55261), -- Melon Juice
(216720, 3, 1179, 0, 0, 1, 0, 0, 55261), -- Ice Cold Milk
(216720, 2, 159, 0, 0, 1, 0, 0, 55261), -- Refreshing Spring Water
(216720, 1, 4600, 0, 0, 1, 0, 0, 55261), -- Cherry Grog
(216715, 31, 64670, 0, 0, 1, 0, 0, 55261), -- Vanishing Powder
(216715, 30, 39505, 0, 0, 1, 0, 0, 55261), -- Virtuoso Inking Set
(216715, 29, 20815, 0, 0, 1, 0, 0, 55261), -- Jeweler's Toolset
(216715, 28, 6532, 0, 0, 1, 0, 0, 55261), -- Bright Baubles
(216715, 27, 6530, 0, 0, 1, 0, 0, 55261), -- Nightcrawlers
(216715, 26, 4400, 0, 0, 1, 0, 0, 55261), -- Heavy Stock
(216715, 25, 4399, 0, 0, 1, 0, 0, 55261), -- Wooden Stock
(216715, 24, 4289, 0, 0, 1, 0, 0, 55261), -- Salt
(216715, 23, 3371, 0, 0, 1, 0, 0, 55261), -- Crystal Vial
(216715, 22, 4340, 0, 0, 1, 0, 0, 55261), -- Gray Dye
(216715, 21, 4342, 0, 0, 1, 0, 0, 55261), -- Purple Dye
(216715, 20, 4341, 0, 0, 1, 0, 0, 55261), -- Yellow Dye
(216715, 19, 2325, 0, 0, 1, 0, 0, 55261), -- Black Dye
(216715, 18, 2604, 0, 0, 1, 0, 0, 55261), -- Red Dye
(216715, 17, 2324, 0, 0, 1, 0, 0, 55261), -- Bleach
(216715, 16, 3857, 0, 0, 1, 0, 0, 55261), -- Coal
(216715, 15, 160298, 0, 0, 1, 0, 0, 55261), -- Durable Flux
(216715, 14, 3466, 0, 0, 1, 0, 0, 55261), -- Strong Flux
(216715, 13, 2880, 0, 0, 1, 0, 0, 55261), -- Weak Flux
(216715, 12, 2678, 0, 0, 1, 0, 0, 55261), -- Mild Spices
(216715, 11, 14341, 0, 0, 1, 0, 0, 55261), -- Rune Thread
(216715, 10, 8343, 0, 0, 1, 0, 0, 55261), -- Heavy Silken Thread
(216715, 9, 4291, 0, 0, 1, 0, 0, 55261), -- Silken Thread
(216715, 8, 2321, 0, 0, 1, 0, 0, 55261), -- Fine Thread
(216715, 7, 2320, 0, 0, 1, 0, 0, 55261), -- Coarse Thread
(216715, 6, 6217, 0, 0, 1, 0, 0, 55261), -- Copper Rod
(216715, 5, 5956, 0, 0, 1, 0, 0, 55261), -- Blacksmith Hammer
(216715, 4, 6256, 0, 0, 1, 0, 0, 55261), -- Fishing Pole
(216715, 3, 2901, 0, 0, 1, 0, 0, 55261), -- Mining Pick
(216715, 2, 85663, 0, 0, 1, 0, 0, 55261), -- Herbalist's Spade
(216715, 1, 7005, 0, 0, 1, 0, 0, 55261); -- Skinning Knife

-- Kaldorei Angler smart ai
SET @ENTRY := 216432;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 1, 0, 100, 1, 1000, 1000, 0, 0, 85, 433070, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Time = 1 seconds (OOC) - Self: Cast spell 433070 on self'),
(@ENTRY, 0, 1, 0, '', 1, 0, 100, 1, 1000, 1000, 0, 0, 85, 433073, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Time = 1 seconds (OOC) - Self: Cast spell 433073 on self'),
(@ENTRY, 0, 2, 0, '', 1, 0, 100, 0, 1000, 1000, 0, 0, 85, 433075, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Time = 1 seconds (OOC) - Self: Cast spell 433075 on self');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceGroup` IN (1,2,3) AND `SourceEntry` = @ENTRY;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, @ENTRY, 0, 0, 58, 1, 0, 0, 0, 'AzsunaBobber', 0, 'Scripted creature has StringId ''AzsunaBobber'''),
(22, 2, @ENTRY, 0, 0, 58, 1, 0, 0, 0, 'SuramarBobber', 0, 'Scripted creature has StringId ''SuramarBobber'''),
(22, 3, @ENTRY, 0, 0, 58, 1, 0, 0, 0, 'ValsharahBobber', 0, 'Scripted creature has StringId ''ValsharahBobber''');

UPDATE `creature` SET `StringId`='AzsunaBobber' WHERE `guid` IN (@CGUID+16, @CGUID+17, @CGUID+40, @CGUID+62);
UPDATE `creature` SET `StringId`='SuramarBobber' WHERE `guid` IN (@CGUID+6, @CGUID+11, @CGUID+14, @CGUID+18, @CGUID+39, @CGUID+63);
UPDATE `creature` SET `StringId`='ValsharahBobber' WHERE `guid` IN (@CGUID+1, @CGUID+2, @CGUID+8, @CGUID+9, @CGUID+10, @CGUID+13, @CGUID+41, @CGUID+42, @CGUID+48);

-- Captain Idrilae smart ai
SET @ENTRY := 223484;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 1, 0, 100, 0, 1000, 3000, 7000, 10000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 7 - 10 seconds (1 - 3s initially) (OOC) - Self: Play emote 1');

-- Taldar Windsinger smart ai
SET @ENTRY := 216415;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 1, 0, 100, 0, 1000, 3000, 7000, 10000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 7 - 10 seconds (1 - 3s initially) (OOC) - Self: Play emote 1');

-- Celestine of the Harvest smart ai
SET @ENTRY := 223451;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 1, 0, 100, 0, 1000, 3000, 7000, 10000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 7 - 10 seconds (1 - 3s initially) (OOC) - Self: Play emote 1');

-- Vassandra Stormclaw smart ai
SET @ENTRY := 210958;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 1, 0, 100, 0, 1000, 3000, 7000, 10000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 7 - 10 seconds (1 - 3s initially) (OOC) - Self: Play emote 1');

-- Tobias Mistmantle smart ai
SET @ENTRY := 215480;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 1, 0, 100, 0, 1000, 1000, 0, 0, 85, 433073, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Time = 1 seconds (OOC) - Self: Cast spell 433073 on self');

-- Path for Maginer Swiftstar
SET @ENTRY := 216718;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Mariner Swiftstar - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -444.2235, 7058.679, 6.714916, NULL, 0),
(@PATH, 1, -424.8285, 7063.065, 6.385643, NULL, 0),
(@PATH, 2, -398.4327, 7069.443, 6.499007, NULL, 0),
(@PATH, 3, -378.1887, 7075.13, 9.679476, NULL, 0),
(@PATH, 4, -358.6361, 7080.143, 10.86702, NULL, 0),
(@PATH, 5, -355.0426, 7087.062, 11.32119, NULL, 0),
(@PATH, 6, -349.6088, 7092.846, 11.24374, NULL, 0),
(@PATH, 7, -342.2732, 7091.438, 11.19068, NULL, 0),
(@PATH, 8, -336.4789, 7084.798, 11.03285, NULL, 0),
(@PATH, 9, -328.0341, 7087.375, 10.68585, NULL, 0),
(@PATH, 10, -314.0624, 7090.527, 9.352626, NULL, 0),
(@PATH, 11, -294.4077, 7094.997, 6.419819, NULL, 0),
(@PATH, 12, -279.6555, 7098.687, 6.385643, NULL, 0),
(@PATH, 13, -264.7729, 7102.727, 6.43664, NULL, 0),
(@PATH, 14, -228.8735, 7111.226, 6.385643, NULL, 0),
(@PATH, 15, -218.9809, 7113.837, 6.420766, NULL, 0),
(@PATH, 16, -210.873, 7115.52, 6.385643, NULL, 4799),
(@PATH, 17, -229.2167, 7112.437, 6.385643, NULL, 0),
(@PATH, 18, -237.2074, 7110.013, 6.385643, NULL, 0),
(@PATH, 19, -249.9359, 7107.223, 6.385643, NULL, 0),
(@PATH, 20, -265.0708, 7103.95, 6.477472, NULL, 0),
(@PATH, 21, -279.973, 7099.904, 6.385643, NULL, 0),
(@PATH, 22, -294.6999, 7096.22, 6.385643, NULL, 0),
(@PATH, 23, -314.3082, 7091.762, 9.304844, NULL, 0),
(@PATH, 24, -328.3756, 7088.585, 10.67763, NULL, 0),
(@PATH, 25, -336.2573, 7085.612, 10.98274, NULL, 0),
(@PATH, 26, -341.8518, 7092.169, 11.09546, NULL, 0),
(@PATH, 27, -349.8669, 7093.649, 11.14192, NULL, 0),
(@PATH, 28, -355.6841, 7087.641, 11.26579, NULL, 0),
(@PATH, 29, -359.1521, 7080.812, 10.79189, NULL, 0),
(@PATH, 30, -378.6967, 7077.153, 9.656857, NULL, 0),
(@PATH, 31, -425.3035, 7065.096, 6.385643, NULL, 0),
(@PATH, 32, -444.7002, 7060.709, 6.707929, NULL, 0),
(@PATH, 33, -459.1752, 7057.187, 9.332377, NULL, 0),
(@PATH, 34, -475.6627, 7053.481, 10.26716, NULL, 0),
(@PATH, 35, -488.8684, 7050.419, 8.091465, NULL, 0),
(@PATH, 36, -507.0684, 7045.768, 6.385643, NULL, 0),
(@PATH, 37, -541.7162, 7037.717, 6.376152, NULL, 0),
(@PATH, 38, -569.29, 7030.037, 10.25049, NULL, 0),
(@PATH, 39, -586.4127, 7026.879, 11.7824, NULL, 0),
(@PATH, 40, -591.7389, 7027.344, 11.31566, NULL, 0),
(@PATH, 41, -591.92, 7024.52, 11.30678, NULL, 8977),
(@PATH, 42, -568.821, 7028.005, 10.21195, NULL, 0),
(@PATH, 43, -541.2004, 7035.696, 6.376152, NULL, 0),
(@PATH, 44, -506.574, 7043.741, 6.521868, NULL, 0),
(@PATH, 45, -488.3746, 7048.393, 8.09162, NULL, 0),
(@PATH, 46, -475.1985, 7051.448, 10.29431, NULL, 0),
(@PATH, 47, -458.6998, 7055.155, 9.311718, NULL, 0);

UPDATE `creature` SET `position_x`= -444.2235, `position_y`= 7058.679, `position_z`= 6.714916, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+12;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+12;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+12, @PATH, 1);

-- Path for Mariner Farsight
SET @ENTRY := 216719;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Mariner Farsight - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -249.5549, 7105.473, 6.385643, NULL, 0),
(@PATH, 1, -236.7553, 7108.279, 6.385643, NULL, 0),
(@PATH, 2, -228.7282, 7110.714, 6.385643, NULL, 0),
(@PATH, 3, -218.8514, 7113.32, 6.421762, NULL, 0),
(@PATH, 4, -210.7597, 7115.042, 6.385643, NULL, 0),
(@PATH, 5, -229.3621, 7112.949, 6.385643, NULL, 0),
(@PATH, 6, -237.3419, 7110.528, 6.385643, NULL, 0),
(@PATH, 7, -250.0493, 7107.743, 6.385643, NULL, 0),
(@PATH, 8, -265.197, 7104.467, 6.494731, NULL, 0),
(@PATH, 9, -280.1075, 7100.42, 6.385643, NULL, 0),
(@PATH, 10, -294.8236, 7096.739, 6.385643, NULL, 0),
(@PATH, 11, -314.3249, 7092.304, 9.285481, NULL, 0),
(@PATH, 12, -328.5202, 7089.098, 10.67416, NULL, 0),
(@PATH, 13, -336.9212, 7085.755, 11.14953, NULL, 0),
(@PATH, 14, -339.8725, 7077.064, 11.20037, NULL, 0),
(@PATH, 15, -345.2392, 7072.23, 11.06675, NULL, 0),
(@PATH, 16, -342.8441, 7055.837, 10.2385, NULL, 0),
(@PATH, 17, -340.8018, 7048.103, 9.273314, NULL, 0),
(@PATH, 18, -336.5584, 7031.103, 6.494926, NULL, 0),
(@PATH, 19, -333.2668, 7014.417, 6.385643, NULL, 0),
(@PATH, 20, -331.533, 7014.78, 6.385643, NULL, 4041),
(@PATH, 21, -333.9208, 7031.707, 6.484591, NULL, 0),
(@PATH, 22, -338.1809, 7048.776, 9.213841, NULL, 0),
(@PATH, 23, -340.2046, 7056.433, 10.28481, NULL, 0),
(@PATH, 24, -343.9821, 7072.558, 11.02192, NULL, 0),
(@PATH, 25, -350.3765, 7073.145, 11.29751, NULL, 0),
(@PATH, 26, -358.6794, 7081.227, 10.95431, NULL, 0),
(@PATH, 27, -378.9119, 7078.01, 9.650318, NULL, 0),
(@PATH, 28, -399.1829, 7072.315, 6.464396, NULL, 0),
(@PATH, 29, -425.5046, 7065.956, 6.385643, NULL, 0),
(@PATH, 30, -444.902, 7061.569, 6.704981, NULL, 0),
(@PATH, 31, -459.3764, 7058.046, 9.336417, NULL, 0),
(@PATH, 32, -475.8592, 7054.342, 10.25321, NULL, 0),
(@PATH, 33, -489.0775, 7051.278, 8.091434, NULL, 0),
(@PATH, 34, -507.2777, 7046.625, 6.385643, NULL, 0),
(@PATH, 35, -541.8441, 7038.594, 6.376152, NULL, 0),
(@PATH, 36, -569.4886, 7030.898, 10.25623, NULL, 0),
(@PATH, 37, -586.4638, 7027.761, 11.7824, NULL, 0),
(@PATH, 38, -591.6746, 7028.313, 11.31411, NULL, 0),
(@PATH, 39, -591.92, 7024.52, 11.30678, NULL, 5094),
(@PATH, 40, -568.6224, 7027.144, 10.23032, NULL, 0),
(@PATH, 41, -540.9819, 7034.84, 6.376152, NULL, 0),
(@PATH, 42, -506.3647, 7042.883, 6.618725, NULL, 0),
(@PATH, 43, -488.1655, 7047.535, 8.091652, NULL, 0),
(@PATH, 44, -475.0019, 7050.586, 10.29258, NULL, 0),
(@PATH, 45, -458.4986, 7054.295, 9.331022, NULL, 0),
(@PATH, 46, -444.0216, 7057.819, 6.717879, NULL, 0),
(@PATH, 47, -424.6274, 7062.205, 6.385643, NULL, 0),
(@PATH, 48, -398.2095, 7068.588, 6.509305, NULL, 0),
(@PATH, 49, -377.9735, 7074.273, 9.659117, NULL, 0),
(@PATH, 50, -358.4177, 7079.86, 10.92467, NULL, 0),
(@PATH, 51, -354.7052, 7086.943, 11.36219, NULL, 0),
(@PATH, 52, -349.4995, 7092.505, 11.26975, NULL, 0),
(@PATH, 53, -342.5816, 7091.153, 11.2122, NULL, 0),
(@PATH, 54, -336.5728, 7084.453, 11.03427, NULL, 0),
(@PATH, 55, -327.8895, 7086.862, 10.68932, NULL, 0),
(@PATH, 56, -313.9447, 7090.007, 9.372982, NULL, 0),
(@PATH, 57, -294.284, 7094.478, 6.428473, NULL, 0),
(@PATH, 58, -279.521, 7098.171, 6.385643, NULL, 0),
(@PATH, 59, -264.6468, 7102.209, 6.419365, NULL, 0),
(@PATH, 60, -249.5549, 7105.473, 6.385643, NULL, 0),
(@PATH, 61, -236.7553, 7108.279, 6.385643, NULL, 0),
(@PATH, 62, -228.7282, 7110.714, 6.385643, NULL, 0),
(@PATH, 63, -218.8514, 7113.32, 6.421762, NULL, 0),
(@PATH, 64, -210.7597, 7115.042, 6.385643, NULL, 0),
(@PATH, 65, -210.873, 7115.52, 6.385643, NULL, 2769),
(@PATH, 66, -229.3621, 7112.949, 6.385643, NULL, 0),
(@PATH, 67, -237.3419, 7110.528, 6.385643, NULL, 0),
(@PATH, 68, -250.0493, 7107.743, 6.385643, NULL, 0),
(@PATH, 69, -265.197, 7104.467, 6.494731, NULL, 0);

UPDATE `creature` SET `position_x`= -249.5549, `position_y`= 7105.473, `position_z`= 6.385643, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+15;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+15;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+15, @PATH, 1);

-- Mariner Bladewhisper
SET @ENTRY := 216716;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Mariner Bladewhisper - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -613.0415, 7017.007, 12.23408, NULL, 0),
(@PATH, 1, -618.9437, 7011.63, 12.30811, NULL, 0),
(@PATH, 2, -629.3265, 7008.188, 12.22587, NULL, 0),
(@PATH, 3, -641.0456, 7006.237, 14.97975, NULL, 0),
(@PATH, 4, -649.0396, 7003.989, 14.9699, NULL, 0),
(@PATH, 5, -654.7565, 7003.953, 15.0327, NULL, 0),
(@PATH, 6, -660.6396, 7003.655, 15.02556, NULL, 0),
(@PATH, 7, -667.4012, 7002.082, 14.9699, NULL, 0),
(@PATH, 8, -671.6588, 7000.751, 14.9699, NULL, 0),
(@PATH, 9, -672.6371, 7004.577, 14.9699, 3.946133, 11184),
(@PATH, 10, -685.0151, 6995.709, 15.00261, NULL, 0),
(@PATH, 11, -694.0286, 6992.051, 15.00262, NULL, 0),
(@PATH, 12, -701.3373, 6990.289, 14.11864, NULL, 0),
(@PATH, 13, -716.5903, 6988.769, 10.8654, NULL, 0),
(@PATH, 14, -728.7397, 6992.981, 8.732605, NULL, 0),
(@PATH, 15, -736.9479, 7003.715, 6.806355, NULL, 0),
(@PATH, 16, -751.0658, 7006.463, 4.686409, NULL, 0),
(@PATH, 17, -764.0928, 7003.558, 3.341783, NULL, 0),
(@PATH, 18, -773.2811, 6992.816, 2.213021, NULL, 0),
(@PATH, 19, -782.2063, 6985.419, 2.003741, NULL, 0),
(@PATH, 20, -787.8115, 6980.907, 4.150393, NULL, 0),
(@PATH, 21, -795.928, 6974.334, 8.047419, NULL, 0),
(@PATH, 22, -804.1801, 6966.755, 11.57928, NULL, 0),
(@PATH, 23, -811.0738, 6960.971, 11.1927, NULL, 0),
(@PATH, 24, -825.9825, 6948.421, 4.249139, NULL, 0),
(@PATH, 25, -833.5652, 6938.183, 2.172491, NULL, 0),
(@PATH, 26, -837.0329, 6926.361, 2.408709, NULL, 0),
(@PATH, 27, -836.736, 6912.379, 2.454994, NULL, 0),
(@PATH, 28, -837.0348, 6898.241, 1.912582, NULL, 0),
(@PATH, 29, -842.0923, 6883.189, 0.7716143, NULL, 0),
(@PATH, 30, -844.6612, 6872.3, -0.04343073, NULL, 0),
(@PATH, 31, -837.6255, 6867.742, 0.4143121, NULL, 0),
(@PATH, 32, -826.8759, 6860.621, 1.654269, NULL, 0),
(@PATH, 33, -814.9301, 6849.353, 2.774899, NULL, 0),
(@PATH, 34, -797.1307, 6840.74, 2.6756, NULL, 0),
(@PATH, 35, -776.3927, 6838.453, 2.524647, NULL, 0),
(@PATH, 36, -756.4286, 6831.657, 5.298503, NULL, 0),
(@PATH, 37, -737.3784, 6823.675, 2.923245, NULL, 0),
(@PATH, 38, -729.0165, 6822.196, 3.185615, NULL, 0),
(@PATH, 39, -721.4677, 6821.805, 3.372219, NULL, 0),
(@PATH, 40, -711.6631, 6827.57, 4.100808, NULL, 0),
(@PATH, 41, -704.852, 6833.984, 5.047148, NULL, 0),
(@PATH, 42, -691.797, 6825.58, 5.890833, NULL, 5128),
(@PATH, 43, -708.8994, 6823.753, 3.954462, NULL, 0),
(@PATH, 44, -720.3379, 6817.23, 3.435481, NULL, 0),
(@PATH, 45, -729.5251, 6817.512, 3.334493, NULL, 0),
(@PATH, 46, -738.5782, 6819.597, 2.859081, NULL, 0),
(@PATH, 47, -758.0992, 6827.251, 5.383128, NULL, 0),
(@PATH, 48, -777.4198, 6833.854, 2.51456, NULL, 0),
(@PATH, 49, -798.4354, 6836.211, 2.760753, NULL, 0),
(@PATH, 50, -817.6012, 6845.471, 2.946625, NULL, 0),
(@PATH, 51, -829.8012, 6856.926, 1.635958, NULL, 0),
(@PATH, 52, -840.2947, 6863.859, 0.6971288, NULL, 0),
(@PATH, 53, -849.0436, 6870.568, 0.02483641, NULL, 0),
(@PATH, 54, -846.6437, 6884.409, 0.6858225, NULL, 0),
(@PATH, 55, -841.677, 6899.049, 1.834334, NULL, 0),
(@PATH, 56, -841.4481, 6912.379, 2.388713, NULL, 0),
(@PATH, 57, -841.7032, 6926.988, 2.29126, NULL, 0),
(@PATH, 58, -837.7855, 6940.279, 2.023427, NULL, 0),
(@PATH, 59, -829.4203, 6951.644, 4.068499, NULL, 0),
(@PATH, 60, -814.1068, 6964.578, 11.27953, NULL, 0),
(@PATH, 61, -807.2887, 6970.296, 11.53659, NULL, 0),
(@PATH, 62, -799.006, 6977.902, 8.196292, NULL, 0),
(@PATH, 63, -790.7719, 6984.573, 4.143846, NULL, 0),
(@PATH, 64, -785.186, 6989.07, 2.022791, NULL, 0),
(@PATH, 65, -776.573, 6996.188, 2.218696, NULL, 0),
(@PATH, 66, -766.5148, 7007.6, 3.349164, NULL, 0),
(@PATH, 67, -751.1252, 7011.175, 4.498532, NULL, 0),
(@PATH, 68, -734.4584, 7007.716, 7.313743, NULL, 0),
(@PATH, 69, -725.993, 6996.811, 8.713339, NULL, 0),
(@PATH, 70, -716.0555, 6993.45, 10.67449, NULL, 0),
(@PATH, 71, -702.1719, 6994.889, 14.33582, NULL, 0),
(@PATH, 72, -695.0721, 6995.681, 15.03531, NULL, 0),
(@PATH, 73, -686.5231, 6999.172, 15.05334, NULL, 0),
(@PATH, 74, -679.8234, 7002.282, 14.9699, NULL, 0),
(@PATH, 75, -675.0313, 7004.027, 14.9699, NULL, 0),
(@PATH, 76, -668.2966, 7005.751, 14.9699, NULL, 0),
(@PATH, 77, -661.3118, 7007.372, 15.01691, NULL, 0),
(@PATH, 78, -655.0699, 7008.654, 15.08356, NULL, 0),
(@PATH, 79, -649.6931, 7008.656, 14.97278, NULL, 0),
(@PATH, 80, -642.2059, 7010.785, 14.97076, NULL, 0),
(@PATH, 81, -630.4513, 7012.765, 12.3095, NULL, 0),
(@PATH, 82, -621.3203, 7015.7, 12.23718, NULL, 0),
(@PATH, 83, -615.6078, 7020.959, 12.15553, NULL, 0),
(@PATH, 84, -597.9864, 7028.916, 11.17155, NULL, 0),
(@PATH, 85, -591.92, 7024.52, 11.30678, NULL, 4187),
(@PATH, 86, -613.0415, 7017.007, 12.23408, NULL, 0),
(@PATH, 87, -618.9437, 7011.63, 12.30811, NULL, 0),
(@PATH, 88, -629.3265, 7008.188, 12.22587, NULL, 0),
(@PATH, 89, -641.0456, 7006.237, 14.97975, NULL, 0),
(@PATH, 90, -649.0396, 7003.989, 14.9699, NULL, 0),
(@PATH, 91, -654.7565, 7003.953, 15.0327, NULL, 0),
(@PATH, 92, -660.6396, 7003.655, 15.02556, NULL, 0),
(@PATH, 93, -667.4012, 7002.082, 14.9699, NULL, 0),
(@PATH, 94, -671.6588, 7000.751, 14.9699, NULL, 0),
(@PATH, 95, -672.6371, 7004.577, 14.9699, NULL, 0);

UPDATE `creature` SET `position_x`= -613.0415, `position_y`= 7017.007, `position_z`= 12.23408, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+23;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+23;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+23, @PATH, 1);

-- Path for Adella
SET @ENTRY := 223437;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Adella - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -721.0695, 6814.263, 3.540386, NULL, 0),
(@PATH, 1, -732.0139, 6817.4, 3.307072, NULL, 0),
(@PATH, 2, -753.7778, 6824.005, 5.322386, NULL, 0),
(@PATH, 3, -782.0989, 6833.752, 2.673567, NULL, 7874),
(@PATH, 4, -753.7778, 6824.005, 5.322386, NULL, 0),
(@PATH, 5, -732.0139, 6817.4, 3.307072, NULL, 0),
(@PATH, 6, -721.0695, 6814.263, 3.540386, NULL, 0),
(@PATH, 7, -707.3455, 6808.688, 4.269749, NULL, 7704);

UPDATE `creature` SET `position_x`= -721.0695, `position_y`= 6814.263, `position_z`= 3.540386, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+61;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+61;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+61, @PATH, 1);
