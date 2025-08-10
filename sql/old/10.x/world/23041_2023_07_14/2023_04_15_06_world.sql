SET @CGUID := 3000071;
SET @OGUID := 3001562;
SET @POOL := 5701;
SET @EVENT := 9;

-- Equipments
UPDATE `creature_equip_template` SET `VerifiedBuild`=48999 WHERE (`ID`=1 AND `CreatureID` IN (43005,34761,12429,6736,6286,4266,3614,3610,3609,3608,3603,3602,3601,3600,3599,3598,3571,3567,2083,2081,2078));

-- Models
UPDATE `creature_model_info` SET `VerifiedBuild`=48999 WHERE `DisplayID` IN (4615, 2055, 6300, 36956, 36944, 62734, 12769, 10045, 35613, 33171, 29139, 27823, 12476, 11900, 9270, 5749, 5440, 4989, 4862, 4235, 4236, 1711, 1710, 1714, 1701, 1705, 1712, 1700, 1709, 1702, 1706, 1703, 1708, 1704, 1707, 4849, 4852, 4850, 2686, 1528, 12729, 2459, 1682, 1896, 6805, 2429, 3033, 759, 10832);

UPDATE `creature_template_model` SET `VerifiedBuild`=48999 WHERE (`Idx`=0 AND `CreatureID` IN (61757,34575,49842,3613,40553,11942,48624,3614,3567,62242,6781,3306,3599,6736,3600,1998,49778,47420,2083,3611,10051,34761,1995,3612,48623,2022,2081,2078,2041,63070,3571,3608,4265,3604,2042,3515,6286,3609,4266,6094,3598,49728,65097,3601,12429,3603,3602,43005,3610)) OR (`Idx`=1 AND `CreatureID` IN (34575,49842,3571,49728)) OR (`Idx`=3 AND `CreatureID` IN (49842,3571,49728)) OR (`Idx`=2 AND `CreatureID` IN (49842,3571,49728));

-- Scaling
DELETE FROM `creature_template_scaling` WHERE (`Entry`=113136 AND `DifficultyID`=0);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(113136, 0, 0, 0, 371, 48999);

UPDATE `creature_template_scaling` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `VerifiedBuild`=48999 WHERE (`Entry`=65097 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=48999 WHERE (`DifficultyID`=0 AND `Entry` IN (63070,62242,61757,49842,49778,49728,48624,48623,47420,43005,40553,34761,34575,12429,11942,10051,6781,6736,6286,6094,4266,4265,3614,3613,3612,3611,3610,3609,3608,3604,3603,3602,3601,3600,3599,3598,3571,3567,3515,3306,2083,2081,2078,2042,2041,2022,1998,1995));

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 32799, 1, 141, 186, '0', 0, 0, 0, 0, 9836.3330078125, 969.412353515625, 1308.505126953125, 0.314159274101257324, 120, 0, 0, 361340, 28784, 0, 0, 0, 0, 48999), -- Spring Collector (Area: Dolanaar - Difficulty: 0) CreateObject1
(@CGUID+1, 32836, 1, 141, 186, '0', 0, 0, 0, 1, 9838.54296875, 961.83575439453125, 1308.533203125, 0.453785598278045654, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48999); -- Noblegarden Vendor (Area: Dolanaar - Difficulty: 0) CreateObject1

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+60;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 113768, 1, 141, 186, '0', 0, 0, 9784.2099609375, 969.43035888671875, 1306.0733642578125, 1.396261811256408691, 0, 0, 0.642786979675292968, 0.766044974327087402, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject1
(@OGUID+1, 113768, 1, 141, 186, '0', 0, 0, 9837.5712890625, 944.31512451171875, 1306.8673095703125, 6.09120035171508789, 0, 0, -0.09584522247314453, 0.995396256446838378, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject1
(@OGUID+2, 113768, 1, 141, 186, '0', 0, 0, 9885.7431640625, 934.13653564453125, 1307.543701171875, 1.972219824790954589, 0, 0, 0.83388519287109375, 0.55193793773651123, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject1
(@OGUID+3, 113768, 1, 141, 186, '0', 0, 0, 9790.1455078125, 932.15472412109375, 1308.1011962890625, 3.508116960525512695, 0, 0, -0.98325443267822265, 0.182238012552261352, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject1
(@OGUID+4, 113768, 1, 141, 186, '0', 0, 0, 9813.13671875, 936.6649169921875, 1308.404052734375, 4.607671737670898437, 0, 0, -0.74314403533935546, 0.669131457805633544, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject1
(@OGUID+5, 113768, 1, 141, 186, '0', 0, 0, 9860.51953125, 912.7969970703125, 1308.530029296875, 0.139624491333961486, 0, 0, 0.06975555419921875, 0.997564136981964111, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject1
(@OGUID+6, 113768, 1, 141, 186, '0', 0, 0, 9837.103515625, 978.41058349609375, 1306.82666015625, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject1
(@OGUID+7, 113768, 1, 141, 186, '0', 0, 0, 9714.7001953125, 990.93804931640625, 1294.8983154296875, 6.021387100219726562, 0, 0, -0.13052558898925781, 0.991444945335388183, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject1
(@OGUID+8, 113768, 1, 141, 186, '0', 0, 0, 9677.677734375, 968.15692138671875, 1293.7860107421875, 4.084071159362792968, 0, 0, -0.8910064697265625, 0.453990638256072998, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject1
(@OGUID+9, 113768, 1, 141, 186, '0', 0, 0, 9764.7001953125, 874.474365234375, 1297.418701171875, 0.645771682262420654, 0, 0, 0.317304611206054687, 0.948323667049407958, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject2
(@OGUID+10, 113768, 1, 141, 186, '0', 0, 0, 9799.23046875, 973.43914794921875, 1303.2203369140625, 2.268925428390502929, 0, 0, 0.906307220458984375, 0.422619491815567016, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject2
(@OGUID+11, 113768, 1, 141, 186, '0', 0, 0, 9797.20703125, 924.8836669921875, 1306.8704833984375, 5.113816738128662109, 0, 0, -0.55193614959716796, 0.833886384963989257, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject2
(@OGUID+12, 113768, 1, 141, 186, '0', 0, 0, 9826.576171875, 934.53009033203125, 1307.4765625, 2.617989301681518554, 0, 0, 0.965925216674804687, 0.258821308612823486, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject2
(@OGUID+13, 113768, 1, 141, 186, '0', 0, 0, 9764.15234375, 891.73529052734375, 1298.1422119140625, 4.328419685363769531, 0, 0, -0.82903671264648437, 0.559194147586822509, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject2
(@OGUID+14, 113768, 1, 141, 186, '0', 0, 0, 9836.7431640625, 947.90997314453125, 1306.714111328125, 5.602506637573242187, 0, 0, -0.33380699157714843, 0.942641437053680419, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject2
(@OGUID+15, 113768, 1, 141, 186, '0', 0, 0, 9823.7783203125, 920.981689453125, 1304.5885009765625, 3.403396368026733398, 0, 0, -0.99144458770751953, 0.130528271198272705, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject2
(@OGUID+16, 113768, 1, 141, 186, '0', 0, 0, 9805.1650390625, 933.521728515625, 1307.33935546875, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject2
(@OGUID+17, 113768, 1, 141, 186, '0', 0, 0, 9870.2900390625, 980.46697998046875, 1309.6800537109375, 4.48549652099609375, 0, 0, -0.7826080322265625, 0.622514784336090087, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject1
(@OGUID+18, 113768, 1, 141, 186, '0', 0, 0, 9761.611328125, 931.51104736328125, 1299.7672119140625, 3.054326534271240234, 0, 0, 0.999048233032226562, 0.043619260191917419, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject1
(@OGUID+19, 113768, 1, 141, 186, '0', 0, 0, 9828.7158203125, 931.17230224609375, 1306.9986572265625, 0.436331570148468017, 0, 0, 0.216439247131347656, 0.976296067237854003, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject2
(@OGUID+20, 113768, 1, 141, 186, '0', 0, 0, 9847.4248046875, 956.81597900390625, 1306.99267578125, 0.034906249493360519, 0, 0, 0.017452239990234375, 0.999847710132598876, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject2
(@OGUID+21, 113768, 1, 141, 186, '0', 0, 0, 9785.072265625, 936.801025390625, 1307.3857421875, 1.466075778007507324, 0, 0, 0.669130325317382812, 0.74314504861831665, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject2
(@OGUID+22, 113768, 1, 141, 186, '0', 0, 0, 9805.51953125, 932.68402099609375, 1309.300048828125, 5.497788906097412109, 0, 0, -0.38268280029296875, 0.923879802227020263, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject2
(@OGUID+23, 113768, 1, 141, 186, '0', 0, 0, 9875.76953125, 959.9656982421875, 1308.5509033203125, 1.064649581909179687, 0, 0, 0.507537841796875, 0.861629426479339599, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject1
(@OGUID+24, 113768, 1, 141, 186, '0', 0, 0, 9778.068359375, 966.87152099609375, 1306.5452880859375, 6.161012649536132812, 0, 0, -0.06104850769042968, 0.998134791851043701, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject2
(@OGUID+25, 113768, 1, 141, 186, '0', 0, 0, 9887.40234375, 931.87823486328125, 1307.5709228515625, 0.034906249493360519, 0, 0, 0.017452239990234375, 0.999847710132598876, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject2
(@OGUID+26, 113768, 1, 141, 186, '0', 0, 0, 9794.083984375, 935.43292236328125, 1307.495849609375, 3.857182979583740234, 0, 0, -0.93667125701904296, 0.350209832191467285, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject2
(@OGUID+27, 113768, 1, 141, 186, '0', 0, 0, 9785.58984375, 883.0936279296875, 1298.1529541015625, 6.12610626220703125, 0, 0, -0.07845878601074218, 0.996917366981506347, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject2
(@OGUID+28, 113768, 1, 141, 186, '0', 0, 0, 9834.787109375, 977.89044189453125, 1306.5548095703125, 5.078907966613769531, 0, 0, -0.56640625, 0.824126183986663818, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject2
(@OGUID+29, 113768, 1, 141, 186, '0', 0, 0, 9823.4326171875, 942.53515625, 1307.0968017578125, 1.378809213638305664, 0, 0, 0.636077880859375, 0.771624863147735595, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject2
(@OGUID+30, 113768, 1, 141, 186, '0', 0, 0, 9865.529296875, 996.1749267578125, 1309.404541015625, 0.15707901120185852, 0, 0, 0.078458786010742187, 0.996917366981506347, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject2
(@OGUID+31, 113768, 1, 141, 186, '0', 0, 0, 9858.8876953125, 912.82965087890625, 1306.2568359375, 0.471238493919372558, 0, 0, 0.233445167541503906, 0.972369968891143798, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject2
(@OGUID+32, 113768, 1, 141, 186, '0', 0, 0, 9814.17578125, 938.75042724609375, 1308.3084716796875, 1.239183306694030761, 0, 0, 0.580702781677246093, 0.814115643501281738, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject2
(@OGUID+33, 113768, 1, 141, 186, '0', 0, 0, 9818.826171875, 940.40594482421875, 1308.3074951171875, 0.977383077144622802, 0, 0, 0.469470977783203125, 0.882947921752929687, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject1
(@OGUID+34, 113768, 1, 141, 186, '0', 0, 0, 9779.5009765625, 893.6844482421875, 1297.871337890625, 2.129300594329833984, 0, 0, 0.874619483947753906, 0.484810054302215576, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject1
(@OGUID+35, 113768, 1, 141, 186, '0', 0, 0, 9733.5771484375, 963.84307861328125, 1294.39501953125, 3.45575571060180664, 0, 0, -0.98768806457519531, 0.156436234712600708, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject1
(@OGUID+36, 113768, 1, 141, 186, '0', 0, 0, 9718.4267578125, 988.63897705078125, 1295.068115234375, 3.298687219619750976, 0, 0, -0.99691677093505859, 0.078466430306434631, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject1
(@OGUID+37, 113768, 1, 141, 186, '0', 0, 0, 9876.3095703125, 979.510009765625, 1310.1600341796875, 0.139624491333961486, 0, 0, 0.06975555419921875, 0.997564136981964111, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+38, 113768, 1, 141, 186, '0', 0, 0, 9784.5791015625, 934.6805419921875, 1307.6177978515625, 2.146752834320068359, 0, 0, 0.878816604614257812, 0.477159708738327026, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject2
(@OGUID+39, 113768, 1, 141, 186, '0', 0, 0, 9779.3818359375, 871.46527099609375, 1297.429931640625, 4.59021615982055664, 0, 0, -0.74895572662353515, 0.662620067596435546, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject1
(@OGUID+40, 113768, 1, 141, 186, '0', 0, 0, 9809.50390625, 936.32305908203125, 1307.838134765625, 3.90954136848449707, 0, 0, -0.92718315124511718, 0.37460830807685852, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject2
(@OGUID+41, 113768, 1, 141, 186, '0', 0, 0, 9810.8125, 976.96820068359375, 1304.439208984375, 1.029743075370788574, 0, 0, 0.492423057556152343, 0.870355963706970214, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject2
(@OGUID+42, 113768, 1, 141, 186, '0', 0, 0, 9777.8388671875, 960.312744140625, 1306.6773681640625, 4.206246376037597656, 0, 0, -0.86162853240966796, 0.50753939151763916, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject2
(@OGUID+43, 113768, 1, 141, 186, '0', 0, 0, 9764.2373046875, 946.02191162109375, 1305.3731689453125, 0.122172988951206207, 0, 0, 0.061048507690429687, 0.998134791851043701, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject2
(@OGUID+44, 113768, 1, 141, 186, '0', 0, 0, 9800.3232421875, 925.2529296875, 1306.9283447265625, 0.837757468223571777, 0, 0, 0.406736373901367187, 0.913545548915863037, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject2
(@OGUID+45, 113768, 1, 141, 186, '0', 0, 0, 9727.2451171875, 969.8856201171875, 1294.6402587890625, 4.468043327331542968, 0, 0, -0.7880105972290039, 0.615661680698394775, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject1
(@OGUID+46, 113768, 1, 141, 186, '0', 0, 0, 9786.6318359375, 932.9698486328125, 1307.8604736328125, 4.345870018005371093, 0, 0, -0.82412624359130859, 0.566406130790710449, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject2
(@OGUID+47, 113768, 1, 141, 186, '0', 0, 0, 9750.5439453125, 904.02850341796875, 1295.517333984375, 0.261798173189163208, 0, 0, 0.130525588989257812, 0.991444945335388183, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject2
(@OGUID+48, 113768, 1, 141, 186, '0', 0, 0, 9796.9736328125, 926.81097412109375, 1306.8636474609375, 2.356194972991943359, 0, 0, 0.923879623413085937, 0.382683247327804565, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject1
(@OGUID+49, 113768, 1, 141, 186, '0', 0, 0, 9721.951171875, 987.2344970703125, 1295.744140625, 1.85004889965057373, 0, 0, 0.798635482788085937, 0.60181504487991333, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject1
(@OGUID+50, 113768, 1, 141, 186, '0', 0, 0, 9674.05078125, 940.224609375, 1290.3349609375, 5.131268978118896484, 0, 0, -0.54463863372802734, 0.838670849800109863, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject1
(@OGUID+51, 113768, 1, 141, 186, '0', 0, 0, 9671.5009765625, 943.3984375, 1290.744873046875, 5.078907966613769531, 0, 0, -0.56640625, 0.824126183986663818, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject1
(@OGUID+52, 113768, 1, 141, 186, '0', 0, 0, 9772.0712890625, 896.5762939453125, 1297.1168212890625, 1.780233979225158691, 0, 0, 0.7771453857421875, 0.629321098327636718, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject2
(@OGUID+53, 113768, 1, 141, 186, '0', 0, 0, 9857.7548828125, 973.2294921875, 1304.809326171875, 4.799657344818115234, 0, 0, -0.67558956146240234, 0.737277925014495849, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject2
(@OGUID+54, 113768, 1, 141, 186, '0', 0, 0, 9841.9345703125, 978.24652099609375, 1306.6475830078125, 5.393068790435791015, 0, 0, -0.43051052093505859, 0.902585566043853759, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject2
(@OGUID+55, 113768, 1, 141, 186, '0', 0, 0, 9830.556640625, 928.17413330078125, 1306.2283935546875, 2.44346022605895996, 0, 0, 0.939692497253417968, 0.34202045202255249, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject2
(@OGUID+56, 113768, 1, 141, 186, '0', 0, 0, 9882.2900390625, 957.22601318359375, 1311.06005859375, 2.268925428390502929, 0, 0, 0.906307220458984375, 0.422619491815567016, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject2
(@OGUID+57, 113768, 1, 141, 186, '0', 0, 0, 9895.0791015625, 964.6641845703125, 1310.525390625, 0.593410074710845947, 0, 0, 0.292370796203613281, 0.95630502700805664, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject2
(@OGUID+58, 113768, 1, 141, 186, '0', 0, 0, 9860.888671875, 910.63336181640625, 1306.1309814453125, 2.844882726669311523, 0, 0, 0.989015579223632812, 0.147811368107795715, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject1
(@OGUID+59, 113768, 1, 141, 186, '0', 0, 0, 9683.44140625, 933.64581298828125, 1290.6617431640625, 0.837757468223571777, 0, 0, 0.406736373901367187, 0.913545548915863037, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject1
(@OGUID+60, 113768, 1, 141, 186, '0', 0, 0, 9881.388671875, 956.99261474609375, 1308.8040771484375, 2.600535154342651367, 0, 0, 0.963629722595214843, 0.26724100112915039, 300, 255, 1, 48999); -- Brightly Colored Egg (Area: Dolanaar - Difficulty: 0) CreateObject2

UPDATE `pool_template` SET `description`='Noblegarden - Dolanaar - Brightly Colored Egg' WHERE `entry`=@POOL;

DELETE FROM `pool_members` WHERE `type`=1 AND `spawnId` BETWEEN @OGUID+0 AND @OGUID+60;
INSERT INTO `pool_members` (`type`, `spawnId`, `poolSpawnId`, `chance`, `description`) VALUES
(1, @OGUID+0, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+1, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+2, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+3, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+4, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+5, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+6, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+7, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+8, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+9, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+10, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+11, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+12, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+13, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+14, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+15, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+16, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+17, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+18, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+19, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+20, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+21, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+22, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+23, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+24, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+25, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+26, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+27, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+28, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+29, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+30, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+31, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+32, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+33, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+34, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+35, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+36, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+37, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+38, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+39, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+40, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+41, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+42, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+43, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+44, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+45, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+46, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+47, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+48, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+49, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+50, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+51, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+52, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+53, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+54, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+55, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+56, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+57, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+58, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+59, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+60, @POOL, 0, 'Noblegarden - Brightly Colored Egg');

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(@EVENT, @CGUID+0),
(@EVENT, @CGUID+1);
