SET @OGUID := 6002301;

SET @ATID := 110;
SET @ATCREATEID := 105;
SET @ATSPAWNID := 204;

-- Neltharion's Lair rear exit spell
DELETE FROM `spell_target_position` WHERE (`ID`=219727 AND `EffectIndex`=0 AND `OrderIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `OrderIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(219727, 0, 0, 1220, 3141.4599609375, 3544.080078125, 771.66998291015625, 61188); -- Spell: 219727 (Neltharion's Lair) Effect 0: 252 (SPELL_EFFECT_TELEPORT_UNITS)

-- Update MawOfSoulsDungeon game tele pos.
UPDATE `game_tele` SET `position_x` = 7209.4799, `position_y` = 7310.4365, `position_z` = 22.4159, `orientation` = 5.820105 WHERE `id` = 1702;

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+17;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 252245, 1220, 7502, 7589, '0', 0, 0, -969.8125, 4314.1240234375, 742.1795654296875, 0.908608078956604003, 0, 0, 0.438837051391601562, 0.898566663265228271, 120, 255, 1, 61122), -- Instance Portal (Area: Windrunner's Sanctuary - Difficulty: 0) CreateObject1
(@OGUID+1, 252245, 1220, 7543, 8143, '0', 0, 0, -432.998260498046875, 2422.338623046875, 110.6934127807617187, 0.770861744880676269, 0, 0, 0.375958442687988281, 0.92663651704788208, 120, 255, 1, 61122), -- Instance Portal (Area: Darkstone Isle - Difficulty: 0) CreateObject1
(@OGUID+2, 252247, 1220, 7334, 7345, '0', 0, 0, 1.418402791023254394, 5809.13525390625, 4.727654457092285156, 4.552899837493896484, 0.058282852172851562, -0.07990741729736328, -0.75697612762451171, 0.645914137363433837, 120, 255, 1, 61122), -- Instance Portal (Area: Mak'rana - Difficulty: 0) CreateObject1
(@OGUID+3, 252248, 1220, 7334, 7345, '0', 0, 0, -1715.6614990234375, 6648.625, 129.7181549072265625, 3.173328638076782226, 0, 0, -0.99987411499023437, 0.015867263078689575, 120, 255, 1, 61122), -- Instance Portal (Area: Mak'rana - Difficulty: 0) CreateObject1
(@OGUID+4, 252247, 1456, 8040, 8081, '1,2,8,23,24', 0, 0, -3925.479248046875, 4549.06005859375, 91.900787353515625, 5.736945152282714843, 0, 0, -0.26973724365234375, 0.962933957576751708, 7200, 255, 1, 61122), -- Instance Portal (Area: Hatecoil Encampment - Difficulty: 0) CreateObject1
(@OGUID+5, 252248, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4185.21728515625, -784.234375, 283.865234375, 1.649240732192993164, 0, 0, 0.734290122985839843, 0.678835749626159667, 7200, 255, 1, 61122), -- Instance Portal (Area: Vault of the Wardens - Difficulty: 0) CreateObject1
(@OGUID+6, 252248, 1220, 7558, 8322, '0', 0, 0, 3123.04345703125, 7561.49755859375, 35.70119476318359375, 3.974596500396728515, 0, 0, -0.91450977325439453, 0.404563784599304199, 120, 255, 1, 61122), -- Instance Portal (Area: Sabermaw Bluff - Difficulty: 0) CreateObject1
(@OGUID+7, 252248, 1220, 7558, 7605, '0', 0, 0, 3821.271728515625, 6353.830078125, 189.4849700927734375, 0.901840269565582275, 0, 0, 0.435793876647949218, 0.900046467781066894, 120, 255, 1, 61122), -- Instance Portal (Area: Wretched Hollow - Difficulty: 0) CreateObject1
(@OGUID+8, 252248, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 3264.473876953125, 1831.138916015625, 242.256103515625, 0.178185537457466125, 0, 0, 0.088974952697753906, 0.996033847332000732, 7200, 255, 1, 61122), -- Instance Portal (Area: Darkheart Thicket - Difficulty: 0) CreateObject1
(@OGUID+9, 252248, 1220, 7503, 8050, '0', 0, 0, 3723.22314453125, 4184.416015625, 894.24835205078125, 6.265376091003417968, 0.01088571548461914, -0.26116657257080078, -0.00502204895019531, 0.965219318866729736, 120, 255, 1, 61122), -- Instance Portal (Area: Sylvan Falls - Difficulty: 0) CreateObject1
(@OGUID+10, 252248, 1458, 7546, 8338, '1,2,8,23,24', 0, 0, 2985.584228515625, 982.98785400390625, 377.844268798828125, 6.121403217315673828, 0, 0, -0.08080291748046875, 0.99673008918762207, 7200, 255, 1, 61122), -- Instance Portal (Area: The Lost Road - Difficulty: 0) CreateObject1
(@OGUID+11, 252248, 1458, 7546, 8338, '1,2,8,23,24', 0, 0, 2828.811767578125, 2125.107666015625, -173.820053100585937, 1.594143629074096679, 0, 0, 0.715312957763671875, 0.698804259300231933, 7200, 255, 1, 61122), -- Instance Portal (Area: The Lost Road - Difficulty: 0) CreateObject1
(@OGUID+12, 252145, 1220, 7541, 7541, '0', 0, 0, 3431.080810546875, 1985.1041259765625, 20.36965560913085937, 3.272694587707519531, 0, 0, -0.99785232543945312, 0.065503887832164764, 120, 255, 1, 61122), -- Instance Portal (Area: Stormheim - Difficulty: 0) CreateObject1
(@OGUID+13, 252237, 1220, 7541, 8249, '0', 0, 0, 2452.704833984375, 814.73956298828125, 256.39013671875, 2.341654062271118164, 0, 0, 0.921072959899902343, 0.389390051364898681, 120, 255, 1, 61122), -- Instance Portal (Area: Terrace of the Watchers - Difficulty: 0) CreateObject1
(@OGUID+14, 252245, 1220, 7637, 7940, '0', 0, 0, 1017.91668701171875, 3828.359375, 9.665826797485351562, 1.392298698425292968, 0, 0, 0.641267776489257812, 0.767317175865173339, 120, 255, 1, 61122), -- Instance Portal (Area: Jandvik - Difficulty: 0) CreateObject1
(@OGUID+15, 252248, 1220, 7637, 7940, '0', 0, 0, 1154.9879150390625, 4380.76806640625, 11.36471843719482421, 2.62295699119567871, 0, 0, 0.966565132141113281, 0.256421238183975219, 120, 255, 1, 61122), -- Instance Portal (Area: Jandvik - Difficulty: 0) CreateObject1
(@OGUID+16, 252145, 1669, 8701, 8841, '0', 0, 0, 5412.83837890625, 10816.5673828125, 22.50126075744628906, 3.017399072647094726, 0, 0, 0.998072624206542968, 0.062056876718997955, 120, 255, 1, 61188), -- Instance Portal (Area: Triad's Conservatory - Difficulty: 0) CreateObject1
(@OGUID+17, 252145, 1753, 8910, 8907, '2,8,23', 0, 0, 5413.9912109375, 10818.3330078125, 20.21274566650390625, 2.885625600814819335, 0, 0, 0.9918212890625, 0.127634420990943908, 7200, 255, 1, 61188); -- Instance Portal (Area: Triad's Conservatory - Difficulty: 0) CreateObject1

DELETE FROM `areatrigger_template` WHERE `Id` BETWEEN @ATID+0 AND @ATID+26;
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `ActionSetId`, `ActionSetFlags`, `VerifiedBuild`) VALUES
(@ATID+0, 1, 1, 0, (0x0002|0x0008), 0), -- The Seat of the Triumvirate - Enter
(@ATID+1, 1, 1, 0, (0x0002|0x0008), 0), -- The Seat of the Triumvirate - Exit
(@ATID+2, 1, 1, 0, (0x0002|0x0008), 0), -- Return to Karazhan - Enter
(@ATID+3, 1, 1, 0, (0x0002|0x0008), 0), -- Return to Karazhan - Exit
(@ATID+4, 1, 1, 0, (0x0002|0x0008), 0), -- The Violet Hold - Enter
(@ATID+5, 1, 1, 0, (0x0002|0x0008), 0), -- The Violet Hold - Exit
(@ATID+6, 1, 1, 0, (0x0002|0x0008), 0), -- Cathedral of Eternal Night - Enter
(@ATID+7, 1, 1, 0, (0x0002|0x0008), 0), -- Cathedral of Eternal Night - Exit
(@ATID+8, 1, 1, 0, (0x0002|0x0008), 0), -- Court of Stars - Enter
(@ATID+9, 1, 1, 0, (0x0002|0x0008), 0), -- Court of Stars - Exit
(@ATID+10, 1, 1, 0, (0x0002|0x0008), 0), -- The Arcway - Enter
(@ATID+11, 1, 1, 0, (0x0002|0x0008), 0), -- The Arcway - Exit
(@ATID+12, 1, 1, 0, (0x0002|0x0008), 0), -- Vault of the Wardens - Enter
(@ATID+13, 1, 1, 0, (0x0002|0x0008), 0), -- Vault of the Wardens - Exit
(@ATID+14, 1, 1, 0, (0x0002|0x0008), 0), -- Eye of Azshara - Enter
(@ATID+15, 1, 1, 0, (0x0002|0x0008), 0), -- Eye of Azshara - Exit
(@ATID+16, 1, 1, 0, (0x0002|0x0008), 0), -- Black Rook Hold - Enter
(@ATID+17, 1, 1, 0, (0x0002|0x0008), 0), -- Black Rook Hold - Exit
(@ATID+18, 1, 1, 0, (0x0002|0x0008), 0), -- Darkheart Thicket - Enter
(@ATID+19, 1, 1, 0, (0x0002|0x0008), 0), -- Darkheart Thicket - Exit
(@ATID+20, 1, 1, 0, (0x0002|0x0008), 0), -- Neltharion's Lair - Enter
(@ATID+21, 1, 1, 0, (0x0002|0x0008), 0), -- Neltharion's Lair - Exit
(@ATID+22, 1, 1, 0, (0x0002|0x0008), 0), -- Neltharion's Lair - Rear Exit
(@ATID+23, 1, 1, 0, (0x0002|0x0008), 0), -- Maw of Souls - Enter
(@ATID+24, 1, 1, 0, (0x0002|0x0008), 0), -- Maw of Souls - Exit
(@ATID+25, 1, 1, 0, (0x0002|0x0008), 0), -- Halls of Valor - Enter
(@ATID+26, 1, 1, 0, (0x0002|0x0008), 0); -- Halls of Valor - Exit

DELETE FROM `areatrigger_create_properties` WHERE `Id` BETWEEN @ATCREATEID+0 AND @ATCREATEID+26;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(@ATCREATEID+0, 1, @ATID+0, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 3, 10, 15, 3, 10, 15, 0, 0, '', 0), -- The Seat of the Triumvirate - Enter
(@ATCREATEID+1, 1, @ATID+1, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 3, 10, 15, 3, 10, 15, 0, 0, '', 0), -- The Seat of the Triumvirate - Exit
(@ATCREATEID+2, 1, @ATID+2, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 2, 3, 10, 2, 3, 10, 0, 0, '', 0), -- Return to Karazhan - Enter
(@ATCREATEID+3, 1, @ATID+3, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 2, 3, 10, 2, 3, 10, 0, 0, '', 0), -- Return to Karazhan - Exit
(@ATCREATEID+4, 1, @ATID+4, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 2, 5, 35, 2, 5, 35, 0, 0, '', 0), -- The Violet Hold - Enter
(@ATCREATEID+5, 1, @ATID+5, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 4, 7, 30, 4, 7, 30, 0, 0, '', 0), -- The Violet Hold - Exit
(@ATCREATEID+6, 1, @ATID+6, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 3, 4.5, 12, 3, 4.5, 12, 0, 0, '', 0), -- Cathedral of Eternal Night - Enter
(@ATCREATEID+7, 1, @ATID+7, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 1, 3, 10, 1, 3, 10, 0, 0, '', 0), -- Cathedral of Eternal Night - Exit
(@ATCREATEID+8, 1, @ATID+8, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 2.7, 5, 10, 2.7, 5, 10, 0, 0, '', 0), -- Court of Stars - Enter
(@ATCREATEID+9, 1, @ATID+9, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 2.7, 5, 10, 2.7, 5, 10, 0, 0, '', 0), -- Court of Stars - Exit
(@ATCREATEID+10, 1, @ATID+10, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 2, 8, 10, 2, 8, 10, 0, 0, '', 0), -- The Arcway - Enter
(@ATCREATEID+11, 1, @ATID+11, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 2, 10, 10, 2, 10, 10, 0, 0, '', 0), -- The Arcway - Exit
(@ATCREATEID+12, 1, @ATID+12, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 3, 8, 10, 3, 8, 10, 0, 0, '', 0), -- Vault of the Wardens - Enter
(@ATCREATEID+13, 1, @ATID+13, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 2, 6, 10.5, 2, 6, 10.5, 0, 0, '', 0), -- Vault of the Wardens - Exit
(@ATCREATEID+14, 1, @ATID+14, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 4, 6, 6, 10, 10, 0, 0, 0, 0, '', 0), -- Eye of Azshara - Enter
(@ATCREATEID+15, 1, @ATID+15, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 4, 6, 6, 10, 10, 0, 0, 0, 0, '', 0), -- Eye of Azshara - Exit
(@ATCREATEID+16, 1, @ATID+16, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 2, 6, 10, 2, 6, 10, 0, 0, '', 0), -- Black Rook Hold - Enter
(@ATCREATEID+17, 1, @ATID+17, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 3, 8, 10, 3, 8, 10, 0, 0, '', 0), -- Black Rook Hold - Exit
(@ATCREATEID+18, 1, @ATID+18, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 2, 9, 22, 2, 9, 22, 0, 0, '', 0), -- Darkheart Thicket - Enter
(@ATCREATEID+19, 1, @ATID+19, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 2, 5, 10, 2, 5, 10, 0, 0, '', 0), -- Darkheart Thicket - Exit
(@ATCREATEID+20, 1, @ATID+20, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 4, 6, 12, 4, 6, 12, 0, 0, '', 0), -- Neltharion's Lair - Enter
(@ATCREATEID+21, 1, @ATID+21, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 2, 5, 10, 2, 5, 10, 0, 0, '', 0), -- Neltharion's Lair - Exit
(@ATCREATEID+22, 1, @ATID+22, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 2, 6, 10, 2, 6, 10, 0, 0, '', 0), -- Neltharion's Lair - Rear Exit
(@ATCREATEID+23, 1, @ATID+23, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 3, 12, 60, 3, 12, 60, 0, 0, '', 0), -- Maw of Souls - Enter
(@ATCREATEID+24, 1, @ATID+24, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 3, 14, 10, 3, 14, 10, 0, 0, '', 0), -- Maw of Souls - Exit
(@ATCREATEID+25, 1, @ATID+25, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 2, 11, 10, 2, 11, 10, 0, 0, '', 0), -- Halls of Valor - Enter
(@ATCREATEID+26, 1, @ATID+26, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 2, 15, 10, 2, 15, 10, 0, 0, '', 0); -- Halls of Valor - Exit

DELETE FROM `areatrigger` WHERE `SpawnId` BETWEEN @ATSPAWNID+0 AND @ATSPAWNID+26;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `Comment`) VALUES
(@ATSPAWNID+0, @ATCREATEID+0, 1, 1669, '0', 5416.08, 10821.28, 20.24, 2.79, 0, 'The Seat of the Triumvirate - Enter'),
(@ATSPAWNID+1, @ATCREATEID+1, 1, 1753, '2,8,23', 5416.08, 10821.28, 20.24, 2.79, 0, 'The Seat of the Triumvirate - Exit'),
(@ATSPAWNID+2, @ATCREATEID+2, 1, 0, '0', -11039.48, -1998, 93, 5.42, 0, 'Return to Karazhan - Enter'),
(@ATSPAWNID+3, @ATCREATEID+3, 1, 1651, '2,8,23', -11036.83, -2001.06, 93.48, 2.22, 0, 'Return to Karazhan - Exit'),
(@ATSPAWNID+4, @ATCREATEID+4, 1, 1220, '0', -968.47, 4315.12, 739.92, 0.89, 0, 'The Violet Hold - Enter'),
(@ATSPAWNID+5, @ATCREATEID+5, 1, 1544, '1,2,23', 4549.37, 4015.25, 83.67, 6.26, 0, 'The Violet Hold - Exit'),
(@ATSPAWNID+6, @ATCREATEID+6, 1, 1220, '0', -433.67, 2421.66, 108.37, 0.78, 0, 'Cathedral of Eternal Night - Enter'),
(@ATSPAWNID+7, @ATCREATEID+7, 1, 1677, '2,8,23', -713.39, 2528.68, 332.09, 6.22, 0, 'Cathedral of Eternal Night - Exit'),
(@ATSPAWNID+8, @ATCREATEID+8, 1, 1220, '0', 1017.84, 3828.85, 8.49, 4.52, 0, 'Court of Stars - Enter'),
(@ATSPAWNID+9, @ATCREATEID+9, 1, 1571, '8,23,2,24', 1017.84, 3828.85, 8.49, 4.52, 0, 'Court of Stars - Exit'),
(@ATSPAWNID+10, @ATCREATEID+10, 1, 1220, '0', 1155.96, 4379.83, 11.68, 5.75, 0, 'The Arcway - Enter'),
(@ATSPAWNID+11, @ATCREATEID+11, 1, 1516, '8,23,2', 3534.61, 4805.37, 591.10, 3.14, 0, 'The Arcway - Exit'),
(@ATSPAWNID+12, @ATCREATEID+12, 1, 1220, '0', -1714.11, 6648.94, 124.83, 3.15, 0, 'Vault of the Wardens - Enter'),
(@ATSPAWNID+13, @ATCREATEID+13, 1, 1493, '1,2,8,23,24', 4185.09, -785.71, 281.78, 1.65, 0, 'Vault of the Wardens - Exit'),
(@ATSPAWNID+14, @ATCREATEID+14, 1, 1220, '0', 0.54, 5811.24, 2.62, 3.75, 0, 'Eye of Azshara - Enter'),
(@ATSPAWNID+15, @ATCREATEID+15, 1, 1456, '1,2,8,23,24', -3926.83, 4548.55, 88.65, 5.18, 0, 'Eye of Azshara - Exit'),
(@ATSPAWNID+16, @ATCREATEID+16, 1, 1220, '0', 3122.23, 7561.73, 32.33, 3.97, 0, 'Black Rook Hold - Enter'),
(@ATSPAWNID+17, @ATCREATEID+17, 1, 1501, '1,2,8,23,24', 3505.64, 7649.18, -7.02, 3.3, 0, 'Black Rook Hold - Exit'),
(@ATSPAWNID+18, @ATCREATEID+18, 1, 1220, '0', 3821.27, 6353.83, 185.53, 3.8, 0, 'Darkheart Thicket - Enter'),
(@ATSPAWNID+19, @ATCREATEID+19, 1, 1466, '1,2,8,23,24', 3265.62, 1831.14, 240, 0.18, 0, 'Darkheart Thicket - Exit'),
(@ATSPAWNID+20, @ATCREATEID+20, 1, 1220, '0', 3720.53, 4184.47, 894.24, 0.14, 0, 'Neltharion''s Lair - Enter'),
(@ATSPAWNID+21, @ATCREATEID+21, 1, 1458, '1,2,8,23,24', 2985.58, 982.99, 379.38, 6.1214, 0, 'Neltharion''s Lair - Exit'),
(@ATSPAWNID+22, @ATCREATEID+22, 1, 1458, '1,2,8,23,24', 2831.18, 2124.47, -178.6, 5.04, 0, 'Neltharion''s Lair - Rear Exit'),
(@ATSPAWNID+23, @ATCREATEID+23, 1, 1220, '0', 3431.08, 1985.1, 20.37, 3.27, 0, 'Maw of Souls - Enter'),
(@ATSPAWNID+24, @ATCREATEID+24, 1, 1492, '1,2,8,23', 7162.33, 7317.96, 20.86, 0.20, 0, 'Maw of Souls - Exit'),
(@ATSPAWNID+25, @ATCREATEID+25, 1, 1220, '0', 2452.15, 814.43, 252.92, 2.33, 0, 'Halls of Valor - Enter'),
(@ATSPAWNID+26, @ATCREATEID+26, 1, 1477, '1,2,8,23', 3817.09, 529.08, 603.34, 3.13, 0, 'Halls of Valor - Exit');

DELETE FROM `areatrigger_template_actions` WHERE `AreaTriggerId` BETWEEN @ATID+0 AND @ATID+26;
INSERT INTO `areatrigger_template_actions` (`AreaTriggerId`, `IsCustom`, `ActionType`, `ActionParam`, `TargetType`) VALUES
(@ATID+0, 1, 2, 6048, 5), -- The Seat of the Triumvirate - Enter
(@ATID+1, 1, 2, 6112, 5), -- The Seat of the Triumvirate - Exit
(@ATID+2, 1, 2, 5784, 5), -- Return to Karazhan - Enter
(@ATID+3, 1, 2, 3771, 5), -- Return to Karazhan - Exit
(@ATID+4, 1, 2, 5293, 5), -- The Violet Hold - Enter
(@ATID+5, 1, 2, 5446, 5), -- The Violet Hold - Exit
(@ATID+6, 1, 2, 5891, 5), -- Cathedral of Eternal Night - Enter
(@ATID+7, 1, 2, 5892, 5), -- Cathedral of Eternal Night - Exit
(@ATID+8, 1, 2, 5432, 5), -- Court of Stars - Enter
(@ATID+9, 1, 2, 5607, 5), -- Court of Stars - Exit
(@ATID+10, 1, 2, 5194, 5), -- The Arcway - Enter
(@ATID+11, 1, 2, 5472, 5), -- The Arcway - Exit
(@ATID+12, 1, 2, 5105, 5), -- Vault of the Wardens - Enter
(@ATID+13, 1, 2, 5104, 5), -- Vault of the Wardens - Exit
(@ATID+14, 1, 2, 5100, 5), -- Eye of Azshara - Enter
(@ATID+15, 1, 2, 5114, 5), -- Eye of Azshara - Exit
(@ATID+16, 1, 2, 5352, 5), -- Black Rook Hold - Enter
(@ATID+17, 1, 2, 5353, 5), -- Black Rook Hold - Exit
(@ATID+18, 1, 2, 5334, 5), -- Darkheart Thicket - Enter
(@ATID+19, 1, 2, 5343, 5), -- Darkheart Thicket - Exit
(@ATID+20, 1, 2, 5355, 5), -- Neltharion's Lair - Enter
(@ATID+21, 1, 2, 5103, 5), -- Neltharion's Lair - Exit
(@ATID+22, 1, 0, 219727, 5), -- Neltharion's Lair - Rear Exit
(@ATID+23, 1, 2, 5102, 5), -- Maw of Souls - Enter
(@ATID+24, 1, 2, 5123, 5), -- Maw of Souls - Exit
(@ATID+25, 1, 2, 5098, 5), -- Halls of Valor - Enter
(@ATID+26, 1, 2, 5099, 5); -- Halls of Valor - Exit
