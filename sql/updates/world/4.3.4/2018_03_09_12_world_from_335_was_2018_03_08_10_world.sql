-- 
DELETE FROM `creature` WHERE `guid`=64985;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(64985,25114,530,0,0,1,1,0,0,12664.64160,-6986.25,15.608,1.622840,7200,0,0,0,0,0,0,0,0,"",0);
UPDATE `conditions` SET `ConditionValue1`=3, `ConditionValue2`=25114  WHERE `SourceEntry` IN (45149) AND `SourceTypeOrReferenceId`=13;