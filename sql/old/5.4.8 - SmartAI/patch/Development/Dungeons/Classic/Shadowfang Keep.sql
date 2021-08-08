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
	
-- Baron Silverlaine
SET @ENTRY := 3887;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,1,0,0,0,100,4,6000,7000,18000,25000,11,93956,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cursed Veil'),
(@ENTRY,0,2,0,0,0,100,6,12000,15000,30000,38000,11,93857,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Worgen Spirit'),
(@ENTRY,0,3,0,0,0,100,2,4000,5000,17000,22000,11,23224,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Veil of Shadow'),
(@ENTRY,0,4,0,6,0,100,7,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Death');
-- NPC talk text insert
SET @ENTRY := 3887;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Leave this accursed place at once!',14,0,100,0,0,0, 'on Aggro Text'),
(@ENTRY,1,0, 'This death is only a temporary respite from my curse.',14,0,100,0,0,0, 'on Death Text');

-- Commander Springvale
SET @ENTRY := 4278;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,1,0,0,0,100,6,12000,12000,27000,27000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Battle'),
(@ENTRY,0,2,0,0,0,100,6,2000,4500,12000,20000,11,93685,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Malefic Strike'),
(@ENTRY,0,3,0,0,0,100,6,6000,9000,22000,28000,11,93687,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Desecration'),
(@ENTRY,0,4,0,0,0,100,2,10000,15000,35000,39000,11,93693,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield of the Perfidious'),
(@ENTRY,0,5,0,0,0,100,4,10000,15000,35000,39000,11,93736,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield of the Perfidious'),
(@ENTRY,0,6,0,0,0,100,2,4000,7000,18000,29000,11,93686,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Unholy Power'),
(@ENTRY,0,7,0,0,0,100,4,4000,7000,18000,29000,11,93735,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Unholy Power'),
(@ENTRY,0,8,0,2,0,100,5,0,30,0,0,11,96272,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Separation Anxiety at 30% HP'),
(@ENTRY,0,9,0,6,0,100,7,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Death');
-- NPC talk text insert
SET @ENTRY := 4278;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Intruders in the keep!To arms!',14,0,100,0,0,0, 'on Aggro Text'),
(@ENTRY,1,0, 'Repel the intruders!',14,0,100,0,0,0, 'on Battle Text'),
(@ENTRY,2,0, 'Our vigilance is eternal...',14,0,100,0,0,0, 'on Death Text');

-- Deathsworn Captain
SET @ENTRY := 3872;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,13600,14500,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hamstring on Close'),
(@ENTRY,0,1,0,0,0,100,6,4000,5000,12000,22000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave');

-- Baron Ashbury
SET @ENTRY := 46962;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,1,0,0,0,100,2,2000,4500,18000,20000,11,93581,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Pain and Suffering'),
(@ENTRY,0,2,0,0,0,100,4,2000,4500,18000,20000,11,93712,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Pain and Suffering'),
(@ENTRY,0,3,7,0,0,100,2,12000,12000,40000,40000,11,93423,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Asphyxiate'),
(@ENTRY,0,4,8,0,0,100,4,12000,12000,40000,40000,11,93710,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Asphyxiate'),
(@ENTRY,0,5,9,0,0,100,2,19000,19000,47000,47000,11,93468,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stay of Execution'),
(@ENTRY,0,6,10,0,0,100,4,19000,19000,47000,47000,11,93705,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stay of Execution'),
(@ENTRY,0,7,0,61,0,100,2,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Cast Asphyxiate'),
(@ENTRY,0,8,0,61,0,100,4,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Cast Asphyxiate'),
(@ENTRY,0,9,11,61,0,100,2,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Boss Text on Cast Stay of Execution'),
(@ENTRY,0,10,12,61,0,100,4,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Boss Text on Cast Stay of Execution'),
(@ENTRY,0,11,0,61,0,100,2,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Cast Stay of Execution'),
(@ENTRY,0,12,0,61,0,100,4,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Cast Stay of Execution'),
(@ENTRY,0,13,0,0,0,100,4,20000,20000,120000,120000,11,93720,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Wracking Pain'),
(@ENTRY,0,14,15,2,0,100,5,0,20,0,0,11,93757,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dark Archangel Form at 20% HP'),
(@ENTRY,0,15,16,61,0,100,5,0,0,0,0,11,93812,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Calamity at 20% HP'),
(@ENTRY,0,16,0,61,0,100,5,0,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Cast Calamity at 20% HP'),
(@ENTRY,0,17,0,6,0,100,7,0,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Death');
-- NPC talk text insert
SET @ENTRY := 46962;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Tally ho! the hunt begins!',14,0,100,0,0,0, 'on Aggro Text'),
(@ENTRY,1,0, 'This is just too easy...',14,0,100,0,0,0, 'on Cast Text'),
(@ENTRY,2,0, 'Baron Ashbury begins to cast Stay of Execution!',41,0,100,0,0,0, 'on Cast Text'),
(@ENTRY,3,0, 'HA!Let\'s at least keep it interesting.',14,0,100,0,0,0, 'on Cast Text'),
(@ENTRY,4,0, 'I grow tired of this hunt... Time to die!',14,0,100,0,0,0, 'on Cast Text'),
(@ENTRY,5,0, 'Killed by lowly commoners,how droll... ',14,0,100,0,0,0, 'on Death Text');

-- Lord Godfrey
SET @ENTRY := 46964;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,1,2,0,0,100,6,8000,9000,22000,25000,11,93520,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pistol Barrage'),
(@ENTRY,0,2,0,61,0,100,6,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Cast Pistol Barrage'),
(@ENTRY,0,3,0,0,0,100,6,2000,3000,35000,42000,11,93707,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Bloodthirsty Ghouls'),
(@ENTRY,0,4,0,0,0,100,2,12000,13000,15000,16000,11,93629,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Cursed Bullets'),
(@ENTRY,0,5,0,0,0,100,4,12000,13000,15000,16000,11,93761,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Cursed Bullets'),
(@ENTRY,0,6,0,0,0,100,2,16000,18000,27000,33000,11,93675,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Wound'),
(@ENTRY,0,7,0,0,0,100,4,16000,18000,27000,33000,11,93771,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Wound'),
(@ENTRY,0,8,0,6,0,100,7,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Death');
-- NPC talk text insert
SET @ENTRY := 46964;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'That bitch Sylvanas sent you too,did she?No matter,your journey ends in agony.',14,0,100,0,0,0, 'on Aggro Text'),
(@ENTRY,1,0, 'Lord Godfrey begins to cast Pistol Barrage!',41,0,100,0,0,0, 'on Cast Text'),
(@ENTRY,2,0, 'I thank you for the clearn death.I would not of done the same... ',14,0,100,0,0,0, 'on Death Text');

-- Lord Walden
SET @ENTRY := 46963;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,1,0,0,0,100,4,5000,7000,19000,26000,11,93702,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Conjure Frost Mixture'),
(@ENTRY,0,2,0,0,0,100,4,11000,14000,28000,34000,11,93562,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Conjure Mystery Toxin'),
(@ENTRY,0,3,0,0,0,100,4,18000,22000,39000,42000,11,93527,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Ice Shards'),
(@ENTRY,0,4,0,0,0,100,2,8000,9000,22000,25000,11,93527,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ice Shards'),
(@ENTRY,0,5,0,0,0,100,2,2000,3000,14000,16000,11,93697,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Conjure Poisonous Mixture'),
(@ENTRY,0,6,0,0,0,100,4,2000,3000,14000,16000,11,93704,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Conjure Poisonous Mixture'),
(@ENTRY,0,7,0,6,0,100,7,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Death');
-- NPC talk text insert
SET @ENTRY := 46963;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Even here I find myself beset by fools!',14,0,100,0,0,0, 'on Aggro Text'),
(@ENTRY,1,0, 'My new life was just beginning...',14,0,100,0,0,0, 'on Death Text');

    /* Trash Mobs */
	
-- Apothecary Baxter <Crown Chemical Co.>
SET @ENTRY := 36565;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4000,4500,12000,20000,11,68821,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chain Reaction'),
(@ENTRY,0,1,0,0,0,100,6,6000,9000,22000,27000,11,68948,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Irresistible Cologne Spray'),
(@ENTRY,0,2,0,9,0,100,6,0,5,25000,35000,11,68946,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Irresistible Cologne on Close');

-- Apothecary Frye <Crown Chemical Co.>
SET @ENTRY := 36272;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,50,7,0,0,0,0,11,68841,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw Cologne on Aggro'),
(@ENTRY,0,1,0,4,0,50,7,0,0,0,0,11,68799,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw Perfume on Aggro'),
(@ENTRY,0,2,0,11,0,100,7,0,0,0,0,11,68704,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lingering Fumes on Spawn');

-- Apothecary Hummel <Crown Chemical Co.>
SET @ENTRY := 36296;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4000,4500,12000,20000,11,68821,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chain Reaction'),
(@ENTRY,0,1,0,0,0,100,6,5000,9000,21000,27000,11,68607,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Alluring Perfume Spray'),
(@ENTRY,0,2,0,0,0,100,6,2000,4000,15000,16000,11,68641,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Alluring Perfume');

-- Corpse Eater
SET @ENTRY := 47134;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,4500,12000,20000,11,91088,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Consume Flesh'),
(@ENTRY,0,1,0,0,0,100,4,2000,4500,12000,20000,11,91093,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Consume Flesh'),
(@ENTRY,0,2,0,0,0,100,4,6000,8000,18000,24000,11,91099,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rotting Bile');

-- Dark Creeper
SET @ENTRY := 47132;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,12000,18000,11,91522,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Dark Touch');

-- Dread Scryer
SET @ENTRY := 47141;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,33833,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,91622,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,2,0,9,0,100,2,0,8,13600,14500,11,12611,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cone of Cold on Close'),
(@ENTRY,0,3,0,9,0,100,4,0,8,15000,17000,11,91623,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Explosion on Close'),
(@ENTRY,0,4,0,2,0,100,4,0,40,14000,21000,11,91624,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enhance Magic at 40% HP');

-- Fel Steed
SET @ENTRY := 3864;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,8,15000,19000,11,7139,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fel Stomp on Close'),
(@ENTRY,0,1,0,9,0,100,4,0,8,15000,19000,11,91312,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fel Stomp on Close');

-- Fetid Ghoul
SET @ENTRY := 47135;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,7,0,0,0,0,11,91561,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Disease Cloud on Spawn'),
(@ENTRY,0,1,0,6,0,100,5,0,0,0,0,11,91554,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fetid Cloud on Death');

-- Frantic Geist
SET @ENTRY := 47131;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,4500,12000,16000,11,91064,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Slashing Claws'),
(@ENTRY,0,1,0,0,0,100,4,2000,4500,12000,16000,11,91074,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Slashing Claws'),
(@ENTRY,0,2,0,4,0,100,5,0,0,0,0,11,91077,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frantic Leap on Aggro');

-- Ghostly Cook
SET @ENTRY := 47232;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4000,5000,15000,19000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,1,0,0,0,100,4,2000,8000,12000,22000,11,91348,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Tenderize');

-- Haunted Servitor
SET @ENTRY := 3875;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,8000,17000,22000,11,7057,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Haunting Spirits'),
(@ENTRY,0,1,0,0,0,100,4,5000,8000,17000,22000,11,91293,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Haunting Spirits'),
(@ENTRY,0,2,0,2,0,100,4,0,50,15000,17000,11,91291,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Drain Life at 50% HP');

-- Mindless Horror
SET @ENTRY := 47137;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,7000,15000,19000,11,91213,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Smash'),
(@ENTRY,0,1,0,0,0,100,4,5000,7000,15000,19000,11,91217,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Smash'),
(@ENTRY,0,2,0,0,0,100,4,9000,12000,22000,24000,11,91220,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Cowering Roar');

-- Odo the Blindwatcher
SET @ENTRY := 50857;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,5000,15000,16000,11,93952,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blinding Shadows'),
(@ENTRY,0,1,0,0,0,100,4,4000,5000,15000,16000,11,93953,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blinding Shadows'),
(@ENTRY,0,2,0,2,0,100,2,0,50,9000,12000,11,93931,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Howling Rage at 50% HP'),
(@ENTRY,0,3,0,2,0,100,4,0,50,9000,12000,11,93951,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Howling Rage at 50% HP');

-- Shadowy Attendant
SET @ENTRY := 47231;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,3400,4700,11,12739,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,4,7000,9000,22000,25000,11,91325,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Shadow Vortex'),
(@ENTRY,0,2,0,0,0,100,4,6000,12000,20000,27000,11,91324,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadowy Touch');

-- Sorcerous Skeleton
SET @ENTRY := 47140;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,15497,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,6,7000,9000,15000,16000,11,13341,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fire Blast'),
(@ENTRY,0,2,0,0,0,100,6,12000,15000,28000,32000,11,91563,1,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Living Bomb');

-- Spitebone Flayer
SET @ENTRY := 47146;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,12000,15000,11,32731,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Flay');

-- Shadow Charger
SET @ENTRY := 3865;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,91309,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,1,0,0,0,100,6,6000,9000,22000,25000,11,29321,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Fear');

-- Pustulant Monstrosity
SET @ENTRY := 47138;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,4500,12000,20000,11,91677,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pustulant Spit'),
(@ENTRY,0,1,0,0,0,100,4,2000,4500,12000,20000,11,91678,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pustulant Spit');

-- Spitebone Guardian
SET @ENTRY := 47145;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3000,5000,14000,16000,11,87081,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike'),
(@ENTRY,0,1,0,13,0,100,6,2000,4500,20000,30000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Bash on Player Spell Cast'),
(@ENTRY,0,2,0,2,0,100,4,0,40,14000,21000,11,91629,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shield of Bones at 40% HP');

-- Spitebone Skeleton
SET @ENTRY := 47143;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,5000,16000,19000,11,91419,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bone Flurry'),
(@ENTRY,0,1,0,0,0,100,4,4000,5000,16000,19000,11,91425,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bone Flurry'),
(@ENTRY,0,2,0,0,0,100,4,8000,9000,25000,28000,11,91426,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Penetrating Strike');

-- Unstable Ravager
SET @ENTRY := 47136;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4000,5000,12000,17000,11,3242,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ravage'),
(@ENTRY,0,1,0,0,0,100,4,8000,11000,18000,22000,11,91668,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Unstable Strength');

-- Wailing Guardsman
SET @ENTRY := 3877;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,8000,9000,15000,11,7074,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Screams of the Past'),
(@ENTRY,0,1,0,0,0,100,4,2000,3000,12000,19000,11,91801,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike');

-- Tormented Officer
SET @ENTRY := 3873;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,3000,25000,30000,11,7054,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Forsaken Ability'),
(@ENTRY,0,1,0,2,0,100,4,0,50,14000,15000,11,91463,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shield Wall at 50% HP');

