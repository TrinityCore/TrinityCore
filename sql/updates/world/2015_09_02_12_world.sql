--
SET @NPC_FLAMEBRINGERS_CHAIN := 27297;
SET @GUID := 43489; -- Need 2

DELETE FROM `creature` WHERE `id`=@NPC_FLAMEBRINGERS_CHAIN;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@GUID+0,@NPC_FLAMEBRINGERS_CHAIN,571,1,1,17188,0,2786.589,-2483.958,49.05502,4.171337,120,0,0,42,0,0,0,33555200,8),
(@GUID+1,@NPC_FLAMEBRINGERS_CHAIN,571,1,1,17188,0,2802.708,-2520.483,52.75195,2.443461,120,0,0,42,0,0,0,33555200,8);
