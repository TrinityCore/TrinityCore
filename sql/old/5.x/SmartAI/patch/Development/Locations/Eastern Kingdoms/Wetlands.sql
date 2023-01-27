/* Copyright (C) 11 April 2011-2016 patch Project 
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
 * patch Project  Copyright (C) 11 April 2011-2015 patch Project 
 * This program comes with ABSOLUTELY NO WARRANTY;
 * This is free software, and you are welcome to redistribute it
 * under certain conditions.
 */
 
-- Balgaras the Foul
SET @ENTRY := 41556;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,77721,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Weave');

-- Bluegill Forager
SET @ENTRY := 42111;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,78542,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Splash');

-- Bluegill Murloc
SET @ENTRY := 41425;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,78542,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Splash'),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,34827,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Water Shield on Spawn'),
(@ENTRY,0,2,0,16,0,100,0,34827,1,15000,30000,11,34827,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Water Shield on Repeat');

-- Bluegill Oracle
SET @ENTRY := 41426;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,78542,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Splash'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,4700,11,32011,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Water Bolt'),
(@ENTRY,0,2,0,2,0,100,0,0,70,22000,25000,11,6274,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Healing Ward at 70% HP');

-- Bluegill Puddlejumper
SET @ENTRY := 42110;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,78542,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Splash'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,66060,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sprint on Aggro');

-- Calamoth Ashbeard <Herald of the Twilight's Hammer>
SET @ENTRY := 41522;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,78129,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Twilight Bolt'),
(@ENTRY,0,1,0,9,0,100,0,0,10,15000,25000,11,82723,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Twilight Blast on Close');

-- Captain Halyndor
SET @ENTRY := 41429;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,30000,35000,11,3360,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Curse of the Eye'),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,15000,15000,11,82599,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Planked'),
(@ENTRY,0,2,0,2,0,100,0,0,55,22000,25000,11,3389,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Ward of the Eye at 55% HP');

-- Captured Mosshide
UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI" WHERE `entry` = 203282;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 41410;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (203282, 41410, 4141000);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(203282, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Gnoll Cage - on gameobject state changed - store player'),
(203282, 1, 1, 2, 61, 0, 100, 0, 2, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 19, 41410, 5, 0, 0, 0, 0, 0, 'Gnoll Cage - linked - send player to Captured Mosshide'),
(203282, 1, 2, 0, 61, 0, 100, 0, 2, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 41410, 5, 0, 0, 0, 0, 0, 'Gnoll Cage - linked - set data 1 1 to Captured Mosshide within 5 yards'),
(41410, 0, 0, 0, 38, 0, 100, 1, 1, 1, 0, 0, 80, 4141000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Captured Mosshide - on data set 1 1 - run actionlist (4141000)'),
(4141000, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 33, 41438, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Captured Mosshide - actionlist - give quest credit (41410)'),
(4141000, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 46, 20, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Captured Mosshide - actionlist - run forward 10 yards'),
(4141000, 9, 2, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Captured Mosshide - actionlist - despawn'),
(41410,0,1,0,11,0,100,1,0,0,0,0,11,8852,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Moss Hide on Spawn');

-- Cave Stalker
SET @ENTRY := 4040;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,55,15000,18000,11,82715,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Flee into the Shadows at 55% HP');

-- Cursed Marine
SET @ENTRY := 41429;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,30000,35000,11,3360,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Curse of the Eye'),
(@ENTRY,0,1,0,0,0,100,0,4000,4000,12000,15000,11,82595,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rusty Rapier');

-- Cursed Sailor
SET @ENTRY := 41428;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,30000,35000,11,3360,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Curse of the Eye'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,75388,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rusty Cut');

-- Dark Iron Holdout
SET @ENTRY := 41394;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,55,8000,10000,11,12169,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shield Block at 55% HP'),
(@ENTRY,0,1,0,2,0,100,0,0,40,12000,19000,11,34783,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spell Reflection at 40% HP');

-- Dark Iron Smouldermage
SET @ENTRY := 41272;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,14000,18000,11,82641,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lava Gout'),
(@ENTRY,0,2,0,1,0,100,0,500,1000,600000,600000,11,79849,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Molten Armor on Spawn');

-- Dark Iron Trapper
SET @ENTRY := 41409;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,12000,16000,11,79721,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Explosive Shot'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,25000,35000,11,80004,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Snake Trap');

-- Displaced Threshadon
SET @ENTRY := 41137;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,82704,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Snap and Toss');

-- Dragonmaw Bonewarder
SET @ENTRY := 1057;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,77721,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Weave'),
(@ENTRY,0,1,0,1,0,100,0,500,1000,300000,300000,11,78646,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bone Shield on Spawn'),
(@ENTRY,0,2,0,16,0,100,0,78646,1,15000,30000,11,78646,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bone Shield on Repeat'),
(@ENTRY,0,3,0,1,0,100,1,3000,5000,0,0,11,78647,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Skeleton on Spawn');

-- Dragonmaw Centurion
SET @ENTRY := 1036;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,78660,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Devastate'),
(@ENTRY,0,1,0,2,0,100,0,0,40,15000,17000,11,3419,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Improved Blocking at 40% HP'),
(@ENTRY,0,2,0,0,0,100,0,3000,9000,10000,20000,11,76622,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sunder Armor');

-- Dragonmaw Grunt
SET @ENTRY := 42107;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7000,8000,15000,18000,11,78521,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Dragon\'s Breath'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rushing Charge on Aggro');

-- Dragonmaw Grunt
SET @ENTRY := 41072;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7000,8000,15000,18000,11,78521,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Dragon\'s Breath'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rushing Charge on Aggro');

-- Dragonmaw Raider
SET @ENTRY := 1034;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,78623,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Leap on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,4000,6000,12000,15000,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Net');

-- Dragonmaw Scout
SET @ENTRY := 41080;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,25000,30000,11,78508,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mark of Flames'),
(@ENTRY,0,1,0,0,0,100,0,6000,8000,12000,15000,11,78509,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Torch Toss');

-- Dragonmaw Shadowwarder
SET @ENTRY := 1038;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,25000,37000,11,78648,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Grim Totem');

-- Dragonmaw Swamprunner
SET @ENTRY := 1035;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,744,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Poison');

-- Dragonmaw Whelpstealer
SET @ENTRY := 42041;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,14000,15000,11,78491,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Whelp Call'),
(@ENTRY,0,1,0,9,0,100,0,5,10,15000,25000,11,78397,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fireproof Net on Close');

-- Drungeld Glowerglare
SET @ENTRY := 41151;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,15000,15000,11,77670,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fire Whirl'),
(@ENTRY,0,1,0,9,0,100,0,0,10,15000,25000,11,17277,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blast Wave on Close'),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,11,82635,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flaming Leap on Aggro');

-- Drungeld Glowerglare
SET @ENTRY := 41553;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,15000,15000,11,77670,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fire Whirl'),
(@ENTRY,0,1,0,9,0,100,0,0,10,15000,25000,11,17277,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blast Wave on Close'),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,11,82635,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flaming Leap on Aggro');

-- Ebon Slavehunter
SET @ENTRY := 42043;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,75068,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lava Burst');

-- Ebon Whelp
SET @ENTRY := 42042;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,78472,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Breath');

-- Elder Razormaw
SET @ENTRY := 1019;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Tendon Rip'),
(@ENTRY,0,1,0,0,0,100,0,4000,9000,15000,20000,11,3427,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Infected Wound');

-- Flood Elemental
SET @ENTRY := 41132;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,1000,15000,20000,11,82703,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pull of the Tides'),
(@ENTRY,0,1,0,0,0,100,0,5000,6000,15000,17000,11,79831,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wave Crash');

-- Forba Slabchisel
SET @ENTRY := 41558;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5500,12000,14000,11,80117,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Earth Spike'),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,12000,15000,11,82738,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rock Shower');

-- Garneg Charskull
SET @ENTRY := 2108;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,14000,18000,11,82641,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lava Gout'),
(@ENTRY,0,2,0,1,0,100,0,500,1000,600000,600000,11,79849,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Molten Armor on Spawn');

-- Gazz the Loch-Hunter
SET @ENTRY := 44227;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,82742,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Impaling Pull on Aggro'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,8852,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Moss Hide at 40% HP');

-- Gnawbone
SET @ENTRY := 14425;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,15000,18000,11,11977,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rend'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,8852,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Moss Hide at 40% HP');

-- Gobbler
SET @ENTRY := 1259;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lightning Shield on Spawn'),
(@ENTRY,0,1,0,16,0,100,0,12550,1,15000,30000,11,12550,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lightning Shield on Repeat'),
(@ENTRY,0,2,0,0,0,100,0,4000,6000,12000,14000,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pierce Armor'),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,4,0,0,0,100,0,5000,8000,12000,15000,11,78542,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Splash');

-- Gorfax Angerfang
SET @ENTRY := 46122;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,77558,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bloody Strike'),
(@ENTRY,0,1,0,2,0,100,0,0,65,22000,25000,11,84310,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bloodlust at 65% HP'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,22000,25000,11,83639,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bloodbath');

-- Harbor Crawler
SET @ENTRY := 44116;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,79175,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Slap & Chop');

-- Harbor Shredfin
SET @ENTRY := 41293;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,69203,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Vicious Bite'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,81173,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP');

-- Highland Lashtail
SET @ENTRY := 1016;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,18000,25000,11,33126,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Dropped Weapon'),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,12000,15000,11,6607,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lash');

-- Highland Razormaw
SET @ENTRY := 41400;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,15000,15000,11,3427,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Infected Wound');

-- Highland Scytheclaw
SET @ENTRY := 41401;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,3147,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rend Flesh');

-- Horghast Flarecrazed
SET @ENTRY := 41273;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,80576,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadowstep');

-- Horghast Flarecrazed
SET @ENTRY := 41554;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,80576,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadowstep');

-- Horrorjaw
SET @ENTRY := 41420;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,12000,15000,11,48287,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Powerful Bite'),
(@ENTRY,0,1,0,0,0,100,0,8000,10000,18000,22000,11,51467,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Intimidating Roar');

-- Leech Stalker
SET @ENTRY := 1111;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,15000,15000,11,3358,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Leech Poison');

-- Leech Widow
SET @ENTRY := 1112;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,15000,15000,11,3358,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Leech Poison'),
(@ENTRY,0,1,0,2,0,100,0,0,55,15000,18000,11,82715,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Flee into the Shadows at 55% HP');

-- Living Fossil
SET @ENTRY := 41388;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,82625,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bone Toss');

-- Ma'ruk Wyrmscale <Dragonmaw Warlord>
SET @ENTRY := 2090;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7000,8000,15000,18000,11,78521,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Dragon\'s Breath'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rushing Charge on Aggro'),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP');

-- Marine Anderson
SET @ENTRY := 24842;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,5,10,15000,25000,11,12024,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Net on Close');

-- Marine Halters
SET @ENTRY := 21841;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,5,10,15000,25000,11,12024,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Net on Close');

-- Marsh Lasher
SET @ENTRY := 41496;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,40,0,0,11,77603,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Uproot Lashlings at 40% HP');

-- Mirelow
SET @ENTRY := 14424;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,40,0,0,11,79825,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Summon Unstable Mushroom at 40% HP'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,31287,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Entangling Roots');

-- Mosshide Gnoll
SET @ENTRY := 41390;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,8852,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Moss Hide at 40% HP'),
(@ENTRY,0,3,0,4,0,20,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro');
-- NPC talk text insert
SET @ENTRY := 41390;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'More bones to gnaw on...',12,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,0,1, 'Grrrr... fresh meat!',12,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,1,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Mosshide Mystic
SET @ENTRY := 41391;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,8852,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Moss Hide at 40% HP'),
(@ENTRY,0,3,0,4,0,20,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro'),
(@ENTRY,0,4,0,0,0,100,0,0,0,3400,4700,11,9739,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wrath');
-- NPC talk text insert
SET @ENTRY := 41391;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'More bones to gnaw on...',12,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,0,1, 'Grrrr... fresh meat!',12,0,50,0,0,0, 'on Aggro Text'),
(@ENTRY,1,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');

-- Mottled Raptor
SET @ENTRY := 41343;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,75002,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Leaping Rush on Aggro');

-- Mottled Screecher
SET @ENTRY := 41342;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,10,15000,25000,11,82608,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Howling Screech on Close');

-- Mouldering Mirebeast
SET @ENTRY := 41424;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,40,0,0,11,79825,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Summon Unstable Mushroom at 40% HP'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,31287,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Entangling Roots');

-- Ocean Crawler
SET @ENTRY := 41295;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,79175,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Slap & Chop');

-- Ocean Shredfin
SET @ENTRY := 44110;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,69203,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Vicious Bite'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,81173,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP');

-- Razormaw Matriarch
SET @ENTRY := 1140;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,3147,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rend Flesh');

-- Rufus Darkshot
SET @ENTRY := 44225;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,12000,16000,11,79721,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Explosive Shot'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,25000,35000,11,80004,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Snake Trap');

-- Sarltooth
SET @ENTRY := 44226;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,82625,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bone Toss'),
(@ENTRY,0,1,0,1,0,100,0,500,1000,300000,300000,11,78646,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bone Shield on Spawn'),
(@ENTRY,0,2,0,16,0,100,0,78646,1,15000,30000,11,78646,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bone Shield on Repeat');

-- Silty Oozeling
SET @ENTRY := 41145;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,82710,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ooze Cap');

-- Slavering Ooze
SET @ENTRY := 41147;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,79607,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Venom Splash');

-- Sludginn
SET @ENTRY := 14433;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,79607,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Venom Splash'),
(@ENTRY,0,1,0,0,0,100,0,10000,11000,20000,25000,11,3335,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Dark Sludge');

-- Smouldering Ooze
SET @ENTRY := 41453;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,82644,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flaming Ooze');

-- Torrention
SET @ENTRY := 41167;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,40,0,0,11,82718,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spawn Waterlings at 40% HP'),
(@ENTRY,0,1,0,9,0,100,0,0,10,15000,25000,11,10987,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Geyser on Close');

-- Twilight Convert
SET @ENTRY := 42154;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,78129,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Twilight Bolt');

-- Twilight Rifleman
SET @ENTRY := 42155;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP');

-- Two-Toes
SET @ENTRY := 44224;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,34827,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lightning Shield on Spawn'),
(@ENTRY,0,1,0,16,0,100,0,34827,1,15000,30000,11,34827,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lightning Shield on Repeat'),
(@ENTRY,0,2,0,0,0,100,0,4000,6000,12000,14000,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pierce Armor'),
(@ENTRY,0,3,0,0,0,100,0,5000,8000,12000,15000,11,78542,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Splash'),
(@ENTRY,0,4,0,4,0,100,1,0,0,0,0,11,66060,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sprint on Aggro');

-- Unstable Shroom
SET @ENTRY := 42835;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving on Aggro'),
(@ENTRY,0,2,0,0,0,100,0,5000,8000,10000,10000,11,79826,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Unstable Cloud');

-- Viper
SET @ENTRY := 44180;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,82632,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Deadly Poison');

-- Wetlands Crocolisk
SET @ENTRY := 41419;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,12000,15000,11,48287,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Powerful Bite');

-- Yorla Darksnare
SET @ENTRY := 41416;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,82708,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flaming Arrow'),
(@ENTRY,0,2,0,0,0,100,0,7000,7000,18000,25000,11,80596,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Explosive Trap');

-- Yorla Darksnare
SET @ENTRY := 41524;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,82708,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flaming Arrow'),
(@ENTRY,0,2,0,0,0,100,0,7000,7000,18000,25000,11,80596,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Explosive Trap');
