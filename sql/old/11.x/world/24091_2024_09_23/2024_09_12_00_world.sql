SET @ATID := 36797;

-- Serverside Areatrigger
DELETE FROM `areatrigger_create_properties` WHERE `Id`=34472 AND `IsCustom`=0;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(34472, 0, @ATID, 1, 4, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0, 'areatrigger_sha_arctic_snowstorm', 0);

DELETE FROM `areatrigger_template` WHERE `Id`=@ATID AND `IsCustom`=1;
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `ActionSetId`, `ActionSetFlags`, `VerifiedBuild`) VALUES
(@ATID, 1, 1, 0, 0, 0);

-- Proc
DELETE FROM `spell_proc` WHERE `SpellId` IN (462764);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(462764,0x0,11,0x80000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x0,0x0,0x0,0,0,0,0); -- Arctic Snowstorm

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_sha_arctic_snowstorm';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(462764, 'spell_sha_arctic_snowstorm');
