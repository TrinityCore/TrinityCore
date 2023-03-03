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
 /* Bosses */
 
-- Entropius
SET @ENTRY := 25840;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,3,0,0,0,0,11,46223,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Entropius Cosmetic Spawn on Spawn'),
(@ENTRY,0,1,0,61,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sunwell Radiance on Spawn'),
(@ENTRY,0,2,0,0,0,100,2,11000,15000,17000,24000,11,46282,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Black Hole'),
(@ENTRY,0,3,0,0,0,100,2,45000,60000,45000,60000,11,46269,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Darkness');

-- M'uru
SET @ENTRY := 25741;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sunwell Radiance on Spawn'),
(@ENTRY,0,1,0,0,0,100,2,3000,8000,4000,7000,11,46008,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Negative Energy'),
(@ENTRY,0,2,0,0,0,100,2,12000,18000,21000,26000,11,45996,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Darkness'),
(@ENTRY,0,3,0,0,0,90,2,9000,15000,10000,16000,11,46263,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Dark Fiend'),
(@ENTRY,0,4,0,0,0,90,2,21000,25000,10000,16000,11,46037,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Berserker'),
(@ENTRY,0,5,0,0,0,90,2,28000,35000,10000,16000,11,46038,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fury Mage'),
(@ENTRY,0,6,0,0,0,90,2,39000,45000,10000,16000,11,45988,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Void Sentinel'),
(@ENTRY,0,7,8,6,0,100,3,0,0,0,0,11,46177,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Open All Portals on Death'),
(@ENTRY,0,8,0,61,0,100,3,0,0,0,0,11,46217,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Entropius on Death');

 /* Trash Mobs */
 
-- Anchorite Elbadon
SET @ENTRY := 25639;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,2,15000,30000,20000,45000,11,45859,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Renew on Spawn'),
(@ENTRY,0,1,0,61,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Spawn');
-- NPC talk text insert
SET @ENTRY := 25639;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'May the light bless you.',12,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,0,1, 'Your wounds are severe, but you will live.',12,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,0,2, 'Rest now, you have fought well today.',12,0,50,0,0,0, 'on Aggro Text');

-- Apocalypse Guard
SET @ENTRY := 25593;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sunwell Radiance on Spawn'),
(@ENTRY,0,1,0,9,0,100,2,0,5,7000,10000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave on Close'),
(@ENTRY,0,2,0,0,0,100,2,14000,25000,18000,26000,11,45029,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Corrupting Strike'),
(@ENTRY,0,3,0,0,0,100,2,5000,11000,14000,18000,11,46283,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Death Coil'),
(@ENTRY,0,4,0,2,0,100,3,0,20,0,0,11,46287,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Infernal Defense at 20% HP');

-- Cataclysm Hound
SET @ENTRY := 25599;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sunwell Radiance on Spawn'),
(@ENTRY,0,1,0,0,0,100,2,7000,11000,18000,24000,11,46292,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cataclysm Breath'),
(@ENTRY,0,2,1,2,0,100,3,0,20,0,0,11,47399,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 20% HP'),
(@ENTRY,0,3,0,61,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 20% HP');
-- NPC talk text insert
SET @ENTRY := 25599;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage');

-- Chaos Gazer
SET @ENTRY := 25595;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sunwell Radiance on Spawn'),
(@ENTRY,0,1,0,9,0,100,2,0,5,16000,21000,11,46288,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Petrify on Close'),
(@ENTRY,0,2,0,0,0,100,2,6000,9000,7000,10000,11,46290,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Tentacle Sweep'),
(@ENTRY,0,3,0,0,0,100,2,18000,24000,21000,26000,11,46291,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Drain Life');

-- Dark Fiend
SET @ENTRY := 25744;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sunwell Radiance on Spawn'),
(@ENTRY,0,1,0,61,0,100,3,0,0,0,0,11,45934,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dark Fiend on Spawn');

-- Doomfire Destroyer
SET @ENTRY := 25592;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sunwell Radiance on Spawn'),
(@ENTRY,0,1,0,0,0,100,2,3000,6000,9000,16000,11,46306,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Create Doomfire Shard');

-- Doomfire Shard
SET @ENTRY := 25948;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sunwell Radiance on Spawn'),
(@ENTRY,0,1,0,2,0,100,3,0,50,0,0,11,46305,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Avenging Rage at 50% HP');

-- Fire Fiend
SET @ENTRY := 26101;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sunwell Radiance on Spawn'),
(@ENTRY,0,1,0,9,0,100,2,0,5,8000,11000,11,46551,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fire Nova on Close');

-- Hand of the Deceiver
SET @ENTRY := 25588;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,1000,1000,1000,1000,11,51733,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dark Aura on Spawn'),
(@ENTRY,0,1,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sunwell Radiance on Spawn'),
(@ENTRY,0,2,0,0,0,100,2,1000,3000,4000,6000,11,45770,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley'),
(@ENTRY,0,3,0,0,0,100,2,9000,15000,21000,28000,11,46875,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Felfire Portal'),
(@ENTRY,0,4,0,2,0,100,3,0,50,0,0,11,45772,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Infusion at 50% HP');

-- Oblivion Mage
SET @ENTRY := 25597;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sunwell Radiance on Spawn'),
(@ENTRY,0,1,0,9,0,100,2,0,5,9000,14000,11,46279,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Buffet on Close'),
(@ENTRY,0,2,0,0,0,100,2,7000,11000,16000,19000,11,46280,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Polymorph');

-- Painbringer
SET @ENTRY := 25591;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sunwell Radiance on Spawn'),
(@ENTRY,0,1,0,0,0,100,2,3000,8000,16000,24000,11,46278,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bring Pain');

-- Priestess of Torment
SET @ENTRY := 25509;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sunwell Radiance on Spawn'),
(@ENTRY,0,1,0,0,0,100,2,5000,8000,14000,18000,11,46270,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirlwind');

-- Shadowsword Assassin
SET @ENTRY := 25484;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sunwell Radiance on Spawn'),
(@ENTRY,0,1,0,61,0,100,3,0,0,0,0,11,16380,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Greater Invisibility on Spawn'),
(@ENTRY,0,2,0,7,0,100,3,0,0,0,0,11,16380,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Greater Invisibility on Evade'),
(@ENTRY,0,3,0,4,0,100,3,0,0,0,0,11,46459,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Assassin\'s Mark on Aggro'),
(@ENTRY,0,4,0,9,0,100,2,0,5,25000,35000,11,46463,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadowstep on Close'),
(@ENTRY,0,5,0,0,0,100,2,1000,3000,7000,10000,11,46460,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Aimed Shot');

-- Shadowsword Berserker
SET @ENTRY := 25798;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sunwell Radiance on Spawn'),
(@ENTRY,0,1,0,0,0,100,2,1000,1000,12000,16000,11,46160,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Flurry');

-- Shadowsword Commander
SET @ENTRY := 25837;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sunwell Radiance on Spawn'),
(@ENTRY,0,1,0,0,0,100,2,1000,1000,15000,21000,11,46763,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Battle Shout'),
(@ENTRY,0,2,0,13,0,100,2,5000,8000,20000,30000,11,46762,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Shield Slam on Player Spell Cast');

-- Shadowsword Deathbringer
SET @ENTRY := 25485;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sunwell Radiance on Spawn'),
(@ENTRY,0,1,0,9,0,100,2,0,5,9000,15000,11,46481,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Disease Buffet on Close');

-- Shadowsword Fury Mage
SET @ENTRY := 25799;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sunwell Radiance on Spawn'),
(@ENTRY,0,1,0,9,0,100,2,0,40,8000,12000,11,46101,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Fireball on Close'),
(@ENTRY,0,2,0,0,0,100,2,18000,25000,45000,55000,11,46102,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spell Fury');

-- Shadowsword Guardian
SET @ENTRY := 25508;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sunwell Radiance on Spawn'),
(@ENTRY,0,1,0,0,0,100,2,18000,21000,20000,30000,11,46239,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Bear Down'),
(@ENTRY,0,2,0,4,0,100,3,0,0,0,0,11,46239,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bear Down on Aggro'),
(@ENTRY,0,3,0,0,0,100,2,7000,11000,15000,24000,11,46240,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Earthquake');

-- Shadowsword Lifeshaper
SET @ENTRY := 25506;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sunwell Radiance on Spawn'),
(@ENTRY,0,1,0,0,0,100,2,15000,25000,40000,70000,11,46466,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Drain Life');

-- Shadowsword Manafiend
SET @ENTRY := 25483;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sunwell Radiance on Spawn'),
(@ENTRY,0,1,0,9,0,100,2,0,15,9000,15000,11,46457,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Explosion on Close'),
(@ENTRY,0,2,0,3,0,100,2,0,10,14000,21000,11,46453,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Drain Mana at 10% Mana'),
(@ENTRY,0,3,0,0,0,100,2,2000,4500,12000,20000,11,46745,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chilling Touch');

-- Shadowsword Soulbinder
SET @ENTRY := 25373;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sunwell Radiance on Spawn'),
(@ENTRY,0,1,0,4,0,50,3,0,0,0,0,11,46229,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Blazing Infernal on Aggro'),
(@ENTRY,0,2,0,4,0,50,3,0,0,0,0,11,46241,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Felguard Slayer on Aggro'),
(@ENTRY,0,3,0,9,0,100,2,0,50,12000,16000,11,46434,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Curse of Exhaustion on Close'),
(@ENTRY,0,4,0,0,0,100,2,9000,15000,14000,18000,11,46442,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flash of Darkness'),
(@ENTRY,0,5,0,0,0,100,2,18000,23000,21000,25000,11,46427,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Domination');

-- Shadowsword Vanquisher
SET @ENTRY := 25486;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sunwell Radiance on Spawn'),
(@ENTRY,0,1,0,9,0,100,2,0,5,11000,14000,11,46469,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Melt Armor on Close'),
(@ENTRY,0,2,0,0,0,100,2,7000,11000,9000,12000,11,46468,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave');

-- Shattered Sun Soldier
SET @ENTRY := 25661;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,46586,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Almost Dead on Spawn');

-- Shield Orb
SET @ENTRY := 25502;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,3000,4000,6000,11,45680,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt');

-- Sunblade Arch Mage
SET @ENTRY := 25367;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sunwell Radiance on Spawn'),
(@ENTRY,0,1,0,9,0,100,2,0,10,8000,11000,11,46555,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Armor on Close'),
(@ENTRY,0,2,0,0,0,100,2,11000,15000,18000,21000,11,46553,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Explosion'),
(@ENTRY,0,3,0,0,0,100,2,16000,21000,26000,32000,11,46573,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blink');

-- Sunblade Cabalist
SET @ENTRY := 25363;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,47248,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,1,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sunwell Radiance on Spawn'),
(@ENTRY,0,2,0,1,0,100,3,3000,5000,0,0,11,46544,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Imp on Spawn'),
(@ENTRY,0,3,0,0,0,100,2,8000,9000,18000,20000,11,46543,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Ignite Mana');

-- Sunblade Dawn Priest
SET @ENTRY := 25371;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sunwell Radiance on Spawn'),
(@ENTRY,0,1,0,4,0,100,3,0,0,0,0,11,46565,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Holyform on Aggro'),
(@ENTRY,0,2,0,0,0,100,2,7000,11000,12000,16000,11,46564,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Holy Nova'),
(@ENTRY,0,3,0,14,0,100,2,50000,100,14000,18000,11,46563,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Renew on Friendlies'),
(@ENTRY,0,4,0,2,0,100,2,0,50,16000,21000,11,46563,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Renew at 50% HP');

-- Sunblade Dragonhawk
SET @ENTRY := 25867;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sunwell Radiance on Spawn'),
(@ENTRY,0,1,0,9,0,100,2,0,5,8000,11000,11,47251,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Breath on Close');

-- Sunblade Dusk Priest
SET @ENTRY := 25506;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sunwell Radiance on Spawn'),
(@ENTRY,0,1,0,0,0,100,2,1000,3000,11000,15000,11,46562,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Mind Flay'),
(@ENTRY,0,2,0,0,0,100,2,8000,14000,21000,26000,11,46560,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Shadow Word: Pain'),
(@ENTRY,0,3,0,2,0,100,2,0,50,15000,18000,11,46561,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Fear at 50% HP');

-- Sunblade Protector
SET @ENTRY := 25507;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sunwell Radiance on Spawn'),
(@ENTRY,0,1,0,0,0,100,2,7000,13000,15000,20000,11,46480,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Fel Lightning');

-- Sunblade Scout
SET @ENTRY := 25372;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sunwell Radiance on Spawn'),
(@ENTRY,0,1,0,4,0,100,3,0,0,0,0,11,46475,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Activate Sunblade Protector on Aggro'),
(@ENTRY,0,2,0,9,0,100,2,0,5,6000,9000,11,46558,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sinister Strike on Close');

-- Sunblade Slayer
SET @ENTRY := 25368;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,47001,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sunwell Radiance on Spawn'),
(@ENTRY,0,2,0,0,0,100,2,6000,9000,15000,20000,11,46557,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Slaying Shoot'),
(@ENTRY,0,3,0,9,0,100,2,0,8,13600,14500,11,46681,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Scatter Shot on Close');

-- Sunblade Vindicator
SET @ENTRY := 25369;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sunwell Radiance on Spawn'),
(@ENTRY,0,1,0,9,0,100,2,0,5,7000,10000,11,58460,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike on Close'),
(@ENTRY,0,2,0,0,0,100,2,9000,13000,12000,16000,11,46559,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Cleave');

-- Void Sentinel
SET @ENTRY := 25772;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sunwell Radiance on Spawn'),
(@ENTRY,0,1,0,9,0,100,2,0,10,7000,11000,11,46087,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Pulse on Close'),
(@ENTRY,0,2,0,0,0,100,2,15000,21000,14000,19000,11,46161,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Void Blast'),
(@ENTRY,0,3,4,6,0,100,3,0,0,0,0,11,46071,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Void Spawns on Death'),
(@ENTRY,0,4,5,61,0,100,3,0,0,0,0,11,46071,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Void Spawns on Death'),
(@ENTRY,0,5,0,61,0,100,3,0,0,0,0,11,46071,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Void Spawns on Death');

-- Void Spawn
SET @ENTRY := 25824;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sunwell Radiance on Spawn'),
(@ENTRY,0,1,0,9,0,100,2,0,10,4000,7000,11,46082,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley on Close');

-- Volatile Felfire Fiend
SET @ENTRY := 25598;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sunwell Radiance on Spawn'),
(@ENTRY,0,1,0,6,0,100,3,0,0,0,0,11,45779,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Felfire Fission on Death');

-- Volatile Fiend
SET @ENTRY := 25851;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sunwell Radiance on Spawn'),
(@ENTRY,0,1,0,4,0,100,3,0,0,0,0,11,46308,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Burning Winds on Aggro'),
(@ENTRY,0,2,3,6,0,100,3,0,0,0,0,11,47287,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Burning Destruction on Death'),
(@ENTRY,0,3,0,61,0,100,3,0,0,0,0,11,45779,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Felfire Fission on Death');

