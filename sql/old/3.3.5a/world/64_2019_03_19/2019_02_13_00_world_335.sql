-- Bartleby SAI
SET @ENTRY := 6090;
UPDATE `creature_template` SET `AIName`="SmartAI", `ScriptName`="" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,2,84,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bartleby - On Reset - Set Faction 84"),
(@ENTRY,0,1,2,19,0,100,0,1640,0,0,0,2,168,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bartleby - On Quest 'Beat Bartleby' Taken - Set Faction 168"),
(@ENTRY,0,2,6,61,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,100,0,0,0,0,0,0,"Bartleby - On Quest Taken - Start Attacking"),
(@ENTRY,0,3,0,25,0,100,0,0,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bartleby - On Reset - Set Invincibility Hp 1"),
(@ENTRY,0,4,5,2,0,100,0,0,15,0,0,15,1640,0,0,0,0,0,12,1,0,0,0,0,0,0,"Bartleby - Between 0-15% Health - Quest Credit 'Beat Bartleby'"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bartleby - Between 0-15% Health - Evade"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Bartleby - On Quest Taken - Store Targetlist");
