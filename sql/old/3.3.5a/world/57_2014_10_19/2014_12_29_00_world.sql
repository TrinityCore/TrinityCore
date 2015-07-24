-- Pathing for Bleeding Hollow Dark Shaman Entry: 16873 'TDB FORMAT'
SET @NPC := 29978;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-945.313,`position_y`=1948.252,`position_z`=67.06455 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-945.313,1948.252,67.06455,0,0,0,0,100,0),
(@PATH,2,-946.7964,1966.628,67.06455,0,0,0,0,100,0),
(@PATH,3,-932.1639,1983.549,66.96194,0,0,0,0,100,0),
(@PATH,4,-914.9733,1976.555,67.05032,0,0,0,0,100,0),
(@PATH,5,-929.8001,1991.014,66.44107,0,0,0,0,100,0),
(@PATH,6,-929.8001,1991.014,66.44107,0,0,0,0,100,0),
(@PATH,7,-941.426,2015.632,66.31691,0,0,0,0,100,0),
(@PATH,8,-965.7396,2015.727,67.03322,0,0,0,0,100,0),
(@PATH,9,-968.4443,2047.705,67.06454,0,0,0,0,100,0),
(@PATH,10,-965.7396,2015.727,67.03322,0,0,0,0,100,0),
(@PATH,11,-965.7396,2015.727,67.03322,0,0,0,0,100,0),
(@PATH,12,-941.426,2015.632,66.31691,0,0,0,0,100,0),
(@PATH,13,-929.8001,1991.014,66.44107,0,0,0,0,100,0),
(@PATH,14,-914.9733,1976.555,67.05032,0,0,0,0,100,0),
(@PATH,15,-914.9733,1976.555,67.05032,0,0,0,0,100,0),
(@PATH,16,-932.1639,1983.549,66.96194,0,0,0,0,100,0),
(@PATH,17,-946.7964,1966.628,67.06455,0,0,0,0,100,0);
-- 0xF13041E90061F326 .go -945.313 1948.252 67.06455
