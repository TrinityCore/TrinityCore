-- Spawn from Sniff
DELETE FROM `creature` WHERE `id`=34526;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(42161,34526,1,1,1,0,0,-1050.052,-286.7274,159.1137,5.951573,120,0,0,1,0,0,0,0,0);
-- Template updates
UPDATE `creature_template` SET `faction_A`=104,`faction_H`=104,`baseattacktime`=2000,`npcflag`=`npcflag`|3,`unit_flags`=`unit_flags`|512 WHERE `entry`=34526; -- Aponi Brightmane
-- Model data
UPDATE `creature_model_info` SET `bounding_radius`=1.003375,`combat_reach`=4.3125,`gender`=1 WHERE `modelid`=29249; -- Aponi Brightmane
-- Addon data
DELETE FROM `creature_template_addon` WHERE `entry`=34526;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(34526,0,1,256,0,NULL); -- Aponi Brightmane
