-- Spawns from sniff
SET @GUID := 40279; -- set value 
DELETE FROM `creature` WHERE `id`=27791;
INSERT IGNORE INTO creature 
 (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`MovementType`)
 VALUES 
(@GUID+0,27791,571,1,1,0,0,3653.64233,-1204.21200,102.420319,4.04458666,120, 0, 0),
(@GUID+1,27791,571,1,1,0,0,3673.77515,-1213.68188,102.420319,4.08126450,120, 0, 0),
(@GUID+2,27791,571,1,1,0,0,3674.53735,-1175.28369,102.420288,1.78801400,120, 0, 0),
(@GUID+3,27791,571,1,1,0,0,3684.37158,-1180.27942,102.420288,1.22173047,120, 0, 0);

