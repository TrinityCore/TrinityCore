-- First quests are not repeatable
DELETE FROM `quest_template_addon` WHERE `ID` IN (7223,7224);

-- Smith Regzar SAI (Source: https://www.youtube.com/watch?v=vwtWwBraRbE)
SET @ID := 13176;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,20,0,100,0,6741,15000,15000,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,"Smith Regzar - On Quest 'More Booty!' Finished - Say Line 3"),
(@ID,0,1,0,20,0,100,0,7224,15000,15000,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,"Smith Regzar - On Quest 'Enemy Booty' Finished - Say Line 3");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"Seasoned units are taking to the field!",14,1,100,0,0,0,8754,0,"Smith Regzar"),
(@ID,1,0,"Our veterans are entering the field!",14,1,100,0,0,0,8755,0,"Smith Regzar"),
(@ID,2,0,"Our champion units are equipped!  Beware, alliance!",14,1,100,0,0,0,8756,0,"Smith Regzar"),
(@ID,3,0,"Thank you for the armor scraps, $n!",12,1,100,0,0,0,8981,0,"Smith Regzar"),
(@ID,3,1,"Our cache of equipment grows!",12,1,100,0,0,0,8982,0,"Smith Regzar");

-- Murgot Deepforge SAI (Source: https://www.youtube.com/watch?v=vwtWwBraRbE)
SET @ID := 13257;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,20,0,100,0,6781,15000,15000,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,"Murgot Deepforge - On Quest 'More Armor Scraps' Finished - Say Line 3"),
(@ID,0,1,0,20,0,100,0,7223,15000,15000,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,"Murgot Deepforge - On Quest 'Armor Scraps' Finished - Say Line 3");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"Seasoned units are entering the battle!",14,7,100,0,0,0,8744,0,"Murgot Deepforge"),
(@ID,1,0,"Veteran units are entering the battle!",14,7,100,0,0,0,8745,0,"Murgot Deepforge"),
(@ID,2,0,"Champion units are entering the battle!",14,7,100,0,0,0,8746,0,"Murgot Deepforge"),
(@ID,3,0,"Great!  Let's keep those supplies coming, people!",12,7,100,0,0,0,8975,0,"Murgot Deepforge"),
(@ID,3,1,"Thanks for the supplies, $n!",12,7,100,0,0,0,8976,0,"Murgot Deepforge");
