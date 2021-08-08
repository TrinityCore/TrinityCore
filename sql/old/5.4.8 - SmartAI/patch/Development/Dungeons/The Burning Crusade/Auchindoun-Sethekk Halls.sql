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
	
-- Anzu
SET @ENTRY := 23035;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,80,6,2000,4500,12000,20000,11,22120,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Charge'),
(@ENTRY,0,1,2,2,0,100,7,0,33,0,0,12,23132,4,46000,0,0,0,1,0,0,0,0,0,0,0,'Cast Brood of Anzu at 33% HP'),
(@ENTRY,0,2,3,61,0,100,7,0,0,0,0,12,23132,4,46000,0,0,0,1,0,0,0,0,0,0,0,'Cast Brood of Anzu at 33% HP'),
(@ENTRY,0,3,0,61,0,100,7,0,0,0,0,12,23132,4,46000,0,0,0,1,0,0,0,0,0,0,0,'Cast Brood of Anzu at 33% HP'),
(@ENTRY,0,4,5,2,0,100,7,0,66,0,0,12,23132,4,46000,0,0,0,1,0,0,0,0,0,0,0,'Cast Brood of Anzu at 66% HP'),
(@ENTRY,0,5,6,61,0,100,7,0,0,0,0,12,23132,4,46000,0,0,0,1,0,0,0,0,0,0,0,'Cast Brood of Anzu at 66% HP'),
(@ENTRY,0,6,0,61,0,100,7,0,0,0,0,12,23132,4,46000,0,0,0,1,0,0,0,0,0,0,0,'Cast Brood of Anzu at 66% HP'),
(@ENTRY,0,7,0,0,0,85,6,14000,14000,26000,26000,11,40184,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Paralyzing Screech'),
(@ENTRY,0,8,0,0,0,75,6,5000,5000,21000,21000,11,40321,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Cyclone of Feathers'),
(@ENTRY,0,9,0,0,0,80,6,22000,22000,30000,30000,11,40303,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Spell Bomb'),
(@ENTRY,0,10,0,0,0,100,6,9000,12000,19000,27000,11,40199,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flesh Rip');

    /* Trash Mobs */
	
-- Avian Darkhawk
SET @ENTRY := 19429;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,8,25,5000,8000,11,38059,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Sonic Charge on Close'),
(@ENTRY,0,1,0,9,0,100,4,8,25,5000,8000,11,39197,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Sonic Charge on Close'),
(@ENTRY,0,2,0,0,0,100,2,4000,7000,8000,12000,11,32901,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Carnivorous Bite'),
(@ENTRY,0,3,0,0,0,100,4,4000,7000,8000,12000,11,39198,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Carnivorous Bite');

-- Avian Ripper
SET @ENTRY := 21891;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,5000,7000,10000,11,38056,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flesh Rip');

-- Avian Warhawk
SET @ENTRY := 18144;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,8,25,5000,8000,11,38059,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Sonic Charge on Close'),
(@ENTRY,0,1,0,0,0,100,6,4000,8000,8000,12000,11,32901,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Carnivorous Bite'),
(@ENTRY,0,2,0,0,0,100,6,2000,3000,7000,12000,11,18144,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Swoop');

-- Cobalt Serpent
SET @ENTRY := 19428;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,17503,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,38238,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,2,0,0,0,100,2,4000,7000,8000,11000,11,38193,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Lightning Breath'),
(@ENTRY,0,3,0,0,0,100,4,4000,7000,8000,11000,11,38133,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Lightning Breath'),
(@ENTRY,0,4,0,0,0,100,6,6000,7000,7000,13000,11,38110,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wing Buffet');

-- Dark Vortex
SET @ENTRY := 18701;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,3400,4700,11,12471,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt');


-- Eagle Spirit
SET @ENTRY := 23136;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,18000,22000,45000,55000,11,40240,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Spite of the Eagle');

-- Falcon Spirit
SET @ENTRY := 23135;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,18000,22000,45000,55000,11,40241,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Speed of the Falcon');

-- Hawk Spirit
SET @ENTRY := 23134;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,15000,18000,33000,35000,11,40237,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Protection of the Hawk');

-- Sethekk Guard
SET @ENTRY := 18323;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3000,5000,10000,15000,11,33967,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thunderclap');

-- Sethekk Initiate
SET @ENTRY := 18318;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,12000,20000,11,16145,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sunder Armor'),
(@ENTRY,0,1,0,0,0,100,6,5000,7000,12000,18000,11,33961,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spell Reflection'),
(@ENTRY,0,2,0,16,0,100,6,33961,20,22000,25000,11,33961,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Spell Reflection on Friendlies Missing Buff'),
(@ENTRY,0,3,0,9,0,100,0,0,30,13600,14500,11,31589,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Slow on Close');

-- Sethekk Oracle
SET @ENTRY := 18328;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,32690,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,38146,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,2,0,0,0,100,6,4000,11000,4000,11000,11,32129,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Faerie Fire');

-- Sethekk Prophet
SET @ENTRY := 18325;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3000,9000,8000,15000,11,27641,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Fear');

-- Sethekk Ravenguard
SET @ENTRY := 18322;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,6000,10000,18000,11,33964,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bloodthirst'),
(@ENTRY,0,1,0,0,0,100,4,2000,6000,10000,18000,11,40423,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bloodthirst'),
(@ENTRY,0,2,0,0,0,100,6,5000,8000,15000,19000,11,32651,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Howling Screech'),
(@ENTRY,0,3,0,2,0,100,7,0,20,0,0,11,34970,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP'),
(@ENTRY,0,4,0,2,0,100,7,0,20,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP');
-- NPC talk text insert
SET @ENTRY := 18322;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy');

-- Sethekk Shaman
SET @ENTRY := 18326;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,32663,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Dark Vortex on Aggro'),
(@ENTRY,0,1,0,0,0,100,2,2000,4500,8000,18000,11,15501,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Earth Shock'),
(@ENTRY,0,2,0,0,0,100,4,2000,4500,8000,18000,11,22885,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Earth Shock');

-- Sethekk Talon Lord
SET @ENTRY := 18321;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,32674,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Avenger\'s Shield on Aggro'),
(@ENTRY,0,1,0,0,0,100,6,2000,6000,10000,15000,11,32654,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Talon of Justice');

-- Time-Lost Controller
SET @ENTRY := 18327;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,33000,35000,11,32764,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Charming Totem'),
(@ENTRY,0,1,0,0,0,100,6,5000,6000,25000,28000,11,35013,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Shrink');

-- Time-Lost Shadowmage
SET @ENTRY := 18320;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,19000,25000,11,32682,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Curse of the Dark Talon');

-- Time-Lost Scryer
SET @ENTRY := 18319;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,33989,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,22273,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,2,0,14,0,100,2,5000,20,7000,10000,11,17843,1,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Flash Heal on Friendlies'),
(@ENTRY,0,3,0,14,0,100,4,8000,20,7000,10000,11,17138,1,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Flash Heal on Friendlies'),
(@ENTRY,0,4,0,14,0,100,2,2000,20,8000,10000,11,12160,1,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Rejuvenation on Friendlies'),
(@ENTRY,0,5,0,14,0,100,4,3500,20,8000,10000,11,15981,1,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Rejuvenation on Friendlies'),
(@ENTRY,0,6,0,1,0,100,6,500,1000,1800000,1800000,11,32689,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Destruction on Spawn');
