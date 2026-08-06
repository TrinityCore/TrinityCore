-- Spawnpoint for the Invisible bunny NPC
DELETE FROM `creature` WHERE `guid`=202603 AND `id`=35015;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnDifficulties`,`phaseId`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`wander_distance`,`currentwaypoint`,`curHealthPct`,`MovementType`,`ScriptName`,`VerifiedBuild`) VALUES
(202603,35015,624,0,0,'3,4',0,0,0,-178.141,77.8142,104.263,0,604800,0,0,100,2,'',0);

DELETE FROM `creature_addon` WHERE `guid`=202603;
INSERT INTO `creature_addon` (`guid`,`PathId`,`mount`,`MountCreatureID`,`StandState`,`AnimTier`,`VisFlags`,`SheathState`,`PvPFlags`,`emote`,`visibilityDistanceType`,`auras`) VALUES
(202603,16208240,0,0,0,3,0,1,0,0,0,NULL);

-- Insert Waypoints for the Invisible bunny NPC
DELETE FROM `waypoint_path` WHERE `PathId`=16208240;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Velocity`,`Comment`) VALUES
(16208240,1,2,NULL,'Migrated from refactor');

DELETE FROM `waypoint_path_node` WHERE `PathId`=16208240;
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(16208240,1,-178.141,77.8142,104.263,NULL,0),
(16208240,2,-177.576,82.8194,103.754,NULL,0),
(16208240,3,-196.210,116.535,103.922,NULL,0),
(16208240,4,-238.688,118.052,104.146,NULL,0),
(16208240,5,-259.618,81.6076,104.146,NULL,0),
(16208240,6,-239.828,46.4965,104.146,NULL,0),
(16208240,7,-197.300,46.5660,104.263,NULL,0);

-- Change the target to the Koralon Stalker
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=66665;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES 
(13,1,66665,0,0,31,0,3,35015,0,0,'Burning Breath: target Burning Breath Koralon Stalker');
