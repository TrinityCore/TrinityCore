-- Source: Sniffs(combat only) & https://www.youtube.com/watch?v=ZczVt20pZKY & other similar
DELETE FROM `smart_scripts` WHERE `entryorguid` = 4850 AND `source_type` = 2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4850,2,0,1,46,0,100,0,4850,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Areatrigger (Winterfin Caverns) - On Trigger - Store Targetlist"),
(4850,2,1,2,61,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,19,25209,0,0,0,0,0,0,0,"Areatrigger (Winterfin Caverns) - On Link - Send Target 1 (Claximus)"),
(4850,2,2,0,61,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,19,25209,0,0,0,0,0,0,0,"Areatrigger (Winterfin Caverns) - On Link - Set Data 0 1 (Claximus)");

DELETE FROM `areatrigger_scripts` WHERE `entry` = 4850;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(4850,"SmartTrigger");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 4850 AND `SourceId` = 2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
-- Got no text in sniff without quest
(22,1,4850,2,0,1,0,45278,0,0,0,0,0,"","Group 0: Execute SAI (Action 0) if player does have aura 'King Mrgl-Mrgl's Spare Suit'"),
(22,1,4850,2,0,29,0,25209,100,0,0,0,0,"","Group 0: Execute SAI (Action 0) if creature 'Claximus' is near");

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 25209;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 25209 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25209,0,0,1,38,0,100,0,0,1,60000,60000,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Claximus - On Data Set 0 1 - Say Line 1"),
(25209,0,1,0,61,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Claximus - On Link - Set Orientation Stored Target 1"),
(25209,0,2,0,4,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Claximus - On Aggro - Say Line 0"),
(25209,0,3,0,0,0,100,0,6000,9000,7000,10000,0,11,50273,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Claximus - In Combat - Cast 'Arcane Barrage'"),
(25209,0,4,0,0,0,100,0,3000,5000,3000,5000,0,11,50275,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Claximus - In Combat - Cast 'Stabilized Magic'");

DELETE FROM `creature_text` WHERE `CreatureID` = 25209;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(25209,0,0,"What tiny morsel comes this way? Not one of the murloc I think.",12,0,100,0,0,0,24435,0,"Claximus"),
(25209,0,1,"It's been a long time since last I tasted $r.",12,0,100,0,0,0,24436,0,"Claximus"),
(25209,0,2,"What's this? You're not one of the Winterfin!",12,0,100,0,0,0,24437,0,"Claximus"),
(25209,0,3,"Did 'King Mrgl-Mrgl' send you? I know what he truly is!",12,0,100,0,0,0,24438,0,"Claximus"),
(25209,1,0,"You're not one of mine. King Mrgl-Mrgl must have sent you to talk terms of surrender. Come closer so that I might see you better.",15,0,100,0,0,0,24460,0,"Claximus");
