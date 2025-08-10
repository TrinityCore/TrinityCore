-- Needed for quest a54952 and h59931 "Finding the Lost Expedition"
SET @SPAWNID := 23;

DELETE FROM `areatrigger` WHERE `SpawnId`=@SPAWNID+0;
INSERT INTO `areatrigger` (`SpawnId`,`AreaTriggerId`,`IsServerSide`,`MapId`,`PosX`,`PosY`,`PosZ`,`Orientation`,`PhaseUseFlags`,`PhaseId`,`PhaseGroup`,`Shape`,`ShapeData0`,`ShapeData1`,`ShapeData2`,`ShapeData3`,`ShapeData4`,`ShapeData5`,`ShapeData6`,`ShapeData7`,`ScriptName`,`Comment`) VALUES
(@SPAWNID+0,17635,1,2175,-245.40972900390625,-2492.088623046875,18.32131385803222656,2.475400209426879882,0,0,0,4,40,40,10,10,0,0,0,0,'','Exiles Reach - Finding the Lost Expedition - Quest Credit');

DELETE FROM `areatrigger_template` WHERE `Id` IN(17635);
INSERT INTO `areatrigger_template` (`Id`,`IsServerSide`,`Type`,`Flags`,`Data0`,`Data1`,`Data2`,`Data3`,`Data4`,`Data5`,`Data6`,`Data7`,`VerifiedBuild`) VALUES
(17635,1,4,0,40,40,10,10,0,0,0,0,0);
