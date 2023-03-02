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
       /* Boss */
	
-- Rokmar the Crackler
SET @ENTRY := 17991;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,8000,8000,20000,21000,11,31956,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Grievous Wound'),
(@ENTRY,0,1,0,0,0,100,4,8000,8000,20000,21000,11,38801,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Grievous Wound'),
(@ENTRY,0,2,0,0,0,100,6,15000,16000,27500,27500,11,31948,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Ensnaring Moss'),
(@ENTRY,0,3,0,0,0,100,6,10500,10500,19000,19000,11,35008,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Water Spit'),
(@ENTRY,0,4,0,2,0,100,7,0,20,0,0,11,34970,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 20% HP'),
(@ENTRY,0,5,0,2,0,100,7,0,20,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 20% HP');
-- NPC talk text insert
SET @ENTRY := 17991;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy');

-- Mennu the Betrayer
SET @ENTRY := 17941;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,1,0,0,0,100,6,18000,18000,26000,26000,11,31985,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Tainted Stoneskin Totem'),
(@ENTRY,0,2,0,0,0,100,6,19000,19000,26200,26200,11,31981,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Tainted Earthgrab Totem'),
(@ENTRY,0,3,0,0,0,100,6,20000,20000,27000,27000,11,31991,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Corrupted Nova Totem'),
(@ENTRY,0,4,0,2,0,100,6,0,60,20000,30000,11,34980,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Mennu\'s Healing Ward at 60% HP'),
(@ENTRY,0,5,0,0,0,100,6,5000,8000,7000,11000,11,35010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lightning Bolt'),
(@ENTRY,0,6,0,5,0,100,6,5000,5000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Player Kill'),
(@ENTRY,0,7,0,6,0,100,7,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Death');
-- NPC talk text insert
SET @ENTRY := 17941;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'The work must continue.',14,0,50,0,0,10376, 'on Aggro Text'),
(@ENTRY,0,1, 'Don\'t make me kill you!',14,0,50,0,0,10378, 'on Aggro Text'),
(@ENTRY,0,2, 'You brought this on yourselves.',14,0,50,0,0,10379, 'on Aggro Text'),
(@ENTRY,1,0, 'It had to be done.',14,0,50,0,0,10380, 'on Player Kill Text'),
(@ENTRY,1,1, 'You should not have come.',14,0,50,0,0,10381, 'on Player Kill Text'),
(@ENTRY,2,0, 'I... Deserve this.',14,0,100,0,0,10382, 'on Death Text');

-- Quagmirran
SET @ENTRY := 17942;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,9000,9500,18000,34500,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,1,0,0,0,100,6,20000,20000,21000,22000,11,32055,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Uppercut'),
(@ENTRY,0,2,3,0,0,100,6,20000,25000,20000,25000,13,100,0,0,0,0,0,4,0,0,0,0,0,0,0,'Threat Mod'),
(@ENTRY,0,3,0,61,0,100,6,0,0,0,0,11,38153,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Acid Spray'),
(@ENTRY,0,4,0,0,0,100,2,28000,31000,25000,27000,11,34780,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Poison Bolt Volley'),
(@ENTRY,0,5,0,0,0,100,4,28000,31000,25000,27000,11,39340,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Poison Bolt Volley');


    /* Trash Mobs */
	
-- Bogstrok
SET @ENTRY := 17816;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,12000,17000,18000,11,31551,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Piercing Jab');

-- Coilfang Champion
SET @ENTRY := 17957;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,15000,22000,11,16145,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sunder Armor on Close'),
(@ENTRY,0,1,0,0,0,100,6,12000,14000,22000,28000,11,19134,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Frightening Shout'),
(@ENTRY,0,2,0,0,0,100,6,4000,17000,11000,15000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave');

-- Coilfang Collaborator
SET @ENTRY := 17962;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,10000,16000,13000,20000,11,33787,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cripple'),
(@ENTRY,0,1,0,0,0,100,6,20000,26000,20000,26000,11,19130,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Revenge'),
(@ENTRY,0,2,0,2,0,100,7,0,30,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP'),
(@ENTRY,0,3,0,2,0,100,7,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP');
-- NPC talk text insert
SET @ENTRY := 17962;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy');

-- Coilfang Defender
SET @ENTRY := 17958;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,12000,15000,16000,11,15655,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Slam'),
(@ENTRY,0,1,0,0,0,100,6,10000,13000,13000,14000,11,31554,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spell Reflection');

-- Coilfang Enchantress
SET @ENTRY := 17961;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,15234,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,37664,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,2,0,0,0,100,2,18000,22000,11000,16000,11,32193,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Lightning Cloud'),
(@ENTRY,0,3,0,0,0,100,4,18000,22000,11000,16000,11,37665,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Lightning Cloud'),
(@ENTRY,0,4,0,0,0,100,6,6000,12000,19000,20000,11,32173,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Entangling Roots');

-- Coilfang Observer
SET @ENTRY := 17938;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,10000,17000,7000,11000,11,17883,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Immolate'),
(@ENTRY,0,1,0,0,0,100,4,10000,17000,7000,11000,11,37668,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Immolate'),
(@ENTRY,0,2,0,0,0,100,2,9000,15000,13000,16000,11,32191,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heavy Dynamite'),
(@ENTRY,0,3,0,0,0,100,4,9000,15000,13000,16000,11,37666,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heavy Dynamite');

-- Coilfang Ray <Observer's Pet>
SET @ENTRY := 21128;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,5000,12000,21000,11,34984,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Psychic Horror');

-- Coilfang Scale-Healer
SET @ENTRY := 21126;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4500,8000,12000,13500,11,34944,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Holy Nova'),
(@ENTRY,0,1,0,0,0,100,4,4500,8000,12000,13500,11,37669,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Holy Nova'),
(@ENTRY,0,2,0,0,0,100,2,10000,13000,25000,35000,11,17139,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Power Word: Shield'),
(@ENTRY,0,3,0,0,0,100,4,10000,13000,25000,35000,11,36052,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Power Word: Shield'),
(@ENTRY,0,4,0,14,0,100,2,4000,40,12000,16000,11,34945,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Heal on Friendlies'),
(@ENTRY,0,5,0,14,0,100,4,8000,40,12000,16000,11,39378,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Heal on Friendlies');

-- Coilfang Slavehandler
SET @ENTRY := 17959;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,6,60000,120000,360000,420000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text OOC'),
(@ENTRY,0,1,0,4,0,100,7,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,2,0,0,0,100,6,6000,6000,9000,9000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hamstring'),
(@ENTRY,0,3,0,0,0,100,6,10000,12000,20000,25000,11,16172,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Head Crack'),
(@ENTRY,0,4,0,0,0,100,6,7000,9000,15000,22000,11,6754,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Slap!');
-- NPC talk text insert
SET @ENTRY := 17959;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Hurry up with it already! The longer you take, the more of a hurtin\' I\'m putting on you!',14,0,50,0,0,0, 'say Text'),
(@ENTRY,0,1, 'Wake up! Now get up and back to work!',14,0,50,0,0,0, 'say Text'),
(@ENTRY,0,2, 'Too soon! You are slacking off too soon!',14,0,50,0,0,0, 'say Text'),
(@ENTRY,0,3, 'Hey!  Over here!  Yeah, over here... I\'m in this cage!!!',14,0,50,0,0,0, 'say Text'),
(@ENTRY,0,4, 'This is terrible..... my arms grow tired from beating on you lazy peons!',14,0,50,0,0,0, 'say Text'),
(@ENTRY,0,5, 'Get back to work you!',14,0,50,0,0,0, 'say Text'),
(@ENTRY,0,6, 'What is this?! Didn\'t mommy and daddy teach you anything?',14,0,50,0,0,0, 'say Text'),
(@ENTRY,1,0, 'Assist me slaves!',14,0,100,0,0,0, 'say Text');

-- Coilfang Soothsayer
SET @ENTRY := 17960;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,3400,4700,11,15791,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,6,6000,9000,12000,14000,11,31555,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Decayed Intellect'),
(@ENTRY,0,2,0,0,0,100,6,9500,11000,12000,18000,11,30923,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Domination');

-- Coilfang Technician
SET @ENTRY := 17940;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,9500,14000,9800,14500,11,16005,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Rain of Fire'),
(@ENTRY,0,1,0,0,0,100,4,9500,14000,9800,14500,11,39376,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Rain of Fire');

-- Coilfang Tempest
SET @ENTRY := 21127;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,9000,7500,15000,11,15667,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sinister Strike'),
(@ENTRY,0,1,0,0,0,100,6,10500,18500,26000,27000,11,36872,32,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Deadly Poison');

-- Greater Bogstrok
SET @ENTRY := 17817;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,6500,14000,6000,14500,11,35760,32,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Decayed Strength');

-- Skar'this the Summoner <Heretic of Neptulon>
SET @ENTRY := 40446;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,1000,1000,11,45846,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Aura on Spawn');

-- Wastewalker Slave
SET @ENTRY := 17963;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,15497,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,12675,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,2,0,1,0,100,6,1000,1000,900000,900000,11,34880,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Elemental Armor on Spawn'),
(@ENTRY,0,3,0,9,0,100,2,0,8,15000,20000,11,32192,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Nova on Close'),
(@ENTRY,0,4,0,9,0,100,4,0,8,15000,20000,11,15531,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Nova on Close');

-- Wastewalker Worker
SET @ENTRY := 17964;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2500,7500,8000,11000,11,13738,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rend'),
(@ENTRY,0,1,0,0,0,100,4,2500,7500,8000,11000,11,37662,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rend'),
(@ENTRY,0,2,0,2,0,100,7,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,3,0,2,0,100,7,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP');
-- NPC talk text insert
SET @ENTRY := 17964;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

