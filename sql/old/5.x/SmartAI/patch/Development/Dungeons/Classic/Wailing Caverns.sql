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
 
-- Lady Anacondra <Fanglord>
SET @ENTRY := 3671;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,20295,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,2,8000,12000,12000,25000,11,8040,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Druid\'s Slumber'),
(@ENTRY,0,2,0,0,0,100,2,1000,1000,75000,90000,11,8148,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thorns Aura'),
(@ENTRY,0,3,0,1,0,100,3,1000,1000,1000,1000,11,39550,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Aura on Spawn'),
(@ENTRY,0,4,0,14,0,100,2,800,40,17000,21000,11,23381,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Healing Touch on Friendlies'),
(@ENTRY,0,5,0,2,0,100,3,0,30,0,0,11,23381,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Healing Touch at 30% HP');

-- Lord Pythas <Fanglord>
SET @ENTRY := 3670;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,20805,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,14,0,100,2,800,40,17000,21000,11,11431,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Healing Touch on Friendlies'),
(@ENTRY,0,2,0,2,0,100,3,0,30,0,0,11,11431,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Healing Touch at 30% HP'),
(@ENTRY,0,3,0,0,0,100,2,8000,12000,12000,25000,11,8040,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Druid\'s Slumber'),
(@ENTRY,0,4,0,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,5,0,0,0,100,2,5000,9000,12000,15000,11,8147,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thunderclap');
-- NPC talk text insert
SET @ENTRY := 3670;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'The coils of death... Will crush you.',14,0,100,0,0,5787, 'combat Say');

-- Lord Serpentis <Fanglord>
SET @ENTRY := 3673;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,12167,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,2,0,100,3,0,50,0,0,11,23381,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Healing Touch at 50% HP'),
(@ENTRY,0,2,0,0,0,100,2,8000,12000,12000,25000,11,8040,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Druid\'s Slumber'),
(@ENTRY,0,3,0,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro');
-- NPC talk text insert
SET @ENTRY := 3673;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'I am the serpent king! I can do anything.',14,0,100,0,0,5788, 'combat Say');

-- Mutanus the Devourer
SET @ENTRY := 3654;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,15000,21000,18000,24000,11,7399,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Terrify'),
(@ENTRY,0,1,0,0,0,100,2,6000,11000,25000,36000,11,7967,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Naralex\'s Nightmare'),
(@ENTRY,0,2,0,0,0,100,2,10000,14000,10000,16000,11,8150,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thundercrack');

-- Skum
SET @ENTRY := 3674;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,30,4000,7000,11,6254,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Chained Bolt on Close');

-- Verdan the Everliving
SET @ENTRY := 5775;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,8,13000,16000,11,8142,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Grasping Vines on Close');

-- Lord Cobrahn <Fanglord>
SET @ENTRY := 3669;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,0,0,100,2,0,0,3400,4700,11,20805,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,2,0,2,0,100,3,0,50,0,0,11,23381,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Healing Touch at 50% HP'),
(@ENTRY,0,3,0,0,0,100,2,10000,10000,13000,20000,11,8040,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Druid\'s Slumber'),
(@ENTRY,0,4,0,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,5,0,14,0,100,2,800,40,18000,24000,11,23381,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Healing Touch on Friendlies'),
(@ENTRY,0,6,7,2,0,100,3,0,30,0,0,11,7965,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Cobrahn Serpent Form at 30% HP'),
(@ENTRY,0,7,0,61,0,100,3,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 1 at 30% HP'),
(@ENTRY,0,8,0,0,1,100,2,3000,4000,16000,18000,11,744,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Poison'),
(@ENTRY,0,9,0,7,1,100,3,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset on Evade');
-- NPC talk text insert
SET @ENTRY := 3669;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'You will never wake the dreamer!',14,0,100,0,0,5785, 'combat Say');

-- Biletoad
SET @ENTRY := 3835;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,3,0,0,0,0,11,10251,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Biletoad Infection on Death');

-- Boahn <Druid of the Fang>
SET @ENTRY := 3672;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,2,2,0,100,3,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,3,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,2,0,100,3,0,30,0,0,11,23381,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Healing Touch at 30% HP');
-- NPC talk text insert
SET @ENTRY := 3672;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Deviate Adder
SET @ENTRY := 5048;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,4000,16000,17000,11,744,0,0,0,0,0,2,32,0,0,0,0,0,0,'Cast Poison');

-- Deviate Creeper
SET @ENTRY := 3632;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,5000,6000,10000,11,3427,0,0,0,0,0,2,32,0,0,0,0,0,0,'Cast Infected Wound');

-- Deviate Crocolisk
SET @ENTRY := 5053;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,9000,12000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Tendon Rip on Close');

-- Deviate Lasher
SET @ENTRY := 5055;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,7000,10000,11,7342,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wide Slash on Close');

-- Deviate Shambler
SET @ENTRY := 5761;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,3,0,50,0,0,11,7948,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Wild Regeneration at 50% HP');

-- Deviate Slayer
SET @ENTRY := 3633;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,9000,14000,11,7938,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fatal Bite at 40% HP');

-- Deviate Dreadfang
SET @ENTRY := 7399;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,9000,15000,11,7399,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Terrify on Close');

-- Deviate Stinglash
SET @ENTRY := 3631;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,7000,12000,20000,11,6607,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lash');

-- Deviate Venomwing
SET @ENTRY := 5756;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3500,4100,11,7951,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Toxic Spit');

-- Deviate Viper
SET @ENTRY := 5755;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,8000,10000,16000,11,7947,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Localized Toxin');

-- Deviate Stalker
SET @ENTRY := 3634;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,22766,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sneak on Spawn');

-- Devouring Ectoplasm
SET @ENTRY := 3638;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,3,0,50,0,0,11,7952,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Clone at 50% HP');

-- Druid of the Fang
SET @ENTRY := 3840;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,0,0,100,2,0,0,3400,4700,11,20805,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,2,0,2,0,100,3,0,50,0,0,11,23381,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Healing Touch at 50% HP'),
(@ENTRY,0,3,0,0,0,100,2,10000,10000,13000,20000,11,8040,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Druid\'s Slumber'),
(@ENTRY,0,4,0,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,5,0,14,0,100,2,800,40,18000,24000,11,23381,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Healing Touch on Friendlies'),
(@ENTRY,0,6,7,2,0,100,3,0,30,0,0,11,7965,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Cobrahn Serpent Form at 30% HP'),
(@ENTRY,0,7,0,61,0,100,3,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 1 at 30% HP'),
(@ENTRY,0,8,0,0,1,100,2,3000,4000,16000,18000,11,744,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Poison'),
(@ENTRY,0,9,0,7,1,100,3,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset on Evade'),
(@ENTRY,0,10,0,1,0,100,3,1000,1000,1000,1000,11,39550,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Aura on Spawn');
-- NPC talk text insert
SET @ENTRY := 3840;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

