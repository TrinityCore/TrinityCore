SET @SL_CGUID := 1052044;
SET @SL_OGUID := 600252;

SET @DF_CGUID := 9003915;

SET @NPCTEXTID := 580007;

-- Delete old Creatures & Gobs
DELETE FROM `creature` WHERE `guid` IN (314152, 314160, 314157, 314151, 314144, 314143, 314141, 314138, 314140, 314139, 314142, 314146, 314156);
DELETE FROM `creature_addon` WHERE `guid` IN (314152, 314160, 314157, 314151, 314144, 314143, 314141, 314138, 314140, 314139, 314142, 314146, 314156);

DELETE FROM `gameobject` WHERE `guid` IN (220160, 220164, 220163, 220161, 220159, 220158, 220169, 220172, 220171, 220168, 220166, 220167);
DELETE FROM `gameobject_addon` WHERE `guid` IN (220160, 220164, 220163, 220161, 220159, 220158, 220169, 220172, 220171, 220168, 220166, 220167);

-- Move Toren Landow
UPDATE `creature` SET `position_x`= -8759.1806640625, `position_y` = 408.755218505859375, `position_z` = 109.7475051879882812, `orientation`= 3.068455934524536132 WHERE `guid` = 314153;

-- Update wander distance for Darlene Stokx
UPDATE `creature` SET `wander_distance` = 3, `MovementType` = 1 WHERE `guid` = 314179;

-- Creature (Shadowlands)
DELETE FROM `creature` WHERE `guid` BETWEEN @SL_CGUID+0 AND @SL_CGUID+21;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `VerifiedBuild`) VALUES
(@SL_CGUID+0, 62913, 0, 1519, 1519, '0', 0, 0, 0, 0, -8795.25, 354.87847900390625, 107.4149856567382812, 0.746493637561798095, 120, 0, 0, 11791, 2434, 0, 0, 0, 44325), -- Dave the Quick (Area: Stormwind City - Difficulty: 0) (Auras: 79962 - Seal of Righteousness)
(@SL_CGUID+1, 167429, 0, 1519, 1519, '0', 0, 0, 0, 0, -8794.095703125, 344.282989501953125, 107.1326828002929687, 4.643115997314453125, 120, 0, 0, 124, 0, 0, 0, 0, 44325), -- Quartermaster Richter (Area: Stormwind City - Difficulty: 0)
(@SL_CGUID+2, 164952, 0, 1519, 1519, '0', 0, 0, 0, 1, -8799.783203125, 347.96875, 109.389678955078125, 3.256366252899169921, 120, 0, 0, 15918, 0, 0, 0, 0, 44325), -- Ezul'aan (Area: Stormwind City - Difficulty: 0)
(@SL_CGUID+3, 164949, 0, 1519, 1519, '0', 0, 0, 0, 1, -8803.3125, 352.62152099609375, 109.2404327392578125, 4.428950786590576171, 120, 0, 0, 15918, 0, 0, 0, 0, 44325), -- Patrice Lancaster (Area: Stormwind City - Difficulty: 0)
(@SL_CGUID+4, 164943, 0, 1519, 1519, '0', 0, 0, 0, 1, -8812.9912109375, 354.923614501953125, 107.13250732421875, 3.992741584777832031, 120, 0, 0, 15918, 0, 0, 0, 0, 44325), -- Remaari (Area: Stormwind City - Difficulty: 0)
(@SL_CGUID+5, 164945, 0, 1519, 1519, '0', 0, 0, 0, 1, -8816.9150390625, 355.164947509765625, 107.132537841796875, 5.334682464599609375, 120, 0, 0, 15918, 0, 0, 0, 0, 44325), -- Mulric Boldrock (Area: Stormwind City - Difficulty: 0)
(@SL_CGUID+6, 164960, 0, 1519, 1519, '0', 0, 0, 0, 1, -8823.1025390625, 348.01910400390625, 107.1320724487304687, 5.972125053405761718, 120, 0, 0, 15918, 0, 0, 0, 0, 44325), -- Dalgrun Steelpine (Area: Stormwind City - Difficulty: 0)
(@SL_CGUID+7, 164957, 0, 1519, 1519, '0', 0, 0, 0, 1, -8824.6923828125, 342.486114501953125, 107.1317291259765625, 0.387711524963378906, 120, 0, 0, 15918, 0, 0, 0, 0, 44325), -- Camille Taylor (Area: Stormwind City - Difficulty: 0)
(@SL_CGUID+8, 164940, 0, 1519, 1519, '0', 0, 0, 0, 1, -8814.6806640625, 332.645843505859375, 107.1317596435546875, 0, 120, 0, 0, 15918, 0, 0, 0, 0, 44325), -- Kualiang Thunderfist (Area: Stormwind City - Difficulty: 0)
(@SL_CGUID+9, 164939, 0, 1519, 1519, '0', 0, 0, 0, 1, -8811.2451171875, 328.1319580078125, 107.1343994140625, 1.215926408767700195, 120, 0, 0, 15918, 0, 0, 0, 0, 44325), -- Signilda Hardforge (Area: Stormwind City - Difficulty: 0)
(@SL_CGUID+10, 164948, 0, 1519, 1519, '0', 0, 0, 0, 1, -8811.16015625, 336.435760498046875, 107.1321563720703125, 1.318002700805664062, 120, 0, 0, 15918, 0, 0, 0, 0, 44325), -- Elton Campbell (Area: Stormwind City - Difficulty: 0)
(@SL_CGUID+11, 164950, 0, 1519, 1519, '0', 0, 0, 0, 1, -8810.046875, 342.36285400390625, 107.13226318359375, 3.842902421951293945, 120, 0, 0, 15918, 0, 0, 0, 0, 44325), -- Gilda Silvershield (Area: Stormwind City - Difficulty: 0)
(@SL_CGUID+12, 164953, 0, 1519, 1519, '0', 0, 0, 0, 1, -8814.5693359375, 340.670135498046875, 107.1315231323242187, 0.521877288818359375, 120, 0, 0, 15918, 0, 0, 0, 0, 44325), -- Katrina Long (Area: Stormwind City - Difficulty: 0)
(@SL_CGUID+13, 164954, 0, 1519, 1519, '0', 0, 0, 0, 0, -8807.138671875, 326.673614501953125, 115.5490188598632812, 2.135253190994262695, 120, 0, 0, 15918, 0, 0, 0, 0, 44325), -- Juisheng Halfclaw (Area: Stormwind City - Difficulty: 0) (Auras: 121801 - Meditate)
(@SL_CGUID+14, 164955, 0, 1519, 1519, '0', 0, 0, 0, 1, -8801.2705078125, 330.185760498046875, 115.5490188598632812, 1.768537640571594238, 120, 0, 0, 15918, 0, 0, 0, 0, 44325), -- Frazzle Frostfingers (Area: Stormwind City - Difficulty: 0)
(@SL_CGUID+15, 164956, 0, 1519, 1519, '0', 0, 0, 0, 1, -8797.7470703125, 333.3507080078125, 115.5490188598632812, 2.937933206558227539, 120, 0, 0, 15918, 0, 0, 0, 0, 44325), -- Azunla (Area: Stormwind City - Difficulty: 0)
(@SL_CGUID+16, 164961, 0, 1519, 1519, '0', 0, 0, 0, 1, -8788.0693359375, 340.927093505859375, 117.7182769775390625, 0.020769992843270301, 120, 0, 0, 15918, 0, 0, 0, 0, 44325), -- Amaria Wildthorn (Area: Stormwind City - Difficulty: 0)
(@SL_CGUID+17, 164962, 0, 1519, 1519, '0', 0, 0, 0, 1, -8791.47265625, 346.81597900390625, 117.718292236328125, 4.396882057189941406, 120, 0, 0, 15918, 0, 0, 0, 0, 44325), -- Mithlos Falconbriar (Area: Stormwind City - Difficulty: 0)
(@SL_CGUID+18, 164947, 0, 1519, 1519, '0', 0, 0, 0, 1, -8817.4755859375, 352.6475830078125, 99.46265411376953125, 6.086604595184326171, 120, 0, 0, 15918, 0, 0, 0, 0, 44325), -- Gerald Black (Area: Stormwind City - Difficulty: 0)
(@SL_CGUID+19, 164941, 0, 1519, 1519, '0', 0, 0, 0, 1, -8802.216796875, 350.62847900390625, 99.46265411376953125, 4.679291248321533203, 120, 0, 0, 15918, 0, 0, 0, 0, 44325), -- Laphandrus Voidheart (Area: Stormwind City - Difficulty: 0)
(@SL_CGUID+20, 164946, 0, 1519, 1519, '0', 0, 0, 0, 1, -8815.5849609375, 358.48089599609375, 99.46265411376953125, 5.414020061492919921, 120, 0, 0, 15918, 0, 0, 0, 0, 44325), -- Veruca Darkstream (Area: Stormwind City - Difficulty: 0)
(@SL_CGUID+21, 164942, 0, 1519, 1519, '0', 0, 0, 0, 1, -8805.2783203125, 340.82464599609375, 99.46265411376953125, 1.271134257316589355, 120, 0, 0, 15918, 0, 0, 0, 0, 44325); -- Evelyn Thorn (Area: Stormwind City - Difficulty: 0)

-- Creature (Dragonflight)
DELETE FROM `creature` WHERE `guid` = @DF_CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `VerifiedBuild`) VALUES
(@DF_CGUID+0, 199145, 0, 1519, 1519, '0', 0, 0, 0, 0, -8805.9345703125, 356.805572509765625, 99.46265411376953125, 2.793352365493774414, 120, 0, 0, 112919, 100, 0, 0, 0, 50000); -- R'mortos the Shining Shadow (Area: Stormwind City - Difficulty: 0) CreateObject1

-- GameObjects (Shadowlands)
DELETE FROM `gameobject` WHERE `guid` BETWEEN @SL_OGUID+0 AND @SL_OGUID+29;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@SL_OGUID+0, 364438, 0, 1519, 1519, '0', 0, 0, -8789.5517578125, 337.802276611328125, 99.42002105712890625, 5.395825862884521484, 0, 0, -0.42926597595214843, 0.903178095817565917, 120, 255, 1, 44325), -- Chair (Area: Stormwind City - Difficulty: 0)
(@SL_OGUID+1, 364434, 0, 1519, 1519, '0', 0, 0, -8795.873046875, 343.62530517578125, 107.0102310180664062, 5.465639114379882812, 0, 0, -0.39748382568359375, 0.917609214782714843, 120, 255, 1, 44325), -- Chair (Area: Stormwind City - Difficulty: 0)
(@SL_OGUID+2, 364428, 0, 1519, 1519, '0', 0, 0, -8811.1455078125, 342.96923828125, 107.03509521484375, 3.850003004074096679, 0, 0, -0.93792247772216796, 0.346844971179962158, 120, 255, 1, 44325), -- Chair (Area: Stormwind City - Difficulty: 0)
(@SL_OGUID+3, 364439, 0, 1519, 1519, '0', 0, 0, -8789.8203125, 335.951568603515625, 99.42002105712890625, 5.395825862884521484, 0, 0, -0.42926597595214843, 0.903178095817565917, 120, 255, 1, 44325), -- Chair (Area: Stormwind City - Difficulty: 0)
(@SL_OGUID+4, 364435, 0, 1519, 1519, '0', 0, 0, -8814.8095703125, 341.74603271484375, 107.0408706665039062, 0.540074884891510009, 0, 0, 0.266767501831054687, 0.963760912418365478, 120, 255, 1, 44325), -- Chair (Area: Stormwind City - Difficulty: 0)
(@SL_OGUID+5, 364429, 0, 1519, 1519, '0', 0, 0, -8809.6513671875, 358.623992919921875, 99.36663818359375, 0.290735781192779541, 0, 0, 0.144856452941894531, 0.989452660083770751, 120, 255, 1, 44325), -- Chair (Area: Stormwind City - Difficulty: 0)
(@SL_OGUID+6, 351981, 0, 1519, 1519, '0', 0, 0, -8788.36328125, 338.57269287109375, 117.6347579956054687, 5.430732250213623046, 0, 0, -0.4134378433227539, 0.910532355308532714, 120, 255, 1, 44325), -- Chair (Area: Stormwind City - Difficulty: 0)
(@SL_OGUID+7, 364436, 0, 1519, 1519, '0', 0, 0, -8787.6220703125, 342.72552490234375, 117.607208251953125, 5.395825862884521484, 0, 0, -0.42926597595214843, 0.903178095817565917, 120, 255, 1, 44325), -- Chair (Area: Stormwind City - Difficulty: 0)
(@SL_OGUID+8, 364430, 0, 1519, 1519, '0', 0, 0, -8811.8837890625, 337.86859130859375, 107.03509521484375, 0.718342781066894531, 0, 0, 0.351498603820800781, 0.936188399791717529, 120, 255, 1, 44325), -- Chair (Area: Stormwind City - Difficulty: 0)
(@SL_OGUID+9, 364432, 0, 1519, 1519, '0', 0, 0, -8812.951171875, 339.11065673828125, 107.03509521484375, 0.604896485805511474, 0, 0, 0.297858238220214843, 0.954610109329223632, 120, 255, 1, 44325), -- Chair (Area: Stormwind City - Difficulty: 0)
(@SL_OGUID+10, 364426, 0, 1519, 1519, '0', 0, 0, -8811.982421875, 344.3277587890625, 107.03509521484375, 4.086831569671630859, 0, 0, -0.89037895202636718, 0.455220073461532592, 120, 255, 1, 44325), -- Chair (Area: Stormwind City - Difficulty: 0)
(@SL_OGUID+11, 364437, 0, 1519, 1519, '0', 0, 0, -8808.6552734375, 342.11676025390625, 99.4849853515625, 0.064361229538917541, 0, 0, 0.032175064086914062, 0.999482274055480957, 120, 255, 1, 44325), -- Chair (Area: Stormwind City - Difficulty: 0)
(@SL_OGUID+12, 364431, 0, 1519, 1519, '0', 0, 0, -8809.6708984375, 341.18939208984375, 107.03509521484375, 3.868662834167480468, 0, 0, -0.93464565277099609, 0.355580478906631469, 120, 255, 1, 44325), -- Chair (Area: Stormwind City - Difficulty: 0)
(@SL_OGUID+13, 364433, 0, 1519, 1519, '0', 0, 0, -8808.431640625, 340.02349853515625, 107.03509521484375, 3.868662834167480468, 0, 0, -0.93464565277099609, 0.355580478906631469, 120, 255, 1, 44325), -- Chair (Area: Stormwind City - Difficulty: 0)
(@SL_OGUID+14, 364427, 0, 1519, 1519, '0', 0, 0, -8788.671875, 344.984161376953125, 117.574737548828125, 5.395825862884521484, 0, 0, -0.42926597595214843, 0.903178095817565917, 120, 255, 1, 44325), -- Chair (Area: Stormwind City - Difficulty: 0)
(@SL_OGUID+15, 364439, 0, 1519, 1519, '0', 0, 0, -8789.8203125, 335.951568603515625, 99.42002105712890625, 5.395825862884521484, 0, 0, -0.42926597595214843, 0.903178095817565917, 120, 255, 1, 44325), -- Chair (Area: Stormwind City - Difficulty: 0)
(@SL_OGUID+16, 364435, 0, 1519, 1519, '0', 0, 0, -8814.8095703125, 341.74603271484375, 107.0408706665039062, 0.540074884891510009, 0, 0, 0.266767501831054687, 0.963760912418365478, 120, 255, 1, 44325), -- Chair (Area: Stormwind City - Difficulty: 0)
(@SL_OGUID+17, 364429, 0, 1519, 1519, '0', 0, 0, -8809.6513671875, 358.623992919921875, 99.36663818359375, 0.290735781192779541, 0, 0, 0.144856452941894531, 0.989452660083770751, 120, 255, 1, 44325), -- Chair (Area: Stormwind City - Difficulty: 0)
(@SL_OGUID+18, 351981, 0, 1519, 1519, '0', 0, 0, -8788.36328125, 338.57269287109375, 117.6347579956054687, 5.430732250213623046, 0, 0, -0.4134378433227539, 0.910532355308532714, 120, 255, 1, 44325), -- Chair (Area: Stormwind City - Difficulty: 0)
(@SL_OGUID+19, 364436, 0, 1519, 1519, '0', 0, 0, -8787.6220703125, 342.72552490234375, 117.607208251953125, 5.395825862884521484, 0, 0, -0.42926597595214843, 0.903178095817565917, 120, 255, 1, 44325), -- Chair (Area: Stormwind City - Difficulty: 0)
(@SL_OGUID+20, 364430, 0, 1519, 1519, '0', 0, 0, -8811.8837890625, 337.86859130859375, 107.03509521484375, 0.718342781066894531, 0, 0, 0.351498603820800781, 0.936188399791717529, 120, 255, 1, 44325), -- Chair (Area: Stormwind City - Difficulty: 0)
(@SL_OGUID+21, 364432, 0, 1519, 1519, '0', 0, 0, -8812.951171875, 339.11065673828125, 107.03509521484375, 0.604896485805511474, 0, 0, 0.297858238220214843, 0.954610109329223632, 120, 255, 1, 44325), -- Chair (Area: Stormwind City - Difficulty: 0)
(@SL_OGUID+22, 364426, 0, 1519, 1519, '0', 0, 0, -8811.982421875, 344.3277587890625, 107.03509521484375, 4.086831569671630859, 0, 0, -0.89037895202636718, 0.455220073461532592, 120, 255, 1, 44325), -- Chair (Area: Stormwind City - Difficulty: 0)
(@SL_OGUID+23, 364437, 0, 1519, 1519, '0', 0, 0, -8808.6552734375, 342.11676025390625, 99.4849853515625, 0.064361229538917541, 0, 0, 0.032175064086914062, 0.999482274055480957, 120, 255, 1, 44325), -- Chair (Area: Stormwind City - Difficulty: 0)
(@SL_OGUID+24, 364431, 0, 1519, 1519, '0', 0, 0, -8809.6708984375, 341.18939208984375, 107.03509521484375, 3.868662834167480468, 0, 0, -0.93464565277099609, 0.355580478906631469, 120, 255, 1, 44325), -- Chair (Area: Stormwind City - Difficulty: 0)
(@SL_OGUID+25, 364433, 0, 1519, 1519, '0', 0, 0, -8808.431640625, 340.02349853515625, 107.03509521484375, 3.868662834167480468, 0, 0, -0.93464565277099609, 0.355580478906631469, 120, 255, 1, 44325), -- Chair (Area: Stormwind City - Difficulty: 0)
(@SL_OGUID+26, 364427, 0, 1519, 1519, '0', 0, 0, -8788.671875, 344.984161376953125, 117.574737548828125, 5.395825862884521484, 0, 0, -0.42926597595214843, 0.903178095817565917, 120, 255, 1, 44325), -- Chair (Area: Stormwind City - Difficulty: 0)
(@SL_OGUID+27, 364438, 0, 1519, 1519, '0', 0, 0, -8789.5517578125, 337.802276611328125, 99.42002105712890625, 5.395825862884521484, 0, 0, -0.42926597595214843, 0.903178095817565917, 120, 255, 1, 44325), -- Chair (Area: Stormwind City - Difficulty: 0)
(@SL_OGUID+28, 364434, 0, 1519, 1519, '0', 0, 0, -8795.873046875, 343.62530517578125, 107.0102310180664062, 5.465639114379882812, 0, 0, -0.39748382568359375, 0.917609214782714843, 120, 255, 1, 44325), -- Chair (Area: Stormwind City - Difficulty: 0)
(@SL_OGUID+29, 364428, 0, 1519, 1519, '0', 0, 0, -8811.1455078125, 342.96923828125, 107.03509521484375, 3.850003004074096679, 0, 0, -0.93792247772216796, 0.346844971179962158, 120, 255, 1, 44325); -- Chair (Area: Stormwind City - Difficulty: 0)
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @SL_OGUID+0 AND @SL_OGUID+29;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@SL_OGUID+0, 0, 0, -0.42926600575447082, 0.903178095817565917, 0, 0), -- Chair
(@SL_OGUID+1, 0, 0, -0.42926600575447082, 0.903178095817565917, 0, 0), -- Chair
(@SL_OGUID+2, 0, 0, -0.42926600575447082, 0.903178095817565917, 0, 0), -- Chair
(@SL_OGUID+3, 0, 0, -0.42926600575447082, 0.903178095817565917, 0, 0), -- Chair
(@SL_OGUID+4, 0, 0, -0.42926600575447082, 0.903178095817565917, 0, 0), -- Chair
(@SL_OGUID+5, 0, 0, -0.42926600575447082, 0.903178095817565917, 0, 0), -- Chair
(@SL_OGUID+6, 0, 0, -0.42926600575447082, 0.903178095817565917, 0, 0), -- Chair
(@SL_OGUID+7, 0, 0, -0.42926600575447082, 0.903178095817565917, 0, 0), -- Chair
(@SL_OGUID+8, 0, 0, -0.42926600575447082, 0.903178095817565917, 0, 0), -- Chair
(@SL_OGUID+9, 0, 0, -0.42926600575447082, 0.903178095817565917, 0, 0), -- Chair
(@SL_OGUID+10, 0, 0, -0.42926600575447082, 0.903178095817565917, 0, 0), -- Chair
(@SL_OGUID+11, 0, 0, -0.42926600575447082, 0.903178095817565917, 0, 0), -- Chair
(@SL_OGUID+12, 0, 0, -0.42926600575447082, 0.903178095817565917, 0, 0), -- Chair
(@SL_OGUID+13, 0, 0, -0.42926600575447082, 0.903178095817565917, 0, 0), -- Chair
(@SL_OGUID+14, 0, 0, -0.42926600575447082, 0.903178095817565917, 0, 0), -- Chair
(@SL_OGUID+15, 0, 0, -0.42926600575447082, 0.903178095817565917, 0, 0), -- Chair
(@SL_OGUID+16, 0, 0, -0.42926600575447082, 0.903178095817565917, 0, 0), -- Chair
(@SL_OGUID+17, 0, 0, -0.42926600575447082, 0.903178095817565917, 0, 0), -- Chair
(@SL_OGUID+18, 0, 0, -0.42926600575447082, 0.903178095817565917, 0, 0), -- Chair
(@SL_OGUID+19, 0, 0, -0.42926600575447082, 0.903178095817565917, 0, 0), -- Chair
(@SL_OGUID+20, 0, 0, -0.42926600575447082, 0.903178095817565917, 0, 0), -- Chair
(@SL_OGUID+21, 0, 0, -0.42926600575447082, 0.903178095817565917, 0, 0), -- Chair
(@SL_OGUID+22, 0, 0, -0.42926600575447082, 0.903178095817565917, 0, 0), -- Chair
(@SL_OGUID+23, 0, 0, -0.42926600575447082, 0.903178095817565917, 0, 0), -- Chair
(@SL_OGUID+24, 0, 0, -0.42926600575447082, 0.903178095817565917, 0, 0), -- Chair
(@SL_OGUID+25, 0, 0, -0.42926600575447082, 0.903178095817565917, 0, 0), -- Chair
(@SL_OGUID+26, 0, 0, -0.42926600575447082, 0.903178095817565917, 0, 0), -- Chair
(@SL_OGUID+27, 0, 0, -0.42926600575447082, 0.903178095817565917, 0, 0), -- Chair
(@SL_OGUID+28, 0, 0, -0.42926600575447082, 0.903178095817565917, 0, 0), -- Chair
(@SL_OGUID+29, 0, 0, -0.42926600575447082, 0.903178095817565917, 0, 0); -- Chair

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (62913 /*62913 (Dave the Quick)*/, 146633 /*146633 (Knight-Captain Jessica)*/, 164947 /*164947 (Gerald Black)*/, 164960 /*164960 (Dalgrun Steelpine)*/, 164957 /*164957 (Camille Taylor)*/, 164954 /*164954 (Juisheng Halfclaw) - Meditate*/, 199145 /*R'mortos the Shining Shadow*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(62913, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 62913 (Dave the Quick)
(146633, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 146633 (Knight-Captain Jessica)
(164947, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 164947 (Gerald Black)
(164960, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, ''), -- 164960 (Dalgrun Steelpine)
(164957, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, ''), -- 164957 (Camille Taylor)
(164954, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '121801'), -- 164954 (Juisheng Halfclaw) - Meditate
(199145, 0, 0, 0, 0, 0, 1, 0, 426, 0, 0, 0, 0, ''); -- R'mortos the Shining Shadow

-- GameObject Template Data
DELETE FROM `gameobject_template` WHERE `entry` IN (351981 /*Chair*/, 364437 /*Chair*/, 364433 /*Chair*/, 364429 /*Chair*/, 364438 /*Chair*/, 364434 /*Chair*/, 364430 /*Chair*/, 364426 /*Chair*/, 364439 /*Chair*/, 364435 /*Chair*/, 364431 /*Chair*/, 364432 /*Chair*/, 364428 /*Chair*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(351981, 7, 32512, 'Chair', '', '', '', 0.999998748302459716, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44325), -- Chair
(364437, 7, 62460, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44325), -- Chair
(364433, 7, 15617, 'Chair', '', '', '', 0.999999940395355224, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44325), -- Chair
(364429, 7, 32290, 'Chair', '', '', '', 0.999999940395355224, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44325), -- Chair
(364438, 7, 17820, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44325), -- Chair
(364434, 7, 15618, 'Chair', '', '', '', 1.509765505790710449, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44325), -- Chair
(364430, 7, 15617, 'Chair', '', '', '', 0.999999940395355224, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44325), -- Chair
(364426, 7, 15617, 'Chair', '', '', '', 0.999999821186065673, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44325), -- Chair
(364439, 7, 17820, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44325), -- Chair
(364435, 7, 15617, 'Chair', '', '', '', 0.999999940395355224, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44325), -- Chair
(364431, 7, 15617, 'Chair', '', '', '', 0.999999940395355224, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44325), -- Chair
(364432, 7, 15617, 'Chair', '', '', '', 0.999999940395355224, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44325), -- Chair
(364428, 7, 15617, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44325); -- Chair

-- Quest stuff
DELETE FROM `quest_details` WHERE `ID` IN (27337, 28394, 27344, 28398, 27354);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(27337, 1, 1, 0, 0, 0, 0, 0, 0, 50000), -- A Fitting Weapon
(28394, 1, 0, 0, 0, 0, 0, 0, 0, 50000), -- The Golem Lord's Creations
(27344, 1, 1, 0, 0, 0, 0, 0, 0, 50000), -- A Well-Earned Reward
(28398, 1, 0, 0, 0, 0, 0, 0, 0, 50000), -- The Pyromancer's Grimoire
(27354, 1, 1, 0, 0, 0, 0, 0, 0, 50000); -- Mastering the Arcane

DELETE FROM `quest_request_items` WHERE `ID`=28394;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(28394, 0, 1, 0, 0, 'We cannot afford to allow those golems to be used against us.', 0); -- The Golem Lord's Creations

DELETE FROM `creature_queststarter` WHERE (`id`=164939 AND `quest`=27337) OR (`id`=164960 AND `quest` IN (28394,27344)) OR (`id`=164955 AND `quest` IN (28398,27354));
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(164939, 27337, 50000), -- A Fitting Weapon offered Signilda Hardforge
(164960, 28394, 50000), -- The Golem Lord's Creations offered Dalgrun Steelpine
(164960, 27344, 50000), -- A Well-Earned Reward offered Dalgrun Steelpine
(164955, 28398, 50000), -- The Pyromancer's Grimoire offered Frazzle Frostfingers
(164955, 27354, 50000); -- Mastering the Arcane offered Frazzle Frostfingers

DELETE FROM `creature_questender` WHERE (`id`=164960 AND `quest`=28394) OR (`id`=164955 AND `quest`=28398);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(164960, 28394, 50000), -- The Golem Lord's Creations ended by Dalgrun Steelpine
(164955, 28398, 50000); -- The Pyromancer's Grimoire ended by Frazzle Frostfingers

-- Gossip & Text data
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=164939 AND `MenuID` IN (25121,25345)) OR (`CreatureID`=164960 AND `MenuID`=25113) OR (`CreatureID`=62913 AND `MenuID`=13917);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(164939, 25121, 50000), -- Signilda Hardforge
(164939, 25345, 50000), -- Signilda Hardforge
(164960, 25113, 50000), -- Dalgrun Steelpine
(62913, 13917, 50469); -- Dave the Quick

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+5;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 187315, 0, 0, 0, 0, 0, 0, 0, 50000), -- 164939 (Signilda Hardforge)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 187268, 0, 0, 0, 0, 0, 0, 0, 50000), -- 164939 (Signilda Hardforge)
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 193626, 0, 0, 0, 0, 0, 0, 0, 50000), -- 164939 (Signilda Hardforge)
(@NPCTEXTID+3, 1, 0, 0, 0, 0, 0, 0, 0, 187305, 0, 0, 0, 0, 0, 0, 0, 50000), -- 164960 (Dalgrun Steelpine)
(@NPCTEXTID+4, 1, 0, 0, 0, 0, 0, 0, 0, 187268, 0, 0, 0, 0, 0, 0, 0, 50000), -- 164960 (Dalgrun Steelpine)
(@NPCTEXTID+5, 1, 0, 0, 0, 0, 0, 0, 0, 193630, 0, 0, 0, 0, 0, 0, 0, 50000); -- 164960 (Dalgrun Steelpine)

DELETE FROM `gossip_menu` WHERE `MenuID` IN (25121, 25345, 25113, 25356);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(25121, @NPCTEXTID+0, 50000), -- 164939 (Signilda Hardforge)
(25345, @NPCTEXTID+1, 50000), -- 164939 (Signilda Hardforge)
(25345, @NPCTEXTID+2, 50000), -- 164939 (Signilda Hardforge)
(25113, @NPCTEXTID+3, 50000), -- 164960 (Dalgrun Steelpine)
(25356, @NPCTEXTID+4, 50000), -- 164960 (Dalgrun Steelpine)
(25113, @NPCTEXTID+5, 50000); -- 164960 (Dalgrun Steelpine)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=25345 AND `OptionID`=11) OR (`MenuID`=25356 AND `OptionID`=3);
INSERT INTO `gossip_menu_option` (`GossipOptionID`, `MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `Flags`, `OverrideIconID`, `GossipNpcOptionID`, `VerifiedBuild`) VALUES
(52745, 25345, 11, 0, 'Tell me about my specialization options.', 0, 0, 25121, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 50000),
(52753, 25356, 3, 0, 'Tell me about my specialization options.', 0, 0, 25113, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 50000);

-- Conditions
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` IN (15, 14)) AND (`SourceGroup` IN (25345, 25121, 25113, 25356));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
-- Warrior
(14, 25121, @NPCTEXTID+0, 0, 0, 15, 0, 1, 0, 0, 0, 'Show Gossip 25121 and (@NPCTEXTID+0) if Player is a Warrior'),
(14, 25345, @NPCTEXTID+1, 0, 0, 15, 0, 1, 0, 0, 0, 'Show Gossip 25145 and (@NPCTEXTID+1) if Player is a Warrior'),
(14, 25345, @NPCTEXTID+2, 0, 0, 15, 0, 1, 0, 0, 1, 'Show Gossip 25145 and (@NPCTEXTID+2) if Player is not a Warrior'),
(15, 25345, 11, 0, 0, 15, 0, 1, 0, 0, 0, 'Show Gossip Menu Option 25145 11 if Player is a Warrior'),
-- Hunter
(14, 25356, @NPCTEXTID+3, 0, 0, 15, 0, 3, 0, 0, 0, 'Show Gossip 25356 and (@NPCTEXTID+3) if Player is a Hunter'),
(14, 25356, @NPCTEXTID+4, 0, 0, 15, 0, 3, 0, 0, 0, 'Show Gossip 25356 and (@NPCTEXTID+4) if Player is a Hunter'),
(14, 25113, @NPCTEXTID+5, 0, 0, 15, 0, 3, 0, 0, 1, 'Show Gossip 25113 and (@NPCTEXTID+5) if Player is not a Hunter'),
(15, 25356, 3, 0, 0, 15, 0, 1, 0, 0, 0, 'Show Gossip Menu Option 25356 3 if Player is a Hunter');

-- Vendor Data
DELETE FROM `npc_vendor` WHERE (`entry`=164947 AND `item`=130329 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=164947 AND `item`=130323 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=164947 AND `item`=130325 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=164947 AND `item`=130258 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=164947 AND `item`=131729 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=164947 AND `item`=7676 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=167429 AND `item`=175173 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=167429 AND `item`=175172 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=167429 AND `item`=175170 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=167429 AND `item`=175166 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=167429 AND `item`=175167 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=167429 AND `item`=175168 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=167429 AND `item`=175162 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(164947, 6, 130329, 0, 0, 1, 0, 0, 49890), -- Gloves of Artful Dodging
(164947, 5, 130323, 0, 0, 1, 0, 0, 49890), -- Vest of Artful Dodging
(164947, 4, 130325, 0, 0, 1, 0, 0, 49890), -- Shoulder of Artful Dodging
(164947, 3, 130258, 0, 0, 1, 0, 0, 49890), -- Pocket Friend
(164947, 2, 131729, 0, 0, 1, 0, 0, 49890), -- Zanzil's Slow Poison
(164947, 1, 7676, 0, 0, 1, 0, 0, 49890), -- Thistle Tea
(167429, 13, 175173, 0, 0, 1, 0, 0, 49890), -- Expeditionary Cudgel
(167429, 12, 175172, 0, 0, 1, 0, 0, 49890), -- Expeditionary Dagger
(167429, 10, 175170, 0, 0, 1, 0, 0, 49890), -- Expeditionary Short Sword
(167429, 7, 175166, 0, 0, 1, 0, 0, 49890), -- Expeditionary Greatsword
(167429, 5, 175167, 0, 0, 1, 0, 0, 49890), -- Expeditionary Staff
(167429, 3, 175168, 0, 0, 1, 0, 0, 49890), -- Expeditionary Quarterstaff
(167429, 1, 175162, 0, 0, 1, 0, 0, 49890); -- Expeditionary Longbow
