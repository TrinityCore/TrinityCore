DELETE FROM `areatrigger_template` WHERE `Id`=29620 AND `IsCustom`=0;
INSERT INTO `areatrigger_template` (`Id`,`IsCustom`,`Flags`,`ActionSetId`,`ActionSetFlags`,`VerifiedBuild`) VALUES
(29620,0,0,0,0,64978);

DELETE FROM `areatrigger_create_properties` WHERE `Id`=25138 AND `IsCustom`=0;
INSERT INTO`areatrigger_create_properties` (`Id`,`IsCustom`,`AreaTriggerId`,`IsAreatriggerCustom`,`Flags`,`MoveCurveId`,`ScaleCurveId`,`MorphCurveId`,`FacingCurveId`,`AnimId`,`AnimKitId`,`DecalPropertiesId`,`SpellForVisuals`,`TimeToTargetScale`,`Speed`,`SpeedIsTime`,`Shape`,`ShapeData0`,`ShapeData1`,`ShapeData2`,`ShapeData3`,`ShapeData4`,`ShapeData5`,`ShapeData6`,`ShapeData7`,`ScriptName`,`VerifiedBuild`) VALUES
(25138,0,29620,0,0,0,0,0,0,-1,0,0,372784,15000,0,0,4,10,10,4,4,0.3,0.3,0,0,'',64978);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_divine_word','spell_pri_divine_word_sanctuary','spell_pri_divine_word_sanctuary_heal');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(372760,'spell_pri_divine_word'),
(372784,'spell_pri_divine_word_sanctuary'),
(372787,'spell_pri_divine_word_sanctuary_heal');

DELETE FROM `spell_proc` WHERE `SpellId` IN (372760);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(372760,0x00,6,0x10000400,0x00000000,0x00000020,0x00000000,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0,0,0,1); -- Divine Word
