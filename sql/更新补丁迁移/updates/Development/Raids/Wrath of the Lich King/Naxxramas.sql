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
 
-- Bile Retcher
SET @ENTRY := 16018;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3600,7000,13700,19700,11,27807,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bile Vomit'),
(@ENTRY,0,1,0,0,0,100,4,3600,7000,13700,19700,11,54326,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bile Vomit');

-- Bile Sludge
SET @ENTRY := 16142;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,7,0,15,0,0,11,27890,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Clone at 15% HP');

-- Bony Construct
SET @ENTRY := 16167;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,9000,20000,20000,30000,11,55319,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Brutal Swipe'),
(@ENTRY,0,1,0,0,0,100,4,9000,20000,20000,30000,11,55324,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Brutal Swipe');

-- Carrion Spinner
SET @ENTRY := 15975;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,9000,16000,11,28434,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Spider Web'),
(@ENTRY,0,1,0,0,0,100,2,5000,8000,14000,18000,11,30043,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Poison Spray'),
(@ENTRY,0,2,0,0,0,100,4,5000,8000,14000,18000,11,56032,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Poison Spray');

-- Crypt Guard
SET @ENTRY := 16573;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,6000,4000,7000,11,28969,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Acid Spit'),
(@ENTRY,0,1,0,0,0,100,4,4000,6000,4000,7000,11,56098,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Acid Spit'),
(@ENTRY,0,2,0,0,0,100,6,7000,9000,7000,9000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,3,4,2,0,100,7,0,30,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP'),
(@ENTRY,0,4,0,61,0,100,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP');
-- NPC talk text insert
SET @ENTRY := 16573;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy');

-- Crypt Reaver
SET @ENTRY := 15978;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,4000,8000,12000,11,56605,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Virulent Poison'),
(@ENTRY,0,1,0,0,0,100,4,2000,4000,8000,12000,11,56624,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Virulent Poison'),
(@ENTRY,0,2,0,0,0,100,6,7000,9000,7000,9000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,3,4,2,0,100,7,0,30,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP'),
(@ENTRY,0,4,0,61,0,100,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP');
-- NPC talk text insert
SET @ENTRY := 15978;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy');

-- Dark Touched Warrior
SET @ENTRY := 16156;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3000,9000,18000,19000,11,55266,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirlwind');

-- Death Knight
SET @ENTRY := 16146;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,1000,7000,10000,17000,11,55213,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Hysteria'),
(@ENTRY,0,1,0,0,0,100,2,1000,2000,8500,20500,11,55209,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Death Coil'),
(@ENTRY,0,2,0,0,0,100,4,1000,2000,8500,20500,11,55320,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Death Coil'),
(@ENTRY,0,3,0,0,0,50,6,16000,17000,24000,28000,11,55210,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Death Coil'),
(@ENTRY,0,4,0,2,0,100,7,0,20,0,0,11,55212,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blood Presence at 20% HP');

-- Death Knight Captain
SET @ENTRY := 16145;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,7000,8000,14000,11,55255,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Plague Strike'),
(@ENTRY,0,1,0,0,0,100,4,2000,7000,8000,14000,11,55321,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Plague Strike'),
(@ENTRY,0,2,0,0,0,100,7,3500,10000,0,0,11,28353,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Raise Dead'),
(@ENTRY,0,3,0,2,0,100,7,0,20,0,0,11,55222,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Unholy Presence at 20% HP');

-- Death Knight Cavalier
SET @ENTRY := 16163;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,50,4600,7300,11,55314,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Strangulate on Close'),
(@ENTRY,0,1,0,9,0,100,4,0,50,4600,7300,11,55334,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Strangulate on Close'),
(@ENTRY,0,2,0,0,0,100,2,1000,3000,4000,9000,11,55313,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Icy Touch'),
(@ENTRY,0,3,0,0,0,100,4,1000,3000,4000,9000,11,55331,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Icy Touch'),
(@ENTRY,0,4,0,0,0,100,2,5000,6000,16000,20000,11,55315,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bone Armor'),
(@ENTRY,0,5,0,0,0,100,4,5000,6000,16000,20000,11,55336,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bone Armor'),
(@ENTRY,0,6,0,2,0,100,7,0,30,0,0,11,55294,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dismount Deathcharger at 30% HP');

-- Death Knight Understudy
SET @ENTRY := 16803;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,10000,18000,4000,7000,11,61696,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blood Strike'),
(@ENTRY,0,1,0,0,0,100,6,8000,20000,30000,31000,11,29061,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bone Barrier'),
(@ENTRY,0,2,0,0,0,100,6,5000,15000,15000,25000,11,29060,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Taunt');

-- Deathcharger Steed
SET @ENTRY := 16067;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,55317,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro');

-- Deathcharger Steed
SET @ENTRY := 29818;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,55317,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro');

-- Dread Creeper
SET @ENTRY := 15974;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,5000,8000,11000,11,28440,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Veil of Shadow'),
(@ENTRY,0,1,0,0,0,100,4,2000,5000,8000,11000,11,53803,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Veil of Shadow');

-- Embalming Slime
SET @ENTRY := 16024;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,1000,2000,2000,5000,11,28322,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Embalming Cloud');

-- Eye Stalk
SET @ENTRY := 16236;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,4,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving on Aggro'),
(@ENTRY,0,2,0,0,0,100,2,5000,7000,14000,17000,11,29407,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mind Flay'),
(@ENTRY,0,3,0,0,0,100,4,5000,7000,14000,17000,11,54805,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mind Flay');

-- Feugen
SET @ENTRY := 15930;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,20000,20000,20000,20000,11,54517,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Magnetic Pull'),
(@ENTRY,0,1,0,0,0,100,2,4000,4000,5000,7000,11,28135,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Static Field'),
(@ENTRY,0,2,0,0,0,100,4,4000,4000,5000,7000,11,54528,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Static Field');

-- Frenzied Bat
SET @ENTRY := 16036;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,1000,2000,11000,17000,11,54781,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frenzied Dive');

-- Guardian of Icecrown
SET @ENTRY := 16441;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,3000,15000,23000,11,28470,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blood Tap');

-- Infectious Ghoul
SET @ENTRY := 16244;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,6000,9000,12000,11,29915,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Flesh Rot'),
(@ENTRY,0,1,0,0,0,100,4,3000,6000,9000,12000,11,54709,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Flesh Rot'),
(@ENTRY,0,2,0,0,0,100,2,8000,14000,19000,24000,11,54703,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rend'),
(@ENTRY,0,3,0,0,0,100,4,8000,14000,19000,24000,11,54708,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rend'),
(@ENTRY,0,4,5,2,0,100,7,0,30,0,0,11,54701,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP'),
(@ENTRY,0,5,0,61,0,100,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP');
-- NPC talk text insert
SET @ENTRY := 16244;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy');

-- Living Monstrosity
SET @ENTRY := 16021;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,7100,12500,18000,21000,11,28293,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Chain Lighting'),
(@ENTRY,0,1,0,0,0,100,4,7100,12500,18000,21000,11,54334,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Chain Lighting'),
(@ENTRY,0,2,0,0,0,100,6,6000,10000,17000,18500,11,28294,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lightning Totem');
-- Lightning Totem
SET @ENTRY := 16385;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,1000,2000,4800,11,28297,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shock'),
(@ENTRY,0,1,0,0,0,100,4,1000,1000,2000,4800,11,54333,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shock');

-- Mad Scientist
SET @ENTRY := 16020;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,7000,17000,6000,13000,11,28301,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Mana Burn'),
(@ENTRY,0,1,0,0,0,100,4,7000,17000,6000,13000,11,54338,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Mana Burn'),
(@ENTRY,0,2,0,2,0,100,2,0,30,18000,21000,11,28306,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Great Heal at 30% HP'),
(@ENTRY,0,3,0,2,0,100,4,0,30,18000,21000,11,54337,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Great Heal at 30% HP');

-- Maexxna Spiderling
SET @ENTRY := 17055;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,9000,5000,8000,11,54121,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Necrotic Poison'),
(@ENTRY,0,1,0,0,0,100,4,5000,9000,5000,8000,11,28776,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Necrotic Poison');

-- Marauding Geist
SET @ENTRY := 30083;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,56729,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frenzied Leap on Aggro');

-- Mutated Grub
SET @ENTRY := 16297;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,5000,6000,8000,11,30109,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Slime Burst'),
(@ENTRY,0,1,0,0,0,100,4,2000,5000,6000,8000,11,54769,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Slime Burst');

-- Naxxramas Acolyte
SET @ENTRY := 15981;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,8000,13000,16000,11,56064,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley'),
(@ENTRY,0,1,0,0,0,100,4,4000,8000,13000,16000,11,56065,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley'),
(@ENTRY,0,2,0,0,0,100,2,9000,13000,14000,17000,11,56063,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Explosion'),
(@ENTRY,0,3,0,0,0,100,4,9000,13000,14000,17000,11,56067,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Explosion');

-- Naxxramas Cultist
SET @ENTRY := 15980;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,7000,14000,17000,11,28447,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Burst'),
(@ENTRY,0,1,0,0,0,100,4,4000,7000,14000,17000,11,53851,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Burst');

-- Naxxramas Follower
SET @ENTRY := 16505;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,1000,1000,16000,21000,11,56107,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Berserker Charge'),
(@ENTRY,0,1,0,0,0,100,6,5000,7000,11000,15000,11,54093,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Silence');

-- Naxxramas Worshipper
SET @ENTRY := 16506;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,54095,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,54096,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball'),
(@ENTRY,0,2,0,6,0,100,7,0,0,0,0,11,28732,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Widow\'s Embrace on Death');

-- Necro Knight
SET @ENTRY := 16165;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,1000,3000,3000,5000,11,15453,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Explosion'),
(@ENTRY,0,1,0,0,0,100,6,8000,9000,14000,16000,11,28391,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blink'),
(@ENTRY,0,2,0,9,0,100,6,0,8,13600,14500,11,30092,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blast Wave on Close'),
(@ENTRY,0,3,0,4,0,50,7,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 1 on Aggro'),
(@ENTRY,0,4,0,0,1,100,6,4000,5000,12000,13000,11,30095,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cone of Cold'),
(@ENTRY,0,5,0,0,1,100,6,7000,9000,15000,19000,11,30091,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Flamestrike'),
(@ENTRY,0,6,0,9,1,100,6,0,8,14000,14500,11,30094,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Nova on Close');

-- Patchwork Golem
SET @ENTRY := 16017;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,7,0,0,0,0,11,27793,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Disease Cloud on Spawn'),
(@ENTRY,0,1,0,0,0,100,6,3000,4000,15000,16000,11,27794,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,2,0,0,0,100,2,5000,9000,18000,22000,11,27758,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast War Stomp'),
(@ENTRY,0,3,0,0,0,100,4,5000,9000,18000,22000,11,56427,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast War Stomp'),
(@ENTRY,0,4,0,12,0,100,6,0,20,35000,43000,11,56426,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Execute when Target is 20% HP');

-- Plague Beast
SET @ENTRY := 16034;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,2,0,50,25000,30000,11,54780,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Plague Splash at 50% HP'),
(@ENTRY,0,1,0,2,0,100,4,0,50,25000,30000,11,56538,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Plague Splash at 50% HP'),
(@ENTRY,0,2,0,11,0,100,7,0,0,0,0,11,30110,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Mutated Spores on Spawn');

-- Plague Slime
SET @ENTRY := 16243;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,50,7,0,0,0,0,11,28987,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Plague Slime Black on Aggro'),
(@ENTRY,0,1,0,4,0,50,7,0,0,0,0,11,28988,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Plague Slime Blue on Aggro'),
(@ENTRY,0,2,0,4,0,50,7,0,0,0,0,11,28989,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Plague Slime Green on Aggro'),
(@ENTRY,0,3,0,4,0,50,7,0,0,0,0,11,28990,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Plague Slime Red on Aggro');

-- Plagued Bat
SET @ENTRY := 16037;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,6000,9000,13000,11,30113,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Putrid Bite'),
(@ENTRY,0,1,0,0,0,100,4,3000,6000,9000,13000,11,54772,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Putrid Bite');

-- Plagued Champion
SET @ENTRY := 16983;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,8000,11000,14000,11,30138,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Shock'),
(@ENTRY,0,1,0,0,0,100,4,4000,8000,11000,14000,11,54889,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Shock'),
(@ENTRY,0,2,0,0,0,100,6,7000,9000,9000,11000,11,32736,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike');

-- Plagued Ghoul
SET @ENTRY := 16447;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,7,0,0,0,0,11,55876,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Plague Contamination on Death');

-- Plagued Warrior
SET @ENTRY := 16984;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,7000,9000,7000,9000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave');

-- Risen Squire
SET @ENTRY := 16154;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4000,7000,45000,48000,11,55318,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pierce Armor');

-- Sewage Slime
SET @ENTRY := 16375;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,7,0,0,0,0,11,28156,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Disease Cloud on Spawn');

-- Shade of Naxxramas
SET @ENTRY := 16164;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,5000,5000,12000,11,28407,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley'),
(@ENTRY,0,1,0,0,0,100,4,3000,5000,5000,12000,11,55323,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley'),
(@ENTRY,0,2,0,0,0,100,6,4000,9000,75000,85000,11,28383,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Portal of Shadows');

-- Skeletal Smith
SET @ENTRY := 16193;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,8000,9000,13000,11,33661,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crush Armor'),
(@ENTRY,0,1,0,0,0,100,6,6000,7000,6000,8000,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Disarm');

-- Sludge Belcher
SET @ENTRY := 16029;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,7,0,0,0,0,11,28362,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Disease Cloud on Spawn'),
(@ENTRY,0,1,0,0,0,100,2,2000,3000,6000,8000,11,27891,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Acidic Sludge'),
(@ENTRY,0,2,0,0,0,100,4,2000,3000,6000,8000,11,54331,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Acidic Sludge');

-- Spore
SET @ENTRY := 16286; 
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY; 
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY; 
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,6,0,100,7,0,0,0,0,11,29232,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fungal Creep on Death');

-- Stitched Colossus
SET @ENTRY := 30071;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,12000,15000,22000,11,55821,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Massive Stomp'),
(@ENTRY,0,1,0,0,0,100,4,5000,12000,15000,22000,11,55826,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Massive Stomp'),
(@ENTRY,0,2,0,2,0,100,7,0,30,0,0,11,54356,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Unstoppable Enrage at 30% HP');

-- Stitched Giant
SET @ENTRY := 16025;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,10000,18000,21000,11,28405,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Knockback'),
(@ENTRY,0,1,0,2,0,100,7,0,30,0,0,11,54356,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Unstoppable Enrage at 30% HP');

-- Stoneskin Gargoyle
SET @ENTRY := 16168;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,5000,5000,7000,11,29325,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Acid Volley'),
(@ENTRY,0,1,0,0,0,100,4,3000,5000,5000,7000,11,54714,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Acid Volley'),
(@ENTRY,0,2,0,2,0,100,2,0,30,60000,60000,11,28995,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stoneskin at 30% HP'),
(@ENTRY,0,3,0,2,0,100,4,0,30,60000,60000,11,54722,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stoneskin at 30% HP');

-- Surgical Assistant
SET @ENTRY := 16022;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,3000,8000,12000,11,28310,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Mind Flay'),
(@ENTRY,0,1,0,0,0,100,4,2000,3000,8000,12000,11,54339,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Mind Flay');

-- Tomb Horror
SET @ENTRY := 15979;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,7000,12000,16000,11,54311,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crypt Scarabs'),
(@ENTRY,0,1,0,0,0,100,4,3000,7000,12000,16000,11,54316,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crypt Scarabs'),
(@ENTRY,0,2,0,0,0,100,2,15000,19000,28000,35000,11,54313,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Crypt Scarab Swarm'),
(@ENTRY,0,3,0,0,0,100,4,15000,19000,28000,35000,11,54317,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Crypt Scarab Swarm');

-- Unholy Axe
SET @ENTRY := 16194;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,6000,13000,20000,20000,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike'),
(@ENTRY,0,1,0,0,0,100,6,2000,9000,9000,14000,11,55463,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirlwind');

-- Unholy Staff
SET @ENTRY := 16215;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,9000,9000,16000,11,28450,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Explosion'),
(@ENTRY,0,1,0,0,0,100,4,3000,9000,9000,16000,11,55467,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Explosion'),
(@ENTRY,0,2,0,9,0,100,6,0,8,13600,14500,11,29849,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Nova on Close'),
(@ENTRY,0,3,0,0,0,100,6,5000,6000,14000,15000,11,29848,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Polymorph');

-- Unholy Swords
SET @ENTRY := 16216;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,9000,15000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave on Close'),
(@ENTRY,0,1,0,11,0,100,7,0,0,0,0,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thrash on Spawn');

-- Unrelenting Death Knight
SET @ENTRY := 16125;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,1000,3000,17000,20000,11,27825,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Mark'),
(@ENTRY,0,1,0,2,0,100,6,0,50,180000,190000,11,29316,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Assistants at 50% HP');

-- Unrelenting Rider
SET @ENTRY := 16126;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,55606,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Unholy Aura on Spawn'),
(@ENTRY,0,1,0,11,0,100,5,0,0,0,0,11,55608,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Unholy Aura on Spawn'),
(@ENTRY,0,2,0,0,0,100,2,2000,4500,9000,15000,11,27831,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley'),
(@ENTRY,0,3,0,0,0,100,4,2000,4500,9000,15000,11,55638,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley'),
(@ENTRY,0,4,0,2,0,100,6,0,50,180000,190000,11,29316,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Assistants at 50% HP');

-- Unrelenting Trainee
SET @ENTRY := 16124;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,5000,6000,8000,11,55604,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Death Plague'),
(@ENTRY,0,1,0,0,0,100,4,2000,5000,6000,8000,11,55645,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Death Plague');

-- Unstoppable Abomination
SET @ENTRY := 23562;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,7,0,30,0,0,11,28468,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP'),
(@ENTRY,0,1,0,61,0,100,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP'),
(@ENTRY,0,2,0,0,0,100,6,2000,4500,12000,20000,11,28467,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Wound');
-- NPC talk text insert
SET @ENTRY := 23562;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy');

-- Unstoppable Abomination
SET @ENTRY := 16428;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,7,0,30,0,0,11,28468,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP'),
(@ENTRY,0,1,0,61,0,100,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP'),
(@ENTRY,0,2,0,0,0,100,6,2000,4500,12000,20000,11,28467,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Wound');
-- NPC talk text insert
SET @ENTRY := 16428;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy');

-- Venom Stalker
SET @ENTRY := 15976;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,28431,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Poison Charge on Aggro'),
(@ENTRY,0,1,0,4,0,100,5,0,0,0,0,11,53809,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Poison Charge on Aggro');

-- Vigilant Shade
SET @ENTRY := 30085;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,7,0,0,0,0,11,55848,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Invisibility on Spawn'),
(@ENTRY,0,1,0,7,0,100,7,0,0,0,0,11,55848,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Invisibility on Evade'),
(@ENTRY,0,2,0,4,0,100,7,0,0,0,0,28,55848,0,0,0,0,0,1,0,0,0,0,0,0,0,'Remove Invisibility on Aggro'),
(@ENTRY,0,3,0,0,0,100,2,3000,3000,9000,10000,11,55850,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley'),
(@ENTRY,0,4,0,0,0,100,4,3000,3000,9000,10000,11,55851,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley');
