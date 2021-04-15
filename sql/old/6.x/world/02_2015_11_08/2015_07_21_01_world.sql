-- Update Deadwind Pass
-- Deadwind Ogre Mage SAI
SET @ENTRY := 7379;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,20824,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deadwind Ogre Mage - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,1,0,100,0,500,1000,600000,600000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deadwind Ogre Mage - Ooc - Cast Lightning Shield"),
(@ENTRY,0,3,0,0,0,100,0,4700,8800,10500,13800,11,15039,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deadwind Mauler - In Combat - Cast 'Flame Shock'"),
(@ENTRY,0,4,0,2,0,100,1,0,45,0,0,11,6742,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deadwind Ogre Mage - Between 0-45% Health - Cast 'Bloodlust' (No Repeat)"),
(@ENTRY,0,5,0,16,0,100,0,6742,30,20000,40000,11,6742,0,0,0,0,0,7,0,0,0,0,0,0,0,"Deadwind Ogre Mage - At 30% Health Less - Cast 'Bloodlust' on Friendlies (Repeat)");

-- Deadwind Warlock SAI
SET @ENTRY := 7372;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,20825,64,0,0,0,0,2,0,0,0,0,0,0,0,"Deadwind Warlock - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deadwind Warlock - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,5000,5000,17800,19100,11,11980,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deadwind Warlock - In Combat - Cast 'Curse of Weakness'"),
(@ENTRY,0,3,0,0,0,100,0,9900,9900,25600,27800,11,20787,0,0,0,0,0,5,0,0,0,0,0,0,0,"Deadwind Warlock - In Combat - Cast 'Immolate'");

-- Unliving Resident SAI
SET @ENTRY := 12380;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6900,7800,18300,23100,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unliving Resident - In Combat - Cast 'Sunder Armor'"),
(@ENTRY,0,1,0,13,0,100,0,12000,18000,0,0,11,11978,0,0,0,0,0,6,0,0,0,0,0,0,0,"Unliving Resident - When Target Use Spell - Cast 'Kick' (Repeat)");
