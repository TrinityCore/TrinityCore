-- Shadowmoon Zealot SAI (Source: https://www.youtube.com/watch?v=jPRsTn38v_U)
SET @ID := 21788;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,6,0,25,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Shadowmoon Zealot - On Death - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"We will never dissipate, mortal... Our fate is tied to Gorefiend...",15,0,100,0,0,0,19444,0,"Shadowmoon Zealot"),
(@ID,0,1,"Pray that the chilling embrace of Teron Gorefiend does not reach out for you...",15,0,100,0,0,0,19445,0,"Shadowmoon Zealot"),
(@ID,0,2,"It is you who have invaded our home. Gorefiend will avenge us!",15,0,100,0,0,0,19446,0,"Shadowmoon Zealot"),
(@ID,0,3,"Gorefiend will have your head, interloper!",15,0,100,0,0,0,19447,0,"Shadowmoon Zealot"),
(@ID,0,4,"We are bound here... eternally. It is the will of Gorefiend.",15,0,100,0,0,0,19448,0,"Shadowmoon Zealot");

-- Shadowmoon Harbinger SAI (Source: https://www.youtube.com/watch?v=jPRsTn38v_U)
SET @ID := 21795;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,6,0,25,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Shadowmoon Harbinger - On Death - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"We will never dissipate, mortal... Our fate is tied to Gorefiend...",15,0,100,0,0,0,19444,0,"Shadowmoon Harbinger"),
(@ID,0,1,"Pray that the chilling embrace of Teron Gorefiend does not reach out for you...",15,0,100,0,0,0,19445,0,"Shadowmoon Harbinger"),
(@ID,0,2,"It is you who have invaded our home. Gorefiend will avenge us!",15,0,100,0,0,0,19446,0,"Shadowmoon Harbinger"),
(@ID,0,3,"Gorefiend will have your head, interloper!",15,0,100,0,0,0,19447,0,"Shadowmoon Harbinger"),
(@ID,0,4,"We are bound here... eternally. It is the will of Gorefiend.",15,0,100,0,0,0,19448,0,"Shadowmoon Harbinger");
