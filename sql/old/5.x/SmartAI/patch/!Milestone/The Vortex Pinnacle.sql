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

-- Armored Mistral
SET @ENTRY := 45915;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,5000,18000,21000,11,88061,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Gale Strike'),
(@ENTRY,0,1,0,2,0,100,6,0,55,18000,21000,11,88058,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rising Winds at 55% HP'),
(@ENTRY,0,2,0,9,0,100,6,0,5,15000,15000,11,88055,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Storm Surge on Close');

-- Cloud Prince
SET @ENTRY := 45917;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3500,4500,12000,15000,11,88073,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Starfall'),
(@ENTRY,0,1,0,0,0,100,6,8000,9000,24000,26000,11,88075,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Typhoon');

-- Empyrean Assassin
SET @ENTRY := 45922;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3000,4500,10000,12000,11,88182,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lethargic Poison'),
(@ENTRY,0,1,0,2,0,100,6,0,55,16000,16500,11,88186,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Vapor Form at 55% HP');

-- Executor of the Caliph
SET @ENTRY := 45928;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,12000,13500,11,78660,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Devastate'),
(@ENTRY,0,1,0,0,0,100,6,7000,8000,20000,20000,11,87761,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rally'),
(@ENTRY,0,2,0,0,0,100,6,5000,5500,15000,18000,11,87759,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shockwave'),
(@ENTRY,0,3,0,9,0,100,6,0,5,9000,12000,11,76622,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sunder Armor on Close');

-- Gust Soldier
SET @ENTRY := 45477;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,7000,8000,17000,20000,11,87933,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Air Nova'),
(@ENTRY,0,1,0,4,0,100,7,0,0,0,0,11,87930,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,2,0,0,0,100,6,5000,5000,12000,12500,11,87923,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wind Blast');

-- Lurking Tempest
SET @ENTRY := 45704;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,3400,4700,11,89105,64,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Lightning Bolt'),
(@ENTRY,0,1,0,11,0,100,7,0,0,0,0,11,85467,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lurk on Spawn');

-- Minister of Air
SET @ENTRY := 45930;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,9000,13000,11,87762,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lightning Lash'),
(@ENTRY,0,1,0,9,0,100,6,0,10,14000,16000,11,87768,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lightning Nova on Close');

-- Servant of Asaad
SET @ENTRY := 45926;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,8000,9000,11,87771,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crusader Strike on Close'),
(@ENTRY,0,1,0,9,0,100,6,0,5,15000,18000,11,58127,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Divine Storm on Close'),
(@ENTRY,0,2,0,2,0,100,7,0,20,0,0,11,87772,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Hand of Protection at 20% HP');

-- Skyfall Star
SET @ENTRY := 45932;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3500,4500,12000,14000,11,87854,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Barrage');

-- Skyfall Star
SET @ENTRY := 52019;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3500,4500,12000,14000,11,87854,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Barrage');

-- Temple Adept
SET @ENTRY := 45935;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,3400,4700,11,88959,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Holy Smite'),
(@ENTRY,0,1,0,2,0,100,6,0,50,15000,15000,11,87780,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Desperate Speed at 50% HP'),
(@ENTRY,0,2,0,14,0,100,2,70000,40,15000,18000,11,87779,1,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Greater Heal on Friendlies'),
(@ENTRY,0,3,0,14,0,100,4,120000,40,15000,18000,11,87779,1,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Greater Heal on Friendlies'),
(@ENTRY,0,4,0,2,0,100,7,0,30,0,0,11,87779,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Greater Heal at 30% HP');

-- Turbulent Squall
SET @ENTRY := 45924;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,12000,13000,11,88175,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Asphyxiate'),
(@ENTRY,0,1,0,0,0,100,6,7000,7000,17000,18000,11,88170,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cloudburst'),
(@ENTRY,0,2,0,0,0,100,6,6000,10000,15000,25000,11,88171,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Hurricane');

-- Whipping Wind
SET @ENTRY := 47238;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,3400,4700,11,88080,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lightning Bolt');

-- Wild Vortex
SET @ENTRY := 45912;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,3400,4700,11,88032,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lightning Bolt'),
(@ENTRY,0,1,0,0,0,100,6,5000,7000,15000,18000,11,88010,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Cyclone'),
(@ENTRY,0,2,0,0,0,100,6,4000,9000,12000,14000,11,88029,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wind Shock');
