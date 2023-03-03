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
 
  /* Raid Normal for 10 people */
 /* Bosses */
 
-- Hyakiss the Lurker
SET @ENTRY := 16179;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,22766,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sneak on Spawn'),
(@ENTRY,0,1,0,7,0,100,3,0,0,0,0,11,22766,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sneak on Evade'),
(@ENTRY,0,2,0,9,0,100,2,0,5,7000,11000,11,29901,0,0,0,0,0,4,32,0,0,0,0,0,0,'Cast Acidic Fang on Close'),
(@ENTRY,0,3,0,0,0,100,2,2000,2000,12000,20000,11,29896,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hyakiss\' Web');

-- Rokad the Ravager
SET @ENTRY := 16181;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,12000,16000,11,29906,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ravage on Close');

-- Shadikith the Glider
SET @ENTRY := 16180;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,45,28000,35000,11,29903,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Dive on Close'),
(@ENTRY,0,1,0,0,0,100,2,7000,11000,8000,12000,11,29905,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wing Buffet'),
(@ENTRY,0,2,0,0,0,100,2,10000,15000,12000,17000,11,29904,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sonic Burst');

 /* Trash Mobs */

-- Arcane Anomaly
SET @ENTRY := 16488;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,40,6000,10000,11,29885,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Arcane Volley on Close'),
(@ENTRY,0,1,0,0,0,100,2,18000,30000,30000,45000,11,29883,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blink'),
(@ENTRY,0,2,0,2,0,100,3,0,75,0,0,11,29880,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Mana Shield at 75% HP'),
(@ENTRY,0,3,0,6,0,100,3,0,0,0,0,11,29882,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Loose Mana on Death');

-- Arcane Protector
SET @ENTRY := 16504;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,3000,18000,21000,11,29840,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fist of Stone');

-- Arcane Watchman
SET @ENTRY := 16485;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,9000,12000,11,29765,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crystal Strike on Close'),
(@ENTRY,0,1,0,0,0,100,2,11000,15000,13000,17000,11,29768,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Overload');

-- Astral Flare
SET @ENTRY := 17096;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,30235,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcing Sear on Spawn');

-- Astral Spark
SET @ENTRY := 17283;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,3000,3000,5000,11,29864,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sear'),
(@ENTRY,0,1,0,2,0,100,3,0,30,0,0,11,29876,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Detonate at 30% HP');

-- Chaotic Sentience
SET @ENTRY := 16489;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,3000,30000,45000,11,29900,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Unstable Magic');

-- Coldmist Stalker
SET @ENTRY := 16170;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,12000,18000,11,29290,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chilling Poison on Close'),
(@ENTRY,0,1,0,11,0,100,3,0,0,0,0,11,22766,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sneak on Spawn'),
(@ENTRY,0,2,0,7,0,100,3,0,0,0,0,11,22766,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sneak on Evade');

-- Coldmist Widow
SET @ENTRY := 16171;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,8,14000,20000,11,29292,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Mist on Close'),
(@ENTRY,0,1,0,9,0,100,2,0,30,5000,9000,11,29293,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Poison Bolt Volley on Close');

-- Concubine
SET @ENTRY := 16461;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,20,2,120000,240000,240000,300000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text OOC'),
(@ENTRY,0,1,0,2,0,100,3,0,50,0,0,11,29490,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Seduction at 50% HP'),
(@ENTRY,0,2,0,9,0,50,2,0,40,18000,29000,11,29497,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Jealousy on Close'),
(@ENTRY,0,3,0,9,0,50,2,0,40,18000,29000,11,29494,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Temptation on Close'),
(@ENTRY,0,4,0,6,0,100,3,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Death');
-- NPC talk text insert
SET @ENTRY := 16461;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Five seconds! I\'m not kidding!',12,0,50,1,0,0, 'say Text'),
(@ENTRY,0,1, 'So I said, \"Yeah, but that\'ll cost you extra.\"',12,0,50,1,0,0, 'say Text'),
(@ENTRY,0,2, 'He asked if the imp could join in... can you believe it? Actually, it wasn\'t half bad...',12,0,50,1,0,0, 'say Text'),
(@ENTRY,0,3, 'We could have had so much fun!',12,0,50,1,0,0, 'say Text'),
(@ENTRY,1,0, 'They fall asleep after. Me, I fall asleep during....',12,0,100,0,0,0, 'say Text on Death');

-- Dreadbeast
SET @ENTRY := 16177;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,9000,14000,11,29561,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave on Close');

-- Ethereal Spellfilcher
SET @ENTRY := 16545;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,30007,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spatial Distortion on Spawn'),
(@ENTRY,0,1,0,0,0,100,2,5000,8000,7000,9000,11,37161,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Volley'),
(@ENTRY,0,2,0,0,0,100,2,8000,12000,15000,21000,11,30039,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Transference'),
(@ENTRY,0,3,0,0,0,100,2,7000,9000,10000,16000,11,30036,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Steal Magic');

-- Ethereal Thief
SET @ENTRY := 16544;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,29982,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spatial Distortion on Spawn'),
(@ENTRY,0,1,0,9,0,100,2,0,5,7000,11000,11,30013,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Disarm on Close'),
(@ENTRY,0,2,0,6,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Death');
-- NPC talk text insert
SET @ENTRY := 16544;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Turn your back while you can!',14,0,100,0,0,0, 'say Text on Death');

-- Fiendish Imp
SET @ENTRY := 17267;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,30050,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Firebolt');

-- Fleshbeast
SET @ENTRY := 16595;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,18000,21000,11,29935,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Gaping Maw on Close'),
(@ENTRY,0,1,0,0,0,100,2,5000,9000,7000,10000,11,29939,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Infectious Poison');

-- Ghastly Haunt
SET @ENTRY := 16481;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,20,9000,14000,11,29712,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Shock on Close'),
(@ENTRY,0,1,0,9,0,100,2,0,5,11000,17000,11,29716,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ethereal Curse on Close'),
(@ENTRY,0,2,0,6,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Death');
-- NPC talk text insert
SET @ENTRY := 16481;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Free... at last.',12,0,50,0,0,0, 'say Text on Death'),
(@ENTRY,0,1, 'Time to move on...',12,0,50,0,0,0, 'say Text on Death');

-- Ghostly Baker
SET @ENTRY := 16412;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,20,9000,14000,11,29676,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rolling Pin on Close'),
(@ENTRY,0,1,0,0,0,100,2,5000,9000,12000,18000,11,29675,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Roast');

-- Ghostly Philanthropist
SET @ENTRY := 16470;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,7000,12000,21000,30000,11,29612,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Incite Rage'),
(@ENTRY,0,1,0,0,0,100,2,5000,9000,7000,10000,11,29609,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Ill Gift');

-- Ghostly Steward
SET @ENTRY := 16414;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,3,0,25,0,0,11,29691,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 25% HP'),
(@ENTRY,0,1,2,61,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 25% HP'),
(@ENTRY,0,2,0,61,0,100,3,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 25% HP'),
(@ENTRY,0,3,0,0,0,100,2,5000,9000,9000,15000,11,29690,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Drunken Skull Crack'),
(@ENTRY,0,4,0,6,0,100,3,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Death');
-- NPC talk text insert
SET @ENTRY := 16414;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy'),
(@ENTRY,1,0, 'How dare you disturb the master\'s dinner!',14,0,50,0,0,0, 'Yell on combat Frenzy'),
(@ENTRY,1,1, 'That was wasted on the likes of you!',14,0,50,0,0,0, 'Yell on combat Frenzy'),
(@ENTRY,1,2, 'That was a 200 year old Pupellyverbos Port!',14,0,50,0,0,0, 'Yell on combat Frenzy'),
(@ENTRY,2,0, 'Wait... No! No!',12,0,100,0,0,0, 'say Text on Death');

-- Greater Fleshbeast
SET @ENTRY := 16596;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,18000,21000,11,29935,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Gaping Maw on Close'),
(@ENTRY,0,1,0,0,0,100,2,5000,9000,7000,10000,11,29939,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Infectious Poison');

-- Greater Shadowbat
SET @ENTRY := 16174;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,11000,16000,11,29303,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Wing Beat on Close'),
(@ENTRY,0,1,0,9,0,100,2,0,2,7000,10000,11,29300,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sonic Blast on Close');

-- Homunculus
SET @ENTRY := 16539;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,30180,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Firebolt');

-- Kil'rek
SET @ENTRY := 17229;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,7000,9000,12000,11,30053,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Amplify Flames'),
(@ENTRY,0,1,0,6,0,100,3,0,0,0,0,11,30065,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Broken Pact on Death');

-- Magical Horror
SET @ENTRY := 16529;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,9000,12000,17000,11,29911,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Power Distortion'),
(@ENTRY,0,1,0,6,0,100,3,0,0,0,0,11,37078,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Volley on Death');

-- Mana Feeder
SET @ENTRY := 16491;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,29908,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Astral Bite on Spawn');

-- Mana Warp
SET @ENTRY := 16530;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,3,0,10,0,0,11,37079,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Warp Breach at 10% HP'),
(@ENTRY,0,1,0,6,0,100,3,0,0,0,0,11,29919,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Warp Breach on Death');

-- Night Mistress
SET @ENTRY := 16460;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,29487,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,1,0,0,0,100,2,12000,15000,11000,17000,11,30358,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Searing Pain'),
(@ENTRY,0,2,0,2,0,100,3,0,50,0,0,11,29491,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Impending Betrayal at 50% HP'),
(@ENTRY,0,3,0,11,0,100,3,0,0,0,0,11,29485,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Alluring Aura on Spawn'),
(@ENTRY,0,4,0,1,0,20,2,120000,240000,240000,300000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text OOC'),
(@ENTRY,0,5,0,6,0,100,3,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Death');
-- NPC talk text insert
SET @ENTRY := 16460;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Five seconds! I\'m not kidding!',12,0,50,1,0,0, 'say Text'),
(@ENTRY,0,1, 'So I said, \"Yeah, but that\'ll cost you extra.\"',12,0,50,1,0,0, 'say Text'),
(@ENTRY,0,2, 'He asked if the imp could join in... can you believe it? Actually, it wasn\'t half bad...',12,0,50,1,0,0, 'say Text'),
(@ENTRY,0,3, 'We could have had so much fun!',12,0,50,1,0,0, 'say Text'),
(@ENTRY,1,0, 'They fall asleep after. Me, I fall asleep during....',12,0,100,0,0,0, 'say Text on Death');

-- Phantom Attendant
SET @ENTRY := 16406;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,13,0,100,2,12000,16000,20000,30000,11,29586,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Kick on Player Spell Cast'),
(@ENTRY,0,1,0,14,0,100,2,18000,40,18000,23000,11,29587,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Shadow Rejuvenation on Friendlies'),
(@ENTRY,0,2,0,6,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Death');
-- NPC talk text insert
SET @ENTRY := 16406;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Where am I? What...',12,0,50,0,0,0, 'say Text on Death'),
(@ENTRY,0,1, 'What is happening?',12,0,50,0,0,0, 'say Text on Death');

-- Phantom Guardsman
SET @ENTRY := 16425;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,13,0,100,2,9000,11000,0,0,11,29684,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Shield Slam on Player Spell Cast'),
(@ENTRY,0,1,0,9,0,100,2,0,5,12000,16000,11,29684,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Slam on Close'),
(@ENTRY,0,2,0,2,0,100,2,0,75,45000,60000,11,29537,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Phantom Hound at 75% HP');

-- Phantom Guest
SET @ENTRY := 16409;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,30,1,2,3,4,0,0,1,0,0,0,0,0,0,0,'Random Phase on Spawn'),
(@ENTRY,0,1,0,9,1,100,2,0,30,25000,28000,11,29930,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Curse of Agony on Close'),
(@ENTRY,0,2,0,0,1,100,2,4000,4500,18000,20000,11,29928,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Immolate'),
(@ENTRY,0,3,0,0,1,100,2,8000,12000,12000,13000,11,29492,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Searing Pain'),
(@ENTRY,0,4,0,7,1,100,3,0,0,0,0,30,1,2,3,4,0,0,1,0,0,0,0,0,0,0,'Random Phase on Evade'),
(@ENTRY,0,5,1,4,2,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving on Aggro'),
(@ENTRY,0,6,2,61,2,100,3,0,0,0,0,11,29582,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw on Aggro'),
(@ENTRY,0,7,3,61,2,100,3,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Melee Attack on Aggro'),
(@ENTRY,0,8,5,9,2,100,2,5,30,2300,3900,11,29582,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,9,0,61,2,100,2,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Ranged Weapon Model'),
(@ENTRY,0,10,7,9,2,100,2,30,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Moving when not in Throw Range'),
(@ENTRY,0,11,0,61,2,100,2,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Melee Attack when not in Throw Range'),
(@ENTRY,0,12,9,9,2,100,2,0,10,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Moving when not in Throw Range'),
(@ENTRY,0,13,10,61,2,100,2,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Melee Weapon Model when not in Throw Range'),
(@ENTRY,0,14,0,61,2,100,2,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Melee Attack when not in Throw Range'),
(@ENTRY,0,15,12,9,2,100,2,11,25,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving at 25 Yards'),
(@ENTRY,0,16,13,61,2,100,2,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Melee Attack at 25 Yards'),
(@ENTRY,0,17,0,61,2,100,2,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Ranged Weapon Model at 25 Yards'),
(@ENTRY,0,18,15,7,2,100,3,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Melee Weapon Model on Evade'),
(@ENTRY,0,19,0,61,2,100,3,0,0,0,0,30,1,2,3,4,0,0,1,0,0,0,0,0,0,0,'Random Phase on Evade'),
(@ENTRY,0,20,0,9,2,100,2,0,5,9000,12000,11,29581,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Punch on Close'),
(@ENTRY,0,21,1,4,3,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving on Aggro'),
(@ENTRY,0,22,2,61,3,100,3,0,0,0,0,11,29579,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw Dynamite on Aggro'),
(@ENTRY,0,23,3,61,3,100,3,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Melee Attack on Aggro'),
(@ENTRY,0,24,5,9,3,100,2,5,30,2300,3900,11,29579,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw Dynamite'),
(@ENTRY,0,25,0,61,3,100,2,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Ranged Weapon Model'),
(@ENTRY,0,26,7,9,3,100,2,30,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Moving when not in Throw Dynamite Range'),
(@ENTRY,0,27,0,61,3,100,2,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Melee Attack when not in Throw Dynamite Range'),
(@ENTRY,0,28,9,9,3,100,2,0,10,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Moving when not in Throw Dynamite Range'),
(@ENTRY,0,29,10,61,3,100,2,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Melee Weapon Model when not in Throw Dynamite Range'),
(@ENTRY,0,30,0,61,3,100,2,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Melee Attack when not in Throw Dynamite Range'),
(@ENTRY,0,31,12,9,3,100,2,11,25,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving at 25 Yards'),
(@ENTRY,0,32,13,61,3,100,2,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Melee Attack at 25 Yards'),
(@ENTRY,0,33,0,61,3,100,2,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Ranged Weapon Model at 25 Yards'),
(@ENTRY,0,34,15,7,3,100,3,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Melee Weapon Model on Evade'),
(@ENTRY,0,35,0,61,3,100,3,0,0,0,0,30,1,2,3,4,0,0,1,0,0,0,0,0,0,0,'Random Phase on Evade'),
(@ENTRY,0,36,0,0,3,100,2,6000,9000,18000,19000,11,29513,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Goblin Dragon Gun'),
(@ENTRY,0,37,0,4,4,100,3,0,0,0,0,11,29521,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dance Vibe on Aggro'),
(@ENTRY,0,38,0,2,4,100,2,0,75,9000,13000,11,29580,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Heal at 75% HP'),
(@ENTRY,0,39,0,9,4,100,2,0,8,13600,14500,11,29514,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Holy Nova on Close'),
(@ENTRY,0,40,0,61,4,100,3,0,0,0,0,30,1,2,3,4,0,0,1,0,0,0,0,0,0,0,'Random Phase on Evade'),
(@ENTRY,0,41,0,6,1,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Death'),
(@ENTRY,0,42,0,6,2,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Death'),
(@ENTRY,0,43,0,6,3,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Death'),
(@ENTRY,0,44,0,6,4,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Death');
-- NPC talk text insert
SET @ENTRY := 16409;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Not... Fair...',12,0,100,0,0,0, 'say Text on Death');

-- Phantom Hound
SET @ENTRY := 17067;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,7000,11000,11,29574,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rend on Close'),
(@ENTRY,0,1,0,6,0,100,3,0,0,0,0,11,29541,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Phantom Hound Visual on Death');

-- Phantom Stagehand
SET @ENTRY := 16472;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,29677,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mallet Toss'),
(@ENTRY,0,1,0,9,0,100,2,0,20,6000,7000,11,41580,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Net on Close'),
(@ENTRY,0,2,0,9,0,100,2,0,5,12000,15000,11,29673,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sandbag on Close');

-- Phantom Valet
SET @ENTRY := 16408;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,1,0,9,0,100,2,0,10,16000,25000,11,29584,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demoralizing Shout on Close'),
(@ENTRY,0,2,0,6,0,100,3,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Death');
-- NPC talk text insert
SET @ENTRY := 16408;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Hey! Where do you think you are going, sneaking around like that?',14,0,100,0,0,0, 'on Aggro Text'),
(@ENTRY,1,0, 'The fates have turned against me!',12,0,100,0,0,0, 'say Text on Death');

-- Phase Hound
SET @ENTRY := 16178;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,29309,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Phase Shift on Spawn');

-- Shadow Pillager
SET @ENTRY := 16540;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,29317,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,1,0,0,0,100,2,7000,11000,17000,21000,11,29928,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Immolate'),
(@ENTRY,0,2,0,0,0,100,2,9000,14000,12000,15000,11,29492,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Searing Pain'),
(@ENTRY,0,3,0,0,0,100,2,12000,16000,30000,35000,11,29930,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Curse of Agony');

-- Shadowbat
SET @ENTRY := 16173;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,8,7000,11000,11,29298,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dark Shriek on Close');

-- Shadowbeast
SET @ENTRY := 16176;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,9000,17000,21000,27000,11,29304,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Howl of the Broken Hills');

-- Skeletal Usher
SET @ENTRY := 16471;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,20,11000,17000,11,29666,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frost Shock on Close'),
(@ENTRY,0,1,0,0,0,100,2,9000,14000,16000,21000,11,29661,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Magnetic Pull'),
(@ENTRY,0,2,0,0,0,100,2,11000,15000,13000,17000,11,29670,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Ice Tomb');

-- Skeletal Waiter
SET @ENTRY := 16415;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,6000,12000,21000,30000,11,32441,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Brittle Bones');

-- Sorcerous Shade
SET @ENTRY := 16526;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,8000,10000,15000,11,29923,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frostbolt Volley'),
(@ENTRY,0,1,0,0,0,100,2,12000,16000,14000,19000,11,29924,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley'),
(@ENTRY,0,2,0,0,0,100,2,18000,21000,15000,18000,11,29922,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fireball Volley');

-- Spectral Apprentice
SET @ENTRY := 16389;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,4000,7000,11,29618,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Burning Brand on Close');

-- Spectral Charger
SET @ENTRY := 15547;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,9000,13000,17000,11,29320,0,0,0,0,0,3,0,0,0,0,0,0,0,'Cast Charge');

-- Spectral Chef
SET @ENTRY := 16411;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,12000,15000,11,29667,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hamstring on Close'),
(@ENTRY,0,1,0,0,0,100,2,4000,8000,6000,10000,11,29665,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave');

-- Spectral Patron
SET @ENTRY := 16468;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,8000,11000,11,29555,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Left Hook on Close'),
(@ENTRY,0,1,0,0,0,100,2,3000,7000,9000,12000,11,29560,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Kick'),
(@ENTRY,0,2,0,6,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Death');
-- NPC talk text insert
SET @ENTRY := 16468;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'I\'ll miss the show!',12,0,50,0,0,0, 'say Text on Death'),
(@ENTRY,0,1, 'Yes... I think I remember now...',12,0,50,0,0,0, 'say Text on Death');

-- Spectral Performer
SET @ENTRY := 16473;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,10000,11000,15000,11,29680,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Curtain Call'),
(@ENTRY,0,1,0,0,0,100,2,11000,17000,15000,21000,11,29679,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Bad Poetry'),
(@ENTRY,0,2,0,6,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Death');
-- NPC talk text insert
SET @ENTRY := 16473;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'It\'s so cold, so dark.... I\'m not overacting, am I?',12,0,100,0,0,0, 'say Text on Death');

-- Spectral Retainer
SET @ENTRY := 16468;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,6000,12000,11,29578,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Rend on Close'),
(@ENTRY,0,1,0,0,0,100,2,9000,13000,18000,22000,11,29546,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Oath of Fealty');

-- Spectral Sentry
SET @ENTRY := 16424;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,29575,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,2,11000,15000,13000,16000,11,29576,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Multi-Shot');

-- Spectral Servant
SET @ENTRY := 16407;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,40,12000,21000,11,29540,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Curse of Past Burdens on Close'),
(@ENTRY,0,1,0,6,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Death');
-- NPC talk text insert
SET @ENTRY := 16407;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'No!',12,0,50,0,0,0, 'say Text on Death'),
(@ENTRY,0,1, 'I am finished!',12,0,50,0,0,0, 'say Text on Death'),
(@ENTRY,0,2, 'The master... will be angry...',12,0,50,0,0,0, 'say Text on Death');

-- Spectral Stable Hand
SET @ENTRY := 15551;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,11000,15000,11,18812,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Knockdown on Close'),
(@ENTRY,0,1,0,0,0,100,2,4000,8000,45000,48000,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pierce Armor'),
(@ENTRY,0,2,0,14,0,100,2,38400,30,21000,28000,11,29339,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Healing Touch on Friendlies'),
(@ENTRY,0,3,0,6,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Death'),
(@ENTRY,0,4,0,16,0,100,2,29340,30,22000,25000,11,29340,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Whip Rage on Friendlies Missing Buff');
-- NPC talk text insert
SET @ENTRY := 15551;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Is this the end?',12,0,50,0,0,0, 'say Text on Death'),
(@ENTRY,0,1, 'What will become of...',12,0,50,0,0,0, 'say Text on Death');

-- Spectral Stallion
SET @ENTRY := 15548;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,6000,9000,11,29577,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hoof Strike on Close'),
(@ENTRY,0,1,0,0,0,100,2,4000,7000,9000,13000,11,29323,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Absorb Vitality');

-- Spell Shade
SET @ENTRY := 16525;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,8000,10000,15000,11,29923,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frostbolt Volley'),
(@ENTRY,0,1,0,0,0,100,2,12000,16000,14000,19000,11,29924,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley'),
(@ENTRY,0,2,0,0,0,100,2,18000,21000,15000,18000,11,29922,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fireball Volley'),
(@ENTRY,0,3,0,11,0,100,3,0,0,0,0,11,29920,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Phasing Invisibility on Spawn');

-- Syphoner
SET @ENTRY := 16492;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,20,9000,13000,11,29881,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Drain Mana on Close');

-- Trapped Soul
SET @ENTRY := 16482;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,8,9000,15000,11,29717,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cone of Cold on Close'),
(@ENTRY,0,1,0,0,0,100,2,1000,3000,120000,130000,11,29718,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Elemental Armor'),
(@ENTRY,0,2,0,16,0,100,2,29340,30,22000,25000,11,29340,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Whip Rage on Friendlies Missing Buff');
-- NPC talk text insert
SET @ENTRY := 16482;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Is this the end?',12,0,50,0,0,0, 'say Text on Death'),
(@ENTRY,0,1, 'What will become of...',12,0,50,0,0,0, 'say Text on Death');

-- Vampiric Shadowbat
SET @ENTRY := 16175;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,4000,8000,11,32429,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Draining Touch on Close');

-- Wanton Hostess
SET @ENTRY := 16459;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,50,3,0,0,0,0,11,29485,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Alluring Aura on Spawn'),
(@ENTRY,0,1,0,1,0,35,2,90000,210000,240000,300000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text OOC'),
(@ENTRY,0,2,0,0,0,100,2,5000,8000,7000,10000,11,29477,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Banshee Wail'),
(@ENTRY,0,3,0,11,0,50,3,0,0,0,0,11,29486,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bewitching Aura on Spawn'),
(@ENTRY,0,4,0,9,0,100,2,0,5,12000,15000,11,29505,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Banshee Shriek on Close');
-- NPC talk text insert
SET @ENTRY := 16461;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Five seconds! I\'m not kidding!',12,0,50,1,0,0, 'say Text'),
(@ENTRY,0,1, 'So I said, \"Yeah, but that\'ll cost you extra.\"',12,0,50,1,0,0, 'say Text'),
(@ENTRY,0,2, 'He asked if the imp could join in... can you believe it? Actually, it wasn\'t half bad...',12,0,50,1,0,0, 'say Text'),
(@ENTRY,0,3, 'We could have had so much fun!',12,0,50,1,0,0, 'say Text');


