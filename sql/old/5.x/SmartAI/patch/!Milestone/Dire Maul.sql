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
  
        /* Bosses */
	
-- Alzzin the Wildshaper
SET @ENTRY := 11492;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,3,0,0,0,0,11,22128,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thorns on Aggro'),
(@ENTRY,0,1,0,61,0,100,3,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 1 on Aggro'),
(@ENTRY,0,2,0,9,1,100,2,0,40,5000,10000,11,22662,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Wither on Close'),
(@ENTRY,0,3,0,0,1,100,2,8000,15000,9000,14000,11,7948,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Wild Regeneration'),
(@ENTRY,0,4,5,0,1,100,2,14000,17000,63000,66000,11,22660,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dire Wolf Form'),
(@ENTRY,0,5,0,61,1,100,2,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 2 on Cast Dire Wolf Form'),
(@ENTRY,0,6,7,0,1,100,2,39000,42000,63000,66000,11,22688,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Tree Form'),
(@ENTRY,0,7,0,61,1,100,2,0,0,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 3 on Cast Tree Form'),
(@ENTRY,0,8,0,9,2,100,2,0,5,8000,12000,11,19319,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Vicious Bite on Close'),
(@ENTRY,0,9,0,9,2,100,2,0,10,7000,13000,11,22689,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mangle on Close'),
(@ENTRY,0,10,11,0,2,100,2,26000,29000,63000,66000,28,22660,0,0,0,0,0,1,0,0,0,0,0,0,0,'Remove Dire Wolf Form'),
(@ENTRY,0,11,0,61,2,100,2,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 1 on Remove Dire Wolf Form'),
(@ENTRY,0,12,0,9,4,100,2,0,5,9000,14000,11,22691,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Disarm on Close'),
(@ENTRY,0,13,0,9,4,100,2,0,40,11000,16000,11,22661,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Enervate on Close'),
(@ENTRY,0,14,0,0,4,100,2,8000,15000,12000,16000,11,10101,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Knock Away'),
(@ENTRY,0,15,16,0,4,100,2,51000,54000,63000,66000,28,22688,0,0,0,0,0,1,0,0,0,0,0,0,0,'Remove Tree Form'),
(@ENTRY,0,16,0,61,4,100,2,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 1 on Remove Tree Form'),
(@ENTRY,0,17,18,2,2,100,3,0,40,0,0,28,22660,0,0,0,0,0,1,0,0,0,0,0,0,0,'Remove Dire Wolf Form at 40% HP'),
(@ENTRY,0,18,19,61,2,100,3,0,0,0,0,39,100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Call for help at 40% HP'),
(@ENTRY,0,19,20,2,4,100,3,0,40,0,0,28,22688,0,0,0,0,0,1,0,0,0,0,0,0,0,'Remove Tree Form at 40% HP'),
(@ENTRY,0,20,0,61,4,100,3,0,0,0,0,39,100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Call for help at 40% HP'),
(@ENTRY,0,21,0,61,1,100,3,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset on Evade'),
(@ENTRY,0,22,0,61,2,100,3,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset on Evade'),
(@ENTRY,0,23,0,61,4,100,3,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset on Evade');

-- Captain Kromcrush
SET @ENTRY := 14325;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,1,0,9,0,100,2,0,5,9000,10000,11,22859,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Cleave on Close'),
(@ENTRY,0,2,0,0,0,100,2,15000,16000,25000,35000,11,22857,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Retaliation'),
(@ENTRY,0,3,0,0,0,100,2,8000,16000,18000,22000,11,19134,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Frightening Shout'),
(@ENTRY,0,4,5,2,0,100,3,0,50,0,0,11,22860,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Call Reavers at 50% HP'),
(@ENTRY,0,5,0,61,0,100,3,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Cast Call Reavers at 50% HP'),
(@ENTRY,0,6,7,2,0,100,3,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,7,0,61,0,100,3,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP');
-- NPC talk text insert
SET @ENTRY := 14325;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'No one get past me and threaten da king!  Ungh, take it!!',14,0,100,0,0,0, 'on Aggro Text'),
(@ENTRY,1,0, 'Help me crush these punys!',14,0,100,0,0,0, 'on Cast Text'),
(@ENTRY,2,0, '%s begins to retaliate all attacks against him!',16,0,100,0,0,0, 'on Cast Text');
	
-- Ferra
SET @ENTRY := 14308;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,3,8,25,0,0,11,22911,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Close'),
(@ENTRY,0,1,0,9,0,100,2,0,5,14000,22500,11,17156,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Maul on Close');

-- Guard Fengus
SET @ENTRY := 14321;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,15749,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Charge on Aggro'),
(@ENTRY,0,1,0,0,0,100,2,2000,4500,8000,15000,11,14516,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike'),
(@ENTRY,0,2,0,0,0,100,2,11000,15000,9000,17000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Bash'),
(@ENTRY,0,3,0,1,0,100,2,500,1000,3600000,3600000,11,22817,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fengus\' Ferocity on Spawn'),
(@ENTRY,0,4,5,2,0,100,3,0,30,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP'),
(@ENTRY,0,5,0,61,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP');
-- NPC talk text insert
SET @ENTRY := 14321;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy');

-- Cho'Rush the Observer
SET @ENTRY := 14324;
SET @ENTRYTOTEM := 6066;
SET @TOTEMSPELL := 8377;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
UPDATE `creature_template` SET `AIName`='0' WHERE `entry`=@ENTRYTOTEM;
UPDATE `creature_template` SET `spell1`=@TOTEMSPELL WHERE `entry`=@ENTRYTOTEM;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,15801,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,2,9000,14000,15000,17000,11,16006,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Chain Lightning'),
(@ENTRY,0,2,0,0,0,100,2,7000,12000,35000,40000,11,8376,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Earthgrab Totem'),
(@ENTRY,0,3,0,2,0,100,2,0,50,15000,22000,11,15982,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Healing Wave at 50% HP'),
(@ENTRY,0,4,0,2,0,100,2,0,30,30000,35000,11,16170,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bloodlust at 30% HP'),
(@ENTRY,0,5,0,9,0,100,2,0,8,13600,14500,11,33860,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Explosion on Close');

-- Guard Mol'dar
SET @ENTRY := 14326;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,15749,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Charge on Aggro'),
(@ENTRY,0,1,0,0,0,100,2,2000,4500,6000,16000,11,14516,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike'),
(@ENTRY,0,2,0,0,0,100,2,11000,15000,10000,18000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Bash'),
(@ENTRY,0,3,0,1,0,100,2,500,1000,3600000,3600000,11,22818,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Mol\'dar\'s Moxie on Spawn'),
(@ENTRY,0,4,5,2,0,100,3,0,30,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP'),
(@ENTRY,0,5,0,61,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP');
-- NPC talk text insert
SET @ENTRY := 14326;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy');

-- Guard Slip'kik
SET @ENTRY := 14323;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,15749,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Charge on Aggro'),
(@ENTRY,0,1,0,0,0,100,2,2000,4500,6000,16000,11,14516,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike'),
(@ENTRY,0,2,0,0,0,100,2,11000,15000,10000,18000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Bash'),
(@ENTRY,0,3,0,1,0,100,2,500,1000,3600000,3600000,11,22820,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Slip\'kik\'s Savvy on Spawn'),
(@ENTRY,0,4,5,2,0,100,3,0,30,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP'),
(@ENTRY,0,5,0,61,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP');
-- NPC talk text insert
SET @ENTRY := 14323;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy');

-- Hydrospawn
SET @ENTRY := 13280;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,10,14000,25000,11,22419,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Riptide on Close'),
(@ENTRY,0,1,0,0,0,100,2,4000,5000,9000,11000,11,22420,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Submersion'),
(@ENTRY,0,2,0,0,0,100,2,8000,10000,18000,27000,11,22421,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Massive Geyser'),
(@ENTRY,0,3,0,2,0,100,3,0,25,0,0,11,22714,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Hydroling at 25% HP');

-- Illyanna Ravenoak
SET @ENTRY := 11488;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,30933,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,5,9,0,100,2,5,30,9000,11000,11,22914,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Concussive Shot'),
(@ENTRY,0,2,5,9,0,100,2,5,30,19000,25000,11,20735,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Multi-Shot'),
(@ENTRY,0,3,0,0,0,100,2,10000,18000,20000,41000,11,22910,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Immolation Trap');

-- Immol'thar
SET @ENTRY := 11496;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,8,6000,14500,11,5568,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Trample on Close'),
(@ENTRY,0,1,0,9,0,100,2,0,5,9000,13500,11,16128,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Infected Bite on Close'),
(@ENTRY,0,2,0,0,0,100,2,1000,3000,6000,20000,11,22899,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Eye of Immol\'thar'),
(@ENTRY,0,3,0,0,0,100,2,10000,21000,11000,22000,11,22950,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Portal of Immol\'thar'),
(@ENTRY,0,4,5,2,0,100,3,0,30,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP'),
(@ENTRY,0,5,0,61,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP');
-- NPC talk text insert
SET @ENTRY := 11496;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy');

-- Isalien
SET @ENTRY := 16097;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,22907,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,3,4000,7000,0,0,11,27639,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Call Pet'),
(@ENTRY,0,2,0,9,0,100,2,5,30,7000,14000,11,14443,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Multi-Shot'),
(@ENTRY,0,3,0,9,0,100,2,0,20,4000,9000,11,12024,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Net'),
(@ENTRY,0,4,0,0,0,100,2,9000,11000,22000,25000,11,27636,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Starshards'),
(@ENTRY,0,5,0,2,0,100,2,0,70,20000,25000,11,27637,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Regrowth at 70% HP');

-- King Gordok
SET @ENTRY := 11501;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,1,0,0,0,100,2,7000,8000,18000,22000,11,22886,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Berserker Charge'),
(@ENTRY,0,2,0,0,0,100,2,8000,9000,11000,16000,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike'),
(@ENTRY,0,3,0,0,0,100,2,12000,15000,17000,24000,11,16727,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast War Stomp'),
(@ENTRY,0,4,0,0,0,100,2,4000,4500,15000,22000,11,15572,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sunder Armor');
-- NPC talk text insert
SET @ENTRY := 11501;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'You no challenge me, scrubs! I\'m da king now, and I stay king FOREVER!!!',14,0,100,0,0,0, 'on Aggro Text');

-- Lethtendris
SET @ENTRY := 14327;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,4500,14000,17000,11,22709,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Void Bolt'),
(@ENTRY,0,1,0,9,0,100,2,0,30,12000,17000,11,20787,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Immolate on Close'),
(@ENTRY,0,2,0,0,0,100,2,8000,13000,8000,19000,11,14887,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley'),
(@ENTRY,0,3,0,0,0,100,2,8000,17000,19000,31000,11,13338,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Curse of Tongues'),
(@ENTRY,0,4,0,0,0,100,2,8000,17000,19000,31000,11,13338,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Curse of Tongues'),
(@ENTRY,0,5,0,0,0,100,2,14000,30000,33000,42000,11,22710,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enlarge');

-- Magister Kalendris
SET @ENTRY := 11487;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,15587,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,2,9000,10000,7000,13000,11,15654,1,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Shadow Word: Pain'),
(@ENTRY,0,2,0,0,0,100,2,22000,32000,13000,27000,11,22919,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Mind Flay'),
(@ENTRY,0,3,0,0,0,100,2,8000,13000,17000,23000,11,7645,1,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Dominate Mind'),
(@ENTRY,0,4,0,2,0,100,3,0,60,0,0,11,22917,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadowform at 60% HP');

-- Pimgib
SET @ENTRY := 14349;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,14034,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,9,0,100,2,0,8,19000,25000,11,15744,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blast Wave on Close'),
(@ENTRY,0,2,0,0,0,100,2,9000,10000,7000,12000,11,22713,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Buffet');

-- Prince Tortheldrin <Ruler of the Shen'dralar>
SET @ENTRY := 11486;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,1,0,11,0,100,3,0,0,0,0,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thrash on Spawn'),
(@ENTRY,0,2,0,9,0,100,2,0,8,10000,11000,11,15589,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirlwind on Close'),
(@ENTRY,0,3,0,0,0,100,2,8000,16000,15000,19000,11,22920,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Blast'),
(@ENTRY,0,4,0,0,0,100,2,14000,15000,11000,13000,11,22995,1,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Summon'),
(@ENTRY,0,5,0,13,0,100,2,2000,4500,20000,30000,11,20537,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Counterspell on Player Spell Cast');
-- NPC talk text insert
SET @ENTRY := 11486;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Who dares disrupt the sanctity of Eldre\'Thalas? Face me, cowards!',14,0,100,0,0,0, 'on Aggro Text');

-- Stomper Kreeg <The Drunk>
SET @ENTRY := 14322;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,240000,300000,300000,420000,5,10,0,0,0,0,0,1,0,0,0,0,0,0,0,'Play Dance Emote on Spawn'),
(@ENTRY,0,1,0,1,0,100,2,420000,480000,300000,420000,5,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Dance Emote on Spawn'),
(@ENTRY,0,2,0,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,3,0,9,0,100,2,0,8,10000,18000,11,15578,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirlwind on Close'),
(@ENTRY,0,4,0,0,0,100,2,7000,13000,20000,27000,11,22833,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Booze Spit'),
(@ENTRY,0,5,0,0,0,100,2,13000,17000,18000,23000,11,16740,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast War Stomp'),
(@ENTRY,0,6,7,2,0,100,3,0,30,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP'),
(@ENTRY,0,7,0,61,0,100,3,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP'),
(@ENTRY,0,8,8,2,0,100,3,0,15,0,0,11,22835,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Drunken Rage at 15% HP'),
(@ENTRY,0,9,0,61,0,100,3,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP');
-- NPC talk text insert
SET @ENTRY := 14322;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'I\'ll crush you!',12,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,0,1, 'Me smash! You die!',12,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,0,2, 'Raaar!!! Me smash $r!',12,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,1,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy'),
(@ENTRY,2,0, '%s goes into a drunken rage!',16,0,100,0,0,0, 'combat Drunken Rage');

-- Tendris Warpwood
SET @ENTRY := 11489;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,1,0,0,0,100,2,1000,3000,10000,16000,11,22994,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Entangle'),
(@ENTRY,0,2,0,9,0,100,2,0,10,28000,33000,11,22924,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Grasping Vines on Close'),
(@ENTRY,0,3,0,9,0,100,2,0,8,6000,14000,11,5568,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Trample on Close');
-- NPC talk text insert
SET @ENTRY := 11489;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'You do not belong here!  Ancients, rise against these intruders!',14,0,100,0,0,0, 'on Aggro Text');

-- Tsu'zee
SET @ENTRY := 11467;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,5000,6000,7000,11,15667,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sinister Strike'),
(@ENTRY,0,1,0,0,0,100,2,6000,8000,9000,12000,11,12540,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gouge'),
(@ENTRY,0,2,0,0,0,100,2,7000,11000,16000,21000,11,21060,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Blind'),
(@ENTRY,0,3,0,67,0,100,2,9000,12000,0,0,11,15657,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Backstab');

-- Zevrim Thornhoof
SET @ENTRY := 11490;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,14000,21000,12000,24000,11,22478,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Intense Pain'),
(@ENTRY,0,1,0,0,0,100,2,11000,20000,17000,26000,11,22651,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Sacrifice');

	   /* Trash Mobs */
			
-- Apprentice of Estulan
SET @ENTRY := 44992;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,1000,1000,1000,1000,11,39550,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Aura on Spawn');	

-- Arcane Feedback
SET @ENTRY := 14400;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,500,1000,600000,600000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lightning Shield on Spawn'),
(@ENTRY,0,1,0,16,0,100,2,12550,1,15000,30000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lightning Shield on Repeat');
	
-- Arcane Torrent
SET @ENTRY := 14399;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,30,2500,8000,11,22945,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Forked Lightning on Close'),
(@ENTRY,0,1,0,0,0,100,2,6000,7000,19000,37000,11,22946,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Lightning Cloud');

-- Carrion Swarmer
SET @ENTRY := 13160;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,14000,21000,11,5416,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Venom Sting on Close');

-- Death Lash
SET @ENTRY := 13285;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,4500,12000,20000,11,16427,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Virulent Poison');

-- Eldreth Apparition
SET @ENTRY := 11471;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,57825,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,1,0,100,2,500,1000,600000,600000,11,18100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Armor on Spawn'),
(@ENTRY,0,2,0,0,0,100,2,3000,14000,18000,24000,11,22744,1,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Chains of Ice'),
(@ENTRY,0,3,0,9,0,100,2,0,8,13600,14500,11,12611,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cone of Cold on Close');

-- Eldreth Darter
SET @ENTRY := 14398;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,6000,8000,8000,19000,11,14033,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Mana Burn'),
(@ENTRY,0,1,0,0,0,100,2,3000,10000,18000,34000,11,17139,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Power Word: Shield');

-- Eldreth Phantasm
SET @ENTRY := 11475;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,15000,20000,11,78535,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Call of the Grave on Close'),
(@ENTRY,0,1,0,0,0,100,2,6000,9000,16000,29000,11,15802,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Shrink');

-- Eldreth Seether
SET @ENTRY := 11469;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,500,1000,600000,600000,11,18968,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fire Shield on Spawn'),
(@ENTRY,0,1,0,0,0,100,2,3000,10000,17000,22000,11,16843,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Crimson Fury'),
(@ENTRY,0,2,3,2,0,100,3,0,30,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP'),
(@ENTRY,0,3,0,61,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP');
-- NPC talk text insert
SET @ENTRY := 11469;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy');

-- Eldreth Sorcerer
SET @ENTRY := 11470;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,20831,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,2,10000,13000,7000,12000,11,22823,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Starshards'),
(@ENTRY,0,2,0,0,0,100,2,9000,15000,16000,21000,11,13323,1,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Polymorph');

-- Eldreth Spectre
SET @ENTRY := 11473;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,13000,22000,17000,25000,11,17201,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dispel Magic'),
(@ENTRY,0,1,0,14,0,100,3,2000,10,0,0,11,7154,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Dark Offering on Friendlies'),
(@ENTRY,0,2,0,14,0,100,3,4000,10,0,0,11,7154,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Dark Offering on Friendlies'),
(@ENTRY,0,3,0,14,0,100,3,6000,10,0,0,11,7154,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Dark Offering on Friendlies');

-- Eldreth Spirit
SET @ENTRY := 11472;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,40,5000,9000,11,22743,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Ribbon of Souls on Close'),
(@ENTRY,0,1,0,9,0,100,2,0,5,7000,14000,11,16838,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Banshee Shriek on Close');

-- Empyrean
SET @ENTRY := 16098;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thrash on Spawn'),
(@ENTRY,0,1,2,2,0,100,3,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,2,0,61,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP');
-- NPC talk text insert
SET @ENTRY := 16098;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage');

-- Eye of Immol'thar
SET @ENTRY := 14396;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,5000,6000,11,22909,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Eye of Immol\'thar on Close');

-- Fel Lash
SET @ENTRY := 13197;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,15230,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,9,0,100,2,0,8,13600,14500,11,22271,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Explosion on Close');

-- Gordok Brute
SET @ENTRY := 11441;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,1,0,0,0,100,2,9000,17000,32000,38000,11,18072,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Uppercut'),
(@ENTRY,0,2,0,13,0,100,2,2000,4500,20000,30000,11,15615,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pummel on Player Spell Cast'),
(@ENTRY,0,3,0,0,0,100,2,4000,9000,15000,22000,11,22572,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bruising Blow'),
(@ENTRY,0,4,0,0,0,100,2,12000,15000,33000,42000,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Backhand'),
(@ENTRY,0,5,5,2,0,100,3,0,30,0,0,11,15716,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,6,0,61,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,'Say Text at 30% HP');
-- NPC talk text insert
SET @ENTRY := 11441;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'I\'ll crush you!',12,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,0,1, 'Me smash! You die!',12,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,0,2, 'Raaar!!! Me smash $r!',12,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,1,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage');

-- Gordok Bushwacker
SET @ENTRY := 14351;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,1,0,0,0,100,2,5000,8000,19000,25000,11,13737,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike'),
(@ENTRY,0,2,0,0,0,100,2,3000,6000,15000,17000,11,15572,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sunder Armor'),
(@ENTRY,0,3,0,9,0,100,2,0,5,13600,14500,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave on Close');
-- NPC talk text insert
SET @ENTRY := 14351;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'I\'ll crush you!',12,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,0,1, 'Me smash! You die!',12,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,0,2, 'Raaar!!! Me smash $r!',12,0,50,0,0,0, 'on Aggro Text');

-- Gordok Captain
SET @ENTRY := 11445;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,5000,7000,9000,11,22575,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Shock'),
(@ENTRY,0,1,0,0,0,100,2,4000,9000,7000,15000,11,22574,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Dark Strike'),
(@ENTRY,0,2,0,0,0,100,2,8000,10000,11000,20000,11,87185,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demoralizing Roar'),
(@ENTRY,0,3,0,0,0,100,2,9000,15000,16000,22000,11,12542,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Fear');

-- Gordok Mage-Lord
SET @ENTRY := 11444;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,15043,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,9,0,100,2,0,20,11000,19000,11,14145,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Fire Blast on Close'),
(@ENTRY,0,2,0,9,0,100,2,0,10,27000,32000,11,18399,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Flamestrike on Close'),
(@ENTRY,0,3,0,0,0,100,2,7000,8000,9000,16000,11,16170,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bloodlust'),
(@ENTRY,0,4,0,0,0,100,2,7000,13000,16000,20000,11,13323,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Polymorph');

-- Gordok Mastiff
SET @ENTRY := 13036;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,8000,5000,9000,11,13445,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rend'),
(@ENTRY,0,1,0,9,0,100,2,0,5,20000,21000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Tendon Rip on Close');

-- Gordok Reaver
SET @ENTRY := 11450;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,9000,13000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave on Close'),
(@ENTRY,0,1,0,0,0,100,2,2000,4500,12000,18000,11,15572,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sunder Armor'),
(@ENTRY,0,2,0,0,0,100,2,6000,9000,19000,25000,11,13737,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike');

-- Gordok Warlock
SET @ENTRY := 11448;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,12739,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,1,0,100,2,500,1000,1800000,1800000,11,13787,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demon Armor on Spawn'),
(@ENTRY,0,2,0,1,0,100,3,3000,5000,0,0,11,22865,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Doomguard on Spawn'),
(@ENTRY,0,3,0,0,0,100,2,2000,4500,12000,16000,11,12742,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Immolate'),
(@ENTRY,0,4,0,0,0,100,2,6000,8000,25000,32000,11,13338,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Curse of Tongues'),
(@ENTRY,0,5,0,0,0,100,2,11000,12000,38000,41000,11,8994,1,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Banish');

-- Highborne Summoner <House of Shen'dralar>
SET @ENTRY := 11466;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,9,0,100,2,0,8,13600,14500,11,11831,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Nova on Close'),
(@ENTRY,0,2,0,0,0,100,2,4000,5000,14000,16000,11,13339,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fire Blast');

-- Ironbark Protector
SET @ENTRY := 11459;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,6000,7000,18000,11,5568,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Trample'),
(@ENTRY,0,1,0,9,0,100,2,0,30,11000,21000,11,28858,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Entangling Roots on Close'),
(@ENTRY,0,2,0,9,0,100,2,0,8,6000,14000,11,18670,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Knock Away on Close');

-- Mana Burst
SET @ENTRY := 14397;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,8,1000,2000,11,22938,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Explosion on Close');

-- Netherwalker
SET @ENTRY := 14389;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,30,7000,14000,11,22878,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley on Close');

-- Petrified Guardian
SET @ENTRY := 14303;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,22696,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thorns on Spawn'),
(@ENTRY,0,1,0,2,0,100,2,0,50,7000,14000,11,22695,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Regrowth at 50% HP');

-- Petrified Treant
SET @ENTRY := 11458;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,2,0,50,25000,42000,11,78530,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Harden Skin at 50% HP');

-- Phase Lasher
SET @ENTRY := 13196;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,4500,12000,16000,11,15285,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fireball Volley'),
(@ENTRY,0,1,0,0,0,100,2,6000,9000,22000,25000,11,17228,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley'),
(@ENTRY,0,2,0,0,0,100,2,14000,15000,33000,38000,11,21749,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thorn Volley'),
(@ENTRY,0,3,0,9,0,100,2,0,8,13600,14500,11,22519,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Ice Nova on Close');

-- Residual Monstrosity
SET @ENTRY := 11484;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,13748,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,9,0,100,2,0,5,19000,23000,11,22940,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Blast on Close'),
(@ENTRY,0,2,0,6,0,100,3,0,0,0,0,11,22939,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Mana Bursts on Death');

-- Skeletal Highborne
SET @ENTRY := 11476;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,5000,9000,11,13444,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sunder Armor on Close');

-- Wandering Eye of Kilrogg
SET @ENTRY := 14386;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,3000,12000,20000,11,22876,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Netherwalker');

-- Warpwood Crusher
SET @ENTRY := 13021;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,10,4000,11000,11,22426,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crush Armor on Close'),
(@ENTRY,0,1,0,9,0,100,2,0,8,11000,20000,11,15550,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Trample on Close');

-- Warpwood Guardian
SET @ENTRY := 11461;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,14,0,100,2,3400,40,8500,14000,11,22373,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Regrowth on Friendlies'),
(@ENTRY,0,1,0,13,0,100,2,9000,14000,0,0,11,15615,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Pummel on Target Spellcast'),
(@ENTRY,0,2,0,9,0,100,2,0,5,21000,21000,11,16172,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Head Crack on Close');

-- Warpwood Stomper
SET @ENTRY := 11465;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,7000,10000,18000,26000,11,16727,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast War Stomp');

-- Warpwood Tangler
SET @ENTRY := 11464;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,40,6000,13000,11,22414,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lightning Bolt on Close'),
(@ENTRY,0,1,0,9,0,100,2,0,30,10000,17000,11,22415,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Entangling Roots on Close');

-- Warpwood Treant
SET @ENTRY := 11462;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,9000,11000,10000,14000,11,11428,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Knockdown'),
(@ENTRY,0,1,0,9,0,100,2,0,5,4000,11000,11,18368,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike on Close'),
(@ENTRY,0,2,0,0,0,100,2,10000,24000,5000,16000,11,14331,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Vicious Rend');

-- Whip Lasher
SET @ENTRY := 13022;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,5000,13000,11,21987,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lash of Pain on Close');

-- Wildspawn Imp
SET @ENTRY := 13276;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,20,7000,15000,11,13340,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fire Blast on Close');

-- Wildspawn Rogue
SET @ENTRY := 11452;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,4500,11000,11,15667,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sinister Strike on Close'),
(@ENTRY,0,1,0,0,0,100,2,12000,17000,20000,27000,11,13298,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Poison'),
(@ENTRY,0,2,0,0,0,100,2,4000,7000,10000,26000,11,15583,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rupture');

-- Wildspawn Hellcaller
SET @ENTRY := 11457;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,15228,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,2,8000,8000,18000,19000,11,31598,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rain of Fire');

-- Wildspawn Betrayer
SET @ENTRY := 11454;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,16100,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,2,8000,8000,12000,17000,11,7896,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Exploding Shot'),
(@ENTRY,0,2,0,0,0,100,2,12000,14000,22000,23000,11,18649,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Shadow Shot'),
(@ENTRY,0,3,0,9,0,100,2,0,5,7000,17000,11,11428,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Knockdown on Close');

-- Wildspawn Felsworn
SET @ENTRY := 11455;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,12471,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,2,3000,4000,120000,120000,11,22418,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chaotic Focus'),
(@ENTRY,0,2,0,0,0,100,2,6000,8000,17000,19000,11,15654,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Shadow Word: Pain'),
(@ENTRY,0,3,0,2,0,100,3,0,30,0,0,11,22417,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Shield at 30% HP');

-- Wildspawn Shadowstalker
SET @ENTRY := 11456;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,22766,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sneak on Spawn'),
(@ENTRY,0,1,0,7,0,100,3,0,0,0,0,11,22766,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sneak on Evade'),
(@ENTRY,0,2,0,67,0,100,2,3900,6900,0,0,11,15582,0,0,0,0,0,2,0,0,0,0,0,0,0,'Casts Backstab'),
(@ENTRY,0,3,0,0,0,100,2,5000,5000,12000,14000,11,7992,0,0,0,0,0,2,32,0,0,0,0,0,0,'Cast Slowing Poison');

-- Wildspawn Satyr
SET @ENTRY := 11451;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,6000,8000,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike on Close'),
(@ENTRY,0,1,0,0,0,100,2,10000,13000,7000,12000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hamstring'),
(@ENTRY,0,2,0,0,0,100,2,3000,7000,10000,20000,11,9128,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Battle Shout'),
(@ENTRY,0,3,0,2,0,100,3,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,4,0,2,0,100,3,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 30% HP');
-- NPC talk text insert
SET @ENTRY := 11451;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage');

-- Wildspawn Trickster
SET @ENTRY := 11453;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,30,8000,16000,11,12493,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Curse of Weakness on Close'),
(@ENTRY,0,1,0,9,0,100,2,0,5,23000,32000,11,3609,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Paralyzing Poison on Close'),
(@ENTRY,0,2,0,0,0,100,2,13000,13000,5000,10000,11,22371,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Curse of Impotence');

