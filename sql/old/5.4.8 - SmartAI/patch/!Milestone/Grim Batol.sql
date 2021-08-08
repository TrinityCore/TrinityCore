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

-- Ascended Flameseeker
SET @ENTRY := 39415;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4000,6000,12000,16000,11,76514,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Confounding Flames'),
(@ENTRY,0,1,0,0,0,100,6,2000,9000,10000,22000,11,76517,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Erupting Fire');

-- Ascended Rockbreaker
SET @ENTRY := 40272;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,12000,14000,11,76093,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Burning Wound'),
(@ENTRY,0,1,0,0,0,100,6,7000,9000,16000,19000,11,76779,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Rock Smash'),
(@ENTRY,0,2,0,0,0,100,6,2000,8000,15000,22000,11,76792,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Petrified Skin'),
(@ENTRY,0,3,0,4,0,100,7,0,0,0,0,11,76086,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Burning Fists on Aggro');

-- Ascended Waterlasher
SET @ENTRY := 40273;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4000,6500,15500,17500,11,76797,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Focused Geyser'),
(@ENTRY,0,1,0,0,0,100,6,7000,9000,18000,25000,11,76097,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Lightning Cloud'),
(@ENTRY,0,2,0,0,0,100,6,5000,5000,13000,13500,11,76794,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Water Spout');

-- Ascended Windwalker
SET @ENTRY := 39414;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,3000,45000,50000,11,76036,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Water Infused Blades'),
(@ENTRY,0,1,0,2,0,100,7,0,20,0,0,11,76557,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Windwalk at 20% HP');

-- Azureborne Guardian <Servant of Deathwing>
SET @ENTRY := 39854;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,3000,12000,13000,11,76394,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Curse of the Azureborne'),
(@ENTRY,0,1,0,0,0,100,6,5000,5000,15000,15000,11,76378,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Infusion');

-- Azureborne Seer <Servant of Deathwing>
SET @ENTRY := 39855;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,9000,11000,11,76369,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Twilight Bolt'),
(@ENTRY,0,1,0,2,0,100,7,0,20,0,0,11,76370,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Warped Twilight at 20% HP'),
(@ENTRY,0,2,0,2,0,100,7,0,40,0,0,11,76340,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Twisted Arcane at 40% HP');

-- Azureborne Seer <Servant of Deathwing>
SET @ENTRY := 40291;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,9000,11000,11,76369,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Twilight Bolt'),
(@ENTRY,0,1,0,2,0,100,7,0,20,0,0,11,76370,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Warped Twilight at 20% HP'),
(@ENTRY,0,2,0,2,0,100,7,0,40,0,0,11,76340,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Twisted Arcane at 40% HP');

-- Azureborne Warlord <Servant of Deathwing>
SET @ENTRY := 39909;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,6000,15000,16000,11,76620,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Azure Blast'),
(@ENTRY,0,1,0,0,0,100,6,10000,10000,20000,25000,11,76626,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Conjure Twisted Visage');

-- Crimsonborne Guardian <Servant of Deathwing>
SET @ENTRY := 39381;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,76404,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crimson Charge on Aggro'),
(@ENTRY,0,1,0,0,0,100,6,4000,6000,14000,16000,11,76409,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crimson Shockwave');

-- Crimsonborne Seer <Servant of Deathwing>
SET @ENTRY := 40290;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,8000,18000,25000,11,76314,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blazing Twilight Shield'),
(@ENTRY,0,1,0,0,0,100,6,4000,4000,12000,15000,11,76332,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Corrupted Flame');

-- Crimsonborne Seer <Servant of Deathwing>
SET @ENTRY := 39405;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,8000,18000,25000,11,76314,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blazing Twilight Shield'),
(@ENTRY,0,1,0,0,0,100,6,4000,4000,12000,15000,11,76332,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Corrupted Flame');

-- Crimsonborne Warlord <Servant of Deathwing>
SET @ENTRY := 39626;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4000,4500,12000,14500,11,76679,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Disarming Blaze'),
(@ENTRY,0,1,0,2,0,100,7,0,45,0,0,11,76685,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Empowering Twilight at 45% HP');

-- Enslaved Burning Ember
SET @ENTRY := 39892;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,9000,12000,11,90846,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Shock');

-- Enslaved Rock Elemental
SET @ENTRY := 39900;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,7,0,30,0,0,11,76014,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Jagged Rock Shield at 30% HP');

-- Enslaved Gronn Brute
SET @ENTRY := 40166;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,12000,13000,11,76703,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crunch Armor');

-- Faceless Corruptor
SET @ENTRY := 40600;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,6,0,40,15000,21000,11,75755,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Siphon Essence at 40% HP'),
(@ENTRY,0,1,0,2,0,100,7,0,20,0,0,11,75763,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Umbral Mending at 20% HP');

-- Faceless Corruptor
SET @ENTRY := 39392;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,6,0,40,15000,21000,11,75755,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Siphon Essence at 40% HP'),
(@ENTRY,0,1,0,2,0,100,7,0,20,0,0,11,75763,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Umbral Mending at 20% HP');

-- Faceless Corruptor
SET @ENTRY := 48844;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,6,0,40,15000,21000,11,75755,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Siphon Essence at 40% HP'),
(@ENTRY,0,1,0,2,0,100,7,0,20,0,0,11,75763,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Umbral Mending at 20% HP');

-- Invoked Flaming Spirit
SET @ENTRY := 40357; 
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY; 
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY; 
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,6,0,100,7,0,0,0,0,11,75238,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Supernova on Death');

-- Khaaphom
SET @ENTRY := 40953;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,13,0,100,6,9000,11000,0,0,11,24259,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Spell Lock on Player Spell Cast');

-- Malignant Trogg
SET @ENTRY := 39984;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,12000,14000,11,76507,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Claw Puncture'),
(@ENTRY,0,1,0,6,0,100,7,0,0,0,0,11,74699,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Modgud\'s Malice on Death'),
(@ENTRY,0,2,0,9,0,100,6,0,8,15000,18000,11,74837,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Modgud\'s Malady on Close');

-- Trogg Dweller
SET @ENTRY := 45467;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,12000,14000,11,76507,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Claw Puncture'),
(@ENTRY,0,1,0,6,0,100,7,0,0,0,0,11,74699,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Modgud\'s Malice on Death'),
(@ENTRY,0,2,0,9,0,100,6,0,8,15000,18000,11,74837,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Modgud\'s Malady on Close');

-- Trogg Dweller
SET @ENTRY := 39450;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,12000,14000,11,76507,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Claw Puncture');

-- Twilight Armsmaster
SET @ENTRY := 41073;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,8000,11000,11,76727,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike on Close'),
(@ENTRY,0,1,0,0,0,100,6,5000,7000,15000,18000,11,76729,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flurry of Blows');

-- Twilight Armsmaster
SET @ENTRY := 40306;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,8000,11000,11,76727,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike on Close'),
(@ENTRY,0,1,0,0,0,100,6,5000,7000,15000,18000,11,76729,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flurry of Blows');

-- Twilight Beguiler <The Twilight's Hammer>
SET @ENTRY := 40167;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,7000,8000,18000,20000,11,76711,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Chained Mind'),
(@ENTRY,0,1,0,0,0,100,6,4000,4500,12000,13500,11,76715,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Deceitful Blast');

-- Twilight Drake
SET @ENTRY := 41095;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4000,4500,15000,17000,11,76817,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Twilight Breath');

-- Twilight Earthshaper <The Twilight's Hammer>
SET @ENTRY := 39890;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,12000,12000,11,76603,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Earth Spike'),
(@ENTRY,0,1,0,2,0,100,6,0,55,30000,32000,11,76596,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stone Skin at 55% HP'),
(@ENTRY,0,2,0,1,0,100,7,3000,5000,0,0,11,74552,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Rock Elemental on Spawn');

-- Twilight Enforcer
SET @ENTRY := 40448;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,15000,16000,11,76411,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Meat Grinder on Close');

-- Twilight Enforcer
SET @ENTRY := 39956;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,15000,16000,11,76411,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Meat Grinder on Close');

-- Twilight Firecatcher <The Twilight's Hammer>
SET @ENTRY := 39870;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,6000,7000,17000,20000,11,76766,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Conduit'),
(@ENTRY,0,1,0,0,0,100,6,4000,5000,9000,11000,11,76765,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Molten Blast'),
(@ENTRY,0,2,0,1,0,100,7,3000,5000,0,0,11,74551,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Burning Ember on Spawn');

-- Twilight Shadow Weaver
SET @ENTRY := 39954;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,3400,4700,11,76416,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,1,0,0,0,100,6,5000,6000,15000,16000,11,90673,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Weave'),
(@ENTRY,0,2,0,1,0,100,7,3000,5000,0,0,11,76418,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Felhunter on Spawn');

-- Twilight Stormbreaker <The Twilight's Hammer>
SET @ENTRY := 39962;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,3400,4700,11,76720,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Water Bolt'),
(@ENTRY,0,1,0,2,0,100,6,0,55,20000,25000,11,90522,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Water Shell at 55% HP'),
(@ENTRY,0,2,0,1,0,100,7,3000,5000,0,0,11,74561,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Water Spirit on Spawn');

-- Twilight Thundercaller <The Twilight's Hammer>
SET @ENTRY := 40270;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,3400,4700,11,76578,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chain Lightning'),
(@ENTRY,0,1,0,0,0,100,6,5000,5000,15000,15000,11,76579,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Overcharge'),
(@ENTRY,0,2,0,1,0,100,7,3000,5000,0,0,11,75096,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Thunder Spirit on Spawn');

-- Twilight War-Mage
SET @ENTRY := 40268;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,12000,13000,11,76825,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ice Blast'),
(@ENTRY,0,1,0,0,0,100,6,6000,8000,16000,18000,11,76826,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Polymorph'),
(@ENTRY,0,2,0,11,0,100,3,0,0,0,0,11,76823,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Ice Enchant on Spawn'),
(@ENTRY,0,3,0,11,0,100,5,0,0,0,0,11,76822,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fire Enchant on Spawn');

-- Twilight Wyrmcaller <The Twilight's Hammer>
SET @ENTRY := 39873;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,6000,19000,22000,11,76816,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Feed Pet');
