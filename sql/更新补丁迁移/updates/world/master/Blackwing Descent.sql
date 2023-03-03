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
 
-- Drakonid Chainwielder
SET @ENTRY := 42649;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,7000,8000,18000,24000,11,79589,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Constricting Chains'),
(@ENTRY,0,1,0,0,0,100,30,5000,5000,27000,33000,11,80051,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Grievous Wound'),
(@ENTRY,0,2,0,0,0,100,30,4000,9000,20000,25000,11,79580,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Overhead Smash');

-- Drakonid Drudge
SET @ENTRY := 42362;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,31,0,0,0,0,11,79630,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Drakonid Rush on Aggro'),
(@ENTRY,0,1,0,0,0,100,30,7000,8000,19000,27000,11,79604,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Thunderclap'),
(@ENTRY,0,2,0,2,0,100,31,0,30,0,0,11,80035,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Vengeful Rage at 30% HP');

-- Drakonid Slayer
SET @ENTRY := 42802;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,30,0,10,15000,18000,11,80391,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blast Wave on Close'),
(@ENTRY,0,1,0,9,0,100,30,0,5,9000,14000,11,80392,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave on Close'),
(@ENTRY,0,2,0,0,0,100,30,7000,8000,21000,24000,11,80390,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike');

-- Golem Sentry
SET @ENTRY := 42800;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,7000,9000,18000,20000,11,81055,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Electrical Discharge'),
(@ENTRY,0,1,0,0,0,100,30,5000,5000,16000,22000,11,81056,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Flash Bomb'),
(@ENTRY,0,2,0,0,0,100,30,2000,6000,12000,27000,11,81063,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Laser Strike');

-- Ivoroc
SET @ENTRY := 42767;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,8000,8000,17000,17000,11,80295,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Curse of Mending'),
(@ENTRY,0,1,0,0,0,100,10,4000,4500,14000,15000,11,80270,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadowflame'),
(@ENTRY,0,2,0,0,0,100,20,4000,4500,14000,15000,11,79921,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadowflame');

-- Maimgor
SET @ENTRY := 42768;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,31,0,30,0,0,11,80084,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,1,0,61,0,100,31,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP'),
(@ENTRY,0,2,0,0,0,100,30,8000,9000,20000,20000,11,80145,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Piercing Grip'),
(@ENTRY,0,3,0,0,0,100,30,4000,4500,14000,15000,11,80270,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadowflame'),
(@ENTRY,0,4,0,0,0,100,30,5000,9000,14000,15000,11,80130,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Tail Lash');
-- NPC talk text insert
SET @ENTRY := 42768;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage');

-- Pyrecraw
SET @ENTRY := 42764;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,9000,10000,16000,19500,11,80127,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Buffet'),
(@ENTRY,0,1,0,0,0,100,10,4000,4500,14000,15000,11,80270,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadowflame'),
(@ENTRY,0,2,0,0,0,100,20,4000,4500,14000,15000,11,79921,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadowflame');

-- Spirit of Angerforge
SET @ENTRY := 43119;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,31,0,0,0,0,11,80655,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stoneblood on Aggro'),
(@ENTRY,0,1,0,11,0,100,31,0,0,0,0,11,80762,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spirit of Angerforge on Spawn');

-- Spirit of Anvilrage
SET @ENTRY := 43128;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,10,5000,7000,13000,15000,11,80648,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Stormbolt'),
(@ENTRY,0,1,0,0,0,100,20,5000,7000,13000,15000,11,91890,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Stormbolt'),
(@ENTRY,0,2,0,11,0,100,31,0,0,0,0,11,80768,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spirit of Anvilrage on Spawn');

-- Spirit of Burningeye
SET @ENTRY := 43130;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,30,0,5,15000,17000,11,80652,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirlwind on Close'),
(@ENTRY,0,1,0,11,0,100,31,0,0,0,0,11,80770,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spirit of Burningeye on Spawn');

-- Spirit of Corehammer
SET @ENTRY := 43122;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,30,0,40,30000,34000,11,80718,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Burden of the Crown at 40% HP'),
(@ENTRY,0,1,0,11,0,100,31,0,0,0,0,11,80763,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spirit of Corehammer on Spawn');

-- Spirit of Ironstar
SET @ENTRY := 43127;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,9000,9000,45000,50000,11,80727,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Execution Sentence'),
(@ENTRY,0,1,0,2,0,100,11,0,30,0,0,11,80747,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shield of Light at 30% HP'),
(@ENTRY,0,2,0,2,0,100,21,0,30,0,0,11,95537,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shield of Light at 30% HP'),
(@ENTRY,0,3,0,11,0,100,31,0,0,0,0,11,80767,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spirit of Ironstar on Spawn');

-- Spirit of Moltenfist
SET @ENTRY := 43125;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,10,6000,8000,18000,20000,11,80649,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Thunderclap'),
(@ENTRY,0,1,0,0,0,100,20,6000,8000,18000,20000,11,91889,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Thunderclap'),
(@ENTRY,0,2,0,11,0,100,31,0,0,0,0,11,80764,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spirit of Moltenfist on Spawn');

-- Spirit of Shadowforge
SET @ENTRY := 43129;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,10,5000,5000,14000,17000,11,80646,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Chain Lightning'),
(@ENTRY,0,1,0,0,0,100,20,5000,5000,14000,17000,11,91891,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Chain Lightning'),
(@ENTRY,0,2,0,11,0,100,31,0,0,0,0,11,80769,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spirit of Shadowforge on Spawn');

-- Spirit of Thaurissan
SET @ENTRY := 43126;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,30,0,40,18000,27000,11,80645,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Avatar at 40% HP'),
(@ENTRY,0,1,0,11,0,100,31,0,0,0,0,11,80766,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spirit of Thaurissan on Spawn');
