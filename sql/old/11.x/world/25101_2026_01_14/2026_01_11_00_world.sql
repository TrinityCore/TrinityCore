DELETE FROM `areatrigger_template` WHERE `Id` IN (3921,36160) AND `IsCustom`=0;
INSERT INTO `areatrigger_template` (`Id`,`IsCustom`,`Flags`,`ActionSetId`,`ActionSetFlags`,`VerifiedBuild`) VALUES
( 3921,0,0,0,0,65299),
(36160,0,0,0,0,65299);

DELETE FROM `areatrigger_create_properties` WHERE `Id` IN (658,33742,34681,34682,33740,34683) AND `IsCustom`=0;
INSERT INTO `areatrigger_create_properties` (`Id`,`IsCustom`,`AreaTriggerId`,`IsAreatriggerCustom`,`Flags`,`MoveCurveId`,`ScaleCurveId`,`MorphCurveId`,`FacingCurveId`,`AnimId`,`AnimKitId`,`DecalPropertiesId`,`SpellForVisuals`,`TimeToTargetScale`,`Speed`,`SpeedIsTime`,`Shape`,`ShapeData0`,`ShapeData1`,`ShapeData2`,`ShapeData3`,`ShapeData4`,`ShapeData5`,`ShapeData6`,`ShapeData7`,`ScriptName`,`VerifiedBuild`) VALUES
(  658,0, 3921,0,2,0,0,78101,0,-1,0,0,NULL,0,1,0,0,0,30,0,0,0,0,0,0,'areatrigger_pri_halo',65299), -- no talents
(33742,0, 3921,0,2,0,0,78103,0,-1,0,0,NULL,0,1,0,0,0,40,0,0,0,0,0,0,'areatrigger_pri_halo',65299), -- Power Surge
(34681,0, 3921,0,2,0,0,78886,0,-1,0,0,NULL,0,1,0,0,0,34,0,0,0,0,0,0,'areatrigger_pri_halo',65299), -- Phantom Reach
(34682,0, 3921,0,2,0,0,78887,0,-1,0,0,NULL,0,1,0,0,0,46,0,0,0,0,0,0,'areatrigger_pri_halo',65299), -- Phantom Reach + Power Surge
(33740,0,36160,0,2,0,0,76237,0,-1,0,0,NULL,0,1,0,0,0,40,0,0,0,0,0,0,'areatrigger_pri_halo_return',65299), -- Power Surge
(34683,0,36160,0,2,0,0,76237,0,-1,0,0,NULL,0,1,0,0,0,46,0,0,0,0,0,0,'areatrigger_pri_halo_return',65299); -- Phantom Reach + Power Surge

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_halo_effect_selector','spell_pri_halo_return_effect_selector');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(120517,'spell_pri_halo_effect_selector'),
(120644,'spell_pri_halo_effect_selector'),
(449840,'spell_pri_halo_return_effect_selector'),
(453094,'spell_pri_halo_return_effect_selector');
