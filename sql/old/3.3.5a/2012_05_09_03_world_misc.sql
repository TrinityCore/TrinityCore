-- Update Scourgelord Tyrannus "Make him fly"
UPDATE `creature_template_addon` SET `bytes1`=50331648 WHERE `entry`=36794;

-- Put Rimefang in the air and make him fly
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=36661;
UPDATE `creature_template_addon` SET `bytes1`=50331648 WHERE `entry`=36661;

-- Deathwhisper Necrolyte SAI
SET @ENTRY   := 36788; -- NPC entry
SET @SPELL1  := 69577; -- Shadow Bolt
SET @SPELL2  := 69578; -- Conversion Beam
SET @SPELL3  := 45104; -- Shadow Channelling
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,100,100,3000,3000,11,@SPELL1,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Deathwhisper Necrolyte - Combat - Cast Shadow Bolt'),
(@ENTRY,0,1,0,0,0,100,6,9000,9000,24000,24000,11,@SPELL2,0,0,0,0,0,5,0,0,0,0,0,0,0, 'Deathwhisper Necrolyte - Combat - Cast Conversion Beam');

-- Deathwhisper Necrolyte pathing
SET @NPC := 202231;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=592.975,`position_y`=176.104,`position_z`=508.746 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES (@NPC,@PATH,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,596.0208,175.5243,508.3654,0,0,0,100,0),
(@PATH,2,605.2656,157.7101,507.2126,0,0,0,100,0),
(@PATH,3,604.4063,146.283,507.3376,0,0,0,100,0),
(@PATH,4,592.2899,131.4271,507.8163,0,0,0,100,0),
(@PATH,5,577.4531,118.224,508.3163,0,0,0,100,0),
(@PATH,6,563.0695,103.7309,514.1504,0,0,0,100,0),
(@PATH,7,557.7743,89.41319,523.1727,0,0,0,100,0),
(@PATH,8,560.9583,77.65278,525.4227,0,0,0,100,0),
(@PATH,9,560.9583,77.65278,525.4227,0,0,0,100,0),
(@PATH,10,571.0139,69.43403,525.2753,0,0,0,100,0),
(@PATH,11,560.9583,77.65278,525.4227,0,0,0,100,0),
(@PATH,12,557.7743,89.41319,523.1727,0,0,0,100,0),
(@PATH,13,563.0695,103.7309,514.1504,0,0,0,100,0),
(@PATH,14,577.4531,118.224,508.3163,0,0,0,100,0),
(@PATH,15,592.2899,131.4271,507.8163,0,0,0,100,0),
(@PATH,16,604.4063,146.283,507.3376,0,0,0,100,0),
(@PATH,17,605.2656,157.7101,507.2126,0,0,0,100,0),
(@PATH,18,596.0208,175.5243,508.3654,0,0,0,100,0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=202231;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(202231,202231,0,0,2),
(202231,202099,7,288,2),
(202231,202282,7,324,2),
(202231,202125,7,360,2),
(202231,202203,7,36,2),
(202231,201960,7,72,2);

-- Remove a dupe spawn
DELETE FROM `creature` WHERE `guid`=201998;
DELETE FROM `creature_addon` WHERE `guid`=201998;
