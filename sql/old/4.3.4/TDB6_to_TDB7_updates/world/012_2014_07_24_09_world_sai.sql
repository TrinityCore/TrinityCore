-- Argus Shadow Mage SAI
SET @ENTRY := 2318;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Argus Shadow Mage - On Aggro - Set Event Phase 1"),
(@ENTRY,0,1,0,0,1,100,0,0,0,3500,4900,11,20816,64,0,0,0,0,2,0,0,0,0,0,0,0,"Argus Shadow Mage - In Combat CMC - Cast 'Shadow Bolt' (Phase 1)"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Argus Shadow Mage - Between 0-30% Health - Set Event Phase 2"),
(@ENTRY,0,3,4,0,2,100,1,0,0,0,0,11,4063,1,0,0,0,0,1,0,0,0,0,0,0,0,"Argus Shadow Mage - In Combat - Cast 'Argus Shadow Mage Transform' (Phase 2) (No Repeat)"),
(@ENTRY,0,4,5,61,2,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Argus Shadow Mage - In Combat - Enable Combat Movement"),
(@ENTRY,0,5,0,61,2,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Argus Shadow Mage - In Combat - Say Line 0"),
(@ENTRY,0,6,0,23,2,100,0,4063,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Argus Shadow Mage - Missing Aura - Set Event Phase 1");
