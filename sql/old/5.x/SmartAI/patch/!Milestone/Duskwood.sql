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
 
-- Anguished Spirit
SET @ENTRY := 45614;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,14000,11,80132,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Unbound Darkness');

-- Barn Owl
SET @ENTRY := 44020;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4500,13000,17000,11,49865,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Eye Peck'),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,18000,24000,11,81680,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Howling Screech');

-- Black Ravager
SET @ENTRY := 628;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,1,0,45,0,0,11,75002,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Leaping Rush on Close');

-- Black Widow
SET @ENTRY := 45582;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4500,15000,17000,11,13884,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Withering Poison'),
(@ENTRY,0,1,0,2,0,100,0,0,40,15000,21000,11,87080,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Vanish at 40% HP');

-- Black Widow Hatchling
SET @ENTRY := 930;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4500,15000,17000,11,13884,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Withering Poison'),
(@ENTRY,0,1,0,9,0,100,0,0,30,8000,9000,11,12023,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Web on Close');

-- Blackbelly Forager
SET @ENTRY := 44089;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rushing Charge on Aggro'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,84873,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Wallow at 30% HP');

-- Bone Chewer
SET @ENTRY := 210;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,2500,11000,11500,11,82625,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bone Toss'),
(@ENTRY,0,1,0,1,0,100,1,0,0,0,0,11,26047,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Birth on Spawn');

-- Buried Corpse
SET @ENTRY := 43851;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,15000,18000,11,84863,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Tunnel'),
(@ENTRY,0,1,0,1,0,100,1,0,0,0,0,11,26047,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Birth on Spawn');

-- Carved One
SET @ENTRY := 45785;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,85253,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rotten Stench on Spawn'),
(@ENTRY,0,1,0,0,0,100,0,4500,6500,14500,16800,11,78472,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Breath');

-- Clattering Coldwraith
SET @ENTRY := 44029;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,1800000,1800000,11,79865,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Armor on Spawn'),
(@ENTRY,0,1,0,0,0,100,0,6000,8000,24000,26000,11,79860,1,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Blizzard'),
(@ENTRY,0,2,0,0,0,100,0,3000,5000,12000,15000,11,79859,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ice Lance');

-- Coalpelt Bear
SET @ENTRY := 44016;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,11000,13000,11,31279,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Swipe'),
(@ENTRY,0,1,0,2,0,100,1,0,45,0,0,11,84868,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Hibernate at 45% HP');

-- Corpseweed
SET @ENTRY := 43732;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,85253,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rotten Stench on Spawn');

-- Crown Duster
SET @ENTRY := 37984;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,70074,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Spray Chemical');

-- Dire Wolf
SET @ENTRY := 43704;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,18501,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP'),
(@ENTRY,0,2,0,0,0,100,0,3000,6000,22000,26000,11,3150,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rabies');
-- NPC talk text insert
SET @ENTRY := 43704;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage');

-- Eliza <Bride of the Embalmer>
SET @ENTRY := 45801;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,1,0,61,0,100,1,0,0,0,0,11,3107,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Eliza\'s Guard on Aggro'),
(@ENTRY,0,2,0,2,0,100,1,0,50,0,0,11,3107,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Eliza\'s Guard at 50% HP'),
(@ENTRY,0,3,0,0,0,100,0,2500,4500,20500,22000,11,81767,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lantern Blaze'),
(@ENTRY,0,4,0,0,0,100,0,8000,12000,15000,18000,11,81764,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw Lantern');
-- NPC talk text insert
SET @ENTRY := 45801;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Eliza isss pretty... sssso pretty...',12,0,100,0,0,0, 'on Aggro Text');

-- Fenros
SET @ENTRY := 507;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,7137,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Charge on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,2000,3000,9000,12000,11,6595,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Exploit Weakness'),
(@ENTRY,0,2,0,0,0,100,0,6000,9000,19000,22000,11,84308,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Furious Howl');

-- Fetid Corpse
SET @ENTRY := 1270;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,16000,18000,11,85234,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fetid Breath'),
(@ENTRY,0,1,0,0,0,100,0,2000,8000,22000,26000,11,7102,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Contagion of Rot'),
(@ENTRY,0,2,0,1,0,100,1,0,0,0,0,11,26047,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Birth on Spawn');

-- Flesh Eater
SET @ENTRY := 3;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,11,26047,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Birth on Spawn');

-- Forlorn Spirit
SET @ENTRY := 43923;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,15000,21000,11,81193,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Unrelenting Anguish');

-- Grave Robber
SET @ENTRY := 218;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,2,0,0,0,100,0,2000,3000,9000,12000,11,6595,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Exploit Weakness');
-- NPC talk text insert
SET @ENTRY := 218;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Insane Ghoul
SET @ENTRY := 511;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,9000,22000,26000,11,83586,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Insane Rambling'),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,11,85236,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Corpse Rot on Death'),
(@ENTRY,0,2,0,1,0,100,1,0,0,0,0,11,26047,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Birth on Spawn');

-- Lupos
SET @ENTRY := 521;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,75002,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Leaping Rush on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,3000,6000,22000,26000,11,3150,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rabies');

-- Marina DeSirrus <Thief of the Dead>
SET @ENTRY := 45811;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,2000,3000,9000,12000,11,6595,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Exploit Weakness'),
(@ENTRY,0,2,0,0,0,100,0,5000,7000,16000,22000,11,78509,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Torch Toss');
-- NPC talk text insert
SET @ENTRY := 45811;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Adventurers are such hypocrites! Like YOU just FOUND your weapons on the side of the road!',12,0,100,0,0,0, 'on Aggro Text');

-- Marus <The Pack Leader>
SET @ENTRY := 45771;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,81173,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP'),
(@ENTRY,0,2,0,2,0,100,0,0,40,16000,21000,11,79853,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Evasion at 40% HP'),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,11,80576,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadowstep at 30% HP');
-- NPC talk text insert
SET @ENTRY := 45771;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy');

-- Morbent Fel
SET @ENTRY := 43761;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,55,22000,26000,11,3108,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Touch of Death at 55% HP'),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,18000,20000,11,3109,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Presence of Death'),
(@ENTRY,0,2,0,11,0,100,1,0,0,0,0,11,8909,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Unholy Shield on Spawn');

-- Morbidius <The Tomb Guardian>
SET @ENTRY := 45619;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,12000,14500,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike on Close');

-- Mor'Ladim
SET @ENTRY := 522;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,6000,12000,15000,11,79961,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Holy Shock'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,3547,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enraging Memories at 30% HP');

-- Naraxis
SET @ENTRY := 574;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4500,15000,17000,11,13884,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Withering Poison'),
(@ENTRY,0,1,0,2,0,100,0,0,40,15000,21000,11,87080,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Vanish at 40% HP'),
(@ENTRY,0,2,0,9,0,100,0,0,30,8000,9000,11,12023,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Web on Close');

-- Nefaru <The Den Mother>
SET @ENTRY := 534;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,15000,17000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Tendon Rip'),
(@ENTRY,0,1,0,0,0,100,0,6000,11000,25000,28000,11,3427,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Infected Wound'),
(@ENTRY,0,2,0,0,0,100,0,12000,15000,33000,36000,11,8715,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Terrifying Howl');

-- Night Watch Guard <The Night Watch>
SET @ENTRY := 10038;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot');

-- Nightbane Dark Runner
SET @ENTRY := 205;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,7137,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Charge on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,2000,3000,9000,12000,11,6595,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Exploit Weakness');

-- Nightbane Shadow Weaver
SET @ENTRY := 533;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,77721,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Weave'),
(@ENTRY,0,10,0,2,1,100,1,0,45,0,0,11,85072,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Woven Shadows at 45% HP');

-- Nightbane Stalker
SET @ENTRY := 44087;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,75002,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Leaping Rush on Aggro'),
(@ENTRY,0,1,0,11,0,100,1,0,0,0,0,11,77806,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Spawn'),
(@ENTRY,0,2,0,7,0,100,1,0,0,0,0,11,77806,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Evade'),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,11,80576,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadowstep at 30% HP');

-- Nightbane Tainted One
SET @ENTRY := 920;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,9000,60000,65000,11,85244,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Worgen Taint');

-- Nightbane Vile Fang
SET @ENTRY := 206;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,11000,25000,28000,11,3427,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Infected Wound'),
(@ENTRY,0,1,0,0,0,100,0,4000,5000,22000,22500,11,84308,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Furious Howl');

-- Nightbane Worgen
SET @ENTRY := 898;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,75002,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Leaping Rush on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,4000,5000,22000,22500,11,84308,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Furious Howl');

-- Plague Spreader
SET @ENTRY := 604;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,33000,36000,11,3436,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wandering Plague'),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,11,85236,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Corpse Rot on Death'),
(@ENTRY,0,2,0,1,0,100,1,0,0,0,0,11,26047,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Birth on Spawn');

-- Rotted One
SET @ENTRY := 948;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,11,26047,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Birth on Spawn'),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,11,3428,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Flesh Eating Worms on Death'),
(@ENTRY,0,2,0,0,0,100,0,4000,7000,16000,18000,11,85234,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fetid Breath');

-- Rotting Horror
SET @ENTRY := 202;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,7000,16000,21000,11,7102,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Contagion of Rot'),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,11,85236,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Corpse Rot on Death');

-- Silent Shade
SET @ENTRY := 44028;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,14000,11,82717,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Vanish'),
(@ENTRY,0,1,0,2,0,100,0,0,40,17000,21000,11,78826,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Evasion at 40% HP');

-- Sister Elsington
SET @ENTRY := 43731;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,1800000,1800000,11,48168,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Inner Fire on Spawn');

-- Skeletal Mage
SET @ENTRY := 203;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9672,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frostbolt'),
(@ENTRY,0,1,0,1,0,100,0,500,1000,1800000,1800000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Armor on Spawn');

-- Skeletal Warrior
SET @ENTRY := 48;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,15000,16000,11,85240,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sundering Cleave on Close');

-- Splinter Fist Firemonger
SET @ENTRY := 1251;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,20,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,5000,7000,16000,22000,11,78509,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Torch Toss'),
(@ENTRY,0,2,0,0,0,100,0,3000,3500,12000,13000,11,13878,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Scorch');
-- NPC talk text insert
SET @ENTRY := 1251;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'I\'ll crush you!',12,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,0,1, 'Me smash! You die!',12,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,0,2, 'Raaar!!! Me smash $r!',12,0,50,0,0,0, 'on Aggro Text');

-- Splinter Fist Ogre
SET @ENTRY := 889;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,20,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,2000,4000,12000,18000,11,80182,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Uppercut');
-- NPC talk text insert
SET @ENTRY := 889;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'I\'ll crush you!',12,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,0,1, 'Me smash! You die!',12,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,0,2, 'Raaar!!! Me smash $r!',12,0,50,0,0,0, 'on Aggro Text');

-- Splinter Fist Warrior
SET @ENTRY := 212;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,20,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,17000,24000,11,78828,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bladestorm');
-- NPC talk text insert
SET @ENTRY := 212;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'I\'ll crush you!',12,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,0,1, 'Me smash! You die!',12,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,0,2, 'Raaar!!! Me smash $r!',12,0,50,0,0,0, 'on Aggro Text');

-- Stalvan Mistmantle
SET @ENTRY := 315;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,16000,18000,11,85234,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fetid Breath'),
(@ENTRY,0,1,0,0,0,100,0,2000,3000,65000,68000,11,3105,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Curse of Stalvan');

-- Stitches <Gift from the Embalmer>
SET @ENTRY := 43862;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,3106,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Aura of Rot on Spawn');

-- The Unknown Soldier
SET @ENTRY := 45739;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP'),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,11,80983,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Commanding Shout on Aggro'),
(@ENTRY,0,3,0,9,0,100,0,0,5,14000,15000,11,85240,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sundering Cleave on Close');
-- NPC talk text insert
SET @ENTRY := 45739;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage');

-- Zzarc' Vul
SET @ENTRY := 300;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,20,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,17000,24000,11,78828,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bladestorm'),
(@ENTRY,0,2,0,0,0,100,0,2000,4000,12000,18000,11,80182,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Uppercut'),
(@ENTRY,0,3,0,9,0,100,0,0,5,22000,22000,11,8716,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Low Swipe on Close'),
(@ENTRY,0,4,0,0,0,100,0,12000,15000,8000,25000,11,5164,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Knockdown');
-- NPC talk text insert
SET @ENTRY := 300;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'I\'ll crush you!',12,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,0,1, 'Me smash! You die!',12,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,0,2, 'Raaar!!! Me smash $r!',12,0,50,0,0,0, 'on Aggro Text');
