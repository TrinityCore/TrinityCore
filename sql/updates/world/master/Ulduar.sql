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
 
  /* Raid Normal for 10 & 25 people */
 /* Trash Mobs */
 
-- Ancient Rune Giant
SET @ENTRY := 32873;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,8000,9000,18000,25000,11,62526,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Rune Detonation'),
(@ENTRY,0,1,0,4,0,100,7,0,0,0,0,11,62942,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Runic Fortification on Aggro'),
(@ENTRY,0,2,0,0,0,100,2,4000,4500,15000,17000,11,62411,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Stomp'),
(@ENTRY,0,3,0,0,0,100,4,4000,4500,15000,17000,11,62413,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Stomp');

-- Arachnopod Destroyer
SET @ENTRY := 34183;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,64779,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charged Leap on Aggro'),
(@ENTRY,0,1,0,0,0,100,6,7000,9000,17500,22500,11,64717,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Flame Spray'),
(@ENTRY,0,2,0,0,0,100,6,5000,5000,14000,16000,11,64776,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Machine Gun');

-- Captured Mercenary Captain
SET @ENTRY := 32908;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,12000,13500,11,62317,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Devastate'),
(@ENTRY,0,1,0,0,0,100,6,6000,8000,10000,17000,11,62444,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Strike'),
(@ENTRY,0,2,0,0,0,100,6,3000,7000,11000,18000,11,57807,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sunder Armor');

-- Captured Mercenary Captain
SET @ENTRY := 32907;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,12000,13500,11,62317,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Devastate'),
(@ENTRY,0,1,0,0,0,100,6,6000,8000,10000,17000,11,62444,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Strike'),
(@ENTRY,0,2,0,0,0,100,6,3000,7000,11000,18000,11,57807,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sunder Armor');

-- Captured Mercenary Soldier
SET @ENTRY := 32885;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,6000,6000,17000,20000,11,62318,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Barbed Shot'),
(@ENTRY,0,1,0,9,0,100,6,0,5,9000,10000,11,40652,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wing Clip on Close'),
(@ENTRY,0,2,0,0,0,100,6,0,0,2300,3900,11,16496,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot');

-- Captured Mercenary Soldier
SET @ENTRY := 32883;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,6000,6000,17000,20000,11,62318,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Barbed Shot'),
(@ENTRY,0,1,0,9,0,100,6,0,5,9000,10000,11,40652,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wing Clip on Close'),
(@ENTRY,0,2,0,0,0,100,6,0,0,2300,3900,11,16496,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot');

-- Chamber Overseer
SET @ENTRY := 34197;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,6000,8000,15000,18000,11,64825,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Staggering Roar'),
(@ENTRY,0,1,0,0,0,100,4,6000,8000,15000,18000,11,64944,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Staggering Roar'),
(@ENTRY,0,2,0,9,0,100,2,10,80,22000,25000,11,64820,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Devastating Leap on Close'),
(@ENTRY,0,3,0,9,0,100,4,10,80,22000,25000,11,64943,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Devastating Leap on Close');

-- Champion of Hodir
SET @ENTRY := 34133;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,8000,9000,18000,22000,11,64649,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Freezing Breath'),
(@ENTRY,0,1,0,0,0,100,2,5000,6000,27000,32000,11,64639,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stomp'),
(@ENTRY,0,2,0,0,0,100,4,5000,6000,27000,32000,11,64652,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stomp');

-- Clockwork Mechanic
SET @ENTRY := 34184;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,30000,35000,11,64966,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Ice Turret');

-- Clockwork Sapper
SET @ENTRY := 34193;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,12000,13000,11,64740,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Energy Sap');

-- Corrupted Servitor
SET @ENTRY := 33354;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,4500,17000,20000,11,63169,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Petrify Joints'),
(@ENTRY,0,1,0,0,0,100,4,2000,4500,17000,20000,11,63549,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Petrify Joints'),
(@ENTRY,0,2,0,0,0,100,6,6000,9000,25000,27000,11,63149,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Violent Earth');

-- Dark Rune Acolyte
SET @ENTRY := 32886;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,8000,8000,33000,38000,11,61964,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Circle of Healing'),
(@ENTRY,0,1,0,2,0,100,6,0,40,14000,21000,11,62334,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Greater Heal at 40% HP'),
(@ENTRY,0,2,0,0,0,100,6,0,0,3400,4700,11,62335,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Holy Smite'),
(@ENTRY,0,3,0,14,0,100,6,100000,40,15000,18000,11,61967,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Renew on Friendlies');

-- Dark Rune Acolyte
SET @ENTRY := 32957;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,8000,8000,33000,38000,11,61964,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Circle of Healing'),
(@ENTRY,0,1,0,2,0,100,6,0,40,14000,21000,11,62334,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Greater Heal at 40% HP'),
(@ENTRY,0,2,0,0,0,100,6,0,0,3400,4700,11,62335,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Holy Smite'),
(@ENTRY,0,3,0,14,0,100,6,100000,40,15000,18000,11,61967,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Renew on Friendlies');

-- Dark Rune Acolyte
SET @ENTRY := 33110;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,8000,8000,33000,38000,11,61964,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Circle of Healing'),
(@ENTRY,0,1,0,2,0,100,6,0,40,14000,21000,11,62334,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Greater Heal at 40% HP'),
(@ENTRY,0,2,0,0,0,100,6,0,0,3400,4700,11,62335,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Holy Smite'),
(@ENTRY,0,3,0,14,0,100,6,100000,40,15000,18000,11,61967,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Renew on Friendlies');

-- Dark Rune Champion
SET @ENTRY := 32876;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,32323,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,1,0,0,0,100,6,5000,5000,14000,16000,11,35054,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike'),
(@ENTRY,0,2,0,0,0,100,6,8000,9000,22000,26000,11,33500,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirlwind');

-- Dark Rune Commoner
SET @ENTRY := 32904;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,12000,20000,11,62326,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Low Blow'),
(@ENTRY,0,1,0,0,0,100,6,6000,7500,10000,15500,11,38313,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pummel');

-- Dark Rune Evoker
SET @ENTRY := 32878;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,4500,12000,14000,11,62327,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Runic Lightning'),
(@ENTRY,0,1,0,0,0,100,4,2000,4500,12000,14000,11,62445,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Runic Lightning'),
(@ENTRY,0,2,0,2,0,100,3,0,55,0,0,11,62321,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Runic Shield at 55% HP'),
(@ENTRY,0,3,0,2,0,100,5,0,55,0,0,11,62529,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Runic Shield at 55% HP'),
(@ENTRY,0,4,0,2,0,100,2,0,40,16000,21000,11,62328,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Runic Mending at 40% HP'),
(@ENTRY,0,5,0,2,0,100,4,0,40,16000,21000,11,62446,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Runic Mending at 40% HP');

-- Dark Rune Ravager
SET @ENTRY := 33755;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,12000,15000,11,63615,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ravage Armor');

-- Dark Rune Thunderer
SET @ENTRY := 33754;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3500,4500,12000,13500,11,63612,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Lightning Brand'),
(@ENTRY,0,1,0,0,0,100,4,3500,4500,12000,13500,11,63673,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Lightning Brand');

-- Dark Rune Warbringer
SET @ENTRY := 32877;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,7,0,0,0,0,11,62320,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Aura of Celerity on Spawn'),
(@ENTRY,0,1,0,0,0,100,6,2000,4500,9000,12000,11,62322,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Runic Strike');

-- Enslaved Fire Elemental
SET @ENTRY := 33838;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,10,13600,14500,11,38064,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blast Wave on Close');

-- Faceless Horror
SET @ENTRY := 33772;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,64429,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Death Grip on Aggro'),
(@ENTRY,0,1,0,0,0,100,6,10000,12000,26000,32000,11,63713,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Dominate Mind'),
(@ENTRY,0,2,0,0,0,100,6,5000,5000,12000,15000,11,63722,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Shadow Crash'),
(@ENTRY,0,3,0,2,0,100,7,0,30,0,0,11,63710,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Void Barrier at 30% HP'),
(@ENTRY,0,4,0,0,0,100,6,9000,9000,18000,20000,11,63703,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Void Wave');

-- Forest Swarmer
SET @ENTRY := 33431;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,6,0,55,30000,33000,11,63059,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Pollinate at 55% HP');

-- Forge Construct
SET @ENTRY := 34085;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,64719,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,1,0,0,0,100,2,4000,4500,11000,14000,11,64720,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Emission'),
(@ENTRY,0,2,0,0,0,100,4,4000,4500,11000,14000,11,64721,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Emission');

-- Guardian Lasher
SET @ENTRY := 34085;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,63007,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Guardian Pheromones on Aggro'),
(@ENTRY,0,1,0,0,0,100,2,4000,5000,12000,15000,11,63047,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Guardian\'s Lash'),
(@ENTRY,0,2,0,0,0,100,4,4000,5000,12000,15000,11,63550,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Guardian\'s Lash');

-- Guardian of Life
SET @ENTRY := 33528;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,7000,18000,24000,11,63226,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Poison Breath'),
(@ENTRY,0,1,0,0,0,100,4,5000,7000,18000,24000,11,63551,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Poison Breath');

-- Hardened Iron Golem
SET @ENTRY := 34190;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,3500,11500,14800,11,64874,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rune Punch'),
(@ENTRY,0,1,0,0,0,100,4,2000,3500,11500,14800,11,64967,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rune Punch'),
(@ENTRY,0,2,0,2,0,100,6,0,60,18000,21000,11,64877,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Harden Fists at 60% HP');

-- Ice Turret
SET @ENTRY := 34224;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,8,13600,14500,11,66346,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Ice Nova on Close'),
(@ENTRY,0,1,0,9,0,100,4,0,8,13600,14500,11,64919,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Ice Nova on Close');

-- Iron Honor Guard
SET @ENTRY := 32875;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,8000,9000,11,42724,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave on Close'),
(@ENTRY,0,1,0,0,0,100,6,6000,8000,15000,16000,11,48639,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hamstring'),
(@ENTRY,0,2,0,13,0,100,2,9000,11000,0,0,11,62332,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Shield Smash on Player Spell Cast'),
(@ENTRY,0,3,0,13,0,100,4,9000,11000,0,0,11,62420,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Shield Smash on Player Spell Cast');

-- Iron Honor Guard
SET @ENTRY := 33125;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,8000,9000,11,42724,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave on Close'),
(@ENTRY,0,1,0,0,0,100,6,6000,8000,15000,16000,11,48639,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hamstring'),
(@ENTRY,0,2,0,13,0,100,2,9000,11000,0,0,11,62332,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Shield Smash on Player Spell Cast'),
(@ENTRY,0,3,0,13,0,100,4,9000,11000,0,0,11,62420,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Shield Smash on Player Spell Cast');

-- Iron Mender
SET @ENTRY := 34198;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,4500,12000,14000,11,64918,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Electro Shock'),
(@ENTRY,0,1,0,0,0,100,4,2000,4500,12000,14000,11,64971,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Electro Shock'),
(@ENTRY,0,2,0,2,0,100,2,0,40,14000,21000,11,64897,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fuse Metal at 40% HP'),
(@ENTRY,0,3,0,2,0,100,4,0,40,14000,21000,11,64968,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fuse Metal at 40% HP');

-- Iron Ring Guard
SET @ENTRY := 32874;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,12,0,100,2,0,20,9000,13000,11,62331,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Impale when Target is 20% HP'),
(@ENTRY,0,1,0,12,0,100,4,0,20,9000,13000,11,62418,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Impale when Target is 20% HP'),
(@ENTRY,0,2,0,0,0,100,6,2000,4500,12000,13000,11,64151,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Whirling Trip');

-- Ironroot Lasher
SET @ENTRY := 33526;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,2000,11000,11500,11,63240,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Ironroot Thorns'),
(@ENTRY,0,1,0,0,0,100,4,1000,2000,11000,11500,11,63553,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Ironroot Thorns');

-- Jormungar Behemoth
SET @ENTRY := 32882;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,6500,15000,16000,11,62315,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Acid Breath'),
(@ENTRY,0,1,0,0,0,100,4,5000,6500,15000,16000,11,62415,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Acid Breath'),
(@ENTRY,0,2,0,0,0,100,2,4000,9000,12000,23000,11,62316,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sweep'),
(@ENTRY,0,3,0,0,0,100,4,4000,9000,12000,23000,11,62417,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sweep');

-- Lightning Charged Iron Dwarf
SET @ENTRY := 34199;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,1500,60000,61000,11,64889,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lightning Charged'),
(@ENTRY,0,1,0,0,0,100,4,1000,1500,20000,25000,11,64975,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lightning Charged');

-- Liquid Pyrite
SET @ENTRY := 33189;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,6,67390,0,0,0,28,62494,0,0,0,0,0,1,0,0,0,0,0,0,0,'On hit by spell Ride Vehicle - Remove auras from Liquid Pyrite'),
(@ENTRY,0,1,0,61,0,100,6,0,0,0,0,41,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,'On hit by spell Ride Vehicle - Despawn');

-- Magma Rager
SET @ENTRY := 34086;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3000,3500,12000,13000,11,64773,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fire Blast'),
(@ENTRY,0,1,0,0,0,100,6,6000,9000,18000,22000,11,64746,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Superheated Winds');

-- Mangrove Ent
SET @ENTRY := 33525;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,9000,9000,25000,27000,11,63272,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Hurricane'),
(@ENTRY,0,1,0,14,0,100,2,200000,40,15000,18000,11,63242,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Nourish on Friendlies'),
(@ENTRY,0,2,0,14,0,100,4,200000,40,15000,18000,11,63556,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Nourish on Friendlies'),
(@ENTRY,0,3,0,2,0,100,2,0,40,18000,21000,11,63241,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Tranquility at 40% HP'),
(@ENTRY,0,4,0,2,0,100,4,0,40,18000,21000,11,63554,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Tranquility at 40% HP');

-- Mechagnome Battletank
SET @ENTRY := 34164;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,64953,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Jump Attack on Aggro'),
(@ENTRY,0,1,0,0,0,100,6,4000,4500,12000,15000,11,64692,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Flame Cannon');

-- Mechanostriker 54-A
SET @ENTRY := 34161;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,6000,15000,18000,11,64766,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Laser Barrage');

-- Misguided Nymph
SET @ENTRY := 33355;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3500,4500,12000,14000,11,63111,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frost Spear'),
(@ENTRY,0,1,0,0,0,100,4,3500,4500,12000,14000,11,63562,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frost Spear'),
(@ENTRY,0,2,0,14,0,100,2,300000,45,15000,18000,11,63082,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Bind Life on Friendlies'),
(@ENTRY,0,3,0,14,0,100,4,300000,45,15000,18000,11,63559,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Bind Life on Friendlies'),
(@ENTRY,0,4,0,2,0,100,3,0,30,0,0,11,63136,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Winter\'s Embrace at 30% HP'),
(@ENTRY,0,5,0,2,0,100,5,0,30,0,0,11,63564,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Winter\'s Embrace at 30% HP');

-- Molten Colossus
SET @ENTRY := 34069;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,9000,11000,27000,32000,11,64697,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Earthquake'),
(@ENTRY,0,1,0,0,0,100,6,5000,6000,15000,25000,11,64699,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Magma Splash'),
(@ENTRY,0,2,0,0,0,100,6,3000,3500,12000,17000,11,64698,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pyroblast');

-- Nature's Blade
SET @ENTRY := 33527;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,4500,12000,15000,11,63247,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Living Tsunami'),
(@ENTRY,0,1,0,0,0,100,4,4000,4500,12000,15000,11,63568,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Living Tsunami');

-- Parts Recovery Technician
SET @ENTRY := 34267;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4000,4500,12000,12500,11,65071,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mechano Kick'),
(@ENTRY,0,1,0,2,0,100,6,0,60,14000,21000,11,65070,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Defense Matrix at 60% HP');

-- Proximity Mine
SET @ENTRY := 34362;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,0,0,100,7,1000,1000,0,0,11,63009,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Explosion'),
(@ENTRY,0,1,0,61,0,100,7,0,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Despawn After Explosion');

-- Rubble
SET @ENTRY := 33768;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,8000,15000,20000,11,63818,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rumble'),
(@ENTRY,0,1,0,0,0,100,4,5000,8000,15000,20000,11,63978,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Stone Nova');

-- Rune Etched Sentry
SET @ENTRY := 34196;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,8000,8000,18000,22000,11,64852,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flaming Rune'),
(@ENTRY,0,1,0,0,0,100,2,3000,3500,11000,12000,11,64870,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lava Burst'),
(@ENTRY,0,2,0,0,0,100,4,3000,3500,11000,12000,11,64991,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lava Burst'),
(@ENTRY,0,3,0,0,0,100,2,5500,6500,15500,15500,11,64847,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Runed Flame Jets'),
(@ENTRY,0,4,0,0,0,100,4,5500,6500,15500,15500,11,64988,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Runed Flame Jets');

-- Runeforged Sentry
SET @ENTRY := 34234;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,8000,8000,18000,22000,11,64852,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flaming Rune'),
(@ENTRY,0,1,0,0,0,100,2,3000,3500,11000,12000,11,64870,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lava Burst'),
(@ENTRY,0,2,0,0,0,100,4,3000,3500,11000,12000,11,64991,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lava Burst'),
(@ENTRY,0,3,0,0,0,100,2,5500,6500,15500,15500,11,64847,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Runed Flame Jets'),
(@ENTRY,0,4,0,0,0,100,4,5500,6500,15500,15500,11,64988,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Runed Flame Jets');

-- Runic Colossus
SET @ENTRY := 32872;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,62613,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,1,0,4,0,100,5,0,0,0,0,11,62614,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,2,0,0,0,100,6,4000,4500,11000,15000,11,62339,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Smash'),
(@ENTRY,0,3,0,2,0,100,6,0,40,20000,21000,11,62338,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Runic Barrier at 40% HP');

-- Salvagebot Sawblade
SET @ENTRY := 34288;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,4500,12000,13000,11,65089,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sawblades'),
(@ENTRY,0,1,0,0,0,100,4,2000,4500,12000,13000,11,65102,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sawblades');

-- Steelforged Defender
SET @ENTRY := 33572;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4000,4500,14000,16000,11,50370,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sunder Armor'),
(@ENTRY,0,1,0,9,0,100,6,0,5,9000,13000,11,62845,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hamstring on Close');

-- Steelforged Defender
SET @ENTRY := 33236;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4000,4500,14000,16000,11,50370,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sunder Armor'),
(@ENTRY,0,1,0,9,0,100,6,0,5,9000,13000,11,62845,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hamstring on Close'),
(@ENTRY,0,2,0,0,0,100,6,0,0,3400,4700,11,57780,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lightning Bolt');

-- Storm Tempered Keeper
SET @ENTRY := 33722;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,7000,15000,18000,11,63541,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Forked Lightning'),
(@ENTRY,0,1,0,0,0,100,6,8000,8000,25000,26000,11,63527,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Charged Sphere'),
(@ENTRY,0,2,0,0,0,100,7,15000,15000,0,0,11,63630,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Vengeful Surge');
-- Charged Sphere
SET @ENTRY := 33715;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,22000,25000,11,63528,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Supercharged');

-- Storm Tempered Keeper
SET @ENTRY := 33699;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,7000,15000,18000,11,63541,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Forked Lightning'),
(@ENTRY,0,1,0,0,0,100,6,8000,8000,25000,26000,11,63527,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Charged Sphere'),
(@ENTRY,0,2,0,0,0,100,7,15000,15000,0,0,11,63630,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Vengeful Surge');

-- Twilight Adherent
SET @ENTRY := 33818;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,7000,25000,26000,11,64663,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Burst'),
(@ENTRY,0,1,0,0,0,100,6,9000,9000,30000,33000,11,64662,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Blink'),
(@ENTRY,0,2,0,14,0,100,6,200000,40,15000,18000,11,63760,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Greater Heal on Friendlies'),
(@ENTRY,0,3,0,0,0,100,6,7000,7000,27000,36000,11,13704,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Psychic Scream'),
(@ENTRY,0,4,0,2,0,100,6,0,40,18000,21000,11,37978,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Renew at 40% HP');

-- Twilight Frost Mage
SET @ENTRY := 33819;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,7000,25000,26000,11,64663,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Burst'),
(@ENTRY,0,1,0,0,0,100,6,9000,9000,30000,33000,11,64662,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Blink'),
(@ENTRY,0,2,0,9,0,100,6,0,8,13600,14500,11,63912,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Nova on Close'),
(@ENTRY,0,3,0,0,0,100,6,0,0,3400,4700,11,63913,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frostbolt'),
(@ENTRY,0,4,0,0,0,100,6,5000,9000,15000,18000,11,63758,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frostbolt Volley');

-- Twilight Guardian
SET @ENTRY := 33822;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,12000,13500,11,62317,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Devastate'),
(@ENTRY,0,1,0,0,0,100,6,6000,8000,10000,17000,11,52719,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Concussion Blow'),
(@ENTRY,0,2,0,0,0,100,6,3000,7000,11000,18000,11,57807,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sunder Armor'),
(@ENTRY,0,3,0,9,0,100,6,0,5,18000,20000,11,63757,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Thunderclap on Close');

-- Twilight Pyromancer
SET @ENTRY := 33820;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,7000,25000,26000,11,64663,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Burst'),
(@ENTRY,0,1,0,0,0,100,6,9000,9000,30000,33000,11,64662,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Blink'),
(@ENTRY,0,2,0,0,0,100,6,0,0,3400,4700,11,63789,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball'),
(@ENTRY,0,3,0,0,0,100,6,5000,9000,17000,18000,11,63775,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Flamestrike'),
(@ENTRY,0,4,0,1,0,100,7,3000,5000,0,0,11,63774,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Fire Elemental on Spawn');

-- Twilight Shadowblade
SET @ENTRY := 33824;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,67,0,100,6,9000,12000,0,0,11,63754,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Backstab'),
(@ENTRY,0,1,0,0,0,100,6,2000,4500,12000,14000,11,63755,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Deadly Poison'),
(@ENTRY,0,2,0,9,0,100,6,0,10,20000,20000,11,63753,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fan of Knives on Close');

-- Twilight Slayer
SET @ENTRY := 33823;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,15000,16000,11,63784,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bladestorm on Close'),
(@ENTRY,0,1,0,0,0,100,6,4000,4500,12000,12000,11,35054,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike');

-- Void Beast
SET @ENTRY := 33806;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,8,13600,14500,11,63723,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Nova on Close');

-- Winter Jormungar
SET @ENTRY := 34137;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,17000,22000,11,64638,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Acidic Bite');

-- Winter Revenant
SET @ENTRY := 34134;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,7000,8000,18000,25000,11,64642,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Blizzard'),
(@ENTRY,0,1,0,0,0,100,4,7000,8000,18000,25000,11,64653,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Blizzard'),
(@ENTRY,0,2,0,11,0,100,7,0,0,0,0,11,64644,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shield of the Winter Revenant on Spawn'),
(@ENTRY,0,3,0,0,0,100,6,5500,5500,15000,15000,11,64643,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirling Strike');

-- Winter Rumbler
SET @ENTRY := 34135;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,8000,12000,13000,11,64645,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cone of Cold'),
(@ENTRY,0,1,0,0,0,100,4,5000,8000,12000,13000,11,64655,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cone of Cold'),
(@ENTRY,0,2,0,0,0,100,2,4000,4000,17000,20000,11,64647,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Snow Blindness'),
(@ENTRY,0,3,0,0,0,100,4,4000,4000,17000,20000,11,64654,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Snow Blindness');

-- Writhing Lasher
SET @ENTRY := 33387;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,12000,13000,11,65062,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lash');

-- XB-488 Disposalbot
SET @ENTRY := 34273;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,3500,12000,13500,11,65080,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cut Scrap Metal'),
(@ENTRY,0,1,0,0,0,100,4,2000,3500,12000,13500,11,65104,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cut Scrap Metal'),
(@ENTRY,0,2,0,6,0,100,7,0,0,0,0,11,65084,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Self Destruct on Death');

-- XD-175 Compactobot
SET @ENTRY := 34271;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3500,4500,13500,16500,11,65078,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Compacted'),
(@ENTRY,0,1,0,0,0,100,4,3500,4500,13500,16500,11,65105,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Compacted');

-- XR-949 Salvagebot
SET @ENTRY := 34269;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,7000,45000,55000,11,65099,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Deploy Salvage Saws');
