-- Shadowy Tormentor SAI (Source: https://www.youtube.com/watch?v=l9RY8ot26CY & https://www.youtube.com/watch?v=98p2aou5E1M)
SET @ID := 26966;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,4,0,100,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Shadowy Tormentor - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"The boy believed he could essssscape... Neither of you shall make it out alive.",12,0,100,0,0,0,26102,0,"Shadowy Tormentor"),
(@ID,0,1,"Kill ussss all... More will come for him...",12,0,100,0,0,0,26103,0,"Shadowy Tormentor"),
(@ID,0,2,"Relent! This ssssoul iss not worth sssaving...",12,0,100,0,0,0,26104,0,"Shadowy Tormentor"),
(@ID,0,3,"You have made a grave misssstake...",12,0,100,0,0,0,26105,0,"Shadowy Tormentor");
