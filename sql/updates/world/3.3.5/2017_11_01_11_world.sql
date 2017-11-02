-- Add script to Venture Co. Overseer
SET @ENTRY := 3286;
-- Venture Co. Overseer SAI
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Overseer - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,71,2,1,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Overseer - Between 0-0% Health - Change Equipment (No Repeat)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,11,6531,0,0,0,0,0,2,0,0,0,0,0,0,0,"Venture Co. Overseer - Between 0-0% Health - Cast 'Overseer's Poison' (No Repeat)"),
(@ENTRY,0,3,0,25,0,100,0,0,0,0,0,71,1,1,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Overseer - On Reset - Change Equipment");

-- Add "enrage" text to Venture Co. Overseer
DELETE FROM `creature_text` WHERE `CreatureID`=@ENTRY;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Probability`, `BroadcastTextId`, `comment`) VALUES
(@ENTRY, 0, 0, '%s grabs for his poisoned dagger!', 16, 100, 1385, 'Venture Co. Overseer - Between 0-30% Health');

-- Add "poisoned dagger" to Venture Co. Overseer
DELETE FROM `creature_equip_template` WHERE `CreatureID`=@ENTRY AND `ID`=2;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`) VALUES (@ENTRY, 2, 5279);
