-- Thundris Windweaver should give players a "Mark of the Wild" buff when "Tools of the Highborne" is rewarded.

-- Add SmartAI to creature template
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3649;

-- Thundris Windweaver Scripts
DELETE FROM `smart_scripts` WHERE `entryorguid`=3649 AND `event_type`=20;
DELETE FROM `smart_scripts` WHERE `entryorguid`=364900 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(3649,0,0,0,20,0,100,0,958,0,0,0,0,80,364900,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Thundris Windweaver - On Quest 'Tools of the Highborne' Completed - Run Script"),

-- Timed List 1
(364900,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Thundris Windweaver - On Script - Set Orientation Invoker"),
(364900,9,1,0,0,0,100,0,0,0,0,0,0,11,1126,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Thundris Windweaver - On Script - Cast 'Mark of the Wild'"),
(364900,9,2,0,0,0,100,0,2000,2000,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Thundris Windweaver - On Script - Set Orientation Home Position");
