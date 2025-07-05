-- The War Within - Dornogal Dungeons
SET @WORLDSAFELOCID := 300000;
SET @TELEID := 5000;
SET @OGUID := 900000;
SET @ATID := 800;
SET @ATCREATEID := 900;
SET @ATSPAWNID := 1000;

DELETE FROM `world_safe_locs` WHERE `ID` BETWEEN @WORLDSAFELOCID+0 AND @WORLDSAFELOCID+7;
INSERT INTO `world_safe_locs` (`ID`, `MapID`, `LocX`, `LocY`, `LocZ`, `Facing`, `COMMENT`) VALUES
(@WORLDSAFELOCID+0, 2579, 1234.56, 567.89, 321.01, 4.712389, '11.x Dungeon - Dornogal - Dawnspire Summit Entrance'),
(@WORLDSAFELOCID+1, 2200, 987.65, 432.10, 210.98, 0.785398, '11.x Dungeon - Dornogal - Dawnspire Summit Exit'),
(@WORLDSAFELOCID+2, 2579, 2345.67, 678.90, 432.12, 3.141593, '11.x Dungeon - Dornogal - Halls of the Deep Entrance'),
(@WORLDSAFELOCID+3, 2580, 345.67, 890.12, 543.21, 2.356194, '11.x Dungeon - Dornogal - Halls of the Deep Exit'),
(@WORLDSAFELOCID+4, 2579, 4567.89, 123.45, 654.32, 1.570796, '11.x Dungeon - Dornogal - The Molten Forge Entrance'),
(@WORLDSAFELOCID+5, 2581, 567.89, 234.56, 765.43, 5.497787, '11.x Dungeon - Dornogal - The Molten Forge Exit'),
(@WORLDSAFELOCID+6, 2579, 6789.01, 345.67, 876.54, 0.000000, '11.x Dungeon - Dornogal - Nerub'ar Palace Entrance'),
(@WORLDSAFELOCID+7, 2582, 789.01, 456.78, 987.65, 3.926991, '11.x Dungeon - Dornogal - Nerub'ar Palace Exit');

DELETE FROM `game_tele` WHERE `id` BETWEEN @TELEID+0 AND @TELEID+7;
INSERT INTO `game_tele` (`id`, `position_x`, `position_y`, `position_z`, `orientation`, `map`, `name`) VALUES
(@TELEID+0, 987.65, 432.10, 210.98, 0.785398, 2200, 'DawnspireSummit'),
(@TELEID+1, 1234.56, 567.89, 321.01, 4.712389, 2579, 'DawnspireSummitDungeon'),
(@TELEID+2, 345.67, 890.12, 543.21, 2.356194, 2580, 'HallsOfTheDeep'),
(@TELEID+3, 2345.67, 678.90, 432.12, 3.141593, 2579, 'HallsOfTheDeepDungeon'),
(@TELEID+4, 567.89, 234.56, 765.43, 5.497787, 2581, 'TheMoltenForge'),
(@TELEID+5, 4567.89, 123.45, 654.32, 1.570796, 2579, 'TheMoltenForgeDungeon'),
(@TELEID+6, 789.01, 456.78, 987.65, 3.926991, 2582, 'NerubarPalace'),
(@TELEID+7, 6789.01, 345.67, 876.54, 0.000000, 2579, 'NerubarPalaceDungeon');

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+7;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 392145, 2200, 15000, 15001, '0', '0', 0, 1200.00, 550.00, 320.00, 4.712389, 0, 0, -0.707106, 0.707107, 120, 255, 1, 50000),
(@OGUID+1, 392145, 2579, 15002, 15003, '1,2,23,8', '0', 0, 1250.00, 600.00, 330.00, 0.785398, 0, 0, 0.382683, 0.923880, 7200, 255, 1, 50000),
(@OGUID+2, 392146, 2200, 15000, 15004, '0', '0', 0, 2300.00, 700.00, 430.00, 3.141593, 0, 0, -1.000000, 0.000000, 120, 255, 1, 50000),
(@OGUID+3, 392146, 2580, 15005, 15006, '1,2,23,8', '0', 0, 350.00, 900.00, 540.00, 2.356194, 0, 0, 0.923880, 0.382683, 7200, 255, 1, 50000),
(@OGUID+4, 392147, 2200, 15000, 15007, '0', '0', 0, 4550.00, 150.00, 650.00, 1.570796, 0, 0, 0.707107, 0.707107, 120, 255, 1, 50000),
(@OGUID+5, 392147, 2581, 15008, 15009, '1,2,23,8', '0', 0, 600.00, 250.00, 760.00, 5.497787, 0, 0, -0.382683, 0.923880, 7200, 255, 1, 50000),
(@OGUID+6, 392148, 2200, 15000, 15010, '0', '0', 0, 6770.00, 350.00, 875.00, 0.000000, 0, 0, 0.000000, 1.000000, 120, 255, 1, 50000),
(@OGUID+7, 392148, 2582, 15011, 15012, '1,2,23,8', '0', 0, 800.00, 500.00, 980.00, 3.926991, 0, 0, -0.923880, 0.382683, 7200, 255, 1, 50000);

DELETE FROM `areatrigger_template` WHERE `Id` BETWEEN @ATID+0 AND @ATID+7;
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `ActionSetId`, `ActionSetFlags`, `VerifiedBuild`) VALUES
(@ATID+0, 1, 1, 0, 0, 0), -- Dawnspire Summit - Enter
(@ATID+1, 1, 1, 0, 0, 0), -- Dawnspire Summit - Exit
(@ATID+2, 1, 1, 0, 0, 0), -- Halls of the Deep - Enter
(@ATID+3, 1, 1, 0, 0, 0), -- Halls of the Deep - Exit
(@ATID+4, 1, 1, 0, 0, 0), -- The Molten Forge - Enter
(@ATID+5, 1, 1, 0, 0, 0), -- The Molten Forge - Exit
(@ATID+6, 1, 1, 0, 0, 0), -- Nerub'ar Palace - Enter
(@ATID+7, 1, 1, 0, 0, 0); -- Nerub'ar Palace - Exit

DELETE FROM `areatrigger_create_properties` WHERE `Id` BETWEEN @ATCREATEID+0 AND @ATCREATEID+7;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(@ATCREATEID+0, 1, @ATID+0, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 3, 12, 45, 3, 12, 45, 0, 0, '', 0),
(@ATCREATEID+1, 1, @ATID+1, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 3, 14, 15, 3, 14, 15, 0, 0, '', 0),
(@ATCREATEID+2, 1, @ATID+2, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 3, 5, 10, 3, 5, 10, 0, 0, '', 0),
(@ATCREATEID+3, 1, @ATID+3, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 3, 7, 12, 3, 7, 12, 0, 0, '', 0),
(@ATCREATEID+4, 1, @ATID+4, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 3, 9, 25, 3, 9, 25, 0, 0, '', 0),
(@ATCREATEID+5, 1, @ATID+5, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 3, 11, 10, 3, 11, 10, 0, 0, '', 0),
(@ATCREATEID+6, 1, @ATID+6, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 4, 5, 15, 4, 5, 15, 0, 0, '', 0),
(@ATCREATEID+7, 1, @ATID+7, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 3, 5, 10, 3, 5, 10, 0, 0, '', 0);

DELETE FROM `areatrigger` WHERE `SpawnId` BETWEEN @ATSPAWNID+0 AND @ATSPAWNID+7;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `Comment`) VALUES
(@ATSPAWNID+0, @ATCREATEID+0, 1, 2200, '0', 1200.00, 550.00, 320.00, 4.712389, 0, 'Dawnspire Summit - Enter'),
(@ATSPAWNID+1, @ATCREATEID+1, 1, 2579, '1,2,23,8', 1250.00, 600.00, 330.00, 0.785398, 0, 'Dawnspire Summit - Exit'),
(@ATSPAWNID+2, @ATCREATEID+2, 1, 2200, '0', 2300.00, 700.00, 430.00, 3.141593, 0, 'Halls of the Deep - Enter'),
(@ATSPAWNID+3, @ATCREATEID+3, 1, 2580, '1,2,23,8', 350.00, 900.00, 540.00, 2.356194, 0, 'Halls of the Deep - Exit'),
(@ATSPAWNID+4, @ATCREATEID+4, 1, 2200, '0', 4550.00, 150.00, 650.00, 1.570796, 0, 'The Molten Forge - Enter'),
(@ATSPAWNID+5, @ATCREATEID+5, 1, 2581, '1,2,23,8', 600.00, 250.00, 760.00, 5.497787, 0, 'The Molten Forge - Exit'),
(@ATSPAWNID+6, @ATCREATEID+6, 1, 2200, '0', 6770.00, 350.00, 875.00, 0.000000, 0, 'Nerub\'ar Palace - Enter'),
(@ATSPAWNID+7, @ATCREATEID+7, 1, 2582, '1,2,23,8', 800.00, 500.00, 980.00, 3.926991, 0, 'Nerub\'ar Palace - Exit');

DELETE FROM `areatrigger_template_actions` WHERE `AreaTriggerId` BETWEEN @ATID+0 AND @ATID+7;
INSERT INTO `areatrigger_template_actions` (`AreaTriggerId`, `IsCustom`, `ActionType`, `ActionParam`, `TargetType`) VALUES
(@ATID+0, 1, 2, @WORLDSAFELOCID+0, 5), -- Dawnspire Summit - Enter
(@ATID+1, 1, 2, @WORLDSAFELOCID+1, 5), -- Dawnspire Summit - Exit
(@ATID+2, 1, 2, @WORLDSAFELOCID+2, 5), -- Halls of the Deep - Enter
(@ATID+3, 1, 2, @WORLDSAFELOCID+3, 5), -- Halls of the Deep - Exit
(@ATID+4, 1, 2, @WORLDSAFELOCID+4, 5), -- The Molten Forge - Enter
(@ATID+5, 1, 2, @WORLDSAFELOCID+5, 5), -- The Molten Forge - Exit
(@ATID+6, 1, 2, @WORLDSAFELOCID+6, 5), -- Nerub'ar Palace - Enter
(@ATID+7, 1, 2, @WORLDSAFELOCID+7, 5); -- Nerub'ar Palace - Exit
