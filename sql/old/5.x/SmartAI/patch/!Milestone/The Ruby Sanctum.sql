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
 
-- Charscale Assaulter
SET @ENTRY := 40419;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,15000,16000,24000,25000,11,75417,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shockwave'),
(@ENTRY,0,1,0,9,0,100,30,0,5,12000,15000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave on Close'),
(@ENTRY,0,2,0,2,0,100,30,0,55,25000,28000,11,75416,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rally at 55% HP');

-- Charscale Commander
SET @ENTRY := 40423;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,4000,5000,50000,55000,11,75414,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rallying Shout'),
(@ENTRY,0,1,0,9,0,100,30,0,5,18000,19000,11,13737,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike on Close'),
(@ENTRY,0,2,0,2,0,100,30,0,55,25000,28000,11,75416,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rally at 55% HP');

-- Charscale Elite
SET @ENTRY := 40421;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,5000,7000,18000,22000,11,15621,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Skull Crack');

-- Charscale Invoker
SET @ENTRY := 40417;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,7000,8000,15000,16000,11,75412,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Scorch'),
(@ENTRY,0,1,0,9,0,100,30,0,10,24000,24000,11,75413,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Flame Wave on Close'),
(@ENTRY,0,2,0,2,0,100,30,0,55,25000,28000,11,75416,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rally at 55% HP');

-- Onyx Flamecaller
SET @ENTRY := 39814;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,6000,9000,18000,22000,11,74394,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lava Gout'),
(@ENTRY,0,1,0,9,0,100,30,0,20,20000,20000,11,74392,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blast Nova on Close');
