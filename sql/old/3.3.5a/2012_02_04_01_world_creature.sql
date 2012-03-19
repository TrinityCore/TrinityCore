-- Spawn Petrov
SET @GUID :=40268;
DELETE FROM `creature` WHERE `id`=26932;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`)  VALUES
(@GUID,26932,571,1,1,0,0,4698.392,-4004.781,212.3551,0.5061455,300,0,0,1,0,0,0,0,0);

-- Template updates for creature 26932 (Petrov)
UPDATE `creature_template` SET `baseattacktime`=1500,`unit_flags`=`unit_flags`|512 WHERE `entry`=26932; -- Petrov
-- Addon data for creature 26932 (Petrov)
DELETE FROM `creature_template_addon` WHERE `entry`=26932;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(26932,0,0,257,333, NULL); -- Petrov
