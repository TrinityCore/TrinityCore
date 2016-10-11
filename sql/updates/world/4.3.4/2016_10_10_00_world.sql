-- 
DELETE FROM `gameobject` WHERE `guid` IN (235373, 235374);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(235373, 203855, 1, 0, 0, 1, 169, 0, 1037.528, -4448.674, 14.66762, 5.671396, 0.02813578, -0.01407146, -0.3008509, 0.9531522, 120, 255, 1, 16057), -- 203855 (Area: -1)
(235374, 55615, 1, 0, 0, 1, 169, 0, 1002.277, -4416.151, 14.258929, 2.537378, 0.008088589, -0.06188297, 0.9524078, 0.2983695, 120, 255, 1, 16057); -- 55615 (Area: -1)

DELETE FROM `creature` WHERE `guid` IN (134677, 250023, 250024);
DELETE FROM `game_event_creature` WHERE `guid`=134677;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(134677, 3293, 1, 0, 0, 1, 169, 0, 0, 1, 1000.0122, -4414.460449, 14.363100, 5.557464, 120, 0, 0, 0, 0, 0, 0, 0, 0, 16057),
(250023, 40970, 1, 0, 0, 1, 169, 0, 0, 1, 318.4895, -4740.3544, 9.57535, 0.086387, 300, 0, 0, 0, 0, 2, 0, 0, 0, 0),
(250024, 40971, 1, 0, 0, 1, 169, 0, 0, 1, 318.2676, -4737.4443, 9.61057, 0.086387, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=250023;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(250023,250023,3,0,2),
(250023,250024,3,270,2);

DELETE FROM `creature_addon` WHERE `guid` IN (250023);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(250023,2500230,0,0,1,0, '');

DELETE FROM `waypoint_data` WHERE `id`=2500230;
INSERT INTO `waypoint_data`(`id`,`point`,`position_x`,`position_y`,`position_z`) VALUES
(2500230,1,318.471, -4740.5556, 9.58138),
(2500230,2,377.829, -4737.5097, 9.67630),
(2500230,3,419.512, -4731.6611, 9.02953),
(2500230,4,629.991, -4729.6743, -10.311),
(2500230,5,748.946, -4635.8989, -3.3200),
(2500230,6,805.083, -4541.9907, 5.00159),
(2500230,7,890.261, -4502.7241, 6.56010),
(2500230,8,1005.62, -4460.1665, 10.7170),
(2500230,9,890.261, -4502.7241, 6.56010),
(2500230,10,805.083, -4541.9907, 5.00159),
(2500230,11,748.946, -4635.8989, -3.3200),
(2500230,12,629.991, -4729.6743, -10.311),
(2500230,13,419.512, -4731.6611, 9.02953),
(2500230,14,377.829, -4737.5097, 9.67630),
(2500230,15,318.471, -4740.5556, 9.58138);
