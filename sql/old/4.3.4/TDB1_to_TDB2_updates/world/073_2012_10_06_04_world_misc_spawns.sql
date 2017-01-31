SET @GUID = 75;  -- Requires one   (creature) - 4.x
SET @GUID2 = 76; -- 4.x
SET @OGUID = 4; -- Requires three (gameobject) - 4.x

DELETE FROM `gameobject` WHERE `id`=203624;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@OGUID,203624,724,15,0x20,3157.372,533.9948,72.8887,1.034892,0,0,0.4946623,0.8690853,120,0,0);

DELETE FROM `creature` WHERE `id` IN (40081,40091); -- ,40151);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@GUID,40091,724,1,0x20,0,0,3113.711,533.5382,72.96869,1.936719,300,0,0,1,0,0,0,0,0),
(@GUID2,40081,724,1,0x20,0,0,3153.75,533.1875,72.97205,0,300,0,0,1,0,0,0,0,0);

SET @PATH = @GUID * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@GUID;
DELETE FROM `creature_addon` WHERE `guid`=@GUID;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@GUID,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3117.59,547.7952,72.96869,0,0,0,0,100,0),
(@PATH,2,3127.461,558.7396,72.96869,0,0,0,0,100,0),
(@PATH,3,3138.042,567.9514,72.98305,0,0,0,0,100,0),
(@PATH,4,3154.09,574.9636,72.98305,0,0,0,0,100,0),
(@PATH,5,3172.565,567.493,72.86058,0,0,0,0,100,0),
(@PATH,6,3181.981,555.8889,72.9127,0,0,0,0,100,0),
(@PATH,7,3189.923,533.3542,73.0377,0,0,0,0,100,0),
(@PATH,8,3182.315,513.4202,72.9771,0,0,0,0,100,0),
(@PATH,9,3177.168,504.3802,72.7271,0,0,0,0,100,0),
(@PATH,10,3167.878,496.8368,72.50312,0,0,0,0,100,0),
(@PATH,11,3152.238,490.4705,72.62009,0,0,0,0,100,0),
(@PATH,12,3138.174,499.3056,72.87009,0,0,0,0,100,0),
(@PATH,13,3126.83,506.0799,72.95515,0,0,0,0,100,0),
(@PATH,14,3120.68,515.3524,72.95515,0,0,0,0,100,0),
(@PATH,15,3113.711,533.5382,72.96869,0,0,0,0,100,0);

