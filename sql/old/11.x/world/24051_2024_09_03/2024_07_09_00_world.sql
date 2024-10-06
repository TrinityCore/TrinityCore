SET @CGUID := 9004246;
SET @OGUID := 9003914;

SET @NPCTEXTID := 590119;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+30;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 216775, 2444, 15115, 15115, '0', '0', 0, 0, 1, -1929.4739990234375, 6865.16162109375, 183.390350341796875, 5.128407001495361328, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Maelir (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+1, 216646, 2444, 15115, 15115, '0', '0', 0, 0, 0, -1892.486083984375, 6874.5703125, 186.787017822265625, 5.84744882583618164, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Shen'dralar Sorcerer (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+2, 216647, 2444, 15115, 15115, '0', '0', 0, 0, 0, -1890.5867919921875, 6874.150390625, 186.7882080078125, 2.853504657745361328, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Highborne Lorekeeper (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+3, 216642, 2444, 15115, 15115, '0', '0', 0, 0, 0, -1946.0103759765625, 6862.1318359375, 185.028564453125, 1.216089844703674316, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Archmage Mordent Evenshade (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 433952 - -Unknown-)
(@CGUID+4, 216274, 2444, 15115, 15115, '0', '0', 0, 0, 1, -1907.78955078125, 6902.65380859375, 177.893524169921875, 2.8787384033203125, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Bel'ameth Sentinel (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+5, 216274, 2444, 15115, 15115, '0', '0', 0, 0, 1, -1852.9461669921875, 6909.62158203125, 176.211090087890625, 3.350155591964721679, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Bel'ameth Sentinel (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+6, 216646, 2444, 15115, 15115, '0', '0', 0, 0, 0, -1927.829833984375, 6863.59033203125, 183.373931884765625, 3.01143646240234375, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Shen'dralar Sorcerer (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+7, 216647, 2444, 15115, 15115, '0', '0', 0, 0, 0, -1891.734375, 6885.6943359375, 177.6788482666015625, 1.884295105934143066, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Highborne Lorekeeper (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 397765 - Cosmetic - Reading Book, Standing)
(@CGUID+8, 216254, 2444, 15115, 15115, '0', '0', 0, 0, 0, -1885.592041015625, 6883.21533203125, 177.679168701171875, 0, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Feyden Darkin (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+9, 216754, 2444, 15115, 15115, '0', '0', 0, 0, 0, -1929.5867919921875, 6862.64404296875, 183.3408203125, 1.190743565559387207, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Solarys Thorngale (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+10, 216646, 2444, 15115, 15115, '0', '0', 0, 0, 0, -1950.7742919921875, 6874.7568359375, 184.5648193359375, 5.432595252990722656, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Shen'dralar Sorcerer (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+11, 216678, 2444, 15115, 15115, '0', '0', 0, 0, 0, -2000.5989990234375, 7021.77880859375, 162.398468017578125, 0, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Trained Nightsaber (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+12, 216677, 2444, 15115, 15115, '0', '0', 0, 0, 0, -2000.0069580078125, 7020.828125, 162.519683837890625, 2.127778053283691406, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Lelanai (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+13, 216274, 2444, 15115, 15115, '0', '0', 0, 0, 1, -2011.44970703125, 7109.88037109375, 170.8522796630859375, 4.763429641723632812, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Bel'ameth Sentinel (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+14, 214196, 2444, 15115, 15115, '0', '0', 0, 0, 0, -1937.3177490234375, 6958.94580078125, 170.3463897705078125, 2.971749544143676757, 120, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 55261), -- Dappleflier (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+15, 216272, 2444, 15115, 15115, '0', '0', 0, 0, 0, -1853.545166015625, 6897.33056640625, 177.3778839111328125, 4.24706125259399414, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Telonis (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+16, 214196, 2444, 15115, 15115, '0', '0', 0, 0, 0, -1874.3182373046875, 6941.98046875, 172.08709716796875, 3.300736665725708007, 120, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 55261), -- Dappleflier (Area: -Unknown- - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+17, 216450, 2444, 15115, 15115, '0', '0', 0, 0, 0, -1855.2535400390625, 6894.35400390625, 177.3778839111328125, 1.212544679641723632, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Darianna (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+18, 214196, 2444, 15115, 15115, '0', '0', 0, 0, 0, -1908.727783203125, 6919.6005859375, 177.4272003173828125, 2.094139575958251953, 120, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 55261), -- Dappleflier (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+19, 216251, 2444, 15115, 15115, '0', '0', 0, 0, 0, -1831.532958984375, 6893.4921875, 179.313446044921875, 4.479478359222412109, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Professor Ash (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 302400 - Cosmetic - ChannelCastOmni Breakable (Druid - Nature)) (possible waypoints or random movement)
(@CGUID+20, 216284, 2444, 15115, 15115, '0', '0', 0, 0, 0, -1855.6632080078125, 6909.92724609375, 176.17529296875, 0.070138074457645416, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Mythrin'dir (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 427624 - [DNT] Flower Crown)
(@CGUID+21, 216271, 2444, 15115, 15115, '0', '0', 0, 0, 0, -1845.96875, 6888.18212890625, 177.3778839111328125, 1.562944293022155761, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Jelena Nightsky (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+22, 214196, 2444, 15115, 15115, '0', '0', 0, 0, 0, -1973.99365234375, 6975.88720703125, 171.5369110107421875, 0.879547297954559326, 120, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 55261), -- Dappleflier (Area: -Unknown- - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+23, 214196, 2444, 15115, 15115, '0', '0', 0, 0, 0, -1832.585693359375, 6909.19677734375, 175.745819091796875, 1.915223360061645507, 120, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 55261), -- Dappleflier (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+24, 216265, 2444, 15115, 15115, '0', '0', 0, 0, 0, -1816.2725830078125, 6875.9755859375, 181.074005126953125, 5.231531620025634765, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Tel'Athir (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 171987 - Hold Potion)
(@CGUID+25, 216778, 2444, 15115, 15115, '0', '0', 0, 0, 0, -1812.4034423828125, 6896.77978515625, 181.288238525390625, 4.572015762329101562, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Denalan (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+26, 214196, 2444, 15115, 15115, '0', '0', 0, 0, 0, -1865.17919921875, 6992.58154296875, 160.5094757080078125, 2.13652968406677246, 120, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 55261), -- Dappleflier (Area: -Unknown- - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+27, 214196, 2444, 15115, 15115, '0', '0', 0, 0, 0, -1776.69580078125, 6896.6748046875, 184.680389404296875, 3.63034820556640625, 120, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 55261), -- Dappleflier (Area: -Unknown- - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+28, 214196, 2444, 15115, 15115, '0', '0', 0, 0, 0, -1790.6502685546875, 6948.27783203125, 175.9986572265625, 2.326062917709350585, 120, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 55261), -- Dappleflier (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+29, 214196, 2444, 15115, 15115, '0', '0', 0, 0, 0, -1958.7611083984375, 7018.47705078125, 159.2208251953125, 0.938952863216400146, 120, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 55261), -- Dappleflier (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+30, 214196, 2444, 15115, 15115, '0', '0', 0, 0, 0, -2036.8785400390625, 7105.47216796875, 176.939727783203125, 5.664341926574707031, 120, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 55261); -- Dappleflier (Area: -Unknown- - Difficulty: 0) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+30;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+10, 0, 0, 0, 0, 0, 1, 0, 714, 0, 0, 0, 0, ''), -- Shen'dralar Sorcerer
(@CGUID+11, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Trained Nightsaber

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+26;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 421536, 2444, 15115, 15115, '0', '0', 0, -1899.4000244140625, 6891.54248046875, 177.574737548828125, 1.320165038108825683, 0, 0, 0.61318206787109375, 0.789941608905792236, 120, 255, 1, 55261), -- Bench (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+1, 421537, 2444, 15115, 15115, '0', '0', 0, -1905.330810546875, 6893.06103515625, 177.574737548828125, 1.320165038108825683, 0, 0, 0.61318206787109375, 0.789941608905792236, 120, 255, 1, 55261), -- Bench (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+2, 421538, 2444, 15115, 15115, '0', '0', 0, -1900.53125, 6909.23388671875, 177.5478057861328125, 4.437390327453613281, 0, 0, -0.79735374450683593, 0.603512227535247802, 120, 255, 1, 55261), -- Bench (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+3, 421539, 2444, 15115, 15115, '0', '0', 0, -1895.942626953125, 6908.09033203125, 177.56927490234375, 4.426036357879638671, 0, 0, -0.8007669448852539, 0.598976016044616699, 120, 255, 1, 55261), -- Bench (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+4, 421532, 2444, 15115, 15115, '0', '0', 0, -1879.4879150390625, 6906.99853515625, 186.6046600341796875, 3.053933382034301757, 0, 0, 0.999039649963378906, 0.043815590441226959, 120, 255, 1, 55261), -- Bench (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+5, 421533, 2444, 15115, 15115, '0', '0', 0, -1886.2542724609375, 6907.97216796875, 186.6046600341796875, 6.019930839538574218, 0, 0, -0.13124752044677734, 0.991349637508392333, 120, 255, 1, 55261), -- Bench (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+6, 421534, 2444, 15115, 15115, '0', '0', 0, -1884.489501953125, 6884.828125, 186.6082305908203125, 2.743263721466064453, 0, 0, 0.98023223876953125, 0.197850331664085388, 120, 255, 1, 55261), -- Bench (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+7, 421535, 2444, 15115, 15115, '0', '0', 0, -1891.72607421875, 6887.21826171875, 186.6082305908203125, 6.073245525360107421, 0, 0, -0.10477733612060546, 0.994495689868927001, 120, 255, 1, 55261), -- Bench (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+8, 421148, 2444, 15115, 15115, '0', '0', 0, -1823.422119140625, 6878.365234375, 181.0181121826171875, 1.842603445053100585, 0, 0, 0.796389579772949218, 0.604783952236175537, 120, 255, 1, 55261), -- Bench (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+9, 421540, 2444, 15115, 15115, '0', '0', 0, -1883.994873046875, 6912.90869140625, 177.576690673828125, 4.718366146087646484, 0, 0, -0.70499038696289062, 0.709216892719268798, 120, 255, 1, 55261), -- Bench (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+10, 421541, 2444, 15115, 15115, '0', '0', 0, -1888.8375244140625, 6880.6943359375, 177.5579986572265625, 1.289340734481811523, 0, 0, 0.600934982299804687, 0.799297928810119628, 120, 255, 1, 55261), -- Bench (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+11, 420912, 2444, 15115, 15115, '0', '0', 0, -1960.3785400390625, 6853.9296875, 187.0005035400390625, 0, 0, 0, 0, 1, 120, 255, 1, 55261), -- Portal to Darkshore (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+12, 420913, 2444, 15115, 15115, '0', '0', 0, -1967.80908203125, 6864, 186.8143310546875, 0, 0, 0, 0, 1, 120, 255, 1, 55261), -- Portal to Val'sharah (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+13, 420909, 2444, 15115, 15115, '0', '0', 0, -1934.43408203125, 6852.17724609375, 183.277313232421875, 0, 0, 0, 0, 1, 120, 255, 1, 55261), -- Portal to Stormwind (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+14, 420910, 2444, 15115, 15115, '0', '0', 0, -1968.7274169921875, 6854.96728515625, 187.0005035400390625, 0.046476732939481735, 0, 0, 0.023236274719238281, 0.99972999095916748, 120, 255, 1, 55261), -- Portal to Mount Hyjal (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+15, 421183, 2444, 15115, 15115, '0', '0', 0, -1954.017333984375, 6859.6162109375, 187.0221099853515625, 1.44789433479309082, -0.36081314086914062, 0.446298599243164062, 0.529017448425292968, 0.625117599964141845, 120, 255, 1, 55261), -- Kaldorei Bag (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+16, 420993, 2444, 15115, 15115, '0', '0', 0, -1708.5133056640625, 6945.7021484375, 180.8152618408203125, 4.372049331665039062, 0, 0, -0.81664180755615234, 0.577144801616668701, 120, 255, 1, 55261), -- Bench (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+17, 421185, 2444, 15115, 15115, '0', '0', 0, -1714.8211669921875, 6935.31591796875, 182.0263214111328125, 4.327532291412353515, -0.6273961067199707, 0.259771347045898437, -0.72699546813964843, 0.101835615932941436, 120, 255, 1, 55261), -- Kaldorei Spear (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+18, 420994, 2444, 15115, 15115, '0', '0', 0, -1693.2120361328125, 6944.7373046875, 188.0771636962890625, 2.993224143981933593, 0, 0, 0.997249603271484375, 0.074116282165050506, 120, 255, 1, 55261), -- Bench (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+19, 421764, 2444, 15115, 15115, '0', '0', 0, -1685.986083984375, 6929.42529296875, 188.2059326171875, 1.605701684951782226, 0, 0, 0.719339370727539062, 0.694658815860748291, 120, 255, 1, 55261), -- Bench (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+20, 422660, 2444, 15115, 15115, '0', '0', 0, -2011.91845703125, 7134.18603515625, 171.930145263671875, 2.801248550415039062, 0, 0, 0.985555648803710937, 0.169351965188980102, 120, 255, 1, 55261), -- Cookpot (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+21, 421768, 2444, 15115, 15115, '0', '0', 0, -2011.6771240234375, 7125.66162109375, 171.897552490234375, 6.169740200042724609, 0, 0, -0.05669212341308593, 0.998391687870025634, 120, 255, 1, 55261), -- Bench (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+22, 421769, 2444, 15115, 15115, '0', '0', 0, -2007.001708984375, 7125.66064453125, 171.904083251953125, 3.272519350051879882, 0, 0, -0.99785804748535156, 0.065416477620601654, 120, 255, 1, 55261), -- Bench (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+23, 421778, 2444, 15115, 15115, '0', '0', 0, -2102.65283203125, 7081.9365234375, 189.6996917724609375, 2.478367090225219726, 0, 0, 0.94551849365234375, 0.325568377971649169, 120, 255, 1, 55261), -- Bench (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+24, 421182, 2444, 15115, 15115, '0', '0', 0, -2119.376708984375, 7116.51416015625, 203.4230499267578125, 5.470659255981445312, 0.910351276397705078, -0.38622760772705078, -0.08833217620849609, 0.119524978101253509, 120, 255, 1, 55261), -- Kaldorei Horn (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+25, 421780, 2444, 15115, 15115, '0', '0', 0, -2150.272705078125, 7079.7509765625, 189.6996612548828125, 0.488691210746765136, 0, 0, 0.241921424865722656, 0.970295846462249755, 120, 255, 1, 55261), -- Bench (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+26, 421779, 2444, 15115, 15115, '0', '0', 0, -2155.4775390625, 7085.79150390625, 189.6996612548828125, 0.863936781883239746, 0, 0, 0.418659210205078125, 0.908143401145935058, 120, 255, 1, 55261); -- Bench (Area: -Unknown- - Difficulty: 0) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+26;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 0.991444885730743408, 0.130526408553123474, 0, 0), -- Bench
(@OGUID+1, 0, 0, 0.991444885730743408, 0.130526408553123474, 0, 0), -- Bench
(@OGUID+2, 0, 0, 0.991444885730743408, 0.130526408553123474, 0, 0), -- Bench
(@OGUID+3, 0, 0, 0.991444885730743408, 0.130526408553123474, 0, 0), -- Bench
(@OGUID+4, 0, 0, 0.991444885730743408, 0.130526408553123474, 0, 0), -- Bench
(@OGUID+5, 0, 0, 0.991444885730743408, 0.130526408553123474, 0, 0), -- Bench
(@OGUID+6, 0, 0, 0.991444885730743408, 0.130526408553123474, 0, 0), -- Bench
(@OGUID+7, 0, 0, 0.991444885730743408, 0.130526408553123474, 0, 0), -- Bench
(@OGUID+8, 0, 0, 0.824125945568084716, 0.566406548023223876, 0, 0), -- Bench
(@OGUID+9, 0, 0, 0.991444885730743408, 0.130526408553123474, 0, 0), -- Bench
(@OGUID+10, 0, 0, 0.991444885730743408, 0.130526408553123474, 0, 0), -- Bench
(@OGUID+11, 0, 0, 0, 1, 0, 3503), -- Portal to Darkshore
(@OGUID+12, 0, 0, 0, 1, 0, 3503), -- Portal to Val'sharah
(@OGUID+13, 0, 0, 0, 1, 0, 3503), -- Portal to Stormwind
(@OGUID+14, 0, 0, 0, 1, 0, 3503), -- Portal to Mount Hyjal
(@OGUID+16, 0, 0, -0.08715587854385375, 0.996194720268249511, 0, 0), -- Bench
(@OGUID+18, 0, 0, -0.08715587854385375, 0.996194720268249511, 0, 0); -- Bench

-- Template
UPDATE `creature_template` SET `faction`=1971, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=216431; -- Sentinel of the New Moon
UPDATE `creature_template` SET `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=217169; -- Archdruid Hamuul Runetotem
UPDATE `creature_template` SET `faction`=188, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=212494; -- Lifedrip
UPDATE `creature_template` SET `faction`=1971, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=216677; -- Lelanai
UPDATE `creature_template` SET `faction`=1971, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=216678; -- Trained Nightsaber
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=212491; -- Coastglider Pup
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=18432 WHERE `entry`=216778; -- Denalan
UPDATE `creature_template` SET `faction`=1971, `npcflag`=81, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=216265; -- Tel'Athir
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=212497; -- Bloompaw Rabbit
UPDATE `creature_template` SET `faction`=35, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=217142; -- Nat
UPDATE `creature_template` SET `faction`=35, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=217143; -- Hannah
UPDATE `creature_template` SET `faction`=188, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=214195; -- Forest Burrower
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=216694; -- Efflorescent Matriarch
UPDATE `creature_template` SET `faction`=1971, `npcflag`=81, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=216271; -- Jelena Nightsky
UPDATE `creature_template` SET `faction`=1971, `npcflag`=129, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=216284; -- Mythrin'dir
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=216786; -- Nantar
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=67110912, `unit_flags3`=1 WHERE `entry`=212109; -- (Bunny) Sessile
UPDATE `creature_template` SET `faction`=1971, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=216754; -- Solarys Thorngale
UPDATE `creature_template` SET `faction`=35, `npcflag`=81, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=216251; -- Professor Ash
UPDATE `creature_template` SET `faction`=1971, `npcflag`=82, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=216254; -- Feyden Darkin
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=217003; -- Finel
UPDATE `creature_template` SET `faction`=1971, `BaseAttackTime`=1500, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=216539; -- Darkshore Visitor
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=216787; -- Shandrina
UPDATE `creature_template` SET `faction`=1971, `npcflag`=83, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=216450; -- Darianna
UPDATE `creature_template` SET `faction`=1971, `BaseAttackTime`=1500, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=216512; -- Hyjal Visitor
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=216781; -- Aayndia Floralwind
UPDATE `creature_template` SET `faction`=1971, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=216274; -- Bel'ameth Sentinel
UPDATE `creature_template` SET `faction`=1971, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=216272; -- Telonis
UPDATE `creature_template` SET `faction`=1971, `npcflag`=1, `BaseAttackTime`=1500, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=216642; -- Archmage Mordent Evenshade
UPDATE `creature_template` SET `faction`=1971, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=216462; -- Amirdrassil Settler
UPDATE `creature_template` SET `faction`=188, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=214196; -- Dappleflier
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=216693; -- Efflorescent Taloncub
UPDATE `creature_template` SET `faction`=1971, `BaseAttackTime`=1500, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=216647; -- Highborne Lorekeeper
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=216695; -- Efflorescent Umbraclaw
UPDATE `creature_template` SET `faction`=1971, `BaseAttackTime`=1500, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=216533; -- Val'sharah Visitor
UPDATE `creature_template` SET `faction`=1971, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=216775; -- Maelir

DELETE FROM `gameobject_template` WHERE `entry` IN (421779 /*Bench*/, 421780 /*Bench*/, 421182 /*Kaldorei Horn*/, 422660 /*Cookpot*/, 421778 /*Bench*/, 421769 /*Bench*/, 421768 /*Bench*/, 421764 /*Bench*/, 420994 /*Bench*/, 421185 /*Kaldorei Spear*/, 420993 /*Bench*/, 421183 /*Kaldorei Bag*/, 420912 /*Portal to Darkshore*/, 420913 /*Portal to Val'sharah*/, 420909 /*Portal to Stormwind*/, 420910 /*Portal to Mount Hyjal*/, 421539 /*Bench*/, 421535 /*Bench*/, 421148 /*Bench*/, 421540 /*Bench*/, 421536 /*Bench*/, 421532 /*Bench*/, 421541 /*Bench*/, 421537 /*Bench*/, 421533 /*Bench*/, 421538 /*Bench*/, 421534 /*Bench*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(421779, 7, 85900, 'Bench', '', '', '', 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 55261), -- Bench
(421780, 7, 85900, 'Bench', '', '', '', 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 55261), -- Bench
(421182, 3, 87317, 'Kaldorei Horn', 'questinteract', '', '', 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6017, 121580, 0, 0, 0, 0, 2484, 55261), -- Kaldorei Horn
(422660, 8, 56971, 'Cookpot', '', '', '', 1, 4, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 55261), -- Cookpot
(421778, 7, 85900, 'Bench', '', '', '', 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 55261), -- Bench
(421769, 7, 85900, 'Bench', '', '', '', 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 55261), -- Bench
(421768, 7, 85900, 'Bench', '', '', '', 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 55261), -- Bench
(421764, 7, 85900, 'Bench', '', '', '', 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 55261), -- Bench
(420994, 7, 85900, 'Bench', '', '', '', 0.999999463558197021, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 55261), -- Bench
(421185, 3, 87320, 'Kaldorei Spear', 'questinteract', '', '', 1.5, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6011, 121576, 0, 0, 0, 0, 2484, 55261), -- Kaldorei Spear
(420993, 7, 85900, 'Bench', '', '', '', 0.999999463558197021, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 55261), -- Bench
(421183, 3, 87318, 'Kaldorei Bag', 'questinteract', '', '', 1, 43, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6010, 121548, 0, 0, 0, 0, 2484, 55261), -- Kaldorei Bag
(420912, 22, 36660, 'Portal to Darkshore', '', '', '', 1, 433023, -1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 876, 55261), -- Portal to Darkshore
(420913, 22, 5231, 'Portal to Val\'sharah', '', '', '', 1, 433025, -1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 876, 55261), -- Portal to Val'sharah
(420909, 22, 66650, 'Portal to Stormwind', '', '', '', 1, 433013, -1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 876, 55261), -- Portal to Stormwind
(420910, 22, 4393, 'Portal to Mount Hyjal', '', '', '', 1, 433018, -1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 876, 55261), -- Portal to Mount Hyjal
(421539, 7, 85900, 'Bench', '', '', '', 0.999999880790710449, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 55261), -- Bench
(421535, 7, 85900, 'Bench', '', '', '', 0.999999761581420898, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 55261), -- Bench
(421148, 7, 85900, 'Bench', '', '', '', 0.999999821186065673, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 55261), -- Bench
(421540, 7, 85900, 'Bench', '', '', '', 0.999999761581420898, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 55261), -- Bench
(421536, 7, 85900, 'Bench', '', '', '', 0.999999761581420898, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 55261), -- Bench
(421532, 7, 85900, 'Bench', '', '', '', 0.999999761581420898, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 55261), -- Bench
(421541, 7, 85900, 'Bench', '', '', '', 0.999999821186065673, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 55261), -- Bench
(421537, 7, 85900, 'Bench', '', '', '', 0.999999761581420898, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 55261), -- Bench
(421533, 7, 85900, 'Bench', '', '', '', 0.999999821186065673, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 55261), -- Bench
(421538, 7, 85900, 'Bench', '', '', '', 0.999999821186065673, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 55261), -- Bench
(421534, 7, 85900, 'Bench', '', '', '', 0.999999821186065673, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 55261); -- Bench

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (216647 /*216647 (Highborne Lorekeeper) - Cosmetic - Reading Book, Standing*/, 216642 /*216642 (Archmage Mordent Evenshade) - -Unknown-*/, 216646 /*216646 (Shen'dralar Sorcerer)*/, 216775 /*216775 (Maelir)*/,216778 /*216778 (Denalan)*/, 216265 /*216265 (Tel'Athir) - Hold Potion*/, 216284 /*216284 (Mythrin'dir) - [DNT] Flower Crown*/, 216251 /*216251 (Professor Ash) - Cosmetic - ChannelCastOmni Breakable (Druid - Nature)*/, 214196 /*214196 (Dappleflier)*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(216647, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '397765'), -- 216647 (Highborne Lorekeeper) - Cosmetic - Reading Book, Standing
(216642, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '433952'), -- 216642 (Archmage Mordent Evenshade) - -Unknown-
(216646, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 216646 (Shen'dralar Sorcerer)
(216775, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 216775 (Maelir)
(216778, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 216778 (Denalan)
(216265, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 216265 (Tel'Athir) - Hold Potion
(216284, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '427624'), -- 216284 (Mythrin'dir) - [DNT] Flower Crown
(216251, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 216251 (Professor Ash) - Cosmetic - ChannelCastOmni Breakable (Druid - Nature)
(214196, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 214196 (Dappleflier)

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (421182 /*Kaldorei Horn*/, 421185 /*Kaldorei Spear*/, 421183 /*Kaldorei Bag*/, 420910 /*Portal to Mount Hyjal*/, 420909 /*Portal to Stormwind*/, 420913 /*Portal to Val'sharah*/, 420912 /*Portal to Darkshore*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(421182, 35, 2113536, 0, 0), -- Kaldorei Horn
(421185, 35, 2113536, 0, 0), -- Kaldorei Spear
(421183, 35, 2113536, 0, 0), -- Kaldorei Bag
(420910, 1732, 32, 0, 3503), -- Portal to Mount Hyjal
(420909, 1732, 32, 0, 3503), -- Portal to Stormwind
(420913, 1732, 32, 0, 3503), -- Portal to Val'sharah
(420912, 1732, 32, 0, 3503); -- Portal to Darkshore

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=216642 AND `MenuID`=33655) OR (`CreatureID`=216265 AND `MenuID`=8516) OR (`CreatureID`=216251 AND `MenuID`=32377) OR (`CreatureID`=216271 AND `MenuID`=7842) OR (`CreatureID`=216450 AND `MenuID`=8520) OR (`CreatureID`=216284 AND `MenuID`=32004);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(216642, 33655, 55261), -- Archmage Mordent Evenshade
(216265, 8516, 55261), -- Tel'Athir
(216251, 32377, 55261), -- Professor Ash
(216271, 7842, 55261), -- Jelena Nightsky
(216450, 8520, 55261), -- Darianna
(216284, 32004, 55261); -- Mythrin'dir

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+2;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 254750, 0, 0, 0, 0, 0, 0, 0, 55261), -- 216642 (Archmage Mordent Evenshade)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 246860, 0, 0, 0, 0, 0, 0, 0, 55261), -- 216251 (Professor Ash)
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 244787, 0, 0, 0, 0, 0, 0, 0, 55261); -- 216284 (Mythrin'dir)

DELETE FROM `gossip_menu` WHERE (`MenuID`=33655 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=32377 AND `TextID`=@NPCTEXTID+1) OR (`MenuID`=32004 AND `TextID`=@NPCTEXTID+2);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(33655, @NPCTEXTID+0, 55261), -- 216642 (Archmage Mordent Evenshade)
(32377, @NPCTEXTID+1, 55261), -- 216251 (Professor Ash)
(32004, @NPCTEXTID+2, 55261); -- 216284 (Mythrin'dir)

DELETE FROM `gossip_menu` WHERE (`MenuID`=8516 AND `TextID`=10649) OR (`MenuID`=8520 AND `TextID`=10653);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(8516, 10649, 55261), -- 216265 (Tel'Athir)
(8520, 10653, 55261); -- 216450 (Darianna)

UPDATE `gossip_menu` SET `VerifiedBuild`=55261 WHERE (`MenuID`=7842 AND `TextID`=9599);
DELETE FROM `gossip_menu_option` WHERE (`OptionID`=0 AND `MenuID` IN (8516,32004,8520)) OR (`OptionID`=2 AND `MenuID`=32377);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(8516, 35791, 0, 3, 'Train me.', 3266, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55261),
(32004, 110480, 0, 1, 'Show me your wares.', 58437, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55261), -- OptionBroadcastTextID: 58437 - 90189 - 180077
(32377, 110918, 2, 3, 'Train me in Herbalism.', 47112, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55261),
(8520, 35450, 0, 3, 'Train me.', 3266, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55261);

-- Creature Equip
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (216431,217169,216274,216775));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(216431, 1, 213018, 0, 0, 213011, 0, 0, 0, 0, 0, 55261), -- Sentinel of the New Moon
(217169, 1, 63052, 0, 0, 0, 0, 0, 0, 0, 0, 55261), -- Archdruid Hamuul Runetotem
(216274, 1, 208761, 0, 0, 0, 0, 0, 0, 0, 0, 55261), -- Bel'ameth Sentinel
(216775, 1, 109677, 0, 0, 0, 0, 0, 0, 0, 0, 55261); -- Maelir

-- NPC spellclick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 216678;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(216678, 406024, 1, 0);

-- Professor Ash smart ai
SET @ENTRY := 216251;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 34, 0, 100, 0, 2, 11, 0, 0, 80, 21625100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 11 - Self: Start timed action list id #Professor Ash #0 (21625100) (update out of combat)'),
(@ENTRY, 0, 1, 0, '', 34, 0, 100, 0, 2, 17, 0, 0, 80, 21625100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 17 - Self: Start timed action list id #Professor Ash #0 (21625100) (update out of combat)'),
(@ENTRY, 0, 2, 0, '', 34, 0, 100, 0, 0, 26, 0, 0, 80, 21625100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement inform, point 26 - Self: Start timed action list id #Professor Ash #0 (21625100) (update out of combat)');

 -- Timed list 21625100 smart ai
SET @ENTRY := 21625100;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 9, 0, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 85, 302400, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Cast spell 302400 on self'),
(@ENTRY, 9, 1, 0, '', 0, 0, 100, 0, 11000, 11000, 0, 0, 92, 0, 302400, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 11 seconds - Self: Interrupt casted spell  302400');

-- Vendor data
DELETE FROM `npc_vendor` WHERE `entry` IN (216677, 216284);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(216677, 7, 18766, 0, 0, 1, 0, 0, 55261), -- Reins of the Swift Frostsaber
(216677, 6, 18767, 0, 0, 1, 0, 0, 55261), -- Reins of the Swift Mistsaber
(216677, 5, 18902, 0, 0, 1, 0, 0, 55261), -- Reins of the Swift Stormsaber
(216677, 4, 8629, 0, 0, 1, 0, 0, 55261), -- Reins of the Striped Nightsaber
(216677, 3, 8632, 0, 0, 1, 0, 0, 55261), -- Reins of the Spotted Frostsaber
(216677, 2, 8631, 0, 0, 1, 0, 0, 55261), -- Reins of the Striped Frostsaber
(216677, 1, 47100, 0, 0, 1, 0, 0, 55261), -- Reins of the Striped Dawnsaber
(216284, 26, 211399, 0, 6071, 1, 0, 0, 55261), -- Technique: Glyph of the Lunar Chameleon
(216284, 25, 188152, 0, 0, 1, 0, 0, 55261), -- Gateway Control Shard
(216284, 24, 64670, 0, 0, 1, 0, 0, 55261), -- Vanishing Powder
(216284, 23, 138293, 0, 0, 1, 0, 0, 55261), -- Explorer's Pack
(216284, 22, 85663, 0, 0, 1, 0, 0, 55261), -- Herbalist's Spade
(216284, 21, 2901, 0, 0, 1, 0, 0, 55261), -- Mining Pick
(216284, 20, 7005, 0, 0, 1, 0, 0, 55261), -- Skinning Knife
(216284, 19, 39505, 0, 0, 1, 0, 0, 55261), -- Virtuoso Inking Set
(216284, 18, 6256, 0, 0, 1, 0, 0, 55261), -- Fishing Pole
(216284, 17, 10498, 0, 0, 1, 0, 0, 55261), -- Gyromatic Micro-Adjustor
(216284, 16, 6219, 0, 0, 1, 0, 0, 55261), -- Arclight Spanner
(216284, 15, 20815, 0, 0, 1, 0, 0, 55261), -- Jeweler's Toolset
(216284, 14, 6218, 0, 0, 1, 0, 0, 55261), -- Runed Copper Rod
(216284, 13, 5956, 0, 0, 1, 0, 0, 55261), -- Blacksmith Hammer
(216284, 12, 197753, 0, 0, 1, 0, 0, 55261), -- Thaldraszian Cocoa Powder
(216284, 11, 197752, 0, 0, 1, 0, 0, 55261), -- Conveniently Packaged Ingredients
(216284, 10, 197751, 0, 0, 1, 0, 0, 55261), -- Pastry Packets
(216284, 9, 197750, 0, 0, 1, 0, 0, 55261), -- Three-Cheese Blend
(216284, 8, 197749, 0, 0, 1, 0, 0, 55261), -- Ohn'ahran Potato
(216284, 7, 38682, 0, 0, 1, 0, 0, 55261), -- Enchanting Vellum
(216284, 6, 200860, 0, 0, 1, 0, 0, 55261), -- Draconic Stopper
(216284, 5, 191474, 0, 0, 1, 0, 0, 55261), -- Draconic Vial
(216284, 4, 192833, 0, 0, 1, 0, 0, 55261), -- Misshapen Filigree
(216284, 3, 198487, 0, 0, 1, 0, 0, 55261), -- Iridescent Water
(216284, 2, 194784, 0, 0, 1, 0, 0, 55261), -- Glittering Parchment
(216284, 1, 190452, 0, 0, 1, 0, 0, 55261); -- Primal Flux

-- Trainer data
DELETE FROM `creature_trainer` WHERE (`CreatureID`=216254 AND `MenuID`=0 AND `OptionID`=0) OR (`CreatureID`=216265 AND `MenuID`=8516 AND `OptionID`=0) OR (`CreatureID`=216251 AND `MenuID`=32377 AND `OptionID`=2) OR (`CreatureID`=216271 AND `MenuID`=7842 AND `OptionID`=0) OR (`CreatureID`=216450 AND `MenuID`=8520 AND `OptionID`=0);
INSERT INTO `creature_trainer` (`CreatureID`, `TrainerID`, `MenuID`, `OptionID`) VALUES
(216254, 1078, 0, 0),
(216265, 1083, 8516, 0),
(216251, 1087, 32377, 2),
(216271, 1085, 7842, 0),
(216450, 1076, 8520, 0);

DELETE FROM `trainer` WHERE `Id` IN (1078, 1083, 1087, 1085, 1076);
INSERT INTO `trainer` (`Id`, `Type`, `Greeting`, `VerifiedBuild`) VALUES
(1078, 2, 'Hello, friend!', 55261),
(1083, 2, 'Hello, friend!', 55261),
(1087, 2, 'Hello, friend!', 55261),
(1085, 2, 'Hello, friend!', 55261),
(1076, 2, 'Hello, friend!', 55261);

DELETE FROM `trainer_spell` WHERE (`TrainerId`=1078 AND `SpellId` IN (383539,389193,383529,383546,383530,383572,383547,384949,384948,383791,383790,383562,383561,383560,383556,383555,383554,383563,383544,383543,383525,383551,383527,383549,366241,264495)) OR (`TrainerId`=1083 AND `SpellId` IN (370711,389190,370748,370746,370743,370731,370722,370717,370465,370547,370551,366248,264212)) OR (`TrainerId`=1087 AND `SpellId` IN (366242,265820)) OR (`TrainerId`=1085 AND `SpellId` IN (366263,265856)) OR (`TrainerId`=1076 AND `SpellId` IN (409555,409557,375183,375184,395844,395851,395847,395839,395845,395863,395868,395867,395864,395865,389195,375188,375187,375185,375182,375181,375179,375178,375174,375173,375168,375164,375108,375106,375105,375103,375102,366239,264578));;
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
(1078, 383539, 1000000, 2828, 15, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1078, 389193, 1000000, 2828, 15, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1078, 383529, 1300000, 2828, 25, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1078, 383546, 1800000, 2828, 50, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1078, 383530, 1000000, 2828, 15, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1078, 383572, 1300000, 2828, 25, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1078, 383547, 1300000, 2828, 25, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1078, 384949, 800000, 2828, 10, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1078, 384948, 800000, 2828, 10, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1078, 383791, 1100000, 2828, 20, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1078, 383790, 1500000, 2828, 35, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1078, 383562, 1700000, 2828, 45, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1078, 383561, 1700000, 2828, 45, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1078, 383560, 1700000, 2828, 45, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1078, 383556, 1700000, 2828, 45, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1078, 383555, 1700000, 2828, 45, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1078, 383554, 1700000, 2828, 45, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1078, 383563, 800000, 2828, 10, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1078, 383544, 1000000, 2828, 15, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1078, 383543, 1000000, 2828, 15, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1078, 383525, 1300000, 2828, 25, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1078, 383551, 1300000, 2828, 25, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1078, 383527, 1300000, 2828, 25, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1078, 383549, 1300000, 2828, 25, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1078, 366241, 1000000, 773, 1, 0, 0, 0, 58, 55261), -- No Faction found! MoneyCost not recalculated!
(1078, 264495, 10, 0, 0, 0, 0, 0, 5, 55261), -- No Faction found! MoneyCost not recalculated!
(1083, 370711, 1000000, 2823, 15, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1083, 389190, 1300000, 2823, 25, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1083, 370748, 800000, 2823, 10, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1083, 370746, 800000, 2823, 10, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1083, 370743, 800000, 2823, 10, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1083, 370731, 1500000, 2823, 35, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1083, 370722, 800000, 2823, 10, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1083, 370717, 1100000, 2823, 20, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1083, 370465, 1300000, 2823, 25, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1083, 370547, 600000, 2823, 5, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1083, 370551, 1800000, 2823, 50, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1083, 366248, 1000000, 171, 1, 0, 0, 0, 58, 55261), -- No Faction found! MoneyCost not recalculated!
(1083, 264212, 10, 0, 0, 0, 0, 0, 5, 55261), -- No Faction found! MoneyCost not recalculated!
(1087, 366242, 1000000, 182, 1, 0, 0, 0, 58, 55261), -- No Faction found! MoneyCost not recalculated!
(1087, 265820, 10, 0, 0, 0, 0, 0, 5, 55261), -- No Faction found! MoneyCost not recalculated!
(1085, 366263, 1000000, 393, 1, 0, 0, 0, 58, 55261), -- No Faction found! MoneyCost not recalculated!
(1085, 265856, 10, 0, 0, 0, 0, 0, 5, 55261), -- No Faction found! MoneyCost not recalculated!
(1076, 409555, 1300000, 2830, 25, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1076, 409557, 1300000, 2830, 25, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1076, 375183, 600000, 2830, 5, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1076, 375184, 1400000, 2830, 30, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1076, 395844, 1100000, 2830, 20, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1076, 395851, 1600000, 2830, 40, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1076, 395847, 1700000, 2830, 45, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1076, 395839, 1800000, 2830, 50, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1076, 395845, 1300000, 2830, 25, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1076, 395863, 1100000, 2830, 20, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1076, 395868, 1600000, 2830, 40, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1076, 395867, 1700000, 2830, 45, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1076, 395864, 1800000, 2830, 50, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1076, 395865, 1300000, 2830, 25, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1076, 389195, 1000000, 2830, 15, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1076, 375188, 1500000, 2830, 35, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1076, 375187, 1500000, 2830, 35, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1076, 375185, 1400000, 2830, 30, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1076, 375182, 1000000, 2830, 15, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1076, 375181, 800000, 2830, 10, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1076, 375179, 1300000, 2830, 25, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1076, 375178, 1300000, 2830, 25, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1076, 375174, 1300000, 2830, 25, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1076, 375173, 1300000, 2830, 25, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1076, 375168, 1000000, 2830, 15, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1076, 375164, 800000, 2830, 10, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1076, 375108, 800000, 2830, 10, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1076, 375106, 600000, 2830, 5, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1076, 375105, 800000, 2830, 10, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1076, 375103, 600000, 2830, 5, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1076, 375102, 1500000, 2830, 35, 0, 0, 0, 0, 55261), -- No Faction found! MoneyCost not recalculated!
(1076, 366239, 1000000, 165, 1, 0, 0, 0, 58, 55261), -- No Faction found! MoneyCost not recalculated!
(1076, 264578, 10, 0, 0, 0, 0, 0, 5, 55261); -- No Faction found! MoneyCost not recalculated!

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID` IN (113020, 116986, 117033, 116936, 116932, 116135, 117025, 116934, 116930, 116919, 112869, 112872, 117031, 113507, 116696, 116987, 112914, 114045, 113572, 117015, 116948, 116927, 117030, 116921, 112912, 117029, 112868, 116693, 116981, 112864, 116979, 116942, 112916, 116698, 112870, 116717, 117011, 116694);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(113020, 0.388999998569488525, 1.5, 0, 55261),
(116986, 1.07983410358428955, 0, 0, 55261),
(117033, 0.305999994277954101, 1.5, 0, 55261),
(116936, 0.388999998569488525, 1.5, 0, 55261),
(116932, 0.305999994277954101, 1.5, 0, 55261),
(116135, 2.429626703262329101, 0, 0, 55261),
(117025, 0.388999998569488525, 1.5, 0, 55261),
(116934, 0.388999998569488525, 1.5, 0, 55261),
(116930, 0.305999994277954101, 1.5, 0, 55261),
(116919, 0.5, 0, 0, 55261),
(112869, 1.65776073932647705, 3, 0, 55261),
(112872, 1.65776073932647705, 3, 0, 55261),
(117031, 0.305999994277954101, 1.5, 0, 55261),
(113507, 0.388999998569488525, 1.5, 0, 55261),
(116696, 0.351899981498718261, 1.724999904632568359, 0, 55261),
(116987, 1.07983410358428955, 0, 0, 55261),
(112914, 0.240000009536743164, 0, 0, 55261),
(114045, 0.305999994277954101, 1.5, 0, 55261),
(113572, 0.388999998569488525, 1.5, 0, 55261),
(117015, 0.447349995374679565, 1.724999904632568359, 0, 55261),
(116948, 0.267382413148880004, 0, 0, 55261),
(116927, 0.305999994277954101, 1.5, 0, 55261),
(117030, 0.305999994277954101, 1.5, 0, 55261),
(116921, 0.305999994277954101, 1.5, 0, 55261),
(112912, 0.240000009536743164, 0, 0, 55261),
(117029, 0.388999998569488525, 1.5, 0, 55261),
(112868, 1.105173826217651367, 2, 0, 55261),
(116693, 0.42790001630783081, 1.65000009536743164, 0, 55261),
(116981, 1.07983410358428955, 0, 0, 55261),
(112864, 1.105173826217651367, 2, 0, 55261),
(116979, 1.07983410358428955, 0, 0, 55261),
(116942, 0.388999998569488525, 1.5, 0, 55261),
(112916, 0.240000009536743164, 0, 0, 55261),
(116698, 0.351899981498718261, 1.724999904632568359, 0, 55261),
(112870, 1.105173826217651367, 2, 0, 55261),
(116717, 0.305999994277954101, 1.5, 0, 55261),
(117011, 0.351899981498718261, 1.724999904632568359, 0, 55261),
(116694, 0.388999998569488525, 1.5, 0, 55261);

UPDATE `creature_model_info` SET `VerifiedBuild`=55261 WHERE `DisplayID` IN (31605, 104530, 100359, 44820, 1072, 105247, 106534, 103844);
UPDATE `creature_model_info` SET `BoundingRadius`=0.524999976158142089, `CombatReach`=2.25, `VerifiedBuild`=55261 WHERE `DisplayID`=89248;
UPDATE `creature_model_info` SET `BoundingRadius`=0.44829609990119934, `CombatReach`=0.300000011920928955, `VerifiedBuild`=55261 WHERE `DisplayID`=102069;

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=216431 AND `DifficultyID`=0); -- 216431 (Sentinel of the New Moon) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2699, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=217169 AND `DifficultyID`=0); -- 217169 (Archdruid Hamuul Runetotem) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=212494 AND `DifficultyID`=0); -- 212494 (Lifedrip) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=216677 AND `DifficultyID`=0); -- 216677 (Lelanai) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=216678 AND `DifficultyID`=0); -- 216678 (Trained Nightsaber) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=212491 AND `DifficultyID`=0); -- 212491 (Coastglider Pup) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2699, `StaticFlags1`=805306368, `VerifiedBuild`=55261 WHERE (`Entry`=216778 AND `DifficultyID`=0); -- 216778 (Denalan) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=216265 AND `DifficultyID`=0); -- 216265 (Tel'Athir) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=217142 AND `DifficultyID`=0); -- 217142 (Nat) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=217143 AND `DifficultyID`=0); -- 217143 (Hannah) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `VerifiedBuild`=55261 WHERE (`Entry`=214195 AND `DifficultyID`=0); -- 214195 (Forest Burrower) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2699, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=216694 AND `DifficultyID`=0); -- 216694 (Efflorescent Matriarch) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=216271 AND `DifficultyID`=0); -- 216271 (Jelena Nightsky) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=216284 AND `DifficultyID`=0); -- 216284 (Mythrin'dir) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=536870912, `VerifiedBuild`=55261 WHERE (`Entry`=216786 AND `DifficultyID`=0); -- 216786 (Nantar) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2078, `StaticFlags1`=536871168, `VerifiedBuild`=55261 WHERE (`Entry`=212109 AND `DifficultyID`=0); -- 212109 ((Bunny) Sessile) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=216754 AND `DifficultyID`=0); -- 216754 (Solarys Thorngale) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=216251 AND `DifficultyID`=0); -- 216251 (Professor Ash) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=216254 AND `DifficultyID`=0); -- 216254 (Feyden Darkin) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=217003 AND `DifficultyID`=0); -- 217003 (Finel) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=216539 AND `DifficultyID`=0); -- 216539 (Darkshore Visitor) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=536870912, `VerifiedBuild`=55261 WHERE (`Entry`=216787 AND `DifficultyID`=0); -- 216787 (Shandrina) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=216450 AND `DifficultyID`=0); -- 216450 (Darianna) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=216512 AND `DifficultyID`=0); -- 216512 (Hyjal Visitor) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=536870912, `VerifiedBuild`=55261 WHERE (`Entry`=216781 AND `DifficultyID`=0); -- 216781 (Aayndia Floralwind) - Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=883, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=216274 AND `DifficultyID`=0); -- 216274 (Bel'ameth Sentinel) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=216272 AND `DifficultyID`=0); -- 216272 (Telonis) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=693, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=216642 AND `DifficultyID`=0); -- 216642 (Archmage Mordent Evenshade) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=216462 AND `DifficultyID`=0); -- 216462 (Amirdrassil Settler) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2699, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=216693 AND `DifficultyID`=0); -- 216693 (Efflorescent Taloncub) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=876, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=216647 AND `DifficultyID`=0); -- 216647 (Highborne Lorekeeper) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2699, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=216695 AND `DifficultyID`=0); -- 216695 (Efflorescent Umbraclaw) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=216533 AND `DifficultyID`=0); -- 216533 (Val'sharah Visitor) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=216775 AND `DifficultyID`=0); -- 216775 (Maelir) - CanSwim

-- Path for Professor Ash
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+19;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+19, @CGUID+19, 0, 0, 515, 0, 0),
(@CGUID+19, @CGUID+25, 3, 0, 515, 0, 0);

SET @ENTRY := 216251;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Professor Ash - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1804.486, 6891.696, 181.4274, NULL, 0),
(@PATH, 1, -1805.382, 6894.315, 181.1484, NULL, 0),
(@PATH, 2, -1807.668, 6896.853, 180.5937, NULL, 0),
(@PATH, 3, -1809.986, 6898.563, 180.123, NULL, 0),
(@PATH, 4, -1813.063, 6900.1, 179.7017, NULL, 0),
(@PATH, 5, -1815.793, 6900.841, 179.4343, NULL, 0),
(@PATH, 6, -1818.319, 6901.868, 178.9769, NULL, 0),
(@PATH, 7, -1821.238, 6901.434, 178.4305, NULL, 0),
(@PATH, 8, -1824.67, 6900.621, 178.6409, NULL, 0),
(@PATH, 9, -1828.194, 6898.692, 178.8451, NULL, 0),
(@PATH, 10, -1830.771, 6896.577, 178.9955, NULL, 0),
(@PATH, 11, -1831.533, 6893.492, 179.3134, NULL, 13609),
(@PATH, 12, -1827.314, 6899.827, 178.7374, NULL, 0),
(@PATH, 13, -1824.389, 6900.85, 178.5756, NULL, 0),
(@PATH, 14, -1821.243, 6901.306, 178.4706, NULL, 0),
(@PATH, 15, -1818.094, 6901.895, 178.982, NULL, 0),
(@PATH, 16, -1816.332, 6901.115, 179.296, NULL, 0),
(@PATH, 17, -1812.873, 6894.17, 180.1825, 4.06389, 12329),
(@PATH, 18, -1806.839, 6893.612, 181.168, NULL, 0),
(@PATH, 19, -1805.363, 6892.005, 181.3353, NULL, 0),
(@PATH, 20, -1803.984, 6887.497, 181.6766, NULL, 0),
(@PATH, 21, -1803.413, 6884.533, 181.901, NULL, 0),
(@PATH, 22, -1802.352, 6882.453, 182.3664, NULL, 0),
(@PATH, 23, -1801.474, 6879.761, 182.9671, NULL, 0),
(@PATH, 24, -1801.012, 6874.972, 183.623, NULL, 0),
(@PATH, 25, -1801.12, 6871.027, 183.719, NULL, 0),
(@PATH, 26, -1802.269, 6867.556, 183.5601, NULL, 12435),
(@PATH, 27, -1799.632, 6875.53, 183.7888, NULL, 0),
(@PATH, 28, -1800.37, 6879.147, 183.3181, NULL, 0),
(@PATH, 29, -1801.372, 6881.885, 182.664, NULL, 0),
(@PATH, 30, -1802.438, 6885.255, 182.0126, NULL, 0),
(@PATH, 31, -1803.58, 6888.558, 181.6622, NULL, 0);

UPDATE `creature` SET `position_x`= -1804.486, `position_y`= 6891.696, `position_z`= 181.4274, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+19;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+19;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+19, @PATH, 1);
