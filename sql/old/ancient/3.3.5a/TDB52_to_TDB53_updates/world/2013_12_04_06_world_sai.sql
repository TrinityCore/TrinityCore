-- Fathom Stone SAI for quest 6921
SET @ENTRY := 177964;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,1,70,0,100,0,1,0,0,0,12,12876,6,300000,1,0,0,8,0,0,0,-780.4395,-79.37307,-44.02165,0.6806784,"Fathom Stone - On Activate - summon Baron Aquanis");

-- Baron Aquanis SAI
SET @ENTRY := 12876;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,4000,6000,11,15043,64,0,0,0,0,2,0,0,0,0,0,0,0,"Baron Aquanis - Combat - Cast Frostbolt"),
(@ENTRY,0,1,0,0,0,100,0,7000,12000,14000,19000,11,14907,1,0,0,0,0,1,0,0,0,0,0,0,0,"Baron Aquanis - Combat - Cast Frost Nova");
