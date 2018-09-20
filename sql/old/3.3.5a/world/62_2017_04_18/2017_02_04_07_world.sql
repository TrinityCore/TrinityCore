-- [NPC][WotlK] Valkyrion Aspirant, missing spawn locs, paths
UPDATE `creature` SET `position_x`=7349.222, `position_y`=258.4479, `position_z`=771.36, `orientation`=5.759586 WHERE  `guid`=107729;
UPDATE `creature` SET `position_x`=7356.891, `position_y`=269.7743, `position_z`=771.2924, `orientation`=5.323254 WHERE  `guid`=107728;
UPDATE `creature` SET `position_x`=7320.799, `position_y`=199.4411, `position_z`=785.1559, `orientation`=0.418879 WHERE  `guid`=107703;
UPDATE `creature` SET `orientation`=0.176970 WHERE  `guid`=107723;
-- add spawn

SET @CGUID := 77807;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+7;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 29569, 571, 0, 0, 1, 1, 0, 1, 7394.997, 178.5903, 770.3085, 0.05235988, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Valkyrion Aspirant (Area: The Blighted Pool)
(@CGUID+1, 29569, 571, 0, 0, 1, 1, 0, 1, 7369.332, 98.02432, 767.8315, 5.837039, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Valkyrion Aspirant (Area: Valkyrion) (possible waypoints or random movement)
(@CGUID+2, 29569, 571, 0, 0, 1, 1, 0, 1, 7293.031, 29.01389, 769.5436, 4.625123, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Valkyrion Aspirant (Area: Valkyrion)
(@CGUID+3, 29569, 571, 0, 0, 1, 1, 0, 1, 7275.657, 24.95085, 769.1705, 4.956735, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Valkyrion Aspirant (Area: Valkyrion)
(@CGUID+4, 29569, 571, 0, 0, 1, 1, 0, 1, 7228.057, -29.3620, 771.0686, 0.328551, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Valkyrion Aspirant (Area: Valkyrion)
(@CGUID+5, 29569, 571, 0, 0, 1, 1, 0, 1, 7349.81, 145.301, 785.312, 0.532759, 300, 0, 0, 12600, 0, 0, 0, 0, 0, 0), -- Valkyrion Aspirant (Area: Valkyrion)
(@CGUID+6, 29569, 571, 0, 0, 1, 1, 0, 1, 7312.06, -40.6448, 766.585, 3.90447, 300, 0, 0, 12175, 0, 0, 0, 0, 0, 0), -- Valkyrion Aspirant (Area: Valkyrion)
(@CGUID+7, 29569, 571, 0, 0, 1, 1, 0, 1, 7402.24, 157.071, 769.469, 0.0599489, 300, 0, 0, 12175, 0, 0, 0, 0, 0, 0); -- Valkyrion Aspirant (Area: Valkyrion)

-- Pathing for  Entry: Entry: 'TDB FORMAT' 
SET @NPC := 107731;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7313.312,`position_y`=182.9937,`position_z`=793.3484 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7313.312,182.9937,793.3484,0,0,0,0,100,0),
(@PATH,2,7327.345,189.4492,786.9259,0,0,0,0,100,0),
(@PATH,3,7333.345,192.6992,784.6759,0,0,0,0,100,0),
(@PATH,4,7341.923,193.2855,781.8031,0,0,0,0,100,0),
(@PATH,5,7349.423,194.2855,779.5531,0,0,0,0,100,0),
(@PATH,6,7356.473,192.0818,778.0201,0,0,0,0,100,0),
(@PATH,7,7363.973,185.5818,775.5201,0,0,0,0,100,0),
(@PATH,8,7371.223,182.0818,774.0201,0,0,0,0,100,0),
(@PATH,9,7381.889,163.8808,772.7557,0,0,0,0,100,0),
(@PATH,10,7382.389,154.8808,772.2557,0,0,0,0,100,0),
(@PATH,11,7382.889,141.1308,770.5057,0,0,0,0,100,0),
(@PATH,12,7382.566,156.2249,772.4506,0,0,0,0,100,0),
(@PATH,13,7382.041,164.2115,773.0219,0,0,0,0,100,0),
(@PATH,14,7375.041,175.9615,773.2719,0,0,0,0,100,0),
(@PATH,15,7371.606,181.718,773.9771,0,0,0,0,100,0),
(@PATH,16,7359.318,192.3345,777.894,0,0,0,0,100,0),
(@PATH,17,7347.818,192.3345,780.394,0,0,0,0,100,0),
(@PATH,18,7339.818,193.3345,782.394,0,0,0,0,100,0),
(@PATH,19,7327.01,189.2397,787.2646,0,0,0,0,100,0),
(@PATH,20,7317.26,184.7397,792.7646,0,0,0,0,100,0),
(@PATH,21,7315.51,183.9897,793.5146,0,0,0,0,100,0),
(@PATH,22,7313.611,182.9695,793.5685,0,0,0,0,100,0),
(@PATH,23,7301.111,176.4695,790.8185,0,0,0,0,100,0),
(@PATH,24,7291.841,171.5271,788.9741,0,0,0,0,100,0),
(@PATH,25,7287.841,169.2771,786.9741,0,0,0,0,100,0),
(@PATH,26,7285.341,168.2771,784.9741,0,0,0,0,100,0);
-- 0x203CD047601CE040000C1D000009F1E9 .go 7313.312 182.9937 793.3484

-- Pathing for  Entry: Entry: 'TDB FORMAT' 
SET @NPC := 107734;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7375.525,`position_y`=95.07399,`position_z`=768.0959 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7375.525,95.07399,768.0959,0,0,0,0,100,0),
(@PATH,2,7381.578,87.97273,767.9186,0,0,0,0,100,0),
(@PATH,3,7381.276,78.87275,768.0051,0,0,0,0,100,0),
(@PATH,4,7376.579,69.93269,768.2582,0,0,0,0,100,0),
(@PATH,5,7366.995,66.48799,768.2737,0,0,0,0,100,0),
(@PATH,6,7361.995,68.98799,768.5237,0,0,0,0,100,0),
(@PATH,7,7364.523,67.67627,768.2407,0,0,0,0,100,0),
(@PATH,8,7367.454,66.37734,768.0353,0,0,0,0,100,0),
(@PATH,9,7376.943,70.24853,768.2549,0,0,0,0,100,0),
(@PATH,10,7381.203,79.12584,768.1313,0,0,0,0,100,0),
(@PATH,11,7381.404,88.16858,767.916,0,0,0,0,100,0),
(@PATH,12,7375.376,95.45366,768.1199,0,0,0,0,100,0),
(@PATH,13,7367.612,98.93452,768.0594,0,0,0,0,100,0),
(@PATH,14,7356.52,94.24516,768.1293,0,0,0,0,100,0),
(@PATH,15,7353.27,86.24516,768.6293,0,0,0,0,100,0),
(@PATH,16,7356.827,94.43121,767.876,0,0,0,0,100,0),
(@PATH,17,7367.631,98.85133,767.9012,0,0,0,0,100,0);
-- 0x203CD047601CE040000C1D000009F23D .go 7375.525 95.07399 768.0959

-- Pathing for  Entry: Entry: 'TDB FORMAT' 
SET @NPC := @CGUID+1;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7381.1,`position_y`=112.154,`position_z`=768.375 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(@PATH, 1, 7381.1, 112.154, 768.375, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 7368.38, 110.845, 767.979, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 7354.4, 103.906, 768.445, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 7344.74, 96.7026, 767.717, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 7337.79, 84.0965, 767.688, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 7340, 69.82, 767.956, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 7353.45, 56.563, 767.706, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 7366.46, 52.9065, 767.821, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 7380.41, 57.9473, 767.699, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 7387.79, 66.6494, 767.697, 0, 0, 0, 0, 100, 0),
(@PATH, 11, 7392.69, 78.596, 767.978, 0, 0, 0, 0, 100, 0),
(@PATH, 12, 7393.78, 90.943, 768.14, 0, 0, 0, 0, 100, 0),
(@PATH, 13, 7387.43, 104.127, 767.719, 0, 0, 0, 0, 100, 0);
-- 0x203CD047601CE040000C1D000009F23D .go 7375.525 95.07399 768.0959

-- Pathing for  Entry: Entry: 'TDB FORMAT' 
SET @NPC := @CGUID+6;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7309.298,`position_y`=-94.63777,`position_z`=766.5891 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7309.298,-94.63777,766.5891,0,0,0,0,100,0),
(@PATH,2,7303.313,-75.03469,766.8827,0,0,0,0,100,0),
(@PATH,3,7289.884,-57.31756,766.8895,0,0,0,0,100,0),
(@PATH,4,7278.167,-53.45168,766.9109,0,0,0,0,100,0),
(@PATH,5,7266.225,-48.76962,766.9287,0,0,0,0,100,0),
(@PATH,6,7246.023,-56.97508,767.0757,0,0,0,0,100,0),
(@PATH,7,7236.773,-64.47508,767.8257,0,0,0,0,100,0),
(@PATH,8,7233.273,-67.47508,768.0757,0,0,0,0,100,0),
(@PATH,9,7227.773,-71.97508,768.5757,0,0,0,0,100,0),
(@PATH,10,7221.167,-77.66672,769.0883,0,0,0,0,100,0),
(@PATH,11,7228.944,-71.11933,768.6108,0,0,0,0,100,0),
(@PATH,12,7233.444,-67.36933,767.8608,0,0,0,0,100,0),
(@PATH,13,7246.307,-56.6386,766.7356,0,0,0,0,100,0),
(@PATH,14,7266.435,-48.60221,766.9109,0,0,0,0,100,0),
(@PATH,15,7278.559,-53.696,766.8962,0,0,0,0,100,0),
(@PATH,16,7290.03,-57.1703,766.8922,0,0,0,0,100,0),
(@PATH,17,7303.547,-75.26831,766.8327,0,0,0,0,100,0),
(@PATH,18,7309.313,-94.89297,766.6609,0,0,0,0,100,0),
(@PATH,19,7308.879,-110.5107,767.2982,0,0,0,0,100,0),
(@PATH,20,7299.829,-123.0285,769.4202,0,0,0,0,100,0),
(@PATH,21,7297.579,-125.0285,769.9202,0,0,0,0,100,0),
(@PATH,22,7291.329,-126.7785,772.1702,0,0,0,0,100,0),
(@PATH,23,7282.079,-128.2785,771.4202,0,0,0,0,100,0),
(@PATH,24,7287.145,-126.9779,772.1946,0,0,0,0,100,0),
(@PATH,25,7291.395,-126.9779,772.1946,0,0,0,0,100,0),
(@PATH,26,7298.645,-123.4779,769.6946,0,0,0,0,100,0),
(@PATH,27,7306.161,-115.4552,767.3415,0,0,0,0,100,0);
-- 0x203CD047601CE040000C1D000009DB69 .go 7309.298 -94.63777 766.5891

-- Pathing for  Entry: Entry: 'TDB FORMAT' 
SET @NPC := 107733;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7221.13,`position_y`=-18.2933,`position_z`=772.599 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(@PATH, 1, 7221.13, -18.2933, 772.599, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 7235.03, -15.6731, 770.008, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 7258.23, -18.5613, 767.271, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 7267.32, -20.2406, 766.602, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 7279.58, -9.386, 766.586, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 7294.6, -3.2081, 766.634, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 7307.04, -9.61598, 766.584, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 7317.91, -27.5873, 766.584, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 7324.12, -37.4071, 766.652, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 7342.71, -37.1454, 769.84, 0, 0, 0, 0, 100, 0),
(@PATH, 11, 7354.25, -35.7761, 773.414, 0, 0, 0, 0, 100, 0),
(@PATH, 12, 7369.89, -32.0949, 776.553, 0, 0, 0, 0, 100, 0),
(@PATH, 13, 7387.69, -27.0577, 780.289, 0, 0, 0, 0, 100, 0),
(@PATH, 14, 7399.21, -28.6298, 784.644, 0, 0, 0, 0, 100, 0),
(@PATH, 15, 7413.14, -30.0314, 780.646, 0, 0, 0, 0, 100, 0),
(@PATH, 16, 7425.27, -29.5534, 780.971, 0, 0, 0, 0, 100, 0),
(@PATH, 17, 7411.44, -28.981, 781.421, 0, 0, 0, 0, 100, 0),
(@PATH, 18, 7399.76, -28.727, 784.636, 0, 0, 0, 0, 100, 0),
(@PATH, 19, 7390.38, -28.7809, 780.746, 0, 0, 0, 0, 100, 0),
(@PATH, 20, 7372.06, -32.0876, 776.64, 0, 0, 0, 0, 100, 0),
(@PATH, 21, 7353.62, -34.6722, 773.221, 0, 0, 0, 0, 100, 0),
(@PATH, 22, 7335, -34.9062, 768.601, 0, 0, 0, 0, 100, 0),
(@PATH, 23, 7319.33, -34.3558, 766.584, 0, 0, 0, 0, 100, 0),
(@PATH, 24, 7310.63, -17.7319, 766.584, 0, 0, 0, 0, 100, 0),
(@PATH, 25, 7299.04, -9.65849, 766.584, 0, 0, 0, 0, 100, 0),
(@PATH, 26, 7285.09, -10.8918, 766.584, 0, 0, 0, 0, 100, 0),
(@PATH, 27, 7270.77, -18.5549, 766.612, 0, 0, 0, 0, 100, 0),
(@PATH, 28, 7263.12, -21.4507, 766.643, 0, 0, 0, 0, 100, 0),
(@PATH, 29, 7252.2, -17.557, 768.13, 0, 0, 0, 0, 100, 0),
(@PATH, 30, 7243.25, -15.1658, 768.691, 0, 0, 0, 0, 100, 0),
(@PATH, 31, 7231.68, -15.6278, 770.68, 0, 0, 0, 0, 100, 0);
-- 0x203CD047601CE040000C1D000009DB69 .go 7309.298 -94.63777 766.5891
