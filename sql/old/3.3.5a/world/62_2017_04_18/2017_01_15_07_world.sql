-- Painmistress Gabrissa -- http://wotlk.openwow.com/npc=21309
-- Painmistress Gabrissa SAI
SET @ENTRY := 21309;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,7000,20000,25000,11,38048,0,0,0,0,0,2,0,0,0,0,0,0,0,"Painmistress Gabrissa - In Combat - Cast 'Curse of Pain'"),
(@ENTRY,0,1,0,0,0,100,0,6000,7000,17000,20000,11,38169,0,0,0,0,0,2,0,0,0,0,0,0,0,"Painmistress Gabrissa - In Combat - Cast 'Subservience'"),
(@ENTRY,0,2,0,25,0,100,0,0,0,0,0,53,0,21309,1,0,0,2,0,0,0,0,0,0,0,0,"Painmistress Gabrissa - On Reset - Start Waypoint"),
(@ENTRY,0,3,0,40,0,100,0,5,21309,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Painmistress Gabrissa - On Waypoint 5 Reached - Run Script"),
(@ENTRY,0,4,5,40,0,100,0,9,21309,0,0,54,20000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Painmistress Gabrissa - On Waypoint 9 Reached - Pause Waypoint"),
(@ENTRY,0,5,0,61,0,100,0,9,21309,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.37533,"Painmistress Gabrissa - On Waypoint 9 Reached - Set Orientation 3.37533"),
(@ENTRY,0,6,0,4,0,100,0,0,0,0,0,49,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Painmistress Gabrissa - On Aggro - Start Attacking");

-- Actionlist SAI
SET @ENTRY := 2130900;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Painmistress Gabrissa - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.60702,"Painmistress Gabrissa - On Script - Set Orientation 3,60702"),
(@ENTRY,9,2,0,0,0,100,0,1000,1000,0,0,11,36578,0,0,0,0,0,10,74619,21310,0,0,0,0,0,"Painmistress Gabrissa - On Script - Cast 'Fool's Fortune'"),
(@ENTRY,9,3,0,0,0,100,0,4000,4000,0,0,92,0,36578,1,0,0,0,1,0,0,0,0,0,0,0,"Painmistress Gabrissa - On Script - Interrupt Spell 'Fool's Fortune'");

DELETE FROM `waypoints` WHERE `entry`=21309;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(21309, 1, -3697.1, 2669.77,  107.186, 'Painmistress Gabrissa'),
(21309, 2, -3697.68, 2673.34, 108.569, 'Painmistress Gabrissa'),
(21309, 3, -3692.22, 2678.74, 108.66,  'Painmistress Gabrissa'),
(21309, 4, -3690.04, 2682.79, 108.752, 'Painmistress Gabrissa'),
(21309, 5, -3692.89, 2684.18, 108.485, 'Painmistress Gabrissa'),
(21309, 6, -3690.92, 2682.03, 108.744, 'Painmistress Gabrissa'),
(21309, 7, -3694.07, 2677.51, 108.537, 'Painmistress Gabrissa'),
(21309, 8, -3697.53, 2673.77, 108.581, 'Painmistress Gabrissa'),
(21309, 9, -3693.46, 2668.44, 107.174, 'Painmistress Gabrissa');
