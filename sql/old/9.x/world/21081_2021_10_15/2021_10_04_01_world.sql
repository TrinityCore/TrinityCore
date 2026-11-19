SET @CGUID := 650070;
SET @OGUID := 400061;

-- creatrue spawns + addon
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+61;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 130993, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 463.76214599609375, 1452.3004150390625, 757.6563720703125, 3.580926895141601562, 7200, 0, 0, 117910, 24340, 0, 0, 0, 0, 40120), -- Captain Fareeya (Area: -Unknown- - Difficulty: 0)
(@CGUID+1, 132215, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 412.4757080078125, 1445.8021240234375, 742.0906982421875, 6.152740001678466796, 7200, 0, 0, 35373, 2434, 0, 0, 0, 0, 40120), -- Lightforged Vindicator (Area: -Unknown- - Difficulty: 0)
(@CGUID+2, 132262, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 453.930572509765625, 1468.77783203125, 757.53436279296875, 4.978931903839111328, 7200, 0, 0, 58955, 24340, 0, 0, 0, 0, 40120), -- Lightforged Protector (Area: -Unknown- - Difficulty: 0) (Auras: 79968 - Blessing of Kings)
(@CGUID+3, 132323, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 402.961822509765625, 1470.2239990234375, 773.267578125, 6.024432659149169921, 7200, 0, 0, 11791, 0, 0, 0, 0, 0, 40120), -- Yalia (Area: -Unknown- - Difficulty: 0)
(@CGUID+4, 123395, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 401.232635498046875, 1450.111083984375, 772.73828125, 5.916550159454345703, 7200, 0, 0, 1456, 1534, 0, 0, 0, 0, 40120), -- High Priestess Ishanah (Area: -Unknown- - Difficulty: 0)
(@CGUID+5, 132334, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 514.09027099609375, 1466.1649169921875, 765.88055419921875, 5.33148050308227539, 7200, 0, 0, 35373, 0, 0, 0, 0, 0, 40120), -- Grand Artificer Romuul (Area: -Unknown- - Difficulty: 0)
(@CGUID+6, 132215, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 449.546875, 1390.829833984375, 772.73822021484375, 0.790043234825134277, 7200, 0, 0, 35373, 2434, 0, 0, 0, 0, 40120), -- Lightforged Vindicator (Area: -Unknown- - Difficulty: 0)
(@CGUID+7, 114590, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 400.505218505859375, 1430.263916015625, 745.0450439453125, 0, 7200, 0, 0, 11791, 0, 0, 0, 0, 0, 40120), -- Generic Bunny (Area: -Unknown- - Difficulty: 0)
(@CGUID+8, 132224, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 400.017364501953125, 1473.9757080078125, 742.05755615234375, 2.548465728759765625, 7200, 0, 0, 11791, 0, 0, 0, 0, 0, 40120), -- Durael (Area: -Unknown- - Difficulty: 0)
(@CGUID+9, 132266, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 499.46527099609375, 1459.7742919921875, 766.04296875, 2.432829141616821289, 7200, 0, 0, 58955, 24340, 0, 0, 0, 0, 40120), -- Lightforged Protector (Area: -Unknown- - Difficulty: 0) (Auras: 79968 - Blessing of Kings)
(@CGUID+10, 132328, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 501.348968505859375, 1439.2274169921875, 757.1728515625, 1.927380919456481933, 7200, 0, 0, 58955, 24340, 0, 0, 0, 0, 40120), -- Lightforged Bulwark (Area: -Unknown- - Difficulty: 0)
(@CGUID+11, 132214, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 458.697906494140625, 1495.8958740234375, 742.05755615234375, 5.855896949768066406, 7200, 0, 0, 11791, 9736, 0, 0, 0, 0, 40120), -- Lightforged Anchorite (Area: -Unknown- - Difficulty: 0)
(@CGUID+12, 132215, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 471.477447509765625, 1409.045166015625, 764.34619140625, 0.43889319896697998, 7200, 0, 0, 35373, 2434, 0, 0, 0, 0, 40120), -- Lightforged Vindicator (Area: -Unknown- - Difficulty: 0)
(@CGUID+13, 132262, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 475.171875, 1439.329833984375, 757.53436279296875, 2.426834821701049804, 7200, 0, 0, 58955, 24340, 0, 0, 0, 0, 40120), -- Lightforged Protector (Area: -Unknown- - Difficulty: 0) (Auras: 79968 - Blessing of Kings)
(@CGUID+14, 132215, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 421.729156494140625, 1399.5069580078125, 772.7384033203125, 1.936838746070861816, 7200, 0, 0, 35373, 2434, 0, 0, 0, 0, 40120), -- Lightforged Vindicator (Area: -Unknown- - Difficulty: 0) (Auras: 260861 - -Unknown-)
(@CGUID+15, 132215, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 425.3350830078125, 1412.5191650390625, 772.77972412109375, 2.104905605316162109, 7200, 0, 0, 35373, 2434, 0, 0, 0, 0, 40120), -- Lightforged Vindicator (Area: -Unknown- - Difficulty: 0)
(@CGUID+16, 96507, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 400.411468505859375, 1459.6163330078125, 772.869873046875, 5.853755950927734375, 7200, 0, 0, 3236, 0, 0, 0, 0, 0, 40120), -- Tassia Whisperglen (Area: -Unknown- - Difficulty: 0)
(@CGUID+17, 126030, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 407.739593505859375, 1488.7257080078125, 772.73828125, 0.137238010764122009, 7200, 0, 0, 1456, 6136, 0, 0, 0, 0, 40120), -- Lightsworn Anchorite (Area: -Unknown- - Difficulty: 0) (Auras: 237554 - Mod Scale -25%, 240226 - Read)
(@CGUID+18, 132225, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 450.708343505859375, 1452.9322509765625, 741.0560302734375, 1.025328755378723144, 7200, 0, 0, 11791, 0, 0, 0, 0, 0, 40120), -- Lightforged Artificer (Area: -Unknown- - Difficulty: 0)
(@CGUID+19, 132266, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 447.821197509765625, 1466.16845703125, 757.53436279296875, 5.30818939208984375, 7200, 0, 0, 58955, 24340, 0, 0, 0, 0, 40120), -- Lightforged Protector (Area: -Unknown- - Difficulty: 0) (Auras: 79968 - Blessing of Kings)
(@CGUID+20, 132214, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 468.720489501953125, 1398.420166015625, 772.715087890625, 0.853685319423675537, 7200, 0, 0, 11791, 9736, 2, 0, 0, 0, 40120), -- Lightforged Anchorite (Area: -Unknown- - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+21, 132215, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 417.572906494140625, 1402.9410400390625, 772.7398681640625, 5.88143157958984375, 7200, 0, 0, 35373, 2434, 0, 0, 0, 0, 40120), -- Lightforged Vindicator (Area: -Unknown- - Difficulty: 0) (Auras: 260861 - -Unknown-)
(@CGUID+22, 130560, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 419.357635498046875, 1478.951416015625, 741.9805908203125, 4.082100868225097656, 7200, 0, 0, 11791, 0, 0, 0, 0, 0, 40120), -- Maras (Area: -Unknown- - Difficulty: 0)
(@CGUID+23, 126022, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 473.36285400390625, 1388.5069580078125, 772.736328125, 1.595954656600952148, 7200, 0, 0, 1456, 1534, 0, 0, 0, 0, 40120), -- Anchorite Lysara (Area: -Unknown- - Difficulty: 0)
(@CGUID+24, 132215, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 446.970489501953125, 1450.7100830078125, 757.6558837890625, 0.353923439979553222, 7200, 0, 0, 35373, 2434, 0, 1, 0, 0, 40120), -- Lightforged Vindicator (Area: -Unknown- - Difficulty: 0)
(@CGUID+25, 132262, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 464.119781494140625, 1431.342041015625, 757.53436279296875, 1.835720300674438476, 7200, 0, 0, 58955, 24340, 0, 0, 0, 0, 40120), -- Lightforged Protector (Area: -Unknown- - Difficulty: 0) (Auras: 79968 - Blessing of Kings)
(@CGUID+26, 132328, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 423.73785400390625, 1502.6978759765625, 772.73822021484375, 3.16117405891418457, 7200, 0, 0, 58955, 24340, 2, 0, 0, 0, 40120), -- Lightforged Bulwark (Area: -Unknown- - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+27, 114590, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 406.71527099609375, 1417.32470703125, 745.19354248046875, 0, 7200, 0, 0, 11791, 0, 0, 0, 0, 0, 40120), -- Generic Bunny (Area: -Unknown- - Difficulty: 0)
(@CGUID+28, 126389, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 410.567718505859375, 1423.107666015625, 741.835693359375, 0.693184614181518554, 7200, 0, 0, 1456, 0, 0, 0, 0, 0, 40120), -- Artificer Shela'na (Area: -Unknown- - Difficulty: 0)
(@CGUID+29, 132215, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 406.114593505859375, 1418.4305419921875, 772.97607421875, 0.630915641784667968, 7200, 0, 0, 35373, 2434, 0, 0, 0, 0, 40120), -- Lightforged Vindicator (Area: -Unknown- - Difficulty: 0)
(@CGUID+30, 132266, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 470.317718505859375, 1434.3541259765625, 757.53436279296875, 2.293528079986572265, 7200, 0, 0, 58955, 24340, 0, 0, 0, 0, 40120), -- Lightforged Protector (Area: -Unknown- - Difficulty: 0) (Auras: 79968 - Blessing of Kings)
(@CGUID+31, 130986, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 441.727447509765625, 1388.3819580078125, 742.0577392578125, 1.234178662300109863, 7200, 0, 0, 82537, 0, 0, 0, 0, 0, 40120), -- Vigilant Quoram (Area: -Unknown- - Difficulty: 0)
(@CGUID+32, 132215, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 461.232635498046875, 1495.3160400390625, 742.05755615234375, 3.130662918090820312, 7200, 0, 0, 35373, 2434, 0, 0, 0, 0, 40120), -- Lightforged Vindicator (Area: -Unknown- - Difficulty: 0)
(@CGUID+33, 132215, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 470.5382080078125, 1412.1146240234375, 764.50634765625, 0.361256211996078491, 7200, 0, 0, 35373, 2434, 0, 0, 0, 0, 40120), -- Lightforged Vindicator (Area: -Unknown- - Difficulty: 0)
(@CGUID+34, 132262, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 492.21527099609375, 1475.203125, 766.04412841796875, 4.566351890563964843, 7200, 0, 0, 58955, 24340, 0, 0, 0, 0, 40120), -- Lightforged Protector (Area: -Unknown- - Difficulty: 0) (Auras: 79968 - Blessing of Kings)
(@CGUID+35, 132328, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 499.682281494140625, 1441.5572509765625, 757.1708984375, 5.122677326202392578, 7200, 0, 0, 58955, 24340, 0, 0, 0, 0, 40120), -- Lightforged Bulwark (Area: -Unknown- - Difficulty: 0)
(@CGUID+36, 132358, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 405.383697509765625, 1481.8541259765625, 742.0577392578125, 2.217966794967651367, 7200, 0, 0, 11791, 0, 0, 0, 0, 0, 40120), -- Enstraa (Area: -Unknown- - Difficulty: 0)
(@CGUID+37, 132225, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 487.984375, 1449.9461669921875, 742.0576171875, 2.175845623016357421, 7200, 0, 0, 11791, 0, 0, 0, 0, 0, 40120), -- Lightforged Artificer (Area: -Unknown- - Difficulty: 0)
(@CGUID+38, 132266, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 387.743072509765625, 1423.5728759765625, 769.68865966796875, 3.993125438690185546, 7200, 0, 0, 58955, 24340, 0, 0, 0, 0, 40120), -- Lightforged Protector (Area: -Unknown- - Difficulty: 0) (Auras: 79968 - Blessing of Kings)
(@CGUID+39, 126075, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 440.055572509765625, 1395.6875, 773.2657470703125, 1.242475390434265136, 7200, 0, 0, 1456, 0, 0, 0, 0, 0, 40120), -- A'naa (Area: -Unknown- - Difficulty: 0)
(@CGUID+40, 132214, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 486.2413330078125, 1451.2586669921875, 742.0576171875, 5.524411201477050781, 7200, 0, 0, 11791, 9736, 0, 0, 0, 0, 40120), -- Lightforged Anchorite (Area: -Unknown- - Difficulty: 0)
(@CGUID+41, 132215, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 426.37847900390625, 1416.3160400390625, 742.0906982421875, 1.025040030479431152, 7200, 0, 0, 35373, 2434, 0, 0, 0, 0, 40120), -- Lightforged Vindicator (Area: -Unknown- - Difficulty: 0)
(@CGUID+42, 125524, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 453.9375, 1414.282958984375, 742.05755615234375, 4.930695533752441406, 7200, 0, 0, 1456, 6136, 0, 0, 0, 0, 40120), -- Lightsworn Anchorite (Area: -Unknown- - Difficulty: 0) (Auras: 237554 - Mod Scale -25%)
(@CGUID+43, 132215, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 438.352447509765625, 1508.420166015625, 772.73809814453125, 2.828768253326416015, 7200, 0, 0, 35373, 2434, 0, 0, 0, 0, 40120), -- Lightforged Vindicator (Area: -Unknown- - Difficulty: 0)
(@CGUID+44, 132266, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 460.326385498046875, 1469.4478759765625, 757.53436279296875, 4.65492105484008789, 7200, 0, 0, 58955, 24340, 0, 0, 0, 0, 40120), -- Lightforged Protector (Area: -Unknown- - Difficulty: 0) (Auras: 79968 - Blessing of Kings)
(@CGUID+45, 132215, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 434.880218505859375, 1507.62158203125, 772.7381591796875, 0.062875635921955108, 7200, 0, 0, 35373, 2434, 0, 0, 0, 0, 40120), -- Lightforged Vindicator (Area: -Unknown- - Difficulty: 0)
(@CGUID+46, 132325, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 406.385406494140625, 1466.861083984375, 742.0577392578125, 0.847385883331298828, 7200, 0, 0, 11791, 0, 0, 0, 0, 0, 40120), -- Jarus (Area: -Unknown- - Difficulty: 0)
(@CGUID+47, 125524, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 455.48785400390625, 1412.189208984375, 742.05755615234375, 2.391975164413452148, 7200, 0, 0, 1456, 6136, 0, 0, 0, 0, 40120), -- Lightsworn Anchorite (Area: -Unknown- - Difficulty: 0) (Auras: 237554 - Mod Scale -25%)
(@CGUID+48, 132215, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 435.052093505859375, 1419.71875, 742.05755615234375, 2.283060073852539062, 7200, 0, 0, 35373, 2434, 0, 0, 0, 0, 40120), -- Lightforged Vindicator (Area: -Unknown- - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+49, 132214, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 432.697906494140625, 1416.8333740234375, 742.07305908203125, 1.956531167030334472, 7200, 0, 0, 11791, 9736, 0, 0, 0, 0, 40120), -- Lightforged Anchorite (Area: -Unknown- - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+50, 125843, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 458.5538330078125, 1435.16845703125, 741.5250244140625, 2.386775016784667968, 7200, 0, 0, 1456, 0, 0, 0, 0, 0, 40120), -- Exodar Artificer (Area: -Unknown- - Difficulty: 0)
(@CGUID+51, 132214, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 418.541656494140625, 1482.03125, 772.72589111328125, 1.48262488842010498, 7200, 0, 0, 11791, 9736, 0, 0, 0, 0, 40120), -- Lightforged Anchorite (Area: -Unknown- - Difficulty: 0)
(@CGUID+52, 125524, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 427.9132080078125, 1412.0035400390625, 772.73809814453125, 1.935839176177978515, 7200, 0, 0, 1456, 6136, 0, 0, 0, 0, 40120), -- Lightsworn Anchorite (Area: -Unknown- - Difficulty: 0) (Auras: 237554 - Mod Scale -25%)
(@CGUID+53, 132215, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 451.727447509765625, 1440.1649169921875, 757.6558837890625, 0.537459969520568847, 7200, 0, 0, 35373, 2434, 0, 1, 0, 0, 40120), -- Lightforged Vindicator (Area: -Unknown- - Difficulty: 0)
(@CGUID+54, 132214, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 456.564239501953125, 1436.0850830078125, 741.5250244140625, 5.735340595245361328, 7200, 0, 0, 11791, 9736, 0, 0, 0, 0, 40120), -- Lightforged Anchorite (Area: -Unknown- - Difficulty: 0)
(@CGUID+55, 132262, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 393.49652099609375, 1411.4757080078125, 769.6885986328125, 2.775591135025024414, 7200, 0, 0, 58955, 24340, 0, 0, 0, 0, 40120), -- Lightforged Protector (Area: -Unknown- - Difficulty: 0) (Auras: 79968 - Blessing of Kings)
(@CGUID+56, 125524, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 427.442718505859375, 1414.5694580078125, 772.77691650390625, 4.600401878356933593, 7200, 0, 0, 1456, 6136, 0, 0, 0, 0, 40120), -- Lightsworn Anchorite (Area: -Unknown- - Difficulty: 0) (Auras: 237554 - Mod Scale -25%)
(@CGUID+57, 132214, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 418.85589599609375, 1484.7430419921875, 772.7310791015625, 4.209278583526611328, 7200, 0, 0, 11791, 9736, 0, 0, 0, 0, 40120), -- Lightforged Anchorite (Area: -Unknown- - Difficulty: 0)
(@CGUID+58, 132215, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 401.232635498046875, 1428.829833984375, 772.97607421875, 0.261928290128707885, 7200, 0, 0, 35373, 2434, 0, 0, 0, 0, 40120), -- Lightforged Vindicator (Area: -Unknown- - Difficulty: 0)
(@CGUID+59, 126390, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 496.010406494140625, 1475.40283203125, 742.67413330078125, 4.389081954956054687, 7200, 0, 0, 1456, 0, 0, 0, 0, 0, 40120), -- Thelbus Wimblenod (Area: -Unknown- - Difficulty: 0) (Auras: 250840 - -Unknown-)
(@CGUID+60, 132210, 1860, 9359, 9359, '0', '10260', 0, 0, 0, 380, 1412.359375, 769.6326904296875, 0.384114116430282592, 7200, 10, 0, 235820, 0, 1, 0, 0, 0, 40120), -- T'paartos (Area: -Unknown- - Difficulty: 0) (Auras: 246141 - -Unknown-) (possible waypoints or random movement)
(@CGUID+61, 130993, 1860, 9359, 9359, '0', '9949', 0, 0, 0, 502.442718505859375, 1470.8004150390625, 765.88055419921875, 3.580926895141601562, 7200, 0, 0, 117910, 24340, 0, 0, 0, 0, 40120); -- Captain Fareeya (Area: -Unknown- - Difficulty: 0)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+61;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Captain Fareeya
(@CGUID+1, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Lightforged Vindicator
(@CGUID+2, 0, 0, 0, 1, 0, 12976, 0, 0, '79968'), -- Lightforged Protector - 79968 - Blessing of Kings
(@CGUID+3, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Yalia
(@CGUID+4, 0, 0, 0, 256, 0, 0, 0, 0, ''), -- High Priestess Ishanah
(@CGUID+5, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Grand Artificer Romuul
(@CGUID+6, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Lightforged Vindicator
(@CGUID+7, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Generic Bunny
(@CGUID+8, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Durael
(@CGUID+9, 0, 0, 0, 1, 0, 14737, 0, 0, '79968'), -- Lightforged Protector - 79968 - Blessing of Kings
(@CGUID+10, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Lightforged Bulwark
(@CGUID+11, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Lightforged Anchorite
(@CGUID+12, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Lightforged Vindicator
(@CGUID+13, 0, 0, 0, 1, 0, 12976, 0, 0, '79968'), -- Lightforged Protector - 79968 - Blessing of Kings
(@CGUID+14, 0, 0, 1, 1, 0, 0, 0, 0, '260861'), -- Lightforged Vindicator - 260861 - -Unknown-
(@CGUID+15, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Lightforged Vindicator
(@CGUID+16, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Tassia Whisperglen
(@CGUID+17, 0, 0, 0, 0, 0, 0, 0, 0, '237554 240226'), -- Lightsworn Anchorite - 237554 - Mod Scale -25%, 240226 - Read
(@CGUID+18, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Lightforged Artificer
(@CGUID+19, 0, 0, 0, 0, 0, 14737, 0, 0, '79968'), -- Lightforged Protector - 79968 - Blessing of Kings
(@CGUID+20, 0, 0, 0, 0, 0, 12894, 0, 0, ''), -- Lightforged Anchorite
(@CGUID+21, 0, 0, 1, 1, 0, 0, 0, 0, '260861'), -- Lightforged Vindicator - 260861 - -Unknown-
(@CGUID+22, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Maras
(@CGUID+23, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Anchorite Lysara
(@CGUID+24, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Lightforged Vindicator
(@CGUID+25, 0, 0, 0, 1, 0, 12976, 0, 0, '79968'), -- Lightforged Protector - 79968 - Blessing of Kings
(@CGUID+26, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Lightforged Bulwark
(@CGUID+27, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Generic Bunny
(@CGUID+28, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Artificer Shela'na
(@CGUID+29, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Lightforged Vindicator
(@CGUID+30, 0, 0, 0, 1, 0, 14737, 0, 0, '79968'), -- Lightforged Protector - 79968 - Blessing of Kings
(@CGUID+31, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Vigilant Quoram
(@CGUID+32, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Lightforged Vindicator
(@CGUID+33, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Lightforged Vindicator
(@CGUID+34, 0, 0, 0, 1, 0, 12976, 0, 0, '79968'), -- Lightforged Protector - 79968 - Blessing of Kings
(@CGUID+35, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Lightforged Bulwark
(@CGUID+36, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Enstraa
(@CGUID+37, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Lightforged Artificer
(@CGUID+38, 0, 0, 0, 1, 0, 14737, 0, 0, '79968'), -- Lightforged Protector - 79968 - Blessing of Kings
(@CGUID+39, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- A'naa
(@CGUID+40, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Lightforged Anchorite
(@CGUID+41, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Lightforged Vindicator
(@CGUID+42, 0, 0, 0, 0, 0, 0, 0, 0, '237554'), -- Lightsworn Anchorite - 237554 - Mod Scale -25%
(@CGUID+43, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Lightforged Vindicator
(@CGUID+44, 0, 0, 0, 1, 0, 14737, 0, 0, '79968'), -- Lightforged Protector - 79968 - Blessing of Kings
(@CGUID+45, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Lightforged Vindicator
(@CGUID+46, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Jarus
(@CGUID+47, 0, 0, 0, 0, 0, 0, 0, 0, '237554'), -- Lightsworn Anchorite - 237554 - Mod Scale -25%
(@CGUID+48, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Lightforged Vindicator
(@CGUID+49, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Lightforged Anchorite
(@CGUID+50, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Exodar Artificer
(@CGUID+51, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Lightforged Anchorite
(@CGUID+52, 0, 0, 0, 0, 0, 0, 0, 0, '237554'), -- Lightsworn Anchorite - 237554 - Mod Scale -25%
(@CGUID+53, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Lightforged Vindicator
(@CGUID+54, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Lightforged Anchorite
(@CGUID+55, 0, 0, 0, 1, 0, 0, 0, 0, '79968'), -- Lightforged Protector - 79968 - Blessing of Kings
(@CGUID+56, 0, 0, 0, 0, 0, 0, 0, 0, '237554'), -- Lightsworn Anchorite - 237554 - Mod Scale -25%
(@CGUID+57, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Lightforged Anchorite
(@CGUID+58, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Lightforged Vindicator
(@CGUID+59, 0, 0, 0, 1, 0, 7276, 0, 0, '250840'), -- Thelbus Wimblenod - 250840 - -Unknown-
(@CGUID+60, 0, 0, 0, 1, 0, 0, 0, 0, '246141'), -- T'paartos - 246141 - -Unknown-
(@CGUID+61, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- Captain Fareeya

DELETE FROM `creature_template_addon` WHERE `entry` IN (132210 /*132210 (T'paartos) - -Unknown-*/, 126390 /*126390 (Thelbus Wimblenod) - -Unknown-*/, 125843 /*125843 (Exodar Artificer)*/, 132325 /*132325 (Jarus)*/, 125524 /*125524 (Lightsworn Anchorite) - Mod Scale -25%*/, 126075 /*126075 (A'naa)*/, 132358 /*132358 (Enstraa)*/, 130986 /*130986 (Vigilant Quoram)*/, 126389 /*126389 (Artificer Shela'na)*/, 126022 /*126022 (Anchorite Lysara)*/, 130560 /*130560 (Maras)*/, 132225 /*132225 (Lightforged Artificer)*/, 126030 /*126030 (Lightsworn Anchorite) - Mod Scale -25%, Read*/, 96507 /*96507 (Tassia Whisperglen)*/, 132214 /*132214 (Lightforged Anchorite)*/, 132328 /*132328 (Lightforged Bulwark)*/, 132266 /*132266 (Lightforged Protector) - Blessing of Kings*/, 132224 /*132224 (Durael)*/, 114590 /*114590 (Generic Bunny)*/, 132334 /*132334 (Grand Artificer Romuul)*/, 123395 /*123395 (High Priestess Ishanah)*/, 132323 /*132323 (Yalia)*/, 132262 /*132262 (Lightforged Protector) - Blessing of Kings*/, 132215 /*132215 (Lightforged Vindicator)*/, 130993 /*130993 (Captain Fareeya)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(132210, 0, 0, 0, 1, 0, 0, 0, 0, '246141'), -- 132210 (T'paartos) - -Unknown-
(126390, 0, 0, 0, 1, 0, 7276, 0, 0, '250840'), -- 126390 (Thelbus Wimblenod) - -Unknown-
(125843, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 125843 (Exodar Artificer)
(132325, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 132325 (Jarus)
(125524, 0, 0, 0, 0, 0, 0, 0, 0, '237554'), -- 125524 (Lightsworn Anchorite) - Mod Scale -25%
(126075, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 126075 (A'naa)
(132358, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 132358 (Enstraa)
(130986, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 130986 (Vigilant Quoram)
(126389, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 126389 (Artificer Shela'na)
(126022, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 126022 (Anchorite Lysara)
(130560, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 130560 (Maras)
(132225, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 132225 (Lightforged Artificer)
(126030, 0, 0, 0, 0, 0, 0, 0, 0, '237554 240226'), -- 126030 (Lightsworn Anchorite) - Mod Scale -25%, Read
(96507, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 96507 (Tassia Whisperglen)
(132214, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 132214 (Lightforged Anchorite)
(132328, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 132328 (Lightforged Bulwark)
(132266, 0, 0, 0, 1, 0, 14737, 0, 0, '79968'), -- 132266 (Lightforged Protector) - Blessing of Kings
(132224, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 132224 (Durael)
(114590, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114590 (Generic Bunny)
(132334, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 132334 (Grand Artificer Romuul)
(123395, 0, 0, 0, 256, 0, 0, 0, 0, ''), -- 123395 (High Priestess Ishanah)
(132323, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 132323 (Yalia)
(132262, 0, 0, 0, 1, 0, 12976, 0, 0, '79968'), -- 132262 (Lightforged Protector) - Blessing of Kings
(132215, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 132215 (Lightforged Vindicator)
(130993, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- 130993 (Captain Fareeya)

-- GameObject spawns + Addon
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+25;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 273496, 1860, 9359, 9359, '0', '10349', 0, 403.679534912109375, 1465.95068359375, 773.2154541015625, 5.628692626953125, 0, 0, -0.32143688201904296, 0.946931004524230957, 7200, 255, 1, 40120), -- Mailbox (Area: -Unknown- - Difficulty: 0)
(@OGUID+1, 273289, 1860, 9359, 9359, '0', '10260', 0, 399.8360595703125, 1453.932373046875, 772.62030029296875, 5.122548580169677734, 0, 0, -0.54829025268554687, 0.836288094520568847, 7200, 255, 1, 40120), -- Anvil (Area: -Unknown- - Difficulty: 0)
(@OGUID+2, 273288, 1860, 9359, 9359, '0', '10260', 0, 397.92938232421875, 1475.33349609375, 741.92742919921875, 4.162619590759277343, 0, 0, -0.87249374389648437, 0.488625317811965942, 7200, 255, 1, 40120), -- Anvil (Area: -Unknown- - Difficulty: 0)
(@OGUID+3, 272190, 1860, 9359, 9359, '0', '10260', 0, 506.250762939453125, 1472.5489501953125, 765.83477783203125, 0.445062816143035888, 0, 0, 0.220699310302734375, 0.97534191608428955, 7200, 255, 1, 40120), -- Navigation Console (Area: -Unknown- - Difficulty: 0)
(@OGUID+4, 273287, 1860, 9359, 9359, '0', '10260', 0, 394.411376953125, 1471.2208251953125, 741.87213134765625, 6.257011890411376953, 0, 0, -0.01308631896972656, 0.999914348125457763, 7200, 255, 1, 40120), -- Forge (Area: -Unknown- - Difficulty: 0)
(@OGUID+5, 273682, 1860, 9359, 9359, '0', '10260', 0, 490.098968505859375, 1477.7430419921875, 742.00762939453125, 5.458199977874755859, 0, 0, -0.4008941650390625, 0.916124403476715087, 7200, 255, 1, 40120), -- Crate (Area: -Unknown- - Difficulty: 0)
(@OGUID+6, 202862, 1860, 9359, 9359, '0', '10260', 0, 478.671875, 1487.732666015625, 742.68634033203125, 4.719912052154541015, 0, 0, -0.70444202423095703, 0.709761500358581542, 7200, 255, 1, 40120), -- Tiny Blue Ragdoll (Area: -Unknown- - Difficulty: 0)
(@OGUID+7, 273288, 1860, 9359, 9359, '0', '10260', 0, 397.92938232421875, 1475.33349609375, 741.92742919921875, 4.162619590759277343, 0, 0, -0.87249374389648437, 0.488625317811965942, 7200, 255, 1, 40120), -- Anvil (Area: -Unknown- - Difficulty: 0)
(@OGUID+8, 273683, 1860, 9359, 9359, '0', '10260', 0, 497.001739501953125, 1475.373291015625, 743.53948974609375, 5.823760986328125, 0, 0, -0.22769737243652343, 0.973731935024261474, 7200, 255, 1, 40120), -- Magical Hat (Area: -Unknown- - Difficulty: 0)
(@OGUID+9, 278730, 1860, 9359, 9359, '0', '10260', 0, 403.619781494140625, 1423.670166015625, 741.75201416015625, 0.436331570148468017, 0, 0, 0.216439247131347656, 0.976296067237854003, 7200, 255, 1, 40120), -- Netherlight Crucible (Area: -Unknown- - Difficulty: 0)
(@OGUID+10, 273850, 1860, 9359, 9359, '0', '10260', 0, 406.720489501953125, 1417.3004150390625, 743.69940185546875, 0, 0, 0, 0, 1, 7200, 255, 1, 40120), -- Shadow (Area: -Unknown- - Difficulty: 0)
(@OGUID+11, 273682, 1860, 9359, 9359, '0', '10260', 0, 497.453125, 1475.5382080078125, 742.42327880859375, 5.367619514465332031, 0, 0, -0.44196033477783203, 0.89703458547592163, 7200, 255, 1, 40120), -- Crate (Area: -Unknown- - Difficulty: 0)
(@OGUID+12, 251228, 1860, 9359, 9359, '0', '10260', 0, 419.30035400390625, 1479.0103759765625, 741.97442626953125, 0, 0, 0, 0, 1, 7200, 255, 1, 40120), -- Draenei Pillow 3 (Area: -Unknown- - Difficulty: 0)
(@OGUID+13, 246170, 1860, 9359, 9359, '0', '10260', 0, 406.4288330078125, 1466.890625, 741.97442626953125, 0, 0, 0, 0, 1, 7200, 255, 1, 40120), -- Chair Low (Area: -Unknown- - Difficulty: 0)
(@OGUID+14, 278729, 1860, 9359, 9359, '0', '10260', 0, 458.87152099609375, 1449.935791015625, 741.23095703125, 3.595921516418457031, 0, 0, -0.97430896759033203, 0.22521558403968811, 7200, 255, 1, 40120), -- Vindicaar Matrix Core (Area: -Unknown- - Difficulty: 0)
(@OGUID+15, 273849, 1860, 9359, 9359, '0', '10260', 0, 400.588531494140625, 1430.265625, 743.67462158203125, 0, 0, 0, 0, 1, 7200, 255, 1, 40120), -- Light (Area: -Unknown- - Difficulty: 0)
(@OGUID+16, 276296, 1860, 9359, 9359, '0', '10260', 0, 408.19097900390625, 1425.7916259765625, 743.59747314453125, 0, 0, 0, 0, 1, 7200, 255, 1, 40120), -- Netherlight Crucible (Area: -Unknown- - Difficulty: 0)
(@OGUID+17, 272190, 1860, 9359, 9359, '0', '10260', 0, 506.250762939453125, 1472.5489501953125, 765.83477783203125, 0.445062816143035888, 0, 0, 0.220699310302734375, 0.97534191608428955, 7200, 255, 1, 40120), -- Navigation Console (Area: -Unknown- - Difficulty: 0)
(@OGUID+18, 273287, 1860, 9359, 9359, '0', '10260', 0, 394.411376953125, 1471.2208251953125, 741.87213134765625, 6.257011890411376953, 0, 0, -0.01308631896972656, 0.999914348125457763, 7200, 255, 1, 40120), -- Forge (Area: -Unknown- - Difficulty: 0)
(@OGUID+19, 273496, 1860, 9359, 9359, '0', '10260', 0, 403.679534912109375, 1465.95068359375, 773.2154541015625, 5.628692626953125, 0, 0, -0.32143688201904296, 0.946931004524230957, 7200, 255, 1, 40120), -- Mailbox (Area: -Unknown- - Difficulty: 0)
(@OGUID+20, 278732, 1860, 9359, 9359, '0', '10260', 0, 500.380218505859375, 1469.8160400390625, 742.44256591796875, 0, 0, 0, 0, 1, 7200, 255, 1, 40120), -- Portal to Stormwind (Area: -Unknown- - Difficulty: 0)
(@OGUID+21, 273681, 1860, 9359, 9359, '0', '10260', 0, 496.133697509765625, 1475.6597900390625, 742.42327880859375, 5.934101104736328125, 0, 0, -0.17365741729736328, 0.9848061203956604, 7200, 255, 1, 40120), -- Crate (Area: -Unknown- - Difficulty: 0)
(@OGUID+22, 278728, 1860, 9359, 9359, '0', '10260', 0, 436.213531494140625, 1439.1197509765625, 761.61798095703125, 0.436331570148468017, 0, 0, 0.216439247131347656, 0.976296067237854003, 7200, 255, 1, 40120), -- Crown Pedestal (Area: -Unknown- - Difficulty: 0)
(@OGUID+23, 233662, 1860, 9359, 9359, '0', '10260', 0, 488.7882080078125, 1477.75, 742.0079345703125, 6.024680614471435546, 0, 0, -0.12889289855957031, 0.991658508777618408, 7200, 255, 1, 40120), -- Small Crate (Area: -Unknown- - Difficulty: 0)
(@OGUID+24, 273684, 1860, 9359, 9359, '0', '10260', 0, 496.8038330078125, 1475.24658203125, 742.42327880859375, 4.1532745361328125, 0, 0, -0.87476730346679687, 0.48454323410987854, 7200, 255, 1, 40120), -- Magical Boots (Area: -Unknown- - Difficulty: 0)
(@OGUID+25, 273289, 1860, 9359, 9359, '0', '10260', 0, 399.8360595703125, 1453.932373046875, 772.62030029296875, 5.122548580169677734, 0, 0, -0.54829025268554687, 0.836288094520568847, 7200, 255, 1, 40120); -- Anvil (Area: -Unknown- - Difficulty: 0)
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+25;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 0.220700010657310485, 0.975341737270355224, 0, 0), -- Mailbox
(@OGUID+1, 0, 0, 0.220700010657310485, 0.975341737270355224, 0, 0), -- Anvil
(@OGUID+2, 0, 0, 0.220700010657310485, 0.975341737270355224, 0, 0), -- Anvil
(@OGUID+3, 0, 0, 0.220700010657310485, 0.975341737270355224, 0, 0), -- Navigation Console
(@OGUID+4, 0, 0, 0.220700010657310485, 0.975341737270355224, 0, 0), -- Forge
(@OGUID+7, 0, 0, 0.220700010657310485, 0.975341737270355224, 0, 0), -- Anvil
(@OGUID+17, 0, 0, 0.220700010657310485, 0.975341737270355224, 0, 0), -- Navigation Console
(@OGUID+18, 0, 0, 0.220700010657310485, 0.975341737270355224, 0, 0), -- Forge
(@OGUID+19, 0, 0, 0.220700010657310485, 0.975341737270355224, 0, 0), -- Mailbox
(@OGUID+20, 0, 0, 0, 1, 8786, 0), -- Portal to Stormwind
(@OGUID+25, 0, 0, 0.220700010657310485, 0.975341737270355224, 0, 0); -- Anvil

-- scaling
DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (132210,126390,125843,132325,125524,126075,132358,130986,126389,126022,130560,132225,126030,132214,132328,132266,132224,132334,123395,132323,132262,132215,130993));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(132210, 0, 0, 0, 293, 40120),
(126390, 0, 0, 0, 337, 40120),
(125843, 0, 0, 0, 337, 40120),
(132325, 0, 0, 0, 293, 40120),
(125524, 0, 0, 0, 337, 40120),
(126075, 0, 0, 0, 337, 40120),
(132358, 0, 0, 0, 293, 40120),
(130986, 0, 0, 0, 293, 40120),
(126389, 0, 0, 0, 337, 40120),
(126022, 0, 0, 0, 337, 40120),
(130560, 0, 0, 0, 293, 40120),
(132225, 0, 0, 0, 293, 40120),
(126030, 0, 0, 0, 337, 40120),
(132214, 0, 0, 0, 293, 40120),
(132328, 0, 0, 0, 293, 40120),
(132266, 0, 0, 0, 293, 40120),
(132224, 0, 0, 0, 293, 40120),
(132334, 0, 0, 0, 293, 40120),
(123395, 0, 0, 0, 337, 40120),
(132323, 0, 0, 0, 293, 40120),
(132262, 0, 0, 0, 293, 40120),
(132215, 0, 0, 0, 293, 40120),
(130993, 0, 0, 0, 293, 40120);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=40120 WHERE (`Entry`=96507 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=40120 WHERE (`Entry`=114590 AND `DifficultyID`=0);

-- Creature Model
DELETE FROM `creature_model_info` WHERE `DisplayID` IN (79624, 83125, 82309, 82303, 82297, 82323, 82308, 82300, 82301, 82321, 82299, 82324, 82307, 82322, 82302);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(79624, 1.20000004768371582, 1.80000007152557373, 0, 40120),
(83125, 1, 1.5, 0, 40120),
(82309, 0.899999976158142089, 1.349999904632568359, 0, 40120),
(82303, 1, 1.5, 0, 40120),
(82297, 1, 1.5, 0, 40120),
(82323, 1, 1.5, 0, 40120),
(82308, 0.899999976158142089, 1.349999904632568359, 0, 40120),
(82300, 1, 1.5, 0, 40120),
(82301, 1, 1.5, 0, 40120),
(82321, 1, 1.5, 0, 40120),
(82299, 1, 1.5, 0, 40120),
(82324, 1, 1.5, 0, 40120),
(82307, 1.10000002384185791, 1.65000009536743164, 0, 40120),
(82322, 1, 1.5, 0, 40120),
(82302, 1, 1.5, 0, 40120);

UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=78910;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=71155;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=78609;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1.5, `VerifiedBuild`=40120 WHERE `DisplayID`=78677;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=78434;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=78387;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=79929;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=78896;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=78659;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=80784;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=71154;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=25607;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=78386;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=27823;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=76255;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=17882;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=60739;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=77524;

-- Trainer Data
DELETE FROM `trainer` WHERE `Id`=882;
INSERT INTO `trainer` (`Id`, `Type`, `Greeting`, `VerifiedBuild`) VALUES
(882, 2, 'Here, let me show you how to bind those wounds....', 40120);

DELETE FROM `trainer_spell` WHERE (`TrainerId`=882 AND `SpellId` IN (102698,102697,202853,202854,7928,7929,74558,74556,88893,74557,3278,3277,27033,27032,3276,18630,10840,10841,18629,45546,45545));
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
(882, 102698, 100, 2536, 25, 0, 0, 0, 0, 40120), -- No Faction found! MoneyCost not recalculated!
(882, 102697, 10, 2536, 1, 0, 0, 0, 0, 40120), -- No Faction found! MoneyCost not recalculated!
(882, 202853, 10, 2534, 1, 0, 0, 0, 0, 40120), -- No Faction found! MoneyCost not recalculated!
(882, 202854, 250, 2534, 60, 0, 0, 0, 0, 40120), -- No Faction found! MoneyCost not recalculated!
(882, 7928, 6500, 2540, 150, 0, 0, 0, 0, 40120), -- No Faction found! MoneyCost not recalculated!
(882, 7929, 18000, 2540, 180, 0, 0, 0, 0, 40120), -- No Faction found! MoneyCost not recalculated!
(882, 74558, 350, 2537, 75, 0, 0, 0, 0, 40120), -- No Faction found! MoneyCost not recalculated!
(882, 74556, 10, 2537, 1, 0, 0, 0, 0, 40120), -- No Faction found! MoneyCost not recalculated!
(882, 88893, 350, 2537, 75, 74558, 0, 0, 0, 40120), -- No Faction found! MoneyCost not recalculated!
(882, 74557, 100, 2537, 25, 0, 0, 0, 0, 40120), -- No Faction found! MoneyCost not recalculated!
(882, 3278, 1750, 2540, 115, 0, 0, 0, 0, 40120), -- No Faction found! MoneyCost not recalculated!
(882, 3277, 400, 2540, 80, 0, 0, 0, 0, 40120), -- No Faction found! MoneyCost not recalculated!
(882, 27033, 115, 2539, 30, 0, 0, 0, 0, 40120), -- No Faction found! MoneyCost not recalculated!
(882, 27032, 10, 2539, 1, 0, 0, 0, 0, 40120), -- No Faction found! MoneyCost not recalculated!
(882, 3276, 150, 2540, 40, 0, 0, 0, 0, 40120), -- No Faction found! MoneyCost not recalculated!
(882, 18630, 560000, 2540, 290, 0, 0, 0, 0, 40120), -- No Faction found! MoneyCost not recalculated!
(882, 10840, 46000, 2540, 210, 0, 0, 0, 0, 40120), -- No Faction found! MoneyCost not recalculated!
(882, 10841, 130000, 2540, 240, 0, 0, 0, 0, 40120), -- No Faction found! MoneyCost not recalculated!
(882, 18629, 260000, 2540, 260, 0, 0, 0, 0, 40120), -- No Faction found! MoneyCost not recalculated!
(882, 45546, 50, 2538, 15, 0, 0, 0, 0, 40120), -- No Faction found! MoneyCost not recalculated!
(882, 45545, 10, 2538, 1, 0, 0, 0, 0, 40120); -- No Faction found! MoneyCost not recalculated!

DELETE FROM `creature_trainer` WHERE (`CreatureId`=126022 AND `MenuID`=8522 AND `OptionIndex`=0);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuID`, `OptionIndex`) VALUES
(126022, 882, 8522, 0);

-- Vendor Data
DELETE FROM `npc_vendor` WHERE (`entry`=132224 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132224 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132224 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132224 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132224 AND `item`=180733 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132224 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132224 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132323 AND `item`=8953 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132323 AND `item`=4602 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132323 AND `item`=4539 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132323 AND `item`=4538 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132323 AND `item`=4537 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132323 AND `item`=4536 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132323 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132323 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132323 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132323 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132323 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132323 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=96507 AND `item`=37460 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=123395 AND `item`=152717 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=123395 AND `item`=152718 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=126075 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=126075 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=126075 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=126075 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=126075 AND `item`=180733 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=126075 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=126075 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(132224, 7, 3857, 0, 0, 1, 0, 0, 40120), -- Coal
(132224, 6, 18567, 0, 0, 1, 0, 0, 40120), -- Elemental Flux
(132224, 5, 3466, 0, 0, 1, 0, 0, 40120), -- Strong Flux
(132224, 4, 2880, 0, 0, 1, 0, 0, 40120), -- Weak Flux
(132224, 3, 180733, 0, 0, 1, 0, 0, 40120), -- -Unknown-
(132224, 2, 5956, 0, 0, 1, 0, 0, 40120), -- Blacksmith Hammer
(132224, 1, 2901, 0, 0, 1, 0, 0, 40120), -- Mining Pick
(132323, 12, 8953, 0, 0, 1, 0, 0, 40120), -- Deep Fried Plantains
(132323, 11, 4602, 0, 0, 1, 0, 0, 40120), -- Moon Harvest Pumpkin
(132323, 10, 4539, 0, 0, 1, 0, 0, 40120), -- Goldenbark Apple
(132323, 9, 4538, 0, 0, 1, 0, 0, 40120), -- Snapvine Watermelon
(132323, 8, 4537, 0, 0, 1, 0, 0, 40120), -- Tel'Abim Banana
(132323, 7, 4536, 0, 0, 1, 0, 0, 40120), -- Shiny Red Apple
(132323, 6, 8766, 0, 0, 1, 0, 0, 40120), -- Morning Glory Dew
(132323, 5, 1645, 0, 0, 1, 0, 0, 40120), -- Moonberry Juice
(132323, 4, 1708, 0, 0, 1, 0, 0, 40120), -- Sweet Nectar
(132323, 3, 1205, 0, 0, 1, 0, 0, 40120), -- Melon Juice
(132323, 2, 1179, 0, 0, 1, 0, 0, 40120), -- Ice Cold Milk
(132323, 1, 159, 0, 0, 1, 0, 0, 40120), -- Refreshing Spring Water
(96507, 1, 37460, 0, 0, 1, 0, 0, 40120), -- Rope Pet Leash
(123395, 2, 152717, 0, 0, 1, 0, 0, 40120), -- -Unknown-
(123395, 1, 152718, 0, 0, 1, 0, 0, 40120), -- -Unknown-
(126075, 7, 3857, 0, 0, 1, 0, 0, 40120), -- Coal
(126075, 6, 18567, 0, 0, 1, 0, 0, 40120), -- Elemental Flux
(126075, 5, 3466, 0, 0, 1, 0, 0, 40120), -- Strong Flux
(126075, 4, 2880, 0, 0, 1, 0, 0, 40120), -- Weak Flux
(126075, 3, 180733, 0, 0, 1, 0, 0, 40120), -- -Unknown-
(126075, 2, 5956, 0, 0, 1, 0, 0, 40120), -- Blacksmith Hammer
(126075, 1, 2901, 0, 0, 1, 0, 0, 40120); -- Mining Pick

-- Creature Equipment
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (132358,130986,132225,132214,132328,132266,132334,132262,132215,130993));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(132358, 1, 12260, 0, 0, 0, 0, 0, 0, 0, 0), -- Enstraa
(130986, 1, 153354, 0, 0, 153353, 0, 0, 0, 0, 0), -- Vigilant Quoram
(132225, 1, 28487, 0, 0, 29637, 0, 0, 0, 0, 0), -- Lightforged Artificer
(132214, 1, 122076, 0, 0, 0, 0, 0, 0, 0, 0), -- Lightforged Anchorite
(132328, 1, 140555, 0, 0, 138831, 0, 0, 0, 0, 0), -- Lightforged Bulwark
(132266, 1, 141994, 0, 0, 0, 0, 0, 0, 0, 0), -- Lightforged Protector
(132334, 1, 126431, 0, 0, 45617, 0, 0, 0, 0, 0), -- Grand Artificer Romuul
(132262, 1, 141994, 0, 0, 0, 0, 0, 0, 0, 0), -- Lightforged Protector
(132215, 1, 94667, 0, 0, 110156, 0, 0, 0, 0, 0), -- Lightforged Vindicator
(130993, 1, 141994, 0, 0, 0, 0, 0, 0, 0, 0); -- Captain Fareeya

-- Gossip Data
UPDATE `gossip_menu` SET `VerifiedBuild`=40120 WHERE (`MenuId`=21451 AND `TextId`=32658); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=40120 WHERE (`MenuId`=21454 AND `TextId`=32670); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=40120 WHERE (`MenuId`=21423 AND `TextId`=32623); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=40120 WHERE (`MenuId`=9821 AND `TextId`=13584); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=40120 WHERE (`MenuId`=21462 AND `TextId`=9849); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=40120 WHERE (`MenuId`=21462 AND `TextId`=9849); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=40120 WHERE (`MenuId`=8522 AND `TextId`=7028); -- 0

DELETE FROM `gossip_menu` WHERE (`MenuId`=21910 AND `TextId`=33495) OR (`MenuId`=22018 AND `TextId`=33727) OR (`MenuId`=22008 AND `TextId`=33709) OR (`MenuId`=22017 AND `TextId`=33725) OR (`MenuId`=22019 AND `TextId`=33728) OR (`MenuId`=22014 AND `TextId`=33721);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(21910, 33495, 40120), -- 130986 (Vigilant Quoram)
(22018, 33727, 40120), -- 132358 (Enstraa)
(22008, 33709, 40120), -- 130560 (Maras)
(22017, 33725, 40120), -- 132334 (Grand Artificer Romuul)
(22019, 33728, 40120), -- 130993 (Captain Fareeya)
(22014, 33721, 40120); -- 132215 (Lightforged Vindicator)

-- Update Gossip_menu_option
DELETE FROM `gossip_menu_option` WHERE `MenuId` IN (21910, 21462, 21423, 21910, 9821) AND `OptionIndex` IN (5,4,3,2,1,0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES
(21462, 0, 5, 'Make this inn your home.', 2822, 8, 65536, 40120),
(21462, 1, 0, 'It is good to see you, Ishanah. How are you?', 136389, 0, 0, 27980),
(21462, 2, 1, 'Let me browse your goods.', 8097, 3, 128, 40120),
(21423, 0, 1, 'I need repairs, Durael.', 136412, 3, 128, 40120),
(21910, 0, 0, 'Hello, Vigilant Quoram. We met before on Argus.', 142629, 1, 1, 40120),
(21910, 1, 0, 'I passed my trial!', 142630, 1, 1, 40120),
(21910, 2, 0, 'What do you know about becoming Lightforged?', 142631, 1, 1, 40120),
(21910, 3, 0, 'Do you plan on staying with the draenei?', 142632, 1, 1, 40120),
(21910, 4, 0, 'How do you like being on the Vindicaar?', 142633, 1, 1, 40120),
(21910, 5, 0, 'Can you teleport me back up to the bridge?', 142634, 1, 1, 40120),
(9821, 0, 12, 'I\'d like to stable my pet here.', 0, 0, 0, 27326),
(9821, 1, 1, 'I\'m looking for a lost companion.', 56613, 3, 128, 40120),
(9821, 3, 0, 'I\'d like to heal and revive my battle pets.', 64115, 1, 1, 40120);

UPDATE `gossip_menu_option` SET `VerifiedBuild`=40120 WHERE (`MenuId`=21423 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=40120 WHERE (`MenuId`=9821 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=40120 WHERE (`MenuId`=9821 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=40120 WHERE (`MenuId`=21462 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=40120 WHERE (`MenuId`=21462 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=40120 WHERE (`MenuId`=21462 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=40120 WHERE (`MenuId`=21462 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=40120 WHERE (`MenuId`=8522 AND `OptionIndex`=0);

-- Update Creature_Template Data
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=1665, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=132210; -- T'paartos
UPDATE `creature_template` SET `gossip_menu_id`=21454, `minlevel`=45, `maxlevel`=45 WHERE `entry`=126390; -- Thelbus Wimblenod
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45 WHERE `entry`=125843; -- Exodar Artificer
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=132325; -- Jarus
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45 WHERE `entry`=125524; -- Lightsworn Anchorite
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `npcflag`=4224, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=126075; -- A'naa
UPDATE `creature_template` SET `gossip_menu_id`=22018, `minlevel`=60, `maxlevel`=60, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=132358; -- Enstraa
UPDATE `creature_template` SET `gossip_menu_id`=21910, `minlevel`=60, `maxlevel`=60, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `HoverHeight`=3 WHERE `entry`=130986; -- Vigilant Quoram
UPDATE `creature_template` SET `gossip_menu_id`=21451, `minlevel`=45, `maxlevel`=45, `npcflag`=3 WHERE `entry`=126389; -- Artificer Shela'na
UPDATE `creature_template` SET `gossip_menu_id`=8522, `minlevel`=45, `maxlevel`=45 WHERE `entry`=126022; -- Anchorite Lysara
UPDATE `creature_template` SET `gossip_menu_id`=22008, `minlevel`=60, `maxlevel`=60, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=130560; -- Maras
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=132225; -- Lightforged Artificer
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45 WHERE `entry`=126030; -- Lightsworn Anchorite
UPDATE `creature_template` SET `gossip_menu_id`=9821 WHERE `entry`=96507; -- Tassia Whisperglen
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=132214; -- Lightforged Anchorite
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=132328; -- Lightforged Bulwark
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=2860, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=132266; -- Lightforged Protector
UPDATE `creature_template` SET `gossip_menu_id`=21423, `minlevel`=60, `maxlevel`=60, `npcflag`=4227, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=132224; -- Durael
UPDATE `creature_template` SET `minlevel`=60 WHERE `entry`=114590; -- Generic Bunny
UPDATE `creature_template` SET `gossip_menu_id`=22017, `minlevel`=60, `maxlevel`=60, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=132334; -- Grand Artificer Romuul
UPDATE `creature_template` SET `gossip_menu_id`=21462, `minlevel`=45, `maxlevel`=45 WHERE `entry`=123395; -- High Priestess Ishanah
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `npcflag`=640, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=132323; -- Yalia
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=2860, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=132262; -- Lightforged Protector
UPDATE `creature_template` SET `gossip_menu_id`=22014, `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=132215; -- Lightforged Vindicator
UPDATE `creature_template` SET `gossip_menu_id`=22019, `minlevel`=60, `maxlevel`=60, `faction`=1665, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=130993; -- Captain Fareeya

-- Update GameObject_Template Data
DELETE FROM `gameobject_template` WHERE `entry` IN (278729 /*Vindicaar Matrix Core*/, 278730 /*Netherlight Crucible*/, 278732 /*Portal to Stormwind*/, 278728 /*Crown Pedestal*/, 246170 /*Chair Low*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `ContentTuningId`, `VerifiedBuild`) VALUES
(278729, 5, 43982, 'Vindicaar Matrix Core', '', '', '', 1.551480054855346679, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 293, 40120), -- Vindicaar Matrix Core
(278730, 5, 44671, 'Netherlight Crucible', '', '', '', 1.149999976158142089, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 293, 40120), -- Netherlight Crucible
(278732, 22, 47526, 'Portal to Stormwind', '', '', '', 1.5, 258310, -1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 863, 40120), -- Portal to Stormwind
(278728, 5, 43983, 'Crown Pedestal', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 293, 40120), -- Crown Pedestal
(246170, 5, 30889, 'Chair Low', '', '', '', 1.25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 339, 40120); -- Chair Low

-- NPC Text
DELETE FROM `npc_text` WHERE `ID` IN (33495 /*33495*/, 33727 /*33727*/, 33709 /*33709*/, 33725 /*33725*/, 33728 /*33728*/, 33721);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(33495, 1, 0, 0, 0, 0, 0, 0, 0, 142628, 0, 0, 0, 0, 0, 0, 0, 40120), -- 33495
(33727, 1, 0, 0, 0, 0, 0, 0, 0, 144921, 0, 0, 0, 0, 0, 0, 0, 40120), -- 33727
(33709, 1, 1, 1, 0, 0, 0, 0, 0, 144770, 144772, 144923, 0, 0, 0, 0, 0, 40120), -- 33709
(33725, 1, 0, 0, 0, 0, 0, 0, 0, 144908, 0, 0, 0, 0, 0, 0, 0, 40120), -- 33725
(33728, 1, 1, 0, 0, 0, 0, 0, 0, 144924, 144925, 0, 0, 0, 0, 0, 0, 40120), -- 33728
(33721, 1, 0, 0, 0, 0, 0, 0, 0, 144864, 0, 0, 0, 0, 0, 0, 0, 40120); -- 33721

-- SET SAI in Template
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (132262, 132266);

-- SAI script for 132262 lightforged-protector
DELETE FROM `smart_scripts` WHERE `entryorguid` = 132262 AND `source_type` = 0;
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(132262, 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 300000, 300000, 0, '', 11, 79968, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1sec and Reapeat every 5min cast Spell on self');

-- SAI script for 132266 lightforged-protector
DELETE FROM `smart_scripts` WHERE `entryorguid` = 132266 AND `source_type` = 0;
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(132266, 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 300000, 300000, 0, '', 11, 79968, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1sec and Reapeat every 5min cast Spell on self');
