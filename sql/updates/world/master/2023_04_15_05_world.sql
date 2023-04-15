SET @CGUID := 3000069;
SET @OGUID := 3001502;
SET @POOL := 5700;
SET @EVENT := 9;

-- Equipments
UPDATE `creature_equip_template` SET `VerifiedBuild`=48999 WHERE (`ID`=2 AND `CreatureID` IN (43464,1228,1226)) OR (`ID`=1 AND `CreatureID` IN (41335,41181,40951,40950,12996,12427,11941,9980,6806,6328,6119,5612,2878,2326,1699,1691,1690,1378,1377,1375,1373,1273,1269,1268,1267,1252,1247,1245,1241,1240,1234,1232,1231,1229,727));

-- Models
UPDATE `creature_model_info` SET `VerifiedBuild`=48999 WHERE `DisplayID` IN (1132, 30586, 42203, 36342, 35581, 32403, 33381, 33279, 33278, 604, 31934, 22769, 1782, 1811, 32194, 28360, 25587, 28302, 12474, 11899, 9253, 5525, 5042, 4864, 3607, 6929, 5040, 3433, 3415, 3435, 3414, 3430, 3427, 5105, 5106, 3405, 3398, 3438, 3417, 3440, 3441, 1684, 1376, 3434, 3513, 3422, 3425, 3420, 3436, 1622, 3558, 3431, 10215, 3429, 607, 1608, 1598);
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=48999 WHERE `DisplayID`=28306;

UPDATE `creature_template_model` SET `VerifiedBuild`=48999 WHERE (`Idx`=0 AND `CreatureID` IN (63074,1374,175155,37198,1125,727,1690,1226,1234,11941,1375,2878,12427,1252,1238,24110,1228,63075,43701,1377,1691,1247,40950,1267,5612,1692,41181,1231,1872,6328,61690,1373,1273,2326,43464,33975,1232,1269,6119,1245,41188,12996,40951,1378,37518,41478,1241,6806,41335,47396,5568,1268,1240,9980,1699,41189,1229,43224,48935,61689)) OR (`Idx`=1 AND `CreatureID` IN (727,24110,41181,41188,12996,41335,5568,41189,43224)) OR (`Idx`=3 AND `CreatureID` IN (41181,41335,5568)) OR (`Idx`=2 AND `CreatureID` IN (41181,41335,5568,43224));

-- Scaling
DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (175155,37518,37198));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(175155, 0, 0, 0, 74, 48999),
(37518, 0, 0, 0, 1477, 48999),
(37198, 0, 0, 0, 1477, 48999);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=48999 WHERE (`DifficultyID`=0 AND `Entry` IN (63075,61690,61689,48935,47396,43701,43464,43224,41478,41335,41189,41188,41181,40951,40950,24110,12996,12427,11941,9980,6806,6328,6119,5612,5568,2878,2326,1872,1699,1692,1691,1690,1378,1377,1375,1374,1373,1273,1269,1268,1267,1252,1247,1245,1241,1240,1238,1234,1232,1231,1229,1228,1226,1125,727));
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `VerifiedBuild`=48999 WHERE (`Entry`=63074 AND `DifficultyID`=0);

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 32799, 0, 1, 131, '0', 0, 0, 0, 0, -5596.77001953125, -506.9320068359375, 401.2413330078125, 2.513274192810058593, 120, 0, 0, 361340, 28784, 0, 0, 0, 0, 48999), -- Spring Collector (Area: Kharanos - Difficulty: 0) CreateObject1
(@CGUID+1, 32836, 0, 1, 131, '0', 0, 0, 0, 1, -5600.47021484375, -512.7509765625, 401.5533447265625, 1.588249564170837402, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48999); -- Noblegarden Vendor (Area: Kharanos - Difficulty: 0) CreateObject1

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+59;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 113768, 0, 1, 131, '0', 0, 0, -5641.919921875, -530.1510009765625, 404.553009033203125, 1.623155713081359863, 0, 0, 0.725374221801757812, 0.688354730606079101, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject1
(@OGUID+1, 113768, 0, 1, 131, '0', 0, 0, -5625.35009765625, -523.54400634765625, 403.863006591796875, 0.680676698684692382, 0, 0, 0.333806037902832031, 0.942641794681549072, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject1
(@OGUID+2, 113768, 0, 1, 131, '0', 0, 0, -5551.1201171875, -475.1099853515625, 397.944000244140625, 1.710421562194824218, 0, 0, 0.754709243774414062, 0.656059443950653076, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject1
(@OGUID+3, 113768, 0, 1, 131, '0', 0, 0, -5574.18994140625, -515.8489990234375, 402.803009033203125, 4.1538848876953125, 0, 0, -0.8746194839477539, 0.484810054302215576, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject1
(@OGUID+4, 113768, 0, 1, 131, '0', 0, 0, -5583.83984375, -476.837005615234375, 397.76300048828125, 1.815141916275024414, 0, 0, 0.788010597229003906, 0.615661680698394775, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject1
(@OGUID+5, 113768, 0, 1, 131, '0', 0, 0, -5572.02978515625, -457.20599365234375, 403.20599365234375, 3.769911527633666992, 0, 0, -0.95105648040771484, 0.309017121791839599, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject1
(@OGUID+6, 113768, 0, 1, 131, '0', 0, 0, -5606.81005859375, -446.06500244140625, 403.97900390625, 0.314158439636230468, 0, 0, 0.156434059143066406, 0.987688362598419189, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+7, 113768, 0, 1, 131, '0', 0, 0, -5637.740234375, -529.75299072265625, 404.60101318359375, 1.117009282112121582, 0, 0, 0.529918670654296875, 0.84804844856262207, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+8, 113768, 0, 1, 131, '0', 0, 0, -5591.89990234375, -508.066986083984375, 401.45001220703125, 3.124123096466064453, 0, 0, 0.99996185302734375, 0.008734640665352344, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+9, 113768, 0, 1, 131, '0', 0, 0, -5639, -504.024993896484375, 396.66900634765625, 5.6897735595703125, 0, 0, -0.29237174987792968, 0.956304728984832763, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject1
(@OGUID+10, 113768, 0, 1, 131, '0', 0, 0, -5651.759765625, -504.99700927734375, 396.85101318359375, 6.195919513702392578, 0, 0, -0.04361915588378906, 0.999048233032226562, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+11, 113768, 0, 1, 131, '0', 0, 0, -5590.93994140625, -497.847991943359375, 399.436004638671875, 5.288348197937011718, 0, 0, -0.4771585464477539, 0.878817260265350341, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+12, 113768, 0, 1, 131, '0', 0, 0, -5561.3798828125, -454.769012451171875, 403.0260009765625, 4.014260292053222656, 0, 0, -0.90630722045898437, 0.422619491815567016, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+13, 113768, 0, 1, 131, '0', 0, 0, -5588.740234375, -514.17401123046875, 404.09600830078125, 0.139624491333961486, 0, 0, 0.06975555419921875, 0.997564136981964111, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+14, 113768, 0, 1, 131, '0', 0, 0, -5629.68017578125, -477.993011474609375, 397.100006103515625, 4.066620349884033203, 0, 0, -0.89493370056152343, 0.44619917869567871, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+15, 113768, 0, 1, 131, '0', 0, 0, -5584.02978515625, -462.618988037109375, 402.3070068359375, 0.523597896099090576, 0, 0, 0.258818626403808593, 0.965925931930541992, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+16, 113768, 0, 1, 131, '0', 0, 0, -5614.0498046875, -522.4959716796875, 402.70599365234375, 3.700104713439941406, 0, 0, -0.96126079559326171, 0.275640487670898437, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+17, 113768, 0, 1, 131, '0', 0, 0, -5577.18994140625, -521.81402587890625, 401.47698974609375, 6.003933906555175781, 0, 0, -0.13917255401611328, 0.990268170833587646, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+18, 113768, 0, 1, 131, '0', 0, 0, -5594.56005859375, -460.384002685546875, 402.493011474609375, 4.782202720642089843, 0, 0, -0.68199825286865234, 0.731353819370269775, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+19, 113768, 0, 1, 131, '0', 0, 0, -5535.89990234375, -504.5, 401.279998779296875, 4.310965538024902343, 0, 0, -0.83388519287109375, 0.55193793773651123, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+20, 113768, 0, 1, 131, '0', 0, 0, -5578.06982421875, -508.540985107421875, 404.09600830078125, 4.607671737670898437, 0, 0, -0.74314403533935546, 0.669131457805633544, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+21, 113768, 0, 1, 131, '0', 0, 0, -5597.52001953125, -476.048004150390625, 396.980010986328125, 3.752462387084960937, 0, 0, -0.95371627807617187, 0.300707906484603881, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+22, 113768, 0, 1, 131, '0', 0, 0, -5593.080078125, -490.4949951171875, 397.649993896484375, 4.991643905639648437, 0, 0, -0.60181427001953125, 0.798636078834533691, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+23, 113768, 0, 1, 131, '0', 0, 0, -5578.14990234375, -516.45098876953125, 404.09600830078125, 5.759587764739990234, 0, 0, -0.25881862640380859, 0.965925931930541992, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+24, 113768, 0, 1, 131, '0', 0, 0, -5645.81005859375, -506.29998779296875, 396.864990234375, 4.276057243347167968, 0, 0, -0.84339141845703125, 0.537299633026123046, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+25, 113768, 0, 1, 131, '0', 0, 0, -5631.669921875, -478.305999755859375, 397.141998291015625, 5.794494152069091796, 0, 0, -0.24192142486572265, 0.970295846462249755, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+26, 113768, 0, 1, 131, '0', 0, 0, -5654.43994140625, -499.233001708984375, 397.0419921875, 2.268925428390502929, 0, 0, 0.906307220458984375, 0.422619491815567016, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+27, 113768, 0, 1, 131, '0', 0, 0, -5588.47021484375, -506.386993408203125, 401.389007568359375, 0.331610709428787231, 0, 0, 0.16504669189453125, 0.986285746097564697, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+28, 113768, 0, 1, 131, '0', 0, 0, -5545.60009765625, -497.102996826171875, 402.079010009765625, 5.602506637573242187, 0, 0, -0.33380699157714843, 0.942641437053680419, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Thunderbrew Distillery - Difficulty: 0) CreateObject2
(@OGUID+29, 113768, 0, 1, 131, '0', 0, 0, -5591.83984375, -501.423004150390625, 400.1099853515625, 1.082102894783020019, 0, 0, 0.51503753662109375, 0.857167601585388183, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+30, 113768, 0, 1, 131, '0', 0, 0, -5638.41015625, -530.447998046875, 404.927001953125, 2.460912704467773437, 0, 0, 0.942641258239746093, 0.333807557821273803, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject1
(@OGUID+31, 113768, 0, 1, 131, '0', 0, 0, -5633.7099609375, -500.428009033203125, 396.66900634765625, 3.78736734390258789, 0, 0, -0.94832324981689453, 0.317305892705917358, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+32, 113768, 0, 1, 131, '0', 0, 0, -5570.3701171875, -454.209991455078125, 402.22601318359375, 3.22885894775390625, 0, 0, -0.99904823303222656, 0.043619260191917419, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+33, 113768, 0, 1, 131, '0', 0, 0, -5640.06982421875, -511.8599853515625, 398.785003662109375, 4.258606910705566406, 0, 0, -0.84804725646972656, 0.529920578002929687, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Thunderbrew Distillery - Difficulty: 0) CreateObject2
(@OGUID+34, 113768, 0, 1, 131, '0', 0, 0, -5659.6201171875, -501.9949951171875, 397.35400390625, 0.418878614902496337, 0, 0, 0.207911491394042968, 0.978147625923156738, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+35, 113768, 0, 1, 131, '0', 0, 0, -5666.080078125, -496.1409912109375, 397.2550048828125, 4.293513298034667968, 0, 0, -0.8386697769165039, 0.544640243053436279, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+36, 113768, 0, 1, 131, '0', 0, 0, -5585.18994140625, -461.907989501953125, 402.358001708984375, 4.625123500823974609, 0, 0, -0.73727703094482421, 0.67559051513671875, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+37, 113768, 0, 1, 131, '0', 0, 0, -5543.06982421875, -475.489013671875, 397.93798828125, 1.186823248863220214, 0, 0, 0.559192657470703125, 0.829037725925445556, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+38, 113768, 0, 1, 131, '0', 0, 0, -5588.14990234375, -451.483001708984375, 403.20599365234375, 6.265733242034912109, 0, 0, -0.00872611999511718, 0.999961912631988525, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+39, 113768, 0, 1, 131, '0', 0, 0, -5655.43994140625, -507.667999267578125, 397.51800537109375, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+40, 113768, 0, 1, 131, '0', 0, 0, -5592.35009765625, -477.011993408203125, 396.980010986328125, 4.468043327331542968, 0, 0, -0.7880105972290039, 0.615661680698394775, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject1
(@OGUID+41, 113768, 0, 1, 131, '0', 0, 0, -5615.9501953125, -446.212005615234375, 404.558990478515625, 4.084071159362792968, 0, 0, -0.8910064697265625, 0.453990638256072998, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+42, 113768, 0, 1, 131, '0', 0, 0, -5628.72021484375, -497.47698974609375, 397.230987548828125, 5.410521507263183593, 0, 0, -0.42261791229248046, 0.906307935714721679, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+43, 113768, 0, 1, 131, '0', 0, 0, -5653.39990234375, -498.02099609375, 396.873992919921875, 1.291541695594787597, 0, 0, 0.60181427001953125, 0.798636078834533691, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+44, 113768, 0, 1, 131, '0', 0, 0, -5572.72998046875, -462.92999267578125, 402.26800537109375, 2.879789113998413085, 0, 0, 0.991444587707519531, 0.130528271198272705, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+45, 113768, 0, 1, 131, '0', 0, 0, -5589.14990234375, -477.10699462890625, 397.566009521484375, 1.588248729705810546, 0, 0, 0.713250160217285156, 0.700909554958343505, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+46, 113768, 0, 1, 131, '0', 0, 0, -5634.759765625, -478.43499755859375, 396.985992431640625, 4.799657344818115234, 0, 0, -0.67558956146240234, 0.737277925014495849, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+47, 113768, 0, 1, 131, '0', 0, 0, -5554.669921875, -446.8380126953125, 403.45098876953125, 2.111847877502441406, 0, 0, 0.870355606079101562, 0.492423713207244873, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+48, 113768, 0, 1, 131, '0', 0, 0, -5550.990234375, -438.001007080078125, 405.385009765625, 1.588248729705810546, 0, 0, 0.713250160217285156, 0.700909554958343505, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+49, 113768, 0, 1, 131, '0', 0, 0, -5636.759765625, -501.881011962890625, 396.66900634765625, 5.270895957946777343, 0, 0, -0.48480892181396484, 0.87462007999420166, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+50, 113768, 0, 1, 131, '0', 0, 0, -5639.81982421875, -477.9429931640625, 396.8380126953125, 4.799657344818115234, 0, 0, -0.67558956146240234, 0.737277925014495849, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+51, 113768, 0, 1, 131, '0', 0, 0, -5537.10009765625, -475.811004638671875, 398.22100830078125, 4.642575740814208984, 0, 0, -0.731353759765625, 0.681998312473297119, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject1
(@OGUID+52, 113768, 0, 1, 131, '0', 0, 0, -5626.330078125, -478.569000244140625, 396.980010986328125, 2.495818138122558593, 0, 0, 0.948323249816894531, 0.317305892705917358, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+53, 113768, 0, 1, 131, '0', 0, 0, -5603.31982421875, -514.6619873046875, 401.82598876953125, 1.500982880592346191, 0, 0, 0.681998252868652343, 0.731353819370269775, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject1
(@OGUID+54, 113768, 0, 1, 131, '0', 0, 0, -5590.85009765625, -507.5050048828125, 404.09600830078125, 5.497788906097412109, 0, 0, -0.38268280029296875, 0.923879802227020263, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject1
(@OGUID+55, 113768, 0, 1, 131, '0', 0, 0, -5531.89990234375, -461.553985595703125, 402.1619873046875, 5.131268978118896484, 0, 0, -0.54463863372802734, 0.838670849800109863, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+56, 113768, 0, 1, 131, '0', 0, 0, -5545.35986328125, -475.141998291015625, 397.95001220703125, 0.366517573595046997, 0, 0, 0.182234764099121093, 0.98325502872467041, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+57, 113768, 0, 1, 131, '0', 0, 0, -5549.990234375, -499.27099609375, 401.70098876953125, 5.881760597229003906, 0, 0, -0.19936752319335937, 0.979924798011779785, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+58, 113768, 0, 1, 131, '0', 0, 0, -5563.830078125, -535.073974609375, 409.95599365234375, 5.201082706451416015, 0, 0, -0.51503753662109375, 0.857167601585388183, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2
(@OGUID+59, 113768, 0, 1, 131, '0', 0, 0, -5561.02978515625, -445.5830078125, 403.800994873046875, 5.410521507263183593, 0, 0, -0.42261791229248046, 0.906307935714721679, 300, 255, 1, 48999); -- Brightly Colored Egg (Area: Kharanos - Difficulty: 0) CreateObject2

UPDATE `pool_template` SET `description`='Noblegarden - Kharanos - Brightly Colored Egg' WHERE `entry`=@POOL;

DELETE FROM `pool_members` WHERE `type`=1 AND `spawnId` BETWEEN @OGUID+0 AND @OGUID+59;
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
(1, @OGUID+59, @POOL, 0, 'Noblegarden - Brightly Colored Egg');

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(@EVENT, @CGUID+0),
(@EVENT, @CGUID+1);
