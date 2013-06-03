SET @GUID=152032; -- Need 8
DELETE FROM `creature` WHERE `id`=33429;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@GUID+0,33429,571,1,256,0,0,6253.47,2263.21,244.456,0.488692,120,0,0,1,0,0,0,0,0,0),
(@GUID+1,33429,571,1,256,0,0,6217.16,2252.59,496.038,0.488692,120,0,0,1,0,0,0,0,0,0),
(@GUID+2,33429,571,1,256,0,0,6234.1,2301.56,488.447,0.488692,120,0,0,1,0,0,0,0,0,0),
(@GUID+3,33429,571,1,256,0,0,6163.18,2231.77,506.981,0.488692,120,0,0,1,0,0,0,0,0,0),
(@GUID+4,33429,571,1,256,0,0,6172.18,2257.27,503.146,0.488692,120,0,0,1,0,0,0,0,0,0),
(@GUID+5,33429,571,1,256,0,0,6242.42,2246.47,491.941,0.56266,120,0,0,1,0,0,0,0,0,0),
(@GUID+6,33429,571,1,256,0,0,6202.35,2284.08,495.286,0.488692,120,0,0,1,0,0,0,0,0,0),
(@GUID+7,33429,571,1,256,0,0,6145.68,2208.17,512.426,0.488692,120,0,0,1,0,0,0,0,0,0);

-- Template updates for creature 33429 (Boneguard Lieutenant)
UPDATE `creature_template` SET `speed_run`=2 WHERE `entry`=33429; -- Boneguard Lieutenant
-- Model data 29098 (creature 33429 (Boneguard Lieutenant))
UPDATE `creature_model_info` SET `bounding_radius`=0.459,`combat_reach`=2.25,`gender`=0 WHERE `modelid`=29098; -- Boneguard Lieutenant
-- Addon data for creature 33429 (Boneguard Lieutenant)
DELETE FROM `creature_template_addon` WHERE `entry`=33429;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(33429,25678,0,1,0,NULL); -- Boneguard Lieutenant
