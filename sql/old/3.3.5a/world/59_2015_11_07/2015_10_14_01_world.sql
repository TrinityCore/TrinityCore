-- Pathing for Lava Surger Entry: 12101 'TDB FORMAT' 
SET @NPC := 56666;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=679.1953,`position_y`=-847.3836,`position_z`=-208.2482 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,679.1953,-847.3836,-208.2482,0,0,1,0,100,0),
(@PATH,2,676.7046,-829.8509,-208.8353,0,0,1,0,100,0),
(@PATH,3,665.002,-813.2372,-208.774,0,0,1,0,100,0),
(@PATH,4,681.6021,-776.7833,-209.1657,0,0,1,0,100,0),
(@PATH,5,686.1985,-738.5436,-209.2948,0,0,1,0,100,0),
(@PATH,6,707.9111,-711.0708,-209.5187,0,0,1,0,100,0),
(@PATH,7,708.2624,-692.8405,-209.5718,0,0,1,0,100,0),
(@PATH,8,690.2739,-662.6287,-209.6574,0,0,1,0,100,0),
(@PATH,9,708.2625,-692.8368,-209.5175,0,0,1,0,100,0),
(@PATH,10,707.9111,-711.0708,-209.5187,0,0,1,0,100,0),
(@PATH,11,686.1985,-738.5436,-209.2948,0,0,1,0,100,0),
(@PATH,12,681.6021,-776.7833,-209.1657,0,0,1,0,100,0),
(@PATH,13,665.002,-813.2372,-208.774,0,0,1,0,100,0),
(@PATH,14,676.7046,-829.8509,-208.8353,0,0,1,0,100,0),
(@PATH,15,679.1953,-847.3836,-208.2482,0,0,1,0,100,0),
(@PATH,16,696.5482,-855.4606,-206.0954,0,0,1,0,100,0),
(@PATH,17,710.7119,-882.6242,-198.953,0,0,1,0,100,0),
(@PATH,18,714.8118,-907.6405,-193.7685,0,0,1,0,100,0),
(@PATH,19,735.3042,-937.3447,-188.4066,0,0,1,0,100,0),
(@PATH,20,714.8118,-907.6405,-193.7685,0,0,1,0,100,0),
(@PATH,21,710.7119,-882.6242,-198.953,0,0,1,0,100,0),
(@PATH,22,697.0541,-866.1818,-204.0854,0,0,1,0,100,0);

UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=696.6885,`position_y`=-852.352,`position_z`=-206.5962,`orientation`=3.674797 WHERE `guid`=56789;
DELETE FROM `creature_addon` WHERE `guid`=56789;
DELETE FROM `waypoint_data` WHERE `id`=567890;
