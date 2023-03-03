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
 
  /* Raid Normal for 25 people */
 /* Trash Mobs */
 
-- Hellfire Warder
SET @ENTRY := 18829;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,9000,18000,27000,11,39175,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley'),
(@ENTRY,0,1,0,9,0,100,2,0,8,20000,23500,11,34436,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Burst on Close'),
(@ENTRY,0,2,0,0,0,100,2,2000,7000,12000,19000,11,34439,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Unstable Affliction'),
(@ENTRY,0,3,0,0,0,100,2,5000,12000,22000,28000,11,34435,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Rain of Fire'),
(@ENTRY,0,4,0,0,0,100,2,9000,17000,14500,21500,11,34437,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Death Coil'),
(@ENTRY,0,5,0,0,0,100,2,21000,27000,28000,35000,11,34441,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Shadow Word: Pain');

