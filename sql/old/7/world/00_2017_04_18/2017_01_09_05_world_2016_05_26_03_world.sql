-- Pathing for Clam Master K Entry: 25800 'TDB FORMAT' 
SET @NPC := 114803;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2342.325,`position_y`=5050.552,`position_z`=-21.01424 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2342.325,5050.552,-21.01424,0,0,0,0,100,0), -- 06:32:15
(@PATH,2,2338.003,5044.308,-22.64446,0,0,0,0,100,0), -- 06:32:22
(@PATH,3,2336.804,5029.821,-26.94789,0,0,0,0,100,0), -- 06:32:27
(@PATH,4,2341.884,5018.865,-30.1459,0,0,0,0,100,0), -- 06:32:33
(@PATH,5,2348.352,5002.221,-30.94783,0,0,0,0,100,0), -- 06:32:40
(@PATH,6,2349.925,4993.154,-32.16956,0,0,0,0,100,0), -- 06:32:45
(@PATH,7,2354.025,4983.295,-33.4639,0,0,0,0,100,0), -- 06:32:50
(@PATH,8,2357.896,4977.057,-33.84595,0,0,0,0,100,0), -- 06:32:53
(@PATH,9,2353.561,4983.914,-33.77616,0,0,0,0,100,0), -- 06:33:00
(@PATH,10,2349.806,4994.94,-31.05927,0,0,0,0,100,0), -- 06:33:04
(@PATH,11,2346.473,5009.516,-31.52969,0,0,0,0,100,0), -- 06:33:08
(@PATH,12,2338.316,5025.714,-28.18582,0,0,0,0,100,0), -- 06:33:13
(@PATH,13,2334.683,5038.239,-23.58451,0,0,0,0,100,0); -- 06:33:20
