-- Arakkoa Egg SAI (Source: ACID)
SET @ID := 20214;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,11,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Arakkoa Egg - On Respawn - Set Reactstate Passive"),
(@ID,0,1,0,6,0,100,0,0,0,0,0,0,11,35788,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Arakkoa Egg - On Death - Cast 'Arakkoa Egg Debuff'");
