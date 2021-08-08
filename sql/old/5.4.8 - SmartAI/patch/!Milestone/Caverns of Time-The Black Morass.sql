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
	
-- Blackfang Tarantula
SET @ENTRY := 18983;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,3000,25000,30000,11,34366,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ebon Poison');

-- Darkwater Crocolisk
SET @ENTRY := 17952;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,7000,13000,11,34370,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Jagged Tooth Snap on Close');

-- Infinite Assassin
SET @ENTRY := 17835;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,5,1000,1000,0,0,11,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Corrupt Medivh on Spawn'),
(@ENTRY,0,1,2,4,0,100,7,0,0,0,0,28,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,'Remove Corrupt Medivh on Aggro'),
(@ENTRY,0,2,0,61,0,20,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,3,0,7,0,100,7,0,0,0,0,11,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Corrupt Medivh on Evade'),
(@ENTRY,0,4,0,67,0,100,2,9000,12000,0,0,11,7159,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Backstab'),
(@ENTRY,0,5,0,67,0,100,4,9000,12000,0,0,11,15657,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Backstab'),
(@ENTRY,0,6,0,0,0,100,6,2000,4500,12000,20000,11,30832,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Kidney Shot'),
(@ENTRY,0,7,0,0,0,100,4,5000,9000,17000,25000,11,38520,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Deadly Poison');
-- NPC talk text insert
SET @ENTRY := 17835;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Your efforts... are in vain.',12,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,0,1, 'We will not be stopped!',12,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,0,2, 'The wizard will fall!',12,0,50,0,0,0, 'on Aggro Text');

-- Infinite Chrono-Lord
SET @ENTRY := 21697;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,11000,27000,27000,30000,11,38539,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Discharge'),
(@ENTRY,0,1,0,0,0,100,6,18000,19000,13000,20000,11,31467,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Time Lapse'),
(@ENTRY,0,2,0,0,0,100,6,22000,22000,22000,22000,11,38540,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Attraction'),
(@ENTRY,0,3,0,0,0,100,6,27000,27000,30000,31000,11,38538,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Blast');

-- Infinite Chronomancer
SET @ENTRY := 17892;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,15124,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,15230,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,2,0,9,0,100,2,0,8,13600,14500,11,33860,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Explosion on Close'),
(@ENTRY,0,3,0,9,0,100,4,0,8,13600,14500,11,33623,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Explosion on Close'),
(@ENTRY,0,4,0,1,0,100,5,1000,1000,0,0,11,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Corrupt Medivh on Spawn'),
(@ENTRY,0,5,24,4,0,100,7,0,0,0,0,28,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,'Remove Corrupt Medivh on Aggro'),
(@ENTRY,0,6,0,61,0,20,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,7,0,7,0,100,7,0,0,0,0,11,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Corrupt Medivh on Evade');
-- NPC talk text insert
SET @ENTRY := 17892;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Your efforts... are in vain.',12,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,0,1, 'We will not be stopped!',12,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,0,2, 'The wizard will fall!',12,0,50,0,0,0, 'on Aggro Text');

-- Infinite Executioner
SET @ENTRY := 18994;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,5,1000,1000,0,0,11,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Corrupt Medivh on Spawn'),
(@ENTRY,0,1,2,4,0,100,7,0,0,0,0,28,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,'Remove Corrupt Medivh on Aggro'),
(@ENTRY,0,2,0,61,0,20,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,3,0,7,0,100,7,0,0,0,0,11,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Corrupt Medivh on Evade'),
(@ENTRY,0,4,0,9,0,100,2,0,5,8000,9000,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike on Close'),
(@ENTRY,0,5,0,9,0,100,4,0,5,8000,9000,11,34920,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike on Close'),
(@ENTRY,0,6,0,0,0,100,2,2000,4500,12000,20000,11,17198,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Overpower'),
(@ENTRY,0,7,0,0,0,100,4,2000,4500,12000,20000,11,37321,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Overpower');
-- NPC talk text insert
SET @ENTRY := 18994;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Your efforts... are in vain.',12,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,0,1, 'We will not be stopped!',12,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,0,2, 'The wizard will fall!',12,0,50,0,0,0, 'on Aggro Text');

-- Infinite Timereaver
SET @ENTRY := 21698;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,15000,17000,11,31464,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Wound'),
(@ENTRY,0,1,0,0,0,100,6,9000,12000,25000,28000,11,38592,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spell Reflection'),
(@ENTRY,0,2,0,0,0,100,6,15000,15000,35000,35000,11,38593,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Wing Buffet'),
(@ENTRY,0,3,0,2,0,100,6,0,30,15000,25000,11,31458,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Hasten at 30% HP');

-- Infinite Vanquisher
SET @ENTRY := 18995;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,15241,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Scorch'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,36807,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Scorch'),
(@ENTRY,0,2,0,9,0,100,2,0,20,13600,14500,11,13341,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fire Blast on Close'),
(@ENTRY,0,3,0,9,0,100,4,0,20,13600,14500,11,38526,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fire Blast on Close'),
(@ENTRY,0,4,0,1,0,100,5,1000,1000,0,0,11,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Corrupt Medivh on Spawn'),
(@ENTRY,0,5,24,4,0,100,7,0,0,0,0,28,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,'Remove Corrupt Medivh on Aggro'),
(@ENTRY,0,6,0,61,0,20,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,7,0,7,0,100,7,0,0,0,0,11,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Corrupt Medivh on Evade');
-- NPC talk text insert
SET @ENTRY := 18995;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Your efforts... are in vain.',12,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,0,1, 'We will not be stopped!',12,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,0,2, 'The wizard will fall!',12,0,50,0,0,0, 'on Aggro Text');

-- Infinite Whelp
SET @ENTRY := 21818;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,5,1000,1000,0,0,11,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Corrupt Medivh on Spawn'),
(@ENTRY,0,1,0,4,0,100,7,0,0,0,0,28,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,'Remove Corrupt Medivh on Aggro'),
(@ENTRY,0,2,0,7,0,100,7,0,0,0,0,11,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Corrupt Medivh on Evade');

-- Rift Keeper
SET @ENTRY := 21104;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,3000,30000,33000,11,36276,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Curse of Vulnerability'),
(@ENTRY,0,1,0,0,0,100,6,9000,11000,24000,25000,11,12542,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Fear'),
(@ENTRY,0,2,0,0,0,100,2,5000,7000,15000,18000,11,36275,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley'),
(@ENTRY,0,3,0,0,0,100,4,5000,7000,15000,18000,11,38533,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley'),
(@ENTRY,0,4,0,2,0,100,7,0,30,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP'),
(@ENTRY,0,5,0,2,0,100,7,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP');
-- NPC talk text insert
SET @ENTRY := 21104;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy');

-- Rift Lord
SET @ENTRY := 17839;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,3000,15000,17000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hamstring'),
(@ENTRY,0,1,0,0,0,100,6,9000,11000,24000,25000,11,11428,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Knockdown'),
(@ENTRY,0,2,0,0,0,100,2,5000,7000,12000,13000,11,15708,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike'),
(@ENTRY,0,3,0,0,0,100,4,5000,7000,12000,13000,11,35054,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley'),
(@ENTRY,0,4,0,2,0,100,7,0,30,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP'),
(@ENTRY,0,5,0,2,0,100,7,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP');
-- NPC talk text insert
SET @ENTRY := 17839;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy');

-- Time Keeper
SET @ENTRY := 17918;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,6000,17000,25000,11,31478,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sand Breath');

