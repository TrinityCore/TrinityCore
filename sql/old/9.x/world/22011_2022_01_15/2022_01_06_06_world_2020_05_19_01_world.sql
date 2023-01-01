-- Bogblossom Bunny SAI (Source: https://www.youtube.com/watch?v=EIFhKHtvOe0) 
SET @ENTRY := 23104;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,54,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bogblossom Bunny - On Just Summoned - Say Line 0"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,0,11,40532,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bogblossom Bunny - On Link - Cast 'Bogblossom Knockback'");

DELETE FROM `creature_text` WHERE `CreatureID` = 23104;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES 
(23104,0,0,"The bogblossom explodes, spraying pollen wildly.",16,0,100,0,0,0,20932,0,'Bogblossom Bunny');
