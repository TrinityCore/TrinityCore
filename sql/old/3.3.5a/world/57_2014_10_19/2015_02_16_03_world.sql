-- 
SET @CGUID := 56502; 

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=11789;
UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=-56500 AND `source_type`=0 AND `id`=0 AND `link`=2;

-- Scourge Reanimator SAI
SET @GUID := -(@CGUID+2);
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=26626;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,25,0,100,1,0,0,0,0,80,2662600,2,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Reanimator - On Reset - Run Script (No Repeat)"),
(@GUID,0,1,0,40,0,100,0,1,2662600,0,0,80,2662601,2,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Reanimator - On Waypoint 1 Reached - Run Script");

-- Drakkari Guardian SAI
SET @GUID := -(@CGUID); 
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=26620;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,1,2000,2000,0,0,69,0,0,0,0,0,0,8,0,0,0,-543.121582,-582.083313,1.025425,2.120673,"Drakkari Guardian - Out of Combat - Move To Position (No Repeat)"),
(@GUID,0,1,0,38,0,100,0,1,1,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Guardian - On Data Set 1 1 - Kill Self");

-- Drakkari Guardian SAI   
SET @GUID := -(@CGUID+1);
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=26620;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,1,2000,2000,0,0,69,0,0,0,0,0,0,8,0,0,0,-536.830505,-578.793091,1.913330,1.774444,"Drakkari Guardian - Out of Combat - Move To Position (No Repeat)"),
(@GUID,0,1,0,38,0,100,0,1,1,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Guardian - On Data Set 1 1 - Kill Self");
