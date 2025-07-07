DELETE FROM `areatrigger_create_properties` WHERE `Id`=34378 AND `IsCustom`=0;
INSERT INTO `areatrigger_create_properties` (`Id`,`IsCustom`,`AreaTriggerId`,`IsAreatriggerCustom`,`Flags`,`MoveCurveId`,`ScaleCurveId`,`MorphCurveId`,`FacingCurveId`,`AnimId`,`AnimKitId`,`DecalPropertiesId`,`SpellForVisuals`,`TimeToTargetScale`,`Speed`,`Shape`,`ShapeData0`,`ShapeData1`,`ShapeData2`,`ShapeData3`,`ShapeData4`,`ShapeData5`,`ShapeData6`,`ShapeData7`,`ScriptName`,`VerifiedBuild`) VALUES
(34378,0,36703,0,0,0,0,0,0,-1,0,0,NULL,60000,0,4,5,5,5,5,1,1,0,0,'areatrigger_hun_implosive_trap',60257); -- Spell: 462032 (Implosive Trap)

DELETE FROM `areatrigger_template` WHERE `Id`=36703 AND `IsCustom`=0;
INSERT INTO `areatrigger_template` (`Id`,`IsCustom`,`Flags`,`VerifiedBuild`) VALUES
(36703,0,0,60257);
