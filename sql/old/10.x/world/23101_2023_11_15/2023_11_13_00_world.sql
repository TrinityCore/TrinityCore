SET @CGUID := 6000868;
SET @OGUID := 6000589;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+31;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 93716, 1481, 7705, 7712, '0', 0, 0, 0, 2, 1476.99658203125, 1905.076416015625, 68.471893310546875, 4.466448783874511718, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Doom Slayer (Area: Illidari Foothold - Difficulty: 0) CreateObject2 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+1, 96930, 1481, 7705, 7712, '0', 0, 0, 0, 1, 1475, 1897.23388671875, 69.34722137451171875, 1.570796370506286621, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Demon Hunter (Area: Illidari Foothold - Difficulty: 0) CreateObject2 (Auras: 222589 - Glaive Anim Replacement)
(@CGUID+2, 97014, 1481, 7705, 7712, '0', 0, 0, 0, 1, 1510.0625, 1805.9930419921875, 46.97104263305664062, 3.425289869308471679, 120, 0, 0, 2485, 3801, 0, NULL, NULL, NULL, NULL, 52106), -- Vile Soulmaster (Area: Illidari Foothold - Difficulty: 0) CreateObject2 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+3, 102724, 1481, 7705, 7712, '0', 0, 0, 0, 1, 1506.7916259765625, 1805.35595703125, 47.07062530517578125, 3.285434961318969726, 120, 0, 0, 2485, 3801, 0, NULL, NULL, NULL, NULL, 52106), -- Vile Soulmaster (Area: Illidari Foothold - Difficulty: 0) CreateObject2 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+4, 96278, 1481, 7705, 7712, '0', 0, 0, 0, 0, 1514.013916015625, 1792.12158203125, 47.17845535278320312, 2.605477333068847656, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Burning Soulstalker (Area: Illidari Foothold - Difficulty: 0) CreateObject2 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+5, 96278, 1481, 7705, 7712, '0', 0, 0, 0, 0, 1508.46875, 1793.5625, 47.26955795288085937, 2.449116945266723632, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Burning Soulstalker (Area: Illidari Foothold - Difficulty: 0) CreateObject2 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+6, 102724, 1481, 7705, 7712, '0', 0, 0, 0, 1, 1509.1597900390625, 1798.732666015625, 46.9756622314453125, 2.983711004257202148, 120, 0, 0, 2485, 3801, 0, NULL, NULL, NULL, NULL, 52106), -- Vile Soulmaster (Area: Illidari Foothold - Difficulty: 0) CreateObject2 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+7, 96931, 1481, 7705, 7712, '0', 0, 0, 0, 1, 1498.2274169921875, 1799.704833984375, 48.01584625244140625, 5.465071678161621093, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Demon Hunter (Area: Illidari Foothold - Difficulty: 0) CreateObject2 (Auras: 222589 - Glaive Anim Replacement)
(@CGUID+8, 96930, 1481, 7705, 7712, '0', 0, 0, 0, 1, 1499.2603759765625, 1796.8958740234375, 48.08179855346679687, 0.455126106739044189, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Demon Hunter (Area: Illidari Foothold - Difficulty: 0) CreateObject2 (Auras: 222589 - Glaive Anim Replacement)
(@CGUID+9, 96931, 1481, 7705, 7712, '0', 0, 0, 0, 1, 1498.359375, 1802.69970703125, 47.79532241821289062, 5.956250667572021484, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Demon Hunter (Area: Illidari Foothold - Difficulty: 0) CreateObject2 (Auras: 222589 - Glaive Anim Replacement)
(@CGUID+10, 96278, 1481, 7705, 7712, '0', 0, 0, 0, 0, 1510.0625, 1805.9930419921875, 46.97104263305664062, 4.229665279388427734, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Burning Soulstalker (Area: Illidari Foothold - Difficulty: 0) CreateObject2 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+11, 97034, 1481, 7705, 7712, '0', 0, 0, 0, 1, 1356.09033203125, 1681.0069580078125, 62.09027862548828125, 0.386698365211486816, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Fury Champion (Area: Illidari Foothold - Difficulty: 0) CreateObject2 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+12, 97034, 1481, 7705, 7712, '0', 0, 0, 0, 1, 1359.4896240234375, 1672.2760009765625, 61.27219009399414062, 0.79650193452835083, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Fury Champion (Area: Illidari Foothold - Difficulty: 0) CreateObject2 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+13, 93716, 1481, 7705, 7712, '0', 0, 0, 0, 2, 1361.8819580078125, 1669.30908203125, 61.05299758911132812, 0.866936087608337402, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Doom Slayer (Area: Illidari Foothold - Difficulty: 0) CreateObject2 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+14, 93716, 1481, 7705, 7712, '0', 0, 0, 0, 2, 1365.59033203125, 1664.435791015625, 61.05555343627929687, 1.274535417556762695, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Doom Slayer (Area: Illidari Foothold - Difficulty: 0) CreateObject2 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+15, 97034, 1481, 7705, 7712, '0', 0, 0, 0, 1, 1352.0694580078125, 1676.623291015625, 63.0538177490234375, 0.738357305526733398, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Fury Champion (Area: Illidari Foothold - Difficulty: 0) CreateObject2 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+16, 96930, 1481, 7705, 7712, '0', 0, 0, 0, 1, 1365.782958984375, 1684.9566650390625, 60.32382965087890625, 3.528020143508911132, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Demon Hunter (Area: Illidari Foothold - Difficulty: 0) CreateObject2 (Auras: 222589 - Glaive Anim Replacement)
(@CGUID+17, 96931, 1481, 7705, 7712, '0', 0, 0, 0, 1, 1371.486083984375, 1678.84375, 60.92013931274414062, 3.167960882186889648, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Demon Hunter (Area: Illidari Foothold - Difficulty: 0) CreateObject2 (Auras: 222589 - Glaive Anim Replacement)
(@CGUID+18, 96931, 1481, 7705, 7712, '0', 0, 0, 0, 1, 1368.7742919921875, 1681.7603759765625, 60.49478912353515625, 4.066812038421630859, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Demon Hunter (Area: Illidari Foothold - Difficulty: 0) CreateObject2 (Auras: 222589 - Glaive Anim Replacement)
(@CGUID+19, 94655, 1481, 7705, 7712, '0', 0, 0, 0, 0, 1383.6805419921875, 1686.3853759765625, 59.04623031616210937, 2.838560819625854492, 120, 10, 0, 1129, 0, 1, NULL, NULL, NULL, NULL, 52106), -- Soul Leech (Area: Illidari Foothold - Difficulty: 0) CreateObject2
(@CGUID+20, 96931, 1481, 7705, 7712, '0', 0, 0, 0, 1, 1392.5816650390625, 1723.0069580078125, 61.5545654296875, 4.250725269317626953, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Demon Hunter (Area: Illidari Foothold - Difficulty: 0) CreateObject1 (Auras: 42459 - Dual Wield, 222589 - Glaive Anim Replacement)
(@CGUID+21, 97600, 1481, 7705, 7712, '0', 0, 0, 0, 1, 1465.7132568359375, 1720.3843994140625, 47.92474365234375, 5.59477090835571289, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Demon Hunter (Area: Illidari Foothold - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+22, 96930, 1481, 7705, 7712, '0', 0, 0, 0, 1, 1442.3642578125, 1804.89111328125, 57.86596298217773437, 4.945046424865722656, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Demon Hunter (Area: Illidari Foothold - Difficulty: 0) CreateObject1 (Auras: 222589 - Glaive Anim Replacement, 42459 - Dual Wield)
(@CGUID+23, 96930, 1481, 7705, 7712, '0', 0, 0, 0, 1, 1443.4580078125, 1815.0545654296875, 59.5240325927734375, 4.800396442413330078, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Demon Hunter (Area: Illidari Foothold - Difficulty: 0) CreateObject1 (Auras: 222589 - Glaive Anim Replacement, 42459 - Dual Wield)
(@CGUID+24, 96930, 1481, 7705, 7712, '0', 0, 0, 0, 1, 1452.907958984375, 1824.5103759765625, 67.13390350341796875, 1.543815851211547851, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Demon Hunter (Area: Illidari Foothold - Difficulty: 0) CreateObject1 (Auras: 222589 - Glaive Anim Replacement, 42459 - Dual Wield)
(@CGUID+25, 113924, 1481, 7705, 7712, '0', 0, 0, 0, 1, 1465.8853759765625, 1783.095458984375, 54.67144775390625, 2.351651668548583984, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Illidari Starr (Area: Illidari Foothold - Difficulty: 0) CreateObject1 (Auras: 42459 - Dual Wield)
(@CGUID+26, 113927, 1481, 7705, 7712, '0', 0, 0, 0, 1, 1460.96533203125, 1778.5191650390625, 54.53687286376953125, 2.251032590866088867, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Illidari Kilbride (Area: Illidari Foothold - Difficulty: 0) CreateObject1 (Auras: 42459 - Dual Wield)
(@CGUID+27, 97599, 1481, 7705, 7712, '0', 0, 0, 0, 0, 1470.9791259765625, 1776.2882080078125, 54.77161407470703125, 2.846484661102294921, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Demon Hunter (Area: Illidari Foothold - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+28, 97600, 1481, 7705, 7712, '0', 0, 0, 0, 0, 1451.0225830078125, 1758.0885009765625, 54.50476837158203125, 0.00523577444255352, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Demon Hunter (Area: Illidari Foothold - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+29, 97599, 1481, 7705, 7712, '0', 0, 0, 0, 0, 1467.1597900390625, 1772.623291015625, 54.73676300048828125, 1.639232635498046875, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Demon Hunter (Area: Illidari Foothold - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+30, 97599, 1481, 7705, 7712, '0', 0, 0, 0, 1, 1470.421875, 1775.0364990234375, 54.44496536254882812, 1.030808806419372558, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Demon Hunter (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+31, 99650, 1481, 7705, 7712, '0', 0, 0, 0, 0, 1535.0521240234375, 1793.603271484375, 45.57520294189453125, 0.04557855799794197, 120, 10, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 52106); -- Thornclaw Broodling (Area: Illidari Foothold - Difficulty: 0) CreateObject1 (possible waypoints or random movement)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+31;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '151597'), -- Doom Slayer - 151597 - No NPC Damage Below 45-90%
(@CGUID+1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '222589'), -- Demon Hunter - 222589 - Glaive Anim Replacement
(@CGUID+2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '151597'), -- Vile Soulmaster - 151597 - No NPC Damage Below 45-90%
(@CGUID+3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '151597'), -- Vile Soulmaster - 151597 - No NPC Damage Below 45-90%
(@CGUID+4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '151597'), -- Burning Soulstalker - 151597 - No NPC Damage Below 45-90%
(@CGUID+5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '151597'), -- Burning Soulstalker - 151597 - No NPC Damage Below 45-90%
(@CGUID+6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '151597'), -- Vile Soulmaster - 151597 - No NPC Damage Below 45-90%!
(@CGUID+7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '222589'), -- Demon Hunter - 222589 - Glaive Anim Replacement
(@CGUID+8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '222589'), -- Demon Hunter - 222589 - Glaive Anim Replacement
(@CGUID+9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '222589'), -- Demon Hunter - 222589 - Glaive Anim Replacement
(@CGUID+10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '151597'), -- Burning Soulstalker - 151597 - No NPC Damage Below 45-90%
(@CGUID+11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '151597'), -- Fury Champion - 151597 - No NPC Damage Below 45-90%
(@CGUID+12, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '151597'), -- Fury Champion - 151597 - No NPC Damage Below 45-90%
(@CGUID+13, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '151597'), -- Doom Slayer - 151597 - No NPC Damage Below 45-90%
(@CGUID+14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '151597'), -- Doom Slayer - 151597 - No NPC Damage Below 45-90%
(@CGUID+15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '151597'), -- Fury Champion - 151597 - No NPC Damage Below 45-90%
(@CGUID+16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '222589'), -- Demon Hunter - 222589 - Glaive Anim Replacement
(@CGUID+17, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '222589'), -- Demon Hunter - 222589 - Glaive Anim Replacement
(@CGUID+18, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '222589'), -- Demon Hunter - 222589 - Glaive Anim Replacement
(@CGUID+20, 0, 64385, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '42459 222589'), -- Demon Hunter - 42459 - Dual Wield, 222589 - Glaive Anim Replacement
(@CGUID+21, 0, 64385, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Demon Hunter
(@CGUID+22, 0, 64385, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '222589 42459'), -- Demon Hunter - 222589 - Glaive Anim Replacement, 42459 - Dual Wield
(@CGUID+23, 0, 64385, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '222589 42459'), -- Demon Hunter - 222589 - Glaive Anim Replacement, 42459 - Dual Wield
(@CGUID+24, 0, 64385, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '222589 42459'), -- Demon Hunter - 222589 - Glaive Anim Replacement, 42459 - Dual Wield
(@CGUID+27, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Demon Hunter
(@CGUID+28, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Demon Hunter
(@CGUID+29, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Demon Hunter
(@CGUID+30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- Demon Hunter

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+8;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 245170, 1481, 7705, 7712, '0', 0, 0, 1479, 1815.93408203125, 55.69550323486328125, 5.333498954772949218, 0, 0, -0.4571990966796875, 0.889364361763000488, 120, 255, 0, 52106), -- Demon Ward (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@OGUID+1, 245170, 1481, 7705, 7712, '0', 0, 0, 1406.3055419921875, 1691.470458984375, 54.59955596923828125, 4.309918403625488281, 0, 0, -0.83417415618896484, 0.551501154899597167, 120, 255, 0, 52106), -- Demon Ward (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@OGUID+2, 245170, 1481, 7705, 7712, '0', 0, 0, 1472.8125, 1760.3004150390625, 54.244842529296875, 5.558539390563964843, 0, 0, -0.3544473648071289, 0.935075938701629638, 120, 255, 0, 52106), -- Demon Ward (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@OGUID+3, 245170, 1481, 7705, 7712, '0', 0, 0, 1434.53125, 1694.576416015625, 54.8055572509765625, 5.266389846801757812, 0, 0, -0.48677825927734375, 0.873525559902191162, 120, 255, 0, 52106), -- Demon Ward (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@OGUID+4, 245170, 1481, 7705, 7712, '0', 0, 0, 1468.4427490234375, 1718.138916015625, 47.31189727783203125, 5.480889797210693359, 0, 0, -0.39047527313232421, 0.920613408088684082, 120, 255, 0, 52106), -- Demon Ward (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@OGUID+5, 254866, 1481, 7705, 7712, '0', 0, 0, 1430.0225830078125, 1709.295166015625, 54.391815185546875, 6.178468227386474609, 0, 0, -0.05233478546142578, 0.998629570007324218, 120, 255, 1, 52106), -- Anvil (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@OGUID+6, 254867, 1481, 7705, 7712, '0', 0, 0, 1427.8160400390625, 1707.498291015625, 54.44990921020507812, 2.871063947677612304, 0, 0, 0.990865707397460937, 0.134852290153503417, 120, 255, 1, 52106), -- Stool (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@OGUID+7, 254865, 1481, 7705, 7712, '0', 0, 0, 1426.529541015625, 1704.736083984375, 54.30316925048828125, 2.015855789184570312, 0, 0, 0.845727920532226562, 0.533614337444305419, 120, 255, 1, 52106), -- Forge (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@OGUID+8, 254868, 1481, 7705, 7712, '0', 0, 0, 1425.3160400390625, 1691.248291015625, 54.34935379028320312, 1.963491797447204589, 0, 0, 0.831468582153320312, 0.555571734905242919, 120, 255, 1, 52106); -- Stool (Area: Illidari Foothold - Difficulty: 0) CreateObject1

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (113927, 113924);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(113927, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '42459'), -- 113927 (Illidari Kilbride) - Dual Wield
(113924, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '42459'); -- 113924 (Illidari Starr) - Dual Wield

DELETE FROM `gameobject_template_addon` WHERE `entry` = 245170 /*Demon Ward*/;
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(245170, 114, 32, 0, 0); -- Demon Ward

-- Creature 97600 smart ai
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 97600;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = -(@CGUID+21);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-(@CGUID+21), 0, 0, 0, '', 34, 0, 100, 0, 2, 4, 0, 0, 80, 9760000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 4 - Self: Start timed action list id #9760000 (update out of combat)'),
(-(@CGUID+21), 0, 1, 0, '', 34, 0, 100, 0, 2, 10, 0, 0, 80, 9760000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 10 - Self: Start timed action list id #9760000 (update out of combat)'),
(-(@CGUID+21), 0, 2, 0, '', 34, 0, 100, 0, 2, 14, 0, 0, 80, 9760000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 14 - Self: Start timed action list id #9760000 (update out of combat)'),
(-(@CGUID+21), 0, 3, 0, '', 34, 0, 100, 0, 2, 17, 0, 0, 80, 9760000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 17 - Self: Start timed action list id #9760000 (update out of combat)'),
(-(@CGUID+21), 0, 4, 0, '', 34, 0, 100, 0, 2, 32, 0, 0, 80, 9760000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 32 - Self: Start timed action list id #9760000 (update out of combat)');

-- Timed list 9760000 smart ai
SET @ENTRY := 9760000;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 9, 0, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 43, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Dismount'),
(@ENTRY, 9, 1, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Set emote state to 69'),
(@ENTRY, 9, 2, 0, '', 0, 0, 100, 0, 20000, 20000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 20 seconds - Self: Set emote state to 0'),
(@ENTRY, 9, 3, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 137, 36264, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Plays SpellVisual with SpellVisualKitId: 36264, KitType: 0 for 0 ms'),
(@ENTRY, 9, 4, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 43, 0, 64385, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Mount to model 64385');

-- Creature 97599 smart ai
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 97599;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = -(@CGUID+30);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-(@CGUID+30), 0, 0, 0, '', 34, 0, 100, 0, 2, 0, 0, 0, 80, 9759900, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 0 - Self: Start timed action list id #9759900 (update out of combat)'),
(-(@CGUID+30), 0, 1, 0, '', 34, 0, 100, 0, 2, 1, 0, 0, 80, 9759900, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 1 - Self: Start timed action list id #9759900 (update out of combat)'),
(-(@CGUID+30), 0, 2, 0, '', 34, 0, 100, 0, 2, 3, 0, 0, 80, 9759900, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 3 - Self: Start timed action list id #9759900 (update out of combat)');

-- Timed list 9759900 smart ai
SET @ENTRY := 9759900;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 9, 0, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 128, 4760, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Plays Anim with ID 4760'),
(@ENTRY, 9, 1, 0, '', 0, 0, 100, 0, 23000, 23000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 23 seconds - Self: Plays Anim with ID 0');

-- Update conditions for phase 5094
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 5094 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 5094, 0, 0, 0, 47, 0, 40378, 2|8|64, 0, 0, 'Apply Phase 5094 if Quest 40378 is complete | in progress | rewarded'),
(26, 5094, 0, 0, 0, 47, 0, 40379, 64, 0, 1, 'Apply Phase 5094 if Quest 40379 is not rewarded'),
(26, 5094, 0, 0, 1, 47, 0, 40378, 2|8|64, 0, 0, 'Apply Phase 5094 if Quest 40378 is complete | in progress | rewarded'),
(26, 5094, 0, 0, 1, 47, 0, 39049, 64, 0, 1, 'Apply Phase 5094 if Quest 39049 is not rewarded'),
(26, 5094, 0, 0, 2, 47, 0, 40378, 2|8|64, 0, 0, 'Apply Phase 5094 if Quest 40378 is complete | in progress | rewarded'),
(26, 5094, 0, 0, 2, 47, 0, 38759, 64, 0, 1, 'Apply Phase 5094 if Quest 38759 is not rewarded');

-- Waypoints for CGUID+22
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+22;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+22, @CGUID+22, 0, 0, 512, 0, 0),
(@CGUID+22, @CGUID+23, 4, 60, 512, 0, 0);

SET @ENTRY := 96930;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 0, 1455.304, 1864.953, 67.20747, NULL, 0, 1),
(@PATH, 1, 1448.026, 1852.033, 65.76717, NULL, 0, 1),
(@PATH, 2, 1442.493, 1838.59, 63.41571, NULL, 0, 1),
(@PATH, 3, 1440.571, 1826.682, 61.59822, NULL, 0, 1),
(@PATH, 4, 1440.168, 1814.16, 59.84146, NULL, 0, 1),
(@PATH, 5, 1443.903, 1798.375, 56.37568, NULL, 0, 1),
(@PATH, 6, 1446.498, 1786.002, 55.0841, NULL, 0, 1),
(@PATH, 7, 1444.672, 1776.771, 54.8313, NULL, 0, 1),
(@PATH, 8, 1440.96, 1770.063, 54.66534, NULL, 0, 1),
(@PATH, 9, 1434.243, 1762.175, 54.48805, NULL, 0, 1),
(@PATH, 10, 1425.535, 1756.764, 54.80664, NULL, 0, 1),
(@PATH, 11, 1421.04, 1747.483, 54.89405, NULL, 0, 1),
(@PATH, 12, 1422.95, 1739.953, 54.01103, NULL, 0, 1),
(@PATH, 13, 1422.944, 1733.422, 53.86541, NULL, 0, 1),
(@PATH, 14, 1417.941, 1724.453, 54.40369, NULL, 0, 1),
(@PATH, 15, 1411.92, 1715.457, 54.48598, NULL, 0, 1),
(@PATH, 16, 1405.74, 1708.472, 54.48562, NULL, 0, 1),
(@PATH, 17, 1398.377, 1702.571, 54.48559, NULL, 6419, 1),
(@PATH, 18, 1411.92, 1715.457, 54.48598, NULL, 0, 1),
(@PATH, 19, 1417.941, 1724.453, 54.40369, NULL, 0, 1),
(@PATH, 20, 1422.944, 1733.422, 53.86541, NULL, 0, 1),
(@PATH, 21, 1422.95, 1739.953, 54.01103, NULL, 0, 1),
(@PATH, 22, 1421.04, 1747.483, 54.89405, NULL, 0, 1),
(@PATH, 23, 1425.535, 1756.764, 54.80664, NULL, 0, 1),
(@PATH, 24, 1434.243, 1762.175, 54.48805, NULL, 0, 1),
(@PATH, 25, 1440.96, 1770.063, 54.66534, NULL, 0, 1),
(@PATH, 26, 1444.672, 1776.771, 54.8313, NULL, 0, 1),
(@PATH, 27, 1446.498, 1786.002, 55.0841, NULL, 0, 1),
(@PATH, 28, 1443.903, 1798.375, 56.37568, NULL, 0, 1),
(@PATH, 29, 1440.168, 1814.16, 59.84146, NULL, 0, 1),
(@PATH, 30, 1440.571, 1826.682, 61.59822, NULL, 0, 1),
(@PATH, 31, 1442.493, 1838.59, 63.41571, NULL, 0, 1),
(@PATH, 32, 1448.026, 1852.033, 65.76717, NULL, 0, 1),
(@PATH, 33, 1455.304, 1864.953, 67.20747, NULL, 0, 1),
(@PATH, 34, 1462.583, 1875.488, 67.82002, NULL, 0, 1),
(@PATH, 35, 1468.863, 1884.46, 68.35853, NULL, 7717, 1);

UPDATE `creature` SET `position_x`= 1469.296, `position_y`= 1881.997, `position_z`= 68.06720, `orientation`= 0.9602662 WHERE `guid`= @CGUID+23;
UPDATE `creature` SET `position_x`= 1455.304, `position_y`= 1864.953, `position_z`= 67.20747, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+22;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+22;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `SheathState`, `auras`) VALUES
(@CGUID+22, @PATH, 64385, 1, '222589 42459');

-- Waypoints for CGUID+21
SET @ENTRY := 97600;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 0, 1476.95, 1797.345, 51.55708, NULL, 0, 1),
(@PATH, 1, 1479.201, 1787.104, 52.83504, NULL, 0, 1),
(@PATH, 2, 1480.891, 1778.55, 54.89057, NULL, 0, 1),
(@PATH, 3, 1476.453, 1768.349, 55.24147, NULL, 0, 1),
(@PATH, 4, 1474.705, 1764.168, 55.36797, NULL, 26553, 1),
(@PATH, 5, 1461.521, 1750.55, 52.64798, NULL, 0, 1),
(@PATH, 6, 1459.561, 1746.085, 55.10339, NULL, 0, 1),
(@PATH, 7, 1457.076, 1740.017, 57.1743, NULL, 0, 1),
(@PATH, 8, 1453.399, 1724.646, 47.76581, NULL, 0, 1),
(@PATH, 9, 1462.5, 1721.875, 46.09338, NULL, 0, 1),
(@PATH, 10, 1465.713, 1720.384, 47.92474, NULL, 27938, 1),
(@PATH, 11, 1442.975, 1716.251, 50.35307, NULL, 0, 1),
(@PATH, 12, 1433.974, 1704.979, 53.62702, NULL, 0, 1),
(@PATH, 13, 1431.45, 1699.859, 54.88998, NULL, 0, 1),
(@PATH, 14, 1432.708, 1698.418, 55.52136, NULL, 28646, 1),
(@PATH, 15, 1416.918, 1703.033, 54.48317, NULL, 0, 1),
(@PATH, 16, 1408.215, 1698.665, 54.48521, NULL, 0, 1),
(@PATH, 17, 1406.581, 1694.771, 55.31854, NULL, 27392, 1),
(@PATH, 18, 1419.927, 1712.661, 54.48559, NULL, 0, 1),
(@PATH, 19, 1426.644, 1722.823, 53.91505, NULL, 0, 1),
(@PATH, 20, 1429.057, 1731.875, 53.07135, NULL, 0, 1),
(@PATH, 21, 1426.587, 1746.613, 54.2347, NULL, 0, 1),
(@PATH, 22, 1426.908, 1751.703, 54.58276, NULL, 0, 1),
(@PATH, 23, 1438.337, 1760.507, 54.48806, NULL, 0, 1),
(@PATH, 24, 1446.387, 1766.545, 54.45451, NULL, 0, 1),
(@PATH, 25, 1453.741, 1776.057, 54.45789, NULL, 0, 1),
(@PATH, 26, 1460.432, 1789.88, 53.09035, NULL, 0, 1),
(@PATH, 27, 1467.505, 1800.708, 52.77264, NULL, 0, 1),
(@PATH, 28, 1471.526, 1807.536, 52.46568, NULL, 0, 1),
(@PATH, 29, 1471.326, 1812.932, 55.47617, NULL, 0, 1),
(@PATH, 30, 1475.057, 1817.384, 56.84558, NULL, 0, 1),
(@PATH, 31, 1477.938, 1817.924, 56.15234, NULL, 0, 1),
(@PATH, 32, 1480.405, 1818.399, 56.65537, NULL, 28004, 1);

UPDATE `creature` SET `position_x`= 1476.95, `position_y`= 1797.345, `position_z`= 51.55708, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+21;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+21;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `SheathState`) VALUES
(@CGUID+21, @PATH, 64385, 1);

-- Waypoints for CGUID+30
SET @ENTRY := 97599;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 1470.422, 1775.036, 54.44497, NULL, 25759),
(@PATH, 1, 1468.554, 1773.09, 54.4449, NULL, 25134),
(@PATH, 2, 1452.356, 1760.01, 54.43709, NULL, 0),
(@PATH, 3, 1451.752, 1759.306, 54.42967, NULL, 26734),
(@PATH, 4, 1470.422, 1775.036, 54.44497, NULL, 0);

UPDATE `creature` SET `position_x`= 1470.422, `position_y`= 1775.036, `position_z`= 54.44497, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+30;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+30;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+30, @PATH, 0);
