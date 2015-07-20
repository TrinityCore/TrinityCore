-- Deadwind Pass SAI
 
-- Damned Soul SAI
 SET @ENTRY := 12378;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,20825,64,0,0,0,0,2,0,0,0,0,0,0,0,"Damned Soul - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,0,0,60,0,5000,7900,14500,21300,11,13748,0,0,0,0,0,2,0,0,0,0,0,0,0,"Damned Soul - In Combat - Cast 'Arcane Bolt'");

-- Deadwind Mauler SAI
SET @ENTRY := 7371;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3400,5600,11500,15700,11,10966,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deadwind Mauler - In Combat - Cast 'Uppercut'");

-- Deadwind Ogre Mage SAI
SET @ENTRY := 7379;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,20824,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,2,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deadwind Ogre Mage - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,1,0,100,0,500,1000,600000,600000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deadwind Ogre Mage - On Spawn - Cast 'Lightning Shield'(Repeat)"),
(@ENTRY,0,3,0,0,0,100,0,4700,8800,10500,13800,11,15039,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deadwind Mauler - In Combat - Cast 'Flame Shock'"),
(@ENTRY,0,4,0,2,0,100,1,0,45,0,0,11,6742,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deadwind Ogre Mage - Between 0-45% Health - Cast 'Bloodlust' (No Repeat)"),
(@ENTRY,0,5,0,16,0,100,0,6742,30,20000,40000,11,6742,0,0,0,0,0,7,0,0,0,0,0,0,0,"Deadwind Ogre Mage - At 30% Health Less - Cast 'Bloodlust' on Friendlies (Repeat)");

-- Deadwind Warlock SAI
SET @ENTRY := 7372;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,20825,64,0,0,0,0,2,0,0,0,0,0,0,0,"Deadwind Warlock - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,2,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deadwind Warlock - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,5000,5000,17800,19100,11,11980,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deadwind Warlock - In Combat - Cast 'Curse of Weakness'"),
(@ENTRY,0,3,0,0,0,100,0,9900,9900,25600,27800,11,20787,0,0,0,0,0,5,0,0,0,0,0,0,0,"Deadwind Warlock - In Combat - Cast 'Immolate'");

-- Restless Shade SAI
SET @ENTRY := 7370;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,11300,12400,11,38240,0,0,0,0,0,2,0,0,0,0,0,0,0,"Restless Shade - In Combat - Cast 'Chilling Touch'"),
(@ENTRY,0,1,0,0,0,100,0,8000,9300,18900,22400,11,18267,0,0,0,0,0,2,0,0,0,0,0,0,0,"Restless Shade - In Combat - Cast 'Curse of Weakness'");

-- Sky Shadow SAI
SET @ENTRY := 7376;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7700,9100,16800,23400,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sky Shadow - In Combat - Cast 'Rend'");

-- Unliving Caretaker SAI
SET @ENTRY := 12379;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Caretaker - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unliving Caretaker - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,7700,7900,10200,14300,11,38621,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sky Shadow - In Combat - Cast 'Debilitating Strike'");

-- NPC talk text insert
SET @ENTRY := 12379;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage');

-- Unliving Resident SAI
SET @ENTRY := 12380;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6900,7800,18300,23100,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unliving Resident - In Combat - Cast 'Sunder Armor'"),
(@ENTRY,0,1,0,13,0,100,0,12000,18000,0,0,11,11978,0,0,0,0,0,6,1,0,0,0,0,0,0,"Unliving Resident - When Target Use Spell - Cast 'Kick' (Repeat)");

-- Wailing Spectre SAI
SET @ENTRY := 12377;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,12300,17800,11,32938,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wailing Spectre - At 8 yards - Cast 'Cry of the Dead' (Repeat)"),
(@ENTRY,0,1,0,9,0,100,0,0,10,7000,26500,11,7713,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wailing Spectre - At 8 yards - Cast 'Wailing Dead' (Repeat)");