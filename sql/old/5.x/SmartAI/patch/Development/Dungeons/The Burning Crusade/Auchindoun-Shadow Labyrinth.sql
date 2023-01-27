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
	
-- Cabal Acolyte
SET @ENTRY := 18633;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,14,0,100,2,9000,20,5000,9000,11,12039,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Heal on Friendlies'),
(@ENTRY,0,1,0,14,0,100,4,15000,20,5000,9000,11,38209,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Heal on Friendlies'),
(@ENTRY,0,2,0,14,0,100,2,4000,20,12000,15000,11,25058,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Renew on Friendlies'),
(@ENTRY,0,3,0,14,0,100,4,7000,20,12000,15000,11,38210,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Renew on Friendlies');

-- Cabal Assassin
SET @ENTRY := 18636;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,7,0,0,0,0,11,30991,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Spawn'),
(@ENTRY,0,1,0,7,0,100,7,0,0,0,0,11,30991,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Evade'),
(@ENTRY,0,2,0,9,0,100,7,0,8,0,0,11,30986,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cheap Shot on Close'),
(@ENTRY,0,3,0,67,0,100,6,9000,12000,0,0,11,30992,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Backstab'),
(@ENTRY,0,4,0,0,0,100,6,2000,4500,12000,20000,11,30981,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crippling Poison'),
(@ENTRY,0,5,0,0,0,100,6,8000,11000,22000,25000,11,36974,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wound Poison');

-- Cabal Cultist
SET @ENTRY := 18631;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,13,0,100,6,9000,11000,0,0,11,15614,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Kick on Player Spell Cast'),
(@ENTRY,0,1,0,0,0,100,6,4000,5000,10000,13000,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thrash');

-- Cabal Deathsworn
SET @ENTRY := 18635;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,8000,10000,12000,15000,11,33480,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Black Cleave'),
(@ENTRY,0,1,0,0,0,100,4,8000,10000,12000,15000,11,38226,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Black Cleave'),
(@ENTRY,0,2,0,0,0,100,6,3000,7000,10000,14000,11,11428,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Knockdown'),
(@ENTRY,0,3,0,2,0,100,7,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,4,0,2,0,100,7,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP');
-- NPC talk text insert
SET @ENTRY := 18635;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage');

-- Cabal Executioner
SET @ENTRY := 18632;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,6000,11000,9000,13000,11,33500,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirlwind'),
(@ENTRY,0,1,0,12,0,100,6,0,20,9000,13000,11,77720,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Execute when Target is 20% HP'),
(@ENTRY,0,2,0,2,0,100,7,0,30,0,0,11,30485,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,3,0,2,0,100,7,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP');
-- NPC talk text insert
SET @ENTRY := 18632;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage');

-- Cabal Familiar
SET @ENTRY := 18641;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,20801,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,38239,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt');

-- Cabal Fanatic
SET @ENTRY := 18830;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,9000,15000,18000,11,12021,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fixate');

-- Cabal Ritualist
SET @ENTRY := 18794;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,15497,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,12675,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,2,0,9,0,100,2,0,8,8000,15000,11,15532,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Nova on Close'),
(@ENTRY,0,3,0,9,0,100,4,0,8,8000,15000,11,15063,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Nova on Close'),
(@ENTRY,0,4,0,0,0,100,2,2000,4500,12000,20000,11,33833,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Missiles'),
(@ENTRY,0,5,0,0,0,100,4,2000,4500,12000,20000,11,38264,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Missiles'),
(@ENTRY,0,6,0,0,0,100,6,6000,9000,18000,22000,11,33487,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Addle Humanoid'),
(@ENTRY,0,7,0,0,0,100,2,11000,12000,25000,26000,11,20795,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Fire Blast'),
(@ENTRY,0,8,0,0,0,100,4,11000,12000,25000,26000,11,14145,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Fire Blast'),
(@ENTRY,0,9,0,1,0,100,7,1000,1000,1000,1000,11,74919,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dark Aura on Spawn');

-- Cabal Shadow Priest
SET @ENTRY := 18637;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,7,0,0,0,0,11,16592,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadowform on Spawn'),
(@ENTRY,0,1,0,9,0,100,2,0,30,12000,15000,11,14032,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Word: Pain on Close'),
(@ENTRY,0,2,0,9,0,100,4,0,30,12000,15000,11,17146,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Word: Pain on Close'),
(@ENTRY,0,3,0,0,0,100,2,5000,8000,10000,15000,11,17165,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Mind Flay'),
(@ENTRY,0,4,0,0,0,100,4,5000,8000,10000,15000,11,38243,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Mind Flay');

-- Cabal Spellbinder
SET @ENTRY := 18639;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,3400,4700,11,33335,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,6,5000,10000,20000,30000,11,33502,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Brain Wash'),
(@ENTRY,0,2,0,0,0,100,6,2000,4500,17000,19000,11,32691,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Spell Shock');

-- Cabal Summoner
SET @ENTRY := 18634;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,14034,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,15228,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,2,0,2,0,50,7,0,50,0,0,11,33507,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Cabal Acolyte at 50% HP'),
(@ENTRY,0,3,0,2,0,50,7,0,50,0,0,11,33506,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Cabal Deathsworn at 50% HP'),
(@ENTRY,0,4,0,0,0,100,6,2000,4500,12000,20000,11,33335,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt');

-- Cabal Warlock
SET @ENTRY := 18640;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,12471,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,15232,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,2,0,1,0,100,6,500,1000,600000,600000,11,13787,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demon Armor on Spawn'),
(@ENTRY,0,3,0,0,0,100,2,2000,3000,22000,25000,11,32863,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Seed of Corruption'),
(@ENTRY,0,4,0,0,0,100,4,2000,3000,22000,25000,11,38252,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Seed of Corruption');

-- Cabal Zealot
SET @ENTRY := 18638;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,12471,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,15472,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,2,0,2,0,100,7,0,30,0,0,11,33958,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,3,0,2,0,100,7,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP'),
(@ENTRY,0,4,23,2,0,100,7,0,20,0,0,11,33499,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shape of the Beast at 20% HP'),
(@ENTRY,0,5,0,61,0,100,7,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Moving on Cast Shape of the Beast at 20% HP');
-- NPC talk text insert
SET @ENTRY := 18638;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage');

-- Fel Guardhound
SET @ENTRY := 18642;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,7000,11000,11,30849,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Spell Lock');

-- Fel Overseer
SET @ENTRY := 18796;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,27577,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Intercept on Aggro'),
(@ENTRY,0,1,0,0,0,100,6,30000,30000,30000,30000,11,19134,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Frightening Shout'),
(@ENTRY,0,2,0,0,0,100,6,5000,9000,12000,16000,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike'),
(@ENTRY,0,3,0,0,0,100,6,9000,12000,9000,16000,11,30471,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Uppercut');

-- Maiden of Discipline
SET @ENTRY := 18663;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,8000,13000,11,32202,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lash of Pain on Close'),
(@ENTRY,0,1,0,0,0,100,6,5000,11000,12000,18000,11,31865,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Seduction');

-- Malicious Instructor
SET @ENTRY := 18848;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,10000,10000,20000,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Disarm'),
(@ENTRY,0,1,0,0,0,100,7,8000,12000,0,0,11,33493,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mark of Malice'),
(@ENTRY,0,2,0,0,0,100,6,7000,11000,12000,18000,11,33501,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Nova');

-- Summoned Cabal Acolyte
SET @ENTRY := 19208;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,14,0,100,2,9000,20,5000,8000,11,12039,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Heal on Friendlies'),
(@ENTRY,0,1,0,14,0,100,4,15000,20,5000,8000,11,38209,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Heal on Friendlies'),
(@ENTRY,0,2,0,14,0,100,2,4000,20,12000,15000,11,25058,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Renew on Friendlies'),
(@ENTRY,0,3,0,14,0,100,4,7000,20,12000,15000,11,38210,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Renew on Friendlies'),
(@ENTRY,0,4,0,7,0,100,7,0,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Despawn on Evade');

-- Summoned Cabal Deathsworn
SET @ENTRY := 19209;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,7000,11000,11000,15000,11,33480,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Black Cleave'),
(@ENTRY,0,1,0,0,0,100,4,7000,11000,11000,15000,11,38226,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Black Cleave'),
(@ENTRY,0,2,0,0,0,100,6,3000,7000,9000,15000,11,11428,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Knockdown'),
(@ENTRY,0,3,0,2,0,100,7,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,4,0,2,0,100,7,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP'),
(@ENTRY,0,5,0,7,0,100,7,0,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Despawn on Evade');
-- NPC talk text insert
SET @ENTRY := 19209;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage');

-- Void Traveler
SET @ENTRY := 19226;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,4500,12000,20000,11,33783,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Empowering Shadows'),
(@ENTRY,0,1,0,0,0,100,4,2000,4500,12000,20000,11,39364,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Empowering Shadows'),
(@ENTRY,0,2,0,0,0,100,6,5000,9000,18000,25000,11,33846,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Nova');

