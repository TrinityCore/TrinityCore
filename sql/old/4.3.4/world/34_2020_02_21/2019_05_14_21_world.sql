-- Pathing for Gnash Entry: 40987 'TDB FORMAT' 
SET @NPC := 341994;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4891.04,`position_y`=3571.267,`position_z`=-118.1813 WHERE `guid`=@NPC;
UPDATE `creature_template_addon` SET `path_id`= @PATH WHERE `entry`=40987;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4891.04,3571.267,-118.1813,0,0,0,0,100,0),
(@PATH,2,-4932.109,3558.501,-120.6123,0,0,0,0,100,0),
(@PATH,3,-4969.269,3534.143,-124.5373,0,0,0,0,100,0),
(@PATH,4,-5002.54,3506.452,-124.0336,0,0,0,0,100,0),
(@PATH,5,-5038.851,3498.985,-126.658,0,0,0,0,100,0),
(@PATH,6,-5002.54,3506.452,-124.0336,0,0,0,0,100,0),
(@PATH,7,-4969.269,3534.143,-124.5373,0,0,0,0,100,0),
(@PATH,8,-4932.134,3558.48,-120.6112,0,0,0,0,100,0),
(@PATH,9,-4891.04,3571.267,-118.1813,0,0,0,0,100,0),
(@PATH,10,-4856.814,3589.009,-117.9192,0,0,0,0,100,0),
(@PATH,11,-4834.09,3615.715,-120.1451,0,0,0,0,100,0),
(@PATH,12,-4816.771,3628.427,-120.8001,0,0,0,0,100,0),
(@PATH,13,-4834.09,3615.715,-120.1451,0,0,0,0,100,0),
(@PATH,14,-4856.814,3589.009,-117.9192,0,0,0,0,100,0);
