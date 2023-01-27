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

-- Felflame Infernal
SET @ENTRY := 34815;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,7000,10000,8000,10000,11,66495,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fel Inferno'),
(@ENTRY,0,1,0,0,0,100,30,5000,5000,15000,19000,11,66494,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Fel Streak');

-- Frost Sphere
SET @ENTRY := 34606;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,30,0,6,18000,25000,11,66193,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Permafrost on Close');

-- Mistress of Pain
SET @ENTRY := 34826;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,7000,10000,9000,14000,11,66378,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shivan Slash'),
(@ENTRY,0,1,0,0,0,100,30,5000,5000,12000,17000,11,66283,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Spinning Pain Spike'),
(@ENTRY,0,2,0,0,0,100,24,13000,15000,15000,20000,11,66336,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mistress\' Kiss');

-- Nerubian Burrower
SET @ENTRY := 34607;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,5000,9000,15000,15000,11,66134,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Strike'),
(@ENTRY,0,1,0,2,0,100,30,0,60,17000,21000,11,67721,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Expose Weakness at 60% HP'),
(@ENTRY,0,2,0,0,0,100,30,10000,10000,25000,32000,11,66129,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spider Frenzy'),
(@ENTRY,0,3,0,2,0,100,31,0,20,0,0,11,67322,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Submerge at 20% HP');

-- Skittering Scarab
SET @ENTRY := 35763;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,4000,4500,12000,17000,11,65775,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Acid-Drenched Mandibles');

-- Snobold Vassal
SET @ENTRY := 34800;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,3000,5000,8000,9000,11,66408,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Batter'),
(@ENTRY,0,1,0,0,0,100,30,5000,7000,7000,12000,11,66407,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Head Crack'),
(@ENTRY,0,2,0,0,0,100,30,10000,15000,10000,16000,11,66313,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Fire Bomb'),
(@ENTRY,0,3,0,2,0,100,31,0,30,0,0,11,66636,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rising Anger at 30% HP');

-- Swarm Scarab
SET @ENTRY := 34605;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,4000,4500,12000,17000,11,65775,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Acid-Drenched Mandibles'),
(@ENTRY,0,1,0,0,0,100,31,10000,15000,0,0,11,66092,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Determination');
