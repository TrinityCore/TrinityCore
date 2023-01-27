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
	
-- Argent Battleworg
SET @ENTRY := 36558;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,68282,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,1,0,9,0,100,6,5,25,12000,14000,11,62575,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Shield-Breaker on Close');

-- Argent Warhorse
SET @ENTRY := 36557;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,68282,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,1,0,9,0,100,6,5,25,12000,14000,11,62575,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Shield-Breaker on Close');

-- Risen Champion <Black Knight's Minion>
SET @ENTRY := 35590;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3500,4500,11300,12800,11,67774,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Claw'),
(@ENTRY,0,1,0,0,0,100,4,3500,4500,11300,12800,11,67879,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Claw'),
(@ENTRY,0,2,0,6,0,100,3,0,0,0,0,11,67729,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Explode on Death'),
(@ENTRY,0,4,0,6,0,100,5,0,0,0,0,11,67886,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Explode on Death');

-- Risen Jaeren Sunsworn <Black Knight's Minion>
SET @ENTRY := 35545;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3500,4500,11300,12800,11,67774,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Claw'),
(@ENTRY,0,1,0,0,0,100,4,3500,4500,11300,12800,11,67879,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Claw'),
(@ENTRY,0,2,0,6,0,100,3,0,0,0,0,11,67729,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Explode on Death'),
(@ENTRY,0,4,0,6,0,100,5,0,0,0,0,11,67886,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Explode on Death'),
(@ENTRY,0,5,0,4,0,100,3,0,0,0,0,11,67749,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Leap on Aggro'),
(@ENTRY,0,6,0,4,0,100,5,0,0,0,0,11,67880,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Leap on Aggro');
