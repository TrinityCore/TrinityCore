-- Qiraji Gladiator SAI (Source: Vengeance part copied from Sethekk Ravenguard(https://www.youtube.com/watch?v=fST7H_oGKoI))
SET @ID := 15324;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Don't reset it or it will not work after evade. Maybe they should respawn if only one was killed and
-- in this case it will not work without no reset flag
(@ID,0,0,0,11,0,100,256,0,0,0,0,64,1,0,0,0,0,0,19,15324,30,0,0,0,0,0,"Qiraji Gladiator - On Respawn - Store Targetlist (No Reset)"),
(@ID,0,1,0,0,0,100,0,9600,22900,16900,33700,11,5568,0,0,0,0,0,1,0,0,0,0,0,0,0,"Qiraji Gladiator - In Combat - Cast 'Trample'"),
(@ID,0,2,0,0,0,100,0,11700,25800,18400,30300,11,10966,0,0,0,0,0,2,0,0,0,0,0,0,0,"Qiraji Gladiator - In Combat - Cast 'Uppercut'"),
(@ID,0,3,4,38,0,100,0,0,1,0,0,11,25164,0,0,0,0,0,1,0,0,0,0,0,0,0,"Qiraji Gladiator - On Data Set 0 1 - Cast 'Vengeance'"),
(@ID,0,4,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Qiraji Gladiator - On Link - Say Line 0"),
(@ID,0,5,0,6,0,100,0,0,0,0,0,45,0,1,0,0,0,0,12,1,0,0,0,0,0,0,"Qiraji Gladiator - On Death - Set Data 0 1");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,1191,0,"Qiraji Gladiator");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 15324 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,4,15324,0,0,36,1,0,0,0,0,0,0,"","Group 0: Execute SAI (Action 3) if creature is alive");

DELETE FROM `creature_formations` WHERE `leaderGUID` IN (144482,144484,144486,144488);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(144482,144482,0,0,3),
(144482,144483,0,0,3),
(144484,144484,0,0,3),
(144484,144485,0,0,3),
(144486,144486,0,0,3),
(144486,144487,0,0,3),
(144488,144488,0,0,3),
(144488,144489,0,0,3);
