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
 
  /* Dungeon Normal for 5 people */
    /* Trash Mobs & Bosses */

-- Electrocutioner 6000
SET @ENTRY := 6235;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,1,0,9,0,100,2,0,30,14500,27400,11,11082,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Megavolt on Close'),
(@ENTRY,0,2,0,0,0,100,2,15700,26500,10900,27300,11,11084,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Shock'),
(@ENTRY,0,3,0,0,0,100,2,17200,33500,17800,38500,11,11085,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Chain Bolt');
-- NPC talk text insert
SET @ENTRY := 6235;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Electric justice!',14,0,100,0,0,5811, 'combat Say');

-- Mekgineer Thermaplugg
SET @ENTRY := 7800;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,12000,15000,11,10101,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Knock Away'),
(@ENTRY,0,1,0,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,2,0,0,0,100,2,20000,20000,40000,65000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text in Combat'),
(@ENTRY,0,3,4,0,0,100,2,6000,6000,30000,30000,12,7915,1,60000,0,0,0,1,0,0,0,0,0,0,0,'Summon Walking Bomb in Combat'),
(@ENTRY,0,4,5,61,0,100,3,0,0,0,0,12,7915,1,60000,0,0,0,1,0,0,0,0,0,0,0,'Summon Walking Bomb in Combat'),
(@ENTRY,0,5,0,61,0,100,3,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text in Combat'),
(@ENTRY,0,6,0,5,0,100,3,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say text on Player Kill'),
(@ENTRY,0,7,0,0,0,100,2,8000,8000,14000,16000,11,74720,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pound'),
(@ENTRY,0,8,0,0,0,100,2,15000,15000,33000,35000,11,11130,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Knock Away'),
(@ENTRY,0,9,0,0,0,100,2,9000,10000,33500,39000,11,93655,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Steam Blast'),
(@ENTRY,0,10,0,0,0,100,2,2000,15000,8000,29000,11,52778,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Welding Beam');
-- NPC talk text insert
SET @ENTRY := 7800;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'USURPERS!!! GNOMEREGAN IS MINE!!!',14,0,100,0,0,5807, 'combat Say'),
(@ENTRY,1,0, 'My machines are the future! They\'ll destroy you all!',14,0,100,0,0,5808, 'combat Say'),
(@ENTRY,2,0, 'Explosions! MORE explosions! I\'ve got to have more explosions!',14,0,100,0,0,5809, 'combat Say'),
(@ENTRY,3,0, '...and stay dead! He got served!',14,0,100,0,0,5810, 'combat Say');

-- Viscous Fallout
SET @ENTRY := 7079;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,17000,19000,11,21687,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Toxic Volley');

-- Dark Iron Ambassador
SET @ENTRY := 6228;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,2,2000,2000,240000,240000,11,10870,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Burning Servant'),
(@ENTRY,0,2,0,0,0,100,2,3000,3000,120000,120000,11,184,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fire Shield');

-- Arcane Nullifier X-21
SET @ENTRY := 6232;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,15700,22900,20500,43400,11,10831,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Reflection Field'),
(@ENTRY,0,1,0,0,0,100,2,17500,32100,24100,32600,11,10832,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Mass Nullify');

-- Crowd Pummeler 9-60
SET @ENTRY := 6229;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,17200,33400,11,10887,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Crowd Pummel on Close'),
(@ENTRY,0,1,0,0,0,100,2,10000,22000,16000,33000,11,5568,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Trample'),
(@ENTRY,0,2,0,0,0,100,2,11900,13400,8300,18000,11,8374,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcing Smash');

-- Burning Servant
SET @ENTRY := 7738;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,10869,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Embers on Aggro');

-- Caverndeep Burrower
SET @ENTRY := 6206;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,4000,9000,10000,11,87081,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike');

-- Caverndeep Reaver
SET @ENTRY := 6211;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,4000,8000,12000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave');

-- Corrosive Lurker
SET @ENTRY := 6219;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,11000,17000,11,9459,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Corrosive Ooze on Close');

-- Dark Iron Agent
SET @ENTRY := 6212;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,15700,24400,21300,34900,11,11802,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dark Iron Land Mine');

-- Dark Iron Land Mine
SET @ENTRY := 8035;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 1 on Aggro'),
(@ENTRY,0,1,0,4,1,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving on Aggro'),
(@ENTRY,0,2,0,4,1,100,3,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Attack on Aggro'),
(@ENTRY,0,3,4,0,1,100,3,5000,5000,0,0,11,92552,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Detonation'),
(@ENTRY,0,4,0,61,1,100,3,0,0,0,0,41,500,0,0,0,0,0,1,0,0,0,0,0,0,0,'Despawn');

-- Holdout Medic
SET @ENTRY := 6392;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,1000,1000,1800000,1800000,11,13864,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Power Word: Fortitude on Spawn'),
(@ENTRY,0,1,0,14,0,100,2,2000,40,20000,25000,11,34945,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Heal on Friendlies'),
(@ENTRY,0,2,0,14,0,100,2,1200,40,24000,28000,11,22168,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Renew on Friendlies');

-- Holdout Technician
SET @ENTRY := 6407;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,2,5000,5000,12000,15000,11,8858,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Bomb');

-- Holdout Warrior
SET @ENTRY := 6391;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,14000,16000,11,12555,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pummel'),
(@ENTRY,0,1,0,9,0,100,2,0,5,8000,11000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike on Close');

-- Irradiated Horror
SET @ENTRY := 6220;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,1000,1000,0,0,11,21862,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Radiation Visual on Spawn'),
(@ENTRY,0,1,0,0,0,100,2,4000,4000,17800,19200,11,744,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Poison');

-- Leprous Defender
SET @ENTRY := 6223;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,2,5000,5000,30000,45000,11,14443,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Multi-Shot');

-- Mechanized Guardian
SET @ENTRY := 6234;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,20,14500,19300,11,11820,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Electrified Net on Close');

-- Irradiated Slime
SET @ENTRY := 6218;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,3,0,0,0,0,11,10341,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Radiation Cloud on Death'),
(@ENTRY,0,1,0,9,0,100,2,0,15,18500,21200,11,81039,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Toxic Nova on Close'),
(@ENTRY,0,2,0,1,0,100,3,1000,1000,0,0,11,21862,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Radiation Visual on Spawn');

-- Leprous Machinesmith
SET @ENTRY := 6224;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,13398,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,1,0,1,0,100,2,10000,45000,30000,70000,11,10348,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Tune Up OOC'),
(@ENTRY,0,2,0,4,0,100,3,0,0,0,0,39,10,0,0,0,0,0,1,0,0,0,0,0,0,0,'Call For Help on Aggro'),
(@ENTRY,0,3,0,0,0,100,2,8000,8000,22000,25000,11,10732,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Supercharge'),
(@ENTRY,0,4,0,4,0,30,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro');
-- NPC talk text insert
SET @ENTRY := 6224;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'A foul trogg if ever I saw one.  Die!',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,0,1, 'This sickness clouds my vision, but I know you must be a trogg.  Die foul invader!',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,0,2, 'No gnome will be left behind.',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,0,3, 'The troggs...they never stop coming.  Die trogg!  Die!',12,0,50,0,0,0, 'combat Say');

-- Leprous Technician
SET @ENTRY := 6222;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,13398,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,1,0,1,0,100,2,10000,45000,30000,70000,11,10348,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Tune Up OOC'),
(@ENTRY,0,2,0,4,0,100,3,0,0,0,0,39,10,0,0,0,0,0,1,0,0,0,0,0,0,0,'Call For Help on Aggro'),
(@ENTRY,0,3,0,0,0,100,2,8000,8000,22000,25000,11,10732,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Supercharge'),
(@ENTRY,0,4,0,4,0,30,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro');
-- NPC talk text insert
SET @ENTRY := 6222;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'A foul trogg if ever I saw one.  Die!',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,0,1, 'This sickness clouds my vision, but I know you must be a trogg.  Die foul invader!',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,0,2, 'No gnome will be left behind.',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,0,3, 'The troggs...they never stop coming.  Die trogg!  Die!',12,0,50,0,0,0, 'combat Say');

-- Irradiated Pillager
SET @ENTRY := 6329;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,1000,1000,0,0,11,21862,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Radiation Visual on Spawn'),
(@ENTRY,0,1,0,9,0,100,2,0,25,3600,7200,11,92266,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Radiation Bolt on Close'),
(@ENTRY,0,2,3,6,0,100,3,0,0,0,0,11,9798,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Radiation on Death'),
(@ENTRY,0,3,0,61,0,100,3,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text'),
(@ENTRY,0,4,0,2,0,100,3,0,30,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP'),
(@ENTRY,0,5,0,2,0,100,3,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP'),
(@ENTRY,0,6,0,0,0,100,2,3000,3000,16000,17000,11,9775,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Irradiated');
-- NPC talk text insert
SET @ENTRY := 6329;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy'),
(@ENTRY,1,0, '%s blood sprays into the air!',16,0,100,0,0,0, 'combat Emote');

-- Mechano-Frostwalker
SET @ENTRY := 6227;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,30,26700,30700,11,10734,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hail Storm on Close'),
(@ENTRY,0,1,0,0,0,100,2,17100,17100,21000,34500,11,11264,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Ice Blast');

-- Mechano-Flamewalker
SET @ENTRY := 6226;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,10900,20400,11,10733,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Spray on Close'),
(@ENTRY,0,1,0,0,0,100,2,10200,18000,14400,25300,11,11970,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fire Nova');

-- Mechano-Tank
SET @ENTRY := 6225;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3500,4100,11,10346,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Machine Gun');

-- Peacekeeper Security Suit
SET @ENTRY := 6230;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,20,20500,22000,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Net on Close'),
(@ENTRY,0,1,0,0,0,100,2,8200,24900,18000,32000,11,10730,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Pacify');

-- Mobile Alert System
SET @ENTRY := 7849;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,1,0,0,0,100,3,2500,2500,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text in Combat'),
(@ENTRY,0,2,3,0,0,100,3,4800,4800,0,0,11,1543,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Flare'),
(@ENTRY,0,3,0,61,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text'),
(@ENTRY,0,4,5,0,0,100,3,6800,6800,0,0,12,6233,1,600000,0,0,0,1,0,0,0,0,0,0,0,'Summon Mechanized Sentry'),
(@ENTRY,0,5,0,61,0,100,3,0,0,0,0,12,6233,1,600000,0,0,0,1,0,0,0,0,0,0,0,'Summon Mechanized Sentry');
-- NPC talk text insert
SET @ENTRY := 7849;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Warning! Warning! Intruder alert! Intruder alert!',14,0,100,0,0,5805, 'combat Say');

