-- Spawn Deadmire
SET @GUID := 33909;
SET @NPC := @GUID*10;
DELETE FROM `creature` WHERE `id`=4841;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@GUID,4841,1,1,1,0,0,-3949.688,-3471.041,29.15445,4.288023,360,0,0,1902,0,0,0,0,0); -- respawn Deadmire on old guid
-- Set movement info
UPDATE `creature_addon` SET `path_id`=@NPC WHERE `guid`=@GUID;
UPDATE `creature_template` SET `MovementType`=2 WHERE `entry`=4841;
-- Add Waypoint Data
DELETE FROM `waypoint_data` WHERE `id`=@NPC;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@NPC,1,-3942.966,-3455.51,28.89743,0,0,0,0,0,0),
(@NPC,2,-3943.117,-3456.498,28.89743,0,0,0,0,0,0),
(@NPC,3,-3948.063,-3467.443,29.64743,0,0,0,0,0,0),
(@NPC,4,-3950.123,-3472.004,29.02243,0,0,0,0,0,0),
(@NPC,5,-3953.303,-3479.054,28.64743,0,0,0,0,0,0),
(@NPC,6,-3953.303,-3479.054,28.64743,0,0,0,0,0,0);
