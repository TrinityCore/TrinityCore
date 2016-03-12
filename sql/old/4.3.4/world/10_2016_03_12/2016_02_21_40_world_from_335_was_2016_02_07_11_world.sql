-- 
-- Razorthorn Ravager SAI
SET @ENTRY := 24922;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id` >=3;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,3,4,8,0,100,0,44935,0,0,0,69,0,0,0,0,0,0,20,187073,30,0,0,0,0,0,"Razorthorn Ravager - On Spellhit 'Expose Razorthorn Root' - Move To Closest Gameobject 'Razorthorn Dirt Mound'"),
(@ENTRY,0,4,5,61,0,100,0,44935,0,0,0,45,1,1,0,0,0,0,20,187073,30,0,0,0,0,0,"Razorthorn Ravager - On Spellhit 'Expose Razorthorn Root' - Set Data 1 1"),
(@ENTRY,0,5,0,61,0,100,0,44935,0,0,0,80,@ENTRY*100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Razorthorn Ravager - On Spellhit 'Expose Razorthorn Root' - Run Script");

-- Actionlist SAI
SET @ENTRY := 2492200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,3000,3000,0,0,11,44941,2,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Cast 'Summon Razorthorn Root'");

-- Razorthorn Dirt Mound SAI
SET @ENTRY := 187073;
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,38,0,100,0,1,1,0,0,80,18707300,2,0,0,0,0,1,0,0,0,0,0,0,0,"Razorthorn Dirt Mound - On Data Set 1 1 - Run Script");

-- Actionlist SAI
SET @ENTRY := 18707300;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,10,10,0,0,44,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Phase 2"),
(@ENTRY,9,1,0,0,0,100,0,120000,120000,0,0,44,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Phase 1");
