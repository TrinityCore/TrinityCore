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
	
-- Dark Ranger Marrah
SET @ENTRY := 24137;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,100,100,0,0,11,34189,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Spawn');

-- Dragonflayer Bonecrusher
SET @ENTRY := 24069;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,12000,19000,11,9791,0,0,0,0,0,5,32,0,0,0,0,0,0,'Cast Head Crack on Close'),
(@ENTRY,0,1,0,9,0,100,4,0,5,12000,19000,11,59599,0,0,0,0,0,5,32,0,0,0,0,0,0,'Cast Head Crack on Close'),
(@ENTRY,0,2,0,0,0,100,6,8000,12000,14000,17000,11,43935,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Knockdown Spin');

-- Dragonflayer Heartsplitter
SET @ENTRY := 24071;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,43665,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,1,2,2,0,100,7,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,7,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,0,0,100,4,0,0,2300,3900,11,59603,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,4,0,9,0,100,2,0,5,11000,14000,11,32908,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wing Clip on Close'),
(@ENTRY,0,5,0,0,0,100,2,6000,7500,11000,17000,11,31551,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Piercing Jab'),
(@ENTRY,0,6,0,9,0,100,4,0,5,11000,14000,11,59604,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wing Clip on Close'),
(@ENTRY,0,7,0,0,0,100,4,6000,7500,11000,17000,11,59605,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Piercing Jab');
-- NPC talk text insert
SET @ENTRY := 24071;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Dragonflayer Ironhelm
SET @ENTRY := 23961;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4500,5000,8500,10000,11,42780,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ringing Slap'),
(@ENTRY,0,1,0,9,0,100,2,0,5,7000,11000,11,57846,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Strike Close'),
(@ENTRY,0,2,0,0,0,100,4,4500,5000,8500,10000,11,59606,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ringing Slap'),
(@ENTRY,0,3,0,9,0,100,4,0,5,7000,11000,11,59607,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Strike Close');

-- Dragonflayer Metalworker
SET @ENTRY := 24078;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,7,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,1,0,2,0,100,7,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP'),
(@ENTRY,0,2,0,9,0,100,2,0,5,5000,9000,11,15572,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sunder Armor on Close'),
(@ENTRY,0,3,0,9,0,100,4,0,5,5000,9000,11,59608,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sunder Armor on Close');
-- NPC talk text insert
SET @ENTRY := 24078;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage');

-- Dragonflayer Overseer
SET @ENTRY := 24085;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,3000,18000,20000,11,38232,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Battle Shout'),
(@ENTRY,0,1,0,0,0,100,4,2000,3000,18000,20000,11,59614,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Battle Shout'),
(@ENTRY,0,2,0,4,0,100,3,0,0,0,0,11,35570,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,3,0,4,0,100,5,0,0,0,0,11,59611,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,4,0,0,0,100,2,7500,8000,20000,30000,11,16244,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Battle Shout'),
(@ENTRY,0,5,0,0,0,100,4,7500,8000,20000,30000,11,59613,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Battle Shout');

-- Frenzied Geist
SET @ENTRY := 28419;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,40414,0,0,0,0,0,2,1,0,0,0,0,0,0,'Cast Fixate on Aggro');

-- Savage Worg
SET @ENTRY := 29735;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,55077,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pounce on Aggro'),
(@ENTRY,0,1,0,2,0,100,7,0,60,0,0,11,42745,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 60% HP'),
(@ENTRY,0,2,0,2,0,100,7,0,60,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 60% HP');
-- NPC talk text insert
SET @ENTRY := 29735;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage');

-- Tunneling Ghoul
SET @ENTRY := 24084;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,1000,2000,8000,12000,11,42702,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Decrepify'),
(@ENTRY,0,1,0,0,0,100,6,5500,6500,14600,17800,11,13446,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike');

-- Skarvald the Constructor
SET @ENTRY := 27390;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,43651,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,1,0,0,0,100,6,6000,9000,16000,21000,11,48583,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Stone Strike');

-- Dragonflayer Runecaster
SET @ENTRY := 23960;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,6000,6000,12000,12000,11,54965,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bolthorn\'s Rune of Flame'),
(@ENTRY,0,1,0,0,0,100,4,6000,6000,12000,12000,11,59617,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bolthorn\'s Rune of Flame'),
(@ENTRY,0,2,0,16,0,100,2,42740,100,17000,25000,11,42740,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Njord\'s Rune of Protection on Friendlies'),
(@ENTRY,0,3,0,16,0,100,2,59616,100,17000,25000,11,59616,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Njord\'s Rune of Protection on Friendlies');

-- Proto-Drake Rider
SET @ENTRY := 24849;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,43665,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,1,2,2,0,100,7,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,7,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,0,0,100,4,0,0,2300,3900,11,59603,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,4,0,9,0,100,2,0,5,11000,14000,11,32908,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wing Clip on Close'),
(@ENTRY,0,5,0,0,0,100,2,6000,7500,11000,17000,11,31551,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Piercing Jab'),
(@ENTRY,0,6,0,9,0,100,4,0,5,11000,14000,11,59604,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wing Clip on Close'),
(@ENTRY,0,7,0,0,0,100,4,6000,7500,11000,17000,11,59605,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Piercing Jab');
-- NPC talk text insert
SET @ENTRY := 24849;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Dragonflayer Spiritualist
SET @ENTRY := 28410;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,3400,4700,11,51587,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,2,2,0,100,7,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,7,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,14,0,100,6,7000,100,7000,7000,11,51586,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Healing Wave on Friendlies'),
(@ENTRY,0,4,0,0,0,100,6,1500,4000,8000,10000,11,51588,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Shock');
-- NPC talk text insert
SET @ENTRY := 28410;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Dragonflayer Weaponsmith
SET @ENTRY := 24080;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,8000,11000,11,42724,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave on Close'),
(@ENTRY,0,1,0,0,0,100,4,8000,8500,9000,11000,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Disarm'),
(@ENTRY,0,2,0,0,0,100,6,3500,3500,12000,16000,11,22427,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Concussion Blow');

-- Enslaved Proto-Drake
SET @ENTRY := 24083;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3500,6000,7000,8500,11,49722,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Knock Away'),
(@ENTRY,0,1,0,9,0,100,2,0,5,17000,21000,11,43931,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rend on Close'),
(@ENTRY,0,2,0,9,0,100,4,0,5,17000,21000,11,59691,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rend on Close'),
(@ENTRY,0,3,0,0,0,100,2,5500,7000,11000,12000,11,50653,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Breath'),
(@ENTRY,0,4,0,0,0,100,4,5500,7000,11000,12000,11,59692,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Breath');

-- Dragonflayer Strategist
SET @ENTRY := 23956;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,42772,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,1,2,2,0,100,7,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,7,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,0,0,100,4,0,0,2300,3900,11,59685,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,4,0,0,0,100,2,4500,5000,11000,16000,11,54962,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Ticking Bomb'),
(@ENTRY,0,5,0,0,0,100,4,4500,5000,11000,16000,11,60227,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Ticking Time Bomb'),
(@ENTRY,0,6,0,0,0,100,6,7500,9000,13000,15000,11,42972,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Blind');
-- NPC talk text insert
SET @ENTRY := 23956;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Proto-Drake Handler
SET @ENTRY := 24082;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,54983,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,1,2,2,0,100,7,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,7,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,0,0,100,4,0,0,2300,3900,11,59696,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,4,0,0,0,100,2,2000,3000,8000,9500,11,38621,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Debilitating Strike'),
(@ENTRY,0,5,0,0,0,100,4,2000,3000,8000,9500,11,59695,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Debilitating Strike'),
(@ENTRY,0,6,0,16,0,100,2,43664,100,15000,21000,11,43664,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Unholy Rage on Friendlies'),
(@ENTRY,0,7,0,16,0,100,4,43664,100,15000,21000,11,59694,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Unholy Rage on Friendlies');
-- NPC talk text insert
SET @ENTRY := 24082;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');
