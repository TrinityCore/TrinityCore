DELETE FROM `creature` WHERE `guid`=113330;

-- Pathing for Deathguard Molder Entry: 27320 'TDB FORMAT' 
SET @NPC := 113329;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3242.083,`position_y`=-683.1053,`position_z`=166.9898 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1 ,3234.214,-662.9944,166.701,0,60000,0,0,100,0),
(@PATH,2 ,3242.083,-683.1053,166.9898,0,0,0,0,100,0),
(@PATH,3 ,3244.742,-697.8635,167.0145,0,0,0,0,100,0),
(@PATH,4 ,3248.017,-702.5844,167.3793,0,0,0,0,100,0),
(@PATH,5 ,3252.101,-710.5942,167.6412,0,0,0,0,100,0),
(@PATH,6 ,3257.548,-721.5476,168.0425,0,0,0,0,100,0),
(@PATH,7 ,3260.511,-729.2581,168.5909,0,60000,0,0,100,0),
(@PATH,8 ,3257.548,-721.5476,168.0425,0,0,0,0,100,0),
(@PATH,9 ,3252.101,-710.5942,167.6412,0,0,0,0,100,0),
(@PATH,10,3248.017,-702.5844,167.3793,0,0,0,0,100,0),
(@PATH,11,3245.563,-698.4318,167.1446,0,0,0,0,100,0);
