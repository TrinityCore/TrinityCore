-- Spawnpoint for the Invisible bunny NPC
DELETE FROM `creature` WHERE `guid`=202603 AND `id`=35015;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`wander_distance`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(202603,35015,624,0,0,3,1,0,0,-178.141,77.8142,104.263,0,604800,0,0,1,0,2,0,0,0,'',0);

DELETE FROM `creature_addon` WHERE `guid`=202603;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`MountCreatureID`,`StandState`,`AnimTier`,`VisFlags`,`SheathState`,`PvPFlags`,`emote`,`visibilityDistanceType`,`auras`) VALUES
(202603,2026030,0,0,0,3,0,1,0,0,0,NULL);

DELETE FROM `creature_template_movement` WHERE `CreatureId`=35015;
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`,`Chase`,`Random`,`InteractionPauseTimer`) VALUES
(35015,NULL,NULL,1,NULL,NULL,NULL,NULL);

-- Insert Waypoints for the Invisible bunny NPC
DELETE FROM `waypoint_data` WHERE `id`=2026030;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(2026030,1,-178.141,77.8142,104.263,NULL,0,1,0,100,0),
(2026030,2,-177.576,82.8194,103.754,NULL,0,1,0,100,0),
(2026030,3,-196.210,116.535,103.922,NULL,0,1,0,100,0),
(2026030,4,-238.688,118.052,104.146,NULL,0,1,0,100,0),
(2026030,5,-259.618,81.6076,104.146,NULL,0,1,0,100,0),
(2026030,6,-239.828,46.4965,104.146,NULL,0,1,0,100,0),
(2026030,7,-197.300,46.5660,104.263,NULL,0,1,0,100,0);

-- Change the target to the Koralon Stalker
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=66665;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES 
(13,1,66665,0,0,31,0,3,35015,0,0,'Burning Breath: target Burning Breath Koralon Stalker');
