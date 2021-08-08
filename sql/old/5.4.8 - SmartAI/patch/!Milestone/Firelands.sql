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
 
  /* Raid Normal & Heroic for 10 & 25 people */
 /* Trash Mobs */
 
-- Ancient Core Hound
SET @ENTRY := 53134;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,9000,9000,25000,27000,11,99693,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Dinner Time'),
(@ENTRY,0,1,0,0,0,100,30,5000,5000,15000,22000,11,99736,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Breath'),
(@ENTRY,0,2,0,0,0,100,30,10000,12000,35000,38000,11,99692,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Terrifying Roar');

-- Ancient Lava Dweller
SET @ENTRY := 53130;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,31,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving on Aggro'),
(@ENTRY,0,1,0,0,0,100,30,6000,8000,12000,17000,11,97549,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lava Shower'),
(@ENTRY,0,2,0,0,0,100,30,2000,4500,3500,4500,11,97306,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lava Spit');

-- Captive Druid of the Talon
SET @ENTRY := 54019;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,100556,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Smouldering Roots on Spawn');

-- Cinderweb Drone
SET @ENTRY := 53635;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,7000,9000,18000,22000,11,99463,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Boiling Spatter'),
(@ENTRY,0,1,0,0,0,100,30,4000,6000,14000,18000,11,99974,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Burning Acid'),
(@ENTRY,0,2,0,2,0,100,31,0,45,0,0,11,100634,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Consume at 45% HP');

-- Cinderweb Spiderling
SET @ENTRY := 53631;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,4000,4500,12000,16000,11,31589,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Slow');

-- Cinderweb Spinner
SET @ENTRY := 53642;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,4000,4500,12000,16000,11,31589,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Slow'),
(@ENTRY,0,1,0,0,0,100,30,7000,7000,10000,19000,11,99647,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Burning Acid');

-- Druid of the Flame
SET @ENTRY := 53619;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,2000,4500,12000,15000,11,99705,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Kneel to the Flame!'),
(@ENTRY,0,1,0,11,0,100,31,0,0,0,0,11,99649,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Reactive Flames on Spawn'),
(@ENTRY,0,2,0,0,0,100,30,7000,9000,18000,25000,11,99626,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Sunfire'),
(@ENTRY,0,3,4,2,0,100,31,0,55,0,0,22,1,1,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 1 at 55% HP'),
(@ENTRY,0,4,0,61,1,100,31,0,0,0,0,11,99574,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Cat Form at 55% HP'),
(@ENTRY,0,5,0,0,1,100,30,5000,5000,18000,25000,11,99629,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Reckless Leap');

-- Fire Scorpion
SET @ENTRY := 53127;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,7000,7000,25000,29000,11,99993,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fiery Blood'),
(@ENTRY,0,1,0,11,0,100,31,0,0,0,0,11,99984,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Slightly Warm Pincers on Spawn');

-- Fire Turtle Hatchling
SET @ENTRY := 53096;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,8000,10000,27000,32000,11,100263,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shell Spin');

-- Flame Archon
SET @ENTRY := 54161;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,6000,9000,18000,18000,11,100802,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Fiery Torment'),
(@ENTRY,0,1,0,0,0,100,30,5000,5000,12000,15000,11,100794,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Torrent');

-- Flamewaker Animator
SET @ENTRY := 53187;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,31,0,30,0,0,11,100742,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Defensive Casting at 30% HP');

-- Flamewaker Beast Handler
SET @ENTRY := 53223;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,0,0,2300,3900,11,99695,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flaming Spear');

-- Flamewaker Cauterizer
SET @ENTRY := 53639;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,30,0,40,14000,21000,11,99618,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Cauterize at 40% HP'),
(@ENTRY,0,1,0,0,0,100,30,7000,8000,15000,18000,11,99625,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Conflagration'),
(@ENTRY,0,2,0,0,0,100,10,10000,10000,27000,31000,11,99687,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Shield'),
(@ENTRY,0,3,0,0,0,100,20,10000,10000,27000,31000,11,100060,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Shield'),
(@ENTRY,0,4,0,0,0,100,30,4000,4500,12000,16000,11,31589,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Slow');

-- Flamewaker Cauterizer
SET @ENTRY := 53121;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,30,0,40,14000,21000,11,99618,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Cauterize at 40% HP'),
(@ENTRY,0,1,0,0,0,100,30,7000,8000,15000,18000,11,99625,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Conflagration');

-- Flamewaker Centurion
SET @ENTRY := 53222;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,30,0,5,12000,14500,11,16856,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Mortal Strike on Close');

-- Flamewaker Forward Guard
SET @ENTRY := 53119;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,30,0,5,17000,18000,11,78660,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Devastate on Close'),
(@ENTRY,0,1,0,0,0,100,30,4000,4500,12000,14000,11,99610,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shockwave'),
(@ENTRY,0,2,0,0,0,100,30,7000,7000,18000,22000,11,76622,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sunder Armor');

-- Flamewaker Hound Master
SET @ENTRY := 54073;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,31,0,0,0,0,11,100778,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Release The Hounds! on Aggro');

-- Flamewaker Overseer
SET @ENTRY := 53185;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,2000,4500,12000,14000,11,100431,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flaming Cleave'),
(@ENTRY,0,1,0,2,0,100,30,0,40,24000,27000,11,100457,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Disciplinary Action at 40% HP');

-- Flamewaker Pathfinder
SET @ENTRY := 53120;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,0,0,2300,3900,11,99695,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flaming Spear'),
(@ENTRY,0,1,0,9,0,100,30,0,40,8000,8000,11,99800,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ensnare on Close');

-- Flamewaker Sentinel
SET @ENTRY := 53640;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,0,0,2300,3900,11,99695,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flaming Spear'),
(@ENTRY,0,1,0,0,0,100,30,4000,4500,12000,16000,11,31589,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Slow');

-- Flamewaker Subjugator
SET @ENTRY := 53188;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,2000,4500,30000,37000,11,100526,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blistering Wound'),
(@ENTRY,0,1,0,2,0,100,31,0,45,0,0,11,100423,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Burning Motivation at 45% HP'),
(@ENTRY,0,2,0,2,0,100,31,0,20,0,0,11,100527,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Furious at 20% HP');

-- Flamewaker Taskmaster
SET @ENTRY := 53224;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,2000,4500,15000,16000,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike'),
(@ENTRY,0,1,0,4,0,100,31,0,0,0,0,11,100779,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Aura of Indomitability on Aggro');

-- Flamewaker Trainee
SET @ENTRY := 53244;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,0,0,2300,3900,11,99695,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flaming Spear'),
(@ENTRY,0,1,0,9,0,100,30,0,40,8000,8000,11,99800,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ensnare on Close');

-- Giant Fire Scorpion
SET @ENTRY := 53127;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,5000,5000,35000,37000,11,99821,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Too Hot To Handle'),
(@ENTRY,0,1,0,11,0,100,31,0,0,0,0,11,99812,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Flame Pincers on Spawn');

-- Hell Hound
SET @ENTRY := 53206;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,2000,4500,12000,14000,11,100057,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rend Flesh');

-- Inferno Hawk
SET @ENTRY := 53648;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,30,0,40,26000,30000,11,99762,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Flames of the Firehawk at 40% HP');

-- Kar the Everburning <Firelord>
SET @ENTRY := 53616;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,3500,5500,19000,22000,11,99567,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Soul Burn'),
(@ENTRY,0,1,0,2,0,100,31,0,65,0,0,11,99575,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Lava Spawn at 65% HP'),
(@ENTRY,0,2,0,2,0,100,31,0,45,0,0,11,99575,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Lava Spawn at 45% HP'),
(@ENTRY,0,3,0,2,0,100,31,0,20,0,0,11,99575,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Lava Spawn at 20% HP');

-- Lava Dweller
SET @ENTRY := 53129;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,31,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving on Aggro'),
(@ENTRY,0,1,0,0,0,100,30,6000,8000,12000,17000,11,97549,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lava Shower'),
(@ENTRY,0,2,0,0,0,100,30,2000,4500,3500,4500,11,97306,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lava Spit');

-- Matriarch Fire Turtle
SET @ENTRY := 53095;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,8000,10000,27000,32000,11,100263,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shell Spin'),
(@ENTRY,0,1,0,0,0,100,30,4000,4500,12000,16000,11,31589,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Slow');

-- Molten Flamefather
SET @ENTRY := 54143;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,5000,5000,20000,20000,11,100724,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Earthquake');

-- Molten Lord
SET @ENTRY := 53115;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,9000,9000,20000,20000,11,99530,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Flame Stomp'),
(@ENTRY,0,1,0,0,0,100,10,4500,4500,15000,17000,11,99532,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Melt Armor'),
(@ENTRY,0,2,0,0,0,100,20,4500,4500,15000,17000,11,100767,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Melt Armor'),
(@ENTRY,0,3,0,0,0,100,30,10000,10000,25000,28000,11,99538,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Lava Jet');

-- Molten Surger
SET @ENTRY := 53141;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,31,0,0,0,0,11,100012,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Surge on Aggro');

-- Patriarch Fire Turtle
SET @ENTRY := 53094;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,7000,8000,17000,22000,11,100418,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Breath'),
(@ENTRY,0,1,0,2,0,100,30,0,55,14000,21000,11,100842,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shell Shield at 55% HP'),
(@ENTRY,0,2,0,0,0,100,30,4000,4500,12000,16000,11,31589,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Slow');

-- Unbound Pyrelord
SET @ENTRY := 53167;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,2000,4500,16000,19000,11,101166,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ignite'),
(@ENTRY,0,1,0,2,0,100,31,0,80,0,0,11,99916,1,0,0,0,0,11,53732,100,0,0,0,0,0,'Cast Ignite Elemental at 80% HP'),
(@ENTRY,0,2,0,2,0,100,31,0,60,0,0,11,99916,1,0,0,0,0,11,53732,100,0,0,0,0,0,'Cast Ignite Elemental at 60% HP'),
(@ENTRY,0,3,0,2,0,100,31,0,40,0,0,11,99916,1,0,0,0,0,11,53732,100,0,0,0,0,0,'Cast Ignite Elemental at 40% HP'),
(@ENTRY,0,4,0,2,0,100,31,0,20,0,0,11,99916,1,0,0,0,0,11,53732,100,0,0,0,0,0,'Cast Ignite Elemental at 20% HP');

-- Unbound Smoldering Elemental
SET @ENTRY := 53732;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,4000,4500,20000,25000,11,99918,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blazing Flame'),
(@ENTRY,0,1,0,2,0,100,31,0,30,0,0,11,99913,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Unbreakable Shell at 30% HP');
