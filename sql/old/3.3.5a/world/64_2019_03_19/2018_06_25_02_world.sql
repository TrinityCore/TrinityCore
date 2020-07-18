-- Sand Gnome
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=22483; 
DELETE FROM `smart_scripts` WHERE `entryorguid`=22483 AND `source_type`=0; 
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`)VALUES 
(22483,0,0,0,54,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sand Gnome - On Just summoned - Say One Line from group 0");

DELETE FROM `creature_text` WHERE `CreatureID`=22483; 
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(22483,0,0,"AAAAEEEEEEIIIIIIII!!!!",12,7,100,5,0,0,20308,0,"Sand Gnome"),
(22483,0,1,"AHHHH-YAAA-YAAA-YAAA!!!",12,7,100,5,0,0,20309,0,"Sand Gnome"),
(22483,0,2,"AWOOOOGAAAA!",12,7,100,5,0,0,20310,0,"Sand Gnome"),
(22483,0,3,"AYYAYAAYAA!",12,7,100,5,0,0,20311,0,"Sand Gnome");
