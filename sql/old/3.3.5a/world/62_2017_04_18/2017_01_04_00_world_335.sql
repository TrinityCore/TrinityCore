-- Right and Left Camp Attack
-- ======================================
-- All Bosses Are Immune To Crowd Control -- Daze, Horror, Shackle, Banish, Polymorph, Knockout, Freeze, Stun, Snare, Sleep, Silence, Pacify, Root, Fear, Distract, Disarm, Confused, Charm
-- ======================================
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|76234719 WHERE `entry` IN (647,645,639,626,1763,646,644,643,642);
-- Group 1 Pathing 
UPDATE `creature` SET `position_x` = -169.588608, `position_y` = -402.076477, `position_z` = 57.082920, `orientation` = 0.354403 WHERE `guid` = 79374;

UPDATE `creature_addon` SET `path_id`=0 WHERE  `guid`=79374;
DELETE FROM `waypoint_data` WHERE `id` IN (793740);

UPDATE `creature` SET `SpawnDist` = 0, `MovementType` = 0 WHERE `guid` IN (79374);
UPDATE `creature` SET `SpawnDist` = 0, `MovementType` = 2 WHERE `guid` IN (79373);
DELETE FROM `creature_formations` WHERE `leaderGUID`=79373;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(79373, 79373, 0, 0, 2, 0, 0), -- Defias Evoker linked to Defias Overseer
(79373, 79374, 2, 0, 2, 0, 0); -- Defias Evoker linked to Defias Overseer

-- RhahkZor Pathing
SET @NPC := 79168;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -193.304, -440.544, 53.5319, 0),
(@PATH, 2, -192.834, -435.956, 53.2713, 15000),
(@PATH, 3, -193.565, -441.151, 53.568, 0),
(@PATH, 4, -191.926, -453.598, 54.4336, 0),
(@PATH, 5, -192.789, -447.285, 54.3726, 40000);

-- Remove Random Movement of 2 Miners
UPDATE `creature` SET `SpawnDist` = 0, `MovementType` = 0 WHERE `guid` IN (79172,79180,79182,79184);

-- Fix an Defias Overseer Pathing (Removed bad waypoint)
SET @NPC := 79273;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -181.386, -491.686, 54.0401, 0),
(@PATH, 2, -180.97, -498.254, 53.4632, 0),
(@PATH, 3, -183.791, -502.539, 53.3808, 0),
(@PATH, 4, -193.579, -506.077, 53.1769, 0),
(@PATH, 5, -193.943, -496.426, 53.2004, 0),
(@PATH, 6, -192.601, -488.515, 54.0488, 0),
(@PATH, 7, -187.413, -492.182, 53.5523, 0);

-- Add Random NPC Movement to Defias Evoker
UPDATE `creature` SET `SpawnDist` = 5, `MovementType` = 1 WHERE `guid` IN (79177);

-- Group 2 Pathing 
UPDATE `creature` SET `position_x` = -206.025070, `position_y` = -505.739960, `position_z` = 51.897705, `orientation` = 3.121361 WHERE `guid` = 79245;
UPDATE `creature_addon` SET `path_id`=0 WHERE  `guid`=79245;
DELETE FROM `waypoint_data` WHERE `id` IN (792450);
UPDATE `creature` SET `SpawnDist` = 0, `MovementType` = 0 WHERE `guid` IN (79245);
UPDATE `creature` SET `SpawnDist` = 0, `MovementType` = 2 WHERE `guid` IN (79244);
DELETE FROM `creature_formations` WHERE `leaderGUID`=79244;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(79244, 79244, 0, 0, 2, 0, 0), -- Defias Evoker linked to Defias Overseer
(79244, 79245, 2, 0, 2, 0, 0); -- Defias Evoker linked to Defias Overseer

-- Fix Gilnid Movement
UPDATE `creature` SET `SpawnDist` = 5, `MovementType` = 1 WHERE `guid` IN (79206);
-- Group 3 Pathing
UPDATE `creature_addon` SET `path_id`=0 WHERE  `guid`=79229;
DELETE FROM `waypoint_data` WHERE `id` IN (792290);
UPDATE `creature` SET `SpawnDist` = 0, `MovementType` = 0 WHERE `guid` IN (79229);
UPDATE `creature` SET `SpawnDist` = 0, `MovementType` = 2 WHERE `guid` IN (79230);
DELETE FROM `creature_formations` WHERE `leaderGUID`=79230;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(79230, 79230, 0, 0, 2, 0, 0), -- Defias Wizard linked to Defias Taskmaster
(79230, 79229, 2, 0, 2, 0, 0); -- Defias Wizard linked to Defias Taskmaster

-- Fix NPC Z Problem
UPDATE `creature` SET `position_z` = 28.4 WHERE `guid` IN (79242);
-- Fix NPC Placement
UPDATE `creature` SET `position_x` = -209.043808, `position_y` = -590.668701, `position_z` = 20.976866, `orientation` = 2.302266 WHERE `guid` = 79212;
UPDATE `creature` SET `position_x` = -196.753937, `position_y` = -582.341492, `position_z` = 20.976866, `orientation` = 1.217631 WHERE `guid` = 79209;

-- Group  Pathing 
UPDATE `creature` SET `position_x` = -112.329689, `position_y` = -645.826172, `position_z` = 8.976121, `orientation` = 5.168961 WHERE `guid` = 79260;
UPDATE `creature_addon` SET `path_id`=0 WHERE  `guid`=79260;
DELETE FROM `waypoint_data` WHERE `id` IN (792600);
UPDATE `creature` SET `SpawnDist` = 0, `MovementType` = 0 WHERE `guid` IN (79260);
UPDATE `creature` SET `SpawnDist` = 0, `MovementType` = 2 WHERE `guid` IN (79361);

DELETE FROM `creature_formations` WHERE `leaderGUID`=79361;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(79361, 79361, 0, 0, 2, 0, 0), -- Defias Wizard linked to Defias Overseer
(79361, 79260, 2, 0, 2, 0, 0); -- Defias Wizard linked to Defias Overseer

-- Delete Humans in Foundry (source: https://youtu.be/Jm_5e3UEPq4?t=133 )
DELETE FROM `creature` WHERE `guid` IN (79285,79283,79284,79380,79378,79379);
DELETE FROM `creature_addon` WHERE `guid` IN (79285,79283,79284,79380,79378,79379);
DELETE FROM `waypoint_data` WHERE `id` IN (792850,792830,792840,793800,793780,793790);
DELETE FROM `linked_respawn` WHERE `linkedGuid` IN (79283,79284,79285,79368,79378,79379,79380,79383);
DELETE FROM `linked_respawn` WHERE `guid` IN (79283,79284,79285,79368,79378,79379,79380,79383);

-- Fix NPC Random Movement
UPDATE `creature` SET `SpawnDist` = 5, `MovementType` = 1 WHERE `guid` IN (79296);

-- Linked Aggro Between Mr. Smite and 2 Defias Blackguards
DELETE FROM `creature_formations` WHERE `leaderGUID`=79337;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(79337, 79337, 0, 0, 2, 0, 0),
(79337, 79345, 0, 0, 2, 0, 0),
(79337, 79346, 0, 0, 2, 0, 0);

-- Linked Aggro Between Defias Pirate and Defias Squallshaper Behind Mr. Smite
DELETE FROM `creature_formations` WHERE `leaderGUID`=79338;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(79338, 79338, 0, 0, 2, 0, 0),
(79338, 79330, 0, 0, 2, 0, 0);

-- MOVE NPC BACK SO THEY DO NOT PULL
UPDATE `creature` SET `position_x` = -22.056364, `position_y` = -809.104553, `position_z` = 19.543686, `orientation` = 1.330994 WHERE `guid` = 79338;
UPDATE `creature` SET `position_x` = -34.434910, `position_y` = -796.904114, `position_z` = 18.909523, `orientation` = 6.229524 WHERE `guid` = 79330;

-- Fix NPC Random Movement of Pirates on the Ship
UPDATE `creature` SET `SpawnDist`=3, `MovementType`=1 WHERE `guid` IN (79323,79325,79305,79327);

-- Remove 2 Defias Blackguards On Deck (They Do Not Exist As Per Videos)
DELETE FROM `creature` WHERE `guid` IN (79368,79383);

-- Linked Aggro Between VanCleef and 2 Defias Blackguard Adds
DELETE FROM `creature_formations` WHERE `leaderGUID`=79336;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(79336, 79336, 0, 0, 2, 0, 0),
(79336, 79369, 0, 0, 2, 0, 0), -- Defias Blackguard
(79336, 79370, 0, 0, 2, 0, 0); -- Defias Blackguard

-- VanCleef Adds (Should Not Random Move)
UPDATE `creature` SET `SpawnDist` = 0, `MovementType` = 0 WHERE `guid` IN (79369,79370);
