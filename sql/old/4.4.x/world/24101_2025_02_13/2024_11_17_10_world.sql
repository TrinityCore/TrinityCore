DELETE FROM `phase_area` WHERE `AreaId`= 4;

DELETE FROM `areatrigger_template`;
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `ActionSetId`, `ActionSetFlags`, `VerifiedBuild`) VALUES
(4352, 1, 0x1, 0, 0, 0),
(4354, 1, 0x1, 0, 0, 0);

DELETE FROM `areatrigger`;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseId`) VALUES
(1, 1, 1, 530, '0', -247.677, 895.675, 144.362, 0, '0'),
(2, 2, 1, 0, '0', -11908.9, -3209.1, -14.7905, 3.281, '0');

DELETE FROM `areatrigger_create_properties`;
INSERT INTO `areatrigger_create_properties`(`Id`,`IsCustom`,`AreaTriggerId`,`IsAreatriggerCustom`,`Flags`,`MoveCurveId`,`ScaleCurveId`,`MorphCurveId`,`FacingCurveId`,`AnimId`,`AnimKitId`,`DecalPropertiesId`,`SpellForVisuals`,`TimeToTarget`,`TimeToTargetScale`,`Shape`,`ShapeData0`,`ShapeData1`,`ShapeData2`,`ShapeData3`,`ShapeData4`,`ShapeData5`,`ShapeData6`,`ShapeData7`,`ScriptName`,`VerifiedBuild`) VALUES 
(1,1,4352,1,0x0,0,0,0,0,-1,0,0,NULL,0,0,1,102.8,6.611,133.8,102.8,6.611,133.8, 0,0,'',0),
(2,1,4354,1,0x0,0,0,0,0,-1,0,0,NULL,0,0,1, 3.833,20.47,52.83,3.833,20.47,52.8,0,0,'',0);

DELETE FROM `areatrigger_create_properties_orbit`;
DELETE FROM `areatrigger_create_properties_polygon_vertex`;
DELETE FROM `areatrigger_create_properties_spline_point`;
DELETE FROM `areatrigger_template_actions`;
INSERT INTO `areatrigger_template_actions` (`AreaTriggerId`, `IsCustom`, `ActionType`, `ActionParam`, `TargetType`) VALUES
(4352, 1, 2, 3736, 0),
(4354, 1, 2, 3737, 0);

DELETE FROM `smart_scripts` WHERE `source_type` IN (11,12);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=28;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceId` IN (11,12);

UPDATE `world_safe_locs` SET `LocX`= -11896.799804688, `LocY`= -3206.7700195312, `LocZ`= -14.67240047455, `Facing`= 10 WHERE `ID`= 3736;
DELETE FROM `gameobject` WHERE `guid` IN (500409, 500410);
DELETE FROM `gameobject_addon` WHERE `guid` IN (500409, 500410);
