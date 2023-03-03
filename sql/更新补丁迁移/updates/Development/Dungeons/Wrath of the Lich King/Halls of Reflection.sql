/* Copyright (C) 11 April 2011-2014 patch Project 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version. 
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public Licensefor more details.
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/> 
 *
 * patch Project  Copyright (C) 11 April 2011-2014 patch Project 
 * This program comes with ABSOLUTELY NO WARRANTY;
 * This is free software, and you are welcome to redistribute it
 * under certain conditions.
 */
 
   /* Dungeon Normal-Heroic for 5 people */
    /* Trash Mobs */
	
-- Raging Ghoul
SET @ENTRY := 36940;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,70150,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Leap on Aggro');

-- Quel'Delar
SET @ENTRY := 37158;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,5000,12000,13000,11,29426,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Strike'),
(@ENTRY,0,1,0,0,0,100,6,3000,9000,7000,19000,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike'),
(@ENTRY,0,2,0,9,0,100,6,0,5,15800,18300,11,67716,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirlwind on Close'),
(@ENTRY,0,3,0,9,0,100,6,0,8,25000,29800,11,67541,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bladestorm on Close');

-- Lumbering Abomination
SET @ENTRY := 37069;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,5000,11300,13800,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave');

-- Frostsworn General
SET @ENTRY := 36723;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,5,45,11000,18000,11,69222,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw Shield on Close'),
(@ENTRY,0,1,0,9,0,100,4,5,45,11000,18000,11,73076,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw Shield on Close');

-- Spiritual Reflection
SET @ENTRY := 37107;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,12000,14000,11,69933,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Baleful Strike'),
(@ENTRY,0,1,0,0,0,100,4,5000,5000,12000,14000,11,70400,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Baleful Strike'),
(@ENTRY,0,2,0,9,0,100,2,0,15,15000,17000,11,69900,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spirit Burst on Close'),
(@ENTRY,0,3,0,9,0,100,4,0,15,15000,17000,11,73046,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spirit Burst on Close');

-- Spiritual Reflection
SET @ENTRY := 37068;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,12000,14000,11,69933,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Baleful Strike'),
(@ENTRY,0,1,0,0,0,100,4,5000,5000,12000,14000,11,70400,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Baleful Strike'),
(@ENTRY,0,2,0,9,0,100,2,0,15,15000,17000,11,69900,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spirit Burst on Close'),
(@ENTRY,0,3,0,9,0,100,4,0,15,15000,17000,11,73046,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spirit Burst on Close');

-- Risen Witch Doctor
SET @ENTRY := 36941;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,70080,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,70182,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,2,0,0,0,100,2,8000,8000,14600,17800,11,70144,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Curse of Doom'),
(@ENTRY,0,3,0,0,0,100,4,8000,8000,14600,17800,11,70183,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Curse of Doom'),
(@ENTRY,0,4,0,9,0,100,2,0,20,14200,16800,11,70145,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley on Close'),
(@ENTRY,0,5,0,9,0,100,4,0,20,14200,16800,11,70184,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley on Close');
