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
    /* Trash Mobs & Bosses*/
 
-- Anger'rel
SET @ENTRY := 9035;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,3000,20000,26000,11,15062,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shield Wall'),
(@ENTRY,0,1,0,0,0,100,2,4000,5000,15000,19000,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sunder Armor'),
(@ENTRY,0,2,0,0,0,100,2,5000,7000,7000,11000,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike'),
(@ENTRY,0,3,0,0,0,100,2,11000,15000,10000,15000,11,12169,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shield Block');

-- Bael'Gar
SET @ENTRY := 9016;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,8000,12000,10000,14000,11,13880,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Magma Splash'),
(@ENTRY,0,1,0,2,0,100,3,0,60,0,0,11,13895,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Spawn of Bael\'Gar at 60% HP'),
(@ENTRY,0,2,0,2,0,100,3,0,40,0,0,11,13895,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Spawn of Bael\'Gar at 40% HP'),
(@ENTRY,0,3,0,2,0,100,3,0,20,0,0,11,13895,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Spawn of Bael\'Gar at 20% HP');

-- Dark Keeper Bethek
SET @ENTRY := 9438;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,15228,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,2,3000,5000,15000,20000,11,12738,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Amplify Damage');

-- Dark Keeper Ofgut
SET @ENTRY := 9442;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,15230,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,2,7000,12000,18000,24000,11,7121,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Anti-Magic Shield');

-- Dark Keeper Uggel
SET @ENTRY := 9439;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,15232,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,2,5000,9000,30000,35000,11,14875,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Curse of Agony');

-- Dark Keeper Vorfalk
SET @ENTRY := 9437;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,15234,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,2,6000,9000,7000,12000,11,15236,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shock');

-- Dark Keeper Zimrel
SET @ENTRY := 9441;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,15238,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,2,9000,14000,40000,55000,11,11974,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Power Word: Shield');

-- Dope'rel
SET @ENTRY := 9040;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,7000,6000,9000,11,15581,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sinister Strike'),
(@ENTRY,0,1,0,0,0,100,2,1000,5000,25000,35000,11,15087,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Evasion'),
(@ENTRY,0,2,0,67,0,100,2,5000,9000,0,0,11,15582,0,0,0,0,0,2,0,0,0,0,0,0,0,'Casts Backstab'),
(@ENTRY,0,3,0,0,0,100,2,8000,12000,12000,17000,11,12540,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Gouge'),
(@ENTRY,0,4,0,9,0,100,2,0,5,12000,16000,11,15583,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rupture on Close');

-- Eviscerator
SET @ENTRY := 9029;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,4000,16000,18000,11,14331,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Vicious Rend'),
(@ENTRY,0,1,0,0,0,100,2,8000,9000,12000,13000,11,15245,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley'),
(@ENTRY,0,2,0,0,0,100,2,7000,12000,18000,24000,11,7121,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Anti-Magic Shield');

-- Fineous Darkvire <Chief Architect>
SET @ENTRY := 9056;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,13,0,100,2,11000,15000,0,0,11,11978,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Kick on Target Spellcast'),
(@ENTRY,0,1,0,9,0,100,2,0,5,6000,8500,11,13953,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Holy Strike on Close'),
(@ENTRY,0,2,0,0,0,100,2,1000,1000,240000,240000,11,8258,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Devotion Aura'),
(@ENTRY,0,3,0,2,0,100,3,0,40,0,0,11,15493,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Holy Light at 40% HP'),
(@ENTRY,0,4,0,2,0,100,3,0,20,0,0,11,15346,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Seal of Reckoning at 20% HP');

-- Golem Lord Argelmach
SET @ENTRY := 8983;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,7000,12000,7000,11000,11,15605,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Shock'),
(@ENTRY,0,1,0,9,0,100,2,0,30,9000,13000,11,15305,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Chain Lightning on Close'),
(@ENTRY,0,2,0,1,0,100,2,500,1000,600000,600000,11,15507,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lightning Shield on Spawn'),
(@ENTRY,0,3,0,16,0,100,2,15507,1,15000,30000,11,15507,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lightning Shield on Repeat');

-- Houndmaster Grebmar
SET @ENTRY := 9319;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,10,22000,24000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demoralizing Shout on Close'),
(@ENTRY,0,1,0,2,0,100,3,0,30,0,0,11,21049,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bloodlust at 30% HP'),
(@ENTRY,0,2,0,0,0,100,2,5000,5000,12000,14000,11,15615,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pummel');

-- Hurley Blackbreath
SET @ENTRY := 9537;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,6000,12000,16000,11,9573,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Breath'),
(@ENTRY,0,1,0,2,0,100,3,0,35,0,0,11,14872,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Drunken Rage at 35% HP');

-- Lord Incendius
SET @ENTRY := 9017;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,9000,17000,18000,24000,11,14099,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mighty Blow'),
(@ENTRY,0,1,0,0,0,100,2,6000,11000,9000,16000,11,13900,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fiery Burst'),
(@ENTRY,0,2,0,0,0,100,2,12000,16000,11000,14000,11,13899,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Fire Storm'),
(@ENTRY,0,3,0,0,0,100,2,1000,5000,20000,28000,11,26977,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Curse of the Elemental Lord');

-- Lord Roccor
SET @ENTRY := 9025;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,7000,11000,9000,14000,11,13728,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Earth Shock'),
(@ENTRY,0,1,0,9,0,100,2,0,15,9000,14000,11,6524,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Ground Tremor on Close'),
(@ENTRY,0,2,0,0,0,100,2,5000,8000,13000,18000,11,13729,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Shock');

-- Hedrum the Creeper
SET @ENTRY := 9032;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,25000,28000,11,15475,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Baneful Poison'),
(@ENTRY,0,1,0,0,0,100,2,3000,3000,12000,13000,11,3609,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Paralyzing Poison'),
(@ENTRY,0,2,0,9,0,100,2,0,30,10000,13000,11,15474,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Web Explosion on Close');

-- Hate'rel
SET @ENTRY := 9034;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,15232,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,2,9000,14000,40000,48000,11,12040,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Shield'),
(@ENTRY,0,2,0,9,0,100,2,0,5,8000,9000,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike on Close');

-- Ok'thor the Breaker
SET @ENTRY := 9030;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,15254,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,2,5000,5000,12000,17000,11,13323,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Polymorph'),
(@ENTRY,0,2,0,9,0,100,2,0,25,11000,12000,11,15453,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Explosion on Close'),
(@ENTRY,0,3,0,0,0,100,2,3000,4000,9000,14000,11,13747,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Slow');

-- Panzor the Invincible
SET @ENTRY := 8923;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,9941,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Obsidian Reflection on Spawn');

-- Plugger Spazzring
SET @ENTRY := 9499;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,12739,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,2,5000,5000,15000,17000,11,8994,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Banish'),
(@ENTRY,0,2,0,9,0,100,2,0,25,17000,22000,11,12742,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Immolate on Close'),
(@ENTRY,0,3,0,0,0,100,2,3000,4000,19000,22000,11,13338,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Curse of Tongues'),
(@ENTRY,0,4,0,1,0,100,2,500,1000,600000,600000,11,13787,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demon Armor on Spawn');

-- Pyromancer Loregrain
SET @ENTRY := 9024;
SET @ENTRYTOTEM := 9637;
SET @TOTEMSPELL := 15037;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
UPDATE `creature_template` SET `AIName`='0' WHERE `entry`=@ENTRYTOTEM;
UPDATE `creature_template` SET `spell1`=@TOTEMSPELL WHERE `entry`=@ENTRYTOTEM;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,6000,7000,11000,11,15095,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Molten Blast'),
(@ENTRY,0,1,0,0,0,100,2,6000,11000,12000,19000,11,15616,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Flame Shock'),
(@ENTRY,0,2,0,0,0,100,2,2000,7000,30000,45000,11,15041,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fire Ward'),
(@ENTRY,0,3,0,0,0,100,2,7000,10000,25000,35000,11,15038,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Scorching Totem');

-- Ribbly Screwspigot
SET @ENTRY := 9543;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,4000,12000,12000,11,12540,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Gouge'),
(@ENTRY,0,1,0,0,0,100,2,5000,6000,10000,14000,11,9080,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Hamstring');

-- Seeth'rel
SET @ENTRY := 9038;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,12675,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,2,3000,5000,64000,75000,11,15044,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Ward'),
(@ENTRY,0,2,0,9,0,100,2,0,8,16000,23000,11,12674,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Nova on Close'),
(@ENTRY,0,3,0,0,0,100,2,9000,14000,19000,24000,11,15244,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cone of Cold'),
(@ENTRY,0,4,0,1,0,100,2,500,1000,600000,600000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Armor on Spawn'),
(@ENTRY,0,5,0,0,0,100,2,8000,8000,15000,16000,11,8364,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blizzard');

-- Verek
SET @ENTRY := 9042;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,3,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,1,0,2,0,100,3,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP'),
(@ENTRY,0,2,0,9,0,100,2,0,20,20000,45000,11,15042,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Curse of Blood on Close');
-- NPC talk text insert
SET @ENTRY := 9042;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage');

-- Vile'rel
SET @ENTRY := 9036;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,3,0,50,0,0,11,15586,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Heal at 50% HP'),
(@ENTRY,0,1,0,9,0,100,2,0,30,3400,4800,11,15587,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mind Blast on Close'),
(@ENTRY,0,2,0,0,0,100,2,20000,30000,60000,120000,11,11974,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Power Word: Shield');

-- Warder Stilgiss
SET @ENTRY := 9041;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,12675,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,2,3000,5000,64000,75000,11,15044,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Ward'),
(@ENTRY,0,2,0,9,0,100,2,0,8,16000,23000,11,12674,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Nova on Close'),
(@ENTRY,0,3,0,1,0,100,2,500,1000,600000,600000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Armor on Spawn');

-- Watchman Doomgrip
SET @ENTRY := 9476;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,4000,9000,11000,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sunder Armor'),
(@ENTRY,0,1,0,2,0,100,3,0,35,0,0,11,15504,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Drink Healing Potion at 35% HP');

-- Anvilrage Footman
SET @ENTRY := 8892;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,14000,14000,11,15614,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Kick'),
(@ENTRY,0,1,0,9,0,100,2,0,5,8000,9000,11,87081,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike on Close');

-- Anvilrage Guardsman
SET @ENTRY := 8891;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,6000,12000,13000,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Disarm'),
(@ENTRY,0,1,0,9,0,100,2,0,5,15000,17000,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sunder Armor on Close'),
(@ENTRY,0,2,0,0,0,100,2,2000,3000,11000,12000,11,12169,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shield Block');

-- Anvilrage Marshal
SET @ENTRY := 8898;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,8258,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Devotion Aura on Aggro'),
(@ENTRY,0,1,0,9,0,100,2,0,5,8000,9000,11,13953,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Holy Strike on Close'),
(@ENTRY,0,2,0,2,0,100,3,0,30,0,0,11,15493,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Holy Light at 30% HP');

-- Anvilrage Medic
SET @ENTRY := 8894;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,500,1000,600000,600000,11,13864,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Power Word: Fortitude on Spawn'),
(@ENTRY,0,1,0,0,0,100,2,5000,6000,10000,12000,11,15587,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mind Blast'),
(@ENTRY,0,2,0,0,0,100,2,12000,15000,28000,32000,11,15585,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Prayer of Healing'),
(@ENTRY,0,3,0,14,0,100,2,3000,40,15000,17000,11,15586,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Heal on Friendlies'),
(@ENTRY,0,4,0,2,0,100,3,0,30,0,0,11,15586,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Heal at 30% HP');

-- Anvilrage Officer
SET @ENTRY := 8895;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,15547,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,2,2,0,100,3,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,3,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,14,2,0,100,3,0,30,0,0,11,13874,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Divine Shield at 30% HP'),
(@ENTRY,0,4,0,0,0,100,2,3000,3000,120000,120000,11,9128,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Battle Shout'),
(@ENTRY,0,5,0,61,0,100,3,0,0,0,0,11,13952,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Holy Light at 30% HP'),
(@ENTRY,0,6,0,9,0,100,2,0,5,9000,13000,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Backhand on Close');
-- NPC talk text insert
SET @ENTRY := 8895;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Anvilrage Overseer
SET @ENTRY := 8889;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,8000,9000,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike on Close'),
(@ENTRY,0,1,0,4,0,100,3,0,0,0,0,11,13589,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Haste Aura on Aggro');

-- Anvilrage Reservist
SET @ENTRY := 8901;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,2,2,0,100,3,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,3,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,0,0,100,2,3000,3000,120000,120000,11,9128,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Battle Shout'),
(@ENTRY,0,4,0,9,0,100,2,0,5,9000,11000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike on Close'),
(@ENTRY,0,5,0,0,0,100,2,5000,5000,13000,15000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hamstring');
-- NPC talk text insert
SET @ENTRY := 8901;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Anvilrage Soldier
SET @ENTRY := 8893;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,8,8000,9000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave on Close'),
(@ENTRY,0,1,0,0,0,100,2,5000,5000,13000,15000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hamstring'),
(@ENTRY,0,2,0,2,0,100,3,0,30,0,0,11,13847,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Recklessness at 30% HP');

-- Anvilrage Warden
SET @ENTRY := 8890;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,30,8000,8500,11,14030,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hooked Net on Close'),
(@ENTRY,0,1,0,0,0,100,2,4000,4000,11000,12000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Bash');

-- Anvilrage Captain
SET @ENTRY := 8903;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,10,22000,24000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demoralizing Shout on Close'),
(@ENTRY,0,1,0,0,0,100,2,4000,4000,15000,16000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Bash'),
(@ENTRY,0,2,0,0,0,100,2,2000,2000,9000,11000,11,13737,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike'),
(@ENTRY,0,3,0,2,0,100,2,0,40,6000,6000,11,12169,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shield Block at 40% HP');

-- Blackbreath Crony
SET @ENTRY := 9541;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,3000,9000,11000,11,15581,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sinister Strike'),
(@ENTRY,0,1,0,0,0,100,2,6000,8000,15000,16000,11,15583,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rupture');

-- Blazing Fireguard
SET @ENTRY := 8910;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,4000,8000,9000,11,13341,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fire Blast'),
(@ENTRY,0,1,0,0,0,100,2,6000,8000,16000,17000,11,20787,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Immolate'),
(@ENTRY,0,2,0,9,0,100,2,0,8,2500,3500,11,15241,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Scorch on Close');

-- Bloodhound
SET @ENTRY := 8921;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,16000,17000,11,13445,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rend'),
(@ENTRY,0,1,0,0,0,100,2,3000,3000,19000,21000,11,13692,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Dire Growl');

-- Bloodhound Mastiff
SET @ENTRY := 8922;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,5000,12000,13000,11,7140,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Expose Weakness'),
(@ENTRY,0,1,0,0,0,100,2,9000,9000,20000,22000,11,15608,0,0,0,0,0,2,1,0,0,0,0,0,0,'Cast Ravenous Claw');

-- Borer Beetle
SET @ENTRY := 8932;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,14539,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Putrid Enzyme on Aggro'),
(@ENTRY,0,1,0,9,0,100,2,0,5,12000,13000,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pierce Armor on Close');

-- Burning Spirit
SET @ENTRY := 9178;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,1,0,0,0,0,11,13489,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Burning Spirit on Death');

-- Arena Spectator
SET @ENTRY := 8916;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,120000,120000,11,9128,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Battle Shout');

-- Burrowing Thundersnout
SET @ENTRY := 8928;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,15611,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,9,0,100,2,0,8,12000,16000,11,15548,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thunderclap on Close'),
(@ENTRY,0,2,0,0,0,100,2,2000,3000,35000,35000,11,14533,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Disjunction');

-- Cave Creeper
SET @ENTRY := 8933;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,14532,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Creeper Venom on Aggro'),
(@ENTRY,0,1,0,9,0,100,2,0,30,9000,13000,11,745,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Web on Close'),
(@ENTRY,0,2,0,0,0,100,2,4000,5000,17000,18000,11,13298,0,0,0,0,0,2,32,0,0,0,0,0,0,'Cast Poison');

-- Dark Guard
SET @ENTRY := 9445;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,5000,8000,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike on Close');

-- Dark Screecher
SET @ENTRY := 8927;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,7000,13000,17000,11,8281,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sonic Burst'),
(@ENTRY,0,1,0,0,0,100,2,2000,3000,33000,35000,11,14538,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Aural Shock');

-- Deep Stinger
SET @ENTRY := 8926;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,7000,11000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave on Close'),
(@ENTRY,0,1,0,0,0,100,2,2000,3000,33000,35000,11,14534,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Barbed Sting'),
(@ENTRY,0,2,0,0,0,100,2,4000,5000,12000,13000,11,7992,0,0,0,0,0,2,32,0,0,0,0,0,0,'Cast Slowing Poison');

-- Doomforge Arcanasmith
SET @ENTRY := 8900;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,13748,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,2,2,0,100,3,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,3,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,9,0,100,2,0,10,8000,9000,11,13745,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Explosion on Close');
-- NPC talk text insert
SET @ENTRY := 8900;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Doomforge Craftsman
SET @ENTRY := 8897;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,15619,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw Wrench on Aggro'),
(@ENTRY,0,1,0,9,0,100,2,5,30,8000,9000,11,9143,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Bomb on Close');

-- Doomforge Dragoon
SET @ENTRY := 8899;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,15620,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,2,2,0,100,3,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,3,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,5,2,0,100,3,0,30,0,0,11,13874,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Divine Shield at 30% HP'),
(@ENTRY,0,4,0,0,0,100,2,3000,3000,120000,120000,11,9128,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Battle Shout'),
(@ENTRY,0,5,0,61,0,100,3,0,0,0,0,11,13952,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Holy Light at 30% HP'),
(@ENTRY,0,6,0,9,0,100,2,0,5,7000,9000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave on Close'),
(@ENTRY,0,7,0,0,0,100,2,8000,8000,12000,13000,11,15495,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Explosive Shot');
-- NPC talk text insert
SET @ENTRY := 8899;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Fireguard
SET @ENTRY := 8909;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,15242,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt');

-- Fireguard Destroyer
SET @ENTRY := 8911;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,30,9000,11000,11,15243,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fireball Volley on Close');

-- Guzzling Patron
SET @ENTRY := 9547;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,20825,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,2,2,0,100,3,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,3,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,9,0,100,2,0,20,16000,17000,11,14868,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Curse of Agony on Close'),
(@ENTRY,0,4,0,2,0,100,3,0,30,0,0,11,14822,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Drunken Rage at 30% HP');
-- NPC talk text insert
SET @ENTRY := 9547;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Grim Patron
SET @ENTRY := 9545;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,3,0,30,0,0,11,14822,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Drunken Rage at 30% HP'),
(@ENTRY,0,1,0,9,0,100,2,0,5,7000,9000,11,15610,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Kick on Close');

-- Hammered Patron
SET @ENTRY := 9554;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,7000,8000,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Backhand on Close'),
(@ENTRY,0,1,0,0,0,100,2,5000,5000,11000,12000,11,14870,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Drunken Stupor');

-- Dredge Worm
SET @ENTRY := 8925;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,7000,8000,12000,11,13298,0,0,0,0,0,2,32,0,0,0,0,0,0,'Cast Poison'),
(@ENTRY,0,1,0,0,0,100,2,2000,3000,33000,35000,11,14535,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dredge Sickness'),
(@ENTRY,0,2,0,0,0,100,2,5000,8000,13000,15000,11,6917,0,0,0,0,0,2,32,0,0,0,0,0,0,'Cast Venom Spit');

-- Molten War Golem
SET @ENTRY := 8908;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,3000,16000,17000,11,15570,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Immolate');

-- Ragereaver Golem
SET @ENTRY := 8906;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,18000,21000,11,17687,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Flurry'),
(@ENTRY,0,1,0,2,0,100,3,0,30,0,0,11,12795,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP'),
(@ENTRY,0,2,0,2,0,100,3,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP');
-- NPC talk text insert
SET @ENTRY := 8906;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy');

-- Ribbly's Crony
SET @ENTRY := 10043;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,2000,11000,12000,11,15581,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sinister Strike'),
(@ENTRY,0,1,0,0,0,100,2,5000,5000,14000,15000,11,15692,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Eviscerate'),
(@ENTRY,0,2,0,0,0,100,2,8000,8000,18000,19000,11,13298,0,0,0,0,0,2,32,0,0,0,0,0,0,'Cast Poison');

-- Shadowforge Citizen
SET @ENTRY := 8902;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,3000,8000,9000,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,1,0,0,0,100,2,5000,6000,12000,13000,11,13339,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fire Blast'),
(@ENTRY,0,2,0,9,0,100,2,0,8,15800,18300,11,11831,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Nova on Close'),
(@ENTRY,0,3,0,2,0,100,3,0,30,0,0,11,11642,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Heal at 30% HP');

-- Shadowforge Flame Keeper
SET @ENTRY := 9956;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,2,2,0,100,3,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,3,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,0,0,100,2,5000,5000,120000,120000,11,9128,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Battle Shout'),
(@ENTRY,0,4,0,0,0,100,2,4000,7000,14000,16000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hamstring'),
(@ENTRY,0,5,0,9,0,100,2,0,5,8000,9000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike on Close');
-- NPC talk text insert
SET @ENTRY := 9956;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Shadowforge Senator
SET @ENTRY := 8904;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,12471,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,2,2,0,100,3,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,3,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,9,0,100,2,0,20,16000,17000,11,14868,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Curse of Agony on Close');
-- NPC talk text insert
SET @ENTRY := 8904;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Shadowforge Peasant
SET @ENTRY := 8896;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,2,2,0,100,3,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,3,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,2,0,100,3,0,30,0,0,11,11642,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Heal at 30% HP');
-- NPC talk text insert
SET @ENTRY := 8896;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Twilight's Hammer Ambassador
SET @ENTRY := 8915;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,500,1000,600000,600000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Armor on Spawn'),
(@ENTRY,0,1,0,0,0,100,2,4000,5000,12000,13000,11,15501,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Earth Shock'),
(@ENTRY,0,2,0,0,0,100,2,3000,3000,11000,15000,11,15096,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Flame Shock'),
(@ENTRY,0,3,0,0,0,100,2,6000,8000,10000,13000,11,15499,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frost Shock'),
(@ENTRY,0,4,0,2,0,100,3,0,50,0,0,11,6742,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bloodlust at 50% HP');

-- Twilight's Hammer Torturer
SET @ENTRY := 8912;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,3000,14000,16000,11,14032,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Shadow Word: Pain');

-- Warbringer Construct
SET @ENTRY := 8905;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,3000,11000,12000,11,15621,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Skull Crack');

-- Wrath Hammer Construct
SET @ENTRY := 8907;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,5000,12000,13000,11,10966,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Uppercut'),
(@ENTRY,0,1,0,9,0,100,2,0,20,9000,12000,11,15575,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Cannon on Close');

-- Weapon Technician
SET @ENTRY := 8920;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,15547,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,2,2,0,100,3,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,3,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,0,0,100,2,5000,5000,12000,12000,11,12551,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frost Shot'),
(@ENTRY,0,4,0,0,0,100,2,8000,8000,25000,26000,11,14443,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Multi-Shot'),
(@ENTRY,0,5,0,0,0,100,2,3000,3000,10000,15000,11,7896,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Exploding Shot');
-- NPC talk text insert
SET @ENTRY := 8920;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Twilight Emissary
SET @ENTRY := 8913;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,15043,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,2,2,0,100,3,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,3,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,9,0,100,2,0,8,15800,18300,11,15063,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Nova on Close'),
(@ENTRY,0,4,0,0,0,100,2,5000,5000,14000,17000,11,8364,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blizzard'),
(@ENTRY,0,5,0,1,0,100,2,500,1000,600000,600000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Armor on Spawn');
-- NPC talk text insert
SET @ENTRY := 8913;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Twilight Bodyguard
SET @ENTRY := 8914;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,5000,12000,14000,11,13902,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fist of Ragnaros'),
(@ENTRY,0,1,0,0,0,100,2,3000,6000,16000,17000,11,15615,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pummel'),
(@ENTRY,0,2,0,14,0,100,2,3000,30,32000,33000,11,13903,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Seal of Sacrifice on Friendlies');
