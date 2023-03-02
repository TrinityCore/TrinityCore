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
	
-- Bog Overlord
SET @ENTRY := 21694;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,37266,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Disease Cloud on Spawn'),
(@ENTRY,0,1,0,11,0,100,5,0,0,0,0,11,37863,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Disease Cloud on Spawn'),
(@ENTRY,0,2,0,9,0,100,2,0,5,4000,6000,11,37272,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Poison Bolt on Close'),
(@ENTRY,0,3,0,9,0,100,4,0,5,4000,6000,11,37862,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Poison Bolt on Close'),
(@ENTRY,0,4,0,0,0,100,6,2000,5000,12000,19000,11,32065,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fungal Decay'),
(@ENTRY,0,5,0,0,0,100,6,7000,9500,12000,15000,11,40340,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Trample'),
(@ENTRY,0,6,0,2,0,100,7,0,20,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 20% HP'),
(@ENTRY,0,7,0,2,0,100,7,0,20,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 20% HP');
-- NPC talk text insert
SET @ENTRY := 21694;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage');

-- Coilfang Engineer
SET @ENTRY := 17721;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,6000,8000,9000,13000,11,40331,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bomb'),
(@ENTRY,0,1,0,0,0,100,4,6000,8000,9000,13000,11,40332,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bomb'),
(@ENTRY,0,2,0,0,0,100,6,4000,6000,5000,7000,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Net');

-- Coilfang Leper
SET @ENTRY := 21338;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,2,2,0,100,7,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,7,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,0,0,100,4,0,0,3400,4700,11,12739,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,4,0,9,0,100,2,0,8,13600,14500,11,11831,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Nova on Close'),
(@ENTRY,0,5,0,9,0,100,4,0,8,13600,14500,11,15063,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Nova on Close'),
(@ENTRY,0,6,0,2,0,100,2,0,40,10000,14000,11,11642,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Heal at 40% HP'),
(@ENTRY,0,7,0,2,0,100,4,0,40,10000,14000,11,15586,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Heal at 40% HP'),
(@ENTRY,0,8,0,0,0,100,2,5000,7000,7000,9000,11,13339,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fire Blast'),
(@ENTRY,0,9,0,0,0,100,4,5000,7000,7000,9000,11,14145,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fire Blast');
-- NPC talk text insert
SET @ENTRY := 21338;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Coilfang Myrmidon
SET @ENTRY := 17800;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,6000,10000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave on Close'),
(@ENTRY,0,1,0,12,0,100,6,0,20,9000,13000,11,77720,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Execute when Target is 20% HP');

-- Coilfang Oracle
SET @ENTRY := 17803;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,8000,13000,16000,11,22582,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frost Shock'),
(@ENTRY,0,1,0,0,0,100,4,5000,8000,13000,16000,11,37865,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frost Shock'),
(@ENTRY,0,2,0,14,0,100,2,13200,40,9000,14000,11,31730,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Heal on Friendlies'),
(@ENTRY,0,3,0,14,0,100,4,13200,40,9000,14000,11,22883,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Heal on Friendlies'),
(@ENTRY,0,4,0,0,0,100,6,9000,12000,14000,18000,11,8281,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sonic Burst');

-- Coilfang Siren
SET @ENTRY := 17801;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,15234,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,2,2,0,100,7,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,7,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,0,0,100,4,0,0,3400,4700,11,37664,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,4,0,0,0,100,2,9000,12000,15000,17000,11,35106,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Flare'),
(@ENTRY,0,5,0,0,0,100,4,9000,12000,15000,17000,11,37856,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Flare'),
(@ENTRY,0,6,0,0,0,100,6,9000,13000,10000,14000,11,38660,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Fear');
-- NPC talk text insert
SET @ENTRY := 17801;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Coilfang Slavemaster
SET @ENTRY := 17805;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4000,7000,11000,15000,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Disarm'),
(@ENTRY,0,1,0,0,0,100,6,8000,12000,12000,15000,11,10987,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Geyser'),
(@ENTRY,0,2,0,2,0,100,7,0,20,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 20% HP'),
(@ENTRY,0,3,0,2,0,100,7,0,20,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 20% HP');
-- NPC talk text insert
SET @ENTRY := 17805;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy');

-- Coilfang Sorceress
SET @ENTRY := 17722;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,12675,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,2,2,0,100,7,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,7,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,0,0,100,4,0,0,3400,4700,11,37930,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,4,0,0,0,100,2,18000,20000,25000,27000,11,39416,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Blizzard'),
(@ENTRY,0,5,0,0,0,100,4,18000,20000,25000,27000,11,31581,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Blizzard'),
(@ENTRY,0,6,0,9,0,100,2,0,8,13000,18000,11,15063,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Nova on Close'),
(@ENTRY,0,7,0,9,0,100,4,0,8,13000,18000,11,15531,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Nova on Close');
-- NPC talk text insert
SET @ENTRY := 17722;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Coilfang Warrior
SET @ENTRY := 17802;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,7164,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Defensive Stance on Aggro'),
(@ENTRY,0,1,0,0,0,100,6,1000,5000,9000,15000,11,31403,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Battle Shout'),
(@ENTRY,0,2,0,0,0,100,6,4000,7000,12000,16000,11,35105,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Blow');

-- Coilfang Water Elemental
SET @ENTRY := 17917;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,7000,15000,21000,11,34449,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Water Bolt Volley'),
(@ENTRY,0,1,0,0,0,100,4,5000,7000,15000,21000,11,37924,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Water Bolt Volley');

-- Dreghood Slave
SET @ENTRY := 17799;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,7,0,30,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP'),
(@ENTRY,0,1,0,2,0,100,7,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP');
-- NPC talk text insert
SET @ENTRY := 17799;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy');


-- Steam Surger
SET @ENTRY := 21696;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,7000,9000,15000,18000,11,37252,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Water Bolt'),
(@ENTRY,0,1,0,0,0,100,4,7000,9000,15000,18000,11,39412,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Water Bolt');

-- Steamrigger Mechanic
SET @ENTRY := 17951;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4000,15000,16000,11,17201,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dispel Magic');

-- Tidal Surger
SET @ENTRY := 21695;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3000,7000,14000,18000,11,37250,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Water Spout'),
(@ENTRY,0,1,0,9,0,100,6,0,8,12000,17000,11,15531,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Nova on Close');

