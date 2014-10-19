DELETE FROM `spell_target_position` WHERE `id`=56649;
INSERT INTO `spell_target_position` (`id`,`effIndex`,`target_map`,`target_position_x`,`target_position_y`,`target_position_z`,`target_orientation`) VALUES
(56649,0,571,7989.938,-3195.042,922.6224,3.572167);

DELETE FROM `spell_script_names` WHERE `spell_id`=50630;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(50630, 'spell_jokkum_eject_all');

DELETE FROM `spell_script_names` WHERE `spell_id`=56650;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(56650, 'spell_veranus_summon');

-- Pathing for King Jokkum Entry: 30331
-- by malcrom
SET @PATH := 2072200;
DELETE FROM `waypoint_data` WHERE `id` IN (@PATH, @PATH+1);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
-- Path to event
(@PATH,1,7357.088,-2865.398,803.5008,0,0,1,0,100,0),
(@PATH,2,7355.184,-2904.322,821.0084,0,0,1,0,100,0),
(@PATH,3,7355.473,-2946.654,833.0916,0,0,1,0,100,0),
(@PATH,4,7358.789,-2974.211,845.01801,0,0,1,0,100,0),
(@PATH,5,7360.866,-2994.785,845.9886,0,0,1,0,100,0),
(@PATH,6,7378.764,-3035.887,840.6003,0,0,1,0,100,0),
(@PATH,7,7411.658,-3072.211,837.5768,0,0,1,0,100,0),
(@PATH,8,7453.996,-3088.695,837.5768,0,0,1,0,100,0),
(@PATH,9,7496.08,-3113.922,837.5829,0,0,1,0,100,0),
(@PATH,10,7536.843,-3136.489,837.5808,0,0,1,0,100,0),
(@PATH,11,7564.738,-3145.144,844.8308,0,0,1,0,100,0),
(@PATH,12,7604.358,-3171.258,850.8867,0,0,1,0,100,0),
(@PATH,13,7635.467,-3207.211,857.19,0,0,1,0,100,0),
(@PATH,14,7657.858,-3219.258,863.19,0,0,1,0,100,0),
(@PATH,15,7685.416,-3218.983,867.14136,0,0,1,0,100,0),
(@PATH,16,7706.542,-3219.742,864.3326,0,0,1,0,100,0),
(@PATH,17,7747.335,-3226.993,862.4576,0,0,1,0,100,0),
(@PATH,18,7796.658,-3221.782,860.6461,0,0,1,0,100,0),
(@PATH,19,7827.596,-3229.273,856.4147,0,0,1,0,100,0),
(@PATH,20,7846.174,-3253.239,852.1281,0,0,1,0,100,0),
-- Path after event and despawn
(@PATH+1,1,7837.094,-3235.536,853.8781,0,0,1,0,100,0),
(@PATH+1,2,7828.622,-3230.38,855.9147,0,0,1,0,100,0),
(@PATH+1,3,7793.782,-3219.743,861.1461,0,0,1,0,100,0),
(@PATH+1,4,7765.224,-3225.374,864.0826,0,0,1,0,100,0),
(@PATH+1,5,7736.733,-3226.5,861.4576,0,0,1,0,100,0);
