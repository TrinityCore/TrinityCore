-- Magmoth Shaman SAI
SET @ENTRY := 25428;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,5,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magmoth Shaman - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Magmoth Shaman - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,25,0,100,0,0,0,0,0,11,45575,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magmoth Shaman - On Reset - Cast 'Magmoth Fire Totem'");

-- Magmoth Fire Totem SAI
SET @ENTRY := 25444;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magmoth Fire Totem - On Just Summoned - Enable Combat Movement"),
(@ENTRY,0,1,0,0,0,100,0,3000,4000,4000,4000,11,45580,0,0,0,0,0,2,0,0,0,0,0,0,0,"Magmoth Fire Totem - In Combat - Cast 'Fireball'"),
(@ENTRY,0,2,0,1,0,100,0,100,100,20000,20000,11,45576,0,0,0,0,0,19,24021,30,0,0,0,0,0,"Magmoth Fire Totem - Out of Combat - Cast 'Cosmetic - New Fire Beam Channel (Mouth)'"),
(@ENTRY,0,3,0,7,0,100,0,0,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magmoth Fire Totem - On Evade - Despawn Instant");
