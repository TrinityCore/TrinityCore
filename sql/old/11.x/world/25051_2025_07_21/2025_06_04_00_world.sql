-- Using legacy MoP range for Mejis future plan to move MoP guids
SET @OGUID := 400729;

SET @ATID := 109;
SET @ATCREATEID := 104;
SET @ATSPAWNID := 203;

UPDATE `gameobject_template_addon` SET `faction`=35, `flags`=0x2000 WHERE `entry` IN (233436, 232552); -- Instance Portal (Party + Heroic + Challenge)

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+13;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 232552, 1116, 6719, 6872, '0', 0, 0, 754.8367919921875, 137.9774322509765625, 8.418164253234863281, 5.477486610412597656, 0, 0, -0.39204120635986328, 0.919947683811187744, 120, 255, 1, 61122), -- Instance Portal (Party + Heroic + Challenge) (Area: Terrace of the Stars - Difficulty: 0) CreateObject1
(@OGUID+1, 212899, 1176, 6932, 6932, '1,2,8,23,24', 0, 0, 1712.3697509765625, 252.6840362548828125, 328.67987060546875, 4.966750621795654296, 0, 0, -0.61170768737792968, 0.791083872318267822, 7200, 255, 1, 61122), -- Instance Portal (Party + Heroic + Challenge) (Area: Shadowmoon Burial Grounds - Difficulty: 0) CreateObject1
(@OGUID+2, 233436, 1116, 6722, 0, '0', 0, 0, 23.10590362548828125, 2523.257080078125, 104.4011764526367187, 0.508704185485839843, 0, 0, 0.251618385314941406, 0.967826545238494873, 120, 255, 1, 61122), -- Instance Portal (Party + Heroic + Challenge) (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+3, 214885, 1116, 6662, 7200, '0', 0, 0, 1493.3177490234375, 3065.427978515625, 110.3917236328125, 2.075940132141113281, 0, 0, 0.861374855041503906, 0.507969796657562255, 120, 255, 1, 61122), -- Instance Portal (Party + Heroic + Challenge) (Area: Auchindoun - Difficulty: 0) CreateObject1
(@OGUID+4, 232552, 1116, 6662, 7200, '0', 0, 0, 1494.9010009765625, 3062.771728515625, 110.8590621948242187, 5.136622428894042968, 0, 0, -0.54239177703857421, 0.840125679969787597, 120, 255, 1, 61122), -- Instance Portal (Party + Heroic + Challenge) (Area: Auchindoun - Difficulty: 0) CreateObject1
(@OGUID+5, 214513, 1116, 6720, 0, '0', 0, 0, 7268.0078125, 4463.84716796875, 129.71368408203125, 4.402121543884277343, 0, 0, -0.80787181854248046, 0.589358270168304443, 120, 255, 1, 61122), -- Instance Portal (Party + Heroic + Challenge) (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+6, 212899, 1175, 6874, 6874, '1,2,8,23,24', 0, 0, 1810.548583984375, -255.40625, 260.434600830078125, 0.101795271039009094, 0, 0, 0.050875663757324218, 0.998704969882965087, 7200, 255, 1, 61122), -- Instance Portal (Party + Heroic + Challenge) (Area: Bloodmaul Slag Mines - Difficulty: 0) CreateObject1
(@OGUID+7, 214885, 1116, 6721, 7320, '0', 0, 0, 7100.6728515625, 194.267364501953125, 143.751678466796875, 0.262173324823379516, 0, 0, 0.130711555480957031, 0.991420447826385498, 120, 255, 1, 61122), -- Instance Portal (Party + Heroic + Challenge) (Area: Everbloom Wilds - Difficulty: 0) CreateObject1
(@OGUID+8, 232552, 1279, 7109, 7109, '1,2,8,23,24', 0, 0, 420.661468505859375, 1308.9739990234375, 125.412872314453125, 1.070775985717773437, 0, 0, 0.510174751281738281, 0.860070765018463134, 7200, 255, 1, 61122), -- Instance Portal (Party + Heroic + Challenge) (Area: The Everbloom - Difficulty: 0) CreateObject1
(@OGUID+9, 212899, 1116, 6721, 7320, '0', 0, 0, 7885.17041015625, 566.609375, 125.7043991088867187, 0.345564097166061401, 0, 0, 0.171923637390136718, 0.985110282897949218, 120, 255, 1, 61122), -- Instance Portal (Party + Heroic + Challenge) (Area: Everbloom Wilds - Difficulty: 0) CreateObject1
(@OGUID+10, 233436, 1208, 6984, 6984, '1,2,8,23,24', 0, 0, 1744.467041015625, 1681.3385009765625, 9.003000259399414062, 0, 0, 0, 0, 1, 7200, 255, 1, 61122), -- Instance Portal (Party + Heroic + Challenge) (Area: Grimrail Depot - Difficulty: 0) CreateObject1
(@OGUID+11, 212899, 1116, 6721, 7411, '0', 0, 0, 8852.3359375, 1345.8038330078125, 98.26377105712890625, 1.602957844734191894, 0, 0, 0.718385696411132812, 0.695645034313201904, 120, 255, 1, 61122), -- Instance Portal (Party + Heroic + Challenge) (Area: The Iron Approach - Difficulty: 0) CreateObject1
(@OGUID+12, 233436, 0, 51, 1444, '0', 0, 0, -7482.423828125, -1323.46533203125, 301.383697509765625, 3.297368764877319335, 0, 0, -0.99696826934814453, 0.077809266746044158, 120, 255, 1, 61122), -- Instance Portal (Party + Heroic + Challenge) (Area: The Sea of Cinders - Difficulty: 0) CreateObject1
(@OGUID+13, 214513, 1358, 7307, 7307, '1,2,19,8,23', 0, 0, 107.01593017578125, -319.06329345703125, 65.46347808837890625, 0, 0, 0, 0, 1, 7200, 255, 1, 61122); -- Instance Portal (Party + Heroic + Challenge) (Area: Upper Blackrock Spire - Difficulty: 0) CreateObject1

-- Create Exit AT for The Everbloom
DELETE FROM `areatrigger_template` WHERE `Id` = @ATID;
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `ActionSetId`, `ActionSetFlags`, `VerifiedBuild`) VALUES
(@ATID, 1, 1, 0, (0x0002|0x0008), 0);

DELETE FROM `areatrigger_create_properties` WHERE `Id` = @ATCREATEID;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(@ATCREATEID, 1, @ATID, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 4, 6, 10, 4, 6, 10, 0, 0, '', 0);

DELETE FROM `areatrigger` WHERE `SpawnId` = @ATSPAWNID;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `Comment`) VALUES
(@ATSPAWNID, @ATCREATEID, 1, 1279, '1,2,8,23,24', 417.81, 1306.52, 125.41, 1.12, 0, 'The Everbloom - Exit');

DELETE FROM `areatrigger_template_actions` WHERE `AreaTriggerId` = @ATID;
INSERT INTO `areatrigger_template_actions` (`AreaTriggerId`, `IsCustom`, `ActionType`, `ActionParam`, `TargetType`) VALUES
(@ATID, 1, 2, 4855, 5);
