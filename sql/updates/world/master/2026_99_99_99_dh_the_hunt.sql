DELETE FROM `areatrigger_create_properties` WHERE `Id`=24961 AND `IsCustom`=0;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `MaxSummons`, `MaxUnits`, `PositionalSoundKitId`, `TimeToTargetScale`, `Speed`, `SpeedIsTime`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `Roll`, `Pitch`, `Yaw`, `TargetRoll`, `TargetPitch`, `TargetYaw`, `ScriptName`, `VerifiedBuild`) VALUES
(24961, 0, 99999, 1, 0, 0x0020, 0, 0, 0, -1, 0, 0, NULL, NULL, NULL, 0, 0, 1, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL, 'at_dh_the_hunt', 70448);

DELETE FROM `areatrigger_template` WHERE `Id`=99999 AND `IsCustom`=1;
INSERT INTO `areatrigger_template`
(`Id`, `IsCustom`, `Flags`, `ActionSetId`, `ActionSetFlags`, `VerifiedBuild`) VALUES
(99999, 1, 0, 0, 0x0080, 70448);
