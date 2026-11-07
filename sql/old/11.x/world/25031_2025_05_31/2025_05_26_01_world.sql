-- Using legacy MoP range for Mejis future plan to move MoP guids
SET @OGUID := 400644;

SET @ATID := 108;
SET @ATCREATEID := 103;
SET @ATSPAWNID := 202;

-- Fix Stratholme Service Entrance AT (formerly client AT, now server AT)
DELETE FROM `areatrigger_teleport` WHERE `ID` = 2214;

DELETE FROM `areatrigger_template` WHERE `Id` = @ATID;
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `ActionSetId`, `ActionSetFlags`, `VerifiedBuild`) VALUES
(@ATID, 1, 1, 0, (0x0002|0x0008), 0);

DELETE FROM `areatrigger_create_properties` WHERE `Id` = @ATCREATEID;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(@ATCREATEID, 1, @ATID, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 10, 10, 10, 10, 10, 10, 0, 0, '', 0);

DELETE FROM `areatrigger` WHERE `SpawnId` = @ATSPAWNID;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `Comment`) VALUES
(@ATSPAWNID, @ATCREATEID, 1, 0, '0', 3237.4599609375, -4060.6000976562, 112.01000213623, 1.85, 0, 'Stratholme - Service Entrance');

DELETE FROM `areatrigger_template_actions` WHERE `AreaTriggerId` = @ATID;
INSERT INTO `areatrigger_template_actions` (`AreaTriggerId`, `IsCustom`, `ActionType`, `ActionParam`, `TargetType`) VALUES
(@ATID, 1, 2, 3652, 5);

-- Fix Scholomance exit
DELETE FROM `areatrigger_teleport` WHERE `ID` = 7539;
INSERT INTO `areatrigger_teleport` (`ID`, `PortLocID`, `Name`) VALUES
(7539, 3672, 'Scholomance - Stairs Exit Target 001');

-- Shadowfang Keep, The Deadmines, Scholomance, Lower Blackrock Spire cosmetic portals
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+7;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 211498, 0, 130, 236, '0', 0, 0, -231.56597900390625, 1570.546875, 76.97183990478515625, 4.356500148773193359, 0, 0, -0.82110404968261718, 0.570778548717498779, 120, 255, 1, 60822), -- Instance Portal (Party + Heroic) (Area: Shadowfang Keep - Difficulty: 0) CreateObject1
(@OGUID+1, 211498, 33, 209, 209, '1,2,19', 0, 0, -231.071182250976562, 2104.975830078125, 76.89212799072265625, 1.157949090003967285, 0, 0, 0.547165870666503906, 0.837024211883544921, 7200, 255, 1, 60822), -- Instance Portal (Party + Heroic) (Area: Shadowfang Keep - Difficulty: 0) CreateObject1
(@OGUID+2, 214516, 0, 40, 20, '0', 0, 0, -11207.9423828125, 1679.657958984375, 24.05051040649414062, 4.618567466735839843, 0, 0, -0.7394876480102539, 0.673170149326324462, 120, 255, 1, 60822), -- Instance Portal (Party + Heroic) (Area: Moonbrook - Difficulty: 0) CreateObject1
(@OGUID+3, 211498, 36, 1581, 1581, '1,2,24', 0, 0, -14.8142366409301757, -388.649322509765625, 63.74285125732421875, 1.594143629074096679, 0, 0, 0.715312957763671875, 0.698804259300231933, 7200, 255, 1, 60822), -- Instance Portal (Party + Heroic) (Area: The Deadmines - Difficulty: 0) CreateObject1
(@OGUID+4, 214516, 36, 1581, 1581, '1,2,24', 0, 0, -109.614593505859375, -1003.848876953125, 34.34879684448242187, 1.290856480598449707, 0, 0, 0.601540565490722656, 0.798842251300811767, 7200, 255, 1, 60822), -- Instance Portal (Party + Heroic) (Area: The Deadmines - Difficulty: Normal) CreateObject1
(@OGUID+5, 212899, 0, 28, 2297, '0', 0, 0, 1278.4149169921875, -2550.982666015625, 87.80724334716796875, 3.619136810302734375, 0, 0, -0.97162914276123046, 0.236509650945663452, 120, 255, 1, 60822), -- Instance Portal (Party + Heroic + Challenge) (Area: Darrowmere Lake - Difficulty: 0) CreateObject1
(@OGUID+6, 211498, 0, 46, 254, '0', 0, 0, -7521.15966796875, -1334.1302490234375, 291.68731689453125, 0.113355278968811035, 0, 0, 0.056647300720214843, 0.998394250869750976, 120, 255, 1, 60822), -- Instance Portal (Party + Heroic) (Area: Blackrock Mountain - Difficulty: 0) CreateObject1
(@OGUID+7, 211498, 229, 1583, 1583, '1', 0, 0, 63.23027420043945312, -325.034149169921875, 53.91907501220703125, 0, 0, 0, 0, 1, 7200, 255, 1, 60822); -- Instance Portal (Party + Heroic) (Area: Blackrock Spire - Difficulty: 0) CreateObject1
