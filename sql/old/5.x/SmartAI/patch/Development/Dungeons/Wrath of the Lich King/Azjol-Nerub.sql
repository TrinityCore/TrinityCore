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
	
-- Anub'ar Assassin
SET @ENTRY := 29214;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY,0,0,0,67,0,100,6,3900,7200,0,0,11,52540,0,0,0,0,0,2,0,0,0,0,0,0,0,'Casts Backstab');

-- Anub'ar Crypt Fiend
SET @ENTRY := 29063;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,7000,9000,12000,11,53330,0,0,0,0,0,5,32,0,0,0,0,0,0,'Cast Infected Wound'),
(@ENTRY,0,1,0,0,0,100,4,4000,7000,9000,12000,11,59348,0,0,0,0,0,5,32,0,0,0,0,0,0,'Cast Infected Wound'),
(@ENTRY,0,2,0,0,0,100,2,9000,12000,10000,13000,11,53322,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Crushing Webs'),
(@ENTRY,0,3,0,0,0,100,4,9000,12000,10000,13000,11,59347,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Crushing Webs');

-- Anub'ar Darter
SET @ENTRY := 29213;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,5000,17000,18000,11,53602,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Dart'),
(@ENTRY,0,1,0,0,0,100,4,2000,5000,17000,18000,11,59349,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Dart');

-- Anub'ar Guardian
SET @ENTRY := 29216;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,5500,12600,14800,11,52532,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike'),
(@ENTRY,0,1,0,0,0,100,2,8800,11300,19900,22400,11,53618,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sunder Armor'),
(@ENTRY,0,2,0,0,0,100,2,8800,11300,19900,22400,11,59350,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sunder Armor');

-- Anub'ar Necromancer
SET @ENTRY := 28925;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,3400,4700,11,53333,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,6,8000,8000,29900,32300,11,53334,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Animate Bones');

-- Anub'ar Crypt Fiend
SET @ENTRY := 29118;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,7000,9000,12000,11,53330,0,0,0,0,0,5,32,0,0,0,0,0,0,'Cast Infected Wound'),
(@ENTRY,0,1,0,0,0,100,4,4000,7000,9000,12000,11,59348,0,0,0,0,0,5,32,0,0,0,0,0,0,'Cast Infected Wound'),
(@ENTRY,0,2,0,0,0,100,2,9000,12000,10000,13000,11,53322,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Crushing Webs'),
(@ENTRY,0,3,0,0,0,100,4,9000,12000,10000,13000,11,59347,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Crushing Webs');

-- Anub'ar Crypt Fiend
SET @ENTRY := 29097;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,7000,9000,12000,11,53330,0,0,0,0,0,5,32,0,0,0,0,0,0,'Cast Infected Wound'),
(@ENTRY,0,1,0,0,0,100,4,4000,7000,9000,12000,11,59348,0,0,0,0,0,5,32,0,0,0,0,0,0,'Cast Infected Wound'),
(@ENTRY,0,2,0,0,0,100,2,9000,12000,10000,13000,11,53322,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Crushing Webs'),
(@ENTRY,0,3,0,0,0,100,4,9000,12000,10000,13000,11,59347,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Crushing Webs');

-- Anub'ar Necromancer
SET @ENTRY := 29119;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,3400,4700,11,53333,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,6,8000,8000,29900,32300,11,53334,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Animate Bones');

-- Anub'ar Crypt Fiend
SET @ENTRY := 29051;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,7000,9000,12000,11,53330,0,0,0,0,0,5,32,0,0,0,0,0,0,'Cast Infected Wound'),
(@ENTRY,0,1,0,0,0,100,4,4000,7000,9000,12000,11,59348,0,0,0,0,0,5,32,0,0,0,0,0,0,'Cast Infected Wound'),
(@ENTRY,0,2,0,0,0,100,2,9000,12000,10000,13000,11,53322,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Crushing Webs'),
(@ENTRY,0,3,0,0,0,100,4,9000,12000,10000,13000,11,59347,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Crushing Webs');

-- Anub'ar Necromancer
SET @ENTRY := 29064;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,3400,4700,11,53333,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,6,8000,8000,29900,32300,11,53334,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Animate Bones');

-- Anub'ar Necromancer
SET @ENTRY := 29098;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,3400,4700,11,53333,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,6,8000,8000,29900,32300,11,53334,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Animate Bones');

-- Anub'ar Skirmisher
SET @ENTRY := 28734;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY,0,0,0,67,0,100,6,9000,12000,0,0,11,52540,0,0,0,0,0,2,0,0,0,0,0,0,0,'Casts Backstab');

-- Anub'ar Webspinner
SET @ENTRY := 29335;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,10000,13000,19000,22000,11,52086,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Web Wrap'),
(@ENTRY,0,1,0,0,0,100,2,4000,7000,9000,13000,11,54290,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Web Shot'),
(@ENTRY,0,2,0,0,0,100,4,4000,7000,9000,13000,11,59362,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Web Shot');

-- Anub'ar Prime Guard
SET @ENTRY := 28128;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,30,9000,13000,11,54309,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Mark of Darkness on Close'),
(@ENTRY,0,1,0,9,0,100,4,0,30,9000,13000,11,59352,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Mark of Darkness on Close'),
(@ENTRY,0,2,0,0,0,100,2,6200,8100,19900,22300,11,54314,0,0,0,0,0,1,1,0,0,0,0,0,0,'Cast Drain Power'),
(@ENTRY,0,3,0,0,0,100,4,6200,8100,19900,22300,11,59354,0,0,0,0,0,1,1,0,0,0,0,0,0,'Cast Drain Power');

-- Anub'ar Crusher
SET @ENTRY := 28922;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,9000,12000,18000,11,53318,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Smash'),
(@ENTRY,0,1,0,0,0,100,4,4000,9000,12000,18000,11,59346,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Smash'),
(@ENTRY,0,2,0,2,0,100,7,0,30,0,0,11,53801,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP'),
(@ENTRY,0,3,0,2,0,100,7,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP');
-- NPC talk text insert
SET @ENTRY := 28922;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy');

-- Anub'ar Champion
SET @ENTRY := 29062;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,13,0,100,2,14000,17000,0,0,11,53394,0,0,0,0,0,6,1,0,0,0,0,0,0,'Cast Pummel on Target Spellcast'),
(@ENTRY,0,1,0,13,0,100,4,14000,17000,0,0,11,59344,0,0,0,0,0,6,1,0,0,0,0,0,0,'Cast Pummel on Target Spellcast'),
(@ENTRY,0,2,0,0,0,100,2,6000,9000,17000,32000,11,53317,0,0,0,0,0,5,32,0,0,0,0,0,0,'Cast Rend'),
(@ENTRY,0,3,0,0,0,100,4,6000,9000,17000,32000,11,59343,0,0,0,0,0,5,32,0,0,0,0,0,0,'Cast Rend');

-- Anub'ar Champion
SET @ENTRY := 29117;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,13,0,100,2,14000,17000,0,0,11,53394,0,0,0,0,0,6,1,0,0,0,0,0,0,'Cast Pummel on Target Spellcast'),
(@ENTRY,0,1,0,13,0,100,4,14000,17000,0,0,11,59344,0,0,0,0,0,6,1,0,0,0,0,0,0,'Cast Pummel on Target Spellcast'),
(@ENTRY,0,2,0,0,0,100,2,6000,9000,17000,32000,11,53317,0,0,0,0,0,5,32,0,0,0,0,0,0,'Cast Rend'),
(@ENTRY,0,3,0,0,0,100,4,6000,9000,17000,32000,11,59343,0,0,0,0,0,5,32,0,0,0,0,0,0,'Cast Rend');

-- Anub'ar Champion
SET @ENTRY := 28924;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,13,0,100,2,14000,17000,0,0,11,53394,0,0,0,0,0,6,1,0,0,0,0,0,0,'Cast Pummel on Target Spellcast'),
(@ENTRY,0,1,0,13,0,100,4,14000,17000,0,0,11,59344,0,0,0,0,0,6,1,0,0,0,0,0,0,'Cast Pummel on Target Spellcast'),
(@ENTRY,0,2,0,0,0,100,2,6000,9000,17000,32000,11,53317,0,0,0,0,0,5,32,0,0,0,0,0,0,'Cast Rend'),
(@ENTRY,0,3,0,0,0,100,4,6000,9000,17000,32000,11,59343,0,0,0,0,0,5,32,0,0,0,0,0,0,'Cast Rend');

-- Anub'ar Champion
SET @ENTRY := 29096;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,13,0,100,2,14000,17000,0,0,11,53394,0,0,0,0,0,6,1,0,0,0,0,0,0,'Cast Pummel on Target Spellcast'),
(@ENTRY,0,1,0,13,0,100,4,14000,17000,0,0,11,59344,0,0,0,0,0,6,1,0,0,0,0,0,0,'Cast Pummel on Target Spellcast'),
(@ENTRY,0,2,0,0,0,100,2,6000,9000,17000,32000,11,53317,0,0,0,0,0,5,32,0,0,0,0,0,0,'Cast Rend'),
(@ENTRY,0,3,0,0,0,100,4,6000,9000,17000,32000,11,59343,0,0,0,0,0,5,32,0,0,0,0,0,0,'Cast Rend');

-- Anub'ar Venomancer
SET @ENTRY := 29217;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,53617,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,59359,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,2,0,0,0,100,2,8000,8000,14800,19300,11,53616,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Poison Bolt Volley'),
(@ENTRY,0,3,0,0,0,100,4,8000,8000,14800,19300,11,59360,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Poison Bolt Volley'),
(@ENTRY,0,4,5,2,0,100,7,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,5,0,61,0,100,7,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP');
-- NPC talk text insert
SET @ENTRY := 29217;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Anub'ar Shadowcaster
SET @ENTRY := 28733;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,52534,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,2,2,0,100,7,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,7,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,0,0,100,4,0,0,3400,4700,11,59357,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,4,0,9,0,100,2,0,8,12000,16000,11,52535,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Nova on Close'),
(@ENTRY,0,5,0,9,0,100,4,0,8,12000,16000,11,59358,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Nova on Close');
-- NPC talk text insert
SET @ENTRY := 28733;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');
