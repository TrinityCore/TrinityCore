-- Ancestral Spirit Wolf SAI (Source: Sniffs & https://www.youtube.com/watch?v=xFF8DOSeMcg)
SET @ID := 17077;
UPDATE `creature_template` SET `speed_walk` = 1.6, `speed_run` = 1, `unit_flags` = 768, `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN @ID*100+0 AND @ID*100+3 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,54,0,100,0,0,0,0,0,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ancestral Spirit Wolf - On Just Summoned - Run Script"),
(@ID,0,1,0,40,0,100,0,9,0,0,0,0,80,@ID*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ancestral Spirit Wolf - On Waypoint 9 Reached - Run Script"),
(@ID,0,2,0,40,0,100,0,68,0,0,0,0,80,@ID*100+2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ancestral Spirit Wolf - On Waypoint 68 Reached - Run Script"),
(@ID,0,3,0,40,0,100,0,73,0,0,0,0,80,@ID*100+3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ancestral Spirit Wolf - On Waypoint 73 Reached - Run Script"),
-- Hacky follow movement prevention
(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,69,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ancestral Spirit Wolf - On Script - Move To Self"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,0,11,29938,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ancestral Spirit Wolf - On Script - Cast 'Guided by the Spirits'"),
(@ID*100+0,9,2,0,0,0,100,0,0,0,0,0,0,11,30011,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ancestral Spirit Wolf - On Script - Cast 'Quest - Ancestral Spirit Wolf Self Snare'"),
(@ID*100+0,9,3,0,0,0,100,0,5000,5000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ancestral Spirit Wolf - On Script - Say Line 0"),
(@ID*100+0,9,4,0,0,0,100,0,4000,4000,0,0,0,53,0,17077,0,0,0,2,1,0,0,0,0,0,0,0,0,"Ancestral Spirit Wolf - On Script - Start Waypoint"),

(@ID*100+1,9,0,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ancestral Spirit Wolf - On Script - Say Line 1"),
-- Something happens here, he changes speed somehow
(@ID*100+2,9,0,0,0,0,100,0,0,0,0,0,0,4,1018,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"Ancestral Spirit Wolf - On Script - Play Sound 1018"),
-- May be different
(@ID*100+3,9,0,0,0,0,100,0,0,0,0,0,0,41,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ancestral Spirit Wolf - On Script - Delayed Despawn"),
(@ID*100+3,9,1,0,0,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,19,17123,0,0,0,0,0,0,0,"Ancestral Spirit Wolf - On Script - Set Data 0 1 (Earthcaller Ryga)");

-- Earthcaller Ryga SAI
SET @ID := 17123;
UPDATE `creature_template` SET `speed_walk` = 1, `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN @ID*100+0 AND @ID*100+2 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,63,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Earthcaller Ryga - On Just Created - Set Event Phase 1"),
(@ID,0,1,0,38,1,100,0,0,1,0,0,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Earthcaller Ryga - On Data Set 0 1 - Run Script (Phase 1)"),
(@ID,0,2,0,40,0,100,0,2,0,0,0,0,80,@ID*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Earthcaller Ryga - On Waypoint 2 Reached - Run Script"),
(@ID,0,3,0,40,0,100,0,4,0,0,0,0,80,@ID*100+2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Earthcaller Ryga - On Waypoint 4 Reached - Run Script"),

(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,53,0,17123,0,0,0,2,1,0,0,0,0,0,0,0,0,"Earthcaller Ryga - On Script - Start Waypoint"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Earthcaller Ryga - On Script - Set Event Phase 2"),

(@ID*100+1,9,0,0,0,0,100,0,1000,1000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Earthcaller Ryga - On Script - Say Line 0"),
(@ID*100+1,9,1,0,0,0,100,0,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Earthcaller Ryga - On Script - Set Flag Standstate Kneel"),
(@ID*100+1,9,2,0,0,0,100,0,10000,10000,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Earthcaller Ryga - On Script - Remove Flag Standstate Kneel"),

(@ID*100+2,9,0,0,0,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Earthcaller Ryga - On Script - Set Event Phase 1");

DELETE FROM `script_waypoint` WHERE `entry` = 17077;
DELETE FROM `waypoints` WHERE `entry` IN (17077,17123);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(17077,1,-19.435663,3803.981,93.55267,0,0,"Ancestral Spirit Wolf"),
(17077,2,-18.685663,3801.731,94.30267,0,0,"Ancestral Spirit Wolf"),
(17077,3,-17.185663,3800.981,95.30267,0,0,"Ancestral Spirit Wolf"),
(17077,4,-15.185663,3801.981,96.05267,0,0,"Ancestral Spirit Wolf"),
(17077,5,-14.435663,3803.731,96.05267,0,0,"Ancestral Spirit Wolf"),
(17077,6,-14.435663,3804.981,95.80267,0,0,"Ancestral Spirit Wolf"),
(17077,7,-15.435663,3805.981,94.80267,0,0,"Ancestral Spirit Wolf"),
(17077,8,-16.935663,3806.481,94.05267,0,0,"Ancestral Spirit Wolf"),
(17077,9,-17.14388,3805.7651,93.82591,0,6000,"Ancestral Spirit Wolf"), --

(17077,10,-18.672201,3822.212,89.946106,0,0,"Ancestral Spirit Wolf"),
(17077,11,-15.436849,3839.5933,86.010345,0,0,"Ancestral Spirit Wolf"),
(17077,12,-13.511067,3869.3118,83.18117,0,0,"Ancestral Spirit Wolf"),
(17077,13,-10.554254,3882.9075,83.18117,0,0,"Ancestral Spirit Wolf"),
(17077,14,-3.270291,3897.9458,85.43117,0,0,"Ancestral Spirit Wolf"),
(17077,15,5.854601,3906.4575,86.36614,0,0,"Ancestral Spirit Wolf"),
(17077,16,21.961697,3917.6707,85.24114,0,0,"Ancestral Spirit Wolf"),
(17077,17,40.73991,3927.2727,84.03038,0,0,"Ancestral Spirit Wolf"),
(17077,18,60.198025,3935.109,81.423935,0,0,"Ancestral Spirit Wolf"),
(17077,19,88.06445,3943.124,77.16091,0,0,"Ancestral Spirit Wolf"),
(17077,20,116.48167,3942.2288,77.71034,0,0,"Ancestral Spirit Wolf"),
(17077,21,140.60602,3938.9385,81.55002,0,0,"Ancestral Spirit Wolf"),
(17077,22,171.98372,3938.8472,79.65354,0,0,"Ancestral Spirit Wolf"),
(17077,23,192.11057,3941.6697,76.27854,0,0,"Ancestral Spirit Wolf"),
(17077,24,210.7275,3945.3862,74.492744,0,0,"Ancestral Spirit Wolf"),
(17077,25,229.317,3953.9805,73.117744,0,0,"Ancestral Spirit Wolf"),
(17077,26,240.94531,3959.795,75.06353,0,0,"Ancestral Spirit Wolf"),
(17077,27,252.27155,3963.4895,76.93853,0,0,"Ancestral Spirit Wolf"),
(17077,28,273.8889,3978.8838,85.78987,0,0,"Ancestral Spirit Wolf"),
(17077,29,290.13867,3990.5635,91.66487,0,0,"Ancestral Spirit Wolf"),
(17077,30,320.1014,4005.4385,98.469826,0,0,"Ancestral Spirit Wolf"),
(17077,31,338.62778,4002.79,104.993286,0,0,"Ancestral Spirit Wolf"),
(17077,32,343.4465,3997.1423,109.36144,0,0,"Ancestral Spirit Wolf"),
(17077,33,348.71088,3984.7383,115.98644,0,0,"Ancestral Spirit Wolf"),
(17077,34,361.33035,3961.4485,123.48554,0,0,"Ancestral Spirit Wolf"),
(17077,35,356.76953,3949.619,126.98554,0,0,"Ancestral Spirit Wolf"),
(17077,36,346.75836,3922.0083,133.68163,0,0,"Ancestral Spirit Wolf"),
(17077,37,347.1215,3899.5994,137.84831,0,0,"Ancestral Spirit Wolf"),
(17077,38,347.1963,3880.4836,142.84831,0,0,"Ancestral Spirit Wolf"),
(17077,39,337.12424,3856.1204,149.44649,0,0,"Ancestral Spirit Wolf"),
(17077,40,331.16196,3842.576,153.38467,0,0,"Ancestral Spirit Wolf"),
(17077,41,320.0521,3829.007,159.86176,0,0,"Ancestral Spirit Wolf"),
(17077,42,313.16516,3826.182,160.61176,0,0,"Ancestral Spirit Wolf"),
(17077,43,303.0879,3819.6777,163.98676,0,0,"Ancestral Spirit Wolf"),
(17077,44,297.51276,3816.4011,165.62602,0,0,"Ancestral Spirit Wolf"),
(17077,45,290.74023,3806.499,169.62602,0,0,"Ancestral Spirit Wolf"),
(17077,46,285.93805,3794.88,174.97627,0,0,"Ancestral Spirit Wolf"),
(17077,47,292.22098,3781.1619,181.85127,0,0,"Ancestral Spirit Wolf"),
(17077,48,296.92133,3770.8481,185.10127,0,0,"Ancestral Spirit Wolf"),
(17077,49,311.4395,3753.1104,184.11917,0,0,"Ancestral Spirit Wolf"),
(17077,50,321.36182,3741.0325,184.36917,0,0,"Ancestral Spirit Wolf"),
(17077,51,332.90778,3728.5825,184.65353,0,0,"Ancestral Spirit Wolf"),
(17077,52,337.21378,3720.4072,184.01471,0,0,"Ancestral Spirit Wolf"),
(17077,53,344.8604,3715.015,184.01471,0,0,"Ancestral Spirit Wolf"),
(17077,54,358.15982,3716.5864,184.01471,0,0,"Ancestral Spirit Wolf"),
(17077,55,366.21744,3719.898,184.01471,0,0,"Ancestral Spirit Wolf"),
(17077,56,374.8206,3724.2727,184.15353,0,0,"Ancestral Spirit Wolf"),
(17077,57,403.90103,3737.9128,180.65353,0,0,"Ancestral Spirit Wolf"),
(17077,58,421.35953,3750.1697,184.40353,0,0,"Ancestral Spirit Wolf"),
(17077,59,448.62393,3768.8801,186.51082,0,0,"Ancestral Spirit Wolf"),
(17077,60,462.85294,3776.5051,186.38582,0,0,"Ancestral Spirit Wolf"),
(17077,61,472.87814,3791.1094,187.16379,0,0,"Ancestral Spirit Wolf"),
(17077,62,484.18484,3809.1467,188.67741,0,0,"Ancestral Spirit Wolf"),
(17077,63,495.23938,3826.8103,191.55241,0,0,"Ancestral Spirit Wolf"),
(17077,64,498.87946,3837.6038,193.37997,0,0,"Ancestral Spirit Wolf"),
(17077,65,500.95297,3849.591,194.49019,0,0,"Ancestral Spirit Wolf"),
(17077,66,505.95724,3862.4604,194.36519,0,0,"Ancestral Spirit Wolf"),
(17077,67,511.11978,3869.2805,192.93457,0,0,"Ancestral Spirit Wolf"),
(17077,68,518.094,3877.0725,191.80957,0,0,"Ancestral Spirit Wolf"), --
(17077,69,521.2715,3882.2812,190.93457,0,0,"Ancestral Spirit Wolf"),
(17077,70,526.9002,3885.513,190.05957,0,0,"Ancestral Spirit Wolf"),
(17077,71,527.0562,3891.684,189.05957,0,0,"Ancestral Spirit Wolf"),
(17077,72,521.69653,3890.5703,189.55957,0,0,"Ancestral Spirit Wolf"),
(17077,73,520.24036,3885.3213,190.43457,0,0,"Ancestral Spirit Wolf"), --

(17123,1,509.49414,3881.9792,191.55957,0,0,"Earthcaller Ryga"),
(17123,2,517.92773,3883.6355,190.68457,0,11000,"Earthcaller Ryga"), --
(17123,3,505.5433,3882.0378,191.3179,0,0,"Earthcaller Ryga"),
(17123,4,504.59192,3882.131,192.18457,5.79449319839477539,1,"Earthcaller Ryga");

UPDATE `creature_text` SET `Sound` = 9036 WHERE `CreatureID` = 17077 AND `GroupID` = 1;
UPDATE `creature_text` SET `comment` = "Ancestral Spirit Wolf" WHERE `CreatureID` = 17077;
UPDATE `creature_text` SET `comment` = "Earthcaller Ryga" WHERE `CreatureID` = 17123;

DELETE FROM `creature_template_movement` WHERE `CreatureId` = 17123;
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`,`Chase`,`Random`,`InteractionPauseTimer`) VALUES
(17123,1,1,0,0,0,0,0);
