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
 
  /* Raid Normal-Heroic for 10 & 25 people */
 /* Trash Mobs */
 
 -- Azureborne Destroyer
 SET @ENTRY := 47087;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,11,0,40,0,0,11,88204,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Infused Fists at 40% HP'),
(@ENTRY,0,1,0,0,0,100,10,5000,5000,14900,17800,11,88178,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Stasis Strike'),
(@ENTRY,0,2,0,2,0,100,21,0,40,0,0,11,93343,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Infused Fists at 40% HP'),
(@ENTRY,0,3,0,0,0,100,20,5000,5000,14900,17800,11,93344,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Stasis Strike');

-- Bound Inferno
SET @ENTRY := 49817;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,31,0,0,0,0,11,93336,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Ward of Combustion on Aggro'),
(@ENTRY,0,1,0,0,0,100,20,8000,8000,16900,19800,11,93383,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Flamestrike'),
(@ENTRY,0,2,0,0,0,100,10,8000,8000,16900,19800,11,93362,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Flamestrike');

-- Bound Rumbler
SET @ENTRY := 49826;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,10,11300,12600,38900,41200,11,93327,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Entomb'),
(@ENTRY,0,1,0,0,0,100,10,5500,5500,15600,17900,11,93325,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shockwave');

-- Bound Zephyr
SET @ENTRY := 49821;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,10,3500,4100,11300,13800,11,93278,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lightning Shock'),
(@ENTRY,0,1,0,0,0,100,10,10500,10500,41200,43500,11,93277,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Rending Gale'),
(@ENTRY,0,2,0,0,0,100,10,8900,8900,15600,16800,11,93306,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Vaporize'),
(@ENTRY,0,3,0,0,0,100,20,3500,4100,11300,13800,11,93387,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lightning Shock'),
(@ENTRY,0,4,0,0,0,100,20,10500,10500,41200,43500,11,93388,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Rending Gale'),
(@ENTRY,0,5,0,0,0,100,20,8900,8900,15600,16800,11,93389,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Vaporize');

-- Bound Deluge
SET @ENTRY := 49825;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,8100,8200,19900,21200,11,93340,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Whirl'),
(@ENTRY,0,1,0,0,0,100,30,1000,1000,54200,55600,11,93335,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Icy Shroud');

-- Calen
SET @ENTRY := 46277;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,12000,12000,29800,35600,11,87946,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Essence of the Red'),
(@ENTRY,0,1,0,0,0,100,30,22500,22500,55400,55400,11,87221,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fiery Resolve'),
(@ENTRY,0,2,0,4,0,100,31,0,0,0,0,11,92941,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Pyrrhic Focus on Aggro');

-- Nether Scion
SET @ENTRY := 44645;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,5000,5000,28900,29500,11,83611,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Nether Blindness');

-- Orphaned Emerald Whelp
SET @ENTRY := 44641;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,5000,5000,12000,13600,11,83609,0,0,0,0,0,2,32,0,0,0,0,0,0,'Cast Atrophic Poison');

-- Pulsing Twilight Egg
SET @ENTRY := 46842;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,31,0,0,0,0,11,87654,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Twilight Carapace on Aggro');

-- Slate Dragon
SET @ENTRY := 44652;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,5000,5000,25900,27800,11,83603,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Stone Touch'),
(@ENTRY,0,1,0,0,0,100,24,9000,9000,15000,39000,11,84593,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Stone Grip');

-- Twilight Shadow Knight
SET @ENTRY := 45261;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,5000,5000,11000,13000,11,78660,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Devastate'),
(@ENTRY,0,1,0,0,0,100,30,9000,9000,22000,22000,11,84832,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Dismantle'),
(@ENTRY,0,2,0,2,0,100,31,0,20,0,0,11,84827,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shield Mastery at 20% HP');

-- Twilight Shadow Mender <The Twilight's Hammer>
SET @ENTRY := 45699;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,30,0,10,15800,16900,11,85643,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Mind Sear on Close'),
(@ENTRY,0,1,0,14,0,100,30,4000,10,20000,30000,11,85575,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Shadow Mending on Friendlies'),
(@ENTRY,0,2,0,9,0,100,30,0,6,12000,13000,11,85664,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Umbral Flames on Close');

-- Twilight Soul Blade
SET @ENTRY := 45265;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,31,0,0,0,0,11,84567,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blade Barrier on Aggro'),
(@ENTRY,0,1,0,0,0,100,30,8000,8000,42000,48000,11,84853,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dark Pool'),
(@ENTRY,0,2,0,0,0,100,30,3500,5500,14600,17800,11,84849,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Soul Blade');

-- Twilight Spitecaller
SET @ENTRY := 48415;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,31,0,70,0,0,11,92947,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Unleash Essence at 70% HP');

-- Twilight Whelp
SET @ENTRY := 48049;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,5000,5500,11200,13600,11,92953,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Twilight Spit');

-- Twilight Whelp
SET @ENTRY := 48050;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,5000,5500,11200,13600,11,92953,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Twilight Spit');

-- Twilight Whelp
SET @ENTRY := 48048;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,5000,5500,11200,13600,11,92953,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Twilight Spit');

-- Twilight Whelp
SET @ENTRY := 48047;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,5000,5500,11200,13600,11,92953,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Twilight Spit');

-- Twilight Whelp
SET @ENTRY := 47265;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,5000,5500,11200,13600,11,92953,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Twilight Spit');

-- Twilight Elementalist
SET @ENTRY := 47152;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,10,0,0,3400,4700,11,88079,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,2,2,0,100,31,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,31,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,0,0,100,20,0,0,3400,4700,11,93360,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,4,0,2,0,100,11,0,40,0,0,11,88065,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Empower Elemental at 40% HP'),
(@ENTRY,0,5,0,2,0,100,21,0,40,0,0,11,93359,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Empower Elemental at 40% HP');
-- NPC talk text insert
SET @ENTRY := 47152;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Twilight Phase-Twister
SET @ENTRY := 45267;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,5000,6000,14500,15600,11,84838,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Twist Phase');

-- Twilight Drake
SET @ENTRY := 48436;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,9000,9000,19800,24600,11,92942,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Twilight Breath');

-- Twilight Dark Mender
SET @ENTRY := 45266;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,8000,8000,17800,19200,11,84856,0,0,0,0,0,1,1,0,0,0,0,0,0,'Cast Hungering Shadows'),
(@ENTRY,0,1,0,0,0,100,30,12000,17000,35000,48000,11,84855,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dark Mending'),
(@ENTRY,0,2,0,14,0,100,30,400000,10,25000,35000,11,84855,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Dark Mending on Friendlies');

-- Chosen Warrior
SET @ENTRY := 46591;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,10,5000,5100,14900,16800,11,87704,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hamstring'),
(@ENTRY,0,1,0,0,0,100,20,5000,5100,14900,16800,11,95769,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hamstring');

-- Earth Ravager
SET @ENTRY := 47150;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,8000,8000,24000,28000,11,87920,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Tremors'),
(@ENTRY,0,1,0,0,0,100,10,12000,12000,20000,20000,11,87917,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Petrify Skin'),
(@ENTRY,0,2,0,0,0,100,20,12000,12000,20000,20000,11,93350,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Petrify Skin');

-- Elemental Firelord
SET @ENTRY := 47081;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,5500,5800,19500,21200,11,87903,0,0,0,0,0,2,1,0,0,0,0,0,0,'Cast Volcanic Wrath'),
(@ENTRY,0,1,0,0,0,100,10,3500,8700,7900,18900,11,87898,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Molten Burst'),
(@ENTRY,0,2,0,0,0,100,20,3500,8700,7900,18900,11,93353,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Molten Burst');

-- Evolved Drakonaar
SET @ENTRY := 49813;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,7000,7000,14600,17800,11,93373,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blade Tempest'),
(@ENTRY,0,1,0,0,0,100,30,3500,4100,11200,13500,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,2,0,0,0,100,30,5800,8900,16800,21200,11,93377,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Twilight Rupture');

-- Faceless Guardian
SET @ENTRY := 45676;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,5000,5000,35000,35000,11,85482,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Volley'),
(@ENTRY,0,1,0,0,0,100,30,9000,9000,19000,19000,11,85412,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Pooled Blood');

-- Fire Elemental
SET @ENTRY := 43406;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,31,0,0,0,0,11,93245,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fire Power on Aggro');

-- Storm Rider
SET @ENTRY := 44650;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,9000,11000,22000,26000,11,83612,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cyclone Winds');

-- Time Warden
SET @ENTRY := 44797;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,5000,5000,29800,32500,11,83601,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Time Dilation');

-- Twilight-Shifter <The Twilight's Hammer>
SET @ENTRY := 45687;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,31,0,50,0,0,11,85556,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Twilight Shift at 50% HP');

-- Twilight Crossfire
SET @ENTRY := 45264;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,0,0,2300,3900,11,84837,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,2,2,0,100,31,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,31,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,0,0,100,30,8000,8000,18900,19900,11,84836,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Multi-Shot'),
(@ENTRY,0,4,0,2,0,100,31,0,50,0,0,11,36828,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rapid Fire at 50% HP'),
(@ENTRY,0,5,0,0,0,100,30,5000,5000,22000,23000,11,90488,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Wyvern Sting');
-- NPC talk text insert
SET @ENTRY := 45264;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Twilight Brute
SET @ENTRY := 47161;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,5000,5000,11000,13000,11,88133,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirling Blades');

-- Twilight Portal Shaper <The Twilight's Hammer>
SET @ENTRY := 45700;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,0,0,3400,4700,11,85544,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,30,10000,10000,38000,42000,11,85529,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shape Portal');
-- NPC talk text insert
SET @ENTRY := 45700;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Crimsonborne Firestarter
SET @ENTRY := 47086;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,8000,8000,15000,15000,11,88219,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Burning Twilight'),
(@ENTRY,0,1,0,0,0,100,30,5000,5000,36000,37000,11,88226,0,0,0,0,0,6,0,0,0,0,0,0,0,'Cast Crimson Flames');

-- Darkened Creation
SET @ENTRY := 44045;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5500,6200,18900,21200,11,82411,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Debilitating Beam'),
(@ENTRY,0,1,0,0,0,100,8,5500,6200,18900,21200,11,93133,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Debilitating Beam'),
(@ENTRY,0,2,0,0,0,100,4,5500,6200,18900,21200,11,93132,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Debilitating Beam'),
(@ENTRY,0,3,0,0,0,100,16,5500,6200,18900,21200,11,93134,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Debilitating Beam');

-- Wind Breaker
SET @ENTRY := 47151;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,4000,6000,13800,16500,11,87875,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Violent Gale Storm'),
(@ENTRY,0,1,0,0,0,100,10,7800,9500,14300,19500,11,87870,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gale Wind'),
(@ENTRY,0,2,0,0,0,100,20,7800,9500,14300,19500,11,93355,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gale Wind');

-- Chosen Seer
SET @ENTRY := 46952;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,10,0,0,3400,4700,11,87710,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,2,2,0,100,31,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,31,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,0,0,100,20,0,0,3400,4700,11,95768,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,4,0,0,0,100,10,7200,7500,11300,14800,11,87707,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Shock'),
(@ENTRY,0,5,0,0,0,100,20,7200,7500,11300,14800,11,95767,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Shock');
-- NPC talk text insert
SET @ENTRY := 46952;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Corrupting Adherent
SET @ENTRY := 43622;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,31,0,0,0,0,11,81757,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spilled Blood of the Old God on Death'),
(@ENTRY,0,1,0,0,0,100,2,5500,6500,20200,21200,11,81685,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Corrupting Crash'),
(@ENTRY,0,2,0,9,0,100,2,0,10,15800,17600,11,81713,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Depravity on Close'),
(@ENTRY,0,3,0,0,0,100,8,5500,6500,20200,21200,11,93179,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Corrupting Crash'),
(@ENTRY,0,4,0,9,0,100,8,0,10,15800,17600,11,93176,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Depravity on Close'),
(@ENTRY,0,5,0,0,0,100,4,5500,6500,20200,21200,11,93178,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Corrupting Crash'),
(@ENTRY,0,6,0,9,0,100,4,0,10,15800,17600,11,93175,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Depravity on Close'),
(@ENTRY,0,7,0,0,0,100,16,5500,6500,20200,21200,11,93180,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Corrupting Crash'),
(@ENTRY,0,8,0,9,0,100,16,0,10,15800,17600,11,93177,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Depravity on Close'); 
 