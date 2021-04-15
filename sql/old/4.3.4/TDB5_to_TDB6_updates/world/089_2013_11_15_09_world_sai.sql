-- Ulf the Bloodletter SAI
SET @ENTRY := 24016;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,7000,12000,11,48288,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ulf the Bloodletter - Between 0-5 Range - Cast 48288"),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ulf the Bloodletter - On Death - Set Event Phase 1"),
(@ENTRY,0,2,3,8,1,100,1,43178,0,0,0,11,43191,0,0,0,0,0,7,0,0,0,0,0,0,0,"Ulf the Bloodletter - On Spellhit By 43178 - Quest Credit (Phase 1)"),
(@ENTRY,0,3,0,61,1,100,1,43178,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ulf the Bloodletter - On Spellhit By 43178 - Forced Despawn (Phase 1)");

-- North Fleet Reservist SAI
SET @ENTRY := 24120;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,43115,0,25000,25000,11,43138,0,0,0,0,0,7,0,0,0,0,0,0,0,"North Fleet Reservist - On Spellhit By 43115 - Quest Credit"),
(@ENTRY,0,1,0,61,0,80,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"North Fleet Reservist - On Spellhit By 43115 - Say Line 0");

-- Oric the Baleful SAI
SET @ENTRY := 24161;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,5000,8000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Oric the Baleful - Between 0-5 Range - Cast 15496"),
(@ENTRY,0,1,0,0,0,100,0,9000,11000,9000,13000,11,32736,1,0,0,0,0,2,0,0,0,0,0,0,0,"Oric the Baleful - In Combat - Cast 32736"),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Oric the Baleful - On Death - Set Event Phase 1"),
(@ENTRY,0,3,4,8,1,100,1,43178,0,0,0,11,43192,0,0,0,0,0,7,0,0,0,0,0,0,0,"Oric the Baleful - On Spellhit By 43178 - Quest Credit (Phase 1)"),
(@ENTRY,0,4,0,61,1,100,1,43178,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Oric the Baleful - On Spellhit By 43178 - Forced Despawn (Phase 1)");

-- Gunnar Thorvardsson SAI
SET @ENTRY := 24162;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,7000,9000,11,41056,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gunnar Thorvardsson - Between 0-5 Range - Cast 41056"),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gunnar Thorvardsson - On Death - Set Event Phase 1"),
(@ENTRY,0,2,3,8,1,100,1,43178,0,0,0,11,43193,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gunnar Thorvardsson - On Spellhit By 43178 - Quest Credit (Phase 1)"),
(@ENTRY,0,3,0,61,1,100,1,43178,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gunnar Thorvardsson - On Spellhit By 43178 - Forced Despawn (Phase 1)");
