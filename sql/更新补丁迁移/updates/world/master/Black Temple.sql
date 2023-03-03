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
 
-- Angered Soul Fragment
SET @ENTRY := 23398;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,1000,7000,11000,11,41986,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Anger');

-- Aqueous Lord
SET @ENTRY := 22878;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,9000,15000,12000,18000,11,40099,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Vile Slime'),
(@ENTRY,0,1,0,0,0,100,2,7000,11000,9000,13000,11,40100,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crashing Wave'),
(@ENTRY,0,2,0,0,0,100,2,14000,18000,30000,45000,12,22883,1,60000,0,0,0,1,0,0,0,0,0,0,0,'Summon Aqueous Spawn');

-- Aqueous Spawn
SET @ENTRY := 22883;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,30,16000,21000,11,40102,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sludge Nova on Close'),
(@ENTRY,0,1,0,0,0,100,3,60000,60000,0,0,11,40106,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Merge'),
(@ENTRY,0,2,0,2,0,100,3,0,30,0,0,11,40105,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Infusion at 30% HP');

-- Aqueous Surger
SET @ENTRY := 22881;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,55,13000,18000,11,40095,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Poison Bolt Volley on Close');

-- Ashtongue Battlelord
SET @ENTRY := 22844;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,10,40,9000,12000,11,41182,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Concussive Throw on Close'),
(@ENTRY,0,1,0,9,0,100,2,0,10,12000,15000,11,32588,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Concussion Blow on Close'),
(@ENTRY,0,2,0,9,0,100,2,0,5,5000,8000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave on Close'),
(@ENTRY,0,3,1,2,0,100,3,0,30,0,0,11,34970,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP'),
(@ENTRY,0,4,0,61,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP');
-- NPC talk text insert
SET @ENTRY := 22844;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy');

-- Ashtongue Defender
SET @ENTRY := 23216;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,6000,11000,11,41178,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Debilitating Strike on Close'),
(@ENTRY,0,1,0,0,0,100,2,11000,16000,13000,17000,11,41975,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Strike'),
(@ENTRY,0,2,0,13,0,100,2,5000,10000,20000,30000,11,41180,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Shield Bash on Player Spell Cast');

-- Ashtongue Elementalist
SET @ENTRY := 23523;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,42024,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lightning Bolt'),
(@ENTRY,0,1,0,0,0,100,2,12000,18000,16000,21000,11,42023,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Rain of Fire');

-- Ashtongue Feral Spirit
SET @ENTRY := 22849;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,12000,19000,33000,38000,11,39575,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Charge Rage'),
(@ENTRY,0,1,0,2,0,100,2,0,50,30000,40000,11,39578,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spirit Bond at 50% HP');

-- Ashtongue Mystic
SET @ENTRY := 22845;
SET @ENTRYTOTEM := 22896;
SET @ENTRYTOTEM2 := 22897;
SET @TOTEMSPELL := 39593;
SET @TOTEMSPELL2 := 32911;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
UPDATE `creature_template` SET `AIName`='0' WHERE `entry`=@ENTRYTOTEM;
UPDATE `creature_template` SET `spell1`=@TOTEMSPELL WHERE `entry`=@ENTRYTOTEM;
UPDATE `creature_template` SET `AIName`='0' WHERE `entry`=@ENTRYTOTEM2;
UPDATE `creature_template` SET `spell1`=@TOTEMSPELL2 WHERE `entry`=@ENTRYTOTEM2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,7000,75000,90000,11,39589,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Cyclone Totem'),
(@ENTRY,0,1,0,0,0,100,2,11000,16000,40000,60000,11,39588,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Searing Totem'),
(@ENTRY,0,2,0,0,0,100,2,18000,23000,100000,115000,11,39586,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Windfury Totem'),
(@ENTRY,0,3,0,9,0,50,2,0,20,25000,25000,11,41115,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Shock on Close'),
(@ENTRY,0,4,0,9,0,50,2,0,20,25000,25000,11,41116,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frost Shock on Close'),
(@ENTRY,0,5,0,0,0,100,2,9000,12000,26000,32000,11,41185,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bloodlust'),
(@ENTRY,0,6,0,14,0,100,2,50000,40,14000,19000,11,41114,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Chain Heal on Friendlies');

-- Ashtongue Primalist
SET @ENTRY := 22847;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,41188,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,2,9000,13000,12000,16000,11,41187,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Multi-Shot'),
(@ENTRY,0,2,0,9,0,100,2,0,5,5000,8000,11,39584,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Sweeping Wing Clip on Close'),
(@ENTRY,0,3,0,0,0,100,2,15000,15000,19000,22000,11,41186,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Wyvern Sting');

-- Ashtongue Rogue
SET @ENTRY := 23318;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,42459,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dual Wield on Aggro'),
(@ENTRY,0,1,0,9,0,100,2,0,5,11000,14000,11,41978,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Debilitating Poison on Close'),
(@ENTRY,0,2,0,12,0,100,2,0,15,11000,15000,11,41177,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Eviscerate when Target is 15% HP');

-- Ashtongue Spiritbinder
SET @ENTRY := 23524;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,14,0,100,2,10000,40,12000,16000,11,42025,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Spirit Mend on Friendlies'),
(@ENTRY,0,1,0,14,0,100,2,15000,40,18000,24000,11,42027,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Chain Heal on Friendlies'),
(@ENTRY,0,2,0,14,0,100,2,18000,40,21000,30000,11,42318,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Spirit Heal on Friendlies');

-- Ashtongue Stalker
SET @ENTRY := 23374;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,34189,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Spawn'),
(@ENTRY,0,1,0,7,0,100,3,0,0,0,0,11,34189,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Evade'),
(@ENTRY,0,2,0,9,0,100,2,0,40,8000,12000,11,41190,0,0,0,0,0,4,32,0,0,0,0,0,0,'Cast Mind-numbing Poison on Close'),
(@ENTRY,0,3,0,9,0,100,2,0,10,7000,11000,11,41189,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Instant Poison on Close'),
(@ENTRY,0,4,0,9,0,100,2,0,10,11000,15000,11,34654,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Blind on Close');

-- Ashtongue Stormcaller
SET @ENTRY := 22846;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,41184,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lightning Bolt'),
(@ENTRY,0,1,0,1,0,100,2,500,1000,600000,600000,11,41151,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lightning Shield on Spawn'),
(@ENTRY,0,2,0,16,0,100,2,41151,1,15000,30000,11,41151,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lightning Shield on Repeat'),
(@ENTRY,0,3,0,0,0,100,2,12000,18000,22000,28000,11,41183,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Chain Lightning');

-- Bonechewer Behemoth
SET @ENTRY := 23196;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,41272,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Behemoth Charge on Aggro'),
(@ENTRY,0,1,0,9,0,100,2,10,40,7000,11000,11,41277,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Fiery Comet on Close'),
(@ENTRY,0,2,0,0,0,100,2,9000,15000,23000,30000,11,41276,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Meteor'),
(@ENTRY,0,3,0,0,0,100,2,7000,12000,12000,15000,11,41274,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fel Stomp'),
(@ENTRY,0,4,1,2,0,100,3,0,30,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP'),
(@ENTRY,0,5,0,61,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP');
-- NPC talk text insert
SET @ENTRY := 23196;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy');

-- Bonechewer Blade Fury
SET @ENTRY := 23235;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,14000,17000,11,41194,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirlwind on Close');

-- Bonechewer Blood Prophet
SET @ENTRY := 23237;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,3,0,30,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP'),
(@ENTRY,0,1,0,61,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP'),
(@ENTRY,0,2,0,9,0,100,2,0,20,20000,24000,11,41230,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Prophecy of Blood on Close'),
(@ENTRY,0,3,0,9,0,100,2,0,40,7000,10000,11,41229,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Bloodbolt on Close'),
(@ENTRY,0,4,0,2,0,100,2,0,50,12000,16000,11,41238,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blood Drain at 50% HP');
-- NPC talk text insert
SET @ENTRY := 23237;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy');

-- Bonechewer Brawler
SET @ENTRY := 23222;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,3,0,30,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP'),
(@ENTRY,0,1,0,61,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP'),
(@ENTRY,0,2,0,0,0,100,2,7000,14000,21000,28000,11,41254,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage');
-- NPC talk text insert
SET @ENTRY := 23222;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy');

-- Bonechewer Combatant
SET @ENTRY := 23239;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,3,0,30,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP'),
(@ENTRY,0,1,0,61,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP'),
(@ENTRY,0,2,0,0,0,100,2,15000,30000,30000,45000,11,41251,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Combat Rage');
-- NPC talk text insert
SET @ENTRY := 23239;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy');

-- Bonechewer Shield Disciple
SET @ENTRY := 23236;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,5,45,8000,13000,11,41213,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw Shield on Close'),
(@ENTRY,0,1,0,9,0,100,2,8,25,18000,25000,11,41198,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Intervene on Close'),
(@ENTRY,0,2,0,9,0,100,2,0,5,9000,15000,11,41197,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Bash on Close'),
(@ENTRY,0,3,0,2,0,100,2,0,50,22000,30000,11,41196,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shield Wall at 50% HP');

-- Bonechewer Spectator
SET @ENTRY := 23223;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,3,0,30,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP'),
(@ENTRY,0,1,0,61,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP'),
(@ENTRY,0,2,0,9,0,100,2,0,5,5000,9000,11,13444,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sunder Armor on Close'),
(@ENTRY,0,3,0,4,0,100,3,0,0,0,0,11,36140,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,4,0,0,0,100,2,3000,6000,5000,8000,11,25646,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Mortal Wound'),
(@ENTRY,0,5,0,0,0,100,2,6000,11000,12000,18000,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,6,0,0,0,100,2,12000,15000,9000,12000,11,13446,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Strike');
-- NPC talk text insert
SET @ENTRY := 23223;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy');

-- Bonechewer Taskmaster
SET @ENTRY := 23028;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,3,5000,9000,0,0,11,40851,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Disgruntled'),
(@ENTRY,0,1,0,2,0,100,3,0,30,0,0,11,40845,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fury at 30% HP');

-- Bonechewer Worker
SET @ENTRY := 22963;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,40844,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw Pick'),
(@ENTRY,0,1,0,0,0,100,2,8000,12000,18000,22000,11,40864,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Throbbing Stun');

-- Charming Courtesan
SET @ENTRY := 22955;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,60,9000,14000,11,41346,0,0,0,0,0,4,32,0,0,0,0,0,0,'Cast Poisonous Throw on Close'),
(@ENTRY,0,1,0,0,0,100,2,7000,13000,25000,32000,11,41345,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Infatuation');

-- Coilskar General
SET @ENTRY := 22873;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,42459,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dual Wield on Aggro'),
(@ENTRY,0,1,0,0,0,100,2,1000,3000,40000,48000,11,40080,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Booming Voice'),
(@ENTRY,0,2,0,0,0,100,2,16000,30000,24000,35000,11,40081,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Free Friend');

-- Coilskar Harpooner
SET @ENTRY := 22874;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,40083,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Spear Throw'),
(@ENTRY,0,1,0,9,0,100,2,0,30,7000,9000,11,40082,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hooked Net on Close'),
(@ENTRY,0,2,0,61,0,100,3,0,0,0,0,11,40084,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Harpooner\'s Mark on Aggro');

-- Coilskar Sea-Caller
SET @ENTRY := 22875;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,30,12000,16000,11,40088,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Forked Lightning on Close'),
(@ENTRY,0,1,0,0,0,100,2,30000,45000,40000,50000,11,40090,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Hurricane'),
(@ENTRY,0,2,0,0,0,100,2,8000,12000,14000,19000,11,40091,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Summon Geyser');

-- Coilskar Soothsayer
SET @ENTRY := 22876;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,15,21000,26000,11,40096,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Holy Nova on Close'),
(@ENTRY,0,1,0,14,0,100,2,40000,40,28000,37000,11,40097,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Restoration on Friendlies');

-- Coilskar Wrangler
SET @ENTRY := 22877;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,7000,11000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave on Close'),
(@ENTRY,0,1,0,0,0,100,2,18000,27000,28000,35000,11,40066,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Lightning Prod'),
(@ENTRY,0,2,0,16,0,100,2,40076,40,25000,40000,11,40076,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Electric Spur on Friendlies Missing Buff');

-- Dragon Turtle <Coilskar Harpooner's Pet>
SET @ENTRY := 22885;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,45,4000,6000,11,40086,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Water Spit on Close'),
(@ENTRY,0,1,0,2,0,100,2,0,50,30000,40000,11,40087,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shell Shield at 50% HP');

-- Dragonmaw Sky Stalker
SET @ENTRY := 23030;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,40873,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,2,7000,11000,12000,16000,11,40872,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Immolation Arrow'),
(@ENTRY,0,2,0,6,0,100,3,0,0,0,0,43,0,0,0,0,0,0,4,0,0,0,0,0,0,0,'Dismount on Death'),
(@ENTRY,0,3,0,61,0,100,3,0,0,0,0,19,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0,'Remove Unit Flag on Aggro');

-- Dragonmaw Wind Reaver
SET @ENTRY := 23330;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,40877,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball'),
(@ENTRY,0,1,0,0,0,100,2,9000,14000,12000,16000,11,40876,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Doom Bolt'),
(@ENTRY,0,2,0,0,0,100,2,14000,18000,16000,21000,11,40875,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Freeze');

-- Dragonmaw Wyrmcaller
SET @ENTRY := 22960;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,7000,12000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave on Close'),
(@ENTRY,0,1,0,0,0,100,2,4000,9000,9000,14000,11,40895,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Jab'),
(@ENTRY,0,2,0,0,0,100,2,8000,15000,16000,21000,11,40892,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Fixate');

-- Enslaved Servant
SET @ENTRY := 22965;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,11000,17000,11,41389,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Kidney Shot on Close'),
(@ENTRY,0,1,0,0,0,100,2,6000,9000,11000,15000,11,41388,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Uppercut');

-- Hand of Gorefiend
SET @ENTRY := 23172;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,3,0,30,0,0,11,38166,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,1,0,61,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP');
-- NPC talk text insert
SET @ENTRY := 23172;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage');

-- Hungering Soul Fragment
SET @ENTRY := 23401;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,41248,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Consuming Strikes on Spawn');

-- Illidari Archon
SET @ENTRY := 23400;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,41370,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Holy Smite'),
(@ENTRY,0,1,0,9,0,100,2,0,30,11000,16000,11,41374,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mind Blast on Close'),
(@ENTRY,0,2,0,0,0,100,2,20000,35000,50000,70000,11,41373,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Power Word: Shield'),
(@ENTRY,0,3,0,14,0,100,2,75000,40,25000,31000,11,41372,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Heal on Friendlies'),
(@ENTRY,0,4,0,2,0,100,2,0,15,9000,13000,11,41375,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Word: Death at 15% HP'),
(@ENTRY,0,5,0,11,0,50,3,0,0,0,0,11,29406,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadowform on Spawn');

-- Illidari Assassin
SET @ENTRY := 23403;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,42459,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dual Wield on Aggro'),
(@ENTRY,0,1,0,9,0,100,2,0,5,11000,15000,11,3609,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Paralyzing Poison on Close'),
(@ENTRY,0,2,0,0,0,100,2,9000,15000,9000,12000,11,39667,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Vanish');

-- Illidari Battle-mage
SET @ENTRY := 23402;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,41383,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball'),
(@ENTRY,0,1,0,0,0,100,2,9000,13000,17000,23000,11,41379,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Flamestrike'),
(@ENTRY,0,2,0,9,0,100,2,0,40,4000,6000,11,41384,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frostbolt'),
(@ENTRY,0,3,0,0,0,100,2,12000,16000,14000,18000,11,41382,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Blizzard');

-- Illidari Blood Lord
SET @ENTRY := 23397;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,10,15000,21000,11,13005,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hammer of Justice on Close'),
(@ENTRY,0,1,0,0,0,100,2,7000,12000,9000,13000,11,41368,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Judgment of Command'),
(@ENTRY,0,2,0,2,0,100,2,0,50,45000,70000,11,41367,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Divine Shield at 50% HP');

-- Illidari Boneslicer
SET @ENTRY := 22869;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,42459,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dual Wield on Aggro'),
(@ENTRY,0,1,0,9,0,100,2,0,5,9000,13000,11,24698,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gouge on Close'),
(@ENTRY,0,2,0,0,0,100,2,18000,25000,25000,38000,11,41176,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Shadowstep'),
(@ENTRY,0,3,0,0,0,100,2,12000,16000,18000,23000,11,39666,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Cloak of Shadows'),
(@ENTRY,0,4,0,0,0,100,2,2000,4500,12000,20000,11,39665,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wound Poison');

-- Illidari Centurion
SET @ENTRY := 23337;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,7000,11000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave on Close'),
(@ENTRY,0,1,0,0,0,100,2,13000,16000,17000,21000,11,41168,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sonic Strike');

-- Illidari Defiler
SET @ENTRY := 22853;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,30,23000,30000,11,39670,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Immolate on Close'),
(@ENTRY,0,1,0,0,0,100,2,15000,21000,26000,32000,11,39671,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Rain of Chaos'),
(@ENTRY,0,2,0,0,0,100,2,25000,25000,30000,38000,11,39672,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Curse of Agony'),
(@ENTRY,0,3,0,0,0,100,2,12000,18000,21000,28000,11,39674,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Banish');

-- Illidari Fearbringer
SET @ENTRY := 22954;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,9000,14000,21000,26000,11,40936,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast War Stomp'),
(@ENTRY,0,1,0,0,0,100,2,12000,19000,15000,20000,11,40938,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Illidari Flames'),
(@ENTRY,0,2,0,0,0,100,2,8000,14000,19000,24000,11,40946,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Rain of Chaos');

-- Illidari Heartseeker
SET @ENTRY := 23339;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,41169,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,2,7000,11000,19000,25000,11,41173,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rapid Shot'),
(@ENTRY,0,2,0,0,0,100,2,45000,60000,60000,75000,11,41171,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Skeleton Shot'),
(@ENTRY,0,3,0,2,0,100,3,0,50,0,0,11,41170,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Curse of the Bleakheart at 50% HP');

-- Illidari Nightlord
SET @ENTRY := 22855;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,10,14000,21000,11,41150,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Fear on Close'),
(@ENTRY,0,1,0,0,0,100,2,17000,28000,21000,26000,11,39645,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Inferno'),
(@ENTRY,0,2,0,0,0,100,2,9000,15000,12000,15000,11,39647,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Curse of Mending'),
(@ENTRY,0,3,0,0,0,100,2,7000,12000,30000,45000,11,39649,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Shadowfiends');

-- Image of Dementia
SET @ENTRY := 23436;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,41,20000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Despawn on Aggro'),
(@ENTRY,0,1,0,0,0,100,2,1000,1000,15000,15000,11,41399,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirlwind');

-- Leviathan
SET @ENTRY := 22884;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,30,4000,7000,11,40078,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Poison Spit on Close'),
(@ENTRY,0,1,0,9,0,100,2,0,45,7000,13000,11,40079,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Debilitating Spray on Close'),
(@ENTRY,0,2,0,0,0,100,2,9000,14000,12000,15000,11,40077,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Tail Sweep');

-- Mutant War Hound
SET @ENTRY := 23232;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,41290,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Disease Cloud on Spawn'),
(@ENTRY,0,1,0,6,0,100,3,0,0,0,0,11,41193,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Cloud of Disease on Death');

-- Priestess of Delight
SET @ENTRY := 22962;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,9000,16000,25000,11,41351,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Curse of Vitality');

-- Priestess of Dementia
SET @ENTRY := 22957;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,8000,12000,18000,11,41397,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Confusion'),
(@ENTRY,0,1,0,0,0,100,2,10000,14000,35000,45000,11,41404,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Dementia');

-- Promenade Sentinel
SET @ENTRY := 23394;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,9000,7000,10000,11,41360,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast L5 Arcane Charge'); 

-- Shadowmoon Blood Mage
SET @ENTRY := 22945;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,41072,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bloodbolt'),
(@ENTRY,0,1,0,0,0,100,2,12000,16000,14000,18000,11,41068,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blood Siphon');

-- Shadowmoon Champion
SET @ENTRY := 22880;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,12000,20000,30000,38000,11,41053,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Whirling Blade'),
(@ENTRY,0,1,0,0,0,100,2,7000,15000,14000,21000,11,41063,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chaotic Light');

-- Shadowmoon Deathshaper
SET @ENTRY := 22882;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,41069,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,1,0,1,0,100,2,500,1000,1800000,1800000,11,13787,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demon Armor on Spawn'),
(@ENTRY,0,2,0,5,0,100,2,15000,15000,1,0,11,41071,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Raise Dead on Creature Death'),
(@ENTRY,0,3,0,0,0,100,2,8000,15000,12000,17000,11,41070,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Death Coil');

-- Shadowmoon Houndmaster
SET @ENTRY := 23018;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,41093,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,11,0,100,3,0,0,0,0,11,39906,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Riding Warhound on Spawn'),
(@ENTRY,0,2,0,0,0,100,2,8000,12000,9000,16000,11,41084,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Silencing Shot'),
(@ENTRY,0,3,0,9,0,100,2,0,5,7000,12000,11,32908,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wing Clip on Close'),
(@ENTRY,0,4,0,0,0,100,2,16000,21000,25000,31000,11,41091,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Volley'),
(@ENTRY,0,5,0,0,0,100,2,5000,8000,25000,35000,11,41085,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Freezing Trap');

-- Shadowmoon Reaver
SET @ENTRY := 22879;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,11000,20000,24000,11,41034,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spell Absorption');

-- Shadowmoon Riding Hound
SET @ENTRY := 23083;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,3,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,1,0,61,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP'),
(@ENTRY,0,2,0,4,0,100,3,0,0,0,0,11,25821,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,3,0,0,0,100,2,2000,4500,12000,20000,11,41092,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Carnivorous Bite');
-- NPC talk text insert
SET @ENTRY := 23083;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage');

-- Shadowmoon Soldier
SET @ENTRY := 23047;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,5000,9000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike on Close');

-- Shadowmoon Weapon Master
SET @ENTRY := 23049;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,3,0,0,0,0,11,41106,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Battle Aura on Spawn'),
(@ENTRY,0,1,2,61,0,100,3,0,0,0,0,11,41099,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Battle Stance on Spawn'),
(@ENTRY,0,2,0,61,0,100,3,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 1 on Spawn'),
(@ENTRY,0,3,0,9,1,100,2,0,5,8000,11000,11,41103,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mutilate on Close'),
(@ENTRY,0,4,5,2,1,100,3,0,65,0,0,11,41105,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Defensive Aura at 65% HP'),
(@ENTRY,0,5,6,61,1,100,3,0,0,0,0,11,41101,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Defensive Stance at 65% HP'),
(@ENTRY,0,6,0,61,1,100,3,0,0,0,0,23,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 2 at 65% HP'),
(@ENTRY,0,7,0,0,2,100,2,7000,16000,21000,30000,11,41104,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shield Wall'),
(@ENTRY,0,8,9,2,2,100,3,0,35,0,0,11,41107,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Berserker Aura at 35% HP'),
(@ENTRY,0,9,10,61,2,100,3,0,0,0,0,11,41100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Berserker Stance at 35% HP'),
(@ENTRY,0,10,11,61,2,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 35% HP'),
(@ENTRY,0,11,0,61,2,100,3,0,0,0,0,23,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 3 at 35% HP'),
(@ENTRY,0,12,0,0,3,100,2,12000,15000,18000,23000,11,41097,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirlwind'),
(@ENTRY,0,13,0,0,3,100,2,15000,19000,25000,26000,11,18813,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Knock Away');
-- NPC talk text insert
SET @ENTRY := 23049;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Berserker stance! Attack them recklessly!',12,0,100,0,0,0, 'on Stance Change Text');

-- Shadowy Construct
SET @ENTRY := 23111;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,5000,9000,11,40327,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Atrophy on Close');

-- Sister of Pain
SET @ENTRY := 22956;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,41362,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shared Bonds on Spawn'),
(@ENTRY,0,1,0,9,0,100,2,0,60,21000,26000,11,41355,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Shadow Word: Pain on Close'),
(@ENTRY,0,2,0,9,0,100,2,0,5,7000,12000,11,41353,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Lash of Pain on Close'),
(@ENTRY,0,3,0,0,0,100,2,12000,16000,18000,24000,11,41369,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Painful Rage'),
(@ENTRY,0,4,0,0,0,100,2,21000,30000,35000,50000,11,41371,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shell of Pain');

-- Sister of Pleasure
SET @ENTRY := 22964;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,41362,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shared Bonds on Spawn'),
(@ENTRY,0,1,0,9,0,100,2,0,8,11000,17000,11,41380,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Holy Nova on Close'),
(@ENTRY,0,2,0,14,0,100,2,100000,40,21000,27000,11,41378,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Greater Heal on Friendlies'),
(@ENTRY,0,3,0,2,0,100,2,0,20,30000,45000,11,41381,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shell of Life at 20% HP');

-- Spellbound Attendant
SET @ENTRY := 22959;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,11000,17000,11,41395,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Kick on Close'),
(@ENTRY,0,1,0,0,0,100,2,5000,9000,12000,16000,11,41396,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Sleep');

-- Storm Fury
SET @ENTRY := 22848;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,9000,16000,21000,11,39581,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Storm Blink'),
(@ENTRY,0,1,0,0,0,100,2,11000,12000,15000,20000,11,39580,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Lightning Cloud');

-- Suffering Soul Fragment
SET @ENTRY := 23399;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,20,7000,10000,11,41245,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Soul Blast on Close');

-- Temple Concubine
SET @ENTRY := 22939;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,10,8000,14000,11,41338,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Love Tap on Close'),
(@ENTRY,0,1,0,0,0,100,2,7000,11000,20000,28000,11,41334,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Polymorph');

-- Wrathbone Flayer
SET @ENTRY := 22953;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,7000,9000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave on Close'),
(@ENTRY,0,1,0,0,0,100,2,10000,13000,16000,21000,11,39544,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Ignored');

