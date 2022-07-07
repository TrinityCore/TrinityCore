-- 
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=97285;
DELETE FROM `smart_scripts` WHERE `entryorguid`=97285 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `action_type`, `action_param1`, `target_type`, `comment`) VALUES
(97285, 0, 0, 0, 25, 11, 192078, 1, 'On Reset - Cast Spell Wind Rush Totem - Self');

UPDATE `areatrigger_template` SET `ScriptName`='areatrigger_sha_wind_rush_totem', `VerifiedBuild`=40120 WHERE `Id`=12676;

DELETE FROM `areatrigger_create_properties` WHERE `Id`=8537;
INSERT INTO `areatrigger_create_properties` (`Id`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `VerifiedBuild`) VALUES
(8537, 12676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 0, 0, 0, 0, 40120); -- SpellId : 192078 
