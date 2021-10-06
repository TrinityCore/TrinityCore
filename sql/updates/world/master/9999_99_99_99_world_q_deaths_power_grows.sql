-- 
SET @AREATRIGGERGUID := 3;
SET @AREATRIGGERID := 3;

DELETE FROM `areatrigger_template` WHERE `Id`=@AREATRIGGERID+0 AND `IsServerSide`=1;
INSERT INTO `areatrigger_template` (`Id`, `IsServerSide`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `ScriptName`, `VerifiedBuild`) VALUES
(@AREATRIGGERID+0, 1, 4, 0, 4, 4, 6, 6, 0, 0, '', 0); -- Areatrigger to give Swear Fealty aura

DELETE FROM `areatrigger_template_actions` WHERE `AreaTriggerId`=@AREATRIGGERID+0 AND `IsServerSide`=1;
INSERT INTO `areatrigger_template_actions` (`AreaTriggerId`, `IsServerSide`, `ActionType`, `ActionParam`, `TargetType`) VALUES
(@AREATRIGGERID+0, 1, 0, 316884, 5);

DELETE FROM `areatrigger` WHERE `SpawnId`=@AREATRIGGERGUID+0;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerId`, `IsServerSide`, `MapId`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `Comment`) VALUES
(@AREATRIGGERGUID+0, @AREATRIGGERID+0, 1, 2297, 426.432281494140625, -2123.810791015625, 864.97430419921875, 3.191439628601074218, 0, 0, 0, 4, 4, 4, 6, 6, 0, 0, 'Allied Race DK Start ICC - Swear Fealty AT');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=28 AND `SourceGroup`=@AREATRIGGERID+0 AND `SourceEntry`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `Comment`) VALUES
(28, @AREATRIGGERID+0, 1, 0, 9, 0, 58877, "Only trigger areatrigger when quest Death's Power Grows is taken");
