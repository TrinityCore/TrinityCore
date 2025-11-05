DELETE FROM `spell_proc` WHERE `SpellId` IN (447444);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(447444,0x00,6,0x00000000,0x00000000,0x00000000,0x00000000,0x11000,0x0,0x1,0x2,0x403,0x0,0x0,0,100,0,0); -- Entropic Rift

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_entropic_rift', 'spell_pri_entropic_rift_aura');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(447444, 'spell_pri_entropic_rift'),
(450193, 'spell_pri_entropic_rift_aura');

DELETE FROM `areatrigger_template` WHERE `Id` = 35700 AND `IsCustom` = 0;
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `ActionSetId`, `ActionSetFlags`, `VerifiedBuild`) VALUES
(35700, 0, 0, 0, 0, 0);

DELETE FROM `areatrigger_create_properties` WHERE `Id` = 33200 AND `IsCustom` = 0;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `SpeedIsTime`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) 
VALUES (33200, 0, 35700, 0, 0, 0, 0, 0, 0, -1, 0, 0, 447445, 20000, 12, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 'areatrigger_pri_entropic_rift', 0);
