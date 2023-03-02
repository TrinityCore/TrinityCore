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
	
-- Gatewatcher Gyro-Kill
SET @ENTRY := 19218;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,1,0,9,0,100,6,0,15,13000,17000,11,35311,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Stream of Machine Fluid on Close'),
(@ENTRY,0,2,3,0,0,100,2,20000,30000,20000,30000,11,35318,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Saw Blade'),
(@ENTRY,0,3,0,61,0,100,2,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Cast Saw Blade'),
(@ENTRY,0,4,5,0,0,100,4,20000,30000,20000,30000,11,39192,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Saw Blade'),
(@ENTRY,0,5,0,61,0,100,4,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Cast Saw Blade'),
(@ENTRY,0,6,0,0,0,100,2,15000,25000,30000,45000,11,35322,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Power'),
(@ENTRY,0,7,0,0,0,100,4,15000,25000,30000,45000,11,39193,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Power'),
(@ENTRY,0,8,0,5,0,100,6,5000,5000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Player Kill'),
(@ENTRY,0,9,0,6,0,100,7,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Death');
-- NPC talk text insert
SET @ENTRY := 19218;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'I predict a painful death.',14,0,100,0,0,11101, 'on Aggro Text'),
(@ENTRY,1,0, 'Measure twice, cut once.',14,0,50,0,0,11104, 'on Cast Text'),
(@ENTRY,1,1, 'If my division is correct you should be quite dead.',14,0,50,0,0,11105, 'on Cast Text'),
(@ENTRY,2,0, 'Your strategy was flawed.',14,0,50,0,0,11102, 'on Player Kill Text'),
(@ENTRY,2,1, 'Yes, the only logical outcome.',14,0,50,0,0,11103, 'on Player Kill Text'),
(@ENTRY,3,0, 'An unforeseen... contingency.',14,0,100,0,0,11106, 'on Death Text');

-- Mechano-Lord Capacitus
SET @ENTRY := 19219;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,1,0,9,0,100,6,0,5,19000,25000,11,35161,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Head Crack on Close'),
(@ENTRY,0,2,0,0,0,100,6,2000,5000,9000,13000,12,20405,1,600000,0,0,0,4,0,0,0,0,0,0,0,'Cast Summon Nether Charge'),
(@ENTRY,0,3,0,0,0,100,4,180000,180000,300000,300000,11,26662,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Berserk'),
(@ENTRY,0,4,8,0,0,50,2,11000,17000,40000,46000,11,35159,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Reflective Damage Shield'),
(@ENTRY,0,5,8,0,0,50,2,11000,17000,40000,46000,11,35158,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Reflective Magic Shield'),
(@ENTRY,0,6,7,0,0,100,4,30000,30000,45000,60000,11,39096,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Polarity Shift'),
(@ENTRY,0,7,0,61,0,100,4,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Cast Polarity Shift'),
(@ENTRY,0,8,0,61,0,100,2,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Reflective Magic Shield or Reflective Damage Shield'),
(@ENTRY,0,9,0,6,0,100,7,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Death');
-- NPC talk text insert
SET @ENTRY := 19219;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'You should split while you can.',14,0,100,0,0,11162, 'on Aggro Text'),
(@ENTRY,1,0, 'Go ahead, gimme your best shot. I can take it!',14,0,50,0,0,11166, 'on Spell Cast Text'),
(@ENTRY,1,1, 'Think you can hurt me, huh? Think I\'m afraid of you?!',14,0,50,0,0,11165, 'on Spell Cast Text'),
(@ENTRY,2,0, 'Damn, I\'m good!',14,0,50,0,0,11164, 'on Spell Cast Text'),
(@ENTRY,2,1, 'Bully!',14,0,50,0,0,11167, 'on Spell Cast Text'),
(@ENTRY,3,0, 'Can\'t say I didn\'t warn you!',14,0,100,0,0,11163, 'on Death Text');
-- Nether Charge
SET @ENTRY := 20405;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,7,0,0,0,0,11,37670,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Detonation Trigger on Spawn'),
(@ENTRY,0,1,0,61,0,100,7,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Melee on Spawn'),
(@ENTRY,0,2,0,4,0,100,7,0,0,0,0,41,18000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Timed Despawn on Aggro'),
(@ENTRY,0,3,0,0,0,100,6,14000,14000,1000,1000,11,35151,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Nether Charge Pulse'),
(@ENTRY,0,4,0,0,0,100,7,0,0,14000,14000,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Movement on Cast Nether Charge Pulse');

    /* Trash Mobs */
	
-- Arcane Servant
SET @ENTRY := 20478;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,40,11000,17000,11,35255,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Volley on Close'),
(@ENTRY,0,1,0,9,0,100,6,0,8,12000,15000,11,22271,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Explosion on Close');

-- Bloodwarder Centurion
SET @ENTRY := 19510;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,8000,13000,11,35178,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Bash on Close'),
(@ENTRY,0,1,0,0,0,100,6,11000,17000,19000,24000,11,35183,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Unstable Affliction');

-- Bloodwarder Physician
SET @ENTRY := 20990;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,9000,14000,12000,16000,11,36333,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Anesthetic'),
(@ENTRY,0,1,0,9,0,100,2,0,20,8000,13000,11,36340,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Holy Shock on Close'),
(@ENTRY,0,2,0,9,0,100,4,0,20,8000,13000,11,38921,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Holy Shock on Close'),
(@ENTRY,0,3,0,14,0,100,2,3000,15,10000,16000,11,36348,1,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Bandage on Friendlies'),
(@ENTRY,0,4,0,14,0,100,4,3000,15,10000,16000,11,38919,1,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Bandage on Friendlies');

-- Bloodwarder Slayer
SET @ENTRY := 19167;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,9000,17000,11,15708,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike on Close'),
(@ENTRY,0,1,0,0,0,100,6,5000,9000,12000,16000,11,35189,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Solar Strike'),
(@ENTRY,0,2,0,0,0,100,6,7000,8000,10000,19000,11,13736,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirlwind');

-- Mechanar Crusher
SET @ENTRY := 19231;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,9000,15000,11,35055,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast The Claw on Close'),
(@ENTRY,0,1,0,0,0,100,2,5000,9000,15000,18000,11,35056,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Glob of Machine Fluid'),
(@ENTRY,0,2,0,0,0,100,4,5000,9000,15000,18000,11,38923,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Glob of Machine Fluid');

-- Mechanar Driller
SET @ENTRY := 19712;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,9000,15000,11,35047,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast The Claw on Close'),
(@ENTRY,0,1,0,0,0,100,2,5000,9000,15000,18000,11,35056,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Glob of Machine Fluid'),
(@ENTRY,0,2,0,0,0,100,4,5000,9000,15000,18000,11,38923,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Glob of Machine Fluid');

-- Mechanar Tinkerer
SET @ENTRY := 19716;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,20,7000,11000,11,35057,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Netherbomb on Close'),
(@ENTRY,0,1,0,9,0,100,4,0,20,7000,11000,11,38925,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Netherbomb on Close'),
(@ENTRY,0,2,0,2,0,100,7,0,50,0,0,11,35058,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Nether Explosion at 50% HP'),
(@ENTRY,0,3,0,2,0,100,6,0,20,11000,16000,11,35062,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Maniacal Charge at 20% HP');

-- Mechanar Wrecker
SET @ENTRY := 19713;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,11000,15000,11,35049,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Pound on Close'),
(@ENTRY,0,1,0,0,0,100,2,5000,9000,15000,18000,11,35056,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Glob of Machine Fluid'),
(@ENTRY,0,2,0,0,0,100,4,5000,9000,15000,18000,11,38923,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Glob of Machine Fluid');

-- Sunseeker Astromage
SET @ENTRY := 19168;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,17195,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Scorch'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,36807,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Scorch'),
(@ENTRY,0,2,0,1,0,100,2,500,1000,600000,600000,11,35265,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fire Shield on Spawn'),
(@ENTRY,0,3,0,1,0,100,4,500,1000,600000,600000,11,38933,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fire Shield on Spawn'),
(@ENTRY,0,4,0,0,0,100,2,8000,13000,18000,22000,11,35267,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Solarburn'),
(@ENTRY,0,5,0,0,0,100,4,8000,13000,18000,22000,11,38930,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Solarburn');

-- Sunseeker Engineer
SET @ENTRY := 20988;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,30,19000,26000,11,36341,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Super Shrink Ray on Close'),
(@ENTRY,0,1,0,0,0,100,2,7000,13000,12000,18000,11,36345,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Death Ray'),
(@ENTRY,0,2,0,0,0,100,4,7000,13000,12000,18000,11,39196,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Death Ray'),
(@ENTRY,0,3,0,2,0,100,6,0,50,30000,36000,11,36343,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Growth Ray at 50% HP');

-- Sunseeker Netherbinder
SET @ENTRY := 20059;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,8,13600,14500,11,35261,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Nova on Close'),
(@ENTRY,0,1,0,9,0,100,4,0,8,13600,14500,11,38936,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Nova on Close'),
(@ENTRY,0,2,0,0,0,100,4,6000,12000,12000,17000,11,17201,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dispel Magic'),
(@ENTRY,0,3,4,0,0,100,6,13000,18000,35000,50000,11,35251,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Arcane Golem'),
(@ENTRY,0,4,0,61,0,100,6,0,0,0,0,11,35251,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Arcane Golem'),
(@ENTRY,0,5,0,0,0,100,2,5000,9000,15000,22000,11,35243,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Starfire'),
(@ENTRY,0,6,0,0,0,100,4,5000,9000,15000,22000,11,38935,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Starfire');

-- Tempest-Forge Destroyer
SET @ENTRY := 19735;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,11000,15000,16000,24000,11,36582,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Charged Fist'),
(@ENTRY,0,1,0,9,0,100,6,0,5,9000,14000,11,35783,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Knockdown on Close');

-- Tempest-Forge Patroller
SET @ENTRY := 19166;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,11000,16000,11,35011,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Knockdown on Close'),
(@ENTRY,0,1,0,9,0,100,2,0,40,8000,12000,11,35012,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Charged Arcane Missile on Close'),
(@ENTRY,0,2,0,9,0,100,4,0,40,8000,12000,11,38941,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Charged Arcane Missile on Close');

