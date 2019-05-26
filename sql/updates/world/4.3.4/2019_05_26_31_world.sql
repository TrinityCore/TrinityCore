-- Add missing npcs
SET @GUID := 252530;
DELETE FROM `creature` WHERE `guid` BETWEEN @GUID AND @GUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseUseFlags`, `phaseMask`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@GUID,47292,1,5034,5602,1,0,1,315,0,-1,0,1,-10228.2,1165.49,117.5203,2.932153,120,0,0,1,0,0,0,0,0,'',0),
(@GUID+1,47292,1,5034,5602,1,0,1,315,0,-1,0,0,-10243.8,1168.54,114.3183,3.298672,120,0,0,1,0,0,0,0,0,'',0),
(@GUID+2,47292,1,5034,5602,1,0,1,315,0,-1,0,0,-10245,1158.94,113.3823,2.80998,120,0,0,1,0,0,0,0,0,'',0);

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @GUID AND @GUID+2;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@GUID,0,0,1,1,0, ''),
(@GUID+1,0,0,0,1,0, '32951'),
(@GUID+2,0,0,0,1,0, '32951');
