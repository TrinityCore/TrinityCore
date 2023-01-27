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
 
  /* Dungeon Normal for 5 people */
    /* Trash Mobs & Bosses*/
 
-- Vicious Thug
SET @ENTRY := 46379;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,11000,12000,11,86738,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Deep Bruise on Close'),
(@ENTRY,0,1,0,0,0,100,2,3000,4000,13000,15000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hamstring'),
(@ENTRY,0,2,0,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Say on Aggro');
-- NPC talk text insert
SET @ENTRY := 46379;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Get up you,lazy bums,there\'s fighting to do!',12,0,50,0,0,0, 'combat Say');

-- Slag Fury
SET @ENTRY := 46263;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,9000,13000,11,86765,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Melt Armor on Close');

-- Shifty Thief
SET @ENTRY := 46381;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,8000,9000,11,14873,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sinister Strike on Close'),
(@ENTRY,0,1,0,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Say on Aggro');
-- NPC talk text insert
SET @ENTRY := 46381;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Start fighting or start bleeding!',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,0,1, 'Time to fight!',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,0,2, 'Freedom!',12,0,50,0,0,0, 'combat Say');

-- Searing Destroyer
SET @ENTRY := 46260;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,10,12000,13500,11,15744,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blast Wave on Close'),
(@ENTRY,0,1,0,0,0,100,2,1000,3000,7000,9000,11,38391,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Scorch');

-- Rumbling Earth
SET @ENTRY := 46262;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,3,0,0,0,0,11,86771,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rock Shards on Death');

-- Rowdy Troublemaker
SET @ENTRY := 46375;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,8000,11000,11,86740,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Dirty Blow on Close'),
(@ENTRY,0,2,0,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Say on Aggro');
-- NPC talk text insert
SET @ENTRY := 46375;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Get up you,lazy bums,there\'s fighting to do!',12,0,50,0,0,0, 'combat Say');

-- Riverpaw Slayer
SET @ENTRY := 46249;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,8500,9900,11,14516,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike on Close'),
(@ENTRY,0,1,0,12,0,100,2,5,20,35000,43000,11,77720,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Execute at 20% Player HP');

-- Riverpaw Shaman
SET @ENTRY := 46252;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,12167,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,2,2,0,100,3,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,3,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,2,0,100,3,0,50,0,0,11,23381,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Healing Touch at 50% HP'),
(@ENTRY,0,4,0,14,0,100,2,1000,40,20000,30000,11,23381,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Healing Touch on Friendlies');
-- NPC talk text insert
SET @ENTRY := 46252;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Riverpaw Poacher
SET @ENTRY := 46250;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,15547,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,2,2,0,100,3,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,3,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,9,0,100,2,0,20,6000,8000,11,31290,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Net on Close');
-- NPC talk text insert
SET @ENTRY := 46250;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Riverpaw Looter
SET @ENTRY := 46251;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,86820,0,0,0,0,0,2,1,0,0,0,0,0,0,'Cast Mad Dash on Aggro'),
(@ENTRY,0,1,0,67,0,100,2,3900,6900,0,0,11,15248,0,0,0,0,0,2,0,0,0,0,0,0,0,'Casts Shank');

-- Riverpaw Basher
SET @ENTRY := 46248;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,8000,10500,11,86814,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bash Head on Close');

-- Enraged Fire Elemental
SET @ENTRY := 46261;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,20,8900,11300,11,13341,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fire Blast on Close'),
(@ENTRY,0,1,0,2,0,100,3,0,30,0,0,11,56646,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,2,0,2,0,100,3,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP');
-- NPC talk text insert
SET @ENTRY := 46261;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage');

-- Randolph Moloch
SET @ENTRY := 46383;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,8000,9000,11,86729,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sweep on Close'),
(@ENTRY,0,1,0,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Say on Aggro'),
(@ENTRY,0,2,0,0,0,100,2,3000,5000,11000,14000,11,86726,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wildly Stabbing'),
(@ENTRY,0,3,4,2,0,100,3,0,50,0,0,11,55964,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Vanish at 50% HP'),
(@ENTRY,0,4,0,61,0,100,3,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 50% HP'),
(@ENTRY,0,5,6,2,0,100,3,0,30,0,0,11,55964,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Vanish at 30% HP'),
(@ENTRY,0,6,0,61,0,100,3,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP'),
(@ENTRY,0,7,0,6,0,100,3,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Death');
-- NPC talk text insert
SET @ENTRY := 46383;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Allow me to introduce myself. I am Randolph Moloch and I will be killing you all today.',14,0,100,0,0,0, 'combat Say'),
(@ENTRY,1,0, 'Randolph Moloch vanishes!',41,0,100,0,0,0, 'combat Say'),
(@ENTRY,2,0, 'My epic schemes,my great plans!Gone!',14,0,100,0,0,0, 'combat Say');

-- Lord Overheat
SET @ENTRY := 46264;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,1,0,0,0,100,2,0,0,3400,4700,11,12466,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball'),
(@ENTRY,0,2,0,0,0,100,2,6000,8000,15000,16000,11,86636,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rain of Fire'),
(@ENTRY,0,3,0,0,0,100,2,4000,5000,10000,12000,11,86633,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Overheat'),
(@ENTRY,0,4,0,6,0,100,3,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Death');
-- NPC talk text insert
SET @ENTRY := 46264;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'ALL MUST BURN!',14,0,100,0,0,0, 'combat Say'),
(@ENTRY,1,0, 'FIRE...EXTINGUISHED!',14,0,100,0,0,0, 'combat Say');

-- Hogger
SET @ENTRY := 46254;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Say on Aggro'),
(@ENTRY,0,1,0,0,0,100,2,3000,4000,8000,12000,11,86604,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Vicious Slice'),
(@ENTRY,0,2,0,0,0,100,2,6000,8000,19000,20000,11,86620,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Maddening Call'),
(@ENTRY,0,3,0,2,0,100,3,0,30,0,0,11,86736,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,4,0,2,0,100,3,0,30,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP'),
(@ENTRY,0,5,0,6,0,100,3,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Death');
-- NPC talk text insert
SET @ENTRY := 46254;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Forest just setback!',14,0,100,0,0,0, 'combat Say'),
(@ENTRY,1,0, 'Hogger enrages!',41,0,100,0,0,0, 'combat Enrage'),
(@ENTRY,2,0, 'Yiiipe!',14,0,100,0,0,0, 'combat Say');

