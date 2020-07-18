-- 
DELETE FROM `creature` WHERE `guid`=64984;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(64984,23746,530,0,0,1,1,0,0,6718.222656, -7594.638672, 126.092712,0.413325,7200,0,0,0,0,0,0,0,0,"",0);
UPDATE `conditions` SET `ConditionValue1`=3, `ConditionValue2`=23746, `ConditionValue3`=64984  WHERE `SourceEntry` IN (42391) AND `SourceTypeOrReferenceId`=13;
