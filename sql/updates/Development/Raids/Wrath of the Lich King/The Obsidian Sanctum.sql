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

-- Onyx Blaze Mistress
SET @ENTRY := 30681;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,12000,13000,11,39529,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Shock'),
(@ENTRY,0,1,0,0,0,100,4,5000,5000,12000,13000,11,58940,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Shock'),
(@ENTRY,0,2,0,0,0,100,2,8000,8000,26000,29000,11,57757,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Rain of Fire'),
(@ENTRY,0,3,0,0,0,100,4,8000,8000,26000,29000,11,58936,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Rain of Fire'),
(@ENTRY,0,4,0,0,0,100,6,3000,11000,8000,17000,11,57753,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Conjure Flame Orb');

-- Onyx Brood General
SET @ENTRY := 30680;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,57740,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Devotion Aura on Aggro'),
(@ENTRY,0,1,0,4,0,100,5,0,0,0,0,11,58944,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Devotion Aura on Aggro'),
(@ENTRY,0,2,0,0,0,100,6,4500,4500,11500,13500,11,13737,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike Shock'),
(@ENTRY,0,3,0,0,0,100,7,6000,6000,0,0,11,57742,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Avenging Fury Shock'),
(@ENTRY,0,4,0,2,0,100,3,0,30,0,0,11,57733,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Draconic Rage at 30% HP'),
(@ENTRY,0,5,0,2,0,100,5,0,30,0,0,11,58942,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Draconic Rage at 30% HP');

-- Onyx Flight Captain
SET @ENTRY := 30682;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,5000,12000,14000,11,58953,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pummel'),
(@ENTRY,0,1,0,0,0,100,6,8000,9000,28000,34000,11,57759,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hammer Drop');

-- Onyx Sanctum Guardian
SET @ENTRY := 30453;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,5500,35000,41000,11,58948,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Curse of Mending'),
(@ENTRY,0,1,0,0,0,100,4,4000,5500,35000,41000,11,39647,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Curse of Mending'),
(@ENTRY,0,2,0,0,0,100,2,9000,9000,17800,19300,11,57728,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shockwave'),
(@ENTRY,0,3,0,0,0,100,4,9000,9000,17800,19300,11,58947,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shockwave'),
(@ENTRY,0,4,0,2,0,100,7,0,30,0,0,11,53801,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP'),
(@ENTRY,0,5,0,2,0,100,7,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP');
-- NPC talk text insert
SET @ENTRY := 30453;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy');

