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
	
-- Azure Mage Slayer
SET @ENTRY := 31010;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,1000,5000,14000,20000,11,58469,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Empowerment');

-- Chaos Watcher
SET @ENTRY := 32235;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,7000,11000,17000,21000,11,54396,0,0,0,0,0,2,1,0,0,0,0,0,0,'Cast Optic Link'),
(@ENTRY,0,1,0,9,0,100,6,0,8,4000,6000,11,54527,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Corrosive Saliva on Close');

-- Lava Hound
SET @ENTRY := 32237;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,8000,11000,16000,22000,11,59469,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Breath'),
(@ENTRY,0,1,0,0,0,100,6,4000,7000,10000,14000,11,59468,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Firebolt'),
(@ENTRY,0,2,0,0,0,100,6,11000,15000,30000,40000,11,54249,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Lava Burn'),
(@ENTRY,0,3,0,0,0,100,6,1000,3000,30000,45000,11,59466,0,0,0,0,0,2,32,0,0,0,0,0,0,'Cast Cauterizing Flames');

-- Portal Guardian
SET @ENTRY := 30660;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,7000,12000,9000,11000,11,58508,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Side Swipe'),
(@ENTRY,0,1,0,0,0,100,6,5000,7000,6000,9000,11,58504,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Agonizing Strike');

-- Portal Guardian
SET @ENTRY := 30892;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,6000,10000,11000,12000,11,58526,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Azure Bindings'),
(@ENTRY,0,1,0,9,0,100,2,0,5,13000,21000,11,58517,0,0,0,0,0,2,32,0,0,0,0,0,0,'Cast Grievous Wound on Close'),
(@ENTRY,0,2,0,9,0,100,4,0,5,13000,21000,11,59262,0,0,0,0,0,2,32,0,0,0,0,0,0,'Cast Grievous Wound on Close'),
(@ENTRY,0,3,0,9,0,100,6,0,5,7000,12000,11,58516,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Overpower on Close');

-- Azure Spellbreaker
SET @ENTRY := 31009;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,30,13000,16000,11,58462,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Arcane Blast on Close'),
(@ENTRY,0,1,0,9,0,100,4,0,30,13000,16000,11,59257,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Arcane Blast on Close'),
(@ENTRY,0,2,0,0,0,100,6,3000,6000,7000,10000,11,25603,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Slow');

-- Azure Invader
SET @ENTRY := 31008;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,8000,11000,5000,9000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,1,0,9,0,100,2,0,5,13000,16000,11,58459,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Impale on Close'),
(@ENTRY,0,2,0,9,0,100,4,0,5,13000,16000,11,59256,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Impale on Close');

-- Ethereal Sphere
SET @ENTRY := 32582;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,5,0,0,0,0,41,40000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Despawn on Timer'),
(@ENTRY,0,1,0,10,0,100,6,1,5,10000,14000,11,59474,0,0,0,0,0,6,1,0,0,0,0,0,0,'Cast Arcane Power');

-- Azure Binder
SET @ENTRY := 31007;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,58456,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,59248,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,2,0,9,0,100,2,0,8,9000,15000,11,58455,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Explosion on Close'),
(@ENTRY,0,3,0,9,0,100,4,0,8,9000,15000,11,59245,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Explosion on Close');

-- Arakkoa Talon Guard
SET @ENTRY := 32228;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,8,10000,16000,11,54462,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Howling Screech on Close'),
(@ENTRY,0,1,0,0,0,100,6,9000,14000,25000,30000,11,39215,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gushing Wound'),
(@ENTRY,0,2,0,0,0,100,6,5000,7000,5000,7000,11,14516,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike');

-- Arakkoa Windwalker
SET @ENTRY := 32226;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,3400,4700,11,53044,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,6,13000,20000,18000,25000,11,59463,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Break Bonds'),
(@ENTRY,0,2,0,0,0,100,6,1000,5000,120000,130000,11,59471,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Earth Shield'),
(@ENTRY,0,3,0,14,0,100,6,30000,40,15000,22000,11,59473,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Chain Heal on Friendlies');

-- Void Lord
SET @ENTRY := 32230;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,6000,10000,9000,14000,11,59743,0,0,0,0,0,5,1,0,0,0,0,0,0,'Cast Void Shift'),
(@ENTRY,0,1,0,0,0,100,6,1000,3000,30000,45000,11,54369,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Void Sentry'),
(@ENTRY,0,2,0,0,0,100,6,3000,5000,12000,17000,11,59745,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shroud of Darkness');

-- Swirling Water Revenant
SET @ENTRY := 32234;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,5000,12000,13000,11,59520,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Water Blast'),
(@ENTRY,0,1,0,0,0,100,6,9000,9000,17000,18000,11,59521,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Water Bolt Volley'),
(@ENTRY,0,2,0,2,0,100,7,0,50,0,0,11,54306,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Protective Bubble at 50% HP'),
(@ENTRY,0,3,0,2,0,100,7,0,30,0,0,11,59522,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP');

-- Portal Keeper
SET @ENTRY := 30695;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,58531,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,61593,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,2,0,9,0,100,2,0,8,13000,19000,11,58532,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frostbolt Volley on Close'),
(@ENTRY,0,3,0,9,0,100,4,0,8,13000,19000,11,61594,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frostbolt Volley on Close'),
(@ENTRY,0,4,0,9,0,100,6,0,8,9000,14000,11,58534,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Deep Freeze on Close');

-- Ethereal Wind Trader
SET @ENTRY := 32231;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,8000,8000,14000,16000,11,59483,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Barrage Volley'),
(@ENTRY,0,1,0,0,0,100,6,5000,5000,11000,11000,11,59485,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Buffet'),
(@ENTRY,0,2,0,0,0,100,6,12000,12000,55000,55000,11,54138,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Ethereal Sphere');

-- Portal Keeper
SET @ENTRY := 30893;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,58535,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,61590,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,2,0,9,0,100,2,0,40,6000,8000,11,58536,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Volley on Close'),
(@ENTRY,0,3,0,9,0,100,4,0,40,6000,8000,11,61591,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Volley on Close'),
(@ENTRY,0,4,0,9,0,100,6,0,8,9000,14000,11,58537,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Polymorph');

-- Veteran Mage Hunter
SET @ENTRY := 58040;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,20829,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,13748,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,2,0,0,0,100,2,5000,7000,12000,13000,11,20823,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball'),
(@ENTRY,0,3,0,0,0,100,4,5000,7000,12000,13000,11,12466,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball'),
(@ENTRY,0,4,0,1,0,100,7,1000,1000,0,0,11,58040,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Destroy Door Seal on Spawn'),
(@ENTRY,0,5,0,0,0,100,4,5000,7000,12000,13000,11,15043,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frostbolt'),
(@ENTRY,0,6,0,0,0,100,2,5000,7000,12000,13000,11,20822,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frostbolt');
