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
 
-- Amani Bear
SET @ENTRY := 23584;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,5000,18000,20000,11,42747,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crunch Armor'),
(@ENTRY,0,1,0,0,0,100,6,1000,2000,28000,32000,11,42745,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage');

-- Amani Bear
SET @ENTRY := 24217;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,5000,18000,20000,11,42747,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crunch Armor'),
(@ENTRY,0,1,0,0,0,100,6,1000,2000,28000,32000,11,42745,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage');

-- Amani Crocolisk
SET @ENTRY := 24047;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4000,5000,13000,15000,11,43352,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Tail Swipe'),
(@ENTRY,0,1,0,0,0,100,6,2000,3000,12000,18000,11,43353,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Infected Bite');

-- Amani Dragonhawk
SET @ENTRY := 23834;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,9000,25000,27000,11,43294,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Breath');

-- Amani Dragonhawk Hatchling
SET @ENTRY := 23598;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,12000,15000,11,43299,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Buffet');

-- Amani Elder Lynx
SET @ENTRY := 24530;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,7,0,30,0,0,11,34970,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP'),
(@ENTRY,0,1,0,61,0,100,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP'),
(@ENTRY,0,2,0,0,0,100,6,2000,4500,12000,14000,11,43357,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Feral Swipe'),
(@ENTRY,0,3,0,0,0,100,6,7000,10000,17000,18500,11,43356,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pounce');
-- NPC talk text insert
SET @ENTRY := 24530;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy');

-- Amani Lynx
SET @ENTRY := 24043;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,7,0,0,0,0,11,42866,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Spawn'),
(@ENTRY,0,1,0,7,0,100,7,0,0,0,0,11,42866,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Evade'),
(@ENTRY,0,2,0,0,0,100,6,2000,4500,12000,14000,11,43357,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Feral Swipe');

-- Amani Lynx Cub
SET @ENTRY := 24064;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,7,0,0,0,0,11,42943,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Spawn'),
(@ENTRY,0,1,0,7,0,100,7,0,0,0,0,11,42943,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Evade'),
(@ENTRY,0,2,0,4,0,100,7,0,0,0,0,11,43317,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dash on Aggro'),
(@ENTRY,0,3,0,9,0,100,6,0,5,9000,12000,11,43358,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gut Rip on Close');

-- Amani Snake
SET @ENTRY := 24338;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,12000,16000,11,25810,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mind-numbing Poison');

-- Amani'shi Axe Thrower
SET @ENTRY := 23542;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,12000,13000,11,31566,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Raptor Strike on Close'),
(@ENTRY,0,1,0,0,0,100,6,7000,8000,16000,18000,11,35011,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Knockdown'),
(@ENTRY,0,2,0,0,0,100,6,5000,5000,25000,27500,11,42359,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Axe Volley');

-- Amani'shi Beast Tamer
SET @ENTRY := 24059;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,16000,16000,11,43359,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Call of the Beast'),
(@ENTRY,0,1,0,0,0,100,6,6000,8000,15000,25000,11,77616,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Dark Simulacrum'),
(@ENTRY,0,2,0,0,0,100,6,9000,10000,27000,32500,11,43361,1,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Domesticate');

-- Amani'shi Berserker
SET @ENTRY := 24374;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,7,0,30,0,0,11,28747,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP'),
(@ENTRY,0,1,0,61,0,100,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP'),
(@ENTRY,0,2,0,4,0,100,7,0,0,0,0,11,97557,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,3,0,0,0,100,6,5000,7000,12000,14000,11,43673,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mighty Blow');
-- NPC talk text insert
SET @ENTRY := 24374;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy');

-- Amani'shi Flame Caster
SET @ENTRY := 23596;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,8000,9000,19000,25000,11,42220,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Conflagration'),
(@ENTRY,0,1,0,0,0,100,6,2000,4000,12000,12000,11,43245,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fire Blast'),
(@ENTRY,0,2,0,0,0,100,6,5000,6500,15000,18500,11,43240,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball Volley'),
(@ENTRY,0,3,0,2,0,100,7,0,35,0,0,11,43242,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blazing Haste at 35% HP');

-- Amani'shi Guardian
SET @ENTRY := 23597;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,7,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,1,0,61,0,100,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP'),
(@ENTRY,0,2,0,0,0,100,6,3500,4500,12000,14000,11,43246,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rend');
-- NPC talk text insert
SET @ENTRY := 23597;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage');

-- Amani'shi Handler
SET @ENTRY := 24065;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,35,8000,9000,11,43362,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Electrified Net on Close'),
(@ENTRY,0,1,0,9,0,100,6,0,5,15000,19000,11,43364,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Tranquilizing Poison on Close');

-- Amani'shi Medicine Man
SET @ENTRY := 23581;
SET @ENTRYTOTEM := 23822;
SET @TOTEMSPELL := 42479;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
UPDATE `creature_template` SET `AIName`='0' WHERE `entry`=@ENTRYTOTEM;
UPDATE `creature_template` SET `spell1`=@TOTEMSPELL WHERE `entry`=@ENTRYTOTEM;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,5000,25000,25000,11,42376,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Healing Ward'),
(@ENTRY,0,1,0,2,0,100,6,0,40,50000,55000,11,42478,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Protective Ward at 40% HP'),
(@ENTRY,0,2,0,2,0,100,6,0,30,20000,30000,11,42477,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chain Heal at 30% HP'),
(@ENTRY,0,3,0,0,0,100,6,0,0,3400,4700,11,97474,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lightning Bolt');

-- Amani'shi Protector
SET @ENTRY := 24180;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,8000,11000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave on Close'),
(@ENTRY,0,1,0,0,0,100,6,5000,8000,15000,15000,11,43529,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike'),
(@ENTRY,0,2,0,2,0,100,6,0,55,20000,25000,11,43530,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Piercing Howl at 55% HP');

-- Amani'shi Reinforcement
SET @ENTRY := 23587;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,32323,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,1,0,0,0,100,6,5000,7000,12000,13000,11,43298,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike');

-- Amani'shi Savage
SET @ENTRY := 23889;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,12000,13000,11,12054,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rend'),
(@ENTRY,0,1,0,0,0,100,6,5000,7000,15000,16000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hamstring'),
(@ENTRY,0,2,0,0,0,100,6,4000,9000,10000,18000,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sunder Armor');

-- Amani'shi Scout
SET @ENTRY := 23586;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,1,0,61,0,100,7,0,0,0,0,11,42177,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Alert Drums on Aggro'),
(@ENTRY,0,2,0,0,0,100,6,0,0,2300,3900,11,16496,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,3,0,0,0,100,6,6000,7000,20000,24000,11,43205,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Multi-Shot');
-- NPC talk text insert
SET @ENTRY := 23586;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Invaders! Sound the Alarm!',14,0,100,0,0,12104, 'on Aggro Text');

-- Amani'shi Tempest
SET @ENTRY := 24549;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,12000,15000,11,97496,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chain Lightning'),
(@ENTRY,0,1,0,9,0,100,6,0,20,15000,18000,11,44033,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thunderclap on Close');

-- Amani'shi Trainer
SET @ENTRY := 23774;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,7000,15000,20000,11,20989,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Sleep'),
(@ENTRY,0,1,0,2,0,100,7,0,30,0,0,11,43292,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Incite Rage at 30% HP');

-- Amani'shi Tribesman
SET @ENTRY := 23582;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,15000,16000,11,42495,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Cyclone Strike on Close'),
(@ENTRY,0,1,0,0,0,100,6,2000,4500,9000,12000,11,36033,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Kick');

-- Amani'shi Warbringer
SET @ENTRY := 23580;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,7,0,30,0,0,11,40743,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP'),
(@ENTRY,0,1,0,61,0,100,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP'),
(@ENTRY,0,2,0,0,0,100,6,2000,4500,12000,14000,11,43273,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,3,4,2,0,100,7,0,20,0,0,11,43274,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dismount Bear at 20% HP'),
(@ENTRY,0,4,5,61,0,100,7,0,0,0,0,43,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dismount Bear at 20% HP'),
(@ENTRY,0,5,0,61,0,100,7,0,0,0,0,19,134217728,0,0,0,0,0,1,0,0,0,0,0,0,0,'Summon Bear at 20% HP'),
(@ENTRY,0,6,0,0,0,100,6,4000,5000,18000,20000,11,42496,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Furious Roar');
-- NPC talk text insert
SET @ENTRY := 23580;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy');

-- Amani'shi Warrior
SET @ENTRY := 24225;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,43519,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,1,0,0,0,100,6,2000,4500,9000,12000,11,43518,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Kick');

-- Amani'shi Wind Walker
SET @ENTRY := 24179;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,6,0,30,20000,30000,11,43527,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chain Heal at 40% HP'),
(@ENTRY,0,1,0,0,0,100,6,2000,4500,12000,14000,11,43524,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frost Shock'),
(@ENTRY,0,2,0,0,0,100,6,0,0,3400,4700,11,43526,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lightning Bolt');

-- Tamed Amani Crocolisk
SET @ENTRY := 24138;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4000,5000,13000,15000,11,43352,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Tail Swipe'),
(@ENTRY,0,1,0,0,0,100,6,2000,3000,12000,18000,11,43353,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Infected Bite');

-- Zandalari Archon
SET @ENTRY := 52962;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,1,2,61,0,100,7,0,0,0,0,11,97977,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blessing of Zandalar on Aggro'),
(@ENTRY,0,2,0,61,0,100,7,0,0,0,0,11,97972,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Glory of the Zandalari on Aggro'),
(@ENTRY,0,3,0,0,0,50,6,9000,9000,25000,25000,11,98018,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Sigil of Death'),
(@ENTRY,0,4,0,0,0,50,6,9000,9000,25000,25000,11,98006,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Sigil of Flame'),
(@ENTRY,0,5,0,0,0,50,6,9000,9000,25000,25000,11,98015,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Sigil of Frost');
-- NPC talk text insert
SET @ENTRY := 52962;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Ancients of Zandalar, mark\'dem for de black road.',14,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,0,1, 'Ancients of Zandalar, grant dis one da ability ta\'mock death itself!',14,0,50,0,0,0, 'on Aggro Text');

-- Zandalari Hierophant
SET @ENTRY := 52958;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,1,2,61,0,100,7,0,0,0,0,11,97977,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blessing of Zandalar on Aggro'),
(@ENTRY,0,2,0,61,0,100,7,0,0,0,0,11,97972,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Glory of the Zandalari on Aggro'),
(@ENTRY,0,3,0,14,0,100,6,200000,55,25000,28000,11,97978,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Ancient Guardian on Friendlies'),
(@ENTRY,0,4,0,2,0,100,6,0,40,22000,25000,11,97974,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sanctify at 40% HP'),
(@ENTRY,0,5,0,0,0,100,6,8000,9000,15000,15000,11,23979,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ancient Power');
-- NPC talk text insert
SET @ENTRY := 52958;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Ancients of Zandalar, mark\'dem for de black road.',14,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,0,1, 'Ancients of Zandalar, grant dis one da ability ta\'mock death itself!',14,0,50,0,0,0, 'on Aggro Text');

-- Zandalari Juggernaut
SET @ENTRY := 52956;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,1,2,61,0,100,7,0,0,0,0,11,97977,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blessing of Zandalar on Aggro'),
(@ENTRY,0,2,0,61,0,100,7,0,0,0,0,11,97972,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Glory of the Zandalari on Aggro'),
(@ENTRY,0,3,0,2,0,100,6,0,50,25000,27000,11,98000,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Ancestral Call at 50% HP'),
(@ENTRY,0,4,0,0,0,100,7,5000,5000,0,0,11,97987,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Tectonic Plating');
-- NPC talk text insert
SET @ENTRY := 52956;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Ancients of Zandalar, mark\'dem for de black road.',14,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,0,1, 'Ancients of Zandalar, grant dis one da ability ta\'mock death itself!',14,0,50,0,0,0, 'on Aggro Text');
