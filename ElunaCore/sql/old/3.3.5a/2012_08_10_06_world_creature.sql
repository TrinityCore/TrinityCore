SET @CGUID:=42571; -- Need 2
DELETE FROM `creature` WHERE `id` IN (30395,30469);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@CGUID+0,30395,571,1,1,0,0,8348.886,-2509.476,1147.369,3.700098,120,0,0,12600,0,0,0,0,0),
(@CGUID+1,30469,571,1,1,0,0,7620.369,-1609.421,969.6507,0.767944,120,0,0,12600,0,0,0,0,0);

-- Template updates
UPDATE `creature_template` SET `npcflag`=`npcflag`|3 WHERE `entry`=30395; -- Chieftain Swiftspear
UPDATE `creature_template` SET `faction_A`=1978,`faction_H`=1978 WHERE `entry`=30469; -- Tracker Val'zij
-- Model data
UPDATE `creature_model_info` SET `bounding_radius`=0.6076385,`combat_reach`=2.625,`gender`=0 WHERE `modelid`=27004; -- Chieftain Swiftspear
-- Addon data
DELETE FROM `creature_template_addon` WHERE `entry`IN (30395,30469);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(30395,0,0,1,0, NULL), -- Chieftain Swiftspear
(30469,0,8,1,0, NULL); -- Tracker Val'zij
