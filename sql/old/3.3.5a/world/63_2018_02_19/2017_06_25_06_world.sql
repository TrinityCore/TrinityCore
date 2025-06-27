-- ==============================
-- RAGEFIRE CHASM TBC UPDATES
-- ==============================

-- ======================================
-- All Bosses Are Immune To Crowd Control -- Daze, Horror, Shackle, Banish, Polymorph, Knockout, Freeze, Stun, Snare, Sleep, Silence, Pacify, Root, Fear, Distract, Disarm, Confused, Charm
-- ======================================
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|76234719 WHERE `entry` IN (11517,11518,11519,11520);

-- Linked Aggro Between Group 1 Ragefire Troggs
DELETE FROM `creature_formations` WHERE `leaderGUID`=48653;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(48653, 48653, 0, 0, 3, 0, 0),
(48653, 48654, 0, 0, 3, 0, 0),
(48653, 48662, 0, 0, 3, 0, 0);

-- Linked Aggro Between Group 2 Ragefire Troggs
DELETE FROM `creature_formations` WHERE `leaderGUID`=48660;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(48660, 48660, 0, 0, 3, 0, 0),
(48660, 48666, 0, 0, 3, 0, 0),
(48660, 48657, 0, 0, 3, 0, 0);

-- Move Trogg Closer To Group
UPDATE `creature` SET `position_x` = -277.035553, `position_y` = -47.274254, `position_z` = -60.932140 WHERE `guid` IN (48658);

-- Linked Aggro Between Group 4 Ragefire Troggs
DELETE FROM `creature_formations` WHERE `leaderGUID`=48671;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(48671, 48671, 0, 0, 3, 0, 0),
(48671, 48667, 0, 0, 3, 0, 0),
(48671, 48665, 0, 0, 3, 0, 0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=48671;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(48671, 48671, 0, 0, 3, 0, 0),
(48671, 48667, 0, 0, 3, 0, 0),
(48671, 48665, 0, 0, 3, 0, 0);

-- Linked Aggro Between 2 Ragefire Troggs (Oggleflint Path)
DELETE FROM `creature_formations` WHERE `leaderGUID`=48656;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(48656, 48656, 0, 0, 3, 0, 0),
(48656, 48652, 0, 0, 3, 0, 0);

-- Linked Aggro Between Ragefire Trogg and Shaman (Oggleflint Path)
DELETE FROM `creature_formations` WHERE `leaderGUID`=43583;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(43583, 43583, 0, 0, 3, 0, 0),
(43583, 43582, 0, 0, 3, 0, 0);

-- Linked Aggro Between (2nd Right-Path) 2 Ragefire Troggs
DELETE FROM `creature_formations` WHERE `leaderGUID`=48677;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(48677, 48677, 0, 0, 3, 0, 0),
(48677, 48678, 0, 0, 3, 0, 0);

-- Earthborer Pathing
SET @NPC := 48642;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -176.762, 11.7284, -31.6117, 0),
(@PATH, 2, -190.166, 10.9667, -33.0618, 0),
(@PATH, 3, -210.648, 7.87269, -39.8187, 0),
(@PATH, 4, -230.782, 9.0604, -44.4237, 0),
(@PATH, 5, -257.486, 7.90906, -49.87, 0),
(@PATH, 6, -277.67, 8.30601, -49.0795, 0),
(@PATH, 7, -286.82, 7.69739, -46.2229, 0),
(@PATH, 8, -298.657, 5.29958, -48.0252, 0),
(@PATH, 9, -303.916, 0.147967, -49.7325, 0),
(@PATH, 10, -293.624, 7.59828, -47.0034, 0),
(@PATH, 11, -280.864, 9.03737, -47.8212, 0),
(@PATH, 12, -265.063, 9.36602, -49.8266, 0),
(@PATH, 13, -247.208, 8.66721, -48.9012, 0),
(@PATH, 14, -233.341, 8.45427, -44.4523, 0),
(@PATH, 15, -216.121, 6.63711, -41.6912, 0),
(@PATH, 16, -204.445, 7.92862, -37.4818, 0),
(@PATH, 17, -192.818, 10.4947, -33.4114, 0),
(@PATH, 18, -172.941, 14.3137, -30.7882, 0),
(@PATH, 19, -161.6, 14.8526, -27.2189, 0),
(@PATH, 20, -147.478, 11.5309, -22.3629, 0),
(@PATH, 21, -135.908, 8.74903, -20.8654, 0),
(@PATH, 22, -124.215, 10.9816, -19.9281, 0),
(@PATH, 23, -116.619, 15.0944, -18.8846, 0),
(@PATH, 24, -111.628, 24.9273, -18.6011, 0),
(@PATH, 25, -108.915, 36.6246, -18.0731, 0),
(@PATH, 26, -114.503, 21.4459, -18.8557, 0),
(@PATH, 27, -118.88, 14.3031, -19.0844, 0),
(@PATH, 28, -131.828, 8.81858, -20.8654, 0),
(@PATH, 29, -144.715, 9.21781, -21.8423, 0),
(@PATH, 30, -161.281, 12.4744, -27.4041, 0),
(@PATH, 31, -170.005, 13.6925, -30.0021, 0);

-- Linked Aggro Between Right Group of Searing Cult Type NPC
DELETE FROM `creature_formations` WHERE `leaderGUID`=48689;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(48689, 48689, 0, 0, 3, 0, 0),
(48689, 48695, 0, 0, 3, 0, 0),
(48689, 48691, 0, 0, 3, 0, 0);

-- Linked Aggro Between Left Group of Searing Cult Type NPC
UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE  `guid`=48687;
DELETE FROM `creature_formations` WHERE `leaderGUID`=48687;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(48687, 48687, 0, 0, 3, 0, 0),
(48687, 48688, 0, 0, 3, 0, 0),
(48687, 48694, 0, 0, 3, 0, 0);

-- Right Searing Blade Enforcer Pathing
SET @NPC := 48690;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -203.927, 99.1463, -25.4809, 0),
(@PATH, 2, -200.74, 104.201, -25.1381, 0),
(@PATH, 3, -198.066, 115.548, -23.217, 0),
(@PATH, 4, -195.291, 126.656, -22.168, 0),
(@PATH, 5, -192.549, 136.545, -24.1064, 0),
(@PATH, 6, -190.259, 144.95, -25.2199, 0),
(@PATH, 7, -193.47, 134.133, -23.458, 0),
(@PATH, 8, -196.29, 123.736, -22.179, 0),
(@PATH, 9, -199.336, 113.159, -23.7528, 0),
(@PATH, 10, -199.643, 106.426, -24.8865, 0),
(@PATH, 11, -205.093, 98.0147, -25.4833, 0);


-- Left Searing Blade Enforcer Pathing
SET @NPC := 48696;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -214.025, 91.2148, -25.0186, 0),
(@PATH, 2, -219.007, 90.5475, -25.0186, 0),
(@PATH, 3, -229.367, 92.7477, -23.1312, 0),
(@PATH, 4, -235.891, 93.102, -21.7277, 0),
(@PATH, 5, -246.583, 91.6992, -23.5772, 0),
(@PATH, 6, -254.38, 92.4157, -25.0184, 0),
(@PATH, 7, -245.579, 91.7263, -23.2418, 0),
(@PATH, 8, -236.893, 92.4553, -21.7166, 0),
(@PATH, 9, -231.24, 92.8211, -22.4395, 0),
(@PATH, 10, -222.659, 90.784, -25.0184, 0),
(@PATH, 11, -217.698, 89.1509, -25.0184, 0),
(@PATH, 12, -209.44, 94.6833, -25.2915, 0);

-- Linked Aggro Between Ragefire Troggs Guarding Oggleflint
DELETE FROM `creature_formations` WHERE `leaderGUID`=48645;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(48645, 48645, 0, 0, 3, 0, 0),
(48645, 48643, 0, 0, 3, 0, 0);

-- Linked Aggro Between 2 Ragefire Troggs (Oggleflint Path)
DELETE FROM `creature_formations` WHERE `leaderGUID`=48649;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(48649, 48649, 0, 0, 3, 0, 0),
(48649, 48659, 0, 0, 3, 0, 0);

-- Linked Aggro Between Left Platform Group of Searing Cult Type NPC
DELETE FROM `creature_formations` WHERE `leaderGUID`=48693;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(48693, 48693, 0, 0, 3, 0, 0),
(48693, 48692, 0, 0, 3, 0, 0),
(48693, 48705, 0, 0, 3, 0, 0);

UPDATE `creature` SET `SpawnDist` = 4, `MovementType` = 1 WHERE `guid` = 48693;

-- Guards Should not be Moving
UPDATE `creature` SET `SpawnDist` = 0, `MovementType` = 0 WHERE `guid` = 48704;
UPDATE `creature` SET `SpawnDist` = 0, `MovementType` = 0 WHERE `guid` = 48703;

-- Linked Aggro Between Left Platform Guards
DELETE FROM `creature_formations` WHERE `leaderGUID`=48704;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(48704, 48704, 0, 0, 3, 0, 0),
(48704, 48703, 0, 0, 3, 0, 0);

-- Linked Aggro Between Right Platform Guards
DELETE FROM `creature_formations` WHERE `leaderGUID`=48699;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(48699, 48699, 0, 0, 3, 0, 0),
(48699, 48700, 0, 0, 3, 0, 0);

-- Linked Aggro Between Far Right Platform Group of Searing Cult Type NPC
DELETE FROM `creature_formations` WHERE `leaderGUID`=48719;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(48719, 48719, 0, 0, 3, 0, 0),
(48719, 48720, 0, 0, 3, 0, 0),
(48719, 48702, 0, 0, 3, 0, 0);

-- Linked Aggro Between Far Right Platform Guards
DELETE FROM `creature_formations` WHERE `leaderGUID`=48713;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(48713, 48713, 0, 0, 3, 0, 0),
(48713, 48712, 0, 0, 3, 0, 0);

-- Linked Aggro Between Far Left Platform Group of Searing Cult Type NPC
DELETE FROM `creature_formations` WHERE `leaderGUID`=48710;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(48710, 48710, 0, 0, 3, 0, 0),
(48710, 48709, 0, 0, 3, 0, 0);

-- Linked Aggro Between Far Left Platform Guards
DELETE FROM `creature_formations` WHERE `leaderGUID`=48708;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(48708, 48708, 0, 0, 3, 0, 0),
(48708, 48711, 0, 0, 3, 0, 0);

-- Linked Aggro Between FAR Far Right Platform Group of Searing Cult Type NPC
DELETE FROM `creature_formations` WHERE `leaderGUID`=48715;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(48715, 48715, 0, 0, 3, 0, 0),
(48715, 48717, 0, 0, 3, 0, 0),
(48715, 48722, 0, 0, 3, 0, 0);

-- Linked Aggro Between FAR Far Right Platform Group of Searing Cult Type NPC
DELETE FROM `creature_formations` WHERE `leaderGUID`=48716;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(48716, 48716, 0, 0, 3, 0, 0),
(48716, 48718, 0, 0, 3, 0, 0),
(48716, 48714, 0, 0, 3, 0, 0);

-- Linked Aggro Between FAR Far Right Platform Group of Searing Cult Type NPC
DELETE FROM `creature_formations` WHERE `leaderGUID`=48723;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(48723, 48723, 0, 0, 3, 0, 0),
(48723, 48724, 0, 0, 3, 0, 0);

-- Linked Aggro Between Group of Searing Cult Type NPC
DELETE FROM `creature_formations` WHERE `leaderGUID`=48732;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(48732, 48732, 0, 0, 3, 0, 0),
(48732, 48728, 0, 0, 3, 0, 0);

-- Linked Aggro Between Group of Searing Cult Type NPC in front of Jergosh the Invoker
DELETE FROM `creature_formations` WHERE `leaderGUID`=48737;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(48737, 48737, 0, 0, 3, 0, 0),
(48737, 48741, 0, 0, 3, 0, 0);

-- Linked Aggro Between Group of Searing Cult Type NPC
DELETE FROM `creature_formations` WHERE `leaderGUID`=48744;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(48744, 48744, 0, 0, 3, 0, 0),
(48744, 48739, 0, 0, 3, 0, 0),
(48744, 48745, 0, 0, 3, 0, 0);

-- Linked Aggro Between Group of Searing Cult Type NPC Up Balzzalan Ramp
DELETE FROM `creature_formations` WHERE `leaderGUID`=48727;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(48727, 48727, 0, 0, 3, 0, 0),
(48727, 48726, 0, 0, 3, 0, 0);

-- Linked Aggro Between Group of Searing Cult Type NPC Up Balzzalan Ramp
DELETE FROM `creature_formations` WHERE `leaderGUID`=48730;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(48730, 48730, 0, 0, 3, 0, 0),
(48730, 48729, 0, 0, 3, 0, 0);

-- Linked Aggro Between Group of Searing Cult Type NPC Up Balzzalan Ramp
DELETE FROM `creature_formations` WHERE `leaderGUID`=48736;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(48736, 48736, 0, 0, 3, 0, 0),
(48736, 48734, 0, 0, 3, 0, 0),
(48736, 48735, 0, 0, 3, 0, 0);

-- Linked Aggro Between Group of Searing Cult Type NPC Up Balzzalan Ramp
DELETE FROM `creature_formations` WHERE `leaderGUID`=48738;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(48738, 48738, 0, 0, 3, 0, 0),
(48738, 48743, 0, 0, 3, 0, 0),
(48738, 48746, 0, 0, 3, 0, 0);

-- Linked Aggro Between Group of Searing Cult Type NPC Up Balzzalan Ramp
DELETE FROM `creature_formations` WHERE `leaderGUID`=48747;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(48747, 48747, 0, 0, 3, 0, 0),
(48747, 48748, 0, 0, 3, 0, 0);

-- Linked Aggro Between Group of Searing Cult Type NPC in Front of  Balzzalan
DELETE FROM `creature_formations` WHERE `leaderGUID`=48751;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(48751, 48751, 0, 0, 3, 0, 0),
(48751, 48749, 0, 0, 3, 0, 0);

-- Linked Aggro Between Ragefire Troggs (Left of Cross-roads near start)
DELETE FROM `creature_formations` WHERE `leaderGUID`=48668;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(48668, 48668, 0, 0, 3, 0, 0),
(48668, 48674, 0, 0, 3, 0, 0);

-- Linked Aggro Between Ragefire Troggs (Left of Cross-roads near start)
DELETE FROM `creature_formations` WHERE `leaderGUID`=48637;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(48637, 48637, 0, 0, 3, 0, 0),
(48637, 38050, 0, 0, 3, 0, 0);

-- Linked Aggro Between Ragefire Troggs (Left of Cross-roads near start)
DELETE FROM `creature_formations` WHERE `leaderGUID`=43580;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(43580, 43580, 0, 0, 3, 0, 0),
(43580, 38049, 0, 0, 3, 0, 0),
(43580, 43581, 0, 0, 3, 0, 0);
