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

-- Brittle Ghoul
SET @ENTRY := 54952;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,11,26047,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Birth on Spawn');

-- Infinite Suppressor
SET @ENTRY := 54920;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3500,4500,12000,13000,11,102601,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Wave'),
(@ENTRY,0,1,0,0,0,100,6,6000,9000,15000,24000,11,102600,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Temporal Vortex');

-- Infinite Warden
SET @ENTRY := 54923;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,5000,13000,16000,11,102598,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Void Strike'),
(@ENTRY,0,1,0,2,0,100,6,0,55,18000,21000,11,102599,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Void Shield at 55% HP');

-- Risen Ghoul
SET @ENTRY := 54191;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,11,26047,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Birth on Spawn');

-- Time-Twisted Breaker
SET @ENTRY := 54552;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,8,18000,22000,11,102132,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Break Armor on Close'),
(@ENTRY,0,1,0,0,0,100,6,6000,9000,15000,16000,11,102124,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rupture Ground');

-- Time-Twisted Drake
SET @ENTRY := 54543;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,7,0,30,0,0,11,102134,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,1,0,61,0,100,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP'),
(@ENTRY,0,2,0,0,0,100,6,4000,4500,12000,14000,11,102135,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Breath');
-- NPC talk text insert
SET @ENTRY := 54543;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage');

-- Time-Twisted Footman
SET @ENTRY := 54687;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4000,5000,14000,14000,11,101817,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Bash'),
(@ENTRY,0,1,0,2,0,100,6,0,40,10000,11000,11,101811,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shield Wall at 40% HP'),
(@ENTRY,0,2,0,9,0,100,6,0,10,16000,18000,11,101820,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thunderclap on Close');

-- Time-Twisted Geist
SET @ENTRY := 54511;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,8000,15000,18000,11,109952,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cadaver Toss'),
(@ENTRY,0,1,0,0,0,100,6,4000,7000,12000,14500,11,102066,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Flesh Rip'),
(@ENTRY,0,2,0,2,0,100,7,0,20,0,0,11,109944,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Cannibalize at 20% HP');

-- Time-Twisted Priest
SET @ENTRY := 54690;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,7,0,50,0,0,11,102409,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Power Word: Shield at 50% HP'),
(@ENTRY,0,1,0,2,0,100,4,0,70,35000,39000,11,102409,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Power Word: Shield at 70% HP'),
(@ENTRY,0,2,0,0,0,100,6,5000,5000,30000,32000,11,102405,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fountain of Light');

-- Time-Twisted Rifleman
SET @ENTRY := 54693;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,2300,3900,11,102410,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,6,4000,5000,12000,15000,11,102411,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Multi-Shot');

-- Time-Twisted Scourge Beast
SET @ENTRY := 54507;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,8000,17000,19000,11,101888,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Face Kick'),
(@ENTRY,0,1,0,0,0,100,6,3000,4000,12000,12000,11,102063,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Putrid Spit'),
(@ENTRY,0,2,0,4,0,100,7,0,0,0,0,11,101891,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Wail of the Dead on Aggro');

-- Time-Twisted Seer
SET @ENTRY := 54553;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,6000,6000,12000,15000,11,102158,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sear Flesh'),
(@ENTRY,0,1,0,0,0,100,6,4000,4000,10000,19000,11,102156,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Call Flames');

-- Time-Twisted Sorceress
SET @ENTRY := 54691;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,101816,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Blast'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,102442,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Blast'),
(@ENTRY,0,2,0,0,0,100,6,7000,9000,17000,20000,11,101812,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Blink');
