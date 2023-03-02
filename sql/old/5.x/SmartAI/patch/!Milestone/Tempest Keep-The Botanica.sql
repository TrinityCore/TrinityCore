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
	
-- Commander Sarannis
SET @ENTRY := 17976;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,1,2,9,0,100,6,0,10,11000,16000,11,34794,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Resonance on Close'),
(@ENTRY,0,2,0,61,0,100,6,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Cast Arcane Resonance on Close'),
(@ENTRY,0,3,4,0,0,100,6,8000,9000,11000,19000,11,34799,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Devastation'),
(@ENTRY,0,4,0,61,0,100,6,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Cast Arcane Devastation'),
(@ENTRY,0,5,6,0,0,100,6,60000,60000,60000,60000,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Summon Bloodwarder Reservist and Bloodwarder Mender'),
(@ENTRY,0,6,7,61,0,100,6,0,0,0,0,12,20078,4,1800000,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Summon Bloodwarder Reservist and Bloodwarder Mender'),
(@ENTRY,0,7,0,61,0,100,6,0,0,0,0,12,19633,4,1800000,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Summon Bloodwarder Reservist and Bloodwarder Mender'),
(@ENTRY,0,8,0,5,0,100,6,5000,5000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Player Kill'),
(@ENTRY,0,9,0,6,0,100,7,0,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Death');
-- NPC talk text insert
SET @ENTRY := 17976;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Step forward! I will see that you are properly welcomed.',14,0,100,0,0,11071, 'on Aggro Text'),
(@ENTRY,1,0, 'You are no longer dealing with some underling.',14,0,100,0,0,11076, 'on Cast Text'),
(@ENTRY,2,0, 'Band\'or shorel\'aran!',14,0,100,0,0,11077, 'on Cast Text'),
(@ENTRY,3,0, 'Guards! Come and kill these intruders!',14,0,100,0,0,11078, 'on Summon Text'),
(@ENTRY,4,0, 'Mission accomplished.',14,0,50,0,0,11073, 'on Player Kill Text'),
(@ENTRY,4,1, 'Oh stop your whimpering.',14,0,50,0,0,11072, 'on Player Kill Text'),
(@ENTRY,5,0, 'I have not yet... begun to...',14,0,100,0,0,11079, 'on Death Text');

-- Thorngrin the Tender
SET @ENTRY := 17978;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,1,2,0,0,100,2,12000,18000,18000,24000,11,34659,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Hellfire'),
(@ENTRY,0,2,0,61,0,100,2,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Cast Hellfire'),
(@ENTRY,0,3,4,0,0,100,4,12000,18000,18000,24000,11,39131,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Hellfire'),
(@ENTRY,0,4,0,61,0,100,4,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Cast Hellfire'),
(@ENTRY,0,5,6,0,0,100,6,6000,10000,24000,30000,11,34661,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sacrifice'),
(@ENTRY,0,6,0,61,0,100,6,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Cast Sacrifice'),
(@ENTRY,0,7,8,0,0,100,6,21000,25000,28000,29000,11,34670,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage'),
(@ENTRY,0,8,0,61,0,100,6,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Cast Enrage'),
(@ENTRY,0,9,0,2,0,100,7,0,50,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 50% HP'),
(@ENTRY,0,10,0,2,0,100,7,0,20,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 20% HP'),
(@ENTRY,0,11,0,5,0,100,6,5000,5000,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Player Kill'),
(@ENTRY,0,12,0,6,0,100,7,0,0,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Death');
-- NPC talk text insert
SET @ENTRY := 17978;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'What aggravation is this? You will die!',14,0,100,0,0,11205, 'on Aggro Text'),
(@ENTRY,1,0, 'Scream while you burn!',14,0,50,0,0,11211, 'on Cast Text'),
(@ENTRY,1,1, 'I\'ll incinerate you!',14,0,50,0,0,11210, 'on Cast Text'),
(@ENTRY,2,0, 'Your life will be mine!',14,0,100,0,0,11208, 'on Cast Text'),
(@ENTRY,3,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage'),
(@ENTRY,4,0, 'I revel in your pain!',14,0,100,0,0,11209, 'at 50% HP Text'),
(@ENTRY,5,0, 'You seek a prize, eh? How about death?',14,0,100,0,0,11206, 'at 20% HP Text'),
(@ENTRY,6,0, 'I hate to say I told you so...',14,0,100,0,0,11207, 'on Player Kill Text'),
(@ENTRY,7,0, 'You won\'t... get far.',14,0,100,0,0,11212, 'on Death Text');

    /* Trash Mobs */
	
-- Bloodfalcon
SET @ENTRY := 18155;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,8,25,14000,19000,11,32323,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Close'),
(@ENTRY,0,1,0,0,0,100,6,7000,11000,12000,16000,11,34856,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Bloodburn'),
(@ENTRY,0,2,0,0,0,100,6,2000,4000,8000,19000,11,18144,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Swoop');

-- Bloodwarder Falconer
SET @ENTRY := 17994;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,45,20000,25000,11,34852,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Call of the Falcon on Close'),
(@ENTRY,0,1,0,0,0,100,6,9000,15000,25000,31000,11,31567,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Deterrence'),
(@ENTRY,0,2,0,9,0,100,6,0,5,12000,16000,11,32908,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wing Clip on Close'),
(@ENTRY,0,3,0,9,0,100,6,8,30,18000,22000,11,34879,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Multi-Shot on Close');

-- Bloodwarder Greenkeeper
SET @ENTRY := 18419;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,17000,21000,11,34800,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Impending Coma on Close'),
(@ENTRY,0,1,0,9,0,100,2,0,40,7000,11000,11,34798,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Greenkeeper\'s Fury on Close'),
(@ENTRY,0,2,0,9,0,100,4,0,40,7000,11000,11,39121,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Greenkeeper\'s Fury on Close'),
(@ENTRY,0,3,0,0,0,100,2,8000,12000,11000,15000,11,34797,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Nature Shock'),
(@ENTRY,0,4,0,0,0,100,4,8000,12000,11000,15000,11,39120,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Nature Shock');

-- Bloodwarder Mender
SET @ENTRY := 19633;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,17194,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mind Blast'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,17287,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mind Blast'),
(@ENTRY,0,2,0,1,0,100,6,500,1000,1800000,1800000,11,34809,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Holy Fury on Spawn'),
(@ENTRY,0,3,0,2,0,100,7,0,30,0,0,11,35096,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Greater Heal at 30% HP');

-- Bloodwarder Protector
SET @ENTRY := 17993;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,8,25,30000,35000,11,34784,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Intervene on Close'),
(@ENTRY,0,1,0,9,0,100,6,0,5,9000,15000,11,29765,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crystal Strike on Close'),
(@ENTRY,0,2,0,0,0,100,6,7000,14000,18000,25000,11,35399,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spell Reflection'),
(@ENTRY,0,3,0,2,0,100,7,0,30,0,0,11,31589,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Slow at 30% HP');

-- Bloodwarder Steward
SET @ENTRY := 18404;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,7000,12000,15000,20000,11,34821,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Flurry');

-- Blue Seedling
SET @ENTRY := 19962;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,40,6000,9000,11,34782,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bind Feet on Close');

-- Frayer
SET @ENTRY := 18587;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,50,7,0,0,0,0,11,34204,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Form on Aggro'),
(@ENTRY,0,1,0,4,0,50,7,0,0,0,0,11,34203,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fire Form on Aggro'),
(@ENTRY,0,2,0,4,0,50,7,0,0,0,0,11,34202,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Form on Aggro'),
(@ENTRY,0,3,0,4,0,50,7,0,0,0,0,11,34205,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Form on Aggro');

-- Frayer Protector
SET @ENTRY := 19953;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,2300,3900,11,34745,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot Thorns');

-- Frayer Wildling
SET @ENTRY := 19608;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,11000,16000,11,34644,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lash on Close'),
(@ENTRY,0,1,0,9,0,100,4,0,5,11000,16000,11,39122,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lash on Close');

-- Greater Frayer
SET @ENTRY := 19557;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,11000,16000,11,34644,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lash on Close'),
(@ENTRY,0,1,0,9,0,100,4,0,5,11000,16000,11,39122,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lash on Close');

-- Mutate Fleshlasher
SET @ENTRY := 19598;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,5000,8000,11,34351,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Vicious Bite on Close');

-- Mutate Fleshlasher
SET @ENTRY := 25354;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,5000,8000,11,34351,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Vicious Bite on Close');

-- Nethervine Inciter
SET @ENTRY := 19511;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,10,120000,120000,11,34616,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Deadly Poison on Close'),
(@ENTRY,0,1,0,9,0,100,6,0,5,20000,25000,11,30621,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Kidney Shot on Close'),
(@ENTRY,0,2,0,9,0,100,6,0,40,13000,18000,11,34615,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Mind-numbing Poison on Close'),
(@ENTRY,0,3,0,2,0,100,6,0,30,30000,35000,11,34173,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sunseeker Blessing at 30% HP');

-- Nethervine Reaper
SET @ENTRY := 19512;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,6000,9000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave on Close'),
(@ENTRY,0,1,0,2,0,100,6,0,30,30000,35000,11,34173,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sunseeker Blessing at 30% HP');

-- Nethervine Trickster
SET @ENTRY := 19843;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,7,0,0,0,0,11,30991,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Spawn'),
(@ENTRY,0,1,0,7,0,100,7,0,0,0,0,11,30991,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Evade'),
(@ENTRY,0,2,0,67,0,100,6,9000,12000,0,0,11,34614,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Backstab');

-- Red Seedling
SET @ENTRY := 19964;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,20,9000,13000,11,36339,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fire Blast on Close');

-- Summoned Bloodwarder Mender
SET @ENTRY := 20083;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,17194,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mind Blast'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,17287,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mind Blast'),
(@ENTRY,0,2,0,1,0,100,6,500,1000,1800000,1800000,11,34809,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Holy Fury on Spawn'),
(@ENTRY,0,3,0,2,0,100,7,0,30,0,0,11,35096,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Greater Heal at 30% HP');

-- Summoned Bloodwarder Reservist
SET @ENTRY := 20078;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,8000,12000,11,34820,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Strike on Close');

-- Sunseeker Botanist
SET @ENTRY := 18422;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,14,0,100,2,4000,40,21000,26000,11,34361,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Regrowth on Friendlies'),
(@ENTRY,0,1,0,14,0,100,4,4000,40,21000,26000,11,39125,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Regrowth on Friendlies'),
(@ENTRY,0,2,0,14,0,100,2,1000,15,25000,29000,11,34254,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Rejuvenate Plant on Friendlies'),
(@ENTRY,0,3,0,14,0,100,4,1000,15,25000,29000,11,39126,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Rejuvenate Plant on Friendlies'),
(@ENTRY,0,4,0,16,0,100,6,34350,10,16000,25000,11,34350,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Nature\'s Rage on Friendlies Missing Buff');

-- Sunseeker Channeler
SET @ENTRY := 19505;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,10,19000,25000,11,34634,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sunseeker Aura on Close'),
(@ENTRY,0,1,0,0,0,100,6,7000,15000,15000,21000,11,34637,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Soul Channel'),
(@ENTRY,0,2,0,2,0,100,6,0,60,19000,25000,11,34222,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sunseeker Blessing at 60% HP'),
(@ENTRY,0,3,0,2,0,100,6,0,30,30000,35000,11,34173,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sunseeker Blessing at 30% HP');

-- Sunseeker Chemist
SET @ENTRY := 19486;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,8,12000,18000,11,34359,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fire Breath Potion on Close'),
(@ENTRY,0,1,0,9,0,100,4,0,8,12000,18000,11,39128,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fire Breath Potion on Close'),
(@ENTRY,0,2,0,0,0,100,2,10000,16000,20000,27000,11,34358,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Vial of Poison'),
(@ENTRY,0,3,0,0,0,100,4,10000,16000,20000,27000,11,39127,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Vial of Poison');

-- Sunseeker Gene-Splicer
SET @ENTRY := 19507;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,30,24000,32000,11,34642,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Death & Decay on Close'),
(@ENTRY,0,1,0,9,0,100,4,0,30,24000,32000,11,39347,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Death & Decay on Close'),
(@ENTRY,0,2,3,2,0,100,7,0,30,0,0,12,19598,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Mutate Fleshlasher at 30% HP'),
(@ENTRY,0,3,0,61,0,100,7,0,0,0,0,12,19598,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Mutate Fleshlasher at 30% HP');

-- Sunseeker Geomancer
SET @ENTRY := 18420;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,8,13600,14500,11,35124,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Explosion on Close');

-- Sunseeker Harvester
SET @ENTRY := 19509;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,30,13600,14500,11,34639,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Polymorph on Close'),
(@ENTRY,0,1,0,0,0,100,6,2000,4500,12000,20000,11,34640,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wilting Touch'),
(@ENTRY,0,2,3,2,0,100,7,0,50,0,0,12,19598,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Mutate Fleshlasher at 50% HP'),
(@ENTRY,0,3,0,61,0,100,7,0,0,0,0,12,19598,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Mutate Fleshlasher at 50% HP');

-- Sunseeker Herbalist
SET @ENTRY := 19508;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,30,15000,19000,11,22127,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Entangling Roots on Close');

-- Sunseeker Researcher
SET @ENTRY := 18421;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,1000,1000,30000,35000,11,34355,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Poison Shield'),
(@ENTRY,0,1,0,9,0,50,6,0,20,9000,15000,11,34354,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Shock on Close'),
(@ENTRY,0,2,0,9,0,50,6,0,20,9000,15000,11,34353,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frost Shock on Close'),
(@ENTRY,0,3,0,9,0,50,6,0,20,9000,15000,11,34352,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mind Shock on Close');

-- Tempest-Forge Peacekeeper
SET @ENTRY := 18405;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,40,14000,21000,11,34785,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Arcane Volley on Close'),
(@ENTRY,0,1,0,9,0,100,6,0,5,9000,13000,11,34793,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Blast on Close'),
(@ENTRY,0,2,0,0,0,100,6,5000,8000,11000,16000,11,34791,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Explosion');

-- Thorn Flayer
SET @ENTRY := 19920;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,35,7000,11000,11,35507,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Mind Flay on Close');

-- White Seedling
SET @ENTRY := 19958;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,9000,14000,11,34752,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Freezing Touch on Close');

