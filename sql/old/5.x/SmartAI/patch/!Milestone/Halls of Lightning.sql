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
	
-- Blistering Steamrager
SET @ENTRY := 28583;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,8000,9000,12000,11,52531,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Steam Blast'),
(@ENTRY,0,1,0,0,0,100,4,5000,8000,9000,12000,11,59141,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Steam Blast');

-- Stormforged Construct
SET @ENTRY := 28835;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,2,0,65,11000,15000,11,53068,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rune Punch at 65% HP'),
(@ENTRY,0,1,0,2,0,100,4,0,65,11000,15000,11,59151,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rune Punch at 65% HP'),
(@ENTRY,0,2,0,0,0,100,2,4000,7000,1000,14000,11,53167,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Forked Lightning'),
(@ENTRY,0,3,0,0,0,100,4,4000,7000,1000,14000,11,59152,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Forked Lightning'),
(@ENTRY,0,4,0,9,0,100,2,0,5,12000,18000,11,61596,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Runic Focus on Close'),
(@ENTRY,0,5,0,9,0,100,4,0,5,12000,18000,11,61579,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Runic Focus on Close');

-- Stormforged Giant
SET @ENTRY := 28920;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,7000,8000,11000,11,53072,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Stormbolt'),
(@ENTRY,0,1,0,0,0,100,4,5000,7000,8000,11000,11,59155,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Stormbolt'),
(@ENTRY,0,2,0,0,0,100,2,13000,17000,9000,15000,11,53071,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thunderstorm'),
(@ENTRY,0,3,0,0,0,100,4,13000,17000,9000,15000,11,59154,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thunderstorm'),
(@ENTRY,0,4,0,2,0,100,7,0,50,0,0,11,32315,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Soul Strike at 50% HP');

-- Stormforged Mender
SET @ENTRY := 28582;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,7,0,80,0,0,11,52773,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hammer Blow at 80% HP'),
(@ENTRY,0,1,0,14,0,100,3,12000,40,0,0,11,52774,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Renew Steel on Friendlies'),
(@ENTRY,0,2,0,14,0,100,5,12000,40,0,0,11,59160,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Renew Steel on Friendlies');

-- Stormforged Runeshaper
SET @ENTRY := 28836;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,7000,10000,24000,30000,11,53049,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Charged Flurry'),
(@ENTRY,0,1,0,0,0,100,4,7000,10000,24000,30000,11,61581,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Charged Flurry'),
(@ENTRY,0,2,0,0,0,100,6,3000,5000,17000,21000,11,53048,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Startling Roar');

-- Stormforged Sentinel
SET @ENTRY := 28837;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,7,0,30,0,0,11,53047,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Storming Bellow at 30% HP'),
(@ENTRY,0,1,0,0,0,100,2,9000,17000,20000,25000,11,53045,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Sleep'),
(@ENTRY,0,2,0,0,0,100,4,9000,17000,20000,25000,11,59165,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Sleep'),
(@ENTRY,0,3,0,14,0,100,2,40000,40,9000,15000,11,34423,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Renew on Friendlies'),
(@ENTRY,0,4,0,14,0,100,4,40000,40,9000,15000,11,37978,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Renew on Friendlies');

-- Stormforged Tactician
SET @ENTRY := 28581;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,6,0,50,15000,27000,11,59085,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Arc Weld at 50% HP'),
(@ENTRY,0,1,0,0,0,100,2,5000,9000,11000,14000,11,52778,0,0,0,0,0,2,1,0,0,0,0,0,0,'Cast Welding Beam'),
(@ENTRY,0,2,0,0,0,100,4,5000,9000,11000,14000,11,59166,0,0,0,0,0,2,1,0,0,0,0,0,0,'Cast Welding Beam');

-- Titanium Vanguard
SET @ENTRY := 28838;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,8,12000,15000,11,58619,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Close'),
(@ENTRY,0,1,0,0,0,100,2,5000,5000,14000,21000,11,53059,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Poison Tipped Spear'),
(@ENTRY,0,2,0,0,0,100,4,5000,5000,14000,21000,11,59178,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Poison Tipped Spear');

-- Unbound Firestorm
SET @ENTRY := 28584;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,6000,8000,12000,11,53788,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lava Burst'),
(@ENTRY,0,1,0,0,0,100,4,0,6000,8000,12000,11,59182,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lava Burst'),
(@ENTRY,0,2,0,2,0,100,2,0,75,16000,22000,11,52624,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Afterburn at 75% HP'),
(@ENTRY,0,3,0,2,0,100,4,0,75,16000,22000,11,59183,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Afterburn at 75% HP');

-- Hardened Steel Berserker
SET @ENTRY := 28579;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,52740,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,1,0,0,0,100,4,0,0,2300,3900,11,59259,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,2,0,2,0,100,7,0,30,0,0,11,61369,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,3,0,2,0,100,7,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP');
-- NPC talk text insert
SET @ENTRY := 28579;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage');

-- Hardened Steel Reaver
SET @ENTRY := 28578;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,7000,11000,11,42724,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave on Close'),
(@ENTRY,0,1,0,0,0,100,2,9000,18000,12000,24000,11,15655,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Slam'),
(@ENTRY,0,2,0,0,0,100,4,9000,18000,12000,24000,11,59142,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Slam');

-- Slag
SET @ENTRY := 28585;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,6000,8000,17000,19000,11,23113,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blast Wave'),
(@ENTRY,0,1,0,0,0,100,4,6000,8000,17000,19000,11,22424,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blast Wave'),
(@ENTRY,0,2,0,0,0,100,2,4000,5500,26000,29000,11,61509,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Melt Armor'),
(@ENTRY,0,3,0,0,0,100,4,4000,5500,26000,29000,11,61510,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Melt Armor');

-- Stormfury Revenant
SET @ENTRY := 28826;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,14000,16000,15000,18000,11,52905,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Thunderbolt'),
(@ENTRY,0,1,0,0,0,100,4,14000,16000,15000,18000,11,59167,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Thunderbolt'),
(@ENTRY,0,2,0,0,0,100,2,0,5000,17000,23000,11,53043,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Electro Shock'),
(@ENTRY,0,3,0,0,0,100,4,0,5000,17000,23000,11,59168,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Electro Shock');

-- Titanium Siegebreaker
SET @ENTRY := 28961;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,10,9000,14000,11,23600,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Piercing Howl on Close'),
(@ENTRY,0,1,0,2,0,100,2,0,40,10000,15000,11,52891,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blade Turning at 40% HP'),
(@ENTRY,0,2,0,2,0,100,4,0,40,10000,15000,11,59173,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blade Turning at 40% HP'),
(@ENTRY,0,3,0,0,0,100,6,10000,13000,14000,17000,11,52890,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Penetrating Strike'),
(@ENTRY,0,4,0,2,0,100,7,0,50,0,0,11,19134,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Frightening Shout at 50% HP');

-- Storming Vortex
SET @ENTRY := 28547;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,53044,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,59169,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,2,0,0,0,100,6,5000,8000,9000,18000,11,60236,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Cyclone');

-- Titanium Thunderer
SET @ENTRY := 28965;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,52904,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,1,0,0,0,100,4,0,0,2300,3900,11,59179,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,2,0,2,0,100,3,0,40,0,0,11,52879,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Deflection at 40% HP'),
(@ENTRY,0,3,0,9,0,100,2,8,30,9700,12500,11,52885,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Deadly Throw on Close'),
(@ENTRY,0,4,0,2,0,100,5,0,40,0,0,11,59181,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Deflection at 40% HP'),
(@ENTRY,0,5,0,9,0,100,4,8,30,9700,12500,11,59180,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Deadly Throw on Close');

-- Hardened Steel Skycaller
SET @ENTRY := 28580;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,16100,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,4,0,0,2300,3900,11,61515,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,2,5,9,0,100,2,5,30,15000,20000,11,52754,1,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Impact Shot'),
(@ENTRY,0,3,5,9,0,100,2,5,30,12000,18000,11,52755,1,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Impact Multi-Shot'),
(@ENTRY,0,4,5,9,0,100,4,5,30,15000,20000,11,59148,1,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Impact Shot'),
(@ENTRY,0,5,5,9,0,100,4,5,30,12000,18000,11,59147,1,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Impact Multi-Shot'),
(@ENTRY,0,6,0,9,0,100,6,0,5,6000,9000,11,61507,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Disengage on Close');
