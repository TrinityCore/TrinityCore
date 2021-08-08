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
    /* Bosses */
	
-- Shirrak the Dead Watcher
SET @ENTRY := 18371;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,6,500,1000,5000,10000,11,32264,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Inhibit Magic on Spawn'),
(@ENTRY,0,1,0,9,0,100,2,0,5,8000,12000,11,36383,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Carnivorous Bite on Close'),
(@ENTRY,0,2,0,9,0,100,4,0,5,8000,12000,11,39382,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Carnivorous Bite on Close'),
(@ENTRY,0,3,0,0,0,100,6,8000,12000,8000,12000,11,32265,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Attract Magic'),
(@ENTRY,0,4,5,0,0,100,6,12000,16000,18000,24000,11,32300,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Focus Fire'),
(@ENTRY,0,5,0,61,0,100,6,0,0,0,0,1,0,0,0,0,0,0,4,0,0,0,0,0,0,0,'Text on Cast Focus Fire');
-- NPC talk text insert
SET @ENTRY := 18371;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Shirrak the Dead Watcher focuses his energy on $T',41,0,100,0,0,0, 'combat Text');

    /* Trash Mobs */
	
-- Angered Skeleton
SET @ENTRY := 18524;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,6,0,50,12000,18000,11,32886,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Infuriated at 50% HP');

-- Auchenai Monk
SET @ENTRY := 18497;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,6,500,1000,120000,125000,11,38168,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spiritual Sight on Spawn'),
(@ENTRY,0,1,0,0,0,100,6,5000,9000,5000,8000,11,37321,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Overpower'),
(@ENTRY,0,2,0,0,0,100,6,9000,14000,10000,13000,11,32849,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Cyclone Strike'),
(@ENTRY,0,3,0,13,0,100,6,2000,4500,7000,11000,11,32846,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Counter Kick on Player Spell Cast'),
(@ENTRY,0,4,0,0,0,50,6,4000,4000,25000,25000,11,32857,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Phantasmal Possessor'),
(@ENTRY,0,5,0,0,0,50,6,4000,4000,25000,25000,11,32853,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Unliving Soldier'),
(@ENTRY,0,6,0,0,0,50,6,4000,4000,25000,25000,11,32854,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Unliving Sorcerer'),
(@ENTRY,0,7,0,0,0,50,6,4000,4000,25000,25000,11,32856,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Unliving Stalker');

-- Auchenai Necromancer
SET @ENTRY := 18702;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,1000,3000,10000,12000,11,35839,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Drain Soul'),
(@ENTRY,0,1,0,14,0,100,6,4000,15,6000,8000,11,33325,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Shadow Mend on Friendlies'),
(@ENTRY,0,2,0,0,0,100,2,4000,7000,21000,24000,11,32863,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Seed of Corruption'),
(@ENTRY,0,3,0,0,0,100,4,4000,7000,21000,24000,11,38252,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Seed of Corruption');

-- Auchenai Soulpriest
SET @ENTRY := 18493;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,32860,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,38378,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,2,0,0,0,100,2,2000,6000,28000,35000,11,32858,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Touch of the Forgotten'),
(@ENTRY,0,3,0,0,0,100,4,2000,6000,28000,35000,11,38377,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Touch of the Forgotten'),
(@ENTRY,0,4,0,9,0,100,6,0,8,13600,14500,11,32859,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Falter on Close'),
(@ENTRY,0,5,0,0,0,50,6,4000,4000,25000,25000,11,32857,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Phantasmal Possessor'),
(@ENTRY,0,6,0,0,0,50,6,4000,4000,25000,25000,11,32853,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Unliving Soldier'),
(@ENTRY,0,7,0,0,0,50,6,4000,4000,25000,25000,11,32854,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Unliving Sorcerer'),
(@ENTRY,0,8,0,0,0,50,6,4000,4000,25000,25000,11,32856,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Unliving Stalker');

-- Auchenai Vindicator
SET @ENTRY := 18495;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,500,1000,600000,600000,11,32861,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadowguard on Spawn'),
(@ENTRY,0,1,0,1,0,100,4,500,1000,600000,600000,11,38379,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadowguard on Spawn'),
(@ENTRY,0,2,0,0,0,100,2,3000,5000,7000,11000,11,17439,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Shock'),
(@ENTRY,0,3,0,0,0,100,4,3000,5000,7000,11000,11,17289,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Shock'),
(@ENTRY,0,4,0,0,0,50,6,4000,4000,25000,25000,11,32857,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Phantasmal Possessor'),
(@ENTRY,0,5,0,0,0,50,6,4000,4000,25000,25000,11,32853,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Unliving Soldier'),
(@ENTRY,0,6,0,0,0,50,6,4000,4000,25000,25000,11,32854,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Unliving Sorcerer'),
(@ENTRY,0,7,0,0,0,50,6,4000,4000,25000,25000,11,32856,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Unliving Stalker');

-- Phantasmal Possessor
SET @ENTRY := 18503;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,10000,20000,30000,11,33401,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Possess');

-- Phasing Cleric
SET @ENTRY := 18557;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,14,0,100,2,5000,20,7000,8000,11,33324,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Major Heal on Friendlies'),
(@ENTRY,0,1,0,14,0,100,4,7000,20,7000,8000,11,22883,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Heal on Friendlies'),
(@ENTRY,0,2,0,14,0,100,2,2000,20,6000,8000,11,25058,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Renew on Friendlies'),
(@ENTRY,0,3,0,14,0,100,4,4000,20,6000,8000,11,38210,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Renew on Friendlies');

-- Phasing Soldier
SET @ENTRY := 18556;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,7,0,0,0,0,11,32828,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Protection Aura on Spawn'),
(@ENTRY,0,1,0,13,0,100,6,2000,4500,8000,12000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Bash on Player Spell Cast');

-- Phasing Sorcerer
SET @ENTRY := 18558;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,12466,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,17290,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,2,0,0,0,100,2,2000,6000,15000,16000,11,15043,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Frostbolt'),
(@ENTRY,0,3,0,0,0,100,4,2000,6000,15000,16000,11,15530,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Frostbolt'),
(@ENTRY,0,4,0,9,0,100,2,0,8,13600,14500,11,15744,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blast Wave on Close'),
(@ENTRY,0,5,0,9,0,100,4,0,8,13600,14500,11,22424,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blast Wave on Close');

-- Phasing Stalker
SET @ENTRY := 18559;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,15547,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,4,0,0,2300,3900,11,16100,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,2,0,9,0,100,2,5,30,15000,19000,11,31975,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Serpent Sting'),
(@ENTRY,0,3,0,9,0,100,4,5,30,15000,19000,11,35511,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Serpent Sting'),
(@ENTRY,0,4,0,9,0,100,4,5,30,12000,25000,11,37551,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Viper Sting'),
(@ENTRY,0,5,0,2,0,100,6,0,40,14000,16000,11,32829,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spirit Vengeance at 40% HP');

-- Raging Soul
SET @ENTRY := 18506;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,32888,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rage on Aggro'),
(@ENTRY,0,1,0,4,0,100,5,0,0,0,0,11,38380,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rage on Aggro'),
(@ENTRY,0,2,0,7,0,100,7,0,0,0,0,11,32811,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Greater Invisibility on Evade');

-- Reanimated Bones
SET @ENTRY := 18700;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,5000,9000,11,13444,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sunder Armor on Close'),
(@ENTRY,0,1,0,0,0,100,6,2000,4500,12000,20000,11,13584,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike');

-- Unliving Cleric
SET @ENTRY := 18500;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,14,0,100,2,5000,20,7000,8000,11,33324,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Major Heal on Friendlies'),
(@ENTRY,0,1,0,14,0,100,4,7000,20,7000,8000,11,22883,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Heal on Friendlies'),
(@ENTRY,0,2,0,14,0,100,2,2000,20,6000,8000,11,25058,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Renew on Friendlies'),
(@ENTRY,0,3,0,14,0,100,4,4000,20,6000,8000,11,38210,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Renew on Friendlies');

-- Unliving Soldier
SET @ENTRY := 18498;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,7,0,0,0,0,11,32828,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Protection Aura on Spawn'),
(@ENTRY,0,1,0,13,0,100,6,2000,4500,8000,12000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Bash on Player Spell Cast');

-- Unliving Sorcerer
SET @ENTRY := 18499;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,15043,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,15530,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,2,0,0,0,100,2,2000,6000,15000,16000,11,12466,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Fireball'),
(@ENTRY,0,3,0,0,0,100,4,2000,6000,15000,16000,11,17290,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Fireball'),
(@ENTRY,0,4,0,9,0,100,2,0,8,13600,14500,11,15744,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blast Wave on Close'),
(@ENTRY,0,5,0,9,0,100,4,0,8,13600,14500,11,22424,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blast Wave on Close');

-- Unliving Stalker
SET @ENTRY := 18501;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,15547,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,4,0,0,2300,3900,11,16100,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,2,0,9,0,100,2,5,30,15000,19000,11,31975,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Serpent Sting'),
(@ENTRY,0,3,0,9,0,100,4,5,30,15000,19000,11,35511,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Serpent Sting'),
(@ENTRY,0,4,0,9,0,100,4,5,30,12000,25000,11,37551,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Viper Sting'),
(@ENTRY,0,5,0,2,0,100,6,0,40,14000,16000,11,32829,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spirit Vengeance at 40% HP');

