-- Pathing for Foulmane Entry: 1847
SET @NPC=1847;
SET @GUID=45454;
SET @PATH=@GUID * 10;
UPDATE `creature` SET `position_x`=1867.8231,`position_y`=-1582.6323,`position_z`=59.543274,`wander_distance`=0,`MovementType`=2 WHERE `guid`=@GUID;
UPDATE `creature_template` SET `MovementType`=2 WHERE `entry`=@NPC;
UPDATE `creature_template_addon` SET `PvpFlags`=0 WHERE `entry`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@GUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(@GUID, @PATH, 0, 0, 0, 0, 0, 1, 0, 0, 0, NULL);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH,1,1867.8231,-1582.6323,59.543274,NULL,0,0,0,100,0),
(@PATH,2,1862.686,-1575.6617,59.418274,NULL,0,0,0,100,0),
(@PATH,3,1865.2483,-1568.495,58.918274,NULL,0,0,0,100,0),
(@PATH,4,1862.7682,-1561.516,59.257603,NULL,0,0,0,100,0),
(@PATH,5,1866.2867,-1555.184,59.20914,NULL,0,0,0,100,0),
(@PATH,6,1874.4098,-1548.5449,59.26224,NULL,0,0,0,100,0),
(@PATH,7,1888.9252,-1546.674,58.882603,NULL,0,0,0,100,0),
(@PATH,8,1898.0934,-1554.2573,59.132603,NULL,0,0,0,100,0),
(@PATH,9,1900.8027,-1568.277,59.696507,NULL,0,0,0,100,0),
(@PATH,10,1899.4547,-1582.4746,59.418274,NULL,0,0,0,100,0),
(@PATH,11,1896.0823,-1588.0172,59.168274,NULL,0,0,0,100,0),
(@PATH,12,1885.111,-1591.6702,59.293274,NULL,0,0,0,100,0),
(@PATH,13,1874.7734,-1589.3805,59.629944,NULL,0,0,0,100,0);
