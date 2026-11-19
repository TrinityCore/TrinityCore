-- Nethurbian Crater KC Bunny SAI
SET @ENTRY := 28352;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,51381,0,180000,180000,33,28352,0,0,0,0,0,7,0,0,0,0,0,0,0,"Nethurbian Crater KC Bunny - On Spellhit 'Toss Grenade' - Quest Credit ''"),
(@ENTRY,0,1,0,61,0,100,0,51381,0,180000,180000,45,1,1,0,0,0,0,20,190555,2,0,0,0,0,0,"Nethurbian Crater KC Bunny - On Spellhit 'Toss Grenade' - Set Data 1 1");

-- Nerubian Crater SAI
SET @ENTRY := 190555;
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,38,0,100,0,1,1,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Nerubian Crater - On Data Set 1 1 - Run Script");

-- Actionlist SAI
SET @ENTRY := 19055500;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,44,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Phase 2"),
(@ENTRY,9,1,0,0,0,100,0,180000,180000,0,0,44,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Phase 1");
