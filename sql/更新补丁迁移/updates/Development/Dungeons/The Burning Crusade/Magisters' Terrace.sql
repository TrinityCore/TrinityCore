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
    /* Trash Mobs */
	
-- Brightscale Wyrm
SET @ENTRY := 24761; 
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY; 
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY; 
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,6,0,100,7,0,0,0,0,11,44406,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Energy Infusion on Death');

-- Coilskar Witch
SET @ENTRY := 24696;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,35946,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,4,0,0,2300,3900,11,22907,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,2,0,0,0,100,6,4000,7000,8000,15000,11,35965,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frost Arrow'),
(@ENTRY,0,3,0,0,0,100,2,3000,8000,15000,20000,11,20299,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Forked Lightning'),
(@ENTRY,0,4,0,0,0,100,4,3000,8000,15000,20000,11,46150,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Forked Lightning'),
(@ENTRY,0,5,0,2,0,100,2,0,50,70000,85000,11,17741,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Mana Shield at 50% HP'),
(@ENTRY,0,6,0,2,0,100,4,0,50,60000,75000,11,46151,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Mana Shield at 50% HP');

-- Ethereum Smuggler
SET @ENTRY := 24698;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,8,12000,17000,11,44538,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Explosion on Close');

-- Fizzle
SET @ENTRY := 24656;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,3400,4700,11,44164,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt');

-- Sister of Torment
SET @ENTRY := 24697;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3000,4500,25000,35000,11,44547,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Deadly Embrace'),
(@ENTRY,0,1,0,0,0,100,6,5000,6000,12000,22000,11,44640,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lash of Pain');

-- Sunblade Blood Knight
SET @ENTRY := 24684;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,44480,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Seal of Wrath on Aggro'),
(@ENTRY,0,1,0,4,0,100,5,0,0,0,0,11,46030,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Seal of Wrath on Aggro'),
(@ENTRY,0,2,0,0,0,100,2,15000,20000,15000,20000,11,44482,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Judgement of Wrath'),
(@ENTRY,0,3,0,0,0,100,4,15000,20000,15000,20000,11,46033,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Judgement of Wrath'),
(@ENTRY,0,4,0,14,0,100,2,14000,40,30000,50000,11,44479,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Holy Light on Friendlies'),
(@ENTRY,0,5,0,14,0,100,4,14000,40,30000,50000,11,46029,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Holy Light on Friendlies');

-- Sunblade Imp
SET @ENTRY := 24815;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,3400,4700,11,46044,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow bolt');

-- Sunblade Keeper
SET @ENTRY := 24762;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,3400,4700,11,15232,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,6,6000,9000,15000,25000,11,20741,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Bolt Volley'),
(@ENTRY,0,2,0,0,0,100,6,9000,12000,12000,15000,11,44765,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Banish');

-- Sunblade Mage Guard
SET @ENTRY := 24683;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,44478,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Glaive Throw'),
(@ENTRY,0,1,0,0,0,100,4,0,0,2300,3900,11,46028,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Glaive Throw'),
(@ENTRY,0,2,0,0,0,100,6,2000,2000,32000,35000,11,44475,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Magic Dampening Field');

-- Sunblade Magister
SET @ENTRY := 24685;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,44606,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,46035,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,2,3,0,0,100,2,8000,11000,17000,27000,11,44644,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Nova'),
(@ENTRY,0,3,0,61,0,100,2,0,0,0,0,11,44604,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enchantment of Spell Haste'),
(@ENTRY,0,4,5,0,0,100,4,8000,11000,17000,27000,11,46036,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Nova'),
(@ENTRY,0,5,0,61,0,100,4,0,0,0,0,11,44604,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enchantment of Spell Haste');

-- Sunblade Physician
SET @ENTRY := 24687;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,44599,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Inject Poison on Aggro'),
(@ENTRY,0,1,0,4,0,100,5,0,0,0,0,11,46046,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Inject Poison on Aggro'),
(@ENTRY,0,2,0,0,0,100,2,26000,26000,24000,54000,11,44583,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Prayer of Mending'),
(@ENTRY,0,3,0,0,0,100,4,26000,26000,24000,54000,11,46045,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Prayer of Mending');

-- Sunblade Warlock
SET @ENTRY := 24686;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,44519,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Incinerate'),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4700,11,46043,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Incinerate'),
(@ENTRY,0,2,0,1,0,100,6,500,1000,1800000,1800000,11,44520,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fel Armor on Spawn'),
(@ENTRY,0,3,0,0,0,100,2,5000,9000,12000,18000,11,44518,1,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Immolate'),
(@ENTRY,0,4,0,0,0,100,4,5000,9000,12000,18000,11,46042,1,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Immolate'),
(@ENTRY,0,5,0,1,0,100,7,3000,5000,0,0,11,44517,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Sunblade Imp on Spawn');

-- Wretched Bruiser
SET @ENTRY := 24689;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3000,4000,6000,11000,11,44534,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wretched Strike'),
(@ENTRY,0,1,0,2,0,100,7,0,20,0,0,11,44505,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Drink Fel Infusion at 20% HP');

-- Wretched Husk
SET @ENTRY := 24690;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,5000,7000,17000,11,44503,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wretched Fireball'),
(@ENTRY,0,1,0,0,0,100,6,6000,7000,14000,24000,11,44504,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wretched Frostbolt'),
(@ENTRY,0,2,0,2,0,100,7,0,20,0,0,11,44505,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Drink Fel Infusion at 20% HP');

-- Wretched Skulker
SET @ENTRY := 24688;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,6000,14000,5000,12000,11,44533,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wretched Stab'),
(@ENTRY,0,1,0,2,0,100,7,0,20,0,0,11,44505,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Drink Fel Infusion at 20% HP');

