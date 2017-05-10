-- Crazed Soldier SAI
SET @ENTRY := 46989;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,500,1000,21500,29500,11,81219,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crazed Soldier - In Combat - Cast 'Battle Shout'"),
(@ENTRY,0,1,0,0,0,100,0,3000,4000,10000,12000,11,79881,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crazed Soldier - In Combat - Cast 'Slam'"),
(@ENTRY,0,2,0,0,0,100,0,10500,11000,18500,23500,11,11977,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crazed Soldier - In Combat - Cast 'Rend'");
