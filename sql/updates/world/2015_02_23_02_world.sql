-- Actionlist SAI
SET @ENTRY := 6192700;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,1,0,0,0,100,0,60000,60000,0,0,12,2202,3,120000,0,0,0,8,0,0,0,4988.25,568.897,3.15542,5,"Bonfire - On Script - Summon Creature 'Greymist Coastrunner'"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,12,2202,3,120000,0,0,0,8,0,0,0,4998.76,568.891,3.21375,5,"Bonfire - On Script - Summon Creature 'Greymist Coastrunner'"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,12,2202,3,120000,0,0,0,8,0,0,0,4994.69,573.448,2.4842,5,"Bonfire - On Script - Summon Creature 'Greymist Coastrunner'"),
(@ENTRY,9,4,0,0,0,100,0,60000,60000,0,0,12,2205,3,120000,0,0,0,8,0,0,0,4988.25,568.897,3.15542,5,"Bonfire - On Script - Summon Creature 'Greymist Warrior'"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,12,2205,3,120000,0,0,0,8,0,0,0,4998.76,568.891,3.21375,5,"Bonfire - On Script - Summon Creature 'Greymist Warrior'"),
(@ENTRY,9,6,0,0,0,100,0,60000,60000,0,0,12,2206,3,120000,0,0,0,8,0,0,0,4998.76,568.891,3.21375,5,"Bonfire - On Script - Summon Creature 'Greymist Hunter'"),
(@ENTRY,9,7,0,0,0,100,0,0,0,0,0,12,10323,3,120000,0,0,0,8,0,0,0,4994.69,573.448,2.4842,5,"Bonfire - On Script - Summon Creature 'Murkdeep'");

-- Bonfire SAI
SET @ENTRY := 61927;
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,38,0,100,0,0,1,0,0,80,6192700,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonfire - On Data Set 0 1 - Run Script");

-- Greymist Hunter SAI
SET @GUID := -37989;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2206;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,6,0,100,0,0,1,0,0,45,0,1,0,0,0,0,14,48515,61927,0,0,0,0,0,"Greymist Hunter - On Just Died -Set Data 0 1");
