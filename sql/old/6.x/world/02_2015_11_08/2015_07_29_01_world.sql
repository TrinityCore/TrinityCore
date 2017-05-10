-- 
-- Durotar Movement + Emotes
-- Burg Tiragarde
DELETE FROM `creature` WHERE `guid`=309653;
SET @NPC := 309658;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-247.4271,`position_y`=-5115.192,`position_z`=42.78535 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-247.4271,-5115.192,42.78535,0,0,0,0,100,0),
(@PATH,2,-247.1771,-5112.692,42.03535,0,0,0,0,100,0),
(@PATH,3,-247.1771,-5104.942,41.78535,0,0,0,0,100,0),
(@PATH,4,-246.6771,-5097.692,41.78535,0,0,0,0,100,0),
(@PATH,5,-249.1591,-5081.185,24.25504,0,0,0,0,100,0),
(@PATH,6,-249.4091,-5077.685,24.25504,0,0,0,0,100,0),
(@PATH,7,-246.2748,-5094.252,41.5968,0,0,0,0,100,0),
(@PATH,8,-235.7748,-5094.252,41.5968,0,0,0,0,100,0),
(@PATH,9,-233.5248,-5094.252,41.5968,0,0,0,0,100,0),
(@PATH,10,-230.816,-5094.397,41.3468,4.694936,5000,0,0,100,0),
(@PATH,11,-233.9653,-5095.188,41.59679,0,0,0,0,100,0),
(@PATH,12,-235.4653,-5095.688,41.59679,0,0,0,0,100,0),
(@PATH,13,-236.2153,-5096.188,41.59679,0,0,0,0,100,0),
(@PATH,14,-236.9653,-5096.938,41.59679,0,0,0,0,100,0),
(@PATH,15,-242.4653,-5101.938,41.59679,0,0,0,0,100,0),
(@PATH,16,-246.4653,-5105.438,41.59679,0,0,0,0,100,0),
(@PATH,17,-246.6247,-5105.591,41.7437,0,0,0,0,100,0),
(@PATH,18,-247.3747,-5106.591,41.7437,0,0,0,0,100,0),
(@PATH,19,-247.3747,-5111.841,41.7437,0,0,0,0,100,0),
(@PATH,20,-247.3747,-5114.341,42.7437,0,0,0,0,100,0);

-- Lieutenant Palliter SAI
SET @ENTRY := 39269;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,2000,2000,16000,18000,5,23,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lieutenant Palliter - Out of Combat - Play Emote 23"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,79733,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lieutenant Palliter - On Aggro - Cast 'Commanding Shout'"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lieutenant Palliter - On Aggro - Say Line 0"),
(@ENTRY,0,3,0,0,0,100,0,100,100,10000,10000,11,78894,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lieutenant Palliter - In Combat - Cast 'Leaping Cleave'"),
(@ENTRY,0,4,0,0,0,100,0,4000,5000,12000,14000,11,79732,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lieutenant Palliter - In Combat - Cast 'Shield Bash'");

DELETE FROM `creature_text` WHERE `entry`=39269;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
(39269, 0, 0, 'Tiragarde belongs to Northwatch now!', 12, 0, 100, 0, 0, 0, 39476, 'Lieutenant Palliter');

-- Shootemotestate
DELETE FROM `creature_addon` WHERE `guid` IN (309657, 309641, 309675,309745,309748);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(309657,0,0,0,1,0, '73911'),
(309641,0,0,0,1,0, '73911'),
(309675,0,0,0,1,0, '73911'),
(309745,0,0,0,1,0, '73911'),
(309748,0,0,0,1,0, '73911');

-- deathemote
DELETE FROM `creature_template_addon` WHERE `entry`=39270;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(39270,0,0,0,1,0, '75511');

-- Injured Razor Hill Grunt SAI
SET @ENTRY := 39270;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,2000,5000,6000,25000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Injured Razor Hill Grunt - Out of Combat - Say Line 0");

DELETE FROM `creature_text` WHERE `entry`=39270;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
(39270, 0, 0, 'H-help me!', 12, 0, 100, 0, 0, 0, 39329, 'Injured Razor Hill Grunt'),
(39270, 0, 1, 'I can''t fight any longer...', 12, 0, 100, 0, 0, 0, 39330, 'Injured Razor Hill Grunt'),
(39270, 0, 2, 'I''ll never see my wife again...', 12, 0, 100, 0, 0, 0, 39328, 'Injured Razor Hill Grunt'),
(39270, 0, 3, 'Somebody... anybody...', 12, 0, 100, 0, 0, 0, 39327, 'Injured Razor Hill Grunt');

UPDATE `creature` SET `spawndist`=5, `MovementType`=1 WHERE `id` IN (39267,39268) AND `guid` NOT IN (309657, 309641, 309675,309745,309748);
UPDATE `creature` SET `spawndist`=10, `MovementType`=1 WHERE  `id`=39272;
UPDATE `creature` SET `spawndist`=7, `MovementType`=1 WHERE  `guid` In (310278, 310285,310327,309861,309860,309864,309881,309872,309873);

-- dancescript
-- Un'Thuwa SAI
SET @ENTRY := 5880;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,21000,21000,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Un'Thuwa - Out of Combat - Run Script");

-- Actionlist SAI
SET @ENTRY := 588000;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,17,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 10"),
(@ENTRY,9,1,0,0,0,100,0,10000,10000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 0");

-- Castemotes
DELETE FROM `creature_addon` WHERE `guid` IN (308230, 308231,308366);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(308230,0,0,0,1,468, ''),
(308231,0,0,0,1,468, ''),
(308366,0,0,0,1,468, '');

UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE `guid` IN (308230, 308231,308366);

UPDATE `creature` SET `spawndist`=8, `MovementType`=1 WHERE  `id` IN (3099, 3126, 3114, 3113,39452,39452,5823,3127,3100,3123,3107,43331);
UPDATE `creature` SET `spawndist`=5, `MovementType`=1 WHERE  `id` IN (3112, 3111,40948,3108,3116,3115,39603);
UPDATE `creature` SET `spawndist`=3, `MovementType`=1 WHERE  `id` IN (42504, 42859, 10685,3198,3197);
UPDATE `creature` SET `spawndist`=2, `MovementType`=1 WHERE  `id` IN (5900,3118,3117);
UPDATE `creature` SET `spawndist`=10, `MovementType`=1 WHERE  `id` IN (3122);

DELETE FROM `creature_template_addon` WHERE `entry` IN (39595, 39596);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(39595,0,0,0,1,35, ''),
(39596,0,0,0,1,35, '');

UPDATE `creature_template_addon` SET `bytes2`=0 WHERE  `entry`=10685;

DELETE FROM `creature_addon` WHERE `guid` IN (310680,310678,310682,310716,310717,310718,310713,310712,310709,310715,310728,310714,310726,310724,310725,310735,310756,310749,310759,310763,310767,310767,310768,310769,310478, 310479, 310480, 310498,310472,310471,310474,310484,310492,310476,310790,310788,310787,310786,310792);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(310478,0,0,0,1,69, ''),
(310479,0,0,0,1,0, ''),
(310480,0,0,0,1,0, '78677'),
(310498,0,0,0,1,0, '78677'),
(310472,0,0,0,1,69, ''),
(310471,0,0,8,1,0, ''),
(310474,0,0,0,1,69, ''),
(310484,0,0,0,1,0, '78677'),
(310492,0,0,0,1,69, ''),
(310476,0,0,0,1,69, ''),
(310790,0,0,8,1,0, ''),
(310788,0,0,8,1,0, ''),
(310787,0,0,0,1,69, ''),
(310786,0,0,0,1,69, ''),
(310792,0,0,0,1,69, ''),
(310769,0,0,0,1,69, ''),
(310768,0,0,8,1,0, ''),
(310767,0,0,0,1,69, ''),
(310763,0,0,0,1,69, ''),
(310759,0,0,0,1,69, ''),
(310749,0,0,0,1,69, ''),
(310756,0,0,8,1,0, ''),
(310735,0,0,8,1,0, ''),
(310725,0,0,8,1,0, ''),
(310724,0,0,8,1,0, ''),
(310726,0,0,0,1,69, ''),
(310714,0,0,0,1,69, ''),
(310728,0,0,0,1,69, ''),
(310715,0,0,8,1,0, ''),
(310709,0,0,0,1,69, ''),
(310712,0,0,0,1,69, ''),
(310713,0,0,8,1,0, ''),
(310716,0,0,8,1,0, ''),
(310718,0,0,0,1,69, ''),
(310717,0,0,0,1,69, ''),
(310682,0,0,0,1,69, ''),
(310678,0,0,0,1,69, ''),
(310680,0,0,0,1,69, '');

UPDATE `creature` SET `position_y`=-4689.793, `position_z`=6.615, `orientation`=0.507, `position_x`=1467.133789 WHERE  `guid`=310652;

-- Chains
UPDATE `creature_template` SET `flags_extra`=128 WHERE  `entry`=39519;
-- Cosmetic Trigger - PRK SAI
SET @GUID := -310585;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=39519;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,1000,1000,10000,10000,11,73964,0,0,0,0,0,19,39352,20,0,0,0,0,0,"Cosmetic Trigger - PRK - Out of Combat - Cast 'Cosmetic Chains'");

-- Cosmetic Trigger - PRK SAI
SET @GUID := -310589;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=39519;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,1000,1000,10000,10000,11,73964,0,0,0,0,0,19,39352,20,0,0,0,0,0,"Cosmetic Trigger - PRK - Out of Combat - Cast 'Cosmetic Chains'");

-- Cosmetic Trigger - PRK SAI
SET @GUID := -310584;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=39519;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,1000,1000,10000,10000,11,73964,0,0,0,0,0,19,39352,20,0,0,0,0,0,"Cosmetic Trigger - PRK - Out of Combat - Cast 'Cosmetic Chains'");

-- Cosmetic Trigger - PRK SAI
SET @GUID := -310587;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=39519;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,1000,1000,10000,10000,11,73964,0,0,0,0,0,19,39353,20,0,0,0,0,0,"Cosmetic Trigger - PRK - Out of Combat - Cast 'Cosmetic Chains'");

-- Cosmetic Trigger - PRK SAI
SET @GUID := -310591;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=39519;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,1000,1000,10000,10000,11,73964,0,0,0,0,0,19,39353,20,0,0,0,0,0,"Cosmetic Trigger - PRK - Out of Combat - Cast 'Cosmetic Chains'");

-- Cosmetic Trigger - PRK SAI
SET @GUID := -310402;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=39519;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,1000,1000,10000,10000,11,73964,0,0,0,0,0,19,39351,20,0,0,0,0,0,"Cosmetic Trigger - PRK - Out of Combat - Cast 'Cosmetic Chains'");

SET @NPC := 310117;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=688.5805,`position_y`=-3873.436,`position_z`=20.99528 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,688.5805,-3873.436,20.99528,0,0,0,0,100,0),
(@PATH,2,701.0805,-3866.936,21.74528,0,0,0,0,100,0),
(@PATH,3,714.0805,-3860.186,21.24528,0,0,0,0,100,0),
(@PATH,4,721.312,-3855.96,21.19275,0,0,0,0,100,0),
(@PATH,5,753.2512,-3836.458,21.41983,0,0,0,0,100,0),
(@PATH,6,768.1808,-3838.11,21.08494,0,0,0,0,100,0),
(@PATH,7,779.3486,-3853.463,21.12897,0,0,0,0,100,0),
(@PATH,8,781.3132,-3853.895,21.12897,0,0,0,0,100,0),
(@PATH,9,779.7146,-3852.905,21.12897,0,0,0,0,100,0),
(@PATH,10,780.6881,-3853.7,21.12897,0,0,0,0,100,0),
(@PATH,11,781.185,-3853.387,21.12897,0,0,0,0,100,0),
(@PATH,12,780.8164,-3853.961,21.12897,0,0,0,0,100,0),
(@PATH,13,781.1316,-3853.759,21.12897,0,0,0,0,100,0),
(@PATH,14,780.6812,-3853.942,21.12897,0,0,0,0,100,0),
(@PATH,15,780.7207,-3854.518,21.00397,0,0,0,0,100,0),
(@PATH,16,779.6035,-3852.928,21.12897,0,0,0,0,100,0),
(@PATH,17,780.5703,-3852.916,21.12897,0,0,0,0,100,0),
(@PATH,18,780.6561,-3853.597,21.12897,0,0,0,0,100,0),
(@PATH,19,780.1292,-3852.995,21.12897,0,0,0,0,100,0),
(@PATH,20,780.8076,-3852.75,21.12897,0,0,0,0,100,0),
(@PATH,21,779.7412,-3853.83,21.12897,0,0,0,0,100,0),
(@PATH,22,780.5329,-3853.471,21.12897,0,0,0,0,100,0),
(@PATH,23,780.4874,-3853.844,21.12897,0,0,0,0,100,0),
(@PATH,24,780.5801,-3852.711,21.12897,0,0,0,0,100,0),
(@PATH,25,768.6416,-3847.647,21.8934,0,0,0,0,100,0),
(@PATH,26,743.6416,-3837.647,21.3934,0,0,0,0,100,0),
(@PATH,27,738.1416,-3835.397,20.6434,0,0,0,0,100,0),
(@PATH,28,729.8916,-3831.897,20.3934,0,0,0,0,100,0),
(@PATH,29,721.3081,-3828.523,20.46003,0,0,0,0,100,0),
(@PATH,30,717.0581,-3831.523,21.21003,0,0,0,0,100,0),
(@PATH,31,713.0581,-3834.523,21.71003,0,0,0,0,100,0),
(@PATH,32,708.5581,-3838.023,22.21003,0,0,0,0,100,0),
(@PATH,33,691.8359,-3850.236,22.41916,0,0,0,0,100,0),
(@PATH,34,687.3359,-3854.236,23.16916,0,0,0,0,100,0),
(@PATH,35,682.3359,-3858.736,24.41916,0,0,0,0,100,0),
(@PATH,36,681.5859,-3859.236,22.66916,0,0,0,0,100,0),
(@PATH,37,680.8359,-3859.986,23.91916,0,0,0,0,100,0),
(@PATH,38,679.3359,-3861.236,25.66916,0,0,0,0,100,0),
(@PATH,39,678.5859,-3861.736,24.16916,0,0,0,0,100,0),
(@PATH,40,677.0859,-3863.236,25.16916,0,0,0,0,100,0),
(@PATH,41,676.3359,-3863.736,23.66916,0,0,0,0,100,0),
(@PATH,42,674.0859,-3865.736,21.91916,0,0,0,0,100,0),
(@PATH,43,671.8359,-3867.736,21.66916,0,0,0,0,100,0),
(@PATH,44,671.6001,-3867.693,21.40687,0,0,0,0,100,0),
(@PATH,45,668.3501,-3870.693,21.65687,0,0,0,0,100,0),
(@PATH,46,652.8501,-3867.943,21.15687,0,0,0,0,100,0),
(@PATH,47,635.9583,-3864.717,21.56643,0,0,0,0,100,0),
(@PATH,48,638.9583,-3852.467,22.06643,0,0,0,0,100,0),
(@PATH,49,642.6121,-3843.297,22.0536,0,0,0,0,100,0),
(@PATH,50,641.5416,-3842.151,22.1786,0,0,0,0,100,0);

-- Razormane Grounds
SET @NPC := 308240;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=79.98973,`position_y`=-4636.818,`position_z`=39.59395 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,79.98973,-4636.818,39.59395,0,0,0,0,100,0),
(@PATH,2,78.48973,-4634.318,40.34395,0,0,0,0,100,0),
(@PATH,3,77.73973,-4632.568,41.09395,0,0,0,0,100,0),
(@PATH,4,76.98973,-4630.568,41.84395,0,0,0,0,100,0),
(@PATH,5,76.23973,-4628.818,42.84395,0,0,0,0,100,0),
(@PATH,6,75.23973,-4626.068,43.34395,0,0,0,0,100,0),
(@PATH,7,74.73973,-4624.318,44.09395,0,0,0,0,100,0),
(@PATH,8,73.98973,-4622.568,44.84395,0,0,0,0,100,0),
(@PATH,9,73.23973,-4620.568,45.34395,0,0,0,0,100,0),
(@PATH,10,72.23973,-4617.818,46.09395,0,0,0,0,100,0),
(@PATH,11,71.48973,-4616.068,46.59395,0,0,0,0,100,0),
(@PATH,12,70.23973,-4613.318,47.59395,0,0,0,0,100,0),
(@PATH,13,70.34749,-4613.038,47.87812,0,0,0,0,100,0),
(@PATH,14,69.34749,-4610.288,48.37812,0,0,0,0,100,0),
(@PATH,15,69.84749,-4608.538,49.12812,0,0,0,0,100,0),
(@PATH,16,70.34749,-4606.538,49.87812,0,0,0,0,100,0),
(@PATH,17,71.09749,-4604.538,50.37812,0,0,0,0,100,0),
(@PATH,18,71.59749,-4602.788,51.37812,0,0,0,0,100,0),
(@PATH,19,72.34749,-4599.788,52.12812,0,0,0,0,100,0),
(@PATH,20,73.09749,-4598.288,52.87812,0,0,0,0,100,0),
(@PATH,21,73.59749,-4596.288,53.87812,0,0,0,0,100,0),
(@PATH,22,73.84749,-4594.288,54.62812,0,0,0,0,100,0),
(@PATH,23,74.59749,-4592.538,55.37812,0,0,0,0,100,0),
(@PATH,24,75.34749,-4589.538,56.12812,0,0,0,0,100,0),
(@PATH,25,77.05266,-4584.726,56.92693,0,0,0,0,100,0),
(@PATH,26,77.30266,-4572.726,56.17693,0,0,0,0,100,0),
(@PATH,27,77.80266,-4566.976,55.92693,0,0,0,0,100,0),
(@PATH,28,78.3463,-4552.961,56.39515,0,0,0,0,100,0),
(@PATH,29,78.3463,-4549.961,56.89515,0,0,0,0,100,0),
(@PATH,30,78.0963,-4547.961,57.39515,0,0,0,0,100,0),
(@PATH,31,78.0963,-4545.961,58.64515,0,0,0,0,100,0),
(@PATH,32,78.0963,-4544.211,59.14515,0,0,0,0,100,0),
(@PATH,33,77.8463,-4541.211,59.89515,0,0,0,0,100,0),
(@PATH,34,77.8463,-4539.211,60.64515,0,0,0,0,100,0),
(@PATH,35,77.8463,-4537.211,61.39515,0,0,0,0,100,0),
(@PATH,36,78.0322,-4545.204,58.6748,0,0,0,0,100,0),
(@PATH,37,77.9944,-4541.933,60.08129,0,0,0,0,100,0),
(@PATH,38,77.7444,-4539.183,60.83129,0,0,0,0,100,0),
(@PATH,39,77.7444,-4537.183,61.33129,0,0,0,0,100,0),
(@PATH,40,77.47198,-4533.455,61.68798,0,0,0,0,100,0),
(@PATH,41,77.47198,-4528.455,60.93798,0,0,0,0,100,0),
(@PATH,42,77.47198,-4526.455,60.18798,0,0,0,0,100,0),
(@PATH,43,77.47198,-4524.455,59.43798,0,0,0,0,100,0),
(@PATH,44,77.47198,-4522.455,58.43798,0,0,0,0,100,0),
(@PATH,45,77.47198,-4520.455,57.43798,0,0,0,0,100,0),
(@PATH,46,77.47198,-4519.705,56.68798,0,0,0,0,100,0),
(@PATH,47,77.47198,-4518.705,56.18798,0,0,0,0,100,0),
(@PATH,48,77.47198,-4516.705,54.93798,0,0,0,0,100,0),
(@PATH,49,77.47198,-4514.705,54.43798,0,0,0,0,100,0),
(@PATH,50,77.47198,-4513.705,53.93798,0,0,0,0,100,0),
(@PATH,51,77.47198,-4511.705,52.93798,0,0,0,0,100,0),
(@PATH,52,77.47198,-4510.705,52.18798,0,0,0,0,100,0),
(@PATH,53,77.47198,-4508.705,51.68798,0,0,0,0,100,0),
(@PATH,54,77.47198,-4506.705,50.68798,0,0,0,0,100,0),
(@PATH,55,77.47198,-4504.705,49.93798,0,0,0,0,100,0),
(@PATH,56,77.60263,-4504.445,49.59322,0,0,0,0,100,0),
(@PATH,57,77.60263,-4502.695,48.84322,0,0,0,0,100,0),
(@PATH,58,77.85263,-4500.695,47.59322,0,0,0,0,100,0),
(@PATH,59,78.10263,-4499.695,46.84322,0,0,0,0,100,0),
(@PATH,60,78.35263,-4497.695,46.09322,0,0,0,0,100,0),
(@PATH,61,78.35263,-4496.695,45.34322,0,0,0,0,100,0),
(@PATH,62,78.60263,-4494.695,44.34322,0,0,0,0,100,0),
(@PATH,63,78.85263,-4493.695,43.84322,0,0,0,0,100,0),
(@PATH,64,79.10263,-4491.945,42.84322,0,0,0,0,100,0),
(@PATH,65,79.10263,-4489.945,41.59322,0,0,0,0,100,0),
(@PATH,66,79.35263,-4488.195,40.34322,0,0,0,0,100,0),
(@PATH,67,79.85263,-4486.195,39.59322,0,0,0,0,100,0),
(@PATH,68,80.10263,-4484.195,39.09322,0,0,0,0,100,0),
(@PATH,69,80.35263,-4482.195,38.34322,0,0,0,0,100,0),
(@PATH,70,82.90936,-4479.622,37.11091,0,0,0,0,100,0),
(@PATH,71,83.65936,-4479.122,36.86091,0,0,0,0,100,0),
(@PATH,72,86.65936,-4478.872,36.36091,0,0,0,0,100,0),
(@PATH,73,90.40936,-4478.372,35.61091,0,0,0,0,100,0),
(@PATH,74,92.40936,-4478.122,35.11091,0,0,0,0,100,0),
(@PATH,75,96.40936,-4477.622,34.36091,0,0,0,0,100,0),
(@PATH,76,100.1594,-4477.122,33.86091,0,0,0,0,100,0),
(@PATH,77,104.1594,-4477.122,33.36091,0,0,0,0,100,0),
(@PATH,78,108.4094,-4477.122,32.61091,0,0,0,0,100,0),
(@PATH,79,110.6594,-4480.622,33.36091,0,0,0,0,100,0),
(@PATH,80,112.1594,-4483.372,33.86091,0,0,0,0,100,0),
(@PATH,81,116.9094,-4485.372,33.86091,0,0,0,0,100,0),
(@PATH,82,120.9094,-4486.372,33.36091,0,0,0,0,100,0),
(@PATH,83,125.1594,-4487.622,33.36091,0,0,0,0,100,0),
(@PATH,84,127.9094,-4488.122,32.61091,0,0,0,0,100,0),
(@PATH,85,132.6594,-4489.372,31.86091,0,0,0,0,100,0),
(@PATH,86,133.4094,-4489.622,32.11091,0,0,0,0,100,0),
(@PATH,87,136.4094,-4489.622,31.61091,0,0,0,0,100,0),
(@PATH,88,137.4094,-4489.622,31.36091,0,0,0,0,100,0),
(@PATH,89,139.4094,-4489.622,30.61091,0,0,0,0,100,0),
(@PATH,90,141.6594,-4489.622,30.36091,0,0,0,0,100,0),
(@PATH,91,145.6594,-4489.622,29.61091,0,0,0,0,100,0),
(@PATH,92,149.9094,-4489.622,28.86091,0,0,0,0,100,0),
(@PATH,93,162.4094,-4499.872,28.36091,0,0,0,0,100,0),
(@PATH,94,166.6594,-4503.872,28.36091,0,0,0,0,100,0),
(@PATH,95,168.6594,-4503.622,27.61091,0,0,0,0,100,0),
(@PATH,96,171.6594,-4503.372,26.86091,0,0,0,0,100,0),
(@PATH,97,171.9954,-4503.409,26.60199,0,0,0,0,100,0),
(@PATH,98,173.7454,-4503.159,26.10199,0,0,0,0,100,0),
(@PATH,99,175.2454,-4504.159,25.85199,0,0,0,0,100,0),
(@PATH,100,177.2454,-4504.159,25.10199,0,0,0,0,100,0),
(@PATH,101,180.2454,-4504.159,24.60199,0,0,0,0,100,0),
(@PATH,102,183.2454,-4504.159,24.35199,0,0,0,0,100,0),
(@PATH,103,188.9954,-4509.909,23.60199,0,0,0,0,100,0),
(@PATH,104,193.2454,-4514.159,23.10199,0,0,0,0,100,0),
(@PATH,105,195.7454,-4516.659,22.60199,0,0,0,0,100,0),
(@PATH,106,194.7454,-4524.659,23.10199,0,0,0,0,100,0),
(@PATH,107,194.7454,-4526.909,23.10199,0,0,0,0,100,0),
(@PATH,108,194.7454,-4528.909,23.10199,0,0,0,0,100,0),
(@PATH,109,194.9398,-4529.146,22.84127,0,0,0,0,100,0),
(@PATH,110,194.9398,-4531.146,22.84127,0,0,0,0,100,0),
(@PATH,111,195.9398,-4545.146,23.34127,0,0,0,0,100,0),
(@PATH,112,197.475,-4570.42,23.57046,0,0,0,0,100,0),
(@PATH,113,195.225,-4575.92,24.07046,0,0,0,0,100,0),
(@PATH,114,193.725,-4579.67,25.07046,0,0,0,0,100,0),
(@PATH,115,190.225,-4587.67,25.57046,0,0,0,0,100,0),
(@PATH,116,187.725,-4594.17,26.07046,0,0,0,0,100,0),
(@PATH,117,186.725,-4596.92,26.82046,0,0,0,0,100,0),
(@PATH,118,184.225,-4602.42,27.57046,0,0,0,0,100,0),
(@PATH,119,183.9489,-4602.694,27.43371,0,0,0,0,100,0),
(@PATH,120,182.9489,-4604.944,27.68371,0,0,0,0,100,0),
(@PATH,121,179.9489,-4608.944,28.43371,0,0,0,0,100,0),
(@PATH,122,174.6989,-4616.194,28.93371,0,0,0,0,100,0),
(@PATH,123,168.1989,-4624.694,28.43371,0,0,0,0,100,0),
(@PATH,124,165.9489,-4627.944,27.43371,0,0,0,0,100,0),
(@PATH,125,163.4489,-4631.194,26.93371,0,0,0,0,100,0),
(@PATH,126,163.4489,-4631.194,26.93371,0,0,0,0,100,0),
(@PATH,127,163.4489,-4631.194,26.93371,0,0,0,0,100,0),
(@PATH,128,160.8272,-4634.672,26.45792,0,0,0,0,100,0),
(@PATH,129,152.3272,-4639.922,25.70792,0,0,0,0,100,0),
(@PATH,130,147.3272,-4642.922,25.20792,0,0,0,0,100,0),
(@PATH,131,143.3272,-4645.672,24.45792,0,0,0,0,100,0),
(@PATH,132,132.2215,-4652.662,24.92623,0,0,0,0,100,0),
(@PATH,133,129.2215,-4652.912,25.92623,0,0,0,0,100,0),
(@PATH,134,127.2215,-4652.912,26.92623,0,0,0,0,100,0),
(@PATH,135,125.2215,-4652.912,28.17623,0,0,0,0,100,0),
(@PATH,136,124.2215,-4652.912,28.92623,0,0,0,0,100,0),
(@PATH,137,123.2215,-4652.912,29.67623,0,0,0,0,100,0),
(@PATH,138,122.2215,-4652.912,29.92623,0,0,0,0,100,0),
(@PATH,139,120.2215,-4652.912,30.92623,0,0,0,0,100,0),
(@PATH,140,119.2215,-4652.912,31.67623,0,0,0,0,100,0),
(@PATH,141,118.2215,-4652.912,32.17623,0,0,0,0,100,0),
(@PATH,142,117.2215,-4653.162,32.92623,0,0,0,0,100,0),
(@PATH,143,115.2215,-4653.162,33.67623,0,0,0,0,100,0),
(@PATH,144,113.2215,-4653.162,34.42623,0,0,0,0,100,0),
(@PATH,145,91.47154,-4654.162,34.92623,0,0,0,0,100,0),
(@PATH,146,91.29816,-4653.952,35.37938,0,0,0,0,100,0),
(@PATH,147,90.29816,-4654.202,35.37938,0,0,0,0,100,0),
(@PATH,148,87.04816,-4648.952,36.12938,0,0,0,0,100,0),
(@PATH,149,85.54816,-4646.452,36.87938,0,0,0,0,100,0),
(@PATH,150,84.29816,-4643.952,37.37938,0,0,0,0,100,0),
(@PATH,151,82.79816,-4641.452,37.87938,0,0,0,0,100,0),
(@PATH,152,81.29816,-4638.952,38.62938,0,0,0,0,100,0),
(@PATH,153,80.29816,-4637.202,39.37938,0,0,0,0,100,0);

SET @NPC := 308225;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=51.70237,`position_y`=-4472.69,`position_z`=42.80334 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,51.70237,-4472.69,42.80334,0,0,0,0,100,0),
(@PATH,2,54.45237,-4473.44,42.05334,0,0,0,0,100,0),
(@PATH,3,59.95237,-4475.19,41.55334,0,0,0,0,100,0),
(@PATH,4,60.26998,-4475.348,41.13422,0,0,0,0,100,0),
(@PATH,5,60.76998,-4475.348,41.13422,0,0,0,0,100,0),
(@PATH,6,64.51998,-4475.598,40.13422,0,0,0,0,100,0),
(@PATH,7,67.51998,-4475.598,39.63422,0,0,0,0,100,0),
(@PATH,8,71.86338,-4476.03,38.55601,0,0,0,0,100,0),
(@PATH,9,74.86338,-4476.03,38.30601,0,0,0,0,100,0),
(@PATH,10,77.61338,-4476.03,37.80601,0,0,0,0,100,0),
(@PATH,11,80.90776,-4475.785,36.80119,0,0,0,0,100,0),
(@PATH,12,82.90776,-4475.285,36.30119,0,0,0,0,100,0),
(@PATH,13,85.40776,-4474.785,35.80119,0,0,0,0,100,0),
(@PATH,14,89.40776,-4473.785,35.05119,0,0,0,0,100,0),
(@PATH,15,89.50303,-4473.408,34.80347,0,0,0,0,100,0),
(@PATH,16,90.50303,-4473.158,34.55347,0,0,0,0,100,0),
(@PATH,17,93.25303,-4471.908,33.80347,0,0,0,0,100,0),
(@PATH,18,95.50303,-4470.408,33.30347,0,0,0,0,100,0),
(@PATH,19,98.25303,-4469.158,32.80347,0,0,0,0,100,0),
(@PATH,20,101.753,-4467.408,32.05347,0,0,0,0,100,0),
(@PATH,21,103.503,-4466.408,31.55347,0,0,0,0,100,0),
(@PATH,22,103.8725,-4466.163,31.41965,0,0,0,0,100,0),
(@PATH,23,104.6225,-4465.663,31.16965,0,0,0,0,100,0),
(@PATH,24,106.3725,-4462.413,30.66965,0,0,0,0,100,0),
(@PATH,25,108.1739,-4459.26,30.06752,0,0,0,0,100,0),
(@PATH,26,106.954,-4450.881,30.1387,0,0,0,0,100,0),
(@PATH,27,102.5359,-4440.718,30.71219,0,0,0,0,100,0),
(@PATH,28,100.0359,-4439.218,31.21219,0,0,0,0,100,0),
(@PATH,29,94.7859,-4436.718,31.71219,0,0,0,0,100,0),
(@PATH,30,90.5359,-4434.468,32.21219,0,0,0,0,100,0),
(@PATH,31,90.21313,-4434.118,32.3544,0,0,0,0,100,0),
(@PATH,32,89.21313,-4433.618,32.6044,0,0,0,0,100,0),
(@PATH,33,84.46313,-4433.118,32.8544,0,0,0,0,100,0),
(@PATH,34,80.10579,-4432.497,33.57849,0,0,0,0,100,0),
(@PATH,35,77.35579,-4433.497,34.32849,0,0,0,0,100,0),
(@PATH,36,74.60579,-4434.247,34.82849,0,0,0,0,100,0),
(@PATH,37,71.85579,-4434.997,35.57849,0,0,0,0,100,0),
(@PATH,38,71.82204,-4435.326,35.58233,0,0,0,0,100,0),
(@PATH,39,70.82204,-4435.576,35.83233,0,0,0,0,100,0),
(@PATH,40,71.64928,-4444.331,36.14789,0,0,0,0,100,0),
(@PATH,41,69.89928,-4449.831,36.64789,0,0,0,0,100,0);

SET @NPC := 310174;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=490.2794,`position_y`=-4222.425,`position_z`=23.92938 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,490.2794,-4222.425,23.92938,0,0,0,0,100,0),
(@PATH,2,492.0294,-4220.675,23.92938,0,0,0,0,100,0),
(@PATH,3,494.0324,-4213.647,23.80242,0,0,0,0,100,0),
(@PATH,4,495.0324,-4210.897,24.55242,0,0,0,0,100,0),
(@PATH,5,499.0324,-4199.897,24.05242,0,0,0,0,100,0),
(@PATH,6,501.0324,-4194.397,23.30242,0,0,0,0,100,0),
(@PATH,7,502.5324,-4190.647,23.05242,0,0,0,0,100,0),
(@PATH,8,503.4245,-4187.801,22.45321,0,0,0,0,100,0),
(@PATH,9,502.0799,-4178.389,22.28867,0,0,0,0,100,0),
(@PATH,10,499.8299,-4173.139,22.03867,0,0,0,0,100,0),
(@PATH,11,499.5309,-4172.999,21.96888,0,0,0,0,100,0),
(@PATH,12,498.2809,-4169.999,21.46888,0,0,0,0,100,0),
(@PATH,13,493.7809,-4166.499,21.21888,0,0,0,0,100,0),
(@PATH,14,493.3959,-4166.228,20.89663,0,0,0,0,100,0),
(@PATH,15,492.8959,-4165.728,20.89663,0,0,0,0,100,0),
(@PATH,16,486.3959,-4164.478,19.89663,0,0,0,0,100,0),
(@PATH,17,482.3959,-4163.478,19.14663,0,0,0,0,100,0),
(@PATH,18,477.6459,-4162.478,18.64663,0,0,0,0,100,0),
(@PATH,19,477.3293,-4162.448,18.40549,0,0,0,0,100,0),
(@PATH,20,476.3293,-4162.198,18.40549,0,0,0,0,100,0),
(@PATH,21,467.304,-4162.001,18.8057,0,0,0,0,100,0),
(@PATH,22,462.804,-4163.751,19.3057,0,0,0,0,100,0),
(@PATH,23,458.7089,-4165.493,19.97128,0,0,0,0,100,0),
(@PATH,24,449.4932,-4169.094,19.40906,0,0,0,0,100,0),
(@PATH,25,441.109,-4171.364,19.6838,0,0,0,0,100,0),
(@PATH,26,436.7829,-4175.063,20.30129,0,0,0,0,100,0),
(@PATH,27,423.515,-4187.791,20.43603,0,0,0,0,100,0),
(@PATH,28,419.515,-4191.791,20.68603,0,0,0,0,100,0),
(@PATH,29,416.765,-4194.541,21.43603,0,0,0,0,100,0),
(@PATH,30,414.4492,-4196.878,21.64558,0,0,0,0,100,0),
(@PATH,31,413.1992,-4203.378,22.14558,0,0,0,0,100,0),
(@PATH,32,412.5412,-4206.537,22.0668,0,0,0,0,100,0),
(@PATH,33,413.2093,-4219.619,22.37138,0,0,0,0,100,0),
(@PATH,34,418.8591,-4227.432,22.75053,0,0,0,0,100,0),
(@PATH,35,426.4359,-4231.621,23.14396,0,0,0,0,100,0),
(@PATH,36,434.6665,-4231.938,22.78331,0,0,0,0,100,0);
