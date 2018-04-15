-- Wrathbone Siegesmith pathing
SET @NPC := 202159;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=646.5851,`position_y`=-191.1892,`position_z`=526.8476 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES (@NPC,@PATH,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,646.5851,-191.1892,526.8476,0,0,0,100,0),
(@PATH,2,648.8837,-181.967,526.7226,0,0,0,100,0),
(@PATH,3,649.4167,-179.4531,526.7226,14000,0,0,100,0),
(@PATH,4,652.1736,-183.3594,526.7226,0,0,0,100,0),
(@PATH,5,648.5643,-188.309,526.8476,0,0,0,100,0),
(@PATH,6,642.5313,-193.4826,527.3874,0,0,0,100,0),
(@PATH,7,633.688,-200.741,528.941,12000,0,0,100,0),
(@PATH,8,641.9254,-196.5747,528.9726,0,0,0,100,0);

-- Wrathbone Siegesmith pathing
SET @NPC := 201855;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=723.5469,`position_y`=-170.9497,`position_z`=527.5121 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES (@NPC,@PATH,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,723.5469,-170.9497,527.5121,13000,0,0,100,0),
(@PATH,2,726.6484,-173.3438,527.1627,0,0,0,100,0),
(@PATH,3,726.6484,-174.3438,527.1627,0,0,0,100,0),
(@PATH,4,725.25,-175.2379,526.8134,0,0,0,100,0),
(@PATH,5,722.0521,-181.5122,526.8134,0,0,0,100,0),
(@PATH,6,721.2031,-187.8142,526.8134,0,0,0,100,0),
(@PATH,7,717.7917,-194.4358,526.8134,0,0,0,100,0),
(@PATH,8,719.3073,-202.2691,527.1509,0,0,0,100,0),
(@PATH,9,720.3403,-206.1198,527.7932,12000,0,0,100,0),
(@PATH,10,717.6111,-199.5035,526.9384,0,0,0,100,0),
(@PATH,11,717.566,-189.0642,526.8134,0,0,0,100,0),
(@PATH,12,718.5764,-182.3958,526.8134,0,0,0,100,0),
(@PATH,13,719.9531,-176.0729,526.8134,0,0,0,100,0);

-- Forgemaster Garfrost pathing
SET @NPC := 201992;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=712.1371,`position_y`=-215.7014,`position_z`=527.066 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`auras`) VALUES (@NPC,@PATH,1,'68792');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,712.1371,-215.7014,527.066,0,0,0,100,0),
(@PATH,2,719.507,-227.8559,527.066,3000,0,0,100,0),
(@PATH,3,712.1371,-215.7014,527.066,0,0,0,100,0),
(@PATH,4,685.1805,-207.349,526.8424,0,0,0,100,0),
(@PATH,5,664.5191,-203.3472,526.816,0,0,0,100,0),
(@PATH,6,645.033,-208.5295,528.941,0,0,0,100,0),
(@PATH,7,653.0729,-194.3681,526.7226,0,0,0,100,0),
(@PATH,8,664.8646,-195.2135,526.7226,0,0,0,100,0),
(@PATH,9,686.0816,-213.8264,526.8424,0,0,0,100,0),
(@PATH,10,697.9757,-221.6215,526.8424,0,0,0,100,0),
(@PATH,11,708.0903,-211.908,527.066,0,0,0,100,0),
(@PATH,12,717.8924,-204.6979,527.191,0,0,0,100,0),
(@PATH,13,699.0504,-201.3438,526.8424,0,0,0,100,0),
(@PATH,14,672.066,-201.1493,526.8424,0,0,0,100,0),
(@PATH,15,655.9496,-203.4931,526.816,0,0,0,100,0),
(@PATH,16,672.066,-201.1493,526.8424,0,0,0,100,0),
(@PATH,17,699.0504,-201.3438,526.8424,0,0,0,100,0),
(@PATH,18,717.8924,-204.6979,527.191,0,0,0,100,0),
(@PATH,19,708.0903,-211.908,527.066,0,0,0,100,0),
(@PATH,20,697.9757,-221.6215,526.8424,0,0,0,100,0),
(@PATH,21,686.0816,-213.8264,526.8424,0,0,0,100,0),
(@PATH,22,664.8646,-195.2135,526.7226,0,0,0,100,0),
(@PATH,23,653.0729,-194.3681,526.7226,0,0,0,100,0),
(@PATH,24,645.033,-208.5295,528.941,0,0,0,100,0),
(@PATH,25,664.5191,-203.3472,526.816,0,0,0,100,0),
(@PATH,26,685.1805,-207.349,526.8424,0,0,0,100,0);
