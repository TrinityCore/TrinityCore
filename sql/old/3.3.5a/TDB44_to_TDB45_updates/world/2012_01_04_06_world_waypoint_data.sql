-- Pathing for King Dred Entry: 27483 "Drak'Tharon Keep"
SET @NPC := 127507;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-544.874,`position_y`=-696.9735,`position_z`=30.29507 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-529.7952,-711.4729,30.37141,0,1000,0,0,100,0),
(@PATH,2,-544.874,-696.9735,30.29507,0,0,0,0,100,0),
(@PATH,3,-550.9299,-694.043,30.49649,0,0,0,0,100,0),
(@PATH,4,-554.3631,-689.458,30.83389,0,0,0,0,100,0),
(@PATH,5,-554.6004,-681.4241,30.67007,0,0,0,0,100,0),
(@PATH,6,-550.1124,-674.5519,30.67007,0,0,0,0,100,0),
(@PATH,7,-540.9714,-671.0374,30.29507,0,0,0,0,100,0),
(@PATH,8,-535.8426,-664.3137,30.29507,0,1000,0,0,100,0),
(@PATH,9,-540.9714,-671.0374,30.29507,0,0,0,0,100,0),
(@PATH,10,-550.1124,-674.5519,30.67007,0,0,0,0,100,0),
(@PATH,11,-554.6004,-681.4241,30.67007,0,0,0,0,100,0),
(@PATH,12,-554.3631,-689.458,30.83389,0,0,0,0,100,0),
(@PATH,13,-550.9299,-694.043,30.49649,0,0,0,0,100,0),
(@PATH,14,-544.874,-696.9735,30.29507,0,0,0,0,100,0);
