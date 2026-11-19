-- Servant of the Throne SAI
SET @ENTRY := 36724;
UPDATE `creature_template` SET `AIName`="SmartAI" , `scriptname` ="" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,1000,3000,4500,11,71029,64,0,0,0,0,2,0,0,0,0,0,0,0,"Servant of the Throne - In Combat - Cast 'Glacial Blast' with CastFlag: 64 and TriggerFlag: 0 (TargetLimit: 0)"),
(@ENTRY,0,1,0,4,0,100,0,0,0,0,0,39,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Servant of the Throne - On Aggro - Call For Help");

-- Ancient Skeletal Soldier SAI
SET @ENTRY := 37012;
UPDATE `creature_template` SET `AIName`="SmartAI" , `scriptname` ="" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,10000,7000,12000,11,70964,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ancient Skeletal Soldier - In Combat - Cast 'Shield Bash' with CastFlag: 0 and TriggerFlag: 0 (TargetLimit: 0)"),
(@ENTRY,0,1,0,4,0,100,0,0,0,0,0,39,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ancient Skeletal Soldier - On Aggro - Call For Help");
