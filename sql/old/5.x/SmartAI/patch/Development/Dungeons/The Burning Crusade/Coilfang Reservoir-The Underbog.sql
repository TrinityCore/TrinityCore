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
       /* Boss */
	
-- Ghaz'an
SET @ENTRY := 18105;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,1000,1000,8000,8500,11,34290,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Acid Spit'),
(@ENTRY,0,1,0,0,0,100,6,2500,2500,5000,7000,11,34268,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Acid Breath'),
(@ENTRY,0,2,0,0,0,100,2,6000,6000,11000,12000,11,34267,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Tail Sweep'),
(@ENTRY,0,3,0,0,0,100,4,6000,6000,11000,12000,11,38737,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Tail Sweep'),	
(@ENTRY,0,4,0,2,0,100,7,0,20,0,0,11,15716,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 20% HP'),
(@ENTRY,0,5,0,2,0,100,7,0,20,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 20% HP');
-- NPC talk text insert
SET @ENTRY := 18105;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage');
	
-- Swamplord Musel'ek
SET @ENTRY := 17826;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,2300,3900,11,22907,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,61,0,100,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,2,5,9,0,100,6,5,30,14000,16000,11,31623,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Aimed Shot'),
(@ENTRY,0,3,5,9,0,100,6,5,30,20000,23000,11,34974,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Multi-Shot'),
(@ENTRY,0,4,0,0,0,100,6,8000,8500,16000,16500,11,31946,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Throw Freezing Trap'),
(@ENTRY,0,5,0,0,0,100,6,7000,7500,15500,17000,11,31615,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Hunter\'s Mark'),
(@ENTRY,0,6,5,9,0,100,6,0,5,30000,40000,11,18813,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Knock Away'),
(@ENTRY,0,7,0,0,0,100,6,2000,4500,12000,18000,11,31566,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Raptor Strike'),
(@ENTRY,0,8,0,2,0,100,6,0,40,14000,19000,11,31567,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Deterrence at 40% HP'),
(@ENTRY,0,9,0,0,0,100,6,13000,13000,33000,33000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text in Combat'),
(@ENTRY,0,10,0,7,0,100,6,5000,5000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Player Kill'),
(@ENTRY,0,11,0,6,0,100,7,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sat Text on Death');
-- NPC talk text insert
SET @ENTRY := 17826;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'I will end this quickly...',14,0,50,0,0,10385, 'on Aggro Text'),
(@ENTRY,0,1, 'We fight to the death!',14,0,50,0,0,10384, 'on Aggro Text'),
(@ENTRY,1,0, 'Beast! Obey me! Kill them at once!',14,0,100,0,0,10383, 'in Combat Text'),
(@ENTRY,2,0, 'Well... done...',14,0,50,0,0,10389, 'on Player Kill Text'),
(@ENTRY,2,1, 'Krypta!',14,0,50,0,0,10387, 'on Player Kill Text'),
(@ENTRY,3,0, 'It is finished.',14,0,100,0,0,10388, 'on Death Text');

-- The Black Stalker
SET @ENTRY := 17882;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,0,0,100,4,10000,15000,10000,15000,11,38755,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Spore Strider'),
(@ENTRY,0,1,2,61,0,100,4,0,0,0,0,11,38755,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Spore Strider'),
(@ENTRY,0,2,0,61,0,100,4,0,0,0,0,11,38755,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Spore Strider'),
(@ENTRY,0,3,0,0,0,100,6,2000,4000,22000,25000,11,31717,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Chain Lightning'),
(@ENTRY,0,4,0,0,0,100,6,14000,16000,32000,33000,11,31715,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Static Charge'),
(@ENTRY,0,5,0,0,0,100,6,12000,15000,20000,22000,11,31704,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Levitate');	
	
    /* Trash Mobs */
 
-- Bog Giant
SET @ENTRY := 17723;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,10000,18000,27000,11,15550,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Trample'),
(@ENTRY,0,1,0,0,0,100,6,3000,7000,30000,31000,11,32065,32,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Fungal Decay'),
(@ENTRY,0,2,0,2,0,100,5,0,50,0,0,11,40318,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Growth at 50% HP'),
(@ENTRY,0,3,0,2,0,100,3,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,4,0,2,0,100,3,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP');
-- NPC talk text insert
SET @ENTRY := 17723;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage');

-- Claw <Swamplord Musel'ek's Pet>
SET @ENTRY := 17827;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,3000,10000,21000,11,31429,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Echoing Roar'),
(@ENTRY,0,1,0,0,0,100,6,5000,5500,11000,21500,11,34298,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Maul'),
(@ENTRY,0,2,0,2,0,100,7,0,30,0,0,11,34971,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP'),
(@ENTRY,0,3,0,2,0,100,7,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP');
-- NPC talk text insert
SET @ENTRY := 17827;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy');

-- Fen Ray
SET @ENTRY := 17731;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3000,9000,16000,21000,11,34984,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Psychic Horror');

-- Lykul Stinger
SET @ENTRY := 19632;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,6,0,50,14000,18000,11,34392,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stinger Rage at 50% HP'),
(@ENTRY,0,1,0,61,0,100,6,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 50% HP');
-- NPC talk text insert
SET @ENTRY := 19632;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy');

-- Lykul Wasp
SET @ENTRY := 17732;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,30,8000,9000,11,32330,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Poison Spit on Close'),
(@ENTRY,0,1,0,2,0,100,7,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,2,0,2,0,100,7,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP');
-- NPC talk text insert
SET @ENTRY := 17732;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage');

-- Murkblood Healer
SET @ENTRY := 17730;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,14,0,100,2,7000,40,16000,20000,11,29427,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Holy Light on Friendlies'),
(@ENTRY,0,1,0,14,0,100,4,14000,40,16000,20000,11,37979,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Holy Light on Friendlies'),
(@ENTRY,0,2,0,14,0,100,2,6000,40,9000,9000,11,34423,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Renew on Friendlies'),
(@ENTRY,0,3,0,14,0,100,4,12000,40,9000,9000,11,37978,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Renew on Friendlies'),
(@ENTRY,0,4,0,2,0,100,2,0,80,15000,20000,11,15585,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Prayer of Healing at 80% HP'),
(@ENTRY,0,5,0,2,0,100,4,0,80,15000,20000,11,35943,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Prayer of Healing at 80% HP');

-- Murkblood Oracle
SET @ENTRY := 17771;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,15497,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,12675,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,2,0,9,0,100,2,0,8,13600,14500,11,32192,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Nova on Close'),
(@ENTRY,0,3,0,9,0,100,4,0,8,13600,14500,11,15531,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Nova on Close'),
(@ENTRY,0,4,0,9,0,100,2,0,30,12000,17000,11,15241,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Scorch on Close'),
(@ENTRY,0,5,0,9,0,100,4,0,30,12000,17000,11,36807,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Scorch on Close'),
(@ENTRY,0,6,0,9,0,100,2,0,30,15000,22000,11,31405,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Corruption on Close'),
(@ENTRY,0,7,0,0,0,100,6,3000,9000,15000,25000,11,12248,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Amplify Damage'),
(@ENTRY,0,8,0,1,0,100,6,500,1000,900000,900000,11,34880,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Elemental Armor on Spawn');

-- Murkblood Spearman
SET @ENTRY := 17729;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,22887,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,1,0,0,0,100,4,0,0,2300,3900,11,40317,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,2,5,9,0,100,2,5,30,8000,13000,11,31407,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Viper Sting'),
(@ENTRY,0,3,5,9,0,100,4,5,30,8000,13000,11,39413,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Viper Sting'),
(@ENTRY,0,4,0,2,0,100,7,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,5,0,2,0,100,7,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP');
-- NPC talk text insert
SET @ENTRY := 17729;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage');

-- Murkblood Tribesman
SET @ENTRY := 17728;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,13000,8000,17000,11,12057,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike'),
(@ENTRY,0,1,0,2,0,100,7,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,2,0,2,0,100,7,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP');
-- NPC talk text insert
SET @ENTRY := 17728;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage');

-- Spore Strider
SET @ENTRY := 22299;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,1000,3000,5000,6000,11,20824,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lightning Bolt');

-- Underbat
SET @ENTRY := 17724;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,6000,4000,13000,11,34171,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Tentacle Lash'),
(@ENTRY,0,1,0,0,0,100,4,2000,6000,4000,13000,11,37956,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Tentacle Lash');

-- Underbog Frenzy
SET @ENTRY := 20465;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,3500,22000,26000,11,12097,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pierce Armor');

-- Underbog Lord
SET @ENTRY := 17734;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,10000,10000,17000,20000,11,25778,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Knock Away'),
(@ENTRY,0,1,0,0,0,100,6,7000,7000,12000,16000,11,32065,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Fungal Decay'),
(@ENTRY,0,2,0,2,0,100,3,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,3,0,2,0,100,3,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP'),
(@ENTRY,0,4,0,2,0,100,5,0,50,0,0,11,40318,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Growth at 50% HP');
-- NPC talk text insert
SET @ENTRY := 17734;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage');

-- Underbog Lurker
SET @ENTRY := 17725;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,34161,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Wild Growth on Aggro'),
(@ENTRY,0,1,0,61,0,100,7,0,0,0,0,28,34161,0,0,0,0,0,1,0,0,0,0,0,0,0,'Remove Wild Growth on Evade');

-- Underbog Shambler
SET @ENTRY := 17871;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,10000,12000,17000,11,32329,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Itchy Spores'),
(@ENTRY,0,1,0,0,0,100,4,2000,10000,12000,17000,11,37965,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Itchy Spores'),
(@ENTRY,0,2,0,2,0,100,2,0,75,25000,30000,11,34163,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fungal Regrowth at 75% HP'),
(@ENTRY,0,3,0,2,0,100,4,0,75,25000,30000,11,37967,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fungal Regrowth at 75% HP'),
(@ENTRY,0,4,0,0,0,100,6,2000,8000,18000,26000,11,31427,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Allergies');

-- Wrathfin Myrmidon
SET @ENTRY := 17726;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,8000,10000,20000,11,31410,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Coral Cut'),
(@ENTRY,0,1,0,0,0,100,4,2000,8000,10000,20000,11,37973,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Coral Cut');

-- Wrathfin Sentry
SET @ENTRY := 17727;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,8000,11000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike on Close'),
(@ENTRY,0,1,0,0,0,100,6,12000,15000,17000,22000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Bash'),
(@ENTRY,0,2,0,4,0,50,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro');
-- NPC talk text insert
SET @ENTRY := 17727;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Illidan reigns!',12,0,100,0,0,0, 'on Aggro Text');

-- Wrathfin Warrior
SET @ENTRY := 17735;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,10000,15000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike on Close'),
(@ENTRY,0,1,0,0,0,100,6,5000,6000,27000,34000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Bash'),
(@ENTRY,0,2,0,2,0,100,7,0,20,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 20% HP'),
(@ENTRY,0,3,0,2,0,100,7,0,20,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 20% HP');
-- NPC talk text insert
SET @ENTRY := 17735;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage');

