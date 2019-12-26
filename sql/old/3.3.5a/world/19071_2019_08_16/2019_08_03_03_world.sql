-- 
UPDATE `creature` SET `MovementType`=1, `spawndist`=4 WHERE `guid` IN (79432,79444,79434,79452);
DELETE FROM `creature` WHERE `id`=20865 AND `guid`=79457;
DELETE FROM `linked_respawn` WHERE `guid`=79457 AND `linkedGuid`=79391;
UPDATE `creature` SET `position_x`=226.532,`position_y`=-4.33270,`position_z`=-8.59788 WHERE `guid`=79427;
UPDATE `creature` SET `position_x`=212.760,`position_y`=9.860930,`position_z`=-7.46838 WHERE `guid`=79444;
UPDATE `creature` SET `position_x`=222.822,`position_y`=-3.72311,`position_z`=-8.45253 WHERE `guid`=79445;
UPDATE `creature` SET `position_x`=225.714,`position_y`=-2.11525,`position_z`=-8.35414 WHERE `guid`=79454;
UPDATE `creature` SET `position_x`=224.367,`position_y`=-4.21835,`position_z`=-8.59119 WHERE `guid`=79456;
UPDATE `creature` SET `position_x`=223.656,`position_y`=-6.03500,`position_z`=-8.77307 WHERE `guid`=79458;

UPDATE `creature` SET `MovementType`=2 WHERE `guid` = 79456;
DELETE FROM `creature_formations` WHERE `leaderGUID` IN (79456);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(79456,79456,0,0,515,0,0),
(79456,79427,3,45,515,0,0),
(79456,79458,3,315,515,0,0),
(79456,79454,3,135,515,0,0),
(79456,79445,3,225,515,0,0);

DELETE FROM `creature_addon` WHERE `guid`=79456;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`, `auras`) VALUES (79456,7945600,1,"");

DELETE FROM `waypoint_data` WHERE `id`=7945600;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(7945600,1,224.36700, -4.21835, -8.59119, 5.285530,0,0,0,100,0),
(7945600,2,223.29058, -14.2510, -9.68364, 4.328913,0,0,0,100,0),
(7945600,3,208.86810, -18.7447, -10.0892, 2.412540,0,0,0,100,0),
(7945600,4,197.82304, -9.46247, -10.1020, 2.326146,0,0,0,100,0),
(7945600,5,190.99885, -0.62968, -10.1037, 2.098381,0,0,0,100,0),
(7945600,6,184.06471, 11.78935, -10.0824, 2.074819,0,0,0,100,0),
(7945600,7,186.71444, 20.19647, -9.72026, 0.735715,0,0,0,100,0),
(7945600,8,196.03006, 22.31151, -8.67650, 0.170228,0,0,0,100,0),
(7945600,9,205.37554, 18.44509, -7.66362, 5.844729,0,0,0,100,0),
(7945600,10,216.87519, 11.19125, -7.46836, 5.620897,0,0,0,100,0);
