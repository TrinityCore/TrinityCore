/* Copyright (C) 11 April 2011-2021 patch Project 
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
    /* Trash Mobs & Bosses*/
	
-- Aarux <The Plagued Nightmare>
SET @ENTRY := 74412;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,150082,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Plagued Bite'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,18000,22000,11,150072,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Web Strand');

-- Amnennar the Coldbringer
SET @ENTRY := 74434;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,151810,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frozen Bomb'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,150679,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Soul Leech at 40% HP'),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro');

-- Death Speaker Blackthorn
SET @ENTRY := 74875;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,'0','0','0','9','0','100','0','20','30','15000','25000','11','151962','0','0','0','0','0','2','0','0','0','0','0','0','0','Cast Shockwave on Close'),
(@ENTRY,'0','1','2','6','0','100','0','0','0','0','0','1','2','0','0','0','0','0','1','0','0','0','0','0','0','0','Say Text on Death'),
(@ENTRY,'0','2','0','61','0','100','0','0','0','0','0','12','74434','1','600000','0','0','0','1','0','0','0','0','0','0','0','SmartAI'),
(@ENTRY,'0','3','0','0','0','100','0','3000','5000','12000','15000','11','150616','0','0','0','0','0','2','0','0','0','0','0','0','0','Cast Searing Shadows'),
(@ENTRY,'0','4','0','2','0','100','0','0','55','22000','35000','11','150550','2','0','0','0','0','1','0','0','0','0','0','0','0','Cast Shadowmend at 55% HP'),
(@ENTRY,'0','5','0','2','0','100','0','0','70','20000','35000','11','150601','2','0','0','0','0','1','0','0','0','0','0','0','0','Cast Summon Skeletons at 40% HP');

-- Mordresh Fire Eye
SET @ENTRY := 74347;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,'0','0','0','10','0','100','1','0','25','0','0','1','0','0','0','0','0','0','1','0','0','0','0','0','0','0','SmartAI'),
(@ENTRY,'0','1','0','4','0','100','0','0','0','0','0','1','1','0','0','0','0','0','1','0','0','0','0','0','0','0','SmartAI'),
(@ENTRY,'0','2','3','6','0','100','0','0','0','0','0','1','2','0','0','0','0','0','1','0','0','0','0','0','0','0','SmartAI'),
(@ENTRY,'0','3','0','61','0','100','0','0','0','0','0','9','0','0','0','0','0','0','15','224819','1000','0','0','0','0','0','SmartAI'),
(@ENTRY,'0','4','0','0','0','100','0','15000','15000','25000','30000','11','150067','0','0','0','0','0','1','0','0','0','0','0','0','0','SmartAI'),
(@ENTRY,'0','5','0','0','0','100','0','10000','10000','25000','35000','11','151575','0','0','0','0','0','1','0','0','0','0','0','0','0','SmartAI'),
(@ENTRY,'0','6','0','0','0','100','0','5000','7000','15000','25000','11','150001','0','0','0','0','0','2','0','0','0','0','0','0','0','SmartAI');

-- Mushlump
SET @ENTRY := 74435;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,149835,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Smack Down'),
(@ENTRY,0,1,0,0,0,100,0,7000,10000,17000,25000,11,149851,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Tummy Ache');

-- Blazing Servitor
SET @ENTRY := 74548;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,150002,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Inferno');

-- Boneflayer Ghoul
SET @ENTRY := 74490;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,1,0,0,0,100,0,7000,9000,10000,22000,11,150479,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Tooth and Nail');

-- Boneflayer Ghoul
SET @ENTRY := 74947;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,1,0,0,0,100,0,7000,9000,10000,22000,11,150479,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Tooth and Nail');

-- Death's Head Arachnomancer
SET @ENTRY := 74483;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,150513,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Venom Nova'),
(@ENTRY,0,1,0,2,0,100,1,0,40,0,0,11,150528,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Empower Arachnid at 40% HP');

-- Death's Head Ghoul Wrangler
SET @ENTRY := 75331;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,151636,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Meaty Giblets');

-- Death's Head Necrolyte
SET @ENTRY := 74411;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,150368,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,11443,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cripple');

-- Death's Head Shadowmender
SET @ENTRY := 74478;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,150368,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,150550,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadowmend at 40% HP'),
(@ENTRY,0,2,0,14,0,100,0,3000,40,15000,18000,11,150550,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Shadowmend on Friendlies');

-- Festering Spiderling
SET @ENTRY := 74583;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,151998,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Festering Poison');

-- Freezing Spirit
SET @ENTRY := 74486;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,12531,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chilling Touch'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,12748,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Nova on Close');

-- Frozen Soul
SET @ENTRY := 74488;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,12531,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chilling Touch'),
(@ENTRY,0,1,0,9,0,100,0,0,15,15000,25000,11,150452,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cone of Cold on Close');

-- Gelatanized Plague Gunk
SET @ENTRY := 74950;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,151928,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Disgusting Slime'),
(@ENTRY,0,1,0,11,0,100,1,0,0,0,0,11,152144,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Disease Cloud on Spawn');

-- Plague-Rotted Webslinger
SET @ENTRY := 74584;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,150485,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Web Wrap');

-- Sah'rhee
SET @ENTRY := 75813;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,152773,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Possession');

-- Splinterbone Captain
SET @ENTRY := 74371;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,10000,17000,11,151008,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Slashing Whirl on Close');

-- Splinterbone Frostweaver
SET @ENTRY := 74379;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,20822,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frostbolt'),
(@ENTRY,0,1,0,0,0,100,0,8000,10000,18000,25000,11,8364,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Blizzard');

-- Splinterbone Shadowcaster
SET @ENTRY := 74480;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,150368,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,1,0,0,0,100,0,8000,10000,18000,25000,11,150385,1,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Coalescing Shadow');

-- Splinterbone Warrior
SET @ENTRY := 74383;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,150332,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Disrupting Dash'),
(@ENTRY,0,1,0,0,0,100,0,8000,9000,10000,20000,11,151010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Smash');

-- Splinterbone Warrior
SET @ENTRY := 74902;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,150332,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Disrupting Dash'),
(@ENTRY,0,1,0,0,0,100,0,8000,9000,10000,20000,11,151010,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Smash');

-- Thorn Eater Ghoul
SET @ENTRY := 74489;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,22696,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thorns on Spawn');