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
 
  /* Dungeon Normal for 5 people */
    /* Trash Mobs & Bosses */
	
-- Bannok Grimaxe <Firebrand Legion Champion>
SET @ENTRY := 9596;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,8000,33000,34000,11,15128,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Mark of Flames'),
(@ENTRY,0,1,0,0,0,100,2,3000,4000,11000,12000,11,13737,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike'),
(@ENTRY,0,2,0,9,0,100,2,0,8,15800,18300,11,41057,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirlwind on Close');

-- Burning Felguard
SET @ENTRY := 10263;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,7000,4000,6000,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike'),
(@ENTRY,0,1,0,0,0,100,2,10000,10000,10000,10000,11,16046,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blast Wave'),
(@ENTRY,0,2,0,9,0,100,2,0,10,15000,20000,11,15548,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thunderclap on Close');

-- Crystal Fang
SET @ENTRY := 10376;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,10000,5000,10000,11,16416,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Spire Spiderling');

-- General Drakkisath
SET @ENTRY := 10363;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,3000,9000,12000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,1,0,0,0,100,2,7000,9000,12000,15000,11,16805,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Conflagration'),
(@ENTRY,0,2,0,0,0,100,2,4000,4000,8000,22000,11,16419,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flamestrike'),
(@ENTRY,0,3,0,0,0,100,2,2000,3000,14000,18000,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pierce Armor'),
(@ENTRY,0,4,0,2,0,100,3,0,30,0,0,11,16789,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rage at 30% HP'),
(@ENTRY,0,5,0,2,0,100,3,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP');
-- NPC talk text insert
SET @ENTRY := 10363;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes raged!',16,0,100,0,0,0, 'combat Rage');

-- Ghok Bashguud <Bloodaxe Champion>
SET @ENTRY := 9718;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,4000,12000,13000,11,87081,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike'),
(@ENTRY,0,1,0,13,0,100,2,12000,18000,0,0,11,11972,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Shield Bash on Target Spellcast'),
(@ENTRY,0,2,0,2,0,100,3,0,30,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP'),
(@ENTRY,0,3,0,2,0,100,3,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP');
-- NPC talk text insert
SET @ENTRY := 9718;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy');

-- Gizrul the Slavener
SET @ENTRY := 10268;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,2,0,20,30000,30000,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 20% HP'),
(@ENTRY,0,1,0,0,0,100,2,10000,10000,10000,10000,11,16495,0,0,0,0,0,2,1,0,0,0,0,0,0,'Cast Fatal Bite'),
(@ENTRY,0,2,0,0,0,100,2,15000,20000,10000,20000,11,16128,0,0,0,0,0,2,32,0,0,0,0,0,0,'Cast Infected Bite');

-- Goraluk Anvilcrack <Blackhand Legion Armorsmith>
SET @ENTRY := 10899;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,10000,20000,20000,11,16172,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Head Crack'),
(@ENTRY,0,1,0,0,0,100,2,10000,10000,10000,10000,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Backhand'),
(@ENTRY,0,2,0,0,0,100,2,5000,7000,4000,6000,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike');

-- Jed Runewatcher <Blackhand Legion>
SET @ENTRY := 10509;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,6000,10000,11,87081,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike on Close'),
(@ENTRY,0,1,0,0,0,100,2,7000,12000,12000,17000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Bash'),
(@ENTRY,0,2,0,4,0,100,3,0,0,0,0,11,15749,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Charge on Aggro');

-- Lord Valthalak
SET @ENTRY := 16042;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,8000,10000,12000,11,27289,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Wrath'),
(@ENTRY,0,1,0,4,0,100,3,0,0,0,0,11,27249,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Spectral Assassin on Aggro');

-- Solakar Flamewreath
SET @ENTRY := 10264;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,12000,16000,11,16727,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast War Stomp on Close');

-- Spirestone Lord Magus
SET @ENTRY := 9217;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,15230,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,2,5000,5000,12000,12000,11,13323,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Polymorph'),
(@ENTRY,0,2,0,2,0,100,2,0,50,10000,12000,11,8365,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enlarge at 50% HP'),
(@ENTRY,0,3,0,16,0,100,2,16171,30,20000,40000,11,16171,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Bloodlust on Friendlies');

-- Urok Doomhowl
SET @ENTRY := 10584;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,5000,9000,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike on Close'),
(@ENTRY,0,1,0,0,0,100,2,7000,8000,12000,14000,11,16508,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Intimidating Roar'),
(@ENTRY,0,2,0,0,0,100,2,9000,14000,17000,21000,11,16509,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rend');

-- Blackhand Assassin <Blackhand Legion>
SET @ENTRY := 10318;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,22766,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Spawn'),
(@ENTRY,0,1,0,7,0,100,3,0,0,0,0,11,22766,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Evade'),
(@ENTRY,0,2,0,0,0,100,2,10000,17000,22000,22000,11,12540,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gouge'),
(@ENTRY,0,3,0,67,0,100,2,3900,6900,0,0,11,15582,0,0,0,0,0,2,0,0,0,0,0,0,0,'Casts Backstab'),
(@ENTRY,0,4,0,0,0,100,2,5000,10000,33000,35000,11,6434,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Slice and Dice');

-- Blackhand Dragon Handler <Blackhand Legion>
SET @ENTRY := 10742;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,14,0,100,2,300000,10,20000,30000,11,16637,0,0,0,0,0,7,1,0,0,0,0,0,0,'Cast Mend Dragon on Friendlies');

-- Blackhand Dreadweaver <Blackhand Legion>
SET @ENTRY := 9817;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,12739,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,2,2,0,100,3,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,3,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,0,0,100,2,10000,15000,21000,22000,11,7068,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Veil of Shadow'),
(@ENTRY,0,4,0,0,0,100,2,5000,11000,15000,19000,11,16247,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Curse of Thorns');
-- NPC talk text insert
SET @ENTRY := 9817;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Blackhand Elite <Blackhand Legion>
SET @ENTRY := 10317;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,13000,17000,9000,28000,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike'),
(@ENTRY,0,1,0,0,0,100,2,15000,33000,25000,30000,11,16172,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Head Crack'),
(@ENTRY,0,2,0,0,0,100,2,5000,22000,11000,27000,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Backhand');

-- Blackhand Incarcerator <Blackhand Legion>
SET @ENTRY := 10316;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,12000,14000,18000,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike'),
(@ENTRY,0,1,0,0,0,100,2,10000,20000,30000,33000,11,16045,0,0,0,0,0,5,1,0,0,0,0,0,0,'Cast Encage');

-- Blackhand Iron Guard <Blackhand Legion>
SET @ENTRY := 10319;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,6000,18000,11,15655,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Slam on Close'),
(@ENTRY,0,1,0,2,0,100,2,0,50,12000,14000,11,15062,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shield Wall at 50% HP');

-- Blackhand Summoner <Blackhand Legion>
SET @ENTRY := 9818;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,12466,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,2,2,0,100,3,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,3,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,9,0,100,2,0,10,15800,17500,11,15532,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Nova on Close'),
(@ENTRY,0,4,0,0,0,50,3,2000,3000,0,0,11,15794,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Blackhand Dreadweaver'),
(@ENTRY,0,5,0,0,0,50,3,2000,3000,0,0,11,15792,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Blackhand Veteran');
-- NPC talk text insert
SET @ENTRY := 9818;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');


-- Blackhand Veteran <Blackhand Legion>
SET @ENTRY := 9819;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,15749,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Charge on Aggro'),
(@ENTRY,0,1,0,9,0,100,2,0,5,13000,22000,11,14516,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike on Close'),
(@ENTRY,0,2,0,0,0,100,2,9000,12000,15000,18000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Bash');

-- Bloodaxe Evoker <Bloodaxe Legion>
SET @ENTRY := 9693;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,13748,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,2,2,0,100,3,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,3,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,9,0,100,2,0,10,14500,16800,11,15744,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blast Wave on Close'),
(@ENTRY,0,4,0,0,0,100,2,12000,14000,25000,26000,11,15743,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Flamecrack');
-- NPC talk text insert
SET @ENTRY := 9693;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Bloodaxe Raider <Bloodaxe Legion>
SET @ENTRY := 9692;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,6000,22000,24000,11,15572,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sunder Armor'),
(@ENTRY,0,1,0,0,0,100,2,3000,4000,11000,13000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave');

-- Bloodaxe Summoner <Bloodaxe Legion>
SET @ENTRY := 9717;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,15791,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,2,2,0,100,3,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,3,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,9,0,100,2,0,10,15000,16800,11,15532,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Nova on Close'),
(@ENTRY,0,4,0,0,0,100,2,8000,11000,14000,37000,11,15734,0,0,0,0,0,5,1,0,0,0,0,0,0,'Cast Summon');
-- NPC talk text insert
SET @ENTRY := 9717;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Bloodaxe Veteran <Bloodaxe Legion>
SET @ENTRY := 9583;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,12000,13000,9000,15000,11,15618,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Snap Kick'),
(@ENTRY,0,1,0,0,0,100,2,5000,5000,9000,11000,11,15615,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pummel');

-- Bloodaxe Warmonger <Bloodaxe Legion>
SET @ENTRY := 9716;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,3,0,30,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP'),
(@ENTRY,0,1,0,2,0,100,3,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP'),
(@ENTRY,0,2,0,0,0,100,2,5000,9000,9000,13000,11,10966,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Uppercut');
-- NPC talk text insert
SET @ENTRY := 9716;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy');

-- Chromatic Dragonspawn
SET @ENTRY := 10447;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,11000,10000,21000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,1,0,9,0,100,2,0,5,6000,16000,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike on Close');

-- Chromatic Elite Guard
SET @ENTRY := 10814;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,12000,12000,14000,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike'),
(@ENTRY,0,1,0,0,0,100,2,12000,14000,9000,19000,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike'),
(@ENTRY,0,2,0,0,0,100,2,5000,15000,11000,25000,11,11428,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Knockdown');

-- Chromatic Whelp
SET @ENTRY := 10442;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,16249,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,2,8000,8000,12000,12000,11,12167,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lightning Bolt'),
(@ENTRY,0,2,0,9,0,100,2,0,8,14000,15000,11,16250,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fireball Volley on Close');

-- Firebrand Pyromancer <Firebrand Legion>
SET @ENTRY := 9264;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,25000,29000,11,15128,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Mark of Flames'),
(@ENTRY,0,1,0,0,0,100,2,4000,4000,8000,12000,11,15096,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Shock'),
(@ENTRY,0,2,0,0,0,100,2,4000,9000,16000,18000,11,15732,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Immolate');

-- Firebrand Legionnaire <Firebrand Legion>
SET @ENTRY := 9260;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,3000,10500,14500,11,3248,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Improved Blocking'),
(@ENTRY,0,1,0,9,0,100,2,0,5,6000,11000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Bash on Close'),
(@ENTRY,0,2,0,0,0,100,2,5000,6000,30000,30000,11,15128,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Mark of Flames');

-- Firebrand Darkweaver <Firebrand Legion>
SET @ENTRY := 9261;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,12471,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,2,2,0,100,3,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,3,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,0,0,100,2,4000,6000,30000,35000,11,15128,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Mark of Flames'),
(@ENTRY,0,4,0,0,0,100,2,9000,14000,9000,14000,11,15090,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Dispel Magic'),
(@ENTRY,0,5,0,0,0,100,2,1000,4000,12000,15000,11,16071,0,0,0,0,0,5,32,0,0,0,0,0,0,'Cast Curse of the Firebrand'),
(@ENTRY,0,6,0,9,0,100,2,0,10,15000,16800,11,14887,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley on Close');
-- NPC talk text insert
SET @ENTRY := 9261;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Firebrand Dreadweaver <Firebrand Legion>
SET @ENTRY := 9263;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,33000,38000,11,15128,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Mark of Flames'),
(@ENTRY,0,1,0,0,0,100,2,1000,4000,12000,15000,11,16071,0,0,0,0,0,5,32,0,0,0,0,0,0,'Cast Curse of the Firebrand'),
(@ENTRY,0,2,0,0,0,100,2,10000,15000,10000,20000,11,15728,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Plague Cloud'),
(@ENTRY,0,3,0,16,0,100,2,15729,30,15000,22000,11,15729,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Remove Curse on Friendlies');

-- Firebrand Grunt <Firebrand Legion>
SET @ENTRY := 9259;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,3,0,30,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP'),
(@ENTRY,0,1,0,2,0,100,3,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP'),
(@ENTRY,0,2,0,0,0,100,2,7000,8000,33000,38000,11,15128,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Mark of Flames'),
(@ENTRY,0,3,0,0,0,100,2,4000,4000,9000,11000,11,13737,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike');
-- NPC talk text insert
SET @ENTRY := 9259;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy');

-- Firebrand Invoker <Firebrand Legion>
SET @ENTRY := 9262;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,12466,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,2,2,0,100,3,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,3,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,9,0,100,2,0,10,15000,15000,11,12470,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fire Nova on Close'),
(@ENTRY,0,4,0,0,0,100,2,8000,8000,15000,17000,11,12468,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flamestrike'),
(@ENTRY,0,5,0,0,0,100,2,7000,8000,33000,38000,11,15128,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Mark of Flames');
-- NPC talk text insert
SET @ENTRY := 9262;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Rage Talon Captain
SET @ENTRY := 10371;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,15000,9000,20000,11,16169,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcing Smash'),
(@ENTRY,0,1,0,0,0,100,2,14000,32000,15000,21000,11,10101,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Knock Away'),
(@ENTRY,0,2,0,0,0,100,2,8000,11000,8000,31000,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike');

-- Rage Talon Dragon Guard
SET @ENTRY := 10366;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,13000,19000,12000,24000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,1,0,0,0,100,2,5000,9000,15000,19000,11,16145,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sunder Armor'),
(@ENTRY,0,2,0,0,0,100,2,11000,12000,9000,25000,11,15655,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Slam');

-- Rage Talon Dragonspawn
SET @ENTRY := 9096;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,8000,9000,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thrash'),
(@ENTRY,0,1,0,0,0,100,2,6000,9000,7000,13000,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike'),
(@ENTRY,0,2,0,0,0,100,2,5000,6000,33000,34000,11,15572,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sunder Armor'),
(@ENTRY,0,3,0,0,0,100,2,8000,11000,15000,19000,11,12021,0,0,0,0,0,2,1,0,0,0,0,0,0,'Cast Fixate'),
(@ENTRY,0,4,0,2,0,100,3,0,30,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP'),
(@ENTRY,0,5,0,2,0,100,3,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP');
-- NPC talk text insert
SET @ENTRY := 9096;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy');

-- Rage Talon Fire Tongue
SET @ENTRY := 10372;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,9000,3000,11000,11,16144,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fire Blast'),
(@ENTRY,0,1,0,9,0,100,2,0,8,13000,20000,11,16635,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fire Nova on Close'),
(@ENTRY,0,2,0,0,0,100,2,3000,5000,16000,17000,11,16168,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Flame Buffet');

-- Rage Talon Flamescale
SET @ENTRY := 10083;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,9000,15000,19000,11,18399,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flamestrike'),
(@ENTRY,0,1,0,9,0,100,2,0,10,13000,22000,11,12470,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fire Nova on Close'),
(@ENTRY,0,2,0,0,0,100,2,8000,11000,16000,21000,11,15285,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fireball Volley');

-- Rookery Guardian
SET @ENTRY := 10258;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,11000,12000,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike'),
(@ENTRY,0,1,0,0,0,100,2,7000,9000,19000,22000,11,15572,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sunder Armor');

-- Rookery Hatcher
SET @ENTRY := 10683;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,11000,12000,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike'),
(@ENTRY,0,1,0,0,0,100,2,7000,9000,19000,22000,11,15572,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sunder Armor');

-- Scarshield Legionnaire <Scarshield Legion>
SET @ENTRY := 9097;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,7000,11000,8000,22000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,1,0,9,0,100,2,0,5,14000,20000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Bash on Close');

-- Scarshield Acolyte <Scarshield Legion>
SET @ENTRY := 9045;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,7000,15000,21000,33000,11,14032,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Shadow Word: Pain'),
(@ENTRY,0,1,0,2,0,100,3,0,75,0,0,11,12039,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Heal at 75% HP'),
(@ENTRY,0,2,0,14,0,100,2,5000,35,17000,24000,11,8362,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Renew on Friendlies');

-- Smolderthorn Axe Thrower
SET @ENTRY := 9267;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,15795,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,1,2,2,0,100,3,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,3,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,0,0,100,2,5000,8000,12000,14000,11,11428,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Knockdown'),
(@ENTRY,0,4,0,0,0,100,2,2000,4000,8000,9000,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thrash');
-- NPC talk text insert
SET @ENTRY := 9267;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Scarshield Warlock <Scarshield Legion>
SET @ENTRY := 9257;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,12471,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,2,2,0,100,3,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,3,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,0,0,100,2,10000,20000,60000,75000,11,15125,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Scarshield Portal');
-- NPC talk text insert
SET @ENTRY := 9257;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Scarshield Portal
SET @ENTRY := 9707;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,5000,5000,11,15126,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Burning Imp'),
(@ENTRY,0,1,0,0,0,100,2,11000,11000,11000,11000,11,16002,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Burning Felhound'),
(@ENTRY,0,2,0,0,0,100,2,20000,20000,20000,20000,11,16004,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Burning Felguard');

-- Scarshield Spellbinder <Scarshield Legion>
SET @ENTRY := 9098;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,13748,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,2,2,0,100,3,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,3,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,16,0,100,2,15123,30,3000,6000,11,15123,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Resist Fire on Friendlies'),
(@ENTRY,0,4,0,0,0,100,2,8000,8000,12000,15000,11,14033,1,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Mana Burn'),
(@ENTRY,0,5,0,13,0,100,2,12000,18000,0,0,11,15122,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Counterspell on Target Spellcast');
-- NPC talk text insert
SET @ENTRY := 9098;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Scarshield Raider <Scarshield Legion>
SET @ENTRY := 9258;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,6000,9000,11,12057,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike on Close'),
(@ENTRY,0,1,0,9,0,100,2,0,30,9000,11000,11,14030,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Hooked Net on Close');

-- Smolderthorn Berserker
SET @ENTRY := 9268;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,3,0,30,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP'),
(@ENTRY,0,1,0,2,0,100,3,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP'),
(@ENTRY,0,2,0,0,0,100,2,8000,8000,17000,19000,11,19643,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike'),
(@ENTRY,0,3,0,0,0,100,2,3000,4000,9000,11000,11,13446,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike');
-- NPC talk text insert
SET @ENTRY := 9268;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy');

-- Smolderthorn Headhunter
SET @ENTRY := 9241;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,15795,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,1,2,2,0,100,3,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,3,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,0,0,100,2,5000,6000,12000,14000,11,16001,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Impale'),
(@ENTRY,0,4,0,9,0,100,2,0,5,12000,14000,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pierce Armor on Close');
-- NPC talk text insert
SET @ENTRY := 9241;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Smolderthorn Mystic
SET @ENTRY := 9239;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,16006,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,2,2,0,100,3,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,3,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,14,0,100,2,2000,40,10000,15000,11,15799,1,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Chain Heal on Friendlies');
-- NPC talk text insert
SET @ENTRY := 9239;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Smolderthorn Seer
SET @ENTRY := 9269;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,15801,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,2,2,0,100,3,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,3,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,1,0,100,2,1000,1000,600000,600000,11,13585,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lightning Shield on Spawn'),
(@ENTRY,0,4,0,16,0,100,2,13585,1,15000,30000,11,13585,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lightning Shield on Repeat'),
(@ENTRY,0,5,0,0,0,100,2,5000,8000,34000,36000,11,15802,1,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Shrink'),
(@ENTRY,0,6,0,14,0,100,2,2000,40,10000,15000,11,12492,1,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Healing Wave on Friendlies');
-- NPC talk text insert
SET @ENTRY := 9269;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Smolderthorn Shadow Hunter
SET @ENTRY := 9265;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY,0,0,0,67,0,100,2,3900,6900,0,0,11,15582,0,0,0,0,0,2,0,0,0,0,0,0,0,'Casts Backstab'),
(@ENTRY,0,1,0,0,0,100,2,5000,5000,12000,13000,11,12540,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gouge'),
(@ENTRY,0,2,0,0,0,100,2,7000,11000,10000,17000,11,76583,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Kick');

-- Spectral Assassin
SET @ENTRY := 16066;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,15000,25000,36000,11,27177,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Defile'),
(@ENTRY,0,1,0,0,0,100,2,4000,4000,9000,11000,11,18663,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Shock');

-- Spire Spider
SET @ENTRY := 10374;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,10000,20000,30000,30000,11,16103,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Spire Spiderling'),
(@ENTRY,0,1,0,0,0,100,2,5000,5000,15000,16000,11,16104,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crystallize');

-- Smolderthorn Shadow Priest
SET @ENTRY := 9240;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,10000,10000,11,15090,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Dispel Magic'),
(@ENTRY,0,1,0,0,0,100,2,6000,8000,5000,10000,11,14033,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Mana Burn'),
(@ENTRY,0,2,0,0,0,100,2,5000,10000,20000,20000,11,11641,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Hex');

-- Smolderthorn Witch Doctor
SET @ENTRY := 9266;
SET @ENTRYTOTEM := 10217;
SET @TOTEMSPELL := 9574;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
UPDATE `creature_template` SET `AIName`='0' WHERE `entry`=@ENTRYTOTEM;
UPDATE `creature_template` SET `spell1`=@TOTEMSPELL WHERE `entry`=@ENTRYTOTEM;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,20000,20000,20000,20000,11,15867,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Flame Buffet Totem'),
(@ENTRY,0,1,0,0,0,100,2,8000,12000,10000,15000,11,15869,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Superior Healing Ward'),
(@ENTRY,0,2,0,0,0,100,2,4000,5000,25000,32000,11,8262,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Elemental Protection Totem');

-- Spirestone Battle Mage
SET @ENTRY := 9197;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,10000,5000,15000,11,15305,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Chain Lightning'),
(@ENTRY,0,1,0,16,0,100,2,16170,30,10000,15000,11,16170,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Bloodlust on Friendlies');

-- Spirestone Enforcer
SET @ENTRY := 9199;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,5000,3000,6000,11,14516,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike'),
(@ENTRY,0,1,0,0,0,100,2,8000,8000,12000,17000,11,15976,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Puncture');

-- Spirestone Reaver
SET @ENTRY := 9200;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,15000,20000,11,11876,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast War Stomp on Close'),
(@ENTRY,0,1,0,0,0,100,2,5000,8000,3000,10000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave');

-- Spirestone Ogre Magus
SET @ENTRY := 9201;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,15979,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,2,2,0,100,3,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,3,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,16,0,100,2,6742,30,10000,15000,11,6742,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Bloodlust on Friendlies'),
(@ENTRY,0,4,0,0,0,100,2,3000,4000,5000,8000,11,13747,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Slow');
-- NPC talk text insert
SET @ENTRY := 9201;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Spirestone Mystic
SET @ENTRY := 9198;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,10000,5000,15000,11,15659,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Chain Lightning'),
(@ENTRY,0,1,0,0,0,100,2,5000,5000,10000,18000,11,8435,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Forked Lightning'),
(@ENTRY,0,2,0,14,0,100,2,3000,40,5000,10000,11,15981,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Rejuvenation on Friendlies'),
(@ENTRY,0,3,0,2,0,100,3,0,30,0,0,11,15982,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Healing Wave at 30% HP');

-- Spirestone Warlord
SET @ENTRY := 9216;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,3,0,30,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP'),
(@ENTRY,0,1,0,2,0,100,3,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP'),
(@ENTRY,0,2,0,0,0,100,2,5000,8000,12000,15000,11,16171,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Empower Will');
-- NPC talk text insert
SET @ENTRY := 9216;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy');

-- Urok Ogre Magus
SET @ENTRY := 10602;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,15979,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,2,2,0,100,3,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,3,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,16,0,100,2,6742,30,10000,15000,11,6742,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Bloodlust on Friendlies'),
(@ENTRY,0,4,0,0,0,100,2,3000,4000,5000,8000,11,13747,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Slow');
-- NPC talk text insert
SET @ENTRY := 10602;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Urok Enforcer
SET @ENTRY := 10601;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,5000,3000,6000,11,14516,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike'),
(@ENTRY,0,1,0,0,0,100,2,8000,8000,12000,17000,11,15976,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Puncture');

-- Summoned Blackhand Veteran <Blackhand Legion>
SET @ENTRY := 10681;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,6000,10000,11,87081,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike on Close'),
(@ENTRY,0,1,0,0,0,100,2,7000,12000,12000,17000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Bash'),
(@ENTRY,0,2,0,4,0,100,3,0,0,0,0,11,15749,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Charge on Aggro');

-- Summoned Blackhand Dreadweaver <Blackhand Legion>
SET @ENTRY := 10680;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,12739,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,2,2,0,100,3,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,3,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,0,0,100,2,5000,5000,17000,18000,11,16247,1,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Curse of Thorns'),
(@ENTRY,0,4,0,0,0,100,2,3000,5000,10000,10000,11,7068,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Veil of Shadow');
-- NPC talk text insert
SET @ENTRY := 10680;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

