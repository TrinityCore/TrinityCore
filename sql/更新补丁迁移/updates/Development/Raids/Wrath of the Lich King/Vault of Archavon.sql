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
 
  /* Raid Normal for 10 & 25 people */
 /* Trash Mobs */
 
-- Archavon Warder
SET @ENTRY := 32353;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,7000,5000,12000,11,60897,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Crush'),
(@ENTRY,0,1,0,0,0,100,4,5000,7000,5000,12000,11,60899,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Crush'),
(@ENTRY,0,2,0,0,0,100,2,8000,10000,17000,20000,11,60902,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirl'),
(@ENTRY,0,3,0,0,0,100,4,8000,10000,17000,20000,11,60916,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirl'),
(@ENTRY,0,4,0,0,0,100,2,10000,15000,15000,25000,11,60919,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Rock Shower'),
(@ENTRY,0,5,0,0,0,100,4,10000,15000,15000,25000,11,60923,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Rock Shower');

-- Flame Warder
SET @ENTRY := 35143;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,8000,4000,7000,11,66813,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Lava Burst'),
(@ENTRY,0,1,0,0,0,100,6,10000,15000,12000,25000,11,66808,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Meteor Fists');

-- Frost Warder
SET @ENTRY := 38482;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,9000,8000,9000,11,72123,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Frost Blast'),
(@ENTRY,0,1,0,11,0,100,7,0,0,0,0,11,72122,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frozen Mallet on Spawn');

-- Tempest Minion
SET @ENTRY := 34049;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,8000,4000,7000,11,64363,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Shock'),
(@ENTRY,0,1,0,0,0,100,6,10000,12000,18000,22000,11,64217,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Overcharged');

-- Tempest Minion
SET @ENTRY := 33998;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,8000,4000,7000,11,64363,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Shock'),
(@ENTRY,0,1,0,0,0,100,6,10000,12000,18000,22000,11,64217,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Overcharged');

-- Tempest Warder
SET @ENTRY := 34015;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,8000,4000,7000,11,64363,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Shock'),
(@ENTRY,0,1,0,0,0,100,6,10000,12000,18000,22000,11,64217,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Overcharged');
