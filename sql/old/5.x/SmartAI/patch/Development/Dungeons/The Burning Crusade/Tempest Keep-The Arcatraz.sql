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
	
-- Dalliah the Doomsayer
SET @ENTRY := 20885;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,1,0,0,0,100,2,4000,7000,14000,19000,11,36173,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gift of the Doomsayer'),
(@ENTRY,0,2,0,0,0,100,4,4000,7000,14000,19000,11,39009,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gift of the Doomsayer'),
(@ENTRY,0,3,4,0,0,100,6,15000,15000,30000,30000,11,36142,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirlwind'),
(@ENTRY,0,4,0,61,0,100,6,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Cast Whirlwind'),
(@ENTRY,0,5,6,0,0,100,2,22000,22000,35000,35000,11,36144,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Heal'),
(@ENTRY,0,6,0,61,0,100,2,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Cast Heal'),
(@ENTRY,0,7,8,0,0,100,4,22000,22000,35000,35000,11,39013,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Heal'),
(@ENTRY,0,8,0,61,0,100,4,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Cast Heal'),
(@ENTRY,0,9,0,0,0,100,4,9000,13000,13000,17000,11,39016,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Wave'),
(@ENTRY,0,10,0,5,0,100,6,5000,5000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Player Kill'),
(@ENTRY,0,11,0,6,0,100,7,0,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Death');
-- NPC talk text insert
SET @ENTRY := 20885;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'It is unwise to anger me.',14,0,100,0,0,11086, 'on Aggro Text'),
(@ENTRY,1,0, 'I\'ll cut you to pieces!',14,0,50,0,0,11090, 'on Cast Text'),
(@ENTRY,1,1, 'Reap the Whirlwind!',14,0,50,0,0,11089, 'on Cast Text'),
(@ENTRY,2,0, 'Ahh... That is much better.',14,0,50,0,0,11091, 'on Cast Text'),
(@ENTRY,2,1, 'Ahh... Just what I needed.',14,0,50,0,0,11092, 'on Cast Text'),
(@ENTRY,3,0, 'Completely ineffective. Just like someone else I know.',14,0,50,0,0,11087, 'on Player Kill Text'),
(@ENTRY,3,1, 'You chose the wrong opponent.',14,0,50,0,0,11088, 'on Player Kill Text'),
(@ENTRY,4,0, 'Now I\'m really... angry...',14,0,100,0,0,11093, 'on Death Text');

-- Wrath-Scryer Soccothrates
SET @ENTRY := 20886;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,1,0,5,0,100,6,5000,5000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Player Kill'),
(@ENTRY,0,2,0,6,0,100,7,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Death'),
(@ENTRY,0,3,0,0,0,100,2,13000,13000,45000,45000,11,35759,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Felfire Shock'),
(@ENTRY,0,4,0,0,0,100,4,13000,13000,45000,45000,11,39006,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Felfire Shock'),
(@ENTRY,0,5,0,0,0,100,4,19000,19000,20000,20000,11,39007,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Immolation'),
(@ENTRY,0,6,0,0,0,100,2,19000,19000,20000,20000,11,36051,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fel Immolation'),
(@ENTRY,0,7,0,0,0,100,6,25000,25000,35000,35000,11,36512,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Knock Away');
-- NPC talk text insert
SET @ENTRY := 20886;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'At last, a target for my frustrations!',14,0,100,0,0,11238, 'on Aggro Text'),
(@ENTRY,1,0, 'Yes, that was quite satisfying',14,0,100,0,0,11239, 'on Player Kill Text'),
(@ENTRY,2,0, 'Knew this was... the only way out',14,0,100,0,0,11243, 'on Death Text');

-- Zereketh The Unbound
SET @ENTRY := 20870;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,1,0,0,0,100,6,21000,32000,32000,45000,11,36119,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Void Zone'),
(@ENTRY,0,2,0,9,0,100,2,0,30,14000,21000,11,36123,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Seed of Corruption on Close'),
(@ENTRY,0,3,0,9,0,100,4,0,30,14000,21000,11,39367,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Seed of Corruption on Close'),
(@ENTRY,0,4,5,0,0,100,2,15000,21000,35000,45000,11,36127,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Nova'),
(@ENTRY,0,5,0,61,0,100,2,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Cast Shadow Nova'),
(@ENTRY,0,6,7,0,0,100,4,15000,21000,35000,45000,11,39005,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Nova'),
(@ENTRY,0,7,0,61,0,100,4,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Cast Shadow Nova'),
(@ENTRY,0,8,0,5,0,100,6,5000,5000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Player Kill'),
(@ENTRY,0,9,0,6,0,100,7,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Death');
-- NPC talk text insert
SET @ENTRY := 20870;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Life energy to... consume.',14,0,100,0,0,11250, 'on Aggro Text'),
(@ENTRY,1,0, 'The shadow... will engulf you.',14,0,50,0,0,11253, 'on Cast Text'),
(@ENTRY,1,1, 'Darkness...consumes...all.',14,0,50,0,0,11254, 'on Cast Text'),
(@ENTRY,2,0, 'This vessel... is empty.',14,0,50,0,0,11251, 'on Player Kill Text'),
(@ENTRY,2,1, 'No...more...life.',14,0,50,0,0,11252, 'on Player Kill Text'),
(@ENTRY,3,0, 'The void...beckons.',14,0,100,0,0,11255, 'on Death Text');

    /* Trash Mobs */
	
-- Akkiris Lightning-Waker
SET @ENTRY := 20908;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3000,8000,16000,21000,11,36912,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lightning Jump'),
(@ENTRY,0,1,0,0,0,100,2,5000,9000,8000,12000,11,36915,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lightning Discharge'),
(@ENTRY,0,2,0,0,0,100,4,5000,9000,8000,12000,11,39028,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lightning Discharge'),
(@ENTRY,0,3,0,0,0,100,6,16000,23000,75000,90000,11,36914,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Lightning-Waker\'s Curse'),
(@ENTRY,0,4,0,8,0,100,6,0,127,30000,30000,11,19714,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Magic Grounding on Spell Hit'),
(@ENTRY,0,5,0,13,0,100,6,2000,4500,10000,10000,11,32691,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Spell Shock on Player Spell Cast');

-- Arcatraz Defender
SET @ENTRY := 20857;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,4500,25000,27000,11,36638,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Immolate'),
(@ENTRY,0,1,0,0,0,100,4,2000,4500,25000,27000,11,38806,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Immolate'),
(@ENTRY,0,2,0,0,0,100,4,5000,6000,15000,19000,11,38812,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Infected Blood');

-- Arcatraz Sentinel
SET @ENTRY := 20869;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,7000,13000,9000,14000,11,36716,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Energy Discharge'),
(@ENTRY,0,1,0,0,0,100,4,7000,13000,9000,14000,11,38828,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Energy Discharge'),
(@ENTRY,0,2,0,2,0,100,3,0,5,0,0,11,36719,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Explode at 5% HP'),
(@ENTRY,0,3,0,2,0,100,5,0,5,0,0,11,38830,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Explode at 5% HP');

-- Arcatraz Warder
SET @ENTRY := 20859;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,15620,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,4,0,0,2300,3900,11,22907,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,2,5,9,0,100,2,5,30,12000,18000,11,36609,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Arcane Shot'),
(@ENTRY,0,3,5,9,0,100,4,5,30,12000,18000,11,38807,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Arcane Shot'),
(@ENTRY,0,4,5,9,0,100,2,5,30,24000,27000,11,36608,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Charged Arcane Shot'),
(@ENTRY,0,5,5,9,0,100,4,5,30,24000,27000,11,38808,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Charged Arcane Shot'),
(@ENTRY,0,6,5,9,0,100,6,0,5,15000,16000,11,35963,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Improved Wing Clip');

-- Blackwing Drakonaar
SET @ENTRY := 20911;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,7000,11000,11,13737,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike on Close'),
(@ENTRY,0,1,0,9,0,100,6,0,20,18000,25000,11,39038,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blast Wave on Close'),
(@ENTRY,0,2,0,0,0,100,6,11000,15000,14000,18000,11,39033,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Brood Power: Black');

-- Blazing Trickster
SET @ENTRY := 20905;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,36906,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,39022,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,2,0,0,0,100,6,2000,5000,16000,21000,11,36907,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fire Shield');

-- Death Watcher
SET @ENTRY := 20867;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,6000,8000,11,36664,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Tentacle Cleave on Close'),
(@ENTRY,0,1,0,9,0,100,4,0,5,6000,8000,11,38816,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Tentacle Cleave on Close'),
(@ENTRY,0,2,0,2,0,100,2,0,50,32000,40000,11,36655,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Drain Life at 50% HP'),
(@ENTRY,0,3,0,2,0,100,4,0,50,32000,40000,11,38817,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Drain Life at 50% HP'),
(@ENTRY,0,4,0,12,0,100,2,0,30,60000,60000,11,36657,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Death Count when Target is 30% HP'),
(@ENTRY,0,5,0,12,0,100,4,0,30,60000,60000,11,38818,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Death Count when Target is 30% HP');


-- Defender Corpse
SET @ENTRY := 21303;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,7,0,8,0,0,11,36593,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Corpse Burst');

-- Entropic Eye
SET @ENTRY := 20868;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,20,17000,25000,11,36677,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chaos Breath on Close'),
(@ENTRY,0,1,0,9,0,100,2,0,5,6000,8000,11,36664,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Tentacle Cleave on Close'),
(@ENTRY,0,2,0,9,0,100,4,0,5,6000,8000,11,38816,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Tentacle Cleave on Close');

-- Eredar Deathbringer
SET @ENTRY := 20880;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,27987,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Unholy Aura on Spawn'),
(@ENTRY,0,1,0,11,0,100,5,0,0,0,0,11,38844,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Unholy Aura on Spawn'),
(@ENTRY,0,2,0,9,0,100,2,0,5,10000,16000,11,36787,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Forceful Cleave on Close'),
(@ENTRY,0,3,0,9,0,100,4,0,5,10000,16000,11,38846,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Forceful Cleave on Close'),
(@ENTRY,0,4,0,0,0,100,2,5000,9000,15000,20000,11,36789,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Diminish Soul'),
(@ENTRY,0,5,0,0,0,100,4,5000,9000,15000,20000,11,38848,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Diminish Soul');

-- Eredar Soul-Eater
SET @ENTRY := 20879;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,7,0,0,0,0,11,36784,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Entropic Aura on Spawn'),
(@ENTRY,0,1,0,9,0,100,6,0,5,14000,21000,11,36778,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Soul Steal on Close'),
(@ENTRY,0,2,0,0,0,100,2,6000,15000,16000,22000,11,36786,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Soul Chill'),
(@ENTRY,0,3,0,0,0,100,4,6000,15000,16000,22000,11,38843,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Soul Chill');

-- Ethereum Life-Binder
SET @ENTRY := 21702;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,8,14000,20000,11,37480,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bind on Close'),
(@ENTRY,0,1,0,9,0,100,4,0,8,14000,20000,11,38900,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bind on Close'),
(@ENTRY,0,2,0,0,0,100,2,7000,11000,18000,24000,11,15654,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Shadow Word: Pain'),
(@ENTRY,0,3,0,0,0,100,4,7000,11000,18000,24000,11,34941,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Shadow Word: Pain'),
(@ENTRY,0,4,0,14,0,100,2,12000,40,25000,35000,11,37479,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Shadow Mend on Friendlies'),
(@ENTRY,0,5,0,14,0,100,2,15000,40,25000,35000,11,38899,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Shadow Mend on Friendlies');

-- Ethereum Slayer
SET @ENTRY := 20896;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,40,12000,15000,11,36839,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Impairing Poison on Close'),
(@ENTRY,0,1,0,9,0,100,2,0,5,7000,11000,11,36838,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Slaying Strike on Close'),
(@ENTRY,0,2,0,9,0,100,4,0,5,7000,11000,11,38894,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Slaying Strike on Close'),
(@ENTRY,0,3,0,0,0,100,6,5000,9000,21000,25000,11,15087,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Evasion');

-- Ethereum Wave-Caster
SET @ENTRY := 20897;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3000,7000,45000,60000,11,32693,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Haste'),
(@ENTRY,0,1,0,13,0,100,6,2000,4500,20000,25000,11,38897,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sonic Boom on Player Spell Cast'),
(@ENTRY,0,2,0,0,0,100,2,10000,15000,19000,25000,11,36840,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Polymorph'),
(@ENTRY,0,3,0,0,0,100,4,10000,15000,19000,25000,11,38896,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Polymorph');

-- Gargantuan Abyssal
SET @ENTRY := 20898;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,38855,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fire Shield on Aggro'),
(@ENTRY,0,1,0,4,0,100,5,0,0,0,0,11,38901,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fire Shield on Aggro'),
(@ENTRY,0,2,0,0,0,100,2,6000,15000,18000,28000,11,36837,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Meteor'),
(@ENTRY,0,3,0,0,0,100,4,6000,15000,18000,28000,11,38903,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Meteor');

-- Protean Horror
SET @ENTRY := 20865;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,3000,5000,11,36612,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Toothy Bite on Close');

-- Protean Spawn
SET @ENTRY := 21395;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,8000,13000,11,36796,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Acidic Bite on Close');

-- Sightless Eye
SET @ENTRY := 21346;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,9000,15000,11,36646,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Sightless Touch on Close'),
(@ENTRY,0,1,0,9,0,100,4,0,5,9000,15000,11,38815,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Sightless Touch on Close');

-- Negaton Warp-Master
SET @ENTRY := 20873;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,6,0,50,30000,45000,11,36813,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Negaton Field at 50% HP');

-- Phase-Hunter
SET @ENTRY := 20906;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,9,0,100,6,0,5,16000,21000,11,36908,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Warp on Close'),
(@ENTRY,0,1,0,61,0,100,6,0,0,0,0,11,36909,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Back Attack on Close'),
(@ENTRY,0,2,0,0,0,100,6,1000,3000,18000,25000,11,36910,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Phase Burst'),
(@ENTRY,0,3,0,0,0,100,6,4000,7000,12000,18000,11,36910,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Phase Burst');

-- Protean Nightmare
SET @ENTRY := 20864;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,40,12000,18000,11,36622,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Incubation on Close'),
(@ENTRY,0,1,0,9,0,100,2,0,5,9000,15000,11,36617,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Gaping Maw on Close'),
(@ENTRY,0,2,0,9,0,100,4,0,5,9000,15000,11,38810,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Gaping Maw on Close'),
(@ENTRY,0,3,0,0,0,100,2,5000,11000,9000,13000,11,36619,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Infectious Poison'),
(@ENTRY,0,4,0,0,0,100,4,5000,11000,9000,13000,11,38811,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Infectious Poison');

-- Sargeron Hellcaller
SET @ENTRY := 20902;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3000,9000,21000,27000,11,36831,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Curse of the Elements'),
(@ENTRY,0,1,0,9,0,100,2,0,30,11000,17000,11,36832,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Incinerate on Close'),
(@ENTRY,0,2,0,9,0,100,4,0,30,11000,17000,11,38918,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Incinerate on Close'),
(@ENTRY,0,3,0,0,0,100,2,5000,11000,17000,24000,11,36829,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Hell Rain'),
(@ENTRY,0,4,0,0,0,100,4,5000,11000,17000,24000,11,38917,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Hell Rain');

-- Twilight Drakonaar
SET @ENTRY := 20910;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,50,2,3000,6000,21000,26000,11,22560,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Brood Power: Black'),
(@ENTRY,0,1,0,0,0,50,4,3000,6000,21000,26000,11,39033,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Brood Power: Black'),
(@ENTRY,0,2,0,0,0,50,2,3000,6000,21000,26000,11,22559,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Brood Power: Blue'),
(@ENTRY,0,3,0,0,0,50,4,3000,6000,21000,26000,11,39037,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Brood Power: Blue'),
(@ENTRY,0,4,0,0,0,50,2,3000,6000,21000,26000,11,22642,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Brood Power: Bronze'),
(@ENTRY,0,5,0,0,0,50,4,3000,6000,21000,26000,11,39036,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Brood Power: Bronze'),
(@ENTRY,0,6,0,0,0,50,6,3000,6000,21000,26000,11,22561,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Brood Power: Green'),
(@ENTRY,0,7,0,0,0,50,2,3000,6000,21000,26000,11,22558,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Brood Power: Red'),
(@ENTRY,0,8,0,0,0,50,4,3000,6000,21000,26000,11,39034,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Brood Power: Red');

-- Unbound Devastator
SET @ENTRY := 20881;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,8,14000,21000,11,36891,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Devastate on Close'),
(@ENTRY,0,1,0,9,0,100,4,0,8,14000,21000,11,38849,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Devastate on Close'),
(@ENTRY,0,2,0,0,0,100,2,6000,10000,16000,22000,11,36887,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Deafening Roar'),
(@ENTRY,0,3,0,0,0,100,4,6000,10000,16000,22000,11,38850,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Deafening Roar');

-- Unchained Doombringer
SET @ENTRY := 20900;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,36833,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Berserker Charge on Aggro'),
(@ENTRY,0,1,0,0,0,100,6,2000,4500,25000,35000,11,36836,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Agonizing Armor'),
(@ENTRY,0,2,0,0,0,100,2,6000,8000,15000,24000,11,36835,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast War Stomp'),
(@ENTRY,0,3,0,0,0,100,4,6000,8000,15000,24000,11,38911,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast War Stomp');

-- Warder Corpse
SET @ENTRY := 21304;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,7,0,8,0,0,11,36593,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Corpse Burst');

-- Soul Devourer
SET @ENTRY := 20866;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,7000,11000,17000,23000,11,36654,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Breath'),
(@ENTRY,0,1,0,0,0,100,4,7000,11000,17000,23000,11,38813,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Breath'),
(@ENTRY,0,2,0,0,0,100,6,15000,17000,12000,18000,11,36644,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sightless Eye'),
(@ENTRY,0,3,0,2,0,100,7,0,30,0,0,11,33958,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,4,0,2,0,100,7,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP');
-- NPC talk text insert
SET @ENTRY := 20866;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage');

-- Skulking Witch
SET @ENTRY := 20882;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,7,0,0,0,0,11,16380,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Greater Invisibility on Spawn'),
(@ENTRY,0,1,0,7,0,100,7,0,0,0,0,11,16380,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Greater Invisibility on Evade'),
(@ENTRY,0,2,0,0,0,100,6,6000,12000,8000,13000,11,36862,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Gouge'),
(@ENTRY,0,3,0,0,0,100,2,3000,4000,12000,17000,11,36864,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lash of Pain'),
(@ENTRY,0,4,0,0,0,100,4,3000,4000,12000,17000,11,38852,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lash of Pain'),
(@ENTRY,0,5,0,0,0,100,2,8000,11000,22000,29000,11,36863,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chastise'),
(@ENTRY,0,6,0,0,0,100,4,8000,11000,22000,29000,11,38851,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chastise');

-- Negaton Screamer 
SET @ENTRY := 20875;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,6000,15000,18000,11,36738,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Volley'),
(@ENTRY,0,1,0,0,0,100,4,4000,6000,15000,18000,11,38835,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Volley'),
(@ENTRY,0,2,0,0,0,100,2,7000,9000,14000,20000,11,36742,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fireball Volley'),
(@ENTRY,0,3,0,0,0,100,4,7000,9000,14000,20000,11,38836,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fireball Volley'),
(@ENTRY,0,4,0,0,0,100,2,12000,15000,24000,25000,11,36741,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frostbolt Volley'),
(@ENTRY,0,5,0,0,0,100,4,12000,15000,24000,25000,11,38837,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frostbolt Volley'),
(@ENTRY,0,6,0,0,0,100,2,22000,26000,33000,37000,11,36736,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley'),
(@ENTRY,0,7,0,0,0,100,4,22000,26000,33000,37000,11,38840,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley'),
(@ENTRY,0,8,0,0,0,100,6,30000,31000,40000,41000,11,36740,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lightning Bolt Volley'),
(@ENTRY,0,9,0,0,0,100,6,8000,9000,24000,28000,11,13704,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Psychic Scream');

-- Sargeron Archer
SET @ENTRY := 20901;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,22907,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,4,0,0,2300,3900,11,38940,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,2,0,0,0,100,2,12000,15000,18000,19000,11,36827,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Hooked Net'),
(@ENTRY,0,3,0,0,0,100,4,12000,15000,18000,19000,11,38912,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Hooked Net'),
(@ENTRY,0,4,0,0,0,50,2,12000,18000,17000,23000,11,35964,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frost Arrow'),
(@ENTRY,0,5,0,0,0,50,4,12000,18000,17000,23000,11,38942,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frost Arrow'),
(@ENTRY,0,6,0,0,0,50,6,12000,18000,17000,23000,11,23601,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Scatter Shot'),
(@ENTRY,0,7,0,0,0,50,2,12000,18000,17000,23000,11,36984,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Serpent Sting'),
(@ENTRY,0,8,0,0,0,50,4,12000,18000,17000,23000,11,38914,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Serpent Sting'),
(@ENTRY,0,9,0,2,0,100,6,0,30,20000,35000,11,36828,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rapid Fire at 30% HP');

-- Spiteful Temptress
SET @ENTRY := 20883;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,36868,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,38892,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,2,0,0,0,100,6,1000,3000,12000,16000,11,36886,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Spiteful Fury'),
(@ENTRY,0,3,0,0,0,100,6,5000,9000,10000,14000,11,36866,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Domination');

-- Sulfuron Magma-Thrower
SET @ENTRY := 20909;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,36987,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,39025,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,2,0,0,0,100,6,3000,6000,24000,30000,11,36917,32,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Magma-Thrower\'s Curse'),
(@ENTRY,0,3,0,0,0,100,2,7000,11000,15000,21000,11,19717,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Rain of Fire'),
(@ENTRY,0,4,0,0,0,100,4,7000,11000,15000,21000,11,39024,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Rain of Fire');

