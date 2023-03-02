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
	
-- Freed Alliance Slave
SET @ENTRY := 37572;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,5000,12000,13000,11,59992,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,1,0,0,0,100,6,8500,9100,16900,19600,11,69566,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Strike'),
(@ENTRY,0,2,0,9,0,100,6,0,10,28000,32000,11,69565,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demoralizing Shout on Close');

-- Freed Alliance Slave
SET @ENTRY := 37576;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,3400,4700,11,69570,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,6,5000,5000,25000,26000,11,70421,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Blizzard'),
(@ENTRY,0,2,0,2,0,100,6,0,20,12000,22000,11,46604,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Ice Block at 20% HP');

-- Fallen Warrior
SET @ENTRY := 36841;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3500,4100,25600,31300,11,69579,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcing Slice'),
(@ENTRY,0,1,0,2,0,100,6,0,50,12000,13000,11,69580,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shield Block at 50% HP'),
(@ENTRY,0,2,0,9,0,100,6,0,10,24300,25600,11,61044,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demoralizing Shout on Close');

-- Deathwhisper Shadowcaster <Cult of the Damned>
SET @ENTRY := 37712;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,70386,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,2,2,0,100,7,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,7,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,0,0,100,4,0,0,3400,4700,11,70387,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,4,0,0,0,100,6,4500,4500,21000,22000,11,70388,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Seed of Corruption');
-- NPC talk text insert
SET @ENTRY := 37712;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Dark Ranger Loralen
SET @ENTRY := 37779;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,2300,3900,11,70513,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot');

-- Dark Ranger Kalira
SET @ENTRY := 37583;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,2300,3900,11,70513,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot');

-- Ymirjar Wrathbringer
SET @ENTRY := 36840;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,8000,8000,19900,22800,11,69603,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blight'),
(@ENTRY,0,1,0,0,0,100,4,8000,8000,19900,22800,11,70285,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blight');

-- Ymirjar Skycaller
SET @ENTRY := 31260;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,5200,12000,13900,11,70292,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Glacial Strike'),
(@ENTRY,0,1,0,0,0,100,6,8000,9000,25000,26000,11,70291,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frostblade');

-- Horde Slave
SET @ENTRY := 36773;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,3400,4700,11,69570,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,6,5000,5000,25000,26000,11,70421,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Blizzard');

-- Fallen Warrior
SET @ENTRY := 38487;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3500,4100,25600,31300,11,69579,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcing Slice'),
(@ENTRY,0,1,0,2,0,100,6,0,50,12000,13000,11,69580,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shield Block at 50% HP'),
(@ENTRY,0,2,0,9,0,100,6,0,10,24300,25600,11,61044,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demoralizing Shout on Close');

-- Horde Slave
SET @ENTRY := 36772;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,5000,12000,13000,11,59992,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,1,0,0,0,100,6,8500,9100,16900,19600,11,69566,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Strike'),
(@ENTRY,0,2,0,9,0,100,6,0,10,28000,32000,11,69565,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demoralizing Shout on Close');

-- Geist Ambusher
SET @ENTRY := 36886;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,69504,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Leaping Face Maul on Aggro'),
(@ENTRY,0,1,0,4,0,100,5,0,0,0,0,11,70271,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Leaping Face Maul on Aggro');

-- Freed Horde Slave
SET @ENTRY := 37577;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,5000,12000,13000,11,59992,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,1,0,0,0,100,6,8500,9100,16900,19600,11,69566,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Strike'),
(@ENTRY,0,2,0,9,0,100,6,0,10,28000,32000,11,69565,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demoralizing Shout on Close');

-- Deathwhisper Torturer <Cult of the Damned>
SET @ENTRY := 37713;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,5000,14500,16800,11,70392,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Black Brand'),
(@ENTRY,0,1,0,0,0,100,6,7500,8500,13500,16900,11,70391,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Curse of Agony');

-- Horde Slave
SET @ENTRY := 36770;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,5000,12000,13000,11,59992,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,1,0,0,0,100,6,8500,9100,16900,19600,11,69566,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Strike'),
(@ENTRY,0,2,0,9,0,100,6,0,10,28000,32000,11,69565,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demoralizing Shout on Close');

-- Alliance Slave
SET @ENTRY := 36766;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,5000,12000,13000,11,59992,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,1,0,0,0,100,6,8500,9100,16900,19600,11,69566,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Strike'),
(@ENTRY,0,2,0,9,0,100,6,0,10,28000,32000,11,69565,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demoralizing Shout on Close');

-- Alliance Slave
SET @ENTRY := 36764;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,5000,12000,13000,11,59992,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,1,0,0,0,100,6,8500,9100,16900,19600,11,69566,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Strike'),
(@ENTRY,0,2,0,9,0,100,6,0,10,28000,32000,11,69565,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demoralizing Shout on Close');

-- Martin Victus
SET @ENTRY := 37580;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,5000,12000,13000,11,59992,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,1,0,0,0,100,6,8500,9100,16900,19600,11,69566,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Strike'),
(@ENTRY,0,2,0,9,0,100,6,0,10,28000,32000,11,69565,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demoralizing Shout on Close');

-- Hungering Ghoul
SET @ENTRY := 37711;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,8000,8000,22000,24000,11,70393,0,0,0,0,0,2,1,0,0,0,0,0,0,'Cast Devour Flesh');

-- Archmage Koreln <Kirin Tor>
SET @ENTRY := 37582;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,3400,4700,11,70616,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt');

-- Archmage Elandra <Kirin Tor>
SET @ENTRY := 37774;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,3400,4700,11,70616,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt');

-- Alliance Slave
SET @ENTRY := 36767;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,3400,4700,11,69570,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,6,5000,5000,25000,26000,11,70421,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Blizzard');

-- Disturbed Glacial Revenant
SET @ENTRY := 36874;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,5500,14600,17800,11,55216,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Avalanche');

-- Freed Horde Slave
SET @ENTRY := 37579;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,3400,4700,11,69570,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,6,5000,5000,25000,26000,11,70421,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Blizzard'),
(@ENTRY,0,2,0,2,0,100,6,0,20,12000,22000,11,46604,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Ice Block at 20% HP');

-- Gorkun Ironskull
SET @ENTRY := 37581;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,5000,12000,13000,11,59992,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,1,0,0,0,100,6,8500,9100,16900,19600,11,69566,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Strike'),
(@ENTRY,0,2,0,9,0,100,6,0,10,28000,32000,11,69565,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demoralizing Shout on Close');

-- Freed Alliance Slave
SET @ENTRY := 37575;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,7,0,50,0,0,11,69569,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Earth Shield at 50% HP'),
(@ENTRY,0,1,0,14,0,100,6,30000,30,20000,30000,11,70425,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Chain Heal on Friendlies'),
(@ENTRY,0,2,0,0,0,100,6,5000,8000,17000,21000,11,70517,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Totem');

-- Alliance Slave
SET @ENTRY := 36765;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,7,0,50,0,0,11,69569,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Earth Shield at 50% HP'),
(@ENTRY,0,1,0,14,0,100,6,30000,30,20000,30000,11,70425,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Chain Heal on Friendlies'),
(@ENTRY,0,2,0,0,0,100,6,5000,8000,17000,21000,11,70517,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Totem');

-- Freed Horde Slave
SET @ENTRY := 37578;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,7,0,50,0,0,11,69569,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Earth Shield at 50% HP'),
(@ENTRY,0,1,0,14,0,100,6,30000,30,20000,30000,11,70425,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Chain Heal on Friendlies'),
(@ENTRY,0,2,0,0,0,100,6,5000,8000,17000,21000,11,70517,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Totem');

-- Deathwhisper Necrolyte <Cult of the Damned>
SET @ENTRY := 36788;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,69577,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,70270,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,2,0,0,0,100,2,8000,8000,16000,16000,11,69578,1,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Conversion Beam'),
(@ENTRY,0,3,0,0,0,100,4,8000,8000,16000,16000,11,70269,1,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Conversion Beam');

-- Horde Slave
SET @ENTRY := 36771;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,7,0,50,0,0,11,69569,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Earth Shield at 50% HP'),
(@ENTRY,0,1,0,14,0,100,6,30000,30,20000,30000,11,70425,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Chain Heal on Friendlies'),
(@ENTRY,0,2,0,0,0,100,6,5000,8000,17000,21000,11,70517,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Totem');

-- Stonespine Gargoyle
SET @ENTRY := 36896;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,12000,13000,11,69520,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gargoyle Strike'),
(@ENTRY,0,1,0,0,0,100,4,5000,5000,12000,13000,11,70275,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gargoyle Strike'),
(@ENTRY,0,2,0,2,0,100,7,0,30,0,0,11,69575,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stoneform at 30% HP');

-- Wrathbone Coldwraith
SET @ENTRY := 36842;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 1 on Aggro'),
(@ENTRY,0,1,0,4,1,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving on Aggro'),
(@ENTRY,0,2,0,4,1,100,3,0,0,0,0,11,69573,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt on Aggro'),
(@ENTRY,0,3,0,9,1,100,2,0,40,3400,4700,11,69573,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,4,0,9,1,100,2,40,100,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Moving when not in bolt Range'),
(@ENTRY,0,5,0,9,1,100,2,10,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving at 15 Yards'),
(@ENTRY,0,6,0,9,1,100,2,0,40,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving when in bolt Range'),
(@ENTRY,0,7,0,3,1,100,2,0,15,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 2 at 15% Mana'),
(@ENTRY,0,8,0,3,2,100,2,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Moving at 15% Mana'),
(@ENTRY,0,9,0,3,2,100,2,30,100,100,100,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 1 When Mana is above 30%'),
(@ENTRY,0,10,0,4,0,100,5,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 1 on Aggro'),
(@ENTRY,0,11,0,4,1,100,5,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving on Aggro'),
(@ENTRY,0,12,0,4,1,100,5,0,0,0,0,11,70277,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt on Aggro'),
(@ENTRY,0,13,0,9,1,100,4,0,40,3400,4700,11,70277,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,14,0,9,1,100,4,40,100,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Moving when not in bolt Range'),
(@ENTRY,0,15,0,9,1,100,4,10,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving at 15 Yards'),
(@ENTRY,0,16,0,9,1,100,4,0,40,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving when in bolt Range'),
(@ENTRY,0,17,0,3,1,100,4,0,15,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 2 at 15% Mana'),
(@ENTRY,0,18,0,3,2,100,4,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Moving at 15% Mana'),
(@ENTRY,0,19,0,3,2,100,4,30,100,100,100,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 1 When Mana is above 30%'),
(@ENTRY,0,20,0,0,1,100,2,8000,8000,35000,37000,11,69574,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Freezing Circle'),
(@ENTRY,0,21,0,0,1,100,4,8000,8000,35000,37000,11,70276,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Freezing Circle');

-- Ymirjar Deathbringer
SET @ENTRY := 36892;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,69528,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,70281,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,2,0,0,0,100,6,5000,5000,55000,55000,11,69516,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Undead');

-- Ymirjar Flamebearer
SET @ENTRY := 36893;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,69583,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,70282,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,2,0,0,0,100,6,11000,12000,35000,39000,11,69516,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Tactical Blink'),
(@ENTRY,0,3,0,0,0,100,2,7000,11000,28000,31000,11,69586,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Hellfire'),
(@ENTRY,0,4,0,0,0,100,4,7000,11000,28000,31000,11,70283,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Hellfire');

-- Plagueborn Horror
SET @ENTRY := 36879;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,7,0,10,0,0,11,69582,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blight Bomb at 10% HP'),
(@ENTRY,0,1,0,0,0,100,2,5000,6000,12000,14000,11,69581,0,0,0,0,0,2,32,0,0,0,0,0,0,'Cast Pustulant Flesh'),
(@ENTRY,0,2,0,0,0,100,4,5000,6000,12000,14000,11,70273,0,0,0,0,0,2,32,0,0,0,0,0,0,'Cast Pustulant Flesh'),
(@ENTRY,0,3,0,9,0,100,6,0,4,15800,18300,11,70274,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Toxic Waste on Close');

-- Wrathbone Laborer
SET @ENTRY := 36830;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,70302,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Blinding Dirt on Aggro'),
(@ENTRY,0,1,0,0,0,100,2,3300,4100,10500,15600,11,70278,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Puncture Wound'),
(@ENTRY,0,2,0,0,0,100,4,3300,4100,10500,15600,11,70279,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Puncture Wound'),
(@ENTRY,0,3,0,9,0,100,2,0,5,12300,16800,11,69572,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shovelled! on Close'),
(@ENTRY,0,4,0,9,0,100,4,0,5,12300,16800,11,70280,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shovelled! on Close');
