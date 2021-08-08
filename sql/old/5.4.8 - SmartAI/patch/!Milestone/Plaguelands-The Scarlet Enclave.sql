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
 
 -- Crimson Acolyte
 SET @ENTRY := 29007;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,15498,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,2,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,0,0,100,0,8000,8000,16000,18900,11,19725,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Turn Undead'),
(@ENTRY,0,4,0,1,0,100,0,500,1000,600000,600000,11,34809,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Holy Fury on Spawn');
-- NPC talk text insert
SET @ENTRY := 29007;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');
 
-- Death Knight
SET @ENTRY := 28934;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,12000,13000,11,52374,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blood Strike'),
(@ENTRY,0,1,0,0,0,100,0,8000,8900,16700,17900,11,52373,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Plague Strike'),
(@ENTRY,0,2,0,0,0,100,0,3000,11000,22300,27800,11,52372,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Icy Touch');

-- Death Knight
SET @ENTRY := 28933;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,12000,13000,11,52374,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blood Strike'),
(@ENTRY,0,1,0,0,0,100,0,8000,8900,16700,17900,11,52373,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Plague Strike'),
(@ENTRY,0,2,0,0,0,100,0,3000,11000,22300,27800,11,52372,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Icy Touch');

-- Dark Rider of Acherus
SET @ENTRY := 28768;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,52356,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,12000,13000,11,52374,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blood Strike'),
(@ENTRY,0,2,0,0,0,100,0,8000,8500,14500,18200,11,50688,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Plague Strike'),
(@ENTRY,0,3,0,0,0,100,0,3000,11000,25400,27800,11,52372,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Icy Touch');

-- Acherus Geist
SET @ENTRY := 28709;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,52206,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Leaping Face Maul on Aggro');

-- Amal'thazad
SET @ENTRY := 28474;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,5000,5000,800000,800000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text OOC'),
(@ENTRY,0,1,0,1,0,100,0,20000,20000,820000,820000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text OOC'),
(@ENTRY,0,2,0,1,0,100,0,40000,40000,840000,840000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text OOC'),
(@ENTRY,0,3,0,1,0,100,0,60000,60000,860000,860000,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text OOC'),
(@ENTRY,0,4,0,1,0,100,0,80000,80000,880000,880000,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text OOC'),
(@ENTRY,0,5,0,1,0,100,0,100000,100000,900000,900000,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text OOC');
-- NPC talk text insert
SET @ENTRY := 28474;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'You have stood and listened long enough. Step forth.',12,0,100,1,0,0, 'Text 1'),
(@ENTRY,1,0, 'You are not overwhelmed just yet disciple... let the hungering cold of death halt this onslaught.',12,0,100,1,0,0, 'Text 2'),
(@ENTRY,2,0, 'Frozen solid, ripe for the slaughter. Let loose a howling blast and shatter them into pieces, disciple.',12,0,100,1,0,0, 'Text 3'),
(@ENTRY,3,0, 'You have more learning ahead of you disciple. Return to your studies.',12,0,100,1,0,0, 'Text 4'),
(@ENTRY,4,0, 'Do not let it consider its next spell so freely, disciple... freeze its mind.',12,0,100,1,0,0, 'Text 5'),
(@ENTRY,5,0, 'Well done.',12,0,100,1,0,0, 'Text 6');

-- Baron Rivendare
SET @ENTRY := 29109;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5500,12000,13500,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,15600,18200,11,15708,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike');

-- Citizen of Havenshire
SET @ENTRY := 28577;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,31,1,2,0,0,0,0,1,0,0,0,0,0,0,0,'Set Random Phase on Aggro'),
(@ENTRY,0,1,2,4,1,100,1,0,0,0,0,17,431,0,0,0,0,0,1,0,0,0,0,0,0,0,'Play Emote Fear on Aggro'),
(@ENTRY,0,2,3,61,1,100,1,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Attack on Aggro'),
(@ENTRY,0,3,4,61,1,100,1,0,0,0,0,4,14987,0,0,0,0,0,1,0,0,0,0,0,0,0,'Play Sound Female on Aggro'),
(@ENTRY,0,4,5,61,1,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Move on Aggro'),
(@ENTRY,0,5,0,61,1,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Say on Aggro'),
(@ENTRY,0,6,0,0,1,100,0,20000,20000,40000,40000,4,14987,0,0,0,0,0,1,0,0,0,0,0,0,0,'Play Sound Female Scream on Repeat'),
(@ENTRY,0,7,0,2,1,100,1,0,70,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Say Text at 70% HP'),
(@ENTRY,0,8,9,7,1,100,1,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset Emote on Evade'),
(@ENTRY,0,9,0,61,1,100,1,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset Phase on Evade'),
(@ENTRY,0,10,0,6,1,100,1,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset Emote on Death'),
(@ENTRY,0,11,12,4,2,100,1,0,0,0,0,11,52262,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Cornered and Enraged! on Aggro'),
(@ENTRY,0,12,13,61,2,100,1,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,13,14,61,2,100,1,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Attack on Aggro'),
(@ENTRY,0,14,0,61,2,100,1,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Move on Aggro'),
(@ENTRY,0,15,0,7,2,100,1,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset Phase on Evade'),
(@ENTRY,0,16,0,6,1,100,1,0,0,0,0,33,28764,0,0,0,0,0,7,0,0,0,0,0,0,0,'Quest Credit on Death'),
(@ENTRY,0,17,0,6,2,100,1,0,0,0,0,33,28764,0,0,0,0,0,7,0,0,0,0,0,0,0,'Quest Credit on Death');
-- NPC talk text insert
SET @ENTRY := 28577;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Why?',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,0,1, 'P... Please don\'t...',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,0,2, 'Spare my life! I will leave this place forever!Please!',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,0,3, 'You make my children orphans on this day,friend! ',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,0,4, 'The... They promised that we\'d be safe... ',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,0,5, 'I\'m too young to die! ',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,0,6, 'Ask for anything and you shall have it! Just spare my life! ',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,1,0, 'The Lich King whispers:Kill them all!',16,0,50,0,0,14772, 'combat Say'),
(@ENTRY,1,1, 'The Lich King whispers:Finish it!',16,0,50,0,0,14774, 'combat Say'),
(@ENTRY,1,2, 'The Lich King whispers:Mercy is for the weak!',16,0,50,0,0,14773, 'combat Say'),
(@ENTRY,1,3, 'The Lich King whispers:No survivors!',16,0,50,0,0,14776, 'combat Say'),
(@ENTRY,1,4, 'The Lich King whispers:Show it the meaning of terror!',16,0,50,0,0,14782, 'combat Say'),
(@ENTRY,1,5, 'The Lich King whispers:No mercy!',16,0,50,0,0,14771, 'combat Say'),
(@ENTRY,1,6, 'The Lich King whispers:Kill or die!',16,0,50,0,0,14777, 'combat Say'),
(@ENTRY,1,7, 'The Lich King whispers:Suffering to the conquered!',16,0,50,0,0,14781, 'combat Say'),
(@ENTRY,2,0, 'I won\'t go down that easy!',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,2,1, 'Die Scourge dog!DIE!',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,2,2, 'Is this the best the Scourge can do?',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,2,3, 'You may take my life, but you won\'t take my freedom!',12,0,50,0,0,0, 'combat Say');

-- Citizen of Havenshire
SET @ENTRY := 28576;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,31,1,2,0,0,0,0,1,0,0,0,0,0,0,0,'Set Random Phase on Aggro'),
(@ENTRY,0,1,2,4,1,100,1,0,0,0,0,17,431,0,0,0,0,0,1,0,0,0,0,0,0,0,'Play Emote Fear on Aggro'),
(@ENTRY,0,2,3,61,1,100,1,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Attack on Aggro'),
(@ENTRY,0,3,4,61,1,100,1,0,0,0,0,4,14991,0,0,0,0,0,1,0,0,0,0,0,0,0,'Play Sound Male on Aggro'),
(@ENTRY,0,4,5,61,1,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Move on Aggro'),
(@ENTRY,0,5,0,61,1,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Say on Aggro'),
(@ENTRY,0,6,0,0,1,100,0,20000,20000,40000,40000,4,14991,0,0,0,0,0,1,0,0,0,0,0,0,0,'Play Sound Male Scream on Repeat'),
(@ENTRY,0,7,0,2,1,100,1,0,70,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Say Text at 70% HP'),
(@ENTRY,0,8,9,7,1,100,1,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset Emote on Evade'),
(@ENTRY,0,9,0,61,1,100,1,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset Phase on Evade'),
(@ENTRY,0,10,0,6,1,100,1,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset Emote on Death'),
(@ENTRY,0,11,12,4,2,100,1,0,0,0,0,11,52262,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Cornered and Enraged! on Aggro'),
(@ENTRY,0,12,13,61,2,100,1,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,13,14,61,2,100,1,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Attack on Aggro'),
(@ENTRY,0,14,0,61,2,100,1,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Move on Aggro'),
(@ENTRY,0,15,0,7,2,100,1,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset Phase on Evade'),
(@ENTRY,0,16,0,6,1,100,1,0,0,0,0,33,28764,0,0,0,0,0,7,0,0,0,0,0,0,0,'Quest Credit on Death'),
(@ENTRY,0,17,0,6,2,100,1,0,0,0,0,33,28764,0,0,0,0,0,7,0,0,0,0,0,0,0,'Quest Credit on Death');
-- NPC talk text insert
SET @ENTRY := 28576;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Why?',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,0,1, 'P... Please don\'t...',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,0,2, 'Spare my life! I will leave this place forever!Please!',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,0,3, 'You make my children orphans on this day,friend! ',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,0,4, 'The... They promised that we\'d be safe... ',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,0,5, 'I\'m too young to die! ',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,0,6, 'Ask for anything and you shall have it! Just spare my life! ',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,1,0, 'The Lich King whispers:Kill them all!',16,0,50,0,0,14772, 'combat Say'),
(@ENTRY,1,1, 'The Lich King whispers:Finish it!',16,0,50,0,0,14774, 'combat Say'),
(@ENTRY,1,2, 'The Lich King whispers:Mercy is for the weak!',16,0,50,0,0,14773, 'combat Say'),
(@ENTRY,1,3, 'The Lich King whispers:No survivors!',16,0,50,0,0,14776, 'combat Say'),
(@ENTRY,1,4, 'The Lich King whispers:Show it the meaning of terror!',16,0,50,0,0,14782, 'combat Say'),
(@ENTRY,1,5, 'The Lich King whispers:No mercy!',16,0,50,0,0,14771, 'combat Say'),
(@ENTRY,1,6, 'The Lich King whispers:Kill or die!',16,0,50,0,0,14777, 'combat Say'),
(@ENTRY,1,7, 'The Lich King whispers:Suffering to the conquered!',16,0,50,0,0,14781, 'combat Say'),
(@ENTRY,2,0, 'I won\'t go down that easy!',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,2,1, 'Die Scourge dog!DIE!',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,2,2, 'Is this the best the Scourge can do?',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,2,3, 'You may take my life, but you won\'t take my freedom!',12,0,50,0,0,0, 'combat Say');


-- Citizen of New Avalon
SET @ENTRY := 28941;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,1,0,5,0,0,31,1,2,0,0,0,0,1,0,0,0,0,0,0,0,'Set Random Phase on Range'),
(@ENTRY,0,1,2,9,1,100,1,0,5,0,0,17,431,0,0,0,0,0,1,0,0,0,0,0,0,0,'Play Emote Fear on Range'),
(@ENTRY,0,2,3,61,1,100,1,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Attack on Range'),
(@ENTRY,0,3,4,61,1,100,1,0,0,0,0,4,14989,0,0,0,0,0,1,0,0,0,0,0,0,0,'Play Sound Female on Range'),
(@ENTRY,0,4,5,61,1,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Move on Range'),
(@ENTRY,0,5,0,61,1,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Say on Range'),
(@ENTRY,0,6,0,0,1,100,0,20000,20000,40000,40000,4,14989,0,0,0,0,0,1,0,0,0,0,0,0,0,'Play Sound Female Scream on Repeat'),
(@ENTRY,0,7,8,7,1,100,1,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset Emote on Evade'),
(@ENTRY,0,8,0,61,1,100,1,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset Phase on Evade'),
(@ENTRY,0,9,0,6,1,100,1,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset Emote on Death'),
(@ENTRY,0,10,11,9,2,100,1,0,5,0,0,11,52262,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Cornered and Enraged! on Range'),
(@ENTRY,0,11,12,61,2,100,1,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Range'),
(@ENTRY,0,12,13,61,2,100,1,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Attack on Range'),
(@ENTRY,0,13,0,61,2,100,1,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Move on Range'),
(@ENTRY,0,14,0,7,2,100,1,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset Phase on Evade'),
(@ENTRY,0,15,16,9,4,100,1,0,0,0,0,11,52716,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Terrified on Range'),
(@ENTRY,0,16,17,61,4,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Range'),
(@ENTRY,0,17,18,61,4,100,1,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Move on Range'),
(@ENTRY,0,18,0,61,4,100,1,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Attack on Range'),
(@ENTRY,0,19,20,0,4,100,0,15000,15000,30000,30000,4,14989,0,0,0,0,0,1,0,0,0,0,0,0,0,'Play Sound Female Scream on Repeat'),
(@ENTRY,0,20,0,61,4,100,0,15000,15000,30000,30000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Repeat'),
(@ENTRY,0,21,22,0,4,100,1,20000,20000,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Move on Repeat'),
(@ENTRY,0,22,0,61,4,100,1,20000,20000,0,0,17,431,0,0,0,0,0,1,0,0,0,0,0,0,0,'Play Emote Fear on Repeat'),
(@ENTRY,0,23,24,7,4,100,1,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset Emote on Evade'),
(@ENTRY,0,24,0,61,4,100,1,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset Phase on Evade'),
(@ENTRY,0,25,0,6,4,100,1,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset Emote on Death'),
(@ENTRY,0,26,0,6,1,100,1,0,0,0,0,33,28764,0,0,0,0,0,7,0,0,0,0,0,0,0,'Quest Credit on Death'),
(@ENTRY,0,27,0,6,2,100,1,0,0,0,0,33,28764,0,0,0,0,0,7,0,0,0,0,0,0,0,'Quest Credit on Death'),
(@ENTRY,0,28,0,6,4,100,1,0,0,0,0,33,28764,0,0,0,0,0,7,0,0,0,0,0,0,0,'Quest Credit on Death');
-- NPC talk text insert
SET @ENTRY := 28941;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Why?',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,0,1, 'Somebody save me!',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,0,2, 'Spare my life! I will leave this place forever!Please!',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,0,3, 'You make my children orphans on this day,friend! ',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,0,4, 'The... They promised that we\'d be safe... ',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,0,5, 'I\'m too young to die! ',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,0,6, 'Ask for anything and you shall have it! Just spare my life! ',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,0,7, 'HELP!HELP! ',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,1,0, 'I won\'t go down that easy!',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,1,1, 'Die Scourge dog!DIE!',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,1,2, 'Is this the best the Scourge can do?',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,1,3, 'You may take my life, but you won\'t take my freedom!',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,1,4, 'DIE!',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,1,5, 'Come then,death knight!',12,0,50,0,0,0, 'combat Say');

-- Citizen of New Avalon
SET @ENTRY := 28942;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,1,0,5,0,0,31,1,2,0,0,0,0,1,0,0,0,0,0,0,0,'Set Random Phase on Range'),
(@ENTRY,0,1,2,9,1,100,1,0,5,0,0,17,431,0,0,0,0,0,1,0,0,0,0,0,0,0,'Play Emote Fear on Range'),
(@ENTRY,0,2,3,61,1,100,1,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Attack on Range'),
(@ENTRY,0,3,4,61,1,100,1,0,0,0,0,4,14993,0,0,0,0,0,1,0,0,0,0,0,0,0,'Play Sound Male on Range'),
(@ENTRY,0,4,5,61,1,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Move on Range'),
(@ENTRY,0,5,0,61,1,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Say on Range'),
(@ENTRY,0,6,0,0,1,100,0,20000,20000,40000,40000,4,14993,0,0,0,0,0,1,0,0,0,0,0,0,0,'Play Sound Male Scream on Repeat'),
(@ENTRY,0,7,8,7,1,100,1,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset Emote on Evade'),
(@ENTRY,0,8,0,61,1,100,1,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset Phase on Evade'),
(@ENTRY,0,9,0,6,1,100,1,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset Emote on Death'),
(@ENTRY,0,10,11,9,2,100,1,0,5,0,0,11,52262,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Cornered and Enraged! on Range'),
(@ENTRY,0,11,12,61,2,100,1,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Range'),
(@ENTRY,0,12,13,61,2,100,1,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Attack on Range'),
(@ENTRY,0,13,0,61,2,100,1,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Move on Range'),
(@ENTRY,0,14,0,7,2,100,1,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset Phase on Evade'),
(@ENTRY,0,15,16,9,4,100,1,0,0,0,0,11,52716,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Terrified on Range'),
(@ENTRY,0,16,17,61,4,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Range'),
(@ENTRY,0,17,18,61,4,100,1,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Move on Range'),
(@ENTRY,0,18,0,61,4,100,1,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Attack on Range'),
(@ENTRY,0,19,20,0,4,100,0,15000,15000,30000,30000,4,14993,0,0,0,0,0,1,0,0,0,0,0,0,0,'Play Sound Male Scream on Repeat'),
(@ENTRY,0,20,0,61,4,100,0,15000,15000,30000,30000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Repeat'),
(@ENTRY,0,21,22,0,4,100,1,20000,20000,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Move on Repeat'),
(@ENTRY,0,22,0,61,4,100,1,20000,20000,0,0,17,431,0,0,0,0,0,1,0,0,0,0,0,0,0,'Play Emote Fear on Repeat'),
(@ENTRY,0,23,24,7,4,100,1,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset Emote on Evade'),
(@ENTRY,0,24,0,61,4,100,1,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset Phase on Evade'),
(@ENTRY,0,25,0,6,4,100,1,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset Emote on Death'),
(@ENTRY,0,26,0,6,1,100,1,0,0,0,0,33,28764,0,0,0,0,0,7,0,0,0,0,0,0,0,'Quest Credit on Death'),
(@ENTRY,0,27,0,6,2,100,1,0,0,0,0,33,28764,0,0,0,0,0,7,0,0,0,0,0,0,0,'Quest Credit on Death'),
(@ENTRY,0,28,0,6,4,100,1,0,0,0,0,33,28764,0,0,0,0,0,7,0,0,0,0,0,0,0,'Quest Credit on Death');
-- NPC talk text insert
SET @ENTRY := 28942;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Why?',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,0,1, 'Somebody save me!',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,0,2, 'Spare my life! I will leave this place forever!Please!',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,0,3, 'You make my children orphans on this day,friend! ',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,0,4, 'The... They promised that we\'d be safe... ',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,0,5, 'I\'m too young to die! ',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,0,6, 'Ask for anything and you shall have it! Just spare my life! ',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,0,7, 'HELP!HELP! ',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,1,0, 'I won\'t go down that easy!',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,1,1, 'Die Scourge dog!DIE!',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,1,2, 'Is this the best the Scourge can do?',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,1,3, 'You may take my life, but you won\'t take my freedom!',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,1,4, 'DIE!',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,1,5, 'Come then,death knight!',12,0,50,0,0,0, 'combat Say');

-- Coldwraith
SET @ENTRY := 28488;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,15043,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt');

-- Commander Eligor Dawnbringer
SET @ENTRY := 29177;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,14,0,100,0,300000,10,20000,30000,11,37979,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Heal on Friendlies');

-- Death Knight
SET @ENTRY := 28934;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,12000,13000,11,52374,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blood Strike'),
(@ENTRY,0,1,0,0,0,100,0,3000,7000,11000,16000,11,52373,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Plague Strike'),
(@ENTRY,0,2,0,0,0,100,0,8000,10000,25000,26300,11,52372,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Icy Touch');

-- Death Knight
SET @ENTRY := 28933;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,12000,13000,11,52374,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blood Strike'),
(@ENTRY,0,1,0,0,0,100,0,3000,7000,11000,16000,11,52373,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Plague Strike'),
(@ENTRY,0,2,0,0,0,100,0,8000,10000,25000,26300,11,52372,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Icy Touch');
 
-- Death Knight Champion
 SET @ENTRY := 29106;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,13000,11,52374,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blood Strike'),
(@ENTRY,0,1,0,0,0,100,0,3200,7100,11000,16000,11,52373,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Plague Strike'),
(@ENTRY,0,2,0,0,0,100,0,7900,9300,24000,26300,11,52372,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Icy Touch'),
(@ENTRY,0,3,0,0,0,100,0,3000,11000,9000,22000,11,52375,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Death Coil');

-- Death Knight Initiate
SET @ENTRY := 28406;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,13000,11,52374,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blood Strike'),
(@ENTRY,0,1,0,0,0,100,0,3200,7100,11000,16000,11,52373,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Plague Strike'),
(@ENTRY,0,2,0,0,0,100,0,7900,9300,24000,26300,11,52372,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Icy Touch'),
(@ENTRY,0,3,0,0,0,100,0,3000,11000,9000,22000,11,52375,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Death Coil');

-- Defender of the Light <The Argent Dawn>
SET @ENTRY := 29174;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4000,12000,13000,11,53643,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Holy Strike'),
(@ENTRY,0,1,0,0,0,100,0,5000,7000,11000,16000,11,53629,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Uppercut'),
(@ENTRY,0,2,0,9,0,100,0,0,35,15800,18300,11,53638,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Holy Wrath on Close'),
(@ENTRY,0,3,0,14,0,100,0,300000,12,28000,32000,11,29427,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Heal on Friendlies'),
(@ENTRY,0,4,0,4,0,100,1,0,0,0,0,11,53625,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Leap on Aggro');

-- Disciple of Frost
SET @ENTRY := 28490;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,22000,26000,11,53549,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Icy Touch'),
(@ENTRY,0,1,0,9,0,100,0,0,20,16900,21200,11,53536,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Howling Blast on Close'),
(@ENTRY,0,2,0,9,0,100,0,0,10,24500,29800,11,53570,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Hungering Cold on Close'),
(@ENTRY,0,3,0,0,0,100,0,4000,6000,13400,15800,11,53550,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mind Freeze');

-- Flesh Behemoth
SET @ENTRY := 29190;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,19000,22000,11,53634,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stomp'),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,15000,28000,11,36706,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thunderclap');

-- Gothik the Harvester
SET @ENTRY := 28890;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,5000,5000,180000,180000,11,52672,0,0,0,0,0,11,0,20,0,0,0,0,0,'Cast  Ghoulplosion  OOC'),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text OOC');
-- NPC talk text insert
SET @ENTRY := 27033;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Is Gothik the Harvester going to have to choke a geist?',12,0,100,0,0,0, 'Text 1');

-- Hearthglen Crusader
SET @ENTRY := 29102;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,53345,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arrow Assault on Aggro'),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,33,29150,0,0,0,0,0,7,0,0,0,0,0,0,0,'Quest Credit on Death');

-- Mayor Quimby
SET @ENTRY := 28945;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Say on Aggro');
-- NPC talk text insert
SET @ENTRY := 28945;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'The Crusade will be victorious!',12,0,100,0,0,0, 'combat Say');

-- Citizen of New Avalon
SET @ENTRY := 28559;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,1,0,5,0,0,31,1,2,0,0,0,0,1,0,0,0,0,0,0,0,'Set Random Phase on Range'),
(@ENTRY,0,1,2,9,1,100,1,0,5,0,0,17,431,0,0,0,0,0,1,0,0,0,0,0,0,0,'Play Emote Fear on Range'),
(@ENTRY,0,2,3,61,1,100,1,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Attack on Range'),
(@ENTRY,0,3,4,61,1,100,1,0,0,0,0,4,14989,0,0,0,0,0,1,0,0,0,0,0,0,0,'Play Sound Female on Range'),
(@ENTRY,0,4,5,61,1,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Move on Range'),
(@ENTRY,0,5,0,61,1,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Say on Range'),
(@ENTRY,0,6,0,0,1,100,0,20000,20000,40000,40000,4,14989,0,0,0,0,0,1,0,0,0,0,0,0,0,'Play Sound Female Scream on Repeat'),
(@ENTRY,0,7,8,7,1,100,1,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset Emote on Evade'),
(@ENTRY,0,8,0,61,1,100,1,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset Phase on Evade'),
(@ENTRY,0,9,0,6,1,100,1,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset Emote on Death'),
(@ENTRY,0,10,11,9,2,100,1,0,5,0,0,11,52262,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Cornered and Enraged! on Range'),
(@ENTRY,0,11,12,61,2,100,1,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Range'),
(@ENTRY,0,12,13,61,2,100,1,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Attack on Range'),
(@ENTRY,0,13,0,61,2,100,1,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Move on Range'),
(@ENTRY,0,14,0,7,2,100,1,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset Phase on Evade'),
(@ENTRY,0,15,16,9,4,100,1,0,0,0,0,11,52716,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Terrified on Range'),
(@ENTRY,0,16,17,61,4,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Range'),
(@ENTRY,0,17,18,61,4,100,1,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Move on Range'),
(@ENTRY,0,18,0,61,4,100,1,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Attack on Range'),
(@ENTRY,0,19,20,0,4,100,0,15000,15000,30000,30000,4,14989,0,0,0,0,0,1,0,0,0,0,0,0,0,'Play Sound Female Scream on Repeat'),
(@ENTRY,0,20,0,61,4,100,0,15000,15000,30000,30000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Repeat'),
(@ENTRY,0,21,22,0,4,100,1,20000,20000,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Move on Repeat'),
(@ENTRY,0,22,0,61,4,100,1,20000,20000,0,0,17,431,0,0,0,0,0,1,0,0,0,0,0,0,0,'Play Emote Fear on Repeat'),
(@ENTRY,0,23,24,7,4,100,1,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset Emote on Evade'),
(@ENTRY,0,24,0,61,4,100,1,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset Phase on Evade'),
(@ENTRY,0,25,0,6,4,100,1,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset Emote on Death'),
(@ENTRY,0,26,0,6,1,100,1,0,0,0,0,33,28764,0,0,0,0,0,7,0,0,0,0,0,0,0,'Quest Credit on Death'),
(@ENTRY,0,27,0,6,2,100,1,0,0,0,0,33,28764,0,0,0,0,0,7,0,0,0,0,0,0,0,'Quest Credit on Death'),
(@ENTRY,0,28,0,6,4,100,1,0,0,0,0,33,28764,0,0,0,0,0,7,0,0,0,0,0,0,0,'Quest Credit on Death'),
(@ENTRY,0,29,0,1,0,100,0,1000,5000,5000,15000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text OOC');
-- NPC talk text insert
SET @ENTRY := 28559;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Why?',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,0,1, 'Somebody save me!',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,0,2, 'Spare my life! I will leave this place forever!Please!',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,0,3, 'You make my children orphans on this day,friend! ',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,0,4, 'The... They promised that we\'d be safe... ',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,0,5, 'I\'m too young to die! ',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,0,6, 'Ask for anything and you shall have it! Just spare my life! ',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,0,7, 'HELP!HELP! ',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,1,0, 'I won\'t go down that easy!',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,1,1, 'Die Scourge dog!DIE!',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,1,2, 'Is this the best the Scourge can do?',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,1,3, 'You may take my life, but you won\'t take my freedom!',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,1,4, 'DIE!',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,1,5, 'Come then,death knight!',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,2,0, 'If you don\'t come out, we\'ll tear this place apart!',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,2,1, 'What\'s "Crimson Down" We deserve to know the truth,Quimby!',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,2,2, 'Where are those ships going,Quimby? Tell us the truth!',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,2,3, 'QUIMBY!!!!!',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,2,4, 'Everybody is dying! Help us!',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,2,5, 'My whole family\'s been killed! Where was the army when we needed them most?',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,2,6, 'No more lies,Quimby! We need answers!',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,2,7, 'This is a slap in the face! We demand answers!',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,2,8, 'The Scourge are running freely through the streets!',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,2,9, 'So much for the Scarlet "paradise!"',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,2,10, 'You are useless,Quimby!',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,2,11, 'I want on that last ship! Don\'t leave us!',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,2,12, 'We we promised safety! Security!',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,2,13, 'We\'re done for.Safe us,Quimby!',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,2,14, 'Naxxramas is gone? Who cares! Acherus is here now and the death knights are killing everybody!',12,0,50,22,0,0, 'combat Say');

-- Citizen of New Avalon
SET @ENTRY := 28560;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,1,0,5,0,0,31,1,2,0,0,0,0,1,0,0,0,0,0,0,0,'Set Random Phase on Range'),
(@ENTRY,0,1,2,9,1,100,1,0,5,0,0,17,431,0,0,0,0,0,1,0,0,0,0,0,0,0,'Play Emote Fear on Range'),
(@ENTRY,0,2,3,61,1,100,1,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Attack on Range'),
(@ENTRY,0,3,4,61,1,100,1,0,0,0,0,4,14993,0,0,0,0,0,1,0,0,0,0,0,0,0,'Play Sound Male on Range'),
(@ENTRY,0,4,5,61,1,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Move on Range'),
(@ENTRY,0,5,0,61,1,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Say on Range'),
(@ENTRY,0,6,0,0,1,100,0,20000,20000,40000,40000,4,14993,0,0,0,0,0,1,0,0,0,0,0,0,0,'Play Sound Male Scream on Repeat'),
(@ENTRY,0,7,8,7,1,100,1,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset Emote on Evade'),
(@ENTRY,0,8,0,61,1,100,1,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset Phase on Evade'),
(@ENTRY,0,9,0,6,1,100,1,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset Emote on Death'),
(@ENTRY,0,10,11,9,2,100,1,0,5,0,0,11,52262,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Cornered and Enraged! on Range'),
(@ENTRY,0,11,12,61,2,100,1,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Range'),
(@ENTRY,0,12,13,61,2,100,1,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Attack on Range'),
(@ENTRY,0,13,0,61,2,100,1,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Move on Range'),
(@ENTRY,0,14,0,7,2,100,1,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset Phase on Evade'),
(@ENTRY,0,15,16,9,4,100,1,0,0,0,0,11,52716,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Terrified on Range'),
(@ENTRY,0,16,17,61,4,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Range'),
(@ENTRY,0,17,18,61,4,100,1,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Move on Range'),
(@ENTRY,0,18,0,61,4,100,1,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Attack on Range'),
(@ENTRY,0,19,20,0,4,100,0,15000,15000,30000,30000,4,14993,0,0,0,0,0,1,0,0,0,0,0,0,0,'Play Sound Male Scream on Repeat'),
(@ENTRY,0,20,0,61,4,100,0,15000,15000,30000,30000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Repeat'),
(@ENTRY,0,21,22,0,4,100,1,20000,20000,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Move on Repeat'),
(@ENTRY,0,22,0,61,4,100,1,20000,20000,0,0,17,431,0,0,0,0,0,1,0,0,0,0,0,0,0,'Play Emote Fear on Repeat'),
(@ENTRY,0,23,24,7,4,100,1,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset Emote on Evade'),
(@ENTRY,0,24,0,61,4,100,1,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset Phase on Evade'),
(@ENTRY,0,25,0,6,4,100,1,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset Emote on Death'),
(@ENTRY,0,26,0,6,1,100,1,0,0,0,0,33,28764,0,0,0,0,0,7,0,0,0,0,0,0,0,'Quest Credit on Death'),
(@ENTRY,0,27,0,6,2,100,1,0,0,0,0,33,28764,0,0,0,0,0,7,0,0,0,0,0,0,0,'Quest Credit on Death'),
(@ENTRY,0,28,0,6,4,100,1,0,0,0,0,33,28764,0,0,0,0,0,7,0,0,0,0,0,0,0,'Quest Credit on Death'),
(@ENTRY,0,29,0,1,0,100,0,1000,5000,5000,15000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text OOC');
-- NPC talk text insert
SET @ENTRY := 28560;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Why?',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,0,1, 'Somebody save me!',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,0,2, 'Spare my life! I will leave this place forever!Please!',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,0,3, 'You make my children orphans on this day,friend! ',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,0,4, 'The... They promised that we\'d be safe... ',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,0,5, 'I\'m too young to die! ',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,0,6, 'Ask for anything and you shall have it! Just spare my life! ',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,0,7, 'HELP!HELP! ',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,1,0, 'I won\'t go down that easy!',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,1,1, 'Die Scourge dog!DIE!',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,1,2, 'Is this the best the Scourge can do?',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,1,3, 'You may take my life, but you won\'t take my freedom!',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,1,4, 'DIE!',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,1,5, 'Come then,death knight!',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,2,0, 'If you don\'t come out, we\'ll tear this place apart!',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,2,1, 'What\'s "Crimson Down" We deserve to know the truth,Quimby!',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,2,2, 'Where are those ships going,Quimby? Tell us the truth!',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,2,3, 'QUIMBY!!!!!',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,2,4, 'Everybody is dying! Help us!',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,2,5, 'My whole family\'s been killed! Where was the army when we needed them most?',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,2,6, 'No more lies,Quimby! We need answers!',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,2,7, 'This is a slap in the face! We demand answers!',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,2,8, 'The Scourge are running freely through the streets!',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,2,9, 'So much for the Scarlet "paradise!"',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,2,10, 'You are useless,Quimby!',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,2,11, 'I want on that last ship! Don\'t leave us!',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,2,12, 'We we promised safety! Security!',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,2,13, 'We\'re done for.Safe us,Quimby!',12,0,50,22,0,0, 'combat Say'),
(@ENTRY,2,14, 'Naxxramas is gone? Who cares! Acherus is here now and the death knights are killing everybody!',12,0,50,22,0,0, 'combat Say');

-- Knight Commander Plaguefist
SET @ENTRY := 29053;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,13000,11,52374,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blood Strike'),
(@ENTRY,0,1,0,0,0,100,0,3200,7100,11000,16000,11,52373,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Plague Strike');

-- Koltira Deathweaver
SET @ENTRY := 29199;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,13000,11,52374,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blood Strike'),
(@ENTRY,0,1,0,0,0,100,0,3200,7100,11000,16000,11,52373,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Plague Strike'),
(@ENTRY,0,2,0,0,0,100,0,7900,9300,24000,26300,11,52372,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Icy Touch');

-- Lady Alistra
SET @ENTRY := 28471;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,53766,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Anti-Magic Shell on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,4000,5500,12000,13000,11,53717,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Corpse Explosion'),
(@ENTRY,0,2,0,0,0,100,0,7000,7100,16000,16000,11,53721,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Death and Decay'),
(@ENTRY,0,3,0,0,0,100,0,7900,9300,24000,26300,11,53769,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Death Coil'),
(@ENTRY,0,4,0,0,0,80,0,5000,5000,29000,31000,11,53605,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Degeneration'),
(@ENTRY,0,5,0,0,0,100,1,3000,3000,0,0,11,53765,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Open Shadow Portal'),
(@ENTRY,0,6,0,0,0,100,0,11000,11000,26000,33000,11,53694,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Plague Strike');

-- Scarlet Commander Rodrick
SET @ENTRY := 29000;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4000,12600,14900,11,52835,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,1,0,2,0,100,1,0,40,0,0,11,31713,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Holy Light at 40% HP');

-- High Inquisitor Valroth
SET @ENTRY := 29001;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,52926,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Say on Aggro'),
(@ENTRY,0,2,0,0,0,100,1,3000,3000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Say in Battle'),
(@ENTRY,0,3,0,0,0,100,1,4000,4000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Say in Battle'),
(@ENTRY,0,4,0,0,0,100,1,6000,6000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Say in Battle'),
(@ENTRY,0,5,0,0,0,100,0,8000,8000,16000,19000,11,52922,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast The Inquisitor\'s Penance'),
(@ENTRY,0,6,0,2,0,100,1,0,30,0,0,11,38210,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Renew at 30% HP');
-- NPC talk text insert
SET @ENTRY := 29001;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Your dark Scourge magic won\'t protect you from the Light!',12,0,100,0,0,0, 'combat Say'),
(@ENTRY,1,0, 'Come out and play!',12,0,100,0,0,0, 'combat Say'),
(@ENTRY,2,0, 'Coward!',12,0,100,0,0,0, 'combat Say'),
(@ENTRY,3,0, 'You have come seeking devilerance? I have come to deliver!',12,0,100,0,0,0, 'combat Say');

-- Scarlet Deserter
SET @ENTRY := 29193;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,5000,5000,800000,800000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text OOC'),
(@ENTRY,0,1,0,1,0,100,0,20000,20000,820000,820000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text OOC'),
(@ENTRY,0,2,0,1,0,100,0,40000,40000,840000,840000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text OOC'),
(@ENTRY,0,3,0,1,0,100,0,60000,60000,860000,860000,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text OOC'),
(@ENTRY,0,4,0,1,0,100,0,80000,80000,880000,880000,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text OOC'),
(@ENTRY,0,5,0,1,0,100,0,100000,100000,900000,900000,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text OOC'),
(@ENTRY,0,6,0,1,0,100,0,120000,120000,920000,920000,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text OOC');
-- NPC talk text insert
SET @ENTRY := 29193;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'The horror! THE HORROR!',12,0,100,0,0,0, 'Text 1'),
(@ENTRY,1,0, 'Wi... Will it hurt?',12,0,100,0,0,0, 'Text 2'),
(@ENTRY,2,0, 'It tingles...',12,0,100,0,0,0, 'Text 3'),
(@ENTRY,3,0, 'Please! Spare me! I...',12,0,100,0,0,0, 'Text 4'),
(@ENTRY,4,0, 'You\'re a monster!',12,0,100,0,0,0, 'Text 5'),
(@ENTRY,5,0, 'Why don\'t you Just Kill me Already?',12,0,100,0,0,0, 'Text 6'),
(@ENTRY,6,0, 'Is it too late to change my mind? How about you just kill me instead?',12,0,100,0,0,0, 'Text 7');

-- Gothik the Harvester
SET @ENTRY := 29112;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,1,0,100,0,22000,22000,822000,822000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text OOC'),
(@ENTRY,0,2,0,1,0,100,0,42000,42000,842000,842000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text OOC'),
(@ENTRY,0,3,0,1,0,100,0,62000,62000,862000,862000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text OOC'),
(@ENTRY,0,4,0,1,0,100,0,82000,82000,882000,882000,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text OOC'),
(@ENTRY,0,5,0,1,0,100,0,102000,102000,902000,902000,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text OOC'),
(@ENTRY,0,6,0,1,0,100,0,122000,122000,922000,922000,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text OOC');
-- NPC talk text insert
SET @ENTRY := 29112;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Oh yes. Immensely. The pain will propably render you unconcious - hence the vat of slime you\'re floating in!',12,0,100,1,0,0, 'Text 1'),
(@ENTRY,1,0, 'That\'s how you know it\'s working.',12,0,100,1,0,0, 'Text 2'),
(@ENTRY,2,0, 'Don\'t be ridiculous. Where would you even go if I did spare you? We just finished eradicating your civilization, remember?',12,0,100,1,0,0, 'Text 3'),
(@ENTRY,3,0, 'Flattery will get you nowhere.',12,0,100,1,0,0, 'Text 3'),
(@ENTRY,4,0, 'You idiot! That\'s What I\'m Doing Right Now!',12,0,100,1,0,0, 'Text 4'),
(@ENTRY,5,0, 'I AM going to kill you. What\'s the rush?',12,0,100,1,0,0, 'Text 5');

-- Scarlet Fleet Guardian
SET @ENTRY := 28856;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,52566,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,12000,14000,11,25710,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Strike'),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,33,28849,0,0,0,0,0,7,0,0,0,0,0,0,0,'Kill Credit for Quest 12701');

-- Rimblat Earthshatter
SET @ENTRY := 29182;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,17000,18000,11,53630,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thunder'),
(@ENTRY,0,1,0,14,0,100,0,300000,20,20000,30000,11,33642,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Chain Heal on Friendlies');

-- Scarlet Medic
SET @ENTRY := 28608;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,15498,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,0,6000,7000,39000,45000,11,19725,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Turn Undead'),
(@ENTRY,0,2,0,1,0,100,0,500,1000,600000,600000,11,13864,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Power Word: Fortitude on Spawn'),
(@ENTRY,0,3,0,6,0,100,1,0,0,0,0,33,28763,0,0,0,0,0,7,0,0,0,0,0,0,0,'Kill Credit for Quest 12678');

-- Scarlet Lord Jesseriah McCree
SET @ENTRY := 28964;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5000,11000,17000,11,52835,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,1,0,0,0,100,0,8000,9000,22000,24000,11,52836,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Holy Wrath');

-- Scarlet Infantryman
SET @ENTRY := 28609;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,3500,13400,14600,11,25710,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Strike'),
(@ENTRY,0,1,0,0,0,100,0,8000,8900,17000,22400,11,53399,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sweeping Slam'),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,33,28763,0,0,0,0,0,7,0,0,0,0,0,0,0,'Kill Credit for Quest 12678');

-- Scarlet Marksman
SET @ENTRY := 28610;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,9,0,100,0,5,30,25000,29000,11,18651,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Multi-Shot'),
(@ENTRY,0,2,0,9,0,100,0,0,5,11000,12000,11,32915,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Raptor Strike'),
(@ENTRY,0,3,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro');
-- NPC talk text insert
SET @ENTRY := 28610;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'You\'re not welcome in these lands.monster!',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,0,1, 'By the Light be cleansed!',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,0,2, 'Let the purging begin!',12,0,50,0,0,0, 'combat Say');

-- Scarlet Crusader
SET @ENTRY := 28940;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,12000,14000,11,52221,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Strike'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,52566,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot on Aggro');

-- Scarlet Fleet Defender
SET @ENTRY := 28834;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,52566,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,33,28849,0,0,0,0,0,7,0,0,0,0,0,0,0,'Kill Credit for Quest 12701');

-- Scarlet Preacher
 SET @ENTRY := 28939;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,15498,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,2,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,0,0,100,0,8000,8000,16000,18900,11,19725,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Turn Undead'),
(@ENTRY,0,4,0,1,0,100,0,500,1000,600000,600000,11,34809,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Holy Fury on Spawn');
-- NPC talk text insert
SET @ENTRY := 28939;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Scarlet Commander
SET @ENTRY := 28936;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4000,13000,14000,11,52221,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Strike'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Say on Aggro');
-- NPC talk text insert
SET @ENTRY := 28936;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Scourge lilth!DIE!',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,0,1, 'I will present your head to Abbendis myself!',12,0,50,0,0,0, 'combat Say'),
(@ENTRY,0,2, 'The Crusade will be victorious!',12,0,50,0,0,0, 'combat Say');

-- Rampaging Abomination
SET @ENTRY := 29115;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,12000,14000,11,53633,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,1,0,9,0,100,0,8,40,12500,19900,11,50335,0,0,0,0,0,2,1,0,0,0,0,0,0,'Cast Scourge Hook on Close');

-- Rampaging Abomination
SET @ENTRY := 29186;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,12000,14000,11,53633,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,1,0,9,0,100,0,8,40,12500,19900,11,50335,0,0,0,0,0,2,1,0,0,0,0,0,0,'Cast Scourge Hook on Close');

-- Scarlet Ballista
SET @ENTRY := 29104;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,1000,2000,12000,15000,11,53117,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Ballista Assault');

-- Scarlet Captain
SET @ENTRY := 28611;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,4000,5000,12000,14000,11,52221,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Strike'),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,33,28763,0,0,0,0,0,7,0,0,0,0,0,0,0,'Kill Credit for Quest 12678');

-- Scarlet Champion
SET @ENTRY := 29080;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,52566,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,4000,5000,12000,14000,11,25710,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Strike');

-- Tirisfal Crusader
SET @ENTRY := 29103;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,53345,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arrow Assault on Aggro'),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,33,29150,0,0,0,0,0,7,0,0,0,0,0,0,0,'Quest Credit on Death');

-- Thassarian
SET @ENTRY := 29200;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,12000,13000,11,52374,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blood Strike'),
(@ENTRY,0,1,0,0,0,100,0,8000,8500,14500,18200,11,50688,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Plague Strike'),
(@ENTRY,0,2,0,0,0,100,0,3000,11000,25400,27800,11,52372,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Icy Touch');

-- Volatile Ghoul
SET @ENTRY := 29219;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,1,0,0,0,0,11,53632,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Ghoulplosion on Death');

-- Volatile Ghoul
SET @ENTRY := 29136;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,1,0,0,0,0,11,53632,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Ghoulplosion on Death');

-- Warrior of the Frozen Wastes
SET @ENTRY := 29206;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,6000,14000,17000,11,53631,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave');

-- Orbaz Bloodbane
SET @ENTRY := 29204;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,12000,13000,11,52374,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blood Strike'),
(@ENTRY,0,1,0,0,0,100,0,8000,8500,14500,18200,11,50688,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Plague Strike'),
(@ENTRY,0,2,0,0,0,100,0,3000,11000,25400,27800,11,52372,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Icy Touch');

-- Scarlet Peasant
SET @ENTRY := 28557;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,31,1,2,0,0,0,0,1,0,0,0,0,0,0,0,'Set Random Phase on Aggro'),
(@ENTRY,0,1,2,4,1,100,1,0,0,0,0,17,431,0,0,0,0,0,1,0,0,0,0,0,0,0,'Play Emote Fear on Aggro'),
(@ENTRY,0,2,3,61,1,100,1,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Attack on Aggro'),
(@ENTRY,0,3,4,61,1,100,1,0,0,0,0,4,14992,0,0,0,0,0,1,0,0,0,0,0,0,0,'Play Sound Male on Aggro'),
(@ENTRY,0,4,5,61,1,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Move on Aggro'),
(@ENTRY,0,5,0,61,1,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Say on Aggro'),
(@ENTRY,0,6,0,0,1,100,0,20000,20000,40000,40000,4,14992,0,0,0,0,0,1,0,0,0,0,0,0,0,'Play Sound Male Scream on Repeat'),
(@ENTRY,0,7,8,7,1,100,1,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset Emote on Evade'),
(@ENTRY,0,8,0,61,1,100,1,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset Phase on Evade'),
(@ENTRY,0,9,0,6,1,100,1,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset Emote on Death'),
(@ENTRY,0,10,0,6,1,100,1,0,0,0,0,33,28763,0,0,0,0,0,7,0,0,0,0,0,0,0,'Kill Credit for Quest 12678'),
(@ENTRY,0,11,12,61,2,100,1,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Attack on Aggro'),
(@ENTRY,0,12,0,61,2,100,1,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Move on Aggro'),
(@ENTRY,0,13,0,7,2,100,1,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset Phase on Evade'),
(@ENTRY,0,14,0,6,2,100,1,0,0,0,0,33,28763,0,0,0,0,0,7,0,0,0,0,0,0,0,'Kill Credit for Quest 12678');
SET @ENTRY := 28557;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Ungh! I ... I think I pooped...',0,0,50,0,0,0, 'combat Say'),
(@ENTRY,0,1, 'Please, dont kill me! I only took this job for the benefits!',0,0,50,0,0,0, 'combat Say'),
(@ENTRY,0,2, 'I... I have a sick grandmother at home... I...I\'m all she\'s got.',0,0,50,0,0,0, 'combat Say'),
(@ENTRY,0,3, 'I picked the wrong week to quit drinkin! ',0,0,50,0,0,0, 'combat Say'),
(@ENTRY,0,4, 'You don\'t have to do this! Nobody has to die! ',0,0,50,0,0,0, 'combat Say'),
(@ENTRY,0,5, 'The... They promised that we\'d be safe... ',0,0,50,0,0,0, 'combat Say'),
(@ENTRY,0,6, 'Not again! Don\'t kill me, i have a family...HELP!!!HELP ME SOMEBODY!!!',0,0,50,0,0,0, 'combat Say');

-- Rayne
SET @ENTRY := 29181;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,21807,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,2,0,100,1,0,50,0,0,11,20664,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rejuvenation at 50% HP'),
(@ENTRY,0,2,0,0,0,100,0,8000,8000,26000,31000,11,20687,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Starfall'),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,11,25817,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Tranquility at 30% HP');
