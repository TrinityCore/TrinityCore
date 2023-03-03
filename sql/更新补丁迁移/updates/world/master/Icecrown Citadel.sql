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
 
  /* Raid Normal & Heroic for 10 & 25 people */
 /* Trash Mobs */
 
-- Ancient Skeletal Soldier
SET @ENTRY := 37012;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,69127,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill of the Throne on Spawn'),
(@ENTRY,0,1,0,0,0,100,30,5000,7000,8000,9000,11,70964,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Bash');

-- Argent Champion
SET @ENTRY := 37928;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,30,8,40,13600,14500,11,53625,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Heroic Leap on Close');

-- Blighted Abomination
SET @ENTRY := 37022;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,69127,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill of the Throne on Spawn'),
(@ENTRY,0,1,0,4,0,100,31,0,0,0,0,11,71140,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Scourge Hook on Aggro'),
(@ENTRY,0,2,0,9,0,100,30,0,5,3000,5000,11,40504,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Cleave on Close'),
(@ENTRY,0,3,0,0,0,100,30,5000,11000,24000,32000,11,71150,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Plague Cloud');

-- Blood Beast
SET @ENTRY := 38508;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,72723,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Resistant Skin on Spawn'),
(@ENTRY,0,1,0,4,0,100,31,0,0,0,0,11,72176,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blood Link on Aggro');

-- Chosen Zealot
SET @ENTRY := 32175;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,30,0,5,9000,12000,11,13445,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rend on Close'),
(@ENTRY,0,1,0,0,0,100,30,4000,4500,18000,25000,11,12530,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frailty');

-- Cultist Shard Watcher <Cult of the Damned>
SET @ENTRY := 32349;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,69127,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill of the Throne on Spawn'),
(@ENTRY,0,1,0,0,0,100,30,5000,6000,12000,15000,11,39175,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley'),
(@ENTRY,0,2,0,0,0,100,30,4000,4000,17000,18000,11,34441,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Word: Pain'),
(@ENTRY,0,3,0,0,0,100,30,7000,11000,20000,28000,11,31117,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Unstable Affliction'),
(@ENTRY,0,4,0,1,0,100,31,1000,1000,1000,1000,11,51733,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Aura on Spawn');

-- Darkfallen Advisor
SET @ENTRY := 37571;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,69127,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill of the Throne on Spawn'),
(@ENTRY,0,1,0,0,0,100,30,5000,9000,6000,11000,11,72057,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Lich Slap'),
(@ENTRY,0,2,0,16,0,100,30,72066,40,10000,20000,11,72066,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Shroud of Spell Warding on Friendlies Missing Buff'),
(@ENTRY,0,3,0,16,0,100,30,72065,50,10000,20000,11,72065,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Shroud of Protection on Friendlies Missing Buff');

-- Darkfallen Archmage <The San'layn>
SET @ENTRY := 37664;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,69127,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill of the Throne on Spawn'),
(@ENTRY,0,1,0,0,0,100,10,0,0,9000,13000,11,70409,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball'),
(@ENTRY,0,2,0,0,0,100,20,0,0,9000,13000,11,71153,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball'),
(@ENTRY,0,3,0,9,0,100,10,0,8,7000,11000,11,70407,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blast Wave on Close'),
(@ENTRY,0,4,0,9,0,100,20,0,8,7000,11000,11,70407,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blast Wave on Close'),
(@ENTRY,0,5,0,0,0,100,10,5000,12000,25000,35000,11,70408,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Amplify Magic'),
(@ENTRY,0,6,0,0,0,100,20,5000,12000,25000,35000,11,72336,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Amplify Magic'),
(@ENTRY,0,7,0,0,0,100,30,10000,16000,15000,21000,11,70410,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Polymorph: Spider');

-- Darkfallen Blood Knight <The San'layn>
SET @ENTRY := 37595;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,69127,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill of the Throne on Spawn'),
(@ENTRY,0,1,0,4,0,100,31,0,0,0,0,11,71736,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Vampiric Aura on Aggro'),
(@ENTRY,0,2,0,9,0,100,30,0,5,3000,6000,11,70437,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Unholy Strike on Close'),
(@ENTRY,0,3,0,0,0,100,30,8000,13000,8000,14000,11,70450,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blood Mirror');

-- Darkfallen Commander <The San'layn>
SET @ENTRY := 37662;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,69127,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill of the Throne on Spawn'),
(@ENTRY,0,1,0,4,0,100,31,0,0,0,0,11,70750,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Battle Shout on Aggro'),
(@ENTRY,0,2,0,0,0,100,10,2000,5000,12000,17000,11,70449,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Vampire Rush'),
(@ENTRY,0,3,0,0,0,100,20,2000,5000,12000,17000,11,71155,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Vampire Rush');

-- Darkfallen Lieutenant <The San'layn>
SET @ENTRY := 37665;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,69127,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill of the Throne on Spawn'),
(@ENTRY,0,1,0,0,0,100,10,5000,9000,8000,13000,11,70435,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rend Flesh'),
(@ENTRY,0,2,0,0,0,100,20,5000,9000,8000,13000,11,71154,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rend Flesh'),
(@ENTRY,0,3,0,0,0,100,30,4000,5000,20000,27000,11,70423,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Vampiric Curse');

-- Darkfallen Noble <The San'layn>
SET @ENTRY := 37663;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,10,0,0,3400,4700,11,72960,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,1,0,0,0,100,20,0,0,3400,4700,11,72961,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,2,0,11,0,100,31,0,0,0,0,11,69127,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill of the Throne on Spawn'),
(@ENTRY,0,3,0,0,0,100,30,7000,12000,13000,17000,11,70645,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Chains of Shadow');

-- Darkfallen Tactician <The San'layn>
SET @ENTRY := 37666;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,69127,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill of the Throne on Spawn'),
(@ENTRY,0,1,0,9,0,100,30,0,5,6000,11000,11,70437,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Unholy Strike on Close'),
(@ENTRY,0,2,0,0,0,100,30,7000,12000,12000,16000,11,70432,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Blood Sap'),
(@ENTRY,0,3,0,9,0,100,30,10,30,16000,24000,11,70431,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadowstep on Close');

-- Deathbound Ward
SET @ENTRY := 37007;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,69127,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill of the Throne on Spawn'),
(@ENTRY,0,1,0,0,0,100,30,5000,7000,5000,8000,11,71021,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Saber Lash'),
(@ENTRY,0,2,0,0,0,100,30,12000,20000,16000,24000,11,71022,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Disrupting Shout'),
(@ENTRY,0,3,0,0,0,100,30,1,80,1000,1000,38,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Combat on LOS'),
(@ENTRY,0,4,0,4,0,100,31,0,0,0,0,38,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Combat on Aggro');

-- Deathspeaker Attendant <Cult of the Damned>
SET @ENTRY := 36811;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,69127,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill of the Throne on Spawn'),
(@ENTRY,0,1,0,0,0,100,30,0,0,3400,4700,11,69387,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,2,0,0,0,100,10,10000,15000,10000,15000,11,69355,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Nova'),
(@ENTRY,0,3,0,0,0,100,20,10000,15000,10000,15000,11,71106,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Nova');

-- Deathspeaker Disciple <Cult of the Damned>
SET @ENTRY := 36807;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,69127,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill of the Throne on Spawn'),
(@ENTRY,0,1,0,0,0,100,30,0,0,3400,4700,11,69387,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,2,0,14,0,100,10,100000,50,7000,11000,11,69389,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Shadow Mend on Friendlies'),
(@ENTRY,0,3,0,14,0,100,20,100000,50,7000,11000,11,71107,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Shadow Mend on Friendlies'),
(@ENTRY,0,4,0,16,0,100,30,69391,30,5000,9000,11,69391,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Dark Blessing on Friendlies Missing Buff');

-- Deathspeaker High Priest <Cult of the Damned>
SET @ENTRY := 36829;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,69127,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill of the Throne on Spawn'),
(@ENTRY,0,1,0,4,0,100,31,0,0,0,0,11,69491,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Aura of Darkness on Aggro'),
(@ENTRY,0,2,0,0,0,100,30,5000,7000,10000,12000,11,69483,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Dark Reckoning');

-- Deathspeaker Servant <Cult of the Damned>
SET @ENTRY := 36805;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,69127,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill of the Throne on Spawn'),
(@ENTRY,0,1,0,0,0,100,10,4000,7000,4000,7000,11,69576,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Chaos Bolt'),
(@ENTRY,0,2,0,0,0,100,20,4000,7000,4000,7000,11,71108,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Chaos Bolt'),
(@ENTRY,0,3,0,0,0,100,10,7000,13000,7000,13000,11,69404,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Curse of Agony'),
(@ENTRY,0,4,0,0,0,100,20,7000,13000,7000,13000,11,71112,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Curse of Agony'),
(@ENTRY,0,5,0,0,0,100,30,5000,9000,6000,12000,11,69405,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Consuming Shadows');

-- Deathspeaker Zealot <Cult of the Damned>
SET @ENTRY := 36808;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,69127,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill of the Throne on Spawn'),
(@ENTRY,0,1,0,0,0,100,30,3000,6000,3000,6000,11,69492,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Cleave');

-- Decaying Colossus
SET @ENTRY := 36880;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,69127,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill of the Throne on Spawn'),
(@ENTRY,0,1,0,0,0,100,10,5000,12000,10000,15000,11,71114,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Massive Stomp'),
(@ENTRY,0,2,0,0,0,100,20,5000,12000,10000,15000,11,71115,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Massive Stomp');

-- Ebon Champion
SET @ENTRY := 37996;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,2000,4500,12000,20000,11,66019,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Death Coil'),
(@ENTRY,0,1,0,0,0,100,30,3000,6000,10000,10000,11,66047,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frost Strike'),
(@ENTRY,0,2,0,0,0,100,30,7000,7000,18000,18000,11,66021,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Icy Touch');

-- Ebon Knight
SET @ENTRY := 32309;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,2000,4500,12000,20000,11,52375,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Death Coil'),
(@ENTRY,0,1,0,0,0,100,30,3000,6000,10000,10000,11,52374,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blood Strike'),
(@ENTRY,0,2,0,0,0,100,30,7000,7000,18000,18000,11,52372,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Icy Touch'),
(@ENTRY,0,3,0,9,0,100,30,10,30,12000,15000,11,57602,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Death Grip on Close');

-- Empowered Vampiric Fiend
SET @ENTRY := 37919;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,41290,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Disease Cloud on Spawn'),
(@ENTRY,0,1,0,0,0,100,30,2000,4500,12000,14000,11,70710,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Leeching Rot');

-- Faceless Lurker
SET @ENTRY := 31691;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,1000,1000,120000,121000,11,52342,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Seething Evil');

-- Frenzied Abomination
SET @ENTRY := 37546;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,69127,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill of the Throne on Spawn'),
(@ENTRY,0,1,0,0,0,100,30,3000,5000,3000,5000,11,70191,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,2,3,2,0,100,31,0,20,0,0,11,70371,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 20% HP'),
(@ENTRY,0,3,0,61,0,100,31,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 20% HP');
-- NPC talk text insert
SET @ENTRY := 37546;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage');

-- Frostwarden Handler
SET @ENTRY := 37531;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,69127,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill of the Throne on Spawn'),
(@ENTRY,0,1,0,0,0,100,10,6000,12000,8000,14000,11,71337,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Concussive Shock'),
(@ENTRY,0,2,0,0,0,100,20,6000,12000,8000,14000,11,71338,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Concussive Shock');

-- Frostwarden Sorceress
SET @ENTRY := 37229;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,69127,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill of the Throne on Spawn'),
(@ENTRY,0,1,0,0,0,100,30,6000,7000,15000,20000,11,71330,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Ice Tomb'),
(@ENTRY,0,2,0,0,0,100,30,0,0,3400,4700,11,71318,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frostbolt'),
(@ENTRY,0,3,0,9,0,100,30,0,8,13600,14500,11,71320,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Nova on Close');

-- Frostwarden Warrior
SET @ENTRY := 37228;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,69127,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill of the Throne on Spawn'),
(@ENTRY,0,1,0,9,0,100,30,0,5,9000,11000,11,71316,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Glacial Strike on Close'),
(@ENTRY,0,2,0,0,0,100,30,7000,8000,18000,20000,11,71325,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frostblade');

-- Frostwing Whelp
SET @ENTRY := 37532;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,69127,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill of the Throne on Spawn'),
(@ENTRY,0,1,0,0,0,100,30,3000,5000,15000,19000,11,71350,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Focus Fire'),
(@ENTRY,0,2,0,0,0,100,10,6000,9000,4000,7000,11,71361,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Frost Blast'),
(@ENTRY,0,3,0,0,0,100,20,6000,9000,4000,7000,11,71362,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Frost Blast');

-- Gluttonous Abomination
SET @ENTRY := 37886;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,69127,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill of the Throne on Spawn'),
(@ENTRY,0,1,0,6,0,100,3,0,0,0,0,11,70633,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Gut Spray on Death'),
(@ENTRY,0,2,0,6,0,100,5,0,0,0,0,11,71283,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Gut Spray on Death'),
(@ENTRY,0,3,0,6,0,100,9,0,0,0,0,11,72025,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Gut Spray on Death'),
(@ENTRY,0,4,0,6,0,100,17,0,0,0,0,11,72026,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Gut Spray on Death');

-- Harbinger of Horror
SET @ENTRY := 32278;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,69127,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill of the Throne on Spawn'),
(@ENTRY,0,1,0,1,0,100,30,500,1000,1800000,1800000,11,18100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Armor on Spawn'),
(@ENTRY,0,2,0,0,0,100,30,0,0,3400,4700,11,61747,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frostbolt'),
(@ENTRY,0,3,0,9,0,100,30,0,10,13500,14500,11,18099,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill Nova on Close'),
(@ENTRY,0,4,0,0,0,100,30,7000,9000,19000,25000,11,12096,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Fear'),
(@ENTRY,0,5,0,9,0,100,30,0,5,9000,11000,11,60924,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lich Slap on Close');

-- Kor'kron Defender
SET @ENTRY := 37032;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,10000,10000,18000,24000,11,69902,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Devastate'),
(@ENTRY,0,1,0,0,0,100,30,5000,6000,14000,25000,11,69903,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Slam'),
(@ENTRY,0,2,0,0,0,100,30,14000,14000,20000,20000,11,69903,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thunderclap');

-- Kor'kron Invoker
SET @ENTRY := 37033;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,8000,9000,18000,20000,11,69904,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blink'),
(@ENTRY,0,1,0,0,0,100,30,0,0,3400,4700,11,69869,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frostfire Bolt'),
(@ENTRY,0,2,0,11,0,100,31,0,0,0,0,11,69811,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Kor\'kron Battle Standard on Spawn');

-- Kor'kron Necrolyte
SET @ENTRY := 37149;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,0,0,3400,4700,11,69972,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,1,0,0,0,100,30,7000,8000,20000,22000,11,69969,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Curse of Doom');

-- Kor'kron Oracle
SET @ENTRY := 37031;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,0,0,3400,4700,11,69970,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lightning Bolt'),
(@ENTRY,0,1,0,16,0,100,30,69926,1,15000,30000,11,69926,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Earth Shield on Repeat'),
(@ENTRY,0,2,0,14,0,100,30,300000,40,15000,18000,11,69923,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Chain Heal on Friendlies'),
(@ENTRY,0,3,0,2,0,100,30,0,40,22000,25000,11,69958,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Healing Wave at 40% HP');

-- Kor'kron Primalist
SET @ENTRY := 37030;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,0,0,3400,4700,11,69968,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wrath'),
(@ENTRY,0,1,0,14,0,100,30,200000,40,15000,18000,11,69882,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Regrowth on Friendlies'),
(@ENTRY,0,2,0,14,0,100,30,100000,40,14000,22000,11,69898,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Rejuvenation on Friendlies'),
(@ENTRY,0,3,0,2,0,100,30,0,40,22000,25000,11,69899,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Healing Touch at 40% HP');

-- Kor'kron Reaver
SET @ENTRY := 37029;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,2000,4500,12000,20000,11,66019,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Death Coil'),
(@ENTRY,0,1,0,0,0,100,30,3000,6000,10000,10000,11,66047,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frost Strike'),
(@ENTRY,0,2,0,0,0,100,30,7000,7000,18000,18000,11,66021,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Icy Touch');

-- Kor'kron Sniper
SET @ENTRY := 37146;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,0,0,2300,3900,11,69974,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,30,5000,7000,15000,20000,11,69989,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Arcane Shot'),
(@ENTRY,0,2,0,0,0,100,30,9000,9000,18000,22000,11,69975,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Explosive Shot');

-- Kor'kron Templar
SET @ENTRY := 37034;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,0,0,3400,4700,11,69967,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Smite'),
(@ENTRY,0,1,0,2,0,100,30,0,55,14000,21000,11,69963,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Greater Heal at 55% HP'),
(@ENTRY,0,2,0,2,0,100,30,0,20,12000,16000,11,69910,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Pain Suppression at 20% HP');

-- Kor'kron Vanquisher
SET @ENTRY := 37035;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,7000,9000,18000,20000,11,69930,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Consecration'),
(@ENTRY,0,1,0,0,0,100,30,5000,5000,14000,15000,11,69934,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Holy Wrath'),
(@ENTRY,0,2,0,0,0,100,30,2000,3000,10000,12000,11,69927,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Avenger\'s Shield');

-- Nerub'ar Broodkeeper
SET @ENTRY := 36725;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,69127,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill of the Throne on Spawn'),
(@ENTRY,0,1,0,0,0,100,30,5000,7000,5000,9000,11,70965,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Crypt Scarabs'),
(@ENTRY,0,2,0,0,0,100,30,7000,11000,7000,11000,11,70980,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Web Wrap'),
(@ENTRY,0,3,0,0,0,100,30,1,80,1000,1000,38,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Combat on LOS'),
(@ENTRY,0,4,0,4,0,100,31,0,0,0,0,38,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Combat on Aggro'),
(@ENTRY,0,5,0,14,0,100,30,100000,40,8000,13000,11,36725,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Dark Mending on Friendlies');

-- Nerub'ar Champion
SET @ENTRY := 37501;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,69127,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill of the Throne on Spawn'),
(@ENTRY,0,1,0,4,0,100,31,0,0,0,0,11,71801,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rush on Aggro');

-- Nerub'ar Webweaver
SET @ENTRY := 37502;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,69127,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill of the Throne on Spawn'),
(@ENTRY,0,1,0,9,0,100,30,0,25,8000,9000,11,71327,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Web on Close'),
(@ENTRY,0,2,0,0,0,100,30,2000,4500,12000,13000,11,71326,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crypt Scarabs');

-- Plague Scientist
SET @ENTRY := 37023;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,69127,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill of the Throne on Spawn'),
(@ENTRY,0,1,0,0,0,100,30,10000,16000,12000,18000,11,71103,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Combobulating Spray'),
(@ENTRY,0,2,0,0,0,100,30,4000,9000,8000,11000,11,73079,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Plague Blast'),
(@ENTRY,0,3,0,0,0,100,30,15000,20000,15000,20000,11,69871,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Plague Stream');

-- Pustulating Horror
SET @ENTRY := 10404;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,69127,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill of the Throne on Spawn'),
(@ENTRY,0,1,0,0,0,100,30,5000,5000,12000,14000,11,71089,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Bubbling Pus'),
(@ENTRY,0,2,0,6,0,100,31,0,0,0,0,11,71088,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blight Bomb on Death');

-- Risen Deathspeaker Servant
SET @ENTRY := 36844;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,69127,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill of the Throne on Spawn'),
(@ENTRY,0,1,0,0,0,100,10,4000,7000,4000,7000,11,69576,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Chaos Bolt'),
(@ENTRY,0,2,0,0,0,100,20,4000,7000,4000,7000,11,71108,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Chaos Bolt'),
(@ENTRY,0,3,0,0,0,100,10,7000,13000,7000,13000,11,69404,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Curse of Agony'),
(@ENTRY,0,4,0,0,0,100,20,7000,13000,7000,13000,11,71112,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Curse of Agony'),
(@ENTRY,0,5,0,0,0,100,30,5000,9000,6000,12000,11,69405,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Consuming Shadows');

-- Servant of the Throne
SET @ENTRY := 36724;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,69127,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill of the Throne on Spawn'),
(@ENTRY,0,1,0,0,0,100,30,3000,5000,7000,11000,11,71029,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Glacial Blast');

-- Skybreaker Assassin
SET @ENTRY := 37017;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,2000,4500,12000,13000,11,69920,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sinister Strike'),
(@ENTRY,0,1,0,0,0,100,30,7000,8000,18000,22000,11,69921,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fan of Knives');

-- Skybreaker Dreadblade
SET @ENTRY := 37004;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,2000,4500,12000,20000,11,69911,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blood Plague'),
(@ENTRY,0,1,0,0,0,100,30,3000,6000,10000,10000,11,69912,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Plague Strike'),
(@ENTRY,0,2,0,0,0,100,30,7000,7000,18000,18000,11,69916,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Icy Touch');

-- Skybreaker Hierophant
SET @ENTRY := 37027;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,0,0,3400,4700,11,69968,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wrath'),
(@ENTRY,0,1,0,14,0,100,30,200000,40,15000,18000,11,69882,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Regrowth on Friendlies'),
(@ENTRY,0,2,0,14,0,100,30,100000,40,14000,22000,11,69898,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Rejuvenation on Friendlies'),
(@ENTRY,0,3,0,2,0,100,30,0,40,22000,25000,11,69899,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Healing Touch at 40% HP');

-- Skybreaker Luminary
SET @ENTRY := 37016;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,0,0,3400,4700,11,69970,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lightning Bolt'),
(@ENTRY,0,1,0,16,0,100,30,69926,1,15000,30000,11,69926,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Earth Shield on Repeat'),
(@ENTRY,0,2,0,14,0,100,30,300000,40,15000,18000,11,69923,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Chain Heal on Friendlies'),
(@ENTRY,0,3,0,2,0,100,30,0,40,22000,25000,11,69958,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Healing Wave at 40% HP');
 
-- Skybreaker Marksman
SET @ENTRY := 37144;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,0,0,2300,3900,11,69974,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,30,5000,7000,15000,20000,11,69989,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Arcane Shot'),
(@ENTRY,0,2,0,0,0,100,30,9000,9000,18000,22000,11,69975,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Explosive Shot');
 
-- Skybreaker Protector
SET @ENTRY := 36998;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,10000,10000,18000,24000,11,69902,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Devastate'),
(@ENTRY,0,1,0,0,0,100,30,5000,6000,14000,25000,11,69903,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Slam'),
(@ENTRY,0,2,0,0,0,100,30,14000,14000,20000,20000,11,69903,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thunderclap');

-- Skybreaker Sorcerer
SET @ENTRY := 37026;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,8000,9000,18000,20000,11,69904,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blink'),
(@ENTRY,0,1,0,0,0,100,30,0,0,3400,4700,11,69869,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frostfire Bolt'),
(@ENTRY,0,2,0,11,0,100,31,0,0,0,0,11,69810,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Skybreaker Battle Standard on Spawn');

-- Skybreaker Summoner
SET @ENTRY := 37148;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,0,0,3400,4700,11,69972,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,1,0,0,0,100,30,7000,8000,20000,22000,11,69969,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Curse of Doom');

-- Skybreaker Vicar
SET @ENTRY := 37021;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,0,0,3400,4700,11,69967,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Smite'),
(@ENTRY,0,1,0,2,0,100,30,0,55,14000,21000,11,69963,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Greater Heal at 55% HP'),
(@ENTRY,0,2,0,2,0,100,30,0,20,12000,16000,11,69910,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Pain Suppression at 20% HP');

-- Skybreaker Vindicator
SET @ENTRY := 37003;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,7000,9000,18000,20000,11,69930,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Consecration'),
(@ENTRY,0,1,0,0,0,100,30,5000,5000,14000,15000,11,69934,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Holy Wrath'),
(@ENTRY,0,2,0,0,0,100,30,2000,3000,10000,12000,11,69927,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Avenger\'s Shield');

-- Spire Frostwyrm
SET @ENTRY := 37230;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,7000,9000,18000,24000,11,70362,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Blizzard'),
(@ENTRY,0,1,0,0,0,100,30,4000,5000,12000,14000,11,70116,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frost Breath');

-- Spire Gargoyle
SET @ENTRY := 37544;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,69127,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill of the Throne on Spawn'),
(@ENTRY,0,1,0,0,0,100,30,3000,5000,6000,9000,11,70189,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Poison Spit');

-- Spire Minion
SET @ENTRY := 37545;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,69127,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill of the Throne on Spawn'),
(@ENTRY,0,1,0,2,0,100,30,0,50,15000,24000,11,70363,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Cannibalize at 50% HP'),
(@ENTRY,0,2,0,9,0,100,30,0,5,6000,9000,11,70396,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ghoul Slash on Close');

-- The Damned
SET @ENTRY := 37011;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,69127,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill of the Throne on Spawn'),
(@ENTRY,0,1,0,0,0,100,30,10000,15000,10000,15000,11,70960,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bone Flurry'),
(@ENTRY,0,2,0,6,0,100,31,0,0,0,0,11,70961,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shattered Bones on Death');

-- Torgo the Elder
SET @ENTRY := 38194;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,30,2000,4500,12000,20000,11,66019,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Death Coil'),
(@ENTRY,0,1,0,0,0,100,30,3000,6000,10000,10000,11,66047,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frost Strike'),
(@ENTRY,0,2,0,0,0,100,30,7000,7000,18000,18000,11,66021,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Icy Touch');

-- Val'kyr Herald
SET @ENTRY := 37098;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,69127,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill of the Throne on Spawn'),
(@ENTRY,0,1,0,4,0,100,31,0,0,0,0,11,71906,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Severed Essence on Aggro');

-- Vampiric Fiend
SET @ENTRY := 37901;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,41290,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Disease Cloud on Spawn'),
(@ENTRY,0,1,0,0,0,100,30,2000,4500,12000,14000,11,70710,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Leeching Rot');

-- Vengeful Fleshreaper
SET @ENTRY := 37038;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,69127,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill of the Throne on Spawn'),
(@ENTRY,0,1,0,9,0,100,30,5,30,5000,10000,11,71164,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Leaping Face Maul on Close'),
(@ENTRY,0,2,0,0,0,100,30,4000,8000,18000,22000,11,71163,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Devour Humanoid');

-- Wicked Spirit
SET @ENTRY := 39190; 
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY; 
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY; 
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,6,0,100,31,0,0,0,0,11,70503,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spirit Burst on Death');

-- Ymirjar Battle-Maiden
SET @ENTRY := 37132;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,69127,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill of the Throne on Spawn'),
(@ENTRY,0,1,0,0,0,100,30,9000,11000,16000,24000,11,71258,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Adrenaline Rush'),
(@ENTRY,0,2,0,9,0,100,30,0,5,5000,8000,11,71257,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Barbaric Strike on Close');

-- Ymirjar Deathbringer
SET @ENTRY := 38125;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,69127,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill of the Throne on Spawn'),
(@ENTRY,0,1,0,0,0,100,10,0,0,3400,4700,11,71296,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,2,0,0,0,100,20,0,0,3400,4700,11,71297,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,3,0,0,0,100,30,4000,6000,6000,8000,11,71298,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Banish'),
(@ENTRY,0,4,0,16,0,100,30,69929,40,35000,50000,11,69929,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Spirit Stream on Friendlies Missing Buff'),
(@ENTRY,0,5,0,2,0,100,10,0,50,18000,25000,11,71299,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Death\'s Embrace at 50% HP'),
(@ENTRY,0,6,0,2,0,100,20,0,50,18000,25000,11,71300,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Death\'s Embrace at 50% HP'),
(@ENTRY,0,7,0,2,0,100,31,0,40,0,0,11,71303,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Ymirjar at 40% HP');

-- Ymirjar Frostbinder
SET @ENTRY := 37127;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,69127,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill of the Throne on Spawn'),
(@ENTRY,0,1,0,4,0,100,31,0,0,0,0,11,71270,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arctic Chill on Aggro'),
(@ENTRY,0,2,0,0,0,100,30,7000,14000,12000,17000,11,71306,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Twisted Winds'),
(@ENTRY,0,3,0,0,0,100,30,15000,20000,15000,20000,11,71274,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frozen Orb');

-- Ymirjar Huntress
SET @ENTRY := 37134;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,69127,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill of the Throne on Spawn'),
(@ENTRY,0,1,0,1,0,100,31,3000,5000,0,0,11,71705,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Warhawk on Spawn'),
(@ENTRY,0,2,0,0,0,100,30,0,0,2300,3900,11,71253,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,3,0,0,0,100,30,8000,9000,9000,14000,11,71252,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Volley'),
(@ENTRY,0,4,0,0,0,100,30,12000,16000,14000,18000,11,71251,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Rapid Shot'),
(@ENTRY,0,5,0,0,0,100,30,5000,10000,7000,14000,11,71249,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Ice Trap');

-- Ymirjar Warlord
SET @ENTRY := 37133;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,31,0,0,0,0,11,69127,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chill of the Throne on Spawn'),
(@ENTRY,0,1,0,9,0,100,30,0,5,8000,13000,11,41056,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirlwind on Close');
