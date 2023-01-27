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
 
  /* Raid Normal for 25 people */
 /* Trash Mobs */
 
-- Apprentice Star Scryer
SET @ENTRY := 20043;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,50,5000,7000,11,37129,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Volley on Close'),
(@ENTRY,0,1,0,9,0,100,2,0,5,19000,22000,11,37133,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Buffet on Close'),
(@ENTRY,0,2,0,9,0,100,2,0,8,12000,16000,11,38725,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Explosion on Close'),
(@ENTRY,0,3,0,0,0,100,2,15000,18000,14000,17000,11,37132,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Shock');

-- Astromancer
SET @ENTRY := 20033;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,37109,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball Volley'),
(@ENTRY,0,1,0,1,0,100,2,500,1000,600000,600000,11,35915,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Molten Armor on Spawn'),
(@ENTRY,0,2,0,0,0,100,2,12000,15000,12000,15000,11,37110,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fire Blast');

-- Astromancer Lord
SET @ENTRY := 20046;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,37109,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball Volley'),
(@ENTRY,0,1,0,1,0,100,2,500,1000,600000,600000,11,38732,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fire Shield on Spawn'),
(@ENTRY,0,2,0,0,0,100,2,12000,15000,12000,15000,11,37110,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fire Blast'),
(@ENTRY,0,3,0,9,0,100,2,0,5,15000,20000,11,37289,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Dragon\'s Breath on Close');

-- Bloodwarder Legionnaire
SET @ENTRY := 20031;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,42459,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dual Wield on Aggro'),
(@ENTRY,0,1,0,9,0,100,2,0,5,8000,11000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave on Close'),
(@ENTRY,0,2,0,0,0,100,2,10000,15000,12000,15000,11,33500,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirlwind'),
(@ENTRY,0,3,0,2,0,100,2,0,50,18000,24000,11,35949,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bloodthirst at 50% HP');

-- Bloodwarder Marshal
SET @ENTRY := 20035;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,42459,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dual Wield on Aggro'),
(@ENTRY,0,1,0,9,0,100,2,0,5,8000,11000,11,34996,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Uppercut on Close'),
(@ENTRY,0,2,0,0,0,100,2,10000,15000,12000,15000,11,33500,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirlwind'),
(@ENTRY,0,3,0,2,0,100,2,0,50,18000,24000,11,35949,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bloodthirst at 50% HP');

-- Bloodwarder Squire
SET @ENTRY := 20036;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,18000,24000,11,39077,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hammer of Justice on Close'),
(@ENTRY,0,1,0,14,0,100,2,20000,50,16000,21000,11,37254,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Flash of Light on Friendlies'),
(@ENTRY,0,2,0,14,0,100,2,50000,30,21000,25000,11,39078,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Cleanse on Friendlies'),
(@ENTRY,0,3,0,12,0,100,2,0,20,12000,16000,11,37255,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hammer of Wrath when Target is 20% HP'),
(@ENTRY,0,4,0,2,0,100,2,0,30,20000,30000,11,37254,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Flash of Light at 30% HP');

-- Bloodwarder Vindicator
SET @ENTRY := 20032;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,18000,24000,11,39077,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hammer of Justice on Close'),
(@ENTRY,0,1,0,14,0,100,2,20000,50,16000,21000,11,37254,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Flash of Light on Friendlies'),
(@ENTRY,0,2,0,14,0,100,2,50000,30,21000,25000,11,39078,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Cleanse on Friendlies'),
(@ENTRY,0,3,0,12,0,100,2,0,20,12000,16000,11,37255,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hammer of Wrath when Target is 20% HP'),
(@ENTRY,0,4,0,2,0,100,2,0,30,20000,30000,11,37254,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Flash of Light at 30% HP');

-- Cosmic Infuser
SET @ENTRY := 21270;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,15,8000,12000,11,36985,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Holy Nova on Close'),
(@ENTRY,0,1,0,14,0,100,2,80000,40,21000,30000,11,36983,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Heal on Friendlies');

-- Crimson Hand Battle Mage
SET @ENTRY := 20047;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,37262,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frostbolt Volley'),
(@ENTRY,0,1,0,1,0,100,2,500,1000,600000,600000,11,38732,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fire Shield on Spawn'),
(@ENTRY,0,2,0,0,0,100,2,12000,15000,12000,15000,11,37110,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fire Blast'),
(@ENTRY,0,3,0,9,0,100,2,0,5,15000,20000,11,37289,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Dragon\'s Breath on Close'),
(@ENTRY,0,4,0,0,0,100,2,12000,15000,18000,24000,11,37263,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Blizzard'),
(@ENTRY,0,5,0,9,0,100,2,0,8,15000,21000,11,37265,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cone of Cold on Close'),
(@ENTRY,0,6,0,9,0,100,2,0,5,12000,25000,11,39087,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frost Attack on Close');

-- Crimson Hand Blood Knight
SET @ENTRY := 20049;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,18000,24000,11,39077,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hammer of Justice on Close'),
(@ENTRY,0,1,0,14,0,100,2,20000,50,16000,21000,11,37254,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Flash of Light on Friendlies'),
(@ENTRY,0,2,0,14,0,100,2,50000,30,21000,25000,11,39078,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Cleanse on Friendlies'),
(@ENTRY,0,3,0,12,0,100,2,0,20,12000,16000,11,37255,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hammer of Wrath when Target is 20% HP'),
(@ENTRY,0,4,0,2,0,100,2,0,30,20000,30000,11,37254,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Flash of Light at 30% HP'),
(@ENTRY,0,5,0,2,0,100,2,0,55,25000,28000,11,37260,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Renew at 55% HP');

-- Crimson Hand Centurion
SET @ENTRY := 20048;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,9000,19000,26000,11,37268,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Flurry');

-- Crimson Hand Inquisitor
SET @ENTRY := 20050;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,37274,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Power Infusion on Aggro'),
(@ENTRY,0,1,0,0,0,100,2,25000,35000,25000,35000,11,37274,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Power Infusion'),
(@ENTRY,0,2,0,9,0,100,2,0,15,6000,8000,11,37276,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mind Flay on Close'),
(@ENTRY,0,3,0,0,0,100,2,7000,11000,21000,26000,11,37275,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Word: Pain');

-- Crystalcore Mechanic
SET @ENTRY := 20052;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,5000,20000,20000,40000,11,37121,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Recharge on Spawn'),
(@ENTRY,0,1,0,0,0,100,2,8000,15000,16000,21000,11,37123,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Saw Blade');

-- Crystalcore Sentinel
SET @ENTRY := 20041;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,9000,14000,25000,35000,11,37104,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Overcharge'),
(@ENTRY,0,1,0,0,0,100,2,21000,25000,25000,30000,11,37106,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Charged Arcane Explosion'),
(@ENTRY,0,2,0,2,0,100,3,0,15,0,0,11,34937,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Powered Down at 15% HP');

-- Devastation
SET @ENTRY := 21269;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,8,11000,15000,11,36981,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirlwind on Close');

-- Ember of Al'ar
SET @ENTRY := 19551; 
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY; 
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY; 
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,6,0,100,3,0,0,0,0,11,34133,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Ember Blast on Death');

-- Infinity Blades
SET @ENTRY := 21271;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,4500,12000,12000,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thrash');

-- Nether Scryer
SET @ENTRY := 20045;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,12000,16000,11,37126,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Blast on Close'),
(@ENTRY,0,1,0,0,0,100,2,9000,12000,18000,22000,11,37135,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Domination');

-- Netherstrand Longbow
SET @ENTRY := 21268;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,36980,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,9,0,100,2,0,20,24000,30000,11,36994,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blink on Close'),
(@ENTRY,0,2,0,0,0,100,2,7000,11000,12000,16000,11,36979,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Multi-Shot');

-- Novice Astromancer
SET @ENTRY := 20044;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,37111,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball'),
(@ENTRY,0,1,0,1,0,100,2,500,1000,600000,600000,11,37282,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fire Shield on Spawn'),
(@ENTRY,0,2,0,9,0,100,2,0,20,12000,16000,11,38728,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fire Nova on Close'),
(@ENTRY,0,3,0,0,0,100,2,15000,19000,18000,22000,11,37279,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Rain of Fire');

-- Phaseshift Bulwark
SET @ENTRY := 21273;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,13000,17000,11,36988,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Bash on Close');

-- Phoenix-Hawk
SET @ENTRY := 20039;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,14000,20000,21000,25000,11,37156,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Dive'),
(@ENTRY,0,1,0,0,0,100,2,3000,6000,11000,14000,11,37159,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Mana Burn');

-- Phoenix-Hawk Hatchling
SET @ENTRY := 20038;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,9000,15000,21000,26000,11,37160,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Silence'),
(@ENTRY,0,1,0,0,0,100,2,5000,7500,12000,15000,11,37319,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Wing Buffet');

-- Staff of Disintegration
SET @ENTRY := 21274;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,36990,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frostbolt'),
(@ENTRY,0,1,0,9,0,100,2,0,8,13600,14500,11,36989,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Nova on Close');

-- Star Scryer
SET @ENTRY := 20034;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,16000,20000,11,37126,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Blast on Close'),
(@ENTRY,0,1,0,0,0,100,2,15000,21000,30000,45000,11,37124,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Starfall'),
(@ENTRY,0,2,0,0,0,100,2,9000,13000,15000,22000,11,37122,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Domination');

-- Tempest Falconer
SET @ENTRY := 20037;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,39079,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,1,0,100,2,500,1000,600000,600000,11,37318,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fire Shield on Spawn'),
(@ENTRY,0,2,0,9,0,100,2,0,5,6000,11000,11,37317,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Knockback on Close'),
(@ENTRY,0,3,0,0,0,100,2,14000,16000,20000,26000,11,37154,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Immolation Arrow');

-- Tempest-Smith
SET @ENTRY := 20042;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,37120,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fragmentation Bomb'),
(@ENTRY,0,1,0,1,0,100,2,5000,20000,20000,40000,11,34946,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Golem Repair on Spawn'),
(@ENTRY,0,2,0,9,0,100,2,0,30,9000,14500,11,37118,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shell Shock on Close'),
(@ENTRY,0,3,0,0,0,100,2,18000,25000,45000,65000,11,37112,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Power Up');

-- Warp Slicer
SET @ENTRY := 21272;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,14000,11,36991,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rend');
