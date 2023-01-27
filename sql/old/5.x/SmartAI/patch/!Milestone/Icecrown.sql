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
 
 -- Aldur'thar Sentry
 SET @ENTRY := 32323;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8800,11300,16800,11,16564,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gargoyle Strike');

-- Alumeth the Ascended <Cult of the Damned>
 SET @ENTRY := 32300;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8800,15300,28700,11,60472,0,0,0,0,0,5,1,0,0,0,0,0,0,'Cast Mind Flay'),
(@ENTRY,0,1,0,0,0,100,0,13000,16700,19800,24300,11,34322,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Psychic Scream'),
(@ENTRY,0,2,0,2,0,100,1,0,45,0,0,11,37978,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Renew at 45% HP'),
(@ENTRY,0,3,0,0,0,100,0,7800,15600,4500,22100,11,34942,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Word: Pain');

-- Angry Kvaldir
SET @ENTRY := 35072;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5500,7900,11200,19800,11,49922,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wave Crash');

-- Animated Laborer
SET @ENTRY := 32267;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3400,9900,11500,17800,11,48374,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Puncture Wound');

-- Apprentice Osterkilgr
SET @ENTRY := 30409;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,14034,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,0,4500,12300,15700,19800,11,60290,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blast Wave');

-- Archbishop Landgren
SET @ENTRY := 29542;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5500,13400,15300,11,60453,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mind Blast'),
(@ENTRY,0,1,0,0,0,100,0,12300,12500,21300,29400,11,60440,0,0,0,0,0,5,1,0,0,0,0,0,0,'Cast Mind Sear'),
(@ENTRY,0,2,0,0,0,100,0,3200,8700,12600,23300,11,60446,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Shadow Word: Pain'),
(@ENTRY,0,3,0,4,0,100,1,0,0,0,0,11,60449,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadowformon Aggro');

-- Argent Battle-priest
SET @ENTRY := 30919;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,58054,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blessing of Kings on Spawn'),
(@ENTRY,0,1,0,2,0,100,1,0,50,0,0,11,58053,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Holy Light at 50% HP'),
(@ENTRY,0,2,0,14,0,100,0,50000,10,20000,30000,11,58053,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Holy Light on Friendlies');

-- Argent Champion
SET @ENTRY := 33707;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,50,1,0,0,0,0,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,1,0,4,0,50,1,0,0,0,0,11,65147,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield-Breaker on Aggro');

-- Argent Champion
SET @ENTRY := 30188;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,53625,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Leap on Aggro');

-- Argent Confessor Paletress
SET @ENTRY := 34102;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,66536,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,0,5500,11200,23400,33500,11,17141,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Holy Fire');

-- Argent Paladin
SET @ENTRY := 30704;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6700,8900,15600,21300,11,58127,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Divine Storm');

-- Argent Peacekeeper
SET @ENTRY := 34179;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4500,5100,11500,19800,11,63861,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Chains of Law');

-- Argent Valiant
SET @ENTRY := 33448;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,50,1,0,0,0,0,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,1,0,4,0,50,1,0,0,0,0,11,65147,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield-Breaker on Aggro');

-- Baelok <Rider of Blood>
SET @ENTRY := 30953;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,61094,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Death Grip on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,12000,14000,27800,37500,11,61090,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Draw Soul'),
(@ENTRY,0,2,0,0,0,100,0,12000,14000,36800,44300,11,61086,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Dancing Runeblade');

-- Baelok <Rider of Blood>
SET @ENTRY := 31159;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,61094,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Death Grip on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,12000,14000,27800,37500,11,61090,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Draw Soul'),
(@ENTRY,0,2,0,0,0,100,0,12000,14000,36800,44300,11,61086,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Dancing Runeblade');

-- Bitter Initiate <Cult of the Damned>
SET @ENTRY := 32238;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,2,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,0,0,100,0,5000,6700,14800,17200,11,32063,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Corruption');
-- NPC talk text insert
SET @ENTRY := 32238;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Blessed Banner of the Crusade
SET @ENTRY := 30891;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,58026,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blessing of the Crusade on Spawn'),
(@ENTRY,0,1,0,16,0,100,0,58026,30,20000,40000,11,58026,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Blessing of the Crusade on Friendlies');

-- Blight Falconer
SET @ENTRY := 31262;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,50092,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot');

-- Bloodsunder <Baelok's Steed>
SET @ENTRY := 31221;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,6000,12000,14300,11,29577,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hoof Strike'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,33000,34000,11,29577,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Absorb Vitality');

-- Bloodsunder <Baelok's Steed>
SET @ENTRY := 31223;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,6000,12000,14300,11,29577,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hoof Strike'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,33000,34000,11,29577,0,0,0,0,0,0,0,0,0,0,0,0,0,'Cast Absorb Vitality');

-- Bone Giant
SET @ENTRY := 31815;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,11200,12300,16700,27900,11,36405,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stomp');

-- Bone Guard
SET @ENTRY := 32479;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4900,11200,10800,18500,11,32736,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike');

-- Bone Sentinel
SET @ENTRY := 32299;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,10700,12300,16500,11,32736,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike');

-- Bone Spider
SET @ENTRY := 32484;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3200,4700,15400,20500,11,744,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Poison');

-- Boneguard Commander
SET @ENTRY := 34127;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,50,1,0,0,0,0,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,1,0,4,0,50,1,0,0,0,0,11,65147,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield-Breaker on Aggro'),
(@ENTRY,0,2,0,1,0,100,0,500,500,900000,900000,11,59942,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Scourge Banner-Bearer on Spawn'),
(@ENTRY,0,3,0,1,0,100,0,200,200,900000,900000,11,60023,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Mark on Spawn');

-- Boneguard Lieutenant
SET @ENTRY := 33429;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,50,1,0,0,0,0,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,1,0,1,0,100,0,500,500,900000,900000,11,62710,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Strong Guy Sundering Thrust Aura on Spawn');

-- Boneguard Scout
SET @ENTRY := 33550;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5500,11300,17800,11,63233,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Necrocution');

-- Brita
SET @ENTRY := 30484;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,49712,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,16000,17000,11,60954,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Aimed Shot'),
(@ENTRY,0,2,0,13,0,100,0,11500,16700,0,0,11,60932,0,0,0,0,0,1,1,0,0,0,0,0,0,'Cast Disengage on Target Spellcast'),
(@ENTRY,0,3,0,0,0,55,0,6000,9000,16000,17000,11,43414,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Freezing Trap'),
(@ENTRY,0,4,0,0,0,45,0,6000,9000,16000,17000,11,44286,0,0,0,0,0,1,1,0,0,0,0,0,0,'Cast Wing Clip');

-- Captain Hartford
SET @ENTRY := 29490;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,20823,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,2,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,9,0,100,1,0,8,15800,18300,11,11831,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Nova on Close'),
(@ENTRY,0,4,0,0,0,100,0,5500,7700,12500,15400,11,20822,0,0,0,0,0,2,1,0,0,0,0,0,0,'Cast Frostbolt');
-- NPC talk text insert
SET @ENTRY := 29490;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Captain Welsington
SET @ENTRY := 29489;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5700,11300,14700,11,32588,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Concussion Blow'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,29489,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Intercept on Aggro'),
(@ENTRY,0,2,0,0,0,100,0,3500,3500,10900,17800,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike');

-- Carrion Fleshstripper
SET @ENTRY := 30206;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,25600,29700,11,35201,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Paralytic Poison');

-- Carrion Hunter
SET @ENTRY := 31263;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4500,6700,11300,15600,11,24187,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Claw');

-- Chained Abomination
SET @ENTRY := 30689;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,50335,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Scourge Hook on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,5600,8900,12000,13400,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave');

-- Chillmaw
SET @ENTRY := 33687;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5900,9300,19800,26700,11,65248,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frost Breath'),
(@ENTRY,0,1,0,0,0,100,0,10600,16700,9000,44000,11,65260,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wing Buffet');

-- Chosen Zealot
SET @ENTRY := 32175;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,6000,14700,16800,11,13445,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rend'),
(@ENTRY,0,1,0,0,0,100,0,13000,13000,25000,49000,11,12530,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frailty');

-- Citadel Watcher
SET @ENTRY := 31787;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3300,8800,12000,13300,11,16564,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gargoyle Strike');

-- Converted Hero
SET @ENTRY := 32255;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,18000,24000,11,61578,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Incapacitating Shout'),
(@ENTRY,0,1,0,0,0,100,0,5500,5500,11000,15800,11,19643,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike'),
(@ENTRY,0,2,0,1,0,100,0,500,500,900000,900000,11,60231,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Grip of the Scourge on Spawn');

-- Coprous the Defiled
SET @ENTRY := 31198;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5500,11300,24000,11,5164,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Knockdown'),
(@ENTRY,0,1,0,0,0,100,0,14000,15000,33000,37000,11,38971,0,0,0,0,0,5,1,0,0,0,0,0,0,'Cast Acid Geyser');

-- Corp'rethar Guardian
SET @ENTRY := 32280;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3300,4900,14700,16800,11,60927,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Infected Bite'),
(@ENTRY,0,1,0,0,0,100,0,7800,9700,19300,25600,11,54378,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Wound');

-- Corpulent Horror
SET @ENTRY := 30696;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,50335,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Scourge Hook on Aggro');

-- Corrupted Scarlet Onslaught
SET @ENTRY := 29400;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,6000,17900,22300,11,38056,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flesh Rip');

-- Cruel Overseer
SET @ENTRY := 31853;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4600,15400,7800,16200,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Backhand'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,19000,20000,11,49639,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crush');

-- Crusader Lord Dalfors
SET @ENTRY := 31003;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,50,0,0,11,58053,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Holy Light at 50% HP'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,23000,29000,11,37554,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield');

-- Crusader of Virtue
SET @ENTRY := 30189;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,50,0,0,11,58053,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Holy Light at 50% HP');

-- Crusader of Virtue
SET @ENTRY := 30672;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,50,0,0,11,58053,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Holy Light at 50% HP');

-- Cult Alchemist <Cult of the Damned>
SET @ENTRY := 32290;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,14700,18900,11,60846,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Corrosive Vial');

-- Cult Assassin <Cult of the Damned>
SET @ENTRY := 35127;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5500,5500,14500,15600,11,14873,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sinister Strike'),
(@ENTRY,0,1,0,0,0,100,0,9900,9900,17900,25600,11,60842,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Expose Armor');

-- Cult Blackguard <Cult of the Damned>
SET @ENTRY := 32276;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5500,5500,14500,15600,11,14873,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sinister Strike'),
(@ENTRY,0,1,0,0,0,100,0,9900,9900,17900,25600,11,60842,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Expose Armor');

-- Cult Conspirator <Cult of the Damned>
SET @ENTRY := 33537;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5500,5500,14500,15600,11,14873,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sinister Strike'),
(@ENTRY,0,1,0,0,0,100,0,9900,9900,17900,25600,11,60842,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Expose Armor');

-- Cult Researcher <Cult of the Damned>
SET @ENTRY := 32297;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6700,7800,13500,17800,11,15587,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mind Blast'),
(@ENTRY,0,1,0,0,0,100,0,10000,10900,9900,21300,11,62129,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wail of Souls');

-- Cult Taskmaster <Cult of the Damned>
SET @ENTRY := 32268;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,11200,13400,11,16583,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Shock'),
(@ENTRY,0,1,0,0,0,100,0,8800,9900,15600,18700,11,3551,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Skull Crack');

-- Cultist Acolyte
SET @ENTRY := 32507;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,15000,19800,11,16568,0,0,0,0,0,2,1,0,0,0,0,0,0,'Cast Mind Flay'),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,13864,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Power Word: Fortitude on Spawn'),
(@ENTRY,0,2,0,2,0,100,1,0,45,0,0,11,11642,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Heal at 45% HP'),
(@ENTRY,0,3,0,14,0,100,0,5000,10,20000,30000,11,11642,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Heal on Friendlies');

-- Cultist Bombardier
SET @ENTRY := 33695;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,65128,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw Dynamite on Aggro'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 30% HP'),
(@ENTRY,0,2,0,7,0,100,1,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset on Evade'),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP'),
(@ENTRY,0,4,0,2,0,100,1,0,70,0,0,11,65130,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Timebomb at 70% HP');
-- NPC talk text insert
SET @ENTRY := 33695;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Cultist Corrupter <Cult of the Damned>
SET @ENTRY := 33695;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,50324,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bone Armor on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,13400,16700,11,50323,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sharpened Bone');

-- Cultist Shard Watcher <Cult of the Damned>
SET @ENTRY := 32349;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (-122417,-122416,-122415,-122414,-122413,-122412,-122418,-122406,-122404,-122409,-122405,-122408,-122407,-122410,-122411);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-122417,0,0,0,1,0,100,0,1000,1000,15000,19000,11,55070,0,0,0,0,0,10,501556,27452,0,0,0,0,0,'channel Shadow Beam'),
(-122416,0,1,0,1,0,100,0,1000,1000,15500,19900,11,55070,0,0,0,0,0,10,501556,27452,0,0,0,0,0,'channel Shadow Beam'),
(-122415,0,2,0,1,0,100,0,1000,1000,15000,19200,11,55070,0,0,0,0,0,10,501556,27452,0,0,0,0,0,'channel Shadow Beam'),
(-122414,0,3,0,1,0,100,0,1000,1000,15300,19000,11,55070,0,0,0,0,0,10,501556,27452,0,0,0,0,0,'channel Shadow Beam'),
(-122413,0,4,0,1,0,100,0,1000,1000,15500,19900,11,55070,0,0,0,0,0,10,501556,27452,0,0,0,0,0,'channel Shadow Beam'),
(-122412,0,5,0,1,0,100,0,1000,1000,15800,20000,11,55070,0,0,0,0,0,10,501556,27452,0,0,0,0,0,'channel Shadow Beam'),
(-122418,0,6,0,1,0,100,0,1000,1000,15700,19000,11,55070,0,0,0,0,0,10,501556,27452,0,0,0,0,0,'channel Shadow Beam'),
(-122406,0,7,0,1,0,100,0,1000,1000,15700,19000,11,55070,0,0,0,0,0,10,501771,27452,0,0,0,0,0,'channel Shadow Beam'),
(-122404,0,8,0,1,0,100,0,1000,1000,15700,19000,11,55070,0,0,0,0,0,10,501771,27452,0,0,0,0,0,'channel Shadow Beam'),
(-122409,0,9,0,1,0,100,0,1000,1000,15700,19000,11,55070,0,0,0,0,0,10,501771,27452,0,0,0,0,0,'channel Shadow Beam'),
(-122405,0,10,0,1,0,100,0,1000,1000,15700,19000,11,55070,0,0,0,0,0,10,501771,27452,0,0,0,0,0,'channel Shadow Beam'),
(-122408,0,11,0,1,0,100,0,1000,1000,15700,19000,11,55070,0,0,0,0,0,10,501772,27452,0,0,0,0,0,'channel Shadow Beam'),
(-122407,0,12,0,1,0,100,0,1000,1000,15700,19000,11,55070,0,0,0,0,0,10,501772,27452,0,0,0,0,0,'channel Shadow Beam'),
(-122410,0,13,0,1,0,100,0,1000,1000,15700,19000,11,55070,0,0,0,0,0,10,501772,27452,0,0,0,0,0,'channel Shadow Beam'),
(-122411,0,14,0,1,0,100,0,1000,1000,15700,19000,11,55070,0,0,0,0,0,10,501772,27452,0,0,0,0,0,'channel Shadow Beam'),
(-122417,0,15,0,0,0,100,0,5000,6000,12500,17600,11,34441,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Word: Pain'),
(-122417,0,16,0,0,0,100,0,9900,9900,16900,22400,11,39175,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley'),
(-122417,0,17,0,0,0,100,0,3500,3500,25600,38900,11,34439,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Unstable Affliction'),
(-122416,0,18,0,0,0,100,0,5000,6000,12500,17600,11,34441,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Word: Pain'),
(-122416,0,19,0,0,0,100,0,9900,9900,16900,22400,11,39175,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley'),
(-122416,0,20,0,0,0,100,0,3500,3500,25600,38900,11,34439,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Unstable Affliction'),
(-122415,0,21,0,0,0,100,0,5000,6000,12500,17600,11,34441,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Word: Pain'),
(-122415,0,22,0,0,0,100,0,9900,9900,16900,22400,11,39175,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley'),
(-122415,0,23,0,0,0,100,0,3500,3500,25600,38900,11,34439,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Unstable Affliction'),
(-122414,0,24,0,0,0,100,0,5000,6000,12500,17600,11,34441,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Word: Pain'),
(-122414,0,25,0,0,0,100,0,9900,9900,16900,22400,11,39175,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley'),
(-122414,0,26,0,0,0,100,0,3500,3500,25600,38900,11,34439,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Unstable Affliction'),
(-122413,0,27,0,0,0,100,0,5000,6000,12500,17600,11,34441,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Word: Pain'),
(-122413,0,28,0,0,0,100,0,9900,9900,16900,22400,11,39175,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley'),
(-122413,0,29,0,0,0,100,0,3500,3500,25600,38900,11,34439,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Unstable Affliction'),
(-122412,0,30,0,0,0,100,0,5000,6000,12500,17600,11,34441,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Word: Pain'),
(-122412,0,31,0,0,0,100,0,9900,9900,16900,22400,11,39175,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley'),
(-122412,0,32,0,0,0,100,0,3500,3500,25600,38900,11,34439,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Unstable Affliction'),
(-122418,0,33,0,0,0,100,0,5000,6000,12500,17600,11,34441,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Word: Pain'),
(-122418,0,34,0,0,0,100,0,9900,9900,16900,22400,11,39175,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley'),
(-122418,0,35,0,0,0,100,0,3500,3500,25600,38900,11,34439,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Unstable Affliction'),
(-122406,0,36,0,0,0,100,0,5000,6000,12500,17600,11,34441,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Word: Pain'),
(-122406,0,37,0,0,0,100,0,9900,9900,16900,22400,11,39175,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley'),
(-122406,0,38,0,0,0,100,0,3500,3500,25600,38900,11,34439,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Unstable Affliction'),
(-122404,0,39,0,0,0,100,0,5000,6000,12500,17600,11,34441,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Word: Pain'),
(-122404,0,40,0,0,0,100,0,9900,9900,16900,22400,11,39175,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley'),
(-122404,0,41,0,0,0,100,0,3500,3500,25600,38900,11,34439,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Unstable Affliction'),
(-122409,0,42,0,0,0,100,0,5000,6000,12500,17600,11,34441,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Word: Pain'),
(-122409,0,43,0,0,0,100,0,9900,9900,16900,22400,11,39175,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley'),
(-122409,0,44,0,0,0,100,0,3500,3500,25600,38900,11,34439,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Unstable Affliction'),
(-122405,0,45,0,0,0,100,0,5000,6000,12500,17600,11,34441,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Word: Pain'),
(-122405,0,46,0,0,0,100,0,9900,9900,16900,22400,11,39175,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley'),
(-122405,0,47,0,0,0,100,0,3500,3500,25600,38900,11,34439,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Unstable Affliction'),
(-122408,0,48,0,0,0,100,0,5000,6000,12500,17600,11,34441,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Word: Pain'),
(-122408,0,49,0,0,0,100,0,9900,9900,16900,22400,11,39175,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley'),
(-122408,0,50,0,0,0,100,0,3500,3500,25600,38900,11,34439,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Unstable Affliction'),
(-122407,0,51,0,0,0,100,0,5000,6000,12500,17600,11,34441,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Word: Pain'),
(-122407,0,52,0,0,0,100,0,9900,9900,16900,22400,11,39175,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley'),
(-122407,0,53,0,0,0,100,0,3500,3500,25600,38900,11,34439,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Unstable Affliction'),
(-122410,0,54,0,0,0,100,0,5000,6000,12500,17600,11,34441,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Word: Pain'),
(-122410,0,55,0,0,0,100,0,9900,9900,16900,22400,11,39175,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley'),
(-122410,0,56,0,0,0,100,0,3500,3500,25600,38900,11,34439,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Unstable Affliction'),
(-122411,0,57,0,0,0,100,0,5000,6000,12500,17600,11,34441,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Word: Pain'),
(-122411,0,58,0,0,0,100,0,9900,9900,16900,22400,11,39175,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley'),
(-122411,0,59,0,0,0,100,0,3500,3500,25600,38900,11,34439,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Unstable Affliction');

-- Damned Apothecary <Cult of the Damned>
 SET @ENTRY := 32289;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,7000,14500,16800,11,34359,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fire Breath Potion'),
(@ENTRY,0,1,0,2,0,100,1,0,35,0,0,11,17534,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Healing Potion at 35% HP');

-- Dancing Runeblade
SET @ENTRY := 32496;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,4500,11300,13500,11,60945,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blood Strike');

-- Dark Ritualist <Cult of the Damned>
SET @ENTRY := 34734;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (-63126,-62862,-62237,-62863,-62860,-62176,-62950,-63125);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-63126,0,0,0,1,0,100,1,1000,1000,1000,1000,11,45846,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Aura on Spawn'),
(-62862,0,1,0,1,0,100,1,1000,1000,1000,1000,11,45846,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Aura on Spawn'),
(-62237,0,2,0,1,0,100,1,1000,1000,1000,1000,11,45846,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Aura on Spawn'),
(-62863,0,3,0,1,0,100,1,1000,1000,1000,1000,11,45846,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Aura on Spawn'),
(-62860,0,4,0,1,0,100,1,1000,1000,1000,1000,11,45846,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Aura on Spawn'),
(-62176,0,5,0,1,0,100,1,1000,1000,1000,1000,11,45846,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Aura on Spawn'),
(-62950,0,6,0,1,0,100,1,1000,1000,1000,1000,11,45846,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Aura on Spawn'),
(-63125,0,7,0,1,0,100,1,1000,1000,1000,1000,11,45846,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Aura on Spawn'),
(@ENTRY,0,8,0,0,0,100,0,5000,8000,18000,18000,11,32000,0,0,0,0,0,2,1,0,0,0,0,0,0,'Cast Mind Sear'),
(@ENTRY,0,9,0,0,0,100,0,3000,3000,11000,13000,11,32026,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pain Spike'),
(-63126,0,10,0,0,0,100,0,5000,8000,18000,18000,11,32000,0,0,0,0,0,2,1,0,0,0,0,0,0,'Cast Mind Sear'),
(-63126,0,11,0,0,0,100,0,3000,3000,11000,13000,11,32026,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pain Spike'),
(-62862,0,12,0,0,0,100,0,5000,8000,18000,18000,11,32000,0,0,0,0,0,2,1,0,0,0,0,0,0,'Cast Mind Sear'),
(-62862,0,13,0,0,0,100,0,3000,3000,11000,13000,11,32026,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pain Spike'),
(-62237,0,14,0,0,0,100,0,5000,8000,18000,18000,11,32000,0,0,0,0,0,2,1,0,0,0,0,0,0,'Cast Mind Sear'),
(-62237,0,15,0,0,0,100,0,3000,3000,11000,13000,11,32026,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pain Spike'),
(-62863,0,16,0,0,0,100,0,5000,8000,18000,18000,11,32000,0,0,0,0,0,2,1,0,0,0,0,0,0,'Cast Mind Sear'),
(-62863,0,17,0,0,0,100,0,3000,3000,11000,13000,11,32026,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pain Spike'),
(-62860,0,18,0,0,0,100,0,5000,8000,18000,18000,11,32000,0,0,0,0,0,2,1,0,0,0,0,0,0,'Cast Mind Sear'),
(-62860,0,19,0,0,0,100,0,3000,3000,11000,13000,11,32026,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pain Spike'),
(-62176,0,20,0,0,0,100,0,5000,8000,18000,18000,11,32000,0,0,0,0,0,2,1,0,0,0,0,0,0,'Cast Mind Sear'),
(-62176,0,21,0,0,0,100,0,3000,3000,11000,13000,11,32026,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pain Spike'),
(-62950,0,22,0,0,0,100,0,5000,8000,18000,18000,11,32000,0,0,0,0,0,2,1,0,0,0,0,0,0,'Cast Mind Sear'),
(-62950,0,23,0,0,0,100,0,3000,3000,11000,13000,11,32026,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pain Spike'),
(-63125,0,24,0,0,0,100,0,5000,8000,18000,18000,11,32000,0,0,0,0,0,2,1,0,0,0,0,0,0,'Cast Mind Sear'),
(-63125,0,25,0,0,0,100,0,3000,3000,11000,13000,11,32026,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pain Spike');

-- Dark Subjugator <Cult of the Damned>
SET @ENTRY := 32236;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (-63126,-62862,-62237,-62863,-62860,-62176,-62950,-63125);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,18000,18000,11,32000,0,0,0,0,0,2,1,0,0,0,0,0,0,'Cast Mind Sear'),
(@ENTRY,0,1,0,0,0,100,0,3000,3000,11000,13000,11,32026,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pain Spike');

-- Darnassus Champion
SET @ENTRY := 33738;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,50,1,0,0,0,0,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,1,0,4,0,50,1,0,0,0,0,11,65147,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield-Breaker on Aggro');

-- Darnassus Valiant
SET @ENTRY := 33559;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,50,1,0,0,0,0,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,1,0,4,0,50,1,0,0,0,0,11,65147,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield-Breaker on Aggro');

-- Death Knight Adept <Host of Suffering>
SET @ENTRY := 31325;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,11000,12000,11,60945,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blood Strike'),
(@ENTRY,0,1,0,0,0,70,0,3300,3300,16000,16000,11,60951,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frost Strike'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,19000,19000,11,60949,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Death Coil'),
(@ENTRY,0,3,0,0,0,100,0,15000,15000,33000,35000,11,60953,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Death and Decay');

-- Death Knight Adept <Host of Suffering>
SET @ENTRY := 31318;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,11000,12000,11,60945,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blood Strike'),
(@ENTRY,0,1,0,0,0,70,0,3300,3300,16000,16000,11,60951,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frost Strike'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,19000,19000,11,60949,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Death Coil'),
(@ENTRY,0,3,0,0,0,100,0,15000,15000,33000,35000,11,60953,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Death and Decay');

-- Death Knight Adept <Host of Suffering>
SET @ENTRY := 31042;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,11000,12000,11,60945,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blood Strike'),
(@ENTRY,0,1,0,0,0,70,0,3300,3300,16000,16000,11,60951,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frost Strike'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,19000,19000,11,60949,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Death Coil'),
(@ENTRY,0,3,0,0,0,100,0,15000,15000,33000,35000,11,60953,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Death and Decay');

-- Death Knight Initiate <Host of Suffering>
SET @ENTRY := 30958;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,9000,9000,19000,19000,11,60950,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Blood Plague'),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,25000,25000,11,60949,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Death Coil'),
(@ENTRY,0,2,0,0,0,100,0,3000,3000,11000,13000,11,60952,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Icy Touch');

-- Death Knight Initiate <Host of Suffering>
SET @ENTRY := 30957;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,9000,9000,19000,19000,11,60950,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Blood Plague'),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,25000,25000,11,60949,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Death Coil'),
(@ENTRY,0,2,0,0,0,100,0,3000,3000,11000,13000,11,60952,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Icy Touch');

-- Death Knight Master
SET @ENTRY := 29738;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,7800,15000,18000,11,50688,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Plague Strike'),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,50689,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blood Presence on Spawn');

-- Deathspeaker Kharos <Cult of the Damned>
SET @ENTRY := 34808;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,45000,55000,11,67005,0,0,0,0,0,1,1,0,0,0,0,0,0,'Cast Summon Shade'),
(@ENTRY,0,2,0,0,0,100,0,5000,7000,18000,22000,11,11962,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Immolate');

-- Decomposed Ghoul
SET @ENTRY := 31812;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,15716,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP'),
(@ENTRY,0,2,0,0,0,100,0,5000,7000,11000,14000,11,12097,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pierce Armor');
-- NPC talk text insert
SET @ENTRY := 31812;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage');

-- Dr. Terrible
SET @ENTRY := 30404;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Say on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,15000,19000,11,61143,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crazed Chop'),
(@ENTRY,0,2,0,0,0,100,0,10000,12000,28000,33000,11,61146,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Slime Stream'),
(@ENTRY,0,3,0,2,0,100,1,0,45,0,0,11,31730,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Heal at 45% HP');

-- NPC talk text insert
SET @ENTRY := 30404;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Now the nightmare\'s real.Now Dr. Terrible is here.To make you quake with fear.To make the whole world kneel.And I won\'t feel
...a thing',12,0,100,0,0,0, 'combat Say');

-- Ebon Blade Champion
SET @ENTRY := 30703;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,58130,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Icebound Fortitude on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,18000,18000,11,50688,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Plague Strike');

-- Ebon Blade Defender
SET @ENTRY := 31250;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,11000,12000,11,60945,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blood Strike'),
(@ENTRY,0,1,0,0,0,70,0,3300,3300,16000,16000,11,59131,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Icy Touch'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,19000,19000,11,60949,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Death Coil'),
(@ENTRY,0,3,0,4,0,100,1,0,0,0,0,11,49576,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Death Grip on Aggro'),
(@ENTRY,0,4,0,0,0,100,0,5000,8000,25000,25000,11,50688,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Plague Strike');

-- Ebon Blade Vindicator
SET @ENTRY := 32488;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,11000,12000,11,60945,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blood Strike'),
(@ENTRY,0,1,0,0,0,70,0,3300,3300,16000,16000,11,59131,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Icy Touch'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,19000,19000,11,60949,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Death Coil'),
(@ENTRY,0,3,0,4,0,100,1,0,0,0,0,11,49576,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Death Grip on Aggro'),
(@ENTRY,0,4,0,0,0,100,0,5000,8000,25000,25000,11,50688,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Plague Strike');

-- Ebon Knight
SET @ENTRY := 32309;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,11000,12000,11,60945,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blood Strike'),
(@ENTRY,0,1,0,0,0,70,0,3300,3300,16000,16000,11,59131,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Icy Touch'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,19000,19000,11,60949,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Death Coil'),
(@ENTRY,0,3,0,4,0,100,1,0,0,0,0,11,49576,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Death Grip on Aggro'),
(@ENTRY,0,4,0,0,0,100,0,5000,8000,25000,25000,11,50688,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Plague Strike');

-- Ebon Blade Reaper
SET @ENTRY := 31316;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,22000,28000,11,60950,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Blood Plague'),
(@ENTRY,0,1,0,0,0,70,0,3300,3300,16000,16000,11,60945,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blood Strike'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,19000,19000,11,60949,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Death Coil'),
(@ENTRY,0,3,0,0,0,100,0,5000,8000,25000,25000,11,60951,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frost Strike');

-- Ebon Blade Veteran
SET @ENTRY := 31314;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,25000,25000,11,50688,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Plague Strike');

-- Efrem the Faithful
SET @ENTRY := 30081;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,17232,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Devotion Aura on Spawn'),
(@ENTRY,0,1,0,2,0,100,1,0,50,0,0,11,17233,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lay on Hands at 50% HP'),
(@ENTRY,0,2,0,0,0,100,0,3300,5500,16000,17600,11,14518,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crusader Strike'),
(@ENTRY,0,3,0,0,0,80,0,9900,9900,21000,32000,11,13005,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hammer of Justice');

-- Eldreth
SET @ENTRY := 31195;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,15620,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,16000,17800,11,34829,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Shot'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,45000,48000,11,44475,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Magic Dampening Field');

-- Enslaved Minion <Void Summoner's Pet>
SET @ENTRY := 32260;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,31976,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Shield on Aggro');

-- Exodar Champion
SET @ENTRY := 33739;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,50,1,0,0,0,0,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,1,0,4,0,50,1,0,0,0,0,11,65147,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield-Breaker on Aggro');

-- Exodar Valiant
SET @ENTRY := 33562;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,50,1,0,0,0,0,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,1,0,4,0,50,1,0,0,0,0,11,65147,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield-Breaker on Aggro');

-- Faceless Lurker
SET @ENTRY := 31691;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,11300,12400,11,52342,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Seething Evil');

-- Fallen Hero's Spirit
SET @ENTRY := 32149;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,12000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike');

-- Fallen Spiderlord
SET @ENTRY := 31780;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,11000,16000,11,60802,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mandible Crush'),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,23000,24500,11,50284,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blinding Swarm');

-- Father Kamaros
SET @ENTRY := 31279;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,25054,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,74973,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Power Word: Fortitude on Spawn'),
(@ENTRY,0,2,0,0,0,100,0,5000,6200,11700,15600,11,17146,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Shadow Word: Pain'),
(@ENTRY,0,3,0,2,0,100,1,0,50,0,0,11,32595,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Power Word: Shield at 50% HP');

-- Father Kamaros
SET @ENTRY := 32800;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,25054,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,74973,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Power Word: Fortitude on Spawn'),
(@ENTRY,0,2,0,0,0,100,0,5000,6200,11700,15600,11,17146,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Shadow Word: Pain'),
(@ENTRY,0,3,0,2,0,100,1,0,50,0,0,11,32595,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Power Word: Shield at 50% HP');

-- Foreman Thaldrin
SET @ENTRY := 31399;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,4300,12300,13300,11,59992,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,1,0,0,0,100,0,6000,6000,7000,16000,11,21401,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frost Shock'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,25000,27000,11,16509,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rend'),
(@ENTRY,0,3,0,0,0,50,0,5000,5000,19000,39000,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike');

-- Forgotten Depths Acolyte
SET @ENTRY := 30205;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,3500,11500,13500,11,16583,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Shock'),
(@ENTRY,0,1,0,0,0,100,0,5500,6500,35000,35000,11,60781,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Curse of Mending');

-- Forgotten Depths Ambusher
SET @ENTRY := 30204;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5500,5500,11500,12500,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave');

-- Forgotten Depths High Priest
SET @ENTRY := 31037;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8300,8500,11300,13400,11,4962,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Encasing Webs'),
(@ENTRY,0,1,0,0,0,100,0,3000,3000,15600,18900,11,32000,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mind Sear');

-- Forgotten Depths High Priest
SET @ENTRY := 30543;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8300,8500,11300,13400,11,4962,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Encasing Webs'),
(@ENTRY,0,1,0,0,0,100,0,3000,3000,15600,18900,11,32000,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mind Sear');

-- Forgotten Depths Slayer
SET @ENTRY := 30333;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5400,11500,12500,11,54185,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Claw Slash');

-- Forgotten Depths Slayer
SET @ENTRY := 30593;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5400,11500,12500,11,54185,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Claw Slash');

-- Forgotten Depths Underking
SET @ENTRY := 31039;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,11000,16000,11,60802,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mandible Crush'),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,23000,24500,11,50284,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blinding Swarm');

-- Forgotten Depths Underking
SET @ENTRY := 30544;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,11000,16000,11,60802,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mandible Crush'),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,23000,24500,11,50284,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blinding Swarm');

-- Forgotten Depths Underking
SET @ENTRY := 30541;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,11000,16000,11,60802,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mandible Crush'),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,23000,24500,11,50284,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blinding Swarm');

-- Freed Crusader
SET @ENTRY := 30274;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,15,0,50,0,20,8000,12000,0,11,56525,0,0,0,0,0,18,20,0,0,0,0,0,0,'Cast Blessing of Kings'),
(@ENTRY,0,1,0,15,0,50,0,20,8000,12000,0,11,56520,0,0,0,0,0,18,20,0,0,0,0,0,0,'Cast Blessing of Might'),
(@ENTRY,0,2,0,15,0,50,0,20,8000,12000,0,11,56521,0,0,0,0,0,18,20,0,0,0,0,0,0,'Cast Blessing of Wisdom');

-- Fringe Engineer Tezzla
SET @ENTRY := 34430;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,14000,15000,11,61998,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Welding Beam');

-- Frostbrood Destroyer
SET @ENTRY := 30575;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,15000,15000,25000,35000,11,57477,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Freezing Breath'),
(@ENTRY,0,1,0,0,0,100,0,9000,9000,48000,48900,11,53363,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wing Buffet');

-- Frostbrood Matriarch
SET @ENTRY := 32492;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,19800,23400,11,60667,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frost Breath');

-- Frostbrood Sentry
SET @ENTRY := 31721;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,7000,12000,14500,11,60542,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bitter Blast');

-- Frostbrood Skytalon
SET @ENTRY := 31137;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,19800,23400,11,60667,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frost Breath');

-- Frostbrood Spawn
SET @ENTRY := 31702;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,19800,23400,11,60667,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frost Breath');

-- Frostbrood Whelp
SET @ENTRY := 31718;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,5000,12000,11,60814,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt');

-- Frostskull Magus
SET @ENTRY := 31813;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,20297,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt');

-- Gargoyle Ambusher
SET @ENTRY := 32188;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4500,5500,11300,14500,11,60239,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gargoyle Ambusher Strike');

-- Gargoyle Ambusher
SET @ENTRY := 32769;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4500,5500,11300,14500,11,60239,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gargoyle Ambusher Strike');

-- General Lightsbane
SET @ENTRY := 29851;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,11000,12000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,19000,19000,11,60186,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Plague Strike'),
(@ENTRY,0,2,0,0,0,100,0,15000,15000,33000,35000,11,60160,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Death and Decay');

-- Geness Half-Soul
SET @ENTRY := 31193;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,11000,13000,11,61041,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Brutal Fist'),
(@ENTRY,0,1,0,13,0,100,0,12000,18000,0,0,11,46182,0,0,0,0,0,6,1,0,0,0,0,0,0,'Cast Snap Kick on Target Spellcast');

-- Glacial Bonelord
SET @ENTRY := 31754;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,11000,13000,11,61041,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Brutal Fist'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,17900,18900,11,51878,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Ice Slash');

-- Gnomeregan Champion
SET @ENTRY := 33740;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,50,1,0,0,0,0,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,1,0,4,0,50,1,0,0,0,0,11,65147,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield-Breaker on Aggro');

-- Gnomeregan Valiant
SET @ENTRY := 33558;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,50,1,0,0,0,0,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,1,0,4,0,50,1,0,0,0,0,11,65147,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield-Breaker on Aggro');

-- Grimkor the Wicked
SET @ENTRY := 32162;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,15537,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,45000,45000,11,52611,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Skeletons');

-- Grimkor's Hound
SET @ENTRY := 32163;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,15000,15000,11,20817,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mana Burn'),
(@ENTRY,0,1,0,0,0,100,0,3000,3000,19000,23900,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Tendon Rip'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,29000,35000,11,14331,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Vicious Rend');

-- Ground Commander Koup
SET @ENTRY := 31808;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,15547,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot');

-- Harbinger of Horror
SET @ENTRY := 32278;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,61747,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,18100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Armor on Spawn'),
(@ENTRY,0,2,0,0,0,100,0,5000,5000,17800,19900,11,60924,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lich Slap'),
(@ENTRY,0,3,0,0,0,100,0,7800,9800,15800,25600,11,12096,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Fear'),
(@ENTRY,0,4,0,0,0,100,0,3400,12300,28900,29800,11,18099,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill Nova');

-- Hideous Plaguebringer
SET @ENTRY := 30987;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3400,4600,11400,16500,11,38761,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcing Smash');

-- High Priest Yath'amon
SET @ENTRY := 30831;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,13300,14500,11,4962,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Encasing Webs'),
(@ENTRY,0,1,0,0,0,100,0,9900,11200,23500,26700,11,38243,0,0,0,0,0,2,1,0,0,0,0,0,0,'Cast Mind Flay'),
(@ENTRY,0,2,0,0,0,100,0,22000,22000,35000,35000,11,34322,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Psychic Scream'),
(@ENTRY,0,3,0,0,0,100,0,3500,3700,10800,11300,11,61705,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Venomous Bite');

-- High Thane Jorfus
SET @ENTRY := 32501;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,11000,12000,11,60945,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blood Strike'),
(@ENTRY,0,1,0,0,0,70,0,3300,3300,16000,16000,11,60951,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frost Strike'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,19000,19000,11,60949,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Death Coil'),
(@ENTRY,0,3,0,0,0,100,0,15000,15000,33000,35000,11,60953,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Death and Decay');

-- Hildana Deathstealer
SET @ENTRY := 32495;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,12000,14000,11,60991,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lash'),
(@ENTRY,0,1,0,0,0,100,0,7800,9900,17800,19900,11,57547,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Touch of the Val\'kyr');

-- Hulking Abomination
SET @ENTRY := 31140;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,50335,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Scourge Hook on Aggro'),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,11,58995,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Exploding Corpse'),
(@ENTRY,0,2,0,0,0,100,0,5000,5000,11300,15600,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave');

-- Hulking Horror
SET @ENTRY := 31411;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,7000,13500,16800,11,49861,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Infected Bite'),
(@ENTRY,0,1,0,0,0,100,0,9000,11000,21000,26000,11,10966,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Uppercut');

-- Hulking Horror
SET @ENTRY := 31413;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,7000,13500,16800,11,49861,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Infected Bite'),
(@ENTRY,0,1,0,0,0,100,0,9000,11000,21000,26000,11,10966,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Uppercut');

-- Hungering Plaguehound
SET @ENTRY := 30952;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,25000,34000,11,3427,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Infected Wound');

-- Icefury <Sapph's Steed>
SET @ENTRY := 31163;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,4000,11300,13500,11,29577,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hoof Strike'),
(@ENTRY,0,1,0,0,0,100,0,8000,9000,17000,21700,11,29323,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Absorb Vitality');

-- Icefury <Sapph's Steed>
SET @ENTRY := 31224;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,4000,11300,13500,11,29577,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hoof Strike'),
(@ENTRY,0,1,0,0,0,100,0,8000,9000,17000,21700,11,29323,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Absorb Vitality');

-- Intrepid Ghoul
SET @ENTRY := 31015;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4700,4900,17800,19800,11,60873,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Festering Bite'),
(@ENTRY,0,1,0,0,0,100,0,12000,14000,23000,26000,11,60872,0,0,0,0,0,2,1,0,0,0,0,0,0,'Cast Ravenous Claw'),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,11,58137,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Ghoulplosion on Death');

-- Ironforge Champion
SET @ENTRY := 33743;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,50,1,0,0,0,0,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,1,0,4,0,50,1,0,0,0,0,11,65147,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield-Breaker on Aggro');

-- Ironforge Valiant
SET @ENTRY := 33564;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,50,1,0,0,0,0,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,1,0,4,0,50,1,0,0,0,0,11,65147,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield-Breaker on Aggro');

-- Jayde
SET @ENTRY := 30839;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,11000,12000,11,60945,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blood Strike'),
(@ENTRY,0,1,0,0,0,70,0,3300,3300,16000,16000,11,59131,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Icy Touch'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,19000,19000,11,60949,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Death Coil'),
(@ENTRY,0,3,0,4,0,100,1,0,0,0,0,11,49576,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Death Grip on Aggro'),
(@ENTRY,0,4,0,0,0,100,0,5000,8000,25000,25000,11,50688,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Plague Strike');

-- Jotunheim Sleep-Watcher
SET @ENTRY := 30725;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,9900,8500,14900,11,60870,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bludgeoning Strike'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,21000,24500,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demoralizing Shout');

-- Jotunheim Warrior
SET @ENTRY := 29880;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,3500,12400,14200,11,43410,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chop'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,21000,24500,11,29880,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demoralize');

-- Knight of the Ebon Blade
SET @ENTRY := 38505;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,58130,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Icebound Fortitude on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,18000,18000,11,50688,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Plague Strike'),
(@ENTRY,0,2,0,0,0,70,0,3300,3300,16000,16000,11,60951,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frost Strike'),
(@ENTRY,0,3,0,0,0,100,0,10000,10000,19000,19000,11,60949,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Death Coil'),
(@ENTRY,0,4,0,0,0,100,0,15000,15000,33000,35000,11,60953,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Death and Decay');

-- Koltira Deathweaver
SET @ENTRY := 32311;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,11200,13400,11,59992,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave');

-- Kor'kron Infantry
SET @ENTRY := 31832;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,15547,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,2,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,0,0,100,0,4500,5500,11300,12700,11,29426,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Strike');
-- NPC talk text insert
SET @ENTRY := 31832;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Kor'kron Infiltrator
SET @ENTRY := 31882;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,11300,13500,11,15667,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sinister Strike');

-- Kor'kron Reaver
SET @ENTRY := 30755;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,23337,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,2,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,0,0,100,0,4500,5400,11800,13500,11,12024,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Net');
-- NPC talk text insert
SET @ENTRY := 30755;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Kor'kron Squad Leader
SET @ENTRY := 31833;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,15547,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,0,3500,4300,15700,16500,11,12551,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Frost Shot'),
(@ENTRY,0,2,0,0,0,100,0,4500,5500,11300,12700,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave');

-- Kul'galar Oracle
SET @ENTRY := 30751;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,45,0,0,11,11642,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Heal at 45% HP'),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,13400,15700,11,31516,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mind Blast'),
(@ENTRY,0,2,0,0,0,100,0,9900,9900,17400,19800,11,16568,0,0,0,0,0,5,1,0,0,0,0,0,0,'Cast Mind Flay');

-- Lady Nightswood
SET @ENTRY := 29858;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,6000,16700,18900,11,5884,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Banshee Curse'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,21000,23000,11,16838,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Banshee Shriek');

-- Lady Nightswood
SET @ENTRY := 29770;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,6000,16700,18900,11,5884,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Banshee Curse'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,21000,23000,11,16838,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Banshee Shriek');

-- Lady Nightswood
SET @ENTRY := 30955;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,6000,16700,18900,11,5884,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Banshee Curse'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,21000,23000,11,16838,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Banshee Shriek');

-- Lordaeron Captain
SET @ENTRY := 32414;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot');

-- Lordaeron Footsoldier
SET @ENTRY := 31254;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot');

-- Lumbering Atrocity
SET @ENTRY := 31226;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,12000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave');

-- Lumbering Atrocity
SET @ENTRY := 30920;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,12000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave');

-- Malefic Necromancer
SET @ENTRY := 31155;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,34344,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,35000,36000,11,50324,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bone Armor');

-- Malithus Brightblade
SET @ENTRY := 36120;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,17800,19600,11,66004,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Seal of Command');

-- Master Summoner Zarod
SET @ENTRY := 30746;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,61747,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,18100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Armor on Spawn'),
(@ENTRY,0,2,0,0,0,100,0,5000,5000,17800,19900,11,60924,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lich Slap'),
(@ENTRY,0,3,0,0,0,100,0,7800,9800,15800,25600,11,12096,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Fear'),
(@ENTRY,0,4,0,0,0,100,0,3400,12300,28900,29800,11,18099,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill Nova');

SET @ENTRY := 30037;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Say on Aggro'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,61227,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Jump Attack on Aggro'),
(@ENTRY,0,2,0,0,0,100,0,5000,5000,13400,14400,11,32736,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike'),
(@ENTRY,0,3,0,0,0,100,0,7000,9000,17800,19900,11,50370,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sunder Armor'),
(@ENTRY,0,4,0,0,0,100,0,15000,15000,25000,32000,11,49807,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirlwind'),
(@ENTRY,0,5,0,0,0,80,0,3000,9000,7000,25000,11,61343,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Dominate');
-- NPC talk text insert
SET @ENTRY := 30037;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'I will take pleasure in gutting you',12,0,100,0,0,0, 'combat Say');

-- Mjordin Water Magus
SET @ENTRY := 30632;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9672,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,2,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,9,0,100,1,0,8,15800,18300,11,15532,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Nova on Close'),
(@ENTRY,0,4,0,1,0,100,1,500,1000,0,0,11,7855,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Water Terror on Spawn');
-- NPC talk text insert
SET @ENTRY := 30632;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Morbid Carcass
SET @ENTRY := 29719;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,50335,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Scourge Hook on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,11000,13000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave');

-- Morbidus
SET @ENTRY := 30698;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,16700,18500,11,72728,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Corrode Flesh'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,25000,28900,11,31277,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stomp');

-- Onslaught Darkweaver
SET @ENTRY := 29614;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,12739,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,13787,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demon Armor on Spawn'),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,54840,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Metamorphosis at 30% HP');

-- Onslaught Gryphon Rider
SET @ENTRY := 29333;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,54617,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,1,2,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,0,0,100,0,5000,5000,14500,15600,11,40652,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wing Clip');
-- NPC talk text insert
SET @ENTRY := 29333;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Onu'zun
SET @ENTRY := 30180;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,15242,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,18100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Armor on Spawn'),
(@ENTRY,0,2,0,13,0,100,0,12000,18000,0,0,11,15122,0,0,0,0,0,6,1,0,0,0,0,0,0,'Cast Counterspell on Target Spellcast'),
(@ENTRY,0,3,0,0,0,100,0,5000,5000,14500,17800,11,15244,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cone of Cold');

-- Onslaught Raven Bishop
SET @ENTRY := 29338;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,50740,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,2,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,2,0,100,1,0,40,0,0,11,50750,1,0,0,0,0,1,1,0,0,0,0,0,0,'Cast Raven Heal at 40% HP'),
(@ENTRY,0,4,0,1,0,100,0,500,1000,600000,600000,11,54323,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blessing of the Light on Spawn');
-- NPC talk text insert
SET @ENTRY := 29338;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Nergeld
SET @ENTRY := 30403;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Say on Aggro'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,60540,0,0,0,0,0,2,1,0,0,0,0,0,0,'Cast Chained Grip on Aggro'),
(@ENTRY,0,2,0,0,0,100,0,5000,5000,12000,12000,11,56746,0,0,0,0,0,0,0,0,0,0,0,0,0,'Cast Punch'),
(@ENTRY,0,3,0,0,0,100,0,9900,9900,17800,18900,11,56748,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Roar'),
(@ENTRY,0,4,0,0,0,100,0,24000,25000,39000,42000,11,56747,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stomp');
-- NPC talk text insert
SET @ENTRY := 30403;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Look at the size of that thing!',12,0,100,0,0,0, 'combat Say');

-- Necrotic Webspinner
SET @ENTRY := 31747;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,12000,12000,11,744,0,0,0,0,0,2,32,0,0,0,0,0,0,'Cast Poison'),
(@ENTRY,0,1,0,0,0,100,0,3000,9000,11000,19000,11,745,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Web');

-- Njorndar Spear-Sister
SET @ENTRY := 30243;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,43413,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,1,2,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,0,0,100,0,5000,5400,11300,15600,11,38029,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Stab');
-- NPC talk text insert
SET @ENTRY := 30243;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Onslaught Harbor Guard
SET @ENTRY := 29330;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,2,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,0,0,100,0,5000,5000,13400,15600,11,18802,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frost Shot');
-- NPC talk text insert
SET @ENTRY := 29330;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Onslaught Paladin
SET @ENTRY := 29329;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,19131,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Charge on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,15800,17800,11,32774,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Avenger\'s Shield');

-- Munch
SET @ENTRY := 30840;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,9000,9000,19000,19000,11,60950,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Blood Plague'),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,25000,25000,11,60949,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Death Coil'),
(@ENTRY,0,2,0,0,0,100,0,3000,3000,11000,13000,11,60952,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Icy Touch');

-- Orbaz Bloodbane <The Hand of Suffering>
SET @ENTRY := 31283;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,9000,9000,19000,19000,11,60950,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Blood Plague'),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,25000,25000,11,60949,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Death Coil');

-- Onslaught Destrier
SET @ENTRY := 29710;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,6000,12000,14300,11,29577,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hoof Strike');

-- Orgrimmar Champion
SET @ENTRY := 33744;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,50,1,0,0,0,0,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,1,0,4,0,50,1,0,0,0,0,11,65147,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield-Breaker on Aggro');

-- Orgrimmar Valiant
SET @ENTRY := 33306;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,50,1,0,0,0,0,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,1,0,4,0,50,1,0,0,0,0,11,65147,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield-Breaker on Aggro');

-- Overseer Jhaeqon <Cult of the Damned>
SET @ENTRY := 32285;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,12471,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt');

-- Overseer Faedris <Cult of the Damned>
SET @ENTRY := 32250;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,50,0,0,11,17173,0,0,0,0,0,2,1,0,0,0,0,0,0,'Cast Drain Life at 50% HP'),
(@ENTRY,0,1,0,0,0,100,0,4500,5500,11300,12800,11,51797,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Blast');

-- Overseer Savryn <Cult of the Damned>
SET @ENTRY := 32291;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4900,5900,11300,14500,11,60850,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mutilate'),
(@ENTRY,0,1,0,0,0,100,0,9000,9000,16700,19800,11,60847,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Slice and Dice');

-- Overseer Veraj <Cult of the Damned>
SET @ENTRY := 32263;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,20825,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,0,4700,6700,15800,16900,11,11980,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Curse of Weakness'),
(@ENTRY,0,2,0,0,0,100,0,7900,11200,19500,22400,11,20787,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Immolate');

-- Overthane Balargarde <Master of Jotunheim>
SET @ENTRY := 31016;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,15043,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,0,15000,15000,25000,25000,11,61076,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirlwind'),
(@ENTRY,0,2,0,0,0,100,0,5000,5000,14000,16000,11,61085,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blizzard');

-- Plague Drenched Ghoul
SET @ENTRY := 32176;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,50106,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Disease Cloud on Spawn'),
(@ENTRY,0,1,0,0,0,100,0,4500,5500,13400,14500,11,60678,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Plague Bite');

-- Plagued Fiend
SET @ENTRY := 31150;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,50106,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Disease Cloud on Spawn'),
(@ENTRY,0,1,0,0,0,100,0,4500,5500,13400,14500,11,60678,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Plague Bite');

-- Plaguehoof <Rokir's Steed>
SET @ENTRY := 31225;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,6000,12000,14300,11,29577,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hoof Strike'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,33000,34000,11,29577,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Absorb Vitality');

-- Possessed Iskalder <The Ancient Hero>
SET @ENTRY := 30924;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,60108,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Leap on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,3500,3500,14500,16700,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,2,0,0,0,100,0,5000,6000,11200,15800,11,57846,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Strike'),
(@ENTRY,0,3,0,0,0,100,0,9000,11000,25000,25000,11,60121,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Ancient Curse');

-- Reanimated Crusader
SET @ENTRY := 30202;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,32674,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Avenger\'s Shield on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,17800,19800,11,58154,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hammer of Injustice'),
(@ENTRY,0,2,0,2,0,100,1,0,45,0,0,11,58153,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Unholy Light at 45% HP'),
(@ENTRY,0,3,0,14,0,100,0,4000,10,20000,30000,11,58153,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Unholy Light on Friendlies');

-- Reanimated Miner
SET @ENTRY := 31843;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,11300,13400,11,48374,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Puncture Wound');

-- Reanimated Captain
SET @ENTRY := 30986;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,32674,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Avenger\'s Shield on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,17800,19800,11,58154,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hammer of Injustice'),
(@ENTRY,0,2,0,2,0,100,1,0,45,0,0,11,58153,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Unholy Light at 45% HP'),
(@ENTRY,0,3,0,14,0,100,0,4000,10,20000,30000,11,58153,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Unholy Light on Friendlies');

-- Rabid Cannibal
SET @ENTRY := 29722;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,17000,21000,11,30639,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Carnivorous Bite');

-- Reanimated Crusader
SET @ENTRY := 31043;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,32674,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Avenger\'s Shield on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,17800,19800,11,58154,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hammer of Injustice'),
(@ENTRY,0,2,0,2,0,100,1,0,45,0,0,11,58153,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Unholy Light at 45% HP'),
(@ENTRY,0,3,0,14,0,100,0,4000,10,20000,30000,11,58153,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Unholy Light on Friendlies');

-- Rith
SET @ENTRY := 31196;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5000,12300,15600,11,58461,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sunder Armor'),
(@ENTRY,0,1,0,0,0,100,0,9000,9000,17800,21200,11,61044,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Demoralizing Shout');

-- Rampaging Ghoul
SET @ENTRY := 32178;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4500,5700,16700,17800,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pierce Armor'),
(@ENTRY,0,1,0,0,0,100,0,9000,9000,22000,25000,11,54475,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rampage');

-- Restless Lookout
SET @ENTRY := 30951;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,50933,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP'),
(@ENTRY,0,2,0,0,0,100,0,4500,6700,13400,15600,11,46202,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pierce Armor');
-- NPC talk text insert
SET @ENTRY := 30951;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy');

-- Putridus the Ancient
SET @ENTRY := 32487;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7900,9800,23400,27800,11,41534,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast War Stomp');

-- Rokir <Rider of the Unholy>
SET @ENTRY := 31160;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,11000,12000,11,60945,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blood Strike'),
(@ENTRY,0,1,0,2,0,100,1,0,50,0,0,11,61099,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Zombie Horde at 50% HP'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,19000,19000,11,60949,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Death Coil'),
(@ENTRY,0,3,0,0,0,100,0,15000,15000,33000,35000,11,60953,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Death and Decay');

-- Ravenous Jaws
SET @ENTRY := 29392;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,11300,13400,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thrash');

-- Risen Laborer
SET @ENTRY := 30949;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3400,9900,11500,17800,11,48374,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Puncture Wound');

-- Rokir <Rider of the Unholy>
SET @ENTRY := 30954;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,11000,12000,11,60945,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blood Strike'),
(@ENTRY,0,1,0,2,0,100,1,0,50,0,0,11,61099,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Zombie Horde at 50% HP'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,19000,19000,11,60949,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Death Coil'),
(@ENTRY,0,3,0,0,0,100,0,15000,15000,33000,35000,11,60953,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Death and Decay');

-- Ravaged Ghoul
SET @ENTRY := 32502;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4700,4900,17800,19800,11,60873,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Festering Bite'),
(@ENTRY,0,1,0,0,0,100,0,12000,14000,23000,26000,11,60872,0,0,0,0,0,2,1,0,0,0,0,0,0,'Cast Ravenous Claw');

-- Restless Lookout
SET @ENTRY := 31554;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,59208,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP'),
(@ENTRY,0,2,0,0,0,100,0,5000,5000,13400,15600,11,46202,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pierce Armor');
-- NPC talk text insert
SET @ENTRY := 31554;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage');

-- Rokir <Rider of the Unholy>
SET @ENTRY := 31160;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,11000,12000,11,60945,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blood Strike'),
(@ENTRY,0,1,0,2,0,100,1,0,50,0,0,11,61099,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Zombie Horde at 50% HP'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,19000,19000,11,60949,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Death Coil'),
(@ENTRY,0,3,0,0,0,100,0,15000,15000,33000,35000,11,60953,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Death and Decay');

-- Pustulent Colossus
SET @ENTRY := 32482;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,11200,12300,16700,27900,11,63546,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stomp'),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,23000,25000,11,28405,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Knockback');

-- Pustulent Horror
SET @ENTRY := 31139;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,11200,12300,16700,27900,11,63546,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stomp'),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,23000,25000,11,28405,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Knockback');

-- Putrid Colossus
SET @ENTRY := 30697;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,11200,12300,16700,27900,11,63546,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stomp'),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,23000,25000,11,28405,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Knockback');

-- Prince Sandoval
SET @ENTRY := 14688;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,16700,17800,11,61162,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Engulfing Strike'),
(@ENTRY,0,1,0,0,0,100,0,12000,12000,26700,28600,11,61163,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fire Nova');

-- Scourge Death Knight
SET @ENTRY := 32486;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,11000,12000,11,60945,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blood Strike'),
(@ENTRY,0,1,0,0,0,70,0,3300,3300,16000,16000,11,60951,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frost Strike'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,19000,19000,11,60949,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Death Coil');

-- Scourge Drudge
SET @ENTRY := 30984;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,11300,14500,11,51917,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,1,0,0,0,100,0,7000,9000,17800,20200,11,49678,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flesh Rot');

-- Sen'jin Champion
SET @ENTRY := 33745;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,50,1,0,0,0,0,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,1,0,4,0,50,1,0,0,0,0,11,65147,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield-Breaker on Aggro');

-- Sen'jin Valiant
SET @ENTRY := 33285;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,50,1,0,0,0,0,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,1,0,4,0,50,1,0,0,0,0,11,65147,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield-Breaker on Aggro');

-- Sentry Worg
SET @ENTRY := 30430;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3400,5600,14500,17200,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Tendon Rip');

-- Scourge Converter
SET @ENTRY := 32257;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,20822,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,0,5000,7000,12000,17800,11,20828,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cone of Cold'),
(@ENTRY,0,2,0,1,0,100,0,500,1000,27000,45600,11,60212,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Grip of the Scourge on Spawn');

-- Scourge Deathcharger
SET @ENTRY := 32490;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,6000,12000,14300,11,29577,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hoof Strike'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,33000,34000,11,29577,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Absorb Vitality');

-- Scourge Soulbinder
SET @ENTRY := 32284;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,60814,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,2,0,100,1,0,50,0,0,11,17620,0,0,0,0,0,2,1,0,0,0,0,0,0,'Cast Drain Life at 50% HP'),
(@ENTRY,0,2,0,0,0,100,0,5000,7000,15700,17800,11,22744,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Chains of Ice');

-- Scourgebeak Fleshripper
SET @ENTRY := 30988;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,11200,14500,11,55079,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Swoop');

-- Scourge Banner-Bearer
SET @ENTRY := 31900;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,11500,16700,11,16583,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Shock'),
(@ENTRY,0,1,0,9,1,100,1,0,8,15800,18300,11,32712,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Nova on Close'),
(@ENTRY,0,2,0,1,0,100,0,500,500,900000,900000,11,59942,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Scourge Banner-Bearer on Spawn'),
(@ENTRY,0,3,0,1,0,100,0,200,200,900000,900000,11,60023,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Mark on Spawn');

-- Saronite Mine Slave
SET @ENTRY := 31397;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,1,0,2,0,100,1,0,35,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 35% HP'),
(@ENTRY,0,2,0,0,0,100,0,8000,8000,18900,21300,11,3148,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Head Crack');
-- NPC talk text insert
SET @ENTRY := 31397;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage');

-- Saronite Shaper
SET @ENTRY := 31255;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7900,9800,23400,27800,11,60960,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast War Stomp');

-- Savage Proto-Drake
SET @ENTRY := 31265;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,16700,18900,11,51219,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Breath'),
(@ENTRY,0,1,0,0,0,100,0,9900,11200,23400,27800,11,41572,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wing Buffet');

-- Shadow Vault Abomination
SET @ENTRY := 31438;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,17800,18600,11,5568,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Trample'),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,25600,27600,11,16790,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Knockdown');

-- Shadow Adept <Cult of the Damned>
SET @ENTRY := 31145;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,60646,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,2,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,2,0,100,1,0,45,0,0,11,17238,0,0,0,0,0,2,1,0,0,0,0,0,0,'Cast Drain Life at 45% HP');
-- NPC talk text insert
SET @ENTRY := 31145;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Sarhule the Risen <Reagents>
SET @ENTRY := 30307;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Armor on Spawn');

-- Sapph <Rider of Frost>
SET @ENTRY := 31161;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,61077,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chains of Ice on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,15600,17800,11,61058,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Hungering Cold');

-- Shadow Vault Boneguard
SET @ENTRY := 30312;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,12000,12300,11,12024,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Net');

-- Shadow Channeler <Cult of the Damned>
SET @ENTRY := 32262;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,13787,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demon Armor on Spawn'),
(@ENTRY,0,2,0,0,0,100,0,5000,5500,16700,18900,11,11962,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Immolate');

-- Sapph <Rider of Frost>
SET @ENTRY := 30956;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,61077,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chains of Ice on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,15600,17800,11,61058,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Hungering Cold');

-- Shadow Cultist <Cult of the Damned>
SET @ENTRY := 29717;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,16592,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadowform on Spawn'),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,14500,17800,11,32000,0,0,0,0,0,2,1,0,0,0,0,0,0,'Cast Mind Sear');

-- Shambling Zombie
SET @ENTRY := 32503;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,9000,9000,16800,18900,11,61095,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Plague Blast');

-- Shambling Zombie
SET @ENTRY := 32499;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,9000,9000,16800,18900,11,61095,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Plague Blast');

-- Salranax the Flesh Render
SET @ENTRY := 30829;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,15242,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,18100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Armor on Spawn'),
(@ENTRY,0,2,0,0,0,100,0,5000,8000,12000,12000,11,15244,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cone of Cold'),
(@ENTRY,0,3,0,13,0,100,0,12000,18000,0,0,11,15122,0,0,0,0,0,6,1,0,0,0,0,0,0,'Cast Counterspell on Target Spellcast');

-- Silvermoon Valiant
SET @ENTRY := 33382;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,50,1,0,0,0,0,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,1,0,4,0,50,1,0,0,0,0,11,65147,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield-Breaker on Aggro');

-- Silvermoon Champion
SET @ENTRY := 33746;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,50,1,0,0,0,0,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,1,0,4,0,50,1,0,0,0,0,11,65147,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield-Breaker on Aggro');

-- Skeletal Archmage
SET @ENTRY := 31779;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,15242,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,18100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Armor on Spawn'),
(@ENTRY,0,2,0,0,0,100,0,5000,8000,12000,12000,11,15244,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cone of Cold'),
(@ENTRY,0,3,0,13,0,100,0,12000,18000,0,0,11,15122,0,0,0,0,0,6,1,0,0,0,0,0,0,'Cast Counterspell on Target Spellcast');

-- Skeletal Constructor
SET @ENTRY := 30687;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,30000,30000,11,50324,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bone Armor');

-- Shambling Zombie
SET @ENTRY := 32503;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,9000,9000,16800,18900,11,61095,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Plague Blast');

-- Shambling Zombie
SET @ENTRY := 32499;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,9000,9000,16800,18900,11,61095,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Plague Blast');

-- Sigrid Iceborn
SET @ENTRY := 30086;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,61168,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,1,0,0,0,100,0,3000,7000,13000,16700,11,61164,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Impale'),
(@ENTRY,0,2,0,13,0,100,0,12000,18000,0,0,11,57635,0,0,0,0,0,6,1,0,0,0,0,0,0,'Cast Disengage on Target Spellcast'),
(@ENTRY,0,3,0,1,0,100,0,500,1000,600000,600000,11,61165,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frostbite Weapon on Spawn');

-- Sigrid Iceborn
SET @ENTRY := 31242;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,61168,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,1,0,0,0,100,0,3000,7000,13000,16700,11,61164,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Impale'),
(@ENTRY,0,2,0,13,0,100,0,12000,18000,0,0,11,57635,0,0,0,0,0,6,1,0,0,0,0,0,0,'Cast Disengage on Target Spellcast'),
(@ENTRY,0,3,0,1,0,100,0,500,1000,600000,600000,11,61165,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frostbite Weapon on Spawn');

-- Sigrid Iceborn
SET @ENTRY := 30086;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,61168,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,1,0,0,0,100,0,3000,7000,13000,16700,11,61164,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Impale'),
(@ENTRY,0,2,0,13,0,100,0,12000,18000,0,0,11,57635,0,0,0,0,0,6,1,0,0,0,0,0,0,'Cast Disengage on Target Spellcast'),
(@ENTRY,0,3,0,1,0,100,0,500,1000,600000,600000,11,61165,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frostbite Weapon on Spawn');

-- Stormwind Champion
SET @ENTRY := 33747;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,50,1,0,0,0,0,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,1,0,4,0,50,1,0,0,0,0,11,65147,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield-Breaker on Aggro');

-- Stormwind Valiant
SET @ENTRY := 33561;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,50,1,0,0,0,0,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,1,0,4,0,50,1,0,0,0,0,11,65147,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield-Breaker on Aggro');

-- Skybreaker Infantry
SET @ENTRY := 31701;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,15547,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,0,3500,4900,13400,15700,11,29426,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Strike');

-- Skeletal Runesmith
SET @ENTRY := 31321;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,1,100,0,4700,4900,11300,14500,11,42724,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,1,0,0,1,100,0,3000,9000,19000,19000,11,46202,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pierce Armor');

-- Skeletal Runesmith
SET @ENTRY := 30921;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,1,100,0,3000,9000,19000,19000,11,46202,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pierce Armor');

-- Sky-Reaver Korm Blackscar
SET @ENTRY := 30824;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,1,100,0,5000,5000,13400,14500,11,42724,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave');

-- Skybreaker Infiltrator
SET @ENTRY := 32222;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,1,100,0,3400,3500,11300,12900,11,15667,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sinister Strike');

-- Skeletal Craftsman
SET @ENTRY := 32164;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,1,100,0,4700,4900,11300,14500,11,42724,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,1,0,0,1,100,0,3000,9000,19000,19000,11,46202,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pierce Armor');

-- Skybreaker Marine
SET @ENTRY := 31701;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,23337,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,0,5000,7000,14000,15000,11,12024,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Net');

-- Skybreaker Squad Leader
SET @ENTRY := 31737;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,15547,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,0,4500,5000,11200,13400,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,2,0,0,0,100,0,9000,9000,18000,22300,11,12551,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frost Shot');

-- Spiked Ghoul
SET @ENTRY := 30597;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,5800,11300,17600,11,54185,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Claw Slash'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,60876,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Jagged Spike on Aggro');

-- Umbral Brute
SET @ENTRY := 30922;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,50420,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP'),
(@ENTRY,0,2,0,0,0,100,0,3500,4900,11300,15600,11,13446,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike'),
(@ENTRY,0,3,0,0,0,100,0,8000,8000,18000,22000,11,10966,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Uppercut');
-- NPC talk text insert
SET @ENTRY := 30922;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage');

-- Thunder Bluff Champion
SET @ENTRY := 33748;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,50,1,0,0,0,0,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,1,0,4,0,50,1,0,0,0,0,11,65147,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield-Breaker on Aggro');

-- Thunder Bluff Valiant
SET @ENTRY := 33383;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,50,1,0,0,0,0,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,1,0,4,0,50,1,0,0,0,0,11,65147,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield-Breaker on Aggro');

-- The Ocular
SET @ENTRY := 29747;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 1 on Aggro'),
(@ENTRY,0,1,0,4,1,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving on Aggro'),
(@ENTRY,0,2,0,0,1,100,0,1000,3000,1000,3000,11,55269,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Deathly Stare');

-- Valhalas Vargul
SET @ENTRY := 30250;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,7000,11300,15600,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave');

-- Undercity Champion
SET @ENTRY := 33749;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,50,1,0,0,0,0,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,1,0,4,0,50,1,0,0,0,0,11,65147,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield-Breaker on Aggro');

-- Umbral Brute
SET @ENTRY := 31320;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,7000,13500,16800,11,13446,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike'),
(@ENTRY,0,1,0,0,0,100,0,9000,11000,21000,26000,11,10966,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Uppercut');

-- The Leaper
SET @ENTRY := 29859;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,7000,13500,16800,11,60195,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sinister Strike'),
(@ENTRY,0,1,0,0,0,100,0,9000,11000,21000,26000,11,60177,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Hunger For Blood');

-- Undercity Valiant
SET @ENTRY := 33384;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,50,1,0,0,0,0,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,1,0,4,0,50,1,0,0,0,0,11,65147,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield-Breaker on Aggro');

-- Underking Talonox
SET @ENTRY := 30830;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,11000,16000,11,60802,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mandible Crush'),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,23000,24500,11,50284,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blinding Swarm');

-- Undying Minion
SET @ENTRY := 31152;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5000,16000,21000,11,60626,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Necrotic Strike');

-- Talla
SET @ENTRY := 31194;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,13700,16800,11,14873,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sinister Strike');

-- The Black Knight
SET @ENTRY := 33785;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,50,1,0,0,0,0,11,63010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,1,0,4,0,50,1,0,0,0,0,11,65147,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield-Breaker on Aggro');

-- The Leaper
SET @ENTRY := 29840;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,7000,13500,16800,11,60195,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sinister Strike'),
(@ENTRY,0,1,0,0,0,100,0,9000,11000,21000,26000,11,60177,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Hunger For Blood');

-- Vargul Assailant
SET @ENTRY := 30471;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4500,5599,13400,15600,11,43410,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chop'),
(@ENTRY,0,1,0,0,0,100,0,8000,9000,35000,37000,11,23262,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demoralize');

-- Val'kyr Taskmistress
SET @ENTRY := 31396;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4600,15400,7800,16200,11,59047,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Backhand'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,19000,20000,11,57547,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Touch of the Val\'kyr');

-- Vile
SET @ENTRY := 29860;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,13000,16700,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Backhand'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,25000,29000,11,37548,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Taunt'),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,56646,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP');

-- Vile
SET @ENTRY := 29769;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,13000,16700,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Backhand'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,25000,29000,11,37548,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Taunt'),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,56646,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP');

-- Vault Geist
SET @ENTRY := 29720;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,16000,17000,11,36590,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rip');

-- Water Terror
SET @ENTRY := 30633;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,60869,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt');

-- Wrathstrike Gargoyle
SET @ENTRY := 30482;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,13400,16700,11,16564,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gargoyle Strike');

-- Wrathstrike Gargoyle
SET @ENTRY := 31040;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,13400,16700,11,16564,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gargoyle Strike');

-- Volgur
SET @ENTRY := 30483;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,49758,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,5000,5600,12000,13400,11,43410,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chop'),
(@ENTRY,0,2,0,0,0,100,0,9000,9000,23400,25500,11,23262,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Demoralize'),
(@ENTRY,0,3,0,0,0,80,0,6000,14000,19000,28000,11,49807,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirlwind');

-- Vindicator Maraad
SET @ENTRY := 30833;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4500,6700,13400,16700,11,17281,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crusader Strike'),
(@ENTRY,0,1,0,2,0,100,1,0,50,0,0,11,29427,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Holy Light at 50% HP');

-- Valiance Commando
SET @ENTRY := 31414;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,15547,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,0,3000,3500,15600,17800,11,31567,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Deterrence'),
(@ENTRY,0,2,0,0,0,100,0,9000,9000,34500,37800,11,35918,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Puncture Armor');

-- Ymirheim Chosen Warrior
SET @ENTRY := 31258;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,61227,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Jump Attack on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,3500,4500,11700,15700,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,2,0,0,0,100,0,6700,7900,14300,19200,11,35949,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bloodthirst');

-- Void Summoner <Cult of the Damned>
SET @ENTRY := 32259;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt');

-- Tinky Wickwhistle
SET @ENTRY := 30162;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7000,8000,15600,17800,11,61552,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wrench Strike'),
(@ENTRY,0,1,0,0,0,100,0,13000,14000,21300,23400,11,37666,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Heavy Dynamite');

-- Thexal Deathchill
SET @ENTRY := 32278;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,61747,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,18100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Armor on Spawn'),
(@ENTRY,0,2,0,0,0,100,0,5000,5000,17800,19900,11,60924,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lich Slap'),
(@ENTRY,0,3,0,0,0,100,0,7800,9800,60000,60000,11,59663,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Deathchill Empowerment'),
(@ENTRY,0,4,0,0,0,100,0,3400,12300,28900,29800,11,18099,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill Nova');

-- Vrykul Necrolord
SET @ENTRY := 31783;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15800,18300,11,32712,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Nova on Close'),
(@ENTRY,0,2,0,2,0,100,1,0,50,0,0,11,50027,0,0,0,0,0,2,1,0,0,0,0,0,0,'Cast Tug Soul at 50% HP');

-- Thane Ufrang the Mighty
SET @ENTRY := 29919;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,13800,15000,11,58460,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Brutal Strike'),
(@ENTRY,0,1,0,0,0,100,0,10000,11000,17800,18900,11,60868,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Powerful Smash'),
(@ENTRY,0,2,0,0,0,100,0,3000,4000,25000,26000,11,16509,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rend');

-- Thane Illskar
SET @ENTRY := 30475;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,19816,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15800,18300,11,17145,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blast Wave on Close'),
(@ENTRY,0,2,0,0,0,100,0,5000,7000,22000,23000,11,20754,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Rain of Fire'),
(@ENTRY,0,3,0,0,0,100,1,11000,11000,12000,12000,11,51779,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frostfire Bolt');

-- Warsong Raider
SET @ENTRY := 31435;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,27577,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Intercept on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,12000,14000,11,25710,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Strike'),
(@ENTRY,0,2,0,0,0,100,0,9000,9000,25000,27800,11,25710,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demoralizing Shout');

-- Ymirheim Defender
SET @ENTRY := 31746;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,59633,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,1,0,0,0,100,0,4000,6000,17900,19200,11,60988,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Poisoned Spear');

-- Ymirheim Spear Gun
SET @ENTRY := 31280;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 1 on Aggro'),
(@ENTRY,0,1,0,4,1,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving on Aggro'),
(@ENTRY,0,2,0,4,1,100,1,0,0,0,0,11,59894,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Launch Spear on Aggro'),
(@ENTRY,0,3,0,9,1,100,0,0,90,3500,4100,11,59894,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Launch Spear');

-- Ymirjar Element Shaper
SET @ENTRY := 31267;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,55216,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,2,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,0,0,100,0,5000,5000,18900,22300,11,61897,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Torn Earth');
-- NPC talk text insert
SET @ENTRY := 31267;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Wyrm Reanimator <Cult of the Damned>
SET @ENTRY := 31731;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,2,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,0,0,100,0,5000,5000,16700,17800,11,32063,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Corruption'),
(@ENTRY,0,4,0,0,0,100,0,8000,9100,11000,13000,11,11443,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Cripple');
-- NPC talk text insert
SET @ENTRY := 31731;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');
