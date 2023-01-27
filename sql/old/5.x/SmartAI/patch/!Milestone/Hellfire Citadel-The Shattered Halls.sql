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
    /* Bosses */
	
-- Blood Guard Porung
SET @ENTRY := 20923;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,4,0,5,9000,12000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave on Close');
	
    /* Trash Mobs */
	
-- Creeping Ooze
SET @ENTRY := 17356;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3000,6000,8000,12000,11,30494,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sticky Ooze');

-- Creeping Oozeling
SET @ENTRY := 17357;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3000,6000,8000,12000,11,30494,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sticky Ooze');
	
-- Fel Orc Convert
SET @ENTRY := 17083;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,3500,14000,20000,11,30478,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hemorrhage');

-- Heathen Guard
SET @ENTRY := 17621;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,6000,10000,10000,14000,11,30474,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bloodthirst'),
(@ENTRY,0,1,0,0,0,100,4,6000,10000,10000,14000,11,30475,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bloodthirst'),
(@ENTRY,0,2,0,2,0,100,7,0,30,0,0,11,30485,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,3,0,2,0,100,7,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP');
-- NPC talk text insert
SET @ENTRY := 17621;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage');

-- Rabid Warhound
SET @ENTRY := 17669;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,4000,6000,11,30639,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Carnivorous Bite on Close'),
(@ENTRY,0,1,0,0,0,100,2,2000,6000,12000,16000,11,30636,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Furious Howl'),
(@ENTRY,0,2,0,0,0,100,4,2000,6000,12000,16000,11,35942,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Furious Howl');

-- Reaver Guard
SET @ENTRY := 17623;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,6000,9000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave on Close'),
(@ENTRY,0,1,0,0,0,100,6,7000,11000,11000,15000,11,30471,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Uppercut'),
(@ENTRY,0,2,0,2,0,100,7,0,30,0,0,11,30485,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,3,0,2,0,100,7,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP');
-- NPC talk text insert
SET @ENTRY := 17623;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage');
	
-- Shadowmoon Acolyte
SET @ENTRY := 16594;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,31516,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mind Blast'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,15587,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mind Blast'),
(@ENTRY,0,2,0,1,0,100,6,500,1000,3600000,3600000,11,30479,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Resist Shadow on Spawn'),
(@ENTRY,0,3,0,0,0,100,2,11000,15000,35000,40000,11,35944,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Power Word: Shield'),
(@ENTRY,0,4,0,0,0,100,4,11000,15000,35000,40000,11,36052,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Power Word: Shield'),
(@ENTRY,0,5,0,0,0,100,2,9000,14000,15000,17000,11,15585,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Prayer of Healing'),
(@ENTRY,0,6,0,0,0,100,4,9000,14000,15000,17000,11,35943,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Prayer of Healing');

-- Shadowmoon Darkcaster
SET @ENTRY := 17694;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,12471,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow bolt'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,15232,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow bolt'),
(@ENTRY,0,2,0,0,0,100,2,2000,6000,15000,18000,11,11990,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Rain of Fire'),
(@ENTRY,0,3,0,0,0,100,4,2000,6000,15000,18000,11,33508,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Rain of Fire'),
(@ENTRY,0,4,0,0,0,100,6,4000,8000,7000,11000,11,12542,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Fear');

-- Sharpshooter Guard
SET @ENTRY := 17622;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,15620,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,4,0,0,2300,3900,11,22907,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,2,0,9,0,100,2,5,30,7000,11000,11,30481,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Incendiary Shot'),
(@ENTRY,0,3,0,9,0,100,4,5,30,7000,11000,11,35945,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Incendiary Shot'),
(@ENTRY,0,4,0,9,0,100,4,5,30,10000,14000,11,37551,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Viper Sting'),
(@ENTRY,0,5,0,9,0,100,2,5,15,9000,12000,11,23601,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Scatter Shot');

-- Shattered Hand Archer
SET @ENTRY := 17427;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,16100,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,4,0,0,2300,3900,11,22907,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,2,0,9,0,100,6,5,30,12000,17000,11,30990,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Multi-Shot');

-- Shattered Hand Assassin
SET @ENTRY := 17695;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,7,0,0,0,0,11,30991,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Spawn'),
(@ENTRY,0,1,0,7,0,100,7,0,0,0,0,11,30991,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Evade'),
(@ENTRY,0,2,0,67,0,100,6,4500,6500,0,0,11,30992,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Backstab'),
(@ENTRY,0,3,0,0,0,100,6,2000,3000,12000,15000,11,36974,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wound Poison'),
(@ENTRY,0,4,0,0,0,100,6,6000,9000,17000,21000,11,30981,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crippling Poison');

-- Shattered Hand Brawler
SET @ENTRY := 16593;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,8000,11000,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thrash'),
(@ENTRY,0,1,0,9,0,100,6,0,5,12000,21000,11,36020,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Curse of the Shattered Hand on Close'),
(@ENTRY,0,2,0,13,0,100,6,9000,11000,0,0,11,36033,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Kick on Player Spell Cast');

-- Shattered Hand Centurion
SET @ENTRY := 17465;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,2,5000,9000,11,15572,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sunder Armor on Close'),
(@ENTRY,0,1,0,9,0,100,4,0,2,5000,9000,11,16145,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sunder Armor on Close'),
(@ENTRY,0,2,0,0,0,100,2,3000,7000,21000,25000,11,30931,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Battle Shout'),
(@ENTRY,0,3,0,0,0,100,4,3000,7000,21000,25000,11,31403,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Battle Shout');

-- Shattered Hand Champion
SET @ENTRY := 17671;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3000,6000,12000,15000,11,32587,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shield Block'),
(@ENTRY,0,1,0,9,0,100,6,0,8,10000,14500,11,32588,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Concussion Blow on Close'),
(@ENTRY,0,2,0,13,0,100,6,2000,4500,20000,30000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Bash on Player Spell Cast');

-- Shattered Hand Executioner
SET @ENTRY := 17301;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,5000,7000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave on Close'),
(@ENTRY,0,1,0,0,0,100,6,7000,11000,12000,15000,11,11876,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast War Stomp');

-- Shattered Hand Gladiator
SET @ENTRY := 17464;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,7000,11000,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike on Close');

-- Shattered Hand Heathen
SET @ENTRY := 17420;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,12000,16000,11,30474,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bloodthirst on Close'),
(@ENTRY,0,1,0,9,0,100,4,0,5,12000,16000,11,35949,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bloodthirst on Close'),
(@ENTRY,0,2,0,2,0,100,7,0,30,0,0,11,30485,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,3,0,2,0,100,7,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP');
-- NPC talk text insert
SET @ENTRY := 17420;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage');

-- Shattered Hand Houndmaster
SET @ENTRY := 17670;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,15620,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,4,0,0,2300,3900,11,22907,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,2,0,9,0,100,2,5,30,60000,70000,11,34100,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Volley'),
(@ENTRY,0,3,0,9,0,100,4,5,30,60000,70000,11,35950,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Volley'),
(@ENTRY,0,4,0,9,0,100,2,5,30,12000,16000,11,30932,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Impaling Bolt'),
(@ENTRY,0,5,0,9,0,100,4,5,30,12000,16000,11,40248,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Impaling Bolt');

-- Shattered Hand Legionnaire
SET @ENTRY := 16700;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,6,500,1000,240000,240000,11,30472,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Aura of Discipline on Spawn'),
(@ENTRY,0,1,0,9,0,100,6,0,5,13600,14500,11,15615,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pummel on Close'),
(@ENTRY,0,2,0,2,0,100,7,0,30,0,0,11,30485,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,3,0,2,0,100,7,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP');
-- NPC talk text insert
SET @ENTRY := 16700;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage');

-- Shattered Hand Reaver
SET @ENTRY := 16699;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4000,7000,15000,20000,11,30471,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Uppercut'),
(@ENTRY,0,1,0,9,0,100,6,0,5,8000,9000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave on Close'),
(@ENTRY,0,2,0,2,0,100,7,0,30,0,0,11,30485,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,3,0,2,0,100,7,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP');
-- NPC talk text insert
SET @ENTRY := 16699;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage');

-- Shattered Hand Savage
SET @ENTRY := 16523;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,20000,25000,11,30470,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Slice and Dice'),
(@ENTRY,0,1,0,6,0,100,3,0,0,0,0,11,36023,3,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Deathblow on Death'),
(@ENTRY,0,2,0,6,0,100,5,0,0,0,0,11,36054,3,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Deathblow on Death'),
(@ENTRY,0,3,0,2,0,100,7,0,30,0,0,11,30485,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,4,0,2,0,100,7,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP');
-- NPC talk text insert
SET @ENTRY := 16523;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage');

-- Shattered Hand Sentry
SET @ENTRY := 16507;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,22911,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,1,0,4,0,100,5,0,0,0,0,11,37511,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,2,0,0,0,100,6,2000,3000,15000,21000,11,31553,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hamstring');

-- Shattered Hand Sharpshooter
SET @ENTRY := 16704;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,15620,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,4,0,0,2300,3900,11,22907,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,2,0,9,0,100,2,5,30,7000,11000,11,30481,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Incendiary Shot'),
(@ENTRY,0,3,0,9,0,100,4,5,30,7000,11000,11,35945,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Incendiary Shot'),
(@ENTRY,0,4,0,9,0,100,4,5,30,10000,14000,11,37551,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Viper Sting'),
(@ENTRY,0,5,0,9,0,100,2,5,15,9000,12000,11,23601,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Scatter Shot');

-- Shattered Hand Zealot
SET @ENTRY := 17462;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,3000,15000,21000,11,31553,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hamstring');

