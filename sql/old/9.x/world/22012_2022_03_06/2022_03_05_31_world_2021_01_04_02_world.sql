--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 37199;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,37199,0,0,31,0,3,21692,0,0,0,0,"","Group 0: Spell 'Dertrok Mind Control' (Effect 0) targets creature 'Cansis'");

-- Dertrok SAI
SET @ID := 21496;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` IN (@ID,21692);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ID,21692) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID*100+0 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,20,0,100,0,10565,0,0,0,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dertrok - On Quest 'The Stones of Vekh'nir' Finished - Run Script"),

(@ID*100+0,9,0,0,0,0,100,0,1000,1000,0,0,0,66,0,0,0,0,0,0,19,21692,0,0,0,0,0,0,0,"Dertrok - On Script - Set Orientation Closest Creature 'Cansis'"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dertrok - On Script - Say Line 0"),
(@ID*100+0,9,2,0,0,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dertrok - On Script - Remove NPC Flag Questgiver"),
(@ID*100+0,9,3,0,0,0,100,0,3000,3000,0,0,0,11,37199,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dertrok - On Script - Cast 'Dertrok Mind Control'"),
(@ID*100+0,9,4,0,0,0,100,0,3000,3000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dertrok - On Script - Say Line 1"),
(@ID*100+0,9,5,0,0,0,100,0,0,0,0,0,0,86,37200,0,19,21692,0,0,1,0,0,0,0,0,0,0,0,"Dertrok - On Script - Cross Cast 'Confused Cansis' (Cansis)"),
(@ID*100+0,9,6,0,0,0,100,0,1000,1000,0,0,0,45,0,1,0,0,0,0,19,21692,0,0,0,0,0,0,0,"Dertrok - On Script - Set Data 0 1 (Cansis)"),
(@ID*100+0,9,7,0,0,0,100,0,4000,4000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dertrok - On Script - Say Line 2"),
(@ID*100+0,9,8,0,0,0,100,0,3000,3000,0,0,0,5,19,0,0,0,0,0,19,21692,0,0,0,0,0,0,0,"Dertrok - On Script - Play Emote 19 (Cansis)"),
(@ID*100+0,9,9,0,0,0,100,0,2000,2000,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dertrok - On Script - Say Line 3"),
(@ID*100+0,9,10,0,0,0,100,0,2000,2000,0,0,0,28,37200,0,0,0,0,0,19,21692,0,0,0,0,0,0,0,"Dertrok - On Script - Remove Aura 'Confused Cansis' (Cansis)"),
(@ID*100+0,9,11,0,0,0,100,0,1000,1000,0,0,0,1,0,0,0,0,0,0,19,21692,0,0,0,0,0,0,0,"Dertrok - On Script - Say Line 0 (Cansis)"),
(@ID*100+0,9,12,0,0,0,100,0,2000,2000,0,0,0,45,0,2,0,0,0,0,19,21692,0,0,0,0,0,0,0,"Dertrok - On Script - Set Data 0 2 (Cansis)"),
(@ID*100+0,9,13,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dertrok - On Script - Set Orientation Home Position"),
(@ID*100+0,9,14,0,0,0,100,0,1000,1000,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dertrok - On Script - Add NPC Flag Questgiver"),
(@ID*100+0,9,15,0,0,0,100,0,0,0,0,0,0,45,0,3,0,0,0,0,19,21692,0,0,0,0,0,0,0,"Dertrok - On Script - Set Data 0 3 (Cansis)"),

(21692,0,0,0,38,0,100,0,0,1,0,0,0,66,0,0,0,0,0,0,19,21496,0,0,0,0,0,0,0,"Cansis - On Data Set 0 1 - Set Orientation Closest Creature 'Dertrok'"),
(21692,0,1,0,38,0,100,0,0,2,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,5.515240192413330078,"Cansis - On Data Set 0 2 - Set Orientation"),
(21692,0,2,0,38,0,100,0,0,3,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cansis - On Data Set 0 3 - Set Orientation Home Position");

DELETE FROM `creature_text` WHERE `CreatureID` IN (21496,21692);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(21496,0,0,"Cansis, hold still. I'm going to try to use this crystal.",12,0,100,1,0,0,19315,0,"Dertrok"),
(21496,1,0,"Interesting... Let me try something.",12,0,100,1,0,0,19317,0,"Dertrok"),
(21496,2,0,"Cansis. You are a chicken.",12,0,100,21,0,0,19318,0,"Dertrok"),
(21496,3,0,"Fascinating.",12,0,100,21,0,0,19389,0,"Dertrok"),
(21692,0,0,"If you ever do that again, I will break your neck.",12,0,100,25,0,0,19388,0,"Cansis");
