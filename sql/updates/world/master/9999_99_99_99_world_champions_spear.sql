DELETE FROM `areatrigger_template` WHERE (`IsCustom`=0 AND `Id`=29927);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `VerifiedBuild`) VALUES
(29927, 0, 64877);

DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id`IN (25558,25559));
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`,`ScriptName`,`VerifiedBuild`) VALUES
(25558, 0, 29927, 0, 0, 0, 0, 0, 0, -1, 0, 0, 376081, 4000, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 'at_warr_champions_spear', 64877), -- Champion's Spear
(25559, 0, 29927, 0, 0, 0, 0, 0, 0, -1, 0, 0, 376081, 4000, 0, 0, 5, 15, 0, 0, 0, 0, 0, 0, 'at_warr_champions_spear', 64877); -- Champion's Spear
