--
UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI", `ScriptName` = "" WHERE `entry` IN (182484,182486,182487,182488,182489,182490,182491,182492,182493,182494,182495,182496,182497,182498,182499,182500,182501,182502,182503,182504);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (182484,182486,182487,182488,182489,182490,182491,182492,182493,182494,182495,182496,182497,182498,182499,182500,182501,182502,182503,182504) AND `source_type` = 1;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 18248400 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(182484,1,0,0,70,0,100,0,2,0,0,0,0,80,18248400,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmaul Prison - On Gameobject State Changed - Run Script"),
(182486,1,0,0,70,0,100,0,2,0,0,0,0,80,18248400,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmaul Prison - On Gameobject State Changed - Run Script"),
(182487,1,0,0,70,0,100,0,2,0,0,0,0,80,18248400,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmaul Prison - On Gameobject State Changed - Run Script"),
(182488,1,0,0,70,0,100,0,2,0,0,0,0,80,18248400,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmaul Prison - On Gameobject State Changed - Run Script"),
(182489,1,0,0,70,0,100,0,2,0,0,0,0,80,18248400,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmaul Prison - On Gameobject State Changed - Run Script"),
(182490,1,0,0,70,0,100,0,2,0,0,0,0,80,18248400,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmaul Prison - On Gameobject State Changed - Run Script"),
(182491,1,0,0,70,0,100,0,2,0,0,0,0,80,18248400,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmaul Prison - On Gameobject State Changed - Run Script"),
(182492,1,0,0,70,0,100,0,2,0,0,0,0,80,18248400,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmaul Prison - On Gameobject State Changed - Run Script"),
(182493,1,0,0,70,0,100,0,2,0,0,0,0,80,18248400,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmaul Prison - On Gameobject State Changed - Run Script"),
(182494,1,0,0,70,0,100,0,2,0,0,0,0,80,18248400,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmaul Prison - On Gameobject State Changed - Run Script"),
(182495,1,0,0,70,0,100,0,2,0,0,0,0,80,18248400,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmaul Prison - On Gameobject State Changed - Run Script"),
(182496,1,0,0,70,0,100,0,2,0,0,0,0,80,18248400,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmaul Prison - On Gameobject State Changed - Run Script"),
(182497,1,0,0,70,0,100,0,2,0,0,0,0,80,18248400,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmaul Prison - On Gameobject State Changed - Run Script"),
(182498,1,0,0,70,0,100,0,2,0,0,0,0,80,18248400,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmaul Prison - On Gameobject State Changed - Run Script"),
(182499,1,0,0,70,0,100,0,2,0,0,0,0,80,18248400,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmaul Prison - On Gameobject State Changed - Run Script"),
(182500,1,0,0,70,0,100,0,2,0,0,0,0,80,18248400,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmaul Prison - On Gameobject State Changed - Run Script"),
(182501,1,0,0,70,0,100,0,2,0,0,0,0,80,18248400,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmaul Prison - On Gameobject State Changed - Run Script"),
(182502,1,0,0,70,0,100,0,2,0,0,0,0,80,18248400,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmaul Prison - On Gameobject State Changed - Run Script"),
(182503,1,0,0,70,0,100,0,2,0,0,0,0,80,18248400,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmaul Prison - On Gameobject State Changed - Run Script"),
(182504,1,0,0,70,0,100,0,2,0,0,0,0,80,18248400,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmaul Prison - On Gameobject State Changed - Run Script"),

(18248400,9,0,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Warmaul Prison - On Script - Store Targetlist"),
(18248400,9,1,0,0,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,19,18428,5,0,0,0,0,0,0,"Warmaul Prison - On Script - Send Target 1 (Mag'har Prisoner)"),
(18248400,9,2,0,0,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,19,18428,5,0,0,0,0,0,0,"Warmaul Prison - On Script - Set Data 0 1 (Mag'har Prisoner)");

-- Mag'har Prisoner SAI (Source: https://www.youtube.com/watch?v=PYuWnVJBOTI)
SET @ID := 18428;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,10,0,20,0,0,15,60000,60000,1,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Mag'har Prisoner - Within 0-15 Range Out of Combat LoS - Say Line 0"),
(@ID,0,1,2,38,0,100,0,0,1,0,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Mag'har Prisoner - On Data Set 0 1 - Say Line 1"),
(@ID,0,2,3,61,0,100,0,0,0,0,0,0,33,18428,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Mag'har Prisoner - On Link - Quest Credit 'Finding the Survivors'"),
(@ID,0,3,0,61,0,100,0,0,0,0,0,0,41,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mag'har Prisoner - On Link - Despawn (3000)");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"Help! Help! They're going to eat me!",12,0,100,0,0,0,15382,0,"Mag'har Prisoner"),
(@ID,0,1,"I'm done for!",12,0,100,0,0,0,15383,0,"Mag'har Prisoner"),
(@ID,0,2,"One day, a hero will rise and lift the orcs up to their former glory.",12,0,100,0,0,0,15384,0,"Mag'har Prisoner"),
(@ID,0,3,"The ogres have the keys! Kill the ogres and get me out of here!",12,0,100,0,0,0,15385,0,"Mag'har Prisoner"),
(@ID,0,4,"My children will be made orphans!",12,0,100,0,0,0,15386,0,"Mag'har Prisoner"),
(@ID,1,0,"Thank you, $r! Your service to the Mag'har will not be forgotten.",12,0,100,5,0,0,15387,0,"Mag'har Prisoner"),
(@ID,1,1,"Death to the ogres!",12,0,100,5,0,0,15388,0,"Mag'har Prisoner"),
(@ID,1,2,"Many thanks, hero!",12,0,100,5,0,0,15389,0,"Mag'har Prisoner"),
(@ID,1,3,"Spirits watch over you, $r!",12,0,100,5,0,0,15390,0,"Mag'har Prisoner");
