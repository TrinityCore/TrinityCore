DELETE FROM `areatrigger_create_properties` WHERE `Id`=9049;
INSERT INTO `areatrigger_create_properties` (`Id`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES 
(9049, 13091, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0, '', 50585);

DELETE FROM `creature_template_addon` WHERE `entry`=47649;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(47649, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '81262');

DELETE FROM `spell_script_names` WHERE `spell_id` IN ('spell_dru_efflorescence', 'spell_dru_efflorescence_dummy', 'spell_dru_efflorescence_heal', 'spell_dru_spring_blossoms');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(145205, 'spell_dru_efflorescence'),
(81262, 'spell_dru_efflorescence_dummy'),
(81269, 'spell_dru_efflorescence_heal'),
(81269, 'spell_dru_spring_blossoms');
