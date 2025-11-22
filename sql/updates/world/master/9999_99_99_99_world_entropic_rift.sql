DELETE FROM `areatrigger_template` WHERE `Id` = 35700 AND `IsCustom` = 0;
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `ActionSetId`, `ActionSetFlags`, `VerifiedBuild`) VALUES
(35700, 0, 0, 0, 0, 0);

DELETE FROM `areatrigger_create_properties` WHERE `Id` = 33200 AND `IsCustom` = 0;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `SpeedIsTime`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) 
VALUES (33200, 0, 35700, 0, 0, 0, 0, 0, 0, -1, 0, 0, 447445, 20000, 12, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 'areatrigger_pri_entropic_rift', 0);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_entropic_rift', 'spell_pri_entropic_rift_aura');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(8092, 'spell_pri_entropic_rift'),
(263165, 'spell_pri_entropic_rift'),
(450193, 'spell_pri_entropic_rift_aura');
