-- Freed Sha'tar Warrior
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|768, `AIName`="SmartAI" WHERE `entry`=22459;
DELETE FROM `smart_scripts` WHERE `entryorguid`=22459 AND `source_type`=0; 
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2245900) AND `source_type`=9; 
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`)VALUES 
(22459,0,0,0,54,0,100,0,0,0,0,0,80,2245900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Freed Sha'tar Warrior - On Just sumoned - Run Script"),
(2245900,9,0,0,0,0,100,0,2000,2000,0,0,66,0,0,0,0,0,0,21,50,0,0,0,0,0,0,"Freed Sha'tar Warrior - On Script - Set Orientation"),
(2245900,9,1,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Freed Sha'tar Warrior - On Script - Say One Line from group 1"),
(2245900,9,2,0,0,0,100,0,5000,5000,0,0,69,1,0,0,0,0,0,8,0,0,0,-3801.0559,4318.7333,5.0761,0,"Freed Sha'tar Warrior - On Script - Move To Position"),
(22459,0,1,0,34,0,100,0,0,1,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Freed Sha'tar Warrior - On movement informer - despawn");

DELETE FROM `creature_text` WHERE `CreatureID`=22459; 
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(22459,1,0,"Praise the naaru, I'm saved. I will try to make it clear on my own.",12,7,100,5,0,0,20143,0,"Freed Sha'tar Warrior"), 
(22459,1,1,"I'm hurt, but I can still run. Thank you, stranger.",12,7,100,5,0,0,20144,0,"Freed Sha'tar Warrior"), 
(22459,1,2,"My thanks, stranger.",12,7,100,5,0,0,20145,0,"Freed Sha'tar Warrior"),  
(22459,1,3,"I'm too weak to fight with you.  Please find my friends.",12,7,100,5,0,0,20146,0,"Freed Sha'tar Warrior"); 
