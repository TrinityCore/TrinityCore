-- Uldum zone missing spawns
DELETE FROM `creature` WHERE `guid` IN (252598,252599,252600,252601,252602);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(252598,47291,1,0,0,1,1,169,0,0,0,-10336,899.299,60.6705,3.84814,120,0,0,1,0,0,0,0,0,'',0),
(252599,47291,1,0,0,1,1,169,0,0,0,-10348.1,881.429,55.0621,1.50098,120,0,0,1,0,0,0,0,0,'',0),
(252600,47291,1,0,0,1,1,169,0,0,0,-10350.1,898.05,58.1504,4.71239,120,0,0,1,0,0,0,0,0,'',0),
(252601,47291,1,0,0,1,1,169,0,0,0,-10357.6,888.941,53.3628,6.17846,120,0,0,1,0,0,0,0,0,'',0),
(252602,47291,1,0,0,1,1,169,0,0,0,-10250.5,1179.73,114.221,5.49779,120,0,0,1,0,0,0,0,0,'',0);
