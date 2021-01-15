-- Sunblade Mage Guard SAI
SET @ENTRY := 24683;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Mage Guard - Out of Combat - Disable Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Mage Guard - Out of Combat - Stop Attacking"),
(@ENTRY,0,2,0,0,0,100,7,0,0,0,0,11,44475,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Mage Guard - In Combat - Cast 'Magic Dampening Field' (No Repeat) (Dungeon)"),
(@ENTRY,0,3,4,9,0,100,0,0,60,5000,5000,11,44478,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunblade Mage Guard - Within 0-60 Range - Cast 'Glaive Throw'"),
(@ENTRY,0,4,0,61,0,100,0,0,60,5000,5000,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Mage Guard - Within 0-60 Range - Set Sheath Ranged"),
(@ENTRY,0,5,6,9,0,100,0,45,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Mage Guard - Within 45-80 Range - Enable Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,45,80,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Mage Guard - Within 45-80 Range - Start Attacking"),
(@ENTRY,0,7,0,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Mage Guard - Within 0-5 Range - Enable Combat Movement"),
(@ENTRY,0,8,9,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Mage Guard - Within 0-0 Range - Set Sheath Melee"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Mage Guard - Within 0-0 Range - Start Attacking"),
(@ENTRY,0,10,11,9,0,100,0,5,20,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Mage Guard - Within 5-20 Range - Disable Combat Movement"),
(@ENTRY,0,11,0,61,0,100,0,5,20,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Mage Guard - Within 5-20 Range - Stop Attacking"),
(@ENTRY,0,12,0,2,0,100,7,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Mage Guard - Between 0-15% Health - Increment Phase (No Repeat) (Dungeon)"),
(@ENTRY,0,13,14,2,0,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Mage Guard - Between 0-15% Health - Enable Combat Movement (No Repeat)"),
(@ENTRY,0,14,0,61,0,100,1,0,15,0,0,25,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sunblade Mage Guard - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,15,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Mage Guard - On Evade - Set Sheath Melee");
