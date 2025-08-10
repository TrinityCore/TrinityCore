SET @TRIGGER_SPAWN_ID := 50;
SET @TRIGGER_ID := 50;

DELETE FROM `areatrigger_template` WHERE `Id` BETWEEN @TRIGGER_ID+0 AND @TRIGGER_ID+3;
INSERT INTO `areatrigger_template` (`Id`, `IsServerSide`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `VerifiedBuild`) VALUES
(@TRIGGER_ID+0, 0, 1, 4, 2, 16, 2.3, 2, 16, 2.3, 0, 0, 0),
(@TRIGGER_ID+1, 1, 0, 0, 70, 70, 0, 0, 0, 0, 0, 0, 0),
(@TRIGGER_ID+2, 1, 1, 0, 20, 20, 10, 20, 20, 10, 0, 0, 0),
(@TRIGGER_ID+3, 1, 1, 0, 30, 20, 10, 30, 20, 10, 0, 0, 0);

DELETE FROM `areatrigger` WHERE `SpawnId` BETWEEN @TRIGGER_SPAWN_ID+0 AND @TRIGGER_SPAWN_ID+3;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerId`, `IsServerSide`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `SpellForVisuals`, `ScriptName`, `Comment`, `VerifiedBuild`) VALUES
(@TRIGGER_SPAWN_ID+0, @TRIGGER_ID+1, 1, 1265, '0', 3982.48, -2936.61, 62.6424, 1.72932, 0, 0, 0, 0, 70, 70, 0, 0, 0, 0, 0, 0, NULL, 'at_altar_altercation_reach_altar', NULL, 0),
(@TRIGGER_SPAWN_ID+1, @TRIGGER_ID+2, 1, 1265, '0', 4187.81, -2779.99, 26.9349, 3.31491, 0, 0, 0, 1, 20, 20, 10, 20, 20, 10, 0, 0, NULL, '', NULL, 0),
(@TRIGGER_SPAWN_ID+2, @TRIGGER_ID+3, 1, 1265, '0', 4046.79, -2940.89, 62.1408, 1.66231, 0, 0, 0, 1, 30, 20, 10, 30, 20, 10, 0, 0, NULL, 'at_altar_altercation_kilrogg_talk', NULL, 0),
(@TRIGGER_SPAWN_ID+3, @TRIGGER_ID+3, 1, 1265, '0', 3921.71, -2962.14, 62.3053, 1.66231, 0, 0, 0, 1, 30, 20, 10, 30, 20, 10, 0, 0, NULL, 'at_altar_altercation_kilrogg_talk', NULL, 0);

DELETE FROM `areatrigger_template_actions` WHERE `AreaTriggerId` BETWEEN @TRIGGER_ID+0 AND @TRIGGER_ID+3;
INSERT INTO `areatrigger_template_actions` (`AreaTriggerId`, `IsServerSide`, `ActionType`, `ActionParam`, `TargetType`) VALUES
(@TRIGGER_ID+2, 1, 0, 169070, 5);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=28 AND `SourceEntry`=1 AND `SourceGroup` BETWEEN @TRIGGER_ID+1 AND @TRIGGER_ID+3;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(28, @TRIGGER_ID+2, 1, 0, 0, 47, 0, 34423, 8, 0, 0, 0, 0, '', 'Only trigger areatrigger when quest 34423 is taken'),
(28, @TRIGGER_ID+2, 1, 0, 0, 48, 0, 274409, 0, 0, 0, 0, 0, '', 'Only trigger areatrigger when has quest objective 274409 active'),

(28, @TRIGGER_ID+3, 1, 0, 0, 47, 0, 34423, 8, 0, 0, 0, 0, '', 'Only trigger areatrigger when quest 34423 is taken'),
(28, @TRIGGER_ID+3, 1, 0, 0, 48, 0, 273678, 0, 3, 1, 0, 0, '', 'Only trigger areatrigger when progress of quest objective 273678 not == 3');
