-- 
DELETE FROM `areatrigger_scripts` WHERE `entry` IN (4950);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(4950,'SmartTrigger');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (4950) AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4950,2,0,1,46,0,100,0,4950,0,0,0,45,1,1,0,0,0,0,10,118282,26605,0,0,0,0,0,"On Trigger - Set Data");

-- Anub'ar Underlord SAI
SET @GUID := -118282;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=26605;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,1,11,0,100,1,0,0,0,0,11,34426,19,0,0,0,0,1,0,0,0,0,0,0,0,"Anub'ar Underlord - On Respawn - Cast 'Greater Invisibility' (No Repeat)"),
(@GUID,0,1,0,61,0,100,0,0,0,0,0,18,128,0,0,0,0,0,0,0,0,0,0,0,0,0,"Anub'ar Underlord - On Respawn - Set Flag Not Attackable (No Repeat)"),
(@GUID,0,2,0,38,0,100,1,1,1,120000,120000,80,2660500,2,0,0,0,0,1,0,0,0,0,0,0,0,"Anub'ar Underlord - On Data Set 1 1 - Run Script (No Repeat)"),
(@GUID,0,3,0,25,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anub'ar Underlord - On Respawn - Set Reactstate Passive");

-- Anub'ar Underlord SAI
SET @ENTRY := 26605;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,12500,17800,11,51681,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anub'ar Underlord - Within 0-8 Range - Cast 'Rearing Stomp'");

DELETE FROM `creature_text` WHERE `entry`=26605;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextId`) VALUES 
(26605, 0, 0, 'You have made a fatal mistake, mortal... There isss no essscape...', 12, 0, 100, 0, 0, 0, 'Anub''ar Underlord', 25860);

-- Actionlist SAI
SET @ENTRY := 2660500;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,28,34426,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anub'ar Underlord - On Script - Remove Aura 'Greater Invisibility'"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,1,0,10000,0,0,0,0,1,0,0,0,0,0,0,0,"Anub'ar Underlord - On Script - Say Line 0"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,12,26606,2,30000,0,0,0,8,0,0,0,3703.85,2164.53,37.2352,3.81021,"Anub'ar Underlord - On Script - Summon Creature 'Anub'ar Slayer'"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,12,26402,2,30000,0,0,0,8,0,0,0,3709.76,2158.12,37.2493,3.19637,"Anub'ar Underlord - On Script - Summon Creature 'Anub'ar Ambusher'"),
(@ENTRY,9,4,0,0,0,100,0,100,100,0,0,45,1,1,0,0,0,0,9,0,0,2,0,0,0,0,"Anub'ar Underlord - On Script - Set Data 1 1"),
(@ENTRY,9,5,0,0,0,100,0,4000,4000,0,0,45,1,1,0,0,0,0,10,98533,26653,0,0,0,0,0,"Anub'ar Underlord - On Script - Set Data 1 1"),
(@ENTRY,9,6,0,0,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anub'ar Underlord - On Script - Set Reactstate Aggressive"),
(@ENTRY,9,7,0,0,0,100,0,0,0,0,0,45,1,2,0,0,0,0,9,0,0,2,0,0,0,0,"Anub'ar Underlord - On Script - Set Data 1 2"),
(@ENTRY,9,8,0,0,0,100,0,0,0,0,0,38,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anub'ar Underlord - On Script - Set In Combat With Zone");

-- Kilix the Unraveler SAI
SET @ENTRY := 26653;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,0,1,1,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Kilix the Unraveler - On Data Set 1 1 - Run Script"),
(@ENTRY,0,1,0,25,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kilix the Unraveler - On Reset - Set Reactstate Passive");

-- Actionlist SAI
SET @ENTRY := 2665300;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,1,0,25000,0,0,0,0,1,0,0,0,0,0,0,0,"Kilix the Unraveler - On Script - Say Line 0"),
(@ENTRY,9,1,0,0,0,100,0,8000,8000,0,0,49,0,0,0,0,0,0,10,118282,26605,0,0,0,0,0,"Kilix the Unraveler - On Script - Start Attacking");

DELETE FROM `creature_text` WHERE `entry`=26653;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextId`) VALUES 
(26653, 0, 0, 'Betrayers! The day of reckoning comes and with it comes your end! See then if your Lich King saves you from the ancient one\'s judgement! Now you die!', 12, 0, 100, 0, 0, 0, 'Kilix the Unraveler', 25861);

-- Anub'ar Slayer SAI
SET @ENTRY := 26606;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,0,1,1,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anub'ar Slayer - On Data Set 1 1 - Set Reactstate Passive"),
(@ENTRY,0,1,0,38,0,100,0,1,2,0,0,49,0,0,0,0,0,0,10,98533,26653,0,0,0,0,0,"Anub'ar Ambusher - On Data Set 1 2 - Start Attacking");

-- Anub'ar Ambusher SAI
SET @ENTRY := 26402;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,50347,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anub'ar Ambusher - On Aggro - Cast 'Rush' (No Repeat)"),
(@ENTRY,0,1,0,38,0,100,0,1,1,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anub'ar Ambusher - On Data Set 1 1 - Set Reactstate Passive"),
(@ENTRY,0,2,0,38,0,100,0,1,2,0,0,49,0,0,0,0,0,0,10,98533,26653,0,0,0,0,0,"Anub'ar Ambusher - On Data Set 1 2 - Start Attacking");
