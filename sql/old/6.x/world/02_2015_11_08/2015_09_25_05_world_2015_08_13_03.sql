-- Stratholme - The Gauntlet
-- 1. Ghoul
SET @NPC := 53675;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH, 1, 3711.96, -3428.02, 131.083, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 3715.35, -3439.06, 129.468, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 3719.55, -3452.41, 129.604, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 3723.87, -3470.47, 129.838, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 3711.6, -3485.74, 129.702, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 3696.91, -3487.86, 131.216, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 3675.95, -3489.1, 135.379, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 3650.84, -3490.4, 136.889, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 3664.74, -3488.84, 136.633, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 3692.63, -3486.4, 132.018, 0, 0, 0, 0, 100, 0),
(@PATH, 11, 3713.54, -3482.02, 129.701, 0, 0, 0, 0, 100, 0),
(@PATH, 12, 3719.24, -3466.01, 129.741, 0, 0, 0, 0, 100, 0),
(@PATH, 13, 3717.94, -3444.6, 129.36, 0, 0, 0, 0, 100, 0),
(@PATH, 14, 3716.43, -3439.47, 129.393, 0, 0, 0, 0, 100, 0);
-- 2 . ghoul
SET @NPC := 53601;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH, 1, 3590.12, -3472.24, 135.046, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 3605.83, -3487.43, 135.938, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 3615.36, -3497.68, 137.061, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 3627.56, -3514.74, 136.693, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 3638.86, -3523.51, 136.974, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 3654.2, -3517.46, 136.842, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 3661.21, -3505.25, 136.721, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 3655.99, -3491.83, 136.798, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 3640.93, -3487.52, 137.452, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 3631.02, -3489.32, 137.395, 0, 0, 0, 0, 100, 0),
(@PATH, 11, 3613.42, -3495.94, 136.891, 0, 0, 0, 0, 100, 0),
(@PATH, 12, 3601.41, -3489.18, 135.84, 0, 0, 0, 0, 100, 0);

-- texts
-- Undead Postman SAI
SET @ENTRY := 11142;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,40,0,0,0,0,0,0,"Undead Postman - On Just Summoned - Start Attacking"),
(@ENTRY,0,1,0,0,0,50,0,0,1000,20000,30000,11,5137,64,0,0,0,0,2,0,0,0,0,0,0,0,"Undead Postman - In Combat - Cast 'Call of the Grave'"),
(@ENTRY,0,2,0,0,0,75,0,3000,4000,8000,9000,11,7713,64,0,0,0,0,2,0,0,0,0,0,0,0,"Undead Postman - In Combat - Cast 'Wailing Dead'"),
(@ENTRY,0,3,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Undead Postman - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `entry`=11142;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
(11142, 0, 0, 'No tampering with the mail!', 12, 0, 100, 0, 0, 0, 6470, 'Undead Postman');

-- enable flying
UPDATE `creature_template` SET `InhabitType`=4 WHERE  `entry`=10408;
-- ghoul
SET @NPC := 53696;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH, 1, 3874.56, -3680.21, 142.696, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 3888.33, -3677.68, 141.623, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 3910.54, -3669.96, 138.655, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 3927.9, -3660.86, 139.4, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 3937.1, -3653.54, 140.085, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 3951.33, -3644.09, 135.489, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 3966.27, -3637.04, 132.434, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 3981.49, -3626.32, 130.01, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 3994.5, -3616.13, 129.41, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 3984.25, -3625.25, 130.021, 0, 0, 0, 0, 100, 0),
(@PATH, 11, 3972.75, -3635.49, 131.203, 0, 0, 0, 0, 100, 0),
(@PATH, 12, 3956.89, -3644.66, 134.041, 0, 0, 0, 0, 100, 0),
(@PATH, 13, 3941.59, -3650.12, 139.218, 0, 0, 0, 0, 100, 0),
(@PATH, 14, 3930.15, -3658.18, 139.569, 0, 0, 0, 0, 100, 0),
(@PATH, 15, 3918.7, -3666.25, 137.71, 0, 0, 0, 0, 100, 0),
(@PATH, 16, 3902.74, -3674.09, 139.385, 0, 0, 0, 0, 100, 0),
(@PATH, 17, 3896.26, -3676.72, 140.59, 0, 0, 0, 0, 100, 0);

-- Plague Ghoul SAI
SET @ENTRY := 10405;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=4;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,4,0,1,0,100,0,3000,5000,8000,12000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Plague Ghoul - Out of Combat - Play Emote 1");

-- Ghoul Ravener SAI
SET @ENTRY := 10406;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,2,0,1,0,100,0,3000,5000,8000,12000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ghoul Ravener - Out of Combat - Play Emote 1");

-- Fleshflayer Ghoul SAI
SET @ENTRY := 10407;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,2,0,1,0,100,0,3000,5000,8000,12000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fleshflayer Ghoul - Out of Combat - Play Emote 1");
