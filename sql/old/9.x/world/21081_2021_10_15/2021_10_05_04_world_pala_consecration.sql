-- 
UPDATE `areatrigger_template` SET `ScriptName`='areatrigger_pal_consecration', `VerifiedBuild`=40120 WHERE `Id`=9228;

DELETE FROM `areatrigger_create_properties` WHERE `Id`=4488;
INSERT INTO `areatrigger_create_properties` (`Id`,`AreaTriggerId`,`MoveCurveId`,`ScaleCurveId`,`MorphCurveId`,`FacingCurveId`,`AnimId`,`AnimKitId`,`DecalPropertiesId`,`TimeToTarget`,`TimeToTargetScale`,`Shape`,`ShapeData0`,`ShapeData1`,`ShapeData2`,`ShapeData3`,`ShapeData4`,`ShapeData5`,`VerifiedBuild`) VALUES
(4488,9228,0,0,0,0,0,0,0,0,12000,0,8,8,0,0,0,0,40120); -- SpellId : 26573

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pal_consecration','spell_pal_hammer_of_the_righteous');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(26573,'spell_pal_consecration'),
(53595,'spell_pal_hammer_of_the_righteous');
