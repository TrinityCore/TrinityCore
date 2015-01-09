/* 4.x removed
-- Pathing for Harrison Jones Entry: 24358
SET @NPC := 86177;
SET @PATH := @NPC * 10;
DELETE FROM `waypoint_data` WHERE `id`IN (@PATH,@PATH+1,@PATH+2);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,131.8243,1644.853,42.0216,0,0,0,100,0),
(@PATH+1,1,121.897,1639.106,42.19081,0,0,0,100,0),
(@PATH+1,2,120.8522,1637.931,42.37172,0,0,0,100,0),
(@PATH+1,3,120.7898,1609.063,43.49005,0,0,0,100,0),
(@PATH+2,1,120.6967,1603.713,43.4503,0,0,0,100,0);
*/
