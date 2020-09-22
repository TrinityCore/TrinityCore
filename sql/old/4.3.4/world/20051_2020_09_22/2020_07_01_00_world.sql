
SET @CGUID := 396378;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+27;
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+27;
-- Thermal Pckets at Fireplume Peak
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 52162, 861, 5733, 5745, 1, 0, 606, 38113, 0, 1278.185791015625, 583.52777099609375, 77.61121368408203125, 0.314159274101257324, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Thermal Pocket Bunny (Area: The Furnace - Difficulty: 0) (Auras: 97963 - Thermal Vent Pulse)
(@CGUID+1, 52162, 861, 5733, 5745, 1, 0, 606, 38113, 0, 1357.314208984375, 564.83331298828125, 81.8060455322265625, 5.462880611419677734, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Thermal Pocket Bunny (Area: The Furnace - Difficulty: 0) (Auras: 97963 - Thermal Vent Pulse)
(@CGUID+2, 52985, 861, 5733, 5748, 1, 0, 606, 38115, 0, 1330.423583984375, 621.86456298828125, 101.17974853515625, 4.258603572845458984, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Thermal Pocket Bunny (Area: Fireplume Peak - Difficulty: 0) (Auras: 97968 - Thermal Vent Pulse)
(@CGUID+3, 52984, 861, 5733, 5748, 1, 0, 606, 38114, 0, 1400.5347900390625, 558.68927001953125, 79.86945343017578125, 3.874630928039550781, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Thermal Pocket Bunny (Area: Fireplume Peak - Difficulty: 0) (Auras: 97966 - Thermal Vent Pulse)
(@CGUID+4, 52162, 861, 5733, 5748, 1, 0, 606, 38113, 0, 1384.421875, 593.43231201171875, 103.3846893310546875, 4.799655437469482421, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Thermal Pocket Bunny (Area: Fireplume Peak - Difficulty: 0) (Auras: 97963 - Thermal Vent Pulse)
(@CGUID+5, 52984, 861, 5733, 5748, 1, 0, 606, 38114, 0, 1414.44970703125, 597.1649169921875, 94.261199951171875, 0.767944872379302978, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Thermal Pocket Bunny (Area: Fireplume Peak - Difficulty: 0) (Auras: 97966 - Thermal Vent Pulse)
(@CGUID+6, 52984, 861, 5733, 5748, 1, 0, 606, 38114, 0, 1287.6441650390625, 676.0867919921875, 81.28753662109375, 3.857177734375, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Thermal Pocket Bunny (Area: Fireplume Peak - Difficulty: 0) (Auras: 97966 - Thermal Vent Pulse)
(@CGUID+7, 52984, 861, 5733, 5748, 1, 0, 606, 38114, 0, 1406.0728759765625, 650.0086669921875, 124.6035690307617187, 6.230825424194335937, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Thermal Pocket Bunny (Area: Fireplume Peak - Difficulty: 0) (Auras: 97966 - Thermal Vent Pulse)
(@CGUID+8, 52985, 861, 5733, 5748, 1, 0, 606, 38115, 0, 1349.3697509765625, 691.84893798828125, 110.9955062866210937, 3.176499128341674804, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Thermal Pocket Bunny (Area: Fireplume Peak - Difficulty: 0) (Auras: 97968 - Thermal Vent Pulse)
(@CGUID+9, 52984, 861, 5733, 5748, 1, 0, 606, 38114, 0, 1407.9444580078125, 633.46875, 116.2598724365234375, 5.462880611419677734, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Thermal Pocket Bunny (Area: Fireplume Peak - Difficulty: 0) (Auras: 97966 - Thermal Vent Pulse)
(@CGUID+10, 52985, 861, 5733, 5748, 1, 0, 606, 38115, 0, 1402.9166259765625, 683.37152099609375, 118.1809234619140625, 2.460914134979248046, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Thermal Pocket Bunny (Area: Fireplume Peak - Difficulty: 0) (Auras: 97968 - Thermal Vent Pulse)
(@CGUID+11, 52985, 861, 5733, 5748, 1, 0, 606, 38115, 0, 1365.51220703125, 719.68402099609375, 89.85120391845703125, 3.054326057434082031, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Thermal Pocket Bunny (Area: Fireplume Peak - Difficulty: 0) (Auras: 97968 - Thermal Vent Pulse)
(@CGUID+12, 52984, 861, 5733, 5748, 1, 0, 606, 38114, 0, 1430.94970703125, 642.33856201171875, 104.5272064208984375, 6.2657318115234375, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Thermal Pocket Bunny (Area: Fireplume Peak - Difficulty: 0) (Auras: 97966 - Thermal Vent Pulse)
(@CGUID+13, 52985, 861, 5733, 5748, 1, 0, 606, 38115, 0, 1407.6197509765625, 689.70831298828125, 117.7217636108398437, 2.234021425247192382, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Thermal Pocket Bunny (Area: Fireplume Peak - Difficulty: 0) (Auras: 97968 - Thermal Vent Pulse)
(@CGUID+14, 52984, 861, 5733, 5748, 1, 0, 606, 38114, 0, 1359.798583984375, 734.72222900390625, 80.300323486328125, 1.675516128540039062, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Thermal Pocket Bunny (Area: Fireplume Peak - Difficulty: 0) (Auras: 97966 - Thermal Vent Pulse)
(@CGUID+15, 52162, 861, 5733, 5748, 1, 0, 606, 38113, 0, 1409.4097900390625, 719.31597900390625, 99.855438232421875, 2.216568231582641601, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Thermal Pocket Bunny (Area: Fireplume Peak - Difficulty: 0) (Auras: 97963 - Thermal Vent Pulse)
(@CGUID+16, 52984, 861, 5733, 5748, 1, 0, 606, 38114, 0, 1431.107666015625, 699.22052001953125, 107.0220184326171875, 6.17846536636352539, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Thermal Pocket Bunny (Area: Fireplume Peak - Difficulty: 0) (Auras: 97966 - Thermal Vent Pulse)
(@CGUID+17, 52162, 861, 5733, 5748, 1, 0, 606, 38113, 0, 1456.984375, 694.08160400390625, 94.035247802734375, 0.069813169538974761, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Thermal Pocket Bunny (Area: Fireplume Peak - Difficulty: 0) (Auras: 97963 - Thermal Vent Pulse)
(@CGUID+18, 52985, 861, 5733, 5748, 1, 0, 606, 38115, 0, 1447.1458740234375, 652.83160400390625, 103.2839431762695312, 4.590215682983398437, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Thermal Pocket Bunny (Area: Fireplume Peak - Difficulty: 0) (Auras: 97968 - Thermal Vent Pulse)
(@CGUID+19, 52984, 861, 5733, 5748, 1, 0, 606, 38114, 0, 1482.6129150390625, 652.28302001953125, 86.5419921875, 4.886921882629394531, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Thermal Pocket Bunny (Area: Fireplume Peak - Difficulty: 0) (Auras: 97966 - Thermal Vent Pulse)
(@CGUID+20, 52984, 861, 5733, 5748, 1, 0, 606, 38114, 0, 1437.84375, 606.50347900390625, 95.20821380615234375, 4.590215682983398437, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Thermal Pocket Bunny (Area: Fireplume Peak - Difficulty: 0) (Auras: 97966 - Thermal Vent Pulse)
(@CGUID+21, 52985, 861, 5733, 5748, 1, 0, 606, 38115, 0, 1501.1475830078125, 646.86981201171875, 80.72277069091796875, 0.139626339077949523, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Thermal Pocket Bunny (Area: Fireplume Peak - Difficulty: 0) (Auras: 97968 - Thermal Vent Pulse)
(@CGUID+22, 52984, 861, 5733, 5748, 1, 0, 606, 38114, 0, 1491.1492919921875, 620.9444580078125, 78.56121826171875, 5.305800914764404296, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Thermal Pocket Bunny (Area: Fireplume Peak - Difficulty: 0) (Auras: 97966 - Thermal Vent Pulse)
-- Lava Bursters
(@CGUID+23, 52633, 861, 5733, 5739, 1, 169, 0, 0, 0, 1234.8541259765625, 385.45660400390625, 15.5024566650390625, 3.682644605636596679, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Lava Burster (Area: Ashen Fields - Difficulty: 0) (Auras: 97313 - Lava Burster Transform)
(@CGUID+24, 52633, 861, 5733, 5739, 1, 169, 0, 0, 0, 1266.2899169921875, 350.060760498046875, 20.8404388427734375, 2.914699792861938476, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Lava Burster (Area: Ashen Fields - Difficulty: 0) (Auras: 97313 - Lava Burster Transform)
(@CGUID+25, 52633, 861, 5733, 5739, 1, 169, 0, 0, 0, 1291.6754150390625, 441.8663330078125, 21.32282066345214843, 1.186823844909667968, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Lava Burster (Area: Ashen Fields - Difficulty: 0) (Auras: 97313 - Lava Burster Transform)
(@CGUID+26, 52633, 861, 5733, 5740, 1, 169, 0, 0, 0, 1358.71533203125, 451.848968505859375, 21.39720344543457031, 0.680678427219390869, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Lava Burster (Area: Magma Springs - Difficulty: 0) (Auras: 97313 - Lava Burster Transform)
(@CGUID+27, 52633, 861, 5733, 5740, 1, 169, 0, 0, 0, 1355.7552490234375, 368.6319580078125, 20.99794960021972656, 0.383972436189651489, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638); -- Lava Burster (Area: Magma Springs - Difficulty: 0) (Auras: 97313 - Lava Burster Transform)


DELETE FROM `creature_template_addon` WHERE `entry` IN (52984, 52162, 52985, 52633);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(52984, 0, 0, 0, 1, 0, 0, 0, 0, '97966'), -- 52984 (Thermal Pocket Bunny) - Thermal Vent Pulse
(52162, 0, 0, 0, 1, 0, 0, 0, 0, '97963'), -- 52162 (Thermal Pocket Bunny) - Thermal Vent Pulse
(52985, 0, 0, 0, 1, 0, 0, 0, 0, '97968'), -- 52985 (Thermal Pocket Bunny) - Thermal Vent Pulse
(52633, 0, 0, 0, 1, 0, 0, 0, 0, '97313'); -- Lava Burster - 97562 - Lava Burster Transform

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (52984, 52162, 52985, 52633);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Flight`, `Rooted`) VALUES
(52984, 0, 1, 0),
(52162, 0, 1, 0),
(52985, 0, 1, 0),
(52633, 0, 1, 1);

UPDATE `creature_template` SET `unit_flags`= 33555200 WHERE `entry` IN (52984, 52162, 52985);
