-- Pathing for Mennu the Betrayer Entry: 17941
SET @NPC := 79362;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=89.26869,`position_y`=-380.2368,`position_z`=15.0899 WHERE `guid`=@NPC;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,89.26869,-380.2368,15.0899,0,0,0,0,100,0),
(@PATH,2,121.6363,-380.3765,29.95734,0,1000,0,0,100,0),
(@PATH,3,89.42728,-380.2369,15.12144,0,0,0,0,100,0),
(@PATH,4,49.4763,-380.2191,3.035575,0,0,0,0,100,0);

-- Pathing for Rokmar the Crackler Entry: 17991
SET @NPC := 79339;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-34.37422,`position_y`=-458.817,`position_z`=-1.952406 WHERE `guid`=@NPC;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-34.37422,-458.817,-1.952406,0,1000,0,0,100,0),
(@PATH,2,-62.09498,-454.9725,-1.592298,0,0,0,0,100,0),
(@PATH,3,-13.55803,-454.8065,2.49773,0,0,0,0,100,0),
(@PATH,4,18.32117,-448.4476,3.055895,0,0,0,0,100,0),
(@PATH,5,-13.55803,-454.8065,2.49773,0,0,0,0,100,0),
(@PATH,6,-62.09498,-454.9725,-1.592298,0,0,0,0,100,0);
