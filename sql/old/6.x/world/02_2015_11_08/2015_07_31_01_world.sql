-- DB/Quest: The Far Watch Offensive 4.x + 6.x
-- Areatrigger SAI
SET @ENTRY := 6135;
DELETE FROM `areatrigger_scripts` WHERE `entry`=@ENTRY;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES (@ENTRY,"SmartTrigger");
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,2,0,0,46,0,100,0,6135,0,0,0,45,1,1,0,0,0,0,10,303897,3438,0,0,0,0,0,"Areatrigger - On Trigger - Set Data 1 1");

-- Kreenig Snarlsnout SAI
SET @ENTRY := 3438;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,1,1,1,0,0,1,0,0,0,0,0,0,21,200,0,0,0,0,0,0,"Kreenig Snarlsnout - On Data Set 1 1 - Say Line 0 (No Repeat)");

DELETE FROM `creature_text` WHERE `entry`=3438;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextId`) VALUES 
(3438, 0, 0, 'Come and face me! *snort* I can smell your $r stench from here.', 14, 0, 100, 0, 0, 0, 'Kreenig Snarlsnout', 44319);
