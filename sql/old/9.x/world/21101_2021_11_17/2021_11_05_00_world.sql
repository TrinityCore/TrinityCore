-- 
SET @ATID := 6;
SET @ATGUID := 6;
DELETE FROM `areatrigger_template` WHERE `IsServerSide`=1 AND `Id`=@ATID+0;
INSERT INTO `areatrigger_template` (`Id`, `IsServerSide`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `ScriptName`, `VerifiedBuild`) VALUES
(@ATID+0, 1, 4, 0, 0.5, 0.5, 3, 3, 0, 0, 'areatrigger_stormwind_teleport_unit', 0);

DELETE FROM `areatrigger` WHERE `SpawnId`=@ATGUID+0;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerId`, `IsServerSide`, `MapId`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `Comment`) VALUES
(@ATGUID+0, @ATID+0, 1, 2268, 729.515625, 609.68231201171875, -238.236251831054687, 2.836383819580078125, 0, 0, 0, 4, 0.5, 0.5, 3, 3, 0, 0, 'Mechagon City - Teleporter to Stormwind');
