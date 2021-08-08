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
 
  /* Dungeon Normal & Heroic for 5 people */
 /* Trash Mobs */

-- Bellows Slave
SET @ENTRY := 40084;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,12000,15000,11,76622,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sunder Armor on Close');

-- Buster
SET @ENTRY := 40013;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,8000,8000,20000,20000,11,76628,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Lava Drool'),
(@ENTRY,0,1,0,9,0,100,6,0,10,11000,13000,11,76665,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Little Big Flame Breath on Close');

-- Conflagration
SET @ENTRY := 39994;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,12000,14000,11,76618,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Immolate'),
(@ENTRY,0,1,0,9,0,100,6,0,20,16000,18000,11,76617,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Heat Exhaustion on Close');

-- Crazed Mage
SET @ENTRY := 39982;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,3400,4700,11,76508,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frostbolt'),
(@ENTRY,0,1,0,9,0,100,6,0,10,15000,16000,11,76509,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Nova on Close'),
(@ENTRY,0,2,0,2,0,100,6,0,40,20000,21000,11,54792,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Icy Veins at 40% HP');

-- Defiled Earth Rager
SET @ENTRY := 40023;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,9000,12000,11,76716,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bludgeoning Strike on Close'),
(@ENTRY,0,1,0,0,0,100,6,4000,4500,18000,20000,11,76717,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Meteor');

-- Evolved Twilight Zealot
SET @ENTRY := 39987;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,8000,9000,15000,18000,11,76522,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Force Blast'),
(@ENTRY,0,1,0,0,0,100,6,2000,4000,12000,15000,11,76561,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gravity Strike'),
(@ENTRY,0,2,0,9,0,100,6,0,8,17000,22000,11,76524,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Grievous Whirl on Close'),
(@ENTRY,0,3,0,0,0,100,6,10000,10000,22000,25000,11,82362,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Shadow Strike'),
(@ENTRY,0,4,0,4,0,100,7,0,0,0,0,11,76575,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blood of the Evolved on Aggro');

-- Incendiary Spark
SET @ENTRY := 40021;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,3400,4700,11,76719,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball'),
(@ENTRY,0,1,0,0,0,100,6,5000,7000,12000,15000,11,76718,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Final Volley');

-- Lucky
SET @ENTRY := 40008;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,8000,8000,20000,20000,11,76628,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Lava Drool'),
(@ENTRY,0,1,0,9,0,100,6,0,10,11000,13000,11,76665,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Little Big Flame Breath on Close');

-- Mad Prisoner
SET @ENTRY := 39985;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,7,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,1,0,61,0,100,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP'),
(@ENTRY,0,2,0,0,0,100,6,2000,4500,15000,20000,11,77568,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Head Crack'),
(@ENTRY,0,3,0,0,0,100,6,5000,5000,12000,16000,11,76512,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Infected Wound');
-- NPC talk text insert
SET @ENTRY := 39985;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage');

-- Runty
SET @ENTRY := 40015;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,8000,8000,20000,20000,11,76628,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Lava Drool'),
(@ENTRY,0,1,0,9,0,100,6,0,10,11000,13000,11,76665,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Little Big Flame Breath on Close');

-- Twilight Element Warden
SET @ENTRY := 40017;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4000,5000,12000,13000,11,76680,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Chain Lightning'),
(@ENTRY,0,1,0,9,0,100,6,0,20,9000,10000,11,76677,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fire Blast on Close'),
(@ENTRY,0,2,0,0,0,100,6,3000,4000,10000,15000,11,58025,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frost Buffet'),
(@ENTRY,0,3,0,9,0,100,6,0,40,15000,18000,11,76682,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frostbomb on Close');

-- Twilight Flame Caller
SET @ENTRY := 39708;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,10,13000,14500,11,76473,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blast Wave on Close'),
(@ENTRY,0,1,0,0,0,100,6,5000,8000,15000,18000,11,76325,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Call Flames');

-- Twilight Obsidian Borer
SET @ENTRY := 40019;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,5000,18000,20000,11,76686,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Shadow Prison'),
(@ENTRY,0,1,0,9,0,100,6,0,20,12000,13000,11,76688,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bore on Close');

-- Twilight Sadist
SET @ENTRY := 39980;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,2300,3900,11,76572,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Short Throw'),
(@ENTRY,0,1,0,9,0,100,6,5,15,7000,9000,11,76502,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heart-seeker Blade on Close'),
(@ENTRY,0,2,0,9,0,100,6,0,10,14000,16000,11,76497,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Inflict Pain on Close'),
(@ENTRY,0,3,0,9,0,100,6,0,5,7000,8000,11,76500,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sinister Strike on Close');

-- Twilight Torturer
SET @ENTRY := 39978;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,6000,15000,16000,11,75590,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Inflict Pain'),
(@ENTRY,0,1,0,0,0,100,6,3000,4000,12000,13500,11,76478,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Red-Hot Poker'),
(@ENTRY,0,2,0,0,0,100,6,4000,8000,10000,17000,11,76484,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Shackles'),
(@ENTRY,0,3,0,2,0,100,7,0,20,0,0,11,76487,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Wild Beatdown at 20% HP');

-- Twilight Zealot
SET @ENTRY := 39990;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,7,0,0,0,0,31,1,3,0,0,0,0,1,0,0,0,0,0,0,0,'Set Random Phase on Spawn'),
(@ENTRY,0,1,0,0,1,100,6,4000,4500,12000,13500,11,76589,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Barrage'),
(@ENTRY,0,2,0,0,1,100,6,5000,6000,15000,18000,11,76592,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Haste'),
(@ENTRY,0,3,0,0,1,100,6,0,0,2700,3200,11,76612,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Missiles'),
(@ENTRY,0,4,0,4,1,100,7,0,0,0,0,11,76591,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Aura of Arcane Haste on Aggro'),
(@ENTRY,0,5,0,0,2,100,6,7000,8000,18000,20000,11,76582,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Gouge'),
(@ENTRY,0,6,0,13,2,100,6,9000,11000,0,0,11,76583,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Kick on Player Spell Cast'),
(@ENTRY,0,7,0,9,2,100,6,0,5,8000,9000,11,13737,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike on Close'),
(@ENTRY,0,8,0,0,2,100,6,3500,4500,12000,14000,11,76594,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rend'),
(@ENTRY,0,9,0,0,4,100,6,0,0,3400,4700,11,76584,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,10,0,9,4,100,6,0,8,13600,14500,11,76588,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Nova on Close');
