--  3.x + 4.x + 6.x
-- DB/SAI: Update Gjostland
-- Haris Lightsbreath SAI
SET @ENTRY := 49954;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,79962,0,0,0,0,0,1,0,0,0,0,0,0,0,"Haris Lightsbreath - Out of Combat - Cast 'Seal of Righteousness'");

-- Matron Narsilla SAI
SET @ENTRY := 49950;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,48168,0,0,0,0,0,1,0,0,0,0,0,0,0,"Matron Narsilla - Out of Combat - Cast 'Inner Fire'");

-- Shadowpine Catlord SAI
SET @ENTRY := 16345;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,16,0,100,0,28902,30,20000,40000,11,28902,0,0,0,0,0,7,0,0,0,0,0,0,0,"Shadowpine Catlord - On Friendly Unit Missing Buff 'Bloodlust' - Cast 'Bloodlust'"),
(@ENTRY,0,1,0,1,0,100,1,1000,1000,0,0,11,28904,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowpine Catlord - Out of Combat - Cast 'Summon Ghostclaw Lynx' (No Repeat)");
