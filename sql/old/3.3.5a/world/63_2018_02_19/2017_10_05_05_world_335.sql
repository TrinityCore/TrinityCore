SET @ENTRY := 3937;
-- Add missing text
DELETE from creature_text WHERE `CreatureID`=@ENTRY;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(@ENTRY, 0, 0, 'Fresh bread for sale!', 12, 7, 100, 0, 0, 0, 4013, 0, 'Kira Songshine'),
(@ENTRY, 0, 1, 'Fresh bread, baked this very morning!', 12, 7, 100, 0, 0, 0, 4014, 0, 'Kira Songshine'),
(@ENTRY, 0, 2, 'Come get yer fresh bread!', 12, 7, 100, 0, 0, 0, 4015, 0, 'Kira Songshine'),
(@ENTRY, 1, 0, 'Guards! Help me!', 14, 7, 100, 0, 0, 0, 4403, 0, 'Kira Songshine');
-- Kira Songshine SAI
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,5000,10000,30000,45000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kira Songshine - Out of Combat - Say Line 0"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kira Songshine - On Aggro - Say Line 1"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,39,60,1,0,0,0,0,1,0,0,0,0,0,0,0,"Kira Songshine - On Aggro Link - Call For Help");
