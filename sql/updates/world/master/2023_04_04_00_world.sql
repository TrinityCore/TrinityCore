SET @CGUID := 396717;
SET @OGUID := 253261;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+381;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 59193, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 240.578125, 80.14409637451171875, 113.5740585327148437, 6.248278617858886718, 86400, 0, 0, 11812, 5485, 0, 0, 0, 0, 48865), -- Boneweaver (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 113647 - Boneweaving)
(@CGUID+1, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 211.203125, 148.0260467529296875, 113.320068359375, 3.141592741012573242, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+2, 59503, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 308.98089599609375, 10.59895801544189453, 113.49212646484375, 0, 86400, 2, 0, 1427, 0, 1, 0, 0, 0, 48865), -- Brittle Skeleton (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 19818 - Double Attack)
(@CGUID+3, 54020, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 261.461822509765625, 98.751739501953125, 114.3255996704101562, 4.764750480651855468, 86400, 0, 0, 112919, 0, 0, 0, 0, 0, 48865), -- General Purpose Bunny JMF (Look 2 - Flying, Huge AOI) (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: )
(@CGUID+4, 59304, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 245.0121612548828125, 81.74826812744140625, 113.4810562133789062, 1.989675283432006835, 86400, 0, 0, 2854, 0, 0, 0, 0, 0, 48865), -- Bone Pile (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 113995 - CLICK ME!)
(@CGUID+5, 58822, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 221.2291717529296875, 34.33159637451171875, 119.311553955078125, 4.723729133605957031, 86400, 0, 0, 23624, 0, 0, 0, 0, 0, 48865), -- Risen Guard (Area: Scholomance - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+6, 54020, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 261.461822509765625, 98.751739501953125, 115.3461990356445312, 4.764750480651855468, 86400, 0, 0, 112919, 0, 0, 0, 0, 0, 48865), -- General Purpose Bunny JMF (Look 2 - Flying, Huge AOI) (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: )
(@CGUID+7, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 229.8055572509765625, 127.3663177490234375, 113.2412796020507812, 0, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+8, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 228.6475677490234375, 127.9652786254882812, 113.2412567138671875, 3.490658521652221679, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+9, 58757, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 240.46875, 39.6875, 119.313262939453125, 0.896803498268127441, 86400, 0, 0, 11415, 2680, 0, 0, 0, 0, 48865), -- Scholomance Acolyte (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+10, 58875, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 261.229156494140625, 116.1319427490234375, 118.5723724365234375, 4.729842185974121093, 86400, 0, 0, 106890, 114200, 0, 0, 0, 0, 48865), -- Darkmaster Gandling (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 113865 - Improved Bone Shield)
(@CGUID+11, 59200, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 261.3507080078125, 98.892364501953125, 113.5723724365234375, 1.576605677604675292, 86400, 0, 0, 122160, 1142, 0, 0, 0, 0, 48865), -- Lilian Voss (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 42459 - Dual Wield)
(@CGUID+12, 64563, 1007, 6066, 6066, '2', 1436, 0, 0, 0, 203.548614501953125, 103.2256927490234375, 132.035888671875, 1.968955516815185546, 86400, 0, 0, 2854, 0, 0, 0, 0, 0, 48865), -- Talking Skull (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 126155 - Talking Skull: Skull State Visual) (possible waypoints or random movement)
(@CGUID+13, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 234.7899322509765625, 138.876739501953125, 113.2545166015625, 0, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+14, 59503, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 304.8038330078125, 21.88541603088378906, 113.4923248291015625, 0, 86400, 2, 0, 1427, 0, 1, 0, 0, 0, 48865), -- Brittle Skeleton (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 19818 - Double Attack)
(@CGUID+15, 59503, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 297.619781494140625, 28.26909828186035156, 113.49371337890625, 0, 86400, 2, 0, 1427, 0, 1, 0, 0, 0, 48865), -- Brittle Skeleton (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 19818 - Double Attack)
(@CGUID+16, 45979, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 276.671875, 99.84722137451171875, 113.8086624145507812, 0, 86400, 0, 0, 112919, 0, 0, 0, 0, 0, 48865), -- General Purpose Bunny JMF (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 114076 - Bone Cosmetic)
(@CGUID+17, 59193, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 282.588531494140625, 80.57465362548828125, 113.57421875, 3.141592741012573242, 86400, 0, 0, 11812, 5485, 0, 0, 0, 0, 48865), -- Boneweaver (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 113647 - Boneweaving)
(@CGUID+18, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 230.3645782470703125, 126.9322891235351562, 113.2412567138671875, 0, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+19, 45979, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 276.75, 118.1996536254882812, 113.8142623901367187, 0, 86400, 0, 0, 112919, 0, 0, 0, 0, 0, 48865), -- General Purpose Bunny JMF (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 114076 - Bone Cosmetic)
(@CGUID+20, 59193, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 240.609375, 118.0868072509765625, 113.57403564453125, 6.230825424194335937, 86400, 0, 0, 11812, 5485, 0, 0, 0, 0, 48865), -- Boneweaver (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 113647 - Boneweaving)
(@CGUID+21, 58823, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 235.40972900390625, 35.03819656372070312, 119.3151931762695312, 5.055787563323974609, 86400, 0, 0, 6849, 2680, 0, 0, 0, 0, 48865), -- Scholomance Neophyte (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 111705 - Shadowy)
(@CGUID+22, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 209.8350677490234375, 131.892364501953125, 113.389892578125, 1.570796370506286621, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+23, 59304, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 247.8506927490234375, 97.43228912353515625, 113.4253768920898437, 4.97418832778930664, 86400, 0, 0, 2854, 0, 0, 0, 0, 0, 48865), -- Bone Pile (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 113995 - CLICK ME!)
(@CGUID+24, 54020, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 261.461822509765625, 98.751739501953125, 116.3733596801757812, 4.764746665954589843, 86400, 0, 0, 112919, 0, 0, 0, 0, 0, 48865), -- General Purpose Bunny JMF (Look 2 - Flying, Huge AOI) (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: )
(@CGUID+25, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 266.024322509765625, 162.390625, 113.3819427490234375, 0, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+26, 59184, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 285.8350830078125, 53.26041793823242187, 113.49224853515625, 4.694935798645019531, 86400, 0, 0, 76350, 3426, 0, 0, 0, 0, 48865), -- Jandice Barov (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+27, 59193, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 282.30902099609375, 117.6423568725585937, 113.5740127563476562, 3.159045934677124023, 86400, 0, 0, 11812, 5485, 0, 0, 0, 0, 48865), -- Boneweaver (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 113647 - Boneweaving)
(@CGUID+28, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 240.5833282470703125, 49.55729293823242187, 119.309967041015625, 0, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+29, 59503, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 311.970489501953125, 2.19444441795349121, 113.49212646484375, 0, 86400, 2, 0, 1427, 0, 1, 0, 0, 0, 48865), -- Brittle Skeleton (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 19818 - Double Attack)
(@CGUID+30, 59193, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 282.5, 99.60764312744140625, 113.57415771484375, 3.211405754089355468, 86400, 0, 0, 11812, 5485, 0, 0, 0, 0, 48865), -- Boneweaver (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 113647 - Boneweaving)
(@CGUID+31, 59613, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 102.8055572509765625, 81.20139312744140625, 101.0136489868164062, 0.03893435001373291, 86400, 0, 0, 48725, 3291, 0, 0, 0, 0, 48865), -- Professor Slate (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 124143 - Backpack State, 42459 - Dual Wield)
(@CGUID+32, 59503, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 301.796875, 16.98263931274414062, 113.49310302734375, 0, 86400, 2, 0, 1427, 0, 1, 0, 0, 0, 48865), -- Brittle Skeleton (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 19818 - Double Attack)
(@CGUID+33, 59394, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 168.3402862548828125, 98.93402862548828125, 108.3292694091796875, 0, 86400, 0, 0, 112919, 0, 0, 0, 0, 0, 48865), -- General Purpose Bunny JMF (Ground) (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 115272 - Coffer of Forgotten Souls)
(@CGUID+34, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 196.3645782470703125, 141.1475677490234375, 113.39605712890625, 4.886921882629394531, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+35, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 193.5729217529296875, 175.828125, 113.3971786499023437, 0.523598790168762207, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+36, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 257.526031494140625, 162.578125, 113.36358642578125, 3.490658521652221679, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+37, 58823, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 167.048614501953125, 34.1649322509765625, 119.30914306640625, 4.286931037902832031, 86400, 0, 0, 6849, 2680, 0, 0, 0, 0, 48865), -- Scholomance Neophyte (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 111705 - Shadowy)
(@CGUID+38, 59929, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 200.5833282470703125, 48.69791793823242187, 132.4090118408203125, 4.720607280731201171, 86400, 0, 0, 2854, 0, 0, 0, 0, 0, 48865), -- Ice Steps (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+39, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 276.80902099609375, 146.0677032470703125, 113.3891830444335937, 0, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+40, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 152.984375, 119.126739501953125, 108.1363677978515625, 0, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+41, 45979, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 261.489593505859375, 99.1631927490234375, 113.5723724365234375, 0, 86400, 0, 0, 112919, 0, 0, 0, 0, 0, 48865), -- General Purpose Bunny JMF (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: )
(@CGUID+42, 59193, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 240.4184112548828125, 99.82465362548828125, 113.57415771484375, 6.213372230529785156, 86400, 0, 0, 11812, 5485, 0, 0, 0, 0, 48865), -- Boneweaver (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 113647 - Boneweaving)
(@CGUID+43, 59359, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 233.6961822509765625, 152.23785400390625, 113.24664306640625, 0.094388820230960845, 86400, 0, 0, 295300, 0, 0, 0, 0, 0, 48865), -- Flesh Horror (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 114176 - Clotting)
(@CGUID+44, 59368, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 213.623260498046875, 170.3541717529296875, 113.2412567138671875, 0.907571196556091308, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Krastinovian Carver (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 114141 - Boiling Bloodthirst, 128122 - Surgical Alterations)
(@CGUID+45, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 232.3663177490234375, 151.361114501953125, 113.2423934936523437, 0, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+46, 45979, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 277.1875, 80.73958587646484375, 113.8179092407226562, 0, 86400, 0, 0, 112919, 0, 0, 0, 0, 0, 48865), -- General Purpose Bunny JMF (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 114076 - Bone Cosmetic)
(@CGUID+47, 59304, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 275.539947509765625, 120.6736068725585937, 113.3808670043945312, 1.640609502792358398, 86400, 0, 0, 2854, 0, 0, 0, 0, 0, 48865), -- Bone Pile (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 113995 - CLICK ME!)
(@CGUID+48, 59614, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 111.1822891235351562, 101.9548568725585937, 102.5650787353515625, 1.583931565284729003, 86400, 0, 0, 11416, 1067, 0, 0, 0, 0, 48865), -- Bored Student (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+49, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 169.9444427490234375, 138.90972900390625, 113.13397216796875, 0, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+50, 54020, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 261.461822509765625, 98.751739501953125, 117.282135009765625, 4.764750480651855468, 86400, 0, 0, 112919, 0, 0, 0, 0, 0, 48865), -- General Purpose Bunny JMF (Look 2 - Flying, Huge AOI) (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: )
(@CGUID+51, 59614, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 119.1545181274414062, 91.84201812744140625, 103.8948287963867187, 3.100518226623535156, 86400, 0, 0, 11416, 1067, 0, 0, 0, 0, 48865), -- Bored Student (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+52, 59304, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 275.322906494140625, 98.5086822509765625, 113.43902587890625, 2.862339973449707031, 86400, 0, 0, 2854, 0, 0, 0, 0, 0, 48865), -- Bone Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 113995 - CLICK ME!)
(@CGUID+53, 58757, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 200.4444427490234375, 30.04340362548828125, 118.924224853515625, 4.746013641357421875, 86400, 0, 0, 11415, 2680, 0, 0, 0, 0, 48865), -- Scholomance Acolyte (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+54, 59614, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 109.65625, 102.0538177490234375, 102.5651473999023437, 1.600717425346374511, 86400, 0, 0, 11416, 1067, 0, 0, 0, 0, 48865), -- Bored Student (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+55, 54020, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 261.461822509765625, 98.751739501953125, 118.8529891967773437, 4.764750480651855468, 86400, 0, 0, 112919, 0, 0, 0, 0, 0, 48865), -- General Purpose Bunny JMF (Look 2 - Flying, Huge AOI) (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: )
(@CGUID+56, 59614, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 116.4201431274414062, 87.46875, 103.8952865600585937, 1.683665394783020019, 86400, 0, 0, 11416, 1067, 0, 0, 0, 0, 48865), -- Bored Student (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+57, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 273.517364501953125, 141.0520782470703125, 113.3851242065429687, 0, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject2 (possible waypoints or random movement)
(@CGUID+58, 59614, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 151.69097900390625, 110.3680572509765625, 108.1381683349609375, 5.89443206787109375, 86400, 0, 0, 11416, 1067, 0, 0, 0, 0, 48865), -- Bored Student (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+59, 59614, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 116.0989608764648437, 94.29514312744140625, 103.8945693969726562, 4.760039806365966796, 86400, 0, 0, 11416, 1067, 0, 0, 0, 0, 48865), -- Bored Student (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+60, 59614, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 143.37847900390625, 97.45833587646484375, 108.1410064697265625, 3.561250925064086914, 86400, 0, 0, 11416, 1067, 0, 0, 0, 0, 48865), -- Bored Student (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+61, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 177.21875, 66.70139312744140625, 108.316162109375, 0, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject2 (possible waypoints or random movement)
(@CGUID+62, 59614, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 110.5451431274414062, 109.541656494140625, 102.5650787353515625, 4.659205436706542968, 86400, 0, 0, 11416, 1067, 0, 0, 0, 0, 48865), -- Bored Student (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+63, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 271.352447509765625, 140.798614501953125, 113.3824462890625, 4.886921882629394531, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+64, 59614, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 126.8975677490234375, 76.298614501953125, 105.3696365356445312, 3.1417694091796875, 86400, 0, 0, 11416, 1067, 0, 0, 0, 0, 48865), -- Bored Student (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+65, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 229.4322967529296875, 135.9340362548828125, 113.2412567138671875, 4.363323211669921875, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+66, 59614, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 127.0798568725585937, 72.96701812744140625, 105.3694992065429687, 3.189453840255737304, 86400, 0, 0, 11416, 1067, 0, 0, 0, 0, 48865), -- Bored Student (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+67, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 203.6805572509765625, 161.373260498046875, 113.396728515625, 4.363323211669921875, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+68, 59614, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 117.5555572509765625, 94.31076812744140625, 103.8945541381835937, 4.686754226684570312, 86400, 0, 0, 11416, 1067, 0, 0, 0, 0, 48865), -- Bored Student (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+69, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 230.25347900390625, 172.3333282470703125, 113.2563934326171875, 0, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject2 (possible waypoints or random movement)
(@CGUID+70, 59614, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 119.2100677490234375, 89.6006927490234375, 103.8950653076171875, 3.091729640960693359, 86400, 0, 0, 11416, 1067, 0, 0, 0, 0, 48865), -- Bored Student (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+71, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 209.876739501953125, 129.9965362548828125, 113.389556884765625, 0, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject2 (possible waypoints or random movement)
(@CGUID+72, 59614, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 148.6770782470703125, 119.8611068725585937, 108.1360855102539062, 0.673298239707946777, 86400, 0, 0, 11416, 1067, 0, 0, 0, 0, 48865), -- Bored Student (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+73, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 278.189239501953125, 156.013885498046875, 113.3908767700195312, 0, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject2 (possible waypoints or random movement)
(@CGUID+74, 59614, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 153.826385498046875, 104.8177108764648437, 108.1395950317382812, 0.013621536083519458, 86400, 0, 0, 11416, 1067, 0, 0, 0, 0, 48865), -- Bored Student (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+75, 59368, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 171.6510467529296875, 132.720489501953125, 113.1806259155273437, 2.617993831634521484, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Krastinovian Carver (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 114141 - Boiling Bloodthirst) (possible waypoints or random movement)
(@CGUID+76, 45979, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 246.420135498046875, 118.1822891235351562, 113.8154525756835937, 0, 86400, 0, 0, 112919, 0, 0, 0, 0, 0, 48865), -- General Purpose Bunny JMF (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 114076 - Bone Cosmetic)
(@CGUID+77, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 172.576385498046875, 127.626739501953125, 113.2190093994140625, 3.141592741012573242, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+78, 59304, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 247.19097900390625, 120.8350677490234375, 113.3263931274414062, 0.157079637050628662, 86400, 0, 0, 2854, 0, 0, 0, 0, 0, 48865), -- Bone Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 113995 - CLICK ME!)
(@CGUID+79, 59614, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 112.2534713745117187, 104.3350677490234375, 102.5650634765625, 3.073004484176635742, 86400, 0, 0, 11416, 1067, 0, 0, 0, 0, 48865), -- Bored Student (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+80, 54020, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 261.461822509765625, 98.751739501953125, 118.18145751953125, 4.764746665954589843, 86400, 0, 0, 112919, 0, 0, 0, 0, 0, 48865), -- General Purpose Bunny JMF (Look 2 - Flying, Huge AOI) (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: )
(@CGUID+81, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 256.336822509765625, 162.439239501953125, 113.3538055419921875, 0, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+82, 59614, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 112.28125, 106.6302108764648437, 102.5650634765625, 3.124699592590332031, 86400, 0, 0, 11416, 1067, 0, 0, 0, 0, 48865), -- Bored Student (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+83, 59614, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 126.9756927490234375, 74.4774322509765625, 105.3695526123046875, 3.161961555480957031, 86400, 0, 0, 11416, 1067, 0, 0, 0, 0, 48865), -- Bored Student (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+84, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 187.796875, 40.1493072509765625, 119.30914306640625, 0, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject2 (possible waypoints or random movement)
(@CGUID+85, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 276.96875, 148.4739532470703125, 113.3859329223632812, 0.523598790168762207, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+86, 59614, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 141.376739501953125, 108.1822891235351562, 108.1382293701171875, 2.674033164978027343, 86400, 0, 0, 11416, 1067, 0, 0, 0, 0, 48865), -- Bored Student (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+87, 59614, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 124.385406494140625, 70.90451812744140625, 105.3692092895507812, 1.801934361457824707, 86400, 0, 0, 11416, 1067, 0, 0, 0, 0, 48865), -- Bored Student (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+88, 59614, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 152.0104217529296875, 96.47916412353515625, 108.14129638671875, 5.947880268096923828, 86400, 0, 0, 11416, 1067, 0, 0, 0, 0, 48865), -- Bored Student (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+89, 59614, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 142.515625, 99.298614501953125, 108.140533447265625, 3.530075311660766601, 86400, 0, 0, 11416, 1067, 0, 0, 0, 0, 48865), -- Bored Student (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+90, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 172.404510498046875, 130.282989501953125, 113.199005126953125, 0, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject2 (possible waypoints or random movement)
(@CGUID+91, 59614, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 146.4288177490234375, 94.9913177490234375, 108.14166259765625, 5.209464550018310546, 86400, 0, 0, 11416, 1067, 0, 0, 0, 0, 48865), -- Bored Student (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+92, 45979, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 246.5121612548828125, 99.42708587646484375, 113.8058395385742187, 0, 86400, 0, 0, 112919, 0, 0, 0, 0, 0, 48865), -- General Purpose Bunny JMF (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 114076 - Bone Cosmetic)
(@CGUID+93, 59368, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 238.5989532470703125, 161.6197967529296875, 113.24761962890625, 2.321287870407104492, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Krastinovian Carver (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 114141 - Boiling Bloodthirst)
(@CGUID+94, 59614, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 124.5451431274414062, 78.09201812744140625, 105.3696441650390625, 4.696930885314941406, 86400, 0, 0, 11416, 1067, 0, 0, 0, 0, 48865), -- Bored Student (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+95, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 230.986114501953125, 151.732635498046875, 113.2514190673828125, 2.094395160675048828, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+96, 45979, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 246.609375, 80.52603912353515625, 113.8112258911132812, 0, 86400, 0, 0, 112919, 0, 0, 0, 0, 0, 48865), -- General Purpose Bunny JMF (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 114076 - Bone Cosmetic)
(@CGUID+97, 59503, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 309.42535400390625, -21.1388893127441406, 113.49212646484375, 0, 86400, 2, 0, 1427, 0, 1, 0, 0, 0, 48865), -- Brittle Skeleton (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 19818 - Double Attack)
(@CGUID+98, 59503, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 269.001739501953125, -23.026041030883789, 113.4921188354492187, 0, 86400, 2, 0, 1427, 0, 1, 0, 0, 0, 48865), -- Brittle Skeleton (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 19818 - Double Attack)
(@CGUID+99, 30298, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 30.25, 57.84201431274414062, 92.71240234375, 0, 86400, 0, 0, 112919, 0, 0, 0, 0, 0, 48865), -- Invisible Stalker (Float, Uninteractible, LargeAOI) (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 114904 - Cosmetic Flames)
(@CGUID+100, 59481, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 280.345489501953125, -2.20659732818603515, 113.49212646484375, 0, 86400, 0, 0, 1016271, 22085, 0, 0, 0, 0, 48865), -- World Trigger (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 114400 - Black Candle)
(@CGUID+101, 58917, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 156.951385498046875, 37.02951431274414062, 122.3416824340820312, 0, 86400, 0, 0, 2854, 0, 0, 0, 0, 0, 48865), -- Book Spawn Target (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+102, 59503, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 307.289947509765625, 29.72916603088378906, 113.49212646484375, 0, 86400, 2, 0, 1427, 0, 1, 0, 0, 0, 48865), -- Brittle Skeleton (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 19818 - Double Attack)
(@CGUID+103, 58633, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 200.3663177490234375, 6.079861164093017578, 119.309112548828125, 1.535889744758605957, 86400, 0, 0, 48860, 2861, 0, 0, 0, 0, 48865), -- Instructor Chillheart (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 29266 - Permanent Feign Death)
(@CGUID+104, 59503, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 311.526031494140625, 33.93229293823242187, 113.49212646484375, 0, 86400, 2, 0, 1427, 0, 1, 0, 0, 0, 48865), -- Brittle Skeleton (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 19818 - Double Attack)
(@CGUID+105, 59503, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 269.001739501953125, -21.1458339691162109, 113.4921646118164062, 0, 86400, 2, 0, 1427, 0, 1, 0, 0, 0, 48865), -- Brittle Skeleton (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 19818 - Double Attack)
(@CGUID+106, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 278.0625, 158.5538177490234375, 113.3907241821289062, 0, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject2 (possible waypoints or random movement)
(@CGUID+107, 58662, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 200.579864501953125, 21.21527862548828125, 118.5661087036132812, 4.677482128143310546, 86400, 0, 0, 228300, 2680, 0, 0, 0, 0, 48865), -- Instructor Chillheart's Phylactery Vehicle (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: )
(@CGUID+108, 59503, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 311.467010498046875, 18.44270896911621093, 113.49212646484375, 0, 86400, 2, 0, 1427, 0, 1, 0, 0, 0, 48865), -- Brittle Skeleton (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 19818 - Double Attack)
(@CGUID+109, 59503, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 263.89410400390625, -15.4982643127441406, 113.49212646484375, 0, 86400, 2, 0, 1427, 0, 1, 0, 0, 0, 48865), -- Brittle Skeleton (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 19818 - Double Attack)
(@CGUID+110, 59503, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 302.89410400390625, -6.87152767181396484, 113.49212646484375, 0, 86400, 2, 0, 1427, 0, 1, 0, 0, 0, 48865), -- Brittle Skeleton (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 19818 - Double Attack)
(@CGUID+111, 59304, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 277.38714599609375, 78.24478912353515625, 113.49798583984375, 4.572762489318847656, 86400, 0, 0, 2854, 0, 0, 0, 0, 0, 48865), -- Bone Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 113995 - CLICK ME!)
(@CGUID+112, 59481, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 282.5225830078125, 29.69791603088378906, 113.49212646484375, 0.03526344895362854, 86400, 0, 0, 1016271, 22085, 0, 0, 0, 0, 48865), -- World Trigger (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 114400 - Black Candle)
(@CGUID+113, 58822, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 195.33160400390625, 66.7586822509765625, 132.035888671875, 1.570796370506286621, 86400, 0, 0, 23624, 0, 0, 0, 0, 0, 48865), -- Risen Guard (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+114, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 229.6336822509765625, 151.8559112548828125, 113.2602691650390625, 1.570796370506286621, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+115, 58822, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 205.46875, 66.63021087646484375, 132.035888671875, 1.570796370506286621, 86400, 0, 0, 23624, 0, 0, 0, 0, 0, 48865), -- Risen Guard (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+116, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 204.4270782470703125, 159.9496612548828125, 113.3966751098632812, 0, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+117, 59614, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 127.1996536254882812, 106.4444427490234375, 105.36871337890625, 2.933904409408569335, 86400, 0, 0, 11416, 1067, 0, 0, 0, 0, 48865), -- Bored Student (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+118, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 196.9809112548828125, 143.4496612548828125, 113.396148681640625, 5.060003280639648437, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject2 (possible waypoints or random movement)
(@CGUID+119, 59614, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 124.126739501953125, 109.447906494140625, 105.3682327270507812, 4.800126552581787109, 86400, 0, 0, 11416, 1067, 0, 0, 0, 0, 48865), -- Bored Student (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+120, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 279.904510498046875, 146.920135498046875, 113.39300537109375, 1.896207690238952636, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject2 (possible waypoints or random movement)
(@CGUID+121, 59368, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 213.31597900390625, 131.234375, 113.24761962890625, 5.497786998748779296, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Krastinovian Carver (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 114141 - Boiling Bloodthirst)
(@CGUID+122, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 175.2465362548828125, 170.9739532470703125, 113.2116622924804687, 0.200715452432632446, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject2 (possible waypoints or random movement)
(@CGUID+123, 59368, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 203.607635498046875, 157.842010498046875, 113.3966293334960937, 2.022486448287963867, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Krastinovian Carver (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 114141 - Boiling Bloodthirst)
(@CGUID+124, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 178.2309112548828125, 172.6788177490234375, 113.190399169921875, 3.141592741012573242, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+125, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 237.9583282470703125, 164.1927032470703125, 113.2469024658203125, 0, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+126, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 233.39410400390625, 138.829864501953125, 113.2422027587890625, 0, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+127, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 197.4027862548828125, 140.96875, 113.39605712890625, 0.451889723539352416, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject2 (possible waypoints or random movement)
(@CGUID+128, 59614, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 127.1406326293945312, 104.5711822509765625, 105.3687973022460937, 2.966682672500610351, 86400, 0, 0, 11416, 1067, 0, 0, 0, 0, 48865), -- Bored Student (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+129, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 192.0225677490234375, 39.04166793823242187, 119.30914306640625, 0.941756784915924072, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject2 (possible waypoints or random movement)
(@CGUID+130, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 230.4756927490234375, 153.09722900390625, 113.2547683715820312, 0, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+131, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 214.69097900390625, 124.583343505859375, 113.2415695190429687, 0.523598790168762207, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+132, 59614, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 123.6927108764648437, 102.5798568725585937, 105.368804931640625, 1.248563408851623535, 86400, 0, 0, 11416, 1067, 0, 0, 0, 0, 48865), -- Bored Student (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+133, 59614, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 126.3593826293945312, 102.751739501953125, 105.3687896728515625, 2.053753614425659179, 86400, 0, 0, 11416, 1067, 0, 0, 0, 0, 48865), -- Bored Student (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+134, 59368, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 224.013885498046875, 175.157989501953125, 113.2412567138671875, 1.815142393112182617, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Krastinovian Carver (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 114141 - Boiling Bloodthirst)
(@CGUID+135, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 203.3975677490234375, 160.0243072509765625, 113.3967056274414062, 0, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject2 (possible waypoints or random movement)
(@CGUID+136, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 154.439239501953125, 90.55728912353515625, 108.142822265625, 0, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject2 (possible waypoints or random movement)
(@CGUID+137, 59503, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 259.49652099609375, 4.197916507720947265, 113.49212646484375, 5.542412757873535156, 86400, 2, 0, 1427, 0, 1, 0, 0, 0, 48865), -- Brittle Skeleton (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 19818 - Double Attack)
(@CGUID+138, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 172.1475677490234375, 169.8072967529296875, 113.1662139892578125, 1.570796370506286621, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+139, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 214.7916717529296875, 166.22222900390625, 113.2412567138671875, 1.570796370506286621, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+140, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 202.904510498046875, 160.1145782470703125, 113.3966827392578125, 1.570796370506286621, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+141, 59368, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 171.2708282470703125, 164.861114501953125, 113.12457275390625, 3.246312379837036132, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Krastinovian Carver (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 114141 - Boiling Bloodthirst)
(@CGUID+142, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 116.9722213745117187, 102.3177108764648437, 103.9012069702148437, 0, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject2 (possible waypoints or random movement)
(@CGUID+143, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 196.5850677490234375, 175.6631927490234375, 113.397216796875, 0, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject2 (possible waypoints or random movement)
(@CGUID+144, 59503, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 259.52777099609375, -14.0746526718139648, 113.49212646484375, 0, 86400, 2, 0, 1427, 0, 1, 0, 0, 0, 48865), -- Brittle Skeleton (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 19818 - Double Attack)
(@CGUID+145, 59503, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 263.4600830078125, 5.15625, 113.49212646484375, 0, 86400, 2, 0, 1427, 0, 1, 0, 0, 0, 48865), -- Brittle Skeleton (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 19818 - Double Attack) (possible waypoints or random movement)
(@CGUID+146, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 172.720489501953125, 126.2065963745117187, 113.2297286987304687, 0.523598790168762207, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+147, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 236.0364532470703125, 164.138885498046875, 113.2449188232421875, 3.141592741012573242, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+148, 59368, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 215.701385498046875, 128.7621612548828125, 113.2412567138671875, 2.356194496154785156, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Krastinovian Carver (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 114141 - Boiling Bloodthirst)
(@CGUID+149, 59503, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 263.079864501953125, 12.55034732818603515, 113.49212646484375, 2.892240524291992187, 86400, 2, 0, 1427, 0, 1, 0, 0, 0, 48865), -- Brittle Skeleton (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 19818 - Double Attack)
(@CGUID+150, 59368, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 259.98785400390625, 162.763885498046875, 113.3633956909179687, 1.710422635078430175, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Krastinovian Carver (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 114141 - Boiling Bloodthirst)
(@CGUID+151, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 272.010406494140625, 162.3715362548828125, 113.3832321166992187, 0, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject2 (possible waypoints or random movement)
(@CGUID+152, 59503, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 300.5850830078125, 35.02083206176757812, 113.4959030151367187, 3.379057645797729492, 86400, 2, 0, 1427, 0, 1, 0, 0, 0, 48865), -- Brittle Skeleton (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 19818 - Double Attack)
(@CGUID+153, 59503, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 261.9444580078125, -7.5, 113.49212646484375, 1.129234552383422851, 86400, 2, 0, 1427, 0, 1, 0, 0, 0, 48865), -- Brittle Skeleton (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 19818 - Double Attack)
(@CGUID+154, 59503, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 295.133697509765625, 20.42534828186035156, 113.4925689697265625, 0, 86400, 2, 0, 1427, 0, 1, 0, 0, 0, 48865), -- Brittle Skeleton (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 19818 - Double Attack)
(@CGUID+155, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 230.234375, 150.623260498046875, 113.25634765625, 0.483147472143173217, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+156, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 235.921875, 140.404510498046875, 113.24505615234375, 2.094395160675048828, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+157, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 213.638885498046875, 125.5694427490234375, 113.323028564453125, 0, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject2 (possible waypoints or random movement)
(@CGUID+158, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 176.5, 174.2239532470703125, 113.2433929443359375, 0, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject2 (possible waypoints or random movement)
(@CGUID+159, 59503, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 292.8350830078125, -20.5607643127441406, 113.49212646484375, 0, 86400, 2, 0, 1427, 0, 1, 0, 0, 0, 48865), -- Brittle Skeleton (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 19818 - Double Attack)
(@CGUID+160, 59503, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 273.088531494140625, -19.6024303436279296, 113.49212646484375, 4.49958658218383789, 86400, 2, 0, 1427, 0, 1, 0, 0, 0, 48865), -- Brittle Skeleton (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 19818 - Double Attack)
(@CGUID+161, 59503, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 311.911468505859375, -13.2951393127441406, 113.49212646484375, 0, 86400, 2, 0, 1427, 0, 1, 0, 0, 0, 48865), -- Brittle Skeleton (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 19818 - Double Attack)
(@CGUID+162, 59503, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 304.814239501953125, 2.3125, 113.49212646484375, 0, 86400, 2, 0, 1427, 0, 1, 0, 0, 0, 48865), -- Brittle Skeleton (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 19818 - Double Attack)
(@CGUID+163, 59503, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 300.015625, -20.9513893127441406, 113.49212646484375, 0, 86400, 2, 0, 1427, 0, 1, 0, 0, 0, 48865), -- Brittle Skeleton (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 19818 - Double Attack)
(@CGUID+164, 59503, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 281.7725830078125, -21.1649303436279296, 113.49212646484375, 5.634348869323730468, 86400, 2, 0, 1427, 0, 1, 0, 0, 0, 48865), -- Brittle Skeleton (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 19818 - Double Attack)
(@CGUID+165, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 211.814239501953125, 147.0989532470703125, 113.299224853515625, 4.886921882629394531, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+166, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 147.2760467529296875, 60.64236068725585937, 106.4951248168945312, 0, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject2 (possible waypoints or random movement)
(@CGUID+167, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 171.2864532470703125, 169.3489532470703125, 113.1658096313476562, 0, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject2 (possible waypoints or random movement)
(@CGUID+168, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 280.289947509765625, 155.0243072509765625, 113.393463134765625, 0, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject2 (possible waypoints or random movement)
(@CGUID+169, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 244.204864501953125, 140.8020782470703125, 113.2583694458007812, 3.141592741012573242, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+170, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 242.953125, 141.357635498046875, 113.255615234375, 0, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+171, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 173.6961822509765625, 127.032989501953125, 113.2234954833984375, 0, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject2 (possible waypoints or random movement)
(@CGUID+172, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 170.532989501953125, 127.0625, 113.223297119140625, 0, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject2 (possible waypoints or random movement)
(@CGUID+173, 59368, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 246.170135498046875, 140.23785400390625, 113.2626495361328125, 3.071779489517211914, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Krastinovian Carver (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 114141 - Boiling Bloodthirst)
(@CGUID+174, 59359, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 184.50347900390625, 173.8836822509765625, 113.313232421875, 5.761324882507324218, 86400, 0, 0, 295300, 0, 0, 0, 0, 0, 48865), -- Flesh Horror (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 114176 - Clotting)
(@CGUID+175, 59368, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 240.640625, 140.763885498046875, 113.2506027221679687, 6.195918560028076171, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Krastinovian Carver (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 114141 - Boiling Bloodthirst)
(@CGUID+176, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 188.40625, 169.529510498046875, 113.2903671264648437, 4.363323211669921875, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+177, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 242.7916717529296875, 139.6458282470703125, 113.2553176879882812, 0, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+178, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 286.486114501953125, 90.49478912353515625, 113.5760345458984375, 0, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject2 (possible waypoints or random movement)
(@CGUID+179, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 193.5850677490234375, 141.1875, 113.3960342407226562, 0, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject2 (possible waypoints or random movement)
(@CGUID+180, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 209.763885498046875, 77.1336822509765625, 132.035919189453125, 0, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject2 (possible waypoints or random movement)
(@CGUID+181, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 176.5208282470703125, 172, 113.1846694946289062, 3.490658521652221679, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+182, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 177.642364501953125, 166.8489532470703125, 113.1658096313476562, 2.094395160675048828, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+183, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 208.6631927490234375, 130.90972900390625, 113.3957977294921875, 4.363323211669921875, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+184, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 214.4427032470703125, 164.1319427490234375, 113.2412567138671875, 0, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+185, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 279.8350830078125, 147.951385498046875, 113.392913818359375, 4.886921882629394531, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+186, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 198.048614501953125, 141.8802032470703125, 113.396087646484375, 4.363323211669921875, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+187, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 209.626739501953125, 129.7777862548828125, 113.3911972045898437, 3.141592741012573242, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+188, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 169.234375, 129.361114501953125, 113.205963134765625, 4.886921882629394531, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+189, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 279.227447509765625, 153.6944427490234375, 113.3921585083007812, 2.094395160675048828, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+190, 59368, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 229.2274322509765625, 131.6458282470703125, 113.2412567138671875, 0.750491559505462646, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Krastinovian Carver (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 114141 - Boiling Bloodthirst) (possible waypoints or random movement)
(@CGUID+191, 59368, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 229.204864501953125, 134.201385498046875, 113.2412567138671875, 0.087266460061073303, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Krastinovian Carver (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 114141 - Boiling Bloodthirst)
(@CGUID+192, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 169.94097900390625, 127.814239501953125, 113.2176132202148437, 0.523598790168762207, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+193, 59359, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 203.5, 135.3541717529296875, 113.395904541015625, 1.388808727264404296, 86400, 0, 0, 295300, 0, 0, 0, 0, 0, 48865), -- Flesh Horror (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 114176 - Clotting)
(@CGUID+194, 59368, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 215.98785400390625, 172.5694427490234375, 113.2412567138671875, 4.24114990234375, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Krastinovian Carver (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 114141 - Boiling Bloodthirst)
(@CGUID+195, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 268.373260498046875, 163.40625, 113.3804931640625, 1.570796370506286621, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+196, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 212.421875, 147.8559112548828125, 113.2783660888671875, 0, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+197, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 236.986114501953125, 163.1302032470703125, 113.2459182739257812, 4.886921882629394531, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+198, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 201.607635498046875, 159.3229217529296875, 113.39666748046875, 3.490658521652221679, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+199, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 279.61285400390625, 145.314239501953125, 113.3927993774414062, 3.490658521652221679, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+200, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 218.8958282470703125, 174.59722900390625, 113.2412567138671875, 0.523598790168762207, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+201, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 232.234375, 152.55035400390625, 113.2432632446289062, 0.483147472143173217, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+202, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 189.3385467529296875, 168.3645782470703125, 113.3252182006835937, 0.523598790168762207, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+203, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 229.7743072509765625, 128.8993072509765625, 113.2412567138671875, 3.141592741012573242, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+204, 59368, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 171.12847900390625, 135.09375, 113.1627273559570312, 3.228859186172485351, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Krastinovian Carver (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 114141 - Boiling Bloodthirst)
(@CGUID+205, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 215.2708282470703125, 164.8663177490234375, 113.2412567138671875, 0, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+206, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 230.1493072509765625, 166.282989501953125, 113.2412567138671875, 1.570796370506286621, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+207, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 196.0364532470703125, 142.56597900390625, 113.396087646484375, 2.094395160675048828, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+208, 59368, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 171.6059112548828125, 137.9270782470703125, 113.141387939453125, 3.909537553787231445, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Krastinovian Carver (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 114141 - Boiling Bloodthirst)
(@CGUID+209, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 280.947906494140625, 154.8559112548828125, 113.3933029174804687, 4.363323211669921875, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+210, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 177.0260467529296875, 176.8020782470703125, 113.2250823974609375, 1.570796370506286621, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+211, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 276.739593505859375, 157.107635498046875, 113.38873291015625, 3.490658521652221679, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+212, 59375, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 189.642364501953125, 169.7777862548828125, 113.3365478515625, 3.490658521652221679, 86400, 0, 0, 27, 0, 0, 0, 0, 0, 48865), -- Cosmetic Meat Pile (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+213, 58823, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 212.640625, 21.40451431274414062, 118.9893722534179687, 3.117332220077514648, 86400, 0, 0, 6849, 2680, 0, 0, 0, 0, 48865), -- Scholomance Neophyte (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 111705 - Shadowy)
(@CGUID+214, 58917, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 240.6875, 28.82118034362792968, 122.6001434326171875, 0, 86400, 0, 0, 2854, 0, 0, 0, 0, 0, 48865), -- Book Spawn Target (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+215, 58823, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 159.9340362548828125, 26.89583396911621093, 119.30914306640625, 3.189329147338867187, 86400, 0, 0, 6849, 2680, 0, 0, 0, 0, 48865), -- Scholomance Neophyte (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 111705 - Shadowy)
(@CGUID+216, 58917, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 157.6024322509765625, 27.31597328186035156, 122.4777984619140625, 0, 86400, 0, 0, 2854, 0, 0, 0, 0, 0, 48865), -- Book Spawn Target (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+217, 58823, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 232.65972900390625, 26.50868034362792968, 119.3255996704101562, 5.022238731384277343, 86400, 0, 0, 6849, 2680, 0, 0, 0, 0, 48865), -- Scholomance Neophyte (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 111705 - Shadowy)
(@CGUID+218, 58757, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 241.90625, 30.81076431274414062, 119.309112548828125, 4.607669353485107421, 86400, 0, 0, 11415, 2680, 0, 0, 0, 0, 48865), -- Scholomance Acolyte (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+219, 59080, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 20.15104103088378906, 57.74479293823242187, 73.8830108642578125, 0, 86400, 0, 0, 106890, 3426, 0, 0, 0, 0, 48865), -- Darkmaster Gandling (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 114910 - Cosmetic Flames)
(@CGUID+220, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 110.1857681274414062, 93.9600677490234375, 102.5726776123046875, 0, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+221, 58823, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 160.189239501953125, 34.91840362548828125, 119.30914306640625, 3.515956401824951171, 86400, 0, 0, 6849, 2680, 0, 0, 0, 0, 48865), -- Scholomance Neophyte (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 111705 - Shadowy)
(@CGUID+222, 58757, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 165.84375, 25.44965362548828125, 119.3091278076171875, 4.956735134124755859, 86400, 0, 0, 11415, 2680, 0, 0, 0, 0, 48865), -- Scholomance Acolyte (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+223, 58823, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 187.7447967529296875, 21.08680534362792968, 118.9363250732421875, 0.000290817202767357, 86400, 0, 0, 6849, 2680, 0, 0, 0, 0, 48865), -- Scholomance Neophyte (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 111705 - Shadowy)
(@CGUID+224, 58757, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 160.8402862548828125, 22.19965362548828125, 119.3091278076171875, 4.607669353485107421, 86400, 0, 0, 11415, 2680, 0, 0, 0, 0, 48865), -- Scholomance Acolyte (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+225, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 241.20501708984375, 26.51387596130371093, 119.2302474975585937, 0.400247186422348022, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+226, 58757, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 237.4756927490234375, 23.61284828186035156, 119.322906494140625, 4.607669353485107421, 86400, 0, 0, 11415, 2680, 0, 0, 0, 0, 48865), -- Scholomance Acolyte (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+227, 58822, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 177.0751800537109375, 17.15880203247070312, 119.2210693359375, 4.727941513061523437, 86400, 0, 0, 23624, 0, 0, 0, 0, 0, 48865), -- Risen Guard (Area: Scholomance - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+228, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 236.589111328125, 23.56732559204101562, 119.235565185546875, 5.454020977020263671, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+229, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 160.682952880859375, 22.638916015625, 119.2210693359375, 1.239473819732666015, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+230, 58823, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 232.7552032470703125, 12.80034732818603515, 119.3304290771484375, 5.044001579284667968, 86400, 0, 0, 6849, 2680, 0, 0, 0, 0, 48865), -- Scholomance Neophyte (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 111705 - Shadowy)
(@CGUID+231, 58917, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 233.4270782470703125, 10.80381965637207031, 122.6840438842773437, 0, 86400, 0, 0, 2854, 0, 0, 0, 0, 0, 48865), -- Book Spawn Target (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+232, 58757, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 171.767364501953125, 6.22743082046508789, 119.3091278076171875, 4.380776405334472656, 86400, 0, 0, 11415, 2680, 0, 0, 0, 0, 48865), -- Scholomance Acolyte (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+233, 58757, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 231.0381927490234375, 5.626736164093017578, 119.30914306640625, 5.462878227233886718, 86400, 0, 0, 11415, 2680, 0, 0, 0, 0, 48865), -- Scholomance Acolyte (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+234, 58917, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 163.5868072509765625, 10.61458301544189453, 121.496612548828125, 0, 86400, 0, 0, 2854, 0, 0, 0, 0, 0, 48865), -- Book Spawn Target (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+235, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 239.3229217529296875, 12.82118034362792968, 119.3211441040039062, 0, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+236, 59467, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 276.670135498046875, 29.90277862548828125, 113.49212646484375, 6.126462459564208984, 86400, 0, 0, 14270, 9916, 0, 0, 0, 0, 48865), -- Candlestick Mage (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 114384 - Flameborn)
(@CGUID+237, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 171.0239410400390625, 2.80881810188293457, 119.2210769653320312, 6.219365596771240234, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+238, 62731, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 196.9305572509765625, -3.65104174613952636, 119.30914306640625, 1.572726607322692871, 86400, 0, 0, 2854, 0, 0, 0, 0, 0, 48865), -- Ice Wall (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+239, 58757, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 170.329864501953125, -2.12152791023254394, 119.30914306640625, 4.516818046569824218, 86400, 0, 0, 11415, 2680, 0, 0, 0, 0, 48865), -- Scholomance Acolyte (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+240, 58823, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 225.39410400390625, -1.48611116409301757, 119.30914306640625, 5.078614234924316406, 86400, 0, 0, 6849, 2680, 0, 0, 0, 0, 48865), -- Scholomance Neophyte (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 111705 - Shadowy)
(@CGUID+241, 58757, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 194.7916717529296875, -9.140625, 119.30914306640625, 4.221302032470703125, 86400, 0, 0, 11415, 2680, 0, 0, 0, 0, 48865), -- Scholomance Acolyte (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+242, 58917, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 170.173614501953125, -4.44791650772094726, 121.8838577270507812, 0, 86400, 0, 0, 2854, 0, 0, 0, 0, 0, 48865), -- Book Spawn Target (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+243, 58757, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 228.15972900390625, -2.72743058204650878, 119.3091278076171875, 3.333578824996948242, 86400, 0, 0, 11415, 2680, 0, 0, 0, 0, 48865), -- Scholomance Acolyte (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+244, 58823, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 170.4027862548828125, 1.71875, 119.30914306640625, 1.545722603797912597, 86400, 0, 0, 6849, 2680, 0, 0, 0, 0, 48865), -- Scholomance Neophyte (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 111705 - Shadowy)
(@CGUID+245, 58917, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 226.47222900390625, -4.51909732818603515, 120.2573165893554687, 0, 86400, 0, 0, 2854, 0, 0, 0, 0, 0, 48865), -- Book Spawn Target (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+246, 58917, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 194.6875, -12.2569446563720703, 119.96026611328125, 0, 86400, 0, 0, 2854, 0, 0, 0, 0, 0, 48865), -- Book Spawn Target (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+247, 58823, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 200.251739501953125, -10.046875, 119.30914306640625, 5.006302356719970703, 86400, 0, 0, 6849, 2680, 0, 0, 0, 0, 48865), -- Scholomance Neophyte (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 111705 - Shadowy)
(@CGUID+248, 58757, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 192.3020782470703125, -9.99826431274414062, 119.2210693359375, 5.693621158599853515, 86400, 0, 0, 11415, 2680, 0, 0, 0, 0, 48865), -- Scholomance Acolyte (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+249, 58917, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 177.65972900390625, -7.36631965637207031, 121.644012451171875, 0, 86400, 0, 0, 2854, 0, 0, 0, 0, 0, 48865), -- Book Spawn Target (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+250, 58823, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 192.6510467529296875, -17.1215286254882812, 119.3091278076171875, 0.01745329238474369, 86400, 0, 0, 6849, 2680, 0, 0, 0, 0, 48865), -- Scholomance Neophyte (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 111705 - Shadowy)
(@CGUID+251, 58917, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 207.4791717529296875, -13.9375, 122.54412841796875, 0, 86400, 0, 0, 2854, 0, 0, 0, 0, 0, 48865), -- Book Spawn Target (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+252, 58917, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 223.298614501953125, -10.8454866409301757, 123.2821044921875, 0, 86400, 0, 0, 2854, 0, 0, 0, 0, 0, 48865), -- Book Spawn Target (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+253, 58823, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 205.796875, -17.0451393127441406, 119.3091278076171875, 2.94960641860961914, 86400, 0, 0, 6849, 2680, 0, 0, 0, 0, 48865), -- Scholomance Neophyte (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 111705 - Shadowy, 114252 - Cosmetic Channel)
(@CGUID+254, 59501, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 258.782012939453125, 9.765321731567382812, 113.4085693359375, 3.076406717300415039, 86400, 3, 0, 8562, 0, 1, 0, 0, 0, 48865), -- Reanimated Corpse (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+255, 59501, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 261.070556640625, -1.0014040470123291, 113.4085845947265625, 3.744545936584472656, 86400, 3, 0, 8562, 0, 1, 0, 0, 0, 48865), -- Reanimated Corpse (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+256, 59467, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 282.864593505859375, 24.72048568725585937, 113.49212646484375, 1.582539796829223632, 86400, 0, 0, 14270, 9916, 0, 0, 0, 0, 48865), -- Candlestick Mage (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 114384 - Flameborn)
(@CGUID+257, 59467, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 289.23089599609375, 29.86458396911621093, 113.49212646484375, 3.047092914581298828, 86400, 0, 0, 14270, 9916, 0, 0, 0, 0, 48865), -- Candlestick Mage (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 114384 - Flameborn)
(@CGUID+258, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 209.224395751953125, -35.9932365417480468, 119.2366943359375, 2.952846765518188476, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+259, 59467, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 273.2100830078125, -1.9565972089767456, 113.4921188354492187, 6.091198921203613281, 86400, 0, 0, 14270, 9916, 0, 0, 0, 0, 48865), -- Candlestick Mage (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 114384 - Flameborn)
(@CGUID+260, 58822, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 242.47161865234375, -43.6986198425292968, 115.2435455322265625, 3.13346719741821289, 86400, 0, 0, 23624, 0, 0, 0, 0, 0, 48865), -- Risen Guard (Area: Scholomance - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+261, 59501, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 298.06756591796875, 27.77035331726074218, 113.4085693359375, 2.407123088836669921, 86400, 3, 0, 8562, 0, 1, 0, 0, 0, 48865), -- Reanimated Corpse (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+262, 59467, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 288.0382080078125, -2.13541674613952636, 113.4921188354492187, 3.228859186172485351, 86400, 0, 0, 14270, 9916, 0, 0, 0, 0, 48865), -- Candlestick Mage (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 114384 - Flameborn)
(@CGUID+263, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 93.429168701171875, 63.92800140380859375, 100.9257354736328125, 5.59657144546508789, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+264, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 96.7430572509765625, 61.24652862548828125, 101.0322952270507812, 0, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+265, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 94.908721923828125, 89.08998870849609375, 100.92425537109375, 0.470585405826568603, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+266, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 80.34053802490234375, 62.6661529541015625, 87.03343963623046875, 5.684138298034667968, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+267, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 80.4439697265625, 57.96351242065429687, 87.03472900390625, 1.688532471656799316, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+268, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 77.76313018798828125, 60.12255096435546875, 87.0343017578125, 2.144720792770385742, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+269, 59501, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 285.9276123046875, -19.3966503143310546, 113.4085693359375, 1.756009221076965332, 86400, 3, 0, 8562, 0, 1, 0, 0, 0, 48865), -- Reanimated Corpse (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+270, 59501, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 307.263092041015625, 27.63460350036621093, 113.4085769653320312, 3.249085187911987304, 86400, 3, 0, 8562, 0, 1, 0, 0, 0, 48865), -- Reanimated Corpse (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+271, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 266.64031982421875, -47.7100753784179687, 113.4241943359375, 3.56571054458618164, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+272, 59501, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 312.490142822265625, -2.45551538467407226, 113.4085693359375, 6.101215362548828125, 86400, 3, 0, 8562, 0, 1, 0, 0, 0, 48865), -- Reanimated Corpse (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+273, 59316, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 246.40972900390625, 99.87326812744140625, 113.81207275390625, 6.283113002777099609, 86400, 0, 0, 3054, 0, 0, 0, 0, 0, 48865), -- Soulflame (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 114007 - Soulflame)
(@CGUID+274, 59316, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 246.2604217529296875, 118.001739501953125, 113.8090896606445312, 0.02070714347064495, 86400, 0, 0, 3054, 0, 0, 0, 0, 0, 48865), -- Soulflame (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 114007 - Soulflame)
(@CGUID+275, 59316, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 276.87847900390625, 80.640625, 113.8130645751953125, 3.162159681320190429, 86400, 0, 0, 3054, 0, 0, 0, 0, 0, 48865), -- Soulflame (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 114007 - Soulflame)
(@CGUID+276, 59394, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 217.265625, 71.04514312744140625, 108.3161392211914062, 2.408554315567016601, 86400, 0, 0, 112919, 0, 0, 0, 0, 0, 48865), -- General Purpose Bunny JMF (Ground) (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+277, 59394, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 217.251739501953125, 71.09375, 108.3161392211914062, 2.408554315567016601, 86400, 0, 0, 112919, 0, 0, 0, 0, 0, 48865), -- General Purpose Bunny JMF (Ground) (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+278, 59394, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 217.2100677490234375, 71.0399322509765625, 108.3161392211914062, 2.408554315567016601, 86400, 0, 0, 112919, 0, 0, 0, 0, 0, 48865), -- General Purpose Bunny JMF (Ground) (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@CGUID+279, 58875, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 217.4305572509765625, 70.94097137451171875, 108.8501129150390625, 2.408554315567016601, 86400, 0, 0, 106890, 114200, 0, 0, 0, 0, 48865), -- Darkmaster Gandling (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 113865 - Improved Bone Shield)
(@CGUID+280, 58722, 1007, 6066, 6066, '1,2', 0, 0, 0, 1, 200.4618072509765625, 86.05208587646484375, 107.8449630737304687, 5.532693862915039062, 86400, 0, 0, 91620, 1142, 0, 0, 0, 0, 48865), -- Lilian Voss (Area: Scholomance - Difficulty: Heroic) CreateObject2 (Auras: 42459 - Dual Wield)
(@CGUID+281, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 71.57086944580078125, 107.3613739013671875, 101.0181732177734375, 3.135441541671752929, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+282, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 70.07335662841796875, 105.3871383666992187, 101.017547607421875, 3.01718449592590332, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+283, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 37.13898086547851562, 111.3053970336914062, 83.510467529296875, 2.360843420028686523, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+284, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 40.125, 94.2743072509765625, 73.7655792236328125, 2.91304636001586914, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+285, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 34.953125, 106.4357681274414062, 83.5960693359375, 5.270894527435302734, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+286, 59099, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 39.33159637451171875, 101.3402786254882812, 73.7655792236328125, 2.129301786422729492, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Fresh Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 113280 - Explosive Pain)
(@CGUID+287, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 42.63194656372070312, 99.58159637451171875, 73.7655792236328125, 2.199048519134521484, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+288, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 42.87152862548828125, 105.4357681274414062, 73.7655792236328125, 2.483566522598266601, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+289, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 28.52835273742675781, 104.9772262573242187, 73.67420196533203125, 0.978476703166961669, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+290, 59099, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 30.79861068725585937, 109.939239501953125, 73.7655792236328125, 3.944444179534912109, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Fresh Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 113280 - Explosive Pain)
(@CGUID+291, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 37.127716064453125, 114.061492919921875, 83.504730224609375, 3.987596988677978515, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+292, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 29.234375, 113.2065963745117187, 83.5040283203125, 0.960924923419952392, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+293, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 32.36893844604492187, 110.9882888793945312, 83.5096282958984375, 3.793090105056762695, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+294, 59099, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 38.52083206176757812, 115.2048568725585937, 73.7655792236328125, 2.478367567062377929, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Fresh Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 113280 - Explosive Pain)
(@CGUID+295, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 32.22320938110351562, 118.3480148315429687, 83.50232696533203125, 2.847486019134521484, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+296, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 33.75902938842773437, 111.5876007080078125, 73.67420196533203125, 4.040074825286865234, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+297, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 33.8543243408203125, 104.1939163208007812, 73.67420196533203125, 0.088336311280727386, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+298, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 30.71854972839355468, 107.0322647094726562, 83.5173492431640625, 0.264507830142974853, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+299, 59167, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 30.578125, 132.50347900390625, 73.73358154296875, 4.642575740814208984, 86400, 0, 0, 2854, 0, 0, 0, 0, 0, 48865), -- Teleport Location (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+300, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 15.62326431274414062, 81.173614501953125, 87.37506103515625, 0, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+301, 59099, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 38.53125, 137.4756927490234375, 83.5960693359375, 4.293509960174560546, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Fresh Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 113280 - Explosive Pain)
(@CGUID+302, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 25.72631072998046875, 93.239410400390625, 73.6742095947265625, 4.632342338562011718, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+303, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 26.8622589111328125, 112.13653564453125, 73.67420196533203125, 4.864401817321777343, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+304, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 20.09887886047363281, 98.88504791259765625, 73.67420196533203125, 1.919088006019592285, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+305, 59099, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 36.10763931274414062, 140.2465362548828125, 83.5960693359375, 2.129301786422729492, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Fresh Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 113280 - Explosive Pain)
(@CGUID+306, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 27.78583526611328125, 118.0101699829101562, 83.50232696533203125, 4.479335308074951171, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+307, 59099, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 32.77951431274414062, 137.4288177490234375, 83.74422454833984375, 6.108652114868164062, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Fresh Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 113280 - Explosive Pain)
(@CGUID+308, 59099, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 22.44097328186035156, 115.782989501953125, 73.7655792236328125, 0.698131680488586425, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Fresh Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 113280 - Explosive Pain)
(@CGUID+309, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 24.36329269409179687, 108.05029296875, 83.5132293701171875, 4.512393951416015625, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+310, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 24.16666603088378906, 113.75, 83.50130462646484375, 1.59007120132446289, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+311, 59099, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 20.31770896911621093, 103.1197891235351562, 73.7655792236328125, 0, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Fresh Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 113280 - Explosive Pain)
(@CGUID+312, 59099, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 36.5399322509765625, 18.42881965637207031, 87.337005615234375, 5.026548385620117187, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Fresh Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 113280 - Explosive Pain)
(@CGUID+313, 50485, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 34.00681686401367187, 31.61159896850585937, 87.25376129150390625, 0.391883164644241333, 86400, 4, 0, 1, 0, 1, 0, 0, 0, 48865), -- Carrion Rat (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+314, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 37.42361068725585937, 19.25, 71.04083251953125, 2.646118640899658203, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+315, 59167, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 31.28819465637207031, 145.5381927490234375, 83.5960540771484375, 4.677482128143310546, 86400, 0, 0, 2854, 0, 0, 0, 0, 0, 48865), -- Teleport Location (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+316, 59099, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 28.86979103088378906, 139.5208282470703125, 83.74422454833984375, 2.670353651046752929, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Fresh Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 113280 - Explosive Pain)
(@CGUID+317, 59099, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 24.34895896911621093, 137.8090362548828125, 83.5960693359375, 3.944444179534912109, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Fresh Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 113280 - Explosive Pain)
(@CGUID+318, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 31.27777862548828125, 23.06770896911621093, 71.03826904296875, 2.286381244659423828, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+319, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 16.60338020324707031, 105.42059326171875, 73.6741943359375, 4.836679935455322265, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+320, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 36.47200775146484375, 5.530022621154785156, 70.95545196533203125, 0.809485852718353271, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+321, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 30.34375, 8.892361640930175781, 83.59604644775390625, 2.20340585708618164, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+322, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, -10.0572919845581054, 60.63888931274414062, 73.765594482421875, 2.426007747650146484, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+323, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, -9.26736164093017578, 55.6180572509765625, 73.765594482421875, 2.286381244659423828, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+324, 59099, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 23.65625, 18.69444465637207031, 87.32025146484375, 3.96189737319946289, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Fresh Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 113280 - Explosive Pain)
(@CGUID+325, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 31.17107772827148437, 13.00783538818359375, 70.9554595947265625, 1.657149910926818847, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+326, 59099, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 32.6875, 2.770833253860473632, 83.20859527587890625, 3.944444179534912109, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Fresh Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 113280 - Explosive Pain)
(@CGUID+327, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 26.87673568725585937, 13.04513931274414062, 83.59604644775390625, 5.867633342742919921, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+328, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 23.45217132568359375, 19.99636459350585937, 70.9554595947265625, 2.438748598098754882, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+329, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, -12.5434026718139648, 64.96527862548828125, 73.765594482421875, 5.593328475952148437, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+330, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 33.53125, 11.90277767181396484, 83.59604644775390625, 2.964835882186889648, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+331, 59099, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 41.52951431274414062, 0.272569447755813598, 72.544464111328125, 6.003932476043701171, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Fresh Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 113280 - Explosive Pain)
(@CGUID+332, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 42.07669448852539062, -6.9146580696105957, 83.50232696533203125, 4.795567512512207031, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+333, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, -9.8498849868774414, 52.38616943359375, 73.6672210693359375, 1.220529079437255859, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+334, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 28.87181282043457031, 2.517256498336791992, 70.95545196533203125, 2.987960338592529296, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+335, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 39.55295562744140625, -10.8628730773925781, 83.50232696533203125, 4.778246402740478515, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+336, 59099, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 27.84722328186035156, 6.291666507720947265, 72.54373931884765625, 3.926990747451782226, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Fresh Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 113280 - Explosive Pain)
(@CGUID+337, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 40.81716156005859375, -2.47846603393554687, 70.95545196533203125, 2.562774181365966796, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+338, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 42.99426651000976562, -6.82727909088134765, 70.95545196533203125, 3.660385370254516601, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+339, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, -18.1739349365234375, 66.5701141357421875, 73.6672210693359375, 0.952071905136108398, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+340, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 25.68797111511230468, 1.158914566040039062, 70.95545196533203125, 6.220479965209960937, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+341, 59099, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, -18.244791030883789, 57.8055572509765625, 83.5960693359375, 3.141592741012573242, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Fresh Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 113280 - Explosive Pain)
(@CGUID+342, 59099, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 35.67708206176757812, 0.145833328366279602, 72.54538726806640625, 0.92502450942993164, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Fresh Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 113280 - Explosive Pain)
(@CGUID+343, 59099, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 36.2899322509765625, -5.3125, 72.8482666015625, 3.944444179534912109, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Fresh Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 113280 - Explosive Pain)
(@CGUID+344, 59167, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 30.69791603088378906, -12.6875, 71.04083251953125, 1.518436431884765625, 86400, 0, 0, 2854, 0, 0, 0, 0, 0, 48865), -- Teleport Location (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+345, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 19.93554496765136718, -0.87885409593582153, 83.5023193359375, 1.772781252861022949, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+346, 59099, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, -25.4861106872558593, 61.35416793823242187, 83.2086181640625, 5.619960308074951171, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Fresh Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 113280 - Explosive Pain)
(@CGUID+347, 59099, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 27.64930534362792968, -5.27430582046508789, 72.5444488525390625, 0.92502450942993164, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Fresh Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 113280 - Explosive Pain)
(@CGUID+348, 59099, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 27.42534828186035156, -9.10763931274414062, 83.20859527587890625, 0.698131680488586425, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Fresh Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 113280 - Explosive Pain)
(@CGUID+349, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 20.03105926513671875, -5.73670816421508789, 83.5023193359375, 4.4085693359375, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+350, 59099, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, -21.8645839691162109, 54.49132156372070312, 83.2086181640625, 6.230825424194335937, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Fresh Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 113280 - Explosive Pain)
(@CGUID+351, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 23.888763427734375, -16.392282485961914, 83.3321533203125, 1.036352992057800292, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+352, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, -20.9954757690429687, 50.8327789306640625, 73.6672210693359375, 1.614932417869567871, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+353, 59167, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, -19.2204856872558593, 57.734375, 73.7655792236328125, 6.230825424194335937, 86400, 0, 0, 2854, 0, 0, 0, 0, 0, 48865), -- Teleport Location (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+354, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 18.51152801513671875, -1.93739962577819824, 70.95545196533203125, 2.89226388931274414, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+355, 59099, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 35.41319656372070312, -19.8784732818603515, 83.20859527587890625, 0, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Fresh Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 113280 - Explosive Pain)
(@CGUID+356, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, -24.363870620727539, 69.955047607421875, 73.6672210693359375, 1.656700849533081054, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+357, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 42.87508010864257812, -18.483123779296875, 83.50232696533203125, 5.223764419555664062, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+358, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 25.82379531860351562, -13.2464265823364257, 83.1116943359375, 4.319416522979736328, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+359, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, -15.6114444732666015, 49.47000503540039062, 73.6672210693359375, 0.681821882724761962, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+360, 59167, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, 31.11979103088378906, -28.1736106872558593, 83.59603118896484375, 1.518436431884765625, 86400, 0, 0, 2854, 0, 0, 0, 0, 0, 48865), -- Teleport Location (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+361, 59099, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, -32.2552070617675781, 60.30382156372070312, 83.2086181640625, 0.907571196556091308, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Fresh Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 113280 - Explosive Pain)
(@CGUID+362, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, -26.4847450256347656, 59.86078262329101562, 73.6672210693359375, 3.552021026611328125, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+363, 59099, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, -28.854166030883789, 55.96701431274414062, 83.2086181640625, 5.375614166259765625, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Fresh Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 113280 - Explosive Pain)
(@CGUID+364, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, -25.8319301605224609, 55.6356201171875, 73.6672210693359375, 5.009667873382568359, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+365, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, -38.7152786254882812, 49.13715362548828125, 83.5960693359375, 1.241492509841918945, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+366, 59099, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, -35.6215286254882812, 71.907989501953125, 73.7655792236328125, 0.209439516067504882, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Fresh Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 113280 - Explosive Pain)
(@CGUID+367, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, -39.9392356872558593, 44.61458206176757812, 83.5960693359375, 2.211864709854125976, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+368, 59099, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, -34.4565963745117187, 47.61979293823242187, 73.7655792236328125, 5.777040004730224609, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Fresh Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 113280 - Explosive Pain)
(@CGUID+369, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, -34.8715286254882812, 44.69791793823242187, 83.5960693359375, 0.869266808032989501, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+370, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, -32.1875, 41.28645706176757812, 83.5960693359375, 3.493831157684326171, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+371, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, -43.1204643249511718, 70.15605926513671875, 83.5109710693359375, 5.719082355499267578, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+372, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, -41.7876472473144531, 42.1019287109375, 83.51096343994140625, 2.001116275787353515, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+373, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, -44.4373779296875, 66.823638916015625, 83.5109710693359375, 1.863911867141723632, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+374, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, -45.3511619567871093, 45.71484375, 83.51096343994140625, 2.349912405014038085, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+375, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, -48.09375, 73.05208587646484375, 83.5960693359375, 2.286381244659423828, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+376, 59099, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, -50.9809036254882812, 57.90625, 69.14117431640625, 2.129301786422729492, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Fresh Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 113280 - Explosive Pain)
(@CGUID+377, 59099, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, -48.203125, 47.58854293823242187, 69.14117431640625, 3.944444179534912109, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Fresh Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 113280 - Explosive Pain)
(@CGUID+378, 59100, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, -47.8814353942871093, 69.94232940673828125, 83.5109710693359375, 1.684842467308044433, 86400, 0, 0, 688, 0, 0, 0, 0, 0, 48865), -- Expired Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+379, 59167, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, -55.0503463745117187, 57.88194656372070312, 83.5960540771484375, 6.2657318115234375, 86400, 0, 0, 2854, 0, 0, 0, 0, 0, 48865), -- Teleport Location (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@CGUID+380, 59099, 1007, 6066, 6066, '1,2', 0, 0, 0, 0, -49.1232643127441406, 66.45659637451171875, 69.14117431640625, 0, 86400, 0, 0, 14270, 0, 0, 0, 0, 0, 48865), -- Fresh Test Subject (Area: Scholomance - Difficulty: Heroic) CreateObject1 (Auras: 113280 - Explosive Pain)
(@CGUID+381, 64562, 1007, 6066, 6066, '1', 1431, 0, 0, 0, 203.548614501953125, 103.2256927490234375, 132.035888671875, 1.968955516815185546, 7200, 0, 0, 2035, 0, 0, 0, 0, 0, 48865); -- Talking Skull (Area: Scholomance - Difficulty: 0) CreateObject1 (Auras: 126155 - Talking Skull: Skull State Visual)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+381;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+33, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '115272'), -- General Purpose Bunny JMF (Ground) - 115272 - Coffer of Forgotten Souls
(@CGUID+51, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- Bored Student
(@CGUID+59, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- Bored Student
(@CGUID+62, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- Bored Student
(@CGUID+83, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- Bored Student
(@CGUID+94, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- Bored Student
(@CGUID+132, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- Bored Student
(@CGUID+133, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- Bored Student
(@CGUID+134, 0, 0, 0, 0, 0, 1, 0, 483, 0, 0, 0, 0, '114141'), -- Krastinovian Carver - 114141 - Boiling Bloodthirst
(@CGUID+141, 0, 0, 0, 0, 0, 1, 0, 483, 0, 0, 0, 0, '114141'), -- Krastinovian Carver - 114141 - Boiling Bloodthirst
(@CGUID+150, 0, 0, 0, 0, 0, 1, 0, 483, 0, 0, 0, 0, '114141'), -- Krastinovian Carver - 114141 - Boiling Bloodthirst
(@CGUID+191, 0, 0, 0, 0, 0, 1, 0, 483, 0, 0, 0, 0, '114141'), -- Krastinovian Carver - 114141 - Boiling Bloodthirst
(@CGUID+204, 0, 0, 0, 0, 0, 1, 0, 483, 0, 0, 0, 0, '114141'), -- Krastinovian Carver - 114141 - Boiling Bloodthirst
(@CGUID+236, 0, 0, 0, 0, 0, 1, 0, 469, 0, 0, 0, 0, '114384'), -- Candlestick Mage - 114384 - Flameborn
(@CGUID+256, 0, 0, 0, 0, 0, 1, 0, 469, 0, 0, 0, 0, '114384'), -- Candlestick Mage - 114384 - Flameborn
(@CGUID+257, 0, 0, 0, 0, 0, 1, 0, 469, 0, 0, 0, 0, '114384'), -- Candlestick Mage - 114384 - Flameborn
(@CGUID+259, 0, 0, 0, 0, 0, 1, 0, 469, 0, 0, 0, 0, '114384'), -- Candlestick Mage - 114384 - Flameborn
(@CGUID+262, 0, 0, 0, 0, 0, 1, 0, 469, 0, 0, 0, 0, '114384'); -- Candlestick Mage - 114384 - Flameborn

-- GameObjects
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+52;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 211648, 1007, 6066, 6066, '1,2', 0, 0, 124.0763931274414062, 89.09027862548828125, 106.9110031127929687, 0, 0, 0, 0, 1, 86400, 255, 1, 48865), -- Alchemy Bottle Green (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+1, 211257, 1007, 6066, 6066, '1,2', 0, 0, 261.1800537109375, -28.02471923828125, 113.2893829345703125, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 86400, 255, 0, 48865), -- Iron Gate (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+2, 211256, 1007, 6066, 6066, '1,2', 0, 0, 261.268829345703125, 61.02359771728515625, 113.2893829345703125, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 86400, 255, 1, 48865), -- Iron Gate (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+3, 211648, 1007, 6066, 6066, '1,2', 0, 0, 125.4218826293945312, 107.157989501953125, 106.9110031127929687, 0, 0, 0, 0, 1, 86400, 255, 1, 48865), -- Alchemy Bottle Green (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+4, 211259, 1007, 6066, 6066, '1,2', 0, 0, 200.493560791015625, 57.14392852783203125, 132.1283721923828125, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 86400, 255, 1, 48865), -- Iron Gate (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+5, 211258, 1007, 6066, 6066, '1,2', 0, 0, 214.8282623291015625, -26.6221923828125, 119.2987823486328125, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 86400, 255, 1, 48865), -- ChillheartToJandice (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+6, 211261, 1007, 6066, 6066, '1,2', 0, 0, 200.015533447265625, 124.35247802734375, 113.2893829345703125, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 86400, 255, 1, 48865), -- Iron Gate (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+7, 211260, 1007, 6066, 6066, '1,2', 0, 0, 90.8001556396484375, 101.5641937255859375, 101.0595550537109375, 0, 0, 0, 0, 1, 86400, 255, 1, 48865), -- Iron Gate (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+8, 211262, 1007, 6066, 6066, '1,2', 0, 0, 261.288543701171875, 135.6597137451171875, 113.2893829345703125, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 86400, 255, 1, 48865), -- Iron Gate (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+9, 175747, 1007, 6066, 6066, '1,2', 0, 0, 218.2586822509765625, 63.296875, 109.6169662475585937, 2.56861424446105957, 0, 0, 0.959241867065429687, 0.28258630633354187, 86400, 255, 1, 48865), -- The Invasion of Draenor (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+10, 214279, 1007, 6066, 6066, '1,2', 0, 0, 240.763885498046875, 44.93229293823242187, 120.1470718383789062, 1.692013978958129882, 0, 0, 0.748639106750488281, 0.662977755069732666, 86400, 255, 1, 48865), -- In the Shadow of the Light (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+11, 214280, 1007, 6066, 6066, '1,2', 0, 0, 219.7395782470703125, 175.4305572509765625, 114.2577972412109375, 4.453361034393310546, 0, 0, -0.79250907897949218, 0.609860122203826904, 86400, 255, 1, 48865), -- Forbidden Rites and other Rituals Necromantic (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+12, 248887, 1007, 6066, 6066, '1,2', 0, 0, 141.204864501953125, 97.71527862548828125, 108.997711181640625, 3.674076557159423828, 0, 0, -0.96476650238037109, 0.263107597827911376, 86400, 255, 1, 48865), -- Pile of Ancient Arkhana (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+13, 210785, 1007, 6066, 6066, '1,2', 0, 0, 31.12314605712890625, 86.7699127197265625, 87.1883392333984375, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 86400, 255, 1, 48865), -- doodad_Vaultgate_top01 (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+14, 212899, 1007, 6066, 6066, '1,2', 0, 0, 186.7083282470703125, 125.4635391235351562, 143.246795654296875, 0.016010453924536705, 0, 0, 0.008005142211914062, 0.999967932701110839, 86400, 255, 1, 48865), -- Instance Portal (Party + Heroic + Challenge) (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+15, 210784, 1007, 6066, 6066, '1,2', 0, 0, 9.8710174560546875, 57.85538864135742187, 74.41617584228515625, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 86400, 255, 1, 48865), -- doodad_Vaultgate_bottom06 (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+16, 210787, 1007, 6066, 6066, '1,2', 0, 0, 2.1038055419921875, 57.80113601684570312, 87.1948699951171875, 3.141592741012573242, 0, 0, -1, 0, 86400, 255, 1, 48865), -- doodad_Vaultgate_top03 (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+17, 210786, 1007, 6066, 6066, '1,2', 0, 0, 30.73661041259765625, 29.4763946533203125, 87.19580841064453125, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 86400, 255, 1, 48865), -- doodad_Vaultgate_top02 (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+18, 210789, 1007, 6066, 6066, '1,2', 0, 0, 60.28564453125, 58.89294815063476562, 87.13812255859375, 0, 0, 0, 0, 1, 86400, 255, 0, 48865), -- Doodad_Portcullis_to_TeleportBossroom (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+19, 210788, 1007, 6066, 6066, '1,2', 0, 0, 30.8193206787109375, 34.21492767333984375, 74.4522552490234375, 3.141592741012573242, 0, 0, -1, 0, 86400, 255, 1, 48865), -- doodad_Vaultgate_bottom04 (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+20, 210791, 1007, 6066, 6066, '1,2', 0, 0, 241.80426025390625, 69.8066558837890625, 113.5301666259765625, 3.141592741012573242, 0, 0, -1, 0, 86400, 255, 1, 48865), -- Doodad_UndeadCampFire29 (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+21, 210793, 1007, 6066, 6066, '1,2', 0, 0, 280.30902099609375, 127.921875, 113.5301666259765625, 3.141592741012573242, 0, 0, -1, 0, 86400, 255, 1, 48865), -- Doodad_UndeadCampFire31 (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+22, 210794, 1007, 6066, 6066, '1,2', 0, 0, 241.80426025390625, 127.921875, 113.5301666259765625, 3.141592741012573242, 0, 0, -1, 0, 86400, 255, 1, 48865), -- Doodad_UndeadCampFire32 (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+23, 210771, 1007, 6066, 6066, '1,2', 0, 0, 173.889312744140625, 77.3735809326171875, 108.3201904296875, 3.141592741012573242, 0, 0, -1, 0, 86400, 255, 1, 48865), -- Reinforced Wooden Door (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+24, 211649, 1007, 6066, 6066, '1,2', 0, 0, 124.5538177490234375, 75.30902862548828125, 106.910797119140625, 0, 0, 0, 0, 1, 86400, 255, 1, 48865), -- Alchemy Bottle Blue (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+25, 211649, 1007, 6066, 6066, '1,2', 0, 0, 125.3611068725585937, 92.28472137451171875, 106.9110031127929687, 0, 0, 0, 0, 1, 86400, 255, 1, 48865), -- Alchemy Bottle Blue (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+26, 211277, 1007, 6066, 6066, '1,2', 0, 0, 168.329864501953125, 98.94965362548828125, 108.246063232421875, 0, 0, 0, 0, 1, 86400, 255, 1, 48865), -- Coffer of Forgotten Souls (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+27, 210781, 1007, 6066, 6066, '1,2', 0, 0, 171.933074951171875, 98.91452789306640625, 108.653045654296875, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 86400, 255, 1, 48865), -- Vault of Souls (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+28, 210783, 1007, 6066, 6066, '1,2', 0, 0, 30.81931304931640625, 78.80165863037109375, 74.4522552490234375, 3.141592741012573242, 0, 0, -1, 0, 86400, 255, 1, 48865), -- doodad_Vaultgate_bottom05 (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+29, 211649, 1007, 6066, 6066, '1,2', 0, 0, 124.1163177490234375, 106.34375, 106.9110031127929687, 0, 0, 0, 0, 1, 86400, 255, 1, 48865), -- Alchemy Bottle Blue (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@OGUID+30, 211649, 1007, 6066, 6066, '1,2', 0, 0, 117.6163177490234375, 105.03125, 105.1500015258789062, 0, 0, 0, 0, 1, 86400, 255, 1, 48865), -- Alchemy Bottle Blue (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@OGUID+31, 211649, 1007, 6066, 6066, '1,2', 0, 0, 117.302093505859375, 104.1736068725585937, 105.1500015258789062, 0, 0, 0, 0, 1, 86400, 255, 1, 48865), -- Alchemy Bottle Blue (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@OGUID+32, 211647, 1007, 6066, 6066, '1,2', 0, 0, 117.720489501953125, 90.7274322509765625, 105.1500015258789062, 0, 0, 0, 0, 1, 86400, 255, 1, 48865), -- Alchemy Bottle White (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@OGUID+33, 211648, 1007, 6066, 6066, '1,2', 0, 0, 109.5781326293945312, 106.9236068725585937, 103.8509979248046875, 0, 0, 0, 0, 1, 86400, 255, 1, 48865), -- Alchemy Bottle Green (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@OGUID+34, 214178, 1007, 6066, 6066, '1,2', 0, 0, 268.220489501953125, 158.2621612548828125, 113.2988128662109375, 0.731383562088012695, 0, 0, 0.357595443725585937, 0.933876574039459228, 86400, 255, 1, 48865), -- Grandmaster Architect Holmberg (Area: Scholomance - Difficulty: Heroic) CreateObject2
(@OGUID+35, 211649, 1007, 6066, 6066, '1,2', 0, 0, 116.5694427490234375, 74.6006927490234375, 105.1497573852539062, 0, 0, 0, 0, 1, 86400, 255, 1, 48865), -- Alchemy Bottle Blue (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+36, 211647, 1007, 6066, 6066, '1,2', 0, 0, 117.1944427490234375, 73.23090362548828125, 105.1500015258789062, 0, 0, 0, 0, 1, 86400, 255, 1, 48865), -- Alchemy Bottle White (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+37, 210792, 1007, 6066, 6066, '1,2', 0, 0, 280.30902099609375, 69.8066558837890625, 113.5301666259765625, 3.141592741012573242, 0, 0, -1, 0, 86400, 255, 1, 48865), -- Doodad_UndeadCampFire30 (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+38, 211648, 1007, 6066, 6066, '1,2', 0, 0, 117.3211822509765625, 75.0225677490234375, 105.1500015258789062, 0, 0, 0, 0, 1, 86400, 255, 1, 48865), -- Alchemy Bottle Green (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+39, 211648, 1007, 6066, 6066, '1,2', 0, 0, 109.5763931274414062, 90.078125, 103.8509979248046875, 0, 0, 0, 0, 1, 86400, 255, 1, 48865), -- Alchemy Bottle Green (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+40, 211648, 1007, 6066, 6066, '1,2', 0, 0, 110.53125, 91.17534637451171875, 103.8509979248046875, 0, 0, 0, 0, 1, 86400, 255, 1, 48865), -- Alchemy Bottle Green (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+41, 211649, 1007, 6066, 6066, '1,2', 0, 0, 110.6180572509765625, 73.66666412353515625, 103.8507308959960937, 0, 0, 0, 0, 1, 86400, 255, 1, 48865), -- Alchemy Bottle Blue (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+42, 211649, 1007, 6066, 6066, '1,2', 0, 0, 105.6440963745117187, 86.28125, 102.51300048828125, 0, 0, 0, 0, 1, 86400, 255, 1, 48865), -- Alchemy Bottle Blue (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+43, 211647, 1007, 6066, 6066, '1,2', 0, 0, 105.8802108764648437, 84.46875, 102.51300048828125, 0, 0, 0, 0, 1, 86400, 255, 1, 48865), -- Alchemy Bottle White (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+44, 211648, 1007, 6066, 6066, '1,2', 0, 0, 105.291656494140625, 77.45139312744140625, 102.51300048828125, 0, 0, 0, 0, 1, 86400, 255, 1, 48865), -- Alchemy Bottle Green (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+45, 211647, 1007, 6066, 6066, '1,2', 0, 0, 105.4635391235351562, 76.24826812744140625, 102.51300048828125, 0, 0, 0, 0, 1, 86400, 255, 1, 48865), -- Alchemy Bottle White (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+46, 211648, 1007, 6066, 6066, '1,2', 0, 0, 105.5052108764648437, 83.49478912353515625, 102.51300048828125, 0, 0, 0, 0, 1, 86400, 255, 1, 48865), -- Alchemy Bottle Green (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+47, 211669, 1007, 6066, 6066, '1,2', 0, 0, 104.5746536254882812, 78.74826812744140625, 102.5644989013671875, 0, 0, 0, 0, 1, 86400, 255, 1, 48865), -- Polyformic Acid Potion (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+48, 211648, 1007, 6066, 6066, '1,2', 0, 0, 104.595489501953125, 76.703125, 102.513397216796875, 0, 0, 0, 0, 1, 86400, 255, 1, 48865), -- Alchemy Bottle Green (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+49, 211648, 1007, 6066, 6066, '1,2', 0, 0, 104.53125, 85.8524322509765625, 102.51300048828125, 0, 0, 0, 0, 1, 86400, 255, 1, 48865), -- Alchemy Bottle Green (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+50, 214277, 1007, 6066, 6066, '1,2', 0, 0, 104.4826431274414062, 83.42708587646484375, 102.5918121337890625, 4.08061981201171875, 0, 0, -0.89178848266601562, 0.452452510595321655, 86400, 255, 1, 48865), -- The Dark Grimoire (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+51, 214278, 1007, 6066, 6066, '1,2', 0, 0, 316.385406494140625, -13.5434026718139648, 115.3127212524414062, 2.486630201339721679, 0, 0, 0.946855545043945312, 0.3216591477394104, 86400, 255, 1, 48865), -- Kel'Thuzad's Deep Knowledge (Area: Scholomance - Difficulty: Heroic) CreateObject1
(@OGUID+52, 211670, 1007, 6066, 6066, '1,2', 0, 0, 104.5749969482421875, 78.74829864501953125, 102.5640029907226562, 0, 0, 0, 0, 1, 86400, 255, 1, 48865); -- Polyformic Acid Potion Highlight (Area: Scholomance - Difficulty: Heroic) CreateObject2
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+52;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+1, 0, 0, 1, -0.00000004371138828, 0, 0), -- Iron Gate
(@OGUID+2, 0, 0, 1, -0.00000004371138828, 0, 0), -- Iron Gate
(@OGUID+4, 0, 0, 1, -0.00000004371138828, 0, 0), -- Iron Gate
(@OGUID+5, 0, 0, 1, -0.00000004371138828, 0, 0), -- ChillheartToJandice
(@OGUID+6, 0, 0, 1, -0.00000004371138828, 0, 0), -- Iron Gate
(@OGUID+7, 0, 0, 1, -0.00000004371138828, 0, 0), -- Iron Gate
(@OGUID+8, 0, 0, 1, -0.00000004371138828, 0, 0), -- Iron Gate
(@OGUID+13, 0, 0, 1, -0.00000004371138828, 0, 0), -- doodad_Vaultgate_top01
(@OGUID+15, 0, 0, 1, -0.00000004371138828, 0, 0), -- doodad_Vaultgate_bottom06
(@OGUID+16, 0, 0, 1, -0.00000004371138828, 0, 0), -- doodad_Vaultgate_top03
(@OGUID+17, 0, 0, 1, -0.00000004371138828, 0, 0), -- doodad_Vaultgate_top02
(@OGUID+18, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_Portcullis_to_TeleportBossroom
(@OGUID+19, 0, 0, 1, -0.00000004371138828, 0, 0), -- doodad_Vaultgate_bottom04
(@OGUID+20, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_UndeadCampFire29
(@OGUID+21, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_UndeadCampFire31
(@OGUID+22, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_UndeadCampFire32
(@OGUID+23, 0, 0, 1, -0.00000004371138828, 0, 0), -- Reinforced Wooden Door
(@OGUID+27, 0, 0, 1, -0.00000004371138828, 0, 0), -- Vault of Souls
(@OGUID+28, 0, 0, 1, -0.00000004371138828, 0, 0), -- doodad_Vaultgate_bottom05
(@OGUID+37, 0, 0, 1, -0.00000004371138828, 0, 0); -- Doodad_UndeadCampFire30

-- GameObject Template Addon
UPDATE `gameobject_template_addon` SET `flags`=16 WHERE `entry`=211277; -- Coffer of Forgotten Souls
UPDATE `gameobject_template_addon` SET `flags`=34 WHERE `entry` IN (211256, 211262); -- Iron Gate
UPDATE `gameobject_template_addon` SET `flags`=34 WHERE `entry`=210781; -- Vault of Souls
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=211261; -- Iron Gate
UPDATE `gameobject_template_addon` SET `flags`=34 WHERE `entry`=210771; -- Reinforced Wooden Door

-- Creature Template
UPDATE `creature_template` SET `unit_flags`=33024 WHERE `entry`=59099; -- Fresh Test Subject
UPDATE `creature_template` SET `unit_flags3`=16777217 WHERE `entry`=59316; -- Soulflame
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=59153; -- Rattlegore
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=524288 WHERE `entry` IN (59242, 59213); -- Woven Boneguard
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=524288 WHERE `entry`=58842; -- Skeleton
UPDATE `creature_template` SET `unit_flags3`=16777217 WHERE `entry`=62731; -- Ice Wall
UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=59200; -- Lilian Voss
UPDATE `creature_template` SET `speed_walk`=1.20000004768371582, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200, `unit_flags3`=524288 WHERE `entry`=59480; -- Brittle Skeleton
UPDATE `creature_template` SET `unit_flags`=0, `unit_flags3`=0 WHERE `entry` IN (59980, 59360); -- Meat Graft
UPDATE `creature_template` SET `unit_flags3`=16777217 WHERE `entry`=58917; -- Book Spawn Target
UPDATE `creature_template` SET `unit_flags3`=16777217 WHERE `entry`=59481; -- World Trigger
UPDATE `creature_template` SET `unit_flags3`=16777216 WHERE `entry`=30298; -- Invisible Stalker (Float, Uninteractible, LargeAOI)
UPDATE `creature_template` SET `BaseAttackTime`=1905 WHERE `entry`=59368; -- Krastinovian Carver
UPDATE `creature_template` SET `unit_flags3`=16777217 WHERE `entry`=59929; -- Ice Steps
UPDATE `creature_template` SET `speed_run`=1.428571462631225585 WHERE `entry`=59613; -- Professor Slate
UPDATE `creature_template` SET `gossip_menu_id`=14564, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=64563; -- Talking Skull
UPDATE `creature_template` SET `unit_flags`=33280 WHERE `entry`=59304; -- Bone Pile
UPDATE `creature_template` SET `unit_flags`=33587264 WHERE `entry`=58664; -- Instructor Chillheart's Phylactery
UPDATE `creature_template` SET `flags_extra` = 128 WHERE `entry` = 59394; -- General Purpose Bunny JMF (Ground)

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (59099,58722,59153,62731,59467,59080,59480,59980,59982,58662,58633,58664,59368,59359,59929,59613,59184,58823,59360,64563,59200,58875,59304,59503,64562);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(59099, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '113280'), -- 59099 (Fresh Test Subject) - Explosive Pain
(58722, 0, 0, 8, 3, 0, 1, 0, 0, 0, 0, 0, 3, '42459'), -- 58722 (Lilian Voss) - Dual Wield
(59153, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '113763'), -- 59153 (Rattlegore) - Rusting
(62731, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 62731 (Ice Wall) - Ice Wall
(59467, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '114384'), -- 59467 (Candlestick Mage) - Flameborn
(59080, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '114910'), -- 59080 (Darkmaster Gandling) - Cosmetic Flames
(59480, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '114447'), -- 59480 (Brittle Skeleton) - Flameborn
(59980, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '114178'), -- 59980 (Meat Graft) - Meat Graft
(59982, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '114178'), -- 59982 (Meat Graft) - Meat Graft
(58662, 0, 0, 0, 0, 0, 1, 0, 0, 1990, 0, 0, 3, ''), -- 58662 (Instructor Chillheart's Phylactery Vehicle)
(58633, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 58633 (Instructor Chillheart)
(58664, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 58664 (Instructor Chillheart's Phylactery)
(59368, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '114141 128122'), -- 59368 (Krastinovian Carver) - Boiling Bloodthirst, Surgical Alterations
(59359, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '114176'), -- 59359 (Flesh Horror) - Clotting
(59929, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 59929 (Ice Steps) - Ice Steps
(59613, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '124143 42459'), -- 59613 (Professor Slate) - Backpack State, Dual Wield
(59184, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 59184 (Jandice Barov)
(58823, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '111705'), -- 58823 (Scholomance Neophyte) - Shadowy
(59360, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '114178'), -- 59360 (Meat Graft) - Ride Vehicle, Meat Graft
(64563, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '126155'), -- 64563 (Talking Skull) - Talking Skull: Skull State Visual
(59200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '42459'), -- 59200 (Lilian Voss) - Dual Wield
(58875, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 3, '113865'), -- 58875 (Darkmaster Gandling) - Improved Bone Shield
(59304, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '113995'), -- 59304 (Bone Pile) - CLICK ME!
(59503, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '19818'), -- 59503 (Brittle Skeleton) - Double Attack
(64562, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '126155'); -- 64562 (Talking Skull) - Talking Skull: Skull State Visual

-- Creature Movement data
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (58664, 30298, 45979, 58875, 59200);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(58664, 0, 0, 1, 1, 0, 0, NULL),
(30298, 0, 0, 1, 0, 0, 0, NULL),
(45979, 0, 0, 1, 0, 0, 0, NULL),
(58875, 0, 0, 1, 0, 0, 0, NULL),
(59200, 0, 0, 1, 1, 0, 0, NULL);

-- Vehicle
DELETE FROM `vehicle_template_accessory` WHERE (`entry`=59359 AND `seat_id` IN (4,3,2,1,0)) OR (`entry`=58662 AND `seat_id`=0);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(59359, 59982, 4, 1, 'Flesh Horror - Meat Graft', 8, 0), -- Flesh Horror - Meat Graft
(59359, 59982, 3, 1, 'Flesh Horror - Meat Graft', 8, 0), -- Flesh Horror - Meat Graft
(59359, 59982, 2, 1, 'Flesh Horror - Meat Graft', 8, 0), -- Flesh Horror - Meat Graft
(59359, 59982, 1, 1, 'Flesh Horror - Meat Graft', 8, 0), -- Flesh Horror - Meat Graft
(59359, 59982, 0, 1, 'Flesh Horror - Meat Graft', 8, 0), -- Flesh Horror - Meat Graft
(58662, 58664, 0, 0, 'Instructor Chillheart\'s Phylactery Vehicle - Instructor Chillheart\'s Phylactery', 8, 0); -- Instructor Chillheart's Phylactery Vehicle - Instructor Chillheart's Phylactery

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (59304, 59359, 58662);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(59304, 113996, 0, 0),
(59359, 61791, 0, 0),
(58662, 58662, 0, 0);

-- Gossip
DELETE FROM `gossip_menu` WHERE (`MenuID`=14579 AND `TextID`=20616);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(14579, 20616, 48865); -- 64562 (Talking Skull)

-- Quest
DELETE FROM `quest_request_items` WHERE `ID`=31440;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(31440, 0, 15, 0, 0, 'The four tomes contain secrets that have damned this place and all associated with it to an eternity of suffering.$B$BThey must be destroyed!', 48865); -- The Four Tomes

-- Phasing
DELETE FROM `phase_area` WHERE `PhaseId` IN (1436, 1431);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(6066, 1436, 'Cosmetic - Scholomance 5.0 - Quest - Talking Skull - 90+ Heroic'),
(6066, 1431, 'Cosmetic - Scholomance 5.0 - Quest - Talking Skull - Low Level');

-- Condition
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 1436 AND `SourceEntry` = 6066) OR (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 1431 AND `SourceEntry` = 6066);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
-- Heroic
(26, 1436, 6066, 0, 0, 49, 0, 2, 0, 0, 0, 0, 0, '', 'Apply Phase 1436 If Difficulty is set to Heroic'),
(26, 1436, 6066, 0, 0, 47, 0, 31442, 64, 0, 1, 0, 0, '', 'Apply Phase 1436 If Quest 31440 IS NOT rewarded'),
(26, 1436, 6066, 0, 1, 49, 0, 2, 0, 0, 0, 0, 0, '', 'Apply Phase 1436 If Difficulty is set to Heroic'),
(26, 1436, 6066, 0, 1, 47, 0, 31448, 64, 0, 1, 0, 0, '', 'Apply Phase 1436 If Quest 31448 IS NOT rewarded'),
-- Normal
(26, 1431, 6066, 0, 0, 49, 0, 1, 0, 0, 0, 0, 0, '', 'Apply Phase 1436 If Difficulty is set to Normal'),
(26, 1431, 6066, 0, 0, 47, 0, 31440, 64, 0, 1, 0, 0, '', 'Apply Phase 1431 If Quest 31440 IS NOT rewarded'),
(26, 1431, 6066, 0, 1, 49, 0, 1, 0, 0, 0, 0, 0, '', 'Apply Phase 1436 If Difficulty is set to Normal'),
(26, 1431, 6066, 0, 1, 47, 0, 31447, 64, 0, 1, 0, 0, '', 'Apply Phase 1431 If Quest 31447 IS NOT rewarded');

-- Scaling
DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=2 AND `Entry` IN (59167,59099,59100,58722,59316,59153,59242,58842,59501,62731,59467,59213,59080,59480,59980,59982,58662,58633,58917,59481,30298,58664,59614,59368,59359,59929,59394,59613,59184,58823,59360,64563,59200,58875,58757,50485,58822,59304,54020,59503,59375,59193));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(59167, 2, 0, 0, 1187, 48865),
(59099, 2, 0, 0, 1187, 48865),
(59100, 2, 0, 0, 1187, 48865),
(58722, 2, 2, 2, 1187, 48865),
(59316, 2, 2, 2, 1187, 48865),
(59153, 2, 2, 2, 1187, 48865),
(59242, 2, 0, 0, 1187, 48865),
(58842, 2, 0, 0, 1187, 48865),
(59501, 2, 0, 0, 1187, 48865),
(62731, 2, 0, 0, 1187, 48865),
(59467, 2, 0, 0, 1187, 48865),
(59213, 2, 0, 0, 1187, 48865),
(59080, 2, 2, 2, 1187, 48865),
(59480, 2, 0, 0, 1187, 48865),
(59980, 2, 0, 0, 1187, 48865),
(59982, 2, 0, 0, 1187, 48865),
(58662, 2, 0, 0, 1187, 48865),
(58633, 2, 2, 2, 1187, 48865),
(58917, 2, 0, 0, 1187, 48865),
(59481, 2, 0, 0, 181, 48865),
(30298, 2, 0, 0, 328, 48865),
(58664, 2, 2, 2, 1187, 48865),
(59614, 2, 0, 0, 1187, 48865),
(59368, 2, 0, 0, 1187, 48865),
(59359, 2, 1, 1, 1187, 48865),
(59929, 2, 0, 0, 1187, 48865),
(59394, 2, 0, 0, 328, 48865),
(59613, 2, 1, 1, 1187, 48865),
(59184, 2, 2, 2, 1187, 48865),
(58823, 2, 0, 0, 1187, 48865),
(59360, 2, 0, 0, 1187, 48865),
(64563, 2, 0, 0, 1187, 48865),
(59200, 2, 2, 2, 1187, 48865),
(58875, 2, 2, 2, 1187, 48865),
(58757, 2, 0, 0, 1187, 48865),
(50485, 2, 0, 0, 81, 48865),
(58822, 2, 1, 1, 1187, 48865),
(59304, 2, 0, 0, 1187, 48865),
(54020, 2, 0, 0, 328, 48865),
(59503, 2, 0, 0, 1187, 48865),
(59375, 2, 0, 0, 651, 48865),
(59193, 2, 1, 1, 1187, 48865);

-- SAI (Channel to Phylactery)
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` IN (58823, 58757);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-(@CGUID+213), -(@CGUID+53), -(@CGUID+223)) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-(@CGUID+213), 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 0, 11, 122499, 0, 0, 0, 0, 0, 11, 58662, 15, 0, 0, 0, 0, 0, 'OnSpawn - Cast 122499 (Cosmetic Shadow Channel) - to nearby Phylactery (10y)'),
(-(@CGUID+53), 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 0, 11, 122499, 0, 0, 0, 0, 0, 11, 58662, 15, 0, 0, 0, 0, 0, 'OnSpawn - Cast 122499 (Cosmetic Shadow Channel) - to nearby Phylactery (10y)'),
(-(@CGUID+223), 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 0, 11, 122499, 0, 0, 0, 0, 0, 11, 58662, 15, 0, 0, 0, 0, 0, 'OnSpawn - Cast 122499 (Cosmetic Shadow Channel) - to nearby Phylactery (10y)');

-- Condition
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 13 AND `SourceGroup` = 1 AND `SourceEntry` = 122499);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 122499, 0, 0, 31, 0, 3, 58662, 0, 0, 0, 0, '', 'Cosmetic Shadow Channel - can only Target Instructor Chillheart Phylactery (58662)');

-- Waypoints for CGUID+5
SET @PATH := (@CGUID+5) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 221.4392, 12.49306, 119.2231, NULL, 0),
(@PATH, 1, 221.3629, 22.5434, 119.2224, NULL, 0),
(@PATH, 2, 221.3889, 31.89583, 119.2219, NULL, 0),
(@PATH, 3, 221.3629, 22.5434, 119.2224, NULL, 0),
(@PATH, 4, 221.4392, 12.49306, 119.2231, NULL, 0),
(@PATH, 5, 221.6875, 2.762153, 119.2211, NULL, 0);

UPDATE `creature` SET `position_x`= 221.4392, `position_y`= 12.49306, `position_z`= 119.2231, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+5;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+5;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+5, @PATH, 1);

-- Waypoints for CGUID+227
SET @PATH := (@CGUID+227) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 176.9514, 25.11806, 119.2211, NULL, 0),
(@PATH, 1, 176.934, 32.99306, 119.2211, NULL, 0),
(@PATH, 2, 176.9514, 25.11806, 119.2211, NULL, 0),
(@PATH, 3, 177.1337, 13.39757, 119.2211, NULL, 0),
(@PATH, 4, 177.3142, 2.741319, 119.2211, NULL, 0),
(@PATH, 5, 177.1337, 13.39757, 119.2211, NULL, 0);

UPDATE `creature` SET `position_x`= 176.9514, `position_y`= 25.11806, `position_z`= 119.2211, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+227;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+227;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+227, @PATH, 1);

-- Waypoints for CGUID+230
SET @PATH := (@CGUID+230) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 227.816, 2.888889, 119.2211, NULL, 0),
(@PATH, 1, 229.1076, 11.52951, 119.2306, NULL, 0),
(@PATH, 2, 232.7552, 12.80035, 119.234, NULL, 6984),
(@PATH, 3, 228.2743, 7.519097, 119.2211, NULL, 0),
(@PATH, 4, 228.3281, 2.956597, 119.2211, NULL, 0),
(@PATH, 5, 232.0833, 0.1128472, 119.2205, NULL, 0),
(@PATH, 6, 235.5486, -1.170139, 119.2212, NULL, 6643);

UPDATE `creature` SET `position_x`= 227.816, `position_y`= 2.888889, `position_z`= 119.2211, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+230;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+230;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `auras`) VALUES
(@CGUID+230, @PATH, 1, '111705');

-- Waypoints for CGUID+250
SET @PATH := (@CGUID+250) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 191.3108, -12.82813, 119.2211, NULL, 0),
(@PATH, 1, 192.651, -17.12153, 119.2211, NULL, 5512),
(@PATH, 2, 190.0122, -12.16667, 119.2211, NULL, 0),
(@PATH, 3, 185.4132, -11.38194, 119.2211, NULL, 0),
(@PATH, 4, 181.3785, -12.90451, 119.2211, NULL, 0),
(@PATH, 5, 179.5868, -14.65451, 119.2211, NULL, 10186);

UPDATE `creature` SET `position_x`= 191.3108, `position_y`= -12.82813, `position_z`= 119.2211, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+250;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+250;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `auras`) VALUES
(@CGUID+250, @PATH, 1, '111705');

-- Waypoints for CGUID+248
SET @PATH := (@CGUID+248) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 186.9167, -6.395833, 119.2211, NULL, 0),
(@PATH, 1, 192.3021, -9.998264, 119.2211, NULL, 6753),
(@PATH, 2, 179.8385, -6.296875, 119.2211, NULL, 2089);

UPDATE `creature` SET `position_x`= 186.9167, `position_y`= -6.395833, `position_z`= 119.2211, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+248;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+248;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+248, @PATH, 1);

-- Waypoints for CGUID+226
SET @PATH := (@CGUID+226) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 232.977, 31.4097, 119.2298, NULL, 8572),
(@PATH, 1, 237.4757, 23.61285, 119.235, NULL, 37771);

UPDATE `creature` SET `position_x`= 232.977, `position_y`= 31.4097, `position_z`= 119.2298, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+226;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+226;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+226, @PATH, 1);

-- Waypoints for CGUID+218
SET @PATH := (@CGUID+218) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 242.0764, 36.47917, 119.2227, NULL, 0),
(@PATH, 1, 242.2257, 39.63715, 119.2244, NULL, 6193),
(@PATH, 2, 241.9063, 30.81076, 119.2264, NULL, 14724);

UPDATE `creature` SET `position_x`= 242.0764, `position_y`= 36.47917, `position_z`= 119.2227, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+218;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+218;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+218, @PATH, 1);

-- Waypoints for CGUID+260
SET @PATH := (@CGUID+260) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 261.8125, -43.65451, 113.4242, NULL, 0),
(@PATH, 1, 255.849, -43.6059, 113.4244, NULL, 0),
(@PATH, 2, 250.2292, -43.60764, 113.4234, NULL, 0),
(@PATH, 3, 243.4531, -43.7066, 115.0068, NULL, 0),
(@PATH, 4, 236.4028, -43.64931, 116.7076, NULL, 0),
(@PATH, 5, 243.4531, -43.7066, 115.0068, NULL, 0),
(@PATH, 6, 250.2292, -43.60764, 113.4234, NULL, 0),
(@PATH, 7, 255.849, -43.6059, 113.4244, NULL, 0);

UPDATE `creature` SET `position_x`= 261.8125, `position_y`= -43.65451, `position_z`= 113.4242, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+260;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+260;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+260, @PATH, 1);

-- Waypoints for CGUID+75
SET @PATH := (@CGUID+75) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 209.0833, 165.8073, 113.2956, NULL, 13968),
(@PATH, 1, 193.8056, 166.5104, 113.2796, NULL, 0),
(@PATH, 2, 185.6944, 166.7743, 113.1922, NULL, 0),
(@PATH, 3, 178.875, 163.8056, 113.1187, NULL, 0),
(@PATH, 4, 178.533, 152.4375, 113.1147, NULL, 0),
(@PATH, 5, 176.4861, 143.8889, 113.0924, NULL, 0),
(@PATH, 6, 176.0174, 133.0347, 113.1382, NULL, 0),
(@PATH, 7, 172.3073, 132.8333, 113.1099, NULL, 13821),
(@PATH, 8, 176.4566, 144.5955, 113.0921, NULL, 0),
(@PATH, 9, 176.4167, 157.441, 113.092, NULL, 0),
(@PATH, 10, 182.2292, 164.0799, 113.1548, NULL, 0),
(@PATH, 11, 180.6441, 168.092, 113.1537, NULL, 12479),
(@PATH, 12, 192.2153, 166.0035, 113.2625, NULL, 0),
(@PATH, 13, 199.2153, 165.875, 113.2997, NULL, 0),
(@PATH, 14, 205.3524, 165.809, 113.2997, NULL, 0);

UPDATE `creature` SET `position_x`= 209.0833, `position_y`= 165.8073, `position_z`= 113.2956, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+75;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+75;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `auras`) VALUES
(@CGUID+75, @PATH, 1, '114141');

-- Waypoints for CGUID+190
SET @PATH := (@CGUID+190) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 224.2865, 144.2153, 113.1836, NULL, 0),
(@PATH, 1, 224.184, 129.2882, 113.1755, NULL, 0),
(@PATH, 2, 229.7326, 129.1892, 113.1392, NULL, 28675),
(@PATH, 3, 216.5885, 132.4288, 113.227, NULL, 0),
(@PATH, 4, 215.4965, 131.349, 113.2336, NULL, 12155),
(@PATH, 5, 224.901, 138.2656, 113.1761, NULL, 0),
(@PATH, 6, 225.184, 149.2014, 113.1806, NULL, 0),
(@PATH, 7, 233.9965, 161.2587, 113.1529, NULL, 12834);

UPDATE `creature` SET `position_x`= 224.2865, `position_y`= 144.2153, `position_z`= 113.1836, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+190;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+190;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `auras`) VALUES
(@CGUID+190, @PATH, 1, '114141');
