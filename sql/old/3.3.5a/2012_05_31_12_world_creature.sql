-- Add missing 7th Legion Chain Gun spawns
DELETE FROM `creature` WHERE `guid` IN (42569,42570,42663,42664);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(42569,27714,571,1,1,25331,0,3665.613,-1209.412,102.4201,4.206244,120,0,0,1,0,0),
(42570,27714,571,1,1,25331,0,3660.56,-1207.094,102.4201,4.29351,120,0,0,1,0,0),
(42663,27714,571,1,1,25331,0,3677.009,-1174.462,102.3367,1.169371,120,0,0,1,0,0),
(42664,27714,571,1,1,25331,0,3682.874,-1177.179,102.4757,1.169371,120,0,0,1,0,0);
-- Add Spells for 7th Legion Chain Gun
UPDATE `creature_template` SET `spell1`=49190,`spell2`=49550 WHERE `entry`=27714;
