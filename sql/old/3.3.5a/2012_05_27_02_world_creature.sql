-- Add Missing spawn for Queen Angerboda
DELETE FROM `creature` WHERE `id`=24023;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(42162,24023,571,1,1,0,0,2855.372,-3869.662,248.6132,2.181662,150,0,0,9291,3231,0,0,0,0);
