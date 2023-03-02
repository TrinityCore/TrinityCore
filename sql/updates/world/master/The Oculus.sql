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
	
-- Phantasmal Air
SET @ENTRY := 27650;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,500,1000,600000,600000,11,25020,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lightning Shield on Spawn'),
(@ENTRY,0,1,0,1,0,100,4,500,1000,600000,600000,11,20545,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lightning Shield on Spawn'),
(@ENTRY,0,2,0,16,0,100,2,25020,1,15000,30000,11,25020,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shield on Repeat'),
(@ENTRY,0,3,0,16,0,100,4,20545,1,15000,30000,11,20545,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shield on Repeat');

-- Greater Ley-Whelp
SET @ENTRY := 28276;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,20,7000,11000,11,51243,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Bolt on Close'),
(@ENTRY,0,1,0,9,0,100,4,0,20,7000,11000,11,59215,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Bolt on Close');

-- Phantasmal Cloudscraper
SET @ENTRY := 27645;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,5000,4000,6000,11,59220,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chain Lightning'),
(@ENTRY,0,1,0,0,0,100,4,3000,5000,4000,6000,11,59223,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chain Lightning'),
(@ENTRY,0,2,0,0,0,100,2,7000,10000,12000,15000,11,15588,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thunderclap'),
(@ENTRY,0,3,0,0,0,100,4,7000,10000,12000,15000,11,59217,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thunderclap');

-- Phantasmal Fire
SET @ENTRY := 27651;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,8000,5000,9000,11,50744,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Blaze'),
(@ENTRY,0,1,0,0,0,100,4,3000,8000,5000,9000,11,59225,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Blaze');

-- Phantasmal Mammoth
SET @ENTRY := 27642;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4000,7000,12000,15000,11,51253,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Trample'),
(@ENTRY,0,1,0,9,0,100,7,8,25,0,0,11,32323,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Close');

-- Phantasmal Naga
SET @ENTRY := 27648;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,3000,9000,12000,11,49711,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Hooked Net'),
(@ENTRY,0,1,0,0,0,100,4,1000,3000,9000,12000,11,59260,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Hooked Net'),
(@ENTRY,0,2,0,0,0,100,2,9000,12000,13000,16000,11,50732,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Water Tomb'),
(@ENTRY,0,3,0,0,0,100,2,9000,12000,13000,16000,11,59261,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Water Tomb');

-- Phantasmal Ogre
SET @ENTRY := 27647;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,6,0,30,20000,24000,11,50730,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bloodlust at 30% HP'),
(@ENTRY,0,1,0,0,0,100,6,3000,7000,9000,12000,11,50731,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mace Smash');

-- Phantasmal Water
SET @ENTRY := 27653;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,35,15800,18300,11,37924,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Water Bolt Volley on Close'),
(@ENTRY,0,1,0,9,0,100,4,0,35,15800,18300,11,59266,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Water Bolt Volley on Close');


-- Phantasmal Wolf
SET @ENTRY := 27644;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,9000,9000,12000,11,50729,0,0,0,0,0,2,32,0,0,0,0,0,0,'Cast Carnivorous Bite'),
(@ENTRY,0,1,0,0,0,100,4,3000,9000,9000,12000,11,59269,0,0,0,0,0,2,32,0,0,0,0,0,0,'Cast Carnivorous Bite'),
(@ENTRY,0,2,0,0,0,100,2,10000,13000,18000,24000,11,50728,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Furious Howl'),
(@ENTRY,0,3,0,0,0,100,4,10000,13000,18000,24000,11,59274,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Furious Howl');

-- Azure Ring Guardian
SET @ENTRY := 27638;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,8000,9000,14000,11,49549,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Ice Beam'),
(@ENTRY,0,1,0,0,0,100,4,4000,8000,9000,14000,11,59211,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Ice Beam');

-- Azure Ley-Whelp
SET @ENTRY := 27636;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,50705,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,59210,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt');

-- Amber Drake
SET @ENTRY := 27755;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,6000,12000,14000,11,49840,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shock Lance');

-- Ring-Lord Sorceress
SET @ENTRY := 27639;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5500,11000,13000,11,16102,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flamestrike'),
(@ENTRY,0,1,0,0,0,100,4,5000,5500,11000,13000,11,61402,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flamestrike'),
(@ENTRY,0,2,0,0,0,100,2,9000,9000,16000,19000,11,50715,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Blizzard'),
(@ENTRY,0,3,0,0,0,100,4,9000,9000,16000,19000,11,59278,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Blizzard');

-- Snowflake
SET @ENTRY := 28153;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,50721,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,59280,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,2,0,0,0,100,7,5000,9000,0,0,11,44604,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enchantment of Spell Haste');

-- Planar Anomaly
SET @ENTRY := 30879;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,8000,12000,14000,11,57976,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Planar Blast');

-- Azure Spellbinder
SET @ENTRY := 27635;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,8000,8000,16000,16000,11,50702,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Volley'),
(@ENTRY,0,1,0,0,0,100,4,8000,8000,16000,16000,11,59212,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Volley'),
(@ENTRY,0,2,0,0,0,100,2,6000,9000,9000,13000,11,50566,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Mind Warp'),
(@ENTRY,0,3,0,0,0,100,4,6000,9000,9000,13000,11,38047,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Mind Warp'),
(@ENTRY,0,4,0,0,0,100,6,9000,12000,4000,8000,11,50572,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Power Sap');

-- Azure Inquisitor
SET @ENTRY := 27633;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,51454,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,1,0,0,0,100,4,0,0,2300,3900,11,59209,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,2,0,0,0,100,6,4000,7000,9000,12000,11,50573,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Cleave'),
(@ENTRY,0,3,0,9,0,100,6,0,10,14000,20000,11,50690,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Immobilizing Field on Close');
