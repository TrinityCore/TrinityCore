DELETE FROM `creature_formations` WHERE `leaderGUID`=101017;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`) VALUES
(101017, 101017, 0, 0, 1),
(101017, 101016, 2, 45, 2);

-- Pathing for Sunreaver Hawkrider Entry: 30265 'TDB FORMAT' 
SET @NPC := 101017;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=5586.633,`position_y`=-658.4381,`position_z`=204.5775 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,28889,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,5586.633,-658.4381,204.5775,0,0,0,0,100,0),
(@PATH,2,5585.409,-655.815,203.7495,0,0,0,0,100,0),
(@PATH,3,5584.759,-647.1207,202.7112,0,0,0,0,100,0),
(@PATH,4,5589.797,-633.0928,200.7699,0,0,0,0,100,0),
(@PATH,5,5598.13,-621.1475,198.2848,0,0,0,0,100,0),
(@PATH,6,5592.634,-628.2191,199.8846,0,0,0,0,100,0),
(@PATH,7,5585.994,-641.5278,201.9498,0,0,0,0,100,0),
(@PATH,8,5584.441,-650.3018,203.0215,0,0,0,0,100,0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=100987;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`) VALUES
(100987, 100987, 0, 0, 1),
(100987, 100986, 2, 45, 2);

-- Pathing for Sunreaver Hawkrider Entry: 30265 'TDB FORMAT' 
SET @NPC := 100987;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=5615.299,`position_y`=-711.0152,`position_z`=206.286 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,28889,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,5615.299,-711.0152,206.286,0,0,0,0,100,0),
(@PATH,2,5608.708,-695.2381,206.6548,0,0,0,0,100,0),
(@PATH,3,5598.26,-684.2681,206.6482,0,0,0,0,100,0),
(@PATH,4,5595.715,-675.8694,206.6474,0,0,0,0,100,0),
(@PATH,5,5589.645,-664.4355,205.7086,0,0,0,0,100,0),
(@PATH,6,5593.898,-670.5458,206.5087,0,0,0,0,100,0),
(@PATH,7,5596.294,-679.0742,206.6474,0,0,0,0,100,0),
(@PATH,8,5606.79,-693.2242,206.6536,0,0,0,0,100,0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=100984;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`) VALUES
(100984, 100984, 0, 0, 1),
(100984, 100985, 2, 45, 2);

-- Pathing for Sunreaver Hawkrider Entry: 30265 'TDB FORMAT' 
SET @NPC := 100984;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=5603.461,`position_y`=-753.2111,`position_z`=198.3089 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,28889,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,5603.461,-753.2111,198.3089,0,0,0,0,100,0),
(@PATH,2,5609.75,-744.6108,201.4747,0,0,0,0,100,0),
(@PATH,3,5614.047,-736.9058,203.5394,0,0,0,0,100,0),
(@PATH,4,5617.86,-725.5508,204.9431,0,0,0,0,100,0),
(@PATH,5,5618.354,-717.699,205.5509,0,0,0,0,100,0),
(@PATH,6,5618.291,-721.7224,205.229,0,0,0,0,100,0),
(@PATH,7,5616.521,-730.5341,204.4404,0,0,0,0,100,0),
(@PATH,8,5613.125,-738.7379,203.1023,0,0,0,0,100,0);
