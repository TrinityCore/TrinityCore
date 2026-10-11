-- Pathing for Alshirr Banebreath Entry: 14340
SET @NPC=14340;
SET @GUID=51894;
SET @PATH=4151520;
DELETE FROM `creature` WHERE `guid`=@GUID;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnDifficulties`,`phaseId`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`wander_distance`,`currentwaypoint`,`curHealthPct`,`MovementType`,`ScriptName`,`StringId`,`VerifiedBuild`) VALUES
(@GUID,14340,1,0,0,'0',0,0,0,4026.52,-555.293,342.505,3.99761,9900,0,0,100,2,'',NULL,0);
UPDATE `creature` SET `position_x`=4026.523,`position_y`=-555.293,`position_z`=342.505,`wander_distance`=0,`MovementType`=2 WHERE `guid`=@GUID;
DELETE FROM `creature_addon` WHERE `guid`=@GUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(@GUID,@PATH,0,0,0,0,0,1,0,0,0,NULL);
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH,0,0x1,NULL,'Alshirr Banebreath - Idle');
DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH,0,4026.523,-555.293,342.40234,NULL,262),
(@PATH,1,3999.6077,-585.43585,338.04718,NULL,0),
(@PATH,2,3967.8643,-599.3677,338.6643,NULL,0),
(@PATH,3,3939.5344,-610.4964,340.5687,NULL,0),
(@PATH,4,3918.8508,-620.3714,339.54425,NULL,0),
(@PATH,5,3893.1277,-649.1434,333.9112,NULL,0),
(@PATH,6,3867.4185,-662.55194,330.7174,NULL,0),
(@PATH,7,3850.8962,-677.3118,328.14496,NULL,0),
(@PATH,8,3841.1611,-713.5064,325.41202,NULL,0),
(@PATH,9,3836.197,-740.15375,319.38464,NULL,0),
(@PATH,10,3827.0447,-763.3758,314.79254,NULL,0),
(@PATH,11,3818.8672,-787.662,307.49838,NULL,0),
(@PATH,12,3792.5173,-812.1507,307.85388,NULL,0),
(@PATH,13,3768.1362,-831.72095,310.0667,NULL,0),
(@PATH,14,3771.9072,-848.68176,306.90726,NULL,0),
(@PATH,15,3757.2969,-866.6099,313.935,NULL,5);
