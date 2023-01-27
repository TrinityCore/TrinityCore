-- billy and adam where moving around and swiming.
-- Still need paths and chat

-- Billy
DELETE FROM `creature` WHERE `guid` = '30855' ;
DELETE FROM `creature` WHERE `guid` = '998584' ;
INSERT  INTO `creature`(`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`npcflag2`,`unit_flags`,`unit_flags2`,`dynamicflags`,`isActive`,`protec_anti_doublet`) VALUES (998584,1367,0,1519,5390,1,3969,0,1367,-8745.62,530.662,96.7376,5.67618,300,0,0,84,0,0,0,0,0,0,0,0,NULL);

-- Adam 
DELETE FROM `creature` WHERE `guid` = '30856' ;
DELETE FROM `creature` WHERE `guid` = '998583' ;
INSERT  INTO `creature`(`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`npcflag2`,`unit_flags`,`unit_flags2`,`dynamicflags`,`isActive`,`protec_anti_doublet`) VALUES (998583,1366,0,1519,5390,1,3969,0,1366,-8744.6,532.018,96.7387,5.68402,300,0,0,84,0,0,0,0,0,0,0,0,NULL);


