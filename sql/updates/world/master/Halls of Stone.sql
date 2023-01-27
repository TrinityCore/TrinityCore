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
	
-- Dark Rune Controller
SET @ENTRY := 27966;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,51507,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Shardling on Aggro'),
(@ENTRY,0,1,0,0,0,100,6,5000,10000,17000,25000,11,51503,0,0,0,0,0,5,1,0,0,0,0,0,0,'Cast Domination'),
(@ENTRY,0,2,0,16,0,100,6,51805,15,14000,17000,11,51805,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Crystalline Growth on Friendlies');

-- Dark Rune Elementalist
SET @ENTRY := 27962;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,53314,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,59024,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,2,0,16,0,100,2,51776,1,15000,30000,11,51776,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lightning Shield on Repeat'),
(@ENTRY,0,3,0,1,0,100,2,500,1000,600000,600000,11,51776,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lightning Shield on Spawn'),
(@ENTRY,0,4,0,16,0,100,4,59025,1,15000,30000,11,59025,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lightning Shield on Repeat'),
(@ENTRY,0,5,0,1,0,100,4,500,1000,600000,600000,11,59025,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lightning Shield on Spawn'),
(@ENTRY,0,6,0,2,0,100,7,0,30,0,0,11,32693,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Haste at 30% HP'),
(@ENTRY,0,7,0,1,0,100,7,1000,1000,0,0,11,51475,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Air Elemental on Spawn');

-- Dark Rune Giant
SET @ENTRY := 27969;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,7,0,30,0,0,11,51494,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Iron Fist at 30% HP'),
(@ENTRY,0,1,0,0,0,100,2,3000,6000,16000,21000,11,51493,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stomp'),
(@ENTRY,0,2,0,0,0,100,4,3000,6000,16000,21000,11,59026,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stomp');

-- Forged Iron Dwarf
SET @ENTRY := 27982;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,6000,12000,13000,11,50895,0,0,0,0,0,2,1,0,0,0,0,0,0,'Cast Lightning Tether'),
(@ENTRY,0,1,0,0,0,100,4,5000,6000,12000,13000,11,59851,0,0,0,0,0,2,1,0,0,0,0,0,0,'Cast Lightning Tether');

-- Forged Iron Trogg
SET @ENTRY := 27979;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,6000,12000,13000,11,50895,0,0,0,0,0,2,1,0,0,0,0,0,0,'Cast Lightning Tether'),
(@ENTRY,0,1,0,0,0,100,4,5000,6000,12000,13000,11,59851,0,0,0,0,0,2,1,0,0,0,0,0,0,'Cast Lightning Tether');

-- Iron Golem Custodian
SET @ENTRY := 27985;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3000,3000,11000,11000,11,33661,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crush Armor'),
(@ENTRY,0,1,0,0,0,100,2,5500,5800,14600,17800,11,12734,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Ground Smash'),
(@ENTRY,0,2,0,0,0,100,4,5500,5800,14600,17800,11,59865,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Ground Smash');

-- Lesser Air Elemental
SET @ENTRY := 28384;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,3400,4700,11,15801,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt');

-- Lightning Construct
SET @ENTRY := 27972;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,6000,9000,15000,11,52383,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Chain Lightning'),
(@ENTRY,0,1,0,0,0,100,4,3000,6000,9000,15000,11,61528,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Chain Lightning'),
(@ENTRY,0,2,0,0,0,100,2,8800,9900,17800,19200,11,52341,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Electrical Overload'),
(@ENTRY,0,3,0,0,0,100,4,8800,9900,17800,19200,11,59038,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Electrical Overload');

-- Raging Construct
SET @ENTRY := 27970;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4000,7000,9000,12000,11,28168,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcing Smash'),
(@ENTRY,0,1,0,0,0,100,2,10000,20000,30000,45000,11,51819,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Potent Jolt'),
(@ENTRY,0,2,0,0,0,100,4,10000,20000,30000,45000,11,61514,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Potent Jolt');

-- Unrelenting Construct
SET @ENTRY := 27971;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,3,0,10,0,0,11,51832,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Short Circuit at 10% HP'),
(@ENTRY,0,1,0,2,0,100,5,0,10,0,0,11,61513,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Short Circuit at 10% HP'),
(@ENTRY,0,2,0,0,0,100,2,4000,7000,9000,16000,11,51491,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Unrelenting Strike'),
(@ENTRY,0,3,0,0,0,100,4,4000,7000,9000,16000,11,59039,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Unrelenting Strike'),
(@ENTRY,0,4,0,4,0,100,3,0,0,0,0,11,51842,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,5,0,4,0,100,5,0,0,0,0,11,59040,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Charge on Aggro');

-- Dark Rune Worker
SET @ENTRY := 27961;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,45000,45000,11,46202,0,0,0,0,0,2,32,0,0,0,0,0,0,'Cast Pierce Armor on Close'),
(@ENTRY,0,1,0,2,0,100,7,0,30,0,0,11,51499,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Disgruntled Anger at 30% HP');

-- Dark Rune Stormcaller
SET @ENTRY := 27984;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,12167,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,59863,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,2,0,0,0,100,2,5500,5500,12000,19000,11,15654,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Shadow Word: Pain'),
(@ENTRY,0,3,0,0,0,100,4,5500,5500,12000,19000,11,59864,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Shadow Word: Pain');

-- Dark Rune Scholar
SET @ENTRY := 27964;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,13,0,100,2,13000,16000,0,0,11,51612,0,0,0,0,0,6,1,0,0,0,0,0,0,'Cast Static Arrest on Target Spellcast'),
(@ENTRY,0,1,0,13,0,100,4,13000,16000,0,0,11,59033,0,0,0,0,0,6,1,0,0,0,0,0,0,'Cast Static Arrest on Target Spellcast'),
(@ENTRY,0,2,0,4,0,100,7,0,0,0,0,11,51799,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Runic Intellect on Aggro');

-- Dark Rune Protector
SET @ENTRY := 27983;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,22120,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,1,0,0,0,100,6,6000,6000,13500,17800,11,42724,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave');

-- Dark Rune Theurgist
SET @ENTRY := 27963;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,15801,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,35010,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,2,0,0,0,100,2,9000,12000,9000,12000,11,53167,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Forked Lightning'),
(@ENTRY,0,3,0,0,0,100,4,9000,12000,9000,12000,11,59152,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Forked Lightning'),
(@ENTRY,0,4,0,2,0,100,7,0,30,0,0,11,51484,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Iron Might at 30% HP');

-- Dark Rune Warrior
SET @ENTRY := 27960;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,9000,12000,9000,12000,11,42724,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,1,0,0,0,100,2,5000,8000,9000,12000,11,53395,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Strike'),
(@ENTRY,0,2,0,0,0,100,4,5000,8000,9000,12000,11,59035,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Strike');

-- Dark Rune Shaper
SET @ENTRY := 27965;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,51496,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,59034,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,2,0,1,0,100,7,1000,1000,1000,1000,11,67040,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Aura on Spawn');
