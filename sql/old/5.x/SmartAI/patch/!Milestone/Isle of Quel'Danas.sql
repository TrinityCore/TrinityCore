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
 
 -- Abyssal Flamewalker
 SET @ENTRY := 25001;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,8000,12000,11,12744,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Immolation'),
(@ENTRY,0,1,0,0,0,100,0,5500,7800,15600,17800,11,12744,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Abyssal Meteor Fall');

-- Crypt Raider
SET @ENTRY := 37541;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,31600,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Crypt Scarabs');

-- Darkspine Myrmidon
SET @ENTRY := 25060;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,15000,19000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demoralizing Shout'),
(@ENTRY,0,1,0,0,0,100,0,5700,9500,12300,18300,11,11971,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sunder Armor');

-- Darkspine Siren
SET @ENTRY := 25073;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9672,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,2,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,1,0,100,0,500,1000,600000,600000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Armor on Spawn'),
(@ENTRY,0,4,0,0,0,100,0,4000,7000,15000,19000,11,38033,0,0,0,0,0,0,0,0,0,0,0,0,0,'Cast Frost Nova'),
(@ENTRY,0,5,0,0,0,100,0,10000,10000,17000,22000,11,3589,0,0,0,0,0,0,0,0,0,0,0,0,0,'Cast Deafening Screech');
-- NPC talk text insert
SET @ENTRY := 25073;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Dawnblade Blood Knight
SET @ENTRY := 24976;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,45105,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Joust'),
(@ENTRY,0,1,0,14,0,100,0,4000,40,5000,12000,11,13952,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Holy Light on Friendlies'),
(@ENTRY,0,2,0,0,0,100,0,8000,18000,25500,35400,11,45337,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Judgement of Wrath'),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,11,13952,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Holy Light at 30% HP'),
(@ENTRY,0,4,0,0,0,100,0,5000,8900,34500,45600,11,45095,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Judgement of Wrath');

-- Dawnblade Hawkrider
SET @ENTRY := 25063;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,0,0,70,3000,6500,11,45189,0,0,0,0,0,6,0,0,0,0,0,0,0,'Cast Dawnblade Attack');

-- Dawnblade Marksman
SET @ENTRY := 24979;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,10,0,100,0,0,70,7000,13000,11,45101,0,0,0,0,0,6,0,0,0,0,0,0,0,'Cast Flaming Arrow'),
(@ENTRY,0,2,0,9,0,100,0,5,30,13400,17800,11,37847,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Immolation Arrow');

-- Dawnblade Reservist
SET @ENTRY := 25087;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,7700,13500,17850,11,32915,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Raptor Strike');

-- Dawnblade Summoner
SET @ENTRY := 24978;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,32707,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,2,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,1,0,100,1,3000,5000,0,0,11,11939,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Imp on Spawn'),
(@ENTRY,0,4,0,1,0,100,0,500,1000,600000,600000,11,44977,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fel Armor on Spawn'),
(@ENTRY,0,5,0,0,0,100,0,3300,11600,17000,21700,11,11962,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Immolate');
-- NPC talk text insert
SET @ENTRY := 24978;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');
-- Imp
SET @ENTRY := 12922;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,20801,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball');

-- Emissary of Hate
SET @ENTRY := 25003;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,5000,14800,19700,11,12054,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rend'),
(@ENTRY,0,1,0,0,0,100,0,8900,12300,9800,25600,11,38611,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Wave');

-- Eredar Sorcerer
SET @ENTRY := 25033;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,20000,11,45046,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flames of Doom');

-- Erratic Sentry
SET @ENTRY := 24972;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,12000,18000,15000,25000,11,45336,0,0,0,0,0,1,1,0,0,0,0,0,0,'Cast Electrical Overload'),
(@ENTRY,0,1,0,0,0,100,0,5500,6700,11200,16700,11,33688,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crystal Strike'),
(@ENTRY,0,2,0,0,0,100,0,8000,12000,8000,12000,11,35892,0,0,0,0,0,1,1,0,0,0,0,0,0,'Cast Suppression'),
(@ENTRY,0,3,0,2,0,40,1,0,50,0,0,11,45014,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Capacitor Overload at 50% HP'),
(@ENTRY,0,4,0,2,0,40,1,0,50,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Text and Emote at 50% HP');
-- NPC talk text insert
SET @ENTRY := 24972;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Core overload detected. System malfunction detected...',12,2,100,0,0,0, 'combat Text');

-- Ghoul Invader
SET @ENTRY := 37539;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,5700,12000,17500,11,38056,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flesh Rip');

-- Irespeaker
SET @ENTRY := 24999;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,35913,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt');

-- Pit Overlord
SET @ENTRY := 25031;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3300,11300,8900,14500,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,1,0,0,0,100,0,5000,7000,12000,15000,11,32709,0,0,0,0,0,5,1,0,0,0,0,0,0,'Cast Death Coil'),
(@ENTRY,0,2,0,0,0,100,0,7500,13000,15000,20000,11,19630,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cone of Fire');

-- Shattered Sun Marksman
SET @ENTRY := 24938;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,96189,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,10,0,100,0,0,70,4500,8000,11,38858,0,0,0,0,0,6,0,0,0,0,0,0,0,'Cast Shoot OOC');

-- Shattered Sun Sentry
SET @ENTRY := 24994;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,5500,12000,18000,11,33688,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crystal Strike');

-- Shattered Sun Peacekeeper
SET @ENTRY := 26253;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,25821,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,7000,9000,8000,12000,11,18328,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Incapacitating Shout'),
(@ENTRY,0,2,0,13,0,100,0,12000,18000,0,0,11,15618,0,0,0,0,0,6,1,0,0,0,0,0,0,'Cast Cast Snap Kick on Target Spellcast'),
(@ENTRY,0,3,0,0,0,100,0,5000,8000,11500,17900,11,19643,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike');

-- Unleashed Hellion
SET @ENTRY := 25002;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,15000,18000,28000,28000,11,20754,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rain of Fire'),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,19000,23000,11,11876,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast War Stomp');

-- Wretched Fiend
SET @ENTRY := 24966;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,1,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text 1 on Aggro'),
(@ENTRY,0,1,0,4,0,10,1,2,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text 2 on Aggro'),
(@ENTRY,0,2,0,4,0,10,1,3,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text 3 on Aggro'),
(@ENTRY,0,3,0,11,0,100,1,0,0,0,0,11,42648,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sleeping Sleep on Spawn'),
(@ENTRY,0,4,0,2,0,100,1,0,50,0,0,11,29098,0,0,0,0,0,2,1,0,0,0,0,0,0,'Cast Bitter Withdrawal at 50% HP'),
(@ENTRY,0,5,0,0,0,100,0,5000,7700,12000,14700,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sunder Armor');
-- NPC talk text insert
SET @ENTRY := 24966;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,1,0, 'Mine! You shall not take this place!',12,33,100,0,0,0, 'combat Text'),
(@ENTRY,2,0, 'Get away, this place is ours!',12,33,100,0,0,0, 'combat Text'),
(@ENTRY,3,0, 'The rift\'s power is ours!',12,33,100,0,0,0, 'combat Text');

-- Wretched Devourer
SET @ENTRY := 24960;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,1,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text 1 on Aggro'),
(@ENTRY,0,1,0,4,0,10,1,2,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text 2 on Aggro'),
(@ENTRY,0,2,0,4,0,10,1,3,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text 3 on Aggro'),
(@ENTRY,0,3,0,0,0,100,0,9000,12000,10000,17000,11,33483,0,0,0,0,0,2,1,0,0,0,0,0,0,'Cast Mana Tap'),
(@ENTRY,0,4,0,0,0,100,0,5500,7600,12000,16200,11,35334,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Nether Shock');
-- NPC talk text insert
SET @ENTRY := 24960;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,1,0, 'Mine! You shall not take this place!',12,33,100,0,0,0, 'combat Text'),
(@ENTRY,2,0, 'Get away, this place is ours!',12,33,100,0,0,0, 'combat Text'),
(@ENTRY,3,0, 'The rift\'s power is ours!',12,33,100,0,0,0, 'combat Text');
