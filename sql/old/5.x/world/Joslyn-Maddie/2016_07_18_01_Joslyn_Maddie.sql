-- respawn 3 npc's in stormwind, they should be standing still.
-- Archmage Gaiman
DELETE FROM `creature`  WHERE `guid` = '30872' ;
DELETE FROM `creature`  WHERE `guid` = '998598' ;
INSERT  INTO `creature`(`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`npcflag2`,`unit_flags`,`unit_flags2`,`dynamicflags`,`isActive`,`protec_anti_doublet`) VALUES (998598,12779,0,1519,1519,1,3969,0,12779,-8784.23,426.198,105.275,5.82145,300,0,0,7320,10026,0,0,0,0,0,0,0,NULL);

-- Harbringer Ennarth
DELETE FROM `creature`  WHERE `guid` = '30873' ;
DELETE FROM `creature`  WHERE `guid` = '998597' ;
INSERT  INTO `creature`(`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`npcflag2`,`unit_flags`,`unit_flags2`,`dynamicflags`,`isActive`,`protec_anti_doublet`) VALUES (998597,19848,0,1519,1519,1,3969,0,19848,-8781.62,428.234,105.275,5.14209,300,0,0,13522,0,0,0,0,0,0,0,0,NULL);

-- Sergeant Major Skyshadow
DELETE FROM `creature`  WHERE `guid` = '30875' ;
DELETE FROM `creature`  WHERE `guid` = '998596' ;
INSERT  INTO `creature`(`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`npcflag2`,`unit_flags`,`unit_flags2`,`dynamicflags`,`isActive`,`protec_anti_doublet`) VALUES (998596,12780,0,1519,1519,1,3969,0,12780,-8779.07,427.631,105.276,3.78728,300,0,0,10456,0,0,0,0,0,0,0,0,NULL);
