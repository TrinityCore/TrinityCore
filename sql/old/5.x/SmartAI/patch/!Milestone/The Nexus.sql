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
	
-- Crazed Mana-Wraith
SET @ENTRY := 26746;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3000,4000,1000,1500,11,33833,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Missiles');

-- Crystalline Keeper
SET @ENTRY := 26782;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,6000,8500,12000,11,33688,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crystal Strike'),
(@ENTRY,0,1,0,0,0,100,4,4000,6000,8500,12000,11,57052,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crystal Strike'),
(@ENTRY,0,2,0,4,0,100,7,0,0,0,0,11,47699,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Crystal Bark on Aggro');

-- Crystalline Frayer
SET @ENTRY := 26793;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3000,4000,9500,15000,11,48053,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ensnare'),
(@ENTRY,0,1,0,4,0,100,7,0,0,0,0,11,48058,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Crystal Bloom on Aggro'),
(@ENTRY,0,2,0,2,0,100,7,0,35,0,0,11,48082,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Seed Pod at 35% HP'),
(@ENTRY,0,3,0,2,0,100,3,0,30,0,0,11,52067,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Aura of Regeneration at 30% HP'),
(@ENTRY,0,4,0,2,0,100,5,0,30,0,0,11,57056,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Aura of Regeneration at 30% HP');

-- Alliance Ranger
SET @ENTRY := 26802;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,15620,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,4,0,0,2300,3900,11,22907,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,2,0,0,0,100,2,7000,11000,9500,10000,11,47777,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Incendiary Shot'),
(@ENTRY,0,3,0,0,0,100,6,12000,15000,16100,19000,11,48191,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rapid Shot'),
(@ENTRY,0,4,0,0,0,100,4,7000,11000,9500,10000,11,56933,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Incendiary Shot'),
(@ENTRY,0,5,0,4,0,100,7,0,0,0,0,28,47543,0,0,0,0,0,1,0,0,0,0,0,0,0,'Remove Aura on Aggro');

-- Alliance Commander
SET @ENTRY := 27949;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,8,25,11000,15000,11,60067,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Close'),
(@ENTRY,0,1,0,4,0,100,7,0,0,0,0,28,47543,0,0,0,0,0,1,0,0,0,0,0,0,0,'Remove Aura on Aggro'),
(@ENTRY,0,2,0,4,0,100,7,0,0,0,0,11,31403,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Battle Shout on Aggro'),
(@ENTRY,0,3,0,0,0,100,6,6000,8000,19500,25000,11,38618,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirlwind');

-- Azure Enforcer
SET @ENTRY := 26734;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3000,4000,12000,19000,11,39171,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Malevolent Strikes'),
(@ENTRY,0,1,0,0,0,100,6,6300,8100,9500,15000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,2,0,0,0,100,6,3000,4000,12000,19000,11,58460,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Brutal Strike');

-- Alliance Cleric
SET @ENTRY := 26805;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,28,47543,0,0,0,0,0,1,0,0,0,0,0,0,0,'Remove Aura on Aggro'),
(@ENTRY,0,1,0,14,0,100,2,10000,25,12100,19000,11,17843,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Flash Heal on Friendlies'),
(@ENTRY,0,2,0,14,0,100,4,10000,25,12100,19000,11,56919,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Flash Heal on Friendlies'),
(@ENTRY,0,3,0,0,0,100,2,9000,11000,9500,15000,11,47697,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Word: Death'),
(@ENTRY,0,4,0,0,0,100,4,9000,11000,9500,15000,11,56920,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Word: Death');

-- Alliance Berserker
SET @ENTRY := 26800;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,28,47543,0,0,0,0,0,1,0,0,0,0,0,0,0,'Remove Aura on Aggro'),
(@ENTRY,0,1,0,0,0,100,6,12000,15000,40000,58000,11,21049,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bloodlust'),
(@ENTRY,0,2,0,0,0,100,6,6000,8000,15000,19000,11,38682,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast War Stomp'),
(@ENTRY,0,3,0,0,0,100,6,9000,10000,9500,15000,11,47774,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy');

-- Horde Berserker
SET @ENTRY := 26799;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,28,47543,0,0,0,0,0,1,0,0,0,0,0,0,0,'Remove Aura on Aggro'),
(@ENTRY,0,1,0,0,0,100,6,12000,15000,40000,58000,11,21049,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bloodlust'),
(@ENTRY,0,2,0,0,0,100,6,6000,8000,15000,19000,11,38682,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast War Stomp'),
(@ENTRY,0,3,0,0,0,100,6,9000,10000,9500,15000,11,47774,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy');

-- Horde Cleric
SET @ENTRY := 26803;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,28,47543,0,0,0,0,0,1,0,0,0,0,0,0,0,'Remove Aura on Aggro'),
(@ENTRY,0,1,0,14,0,100,2,10000,25,12100,19000,11,17843,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Flash Heal on Friendlies'),
(@ENTRY,0,2,0,14,0,100,4,10000,25,12100,19000,11,56919,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Flash Heal on Friendlies'),
(@ENTRY,0,3,0,0,0,100,2,9000,11000,9500,15000,11,47697,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Word: Death'),
(@ENTRY,0,4,0,0,0,100,4,9000,11000,9500,15000,11,56920,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Word: Death');

-- Horde Commander
SET @ENTRY := 27947;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,8,25,11000,15000,11,60067,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Close'),
(@ENTRY,0,1,0,4,0,100,7,0,0,0,0,28,47543,0,0,0,0,0,1,0,0,0,0,0,0,0,'Remove Aura on Aggro'),
(@ENTRY,0,2,0,4,0,100,7,0,0,0,0,11,31403,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Battle Shout on Aggro'),
(@ENTRY,0,3,0,0,0,100,6,6000,8000,19500,25000,11,38618,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirlwind');

-- Horde Ranger
SET @ENTRY := 26801;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,15620,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,4,0,0,2300,3900,11,22907,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,2,0,0,0,100,2,7000,11000,9500,10000,11,47777,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Incendiary Shot'),
(@ENTRY,0,3,0,0,0,100,6,12000,15000,16100,19000,11,48191,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rapid Shot'),
(@ENTRY,0,4,0,0,0,100,4,7000,11000,9500,10000,11,56933,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Incendiary Shot'),
(@ENTRY,0,5,0,4,0,100,7,0,0,0,0,28,47543,0,0,0,0,0,1,0,0,0,0,0,0,0,'Remove Aura on Aggro');

-- Grand Magus Telestra
SET @ENTRY := 26930;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,3000,8000,9000,11,47729,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ice Barb'),
(@ENTRY,0,1,0,0,0,100,4,3000,3000,8000,9000,11,56937,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ice Barb'),
(@ENTRY,0,2,0,0,0,100,2,9000,9000,15000,16000,11,47727,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blizzard'),
(@ENTRY,0,3,0,0,0,100,4,9000,9000,15000,16000,11,56936,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blizzard');

-- Crystalline Tender
SET @ENTRY := 28231;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,12000,15000,19500,35000,11,51972,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Tranquility'),
(@ENTRY,0,1,0,0,0,100,4,12000,15000,19500,35000,11,57054,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Tranquility'),
(@ENTRY,0,2,0,0,0,100,6,2000,5000,11100,19000,11,50994,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Toughen Hide');

-- Azure Warder
SET @ENTRY := 26716;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,6000,29000,35000,11,17741,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Mana Shield'),
(@ENTRY,0,1,0,0,0,100,4,4000,6000,29000,35000,11,56778,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Mana Shield'),
(@ENTRY,0,2,0,0,0,100,2,9000,11000,9000,12000,11,6726,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Silence'),
(@ENTRY,0,3,0,0,0,100,4,9000,11000,9000,12000,11,56777,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Silence');

-- Azure Scale-Binder
SET @ENTRY := 26735;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,14,0,100,2,9000,25,9500,15000,11,15586,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Heal on Friendlies'),
(@ENTRY,0,1,0,14,0,100,4,9000,25,9500,15000,11,61326,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Heal on Friendlies'),
(@ENTRY,0,2,0,0,0,100,2,4000,6000,9500,15000,11,38881,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Blast'),
(@ENTRY,0,3,0,0,0,100,4,4000,6000,9500,15000,11,56969,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Blast');

-- Azure Magus
SET @ENTRY := 26722;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,15530,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,56775,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,2,0,0,0,100,2,9000,11000,9000,15000,11,37132,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Shock'),
(@ENTRY,0,3,0,0,0,100,4,9000,11000,9000,15000,11,56776,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Shock');

-- Grand Magus Telestra
SET @ENTRY := 26929;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,6000,8000,9000,13000,11,47731,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Critter'),
(@ENTRY,0,1,0,6,0,100,7,0,0,0,0,11,47713,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon on Death'),
(@ENTRY,0,2,0,0,0,100,6,15000,16000,15000,16000,11,47736,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Time Stop');

-- Grand Magus Telestra
SET @ENTRY := 26928;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,3000,8000,9000,11,47721,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fire Blast'),
(@ENTRY,0,1,0,6,0,100,7,0,0,0,0,11,47711,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon on Death'),
(@ENTRY,0,2,0,0,0,100,4,3000,3000,8000,9000,11,56939,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fire Blast'),
(@ENTRY,0,3,0,0,0,100,2,9000,9000,9500,11500,11,47723,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Scorch'),
(@ENTRY,0,4,0,0,0,100,4,9000,9000,9500,11500,11,56938,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Scorch');

-- Mage Slayer
SET @ENTRY := 26730;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3000,4000,15000,19000,11,50131,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Draw Magic'),
(@ENTRY,0,1,0,0,0,100,6,8000,10000,9500,15000,11,30849,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Spell Lock');

-- Steward
SET @ENTRY := 26729;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3000,5000,15000,19000,11,47779,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Torrent'),
(@ENTRY,0,1,0,0,0,100,6,7000,9000,9500,15000,11,47780,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Spellbreaker');

-- Crazed Mana-Surge
SET @ENTRY := 26737;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,9000,11000,9500,15000,11,47696,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Nova'),
(@ENTRY,0,1,0,0,0,100,4,9000,11000,9500,15000,11,57046,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Nova'),
(@ENTRY,0,2,0,0,0,100,2,4000,6000,9500,15000,11,48054,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mana Burn'),
(@ENTRY,0,3,0,0,0,100,4,4000,6000,9500,15000,11,57047,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mana Burn'),
(@ENTRY,0,4,0,6,0,100,7,0,0,0,0,11,29882,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Loose Mana on Death');

-- Crystalline Protector
SET @ENTRY := 26792;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,9000,11000,9500,15000,11,50302,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shard Spray'),
(@ENTRY,0,1,0,0,0,100,4,9000,11000,9500,15000,11,57051,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shard Spray'),
(@ENTRY,0,2,0,0,0,100,6,12000,15000,11100,19000,11,30633,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thunderclap'),
(@ENTRY,0,3,0,0,0,100,2,4000,6000,9500,15000,11,47698,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Crystal Chains'),
(@ENTRY,0,4,0,0,0,100,4,4000,6000,9500,15000,11,57050,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Crystal Chains');

-- Commander Kolurg
SET @ENTRY := 26798;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,6000,8000,19500,25000,11,38618,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirlwind'),
(@ENTRY,0,1,0,4,0,100,7,0,0,0,0,28,47543,0,0,0,0,0,1,0,0,0,0,0,0,0,'Remove Aura on Aggro'),
(@ENTRY,0,2,0,4,0,100,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Say on Aggro'),
(@ENTRY,0,3,0,4,0,100,7,0,0,0,0,11,31403,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Battle Shout on Aggro'),
(@ENTRY,0,4,0,9,0,100,6,8,25,11000,15000,11,60067,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Close'),
(@ENTRY,0,5,0,5,0,100,6,5000,5000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say on Player Death'),
(@ENTRY,0,6,0,6,0,100,7,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say on Death'),
(@ENTRY,0,7,0,0,0,100,6,13000,15000,45000,55000,11,19134,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Frightening Shout');
-- NPC talk text insert
SET @ENTRY := 26798;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'What is this? Mag thorin Kar! Kill them!',14,0,100,0,0,13458, 'combat Say'),
(@ENTRY,1,0, 'Our task is not yet done!',14,0,100,0,0,13459, 'combat Say'),
(@ENTRY,2,0, 'GOOO!',14,0,100,0,0,13460, 'combat Say');

-- Commander Stoutbeard
SET @ENTRY := 26796;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,6000,8000,19500,25000,11,38618,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirlwind'),
(@ENTRY,0,1,0,4,0,100,7,0,0,0,0,28,47543,0,0,0,0,0,1,0,0,0,0,0,0,0,'Remove Aura on Aggro'),
(@ENTRY,0,2,0,4,0,100,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Say on Aggro'),
(@ENTRY,0,3,0,4,0,100,7,0,0,0,0,11,31403,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Battle Shout on Aggro'),
(@ENTRY,0,4,0,9,0,100,6,8,25,11000,15000,11,60067,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Close'),
(@ENTRY,0,5,0,5,0,100,6,5000,5000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say on Player Death'),
(@ENTRY,0,6,0,6,0,100,7,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say on Death'),
(@ENTRY,0,7,0,0,0,100,6,13000,15000,45000,55000,11,19134,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Frightening Shout');
-- NPC talk text insert
SET @ENTRY := 26796;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'What? Where in a..? Don\'t just stand around lads KILL SOMEBODY!',14,0,100,0,0,13193, 'combat Say'),
(@ENTRY,1,0, 'Now we\re getting someplace!',14,0,100,0,0,13195, 'combat Say'),
(@ENTRY,2,0, 'Is that all you\'ve... got?',14,0,100,0,0,13194, 'combat Say');

-- Mage Hunter Ascendant
SET @ENTRY := 26727;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,12466,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,17290,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,2,0,0,0,100,2,10000,12000,11000,15000,11,15244,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cone of Cold'),
(@ENTRY,0,3,0,0,0,100,4,10000,12000,11000,15000,11,38384,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cone of Cold'),
(@ENTRY,0,4,0,0,0,100,2,7000,9000,15000,28000,11,36808,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Rain of Fire'),
(@ENTRY,0,5,0,0,0,100,4,7000,9000,15000,28000,11,39376,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Rain of Fire'),
(@ENTRY,0,6,0,13,0,100,6,9000,11000,0,0,11,47789,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Arcane Trap on Player Spell Cast'),
(@ENTRY,0,7,0,0,0,100,6,11000,11000,16000,19000,11,55040,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Freezing Trap'),
(@ENTRY,0,8,0,0,0,100,6,5000,5000,35000,37000,11,13323,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Polymorph');

-- Mage Hunter Initiate
SET @ENTRY := 26728;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,12000,15000,9500,15000,11,25058,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Renew'),
(@ENTRY,0,1,0,0,0,100,2,4000,6000,9500,15000,11,50198,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Magic Burn'),
(@ENTRY,0,2,0,0,0,100,4,4000,6000,9500,15000,11,56860,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Magic Burn'),
(@ENTRY,0,3,0,0,0,100,6,9000,11000,9500,15000,11,17682,1,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Drain Mana');

