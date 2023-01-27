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
 
-- Ancient Water Lord
SET @ENTRY := 57160;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,4000,5500,13500,15500,11,107791,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flood'),
(@ENTRY,0,1,0,0,0,100,30,7000,9000,25000,27000,11,107801,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Drenched');

-- Claw of Go'rath
SET @ENTRY := 57890;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,5000,7000,14000,18000,11,109396,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Ooze Spit'),
(@ENTRY,0,1,0,0,0,100,30,7000,10000,15000,30000,11,109197,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Tentacle Toss'),
(@ENTRY,0,2,1,4,0,100,31,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving on Aggro');

-- Claw of Go'rath
SET @ENTRY := 55418;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,5000,7000,14000,18000,11,109396,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Ooze Spit'),
(@ENTRY,0,1,0,0,0,100,30,4000,4000,18000,22000,11,104377,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Black Blood of Go\'rath'),
(@ENTRY,0,2,1,4,0,100,31,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving on Aggro');

-- Earthen Destroyer
SET @ENTRY := 57158;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,2000,4500,12000,15000,11,107597,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Boulder Smash'),
(@ENTRY,0,1,0,0,0,100,30,7000,9000,22000,26000,11,107675,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dust Storm'),
(@ENTRY,0,2,0,0,0,100,30,0,0,3400,4700,11,95440,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt');

-- Earthen Soldier
SET @ENTRY := 57159;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,0,0,3400,4700,11,95440,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,1,0,0,0,100,30,8000,9000,24000,28000,11,107852,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Twilight Corruption'),
(@ENTRY,0,2,0,2,0,100,31,0,30,0,0,11,107872,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Twilight Rage at 30% HP');

-- Eye of Go'rath
SET @ENTRY := 57875;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,31,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving on Aggro'),
(@ENTRY,0,1,0,0,0,100,30,7000,9000,18000,20000,11,109391,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Shadow Gaze');

-- Faceless Corruptor
SET @ENTRY := 57749;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,0,0,3400,4700,11,96516,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt');

-- Flail of Go'rath
SET @ENTRY := 57877;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,31,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving on Aggro'),
(@ENTRY,0,1,0,0,0,100,30,2000,4500,12000,13000,11,110102,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sludge Spew'),
(@ENTRY,0,2,0,0,0,100,30,9000,9000,25000,27000,11,109199,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Wild Flail');

-- Twilight Siege Captain <The Twilight's Hammer>
SET @ENTRY := 57280;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,31,1000,1000,1000,1000,11,45846,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Aura on Spawn'),
(@ENTRY,0,1,0,0,0,100,30,2000,4500,14000,16000,11,108183,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Twilight Submission'),
(@ENTRY,0,2,0,0,0,100,30,8000,9000,22000,27000,11,108172,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Twilight Volley');
