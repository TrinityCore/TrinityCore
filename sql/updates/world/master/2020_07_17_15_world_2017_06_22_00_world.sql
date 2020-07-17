-- 
DELETE FROM `creature` WHERE `guid` IN (80429,80430,80431);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(80429, 28083, 571, 0, 0, '0', 0, 0, 0, 0, 0, 4828.275, 4759.095, -75.660, 3.921138, 300, 5, 0, 11770, 0, 1, 0, 0, 0, 0),
(80430, 28083, 571, 0, 0, '0', 0, 0, 0, 0, 0, 4767.104, 4694.607, -67.343, 5.262608, 300, 5, 0, 11770, 0, 1, 0, 0, 0, 0),
(80431, 28083, 571, 0, 0, '0', 0, 0, 0, 0, 0, 4859.410, 4397.716, -62.169, 4.507830, 300, 5, 0, 11770, 0, 1, 0, 0, 0, 0);

DELETE FROM `pool_template` WHERE `entry`=384;
INSERT INTO pool_template (`entry`,`max_limit`,`description`) VALUES
(384,1, 'Serfex the Reaver Spawn (1 out 4)');

DELETE FROM `pool_creature` WHERE `pool_entry`=384;
INSERT INTO pool_creature(`guid`,`pool_entry`,`chance`,`description`) VALUES
(80429,384,0, 'Serfex the Reaver 1'),
(80430,384,0, 'Serfex the Reaver 2'),
(80431,384,0, 'Serfex the Reaver 3'),
(112864,384,0, 'Serfex the Reaver 4');
