-- Festering Corpse SAI
SET @ENTRY := 31130;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,1,58641,0,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Festering Corpse - On Spellhit 'Olakin's Torch' - Run Script (No Repeat)");

-- Actionlist SAI
SET @ENTRY := 3113000;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,11,59216,0,0,0,0,0,1,0,0,0,0,0,0,0,"Festering Corpse - On Script - Cast 'Burning Corpse'"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,33,31130,0,0,0,0,0,7,0,0,0,0,0,0,0,"Festering Corpse - On Script - Quest Credit 'By Fire Be Purged'"),
(@ENTRY,9,2,0,0,0,100,0,6000,9000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Festering Corpse - On Script - Despawn Instant");
