DELETE FROM `creature` WHERE `guid` IN (101984,102039,101966,101942,101943,101913,101790,88308);
DELETE FROM `creature` WHERE `guid` BETWEEN 102022 AND 102032;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(101984,29504,571,1,1,7168.308,-3616.868,830.689,3.692736,300,5,1), -- Seething Revenant
(102022,29504,571,1,1,7185.381,-3632.053,824.247,4.338225,300,5,1), -- Seething Revenant
(102023,29504,571,1,1,7191.07,-3520.252,826.8859,4.542768,300,5,1), -- Seething Revenant
(102024,29504,571,1,1,7217.771,-3425.522,838.6382,5.01096,300,5,1), -- Seething Revenant
(102025,29504,571,1,1,7221.059,-3668.075,823.829,5.133259,300,5,1), -- Seething Revenant
(102026,29504,571,1,1,7223.214,-3625.205,823.4471,3.3342,300,5,1), -- Seething Revenant
(102027,29504,571,1,1,7245.613,-3324.135,852.1368,0.2004583,300,5,1), -- Seething Revenant
(102028,29504,571,1,1,7247.223,-3147.932,837.5768,3.113845,300,5,1), -- Seething Revenant
(102029,29504,571,1,1,7250.414,-3082.812,837.5768,5.273692,300,5,1), -- Seething Revenant
(102030,29504,571,1,1,7257.364,-3650.48,823.7267,5.320714,300,5,1), -- Seething Revenant
(102031,29504,571,1,1,7318.657,-3108.576,837.5768,0.7864776,300,5,1), -- Seething Revenant
(102032,29504,571,1,1,7319.729,-3256.892,843.9413,4.579113,300,5,1), -- Seething Revenant
(102039,29504,571,1,1,7322.325,-3181.755,837.5279,3.279677,300,5,1), -- Seething Revenant
(101966,29504,571,1,1,7384.565,-3117.917,837.5417,1.487818,300,5,1), -- Seething Revenant
(101942,29504,571,1,1,7407.328,-3276.822,858.1526,3.880721,300,5,1), -- Seething Revenant
(101943,29504,571,1,1,7454.707,-3204.902,837.5764,4.937684,300,5,1), -- Seething Revenant
(101913,29504,571,1,1,7457.445,-3072.987,837.5768,1.176061,300,5,1), -- Seething Revenant
(101790,29504,571,1,1,7483.619,-3148.763,837.5848,3.356413,300,5,1), -- Seething Revenant
(88308,29503,571,1,1,7217.113,-3659.162,823.2127,2.024582,120,0,0); -- Fjorn

-- Pathing for Seething Revenant Entry: 29504
SET @NPC := 102023;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7185.569,`position_y`=-3578.212,`position_z`=826.3776 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7185.569,-3578.212,826.3776,0,0,0,0,100,0),
(@PATH,2,7184.791,-3556.857,827.6204,0,0,0,0,100,0),
(@PATH,3,7191.07,-3520.252,826.8859,0,0,0,0,100,0),
(@PATH,4,7203.232,-3480.131,833.8677,0,0,0,0,100,0),
(@PATH,5,7191.07,-3520.252,826.8859,0,0,0,0,100,0),
(@PATH,6,7184.791,-3556.857,827.6204,0,0,0,0,100,0);

-- Pathing for Seething Revenant Entry: 29504
SET @NPC := 102024;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7212.51,`position_y`=-3459.921,`position_z`=835.768 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7212.51,-3459.921,835.768,0,0,0,0,100,0),
(@PATH,2,7219.868,-3432.39,837.9383,0,0,0,0,100,0),
(@PATH,3,7213.401,-3411.379,840.3849,0,0,0,0,100,0),
(@PATH,4,7206.807,-3388.99,843.8749,0,0,0,0,100,0),
(@PATH,5,7213.369,-3411.22,840.351,0,0,0,0,100,0),
(@PATH,6,7219.868,-3432.39,837.9383,0,0,0,0,100,0);
