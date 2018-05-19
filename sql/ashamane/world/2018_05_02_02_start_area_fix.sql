-- Drenei start area fix
DELETE FROM `creature_queststarter` WHERE `id` = '17089' AND `quest` = '9421'; 
DELETE FROM `creature_queststarter` WHERE `id` = '17089' AND `quest` = '26969'; 
DELETE FROM `creature_queststarter` WHERE `id` = '16503' AND `quest` = '9289'; 
DELETE FROM `creature_queststarter` WHERE `id` = '16503' AND `quest` = '26958'; 
DELETE FROM `creature_queststarter` WHERE `id` = '16499' AND `quest` = '9288'; 
DELETE FROM `creature_queststarter` WHERE `id` = '16499' AND `quest` = '26963'; 
DELETE FROM `creature_queststarter` WHERE `id` = '16502' AND `quest` = '9291'; 
DELETE FROM `creature_queststarter` WHERE `id` = '16502' AND `quest` = '26970'; 
DELETE FROM `creature_queststarter` WHERE `id` = '16500' AND `quest` = '9290'; 
DELETE FROM `creature_queststarter` WHERE `id` = '16500' AND `quest` = '26968'; 
DELETE FROM `creature_queststarter` WHERE `id` = '16501' AND `quest` = '9287'; 
DELETE FROM `creature_queststarter` WHERE `id` = '16501' AND `quest` = '26966'; 
DELETE FROM `creature` WHERE `id`=16550;

DELETE FROM `gameobject` WHERE `id`=181286;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`,`isActive`,`ScriptName`,`VerifiedBuild`) VALUES
(19578, 181286, 530, 6456, 3527, 1, 0, 0, 0, -1, -4095.24, -13747.7, 74.6892, 3.85195, 0, 0, 0.937584, -0.347758, 600, 100, 1, 0, '', 0),
(19579, 181286, 530, 6456, 3527, 1, 0, 0, 0, -1, -4187.71, -13738.7, 74.42, 5.56, 0, 0, 0.353764, -0.935335, 600, 100, 1, 0, '', 0);
UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `id` IN (38345,43599);